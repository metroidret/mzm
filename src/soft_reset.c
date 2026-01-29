#include "soft_reset.h"
#include "gba.h"
#include "callbacks.h"

#include "data/shortcut_pointers.h"
#include "data/menus/language_select_data.h"

#include "constants/cutscene.h"
#include "constants/audio.h"
#include "constants/menus/pause_screen.h"

#include "structs/menus/language_select.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/cutscene.h"

#ifdef REGION_EU
static void LanguageSelectChangeHighlight(u8 highlight, u8 language);
static void LanguageSelectUpdateHighlightAnimation(struct LanguageColorAnimation* pAnim);
static u32 LanguageSelectMainLoop(void);
#endif // REGION_EU

/**
 * @brief 7ef9c | 54 | Main loop for a soft reset
 * 
 * @return u32 bool, ended
 */
u32 SoftResetMainLoop(void)
{
    switch (gSubGameMode1)
    {
        case 0:
            SoftResetInit();
            #ifdef REGION_EU
            if (LANGUAGE_SELECT_DATA.loadLanguageSelect)
                gSubGameMode1 = 3;
            else
                gSubGameMode1++;
            #else // !REGION_EU
            gSubGameMode1++;
            #endif // REGION_EU
            break;

        case 1:
            if (gWrittenToBldy_NonGameplay - 4 < 1)
                gWrittenToBldy_NonGameplay = 0;
            else
                gWrittenToBldy_NonGameplay -= 4;
            
            if (gWrittenToBldy_NonGameplay == 0)
                gSubGameMode1++;
            break;

        case 2:
            return TRUE;

        #ifdef REGION_EU

        case 3:
            if (gWrittenToBldy_NonGameplay - 2 <= 0)
                gWrittenToBldy_NonGameplay = 0;
            else
                gWrittenToBldy_NonGameplay -= 2;
            
            if (gWrittenToBldy_NonGameplay == 0)
            {
                LANGUAGE_SELECT_DATA.bldcnt = UCHAR_MAX;
                gSubGameMode1 = 4;
            }

            LanguageSelectUpdateHighlightAnimation(&LANGUAGE_SELECT_DATA.languageAnimation);
            break;

        case 4:
            if (LanguageSelectMainLoop())
            {
                LANGUAGE_SELECT_DATA.timer = 0;
                LANGUAGE_SELECT_DATA.languageAnimation.interval = DELTA_TIME;
                gSubGameMode1++;
            }

            LanguageSelectUpdateHighlightAnimation(&LANGUAGE_SELECT_DATA.languageAnimation);
            break;

        case 5:
            APPLY_DELTA_TIME_INC(LANGUAGE_SELECT_DATA.timer);
            if (LANGUAGE_SELECT_DATA.timer > CONVERT_SECONDS(1.f))
                gSubGameMode1++;

            LanguageSelectUpdateHighlightAnimation(&LANGUAGE_SELECT_DATA.languageAnimation);
            break;

        case 6:
            if (gWrittenToBldy_NonGameplay + 2 > 0xF)
                gWrittenToBldy_NonGameplay = 0x10;
            else
                gWrittenToBldy_NonGameplay += 2;
            
            if (gWrittenToBldy_NonGameplay == 0x10)
                gSubGameMode1 = 2;

            LanguageSelectUpdateHighlightAnimation(&LANGUAGE_SELECT_DATA.languageAnimation);
            break;

        case 7:
        case 8:
            SoftResetInit();
            if (LANGUAGE_SELECT_DATA.loadLanguageSelect)
                gSubGameMode1 = 3;
            else
                gSubGameMode1 = 2;
            break;

        #endif // REGION_EU
    }

    return FALSE;
}

#ifdef REGION_EU

/**
 * @brief Changes the highlight of a language on the language select menu
 * 
 * @param highlight Whether to highlight the language
 * @param language The language to change
 */
static void LanguageSelectChangeHighlight(u8 highlight, u8 language)
{
    u16 i;
    u16* dst1;
    u16* dst2;

    dst2 = VRAM_BASE + 0xF800;
    dst1 = dst2 + sLanguageSelectLanguageTileTableOffsets[language - LANGUAGE_ENGLISH];
    dst2 = dst1 + 0x20;

    if (highlight)
    {
        i = 0;
        while (i < 16)
        {
            *dst1 &= 0x3FF;
            *dst2 &= 0x3FF;
            i++;
            dst1++;
            dst2++;
        }
    }
    else
    {
        i = 0;
        while (i < 16)
        {
            *dst1 |= 0xF000;
            *dst2 |= 0xF000;
            i++;
            dst1++;
            dst2++;
        }
    }
}

