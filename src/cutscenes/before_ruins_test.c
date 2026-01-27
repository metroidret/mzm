#include "cutscenes/before_ruins_test.h"
#include "cutscenes/cutscene_utils.h"
#include "dma.h"
#include "gba.h"
#include "color_effects.h" // Required
#include "music_wrappers.h"
#include "syscall_wrappers.h"

#include "data/shortcut_pointers.h"
#include "data/cutscenes/before_ruins_test_data.h"

#include "constants/cutscene.h"
#include "constants/audio.h"

#include "structs/display.h"

static void BeforeRuinsTestWallAndGreyVoiceScrollAndLoadYoungSamusGfx(struct CutsceneGraphicsData* pGraphics);
static void BeforeRuinsTestWallAndGreyVoiceApplyMonochrome(struct CutsceneGraphicsData* pGraphics);
static void BeforeRuinsTestWallAndGreyScrollCloseUp(struct CutsceneGraphicsData* pGraphics);

static struct CutsceneGraphicsData sBeforeRuinsTestCutsceneGraphicsData = {
    .active = FALSE,
    .paletteStage = 0,
    .maxTimer = 4,
    .maxPaletteStage = 0,
    .timer = 0
};

/**
 * @brief 663c8 | 270 | Handles the close up part
 * 
 * @return u8 FALSE
 */
static u8 BeforeRuinsTestSamusCloseUp(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            SEND_TO_PALRAM(sBeforeRuinsTestSamusCloseUpPal, PALRAM_BASE);
            SET_BACKDROP_COLOR(COLOR_BLACK);

            CallLZ77UncompVram(sBeforeRuinsTestYoungSamusCloseUpGfx, BGCNT_TO_VRAM_CHAR_BASE(sBeforeRuinsTestPageData[5].graphicsPage));
            CallLZ77UncompVram(sBeforeRuinsTestSamusCloseUpGfx, BGCNT_TO_VRAM_CHAR_BASE(sBeforeRuinsTestPageData[6].graphicsPage));
            
            CallLZ77UncompVram(sBeforeRuinsTestYoungSamusCloseUpTileTable, BGCNT_TO_VRAM_TILE_BASE(sBeforeRuinsTestPageData[5].tiletablePage));
            CallLZ77UncompVram(sBeforeRuinsTestSamusCloseUpEyesClosedTileTable, BGCNT_TO_VRAM_TILE_BASE(sBeforeRuinsTestPageData[8].tiletablePage));
            CallLZ77UncompVram(sBeforeRuinsTestSamusCloseUpEyesOpenedTileTable, BGCNT_TO_VRAM_TILE_BASE(sBeforeRuinsTestPageData[7].tiletablePage));
            CallLZ77UncompVram(sBeforeRuinsTestSamusCloseUpOutlineTileTable, BGCNT_TO_VRAM_TILE_BASE(sBeforeRuinsTestPageData[6].tiletablePage));

            CutsceneSetBgcntPageData(sBeforeRuinsTestPageData[5]);
            CutsceneSetBgcntPageData(sBeforeRuinsTestPageData[8]);
            CutsceneSetBgcntPageData(sBeforeRuinsTestPageData[7]);
            CutsceneSetBgcntPageData(sBeforeRuinsTestPageData[6]);

            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_X | CUTSCENE_BG_EDIT_Y, sBeforeRuinsTestPageData[5].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_X | CUTSCENE_BG_EDIT_Y, sBeforeRuinsTestPageData[8].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_X | CUTSCENE_BG_EDIT_Y, sBeforeRuinsTestPageData[7].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_X | CUTSCENE_BG_EDIT_Y, sBeforeRuinsTestPageData[6].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneReset();

            // TODO: Fix enum instead of using ifdef here
            #ifdef REGION_EU
            CutsceneStartBackgroundFading(11);
            #else // !REGION_EU
            CutsceneStartBackgroundFading(10);
            #endif // REGION_EU
            CUTSCENE_DATA.dispcnt = sBeforeRuinsTestPageData[5].bg | sBeforeRuinsTestPageData[8].bg |sBeforeRuinsTestPageData[6].bg;
            
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(3.f))
            {
                CutsceneStartBackgroundEffect(BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET,
                    0, BLDALPHA_MAX_VALUE, 16, 1);

                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_BG_ENDED)
            {
                CUTSCENE_DATA.dispcnt ^= sBeforeRuinsTestPageData[5].bg;

                CutsceneStartBackgroundEffect(BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET,
                    0, BLDALPHA_MAX_VALUE, 1, 16);

                CUTSCENE_DATA.dispcnt |= sBeforeRuinsTestPageData[7].bg;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(1.f) + TWO_THIRD_SECOND)
            {
                CutsceneStartBackgroundEffect(BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET,
                    BLDALPHA_MAX_VALUE, 0, 1, 4);

                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_BG_ENDED)
            {
                CUTSCENE_DATA.dispcnt ^= sBeforeRuinsTestPageData[8].bg;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 5:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(2.f) + ONE_THIRD_SECOND)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 6:
            if (CutsceneTransferAndUpdateFade())
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 7:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(1.f) + CONVERT_SECONDS(1.f / 6))
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 8:
            CutsceneFadeScreenToWhite();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    #ifdef DEBUG
    CutsceneCheckSkipStage(1);
    #endif // DEBUG

    return FALSE;
}

