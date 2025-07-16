#include "tourian_escape.h"
#include "macros.h"
#include "animated_graphics.h"
#include "audio_wrappers.h"
#include "fixed_point.h"
#include "complex_oam.h"
#include "callbacks.h"
#include "dma.h"
#include "room_cutscene.h"

#include "data/generic_data.h"
#include "data/intro_data.h"
#include "data/shortcut_pointers.h"
#include "data/tourian_escape_data.h"
#include "data/cutscenes/story_text_cutscene_data.h"

#include "constants/audio.h"
#include "constants/connection.h"
#include "constants/samus.h"
#include "constants/text.h"

#include "structs/bg_clip.h"
#include "structs/display.h"
#include "structs/tourian_escape.h"

/**
 * @brief 81248 | d8 | V-blank for the tourian escape
 * 
 */
static void TourianEscapeVBlank(void)
{
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16(DMA_ENABLE | DMA_32BIT, OAM_SIZE / sizeof(u32)));

    WRITE_16(REG_DISPCNT, TOURIAN_ESCAPE_DATA.dispcnt);
    WRITE_16(REG_BLDCNT, TOURIAN_ESCAPE_DATA.bldcnt);

    WRITE_16(REG_BLDALPHA, C_16_2_8(gIoRegistersBackup.BLDALPHA_NonGameplay_EVB, gIoRegistersBackup.BLDALPHA_NonGameplay_EVA));
    WRITE_16(REG_BLDY, gWrittenToBldy_NonGameplay);

    WRITE_16(REG_BG0HOFS, SUB_PIXEL_TO_PIXEL(gBg0XPosition));
    WRITE_16(REG_BG0VOFS, SUB_PIXEL_TO_PIXEL(gBg0YPosition));

    WRITE_16(REG_BG1HOFS, SUB_PIXEL_TO_PIXEL(gBg1XPosition));
    WRITE_16(REG_BG1VOFS, SUB_PIXEL_TO_PIXEL(gBg1YPosition));

    WRITE_16(REG_BG2HOFS, SUB_PIXEL_TO_PIXEL(gBg2XPosition));
    WRITE_16(REG_BG2VOFS, SUB_PIXEL_TO_PIXEL(gBg2YPosition));

    WRITE_16(REG_BG3HOFS, SUB_PIXEL_TO_PIXEL(gBg3XPosition));
    WRITE_16(REG_BG3VOFS, SUB_PIXEL_TO_PIXEL(gBg3YPosition));

    AnimatedGraphicsTransfer();
}

/**
 * @brief 81320 | f8 | V-blank for the tourian escape (zebes exploding sequence)
 * 
 */
static void TourianEscapeVBlankZebesExploding(void)
{
    DMA_SET(3, gOamData, OAM_BASE, C_32_2_16(DMA_ENABLE | DMA_32BIT, OAM_SIZE / sizeof(u32)));

    WRITE_16(REG_DISPCNT, TOURIAN_ESCAPE_DATA.dispcnt);
    WRITE_16(REG_BLDCNT, TOURIAN_ESCAPE_DATA.bldcnt);

    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_H, gWrittenToBldalpha_L));
    WRITE_16(REG_BLDY, gWrittenToBldy_NonGameplay);

    WRITE_16(REG_BG0HOFS, MOD_AND(gBg0XPosition, 0x200));
    WRITE_16(REG_BG0VOFS, MOD_AND(gBg0YPosition, 0x100));

    WRITE_16(REG_BG1HOFS, MOD_AND(gBg1XPosition, 0x200));
    WRITE_16(REG_BG1VOFS, MOD_AND(gBg1YPosition, 0x100));

    WRITE_16(REG_BG2HOFS, MOD_AND(gBg2XPosition, 0x200));
    WRITE_16(REG_BG2VOFS, MOD_AND(gBg2YPosition, 0x100));

    WRITE_16(REG_WIN0H, C_16_2_8(TOURIAN_ESCAPE_DATA.win0h_H, TOURIAN_ESCAPE_DATA.win0h_L));
    WRITE_16(REG_WIN0V, C_16_2_8(TOURIAN_ESCAPE_DATA.win0v_H, TOURIAN_ESCAPE_DATA.win0v_L));
}

/**
 * @brief 81418 | 100 | V-blank for the tourian escape (samus surrounded sequence)
 * 
 */
static void TourianEscapeVBlankSamusSurrounded(void)
{
    WRITE_16(REG_DISPCNT, TOURIAN_ESCAPE_DATA.dispcnt);
    WRITE_16(REG_BLDCNT, TOURIAN_ESCAPE_DATA.bldcnt);
    WRITE_16(REG_BLDALPHA, C_16_2_8(gWrittenToBldalpha_H, gWrittenToBldalpha_L));

    WRITE_16(REG_BG2PA, gWrittenToBg2Pa);
    WRITE_16(REG_BG2PB, gWrittenToBg2Pb);
    WRITE_16(REG_BG2PC, gWrittenToBg2Pc);
    WRITE_16(REG_BG2PD, gWrittenToBg2Pd);

    WRITE_16(REG_BG2X_L, gWrittenToBg2X);
    WRITE_16(REG_BG2X_H, (gWrittenToBg2X & (0xFFF << 16)) >> 16);

    WRITE_16(REG_BG2Y_L, gWrittenToBg2Y);
    WRITE_16(REG_BG2Y_H, (gWrittenToBg2Y & (0xFFF << 16)) >> 16);

    WRITE_16(REG_BG0HOFS, MOD_AND(gBg0XPosition, 0x200));
    WRITE_16(REG_BG0VOFS, MOD_AND(gBg0YPosition, 0x100));

    WRITE_16(REG_BG1HOFS, MOD_AND(gBg1XPosition, 0x200));
    WRITE_16(REG_BG1VOFS, MOD_AND(gBg1YPosition, 0x100));

    WRITE_16(REG_BG2HOFS, MOD_AND(gBg2XPosition, 0x200));
    WRITE_16(REG_BG2VOFS, MOD_AND(gBg2YPosition, 0x100));
}

/**
 * @brief 81518 | 16c | Processes the OAM
 * 
 */
static void TourianEscapeProcessOam(void)
{
    u16* dst;
    const u16* src;
    u16 nextSlot;
    u16 currSlot;
    u16 part;
    u16 yPosition;
    u16 xPosition;
    u16 i;

    dst = (u16*)gOamData;
    nextSlot = 0;
    currSlot = 0;
    
    if (TOURIAN_ESCAPE_DATA.unk_BE > 2)
    {
        src = sTourianEscapeOam_375d10_Frame0;
        part = *src++;
        nextSlot += MOD_AND(part, 0x100);

        xPosition = SCREEN_X_MIDDLE + 8;
        yPosition = SCREEN_Y_MIDDLE;

        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.objMode = 1;

            gOamData[currSlot].split.y = part + yPosition;

            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = MOD_AND(part + xPosition, 0x200);

            *dst++ = *src++;
            *dst++;
        }
    }

    for (i = 0; i < TOURIAN_ESCAPE_MAX_OBJECTS; i++)
    {
        if (!TOURIAN_ESCAPE_DATA.unk_8[i])
            continue;
        
        src = TOURIAN_ESCAPE_DATA.oamFramePointers[i];
        part = *src++;
        nextSlot += MOD_AND(part, 0x100);

        xPosition = TOURIAN_ESCAPE_DATA.oamXPositions[i];
        yPosition = TOURIAN_ESCAPE_DATA.oamYPositions[i];

        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.y = part + yPosition;

            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = MOD_AND(part + xPosition, 0x200);

            *dst++ = *src++;

            gOamData[currSlot].split.priority = TOURIAN_ESCAPE_DATA.oamPriorities[i];
            *dst++;
        }
    }

    gNextOamSlot = currSlot;
}

/**
 * @brief 81684 | 104 | Calculates the BG2 position and matrix parameters
 * 
 */
static void TourianEscapeCalculateBg2(void)
{
    gWrittenToBg2Pa = FixedMultiplication(COS(gBg2Rotation), FixedInverse(gBg2XScaling));
    gWrittenToBg2Pb = FixedMultiplication(SIN(gBg2Rotation), FixedInverse(gBg2XScaling));
    gWrittenToBg2Pc = FixedMultiplication(-SIN(gBg2Rotation), FixedInverse(gBg2YScaling));
    gWrittenToBg2Pd = gWrittenToBg2Pa;

    gWrittenToBg2X = (SCREEN_X_MIDDLE << 8) - gWrittenToBg2Pa * SCREEN_X_MIDDLE - gWrittenToBg2Pb * SCREEN_Y_MIDDLE;
    gWrittenToBg2Y = (SCREEN_Y_MIDDLE << 8) - gWrittenToBg2Pc * SCREEN_X_MIDDLE - gWrittenToBg2Pd * SCREEN_Y_MIDDLE;
}

/**
 * @brief 81788 | 144 | To document
 * 
 * @param param_1 To document
 */
static void unk_81788(u8 param_1)
{
    s32 i;
    u32 var_0;
    u32 offset;

    for (i = 4; i < TOURIAN_ESCAPE_MAX_OBJECTS; i++)
    {
        offset = TOURIAN_ESCAPE_DATA.oamTimers[i] / 4;
        if (MOD_AND(TOURIAN_ESCAPE_DATA.unk_8[i], 2))
        {
            TOURIAN_ESCAPE_DATA.oamFramePointers[i] = sTourianEscape_47ce00[offset];
        }
        else
        {
            TOURIAN_ESCAPE_DATA.oamFramePointers[i] = sTourianEscape_47ce10[offset];
        }

        var_0 = FALSE;
        if (!param_1)
        {
            if (TOURIAN_ESCAPE_DATA.oamXPositions[i] < 256)
            {
                TOURIAN_ESCAPE_DATA.oamXPositions[i] += TOURIAN_ESCAPE_DATA.unk_96[i];
            }
            else
            {
                var_0 = TRUE;
            }
        }
        else
        {
            if (TOURIAN_ESCAPE_DATA.oamYPositions[i] < 252)
            {
                TOURIAN_ESCAPE_DATA.oamYPositions[i] -= TOURIAN_ESCAPE_DATA.unk_96[i];
            }
            else
            {
                var_0 = TRUE;
            }
        }

        if (var_0)
        {
            TOURIAN_ESCAPE_DATA.unk_8[i] ^= 3;
            TOURIAN_ESCAPE_DATA.oamFrames[i] = MOD_AND(TOURIAN_ESCAPE_DATA.oamFrames[i] + 1, 16);

            TOURIAN_ESCAPE_DATA.oamXPositions[i] = sTourianEscape_47ce20[TOURIAN_ESCAPE_DATA.oamFrames[i]][0];
            TOURIAN_ESCAPE_DATA.oamYPositions[i] = sTourianEscape_47ce20[TOURIAN_ESCAPE_DATA.oamFrames[i]][1];
            TOURIAN_ESCAPE_DATA.unk_96[i] = sTourianEscape_47ce20[TOURIAN_ESCAPE_DATA.oamFrames[i]][2];
        }

        TOURIAN_ESCAPE_DATA.oamTimers[i] = MOD_AND(TOURIAN_ESCAPE_DATA.oamTimers[i] + 1, 16);
    }
}

/**
 * @brief 818cc | 20c | To document
 * 
 */