/**
 * @brief Updates the highlighted language palette in the language select menu
 * 
 * @param pAnim Pointer to LanguageColorAnimation data
 */
static void LanguageSelectUpdateHighlightAnimation(struct LanguageColorAnimation* pAnim)
{
    if (pAnim->timer != 0)
    {
        pAnim->timer--;
        return;
    }

    pAnim->timer = pAnim->interval;
    pAnim->index++;

    if (pAnim->index > 13)
        pAnim->index = 0;

    DmaTransfer(3, sLanguageSelectBgPal + sLanguageTextAnimationPaletteRows[pAnim->index] * PAL_ROW, PALRAM_BASE, PAL_ROW, 16);
}

/**
 * @brief Main routine for language select menu
 * 
 * @return u32 bool, language selected
 */
static u32 LanguageSelectMainLoop(void)
{
    s32 language;

    CheckForMaintainedInput(MAINTAINED_INPUT_SPEED_SLOW);

    if (gChangedInput & (KEY_A | KEY_START))
    {
        if (INVALID_EU_LANGUAGE(LANGUAGE_SELECT_DATA.selectedLanguage))
        {
            // Select English by default
            LANGUAGE_SELECT_DATA.selectedLanguage = LANGUAGE_ENGLISH;
            LanguageSelectChangeHighlight(TRUE, LANGUAGE_SELECT_DATA.selectedLanguage);

            for (language = LANGUAGE_ENGLISH + 1; language < LANGUAGE_COUNT; language++)
            {
                LanguageSelectChangeHighlight(FALSE, language);
            }

            return FALSE;
        }

        if (LANGUAGE_SELECT_DATA.selectedLanguage != gLanguage)
        {
            gLanguage = LANGUAGE_SELECT_DATA.selectedLanguage;
            SramWrite_Language();
        }

        SoundPlay(SOUND_ACCEPT_CONFIRM_MENU);
        FadeMusic(CONVERT_SECONDS(1.f));
        return TRUE;
    }

    language = 0;

    if (gChangedInput & KEY_UP)
    {
        if (LANGUAGE_SELECT_DATA.selectedLanguage > LANGUAGE_ENGLISH)
        {
            language = LANGUAGE_SELECT_DATA.selectedLanguage;
            LANGUAGE_SELECT_DATA.selectedLanguage = language - 1;
        }
        else
        {
            language = LANGUAGE_ENGLISH;
            LANGUAGE_SELECT_DATA.selectedLanguage = LANGUAGE_COUNT - 1;
        }
    }
    else if (gChangedInput & KEY_DOWN)
    {
        if (LANGUAGE_SELECT_DATA.selectedLanguage < LANGUAGE_COUNT - 1)
        {
            language = LANGUAGE_SELECT_DATA.selectedLanguage;
            LANGUAGE_SELECT_DATA.selectedLanguage = language + 1;
        }
        else
        {
            language = LANGUAGE_COUNT - 1;
            LANGUAGE_SELECT_DATA.selectedLanguage = LANGUAGE_ENGLISH;
        }
    }

    if (language == 0)
        return FALSE;

    SoundPlay(SOUND_SUB_MENU_CURSOR);
    LanguageSelectChangeHighlight(FALSE, language);
    LanguageSelectChangeHighlight(TRUE, LANGUAGE_SELECT_DATA.selectedLanguage);
    return FALSE;
}

#endif // REGION_EU

/**
 * @brief 7eff0 | 110 | Initializes a soft reset
 * 
 */
