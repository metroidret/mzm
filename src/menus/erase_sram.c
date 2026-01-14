#include "menus/erase_sram.h"
#include "macros.h"
#include "callbacks.h"

#include "data/shortcut_pointers.h"
#include "data/menus/erase_sram_data.h"
#include "data/menus/title_screen_data.h"
#include "data/menus/pause_screen_data.h"

#include "constants/audio.h"
#include "constants/game_state.h"
#include "constants/menus/erase_sram.h"

#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/menus/erase_sram.h"

static u32 EraseSramProcessInput(void);
static void EraseSramApplyInput(void);
static u32 EraseSramCheckForInput(void);
static void EraseSramInit(void);
static void EraseSramResetOam(void);
static void EraseSramUpdateCursorPosition(void);
static void EraseSramVBlank(void);
static void EraseSramVBlank_Empty(void);
static void EraseSramProcessOAM(void);

static const u32* sEraseSramTextGfxPointers[LANGUAGE_END][2] = {
    [LANGUAGE_JAPANESE] = {
        sEraseSramMenuQuestionJapaneseGfx,
        sEraseSramMenuConfirmJapaneseGfx
    },
    [LANGUAGE_HIRAGANA] = {
        sEraseSramMenuQuestionJapaneseGfx,
        sEraseSramMenuConfirmJapaneseGfx
    },
    [LANGUAGE_ENGLISH] = {
        sEraseSramMenuQuestionEnglishGfx,
        sEraseSramMenuConfirmEnglishGfx
    },
    #if defined(REGION_EU) || defined(REGION_US_BETA)
    [LANGUAGE_GERMAN] = {
        sEraseSramMenuQuestionGermanGfx,
        sEraseSramMenuConfirmGermanGfx
    },
    [LANGUAGE_FRENCH] = {
        sEraseSramMenuQuestionFrenchGfx,
        sEraseSramMenuConfirmFrenchGfx
    },
    [LANGUAGE_ITALIAN] = {
        sEraseSramMenuQuestionItalianGfx,
        sEraseSramMenuConfirmItalianGfx
    },
    [LANGUAGE_SPANISH] = {
        sEraseSramMenuQuestionSpanishGfx,
        sEraseSramMenuConfirmSpanishGfx
    }
    #else // !(REGION_EU || REGION_US_BETA)
    [LANGUAGE_GERMAN] = {
        sEraseSramMenuQuestionEnglishGfx,
        sEraseSramMenuConfirmEnglishGfx
    },
    [LANGUAGE_FRENCH] = {
        sEraseSramMenuQuestionEnglishGfx,
        sEraseSramMenuConfirmEnglishGfx
    },
    [LANGUAGE_ITALIAN] = {
        sEraseSramMenuQuestionEnglishGfx,
        sEraseSramMenuConfirmEnglishGfx
    },
    [LANGUAGE_SPANISH] = {
        sEraseSramMenuQuestionEnglishGfx,
        sEraseSramMenuConfirmEnglishGfx
    }
    #endif // REGION_EU || REGION_US_BETA
};

/**
 * @brief 75c30 | 14c | Main loop for the erase sram menu
 * 
 * @return u32 bool, leaving
 */
