#include "gba.h"
#include "power_bomb_explosion.h"
#include "audio_wrappers.h"
#include "haze.h"
#include "screen_shake.h"
#include "fixed_point.h"
#include "macros.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/haze.h"
#include "constants/game_state.h"
#include "constants/room.h"
#include "constants/power_bomb_explosion.h"

#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/display.h"
#include "structs/in_game_cutscene.h"
#include "structs/game_state.h"
#include "structs/room.h"
#include "structs/power_bomb_explosion.h"
#include "temp_globals.h"

static void PowerBombExplosion(void);
static void PowerBombExplosionSet0x12To0(void);
static void PowerBombExplosionBegin(void);
static void PowerBombExplosionEnd(void);

extern u8 sHazeData[EFFECT_HAZE_END][4];

/**
 * 5745c | 48 | Main loop for the power bomb explosion
 */
void PowerBombExplosionProcess(void)
{
    if (gCurrentPowerBomb.animationState > PB_STATE_UNK_1)
    {
        PowerBombExplosionSet0x12To0();
        if (gCurrentPowerBomb.unk_12 == 0) // Most likely a cancelled feature
        {
            if (gCurrentPowerBomb.animationState == PB_STATE_UNK_2)
                PowerBombExplosionBegin();
            else if (gCurrentPowerBomb.animationState == PB_STATE_ENDING)
                PowerBombExplosionEnd();
            else if (gSubGameMode1 == SUB_GAME_MODE_PLAYING)
                PowerBombExplosion();
        }
    }
}

/**
 * @brief 574a4 | 248 | Updates the power bomb explosion, handles interacting with blocks
 * 
 */