void SoftResetInit(void)
{
    // Non-EU regions presumably use the CutsceneData struct for non-gameplay RAM,
    // since the offsets for bldcnt and dispcnt line up

    CallbackSetVblank(SoftResetVBlank_Empty);

    #ifdef REGION_EU
    BitFill(3, 0, &gNonGameplayRam, sizeof(gNonGameplayRam), 32);
    #else // !REGION_EU
    DMA3_FILL_32(0, &gNonGameplayRam, sizeof(gNonGameplayRam));
    #endif

    #ifdef REGION_EU
    if (gSubGameMode1 == 0)
        WRITE_16(REG_BLDCNT, LANGUAGE_SELECT_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
    else
        WRITE_16(REG_BLDCNT, LANGUAGE_SELECT_DATA.bldcnt = UCHAR_MAX);
    #else // !REGION_EU
    WRITE_16(REG_BLDCNT, CUTSCENE_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);
    #endif
    
    WRITE_16(REG_BLDY, gWrittenToBldy_NonGameplay = BLDY_MAX_VALUE);
    #ifdef REGION_EU
    WRITE_16(REG_DISPCNT, LANGUAGE_SELECT_DATA.dispcnt = 0);
    #else // !REGION_EU
    WRITE_16(REG_DISPCNT, CUTSCENE_DATA.dispcnt = 0);
    #endif // REGION_EU

    gNextOamSlot = 0;
    ClearGfxRam();
    ResetFreeOam();

    gOamXOffset_NonGameplay = gOamYOffset_NonGameplay = 0;
    #ifndef REGION_EU
    SET_BACKDROP_COLOR(COLOR_BLACK);
    #endif // !REGION_EU
    gSubGameMode3 = 0;

    gBg0HOFS_NonGameplay = gBg0VOFS_NonGameplay = 0;
    gBg1HOFS_NonGameplay = gBg1VOFS_NonGameplay = 0;
    gBg2HOFS_NonGameplay = gBg2VOFS_NonGameplay = 0;
    gBg3HOFS_NonGameplay = gBg3VOFS_NonGameplay = 0;

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);
    
    #ifdef REGION_EU
    LANGUAGE_SELECT_DATA.selectedLanguage = gLanguage;

    if (INVALID_EU_LANGUAGE(LANGUAGE_SELECT_DATA.selectedLanguage))
    {
        LANGUAGE_SELECT_DATA.selectedLanguage = LANGUAGE_ENGLISH;
        LANGUAGE_SELECT_DATA.loadLanguageSelect = TRUE;
    }
    else
    {
        LANGUAGE_SELECT_DATA.loadLanguageSelect = gSubGameMode1 == 7;
    }

    if (LANGUAGE_SELECT_DATA.loadLanguageSelect)
    {
        LANGUAGE_SELECT_DATA.languageAnimation = sInitialLanguageColorAnimation;

        DMA3_COPY_16(sLanguageSelectBgPal, PALRAM_BASE, COLORS_IN_PAL);
        SET_BACKDROP_COLOR(COLOR_BLACK);

        LZ77UncompVRAM(sLanguageSelectGfx, VRAM_BASE);
        LZ77UncompVRAM(sLanguageSelectTileTable, VRAM_BASE + 0xF800);

        LanguageSelectChangeHighlight(TRUE, LANGUAGE_SELECT_DATA.selectedLanguage);

        WRITE_16(REG_BG0CNT, 0);
        WRITE_16(REG_BG2CNT, 0);
        WRITE_16(REG_BG1CNT, 0);
        WRITE_16(REG_BG3CNT, 0x1F03);
        LANGUAGE_SELECT_DATA.dispcnt = 0x800;
    }
    else
    {
        SET_BACKDROP_COLOR(COLOR_BLACK);
        LANGUAGE_SELECT_DATA.dispcnt = 0;
    }

    WRITE_16(REG_DISPCNT, LANGUAGE_SELECT_DATA.dispcnt);
    #else // !REGION_EU
    WRITE_16(REG_DISPCNT, CUTSCENE_DATA.dispcnt = 0);
    #endif // REGION_EU

    CallbackSetVblank(SoftResetVBlank);
}

/**
 * @brief 7f100 | 14 | V-blank code for a soft reset
 * 
 */
void SoftResetVBlank(void)
{
    WRITE_16(REG_BLDY, gWrittenToBldy_NonGameplay);

    #ifdef REGION_EU
    WRITE_16(REG_BLDCNT, LANGUAGE_SELECT_DATA.bldcnt);
    #endif // REGION_EU
}

/**
 * @brief 7f114 | c | Empty v-blank for a soft reset
 * 
 */
void SoftResetVBlank_Empty(void)
{
    vu8 c = 0;
}