u32 EraseSramMainLoop(void)
{
    u32 leaving;

    leaving = FALSE;

    APPLY_DELTA_TIME_INC(ERASE_SRAM_DATA.timer);
    switch (gSubGameMode1)
    {
        case 0:
            EraseSramInit();
            gSubGameMode1++;
            break;

        case 1:
            if (gWrittenToBldy_NonGameplay != 0)
            {
                gWrittenToBldy_NonGameplay--;
                break;
            }

            ERASE_SRAM_DATA.bldcnt = (BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT) & ~BLDCNT_OBJ_FIRST_TARGET_PIXEL;
            ERASE_SRAM_DATA.bldyTarget = gWrittenToBldy_NonGameplay;

            gSubGameMode1++;
            ERASE_SRAM_DATA.timer = 0;
            break;

        case 2:
            gSubGameMode2 = EraseSramProcessInput();
            if (gSubGameMode2 == 0)
                break;

            ERASE_SRAM_DATA.timer = 0;
            if (gSubGameMode2 == ERASE_SRAM_INPUT_ACTION_ERASING)
                gSubGameMode1 = 5;
            else
                gSubGameMode1 = 3;
            break;

        case 3:
            if (ERASE_SRAM_DATA.timer <= TWO_THIRD_SECOND)
                break;

            ERASE_SRAM_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

            ERASE_SRAM_DATA.timer = 0;
            gSubGameMode1++;
            break;

        case 4:
            if (gWrittenToBldy_NonGameplay < BLDY_MAX_VALUE)
            {
                gWrittenToBldy_NonGameplay++;
                break;
            }

            ERASE_SRAM_DATA.dispcnt &= ~(DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);
            leaving = TRUE;
            break;

        case 5:
            if (ERASE_SRAM_DATA.timer <= TWO_THIRD_SECOND)
                break;

            ERASE_SRAM_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            ERASE_SRAM_DATA.timer = 0;
            gSubGameMode1++;
            break;

        case 6:
            if (gWrittenToBldy_NonGameplay < BLDY_MAX_VALUE)
            {
                gWrittenToBldy_NonGameplay++;
                break;
            }

            gSubGameMode1++;
            ERASE_SRAM_DATA.dispcnt = DCNT_BLANK;
            break;

        case 7:
            RestartSound();
            EraseSram();
            leaving = TRUE;
    }

    if (!leaving)
        EraseSramProcessOAM();

    return leaving;
}

/**
 * @brief 75d7c | 54 | Processes the input for the erase sram menu
 * 
 * @return u32 action
 */
static u32 EraseSramProcessInput(void)
{
    u32 result;

    result = ERASE_SRAM_INPUT_ACTION_NONE;

    if (ERASE_SRAM_DATA.nextOption & ERASE_SRAM_OPTION_CHANGED_FLAG)
        EraseSramApplyInput();
    else
        result = EraseSramCheckForInput();

    // Update BLDY based on target
    if (ERASE_SRAM_DATA.bldyTarget != gWrittenToBldy_NonGameplay)
    {
        if (ERASE_SRAM_DATA.bldyTarget > gWrittenToBldy_NonGameplay)
            gWrittenToBldy_NonGameplay++;
        else
            gWrittenToBldy_NonGameplay--;
    }
    
    EraseSramUpdateCursorPosition();

    return result;
}

/**
 * @brief 75dd0 | ac | Applies the input
 * 
 */
static void EraseSramApplyInput(void)
{
    if (ERASE_SRAM_DATA.oam[0].oamID == ERASE_SRAM_OAM_ID_CURSOR_SELECTING)
        return;

    ERASE_SRAM_DATA.nextOption &= ~ERASE_SRAM_OPTION_CHANGED_FLAG;
    ERASE_SRAM_DATA.currentOption = ERASE_SRAM_DATA.nextOption;

    switch (ERASE_SRAM_DATA.nextOption)
    {
        case ERASE_SRAM_OPTION_QUESTION_NO:
            ERASE_SRAM_DATA.oam[2].oamID = sEraseSramQuestionWindowNoSelectedOamId;
            ERASE_SRAM_DATA.oam[1].oamID = 0;
            break;

        case ERASE_SRAM_OPTION_QUESTION_YES:
            ERASE_SRAM_DATA.oam[2].oamID = sEraseSramQuestionWindowYesSelectedOamId;
            ERASE_SRAM_DATA.oam[1].oamID = 0;
            break;

        case ERASE_SRAM_OPTION_CONFIRM_NO:
            ERASE_SRAM_DATA.oam[1].oamID = sEraseSramConfirmWindowNoSelectedOamId;
            break;

        case ERASE_SRAM_OPTION_CONFIRM_YES:
            ERASE_SRAM_DATA.oam[1].oamID = sEraseSramConfirmWindowYesSelectedOamId;
            break;
    }

    ERASE_SRAM_DATA.oam[1].exists = OAM_ID_CHANGED_FLAG;
    ERASE_SRAM_DATA.oam[2].exists = OAM_ID_CHANGED_FLAG;

    ERASE_SRAM_DATA.oam[0].oamID = ERASE_SRAM_OAM_ID_CURSOR_IDLE;
    ERASE_SRAM_DATA.oam[0].exists = OAM_ID_CHANGED_FLAG;
}

