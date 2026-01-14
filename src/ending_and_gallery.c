#include "ending_and_gallery.h"
#include "callbacks.h"
#include "dma.h"

#include "data/shortcut_pointers.h"
#include "data/ending_and_gallery_data.h"

#include "constants/audio.h"
#include "constants/ending_and_gallery.h"
#include "constants/game_state.h"
#include "constants/text.h"

#include "structs/bg_clip.h"
#include "structs/display.h"
#include "structs/ending_and_gallery.h"
#include "structs/game_state.h"

#define SETUP_ENDING_TEXT_OAM(endingOam, i) \
{ \
    ENDING_DATA.oamLength = ARRAY_SIZE(endingOam) + 6; \
    for (i = 0; i < ARRAY_SIZE(endingOam); i++) \
    { \
        ENDING_DATA.oamTypes[i + 6] = endingOam[i].type; \
        ENDING_DATA.endingLettersSpawnDelay[i + 6] = endingOam[i].spawnDelay; \
        ENDING_DATA.unk_160[i + 6] = endingOam[i].unk_2; \
        ENDING_DATA.oamXPositions[i + 6] = endingOam[i].xPosition; \
        ENDING_DATA.oamYPositions[i + 6] = endingOam[i].yPosition; \
        ENDING_DATA.oamFramePointers[i + 6] = endingOam[i].pFrame; \
    } \
}

#define SETUP_ENDING_FULL_LINES_OAM(endingOam) \
{ \
    ENDING_DATA.oamTypes[line] = endingOam[line].type; \
    ENDING_DATA.endingLettersSpawnDelay[line] = endingOam[line].spawnDelay; \
    ENDING_DATA.unk_160[line] = endingOam[line].unk_2; \
    ENDING_DATA.oamXPositions[line] = endingOam[line].xPosition; \
    ENDING_DATA.oamYPositions[line] = endingOam[line].yPosition; \
    ENDING_DATA.oamFramePointers[line] = endingOam[line].pFrame; \
}

/**
 * @brief 84c34 | 48 | Checks if an ending letter should display
 * 
 * @param offset Offset, to document
 */
static void EndingImageUpdateLettersSpawnDelay(u32 offset)
{
    if (ENDING_DATA.oamTypes[offset] == ENDING_OAM_TYPE_NONE)
        return;

    if (ENDING_DATA.endingLettersSpawnDelay[offset])
    {
        ENDING_DATA.endingLettersSpawnDelay[offset]--;
        if (ENDING_DATA.endingLettersSpawnDelay[offset] == 0)
            ENDING_DATA.oamTypes[offset]++;
    }
}

/**
 * @brief 84c7c | 26c | Loads a set of OAM for the ending image
 * 
 * @param set Set to load
 */
static void EndingImageLoadTextOAM(u32 set)
{
    s32 i;

    #ifdef REGION_EU
    switch (ENDING_DATA.language)
    {
        case LANGUAGE_GERMAN:
            if (set == ENDING_IMAGE_OAM_SET_CLEAR_TIME)
            {
                SETUP_ENDING_TEXT_OAM(sEndingImageOam_ClearTime_German, i);
            }
            else
            {
                SETUP_ENDING_TEXT_OAM(sEndingImageOam_Collecting_German, i);
            }
            break;

        case LANGUAGE_FRENCH:
            if (set == ENDING_IMAGE_OAM_SET_CLEAR_TIME)
            {
                SETUP_ENDING_TEXT_OAM(sEndingImageOam_ClearTime_French, i);
            }
            else
            {
                SETUP_ENDING_TEXT_OAM(sEndingImageOam_Collecting_French, i);
            }
            break;

        case LANGUAGE_ITALIAN:
            if (set == ENDING_IMAGE_OAM_SET_CLEAR_TIME)
            {
                SETUP_ENDING_TEXT_OAM(sEndingImageOam_ClearTime_Italian, i);
            }
            else if (set == ENDING_IMAGE_OAM_SET_YOUR_RATE)
            {
                SETUP_ENDING_TEXT_OAM(sEndingImageOam_YourRate_Italian, i);
            }
            else
            {
                SETUP_ENDING_TEXT_OAM(sEndingImageOam_Collecting_Italian, i);
            }
            break;

        case LANGUAGE_SPANISH:
            if (set == ENDING_IMAGE_OAM_SET_CLEAR_TIME)
            {
                SETUP_ENDING_TEXT_OAM(sEndingImageOam_ClearTime_Spanish, i);
            }
            else
            {
                SETUP_ENDING_TEXT_OAM(sEndingImageOam_Collecting_Spanish, i);
            }
            break;

        case LANGUAGE_HIRAGANA:
            if (set == ENDING_IMAGE_OAM_SET_CLEAR_TIME)
            {
                SETUP_ENDING_TEXT_OAM(sEndingImageOam_ClearTime_Hiragana, i);
            }
            else
            {
                SETUP_ENDING_TEXT_OAM(sEndingImageOam_Collecting_Hiragana, i);
            }
            break;

        default:
            // Japanese and English
            if (set == ENDING_IMAGE_OAM_SET_CLEAR_TIME)
            {
                SETUP_ENDING_TEXT_OAM(sEndingImageOam_ClearTime_English, i);
            }
            else if (set == ENDING_IMAGE_OAM_SET_YOUR_RATE)
            {
                SETUP_ENDING_TEXT_OAM(sEndingImageOam_YourRate_English, i);
            }
            else
            {
                SETUP_ENDING_TEXT_OAM(sEndingImageOam_Collecting_English, i);
            }
            break;
    }
    #else // !REGION_EU
    if (ENDING_DATA.language == LANGUAGE_HIRAGANA)
    {
        if (set == ENDING_IMAGE_OAM_SET_CLEAR_TIME)
        {
            SETUP_ENDING_TEXT_OAM(sEndingImageOam_ClearTime_Hiragana, i);
        }
        else
        {
            SETUP_ENDING_TEXT_OAM(sEndingImageOam_Collecting_Hiragana, i);
        }
    }
    else
    {
        // Japanese and English
        if (set == ENDING_IMAGE_OAM_SET_CLEAR_TIME)
        {
            SETUP_ENDING_TEXT_OAM(sEndingImageOam_ClearTime_English, i);
        }
        else if (set == ENDING_IMAGE_OAM_SET_YOUR_RATE)
        {
            SETUP_ENDING_TEXT_OAM(sEndingImageOam_YourRate_English, i);
        }
        else
        {
            SETUP_ENDING_TEXT_OAM(sEndingImageOam_Collecting_English, i);
        }
    }
    #endif // REGION_EU
}

/**
 * @brief 84ee8 | c8 | Display a line of text of an ending image permanently
 * 
 * @param line Line
 */
static void EndingImageDisplayLinePermanently(u32 line)
{
    s32 i;

    #ifdef REGION_EU
    switch (ENDING_DATA.language)
    {
        case LANGUAGE_GERMAN:
            SETUP_ENDING_FULL_LINES_OAM(sEndingImageOam_FullLines_German);
            break;

        case LANGUAGE_FRENCH:
            SETUP_ENDING_FULL_LINES_OAM(sEndingImageOam_FullLines_French);
            break;

        case LANGUAGE_ITALIAN:
            SETUP_ENDING_FULL_LINES_OAM(sEndingImageOam_FullLines_Italian);
            break;

        case LANGUAGE_SPANISH:
            SETUP_ENDING_FULL_LINES_OAM(sEndingImageOam_FullLines_Spanish);
            break;

        case LANGUAGE_HIRAGANA:
            SETUP_ENDING_FULL_LINES_OAM(sEndingImageOam_FullLines_Hiragana);
            break;

        default:
            SETUP_ENDING_FULL_LINES_OAM(sEndingImageOam_FullLines_English);
            break;
    }
    #else // !REGION_EU
    if (ENDING_DATA.language == LANGUAGE_HIRAGANA)
    {
        SETUP_ENDING_FULL_LINES_OAM(sEndingImageOam_FullLines_Hiragana);
    }
    else
    {
        SETUP_ENDING_FULL_LINES_OAM(sEndingImageOam_FullLines_English);
    }
    #endif // REGION_EU

    for (i  = 0; i < ENDING_DATA.oamLength - 6; i++)
        ENDING_DATA.oamTypes[i + 6] = ENDING_OAM_TYPE_NONE;

    ENDING_DATA.oamLength = 6;
}

/**
 * @brief 84fb0 | 204 | To document
 * 
 */