static void unk_818cc(void)
{
    u16* dst;
    const u16* src;
    u16 nextSlot;
    u16 currSlot;
    u16 part;
    u16 yPosition;
    u16 xPosition;
    u16 i;

    #ifdef BUGFIX
    currSlot = 0;
    #endif // BUGFIX

    dst = (u16*)gOamData;

    if (TOURIAN_ESCAPE_DATA.unk_8[0])
    {
        src = TOURIAN_ESCAPE_DATA.oamFramePointers[0];
        part = *src++;
        nextSlot = MOD_AND(part, 0x100);

        yPosition = TOURIAN_ESCAPE_DATA.oamYPositions[0];
        xPosition = TOURIAN_ESCAPE_DATA.oamXPositions[0];
        
        for (currSlot = 0; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;
            
            part = *src++;
            *dst++ = part;
            
            *dst++ = *src++;
            dst++;

            ProcessComplexOam(currSlot, xPosition, yPosition, 0, TOURIAN_ESCAPE_DATA.unk_82, TRUE, 0);
        }

        CalculateOamPart4(0, TOURIAN_ESCAPE_DATA.unk_82, 0);
    }

    if (TOURIAN_ESCAPE_DATA.unk_8[1])
    {
        src = TOURIAN_ESCAPE_DATA.oamFramePointers[1];
        part = *src++;
        nextSlot += MOD_AND(part, 0x100);

        yPosition = TOURIAN_ESCAPE_DATA.oamYPositions[1];
        xPosition = TOURIAN_ESCAPE_DATA.oamXPositions[1];
    
        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;
            
            part = *src++;
            *dst++ = part;
            
            *dst++ = *src++;
            dst++;

            ProcessComplexOam(currSlot, xPosition, yPosition, 0, TOURIAN_ESCAPE_DATA.scaling, TRUE, 4);
        }

        CalculateOamPart4(0, TOURIAN_ESCAPE_DATA.scaling, 16);
    }

    for (i = 4; i < TOURIAN_ESCAPE_MAX_OBJECTS; i++)
    {
        if (!TOURIAN_ESCAPE_DATA.unk_8[i])
            continue;

        src = TOURIAN_ESCAPE_DATA.oamFramePointers[i];
        part = *src++;
        nextSlot += MOD_AND(part, 0x100);

        yPosition = TOURIAN_ESCAPE_DATA.oamYPositions[i];
        xPosition = TOURIAN_ESCAPE_DATA.oamXPositions[i];

        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.y = part + yPosition;

            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = MOD_AND(part + xPosition, 0x200);

            *dst++ = *src++;

            gOamData[currSlot].split.priority = TOURIAN_ESCAPE_DATA.oamPriorities[i];
            *dst++;
        }
    }

    gNextOamSlot = currSlot;
}

/**
 * @brief 81ad8 | 22c | To document
 * 
 */
static void unk_81ad8(void)
{
    const u16* src;
    u16* dst;
    u16 currSlot;
    u16 nextSlot;
    u16 yPosition;
    u16 xPosition;
    u16 part;
    u8 offset;
    u16 i;
    const u16* pal;

    if ((TOURIAN_ESCAPE_DATA.oamTimers[0] & 3) < 2)
    {
        TOURIAN_ESCAPE_DATA.oamXPositions[0] = 0x6D;
        TOURIAN_ESCAPE_DATA.oamYPositions[0] = 0x46;
    }
    else
    {
        TOURIAN_ESCAPE_DATA.oamXPositions[0] = 0x6C;
        TOURIAN_ESCAPE_DATA.oamYPositions[0] = 0x47;
    }

    TOURIAN_ESCAPE_DATA.oamTimers[0]++;

    if (TOURIAN_ESCAPE_DATA.unk_8[1])
    {
        offset = TOURIAN_ESCAPE_DATA.oamTimers[1]++ / 4;
        if (offset >= ARRAY_SIZE(sTourianEscape_47ce90))
        {
            TOURIAN_ESCAPE_DATA.oamTimers[1] = 0;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = 0x6D;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = 0x46;
            offset = 0;
        }

        TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47cea0[offset];
        TOURIAN_ESCAPE_DATA.oamXPositions[1] += sTourianEscape_47ce80[offset];
        TOURIAN_ESCAPE_DATA.oamYPositions[1] += sTourianEscape_47ce90[offset];
    }

    if (TOURIAN_ESCAPE_DATA.unk_8[2])
    {
        offset = TOURIAN_ESCAPE_DATA.oamTimers[2]++ / 4;
        if (offset >= ARRAY_SIZE(sTourianEscape_47ce90))
        {
            TOURIAN_ESCAPE_DATA.oamTimers[2] = 0;
            TOURIAN_ESCAPE_DATA.oamXPositions[2] = 0x6D;
            TOURIAN_ESCAPE_DATA.oamYPositions[2] = 0x46;
            offset = 0;
        }

        TOURIAN_ESCAPE_DATA.oamFramePointers[2] = sTourianEscape_47cea0[offset];
        TOURIAN_ESCAPE_DATA.oamXPositions[2] += sTourianEscape_47ce80[offset];
        TOURIAN_ESCAPE_DATA.oamYPositions[2] -= sTourianEscape_47ce90[offset];
    }

    if (MOD_AND(TOURIAN_ESCAPE_DATA.timer, 8) < 4)
    {
        pal = sTourianEscape_479f00 - 16;
    }
    else
    {
        pal = sTourianEscape_479f00;
    }

    #ifdef REGION_EU
    DmaTransfer(3, pal, PALRAM_OBJ + 5 * PAL_ROW_SIZE, PAL_ROW_SIZE, 16);
    #else // !REGION_EU
    DMA_SET(3, pal, PALRAM_OBJ + 5 * PAL_ROW_SIZE, C_32_2_16(DMA_ENABLE, PAL_ROW));
    #endif // REGION_EU

    dst = (u16*)gOamData;
    nextSlot = 0;
    currSlot = 0;

    for (i = 0; i < 4; i++)
    {
        if (!TOURIAN_ESCAPE_DATA.unk_8[i])
            continue;

        src = TOURIAN_ESCAPE_DATA.oamFramePointers[i];
        part = *src++;
        nextSlot += MOD_AND(part, 0x100);
        
        xPosition = TOURIAN_ESCAPE_DATA.oamXPositions[i];
        yPosition = TOURIAN_ESCAPE_DATA.oamYPositions[i];

        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.y = part + yPosition;
            gOamData[currSlot].split.objMode = 1;

            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = MOD_AND(part + xPosition, 0x200);

            *dst++ = *src++;
            dst++;
        }
    }

    gNextOamSlot = currSlot;
}

/**
 * @brief 81d04 | 12c | Initializes the tourian escape
 * 
 */
static void TourianEscapeInit(void)
{
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_DISPSTAT, READ_16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~IF_HBLANK);
    WRITE_16(REG_IF, IF_HBLANK);

    WRITE_16(REG_IME, TRUE);
    WRITE_16(REG_DISPCNT, 0);
    WRITE_16(REG_BLDCNT, 0);

    gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE;
    gWrittenToBldalpha_H = 0;
    gWrittenToBldy_NonGameplay = 0;

    WRITE_16(REG_IME, FALSE);
    CallbackSetVblank(NULL);
    WRITE_16(REG_IME, TRUE);

    DMA_FILL_32(3, 0, &gNonGameplayRam, sizeof(gNonGameplayRam));
    ClearGfxRam();

    LZ77UncompVRAM(sMotherShipBlowingUpExplosionsGfx, VRAM_OBJ);
    LZ77UncompVRAM(sTourianEscapeDebrisGfx, VRAM_BASE + 0x13000);

    #ifdef REGION_EU
    DmaTransfer(3, sMotherShipBlowingUpExplosionsPal, PALRAM_OBJ, sizeof(sMotherShipBlowingUpExplosionsPal), 16);
    #else // !REGION_EU
    DMA_SET(3, sMotherShipBlowingUpExplosionsPal, PALRAM_OBJ, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sMotherShipBlowingUpExplosionsPal)));
    #endif // REGION_EU

    LoadRoomCutscene(AREA_TOURIAN, 4 + 1, BLOCK_SIZE * 5, BLOCK_SIZE * 10);

    WRITE_16(REG_IME, FALSE);
    CallbackSetVblank(TourianEscapeVBlank);
    WRITE_16(REG_IME, TRUE);
    gNextOamSlot = 0;
    ResetFreeOam();

    TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ;
    TourianEscapeVBlank();
}

/**
 * @brief 81e30 | 834 | Handles the rooms exploding and ship leaving the planet part
 * 
 * @return u8 bool, ended
 */