/**
 * @brief 75e7c | 10c | Checks for input
 * 
 * @return u32 action
 */
static u32 EraseSramCheckForInput(void)
{
    u32 sound;
    u32 result;
    u32 exiting;

    result = ERASE_SRAM_INPUT_ACTION_NONE;
    sound = 0;
    exiting = FALSE;

    switch (ERASE_SRAM_DATA.currentOption)
    {
        case ERASE_SRAM_OPTION_QUESTION_NO:
            if (gChangedInput & KEY_RIGHT)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_QUESTION_YES;
                sound = ERASE_SRAM_SOUND_CURSOR;
                break;
            }

            if (gChangedInput & KEY_A)
            {
                result = ERASE_SRAM_INPUT_ACTION_OPENING_SUB_WINDOW;
                exiting = TRUE;
            }
            break;

        case ERASE_SRAM_OPTION_QUESTION_YES:
            if (gChangedInput & KEY_LEFT)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_QUESTION_NO;
                sound = ERASE_SRAM_SOUND_CURSOR;
                break;
            }

            if (gChangedInput & KEY_A)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_CONFIRM_NO;
                sound = ERASE_SRAM_SOUND_SELECT_YES;
                ERASE_SRAM_DATA.bldyTarget = 4;
            }
            break;

        case ERASE_SRAM_OPTION_CONFIRM_NO:
            if (gChangedInput & KEY_RIGHT)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_CONFIRM_YES;
                sound = ERASE_SRAM_SOUND_CURSOR;
                break;
            }

            if (gChangedInput & (KEY_A | KEY_B))
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_QUESTION_NO;
                ERASE_SRAM_DATA.bldyTarget = 0;
                sound = ERASE_SRAM_SOUND_REFUSE;
            }
            break;

        case ERASE_SRAM_OPTION_CONFIRM_YES:
            if (gChangedInput & KEY_LEFT)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_CONFIRM_NO;
                sound = ERASE_SRAM_SOUND_CURSOR;
                break;
            }

            if (gChangedInput & KEY_A)
            {
                result = ERASE_SRAM_INPUT_ACTION_ERASING;
                exiting = TRUE;
                break;
            }

            if (gChangedInput & KEY_B)
            {
                ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_QUESTION_NO;
                sound = ERASE_SRAM_SOUND_REFUSE;
                ERASE_SRAM_DATA.bldyTarget = 0;
            }
            break;
    }

    if (exiting)
    {
        ERASE_SRAM_DATA.oam[0].oamID = ERASE_SRAM_OAM_ID_CURSOR_SELECTING;
        ERASE_SRAM_DATA.oam[0].exists = OAM_ID_CHANGED_FLAG;
        sound = ERASE_SRAM_SOUND_CONFIRM;
    }

    if (sEraseSramMenuSoundsID[sound])
        SoundPlay(sEraseSramMenuSoundsID[sound]);

    return result;
}

/**
 * @brief 75f88 | 24c | Initializes the erase sram menu
 * 
 */