static void EndingImageLoadIGTAndPercentageGraphics(void)
{
    s32 hoursTens;
    s32 hoursOnes;
    s32 minutesTens;
    s32 minutesOnes;
    s32 secondsTens;
    s32 secondsOnes;

    s32 percentageHundreds;
    s32 percentageTens;
    s32 percentageOnes;

    s32 offset;

    hoursTens = 0;
    hoursOnes = gInGameTimer.hours;

    while (hoursOnes > 9)
    {
        hoursOnes -= 10;
        hoursTens++;
    }

    minutesTens = 0;
    minutesOnes = gInGameTimer.minutes;

    while (minutesOnes > 9)
    {
        minutesOnes -= 10;
        minutesTens++;
    }

    secondsTens = 0;
    secondsOnes = gInGameTimer.seconds;

    while (secondsOnes > 9)
    {
        secondsOnes -= 10;
        secondsTens++;
    }

    if (hoursTens != 0)
    {
        offset = hoursTens * 64;
        #ifdef REGION_EU
        DmaTransfer(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ, 64, 16);
        DmaTransfer(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x400, 64, 16);
        #else // !REGION_EU
        DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ, C_32_2_16(DMA_ENABLE, 64 / 2));
        DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x400, C_32_2_16(DMA_ENABLE, 64 / 2));
        #endif // REGION_EU
    }

    offset = hoursOnes * 64;
    #ifdef REGION_EU
    DmaTransfer(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x040, 64, 16);
    DmaTransfer(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x440, 64, 16);
    #else // !REGION_EU
    DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x040, C_32_2_16(DMA_ENABLE, 64 / 2));
    DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x440, C_32_2_16(DMA_ENABLE, 64 / 2));
    #endif // REGION_EU

    offset = minutesTens * 64;
    #ifdef REGION_EU
    DmaTransfer(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x0A0, 64, 16);
    DmaTransfer(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x4A0, 64, 16);
    #else // !REGION_EU
    DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x0A0, C_32_2_16(DMA_ENABLE, 64 / 2));
    DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x4A0, C_32_2_16(DMA_ENABLE, 64 / 2));
    #endif // REGION_EU

    offset = minutesOnes * 64;
    #ifdef REGION_EU
    DmaTransfer(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x0E0, 64, 16);
    DmaTransfer(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x4E0, 64, 16);
    #else // !REGION_EU
    DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x0E0, C_32_2_16(DMA_ENABLE, 64 / 2));
    DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x4E0, C_32_2_16(DMA_ENABLE, 64 / 2));
    #endif // REGION_EU

    offset = secondsTens * 64;
    #ifdef REGION_EU
    DmaTransfer(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x140, 64, 16);
    DmaTransfer(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x540, 64, 16);
    #else // !REGION_EU
    DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x140, C_32_2_16(DMA_ENABLE, 64 / 2));
    DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x540, C_32_2_16(DMA_ENABLE, 64 / 2));
    #endif // REGION_EU

    offset = secondsOnes * 64;
    #ifdef REGION_EU
    DmaTransfer(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x180, 64, 16);
    DmaTransfer(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x580, 64, 16);
    #else // !REGION_EU
    DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x180, C_32_2_16(DMA_ENABLE, 64 / 2));
    DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x580, C_32_2_16(DMA_ENABLE, 64 / 2));
    #endif // REGION_EU

    percentageHundreds = 0;
    hoursOnes = 0; // percentageTens
    minutesTens = ENDING_DATA.completionPercentage; // percentageOnes

    while (minutesTens >= 100)
    {
        minutesTens -= 100;
        percentageHundreds++;
    }

    while (minutesTens >= 10)
    {
        minutesTens -= 10;
        hoursOnes++;
    }

    if (percentageHundreds != 0)
    {
        offset = percentageHundreds * 64;
        #ifdef REGION_EU
        DmaTransfer(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x1C0, 64, 16);
        DmaTransfer(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x5C0, 64, 16);
        #else // !REGION_EU
        DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x1C0, C_32_2_16(DMA_ENABLE, 64 / 2));
        DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x5C0, C_32_2_16(DMA_ENABLE, 64 / 2));
        #endif // REGION_EU
    }
    
    if (percentageHundreds != 0 || hoursOnes != 0)
    {
        offset = hoursOnes * 64;
        #ifdef REGION_EU
        DmaTransfer(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x200, 64, 16);
        DmaTransfer(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x600, 64, 16);
        #else // !REGION_EU
        DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x200, C_32_2_16(DMA_ENABLE, 64 / 2));
        DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x600, C_32_2_16(DMA_ENABLE, 64 / 2));
        #endif // REGION_EU
    }

    offset = minutesTens * 64;
    #ifdef REGION_EU
    DmaTransfer(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x240, 64, 16);
    DmaTransfer(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x640, 64, 16);
    #else // !REGION_EU
    DMA_SET(3, &sEndingImageNumbersGfx_Upper[offset], VRAM_OBJ + 0x240, C_32_2_16(DMA_ENABLE, 64 / 2));
    DMA_SET(3, &sEndingImageNumbersGfx_Lower[offset], VRAM_OBJ + 0x640, C_32_2_16(DMA_ENABLE, 64 / 2));
    #endif // REGION_EU
}

/**
 * @brief 851b4 | 164 | V-blank code for gallery, ending image and credits
 * 
 */
static void GalleryVBlank(void)
{
    u32 buffer;
    u32 bgPos;

    DMA_SET(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / sizeof(u32));

    // On even length lines
    if (ENDING_DATA.unk_6 == 1)
    {
        DMA_SET(3, ENDING_DATA.creditLineTilemap_1, VRAM_BASE + ENDING_DATA.creditLineOffset_1,
            C_32_2_16(DMA_ENABLE, ARRAY_SIZE(ENDING_DATA.creditLineTilemap_1)));
        DMA_SET(3, ENDING_DATA.creditLineTilemap_2, VRAM_BASE + ENDING_DATA.creditLineOffset_2,
            C_32_2_16(DMA_ENABLE, ARRAY_SIZE(ENDING_DATA.creditLineTilemap_2)));

        DMA_FILL_32(3, 0, VRAM_BASE + 0x800 + ENDING_DATA.creditLineOffset_1, ARRAY_SIZE(ENDING_DATA.creditLineTilemap_1) * 2);
        DMA_FILL_32(3, 0, VRAM_BASE + 0x800 + ENDING_DATA.creditLineOffset_2, ARRAY_SIZE(ENDING_DATA.creditLineTilemap_2) * 2);
    }
    // On odd length lines
    else if (ENDING_DATA.unk_6 != 0)
    {
        DMA_SET(3, ENDING_DATA.creditLineTilemap_1, VRAM_BASE + 0x800 + ENDING_DATA.creditLineOffset_1,
            C_32_2_16(DMA_ENABLE, ARRAY_SIZE(ENDING_DATA.creditLineTilemap_1)));
        DMA_SET(3, ENDING_DATA.creditLineTilemap_2, VRAM_BASE + 0x800 + ENDING_DATA.creditLineOffset_2,
            C_32_2_16(DMA_ENABLE, ARRAY_SIZE(ENDING_DATA.creditLineTilemap_2)));

        DMA_FILL_32(3, 0, VRAM_BASE + ENDING_DATA.creditLineOffset_1, ARRAY_SIZE(ENDING_DATA.creditLineTilemap_1) * 2);
        DMA_FILL_32(3, 0, VRAM_BASE + ENDING_DATA.creditLineOffset_2, ARRAY_SIZE(ENDING_DATA.creditLineTilemap_2) * 2);
    }

    WRITE_16(REG_DISPCNT, ENDING_DATA.dispcnt);
    WRITE_16(REG_BLDCNT, ENDING_DATA.bldcnt);

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_H, gWrittenToBldalpha_L));
    WRITE_16(REG_BLDY, gWrittenToBldy_NonGameplay);

    WRITE_16(REG_BG0VOFS, bgPos = MOD_AND(gBg0YPosition / 16, 0x200));
    WRITE_16(REG_BG1VOFS, bgPos);
    WRITE_16(REG_BG2VOFS, MOD_AND(gBg2YPosition / 16, 0x200));
    WRITE_16(REG_BG3VOFS, MOD_AND(gBg3YPosition / 16, 0x200));
}

/**
 * @brief 85318 | a8 | V-blank code for the end screen
 * 
 */
static void EndScreenVBlank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16(DMA_ENABLE | DMA_32BIT, OAM_SIZE / sizeof(u32)));

    WRITE_16(REG_DISPCNT, ENDING_DATA.dispcnt);
    WRITE_16(REG_BLDCNT, ENDING_DATA.bldcnt);

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_H, gWrittenToBldalpha_L));
    WRITE_16(REG_BLDY, gWrittenToBldy_NonGameplay);

    WRITE_16(REG_BG1HOFS, MOD_AND(gBg1XPosition, 0x200));
    WRITE_16(REG_BG2HOFS, MOD_AND(gBg2XPosition, 0x200));
    WRITE_16(REG_BG3HOFS, MOD_AND(gBg3XPosition, 0x200));
}

/**
 * @brief 853c0 | a8 | V-blank code for the unlocked options
 * 
 */
static void UnlockedOptionsVBlank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16(DMA_ENABLE | DMA_32BIT, OAM_SIZE / sizeof(u32)));

    WRITE_16(REG_DISPCNT, ENDING_DATA.dispcnt);
    WRITE_16(REG_BLDCNT, ENDING_DATA.bldcnt);

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_H, gWrittenToBldalpha_L));
    WRITE_16(REG_BLDY, gWrittenToBldy_NonGameplay);

    WRITE_16(REG_WIN0H, C_16_2_8(ENDING_DATA.oamXPositions[0], ENDING_DATA.oamXPositions[1]));
    WRITE_16(REG_WIN0V, C_16_2_8(ENDING_DATA.oamYPositions[0], ENDING_DATA.oamYPositions[1]));
}

/**
 * @brief 85464 | 1f8 | Initializes the credits
 * 
 */
