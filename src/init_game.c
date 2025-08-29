#include "init_game.h"

#include "callbacks.h"

#include "gba.h"
#include "io.h"
#include "soft_reset_input.h"
#include "types.h"
#include "menus/boot_debug.h"

#include "constants/game_state.h"
#include "structs/audio.h"
#include "structs/game_state.h"

void InitializeGame(void)
{
    WRITE_16(REG_DISPCNT, DCNT_BLANK);
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, 0);

    DMA_FILL_32(3, 0, EWRAM_BASE, EWRAM_SIZE);
    DMA_FILL_32(3, 0, IWRAM_BASE, IWRAM_SIZE - 0x200);

    ClearGfxRam();
    LoadInterruptCode();
    CallbackSetVblank(SoftResetVBlankCallback);
    SramRead_All();
    InitializeAudio();
    #ifdef BUGFIX
    SramRead_SoundMode();
    FileSelectApplyStereo();
    #endif // BUGFIX

    WRITE_16(REG_IE, IF_VBLANK | IF_DMA2 | IF_GAMEPAK);
    WRITE_16(REG_DISPSTAT, DSTAT_IF_VBLANK);
    WRITE_16(REG_WAITCNT, WAIT_SRAM_4CYCLES | WAIT_BANK0_3CYCLES
        | WAIT_BANK0_SUBSEQUENT_1CYCLE
        | WAIT_BANK1_3CYCLES | WAIT_BANK1_SUBSEQUENT_1CYCLE
        | WAIT_BANK2_3CYCLES | WAIT_BANK2_SUBSEQUENT_1CYCLE
        | WAIT_GAMEPACK_CGB);

    gSubGameMode1 = 0;
    gSubGameMode2 = 0;
    gDebugMode = FALSE;

    gButtonInput = KEY_NONE;
    gPreviousButtonInput = KEY_NONE;
    gChangedInput = KEY_NONE;

    UpdateInput();

    if (gChangedInput == (KEY_L | KEY_R))
    {
        gMainGameMode = GM_ERASE_SRAM;
    }
    else
    {
        #ifdef DEBUG
        BootDebugReadSram();
        gMainGameMode = gDebugMode ? GM_DEBUG_MENU : GM_SOFT_RESET;
        #else // !DEBUG
        gMainGameMode = GM_SOFT_RESET;
        #endif // DEBUG
    }

    gButtonInput = 0;
    gPreviousButtonInput = 0;
    gChangedInput = 0;

    gDisableSoftReset = FALSE;
    gStereoFlag = FALSE;

    WRITE_16(REG_IF, USHORT_MAX);
    WRITE_16(REG_IME, TRUE);
}