static void EraseSramInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IF, IF_HBLANK);
    WRITE_16(REG_IME, TRUE);
    
    CallbackSetVblank(EraseSramVBlank_Empty);

    WRITE_16(REG_BLDCNT, BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);

    WRITE_16(REG_BLDY, gWrittenToBldy_NonGameplay = BLDY_MAX_VALUE);

    DMA_FILL_32(3, 0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    ClearGfxRam();
    gNextOamSlot = 0;
    ResetFreeOam();

    ERASE_SRAM_DATA.language = gLanguage;
    // This code sets the language to the region's default if the language is invalid for that region.
    // Debug allows any language, US allows any European language, and JP allows Japanese or hiragana.
    #if defined(DEBUG)
    if (ERASE_SRAM_DATA.language >= LANGUAGE_END)
    #elif defined(REGION_JP)
    if (ERASE_SRAM_DATA.language > LANGUAGE_HIRAGANA)
    #else // !(DEBUG || REGION_JP)
    if (INVALID_EU_LANGUAGE(ERASE_SRAM_DATA.language))
    #endif
    {
        ERASE_SRAM_DATA.language = LANGUAGE_DEFAULT;
    }

    while (READ_16(REG_VCOUNT) >= 21 && READ_16(REG_VCOUNT) <= SCREEN_SIZE_Y);

    #ifdef REGION_EU
    DmaTransfer(3, sEraseSramMenuBackgroundPal, PALRAM_BASE, 13 * PAL_ROW_SIZE, 16);
    DmaTransfer(3, sEraseSramMenuObjectsPal, PALRAM_OBJ, sizeof(sEraseSramMenuObjectsPal), 16);
    #else // !REGION_EU
    DMA_SET(3, sEraseSramMenuBackgroundPal, PALRAM_BASE, C_32_2_16(DMA_ENABLE, (13 * PAL_ROW_SIZE) / sizeof(u16)));
    DMA_SET(3, sEraseSramMenuObjectsPal, PALRAM_OBJ, C_32_2_16(DMA_ENABLE, sizeof(sEraseSramMenuObjectsPal) / sizeof(u16)));
    #endif // REGION_EU
    
    SET_BACKDROP_COLOR(COLOR_BLACK);

    LZ77UncompVRAM(sEraseSramMenuFirstBoxGfx, VRAM_BASE + 0x1000);
    LZ77UncompVRAM(sEraseSramMenuObjectsGfx, VRAM_BASE + 0x12000);
    LZ77UncompVRAM(sTitleScreenSpaceBackgroundDecorationGfx, VRAM_BASE + 0x1800);
    LZ77UncompVRAM(sTitleScreenSpaceAndGroundBackgroundGfx, VRAM_BASE + 0x3400);

    LZ77UncompVRAM(sEraseSramTextGfxPointers[ERASE_SRAM_DATA.language][0], VRAM_BASE);
    LZ77UncompVRAM(sEraseSramTextGfxPointers[ERASE_SRAM_DATA.language][1], VRAM_BASE + 0x11000);
    LZ77UncompVRAM(sEraseSramTextGfxPointers[ERASE_SRAM_DATA.language][0], VRAM_OBJ);

    LZ77UncompVRAM(sEraseSramMenuBoxTileTable, VRAM_BASE + 0xD000);
    LZ77UncompVRAM(sEraseSramMenuBackgroundTileTable, VRAM_BASE + 0xF000);

    WRITE_16(REG_BG0CNT, 0);
    WRITE_16(REG_BG2CNT, 0);
    
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 26, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 30, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    gWrittenToBldalpha_H = 0;
    WRITE_16(REG_BLDALPHA, 0);

    gSubGameMode3 = 0;

    gBg1HOFS_NonGameplay = 0;
    gBg1VOFS_NonGameplay = 0;
    gBg3HOFS_NonGameplay = 0;
    gBg3VOFS_NonGameplay = 0;

    EraseSramResetOam();
    EraseSramUpdateCursorPosition();
    EraseSramProcessOAM();
    EraseSramVBlank();

    ERASE_SRAM_DATA.bldcnt = READ_16(REG_BLDCNT);
    ERASE_SRAM_DATA.dispcnt = DCNT_BG1 | DCNT_BG3 | DCNT_OBJ;
    WRITE_16(REG_DISPCNT, ERASE_SRAM_DATA.dispcnt);

    CallbackSetVblank(EraseSramVBlank);
}

/**
 * @brief 761d4 | c4 | Initializes the OAM for the erase sram menu
 * 
 */