static void CreditsInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IF, IF_HBLANK);

    WRITE_16(REG_IME, TRUE);
    WRITE_16(REG_DISPCNT, 0);

    WRITE_16(REG_IME, FALSE);
    CallbackSetVblank(GalleryVBlank);
    WRITE_16(REG_IME, TRUE);

    DMA_FILL_32(3, 0, &gNonGameplayRam, sizeof(gNonGameplayRam))

    ClearGfxRam();

    LZ77UncompVRAM(sCreditsChozoWallBackgroundGfx, VRAM_BASE);
    LZ77UncompVRAM(sCreditsChozoWallBackgroundTileTable, VRAM_BASE + 0xE000);
    LZ77UncompVRAM(sCreditsChozoWallBottomTileTable, VRAM_BASE + 0xD800);
    LZ77UncompVRAM(sCreditsCharactersGfx, VRAM_BASE + 0x8000);

    #ifdef REGION_EU
    DmaTransfer(3, sCreditsChozoWallPal, PALRAM_BASE, sizeof(sCreditsChozoWallPal), 16);
    DmaTransfer(3, sCreditsCharactersPal, PALRAM_BASE + 13 * PAL_ROW_SIZE, sizeof(sCreditsCharactersPal), 16);
    #else // !REGION_EU
    DMA_SET(3, sCreditsChozoWallPal, PALRAM_BASE, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sCreditsChozoWallPal)));
    DMA_SET(3, sCreditsCharactersPal, PALRAM_BASE + 13 * PAL_ROW_SIZE, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sCreditsCharactersPal)));
    #endif // REGION_EU

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 30, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 31, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 28, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x512));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(2, 26, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x512));

    gNextOamSlot = 0;
    ResetFreeOam();

    gBg0XPosition = 0;
    gBg0YPosition = 0x1000;
    gBg1XPosition = 0;
    gBg1YPosition = 0x1000;
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0x1000);
    WRITE_16(REG_BG1HOFS, 4);
    WRITE_16(REG_BG1VOFS, 0x1000);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    ENDING_DATA.unk_E = 0x80;
    ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3;
    ENDING_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

    gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE;
    gWrittenToBldalpha_H = 0;
    gWrittenToBldy_NonGameplay = BLDY_MAX_VALUE;

    GalleryVBlank();
    PlayMusic(MUSIC_CREDITS, 0);
}

/**
 * @brief 8565c | 398 | Displays a credit line
 * 
 * @param line Line
 * @return u8 To document
 */
static u8 CreditsDisplayLine(u32 line)
{
    u8 i;
    s32 tile;
    u32 ret_0;
    u32 ret_1;
    u8 tilemapOffset;
    const struct CreditsEntry* pCredits;

    pCredits = sCredits;
    pCredits += line;
    
    for (i = 0; i < ARRAY_SIZE(ENDING_DATA.creditLineTilemap_1); i++)
    {
        ENDING_DATA.creditLineTilemap_1[i] = 0;
        ENDING_DATA.creditLineTilemap_2[i] = 0;
    }

    if (pCredits->type == CREDIT_LINE_TYPE_BLUE)
        tile = 14 << 12;
    else if (pCredits->type == CREDIT_LINE_TYPE_RED)
        tile = 15 << 12;
    else
        tile = 13 << 12;

    ret_0 = 0;
    ret_1 = 0;
    i = 0;
    
    switch (pCredits->type)
    {
        case CREDIT_LINE_TYPE_BLUE:
        case CREDIT_LINE_TYPE_RED:
        case CREDIT_LINE_TYPE_WHITE_SMALL:
            for (tilemapOffset = 0; tilemapOffset < ARRAY_SIZE(ENDING_DATA.creditLineTilemap_1) - 2; tilemapOffset++)
            {
                if (pCredits->text[tilemapOffset] == 0)
                    break;
            }

            if (tilemapOffset & 1)
            {
                ret_1 = 0x80;
                tilemapOffset--;
            }

            tilemapOffset = (0x1E - tilemapOffset) >> 1;

            while (TRUE)
            {
                if (pCredits->text[i] == 0)
                {
                    break;
                }
                
                if ((u8)(pCredits->text[i] - 0x41) < 0x1A)
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = pCredits->text[i] + (tile - 0x40);
                }
                else if ((u8)(pCredits->text[i] - 0x61) < 0x1A)
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = pCredits->text[i] + (tile - 0x41);
                }
                else if (pCredits->text[i] == '.')
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = tile + 0x1B;
                }
                else if (pCredits->text[i] == ',')
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = tile + 0x1C;
                }
                else if (pCredits->text[i] == '&')
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = tile + 0x1D;
                }

                i++;
                tilemapOffset++;
            }
            ret_0 = 1;
            break;

        case CREDIT_LINE_TYPE_END:
            ret_0 = 9;
            break;

        case CREDIT_LINE_TYPE_ALL_RIGHTS:
            for (i = 0; i < 20; i++)
                ENDING_DATA.creditLineTilemap_1[i + 5] = 0xC0 + i + tile;
            ret_0 = 1;
            ret_1 = 0x10;
            break;

        case CREDIT_LINE_TYPE_THE_COPYRIGHT:
            for (i = 0; i < 20; i++)
                ENDING_DATA.creditLineTilemap_1[i + 5] = 0xE0 + i + tile;
            ret_0 = 1;
            break;

        case 5:
            ret_0 = 1;
            break;

        case CREDIT_LINE_TYPE_SCENARIO:
            for (i = 0; i < 20; i++)
                ENDING_DATA.creditLineTilemap_1[i + 5] = 0x100 + i + tile;
            ret_0 = 1;
            break;

        case CREDIT_LINE_TYPE_RESERVED:
            for (i = 0; i < 20; i++)
                ENDING_DATA.creditLineTilemap_1[i + 5] = 0x120 + i + tile;
            ret_0 = 1;
            break;

        case CREDIT_LINE_TYPE_WHITE_BIG:
            for (tilemapOffset = 0; tilemapOffset < 0x1E; tilemapOffset++)
            {
                if (pCredits->text[tilemapOffset] == 0)
                    break;
            }

            if (tilemapOffset & 1)
            {
                ret_1 = 0x80;
                tilemapOffset--;
            }

            tilemapOffset = (0x1E - tilemapOffset) >> 1;

            while (TRUE)
            {
                if (pCredits->text[i] == 0)
                {
                    break;
                }
                
                if (pCredits->text[i] >= 'A' && pCredits->text[i] <= 'Z')
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = pCredits->text[i] + (tile - 1);
                    ENDING_DATA.creditLineTilemap_2[tilemapOffset] = pCredits->text[i] + (tile + 0x1F);
                }
                else if (pCredits->text[i] >= 'a' && pCredits->text[i] <= 'z')
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = pCredits->text[i] + (tile + 0x1F);
                    ENDING_DATA.creditLineTilemap_2[tilemapOffset] = pCredits->text[i] + (tile + 0x3F);
                }
                else if (pCredits->text[i] == '.')
                {
                    ENDING_DATA.creditLineTilemap_2[tilemapOffset] = tile + 0x7B;
                }
                else if (pCredits->text[i] == ',')
                {
                    ENDING_DATA.creditLineTilemap_2[tilemapOffset] = tile + 0x7C;
                }
                else if (pCredits->text[i] == '-')
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = tile + 0x5A;
                }
                else if (pCredits->text[i] == '+')
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = tile + 0x9A;
                    ENDING_DATA.creditLineTilemap_2[tilemapOffset] = tile + 0xBA;
                }
                #ifdef REGION_EU
                else if (pCredits->text[i] == 0x23) // ó
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = tile + 0x9B;
                    ENDING_DATA.creditLineTilemap_2[tilemapOffset] = tile + 0xBB;
                }
                else if (pCredits->text[i] == 0x24) // ß
                {
                    ENDING_DATA.creditLineTilemap_1[tilemapOffset] = tile + 0x5D;
                    ENDING_DATA.creditLineTilemap_2[tilemapOffset] = tile + 0x7D;
                }
                else if (pCredits->text[i] == 0x25) // acute accent (´)
                {
                    ENDING_DATA.creditLineTilemap_2[tilemapOffset] = tile + 0x7E;
                }
                #endif // REGION_EU

                i++;
                tilemapOffset++;
            }
            ret_0 = 2;
            break;
    }

    return ret_0 | ret_1;
}

/**
 * @brief 859f4 | 18c | Displays the credits
 * 
 * @return u8 bool, ended
 */