static u8 TourianEscapeZebesExploding(void)
{
    u8 ended;
    s32 var_0;
    u16 i;
    u8 offset;

    ended = FALSE;
    var_0 = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = sTourianEscape_47ced0[0][0];
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = sTourianEscape_47ced0[0][1];

            TOURIAN_ESCAPE_DATA.unk_8[1] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = sTourianEscape_47cef0[0][0];
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = sTourianEscape_47cef0[0][1];

            TOURIAN_ESCAPE_DATA.unk_8[2] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[2] = sTourianEscape_47cf10[0][0];
            TOURIAN_ESCAPE_DATA.oamYPositions[2] = sTourianEscape_47cf10[0][1];

            TOURIAN_ESCAPE_DATA.unk_8[3] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFrames[3] = 8;
            TOURIAN_ESCAPE_DATA.oamXPositions[3] = sTourianEscape_47cf30[0][0];
            TOURIAN_ESCAPE_DATA.oamYPositions[3] = sTourianEscape_47cf30[0][1];

            for (i = 4; i < TOURIAN_ESCAPE_MAX_OBJECTS - 1; i++)
            {
                TOURIAN_ESCAPE_DATA.unk_8[i] = TRUE;
                TOURIAN_ESCAPE_DATA.oamFrames[i] = i;
                TOURIAN_ESCAPE_DATA.oamXPositions[i] = sTourianEscape_47cf50[TOURIAN_ESCAPE_DATA.oamFrames[i]][0];
                TOURIAN_ESCAPE_DATA.oamYPositions[i] = sTourianEscape_47cf50[TOURIAN_ESCAPE_DATA.oamFrames[i]][1];
            }

            SoundPlay(SOUND_TOURIAN_ESCAPE_FIRST_ROOM_EXPLODING);
            break;

        case 64:
        case 136:
        case 208:
        case 352:
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            TOURIAN_ESCAPE_DATA.unk_1++;
            break;

        case 65:
            SoundPlay(SOUND_23F);
            break;

        case 137:
            SoundPlay(SOUND_241);
            break;

        case 209:
            SoundPlay(SOUND_243);
            break;

        case 104:
            LoadRoomCutscene(AREA_TOURIAN, 5 + 1, BLOCK_SIZE * 2, BLOCK_SIZE * 12);

            i = 4;
            var_0 = TRUE;
            for (; i < TOURIAN_ESCAPE_MAX_OBJECTS - 1; i++)
            {
                TOURIAN_ESCAPE_DATA.oamTimers[i] = 0;
                TOURIAN_ESCAPE_DATA.oamFrames[i] = (TOURIAN_ESCAPE_DATA.oamFrames[i] + 1) & 7;
                TOURIAN_ESCAPE_DATA.oamXPositions[i] = sTourianEscape_47cf50[TOURIAN_ESCAPE_DATA.oamFrames[i]][0];
                TOURIAN_ESCAPE_DATA.oamYPositions[i] = sTourianEscape_47cf50[TOURIAN_ESCAPE_DATA.oamFrames[i]][1];
            }

            SoundPlay(SOUND_TOURIAN_ESCAPE_OTHER_ROOMS_EXPLODING);
            break;

        case 176:
            LoadRoomCutscene(AREA_CRATERIA, 1 + 1, BLOCK_SIZE * 2, BLOCK_SIZE * 16);

            i = 4;
            var_0 = TRUE;
            for (; i < TOURIAN_ESCAPE_MAX_OBJECTS - 1; i++)
            {
                TOURIAN_ESCAPE_DATA.oamTimers[i] = 0;
                TOURIAN_ESCAPE_DATA.oamFrames[i] = (TOURIAN_ESCAPE_DATA.oamFrames[i] + 1) & 7;
                TOURIAN_ESCAPE_DATA.oamXPositions[i] = sTourianEscape_47cf50[TOURIAN_ESCAPE_DATA.oamFrames[i]][0];
                TOURIAN_ESCAPE_DATA.oamYPositions[i] = sTourianEscape_47cf50[TOURIAN_ESCAPE_DATA.oamFrames[i]][1];
            }

            SoundPlay(SOUND_TOURIAN_ESCAPE_OTHER_ROOMS_EXPLODING);
            break;

        case 246:
            WRITE_16(REG_IME, FALSE);
            CallbackSetVblank(TourianEscapeVBlankZebesExploding);
            WRITE_16(REG_IME, TRUE);

            LZ77UncompVRAM(sTourianEscapeZebesGfx, VRAM_BASE);
            break;

        case 247:
            LZ77UncompVRAM(sTourianEscapeZebesExplodingShipAndExplosionsGfx, VRAM_OBJ);
            TOURIAN_ESCAPE_DATA.unk_2++;
            TOURIAN_ESCAPE_DATA.unk_5 = 0;

            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = BLOCK_SIZE * 3;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamTimers[0] = 0;

            TOURIAN_ESCAPE_DATA.unk_8[1] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = 0x59;
            TOURIAN_ESCAPE_DATA.oamTimers[1] = 0;
            for (i = 2; i < TOURIAN_ESCAPE_MAX_OBJECTS - 1; i++)
            {
                TOURIAN_ESCAPE_DATA.unk_8[i] = 0;
                TOURIAN_ESCAPE_DATA.oamFrames[i] = 0;
                TOURIAN_ESCAPE_DATA.oamTimers[i] = 0;
            }

            gBg0XPosition = 0;
            gBg0YPosition = 0;
            gBg1XPosition = 0;
            gBg1YPosition = 0;
            gBg2XPosition = 0;
            gBg2YPosition = 0;
            FadeCurrentMusicAndQueueNextMusic(0, MUSIC_ESCAPING_ZEBES_CUTSCENE, 0);
            break;

        case 248:
            LZ77UncompVRAM(sTourianEscapeZebesTileTable, VRAM_BASE + 0xF000);

            #ifdef REGION_EU
            DmaTransfer(3, sTourianEscapeExplodingPal, PALRAM_BASE, sizeof(sTourianEscapeExplodingPal), 16);
            DmaTransfer(3, sTourianEscapeExplodingPal, PALRAM_OBJ, sizeof(sTourianEscapeExplodingPal), 16);
            #else // !REGION_EU
            DMA_SET(3, sTourianEscapeExplodingPal, PALRAM_BASE, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeExplodingPal)));
            DMA_SET(3, sTourianEscapeExplodingPal, PALRAM_OBJ, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeExplodingPal)));
            #endif // REGION_EU

            WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 30, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;
            gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE / 2 + 2;
            gWrittenToBldalpha_H = BLDALPHA_MAX_VALUE / 2 - 2;

            var_0 = 2;
            SoundPlay(SOUND_TOURIAN_ESCAPE_SAMUS_LEAVING_PLANET);
            break;

        case 512:
            gBg0XPosition = 0;
            gBg0YPosition = 0;
            ended = TRUE;
            break;
    }

    if (TOURIAN_ESCAPE_DATA.timer < CONVERT_SECONDS(4.f))
        AnimatedGraphicsUpdate();

    if (var_0)
    {
        TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_BG1_SECOND_TARGET_PIXEL |
            BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL |
            BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

        gWrittenToBldy_NonGameplay = 0;
        TOURIAN_ESCAPE_DATA.unk_1 = 0;
    }

    if (TOURIAN_ESCAPE_DATA.unk_1)
    {
        if (TOURIAN_ESCAPE_DATA.timer > CONVERT_SECONDS(4.25f))
        {
            if (TOURIAN_ESCAPE_DATA.unk_5++ > 5)
            {
                if (gWrittenToBldy_NonGameplay < BLDY_MAX_VALUE)
                    gWrittenToBldy_NonGameplay++;

                TOURIAN_ESCAPE_DATA.unk_5 = 0;
            }
        }
        else
        {
            if (TOURIAN_ESCAPE_DATA.unk_5++ & 1)
            {
                if (gWrittenToBldy_NonGameplay < BLDY_MAX_VALUE)
                    gWrittenToBldy_NonGameplay++;
            }
        }
    }

    if (TOURIAN_ESCAPE_DATA.unk_2)
    {
        if (MOD_AND(TOURIAN_ESCAPE_DATA.timer, 8) < 4)
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47a4e0;
        else
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47a506;

        if (MOD_AND(TOURIAN_ESCAPE_DATA.timer, 4) < 2)
            TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47a52c;
        else
            TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47a540;

        if (TOURIAN_ESCAPE_DATA.oamTimers[1] > 11)
        {
            gBg0XPosition++;
            TOURIAN_ESCAPE_DATA.oamXPositions[1]--;
            TOURIAN_ESCAPE_DATA.oamTimers[1] = 0;
        }
        else
        {
            TOURIAN_ESCAPE_DATA.oamTimers[1]++;
        }
    }
    else
    {
        if (TOURIAN_ESCAPE_DATA.oamTimers[0] >= sTourianEscapeOam_HugeShipExplosion[TOURIAN_ESCAPE_DATA.oamFrames[0]].timer)
        {
            TOURIAN_ESCAPE_DATA.oamTimers[0] = 0;
            TOURIAN_ESCAPE_DATA.oamFrames[0]++;

            if (sTourianEscapeOam_HugeShipExplosion[TOURIAN_ESCAPE_DATA.oamFrames[0]].timer == 0)
            {
                TOURIAN_ESCAPE_DATA.oamFrames[0] = 0;
                TOURIAN_ESCAPE_DATA.unk_8[0] = MOD_AND(TOURIAN_ESCAPE_DATA.unk_8[0] + 1, 8) + 1;

                offset = TOURIAN_ESCAPE_DATA.unk_8[0] - 1;
                TOURIAN_ESCAPE_DATA.oamXPositions[0] = sTourianEscape_47ced0[offset][0];
                TOURIAN_ESCAPE_DATA.oamYPositions[0] = sTourianEscape_47ced0[offset][1];
            }
        }

        if (TOURIAN_ESCAPE_DATA.oamTimers[1] >= sChozodiaEscapeOam_47cc64[TOURIAN_ESCAPE_DATA.oamFrames[1]].timer)
        {
            TOURIAN_ESCAPE_DATA.oamTimers[1] = 0;
            TOURIAN_ESCAPE_DATA.oamFrames[1]++;

            if (sChozodiaEscapeOam_47cc64[TOURIAN_ESCAPE_DATA.oamFrames[1]].timer == 0)
            {
                TOURIAN_ESCAPE_DATA.oamFrames[1] = 0;
                TOURIAN_ESCAPE_DATA.unk_8[1] = MOD_AND(TOURIAN_ESCAPE_DATA.unk_8[1] + 1, 8) + 1;

                offset = TOURIAN_ESCAPE_DATA.unk_8[1] - 1;
                TOURIAN_ESCAPE_DATA.oamXPositions[1] = sTourianEscape_47cef0[offset][0];
                TOURIAN_ESCAPE_DATA.oamYPositions[1] = sTourianEscape_47cef0[offset][1];
            }
        }

        if (TOURIAN_ESCAPE_DATA.oamTimers[2] >= sChozodiaEscapeOam_47ccbc[TOURIAN_ESCAPE_DATA.oamFrames[2]].timer)
        {
            TOURIAN_ESCAPE_DATA.oamTimers[2] = 0;
            TOURIAN_ESCAPE_DATA.oamFrames[2]++;

            if (sChozodiaEscapeOam_47ccbc[TOURIAN_ESCAPE_DATA.oamFrames[2]].timer == 0)
            {
                TOURIAN_ESCAPE_DATA.oamFrames[2] = 0;
                TOURIAN_ESCAPE_DATA.unk_8[2] = MOD_AND(TOURIAN_ESCAPE_DATA.unk_8[2] + 1, 8) + 1;

                offset = TOURIAN_ESCAPE_DATA.unk_8[2] - 1;
                TOURIAN_ESCAPE_DATA.oamXPositions[2] = sTourianEscape_47cf10[offset][0];
                TOURIAN_ESCAPE_DATA.oamYPositions[2] = sTourianEscape_47cf10[offset][1];
            }
        }

        if (TOURIAN_ESCAPE_DATA.oamTimers[3] >= sTourianEscapeOam_HugeShipExplosion[TOURIAN_ESCAPE_DATA.oamFrames[3]].timer)
        {
            TOURIAN_ESCAPE_DATA.oamTimers[3] = 0;
            TOURIAN_ESCAPE_DATA.oamFrames[3]++;

            if (sTourianEscapeOam_HugeShipExplosion[TOURIAN_ESCAPE_DATA.oamFrames[3]].timer == 0)
            {
                TOURIAN_ESCAPE_DATA.oamFrames[3] = 0;
                TOURIAN_ESCAPE_DATA.unk_8[3] = MOD_AND(TOURIAN_ESCAPE_DATA.unk_8[3] + 1, 8) + 1;

                offset = TOURIAN_ESCAPE_DATA.unk_8[3] - 1;
                TOURIAN_ESCAPE_DATA.oamXPositions[3] = sTourianEscape_47cf30[offset][0];
                TOURIAN_ESCAPE_DATA.oamYPositions[3] = sTourianEscape_47cf30[offset][1];
            }
        }

        TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscapeOam_HugeShipExplosion[TOURIAN_ESCAPE_DATA.oamFrames[0]].pFrame;
        TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sChozodiaEscapeOam_47cc64[TOURIAN_ESCAPE_DATA.oamFrames[1]].pFrame;
        TOURIAN_ESCAPE_DATA.oamFramePointers[2] = sChozodiaEscapeOam_47ccbc[TOURIAN_ESCAPE_DATA.oamFrames[2]].pFrame;
        TOURIAN_ESCAPE_DATA.oamFramePointers[3] = sTourianEscapeOam_HugeShipExplosion[TOURIAN_ESCAPE_DATA.oamFrames[3]].pFrame;

        TOURIAN_ESCAPE_DATA.oamTimers[0]++;
        TOURIAN_ESCAPE_DATA.oamTimers[1]++;
        TOURIAN_ESCAPE_DATA.oamTimers[2]++;
        TOURIAN_ESCAPE_DATA.oamTimers[3]++;

        for (i = 4; i < TOURIAN_ESCAPE_MAX_OBJECTS - 1; i++)
        {
            if (TOURIAN_ESCAPE_DATA.oamTimers[i] < CONVERT_SECONDS(.25f))
                TOURIAN_ESCAPE_DATA.oamTimers[i]++;

            offset = TOURIAN_ESCAPE_DATA.oamTimers[i] / 4;
            TOURIAN_ESCAPE_DATA.oamFramePointers[i] = sTourianEscape_47cec0[offset];
            TOURIAN_ESCAPE_DATA.oamYPositions[i] += PIXEL_SIZE;
        }

        i = MOD_AND(TOURIAN_ESCAPE_DATA.timer, 8);

        if (i == 1)
        {
            gBg0XPosition += 8;
            gBg0YPosition -= 8;
            gBg1XPosition += 8;
            gBg1YPosition -= 8;
            gBg2XPosition += 8;
            gBg2YPosition -= 8;
        }
        
        if (i == 3)
        {
            gBg3XPosition += 8;
            gBg3YPosition -= 8;
        }
        
        if (i == 4)
        {
            gBg0XPosition -= 8;
            gBg0YPosition += 8;
            gBg1XPosition -= 8;
            gBg1YPosition += 8;
            gBg2XPosition -= 8;
            gBg2YPosition += 8;
        }
        
        if (i == 6)
        {
            gBg3XPosition -= 8;
            gBg3YPosition += 8;
        }
    }

    TourianEscapeProcessOam();

    return ended;
}

/**
 * @brief 82664 | 36c | Handles the samus in her ship part of the cutscene
 * 
 * @return u8 bool, ended
 */
