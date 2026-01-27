#include "menus/title_screen.h"
#include "dma.h"
#include "macros.h"
#include "callbacks.h"
#include "oam_id.h"
#include "gba/rom_header.h"

#include "data/shortcut_pointers.h"
#include "data/menus/title_screen_data.h"
#include "data/menus/pause_screen_data.h"
#include "data/text_data.h"
#include "data/menus/game_over_data.h"

#include "constants/menus/title_screen.h"
#include "constants/audio.h"
#include "constants/color_fading.h"
#include "constants/demo.h"

#include "structs/demo.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/samus.h"

#define TITLE_SCREEN_SPARKLE_DELAY CONVERT_SECONDS(.35f + 1.f / 60)

#ifdef REGION_EU
static void TitleScreenSetMenuPalette(TitleScreenMenuOption param0);
#endif // REGION_EU

static struct TitleScreenAnimatedPalette sTitleScreenAnimatedPaletteTemplates[4] = {
    [0] = {
        .paletteRow = 0,
        .maxTimer = 17,
        .timer = 17,
        .unk_4 = 0
    },
    [1] = {
        .paletteRow = 0,
        .maxTimer = 3,
        .timer = 3,
        .unk_4 = 2
    },
    [2] = {
        .paletteRow = 0,
        .maxTimer = 9,
        .timer = 9,
        .unk_4 = 0
    },
    [3] = {
        .paletteRow = 0,
        .maxTimer = 4,
        .timer = 4,
        .unk_4 = 1
    }
};

#ifdef REGION_EU
static const u8* sRomInfoStringPointers[1] = {
    sTitleScreenRomInfoTime
};
#else // !REGION_EU
static const u8* sRomInfoStringPointers[4] = {
    sTitleScreenRomInfoTime,
    sTitleScreenRomInfoRegionJPN,
    sTitleScreenRomInfoRegionEUR,
    sTitleScreenRomInfoRegionUSA
};
#endif // REGION_EU

#ifdef REGION_EU
static const u32* sTitleScreenMenuGfxPointers[(LANGUAGE_COUNT - LANGUAGE_ENGLISH) * 2] = {
    sTitleScreenEnglishMenuGfx_Top,
    sTitleScreenEnglishMenuGfx_Bottom,
    sTitleScreenGermanMenuGfx_Top,
    sTitleScreenGermanMenuGfx_Bottom,
    sTitleScreenFrenchMenuGfx_Top,
    sTitleScreenFrenchMenuGfx_Bottom,
    sTitleScreenItalianMenuGfx_Top,
    sTitleScreenItalianMenuGfx_Bottom,
    sTitleScreenSpanishMenuGfx_Top,
    sTitleScreenSpanishMenuGfx_Bottom
};
#endif // REGION_EU

static u8 sTitleScreenCometsFlags[2][2] = {
    [0] = {
        TITLE_SCREEN_TYPE_FIRST_COMET_ACTIVE, TITLE_SCREEN_TYPE_FIRST_COMET_ENDED
    },
    [1] = {
        TITLE_SCREEN_TYPE_SECOND_COMET_ACTIVE, TITLE_SCREEN_TYPE_SECOND_COMET_ENDED
    }
};

static u8 sTitleScreenSkyDecorationsPaletteRows[6] = {
    8, 9, 10, 11, 10, 9
};

static u8 sTitleScreenTitlePaletteRows[14] = {
    0, 1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1
};

static u8 sTitleScreenPromptPaletteRows[7] = {
    0, 1, 2, 3, 2, 1, 0
};

/**
 * @brief 76390 | 60 | Forward the page data to the correct BGCNT register
 * 
 * @param pPageData Title screen page data pointer
 */
void TitleScreenSetBGCNTPageData(const struct TitleScreenPageData* const pPageData)
{
    u16 value;

    // value = CREATE_BGCNT(pPageData->graphicsPage, pPageData->tiletablePage, pPageData->priority, pPageData->screenSize);
    value = pPageData->priority | pPageData->screenSize | pPageData->tiletablePage << BGCNT_SCREEN_BASE_BLOCK_SHIFT |
        pPageData->graphicsPage << BGCNT_CHAR_BASE_BLOCK_SHIFT;

    if (pPageData->bg == DCNT_BG0)
        WRITE_16(REG_BG0CNT, value);
    else if (pPageData->bg == DCNT_BG1)
        WRITE_16(REG_BG1CNT, value);
    else if (pPageData->bg == DCNT_BG2)
        WRITE_16(REG_BG2CNT, value);
    else
        WRITE_16(REG_BG3CNT, value);
}

/**
 * @brief 763f0 | 18 | Loads the tiletable of a page data
 * 
 * @param pPageData Title screen page data pointer
 */
void TitleScreenLoadPageData(const struct TitleScreenPageData* const pPageData)
{
    LZ77UncompVRAM(pPageData->tiletablePointer, VRAM_BASE + pPageData->tiletablePage * 0x800);
}

/**
 * @brief 76408 | 18 | Loads the tiletable of a page data
 * 
 * @param pPageData Title screen page data pointer
 */
void TitleScreenLoadPageData_Copy(const struct TitleScreenPageData* const pPageData)
{
    LZ77UncompVRAM(pPageData->tiletablePointer, VRAM_BASE + pPageData->tiletablePage * 0x800);
}

/**
 * @brief 76420 | 2c | Updates the OAM id of a title screen OAM
 * 
 * @param offset OAM offset
 * @param oamId OAM id
 */
void TitleScreenUpdateOamId(u8 offset, u8 oamId)
{
    TITLE_SCREEN_DATA.oam[offset].oamID = oamId;
    TITLE_SCREEN_DATA.oam[offset].animationDurationCounter = 0;
    TITLE_SCREEN_DATA.oam[offset].currentAnimationFrame = 0;
}

/**
 * @brief 7644c | 2c | Calls the OAM process handler
 * 
 */
void TitleScreenCallProcessOAM(void)
{
    gNextOamSlot = 0;
    ProcessMenuOam(ARRAY_SIZE(TITLE_SCREEN_DATA.oam), TITLE_SCREEN_DATA.oam, sTitleScreenOam);
    ResetFreeOam();
}

/**
 * @brief 76478 | 50 | Resets the OAM
 * 
 */
void TitleScreenResetOAM(void)
{
    s32 i;
    struct MenuOamData* pOam;

    for (pOam = TITLE_SCREEN_DATA.oam, i = 0; i < (s32)ARRAY_SIZE(TITLE_SCREEN_DATA.oam); i++, pOam++)
        *pOam = sMenuOamData_Empty;

    TitleScreenUpdateOamId(0, 0);

    TITLE_SCREEN_DATA.oam[0].yPosition = sTitleScreenRomInfoPosition[0];
    TITLE_SCREEN_DATA.oam[0].xPosition = sTitleScreenRomInfoPosition[1];
}

/**
 * @brief 764c8 | 118 | Handles the title screen fading in
 * 
 * @return u32 
 */