static u8 CreditsDisplay(void)
{
    u8 ended;
    s32 temp;
    u8 result;

    u8 unk_0;
    u8 unk_1;

    if (ENDING_DATA.unk_1)
    {
        ended = FALSE;
        switch (ENDING_DATA.timer++)
        {
            case CONVERT_SECONDS(7.f) + CONVERT_SECONDS(11.f / 15.f):
                ENDING_DATA.unk_1++;
                break;

            case CONVERT_SECONDS(8.8f):
                ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_SECOND_TARGET_PIXEL;
                gWrittenToBldy_NonGameplay = 0;
                ENDING_DATA.unk_1++;
                break;

            case CONVERT_SECONDS(9.f) + ONE_THIRD_SECOND:
                ENDING_DATA.dispcnt = DCNT_BG2 | DCNT_BG3;
                ENDING_DATA.bldcnt = 0;
                ended = TRUE;
                break;
        }

        if (ENDING_DATA.unk_1 == 2)
        {
            if (MOD_AND(ENDING_DATA.endScreenTimer++, 4) == 0)
            {
                if (gWrittenToBldy_NonGameplay)
                    gWrittenToBldy_NonGameplay--;
            }
        }
        else if (ENDING_DATA.unk_1 == 3)
        {
            if (MOD_AND(ENDING_DATA.timer, 2))
            {
                if (gWrittenToBldalpha_L)
                {
                    gWrittenToBldalpha_L--;
                    gWrittenToBldalpha_H = BLDALPHA_MAX_VALUE - gWrittenToBldalpha_L;
                }
                else
                    ENDING_DATA.unk_1++;
            }
        }

        return ended;
    }

    if (ENDING_DATA.unk_E > 0x7F)
    {
        ENDING_DATA.unk_E &= 0x7F;

        if (ENDING_DATA.unk_8 == ENDING_DATA.unk_A)
        {
            ended = CreditsDisplayLine(ENDING_DATA.currentCreditLine);
            unk_0 = ended & 0xF0;
            ended = ended & 0xF;

            if (ended == 0x9)
            {
                ENDING_DATA.unk_1 = 1;
            }
            else
            {
                temp = ENDING_DATA.unk_A * 0x40 + 0x500;
                if (temp > 0x7FF)
                    temp &= 0x7FF;

                ENDING_DATA.creditLineOffset_1 = temp + 0xF000;

                temp = ENDING_DATA.unk_A * 0x40 + 0x540;
                if (temp > 0x7FF)
                    temp &= 0x7FF;

                ENDING_DATA.creditLineOffset_2 = temp + 0xF000;

                ENDING_DATA.unk_A += ended;
                ENDING_DATA.currentCreditLine++;
                ENDING_DATA.unk_6++;

                if (unk_0 == 0x80)
                    ENDING_DATA.unk_6++;
            }
        }

        ENDING_DATA.unk_8++;
    }

    #ifdef REGION_EU
    ENDING_DATA.unk_E += 9;
    gBg0YPosition += 9;
    #else // !REGION_EU
    ENDING_DATA.unk_E += 7;
    gBg0YPosition += 7;
    #endif // REGION_EU

    return FALSE;
}

/**
 * @brief 85b80 | 90 | Handles the scrolling wall part of the after credits
 * 
 * @return u8 bool, ended
 */
static u8 CreditsChozoWallMovement(void)
{
    u8 ended;

    ended = FALSE;

    switch (ENDING_DATA.timer++)
    {
        case 0:
            // Load bottom graphics
            LZ77UncompVRAM(sCreditsChozoWallBottomGfx, VRAM_BASE + 0x8000);
            break;

        case 1:
            // Enable background scrolling
            ENDING_DATA.unk_1++;
            break;

        case CONVERT_SECONDS(8.f) + CONVERT_SECONDS(8.f / 15.f):
            WRITE_16(REG_BG1HOFS, 0);
            ended = TRUE;
            break;
    }

    if (ENDING_DATA.unk_1)
    {
        gBg2YPosition += 8;
        gBg3YPosition += 8;
    
        // Check end scrolling
        if (gBg2YPosition == BLOCK_SIZE * 56)
            ENDING_DATA.unk_1 = FALSE; // Disable background scrolling
    }

    return ended;
}

/**
 * @brief 85c10 | 1f8 | Handles the zooming wall part of the after credits 
 * 
 * @return u8 bool, ended (0/2)
 */
static u8 CreditsChozoWallZoom(void)
{
    u8 ended;

    ended = FALSE;

    switch (ENDING_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sCreditsChozoWallBottomZoomedGfx, VRAM_BASE);
            #ifdef REGION_EU
            DmaTransfer(3, sCreditsChozoWallPal, PALRAM_BASE, sizeof(sCreditsChozoWallPal), 16);
            #else // !REGION_EU
            DMA_SET(3, sCreditsChozoWallPal, PALRAM_BASE, DMA_ENABLE << 16 | ARRAY_SIZE(sCreditsChozoWallPal));
            #endif // REGION_EU
            gBg0YPosition = 0;
            gWrittenToBldalpha_L = 0;
            gWrittenToBldalpha_H = 16;
            break;

        case 1:
            LZ77UncompVRAM(sCreditsChozoWallBottomZoomedTileTable, VRAM_BASE + 0xF000);
            WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 30, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG2 | DCNT_BG3;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;

            ENDING_DATA.unk_1++;
            break;

        case CONVERT_SECONDS(3.2f):
            ENDING_DATA.dispcnt = DCNT_BG0;
            ENDING_DATA.bldcnt = 0;
            ENDING_DATA.unk_1++;
            gBg1YPosition = 0;
            gWrittenToBldalpha_L = 16;
            gWrittenToBldalpha_H = 0;
            break;

        case CONVERT_SECONDS(3.2f) + CONVERT_SECONDS(1.f / 60):
            LZ77UncompVRAM(sCreditsChozoDrawingGfx, VRAM_BASE + 0x8000);
            break;

        case CONVERT_SECONDS(3.2f) + CONVERT_SECONDS(2.f / 60):
            LZ77UncompVRAM(sCreditsChozoDrawingTileTable, VRAM_BASE + 0xF800);
            ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG1;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG1_SECOND_TARGET_PIXEL;

            ENDING_DATA.unk_1++;
            break;

        case CONVERT_SECONDS(13.f) + ONE_THIRD_SECOND:
            ENDING_DATA.dispcnt = DCNT_BG1;
            ENDING_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

            ENDING_DATA.unk_1++;
            break;

        case CONVERT_SECONDS(16.f):
            ended = 2;
            break;
    }

    if (ENDING_DATA.unk_1 == 1)
    {
        if (MOD_AND(ENDING_DATA.timer, 8) == 0)
        {
            if (gWrittenToBldalpha_L < BLDALPHA_MAX_VALUE)
                gWrittenToBldalpha_L++;

            if (gWrittenToBldalpha_H != 0)
                gWrittenToBldalpha_H--;
        }
    }
    else if (ENDING_DATA.unk_1 == 3)
    {
        if (MOD_AND(ENDING_DATA.timer, 8) == 0)
        {
            if (gWrittenToBldalpha_L != 0)
                gWrittenToBldalpha_L--;

            if (gWrittenToBldalpha_H < BLDALPHA_MAX_VALUE)
                gWrittenToBldalpha_H++;
        }
    }
    else if (ENDING_DATA.unk_1 == 4)
    {
        if (MOD_AND(ENDING_DATA.timer, 8) == 0)
        {
            if (gWrittenToBldy_NonGameplay < BLDY_MAX_VALUE)
                gWrittenToBldy_NonGameplay++;
        }
    }

    return ended;
}

/**
 * @brief 85e08 | 248 | Initializes the end screen (samus posing)
 * 
 */
static void EndScreenInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IF, IF_HBLANK);

    WRITE_16(REG_IME, TRUE);
    WRITE_16(REG_DISPCNT, 0);

    WRITE_16(REG_IME, FALSE);
    CallbackSetVblank(EndScreenVBlank);
    WRITE_16(REG_IME, TRUE);

    LZ77UncompVRAM(sEndingSamusPosingSpaceBackgroundGfx, VRAM_BASE + 0x3000);
    LZ77UncompVRAM(sEndingLightGfx, VRAM_BASE + 0xB000);
    LZ77UncompVRAM(sEndingSamusPosingGfx_1, VRAM_BASE);
    LZ77UncompVRAM(sEndingSamusPosingGfx_2, VRAM_BASE + 0x8000);

    LZ77UncompVRAM(sEndingSamusPosingSpaceBackgroundTileTable, VRAM_BASE + 0xF800);
    LZ77UncompVRAM(sEndingLightTileTable, VRAM_BASE + 0xF000);
    LZ77UncompVRAM(sEndingSamusPosingTileTable_1, VRAM_BASE + 0xD000);
    LZ77UncompVRAM(sEndingSamusPosingTileTable_2, VRAM_BASE + 0xE000);

    BitFill(3, 0, VRAM_BASE + 0xD800, 0x800, 32);
    BitFill(3, 0, VRAM_BASE + 0xE800, 0x800, 32);

    #ifdef REGION_EU
    DmaTransfer(3, sEndingPosingPal, PALRAM_BASE, sizeof(sEndingPosingPal), 16);
    #else // !REGION_EU
    DMA_SET(3, sEndingPosingPal, PALRAM_BASE, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sEndingPosingPal)));
    #endif // REGION_EU

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 30, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 26, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_512x256));
    WRITE_16(REG_BG2CNT, CREATE_BGCNT(2, 28, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_512x256));
    WRITE_16(REG_BG3CNT, CREATE_BGCNT(0, 31, BGCNT_LOW_PRIORITY, BGCNT_SIZE_256x256));
    
    gNextOamSlot = 0;
    ResetFreeOam();
    #ifdef REGION_EU
    DmaTransfer(3, gOamData, OAM_BASE, OAM_SIZE, 32);
    #else // !REGION_EU
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16(DMA_ENABLE | DMA_32BIT, OAM_SIZE / sizeof(u32)));
    #endif // REGION_EU

    gBg0XPosition = 0;
    gBg0YPosition = 0;
    gBg1XPosition = 0x100;
    gBg1YPosition = 0;
    gBg2XPosition = 0x100;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0x100);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0x100);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    DMA_FILL_32(3, 0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    ENDING_DATA.endingNumber = PEN_GET_ENDING(ChozodiaEscapeGetItemCountAndEndingNumber()) & 7;
    ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ;

    gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE;
    gWrittenToBldalpha_H = 0;
    gWrittenToBldy_NonGameplay = BLDY_MAX_VALUE;

    EndScreenVBlank();
}

