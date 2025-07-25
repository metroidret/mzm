#include "menus/game_over.h"
#include "dma.h"
#include "macros.h"
#include "callbacks.h"
#include "oam_id.h"
#include "temp_globals.h"

#include "data/menus/game_over_data.h"
#include "data/menus/file_select_data.h"
#include "data/shortcut_pointers.h"
#include "data/menus/pause_screen_data.h"

#include "constants/audio.h"
#include "constants/demo.h"
#include "constants/game_over.h"
#include "constants/menus/file_select.h"
#include "constants/menus/boot_debug.h"

#include "structs/demo.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/samus.h"

static u32 GameOverProcessInput(void);
static void GameOverUpdateTextGfx(void);
static void GameOverInit(void);
static void GameOverInit_Debug(void);
static void GameOverVBlank(void);
static void GameOverVBlank_Empty(void);
static void GameOverUpdateLettersPalette(void);
static void GameOverUpdateSamusHead(GameOverCursorAction action);
static void GameOverProcessOAM(void);

/**
 * @brief 778c4 | 214 | Subroutine for the game over
 * 
 * @return u32 bool, ended
 */
u32 GameOverSubroutine(void)
{
    u32 ended;

    ended = FALSE;

    APPLY_DELTA_TIME_INC(GAME_OVER_DATA.timer);

    switch (gSubGameMode1)
    {
        case 0:
            if (gCurrentDemo.active)
            {
                gCurrentDemo.number++;
                gCurrentDemo.active = FALSE;

                DoSoundAction(SOUND_ACTION_DISABLE_STEREO | SOUND_ACTION_PWM(9) | SOUND_ACTION_FREQ_INDEX(SOUND_MODE_FREQ_13379) | SOUND_ACTION_VOLUME(15) | SOUND_ACTION_MAX_CHANNELS(7) | SOUND_ACTION_ENABLE_REVERB);
                FadeAllSounds(CONVERT_SECONDS(1.f / 6));
                FadeMusic(CONVERT_SECONDS(1.f / 6));
                gDemoState = DEMO_STATE_NONE;
                gSubGameMode2 = 2;
                return TRUE;
            }

            #ifdef DEBUG
            if (gDebugMode && gSectionInfo.sectionIndex < BOOT_DEBUG_SECTION_SAVE_A)
            {
                GameOverInit_Debug();
                gSubGameMode1 = 9;
            }
            else
            #endif // DEBUG
            {
                GameOverInit();
                GAME_OVER_DATA.timer = 0;
                gSubGameMode1++;
            }
            break;

        case 1:
            if (gWrittenToBldy_NonGameplay > 2)
            {
                gWrittenToBldy_NonGameplay--;
                break;
            }

            GAME_OVER_DATA.dispcnt |= DCNT_WIN1;
            GAME_OVER_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;
            gSubGameMode1++;
            break;

        case 2:
            if (gWrittenToBldy_NonGameplay < 6)
            {
                gWrittenToBldy_NonGameplay += 2;
                if (gWrittenToBldy_NonGameplay > 6)
                    gWrittenToBldy_NonGameplay = 6;
                break;
            }
            GAME_OVER_DATA.dynamicPalette.enableFlags = 0x80 | 1;
            PlayMusic(MUSIC_GAME_OVER, 0);
            gSubGameMode1++;
            break;

        case 3:
            if (GameOverProcessInput())
            {
                GAME_OVER_DATA.timer = 0;
                gSubGameMode1++;
            }

            GameOverUpdateLettersPalette();
            break;
        
        case 4:
            if (GAME_OVER_DATA.oam[0].ended)
            {
                GAME_OVER_DATA.timer = 0;
                gSubGameMode1++;
            }

            GameOverUpdateLettersPalette();
            break;

        case 5:
            GameOverUpdateLettersPalette();
            gWrittenToBldy_NonGameplay = 4;
            GAME_OVER_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;
            GAME_OVER_DATA.dispcnt ^= DCNT_WIN1;
            FadeMusic(ONE_THIRD_SECOND);
            gSubGameMode1++;
            break;

        case 6:
            if (gWrittenToBldy_NonGameplay < BLDY_MAX_VALUE)
                gWrittenToBldy_NonGameplay++;
            else
                gSubGameMode1++;
            break;

        case 7:
            if (GAME_OVER_DATA.optionSelected == 1)
            {
                #ifdef DEBUG
                gSubGameMode2 = !gDebugMode ? 1 : 16;
                #else // !DEBUG
                gSubGameMode2 = 1;
                #endif
                ended = TRUE;
                break;
            }

            gSubGameMode2 = 4;
            gSubGameMode1++;
            break;

        case 8:
            #ifdef DEBUG
            if (gDebugMode)
            {
                unk_75c04(3);
            }
            else
            #endif // DEBUG
            {
                unk_75c04(0);
                gLanguage = gGameCompletion.language;
            }
            ended = TRUE;
            break;

        case 9:
            if (gWrittenToBldy_NonGameplay < BLDY_MAX_VALUE)
                gWrittenToBldy_NonGameplay++;
            else
            {
                gSubGameMode2 = 0x10;
                ended = TRUE;
            }
            break;
    }

    GameOverProcessOAM();
    return ended;
}