/**
 * @brief 66638 | 2d8 | Handles the wall view and the grey voice part
 * 
 * @return u8 FALSE
 */
static u8 BeforeRuinsTestWallAndGreyVoice(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            SEND_TO_PALRAM(sBeforeRuinsTestChozoWallPal, PALRAM_BASE);
            SET_BACKDROP_COLOR(COLOR_BLACK);

            ApplyMonochromeToPalette(sBeforeRuinsTestChozoWallPal, BEFORE_RUINS_TEST_EWRAM.wallPalMonochrome, 0);
            DmaTransfer(3, sBeforeRuinsTestChozoWallPal, BEFORE_RUINS_TEST_EWRAM.wallPal, sizeof(sBeforeRuinsTestChozoWallPal), 16);

            CallLZ77UncompVram(sBeforeRuinsTestChozoWallBackgroundGfx, BGCNT_TO_VRAM_CHAR_BASE(sBeforeRuinsTestPageData[2].graphicsPage));
            BitFill(3, 0, BGCNT_TO_VRAM_TILE_BASE(sBeforeRuinsTestPageData[2].tiletablePage), BGCNT_VRAM_TILE_SIZE, 32);
            BitFill(3, 0, BGCNT_TO_VRAM_TILE_BASE(sBeforeRuinsTestPageData[3].tiletablePage), BGCNT_VRAM_TILE_SIZE, 32);

            CallLZ77UncompVram(sBeforeRuinsTestChozoWallBackgroundTileTable, BGCNT_TO_VRAM_TILE_BASE(sBeforeRuinsTestPageData[2].tiletablePage));
            CallLZ77UncompVram(sBeforeRuinsTestYoungSamusAndGreyVoiceTileTable, BGCNT_TO_VRAM_TILE_BASE(sBeforeRuinsTestPageData[3].tiletablePage));

            CutsceneSetBgcntPageData(sBeforeRuinsTestPageData[2]);
            CutsceneSetBgcntPageData(sBeforeRuinsTestPageData[3]);

            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_X | CUTSCENE_BG_EDIT_Y, sBeforeRuinsTestPageData[2].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_X | CUTSCENE_BG_EDIT_Y, sBeforeRuinsTestPageData[3].bg, NON_GAMEPLAY_START_BG_POS);

            CallLZ77UncompVram(sBeforeRuinsTestYoungSamusAndGreyVoiceCloseUpGfx, BGCNT_TO_VRAM_CHAR_BASE(sBeforeRuinsTestPageData[4].graphicsPage));
            CallLZ77UncompVram(sBeforeRuinsTestYoungSamusAndGreyVoiceCloseUpTileTable, BGCNT_TO_VRAM_TILE_BASE(sBeforeRuinsTestPageData[4].tiletablePage));

            CutsceneSetBgcntPageData(sBeforeRuinsTestPageData[4]);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_X, sBeforeRuinsTestPageData[4].bg, NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE * 5);
            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_Y, sBeforeRuinsTestPageData[4].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneReset();

            gWrittenToBldalpha_L = 0;
            gWrittenToBldalpha_H = BLDALPHA_MAX_VALUE;

            CUTSCENE_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;
            DmaTransfer(3, &sBeforeRuinsTestCutsceneGraphicsData, &CUTSCENE_DATA.graphicsData[1], sizeof(CUTSCENE_DATA.graphicsData[1]), 16);

            CUTSCENE_DATA.dispcnt = sBeforeRuinsTestPageData[2].bg | sBeforeRuinsTestPageData[4].bg;
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(2.f))
            {
                CUTSCENE_DATA.graphicsData[0].active |= TRUE;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            if (CUTSCENE_DATA.timeInfo.timer == (CONVERT_SECONDS(3.f) + ONE_THIRD_SECOND) && !CUTSCENE_DATA.graphicsData[1].active)
            {
                CUTSCENE_DATA.graphicsData[1].active |= TRUE;
            }

            if (CUTSCENE_DATA.timeInfo.timer == (CONVERT_SECONDS(9.f) + ONE_THIRD_SECOND) && !CUTSCENE_DATA.graphicsData[2].active)
            {
                CutsceneStartBackgroundEffect(CUTSCENE_DATA.bldcnt, BLDALPHA_MAX_VALUE, 0, 16, 1);
                CUTSCENE_DATA.graphicsData[2].active |= TRUE;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            if (!CUTSCENE_DATA.graphicsData[0].active && !CUTSCENE_DATA.graphicsData[1].active && !CUTSCENE_DATA.graphicsData[2].active &&
                CUTSCENE_DATA.specialEffect.status & CUTSCENE_SPECIAL_EFFECT_STATUS_BG_ENDED)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(1.f))
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 5:
            CutsceneFadeScreenToWhite();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    BeforeRuinsTestWallAndGreyVoiceScrollAndLoadYoungSamusGfx(&CUTSCENE_DATA.graphicsData[0]);
    BeforeRuinsTestWallAndGreyVoiceApplyMonochrome(&CUTSCENE_DATA.graphicsData[1]);
    BeforeRuinsTestWallAndGreyScrollCloseUp(&CUTSCENE_DATA.graphicsData[2]);

    *CutsceneGetBgVerticalPointer(sBeforeRuinsTestPageData[3].bg) = *CutsceneGetBgVerticalPointer(sBeforeRuinsTestPageData[2].bg);

    #ifdef DEBUG
    CutsceneCheckSkipStage(1);
    #endif // DEBUG

    return FALSE;
}