/**
 * @brief 86050 | 764 | Handles the entire samus posing sequence
 * 
 * @return u8 bool, ended
 */
static u8 EndScreenSamusPosing(void)
{
    u8 ended;
    u32 temp;

    ended = FALSE;

    ENDING_DATA.endScreenTimer++;

    switch (ENDING_DATA.unk_1)
    {
        case 4:
            if (ENDING_DATA.timer++ <= 7)
                break;

        case 0:
            gBg1XPosition += 8;
            if (gBg1XPosition >= BLOCK_SIZE * 8)
            {
                gBg1XPosition = 0;
                ENDING_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                    BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;
                ENDING_DATA.timer = 0;
                ENDING_DATA.unk_1++;
            }
            break;

        case 1:
        case 3:
        case 5:
            if (ENDING_DATA.timer++ > 24)
            {
                ENDING_DATA.oamTypes[0] = 1;
                ENDING_DATA.timer = 0;
                ENDING_DATA.unk_1++;
            }
            break;

        case 2:
        case 6:
            if (ENDING_DATA.timer++ > 7)
            {
                gBg2XPosition += 8;
                if (gBg2XPosition >= BLOCK_SIZE * 8)
                {
                    gBg2XPosition = BLOCK_SIZE * 8;
                    ENDING_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                        BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;
                    ENDING_DATA.timer = 0;
                    ENDING_DATA.unk_1++;
                }
            }
            break;

        case 7:
            if (ENDING_DATA.timer++ > 64)
            {
                ENDING_DATA.oamTypes[0] = 1;
                ENDING_DATA.timer = 0;
                ENDING_DATA.unk_1++;
            }
            break;

        case 8:
            if (ENDING_DATA.timer++ > 23)
            {
                if (gBg1XPosition >= 10)
                {
                    gBg1XPosition -= 10;
                }
                else
                {
                    gBg1XPosition = 0;
                    ENDING_DATA.timer = 0;
                    ENDING_DATA.unk_1++;
                }
            }
            break;

        case 9:
            if (ENDING_DATA.timer++ > 31)
            {
                ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_BG2 | DCNT_BG3;
                
                if (ENDING_DATA.endingNumber != 0)
                {
                    ENDING_DATA.oamTypes[0] = 3;
                }
                else
                {
                    ENDING_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                        BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;
                    ENDING_DATA.oamTypes[0] = 1;
                }
                
                ENDING_DATA.timer = 0;
                ENDING_DATA.unk_1++;
            }
            break;

        case 10:
            if (ENDING_DATA.timer++ > 288)
                ENDING_DATA.oamTypes[1] = 32;
            break;
    }

    switch (ENDING_DATA.oamTypes[0])
    {
        case 1:
            if (ENDING_DATA.endScreenTimer & 1)
            {
                if (gWrittenToBldalpha_L != 0)
                    gWrittenToBldalpha_L--;
                else
                {
                    ENDING_DATA.oamTypes[0] = 0;
                    ENDING_DATA.oamTypes[1]++;
                }

                gWrittenToBldalpha_H = BLDALPHA_MAX_VALUE - gWrittenToBldalpha_L;
            }
            break;

        case 2:
            if (ENDING_DATA.endScreenTimer & 3)
                break;

            if (gWrittenToBldalpha_L < BLDALPHA_MAX_VALUE)
                gWrittenToBldalpha_L++;
            else
            {
                ENDING_DATA.oamTypes[0] = 0;
                ENDING_DATA.oamTypes[1]++;
            }
            break;

        case 3:
            ++ENDING_DATA.unk_160[0];
            temp = ENDING_DATA.unk_160[0];
            if ((u8)temp >= 16)
            {
                ENDING_DATA.unk_160[0] = 0;
                ENDING_DATA.oamTypes[1] = 16;
                break;
            }
            #ifdef REGION_EU
            DmaTransfer(3, sEndingWhitePalPointers[(u8)temp / 4],
                PALRAM_BASE, sizeof(sEndingPosingPal_White1), 16);
            #else // !REGION_EU
            DMA_SET(3, sEndingWhitePalPointers[(u8)temp / 4],
                PALRAM_BASE, DMA_ENABLE << 16 | ARRAY_SIZE(sEndingPosingPal_White1));
            #endif // REGION_EU
            break;

        case 4:
            if (MOD_AND(ENDING_DATA.endScreenTimer, 2) == 0)
                break;

            if (gWrittenToBldy_NonGameplay < BLDY_MAX_VALUE)
                gWrittenToBldy_NonGameplay++;
            else
                ENDING_DATA.oamTypes[1]++;
            break;

        case 5:
            if (MOD_AND(ENDING_DATA.endScreenTimer, 4))
                break;

            if (gWrittenToBldy_NonGameplay)
                gWrittenToBldy_NonGameplay--;
            else
            {
                ENDING_DATA.oamTypes[0] = 0;
                ENDING_DATA.oamTypes[1]++;
            }
            break;
    }

    switch (ENDING_DATA.oamTypes[1])
    {
        case 1:
            WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 26, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_512x256));
            WRITE_16(REG_BG2CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_512x256));

            LZ77UncompVRAM(sEndingSamusPosingGfx_3, VRAM_BASE);
            LZ77UncompVRAM(sEndingSamusPosingTileTable_3, VRAM_BASE + 0xD000);

            ENDING_DATA.bldcnt = 0;
            gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE;
            gWrittenToBldalpha_H = 0;
            gBg1XPosition = BLOCK_SIZE * 4;
            ENDING_DATA.oamTypes[1]++;
            break;

        case 3:
            WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 26, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_512x256));
            WRITE_16(REG_BG2CNT, CREATE_BGCNT(2, 28, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_512x256));

            LZ77UncompVRAM(sEndingSamusPosingGfx_4, VRAM_BASE + 0x8000);
            LZ77UncompVRAM(sEndingSamusPosingTileTable_4, VRAM_BASE + 0xE000);

            ENDING_DATA.bldcnt = 0;
            gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE;
            gWrittenToBldalpha_H = 0;
            gBg2XPosition = BLOCK_SIZE * 4;
            ENDING_DATA.oamTypes[1]++;
            break;

        case 5:
            WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 26, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_512x256));
            WRITE_16(REG_BG2CNT, CREATE_BGCNT(2, 28, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_512x256));

            LZ77UncompVRAM(sEndingSamusPosingGfx_5, VRAM_BASE);
            LZ77UncompVRAM(sEndingSamusPosingTileTable_5, VRAM_BASE + 0xD000);

            ENDING_DATA.bldcnt = 0;
            gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE;
            gWrittenToBldalpha_H = 0;
            gBg1XPosition = BLOCK_SIZE * 4;
            ENDING_DATA.oamTypes[1]++;
            break;

        case 7:
            WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 26, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_512x256));
            WRITE_16(REG_BG2CNT, CREATE_BGCNT(2, 28, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_512x256));

            if (ENDING_DATA.endingNumber == 0)
            {
                LZ77UncompVRAM(sEndingSamusPosingFullSuitGfx, VRAM_BASE + 0x8000);
                LZ77UncompVRAM(sEndingSamusPosingFullSuitTileTable, VRAM_BASE + 0xE000);
            }
            else if (ENDING_DATA.endingNumber == 1)
            {
                LZ77UncompVRAM(sEndingSamusPosingHelmetOffGfx, VRAM_BASE + 0x8000);
                LZ77UncompVRAM(sEndingSamusPosingHelmetOffTileTable, VRAM_BASE + 0xE000);
            }
            else
            {
                LZ77UncompVRAM(sEndingSamusPosingSuitlessGfx, VRAM_BASE + 0x8000);
                LZ77UncompVRAM(sEndingSamusPosingSuitlessTileTable, VRAM_BASE + 0xE000);
            }

            ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_BG3;
            ENDING_DATA.bldcnt = 0;
            gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE;
            gWrittenToBldalpha_H = 0;
            gBg2XPosition = 0;

            ENDING_DATA.oamTypes[1]++;
            break;

        case 9:
            ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG2 | DCNT_BG3;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;
            
            gWrittenToBldalpha_L = 0;
            gWrittenToBldalpha_H = BLDALPHA_MAX_VALUE;
            ENDING_DATA.oamTypes[0] = 2;
            ENDING_DATA.oamTypes[1]++;
            break;

        case 16:
            ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_BG2 | DCNT_BG3;
            ENDING_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;
            
            ENDING_DATA.oamTypes[0]++;
            ENDING_DATA.oamTypes[1]++;
            break;

        case 18:
            ENDING_DATA.dispcnt = DCNT_BG2 | DCNT_BG3;
            ENDING_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;
            
            ENDING_DATA.oamTypes[0]++;
            ENDING_DATA.oamTypes[1]++;
            break;

        case 19:
            #ifdef REGION_EU
            DmaTransfer(3, sEndingPosingPal, PALRAM_BASE, 5 * PAL_ROW_SIZE, 16);
            #else // !REGION_EU
            DMA_SET(3, sEndingPosingPal, PALRAM_BASE, C_32_2_16(DMA_ENABLE, 0x50));
            #endif // REGION_EU
            ENDING_DATA.oamTypes[1]++;
            break;

        case 32:
            ENDING_DATA.dispcnt = DCNT_BG2 | DCNT_BG3;
            ENDING_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

            gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE;
            gWrittenToBldalpha_H = 0;
            ended++;
            break;
    }

    if (MOD_AND(ENDING_DATA.endScreenTimer, 8) == 0)
        gBg3XPosition++;

    return ended;
}