static u8 TourianEscapeSamusInHerShip(void)
{
    u8 ended;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeSamusInHerShipSuitGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sMotherShipExplodingFlashGfx, VRAM_BASE + 0x8000);
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeSamusInHerShipSuitTileTable, VRAM_BASE + 0x7000);
            LZ77UncompVRAM(sMotherShipExplodingFlashTileTable, VRAM_BASE + 0xF000);

            if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
            {
                #ifdef REGION_EU
                DmaTransfer(3, sTourianEscapeSamusInHerShipVariaSuitPal, PALRAM_BASE,
                    sizeof(sTourianEscapeSamusInHerShipVariaSuitPal), 16);
                #else // !REGION_EU
                DMA_SET(3, sTourianEscapeSamusInHerShipVariaSuitPal, PALRAM_BASE,
                    C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeSamusInHerShipVariaSuitPal)));
                #endif // REGION_EU
            }
            else
            {
                #ifdef REGION_EU
                DmaTransfer(3, sTourianEscapeSamusInHerShipPowerSuitPal, PALRAM_BASE,
                    sizeof(sTourianEscapeSamusInHerShipPowerSuitPal), 16);
                #else // !REGION_EU
                DMA_SET(3, sTourianEscapeSamusInHerShipPowerSuitPal, PALRAM_BASE,
                    C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeSamusInHerShipPowerSuitPal)));
                #endif // REGION_EU
            }
            break;

        case 3:
            WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 30, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 14, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));

            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG1 | DCNT_OBJ;
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_SCREEN_SECOND_TARGET;

            gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE;
            gWrittenToBldalpha_H = 0;
            gWrittenToBldy_NonGameplay = 0;
            break;

        case 56:
            TOURIAN_ESCAPE_DATA.dispcnt |= DCNT_WIN0;
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            gWrittenToBldy_NonGameplay = 10;

            WRITE_16(REG_WININ, WIN0_ALL);
            WRITE_16(REG_WINOUT, WIN0_ALL_NO_COLOR_EFFECT);

            TOURIAN_ESCAPE_DATA.win0h_H = SCREEN_X_MIDDLE - 1;
            TOURIAN_ESCAPE_DATA.win0h_L = SCREEN_X_MIDDLE + 1;
            TOURIAN_ESCAPE_DATA.win0v_H = SCREEN_Y_MIDDLE - 1;
            TOURIAN_ESCAPE_DATA.win0v_L = SCREEN_Y_MIDDLE + 1;

            TOURIAN_ESCAPE_DATA.unk_2++;
            SoundPlay(SOUND_TOURIAN_ESCAPE_SAMUS_REMOVING_SUIT_1);
            break;

        case 160:
            LZ77UncompVRAM(sTourianEscapeSamusInHerShipSuitlessGfx, VRAM_BASE);
            break;

        case 161:
            LZ77UncompVRAM(sTourianEscapeSamusInHerShipSuitlessTileTable, VRAM_BASE + 0x7000);
            LZ77UncompVRAM(sTourianEscapeSamusInHerShipSuitlessEyesOpenedTileTable, VRAM_BASE + 0x7800);

            #ifdef REGION_EU
            DmaTransfer(3, sTourianEscapeSamusInHerShipSuitlessPal, PALRAM_BASE,
                sizeof(sTourianEscapeSamusInHerShipSuitlessPal), 16);
            #else // !REGION_EU
            DMA_SET(3, sTourianEscapeSamusInHerShipSuitlessPal, PALRAM_BASE,
                C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeSamusInHerShipSuitlessPal)));
            #endif // REGION_EU
            break;

        case 162:
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_OBJ;
            TOURIAN_ESCAPE_DATA.unk_2++;

            SoundPlay(SOUND_TOURIAN_ESCAPE_SAMUS_REMOVING_SUIT_2);
            break;

        case 200:
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG1_SECOND_TARGET_PIXEL;
            gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE;

            TOURIAN_ESCAPE_DATA.unk_2++;
            SoundPlay(SOUND_TOURIAN_ESCAPE_SAMUS_REMOVING_SUIT_3);
            break;

        case 352:
            WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 15, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            break;

        case 372:
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            TOURIAN_ESCAPE_DATA.bldcnt = 0;
            gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE;
            gWrittenToBldalpha_H = 0;
            gWrittenToBldy_NonGameplay = 0;
            ended = TRUE;
    }

    if (TOURIAN_ESCAPE_DATA.unk_2 == 1)
    {
        if (TOURIAN_ESCAPE_DATA.unk_5++ < 40)
        {
            TOURIAN_ESCAPE_DATA.win0v_H -= 3;
            TOURIAN_ESCAPE_DATA.win0v_L += 3;
        }
        else
        {
            TOURIAN_ESCAPE_DATA.win0h_H -= 4;
            TOURIAN_ESCAPE_DATA.win0h_L += 4;
        }

        if (TOURIAN_ESCAPE_DATA.win0v_H < 0)
            TOURIAN_ESCAPE_DATA.win0v_H = 0;

        if (TOURIAN_ESCAPE_DATA.win0v_L > SCREEN_SIZE_Y)
            TOURIAN_ESCAPE_DATA.win0v_L = SCREEN_SIZE_Y;

        if (TOURIAN_ESCAPE_DATA.win0h_H < 0)
            TOURIAN_ESCAPE_DATA.win0h_H = 0;

        if (TOURIAN_ESCAPE_DATA.win0h_L > SCREEN_SIZE_X)
            TOURIAN_ESCAPE_DATA.win0h_L = SCREEN_SIZE_X;

        if (TOURIAN_ESCAPE_DATA.timer >= 128 && MOD_AND(TOURIAN_ESCAPE_DATA.timer, 2))
        {
            if (gWrittenToBldy_NonGameplay < BLDY_MAX_VALUE)
                gWrittenToBldy_NonGameplay++;
        }
    }
    else if (TOURIAN_ESCAPE_DATA.unk_2 == 2)
    {
        if (MOD_AND(TOURIAN_ESCAPE_DATA.timer, 2))
        {
            if (gWrittenToBldy_NonGameplay != 0)
                gWrittenToBldy_NonGameplay--;
        }
    }
    else if (TOURIAN_ESCAPE_DATA.unk_2 != 0)
    {
        if (MOD_AND(TOURIAN_ESCAPE_DATA.timer, 4) == 0)
        {
            if (gWrittenToBldalpha_L != 0)
            {
                gWrittenToBldalpha_L--;
                gWrittenToBldalpha_H = 16 - gWrittenToBldalpha_L;
            }
        }
    }

    return ended;
}

/**
 * @brief 829d0 | 288 | Handles the samus looking around part
 * 
 * @return u8 bool, ended
 */
static u8 TourianEscapeSamusLookingAround(void)
{
    u8 ended;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeSamusSamusInHerShipLookingGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sTourianEscapeSamusSamusInHerShipLookingGfx, VRAM_OBJ);

            gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE / 2;
            gWrittenToBldalpha_H = BLDALPHA_MAX_VALUE / 2;

            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47a554;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = BLOCK_SIZE * 2;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = 0;

            TOURIAN_ESCAPE_DATA.unk_8[1] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47a56e;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = BLOCK_SIZE * 2;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeSamusSamusInHerShipLookingLeftTileTable, VRAM_BASE + 0x8000);
            LZ77UncompVRAM(sTourianEscapeSamusSamusInHerShipLookingRightTileTable, VRAM_BASE + 0x8800);

            #ifdef REGION_EU
            DmaTransfer(3, sTourianEscapeSamusLookingAroundPal, PALRAM_BASE,
                sizeof(sTourianEscapeSamusLookingAroundPal), 16);
            DmaTransfer(3, sTourianEscapeSamusLookingAroundPal, PALRAM_OBJ,
                sizeof(sTourianEscapeSamusLookingAroundPal), 16);
            #else // !REGION_EU
            DMA_SET(3, sTourianEscapeSamusLookingAroundPal, PALRAM_BASE,
                C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeSamusLookingAroundPal)));
            DMA_SET(3, sTourianEscapeSamusLookingAroundPal, PALRAM_OBJ,
                C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeSamusLookingAroundPal)));
            #endif // REGION_EU
            break;

        case 3:
            WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 16, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG0_SECOND_TARGET_PIXEL;
            break;

        case 16:
            TOURIAN_ESCAPE_DATA.unk_2++;
            break;

        case 32:
            WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 17, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            break;

        case 56:
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            TOURIAN_ESCAPE_DATA.bldcnt = 0;

            gBg2Rotation = 0;
            gBg2XScaling = Q_16_16(96.f / 4096.f);
            gBg2YScaling = Q_16_16(96.f / 4096.f);
            ended++;
            break;
    }

    if (TOURIAN_ESCAPE_DATA.unk_2)
    {
        if (TOURIAN_ESCAPE_DATA.oamYPositions[0] < SCREEN_Y_MIDDLE)
        {
            TOURIAN_ESCAPE_DATA.oamYPositions[0] += 8;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] -= 8;
        }
    }

    TourianEscapeProcessOam();

    return ended;
}

/**
 * @brief 82c58 | 178 | Handles the samus being surrounded part
 * 
 * @return u8 bool, ended
 */
static u8 TourianEscapeSamusSurrounded(void)
{
    u8 ended;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeSamusSurroundedBackgroundGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sTourianEscape_49cb90, VRAM_BASE + 0x8000);
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeSamusSurroundedBackgroundTileTable, VRAM_BASE + 0x7000);
            LZ77UncompVRAM(sTourianEscape_49fb70, VRAM_BASE + 0x7800);

            #ifdef REGION_EU
            DmaTransfer(3, sTourianEscapeSamusSurroundedPal, PALRAM_BASE, sizeof(sTourianEscapeSamusSurroundedPal), 16);
            #else // !REGION_EU
            DMA_SET(3, sTourianEscapeSamusSurroundedPal, PALRAM_BASE, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeSamusSurroundedPal)));
            #endif // REGION_EU

            gBg0XPosition = 0;
            gBg0YPosition = 0;

            gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE;
            gWrittenToBldalpha_H = 0;
            break;

        case 3:
            WRITE_16(REG_IME, FALSE);
            CallbackSetVblank(TourianEscapeVBlankSamusSurrounded);
            WRITE_16(REG_IME, TRUE);
            break;

        case 4:
            WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 14, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
            WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 14, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
            WRITE_16(REG_BG2CNT, CREATE_BGCNT(2, 15, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_512x256) | (1 << 7));
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_MODE_1 | DCNT_BG0 | DCNT_BG2 | DCNT_OBJ;
            break;

        case 32:
            TOURIAN_ESCAPE_DATA.unk_2++;
            break;

        case 112:
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_SCREEN_SECOND_TARGET;
            ended = TRUE;
            break;
    }

    if (TOURIAN_ESCAPE_DATA.unk_2)
    {
        if (gBg2XScaling > Q_16_16(16.f / 4096.f))
        {
            gBg2XScaling -= Q_16_16(5.f / 4096.f);
            gBg2YScaling -= Q_16_16(5.f / 4096.f);
        }
        else
        {
            gBg2XScaling = Q_16_16(16.f / 4096.f);
            gBg2YScaling = Q_16_16(16.f / 4096.f);
        }
    }

    TourianEscapeCalculateBg2();

    return ended;
}

/**
 * @brief 82dd0 | 1d0 | Handles the samus flying in part
 * 
 * @return u8 bool, ended
 */