static void EraseSramResetOam(void)
{
    s32 i;
    
    gOamXOffset_NonGameplay = 0;
    gOamYOffset_NonGameplay = 0;

    ERASE_SRAM_DATA.currentOption = ERASE_SRAM_OPTION_QUESTION_NO;
    ERASE_SRAM_DATA.nextOption = ERASE_SRAM_OPTION_CHANGED_FLAG | ERASE_SRAM_OPTION_QUESTION_NO;

    for (i = 0; i < ARRAY_SIZE(ERASE_SRAM_DATA.oam); i++)
        ERASE_SRAM_DATA.oam[i] = sMenuOamDataEraseSram_Empty;

    ERASE_SRAM_DATA.oam[2].oamID = sEraseSramQuestionWindowNoSelectedOamId;
    ERASE_SRAM_DATA.oam[2].yPosition = sEraseSramMenuCursorPosition[0][1];
    ERASE_SRAM_DATA.oam[2].xPosition = sEraseSramMenuCursorPosition[0][0];
    ERASE_SRAM_DATA.oam[2].exists = TRUE;

    ERASE_SRAM_DATA.oam[1].oamID = 0;
    ERASE_SRAM_DATA.oam[1].yPosition = sEraseSramMenuCursorPosition[1][1];
    ERASE_SRAM_DATA.oam[1].xPosition = sEraseSramMenuCursorPosition[1][0];
    ERASE_SRAM_DATA.oam[1].exists = TRUE;

    ERASE_SRAM_DATA.oam[0].oamID = ERASE_SRAM_OAM_ID_CURSOR_IDLE;
    ERASE_SRAM_DATA.oam[0].exists = TRUE;
}

/**
 * @brief 76298 | 48 | Updates the cursor position based on the current option
 * 
 */
static void EraseSramUpdateCursorPosition(void)
{
    // Panel position + option position
    ERASE_SRAM_DATA.oam[0].yPosition = sEraseSramMenuCursorPosition[DIV_SHIFT(ERASE_SRAM_DATA.currentOption, 2)][1] +
        sEraseSramMenuCursorPositionOffset[ERASE_SRAM_DATA.currentOption][1];

    ERASE_SRAM_DATA.oam[0].xPosition = sEraseSramMenuCursorPosition[DIV_SHIFT(ERASE_SRAM_DATA.currentOption, 2)][0] +
        sEraseSramMenuCursorPositionOffset[ERASE_SRAM_DATA.currentOption][0];
}

/**
 * @brief 762e0 | 78 | Erase sram menu V-blank code
 * 
 */
static void EraseSramVBlank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16(DMA_ENABLE | DMA_32BIT, OAM_SIZE / sizeof(u32)));

    WRITE_16(REG_BLDY, gWrittenToBldy_NonGameplay);

    WRITE_16(REG_BG1HOFS, SUB_PIXEL_TO_PIXEL(gBg1HOFS_NonGameplay));
    WRITE_16(REG_BG1VOFS, SUB_PIXEL_TO_PIXEL(gBg1VOFS_NonGameplay));

    WRITE_16(REG_BG3HOFS, SUB_PIXEL_TO_PIXEL(gBg3HOFS_NonGameplay));
    WRITE_16(REG_BG3VOFS, SUB_PIXEL_TO_PIXEL(gBg3VOFS_NonGameplay));

    WRITE_16(REG_BLDCNT, ERASE_SRAM_DATA.bldcnt);
    WRITE_16(REG_DISPCNT, ERASE_SRAM_DATA.dispcnt);
}

/**
 * @brief 76358 | c | Empty v-blank for the erase sram menu
 * 
 */
static void EraseSramVBlank_Empty(void)
{
    vu8 c = 0;
}

/**
 * @brief 76364 | 2c | Processes the OAM for the erase sram menu
 * 
 */
static void EraseSramProcessOAM(void)
{
    gNextOamSlot = 0;
    ProcessMenuOam(ARRAY_SIZE(ERASE_SRAM_DATA.oam), ERASE_SRAM_DATA.oam, sEraseSramMenuOam);
    ResetFreeOam();
}