/**
 * @brief 66910 | 78 | Handles the scrolling of the wall and loads the young samus and grey voice graphics
 * 
 * @param pGraphics Cutscene graphics data pointer
 */
void BeforeRuinsTestWallAndGreyVoiceScrollAndLoadYoungSamusGfx(struct CutsceneGraphicsData* pGraphics)
{
    u16* pPosition;

    if (!(pGraphics->active & TRUE))
        return;

    pPosition = CutsceneGetBgVerticalPointer(sBeforeRuinsTestPageData[2].bg);
    (*pPosition)++;

    if (*pPosition >= NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE * 10)
    {
        *pPosition = NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE * 10;
        pGraphics->active = FALSE;
    }

    if (!(CUTSCENE_DATA.dispcnt & sBeforeRuinsTestPageData[3].bg) && *pPosition == NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE * 6)
    {
        CallLZ77UncompVram(sBeforeRuinsTestYoungSamusAndGreyVoiceGfx, BGCNT_TO_VRAM_CHAR_BASE(sBeforeRuinsTestPageData[3].graphicsPage));
        CUTSCENE_DATA.dispcnt |= sBeforeRuinsTestPageData[3].bg;
    }
}

/**
 * @brief 66988 | 6c | Handles the monochrome palette transition
 * 
 * @param pGraphics Cutscene graphics data pointer
 */
void BeforeRuinsTestWallAndGreyVoiceApplyMonochrome(struct CutsceneGraphicsData* pGraphics)
{
    if (!(pGraphics->active & TRUE))
        return;

    if (pGraphics->timer != 0)
    {
        APPLY_DELTA_TIME_DEC(pGraphics->timer);
        return;
    }

    pGraphics->timer = pGraphics->maxTimer;
    pGraphics->paletteStage++;

    ApplySmoothMonochromeToPalette(BEFORE_RUINS_TEST_EWRAM.wallPal, BEFORE_RUINS_TEST_EWRAM.wallPalMonochrome,
        BEFORE_RUINS_TEST_EWRAM.wallPalMonochromeTransition, pGraphics->paletteStage);
    DmaTransfer(3, BEFORE_RUINS_TEST_EWRAM.wallPalMonochromeTransition, PALRAM_BASE, sizeof(BEFORE_RUINS_TEST_EWRAM.wallPalMonochromeTransition), 16);

    if (pGraphics->paletteStage == 32)
        pGraphics->active = FALSE;
}

/**
 * @brief 669f4 | 3c | Handles the scrolling of the young samus and grey voice close up
 * 
 * @param pGraphics Cutscene graphics data pointer
 */
void BeforeRuinsTestWallAndGreyScrollCloseUp(struct CutsceneGraphicsData* pGraphics)
{
    u16* pPosition;

    if (!(pGraphics->active & TRUE))
        return;

    pPosition = CutsceneGetBgHorizontalPointer(sBeforeRuinsTestPageData[4].bg);
    (*pPosition) -= PIXEL_SIZE / 2;

    if (*pPosition <= NON_GAMEPLAY_START_BG_POS)
    {
        *pPosition = NON_GAMEPLAY_START_BG_POS;
        pGraphics->active = FALSE;
    }
}