/**
 * @brief 867b4 | 29c | Initializes the ending image sequence
 * 
 */
static void EndingImageInit(void)
{
    u32 endingNbr;
    u32 energyNbr;
    u32 missilesNbr;
    u32 superMissilesNbr;
    u32 powerBombNbr;
    u32 abilityCount;
    u32 pen;

    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IF, IF_HBLANK);
    WRITE_16(REG_IME, TRUE);
    WRITE_16(REG_DISPCNT, 0);
    WRITE_16(REG_IME, FALSE);

    CallbackSetVblank(GalleryVBlank);
    WRITE_16(REG_IME, TRUE);

    DMA_FILL_32(3, 0, &gNonGameplayRam, sizeof(gNonGameplayRam));

    pen = ChozodiaEscapeGetItemCountAndEndingNumber();

    energyNbr = PEN_GET_ENERGY(pen);
    missilesNbr = PEN_GET_MISSILE(pen);
    superMissilesNbr = PEN_GET_SUPER_MISSILE(pen);
    powerBombNbr = PEN_GET_POWER_BOMB(pen);
    abilityCount = PEN_GET_ABILITY(pen);
    endingNbr = PEN_GET_ENDING(pen);
        
    LZ77UncompVRAM(sEndingImagesTopGfxPointers[endingNbr], VRAM_BASE);
    LZ77UncompVRAM(sEndingImagesBottomGfxPointers[endingNbr], VRAM_BASE + 0x8000);
    LZ77UncompVRAM(sEndingImagesTopTileTablePointers[endingNbr], VRAM_BASE + 0xE000);
    LZ77UncompVRAM(sEndingImagesHalfTileTablePointers[endingNbr], VRAM_BASE + 0xF800);
    BitFill(3, 0x4FF04FF, VRAM_BASE + 0xE800, 0x800, 0x20);
    #ifdef REGION_EU
    DmaTransfer(3, sEndingImagesPalPointers[endingNbr], PALRAM_BASE, PAL_SIZE, 16);
    #else // !REGION_EU
    DMA_SET(3, sEndingImagesPalPointers[endingNbr], PALRAM_BASE, C_32_2_16(DMA_ENABLE, 0x100));
    #endif // REGION_EU

    ENDING_DATA.completionPercentage = energyNbr + missilesNbr + superMissilesNbr + powerBombNbr + abilityCount;

    #ifndef REGION_EU
    LZ77UncompVRAM(sEndingImageNumbersMiscEnglishGfx, VRAM_OBJ);
    #endif // !REGION_EU

    ENDING_DATA.language = gLanguage;

    #ifdef REGION_EU
    switch (ENDING_DATA.language)
    {
        case LANGUAGE_GERMAN:
            LZ77UncompVRAM(sEndingImageNumbersMiscGermanGfx, VRAM_OBJ);
            LZ77UncompVRAM(sEndingImageTextGermanGfx, VRAM_BASE + 0x11000);
            break;
        
        case LANGUAGE_FRENCH:
            LZ77UncompVRAM(sEndingImageNumbersMiscFrenchGfx, VRAM_OBJ);
            LZ77UncompVRAM(sEndingImageTextFrenchGfx, VRAM_BASE + 0x11000);
            break;

        case LANGUAGE_ITALIAN:
            LZ77UncompVRAM(sEndingImageNumbersMiscItalianGfx, VRAM_OBJ);
            LZ77UncompVRAM(sEndingImageTextItalianGfx, VRAM_BASE + 0x11000);
            break;

        case LANGUAGE_SPANISH:
            LZ77UncompVRAM(sEndingImageNumbersMiscSpanishGfx, VRAM_OBJ);
            LZ77UncompVRAM(sEndingImageTextSpanishGfx, VRAM_BASE + 0x11000);
            break;

        case LANGUAGE_HIRAGANA:
            LZ77UncompVRAM(sEndingImageNumbersMiscEnglishGfx, VRAM_OBJ);
            LZ77UncompVRAM(sEndingImageTextHiraganaGfx, VRAM_BASE + 0x11000);
            break;

        default:
            LZ77UncompVRAM(sEndingImageNumbersMiscEnglishGfx, VRAM_OBJ);
            LZ77UncompVRAM(sEndingImageTextEnglishGfx, VRAM_BASE + 0x11000);
            break;
    }
    #else // !REGION_EU
    if (gLanguage > LANGUAGE_ENGLISH)
        ENDING_DATA.language = LANGUAGE_ENGLISH;

    if (ENDING_DATA.language == LANGUAGE_HIRAGANA)
        LZ77UncompVRAM(sEndingImageTextHiraganaGfx, VRAM_BASE + 0x11000);
    else
        LZ77UncompVRAM(sEndingImageTextEnglishGfx, VRAM_BASE + 0x11000);
    #endif // REGION_EU

    #ifdef REGION_EU
    DmaTransfer(3, sEndingImageTextPal, PALRAM_OBJ, sizeof(sEndingImageTextPal), 16);
    #else // !REGION_EU
    DMA_SET(3, sEndingImageTextPal, PALRAM_OBJ, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sEndingImageTextPal)));
    #endif // REGION_EU

    EndingImageLoadIGTAndPercentageGraphics();
    WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x512));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 30, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x512));

    gNextOamSlot = 0;
    ResetFreeOam();

    gBg0XPosition = 0;
    gBg0YPosition = 0x1000;
    gBg1XPosition = 0;
    gBg1YPosition = 0x1000;
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    ENDING_DATA.dispcnt = DCNT_OBJ | DCNT_BG0 | DCNT_BG1;
    ENDING_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

    gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE;
    gWrittenToBldalpha_H = 0;
    gWrittenToBldy_NonGameplay = BLDY_MAX_VALUE;

    GalleryVBlank();
}

/**
 * @brief 86a50 | 23c | Display the text on an ending image
 * 
 */
static void EndingImageDisplayText(void)
{
    u16* dst;
    const u16* src;
    s32 i;
    s32 nextSlot;
    s32 currSlot;
    u16 part;
    s32 palette;

    dst = (u16*)gOamData;
    nextSlot = 0;
    currSlot = 0;

    for (i = 0; i < ENDING_DATA.oamLength; i++)
    {
        if (ENDING_DATA.oamTypes[i] == ENDING_OAM_TYPE_NONE || ENDING_DATA.oamTypes[i] == ENDING_OAM_TYPE_CHAR)
            continue;

        if (ENDING_DATA.unk_160[i] < 64)
            ENDING_DATA.unk_160[i]++;

        palette = 0;
        if (i > 5)
        {
            if (ENDING_DATA.unk_160[i] < 4)
                palette = 11;
            else if (ENDING_DATA.unk_160[i] < 8)
                palette = 12;
            else if (ENDING_DATA.unk_160[i] < 12)
                palette = 13;
        }
        else if (i == 5)
        {
            ENDING_DATA.unk_160[i] &= 0x3F;
            palette = sEndingImage_54e2dc[ENDING_DATA.unk_160[i] / 8];
        }

        src = ENDING_DATA.oamFramePointers[i];
        part = *src++;
        nextSlot += MOD_AND(part, 0x100);

        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.y = part + ENDING_DATA.oamYPositions[i];

            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = MOD_AND(part + ENDING_DATA.oamXPositions[i], 0x200);

            *dst++ = *src++;
            gOamData[currSlot].split.paletteNum = palette;

            dst++;
        }
    }

    if (ENDING_DATA.hasNewRecord)
    {
        if (ENDING_DATA.newRecordPaletteTimer++ > 70)
            ENDING_DATA.newRecordPaletteTimer = 0;
            
        palette = sEndingImageNewRecordPalettes[ENDING_DATA.newRecordPaletteTimer / 6];

        #ifdef REGION_EU
        src = sEndingImageOamPointers_NewRecord[ENDING_DATA.language];
        #else // !REGION_EU
        src = sEndingImageOam_NewRecordEnglish;
        #endif // REGION_EU

        part = *src++;
        nextSlot += MOD_AND(part, 0x100);

        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.y = part + 59;

            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = MOD_AND(part + 48, 0x200);

            *dst++ = *src++;
            gOamData[currSlot].split.paletteNum = palette;

            dst++;
        }
    }

    gNextOamSlot = currSlot;
}

/**
 * @brief 86c8c | 1ec | Handles the ending image displaying
 * 
 * @return u8 bool, ended
 */