/**
 * @brief 77ad4 | 78 | Handles the inputs for the game over menu
 * 
 * @return u32 bool, leaving
 */
static u32 GameOverProcessInput(void)
{
    u32 doingSomething;

    doingSomething = FALSE;

    if (gChangedInput & (KEY_A | KEY_START))
    {
        FileSelectPlayMenuSound(MENU_SOUND_REQUEST_GAME_OVER_START_GAME);
        GameOverUpdateSamusHead(SAMUS_CURSOR_ACTION_SELECTING);
        return TRUE;
    }

    // Handle cursor movement
    if (gChangedInput & KEY_UP)
    {
        if (GAME_OVER_DATA.optionSelected != 0)
        {
            GAME_OVER_DATA.optionSelected = 0;
            doingSomething++;
        }
    }
    else if (gChangedInput & KEY_DOWN)
    {
        if (GAME_OVER_DATA.optionSelected != 1)
        {
            GAME_OVER_DATA.optionSelected = 1;
            doingSomething++;
        }
    }

    if (!doingSomething)
        return FALSE;

    // Update cursor
    FileSelectPlayMenuSound(MENU_SOUND_REQUEST_GAME_OVER_MENU_CURSOR);
    GameOverUpdateTextGfx();
    GameOverUpdateSamusHead(SAMUS_CURSOR_ACTION_MOVING);

    return FALSE;
}

/**
 * @brief 77b4c | 5c | Updates the graphics of the text
 * 
 */
static void GameOverUpdateTextGfx(void)
{
    u8 palette;
    u16* dst;
    s32 i;

    dst = VRAM_BASE + 0x340;

    // Get palette
    if (GAME_OVER_DATA.optionSelected == 0)
        palette = 2;
    else
        palette = 3;

    // Top
    for (i = 0; i < 64; i++, dst++)
        *dst = (*dst & 0xFFF) | palette << 12;

    // Toggle palette
    palette ^= 1;
    dst += 32;

    // Bottom
    for (i = 0; i < 64; i++, dst++)
        *dst = (*dst & 0xFFF) | palette << 12;
}

static const u32* sGameOverTextPromptGfxPointers[LANGUAGE_END] = {
    [LANGUAGE_JAPANESE] = sGameOverTextPromptEnglishGfx,
    [LANGUAGE_HIRAGANA] = sGameOverTextPromptHiraganaGfx,
    [LANGUAGE_ENGLISH] = sGameOverTextPromptEnglishGfx,
    #if defined(REGION_EU) || defined(REGION_US_BETA)
    [LANGUAGE_GERMAN] = sGameOverTextPromptGermanGfx,
    [LANGUAGE_FRENCH] = sGameOverTextPromptFrenchGfx,
    [LANGUAGE_ITALIAN] = sGameOverTextPromptItalianGfx,
    [LANGUAGE_SPANISH] = sGameOverTextPromptSpanishGfx
    #else // !(REGION_EU || REGION_US_BETA)
    [LANGUAGE_GERMAN] = sGameOverTextPromptEnglishGfx,
    [LANGUAGE_FRENCH] = sGameOverTextPromptEnglishGfx,
    [LANGUAGE_ITALIAN] = sGameOverTextPromptEnglishGfx,
    [LANGUAGE_SPANISH] = sGameOverTextPromptEnglishGfx
    #endif // REGION_EU || REGION_US_BETA
};

/**
 * @brief 77ba8 | 230 | Initializes the game over menu
 * 
 */