u32 TitleScreenFadingIn(void)
{
    u32 ended;
    u16* src;
    u16* dst;

    ended = FALSE;
    switch (TITLE_SCREEN_DATA.fadingStage)
    {
        case 0:
            TITLE_SCREEN_DATA.colorToApply = 0;
            TITLE_SCREEN_DATA.paletteUpdated = FALSE;
            TITLE_SCREEN_DATA.fadingTimer = 0;

            TITLE_SCREEN_DATA.fadingStage++;
            break;

        case 1:
            if (TITLE_SCREEN_DATA.paletteUpdated)
                break;

            if (TITLE_SCREEN_DATA.colorToApply < 32)
            {
                src = (void*)sEwramPointer + 0x8000;
                dst = (void*)sEwramPointer + 0x8400;
                ApplySpecialBackgroundFadingColor(0, TITLE_SCREEN_DATA.colorToApply, &src, &dst, USHORT_MAX);

                src = (void*)sEwramPointer + 0x8200;
                dst = (void*)sEwramPointer + 0x8600;
                ApplySpecialBackgroundFadingColor(0, TITLE_SCREEN_DATA.colorToApply, &src, &dst, USHORT_MAX);

                TITLE_SCREEN_DATA.paletteUpdated = TRUE;
                if (TITLE_SCREEN_DATA.colorToApply == 31)
                {
                    TITLE_SCREEN_DATA.colorToApply++;
                    break;
                }

                if (TITLE_SCREEN_DATA.colorToApply + 4 > 31)
                    TITLE_SCREEN_DATA.colorToApply = 31;
                else
                    TITLE_SCREEN_DATA.colorToApply += 4;

                break;
            }
            
            DmaTransfer(3, (void*)sEwramPointer + 0x8000, (void*)sEwramPointer + 0x8400, 0x400, 16);
            TITLE_SCREEN_DATA.paletteUpdated = TRUE;
            TITLE_SCREEN_DATA.fadingStage++;
            break;

        case 2:
            if (!TITLE_SCREEN_DATA.paletteUpdated)
            {
                TITLE_SCREEN_DATA.colorToApply = 0;
                TITLE_SCREEN_DATA.fadingStage = 0;
                ended = TRUE;
            }
    }

    return ended;
}

/**
 * @brief 765e0 | 130 | Handles the title screen fading out
 * 
 * @param intensity 
 * @param delay 
 * @return u32 bool, ended
 */
u32 TitleScreenFadingOut(u8 intensity, u8 delay)
{
    u32 ended;
    u16* src;
    u16* dst;

    ended = FALSE;
    APPLY_DELTA_TIME_INC(TITLE_SCREEN_DATA.fadingTimer);
    switch (TITLE_SCREEN_DATA.fadingStage)
    {
        case 0:
            TITLE_SCREEN_DATA.colorToApply = 0;
            TITLE_SCREEN_DATA.paletteUpdated = FALSE;
            TITLE_SCREEN_DATA.fadingTimer = 0;

            TITLE_SCREEN_DATA.fadingStage++;
            break;

        case 1:
            if (TITLE_SCREEN_DATA.paletteUpdated)
                break;

            if (TITLE_SCREEN_DATA.fadingTimer < delay)
                break;

            TITLE_SCREEN_DATA.fadingTimer = 0;
            if (TITLE_SCREEN_DATA.colorToApply < 32)
            {
                src = (void*)sEwramPointer + 0x8000;
                dst = (void*)sEwramPointer + 0x8400;
                ApplySpecialBackgroundFadingColor(COLOR_FADING_CANCEL, TITLE_SCREEN_DATA.colorToApply, &src, &dst, USHORT_MAX);

                src = (void*)sEwramPointer + 0x8200;
                dst = (void*)sEwramPointer + 0x8600;
                ApplySpecialBackgroundFadingColor(COLOR_FADING_CANCEL, TITLE_SCREEN_DATA.colorToApply, &src, &dst, USHORT_MAX);

                TITLE_SCREEN_DATA.paletteUpdated = TRUE;
                if (TITLE_SCREEN_DATA.colorToApply == 31)
                {
                    TITLE_SCREEN_DATA.colorToApply++;
                    break;
                }

                if (TITLE_SCREEN_DATA.colorToApply + intensity > 31)
                    TITLE_SCREEN_DATA.colorToApply = 31;
                else
                    TITLE_SCREEN_DATA.colorToApply += intensity;

                break;
            }
            
            BitFill(3, 0, (void*)sEwramPointer + 0x8400, 0x400, 16);
            TITLE_SCREEN_DATA.paletteUpdated = TRUE;
            TITLE_SCREEN_DATA.fadingStage++;
            break;

        case 2:
            if (!TITLE_SCREEN_DATA.paletteUpdated)
            {
                TITLE_SCREEN_DATA.colorToApply = 0;
                TITLE_SCREEN_DATA.fadingStage = 0;
                ended = TRUE;
            }
    }

    return ended;
}

/**
 * @brief 76710 | 94 | To document
 * 
 * @param param_1 To document
 */
void unk_76710(u8 param_1)
{
    if (!param_1)
    {
        DmaTransfer(3, PALRAM_BASE, (void*)sEwramPointer + 0x8000, 0x400, 16);
        BitFill(3, 0, PALRAM_BASE, PALRAM_SIZE, 16);
        DmaTransfer(3, PALRAM_BASE, (void*)sEwramPointer + 0x8400, 0x400, 16);
    }
    else
        DmaTransfer(3, PALRAM_BASE, (void*)sEwramPointer + 0x8000, 0x400, 16);

    TITLE_SCREEN_DATA.fadingStage = 0;
}

/**
 * @brief 767a4 | 40 | To document
 * 
 */
void unk_767a4(void)
{
    if (TITLE_SCREEN_DATA.paletteUpdated)
    {
        DmaTransfer(3, (void*)sEwramPointer + 0x8400, PALRAM_BASE, 0x400, 16);
        TITLE_SCREEN_DATA.paletteUpdated = FALSE;
    }
}

/**
 * @brief 767e4 | 194 | Updates the animated palettes of the title screen
 * 
 */