static u8 EndingImageDisplay(void)
{
    u8 ended;
    u8 i;

    ended = FALSE;

    switch (ENDING_DATA.timer++)
    {
        case 0:
            ENDING_DATA.unk_8++;
            break;

        case CONVERT_SECONDS(.5f):
            EndingImageLoadTextOAM(ENDING_IMAGE_OAM_SET_CLEAR_TIME);
            ENDING_DATA.unk_1 = TRUE;
            break;

        case CONVERT_SECONDS(1.f) + CONVERT_SECONDS(5.f / 6.f):
            EndingImageDisplayLinePermanently(ENDING_IMAGE_LINE_CLEAR_TIME);
            break;

        case CONVERT_SECONDS(3.f):
            EndingImageDisplayLinePermanently(ENDING_IMAGE_LINE_TIMER);
            if (gEndingFlags & ENDING_FLAG_NEW_TIME_ATTACK_RECORD)
                ENDING_DATA.hasNewRecord++;
            break;

        case CONVERT_SECONDS(5.5f):
            EndingImageLoadTextOAM(ENDING_IMAGE_OAM_SET_YOUR_RATE);
            break;

        case CONVERT_SECONDS(6.25f):
            if (ENDING_DATA.language == LANGUAGE_JAPANESE || ENDING_DATA.language == LANGUAGE_ENGLISH ||
                ENDING_DATA.language == LANGUAGE_ITALIAN)
                EndingImageDisplayLinePermanently(ENDING_IMAGE_LINE_YOUR_RATE);
            break;

        case CONVERT_SECONDS(6.f) + ONE_THIRD_SECOND:
            if (ENDING_DATA.language == LANGUAGE_JAPANESE || ENDING_DATA.language == LANGUAGE_ENGLISH ||
                ENDING_DATA.language == LANGUAGE_ITALIAN)
                EndingImageLoadTextOAM(ENDING_IMAGE_OAM_SET_COLLECTING);
            break;

        case CONVERT_SECONDS(7.f) + TWO_THIRD_SECOND:
            EndingImageDisplayLinePermanently(ENDING_IMAGE_LINE_COLLECTING);
            break;

        case CONVERT_SECONDS(8.f) + CONVERT_SECONDS(5.f / 6.f):
            EndingImageDisplayLinePermanently(ENDING_IMAGE_LINE_PERCENTAGE);
            break;

        case CONVERT_SECONDS(13.f):
            if (ENDING_DATA.language != LANGUAGE_HIRAGANA)
                EndingImageDisplayLinePermanently(ENDING_IMAGE_LINE_NEXT_MISSION);
            break;

        case CONVERT_SECONDS(22.f) + CONVERT_SECONDS(14.f / 15.f):
            if (gChangedInput & (KEY_A | KEY_B | KEY_START))
                FadeMusic(CONVERT_SECONDS(4.25f) + CONVERT_SECONDS(1.f / 60));
            else
                ENDING_DATA.timer--;
            break;

        case CONVERT_SECONDS(27.f) + CONVERT_SECONDS(11.f / 15.f):
            ended = TRUE;
    }

    if (ENDING_DATA.unk_8)
    {
        if (gBg0YPosition > 6)
        {
            gBg0YPosition -= 6;
            gBg1YPosition -= 6;
        }
        else
        {
            gBg0YPosition = 0;
            gBg1YPosition = 0;
            ENDING_DATA.unk_8 = FALSE;
        }
    }

    if (ENDING_DATA.timer > CONVERT_SECONDS(23.f))
        return ended;

    if (ENDING_DATA.timer >= CONVERT_SECONDS(13.5f) && gButtonInput & (KEY_R | KEY_L))
        return ended;

    if (ENDING_DATA.unk_1 == TRUE)
    {
        for (i = 6; i < ENDING_DATA.oamLength; i++)
            EndingImageUpdateLettersSpawnDelay(i);
    }

    EndingImageDisplayText();

    return ended;
}

/**
 * @brief 86e78 | 158 | Initializes the unlocked options
 * 
 */
static void UnlockedOptionsInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IF, IF_HBLANK);

    WRITE_16(REG_IME, TRUE);
    WRITE_16(REG_DISPCNT, 0);

    WRITE_16(REG_IME, FALSE);
    CallbackSetVblank(UnlockedOptionsVBlank);
    WRITE_16(REG_IME, TRUE);

    DMA_FILL_32(3, 0, &gNonGameplayRam, sizeof(gNonGameplayRam));
    ClearGfxRam();

    LZ77UncompVRAM(sUnlockedOptionsTileTable, VRAM_BASE + 0x8000);
    BitFill(3, -1, VRAM_BASE + 0x7FE0, 0x20, 32);
    BitFill(3, 0xF3FFF3FF, VRAM_BASE + 0x8800, 0x800, 32);

    #ifdef REGION_EU
    DmaTransfer(3, sUnlockedOptionsPal, PALRAM_BASE + 15 * PAL_ROW_SIZE, sizeof(sUnlockedOptionsPal), 16);
    #else // !REGION_EU
    DMA_SET(3, sUnlockedOptionsPal, PALRAM_BASE + 15 * PAL_ROW_SIZE, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sUnlockedOptionsPal)));
    #endif // REGION_EU

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 16, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 17, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));

    gNextOamSlot = 0;
    ResetFreeOam();

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0);

    ENDING_DATA.dispcnt = 0;
    ENDING_DATA.bldcnt = 0;

    gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE;
    gWrittenToBldalpha_H = 0;

    gWrittenToBldy_NonGameplay = BLDY_MAX_VALUE;

    UnlockedOptionsVBlank();
}

/**
 * @brief 86fd0 | 20c | Handles the pop up displaying what's been unlocked
 * 
 * @return u8 0, 1 pop up ended, 2 ended
 */
static u8 UnlockedOptionsPopUp(void)
{
    u32 msgNumber;
    u8 ended;

    ended = FALSE;

    switch (ENDING_DATA.timer++)
    {
        case 0:
            BitFill(3, 0, VRAM_BASE, 0x2000, 32);

            if (gEndingFlags & ENDING_FLAG_FIRST_CLEAR)
                msgNumber = FILE_SCREEN_TEXT_GALLERY_UNLOCK;
            else if (gEndingFlags & ENDING_FLAG_FIRST_HARD_MODE_CLEAR)
                msgNumber = FILE_SCREEN_TEXT_SOUND_TEST_UNLOCK;
            else if (gEndingFlags & ENDING_FLAG_FIRST_TIME_ATTACK_CLEAR)
                msgNumber = FILE_SCREEN_TEXT_TIME_ATTACK_RECORD_UNLOCK;
            else
                msgNumber = FILE_SCREEN_TEXT_NES_METROID_UNLOCK;

            TextStartFileScreen(msgNumber);
            ENDING_DATA.oamTypes[0] = 0;
            break;

        case CONVERT_SECONDS(.5f) + CONVERT_SECONDS(1.f / 30):
            ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_WIN0;
            WRITE_16(REG_WININ, 3);
            WRITE_16(REG_WINOUT, 0);
            ENDING_DATA.unk_1++;

            ENDING_DATA.oamXPositions[0] = SCREEN_X_MIDDLE;
            ENDING_DATA.oamXPositions[1] = SCREEN_X_MIDDLE;
            ENDING_DATA.oamYPositions[0] = SCREEN_Y_MIDDLE;
            ENDING_DATA.oamYPositions[1] = SCREEN_Y_MIDDLE;
            break;

        case CONVERT_SECONDS(2.f) + CONVERT_SECONDS(2.f / 15.f):
            ENDING_DATA.timer--;
            break;
    }

    if (ENDING_DATA.oamTypes[0] == 0)
        ENDING_DATA.oamTypes[0] = TextProcessFileScreenPopUp();

    if (ENDING_DATA.unk_1 == 1)
    {
        if (ENDING_DATA.oamXPositions[0] > 0x30)
        {
            ENDING_DATA.oamXPositions[0] -= 8;
            ENDING_DATA.oamXPositions[1] += 8;
            ENDING_DATA.oamYPositions[0] -= 4;
            ENDING_DATA.oamYPositions[1] += 4;
        }
        else
        {
            ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_WIN0;

            ENDING_DATA.oamXPositions[0] = 0x2C;
            ENDING_DATA.oamXPositions[1] = 0xBC;
            ENDING_DATA.oamYPositions[0] = 0x2C;
            ENDING_DATA.oamYPositions[1] = 0x74;
            ENDING_DATA.unk_1++;
        }
    }
    else if (ENDING_DATA.unk_1 == 2)
    {
        if (gChangedInput & KEY_A)
        {
            ENDING_DATA.dispcnt = DCNT_BG1 | DCNT_WIN0;
            ENDING_DATA.unk_1++;
            ENDING_DATA.timer++;
        }
    }
    else if (ENDING_DATA.unk_1 == 3)
    {
        if (ENDING_DATA.oamXPositions[0] < 0x70)
        {
            ENDING_DATA.oamXPositions[0] += 8;
            ENDING_DATA.oamXPositions[1] -= 8;
            ENDING_DATA.oamYPositions[0] += 4;
            ENDING_DATA.oamYPositions[1] -= 4;
        }
        else
        {
            ENDING_DATA.dispcnt = 0;

            if (gEndingFlags & ENDING_FLAG_FIRST_CLEAR)
                ended++;
            else
                ended += 2;
        }
    }

    return ended;
}

static CreditsFunc_T sCreditsFunctionPointers[3] = {
    [0] = CreditsDisplay,
    [1] = CreditsChozoWallMovement,
    [2] = CreditsChozoWallZoom
};

static CreditsFunc_T sEndScreenFunctionPointers[1] = {
    [0] = EndScreenSamusPosing
};

static CreditsFunc_T sEndingImageFunctionPointers[1] = {
    [0] = EndingImageDisplay
};

static CreditsFunc_T sUnlockedOptionsFunctionPointers[2] = {
    [0] = UnlockedOptionsPopUp,
    [1] = UnlockedOptionsPopUp
};

/**
 * @brief 871dc | 208 | Main loop for the credits
 * 
 * @return u32 bool, ended
 */
