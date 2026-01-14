#include "fusion_gallery.h"
#include "dma.h"

#include "data/shortcut_pointers.h"
#include "data/fusion_gallery_data.h"

#include "constants/audio.h"
#include "constants/ending_and_gallery.h"
#include "constants/game_state.h"
#include "constants/text.h"

#include "structs/bg_clip.h"
#include "structs/display.h"
#include "structs/fusion_gallery.h"
#include "structs/game_state.h"

#define IMAGE_LENGTH (BLOCK_SIZE * 64)

/**
 * @brief 847f8 | 78 | V-blank code for the fusion gallery
 * 
 */
static void FusionGalleryVBlank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16(DMA_ENABLE | DMA_32BIT, OAM_SIZE / sizeof(u32)));

    WRITE_16(REG_DISPCNT, FUSION_GALLERY_DATA.dispcnt);
    WRITE_16(REG_BLDCNT, FUSION_GALLERY_DATA.bldcnt);

    WRITE_16(REG_BLDY, gWrittenToBldy_NonGameplay);

    WRITE_16(REG_BG0VOFS, MOD_AND(gBg0YPosition / 16, 0x200));
    WRITE_16(REG_BG1VOFS, MOD_AND(gBg1YPosition / 16, 0x200));
}

static void FusionGalleryInit(void)
{
    u32 image;

    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IF, IF_HBLANK);

    WRITE_16(REG_IME, TRUE);
    WRITE_16(REG_DISPCNT, 0);

    WRITE_16(REG_IME, FALSE);
    CallbackSetVblank(FusionGalleryVBlank);
    WRITE_16(REG_IME, TRUE);

    if (gSubGameMode1 == 0)
    {
        ClearGfxRam();
        DMA_FILL_32(3, 0, &gNonGameplayRam, sizeof(gNonGameplayRam));
    }

    image = FUSION_GALLERY_DATA.currentImage;
    LZ77UncompVRAM(sFusionGalleryData[image].pTopGfx, VRAM_BASE);
    LZ77UncompVRAM(sFusionGalleryData[image].pBottomGfx, VRAM_BASE + 0x8000);
    LZ77UncompVRAM(sFusionGalleryData[image].pTopTileTable, VRAM_BASE + 0xE000);
    LZ77UncompVRAM(sFusionGalleryData[image].pBottomTileTable, VRAM_BASE + 0xF800);

    BitFill(3, 0x4FF04FF, VRAM_BASE + 0xE800, 0x800, 32);
    #ifdef REGION_EU
    DmaTransfer(3, sFusionGalleryData[image].pPalette, PALRAM_BASE, PAL_SIZE, 16);
    #else // !REGION_EU
    DMA_SET(3, sFusionGalleryData[image].pPalette, PALRAM_BASE, C_32_2_16(DMA_ENABLE, 16 * PAL_ROW));
    #endif // REGION_EU

    WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x512));
    WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 30, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x512));

    gNextOamSlot = 0;
    ResetFreeOam();

    gBg0XPosition = 0;
    gBg0YPosition = IMAGE_LENGTH;
    gBg1XPosition = 0;
    gBg1YPosition = IMAGE_LENGTH;
    gBg2XPosition = 0;
    gBg2YPosition = 0;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    WRITE_16(REG_BG0HOFS, 0);
    WRITE_16(REG_BG0VOFS, IMAGE_LENGTH);
    WRITE_16(REG_BG1HOFS, 0);
    WRITE_16(REG_BG1VOFS, IMAGE_LENGTH);
    WRITE_16(REG_BG2HOFS, 0);
    WRITE_16(REG_BG2VOFS, 0);
    WRITE_16(REG_BG3HOFS, 0);
    WRITE_16(REG_BG3VOFS, 0);

    FUSION_GALLERY_DATA.finishedInitialScroll = FALSE;
    FUSION_GALLERY_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_OBJ;
    ENDING_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

    FusionGalleryVBlank();
}

/**
 * @brief 84a40 | 120 | Handles the display of the fusion gallery image
 * 
 * @return u32 bool, ended
 */
static u32 FusionGalleryDisplay(void)
{
    u8 imageId;
    u32 ended;
    s32 velocity;
    u32 change;
    u8 complPercent;
    u8 bit;

    ended = FALSE;
    change = FALSE;
    imageId = FUSION_GALLERY_DATA.currentImage;
    complPercent = 0;

    if (gChangedInput & KEY_B)
    {
        FUSION_GALLERY_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

        gWrittenToBldy_NonGameplay = 0;
        ended = TRUE;
    }
    else if (gChangedInput & (KEY_A | KEY_RIGHT))
    {
        if (imageId < NUMBER_OF_FUSION_GALLERY_IMAGES - 1)
            imageId++;
        else
            imageId = 0;
        
        change++;
    }
    else if (gChangedInput & KEY_LEFT)
    {
        if (imageId != 0)
            imageId--;
        else
            imageId = NUMBER_OF_FUSION_GALLERY_IMAGES - 1;

        change++;
    }

    
    if (change)
    {
        FUSION_GALLERY_DATA.currentImage = imageId;

        FUSION_GALLERY_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;

        gWrittenToBldy_NonGameplay = 0;
        gSubGameMode1 = 5;
    }

    change = FALSE;
    velocity = 8;

    if (FUSION_GALLERY_DATA.finishedInitialScroll)
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
            FUSION_GALLERY_DATA.finishedInitialScroll = TRUE;
        }
    }
    else
    {
        gBg0YPosition += velocity;
        gBg1YPosition += velocity;

        if (gBg0YPosition > IMAGE_LENGTH)
        {
            gBg0YPosition = IMAGE_LENGTH;
            gBg1YPosition = IMAGE_LENGTH;
        }
    }

    return ended;
}

/**
 * @brief 84b60 | d4 | Fusion gallery main loop
 * 
 * @return u32 bool, ended
 */
u32 FusionGalleryMainLoop(void)
{
    u32 ended;

    ended = FALSE;
    FUSION_GALLERY_DATA.stage = 0;

    switch (gSubGameMode1)
    {
        case 0:
        case 4:
            FusionGalleryInit();
            gSubGameMode1 = 1;
            break;

        case 1:
            if (gWrittenToBldy_NonGameplay != 0)
            {
                gWrittenToBldy_NonGameplay--;
                break;
            }

            FUSION_GALLERY_DATA.bldcnt = 0;
            gSubGameMode1++;
            break;

        case 2:
            if (FusionGalleryDisplay())
                gSubGameMode1++;
            break;

        case 3:
        case 5:
            if (gWrittenToBldy_NonGameplay < BLDY_MAX_VALUE)
            {
                if (MOD_AND(FUSION_GALLERY_DATA.fadeOutTimer++, 2) != 0)
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