static void GameOverInit(void)
{
    CallbackSetVblank(GameOverVBlank_Empty);

    #ifdef REGION_EU
    BitFill(3, 0, &gNonGameplayRam, sizeof(gNonGameplayRam), 32);
    #else // !REGION_EU
    DMA_FILL_32(3, 0, &gNonGameplayRam, sizeof(gNonGameplayRam));
    #endif // REGION_EU

    WRITE_16(REG_BLDCNT, GAME_OVER_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);

    WRITE_16(REG_BLDY, gWrittenToBldy_NonGameplay = BLDY_MAX_VALUE);
    WRITE_16(REG_DISPCNT, 0);

    gNextOamSlot = 0;
    ClearGfxRam();
    ResetFreeOam();

    gOamXOffset_NonGameplay = gOamYOffset_NonGameplay = 0;

    DoSoundAction(SOUND_ACTION_ENABLE_REVERB);
    StopAllMusicAndSounds();

    DmaTransfer(3, sGameOverMenuPal, PALRAM_BASE, sizeof(sGameOverMenuPal), 16);
    SET_BACKDROP_COLOR(COLOR_BLACK);
    #ifdef REGION_EU
    DmaTransfer(3, sFileSelectIconsPal, PALRAM_OBJ, sizeof(sFileSelectIconsPal), 16);
    #else // !REGION_EU
    DMA_SET(3, sFileSelectIconsPal, PALRAM_OBJ, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sFileSelectIconsPal)));
    #endif // REGION_EU

    LZ77UncompVRAM(sGameOverBackgroundTileTable, VRAM_BASE + 0x1800);
    LZ77UncompVRAM(sGameOverTextTileTable, VRAM_BASE + 0x800);
    LZ77UncompVRAM(sGameOver_454520, VRAM_BASE);
    DmaTransfer(3, VRAM_BASE + 0x1800, VRAM_BASE + 0x1000, 0x1800 - 0x1000, 32);
    LZ77UncompVRAM(sGameOverTextAndBackgroundGfx, VRAM_BASE + 0x4000);
    LZ77UncompVRAM(sFileSelectObjIconsGfx, VRAM_OBJ);
    LZ77UncompVRAM(sGameOverTextPromptGfxPointers[gLanguage], VRAM_BASE + 0xA800);

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(1, 0, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(1, 1, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(1, 2, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(1, 3, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));

    GAME_OVER_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ;
    WRITE_8(REG_WINOUT, WIN0_ALL_NO_COLOR_EFFECT);
    WRITE_8(REG_WININ + 1, HIGH_BYTE(WIN1_ALL));

    GAME_OVER_DATA.dynamicPalette = sGameOverDynamicPalette_Empty;

    gSubGameMode3 = 0;

    gBg0HOFS_NonGameplay = gBg0VOFS_NonGameplay = 0;
    gBg1HOFS_NonGameplay = gBg1VOFS_NonGameplay = 0;
    gBg3HOFS_NonGameplay = gBg3VOFS_NonGameplay = 0;
    gBg2HOFS_NonGameplay = gBg2VOFS_NonGameplay = 0;

    GAME_OVER_DATA.optionSelected = GAME_OVER_DATA.unk_35 = 0;

    GameOverUpdateTextGfx();

    GAME_OVER_DATA.oam[0] = sMenuOamData_Empty;

    GameOverUpdateSamusHead(SAMUS_CURSOR_ACTION_LOADING);
    CallbackSetVblank(GameOverVBlank);
}

/**
 * @brief 77dd8 | 134 | Initializes the game over menu for debug
 * 
 */
static void GameOverInit_Debug(void)
{
    CallbackSetVblank(GameOverVBlank_Empty);

    #ifdef REGION_EU
    BitFill(3, 0, &gNonGameplayRam, sizeof(gNonGameplayRam), 32);
    #else // !REGION_EU
    DMA_FILL_32(3, 0, &gNonGameplayRam, sizeof(gNonGameplayRam));
    #endif

    WRITE_16(REG_BLDCNT, GAME_OVER_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);

    WRITE_16(REG_BLDY, gWrittenToBldy_NonGameplay = BLDY_MAX_VALUE);
    WRITE_16(REG_DISPCNT, GAME_OVER_DATA.dispcnt = 0);

    gNextOamSlot = 0;
    ClearGfxRam();
    ResetFreeOam();

    gOamXOffset_NonGameplay = gOamYOffset_NonGameplay = 0;

    DoSoundAction(SOUND_ACTION_DISABLE_STEREO | SOUND_ACTION_PWM(9) | SOUND_ACTION_FREQ_INDEX(SOUND_MODE_FREQ_13379) | SOUND_ACTION_VOLUME(15) | SOUND_ACTION_MAX_CHANNELS(7) | SOUND_ACTION_ENABLE_REVERB);
    StopAllMusicAndSounds();

    SET_BACKDROP_COLOR(COLOR_WHITE);

    WRITE_16(REG_BG0CNT, 0);
    WRITE_16(REG_BG1CNT, 0);
    WRITE_16(REG_BG2CNT, 0);
    WRITE_16(REG_BG3CNT, 0);

    gSubGameMode3 = 0;

    gBg0HOFS_NonGameplay = gBg0VOFS_NonGameplay = 0;
    gBg1HOFS_NonGameplay = gBg1VOFS_NonGameplay = 0;
    gBg2HOFS_NonGameplay = gBg2VOFS_NonGameplay = 0;
    gBg3HOFS_NonGameplay = gBg3VOFS_NonGameplay = 0;

    GAME_OVER_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

    gWrittenToBldy_NonGameplay = 0;
    GAME_OVER_DATA.optionSelected = GAME_OVER_DATA.unk_35 = 0;

    GameOverUpdateTextGfx();

    GAME_OVER_DATA.oam[0] = sMenuOamData_Empty;

    CallbackSetVblank(GameOverVBlank);
}

/**
 * @brief 77f0c | dc | V-blank code for the game over
 * 
 */
static void GameOverVBlank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16(DMA_ENABLE | DMA_32BIT, OAM_SIZE / sizeof(u32)))

    WRITE_16(REG_BG0HOFS, SUB_PIXEL_TO_PIXEL(gBg0HOFS_NonGameplay));
    WRITE_16(REG_BG0VOFS, SUB_PIXEL_TO_PIXEL(gBg0VOFS_NonGameplay));

    WRITE_16(REG_BG1HOFS, SUB_PIXEL_TO_PIXEL(gBg1HOFS_NonGameplay));
    WRITE_16(REG_BG1VOFS, SUB_PIXEL_TO_PIXEL(gBg1VOFS_NonGameplay));

    WRITE_16(REG_BG2HOFS, SUB_PIXEL_TO_PIXEL(gBg2HOFS_NonGameplay));
    WRITE_16(REG_BG2VOFS, SUB_PIXEL_TO_PIXEL(gBg2VOFS_NonGameplay));

    WRITE_16(REG_BG3HOFS, SUB_PIXEL_TO_PIXEL(gBg3HOFS_NonGameplay));
    WRITE_16(REG_BG3VOFS, SUB_PIXEL_TO_PIXEL(gBg3VOFS_NonGameplay));

    WRITE_16(REG_DISPCNT, GAME_OVER_DATA.dispcnt);
    WRITE_16(REG_BLDY, gWrittenToBldy_NonGameplay);

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_H, gWrittenToBldalpha_L));

    WRITE_16(REG_BLDCNT, GAME_OVER_DATA.bldcnt);
    WRITE_16(REG_WIN1H, GAME_OVER_DATA.win1H);
    WRITE_16(REG_WIN1V, GAME_OVER_DATA.win1V);
}