void TitleScreenUpdateAnimatedPalette(void)
{
    struct TitleScreenAnimatedPalette* pAnim;

    if (TITLE_SCREEN_DATA.activeAnimatedPalettes & TITLE_SCREEN_ANIMATED_PALETTE_SKY_DECORATIONS)
    {
        pAnim = &TITLE_SCREEN_DATA.animatedPalettes[0];
        pAnim->timer--;
        if (pAnim->timer == 0)
        {
            pAnim->timer = pAnim->maxTimer;
            pAnim->paletteRow++;

            if (pAnim->paletteRow >= ARRAY_SIZE(sTitleScreenSkyDecorationsPaletteRows))
                pAnim->paletteRow = 0;

            DmaTransfer(3, &sTitleScreenPal[sTitleScreenSkyDecorationsPaletteRows[pAnim->paletteRow] * 16], PALRAM_BASE + 0x100, 0x20, 16);
        }
    }

    if (TITLE_SCREEN_DATA.activeAnimatedPalettes & TITLE_SCREEN_ANIMATED_PALETTE_TITLE)
    {
        pAnim = &TITLE_SCREEN_DATA.animatedPalettes[1];
        if (pAnim->unk_4 == 0)
        {
            pAnim->unk_4 = sTitleScreenAnimatedPaletteTemplates[1].unk_4;
            TITLE_SCREEN_DATA.activeAnimatedPalettes ^= TITLE_SCREEN_ANIMATED_PALETTE_TITLE;
        }
        else
        {
            pAnim->timer--;
            if (pAnim->timer == 0)
            {
                pAnim->timer = pAnim->maxTimer;
                pAnim->paletteRow++;

                if (pAnim->paletteRow >= ARRAY_SIZE(sTitleScreenTitlePaletteRows))
                {
                    pAnim->paletteRow = 0;
                    pAnim->unk_4--;
                }

                DmaTransfer(3, &sTitleScreenPal[sTitleScreenTitlePaletteRows[pAnim->paletteRow] * 16 + 1], PALRAM_BASE + 2, 0x1E, 16);
            }
        }
    }

    if (TITLE_SCREEN_DATA.activeAnimatedPalettes & TITLE_SCREEN_ANIMATED_PALETTE_PROMPT)
    {
        pAnim = &TITLE_SCREEN_DATA.animatedPalettes[2];
        if (pAnim->unk_4 != 0)
        {
            pAnim->timer--;
            if (pAnim->timer == 0)
            {
                pAnim->timer = pAnim->maxTimer;
                pAnim->paletteRow++;

                if (pAnim->paletteRow > 1)
                    pAnim->paletteRow = 0;

                pAnim->paletteRow *= 4;
            }

            DmaTransfer(3, &sTitleScreenPromptPal[pAnim->paletteRow * 16], PALRAM_BASE + 0x1A0, 0x18, 16);
        }
        else
        {
            pAnim->timer--;
            if (pAnim->timer == 0)
            {
                pAnim->timer = pAnim->maxTimer;
                pAnim->paletteRow++;

                if (pAnim->paletteRow > 5)
                    pAnim->paletteRow = 0;
            }
            
            DmaTransfer(3, &sTitleScreenPromptPal[sTitleScreenPromptPaletteRows[pAnim->paletteRow] * 16], PALRAM_BASE + 0x1A0, 0x18, 16);
        }
    }
}

/**
 * @brief 76978 | 120 | To document
 * 
 */
void unk_76978(u8 param_1)
{
    if (param_1 & 1)
    {
        DmaTransfer(3, (void*)sEwramPointer + 0x4000, VRAM_BASE + 0x4000, 0x800, 16);
        DmaTransfer(3, (void*)sEwramPointer + 0x4800, VRAM_BASE + 0x4800, 0x800, 16);
    }

    if (param_1 & 2)
    {
        DmaTransfer(3, (void*)sEwramPointer + 0x5000, VRAM_BASE + 0x5000, 0x800, 16);
        DmaTransfer(3, (void*)sEwramPointer + 0x5800, VRAM_BASE + 0x5800, 0x800, 16);
    }

    if (param_1 & 4)
    {
        DmaTransfer(3, (void*)sEwramPointer + 0x6000, VRAM_BASE + 0x6000, 0x800, 16);
        DmaTransfer(3, (void*)sEwramPointer + 0x6800, VRAM_BASE + 0x6800, 0x800, 16);
    }

    if (param_1 & 8)
    {
        DmaTransfer(3, (void*)sEwramPointer + 0x7000, VRAM_BASE + 0x7000, 0x400, 16);
        TITLE_SCREEN_DATA.unk_24 = gBg3VOFS_NonGameplay = BLOCK_SIZE * 12 + HALF_BLOCK_SIZE;
    }
}

/**
 * @brief 76a98 | c8 | To document
 * 
 * @return u32 bool, ended
 */
u32 unk_76a98(void)
{
    u32 ended;

    ended = FALSE;
    switch (TITLE_SCREEN_DATA.unk_E)
    {
        case 0:
            break;

        case 1:
            TITLE_SCREEN_DATA.oamTimings[0].stage = 16;
            TITLE_SCREEN_DATA.oamTimings[1].stage = 16;

            TITLE_SCREEN_DATA.dispcnt &= ~sTitleScreenPageData[0].bg;
            TITLE_SCREEN_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

            TITLE_SCREEN_DATA.unk_E++;
            break;

        case 2:
            gWrittenToBldy_NonGameplay += 4;
            if (gWrittenToBldy_NonGameplay >= BLDY_MAX_VALUE)
            {
                gWrittenToBldy_NonGameplay = BLDY_MAX_VALUE;
                TITLE_SCREEN_DATA.unk_E++;
            }
            break;

        case 3:
        case 4:
        case 5:
        case 6:
            unk_76978(1 << (TITLE_SCREEN_DATA.unk_E - 3));
            TITLE_SCREEN_DATA.unk_E++;
            break;

        case 7:
            if (gWrittenToBldy_NonGameplay >= 9)
            {
                gWrittenToBldy_NonGameplay -= 8;
                break;
            }

            gWrittenToBldy_NonGameplay = 0;
            TITLE_SCREEN_DATA.unk_E = 0;
            ended = TRUE;
            break;
    }

    return ended;
}

/**
 * @brief 76b60 | 194 | Handles the comet view part of the title screen
 * 
 * @return u32 bool, ended
 */
u32 TitleScreenCometsView(void)
{
    u32 ended;
    s32 screenOffset;

    screenOffset = 0;
    ended = FALSE;
    APPLY_DELTA_TIME_INC(TITLE_SCREEN_DATA.cometsTimer);

    if (gChangedInput & (KEY_A | KEY_START))
    {
        TITLE_SCREEN_DATA.unk_E = 1;
        return FALSE;
    }

    switch (TITLE_SCREEN_DATA.cometsStage)
    {
        case 0:
            TITLE_SCREEN_DATA.cometsStage++;
            TITLE_SCREEN_DATA.cometsTimer = 0;
            break;

        case 1:
            // Wait
            if (TITLE_SCREEN_DATA.cometsTimer > CONVERT_SECONDS(1.f))
            {
                // Spawn first comet
                TITLE_SCREEN_DATA.type |= TITLE_SCREEN_TYPE_FIRST_COMET_ACTIVE;
                TITLE_SCREEN_DATA.oamTimings[0].stage = 0;
                TITLE_SCREEN_DATA.oamTimings[0].timer = 0;

                TITLE_SCREEN_DATA.cometsStage++;
                TITLE_SCREEN_DATA.cometsTimer = 0;
            }
            break;

        case 2:
            // Wait
            if (TITLE_SCREEN_DATA.cometsTimer > CONVERT_SECONDS(2.f))
            {
                // Spawn second comet
                TITLE_SCREEN_DATA.type |= TITLE_SCREEN_TYPE_SECOND_COMET_ACTIVE;
                TITLE_SCREEN_DATA.oamTimings[1].stage = 0;
                TITLE_SCREEN_DATA.oamTimings[1].timer = 0;

                TITLE_SCREEN_DATA.cometsStage++;
                TITLE_SCREEN_DATA.cometsTimer = 0;
            }
            break;

        case 3:
            // Wait
            if (TITLE_SCREEN_DATA.cometsTimer > CONVERT_SECONDS(.5f))
            {
                TITLE_SCREEN_DATA.cometsStage++;
                TITLE_SCREEN_DATA.cometsTimer = 0;
            }
            break;

        case 4:
            // Scroll screen
            if (gBg3VOFS_NonGameplay >= BLOCK_SIZE * 12 + HALF_BLOCK_SIZE)
            {
                gBg3VOFS_NonGameplay = BLOCK_SIZE * 12 + HALF_BLOCK_SIZE;
                TITLE_SCREEN_DATA.cometsStage++;
                break;
            }

            if (BLOCK_SIZE * 12 + HALF_BLOCK_SIZE - gBg3VOFS_NonGameplay < 9)
                screenOffset += PIXEL_SIZE / 2;
            else
                screenOffset += PIXEL_SIZE;
            break;

        default:
            ended = TRUE;
            break;
    }

    if (!ended)
    {
        screenOffset += gBg3VOFS_NonGameplay;
        if (screenOffset > BLOCK_SIZE * 12 + HALF_BLOCK_SIZE)
            screenOffset = BLOCK_SIZE * 12 + HALF_BLOCK_SIZE;
        else if (screenOffset < 0)
            screenOffset = 0;

        gBg3VOFS_NonGameplay = screenOffset;

        TitleScreenTransferGroundGraphics();
    }

    TITLE_SCREEN_DATA.unk_24 = gBg3VOFS_NonGameplay;

    return ended;
}