/**
 * @brief 66a30 | 70 | Handles the view of the chozo side walls part
 * 
 * @return u8 FALSE
 */
static u8 BeforeRuinsTestChozoWallSides(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            // Wait
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(2.f) + ONE_THIRD_SECOND)
            {
                // Toggle viewed wall
                CUTSCENE_DATA.dispcnt ^= sBeforeRuinsTestPageData[0].bg;
                CUTSCENE_DATA.dispcnt |= sBeforeRuinsTestPageData[1].bg;
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 1:
            // Wait
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(2.f) + ONE_THIRD_SECOND)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            CutsceneFadeScreenToBlack();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    #ifdef DEBUG
    CutsceneCheckSkipStage(1);
    #endif // DEBUG

    return FALSE;
}

/**
 * @brief 66aa0 | 130 | Initializes the before Ruins Test cutscene
 * 
 * @return u8 FALSE
 */
static u8 BeforeRuinsTestInit(void)
{
    CutsceneFadeScreenToBlack();

    SEND_TO_PALRAM(sBeforeRuinsTestChozoWallSidesPal, PALRAM_BASE);
    BitFill(3, 0, PALRAM_OBJ, PAL_SIZE, 32);
    SET_BACKDROP_COLOR(COLOR_BLACK);

    CallLZ77UncompVram(sBeforeRuinsTestLeftSideOfChozoWallGfx, BGCNT_TO_VRAM_CHAR_BASE(sBeforeRuinsTestPageData[0].graphicsPage));
    CallLZ77UncompVram(sBeforeRuinsTestRightSideOfChozoWallGfx, BGCNT_TO_VRAM_CHAR_BASE(sBeforeRuinsTestPageData[1].graphicsPage));

    BitFill(3, 0, BGCNT_VRAM_TILE_SIZE + BGCNT_TO_VRAM_TILE_BASE(sBeforeRuinsTestPageData[0].tiletablePage), BGCNT_VRAM_TILE_SIZE, 32);
    BitFill(3, 0, BGCNT_TO_VRAM_TILE_BASE(sBeforeRuinsTestPageData[1].tiletablePage), BGCNT_VRAM_TILE_SIZE, 32);

    CallLZ77UncompVram(sBeforeRuinsTestLeftSideOfChozoWallTileTable, BGCNT_TO_VRAM_TILE_BASE(sBeforeRuinsTestPageData[0].tiletablePage));
    CallLZ77UncompVram(sBeforeRuinsTestRightSideOfChozoWallTileTable, BGCNT_VRAM_TILE_SIZE + BGCNT_TO_VRAM_TILE_BASE(sBeforeRuinsTestPageData[1].tiletablePage));

    CutsceneSetBgcntPageData(sBeforeRuinsTestPageData[0]);
    CutsceneSetBgcntPageData(sBeforeRuinsTestPageData[1]);
    CutsceneReset();

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_X | CUTSCENE_BG_EDIT_Y, sBeforeRuinsTestPageData[0].bg, NON_GAMEPLAY_START_BG_POS);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_Y, sBeforeRuinsTestPageData[1].bg, NON_GAMEPLAY_START_BG_POS);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_X, sBeforeRuinsTestPageData[1].bg, NON_GAMEPLAY_START_BG_POS + BLOCK_SIZE * 16);

    PlayMusic(MUSIC_CHOZO_STATUE_HINT_DELAY, 0);

    CUTSCENE_DATA.dispcnt = sBeforeRuinsTestPageData[0].bg;

    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;
    CUTSCENE_DATA.timeInfo.stage++;

    return FALSE;
}

static struct CutsceneStageData sBeforeRuinsTestStageData[5] = {
    [0] = {
        .pFunction = BeforeRuinsTestInit,
        .oamLength = 0
    },
    [1] = {
        .pFunction = BeforeRuinsTestChozoWallSides,
        .oamLength = 0
    },
    [2] = {
        .pFunction = BeforeRuinsTestWallAndGreyVoice,
        .oamLength = 0
    },
    [3] = {
        .pFunction = BeforeRuinsTestSamusCloseUp,
        .oamLength = 0
    },
    [4] = {
        .pFunction = CutsceneEndFunction,
        .oamLength = 0
    }
};

/**
 * @brief 66bd0 | 30 | Main loop for the before Ruins Test cutscene
 * 
 * @return u8 bool, ended
 */
u8 BeforeRuinsTestMainLoop(void)
{
    u8 ended;

    ended = sBeforeRuinsTestStageData[CUTSCENE_DATA.timeInfo.stage].pFunction();

    CutsceneUpdateBackgroundsPosition(TRUE);
    return ended;
}