static u8 TourianEscapeSamusFlyingIn(void)
{
    u8 ended;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            WRITE_16(REG_IME, FALSE);
            CallbackSetVblank(TourianEscapeVBlankZebesExploding);
            WRITE_16(REG_IME, TRUE);

            LZ77UncompVRAM(sIntroTextAndShipFlyingInGfx, VRAM_OBJ);
            SoundPlay(SOUND_TOURIAN_ESCAPE_SAMUS_FLYING_IN);
            break;

        case 1:
            LZ77UncompVRAM(sIntroSpaceBackgroundGfx, VRAM_BASE);
            break;

        case 2:
            LZ77UncompVRAM(sIntroSpaceBackgroundTileTable, VRAM_BASE + 0xF000);

            DMA_SET(3, sIntroTextAndShipPal, PALRAM_BASE, C_32_2_16(DMA_ENABLE, sizeof(sIntroTextAndShipPal) / 2 + 16));
            DMA_SET(3, sIntroTextAndShipPal, PALRAM_OBJ, C_32_2_16(DMA_ENABLE, sizeof(sIntroTextAndShipPal) / 2 + 16));

            WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 30, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;

            gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE / 2 + 1;
            gWrittenToBldalpha_H = BLDALPHA_MAX_VALUE / 2 - 1;

            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            TOURIAN_ESCAPE_DATA.unk_82 = 32;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = SCREEN_X_MIDDLE;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = SCREEN_SIZE_Y / 8 + 8;
            TOURIAN_ESCAPE_DATA.oamTimers[0] = 0;
            break;

        case 32:
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            TOURIAN_ESCAPE_DATA.bldcnt = 0;

            ended = TRUE;
    }

    if (TOURIAN_ESCAPE_DATA.unk_8[0])
    {
        if (TOURIAN_ESCAPE_DATA.oamTimers[0] < 4)
            TOURIAN_ESCAPE_DATA.oamYPositions[0] += 8;
        else if (TOURIAN_ESCAPE_DATA.oamTimers[0] < 8)
            TOURIAN_ESCAPE_DATA.oamYPositions[0] += 6;
        else if (TOURIAN_ESCAPE_DATA.oamTimers[0] < 16)
            TOURIAN_ESCAPE_DATA.oamYPositions[0] += 3;
        else if (TOURIAN_ESCAPE_DATA.oamTimers[0] < 20)
            TOURIAN_ESCAPE_DATA.oamYPositions[0] += 1;
        else if (TOURIAN_ESCAPE_DATA.oamTimers[0] < 28)
            TOURIAN_ESCAPE_DATA.oamYPositions[0] -= 1;

        if (TOURIAN_ESCAPE_DATA.unk_82 < 128)
            TOURIAN_ESCAPE_DATA.unk_82 += 8;
        else if (TOURIAN_ESCAPE_DATA.unk_82 < 320)
            TOURIAN_ESCAPE_DATA.unk_82 += 16;
        else if (TOURIAN_ESCAPE_DATA.unk_82 < 480)
            TOURIAN_ESCAPE_DATA.unk_82 += 32;

        if ((TOURIAN_ESCAPE_DATA.oamTimers[0]++ & 7) < 4)
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sIntroShipFlyingTowardsCameraOam_1;
        else
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sIntroShipFlyingTowardsCameraOam_2;
    }

    unk_818cc();

    return ended;
}

/**
 * @brief 82fa0 | 424 | Handles the samus being chased by pirates part
 * 
 * @return u8 bool, ended
 */
static u8 TourianEscapeSamusChasedByPirates(void)
{
    u8 ended;
    u8 i;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeSamusChasedBackgroundGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sTourianEscapeSamusSamusChasedShipsGfx, VRAM_OBJ);
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeSamusChasedBackgroundTileTable, VRAM_BASE + 0xE000);

            #ifdef REGION_EU
            DmaTransfer(3, sTourianEscapeSamusChasedBackgroundPal, PALRAM_BASE,
                sizeof(sTourianEscapeSamusChasedBackgroundPal), 16);
            DmaTransfer(3, sTourianEscapeSamusChasedShipsPal, PALRAM_OBJ,
                sizeof(sTourianEscapeSamusChasedShipsPal), 16);
            #else // !REGION_EU
            DMA_SET(3, sTourianEscapeSamusChasedBackgroundPal, PALRAM_BASE,
                C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeSamusChasedBackgroundPal)));
            DMA_SET(3, sTourianEscapeSamusChasedShipsPal, PALRAM_OBJ,
                C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeSamusChasedShipsPal)));
            #endif // REGION_EU

            TOURIAN_ESCAPE_DATA.unk_8[0] = FALSE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47a602;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = 0xDC;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = 0xDC;
            TOURIAN_ESCAPE_DATA.oamPriorities[0] = 0;

            TOURIAN_ESCAPE_DATA.unk_8[1] = FALSE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47a622;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = 0x100;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = 0xF0;
            TOURIAN_ESCAPE_DATA.oamPriorities[1] = 0;

            TOURIAN_ESCAPE_DATA.unk_8[2] = FALSE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[2] = sTourianEscape_47a642;
            TOURIAN_ESCAPE_DATA.oamXPositions[2] = 0xB4;
            TOURIAN_ESCAPE_DATA.oamYPositions[2] = 0xF0;
            TOURIAN_ESCAPE_DATA.oamPriorities[2] = 0;

            TOURIAN_ESCAPE_DATA.unk_8[3] = FALSE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[3] = sTourianEscape_47a662;
            TOURIAN_ESCAPE_DATA.oamXPositions[3] = 0xD4;
            TOURIAN_ESCAPE_DATA.oamYPositions[3] = 0xBE;
            TOURIAN_ESCAPE_DATA.oamPriorities[3] = 0;

            TOURIAN_ESCAPE_DATA.unk_8[4] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFrames[4] = 0;

            TOURIAN_ESCAPE_DATA.unk_8[5] = 2;
            TOURIAN_ESCAPE_DATA.oamFrames[5] = 6;

            TOURIAN_ESCAPE_DATA.unk_8[6] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFrames[6] = 14;

            TOURIAN_ESCAPE_DATA.unk_8[7] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFrames[7] = 9;

            TOURIAN_ESCAPE_DATA.unk_8[8] = 2;
            TOURIAN_ESCAPE_DATA.oamFrames[8] = 3;

            TOURIAN_ESCAPE_DATA.unk_8[9] = 2;
            TOURIAN_ESCAPE_DATA.oamFrames[9] = 11;

            for (i = 4; i < TOURIAN_ESCAPE_MAX_OBJECTS; i++)
            {
                TOURIAN_ESCAPE_DATA.oamXPositions[i] = sTourianEscape_47ce20[TOURIAN_ESCAPE_DATA.oamFrames[i]][0];
                TOURIAN_ESCAPE_DATA.oamYPositions[i] = sTourianEscape_47ce20[TOURIAN_ESCAPE_DATA.oamFrames[i]][1];
                TOURIAN_ESCAPE_DATA.unk_96[i] = sTourianEscape_47ce20[TOURIAN_ESCAPE_DATA.oamFrames[i]][2];
            }

            gBg0XPosition = 0;
            gBg0YPosition = 0;
            break;

        case 3:
            WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;
            break;

        case 40:
            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            SoundPlay(SOUND_TOURIAN_ESCAPE_SAMUS_FLEEING_RIGHT_TO_LEFT);
            break;

        case 64:
            TOURIAN_ESCAPE_DATA.unk_8[1] = TRUE;
            TOURIAN_ESCAPE_DATA.unk_8[2] = TRUE;
            TOURIAN_ESCAPE_DATA.unk_8[3] = TRUE;

            SoundPlay(SOUND_TOURIAN_ESCAPE_SAMUS_FLEEING_LEFT_TO_RIGHT);
            break;

        case 72:
            TOURIAN_ESCAPE_DATA.unk_8[0] = FALSE;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            break;

        case 116:
            TOURIAN_ESCAPE_DATA.unk_8[1] = FALSE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47a5d4;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = BLOCK_SIZE * 7 - QUARTER_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;

            TOURIAN_ESCAPE_DATA.unk_8[2] = FALSE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[2] = sTourianEscape_47a5f4;
            TOURIAN_ESCAPE_DATA.oamXPositions[2] = BLOCK_SIZE * 8 - QUARTER_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamYPositions[2] = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            break;

        case 119:
            TOURIAN_ESCAPE_DATA.unk_8[3] = FALSE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[3] = sTourianEscape_47a5f4;
            TOURIAN_ESCAPE_DATA.oamXPositions[3] = BLOCK_SIZE * 7 - QUARTER_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamYPositions[3] = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            break;

        case 160:
            TOURIAN_ESCAPE_DATA.unk_8[0] = 2;
            SoundPlay(SOUND_TOURIAN_ESCAPE_PIRATES_CHASING_RIGHT_TO_LEFT);
            break;

        case 176:
            TOURIAN_ESCAPE_DATA.unk_8[1] = 2;
            SoundPlay(SOUND_TOURIAN_ESCAPE_PIRATES_CHASING_LEFT_TO_RIGHT);
            break;

        case 182:
            TOURIAN_ESCAPE_DATA.unk_8[2] = 2;
            break;

        case 184:
            TOURIAN_ESCAPE_DATA.unk_8[3] = 2;
            break;

        case 177:
            TOURIAN_ESCAPE_DATA.unk_8[0] = FALSE;
            break;

        case 192:
            TOURIAN_ESCAPE_DATA.unk_8[1] = FALSE;
            break;

        case 198:
            TOURIAN_ESCAPE_DATA.unk_8[2] = FALSE;
            break;

        case 200:
            TOURIAN_ESCAPE_DATA.unk_8[3] = FALSE;
            break;

        case 256:
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            ended = TRUE;
    }

    if (!(TOURIAN_ESCAPE_DATA.timer & 7))
        gBg0XPosition--;

    for (i = 0; i < 4; i++)
    {
        if (TOURIAN_ESCAPE_DATA.unk_8[i] == 1)
        {
            TOURIAN_ESCAPE_DATA.oamXPositions[i] -= 6;
            TOURIAN_ESCAPE_DATA.oamYPositions[i] += 6;
        }
        else if (TOURIAN_ESCAPE_DATA.unk_8[i] == 2)
        {
            TOURIAN_ESCAPE_DATA.oamXPositions[i] += 14;
            TOURIAN_ESCAPE_DATA.oamYPositions[i] -= 14;
        }
    }

    if (TOURIAN_ESCAPE_DATA.unk_8[4])
        unk_81788(FALSE);

    if (TOURIAN_ESCAPE_DATA.unk_8[0] == 2)
    {
        if (TOURIAN_ESCAPE_DATA.oamTimers[0] < 4)
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47a588;
        else
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47a5ae;

        TOURIAN_ESCAPE_DATA.oamTimers[0] = MOD_AND(TOURIAN_ESCAPE_DATA.oamTimers[0] + 1, 8);
    }

    TourianEscapeProcessOam();
    
    return ended;
}

/**
 * @brief 833c4 | 49c | Handles the samus chased by pirates firing part
 * 
 * @return u8 bool, ended
 */