u32 CreditsMainLoop(void)
{
    u32 ended;
    u32 stageResult;

    ended = FALSE;
    ENDING_DATA.unk_6 = 0;
    gNextOamSlot = 0;

    switch (gSubGameMode1)
    {
        case 0:
            CreditsInit();
            gSubGameMode1++;
            break;

        case 2:
            #if defined(DEBUG) && !defined(REGION_US_BETA)
            // This is a debug feature that lets you skip the credits by pressing L.
            // It's part of the EU beta ROM but not the US beta ROM
            if (gChangedInput & KEY_L)
            {
                ENDING_DATA.bldcnt = UCHAR_MAX;
                gSubGameMode1++;
                break;
            }
            #endif // DEBUG && !REGION_US_BETA
            stageResult = sCreditsFunctionPointers[ENDING_DATA.stage]();
            if (stageResult)
            {
                ENDING_DATA.stage++;
                ENDING_DATA.unk_1 = 0;
                ENDING_DATA.endScreenTimer = 0;
                ENDING_DATA.timer = 0;

                if (stageResult > 1)
                    gSubGameMode1++;
            }

            ResetFreeOam();
            break;

        case 7:
        case 11:
            if (gWrittenToBldy_NonGameplay < BLDY_MAX_VALUE)
                gWrittenToBldy_NonGameplay++;
            else
                gSubGameMode1++;
            break;

        case 4:
            EndScreenInit();
            gSubGameMode1++;
            break;

        case 6:
            if (sEndScreenFunctionPointers[ENDING_DATA.stage]())
                gSubGameMode1++;
            break;

        case 8:
            EndingImageInit();
            gSubGameMode1++;
            break;

        case 5:
        case 9:
        case 13:
            if (gWrittenToBldy_NonGameplay != 0)
                gWrittenToBldy_NonGameplay--;
            else
            {
                ENDING_DATA.bldcnt = 0;
                gSubGameMode1++;
            }
            break;

        case 10:
            if (sEndingImageFunctionPointers[ENDING_DATA.stage]())
            {
                if (gEndingFlags & (ENDING_FLAG_UNKNOWN | ENDING_FLAG_FIRST_TIME_ATTACK_CLEAR |
                    ENDING_FLAG_FIRST_HARD_MODE_CLEAR | ENDING_FLAG_FIRST_CLEAR))
                {
                    ENDING_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

                    gWrittenToBldy_NonGameplay = 0;
                    gSubGameMode1++;
                }
                else
                {
                    gDisableSoftReset = FALSE;
                    ended++;
                }
            }

            ResetFreeOam();
            break;

        case 1:
        case 3:
            gSubGameMode1++;
            break;

        case 15:
            if (gEndingFlags & (ENDING_FLAG_UNKNOWN | ENDING_FLAG_FIRST_TIME_ATTACK_CLEAR |
                ENDING_FLAG_FIRST_HARD_MODE_CLEAR | ENDING_FLAG_FIRST_CLEAR))
            {
                gSubGameMode1++;
                break;
            }

            gDisableSoftReset = FALSE;
            ended++;
            break;

        case 12:
            UnlockedOptionsInit();
            gSubGameMode1++;
            break;

        case 14:
            stageResult = sUnlockedOptionsFunctionPointers[ENDING_DATA.stage]();
            if (stageResult)
            {
                gEndingFlags = 0;
                ENDING_DATA.stage++;
                ENDING_DATA.unk_1 = 0;
                ENDING_DATA.endScreenTimer = 0;
                ENDING_DATA.timer = 0;

                if (stageResult > 1)
                    gSubGameMode1++;
            }

            ResetFreeOam();
            break;
    }

    return ended;
}

/**
 * @brief 873e4 | 238 | Initializes the gallery
 * 
 */
static void GalleryInit(void)
{
    u32 endingNbr;
    u32 i;
    u32 bit;

    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IF, IF_HBLANK);

    WRITE_16(REG_IME, TRUE);
    WRITE_16(REG_DISPCNT, 0);

    WRITE_16(REG_IME, FALSE);
    CallbackSetVblank(GalleryVBlank);
    WRITE_16(REG_IME, TRUE);

    if (gSubGameMode1 == 0)
    {
        ClearGfxRam();
        DMA_FILL_32(3, 0, &gNonGameplayRam, sizeof(gNonGameplayRam));
    }

    endingNbr = ENDING_DATA.endingNumber;

    for (i = 0; i < 8; i++)
    {
        bit = 1 << endingNbr;
        if (gFileScreenOptionsUnlocked.galleryImages & bit)
            break;

        if (ENDING_DATA.completionPercentage != 0)
        {
            if (endingNbr != 0)
                endingNbr--;
            else
                endingNbr = 7;
        }
        else
        {
            if (endingNbr < 7)
                endingNbr++;
            else
                endingNbr = 0;
        }
    }

    ENDING_DATA.endingNumber = endingNbr;

    LZ77UncompVRAM(sEndingImagesTopGfxPointers[endingNbr], VRAM_BASE);
    LZ77UncompVRAM(sEndingImagesBottomGfxPointers[endingNbr], VRAM_BASE + 0x8000);
    LZ77UncompVRAM(sEndingImagesTopTileTablePointers[endingNbr], VRAM_BASE + 0xE000);
    LZ77UncompVRAM(sEndingImagesHalfTileTablePointers[endingNbr], VRAM_BASE + 0xF800);

    BitFill(3, 0x4FF04FF, VRAM_BASE + 0xE800, 0x800, 32);

    #ifdef REGION_EU
    DmaTransfer(3, sEndingImagesPalPointers[endingNbr], PALRAM_BASE, PAL_SIZE, 16);
    #else // !REGION_EU
    DMA_SET(3, sEndingImagesPalPointers[endingNbr], PALRAM_BASE, C_32_2_16(DMA_ENABLE, COLORS_IN_PAL));
    #endif // REGION_EU

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x512));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 30, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x512));

    gNextOamSlot = 0;
    ResetFreeOam();

    gBg0XPosition = 0;
    gBg0YPosition = 0x1000;
    gBg1XPosition = 0;
    gBg1YPosition = 0x1000;
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, 0x1000);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, 0x1000);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    ENDING_DATA.unk_8 = 0;

    ENDING_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_OBJ;
    ENDING_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

    GalleryVBlank();
}

/**
 * @brief 8761c | 15c | Handles the display of the gallery image
 * 
 * @return u32 
 */
static u32 GalleryDisplay(void)
{
    u8 endingNbr;
    u32 ended;
    s32 velocity;
    u32 change;
    u8 complPercent;
    u8 bit;

    endingNbr = ENDING_DATA.endingNumber;
    bit = 1 << endingNbr;
    ended = FALSE;
    change = FALSE;
    complPercent = 0;

    if (gChangedInput & KEY_B)
    {
        ENDING_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

        gWrittenToBldy_NonGameplay = 0;
        ended = TRUE;
    }
    else if (gChangedInput & (KEY_A | KEY_RIGHT))
    {
        if (endingNbr < 7)
            endingNbr++;
        else
            endingNbr = 0;
        
        if (gFileScreenOptionsUnlocked.galleryImages > bit)
            change++;
    }
    else if (gChangedInput & KEY_LEFT)
    {
        if (endingNbr != 0)
            endingNbr--;
        else
            endingNbr = 7;

        complPercent++;
        if (gFileScreenOptionsUnlocked.galleryImages > bit)
            change++;
    }

    
    if (change)
    {
        ENDING_DATA.endingNumber = endingNbr;
        ENDING_DATA.completionPercentage = complPercent;

        ENDING_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

        gWrittenToBldy_NonGameplay = 0;
        gSubGameMode1 = 5;
    }

    change = FALSE;
    velocity = 8;

    if (ENDING_DATA.unk_8 != 0)
    {
        if (gButtonInput & KEY_DOWN)
            change = TRUE;

        velocity = 12;
    }

    if (!change)
    {
        if (gBg0YPosition > velocity)
        {
            gBg0YPosition -= velocity;
            gBg1YPosition -= velocity;
        }
        else
        {
            GALLERY_RESET_BG_POS();
            ENDING_DATA.unk_8 = TRUE;
        }
    }
    else
    {
        gBg0YPosition += velocity;
        gBg1YPosition += velocity;

        if (gBg0YPosition > BLOCK_SIZE * 64)
        {
            gBg0YPosition = BLOCK_SIZE * 64;
            gBg1YPosition = BLOCK_SIZE * 64;
        }
    }

    return ended;
}

/**
 * @brief 87778 | d8 | Main loop for the gallery
 * 
 * @return u32 bool, ended
 */
u32 GalleryMainLoop(void)
{
    u32 ended;

    ended = FALSE;
    ENDING_DATA.unk_6 = 0;

    switch (gSubGameMode1)
    {
        case 0:
        case 4:
            GalleryInit();
            gSubGameMode1 = 1;
            break;

        case 1:
            if (gWrittenToBldy_NonGameplay != 0)
            {
                gWrittenToBldy_NonGameplay--;
                break;
            }

            ENDING_DATA.bldcnt = 0;
            gSubGameMode1++;
            break;

        case 2:
            if (GalleryDisplay())
                gSubGameMode1++;
            break;

        case 3:
        case 5:
            if (gWrittenToBldy_NonGameplay < BLDY_MAX_VALUE)
            {
                if (MOD_AND(ENDING_DATA.timer++, 2))
                    gWrittenToBldy_NonGameplay++;

                break;
            }

            if (gSubGameMode1 == 3)
                ended++;
            else
                gSubGameMode1 = 4;
            break;
    }

    return ended;
}