static void PowerBombExplosion(void)
{
    s32 verticalAxis;
    s32 horizontalAxis;
    s32 hitboxTop;
    s32 hitboxBottom;
    s32 hitboxLeft;
    s32 hitboxRight;
    s32 outerLoop;
    s32 innerLoop;
    s32 xPositionLeft;
    s32 xPositionRight;
    s32 yPositionTop;
    s32 yPositionBottom;
    u16 clipdata;
    
    verticalAxis = gCurrentPowerBomb.semiMinorAxis * 4;
    horizontalAxis = gCurrentPowerBomb.semiMinorAxis * 8;
    #ifdef BUGFIX
    verticalAxis = FixedMultiplication(verticalAxis, Q_8_8(0.95));
    horizontalAxis = FixedMultiplication(horizontalAxis, Q_8_8(0.95));
    #else // !BUGFIX
    verticalAxis *= 0.95;
    horizontalAxis *= 0.95;
    #endif // BUGFIX

    hitboxLeft = (s16)-horizontalAxis;
    hitboxRight = (s16)horizontalAxis;
    hitboxTop = (s16)-verticalAxis;
    hitboxBottom = (s16)verticalAxis;

    // Check if left edge of explosion is past left side of room. Can only be true while in-bounds
    horizontalAxis = hitboxLeft;
    if (gCurrentPowerBomb.xPosition + horizontalAxis < 0)
        hitboxLeft = (s16)-gCurrentPowerBomb.xPosition;

    // Check if top edge of explosion is past top side of room. Can only be true while in-bounds
    verticalAxis = hitboxTop;
    if (gCurrentPowerBomb.yPosition + verticalAxis < 0)
        hitboxTop = (s16)-gCurrentPowerBomb.yPosition;

    // Check if right edge of explosion is past right side of room
    // BUG: If far enough out-of-bounds, integer underflow will occur from the subtraction
    horizontalAxis = hitboxRight;
    if ((gBgPointersAndDimensions.clipdataWidth * BLOCK_SIZE) < (gCurrentPowerBomb.xPosition + horizontalAxis))
        hitboxRight = (s16)(gBgPointersAndDimensions.clipdataWidth * BLOCK_SIZE - gCurrentPowerBomb.xPosition);

    // Check if bottom edge of explosion is past bottom side of room
    // BUG: If far enough out-of-bounds, integer underflow will occur from the subtraction
    verticalAxis = hitboxBottom;
    if ((gBgPointersAndDimensions.clipdataHeight * BLOCK_SIZE) < (gCurrentPowerBomb.yPosition + verticalAxis))
        hitboxBottom = (s16)(gBgPointersAndDimensions.clipdataHeight * BLOCK_SIZE - gCurrentPowerBomb.yPosition);

    gCurrentPowerBomb.hitboxLeft = hitboxLeft;
    gCurrentPowerBomb.hitboxRight = hitboxRight;
    gCurrentPowerBomb.hitboxTop = hitboxTop;
    gCurrentPowerBomb.hitboxBottom = hitboxBottom;

    if (gCurrentPowerBomb.animationState < PB_STATE_IMPLODING)
    {
        hitboxLeft = DIV_SHIFT(hitboxLeft + gCurrentPowerBomb.xPosition, BLOCK_SIZE);
        hitboxRight = DIV_SHIFT(hitboxRight + gCurrentPowerBomb.xPosition, BLOCK_SIZE);
        hitboxTop = DIV_SHIFT(hitboxTop + gCurrentPowerBomb.yPosition, BLOCK_SIZE);
        hitboxBottom = DIV_SHIFT(hitboxBottom + gCurrentPowerBomb.yPosition, BLOCK_SIZE);

        if (MOD_AND(gFrameCounter8Bit, 2) == 0)
        {
            gCurrentClipdataAffectingAction = CAA_POWER_BOMB;

            // Do 2 loops, one for left side and one for right side
            for (outerLoop = 0; outerLoop < 2; outerLoop++)
            {
                if (outerLoop == 0)
                    horizontalAxis = hitboxLeft;
                else
                    horizontalAxis = hitboxRight;

                // BUG: yPosition is not checked if out-of-bounds, which can lead to memory corruption
                yPositionTop = gCurrentPowerBomb.yPosition / BLOCK_SIZE;
                yPositionBottom = yPositionTop;

                for (innerLoop = 0; innerLoop != 2;)
                {
                    innerLoop = 0;
                    if (yPositionTop >= hitboxTop)
                    {
                        clipdata = GET_CLIP_BLOCK(horizontalAxis, yPositionTop);
                        if (clipdata != 0)
                            BlockApplyCcaa(yPositionTop, horizontalAxis, clipdata);

                        yPositionTop = (s16)(yPositionTop - 1);
                    }
                    else
                        innerLoop++;
                    
                    if ((s32)yPositionBottom <= hitboxBottom)
                    {
                        clipdata = GET_CLIP_BLOCK(horizontalAxis, yPositionBottom);
                        if (clipdata != 0)
                            BlockApplyCcaa(yPositionBottom, horizontalAxis, clipdata);

                        yPositionBottom = (s16)(yPositionBottom + 1);
                    }
                    else
                        innerLoop++;
                }
            }
        }
        else
        {
            gCurrentClipdataAffectingAction = CAA_POWER_BOMB;

            // Do 2 loops, one for top side and one for bottom side
            for (outerLoop = 0; outerLoop < 2; outerLoop++)
            {
                if (outerLoop == 0)
                    verticalAxis = hitboxTop;
                else
                    verticalAxis = hitboxBottom;

                // BUG: xPosition is not checked if out-of-bounds, which can lead to memory corruption
                xPositionRight = gCurrentPowerBomb.xPosition / BLOCK_SIZE;
                xPositionLeft = xPositionRight;

                for (innerLoop = 0; innerLoop != 2;)
                {
                    innerLoop = 0;
                    if (xPositionLeft >= hitboxLeft)
                    {
                        clipdata = GET_CLIP_BLOCK(xPositionLeft, verticalAxis);
                        if (clipdata != 0)
                            BlockApplyCcaa(verticalAxis, xPositionLeft, clipdata);
                        
                        xPositionLeft = (s16)(xPositionLeft - 1);
                    }
                    else
                        innerLoop++;
                    
                    if (xPositionRight <= hitboxRight)
                    {
                        clipdata = GET_CLIP_BLOCK(xPositionRight, verticalAxis);
                        if (clipdata != 0)
                            BlockApplyCcaa(verticalAxis, xPositionRight, clipdata);

                        xPositionRight = (s16)(xPositionRight + 1);
                    }
                    else
                        innerLoop++;
                }
            }
        }
        gCurrentClipdataAffectingAction = CAA_NONE;
    }
}

/**
 * 576ec | 48 | Starts a power bomb explosion at the given parameters
 * 
 * @param xPosition The X Position of the epicenter
 * @param yPosition The Y Position of the epicenter
 * @param owner Owner of the power bomb, left over from fusion
 */
void PowerBombExplosionStart(u16 xPosition, u16 yPosition, u8 owner)
{
    if (gSubGameMode1 != SUB_GAME_MODE_PLAYING)
        return;

    PowerBombExplosionSet0x12To0();
    // Check if there isn't already an explosion
    if (gCurrentPowerBomb.animationState == PB_STATE_NONE)
    {
        gCurrentPowerBomb.xPosition = xPosition;
        gCurrentPowerBomb.yPosition = yPosition;
        gCurrentPowerBomb.owner = owner;

        if (gCurrentPowerBomb.unk_12 != 0)
            gCurrentPowerBomb.animationState = PB_STATE_UNK_2;
        else
            PowerBombExplosionBegin();
    }
}