static u8 TourianEscapeSamusChasedByPiratesFiring(void)
{
    u8 ended;
    s32 velocity;
    u32 var_0;
    u32 var_1;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeShipsAndProjectilesGfx, VRAM_OBJ);
            break;

        case 1:
            #ifdef REGION_EU
            DmaTransfer(3, sTourianEscapeSamusChasedByPiratesFiringPal, PALRAM_OBJ,
                sizeof(sTourianEscapeSamusChasedByPiratesFiringPal), 16);
            #else // !REGION_EU
            DMA_SET(3, sTourianEscapeSamusChasedByPiratesFiringPal, PALRAM_OBJ,
                DMA_ENABLE << 16 | ARRAY_SIZE(sTourianEscapeSamusChasedByPiratesFiringPal));
            #endif // REGION_EU

            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = 0x78;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = BLOCK_SIZE + HALF_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.unk_82 = 0xC0;

            TOURIAN_ESCAPE_DATA.unk_8[1] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = 0x78;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = HALF_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.scaling = Q_8_8(1.f);

            TOURIAN_ESCAPE_DATA.unk_8[4] = TRUE;
            TOURIAN_ESCAPE_DATA.unk_8[5] = 2;
            TOURIAN_ESCAPE_DATA.unk_8[6] = 2;
            TOURIAN_ESCAPE_DATA.unk_8[7] = TRUE;
            TOURIAN_ESCAPE_DATA.unk_8[8] = 2;
            TOURIAN_ESCAPE_DATA.unk_8[9] = TRUE;

            TOURIAN_ESCAPE_DATA.oamXPositions[2] = TOURIAN_ESCAPE_DATA.oamXPositions[0] * 8;
            TOURIAN_ESCAPE_DATA.oamYPositions[2] = TOURIAN_ESCAPE_DATA.oamYPositions[0] * 8;

            TOURIAN_ESCAPE_DATA.unk_96[2] = sTourianEscape_47cfa4[TOURIAN_ESCAPE_DATA.oamFrames[3]];
            TOURIAN_ESCAPE_DATA.unk_AE = sTourianEscape_47cfb4[TOURIAN_ESCAPE_DATA.oamFrames[3]];
            TOURIAN_ESCAPE_DATA.unk_96[3] = sTourianEscape_47cfc4[TOURIAN_ESCAPE_DATA.oamFrames[3]];
            TOURIAN_ESCAPE_DATA.unk_B0 = sTourianEscape_47cfd4[TOURIAN_ESCAPE_DATA.oamFrames[3]];

            gBg0XPosition = BLOCK_SIZE - QUARTER_BLOCK_SIZE;
            gBg0YPosition = BLOCK_SIZE + QUARTER_BLOCK_SIZE;
            break;

        case 2:
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;
            SoundPlay(SOUND_TOURIAN_ESCAPE_SAMUS_DODGING_SHOTS);
            SoundPlay(SOUND_TOURIAN_ESCAPE_PIRATES_FIRING);
            break;

        case 120:
            TOURIAN_ESCAPE_DATA.unk_8[1]++;
            break;

        case 160:
            TOURIAN_ESCAPE_DATA.oamTimers[0] = 0;
            TOURIAN_ESCAPE_DATA.oamFrames[0] = 0;

        case 126:
            TOURIAN_ESCAPE_DATA.unk_8[0]++;
            break;

        case 192:
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            break;

        case 368:
            SoundPlay(SOUND_TOURIAN_ESCAPE_SAMUS_FLYING_AFTER_SHOTS);
            break;

        case 384:
            ended = TRUE;
    }

    if (MOD_AND(TOURIAN_ESCAPE_DATA.timer, 8) == 0)
        gBg0YPosition--;

    if (TOURIAN_ESCAPE_DATA.unk_8[0])
    {
        if (TOURIAN_ESCAPE_DATA.unk_8[0] == 1)
        {
            velocity = TOURIAN_ESCAPE_DATA.unk_96[2];

            if (velocity > 48)
                velocity = 48;

            if (velocity < -48)
                velocity = -48;

            TOURIAN_ESCAPE_DATA.oamXPositions[2] += velocity;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = DIV_SHIFT(TOURIAN_ESCAPE_DATA.oamXPositions[2], 8);

            velocity = TOURIAN_ESCAPE_DATA.unk_AE;

            if (velocity > 24)
                velocity = 24;

            if (velocity < -24)
                velocity = -24;

            TOURIAN_ESCAPE_DATA.oamYPositions[2] += velocity;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = DIV_SHIFT(TOURIAN_ESCAPE_DATA.oamYPositions[2], 8);

            TOURIAN_ESCAPE_DATA.unk_96[2] += TOURIAN_ESCAPE_DATA.unk_96[3];
            TOURIAN_ESCAPE_DATA.unk_AE += TOURIAN_ESCAPE_DATA.unk_B0;

            var_0 = 0;

            switch (TOURIAN_ESCAPE_DATA.oamFrames[2])
            {
                case 0:
                    if (TOURIAN_ESCAPE_DATA.unk_96[2] >= 0)
                        var_0 = 1;
                    break;

                case 1:
                case 3:
                    if (TOURIAN_ESCAPE_DATA.oamTimers[2]++ >= ONE_THIRD_SECOND)
                    {
                        TOURIAN_ESCAPE_DATA.oamTimers[2] = 0;
                        var_0 = 2;
                    }
                    break;

                case 2:
                    if (TOURIAN_ESCAPE_DATA.unk_96[2] <= 0)
                        var_0 = 1;
                    break;
            }

            if (var_0 == 1)
            {
                TOURIAN_ESCAPE_DATA.oamFrames[2]++;
                TOURIAN_ESCAPE_DATA.unk_96[3] = 0;
                TOURIAN_ESCAPE_DATA.unk_B0 = 0;
            }
            
            if (var_0 == 2)
            {
                if (TOURIAN_ESCAPE_DATA.oamFrames[2] < 3)
                    TOURIAN_ESCAPE_DATA.oamFrames[2]++;
                else
                    TOURIAN_ESCAPE_DATA.oamFrames[2] = 0;

                if (TOURIAN_ESCAPE_DATA.oamFrames[3] < 7)
                    TOURIAN_ESCAPE_DATA.oamFrames[3]++;
                else
                    TOURIAN_ESCAPE_DATA.oamFrames[3] = 0;

                TOURIAN_ESCAPE_DATA.unk_96[2] = sTourianEscape_47cfa4[TOURIAN_ESCAPE_DATA.oamFrames[3]];
                TOURIAN_ESCAPE_DATA.unk_AE = sTourianEscape_47cfb4[TOURIAN_ESCAPE_DATA.oamFrames[3]];
                TOURIAN_ESCAPE_DATA.unk_96[3] = sTourianEscape_47cfc4[TOURIAN_ESCAPE_DATA.oamFrames[3]];
                TOURIAN_ESCAPE_DATA.unk_B0 = sTourianEscape_47cfd4[TOURIAN_ESCAPE_DATA.oamFrames[3]];
            }

            if (TOURIAN_ESCAPE_DATA.oamTimers[0] & 1)
                TOURIAN_ESCAPE_DATA.unk_82++;
        }

        if (TOURIAN_ESCAPE_DATA.unk_8[0] < 3)
        {
            if (TOURIAN_ESCAPE_DATA.oamFrames[0] > 14)
                TOURIAN_ESCAPE_DATA.oamFrames[0] = 0;
        }
        else
        {
            if (TOURIAN_ESCAPE_DATA.oamFrames[0] >= 23)
                TOURIAN_ESCAPE_DATA.oamFrames[0] = 23;

            if (TOURIAN_ESCAPE_DATA.oamTimers[0] < 4)
                TOURIAN_ESCAPE_DATA.oamYPositions[0] += 4;
            else if (TOURIAN_ESCAPE_DATA.oamTimers[0] < 8)
                TOURIAN_ESCAPE_DATA.oamYPositions[0] += 2;
            else
                TOURIAN_ESCAPE_DATA.oamYPositions[0] += 1;

            if (TOURIAN_ESCAPE_DATA.unk_82 < 0x1F8)
                TOURIAN_ESCAPE_DATA.unk_82 += 8;
        }
        
        var_1 = TOURIAN_ESCAPE_DATA.oamFrames[0] / 4;
        TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47cf70[var_1];

        TOURIAN_ESCAPE_DATA.oamFrames[0]++;
        TOURIAN_ESCAPE_DATA.oamTimers[0]++;
    }

    if (TOURIAN_ESCAPE_DATA.unk_8[4])
        unk_81788(TRUE);

    if (TOURIAN_ESCAPE_DATA.unk_8[1])
    {
        var_1 = 0;
        if (TOURIAN_ESCAPE_DATA.scaling > Q_8_8(.625f))
        {
            if (TOURIAN_ESCAPE_DATA.oamFrames[1] > 26)
                TOURIAN_ESCAPE_DATA.oamFrames[1] = 0;

            var_1 = TOURIAN_ESCAPE_DATA.oamFrames[1] / 4;
        }

        TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47cf88[var_1];

        if (TOURIAN_ESCAPE_DATA.unk_8[1] == 1)
            TOURIAN_ESCAPE_DATA.scaling -= Q_8_8(.005f);
        else
            TOURIAN_ESCAPE_DATA.scaling -= Q_8_8(.01f);

        if (TOURIAN_ESCAPE_DATA.scaling < Q_8_8(.035f))
            TOURIAN_ESCAPE_DATA.unk_8[1] = FALSE;

        TOURIAN_ESCAPE_DATA.oamFrames[1]++;
        TOURIAN_ESCAPE_DATA.oamTimers[1]++;
    }

    unk_818cc();

    return ended;
}

/**
 * @brief 83860 | 4b0 | Handles the samus getting shot part
 * 
 * @return u8 bool, ended
 */
static u8 TourianEscapeSamusGettingShot(void)
{
    u8 ended;
    s32 velocity;
    u16 position;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeSamusGettingShotGfx, VRAM_BASE + 0x8000);
            break;

        case 1:
            LZ77UncompVRAM(sTourianEscapeSamusGettingShotShipGfx, VRAM_OBJ);
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_DECREASE_EFFECT;
            gWrittenToBldy_NonGameplay = BLDY_MAX_VALUE;
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeSamusGettingShotTileTable, VRAM_BASE + 0xF000);
            #ifdef REGION_EU
            DmaTransfer(3, sTourianEscapeSamusGettingShotPal, PALRAM_OBJ, sizeof(sTourianEscapeSamusGettingShotPal), 16);
            #else // !REGION_EU
            DMA_SET(3, sTourianEscapeSamusGettingShotPal, PALRAM_OBJ, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeSamusGettingShotPal)));
            #endif // REGION_EU

            gBg0XPosition = BLOCK_SIZE + HALF_BLOCK_SIZE;
            gBg0YPosition = BLOCK_SIZE - QUARTER_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.unk_1++;
            break;

        case 3:
            WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 28, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;
            TOURIAN_ESCAPE_DATA.unk_8[4] = TRUE;
            TOURIAN_ESCAPE_DATA.unk_8[5] = 2;
            TOURIAN_ESCAPE_DATA.unk_8[6] = 2;
            TOURIAN_ESCAPE_DATA.unk_8[7] = TRUE;
            TOURIAN_ESCAPE_DATA.unk_8[8] = 2;
            TOURIAN_ESCAPE_DATA.unk_8[9] = TRUE;
            break;

        case 24:
            TOURIAN_ESCAPE_DATA.unk_8[0]++;
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47a904;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = 0x12D;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = 0xAE;
            TOURIAN_ESCAPE_DATA.oamPriorities[0] = 0;

            TOURIAN_ESCAPE_DATA.oamXPositions[1] = TOURIAN_ESCAPE_DATA.oamXPositions[0] * 32;
            TOURIAN_ESCAPE_DATA.oamXPositions[2] = TOURIAN_ESCAPE_DATA.oamYPositions[0] * 32;

            TOURIAN_ESCAPE_DATA.unk_96[1] = 0x38;
            TOURIAN_ESCAPE_DATA.unk_96[2] = 0x1C;
            break;

        case 128:
            TOURIAN_ESCAPE_DATA.unk_96[1] = 0;
            TOURIAN_ESCAPE_DATA.unk_96[2] = 0;

        case 136:
            TOURIAN_ESCAPE_DATA.unk_8[0]++;
            break;

        case 336:
            #ifdef REGION_EU
            DmaTransfer(3, sTourianEscapeSamusGettingShotPal, PALRAM_BASE, sizeof(sTourianEscapeSamusGettingShotPal), 16);
            #else // !REGION_EU
            DMA_SET(3, sTourianEscapeSamusGettingShotPal, PALRAM_BASE, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeSamusGettingShotPal)));
            #endif // REGION_EU
            WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 30, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG1 | DCNT_OBJ;
            TOURIAN_ESCAPE_DATA.unk_8[0] = 0;
            SoundPlay(SOUND_TOURIAN_ESCAPE_DECISIVE_SHOT);
            break;

        case 400:
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            ended = TRUE;
    }

    if (TOURIAN_ESCAPE_DATA.unk_1)
    {
        if (gWrittenToBldy_NonGameplay != 0)
        {
            if (MOD_AND(TOURIAN_ESCAPE_DATA.timer, 8) == 0)
                gWrittenToBldy_NonGameplay--;
        }
        else
        {
            TOURIAN_ESCAPE_DATA.bldcnt = 0;
            TOURIAN_ESCAPE_DATA.unk_1 = FALSE;
        }
    }

    if (MOD_AND(TOURIAN_ESCAPE_DATA.timer, 8) == 0)
        gBg0XPosition--;

    if (TOURIAN_ESCAPE_DATA.unk_8[4])
        unk_81788(FALSE);

    if (TOURIAN_ESCAPE_DATA.unk_8[0] == 1)
    {
        if (TOURIAN_ESCAPE_DATA.timer > 111)
        {
            TOURIAN_ESCAPE_DATA.unk_96[1]--;
            if (TOURIAN_ESCAPE_DATA.timer & 1)
                TOURIAN_ESCAPE_DATA.unk_96[2]--;
        }

        position = TOURIAN_ESCAPE_DATA.oamXPositions[1] -= TOURIAN_ESCAPE_DATA.unk_96[1];
        TOURIAN_ESCAPE_DATA.oamXPositions[2] -= TOURIAN_ESCAPE_DATA.unk_96[2];
        TOURIAN_ESCAPE_DATA.oamXPositions[0] = TOURIAN_ESCAPE_DATA.oamXPositions[1] / 32;
        TOURIAN_ESCAPE_DATA.oamYPositions[0] = TOURIAN_ESCAPE_DATA.oamXPositions[2] / 32;
    }
    else if (TOURIAN_ESCAPE_DATA.unk_8[0] == 3)
    {
        switch (TOURIAN_ESCAPE_DATA.oamFrames[1])
        {
            case 0:
                TOURIAN_ESCAPE_DATA.unk_96[1]--;
                if (TOURIAN_ESCAPE_DATA.unk_96[1] < -27)
                    TOURIAN_ESCAPE_DATA.oamFrames[1]++;
                break;

            case 1:
                TOURIAN_ESCAPE_DATA.unk_96[1]++;
                if (TOURIAN_ESCAPE_DATA.unk_96[1] == 0)
                    TOURIAN_ESCAPE_DATA.oamFrames[1]++;
                break;

            case 2:
            case 5:
                if (TOURIAN_ESCAPE_DATA.oamTimers[3]++ > 3)
                {
                    if (TOURIAN_ESCAPE_DATA.oamFrames[1] == 2)
                        TOURIAN_ESCAPE_DATA.oamFrames[1]++;
                    else
                        TOURIAN_ESCAPE_DATA.oamFrames[1] = 0;

                    TOURIAN_ESCAPE_DATA.oamTimers[3] = 0;
                }
                break;

            case 3:
                TOURIAN_ESCAPE_DATA.unk_96[1]++;
                if (TOURIAN_ESCAPE_DATA.unk_96[1] > 39)
                    TOURIAN_ESCAPE_DATA.oamFrames[1]++;
                break;

            case 4:
                TOURIAN_ESCAPE_DATA.unk_96[1]--;
                if (TOURIAN_ESCAPE_DATA.unk_96[1] == 0)
                    TOURIAN_ESCAPE_DATA.oamFrames[1]++;
                break;
        }
        
        velocity = TOURIAN_ESCAPE_DATA.unk_96[1];
        if (velocity > 16)
            velocity = 16;
    
        if (velocity < -16)
            velocity = -16;
    
        position = TOURIAN_ESCAPE_DATA.oamXPositions[1] += velocity;
        TOURIAN_ESCAPE_DATA.oamXPositions[0] = position / 32;
    
        switch (TOURIAN_ESCAPE_DATA.oamFrames[2])
        {
                case 0:
                    TOURIAN_ESCAPE_DATA.unk_96[2]--;
                    if (TOURIAN_ESCAPE_DATA.unk_96[2] < -19)
                        TOURIAN_ESCAPE_DATA.oamFrames[2]++;
                    break;
    
                case 1:
                    TOURIAN_ESCAPE_DATA.unk_96[2]++;
                    if (TOURIAN_ESCAPE_DATA.unk_96[2] == 0)
                        TOURIAN_ESCAPE_DATA.oamFrames[2]++;
                    break;
    
                case 2:
                case 5:
                    if (TOURIAN_ESCAPE_DATA.oamTimers[4]++ > 3)
                    {
                        if (TOURIAN_ESCAPE_DATA.oamFrames[2] == 2)
                            TOURIAN_ESCAPE_DATA.oamFrames[2]++;
                        else
                            TOURIAN_ESCAPE_DATA.oamFrames[2] = 0;
    
                        TOURIAN_ESCAPE_DATA.oamTimers[4] = 0;
                    }
                    break;
    
                case 3:
                    TOURIAN_ESCAPE_DATA.unk_96[2]++;
                    if (TOURIAN_ESCAPE_DATA.unk_96[2] > 19)
                        TOURIAN_ESCAPE_DATA.oamFrames[2]++;
                    break;
    
                case 4:
                    TOURIAN_ESCAPE_DATA.unk_96[2]--;
                    if (TOURIAN_ESCAPE_DATA.unk_96[2] == 0)
                        TOURIAN_ESCAPE_DATA.oamFrames[2]++;
                    break;
        }
    
        velocity = TOURIAN_ESCAPE_DATA.unk_96[2];
        if (velocity > 8)
            velocity = 8;
    
        if (velocity < -8)
            velocity = -8;
    
        position = TOURIAN_ESCAPE_DATA.oamXPositions[2] += velocity;
        TOURIAN_ESCAPE_DATA.oamYPositions[0] = position / 32;
    }

    TourianEscapeProcessOam();

    return ended;
}