/**
 * @brief 76cf4 | 9c | Transfers the ground graphics
 * 
 */
void TitleScreenTransferGroundGraphics(void)
{
    s32 var_0;
    s32 var_1;
    u8* src;

    #ifdef BUGFIX
    src = NULL;
    #endif // BUGFIX

    var_0 = -1;
    var_1 = -1;

    if (TITLE_SCREEN_DATA.unk_24 != gBg3VOFS_NonGameplay)
    {
        if (TITLE_SCREEN_DATA.unk_24 < gBg3VOFS_NonGameplay)
        {
            if (gBg3VOFS_NonGameplay >= (BLOCK_SIZE * 5 + HALF_BLOCK_SIZE))
            {
                var_0 = (gBg3VOFS_NonGameplay - (BLOCK_SIZE * 5 + HALF_BLOCK_SIZE)) >> 5;
                var_1 = (TITLE_SCREEN_DATA.unk_24 - (BLOCK_SIZE * 5 + HALF_BLOCK_SIZE)) >> 5;
                src = (void*)sEwramPointer + 0x4000;
            }
        }
        else
        {
            if (gBg3VOFS_NonGameplay <= (BLOCK_SIZE * 7 + HALF_BLOCK_SIZE))
            {
                var_0 = 13 - (((BLOCK_SIZE * 7 + HALF_BLOCK_SIZE) - gBg3VOFS_NonGameplay) >> 5);
                var_1 = 13 - (((BLOCK_SIZE * 7 + HALF_BLOCK_SIZE) - TITLE_SCREEN_DATA.unk_24) >> 5);
                src = (void*)sEwramPointer;
            }
        }
    }

    if (var_0 < 14u && var_0 != var_1)
    {
        var_0 *= 0x400;
        DmaTransfer(3, src + var_0, VRAM_BASE + 0x4000 + var_0, 0x400, 16);
    }
}

/**
 * @brief 76d90 | 88 | Processes the comets and the sparkles
 * 
 */
void TitleScreenProcessOAM(void)
{
    if (TITLE_SCREEN_DATA.type & TITLE_SCREEN_TYPE_TOP_SPARKLE_ACTIVE)
        TitleScreenProcessTopSparkle(&TITLE_SCREEN_DATA.oamTimings[0], &TITLE_SCREEN_DATA.oam[5]);
    else if (TITLE_SCREEN_DATA.type & TITLE_SCREEN_TYPE_FIRST_COMET_ACTIVE)
        TitleScreenProcessComets(&TITLE_SCREEN_DATA.oamTimings[0], &TITLE_SCREEN_DATA.oam[5], 0);

    if (TITLE_SCREEN_DATA.type & TITLE_SCREEN_TYPE_BOTTOM_SPARKLE_ACTIVE)
    {
        if (TitleScreenProcessBottomSparkle(&TITLE_SCREEN_DATA.oamTimings[1], &TITLE_SCREEN_DATA.oam[6]))
        {
            UpdateMenuOamDataID(&TITLE_SCREEN_DATA.oam[5], TITLE_SCREEN_OAM_ID_SPARKLE_GROWING);
            UpdateMenuOamDataID(&TITLE_SCREEN_DATA.oam[6], TITLE_SCREEN_OAM_ID_SPARKLE_GROWING);
        }
    }
    else if (TITLE_SCREEN_DATA.type & TITLE_SCREEN_TYPE_SECOND_COMET_ACTIVE)
        TitleScreenProcessComets(&TITLE_SCREEN_DATA.oamTimings[1], &TITLE_SCREEN_DATA.oam[6], 1);
}

/**
 * @brief 76e18 | 174 | Processes a comet
 * 
 * @param pTiming OAM Timing pointer
 * @param pOam Menu OAM pointer
 * @param cometNumber Comet number
 */