/**
 * 57734 | c | Sets the field at offset 0x12 of the current power bomb to 0x0, purpose is unknown 
 * 
 */
static void PowerBombExplosionSet0x12To0(void)
{
    gCurrentPowerBomb.unk_12 = 0;
}

/**
 * @brief 57740 | 78 | Begins a power bomb explosion
 * 
 */
static void PowerBombExplosionBegin(void)
{
    if (gSubGameMode1 != SUB_GAME_MODE_PLAYING)
        return;

    gCurrentPowerBomb.animationState = PB_STATE_EXPLODING;
    gCurrentPowerBomb.powerBombPlaced = FALSE;

    DMA_SET(3, PALRAM_BASE, EWRAM_BASE + 0x9000, C_32_2_16(DMA_ENABLE, PAL_SIZE / 2));
    gUnk_02035400 = 0;

    HazeSetupCode(HAZE_VALUE_POWER_BOMB_EXPANDING);

    gCurrentPowerBomb.stage = 0;
    gCurrentPowerBomb.semiMinorAxis = 4;

    gCurrentPowerBomb.hitboxLeft = 0;
    gCurrentPowerBomb.hitboxRight = 0;
    gCurrentPowerBomb.hitboxTop = 0;
    gCurrentPowerBomb.hitboxBottom = 0;

    gCurrentPowerBomb.unk_12 = 0;
    gCurrentPowerBomb.unk_3 = 0;

    ScreenShakeStartHorizontal(CONVERT_SECONDS(2.f), 0x80);

    SoundPlay(SOUND_POWER_BOMB_EXPLOSION);
}

/**
 * @brief 577b8 | 154 | Handles ending a power bomb explosion
 * 
 */
static void PowerBombExplosionEnd(void)
{
    u8 eva;
    u8 evb;
    u8 done;

    if (gCurrentPowerBomb.stage == 0)
    {
        WRITE_16(REG_BLDY, 0);
        gWrittenToBldcnt = gIoRegistersBackup.Bldcnt_NonGameplay;

        if (sHazeData[gCurrentRoomEntry.visualEffect][3] == 2)
            gWrittenToBldalpha = C_16_2_8(0, 16);
        else
            gWrittenToBldalpha = C_16_2_8(16, 0);

        gWrittenToDispcnt = WRITE_16(REG_DISPCNT, READ_16(REG_DISPCNT) | DCNT_WIN1);

        gWrittenToWin1H = C_16_2_8(gSuitFlashEffect.left, gSuitFlashEffect.right);
        gWrittenToWin1V = C_16_2_8(gSuitFlashEffect.top, gSuitFlashEffect.bottom);

        // Set transparent color
        SET_BACKDROP_COLOR(COLOR_BLACK);

        gWrittenToWinIn_H = gIoRegistersBackup.WININ_H;
        gWrittenToWinOut_L = gIoRegistersBackup.WINOUT_L;

        // Get BGCNT backups
        WRITE_16(REG_BG0CNT, gIoRegistersBackup.BG0CNT);
        WRITE_16(REG_BG1CNT, gIoRegistersBackup.BG1CNT);
        WRITE_16(REG_BG2CNT, gIoRegistersBackup.BG2CNT);
        WRITE_16(REG_BG3CNT, gIoRegistersBackup.BG3CNT);

        gWrittenToDispcnt = gIoRegistersBackup.Dispcnt_NonGameplay;
        gCurrentPowerBomb.stage = 1;
    }
    else if (gCurrentPowerBomb.stage == 1)
    {
        // Fade BLDALPHA until it was the same as before the power bomb
        eva = LOW_BYTE(READ_16(REG_BLDALPHA));
        evb = HIGH_BYTE(READ_16(REG_BLDALPHA));
        done = TRUE;

        if (gIoRegistersBackup.BLDALPHA_NonGameplay_EVB != evb)
        {
            if (gIoRegistersBackup.BLDALPHA_NonGameplay_EVB < evb)
                evb--;
            else
                evb++;

            done = FALSE;
        }

        if (gIoRegistersBackup.BLDALPHA_NonGameplay_EVA != eva)
        {
            if (gIoRegistersBackup.BLDALPHA_NonGameplay_EVA < eva)
                eva--;
            else
                eva++;

            done = FALSE;
        }

        gWrittenToBldalpha = C_16_2_8(evb, eva);

        if (done)
            gCurrentPowerBomb.stage = 2;
    }
    else if (gCurrentPowerBomb.stage == 2)
    {
        // Kill the power bomb
        gCurrentPowerBomb.animationState = PB_STATE_NONE;
        gCurrentPowerBomb.owner = 0;
        gCurrentPowerBomb.stage = 0;
    }
}