/**
 * @brief 83d10 | 198 | Handles the samus going to crash part
 * 
 * @return u8 bool, ended
 */
static u8 TourianEscapeSamusGoingToCrash(void)
{
    u8 ended;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeZebesGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sTourianEscapeShipGoingToCrashGfx, VRAM_OBJ);
            gBg0XPosition = 16;
            gBg0YPosition = 0;

            gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE / 2 + 1;
            gWrittenToBldalpha_H = BLDALPHA_MAX_VALUE / 2 - 1;
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeZebesTileTable, VRAM_BASE + 0xF000);

            #ifdef REGION_EU
            DmaTransfer(3, sTourianEscapeExplodingPal, PALRAM_BASE,
                sizeof(sTourianEscapeExplodingPal), 16);
            DmaTransfer(3, sTourianEscapeSamusGoingToCrashPal, PALRAM_OBJ,
                sizeof(sTourianEscapeSamusGoingToCrashPal), 16);
            #else // !REGION_EU
            DMA_SET(3, sTourianEscapeExplodingPal, PALRAM_BASE,
                C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeExplodingPal)));
            DMA_SET(3, sTourianEscapeSamusGoingToCrashPal, PALRAM_OBJ,
                C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeSamusGoingToCrashPal)));
            #endif // REGION_EU

            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47a98a;
            TOURIAN_ESCAPE_DATA.unk_8[3] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[3] = sTourianEscape_47a958;
            TOURIAN_ESCAPE_DATA.oamXPositions[3] = 0x88;
            TOURIAN_ESCAPE_DATA.oamYPositions[3] = 0x58;
            break;

        case 3:
            WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 30, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_SCREEN_SECOND_TARGET | BLDCNT_ALPHA_BLENDING_EFFECT;
            SoundPlay(SOUND_TOURIAN_ESCAPE_SHIP_FREE_FALLING);
            break;

        case 6:
            TOURIAN_ESCAPE_DATA.unk_8[1] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = 0x6D;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = 0x46;
            break;

        case 12:
            TOURIAN_ESCAPE_DATA.unk_8[2] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[2] = 0x6D;
            TOURIAN_ESCAPE_DATA.oamYPositions[2] = 0x46;
            break;

        case 80:
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            TOURIAN_ESCAPE_DATA.bldcnt = 0;
            ended = TRUE;
    }

    if (TOURIAN_ESCAPE_DATA.unk_5++ > 4)
    {
        TOURIAN_ESCAPE_DATA.unk_5 = 0;
        gBg0XPosition--;
    }

    unk_81ad8();

    return ended;
}

/**
 * @brief 83ea8 | 25c | Handles the samus crashing part
 * 
 * @return u8 bool, ended
 */
static u8 TourianEscapeSamusCrashing(void)
{
    u8 ended;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeShipCrashingForegroundGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sTourianEscapeShipCrashingExplosionGfx, VRAM_BASE + 0x8000);
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeShipCrashingBackgroundAndShipGfx, VRAM_OBJ);
            break;

        case 3:
            LZ77UncompVRAM(sTourianEscapeShipCrashingForegroundTileTable, VRAM_BASE + 0x7000);
            LZ77UncompVRAM(sTourianEscapeShipCrashingExplosionTileTable, VRAM_BASE + 0xF000);

            #ifdef REGION_EU
            DmaTransfer(3, sTourianEscapeSamusCrashingForegroundPal, PALRAM_BASE,
                sizeof(sTourianEscapeSamusCrashingForegroundPal), 16);
            #else // !REGION_EU
            DMA_SET(3, sTourianEscapeSamusCrashingForegroundPal, PALRAM_BASE,
                C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeSamusCrashingForegroundPal)));
            #endif // REGION_EU
            break;

        case 4:
            #ifdef REGION_EU
            DmaTransfer(3, sTourianEscapeShipCrashingBackgroundAndShipPal, PALRAM_OBJ,
                sizeof(sTourianEscapeShipCrashingBackgroundAndShipPal), 16);
            #else // !REGION_EU
            DMA_SET(3, sTourianEscapeShipCrashingBackgroundAndShipPal, PALRAM_OBJ,
                C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeShipCrashingBackgroundAndShipPal)));
            #endif // REGION_EU

            TOURIAN_ESCAPE_DATA.unk_8[1] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47aa96;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = 0x78;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = 0x68;
            TOURIAN_ESCAPE_DATA.oamPriorities[1] = 2;

            gBg0XPosition = 0;
            gBg0YPosition = 0;

            SoundPlay(SOUND_TOURIAN_ESCAPE_SAMUS_CRASHING_FALLING);
            break;

        case 5:
            WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 14, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 30, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_OBJ;
            break;

        case 10:
            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = 0xFA;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = 0x10;
            TOURIAN_ESCAPE_DATA.oamPriorities[0] = 2;
            break;

        case 64:
            TOURIAN_ESCAPE_DATA.unk_8[0] = FALSE;
            break;

        case 104:
            #ifdef REGION_EU
            DmaTransfer(3, sTourianEscape_479f80, PALRAM_BASE, sizeof(sTourianEscape_479f80), 16);
            #else // !REGION_EU
            DMA_SET(3, sTourianEscape_479f80, PALRAM_BASE, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscape_479f80)));
            #endif // REGION_EU
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_OBJ;
            
            TOURIAN_ESCAPE_DATA.unk_8[0] = FALSE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47ab28;
            TOURIAN_ESCAPE_DATA.unk_2++;
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_SCREEN_FIRST_TARGET | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            SoundPlay(SOUND_TOURIAN_ESCAPE_SAMUS_CRASHING_COLLISION);
            break;

        case 288:
            ended = TRUE;
    }

    if (TOURIAN_ESCAPE_DATA.unk_2)
    {
        if (TOURIAN_ESCAPE_DATA.unk_5 & 1)
        {
            if (gWrittenToBldy_NonGameplay < BLDY_MAX_VALUE)
                gWrittenToBldy_NonGameplay++;
        }

        TOURIAN_ESCAPE_DATA.unk_5++;
    }

    if (TOURIAN_ESCAPE_DATA.unk_8[0])
    {
        TOURIAN_ESCAPE_DATA.oamFrames[0] = MOD_AND(TOURIAN_ESCAPE_DATA.oamTimers[0], 32) / 8;
        TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47cfe4[TOURIAN_ESCAPE_DATA.oamFrames[0]];
        TOURIAN_ESCAPE_DATA.oamXPositions[0] -= 4;
        TOURIAN_ESCAPE_DATA.oamYPositions[0] += 2;
        TOURIAN_ESCAPE_DATA.oamTimers[0]++;
    }

    TourianEscapeProcessOam();

    return ended;
}

/**
 * @brief 84104 | 288 | Handles the samus looking at the sky part
 * 
 * @return u8 bool, ended
 */