/**
 * @brief 77fe8 | c | Empty V-blank code
 * 
 */
static void GameOverVBlank_Empty(void)
{
    vu8 c = 0;
}

static u8 sGameOverTextPaletteMaxTimers[3] = {
    ONE_THIRD_SECOND, ONE_THIRD_SECOND, ONE_THIRD_SECOND
};

static s8 sGameOverTextGradientPaletteOffset[9] = {
    0, 1, 2, 3, 2, 1, 0, 0, 0
};

/**
 * @brief 77ff4 | 180 | Handles the animation of the GAME OVER letters
 * 
 */
static void GameOverUpdateLettersPalette(void)
{
    s32 i;
    s32 j;
    s32 k;
    s32 row;
    const u16* src;

    if (GAME_OVER_DATA.dynamicPalette.enableFlags == 0)
        return;

    if (GAME_OVER_DATA.dynamicPalette.enableFlags & 0x80)
    {
        if ((GAME_OVER_DATA.dynamicPalette.enableFlags & 0x7F) != GAME_OVER_DATA.dynamicPalette.unk_4)
        {
            GAME_OVER_DATA.dynamicPalette.unk_4 = GAME_OVER_DATA.dynamicPalette.enableFlags & 0x7F;
            GAME_OVER_DATA.dynamicPalette.timer = 0;
            GAME_OVER_DATA.dynamicPalette.currentPaletteRow = 0;
            GAME_OVER_DATA.dynamicPalette.unk_13 = 0;
            GAME_OVER_DATA.dynamicPalette.timerLimit = sGameOverTextPaletteMaxTimers[GAME_OVER_DATA.dynamicPalette.unk_4];
        }

        GAME_OVER_DATA.dynamicPalette.enableFlags = 1;
        return;
    }

    APPLY_DELTA_TIME_INC(GAME_OVER_DATA.dynamicPalette.timer);
    if (GAME_OVER_DATA.dynamicPalette.timerLimit > GAME_OVER_DATA.dynamicPalette.timer)
        return;

    src = &sGameOverMenuPal[4];
    switch (GAME_OVER_DATA.dynamicPalette.unk_4)
    {
        // unk_4 will never be 0 when it reaches here?
        case 0:
            GAME_OVER_DATA.dynamicPalette.currentPaletteRow++;
            if (GAME_OVER_DATA.dynamicPalette.currentPaletteRow >= ARRAY_SIZE(GAME_OVER_DATA.dynamicPalette.palette))
                GAME_OVER_DATA.dynamicPalette.currentPaletteRow = 0;

            row = GAME_OVER_DATA.dynamicPalette.currentPaletteRow;
            for (i = 0; i < ARRAY_SIZE(GAME_OVER_DATA.dynamicPalette.palette); i++, row++)
            {
                if (row >= ARRAY_SIZE(GAME_OVER_DATA.dynamicPalette.palette))
                    row = 0;

                GAME_OVER_DATA.dynamicPalette.palette[i] = src[row];
            }
            break;

        case 1:
            GAME_OVER_DATA.dynamicPalette.currentPaletteRow++;
            if (GAME_OVER_DATA.dynamicPalette.currentPaletteRow >= ARRAY_SIZE(sGameOverTextGradientPaletteOffset))
                GAME_OVER_DATA.dynamicPalette.currentPaletteRow = 0;

            // palette offsets create the "breathing" effect of the GAME OVER letters
            j = sGameOverTextGradientPaletteOffset[GAME_OVER_DATA.dynamicPalette.currentPaletteRow];
            if (j >= 0)
            {
                // Fill the first j rows with the default color
                for (i = 0; i < j; i++)
                    GAME_OVER_DATA.dynamicPalette.palette[i] = *src;

                // Fill the next 6 - i rows
                for (k = 0; i < 6; i++, k++)
                    GAME_OVER_DATA.dynamicPalette.palette[i] = src[k];
            }
            // palette offset is always non-negative, thus this condition is unused
            else
            {
                for (i = 5; j < 0; j++, i--)
                    GAME_OVER_DATA.dynamicPalette.palette[i] = src[5];

                for (k = 4; i >= 0; i--, k--)
                    GAME_OVER_DATA.dynamicPalette.palette[i] = src[k];
            }
            break;
    }

    GAME_OVER_DATA.dynamicPalette.timer = 0;
    DmaTransfer(3, GAME_OVER_DATA.dynamicPalette.palette, PALRAM_BASE + 4 * sizeof(u16), sizeof(GAME_OVER_DATA.dynamicPalette.palette), 16);
}

