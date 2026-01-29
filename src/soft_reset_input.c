#include "soft_reset_input.h"
#include "gba.h"
#include "macros.h"
#include "menus/boot_debug.h"

#include "constants/game_state.h"
#include "structs/audio.h"
#include "structs/game_state.h"

#include "data/menus/language_select_data.h"

#define SOFT_RESET_KEYS (KEY_A | KEY_B | KEY_START | KEY_SELECT)

/**
 * @brief 7c4 | c | Removed code for V-Blank during soft reset
 * 
 */
void SoftResetVBlankCallback(void)
{
    /* probably left over from some debugging code */
    volatile u8 c = 0;
}

/**
 * @brief 7d0 | 34 | Checks for soft reset conditions
 * 
 */
void SoftResetCheck(void)
{
    if (gMainGameMode == GM_START_SOFT_RESET)
        return;

    if (gDisableSoftReset)
        return;

    if ((gButtonInput & SOFT_RESET_KEYS) == SOFT_RESET_KEYS)
        gMainGameMode = GM_START_SOFT_RESET;
}

/**
 * @brief 804 | 108 | Prepares game and register states for a soft reset
 * 
 */
void SoftReset(void)
{
    #ifdef REGION_EU
    s32 tmp;
    #endif // REGION_EU

    HazeTransferAndDeactivate();
    RestartSound();

    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_IE, 0);
    WRITE_16(REG_DISPSTAT, 0);
    SET_BACKDROP_COLOR(COLOR_BLACK);
    WRITE_16(REG_DISPCNT, 0);
    WRITE_16(REG_BLDY, BLDY_MAX_VALUE);
    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT);

    DMA3_FILL_32(0, EWRAM_BASE, EWRAM_SIZE);
    DMA3_FILL_32(0, IWRAM_BASE, IWRAM_SIZE - 0x200);

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

    #ifdef DEBUG
    BootDebugReadSram();
    gMainGameMode = gDebugMode ? GM_DEBUG_MENU : GM_INTRO;
    #else // !DEBUG
    gMainGameMode = GM_INTRO;
    #endif // DEBUG

    gSubGameMode1 = 0;
    gSubGameMode2 = 0;
    gResetGame = FALSE;
    gStereoFlag = 0;

    #ifdef REGION_EU
    #ifdef DEBUG
    if (gMainGameMode == GM_INTRO)
    #endif // DEBUG
    {
        if (INVALID_EU_LANGUAGE(gLanguage))
        {
            gMainGameMode = GM_SOFT_RESET;
            gSubGameMode1 = sLanguageSelectGameModeSub1Values[1];
        }
    }
    #endif // REGION_EU

    gButtonInput = KEY_NONE;
    gPreviousButtonInput = KEY_NONE;
    gChangedInput = KEY_NONE;

    WRITE_16(REG_IF, USHORT_MAX);
    // TODO: Find a better way to get a match here
    #if defined(REGION_EU) && !defined(REGION_EU_BETA)
    // Written this way to produce matching ASM
    tmp = TRUE;
    WRITE_16(REG_IME, tmp);
    #else // !REGION_EU || REGION_EU_BETA
    WRITE_16(REG_IME, TRUE);
    #endif // REGION_EU && !REGION_EU_BETA
}