static u8 TourianEscapeSamusLookingAtSky(void)
{
    u8 ended;
    u8 i;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtSkyGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtSkySkyBackgroundGfx, VRAM_BASE + 0x8000);
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtSkyPiratesShipGfx, VRAM_OBJ);
            break;

        case 3:
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtSkySkyBackgroundTileTable, VRAM_BASE + 0xE000);
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtSkyTopTileTable, VRAM_BASE + 0xF000);
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtSkyBottomTileTable, VRAM_BASE + 0xF800);

            #ifdef REGION_EU
            DmaTransfer(3, sTourianEscapeSamusLookingAtSkyPal, PALRAM_BASE, sizeof(sTourianEscapeSamusLookingAtSkyPal), 16);
            DmaTransfer(3, sTourianEscapeSamusLookingAtSkyPal, PALRAM_OBJ, sizeof(sTourianEscapeSamusLookingAtSkyPal), 16);
            #else // !REGION_EU
            DMA_SET(3, sTourianEscapeSamusLookingAtSkyPal, PALRAM_BASE, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeSamusLookingAtSkyPal)));
            DMA_SET(3, sTourianEscapeSamusLookingAtSkyPal, PALRAM_OBJ, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeSamusLookingAtSkyPal)));
            #endif // REGION_EU

            gBg0YPosition = 0;
            gBg1YPosition = 0;
            gBg2YPosition = BLOCK_SIZE + HALF_BLOCK_SIZE;
            break;

        case 4:
            WRITE_16(REG_BG0CNT, CREATE_BGCNT(2, 28, BGCNT_LOW_MID_PRIORITY, BGCNT_SIZE_256x256));
            WRITE_16(REG_BG1CNT, CREATE_BGCNT(0, 30, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));
            WRITE_16(REG_BG2CNT, CREATE_BGCNT(0, 31, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_OBJ;

        case 160:
            TOURIAN_ESCAPE_DATA.unk_2++;
            break;

        case 16:
            TOURIAN_ESCAPE_DATA.unk_8[0] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[0] = sTourianEscape_47abba;
            TOURIAN_ESCAPE_DATA.oamXPositions[0] = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamYPositions[0] = BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamPriorities[0] = 2;

            SoundPlay(SOUND_TOURIAN_ESCAPE_PIRATES_FLYING_OVER);
            break;

        case 24:
            TOURIAN_ESCAPE_DATA.unk_8[1] = TRUE;
            TOURIAN_ESCAPE_DATA.oamFramePointers[1] = sTourianEscape_47abc8;
            TOURIAN_ESCAPE_DATA.oamXPositions[1] = HALF_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamYPositions[1] = BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE;
            TOURIAN_ESCAPE_DATA.oamPriorities[1] = 2;
            break;

        case 96:
            TOURIAN_ESCAPE_DATA.unk_8[0] = FALSE;
            break;

        case 104:
            TOURIAN_ESCAPE_DATA.unk_8[1] = FALSE;
            break;

        case 432:
            SET_BACKDROP_COLOR(COLOR_BLACK);
            TOURIAN_ESCAPE_DATA.dispcnt = 0;
            gBg0YPosition = 0;
            gBg1YPosition = 0;
            ended = TRUE;
    }

    if (TOURIAN_ESCAPE_DATA.unk_2 == 1)
    {
        if (MOD_AND(TOURIAN_ESCAPE_DATA.timer, 2))
        {
            if (gWrittenToBldy_NonGameplay != 0)
                gWrittenToBldy_NonGameplay--;
            else
                TOURIAN_ESCAPE_DATA.bldcnt = 0;
        }
    }
    else if (TOURIAN_ESCAPE_DATA.unk_2 == 2)
    {
        gBg0YPosition++;
        gBg1YPosition++;

        if (gBg0YPosition >= 96)
            gBg2YPosition++;

        if (MOD_AND(gBg2YPosition, 0x100) == SCREEN_SIZE_Y)
            TOURIAN_ESCAPE_DATA.unk_2 = 0;
    }

    for (i = 0; i < 2; i++)
    {
        if (TOURIAN_ESCAPE_DATA.unk_8[i])
        {
            TOURIAN_ESCAPE_DATA.oamXPositions[i] += 2;
            TOURIAN_ESCAPE_DATA.oamYPositions[i] -= 3;
        }
    }

    TourianEscapeProcessOam();

    return ended;
}

/**
 * @brief 8438c | 388 | Handles the samus looking at the mother ship part
 * 
 * @return u8 bool, ended
 */
static u8 TourianEscapeSamusLookingAtMotherShip(void)
{
    u8 ended;
    u8 i;
    u16 position;

    ended = FALSE;

    switch (TOURIAN_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtMotherShipGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtMotherShipMotherShipGfx, VRAM_BASE + 0x8000);
            break;

        case 2:
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtMotherShipTileTable, VRAM_BASE + 0x7000);
            LZ77UncompVRAM(sTourianEscapeSamusLookingAtMotherShipMotherShipTileTable, VRAM_BASE + 0xF000);

            #ifdef REGION_EU
            DmaTransfer(3, sTourianEscapeSamusLookingAtMotherShipPal, PALRAM_BASE,
                sizeof(sTourianEscapeSamusLookingAtMotherShipPal), 16);
            #else // !REGION_EU
            DMA_SET(3, sTourianEscapeSamusLookingAtMotherShipPal, PALRAM_BASE,
                C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeSamusLookingAtMotherShipPal)));
            #endif // REGION_EU

            gBg0XPosition = 16;
            gBg1XPosition = 0;
            break;

        case 3:
            BitFill(3, 0, VRAM_OBJ, 0x8000, 32);
            LZ77UncompVRAM(sTourianEscapeRainGfx, VRAM_OBJ);
            #ifdef REGION_EU
            DmaTransfer(3, sTourianEscapeRainPal, PALRAM_OBJ, sizeof(sTourianEscapeRainPal), 16);
            DmaTransfer(3, sStoryTextCutscenePal, PALRAM_OBJ + 15 * PAL_ROW_SIZE, sizeof(sStoryTextCutscenePal), 16);
            #else // !REGION_EU
            DMA_SET(3, sTourianEscapeRainPal, PALRAM_OBJ, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sTourianEscapeRainPal)));
            DMA_SET(3, sStoryTextCutscenePal, PALRAM_OBJ + 15 * PAL_ROW_SIZE, C_32_2_16(DMA_ENABLE, ARRAY_SIZE(sStoryTextCutscenePal)));
            #endif // REGION_EU

            for (i = 0; i < TOURIAN_ESCAPE_MAX_OBJECTS; i++)
            {
                TOURIAN_ESCAPE_DATA.unk_8[i] = TRUE;
                TOURIAN_ESCAPE_DATA.oamTimers[i] = sTourianEscape_47cff4[i];
                TOURIAN_ESCAPE_DATA.oamXPositions[i] = sTourianEscape_47cffe[i];
                TOURIAN_ESCAPE_DATA.oamYPositions[i] = BLOCK_SIZE * 4 - 4;
                TOURIAN_ESCAPE_DATA.oamPriorities[i] = 0;
            }

            gWrittenToBldalpha_L = 0;
            gWrittenToBldalpha_H = BLDALPHA_MAX_VALUE;
            gWrittenToBldy_NonGameplay = 0;
            break;

        case 4:
            WRITE_16(REG_BG0CNT, CREATE_BGCNT(0, 14, BGCNT_HIGH_PRIORITY, BGCNT_SIZE_256x256));
            WRITE_16(REG_BG1CNT, CREATE_BGCNT(2, 30, BGCNT_HIGH_MID_PRIORITY, BGCNT_SIZE_256x256));

            TOURIAN_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_OBJ;
            TOURIAN_ESCAPE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
                BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_DECREASE_EFFECT | BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_BG1_SECOND_TARGET_PIXEL |
                BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL;

        case 96:
        case 160:
            TOURIAN_ESCAPE_DATA.unk_2++;
            break;

        case 5:
            TextStartStory(STORY_TEXT_THE_TIMING);
            break;

        case 6:
        case 224:
            TOURIAN_ESCAPE_DATA.unk_BE++;
            break;

        case 448:
            TOURIAN_ESCAPE_DATA.timer--;
            break;
    }

    if (TOURIAN_ESCAPE_DATA.timer > CONVERT_SECONDS(7.45f) && gChangedInput & (KEY_A | KEY_B))
        ended = TRUE + 1;

    if (TOURIAN_ESCAPE_DATA.unk_BE == 1)
    {
        if (TextProcessStory())
            TOURIAN_ESCAPE_DATA.unk_BE++;
    }
    else if (TOURIAN_ESCAPE_DATA.unk_BE == 3)
    {
        if (MOD_AND(TOURIAN_ESCAPE_DATA.unk_BF++, 4) == 0)
        {
            if (gWrittenToBldalpha_L < BLDALPHA_MAX_VALUE)
            {
                gWrittenToBldalpha_L++;
                gWrittenToBldalpha_H = BLDALPHA_MAX_VALUE - gWrittenToBldalpha_L;
            }
        }
    }

    if (TOURIAN_ESCAPE_DATA.unk_2 < 2)
    {
        i = MOD_AND(TOURIAN_ESCAPE_DATA.unk_5++, 16);
        if (i == 0)
        {
            gBg0XPosition--;
            gBg1XPosition++;
        }
        
        if (i == 8)
            gBg1XPosition++;
    }

    if (TOURIAN_ESCAPE_DATA.unk_2 == 3 && MOD_AND(TOURIAN_ESCAPE_DATA.timer, 2))
    {
        if (gWrittenToBldy_NonGameplay < 4)
            gWrittenToBldy_NonGameplay++;
    }

    for (i = 0; i < TOURIAN_ESCAPE_MAX_OBJECTS; i++)
    {
        if (!TOURIAN_ESCAPE_DATA.unk_8[i])
            continue;

        if (TOURIAN_ESCAPE_DATA.oamTimers[i] != 0)
        {
            TOURIAN_ESCAPE_DATA.oamTimers[i]--;
            continue;
        }

        TOURIAN_ESCAPE_DATA.oamXPositions[i] -= 2;
        position = TOURIAN_ESCAPE_DATA.oamYPositions[i];
        TOURIAN_ESCAPE_DATA.oamYPositions[i] += 4;
        position -= (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
        
        if (position < 13)
        {
            TOURIAN_ESCAPE_DATA.oamXPositions[i] = sTourianEscape_47cffe[i];
            TOURIAN_ESCAPE_DATA.oamYPositions[i] = BLOCK_SIZE * 4 - 4;
        }

        if ((TOURIAN_ESCAPE_DATA.timer & 7) < 4)
            TOURIAN_ESCAPE_DATA.oamFramePointers[i] = sTourianEscape_47ac10;
        else
            TOURIAN_ESCAPE_DATA.oamFramePointers[i] = sTourianEscape_47ac18;
    }

    TourianEscapeProcessOam();

    return ended;
}

static TourianEscapeFunc_T sTourianEscapeSubroutinePointers[12] = {
    [0]  = TourianEscapeZebesExploding,
    [1]  = TourianEscapeSamusInHerShip,
    [2]  = TourianEscapeSamusLookingAround,
    [3]  = TourianEscapeSamusSurrounded,
    [4]  = TourianEscapeSamusFlyingIn,
    [5]  = TourianEscapeSamusChasedByPirates,
    [6]  = TourianEscapeSamusChasedByPiratesFiring,
    [7]  = TourianEscapeSamusGettingShot,
    [8]  = TourianEscapeSamusGoingToCrash,
    [9]  = TourianEscapeSamusCrashing,
    [10] = TourianEscapeSamusLookingAtSky,
    [11] = TourianEscapeSamusLookingAtMotherShip
};

/**
 * @brief 84714 | e4 | Executes the current tourian escape subroutine
 * 
 * @return u8 bool, ended
 */
u8 TourianEscapeCallSubroutines(void)
{
    u8 ended;
    u8 result;
    s32 i;

    ended = FALSE;
    gNextOamSlot = 0;

    switch (gGameModeSub1)
    {
        case 0:
            TourianEscapeInit();
            gGameModeSub1++;
            break;

        case 1:
            if (gWrittenToBldy_NonGameplay != 0)
            {
                gWrittenToBldy_NonGameplay--;
                break;
            }

            TOURIAN_ESCAPE_DATA.bldcnt = 0;
            gGameModeSub1++;
            break;

        case 2:
            result = sTourianEscapeSubroutinePointers[TOURIAN_ESCAPE_DATA.stage]();

            if (result == TRUE)
            {
                TOURIAN_ESCAPE_DATA.stage++;
                TOURIAN_ESCAPE_DATA.unk_2 = 0;
                TOURIAN_ESCAPE_DATA.unk_5 = 0;
                TOURIAN_ESCAPE_DATA.timer = 0;
                TOURIAN_ESCAPE_DATA.unk_1 = 0;

                for (i = 0; i < TOURIAN_ESCAPE_MAX_OBJECTS; i++)
                {
                    TOURIAN_ESCAPE_DATA.unk_8[i] = 0;
                    TOURIAN_ESCAPE_DATA.oamTimers[i] = 0;
                    TOURIAN_ESCAPE_DATA.oamPriorities[i] = 0;

                    if (i < 4)
                        TOURIAN_ESCAPE_DATA.oamFrames[i] = 0;
                }
            }
            else if (result)
                gGameModeSub1++;

            ResetFreeOam();
            break;

        case 3:
            ended = TRUE;
    }

    return ended;
}