/**
 * @brief 78174 | 88 | Updates the head of Samus (cursor)
 * 
 * @param action Action done
 */
static void GameOverUpdateSamusHead(GameOverCursorAction action)
{
    UpdateMenuOamDataID(&GAME_OVER_DATA.oam[0], sGameOverSamusHeadOamIds[gEquipment.suitType][action]);

    GAME_OVER_DATA.oam[0].xPosition = sGameOverSamusHeadXPositions[gLanguage];
    GAME_OVER_DATA.oam[0].yPosition = sGameOverSamusHeadYPositions[GAME_OVER_DATA.optionSelected];

    if (GAME_OVER_DATA.optionSelected != 0)
        GAME_OVER_DATA.win1V = C_16_2_8(126, 145 + 1);
    else
        GAME_OVER_DATA.win1V = C_16_2_8(102, 121 + 1);

    GAME_OVER_DATA.win1H = C_16_2_8(0, 239 + 1);
}

/**
 * @brief 781fc | 2c | Processes the OAM for the game over menu
 * 
 */
static void GameOverProcessOAM(void)
{
    gNextOamSlot = 0;
    ProcessComplexMenuOam(ARRAY_SIZE(GAME_OVER_DATA.oam), GAME_OVER_DATA.oam, sGameOverOam);
    ResetFreeOam();
}