void TitleScreenProcessComets(struct TitleScreenOamTiming* pTiming, struct MenuOamData* pOam, u8 cometNumber)
{
    u32 movement;
    u32 xLimit;
    u32 yLimit;

    pTiming->timer++;
    
    switch (pTiming->stage)
    {
        case 0:
            // Set starting position
            if (cometNumber == 0)
            {
                pOam->yPosition = BLOCK_SIZE * 2;
                pOam->xPosition = BLOCK_SIZE * 8;
            }
            else
            {
                pOam->yPosition = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
                pOam->xPosition = BLOCK_SIZE * 13 + 8;
            }

            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
            pOam->oamID = TITLE_SCREEN_OAM_ID_COMET_SPAWNING;

            pOam->exists = TRUE;
            pOam->boundBackground = 3;
            pOam->notDrawn = FALSE;

            pTiming->stage++;
            pTiming->timer = 0;
            break;

        case 1:
            // Wait
            if (pTiming->timer > 20)
            {
                pOam->oamID = TITLE_SCREEN_OAM_ID_COMET_APPEARING;
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 2:
            // Wait for animation to end
            if (pOam->oamID == TITLE_SCREEN_OAM_ID_COMET_FLYING)
            {
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 3:
            movement = pTiming->timer + 8;

            // Move comet
            pOam->xPosition -= movement;
            pOam->yPosition += movement;

            // Check out of bounds
            yLimit = pOam->yPosition - (s16)gBg3VOFS_NonGameplay;
            xLimit = pOam->xPosition - (s16)gBg3HOFS_NonGameplay;

            pOam->notDrawn = FALSE;

            if (yLimit + BLOCK_SIZE * 2 > BLOCK_SIZE * 14)
                pOam->notDrawn = TRUE;

            if (xLimit + BLOCK_SIZE * 2 > BLOCK_SIZE * 19)
                pOam->notDrawn = TRUE;

            if (pOam->notDrawn)
            {
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 4:
            // Set comet to be inactive
            TITLE_SCREEN_DATA.type ^= sTitleScreenCometsFlags[cometNumber][0]; // Active flag
            TITLE_SCREEN_DATA.type |= sTitleScreenCometsFlags[cometNumber][1]; // Ended flag
            break;

        default:
            TITLE_SCREEN_DATA.type &= ~sTitleScreenCometsFlags[cometNumber][0];
            pOam->notDrawn = TRUE;
            break;
    }
}

/**
 * @brief 76f8c | 88 | Processes the top sparkle
 * 
 * @param pTiming OAM Timing pointer
 * @param pOam Menu OAM pointer
 */
void TitleScreenProcessTopSparkle(struct TitleScreenOamTiming* pTiming, struct MenuOamData* pOam)
{
    pTiming->timer++;

    switch (pTiming->stage)
    {
        case 0:
            // Initialize OAM
            DmaTransfer(3, &sTitleScreenTopSparkleBaseOam, pOam, sizeof(sTitleScreenTopSparkleBaseOam), 16);
            pTiming->stage++;
            pTiming->timer = 0;
            break;

        case 1:
            // Wait
            if (pTiming->timer > TITLE_SCREEN_SPARKLE_DELAY)
            {
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 2:
            // Move to the right
            pOam->xPosition += 12;

            // Check animation has ended
            if (pOam->oamID == 0)
            {
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 3:
            // Set sparkle to be inactive
            TITLE_SCREEN_DATA.type ^= TITLE_SCREEN_TYPE_TOP_SPARKLE_ACTIVE;
            TITLE_SCREEN_DATA.type |= TITLE_SCREEN_TYPE_TOP_SPARKLE_ENDED;
    }
}

/**
 * @brief 77014 | e4 | Processes the bottom sparkle
 * 
 * @param pTiming OAM Timing pointer
 * @param pOam Menu OAM pointer
 * @return u32 bool, OAM id update needed
 */
u32 TitleScreenProcessBottomSparkle(struct TitleScreenOamTiming* pTiming, struct MenuOamData* pOam)
{
    u32 idUpdate;

    idUpdate = FALSE;

    pTiming->timer++;
    switch (pTiming->stage)
    {
        case 0:
            // Initialize OAM
            DmaTransfer(3, &sTitleScreenBottomSparkleBaseOam, pOam, sizeof(sTitleScreenBottomSparkleBaseOam), 16);
            pTiming->stage++;
            pTiming->timer = 0;
            break;

        case 1:
            // Wait
            if (pTiming->timer > TITLE_SCREEN_SPARKLE_DELAY)
            {
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;
        
        case 2:
            // Move to the left
            pOam->xPosition -= PIXEL_SIZE * 3;
            if (pOam->xPosition <= BLOCK_SIZE * 11 + HALF_BLOCK_SIZE)
            {
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 3:
            // Move down
            pOam->yPosition += EIGHTH_BLOCK_SIZE;
            if (pOam->yPosition >= BLOCK_SIZE * 5 + THREE_QUARTER_BLOCK_SIZE)
            {
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 4:
            // Move to the left
            pOam->xPosition -= PIXEL_SIZE * 3;
            if (pOam->xPosition <= BLOCK_SIZE * 10)
            {
                // Flag an OAM id update for both sparkles 
                idUpdate = TRUE;
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 5:
            // Move to the left
            pOam->xPosition -= PIXEL_SIZE * 3;
            // Check animation has ended
            if (pOam->oamID == 0)
            {
                pTiming->stage++;
                pTiming->timer = 0;
            }
            break;

        case 6:
            // Set sparkle to be inactive
            TITLE_SCREEN_DATA.type ^= TITLE_SCREEN_TYPE_BOTTOM_SPARKLE_ACTIVE;
            TITLE_SCREEN_DATA.type |= TITLE_SCREEN_TYPE_BOTTOM_SPARKLE_ENDED;
    }

    return idUpdate;
}

/**
 * @brief 770f8 | a8 | Checks if a demo should play
 * 
 * @return u32 0 = Nothing, 1 = Input, 2 = Demo start
 */
u32 TitleScreenCheckPlayEffects(void)
{
    #ifdef REGION_EU
    u32 tmp1;
    u32 tmp2;
    #endif // REGION_EU

    TITLE_SCREEN_DATA.demoTimer++;
    if (TITLE_SCREEN_DATA.demoTimer > 60 * 17)
        return 2;

    TITLE_SCREEN_DATA.effectsTimer++;
    if ((TITLE_SCREEN_DATA.type & TITLE_SCREEN_TYPE_ALL_SPARKLES_ENDED) == TITLE_SCREEN_TYPE_ALL_SPARKLES_ENDED)
    {
        // Restart timer
        TITLE_SCREEN_DATA.effectsTimer = 0;
        TITLE_SCREEN_DATA.type ^= TITLE_SCREEN_TYPE_ALL_SPARKLES_ENDED;
    }
    else if (TITLE_SCREEN_DATA.effectsTimer == 60 * 4)
    {
        // Start title animated palette
        TITLE_SCREEN_DATA.activeAnimatedPalettes |= TITLE_SCREEN_ANIMATED_PALETTE_TITLE;
    }
    else if (TITLE_SCREEN_DATA.effectsTimer == 60 * 6)
    {
        // Start sparkles
        TITLE_SCREEN_DATA.type |= TITLE_SCREEN_TYPE_TOP_SPARKLE_ACTIVE | TITLE_SCREEN_TYPE_BOTTOM_SPARKLE_ACTIVE;
        TITLE_SCREEN_DATA.oamTimings[0].stage = 0;
        TITLE_SCREEN_DATA.oamTimings[0].timer = 0;
        TITLE_SCREEN_DATA.oamTimings[1].stage = 0;
        TITLE_SCREEN_DATA.oamTimings[1].timer = 0;
    }

    if (!TITLE_SCREEN_DATA.unk_F)
    {
        if (TITLE_SCREEN_DATA.timer > 30)
            TITLE_SCREEN_DATA.unk_F = TRUE;
    }
    else if (gChangedInput & (KEY_A | KEY_START))
    {
        #ifdef REGION_EU
        tmp1 = TITLE_SCREEN_DATA.oamTimings[2].menuOption != TITLE_SCREEN_MENU_OPTION_START_GAME ? 3 : 1;
        tmp2 = tmp1;
        return tmp2;
        #else // !REGION
        return 1;
        #endif // REGION_EU
    }

    #ifdef REGION_EU
    if (gChangedInput & (KEY_UP | KEY_DOWN))
    {
        tmp2 = FALSE;

        if (gChangedInput & KEY_UP && TITLE_SCREEN_DATA.oamTimings[2].menuOption != TITLE_SCREEN_MENU_OPTION_START_GAME)
        {
            TITLE_SCREEN_DATA.oamTimings[2].menuOption = TITLE_SCREEN_MENU_OPTION_START_GAME;
            tmp2 = TRUE;
        }
        else if (gChangedInput & KEY_DOWN && TITLE_SCREEN_DATA.oamTimings[2].menuOption == TITLE_SCREEN_MENU_OPTION_START_GAME)
        {
            TITLE_SCREEN_DATA.oamTimings[2].menuOption = TITLE_SCREEN_MENU_OPTION_LANGUAGE;
            tmp2 = TRUE;
        }

        if (tmp2)
        {
            SoundPlay(0x1FA);
            TitleScreenSetMenuPalette(TITLE_SCREEN_DATA.oamTimings[2].menuOption);
            TITLE_SCREEN_DATA.demoTimer = 0;
        }
    }
    #endif // REGION_EU

    #ifdef DEBUG
    if (gChangedInput & KEY_L)
        return 2;

    if (gButtonInput & KEY_SELECT)
    {
        if (gChangedInput & KEY_RIGHT)
            TitleScreenSetCopyrightSymbol(TITLE_SCREEN_COPYRIGHT_SYMBOL_REGISTERED_TRADEMARK);
        else if (gChangedInput & KEY_LEFT)
            TitleScreenSetCopyrightSymbol(TITLE_SCREEN_COPYRIGHT_SYMBOL_TRADEMARK);
    }

    if (gChangedInput & KEY_SELECT)
        BitFill(3, 0, VRAM_BASE + 0xF800, 0x800, 16);
    #endif // DEBUG

    return 0;
}

/**
 * @brief 771a0 | 178 | Main loop for the title screen
 * 
 * @return u32 bool, leaving
 */
u32 TitleScreenMainLoop(void)
{
    u32 leaving;
    u32 ret;

    leaving = FALSE;
    TITLE_SCREEN_DATA.timer++;

    switch (gSubGameMode1)
    {
        case 0:
            TitleScreenInit();
            gSubGameMode1 = 1;
            TITLE_SCREEN_DATA.timer = 0;
            break;

        case 1:
            unk_767a4();
            if (TitleScreenFadingIn())
            {
                UpdateMusicPriority(2);
                PlayMusic(MUSIC_TITLE_SCREEN, 2);
                TITLE_SCREEN_DATA.timer = 0;
                gSubGameMode1++;
            }
            break;

        case 2:
            ret = TitleScreenIdle();
            gSubGameMode2 = ret;
            if (gSubGameMode2 != 0)
            {
                TITLE_SCREEN_DATA.timer = 0;
                if (gSubGameMode2 == 2)
                {
                    UpdateMusicPriority(4);
                    gSubGameMode1 = 3;
                }
                #ifdef DEBUG
                #ifdef REGION_EU
                else if (gSubGameMode2 == 4)
                #else // !REGION_EU
                else if (gSubGameMode2 == 3)
                #endif // REGION_EU
                {
                    gSubGameMode1 = 5;
                }
                #endif // DEBUG
                else
                {
                    #ifdef REGION_EU
                    if (gSubGameMode2 == 3)
                    {
                        SoundPlay(SOUND_ACCEPT_CONFIRM_MENU);
                    }
                    else
                    #endif // REGION_EU
                    {
                        SoundPlay(SOUND_TITLE_SCREEN_PRESSING_START);
                    }
                    TITLE_SCREEN_DATA.animatedPalettes[2] = sTitleScreenAnimatedPaletteTemplates[3];
                    gSubGameMode1 = 3;
                }

                if (TITLE_SCREEN_DATA.animatedPalettes[1].unk_4 != 0)
                    TITLE_SCREEN_DATA.animatedPalettes[1].unk_4 = 1;

                gDemoState = DEMO_STATE_NONE;
            }

            TitleScreenUpdateAnimatedPalette();
            TitleScreenProcessOAM();
            break;

        case 3:
            TitleScreenUpdateAnimatedPalette();
            TitleScreenProcessOAM();

            if (TITLE_SCREEN_DATA.animatedPalettes[2].paletteRow == 0 && TITLE_SCREEN_DATA.timer > 40)
            {
                unk_76710(TRUE);
                gSubGameMode1++;
                TITLE_SCREEN_DATA.timer = 0;
            }
            break;

        case 4:
            unk_767a4();
            if (TitleScreenFadingOut(1, 1))
                leaving = TRUE;
            break;

        case 5:
            #ifdef DEBUG
            unk_767a4();
            if (TitleScreenFadingOut(2, 0))
                leaving = TRUE;
            #endif // DEBUG
            break;
    }

    if (!leaving)
        TitleScreenCallProcessOAM();

    return leaving;
}

/**
 * @brief 77318 | b0 | Handles the title screen being idle
 * 
 * @return u32 0 = Nothing, 1 = Input, 2 = Demo start
 */
u32 TitleScreenIdle(void)
{
    u32 ret;

    ret = 0;

    switch (TITLE_SCREEN_DATA.oamTimings[2].stage)
    {
        case TITLE_SCREEN_IDLE_STAGE_COMETS:
            if (TITLE_SCREEN_DATA.unk_E != 0)
            {
                if (unk_76a98())
                    TitleScreenSetIdleStage(TITLE_SCREEN_IDLE_STAGE_IDLE);
            }
            else
            {
                if (TitleScreenCometsView())
                    TitleScreenSetIdleStage(TITLE_SCREEN_IDLE_STAGE_TITLE_FADING);
            }
            break;

        case TITLE_SCREEN_IDLE_STAGE_TITLE_FADING:
            if (gChangedInput != KEY_NONE)
            {
                gWrittenToBldalpha_L = 16;
                gWrittenToBldalpha_H = 0;
            }
            else if (TITLE_SCREEN_DATA.timer % 10 == 0)
            {
                if (gWrittenToBldalpha_L >= 16)
                {
                    TitleScreenSetIdleStage(TITLE_SCREEN_IDLE_STAGE_IDLE);
                    break;
                }
                
                gWrittenToBldalpha_L++;
                gWrittenToBldalpha_H = 16 - gWrittenToBldalpha_L;
            }

            if (gWrittenToBldalpha_L >= 16)
                TitleScreenSetIdleStage(TITLE_SCREEN_IDLE_STAGE_IDLE);
            break;

        case TITLE_SCREEN_IDLE_STAGE_IDLE:
            ret = (s8)TitleScreenCheckPlayEffects();
    }

    return ret;
}

/**
 * @brief 773c8 | 94 | Sets the idle stage for the title screen
 * 
 * @param stage 
 */
void TitleScreenSetIdleStage(u8 stage)
{
    TITLE_SCREEN_DATA.oamTimings[2].stage = stage;

    switch (TITLE_SCREEN_DATA.oamTimings[2].stage)
    {
        case 1:
            TITLE_SCREEN_DATA.dispcnt |= sTitleScreenPageData[1].bg | sTitleScreenPageData[0].bg;

            TITLE_SCREEN_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG0_SECOND_TARGET_PIXEL |
                BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL |
                BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            TITLE_SCREEN_DATA.timer = 0;
            gWrittenToBldalpha_L = 0;
            gWrittenToBldalpha_H = 16;
            break;

        case 2:
            TITLE_SCREEN_DATA.dispcnt |= sTitleScreenPageData[1].bg | sTitleScreenPageData[0].bg;

            TITLE_SCREEN_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG0_SECOND_TARGET_PIXEL |
                BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL |
                BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            gWrittenToBldalpha_L = 16;
            gWrittenToBldalpha_H = 0;
            TITLE_SCREEN_DATA.effectsTimer = 210;
            TITLE_SCREEN_DATA.unk_F = FALSE;
            TITLE_SCREEN_DATA.timer = 0;
            break;
    }
}

/**
 * @brief 7745c | 2a0 | Initializes the title screen
 * 
 */
void TitleScreenInit(void)
{
    CallbackSetVblank(TitleScreenVBlank_Empty);

    #ifdef REGION_EU
    BitFill(3, 0, &gNonGameplayRam, sizeof(gNonGameplayRam), 32);
    #else // !REGION_EU
    DMA_FILL_32(3, 0, &gNonGameplayRam, sizeof(gNonGameplayRam))
    #endif // REGION_EU

    TITLE_SCREEN_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

    WRITE_16(REG_BLDCNT, TITLE_SCREEN_DATA.bldcnt);

    WRITE_16(REG_BLDY, gWrittenToBldy_NonGameplay = BLDY_MAX_VALUE);

    WRITE_16(REG_DISPCNT, TITLE_SCREEN_DATA.dispcnt = 0);

    gNextOamSlot = 0;

    ClearGfxRam();
    ResetFreeOam();
    
    gOamXOffset_NonGameplay = gOamYOffset_NonGameplay = 0;

    #ifdef REGION_EU
    BitFill(3, 0, &gSamusPhysics, sizeof(gSamusPhysics), 32);
    #else // !REGION_EU
    DMA_FILL_32(3, 0, &gSamusPhysics, sizeof(gSamusPhysics));
    #endif // REGION_EU

    gBootDebugActive = FALSE;
    gDebugMode = FALSE;

    StopAllMusicAndSounds();

    DmaTransfer(3, sTitleScreenPal, PALRAM_BASE, sizeof(sTitleScreenPal), 16);
    DmaTransfer(3, sTitleScreenPal, PALRAM_OBJ, sizeof(sTitleScreenPal), 16);

    SET_BACKDROP_COLOR(COLOR_BLACK);

    #ifdef REGION_EU
    DmaTransfer(3, &sTitleScreenUnselectedMenuPal, PALRAM_BASE + 0x1E0, sizeof(sTitleScreenUnselectedMenuPal), 16);
    TITLE_SCREEN_DATA.oamTimings[2].menuOption = TITLE_SCREEN_MENU_OPTION_START_GAME;
    #endif // REGION_EU

    TitleScreenLoadPageData(&sTitleScreenPageData[0]);
    TitleScreenLoadPageData(&sTitleScreenPageData[1]);

    // JP uses the registered trademark symbol, while non-JP uses the trademark symbol.
    // Debug allows any language, so it checks the language to decide which to use.
    #if defined(DEBUG) || !defined(REGION_JP)
    #if defined(DEBUG)
    if (gLanguage >= LANGUAGE_ENGLISH)
    #endif // DEBUG
    {
        TitleScreenSetCopyrightSymbol(TITLE_SCREEN_COPYRIGHT_SYMBOL_TRADEMARK);
    }
    #endif // DEBUG || !REGION_JP
    #if defined(DEBUG) || defined(REGION_JP)
    #if defined(DEBUG)
    else
    #endif // DEBUG
    {
        TitleScreenSetCopyrightSymbol(TITLE_SCREEN_COPYRIGHT_SYMBOL_REGISTERED_TRADEMARK);
    }
    #endif // DEBUG || REGION_JP

    CallLZ77UncompVram(sTitleScreenTitleGfx, VRAM_BASE + 0xC000);
    CallLZ77UncompVram(sTitleScreenSpaceBackgroundGfx, VRAM_BASE + 0x4000);
    CallLZ77UncompVram(sTitleScreenSpaceBackgroundDecorationGfx, VRAM_BASE + 0xA400);
    CallLZ77UncompWram(sTitleScreenSpaceAndGroundBackgroundGfx, (void*)sEwramPointer + 0x4000);

    DmaTransfer(3, VRAM_BASE + 0x4000, (void*)sEwramPointer, 0x4000, 16);

    CallLZ77UncompVram(sTitleScreenSparklesGfx, VRAM_OBJ);

    #ifdef REGION_EU
    CallLZ77UncompVram(sTitleScreenMenuGfxPointers[(gLanguage - LANGUAGE_ENGLISH) * 2], VRAM_BASE + 0xE800);
    CallLZ77UncompVram(sTitleScreenMenuGfxPointers[(gLanguage - LANGUAGE_ENGLISH) * 2 + 1], VRAM_BASE + 0xEC00);
    TitleScreenSetMenuPalette(TITLE_SCREEN_DATA.oamTimings[2].menuOption);
    #endif // REGION_EU

    // Undefined
    TitleScreenSetBGCNTPageData(&sTitleScreenPageData[0]);
    TitleScreenSetBGCNTPageData(&sTitleScreenPageData[1]);

    #ifdef DEBUG
    if (sRomInfoStringPointers[0][0] != '\0')
        TitleScreenDrawDebugText();
    #endif // DEBUG

    gSubGameMode3 = 0;
    gBg0HOFS_NonGameplay = gBg0VOFS_NonGameplay = 0;
    gBg1HOFS_NonGameplay = gBg1VOFS_NonGameplay = 0;
    gBg2HOFS_NonGameplay = gBg2VOFS_NonGameplay = 0;
    gBg3HOFS_NonGameplay = gBg3VOFS_NonGameplay = 0;

    gWrittenToBldalpha_H = 16;
    gWrittenToBldalpha_L = 0;

    TITLE_SCREEN_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET;

    TITLE_SCREEN_DATA.demoTimer = 0;

    if (gSubGameMode2 == 0)
    {
        TITLE_SCREEN_DATA.oamTimings[2].stage = TITLE_SCREEN_IDLE_STAGE_COMETS;
    }
    else
    {
        unk_76978(UCHAR_MAX);
        TITLE_SCREEN_DATA.oamTimings[2].stage = TITLE_SCREEN_IDLE_STAGE_IDLE;

        TITLE_SCREEN_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET;
        
        gWrittenToBldalpha_L = 16;
        gWrittenToBldalpha_H = 0;

        TITLE_SCREEN_DATA.effectsTimer = 210;
        TITLE_SCREEN_DATA.unk_F = FALSE;
        TITLE_SCREEN_DATA.timer = 0;
    }

    TitleScreenResetOAM();
    TitleScreenCallProcessOAM();
    TitleScreenVBlank();
    unk_76710(FALSE);

    // Set active animated palettes
    TITLE_SCREEN_DATA.activeAnimatedPalettes = TITLE_SCREEN_ANIMATED_PALETTE_SKY_DECORATIONS | TITLE_SCREEN_ANIMATED_PALETTE_PROMPT;

    TITLE_SCREEN_DATA.animatedPalettes[0] = sTitleScreenAnimatedPaletteTemplates[0];
    TITLE_SCREEN_DATA.animatedPalettes[1] = sTitleScreenAnimatedPaletteTemplates[1];
    TITLE_SCREEN_DATA.animatedPalettes[2] = sTitleScreenAnimatedPaletteTemplates[2];

    WRITE_16(REG_DISPCNT, TITLE_SCREEN_DATA.dispcnt = DCNT_OBJ | sTitleScreenPageData[0].bg | sTitleScreenPageData[1].bg);

    CallbackSetVblank(TitleScreenVBlank);
}

/**
 * @brief 776fc | d0 | Title screen V-blank code
 * 
 */
void TitleScreenVBlank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16(DMA_ENABLE | DMA_32BIT, OAM_SIZE / sizeof(u32)));

    WRITE_16(REG_BG0HOFS, SUB_PIXEL_TO_PIXEL(gBg0HOFS_NonGameplay));
    WRITE_16(REG_BG0VOFS, SUB_PIXEL_TO_PIXEL(gBg0VOFS_NonGameplay));

    WRITE_16(REG_BG1HOFS, SUB_PIXEL_TO_PIXEL(gBg1HOFS_NonGameplay));
    WRITE_16(REG_BG1VOFS, SUB_PIXEL_TO_PIXEL(gBg1VOFS_NonGameplay));

    WRITE_16(REG_BG2HOFS, SUB_PIXEL_TO_PIXEL(gBg2HOFS_NonGameplay));
    WRITE_16(REG_BG2VOFS, SUB_PIXEL_TO_PIXEL(gBg2VOFS_NonGameplay));

    WRITE_16(REG_BG3HOFS, SUB_PIXEL_TO_PIXEL(gBg3HOFS_NonGameplay));
    WRITE_16(REG_BG3VOFS, SUB_PIXEL_TO_PIXEL(gBg3VOFS_NonGameplay));

    WRITE_16(REG_DISPCNT, TITLE_SCREEN_DATA.dispcnt);
    WRITE_16(REG_BLDY, gWrittenToBldy_NonGameplay);
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_H, gWrittenToBldalpha_L));
    WRITE_16(REG_BLDCNT, TITLE_SCREEN_DATA.bldcnt);
}

/**
 * @brief 777cc | c | Empty v-blank for the title screen
 * 
 */
void TitleScreenVBlank_Empty(void)
{
    vu8 c = 0;
}

#ifdef REGION_EU
/**
 * @brief Sets the palette for "Start Game" and "Language" on the title screen
 * 
 * @param option Which option is selected
 */
static void TitleScreenSetMenuPalette(TitleScreenMenuOption option)
{
    s32 temp;
    u16* dst1;
    u16* dst2;
    u16 i;

    // Set "Start Game" palette
    dst1 = VRAM_BASE + 0x352 + sTitleScreenPageData[0].tiletablePage * 0x800;
    dst2 = dst1 + 0x20;

    if (option == TITLE_SCREEN_MENU_OPTION_START_GAME)
    {
        for (i = 0; i < 12; i++, dst1++, dst2++)
        {
            *dst1 = (*dst1 & 0x3FF) | 0xD000;
            *dst2 = (*dst2 & 0x3FF) | 0xD000;
        }
    }
    else
    {
        for (i = 0; i < 12; i++, dst1++, dst2++)
        {
            *dst1 |= 0xF000;
            *dst2 |= 0xF000;
        }
    }

    // Set "Language" palette
    dst1 = VRAM_BASE + 0x3D6 + sTitleScreenPageData[0].tiletablePage * 0x800;
    dst2 = dst1 + 0x20;

    if (option != TITLE_SCREEN_MENU_OPTION_START_GAME)
    {
        for (i = 0; i < 8; i++, dst1++, dst2++)
        {
            *dst1 = (*dst1 & 0x3FF) | 0xD000;
            *dst2 = (*dst2 & 0x3FF) | 0xD000;
        }
    }
    else
    {
        for (i = 0; i < 8; i++, dst1++, dst2++)
        {
            *dst1 |= 0xF000;
            *dst2 |= 0xF000;
        }
    }
}
#endif // REGION_EU

/**
 * @brief 777d8 | 4c | Changes the copyright symbol
 * 
 * @param symbol Which symbol to use
 */
void TitleScreenSetCopyrightSymbol(TitleScreenCopyrightSymbol symbol)
{
    s32 i;
    u32 value;
    u32 bgOffset;
    u16* dst;
    u32 mask;
    u32 temp;

    bgOffset = sTitleScreenPageData[0].tiletablePage * 2048;

    if (symbol == TITLE_SCREEN_COPYRIGHT_SYMBOL_NONE)
        return;

    if (symbol == TITLE_SCREEN_COPYRIGHT_SYMBOL_TRADEMARK)
        temp = 0x12D;
    else
        temp = 0x10D;
    value = temp;
    
    i = 0;
    mask = 0xFC00;
    dst = VRAM_BASE + 0x178 + bgOffset;

    while (i < 2)
    {
        *dst++ = (*dst & mask) | (value + i);

        i++;
    }
}

/**
 * @brief 77824 | a0 | Draws a string to the title screen (for debugging purposes)
 * 
 * @param pString String pointer
 * @param dst Destination pointer
 * @param palette Palette
 */
void TitleScreenDrawString(const u8* pString, u16* dst, u8 palette)
{
    u16 tile;

    while (*pString)
    {
        if (*pString != ' ')
        {
            if (*pString >= '0' && *pString <= '9')
                tile = *pString - '0';
            else if (*pString >= 'A' && *pString <= 'Z')
                tile = *pString - 'A' + 10;
            else if (*pString == ':')
                tile = 0x24;
            else if (*pString == '_')
                tile = 0x25;
            else if (*pString == '/')
                tile = 0x26;
            else if (*pString >= 'a' && *pString <= 'z')
                tile = *pString - 'a' + 10;
            else
                tile = 0x8000;
        }
        else
        {
            tile = 0x8000;
        }

        if (tile != 0x8000)
            *dst = (palette << 0xC) | (tile + 0x1C0);

        dst++;
        pString++;
    }
}

#ifdef DEBUG

#ifdef REGION_EU
#define STRING_PAL_ROW 14
#else // !REGION_EU
#define STRING_PAL_ROW 15
#endif // REGION_EU

void TitleScreenDrawDebugText(void)
{
    s32 i;
    u8 string[5];
    
    DmaTransfer(3, sCharactersGfx, VRAM_BASE + 0xF800, 0x800, 16);
    #ifndef REGION_EU
    DmaTransfer(3, sGameOverMenuPal + 1 * PAL_ROW_SIZE, PALRAM_BASE + 15 * PAL_ROW_SIZE, 1 * PAL_ROW_SIZE, 16);
    #endif // !REGION_EU
    TitleScreenDrawString(sRomInfoStringPointers[0], VRAM_BASE + sTitleScreenPageData[0].tiletablePage * 0x800, STRING_PAL_ROW);

    for (i = 0; i < 4; i++)
        string[i] = game_code[i];
    string[4] = '\0';

    TitleScreenDrawString(string, VRAM_BASE + 0x40 + sTitleScreenPageData[0].tiletablePage * 0x800, STRING_PAL_ROW);

    i = game_version >> 4;
    if (i >= 0 && i < 10)
        i += '0';
    else if (i >= 10 && i < 16)
        i += 'A' - 10;
    else
        i = ' ';
    string[0] = i;
    
    i = game_version & 0xF;
    if (i >= 0 && i < 10)
        i += '0';
    else if (i >= 10 && i < 16)
        i += 'A' - 10;
    else
        i = ' ';
    string[1] = i;

    string[2] = '/';
    string[3] = 'D';
    string[4] = '\0';

    TitleScreenDrawString(string, VRAM_BASE + 0x80 + sTitleScreenPageData[0].tiletablePage * 0x800, STRING_PAL_ROW);
}

#undef STRING_PAL_ROW

#endif // DEBUG
