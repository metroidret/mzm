#include "sprites_AI/deorem.h"
#include "gba.h"
#include "macros.h"

#include "data/sprites/deorem.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/particle.h"

#include "structs/clipdata.h"
#include "structs/game_state.h"
#include "structs/samus.h"
#include "structs/scroll.h"
#include "structs/sprite.h"

#define DEOREM_POSE_WAITING_FOR_FIGHT 0x8
#define DEOREM_POSE_SPAWN_GOING_DOWN 0x9
#define DEOREM_POSE_SPAWN_DELAY_BEFORE_GOING_UP 0x22
#define DEOREM_POSE_SPAWN_GOING_UP 0x23
#define DEOREM_POSE_SPAWN_DELAY_BEFORE_HEAD_EMERGES 0x24
#define DEOREM_POSE_SPAWN_HEAD_EMERGES 0x25
#define DEOREM_POSE_MAIN 0x26
#define DEOREM_POSE_RETRACTING 0x27
#define DEOREM_POSE_THORNS_DOWN_SEGMENT 0x28
#define DEOREM_POSE_THORNS_UP_SEGMENT 0x29
#define DEOREM_POSE_AFTER_THORNS 0x2A
#define DEOREM_POSE_WAIT_TO_LEAVE 0x42
#define DEOREM_POSE_START_LEAVING 0x43
#define DEOREM_POSE_LEAVING 0x44
#define DEOREM_POSE_LEAVING_IN_GROUND 0x45
#define DEOREM_POSE_CALL_SPAWN_CHARGE_BEAM 0x60
#define DEOREM_POSE_DYING_GOING_DOWN 0x67
#define DEOREM_POSE_DEATH 0x68

#define EYE_OPENING_TIMER (CONVERT_SECONDS(1.f) + ONE_THIRD_SECOND)

// The space between the 2 deorem body parts around the screen
#define DEOREM_WIDTH (BLOCK_SIZE * 13)
#define DEOREM_HEIGHT (BLOCK_SIZE * 10)
// The X offset at which deorem's head can't go
#define DEOREM_HEAD_SPACE_OFFSET (BLOCK_SIZE * 3)
// The min X position for deorem's head on the left
#define DEOREM_HEAD_SPACE_LEFT (DEOREM_HEAD_SPACE_OFFSET)
// The max X position for deorem's head on the right
#define DEOREM_HEAD_SPACE_RIGHT (DEOREM_WIDTH - DEOREM_HEAD_SPACE_OFFSET)
// How far the head extends downwards from the ceiling
#define DEOREM_HEAD_Y_OFFSET (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE)

#define DEOREM_OUTSIDE_FIGHT_RANGE (SCREEN_SIZE_X_SUB_PIXEL + BLOCK_SIZE)

#define SPAWN_GOING_DOWN_DURATION (CONVERT_SECONDS(.1f) + TWO_THIRD_SECOND)
#define SPAWN_GOING_UP_DURATION (CONVERT_SECONDS(5.f / 6))
#define DEOREM_SPAWNING_SPEED (QUARTER_BLOCK_SIZE)
#define DEOREM_LEAVING_SPEED (QUARTER_BLOCK_SIZE)

#define DEOREM_ATTACK_SPEED_Y (EIGHTH_BLOCK_SIZE)
#define DEOREM_DIAGONAL_ATTACK_RANGE (BLOCK_SIZE + HALF_BLOCK_SIZE)

// Deorem segment

enum DeoremSegment {
    DEOREM_SEGMENT_DOWN_JUNCTION,
    DEOREM_SEGMENT_DOWN_1,
    DEOREM_SEGMENT_DOWN_2,
    DEOREM_SEGMENT_DOWN_3,
    DEOREM_SEGMENT_DOWN_4,
    DEOREM_SEGMENT_DOWN_5,

    DEOREM_SEGMENT_UP_JUNCTION,
    DEOREM_SEGMENT_UP_1,
    DEOREM_SEGMENT_UP_2,
    DEOREM_SEGMENT_UP_3,
    DEOREM_SEGMENT_UP_4,
    DEOREM_SEGMENT_UP_5,

    DEOREM_SEGMENT_NECK_JUNCTION,
    DEOREM_SEGMENT_NECK_1,
    DEOREM_SEGMENT_NECK_2,

    DEOREM_SEGMENT_LEAVING_1,
    DEOREM_SEGMENT_LEAVING_2,
    DEOREM_SEGMENT_LEAVING_3,

    DEOREM_SEGMENT_TAIL,
    DEOREM_SEGMENT_19
};

#define DEOREM_SEGMENT_POSE_DOWN_SEGMENT_SPAWNING 0x8
#define DEOREM_SEGMENT_POSE_DOWN_SEGMENT_AFTER_SPAWNING 0x9
#define DEOREM_SEGMENT_POSE_DOWN_SEGMENT_IDLE 0xF
#define DEOREM_SEGMENT_POSE_UP_SEGMENT_IDLE 0x11
#define DEOREM_SEGMENT_POSE_UP_SEGMENT_SPAWNING 0x22
#define DEOREM_SEGMENT_POSE_UP_SEGMENT_AFTER_SPAWNING 0x23
#define DEOREM_SEGMENT_POSE_NECK_SEGMENT_IDLE 0x24
#define DEOREM_SEGMENT_POSE_GOING_DOWN 0x33
#define DEOREM_SEGMENT_POSE_GOING_UP 0x35
#define DEOREM_SEGMENT_POSE_UP_LEAVING 0x42
#define DEOREM_SEGMENT_POSE_UP_DESPAWN 0x43
#define DEOREM_SEGMENT_POSE_DOWN_DESPAWN 0x46
#define DEOREM_SEGMENT_POSE_NECK_LEAVING 0x4A
#define DEOREM_SEGMENT_POSE_NECK_BURROW 0x4B
#define DEOREM_SEGMENT_POSE_NECK_DESPAWN 0x4C
#define DEOREM_SEGMENT_POSE_DYING 0x67

#define DEOREM_SEGMENT_SPACING (BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE)
#define DEOREM_SEGMENT_PADDING (DEOREM_SEGMENT_SPACING + BLOCK_SIZE + PIXEL_SIZE)

#define DEOREM_THORN_TIMING_1 (CONVERT_SECONDS(4.f + 1.f / 60))
#define DEOREM_THORN_TIMING_2 (CONVERT_SECONDS(3.f + 1.f / 60))
#define DEOREM_THORN_TIMING_3 (CONVERT_SECONDS(1.f + 1.f / 60) + TWO_THIRD_SECOND)
#define DEOREM_THORN_TIMING_4 (ONE_THIRD_SECOND + CONVERT_SECONDS(1.f / 60))

// Deorem eye

#define DEOREM_EYE_POSE_IDLE_INIT 0x8
#define DEOREM_EYE_POSE_IDLE 0x9
#define DEOREM_EYE_POSE_DYING_SPINNING 0x67
#define DEOREM_EYE_POSE_DYING_MOVING 0x68

#define DEOREM_EYE_Y_OFFSET (HALF_BLOCK_SIZE - PIXEL_SIZE)
#define DEOREM_EYE_X_OFFSET (PIXEL_SIZE)

#define DEOREM_EYE_DYING_SPEED (PIXEL_SIZE / 2)

// Deorem thorn

#define DEOREM_THORN_POSE_SPAWNING 0x9
#define DEOREM_THORN_POSE_MOVING 0x23

/**
 * @brief 20c7c | 84 | Changes the clipdata on deorem's left wall
 * 
 * @param caa Clipdata affecting action
 */
/*static*/ void DeoremChangeLeftWallClipdata(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gBossWork.work1;
    xPosition = gBossWork.work2;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE * 0, xPosition);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE * 1, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE * 2, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE * 3, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE * 4, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition);
}

/**
 * @brief 20d00 | 90 | Changes the clipdata on deorem's right wall
 * 
 * @param caa Clipdata affecting action
 */
/*static*/ void DeoremChangeRightWallClipdata(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gBossWork.work1;
    xPosition = gBossWork.work2 + DEOREM_WIDTH;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE * 0, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE * 1, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE * 2, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE * 3, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE * 4, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition);
}

/**
 * @brief 20d90 | d4 | Handles moving Deorem on the X axis when attacking diagonally
 * 
 * @param speedCap Speed cap
 * @param dstPosition Destination X position
 */
/*static*/ void DeoremMoveDiagonallyX(u8 speedCap, u16 dstPosition)
{
    s32 speed;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.xPosition > dstPosition - PIXEL_SIZE)
            {
                gCurrentSprite.work1 = gCurrentSprite.work2;
            }
            else
            {
                if (gCurrentSprite.work2 < speedCap)
                    gCurrentSprite.work2++;

                if (gCurrentSprite.xPosition < gBossWork.work2 + DEOREM_HEAD_SPACE_RIGHT)
                {
                    speed = gCurrentSprite.work2;
                    gCurrentSprite.xPosition += speed / 2;
                }
            }
        }
        else
        {
            if (gCurrentSprite.work1 >= ONE_SUB_PIXEL * 2)
                gCurrentSprite.work1 -= ONE_SUB_PIXEL;

            if (gCurrentSprite.xPosition < gBossWork.work2 + DEOREM_HEAD_SPACE_RIGHT)
            {
                speed = gCurrentSprite.work1;
                gCurrentSprite.xPosition += speed / 2;
            }
        }
    }
    else
    {
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.xPosition < dstPosition + PIXEL_SIZE)
            {
                gCurrentSprite.work1 = gCurrentSprite.work2;
            }
            else
            {
                if (gCurrentSprite.work2 < speedCap)
                    gCurrentSprite.work2++;

                if (gCurrentSprite.xPosition > gBossWork.work2 + DEOREM_HEAD_SPACE_LEFT)
                {
                    speed = gCurrentSprite.work2;
                    gCurrentSprite.xPosition -= speed / 2;
                }
            }
        }
        else
        {
            if (gCurrentSprite.work1 >= ONE_SUB_PIXEL * 2)
                gCurrentSprite.work1 -= ONE_SUB_PIXEL;

            if (gCurrentSprite.xPosition > gBossWork.work2 + DEOREM_HEAD_SPACE_LEFT)
            {
                speed = gCurrentSprite.work1;
                gCurrentSprite.xPosition -= speed / 2;
            }
        }
    }
}

/**
 * @brief 20e64 | 11c | Handles the spawning of random sprite debris before the fight
 * 
 * @param rng Random number
 */
/*static*/ void DeoremRandomSpriteDebris(u8 rng)
{
    u16 yPosition;
    u16 xPosition;
    u8 rng1;
    u8 rng2;

    yPosition = gBossWork.work1 + HALF_BLOCK_SIZE;
    xPosition = gBossWork.work2 + DEOREM_WIDTH / 2;
    rng1 = gSpriteRng;
    rng2 = gFrameCounter8Bit;

    if (rng1 % 2)
    {
        SpriteDebrisInit(0, 5, yPosition - (BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE - PIXEL_SIZE) + rng1 * ONE_SUB_PIXEL,
            xPosition + QUARTER_BLOCK_SIZE + PIXEL_SIZE + rng1 * HALF_BLOCK_SIZE);
    }
    else
    {
        SpriteDebrisInit(0, 7, yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE) + rng1 * ONE_SUB_PIXEL,
            xPosition + (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2) + rng1 * QUARTER_BLOCK_SIZE);
    }

    if (rng1 >= SPRITE_RNG_PROB(.5f))
    {
        SpriteDebrisInit(0, 8, yPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE) + rng1 * ONE_SUB_PIXEL,
            xPosition - (QUARTER_BLOCK_SIZE + PIXEL_SIZE / 2) - rng1 * PIXEL_SIZE / 2);
    }
    else
    {
        SpriteDebrisInit(0, 6, yPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2) + rng1,
            xPosition - (QUARTER_BLOCK_SIZE + PIXEL_SIZE / 2) - rng1 * PIXEL_SIZE);
        SpriteDebrisInit(0, 5, yPosition - (BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE), xPosition - rng2 * PIXEL_SIZE / 2);
    }

    if (MOD_BLOCK_AND(rng, CONVERT_SECONDS(.5f + 1.f / 30)) == 0)
    {
        if (rng1 % 2)
        {
            SpriteDebrisInit(0, 6, yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE),
                xPosition - rng2 * PIXEL_SIZE / 2);
        }
        else
        {
            SpriteDebrisInit(0, 8, yPosition - (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE),
                xPosition - rng2 * PIXEL_SIZE / 2);
        }

        if (rng1 >= SPRITE_RNG_PROB(.75f))
        {
            SpriteDebrisInit(0, 5, yPosition - (EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2), xPosition + rng2 * PIXEL_SIZE / 2);
            SpriteDebrisInit(0, 6, yPosition - (BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE) + rng1,
                xPosition - rng1 * EIGHTH_BLOCK_SIZE);
        }
        else
        {
            SpriteDebrisInit(0, 7, yPosition - (BLOCK_SIZE - PIXEL_SIZE), xPosition + rng2 * PIXEL_SIZE / 2);
        }
    }
}

/**
 * @brief 20f80 | a8 | Handles the spawning of sprite debris when Deorem appears
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param timer Timer (determines which set to spawn)
 */
/*static*/ void DeoremSpriteDebrisSpawn(u16 yPosition, u16 xPosition, u8 timer)
{
    switch (timer)
    {
        case CONVERT_SECONDS(1.f / 60):
            SpriteDebrisInit(0, 17, yPosition - BLOCK_SIZE, xPosition);
            SpriteDebrisInit(0, 18, yPosition - QUARTER_BLOCK_SIZE, xPosition + (BLOCK_SIZE - PIXEL_SIZE / 2));
            break;

        case CONVERT_SECONDS(.05f):
            SpriteDebrisInit(0, 19, yPosition + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
                xPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE - PIXEL_SIZE));
            SpriteDebrisInit(0, 4, yPosition, xPosition + (HALF_BLOCK_SIZE - PIXEL_SIZE / 2));
            break;

        case CONVERT_SECONDS(.1f + 1.f / 60):
            SpriteDebrisInit(0, 17, yPosition + (QUARTER_BLOCK_SIZE + PIXEL_SIZE),
                xPosition - (QUARTER_BLOCK_SIZE + PIXEL_SIZE));
            SpriteDebrisInit(0, 18, yPosition - (QUARTER_BLOCK_SIZE + PIXEL_SIZE),
                xPosition + (BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE - PIXEL_SIZE / 2));
            break;

        case CONVERT_SECONDS(.2f):
            SpriteDebrisInit(0, 19, yPosition + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
                xPosition + (HALF_BLOCK_SIZE - PIXEL_SIZE / 2));
            SpriteDebrisInit(0, 4, yPosition - QUARTER_BLOCK_SIZE, xPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE));
    }
}

/**
 * @brief 21028 | 6c | Checks if Deorem is leaving
 * 
 * @param ramSlot Deorem's eye ram slot
 * @return bool, leaving
 */
/*static*/ u8 DeoremCheckLeaving(u8 eyeSlot)
{
    if (gSpriteData[eyeSlot].yPositionSpawn == 0)
    {
        gCurrentSprite.pose = DEOREM_POSE_WAIT_TO_LEAVE;

        if (gCurrentSprite.pOam != sDeoremOam_ClosedFast && gCurrentSprite.pOam != sDeoremOam_Closing)
        {
            gCurrentSprite.pOam = sDeoremOam_Closing;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.hitboxBottom = BLOCK_SIZE;
            gSpriteData[eyeSlot].status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            SoundPlay(SOUND_DEOREM_CLOSING_JAW);
        }
        
        return TRUE;
    }
    
    return FALSE;
}

/**
 * @brief 21094 | 40 | Spawns and loads a charge beam sprite at the given position
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 */
/*static*/ void DeoremSpawnChargeBeam(u16 yPosition, u16 xPosition)
{
    u8 gfxSlot;

    gfxSlot = gCurrentSprite.spritesetGfxSlot;

    SpriteSpawnPrimary(PSPRITE_CHARGE_BEAM, 0, gfxSlot, yPosition, xPosition, 0);
    SpriteLoadGfx(PSPRITE_CHARGE_BEAM, gfxSlot);
    SpriteLoadPal(PSPRITE_CHARGE_BEAM, gfxSlot, 1);
}

/**
 * @brief 210d4 | 3c | Sets the timer for how long the eye stays open
 * 
 */
/*static*/ void DeoremSetEyeOpeningTimer(void)
{
    if (gDifficulty == DIFF_EASY)
        gCurrentSprite.work0 = EYE_OPENING_TIMER * 3 / 2;
    else if (gDifficulty == DIFF_HARD)
        gCurrentSprite.work0 = EYE_OPENING_TIMER / 2;
    else
        gCurrentSprite.work0 = EYE_OPENING_TIMER;
}

/**
 * @brief 21110 | 2c | Calls the charge beam spawn handler, used when Deorem is already dead but the charge beam hasn't been picked up
 * 
 */
/*static*/ void DeoremCallSpawnChargeBeam(void)
{
    DeoremSpawnChargeBeam(gCurrentSprite.yPosition + BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE,
        gCurrentSprite.xPosition + DEOREM_WIDTH / 2);

    gCurrentSprite.status = 0;
}

/**
 * @brief 2113c | 128 | Initialize a Deorem sprite
 */
/*static*/ void DeoremInit(void)
{
    if (gCurrentSprite.spriteId == PSPRITE_DEOREM_FIRST_LOCATION)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED))
        {
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED) &&
                !(gEquipment.beamBombs & BBF_CHARGE_BEAM) &&
                !EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_KILLED_AT_SECOND_LOCATION))
            {
                gCurrentSprite.pose = DEOREM_POSE_CALL_SPAWN_CHARGE_BEAM;
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            }
            else
            {
                gCurrentSprite.status = 0;
            }
            return;
        }
    }
    else
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED))
        {
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED) &&
                !(gEquipment.beamBombs & BBF_CHARGE_BEAM) &&
                EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_KILLED_AT_SECOND_LOCATION))
            {
                gCurrentSprite.pose = DEOREM_POSE_CALL_SPAWN_CHARGE_BEAM;
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            }
            else
            {
                gCurrentSprite.status = 0;
            }
            return;
        }
    }

    gBossWork.work1 = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    gBossWork.work2 = gCurrentSprite.xPosition;

    // Put the head into the ceiling
    gCurrentSprite.yPosition -= DEOREM_HEAD_Y_OFFSET;

    gCurrentSprite.hitboxTop = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.hitboxBottom = BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);

    gCurrentSprite.pOam = sDeoremOam_ClosedSlow;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 10;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.work0 = 0;
    gCurrentSprite.pose = DEOREM_POSE_WAITING_FOR_FIGHT;
    gCurrentSprite.rotation = 0;
}

/**
 * @brief 21264 | 1b8 | Handles Deorem waiting for the fight to start
 */
/*static*/ void DeoremWaitingForFight(void)
{
    u16 samusX;
    u16 xPosition;
    u16 yPosition;
    u8 gfxRow;
    u8 ramSlot;

    xPosition = gBossWork.work2 + DEOREM_WIDTH / 2;
    samusX = gSamusData.xPosition;

    APPLY_DELTA_TIME_INC(gCurrentSprite.work0);

    if (gEquipment.maxMissiles == 0)
    {
        if (samusX > xPosition - DEOREM_OUTSIDE_FIGHT_RANGE && samusX < xPosition + DEOREM_OUTSIDE_FIGHT_RANGE)
        {
            if (gSpriteRng == 0)
            {
                ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
            }

            if (MOD_AND(gCurrentSprite.work0, CONVERT_SECONDS(.5f + 1.f / 30)) == 0)
            {
                DeoremRandomSpriteDebris(gCurrentSprite.work0);
                SoundPlay(SOUND_190);
            }
        }
    }
    else if (samusX <= (xPosition - HALF_BLOCK_SIZE) || (samusX >= xPosition + HALF_BLOCK_SIZE))
    {
        if (samusX > xPosition - DEOREM_OUTSIDE_FIGHT_RANGE && samusX < xPosition + DEOREM_OUTSIDE_FIGHT_RANGE)
        {
            if (gSpriteRng == 0)
            {
                ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
            }

            if (MOD_AND(gCurrentSprite.work0, CONVERT_SECONDS(.5f + 1.f / 30)) == 0)
            {
                DeoremRandomSpriteDebris(gCurrentSprite.work0);
                SoundPlay(SOUND_190);
            }
        }
    }
    else
    {        
        gLockScreen.lock = LOCK_SCREEN_TYPE_POSITION;
        gLockScreen.yPositionCenter = gSamusData.yPosition;
        gLockScreen.xPositionCenter = gBossWork.work2 + DEOREM_WIDTH / 2;

        // Determine on which position deorem starts, either left of right
        if (gSamusData.direction & KEY_RIGHT)
        {
            // Right
            gBossWork.work3 = TRUE;
            gCurrentSprite.xPosition += DEOREM_WIDTH;
        }
        else
        {
            // Left
            gBossWork.work3 = FALSE;
        }

        gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
        gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;

        gfxRow = gCurrentSprite.spritesetGfxSlot;
        ramSlot = gCurrentSprite.primarySpriteRamSlot;
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;
        
        gCurrentSprite.pose = DEOREM_POSE_SPAWN_GOING_DOWN;
        gCurrentSprite.work0 = SPAWN_GOING_DOWN_DURATION;

        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_DOWN_5, gfxRow, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_DOWN_4, gfxRow, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_DOWN_3, gfxRow, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_DOWN_2, gfxRow, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_DOWN_1, gfxRow, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_DOWN_JUNCTION, gfxRow, ramSlot, yPosition, xPosition, 0);
        
        ScreenShakeStartVertical(TWO_THIRD_SECOND, 0x80 | 1);
        SoundPlay(SOUND_DEOREM_MOVING);
        
        DeoremChangeLeftWallClipdata(CAA_MAKE_SOLID_GRIPPABLE);
        DeoremChangeRightWallClipdata(CAA_MAKE_SOLID_GRIPPABLE);
    }
}

/**
 * @brief 2141c | f4 | Handles Deorem going down while spawning
 * 
 */
/*static*/ void DeoremSpawnGoingDown(void)
{
    u16 xPosition;
    u16 yPosition;
    u8 timer;

    yPosition = gBossWork.work1;
    xPosition = gCurrentSprite.xPositionSpawn;
    gCurrentSprite.yPosition += DEOREM_SPAWNING_SPEED;

    if (gCurrentSprite.work0 <= CONVERT_SECONDS(.25f))
    {
        timer = gCurrentSprite.work0;
        DeoremSpriteDebrisSpawn(yPosition + BLOCK_SIZE * 6, xPosition, timer);
        if (timer == CONVERT_SECONDS(2.f / 15))
        {
            ParticleSet(yPosition + BLOCK_SIZE * 7, xPosition, PE_TWO_MEDIUM_DUST);
        }
    }
    else
    {
        timer = SPAWN_GOING_DOWN_DURATION - gCurrentSprite.work0;
        DeoremSpriteDebrisSpawn(yPosition + BLOCK_SIZE, xPosition, timer);
        if (timer == 0)
        {
            // First frame of going down
            ParticleSet(yPosition + BLOCK_SIZE, xPosition, PE_TWO_MEDIUM_DUST);
            SoundPlay(SOUND_DEOREM_SPAWN_GOING_DOWN);
            SoundPlay(SOUND_DEOREM_SCREAMING);
            PlayMusic(MUSIC_WORMS_BATTLE, 0);
        }
    }

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = DEOREM_POSE_SPAWN_DELAY_BEFORE_GOING_UP;
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);
        gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;

        // Set X position for the going up part of the spawn
        if (gBossWork.work3)
            gCurrentSprite.xPosition -= DEOREM_WIDTH;
        else
            gCurrentSprite.xPosition += DEOREM_WIDTH;

        ScreenShakeStartVertical(TWO_THIRD_SECOND, 0x80 | 1);
        SoundPlay(SOUND_DEOREM_MOVING);
    }
}

/**
 * @brief 21510 | d0 | Handles Deorem waiting a bit before going up during spawn
 * 
 */
/*static*/ void DeoremSpawnDelayBeforeGoingUp(void)
{
    u16 yPosition;
    u8 gfxSlot;
    u8 ramSlot;
    u16 xPosition;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = DEOREM_POSE_SPAWN_GOING_UP;
        gCurrentSprite.work0 = SPAWN_GOING_UP_DURATION;
        // Put in the ground
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn + DEOREM_HEIGHT + DEOREM_HEAD_Y_OFFSET - PIXEL_SIZE;

        gfxSlot = gCurrentSprite.spritesetGfxSlot;
        ramSlot = gCurrentSprite.primarySpriteRamSlot;
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;

        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_UP_5, gfxSlot, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_UP_4, gfxSlot, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_UP_3, gfxSlot, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_UP_2, gfxSlot, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_UP_1, gfxSlot, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_UP_JUNCTION, gfxSlot, ramSlot, yPosition, xPosition, 0);

        ScreenShakeStartVertical(TWO_THIRD_SECOND, 0x80 | 1);
        SoundPlay(SOUND_DEOREM_MOVING);
    }
}

/**
 * @brief 215e0 | e0 | Handles Deorem going up while spawning
 * 
 */
/*static*/ void DeoremSpawnGoingUp(void)
{
    u16 xPosition;
    u16 yPosition;
    u8 timer;

    yPosition = gBossWork.work1;
    xPosition = gCurrentSprite.xPosition;
    gCurrentSprite.yPosition -= DEOREM_SPAWNING_SPEED;

    if (gCurrentSprite.work0 <= CONVERT_SECONDS(.25f))
    {
        timer = gCurrentSprite.work0;
        DeoremSpriteDebrisSpawn(yPosition + BLOCK_SIZE, xPosition, timer);
        if (timer == CONVERT_SECONDS(2.f / 15))
        {
            ParticleSet(yPosition + BLOCK_SIZE, xPosition, PE_TWO_MEDIUM_DUST);
        }
    }
    else
    {
        timer = SPAWN_GOING_UP_DURATION - gCurrentSprite.work0;
        DeoremSpriteDebrisSpawn(yPosition + BLOCK_SIZE * 6, xPosition, timer);
        if (timer == CONVERT_SECONDS(1.f / 15))
        {
            ParticleSet(yPosition + BLOCK_SIZE * 7, xPosition, PE_TWO_MEDIUM_DUST);
        }
    }

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.status = (gCurrentSprite.status & ~SPRITE_STATUS_Y_FLIP) | SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.pose = DEOREM_POSE_SPAWN_DELAY_BEFORE_HEAD_EMERGES;
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f);

        // Set X position in the middle of the body parts, that's where the head will be
        if (gBossWork.work3)
            gCurrentSprite.xPosition += DEOREM_WIDTH / 2;
        else
            gCurrentSprite.xPosition -= DEOREM_WIDTH / 2;

        ScreenShakeStartVertical(TWO_THIRD_SECOND, 0x80 | 1);
        SoundPlay(SOUND_DEOREM_MOVING);
    }
}

/**
 * @brief 216c0 | 117 | Handles Deorem waiting a bit before the head emerges during spawn
 * 
 */
/*static*/ void DeoremSpawnDelayBeforeHead(void)
{
    u8 gfxSlot;
    u8 ramSlot;
    u16 yPosition;
    u16 xPosition;
    u8 segmentESlot;
    u8 segmentDSlot;
    u8 segmentCSlot;
    u8 eyeSlot;

    if (MOD_AND(gCurrentSprite.work0, CONVERT_SECONDS(.5f + 1.f / 30)) == 0)
        DeoremRandomSpriteDebris(gCurrentSprite.work0);

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = DEOREM_POSE_SPAWN_HEAD_EMERGES;
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6 + 1.f / 60);
        
        gfxSlot = gCurrentSprite.spritesetGfxSlot;
        ramSlot = gCurrentSprite.primarySpriteRamSlot;
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;

        segmentESlot = SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_NECK_2, gfxSlot, ramSlot, yPosition, xPosition, 0);
        segmentDSlot = SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_NECK_1, gfxSlot, ramSlot, yPosition, xPosition, 0);
        segmentCSlot = SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_NECK_JUNCTION, gfxSlot, ramSlot, yPosition, xPosition, 0);

        gSpriteData[segmentDSlot].work0 = segmentCSlot;
        gSpriteData[segmentESlot].work0 = segmentDSlot;

        eyeSlot = SpriteSpawnSecondary(SSPRITE_DEOREM_EYE, 0, gfxSlot, ramSlot,
            yPosition - DEOREM_EYE_Y_OFFSET, xPosition - DEOREM_EYE_X_OFFSET, 0);

        if (eyeSlot == UCHAR_MAX)
            gCurrentSprite.status = 0;
        else
            gCurrentSprite.work3 = eyeSlot;
    }
}

/**
 * @brief 217d4 | ac | Handles the head spawning part
 * 
 */
/*static*/ void DeoremSpawnHead(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.work3;

    if (MOD_AND(gFrameCounter8Bit, CONVERT_SECONDS(.5f + 1.f / 30)) == 0)
        DeoremRandomSpriteDebris(gFrameCounter8Bit);

    // Move down until the head reaches the designated offset
    if (gCurrentSprite.yPosition < gCurrentSprite.yPositionSpawn + DEOREM_HEAD_Y_OFFSET)
    {
        gCurrentSprite.yPosition += EIGHTH_BLOCK_SIZE;
        return;
    }

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);

    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = DEOREM_POSE_MAIN;

        if (gDifficulty == DIFF_EASY)
            gCurrentSprite.work0 = CONVERT_SECONDS(1.5f);
        else if (gDifficulty == DIFF_HARD)
            gCurrentSprite.work0 = CONVERT_SECONDS(.5f + 1.f / 15);
        else
            gCurrentSprite.work0 = CONVERT_SECONDS(1.f);

        gCurrentSprite.pOam = sDeoremOam_Opening;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.hitboxBottom = 0;
        
        gSpriteData[ramSlot].status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;

        SoundPlay(SOUND_DEOREM_OPENING_JAW);
    }
}

/**
 * @brief 21880 | 284 | Handles deorem being idle and the down attack 
 * 
 */
/*static*/ void DeoremMainLoop(void)
{
    u16 movement;
    u16 yRange;
    u32 eyeSlot;
    u16 health;

    eyeSlot = gCurrentSprite.work3;
    health = gSpriteData[eyeSlot].health;

    if (gCurrentSprite.work0 != 0 && !(gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN))
    {
        if (!DeoremCheckLeaving(gCurrentSprite.work3))
        {
            if (gCurrentSprite.pOam == sDeoremOam_Closing)
            {
                if (SpriteUtilHasCurrentAnimationEnded())
                {
                    gCurrentSprite.pOam = sDeoremOam_ClosedFast;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
            }
            else if (gCurrentSprite.pOam == sDeoremOam_Opening)
            {
                if (SpriteUtilHasCurrentAnimationEnded())
                {
                    gCurrentSprite.pOam = sDeoremOam_OpenedFast;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
            }                

            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (gCurrentSprite.work0 == 0)
            {
                SpriteUtilMakeSpriteFaceSamusDirection();
                gCurrentSprite.pOam = sDeoremOam_Warning;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
                SoundPlay(SOUND_DEOREM_WARNING);
                gCurrentSprite.rotation = FALSE;
            
                if (health == DEOREM_MAX_HEALTH)
                {
                    // Still at full health, force going straight down
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                    gCurrentSprite.work0 = CONVERT_SECONDS(2.f / 15);
                }
                else if (gCurrentSprite.xPosition - DEOREM_DIAGONAL_ATTACK_RANGE < gSamusData.xPosition &&
                         gCurrentSprite.xPosition + DEOREM_DIAGONAL_ATTACK_RANGE > gSamusData.xPosition)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                    gCurrentSprite.work0 = CONVERT_SECONDS(2.f / 15);
                }
                else
                {
                    gCurrentSprite.work1 = 0;
                    gCurrentSprite.work2 = 1;
                    gCurrentSprite.scaling = gSamusData.xPosition;
        
                    ScreenShakeStartVertical(ONE_THIRD_SECOND, 0x80 | 1);
                }
            }
            else if (gCurrentSprite.work0 == CONVERT_SECONDS(.35f + 1.f / 30) && gCurrentSprite.pOam == sDeoremOam_OpenedFast)
            {
                gCurrentSprite.pOam = sDeoremOam_Closing;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.hitboxBottom = BLOCK_SIZE;
    
                gSpriteData[eyeSlot].status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                SoundPlay(SOUND_DEOREM_CLOSING_JAW);
            }
        }
    }
    else
    {
        if (gCurrentSprite.pOam == sDeoremOam_Warning)
        {
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
                {
                    gCurrentSprite.pOam = sDeoremOam_GoingDown;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    return;
                }

                gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
            }
    
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
            {
                yRange = DEOREM_HEIGHT - (BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE + PIXEL_SIZE);
                if (health == DEOREM_MAX_HEALTH)
                    movement = DEOREM_ATTACK_SPEED_Y;
                else
                    movement = DEOREM_ATTACK_SPEED_Y * 1.5;
            
                if (gCurrentSprite.work0 != 0)
                {
                    gCurrentSprite.yPosition -= movement;
                    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
                    if (gCurrentSprite.work0 == 0)
                        ScreenShakeStartVertical(ONE_THIRD_SECOND, 0x80 | 1);
                    return;
                }
            }
            else
            {
                DeoremMoveDiagonallyX(QUARTER_BLOCK_SIZE + PIXEL_SIZE, gCurrentSprite.scaling);
                yRange = DEOREM_HEIGHT - (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE);
                movement = DEOREM_ATTACK_SPEED_Y;
            }

            if (gCurrentSprite.yPosition < gCurrentSprite.yPositionSpawn + yRange)
            {
                gCurrentSprite.yPosition += movement;
                if (gCurrentSprite.rotation)
                    return;

                // Played sound flag
                gCurrentSprite.rotation++;
                
                if (movement > EIGHTH_BLOCK_SIZE)
                    SoundPlay(SOUND_DEOREM_MOVEMENT_SMALL);
                else
                    SoundPlay(SOUND_DEOREM_MOVEMENT_LONG);
            }
            else
            {
                gCurrentSprite.pose = DEOREM_POSE_RETRACTING;
                gCurrentSprite.work0 = CONVERT_SECONDS(.5f);

                gCurrentSprite.pOam = sDeoremOam_Opening;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.hitboxBottom = 0;
            
                gSpriteData[eyeSlot].status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
                SoundPlay(SOUND_DEOREM_OPENING_JAW);
            }
        }
    }
}

/**
 * @brief 21b04 | 16c | Handles Deorem retracting after going down to attack
 * 
 */
/*static*/ void DeoremRetracting(void)
{
    u16 eyeSlot = gCurrentSprite.work3;
    u16 health = gSpriteData[eyeSlot].health;

    if (gCurrentSprite.work0 != 0)
    {
        if (gCurrentSprite.pOam == sDeoremOam_Opening && SpriteUtilHasCurrentAnimationEnded())
        {
            gCurrentSprite.pOam = sDeoremOam_OpenedFast;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.hitboxLeft = -(BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE;
        }

        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 > CONVERT_SECONDS(.4f))
        {
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN))
                DeoremMoveDiagonallyX(QUARTER_BLOCK_SIZE, gSamusData.xPosition);
        }
        else if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            SoundPlay(SOUND_DEOREM_RETRACTED);
        }
    }
    else
    {
        gCurrentSprite.yPosition -= DEOREM_ATTACK_SPEED_Y;
        if (gCurrentSprite.yPosition < gCurrentSprite.yPositionSpawn + DEOREM_HEAD_Y_OFFSET)
        {
            gCurrentSprite.hitboxLeft = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE;
            gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn + DEOREM_HEAD_Y_OFFSET;
        
            if (DeoremCheckLeaving(eyeSlot))
                return;

            if (health == DEOREM_MAX_HEALTH || gSpriteRng >= SPRITE_RNG_PROB(.6875f) || health <= DEOREM_MAX_HEALTH / 3)
            {
                if (gBossWork.work3)
                {
                    if (gCurrentSprite.xPositionSpawn - DEOREM_WIDTH / 2 <= gSamusData.xPosition)
                        gCurrentSprite.pose = DEOREM_POSE_THORNS_DOWN_SEGMENT;
                    else
                        gCurrentSprite.pose = DEOREM_POSE_THORNS_UP_SEGMENT;
                }
                else
                {
                    if (gCurrentSprite.xPositionSpawn + DEOREM_WIDTH / 2 > gSamusData.xPosition)
                        gCurrentSprite.pose = DEOREM_POSE_THORNS_DOWN_SEGMENT;
                    else
                        gCurrentSprite.pose = DEOREM_POSE_THORNS_UP_SEGMENT;
                }

                gCurrentSprite.work0 = CONVERT_SECONDS(4.25f);
                gCurrentSprite.rotation = 0;
            }
            else
            {
                gCurrentSprite.pose = DEOREM_POSE_MAIN;
                DeoremSetEyeOpeningTimer();
            }
        }
    }
}

/**
 * @brief 21c70 | f4 | Handles Deorem throwing thorns (doesn't handle the thorn throwing, just the idle state)
 * 
 */
/*static*/ void DeoremThrowingThorns(void)
{
    u8 changeAnimTime;

    u32 eyeSlot = gCurrentSprite.work3;
    u16 health = gSpriteData[eyeSlot].health;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    changeAnimTime = CONVERT_SECONDS(3.f + 5.f / 6);
    if (health > DEOREM_MAX_HEALTH / 3)
    {
        if (health <= DEOREM_MAX_HEALTH / 3 * 2)
            changeAnimTime = CONVERT_SECONDS(3.5f);
        else
            changeAnimTime = CONVERT_SECONDS(.5f);
    }

    if (MOD_AND(gCurrentSprite.rotation, CONVERT_SECONDS(.25f + 1.f / 60)) == 0)
        SoundPlay(SOUND_DEOREM_THROWING_THORNS);

    APPLY_DELTA_TIME_INC(gCurrentSprite.rotation);

    if (gCurrentSprite.work0 < changeAnimTime)
    {
        if (gCurrentSprite.pOam == sDeoremOam_OpenedFast)
        {
            gCurrentSprite.pOam = sDeoremOam_Closing;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.hitboxBottom = BLOCK_SIZE;
            gSpriteData[eyeSlot].status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            SoundPlay(SOUND_DEOREM_CLOSING_JAW);
        }
        else if (gCurrentSprite.pOam == sDeoremOam_Closing && SpriteUtilHasCurrentAnimationEnded())
        {
            gCurrentSprite.pOam = sDeoremOam_ClosedFast;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }

        if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.pose = DEOREM_POSE_AFTER_THORNS;
            gCurrentSprite.work0 = CONVERT_SECONDS(1.f);
        }
    }
}

/**
 * @brief 21d64 | 4c | Called after the last thorn is thrown and before it hits the ground
 * 
 */
/*static*/ void DeoremAfterThorns(void)
{
    if (gCurrentSprite.pOam == sDeoremOam_Closing && SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pOam = sDeoremOam_ClosedFast;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = DEOREM_POSE_MAIN;
        DeoremSetEyeOpeningTimer();
    }
}

/**
 * @brief 21db0 | 78 | Intiializes deorem to be dying
 * 
 */
/*static*/ void DeoremDyingInit(void)
{
    gCurrentSprite.pOam = sDeoremOam_Dying;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = DEOREM_POSE_DYING_GOING_DOWN;
    gCurrentSprite.invincibilityStunFlashTimer |= CONVERT_SECONDS(1.85f + 1.f / 60);

    DeoremChangeLeftWallClipdata(CAA_REMOVE_SOLID);
    DeoremChangeRightWallClipdata(CAA_REMOVE_SOLID);

    gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;
    EventFunction(EVENT_ACTION_SETTING, EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED);
    EventFunction(EVENT_ACTION_SETTING, EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED);

    if (gCurrentSprite.spriteId == PSPRITE_DEOREM_SECOND_LOCATION)
        EventFunction(EVENT_ACTION_SETTING, EVENT_DEOREM_KILLED_AT_SECOND_LOCATION);

    SoundPlay(SOUND_DEOREM_DYING);
    FadeCurrentMusicAndQueueNextMusic(CONVERT_SECONDS(5.f / 6), MUSIC_BRINSTAR, 0);
}

/**
 * @brief 21e28 | 4c | Handles Deorem dying
 * 
 */
/*static*/ void DeoremDying(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gCurrentSprite.yPosition < gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE)
    {
        gCurrentSprite.yPosition += PIXEL_SIZE;
    }
    else
    {
        gCurrentSprite.pose = DEOREM_POSE_DEATH;
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f);
        SPRITE_CLEAR_ISFT(gCurrentSprite);
        gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }
}

/**
 * @brief 21e74 | 38 | Calls Sprite Death
 * 
 */
/*static*/ void DeoremDeath(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition + BLOCK_SIZE,
            FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}

/**
 * @brief 21eac | 60 | Checks if the leaving to the ceiling animation has ended
 *
 */
/*static*/ void DeoremWaitToLeave(void)
{
    if (gCurrentSprite.pOam == sDeoremOam_Closing || gCurrentSprite.pOam == sDeoremOam_ClosedFast)
    {
        if (SpriteUtilHasCurrentAnimationEnded())
        {
            gCurrentSprite.pOam = sDeoremOam_ClosedSlow;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
    else if (gCurrentSprite.pOam == sDeoremOam_ClosedSlow)
    {
        gCurrentSprite.pose = DEOREM_POSE_START_LEAVING;
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f);
        gCurrentSprite.rotation = 0;
    }
}

/**
 * @brief 21f0c | 180 | Handles Deorem starting to leave the fight
 * 
 */
/*static*/ void DeoremStartLeaving(void)
{
    u8 i;
    u8 timer;
    u8 gfxSlot;
    u8 ramSlot;
    u16 yPosition;
    u16 xPosition;

    if (gCurrentSprite.yPosition > gCurrentSprite.yPositionSpawn - BLOCK_SIZE)
    {
        gCurrentSprite.yPosition -= PIXEL_SIZE;
        return;
    }

    // Wait for all drops to despawn/be taken before leaving
    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (!(gSpriteData[i].status & SPRITE_STATUS_EXISTS))
            continue;

        if (gSpriteData[i].properties & SP_SECONDARY_SPRITE)
            continue;

        if (gSpriteData[i].spriteId == PSPRITE_LARGE_ENERGY_DROP ||
            gSpriteData[i].spriteId == PSPRITE_SMALL_ENERGY_DROP ||
            gSpriteData[i].spriteId == PSPRITE_MISSILE_DROP ||
            gSpriteData[i].spriteId == PSPRITE_SUPER_MISSILE_DROP ||
            gSpriteData[i].spriteId == PSPRITE_POWER_BOMB_DROP)
        {
            return;
        }
    }

    if (gCurrentSprite.work0 != 0)
    {
        timer = gCurrentSprite.work0;
        DeoremSpriteDebrisSpawn(gBossWork.work1 - HALF_BLOCK_SIZE, gBossWork.work2 + DEOREM_WIDTH / 2, timer);

        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);

        if (gCurrentSprite.work0 == 0)
        {
            gSpriteData[gCurrentSprite.work3].status = 0;
        }
    }
    else
    {
        gCurrentSprite.xPosition = gBossWork.work2 + BLOCK_SIZE * 6 + HALF_BLOCK_SIZE;
        gCurrentSprite.pose = DEOREM_POSE_LEAVING;

        gfxSlot = gCurrentSprite.spritesetGfxSlot;
        ramSlot = gCurrentSprite.primarySpriteRamSlot;
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;

        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_LEAVING_3, gfxSlot, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_LEAVING_2, gfxSlot, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_LEAVING_1, gfxSlot, ramSlot, yPosition, xPosition, 0);

        DeoremChangeLeftWallClipdata(CAA_REMOVE_SOLID);
        DeoremChangeRightWallClipdata(CAA_REMOVE_SOLID);

        gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;

        if (gCurrentSprite.spriteId == PSPRITE_DEOREM_FIRST_LOCATION)
        {
            // Leaving first location
            EventFunction(EVENT_ACTION_SETTING, EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED);
            EventFunction(EVENT_ACTION_CLEARING, EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED);
        }
        else
        {
            // Leaving second location
            EventFunction(EVENT_ACTION_CLEARING, EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED);
            EventFunction(EVENT_ACTION_SETTING, EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED);
        }

        SoundPlay(SOUND_DEOREM_LEAVING);
        FadeCurrentMusicAndQueueNextMusic(CONVERT_SECONDS(5.f / 6), MUSIC_BRINSTAR, 0);
    }
}

/**
 * @brief 2208c | 64 | Handles Deorem leaving the fight
 * 
 */
/*static*/ void DeoremLeaving(void)
{
    if (MOD_AND(gFrameCounter8Bit, CONVERT_SECONDS(.25f + 1.f / 60)) == 0)
    {
        if (MOD_AND(gFrameCounter8Bit, CONVERT_SECONDS(.5f + 1.f / 30)) == 0)
            DeoremRandomSpriteDebris(gFrameCounter8Bit);

        ScreenShakeStartVertical(ONE_THIRD_SECOND, 0x80 | 1);
    }

    if (gCurrentSprite.yPosition < gCurrentSprite.yPositionSpawn + DEOREM_HEIGHT + BLOCK_SIZE)
    {
        gCurrentSprite.yPosition += QUARTER_BLOCK_SIZE;
    }
    else
    {
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = DEOREM_POSE_LEAVING_IN_GROUND;
        gCurrentSprite.work1 = CONVERT_SECONDS(4.f);
    }
}

/**
 * @brief 220f0 | 50 | Calls DeoremRandomSpriteDebris, starts a vertical screen shake
 * (Called when Deorem is leaving and it has its head on the ground)
 * 
 */
/*static*/ void DeoremLeavingInGroundDebris(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (MOD_AND(gFrameCounter8Bit, CONVERT_SECONDS(.25f + 1.f / 60)) == 0)
    {
        if (MOD_AND(gFrameCounter8Bit, CONVERT_SECONDS(.5f + 1.f / 30)) == 0)
            DeoremRandomSpriteDebris(gFrameCounter8Bit);

        ScreenShakeStartVertical(ONE_THIRD_SECOND, 0x80 | 1);
    }

    if (APPLY_DELTA_TIME_DEC(gCurrentSprite.work1) == 0)
    {
        gCurrentSprite.status = 0;
    }
}

/**
 * @brief 22140 | 21c | Initialize a Deorem segment sprite
 * 
 */
/*static*/ void DeoremSegmentInit(void)
{
    u8 roomSlot;
    
    gCurrentSprite.frozenPaletteRowOffset = 1;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.health = 1;

    roomSlot = gCurrentSprite.roomSlot;

    switch (roomSlot)
    {
        case DEOREM_SEGMENT_DOWN_1:
        case DEOREM_SEGMENT_DOWN_5:
        case DEOREM_SEGMENT_UP_1:
        case DEOREM_SEGMENT_UP_5:
        case DEOREM_SEGMENT_NECK_1:
        case DEOREM_SEGMENT_LEAVING_3:
            gCurrentSprite.currentAnimationFrame = 1;
            break;
            
        case DEOREM_SEGMENT_DOWN_2:
        case DEOREM_SEGMENT_UP_2:
        case DEOREM_SEGMENT_NECK_JUNCTION:
        case DEOREM_SEGMENT_LEAVING_2:
        case DEOREM_SEGMENT_TAIL:
        case DEOREM_SEGMENT_19:
            gCurrentSprite.currentAnimationFrame = 2;
            break;

        case DEOREM_SEGMENT_DOWN_3:
        case DEOREM_SEGMENT_UP_3:
        case DEOREM_SEGMENT_LEAVING_1:
            gCurrentSprite.currentAnimationFrame = 3;
            break;

        case DEOREM_SEGMENT_DOWN_JUNCTION:
        case DEOREM_SEGMENT_DOWN_4:
        case DEOREM_SEGMENT_UP_4:
        case DEOREM_SEGMENT_NECK_2:
            gCurrentSprite.currentAnimationFrame = 0;
            break;
    }

    if (roomSlot == DEOREM_SEGMENT_TAIL)
    {
        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.hitboxBottom = BLOCK_SIZE + HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -THREE_QUARTER_BLOCK_SIZE;
        gCurrentSprite.hitboxRight = THREE_QUARTER_BLOCK_SIZE;

        gCurrentSprite.pOam = sDeoremSegmentOam_Tail;
    }
    else if (roomSlot == DEOREM_SEGMENT_DOWN_JUNCTION ||
             roomSlot == DEOREM_SEGMENT_UP_JUNCTION ||
             roomSlot == DEOREM_SEGMENT_NECK_JUNCTION)
    {
        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);

        gCurrentSprite.hitboxTop = -BLOCK_SIZE;
        gCurrentSprite.hitboxBottom = BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE;

        gCurrentSprite.pOam = sDeoremSegmentOam_Junction;
        gCurrentSprite.drawOrder = 11;
    }
    else
    {        
        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -BLOCK_SIZE;
        gCurrentSprite.hitboxBottom = BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE;

        gCurrentSprite.pOam = sDeoremSegmentOam_Middle;   
    }

    if (roomSlot == DEOREM_SEGMENT_DOWN_JUNCTION ||
        roomSlot == DEOREM_SEGMENT_DOWN_1 ||
        roomSlot == DEOREM_SEGMENT_DOWN_2 ||
        roomSlot == DEOREM_SEGMENT_DOWN_3 ||
        roomSlot == DEOREM_SEGMENT_DOWN_4 ||
        roomSlot == DEOREM_SEGMENT_DOWN_5)
    {
        gCurrentSprite.pose = DEOREM_SEGMENT_POSE_DOWN_SEGMENT_SPAWNING;
    }
    else if (roomSlot == DEOREM_SEGMENT_UP_JUNCTION ||
             roomSlot == DEOREM_SEGMENT_UP_1 ||
             roomSlot == DEOREM_SEGMENT_UP_2 ||
             roomSlot == DEOREM_SEGMENT_UP_3 ||
             roomSlot == DEOREM_SEGMENT_UP_4 ||
             roomSlot == DEOREM_SEGMENT_UP_5)
    {
        gCurrentSprite.pose = DEOREM_SEGMENT_POSE_UP_SEGMENT_SPAWNING;
        gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
    }
    else if (roomSlot == DEOREM_SEGMENT_NECK_JUNCTION ||
             roomSlot == DEOREM_SEGMENT_NECK_1 ||
             roomSlot == DEOREM_SEGMENT_NECK_2)
    {
        gCurrentSprite.pose = DEOREM_SEGMENT_POSE_NECK_SEGMENT_IDLE;
        gCurrentSprite.work1 = 0;
        gCurrentSprite.work2 = 1;
    }
    else if (roomSlot == DEOREM_SEGMENT_LEAVING_1 ||
             roomSlot == DEOREM_SEGMENT_LEAVING_2 ||
             roomSlot == DEOREM_SEGMENT_LEAVING_3)
    {
        gCurrentSprite.pose = DEOREM_SEGMENT_POSE_NECK_LEAVING;
        gCurrentSprite.drawOrder = 3;
        gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }
    else if (roomSlot == DEOREM_SEGMENT_TAIL)
    {
        gCurrentSprite.pose = DEOREM_SEGMENT_POSE_DOWN_SEGMENT_IDLE;
        gCurrentSprite.drawOrder = 3;
        gCurrentSprite.work2 = 28;
    }
    else if (roomSlot == DEOREM_SEGMENT_19)
    {
        gCurrentSprite.pose = DEOREM_SEGMENT_POSE_UP_SEGMENT_IDLE;
        gCurrentSprite.drawOrder = 3;
        gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
        gCurrentSprite.work2 = 28;
    }
    else
    {
        gCurrentSprite.status = 0;
    }
}

/**
 * @brief 2235c | 90 | Handles the movement of a "down" segment when spawning
 * 
 */
/*static*/ void DeoremSegmentSpawnGoingDown(void)
{
    u8 ramSlot;
    u32 tmp1;
    u32 tmp2;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_DOWN_JUNCTION)
    {
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - DEOREM_SEGMENT_PADDING;
    }
    else
    {
        tmp1 = gSpriteData[ramSlot].yPosition - DEOREM_SEGMENT_PADDING;
        tmp2 = gCurrentSprite.roomSlot * DEOREM_SEGMENT_SPACING;
        gCurrentSprite.yPosition = tmp2;
        gCurrentSprite.yPosition = (tmp2 = tmp1) - gCurrentSprite.yPosition;
    }

    if (gSpriteData[ramSlot].pose == DEOREM_POSE_SPAWN_DELAY_BEFORE_GOING_UP)
    {
        gCurrentSprite.pose = DEOREM_SEGMENT_POSE_DOWN_SEGMENT_AFTER_SPAWNING;
        gCurrentSprite.work0 = CONVERT_SECONDS(.1f);

        if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_DOWN_JUNCTION)
        {
            gCurrentSprite.pOam = sDeoremSegmentOam_Middle;
            gCurrentSprite.drawOrder = 4;
        }
    }
}

/**
 * @brief 223ec | 9c80 | Handles the spawning movement of a "down" segment while the "up" segments are spawning
 * 
 */
/*static*/ void DeoremSegmentSpawnGoingDownAfter(void)
{
    u8 ramSlot;
    u16 movement;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    movement = DEOREM_SPAWNING_SPEED;
    if (gSpriteData[ramSlot].pose == DEOREM_POSE_SPAWN_HEAD_EMERGES)
        movement /= 2;
    gCurrentSprite.yPosition += movement;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.work0 = DEOREM_SEGMENT_SPACING / movement;
        gCurrentSprite.yPosition -= movement * gCurrentSprite.work0;
        gCurrentSprite.currentAnimationFrame++;
        if (gCurrentSprite.currentAnimationFrame > 3)
            gCurrentSprite.currentAnimationFrame = 0;
    }

    if (gSpriteData[ramSlot].pose == DEOREM_POSE_MAIN)
    {
        gCurrentSprite.work2 = gCurrentSprite.roomSlot * 4;
        gCurrentSprite.pose = DEOREM_SEGMENT_POSE_DOWN_SEGMENT_IDLE;
        if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_DOWN_5)
        {
            SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_TAIL,
                gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition - DEOREM_SEGMENT_SPACING, gCurrentSprite.xPosition, 0);
        }
    }
}

/**
 * @brief 224b4 | 90 | Handles the movement of a "up" segment when spawning
 * 
 */
/*static*/ void DeoremSegmentSpawnGoingUp(void)
{
    u8 ramSlot;
    s32 yPosition;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    
    if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_UP_JUNCTION)
    {
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition + DEOREM_SEGMENT_PADDING;
    }
    else
    {
        yPosition = gSpriteData[ramSlot].yPosition + DEOREM_SEGMENT_PADDING;
        gCurrentSprite.yPosition = yPosition + (gCurrentSprite.roomSlot - 6) * DEOREM_SEGMENT_SPACING;
    }

    if (gSpriteData[ramSlot].pose == DEOREM_POSE_SPAWN_DELAY_BEFORE_HEAD_EMERGES)
    {
        gCurrentSprite.pose = DEOREM_SEGMENT_POSE_UP_SEGMENT_AFTER_SPAWNING;
        gCurrentSprite.work0 = 6;

        if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_UP_JUNCTION)
        {
            gCurrentSprite.pOam = sDeoremSegmentOam_Middle;
            gCurrentSprite.drawOrder = 4;
        }
    }
}

/**
 * @brief 22544 | c8 | Handles the spawning movement of a "up" segment while the "neck" segments are spawning
 * 
 */
/*static*/ void DeoremSegmentSpawnGoingUpAfter(void)
{
    u32 ramSlot;
    s32 movement;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    movement = DEOREM_SPAWNING_SPEED;
    if (gSpriteData[ramSlot].pose == DEOREM_POSE_SPAWN_HEAD_EMERGES)
        movement /= 2;
    gCurrentSprite.yPosition -= movement;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.work0 = DEOREM_SEGMENT_SPACING / movement;
        gCurrentSprite.yPosition += movement * gCurrentSprite.work0;

        gCurrentSprite.currentAnimationFrame++;
        if (gCurrentSprite.currentAnimationFrame > 3)
            gCurrentSprite.currentAnimationFrame = 0;
    }

    if (gSpriteData[ramSlot].pose == DEOREM_POSE_MAIN)
    {
        gCurrentSprite.work2 = (gCurrentSprite.roomSlot - DEOREM_SEGMENT_UP_JUNCTION) * 4;
        gCurrentSprite.pose = DEOREM_SEGMENT_POSE_UP_SEGMENT_IDLE;
        if (gCurrentSprite.roomSlot == 11)
        {
            SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, DEOREM_SEGMENT_19,
                gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition + DEOREM_SEGMENT_SPACING, gCurrentSprite.xPosition, 0);
            
        }
    }
}

/**
 * @brief 2260c | 144 | Handles a "down" segment being idle
 * 
 */
/*static*/ void DeoremSegmentDownIdle(void)
{
    u8 ramSlot;
    u8 deoremTimer;
    u16 spritesetGfxSlot;
    u16 primarySpriteRamSlot;
    u16 yPosition;
    u16 xPosition;
    u16 statusToAdd;
    u32 xMovement;
    u32 index;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    deoremTimer = gSpriteData[ramSlot].work0;
    
    if (deoremTimer != 0)
    {
        if (gSpriteData[ramSlot].pose == DEOREM_POSE_THORNS_DOWN_SEGMENT)
        {            
            APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);
            APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);
            APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);
            APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);

            spritesetGfxSlot = gCurrentSprite.spritesetGfxSlot;
            primarySpriteRamSlot = gCurrentSprite.primarySpriteRamSlot;
            yPosition = gCurrentSprite.yPosition + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

            if (gBossWork.work3)
            {
                xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE);
                statusToAdd = 0;
            }
            else
            {
                xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE + HALF_BLOCK_SIZE);
                statusToAdd = SPRITE_STATUS_X_FLIP;
            }
    
            if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_DOWN_1 && deoremTimer == DEOREM_THORN_TIMING_1)
            {
                SpriteSpawnSecondary(SSPRITE_DEOREM_THORN, 0,
                    spritesetGfxSlot, primarySpriteRamSlot,
                    yPosition, xPosition, statusToAdd);
            }
            else if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_DOWN_2 && deoremTimer == DEOREM_THORN_TIMING_2)
            {
                SpriteSpawnSecondary(SSPRITE_DEOREM_THORN, 1,
                    spritesetGfxSlot, primarySpriteRamSlot,
                    yPosition, xPosition, statusToAdd);
            }
            else if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_DOWN_3 && deoremTimer == DEOREM_THORN_TIMING_3)
            {
                SpriteSpawnSecondary(SSPRITE_DEOREM_THORN, 2,
                    spritesetGfxSlot, primarySpriteRamSlot,
                    yPosition, xPosition, statusToAdd);
            }
            else if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_DOWN_4 && deoremTimer == DEOREM_THORN_TIMING_4)
            {
                SpriteSpawnSecondary(SSPRITE_DEOREM_THORN, 3,
                    spritesetGfxSlot, primarySpriteRamSlot,
                    yPosition, xPosition, statusToAdd);
            }
        }
        else
        {            
            index = gCurrentSprite.work2;
            xMovement = sDeoremSegmentXVelocity[index];
            if (xMovement == SHORT_MAX)
            {
                xMovement = sDeoremSegmentXVelocity[0];
                index = 0;
            }
            gCurrentSprite.work2 = index + 1;
            gCurrentSprite.xPosition += xMovement;
        }
    }
    else
    {
        if (gSpriteData[ramSlot].pose == DEOREM_POSE_MAIN)
        {
            gCurrentSprite.pose = DEOREM_SEGMENT_POSE_GOING_DOWN;
            gCurrentSprite.work0 = CONVERT_SECONDS(.4f + 1.f / 60);
        }
        else if (gSpriteData[ramSlot].pose == DEOREM_POSE_RETRACTING)
        {
            gCurrentSprite.pose = DEOREM_SEGMENT_POSE_GOING_UP;
            gCurrentSprite.work0 = CONVERT_SECONDS(.4f + 1.f / 60);
        }
        else if (gSpriteData[ramSlot].pose == DEOREM_POSE_LEAVING)
        {
            gCurrentSprite.pose = DEOREM_SEGMENT_POSE_DOWN_DESPAWN;
            gCurrentSprite.work0 = TWO_THIRD_SECOND + CONVERT_SECONDS(.1f);
        }
    }
}

/**
 * @brief 22750 | 144 | Handles the idle animation and the thorn throwing of the segments on the left side
 * 
 */
/*static*/ void DeoremSegmentUpIdle(void)
{
    u16 yPosition;
    u8 ramSlot;
    u8 deoremTimer;
    u16 spritesetGfxSlot;
    u16 primarySpriteRamSlot;
    u16 xPosition;
    u16 statusToAdd;
    u32 xVelocity;
    u32 index;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    deoremTimer = gSpriteData[ramSlot].work0;
    
    if (deoremTimer != 0)
    {
        if (gSpriteData[ramSlot].pose == DEOREM_POSE_THORNS_UP_SEGMENT)
        {
            APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);
            APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);
            APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);
            APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);

            spritesetGfxSlot = gCurrentSprite.spritesetGfxSlot;
            primarySpriteRamSlot = gCurrentSprite.primarySpriteRamSlot;
            yPosition = gCurrentSprite.yPosition;
            
            if (gBossWork.work3)
            {
                xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE + HALF_BLOCK_SIZE);
                statusToAdd = SPRITE_STATUS_X_FLIP;
            }
            else
            {
                xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE);
                statusToAdd = 0;
            }
    
            if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_UP_4 && deoremTimer == DEOREM_THORN_TIMING_1)
            {
                SpriteSpawnSecondary(SSPRITE_DEOREM_THORN, 0,
                    spritesetGfxSlot, primarySpriteRamSlot,
                    yPosition, xPosition, statusToAdd);
            }
            else if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_UP_3 && deoremTimer == DEOREM_THORN_TIMING_2)
            {
                SpriteSpawnSecondary(SSPRITE_DEOREM_THORN, 1,
                    spritesetGfxSlot, primarySpriteRamSlot,
                    yPosition, xPosition, statusToAdd);
            }
            else if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_UP_2 && deoremTimer == DEOREM_THORN_TIMING_3)
            {
                SpriteSpawnSecondary(SSPRITE_DEOREM_THORN, 2,
                    spritesetGfxSlot, primarySpriteRamSlot,
                    yPosition, xPosition, statusToAdd);
            }
            else if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_UP_1 && deoremTimer == DEOREM_THORN_TIMING_4)
            {
                SpriteSpawnSecondary(SSPRITE_DEOREM_THORN, 3,
                    spritesetGfxSlot, primarySpriteRamSlot,
                    yPosition, xPosition, statusToAdd);
            }
        }
        else
        {
            index = gCurrentSprite.work2;
            xVelocity = sDeoremSegmentXVelocity[index];
            if (xVelocity == SHORT_MAX)
            {
                xVelocity = sDeoremSegmentXVelocity[0];
                index = 0;
            }
            gCurrentSprite.work2 = index + 1;
            gCurrentSprite.xPosition += xVelocity;
        }
    }
    else
    {
        if (gSpriteData[ramSlot].pose == DEOREM_POSE_MAIN)
        {
            gCurrentSprite.pose = DEOREM_SEGMENT_POSE_GOING_UP;
            gCurrentSprite.work0 = CONVERT_SECONDS(.4f + 1.f / 60);
        }
        else if (gSpriteData[ramSlot].pose == DEOREM_POSE_RETRACTING)
        {
            gCurrentSprite.pose = DEOREM_SEGMENT_POSE_GOING_DOWN;
            gCurrentSprite.work0 = CONVERT_SECONDS(.4f + 1.f / 60);
        }
        else if (gSpriteData[ramSlot].pose == DEOREM_POSE_LEAVING)
        {
            gCurrentSprite.pose = DEOREM_SEGMENT_POSE_UP_LEAVING;
            gCurrentSprite.work0 = CONVERT_SECONDS(.1f);
            gCurrentSprite.work1 = CONVERT_SECONDS(1.25f + 1.f / 60);
        }
    }
}

/**
 * @brief 22894 | 8c | Handles the segments going down when Deorem is going down
 * 
 */
/*static*/ void DeoremSegmentGoingDown(void)
{
    u32 xMovement;
    u32 work2;
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.work0 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        gCurrentSprite.yPosition += PIXEL_SIZE;
    }

    if (gSpriteData[ramSlot].work0 != 0)
    {
        if (gCurrentSprite.roomSlot < DEOREM_SEGMENT_UP_JUNCTION || gCurrentSprite.roomSlot == DEOREM_SEGMENT_TAIL)
            gCurrentSprite.pose = DEOREM_SEGMENT_POSE_DOWN_SEGMENT_IDLE;
        else
            gCurrentSprite.pose = DEOREM_SEGMENT_POSE_UP_SEGMENT_IDLE;
    }
            
    work2 = gCurrentSprite.work2;
    xMovement = sDeoremSegmentXVelocity[work2];
    if (xMovement == SHORT_MAX)
    {
        xMovement = sDeoremSegmentXVelocity[0];
        work2 = 0;
    }
    gCurrentSprite.work2 = work2 + 1;
    gCurrentSprite.xPosition += xMovement;
}

/**
 * @brief 22920 | 8c | Handles the segments going up when Deorem is going down
 * 
 */
/*static*/ void DeoremSegmentGoingUp(void)
{
    u32 xMovement;
    u32 work2;
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.work0 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        gCurrentSprite.yPosition -= PIXEL_SIZE;
    }

    if (gSpriteData[ramSlot].work0 != 0)
    {
        if (gCurrentSprite.roomSlot < DEOREM_SEGMENT_UP_JUNCTION || gCurrentSprite.roomSlot == DEOREM_SEGMENT_TAIL)
            gCurrentSprite.pose = DEOREM_SEGMENT_POSE_DOWN_SEGMENT_IDLE;
        else
            gCurrentSprite.pose = DEOREM_SEGMENT_POSE_UP_SEGMENT_IDLE;
    }
            
    work2 = gCurrentSprite.work2;
    xMovement = sDeoremSegmentXVelocity[work2];
    if (xMovement == SHORT_MAX)
    {
        xMovement = sDeoremSegmentXVelocity[0];
        work2 = 0;
    }
    gCurrentSprite.work2 = work2 + 1;
    gCurrentSprite.xPosition += xMovement;
}

/**
 * @brief 229ac | b4 | Handles a "neck" part being idle
 * 
 */
/*static*/ void DeoremSegmentNeckIdle(void)
{
    u16 deoremXPos;
    u16 xPosition;
    u16 posOffset;
    u16 movement;
    s32 yPosition;
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_NECK_JUNCTION)
    {
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - DEOREM_SEGMENT_PADDING;
        deoremXPos = gSpriteData[ramSlot].xPosition;
    }
    else
    {
        yPosition = gSpriteData[ramSlot].yPosition - DEOREM_SEGMENT_PADDING;
        gCurrentSprite.yPosition = yPosition - (gCurrentSprite.roomSlot - DEOREM_SEGMENT_NECK_JUNCTION) * DEOREM_SEGMENT_SPACING;
        deoremXPos = gSpriteData[gCurrentSprite.work0].xPosition;
    }

    xPosition = gCurrentSprite.xPosition;

    if (xPosition > deoremXPos)
        posOffset = xPosition - deoremXPos;
    else
        posOffset = deoremXPos - xPosition;

    if (posOffset <= PIXEL_SIZE / 2)
        movement = ONE_SUB_PIXEL;
    else
        movement = posOffset / 4;

    if (xPosition < deoremXPos)
        gCurrentSprite.xPosition += movement;
    else if (xPosition > deoremXPos)
        gCurrentSprite.xPosition -= movement;
    
    if (gSpriteData[ramSlot].pose == DEOREM_POSE_LEAVING)
    {
        gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;
        gCurrentSprite.pose = DEOREM_SEGMENT_POSE_NECK_LEAVING;
    }
}

/**
 * @brief 22a60 | b4 | Handles an "up" segment leaving
 * 
 */
/*static*/ void DeoremSegmentUpLeaving(void)
{
    gCurrentSprite.yPosition -= DEOREM_LEAVING_SPEED;

    if (APPLY_DELTA_TIME_DEC(gCurrentSprite.work0) == 0)
    {
        gCurrentSprite.work0 = CONVERT_SECONDS(.1f);
        gCurrentSprite.yPosition += BLOCK_SIZE + HALF_BLOCK_SIZE;

        gCurrentSprite.currentAnimationFrame++;
        if (gCurrentSprite.currentAnimationFrame > 3)
            gCurrentSprite.currentAnimationFrame = 0;

        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_19)
            {
                gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
                gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
                gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
                
                gCurrentSprite.hitboxTop = -THREE_QUARTER_BLOCK_SIZE;
                gCurrentSprite.hitboxBottom = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
                gCurrentSprite.hitboxLeft = -BLOCK_SIZE;
                gCurrentSprite.hitboxRight = BLOCK_SIZE;

                gCurrentSprite.pOam = sDeoremSegmentOam_Tail;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                gCurrentSprite.work0 = CONVERT_SECONDS(.95f - 1.f / 60);
            }
            else
            {
                gCurrentSprite.work0 = CONVERT_SECONDS(.75f + 1.f / 60);
            }

            gCurrentSprite.pose = DEOREM_SEGMENT_POSE_UP_DESPAWN;
        }
    }
    
    if (gCurrentSprite.work1 != 0)
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work1);
}

/**
 * @brief 22b14 | 28 | Handles an "up" segment despawning when leaving
 * 
 */
/*static*/ void DeoremSegmentUpDespawn(void)
{
    gCurrentSprite.yPosition -= DEOREM_LEAVING_SPEED;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
        gCurrentSprite.status = 0;
}

/**
 * @brief 22b3c | 28 | Handles a "down" segment despawning when leaving
 * 
 */
/*static*/ void DeoremSegmentDownDespawn(void)
{
    gCurrentSprite.yPosition += DEOREM_LEAVING_SPEED;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
        gCurrentSprite.status = 0;
}

/**
 * @brief 22b64 | 90 | Handles a "neck" segment leaving
 * 
 */
/*static*/ void DeoremSegmentNeckLeaving(void)
{
    u8 ramSlot;
    s32 yPosition;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_NECK_JUNCTION)
    {
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - DEOREM_SEGMENT_PADDING;
    }
    else
    {
        yPosition = gSpriteData[ramSlot].yPosition - DEOREM_SEGMENT_PADDING;
        gCurrentSprite.yPosition = yPosition - (gCurrentSprite.roomSlot - 12) * DEOREM_SEGMENT_SPACING;
    }

    if (gSpriteData[ramSlot].pose == DEOREM_POSE_LEAVING_IN_GROUND)
    {
        gCurrentSprite.pose = DEOREM_SEGMENT_POSE_NECK_BURROW;
        gCurrentSprite.work0 = CONVERT_SECONDS(.1f);
        gCurrentSprite.work1 = ONE_THIRD_SECOND;

        if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_NECK_JUNCTION)
            gCurrentSprite.pOam = sDeoremSegmentOam_Middle;
    }
}

/**
 * @brief 22bf4 | a0 | Handles a "neck" segment burrowing into the ground when leaving
 * 
 */
/*static*/ void DeoremSegmentNeckBurrow(void)
{
    gCurrentSprite.yPosition += DEOREM_LEAVING_SPEED;

    if (APPLY_DELTA_TIME_DEC(gCurrentSprite.work0) == 0)
    {
        gCurrentSprite.work0 = CONVERT_SECONDS(.1f);
        gCurrentSprite.yPosition -= BLOCK_SIZE + HALF_BLOCK_SIZE;
        gCurrentSprite.currentAnimationFrame++;
        if (gCurrentSprite.currentAnimationFrame > 3)
            gCurrentSprite.currentAnimationFrame = 0;

        if (APPLY_DELTA_TIME_DEC(gCurrentSprite.work1) == 0)
        {
            if (gCurrentSprite.roomSlot == DEOREM_SEGMENT_LEAVING_3)
            {
                gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
                gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
                gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
                
                gCurrentSprite.hitboxTop = -THREE_QUARTER_BLOCK_SIZE;
                gCurrentSprite.hitboxBottom = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
                gCurrentSprite.hitboxLeft = -BLOCK_SIZE;
                gCurrentSprite.hitboxRight = BLOCK_SIZE;

                gCurrentSprite.pOam = sDeoremSegmentOam_Tail;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }

            gCurrentSprite.pose = DEOREM_SEGMENT_POSE_NECK_DESPAWN;
            gCurrentSprite.work0 = TWO_THIRD_SECOND + CONVERT_SECONDS(.1f);
        }
    }
}

/**
 * @brief 22c94 | 28 | Handles a "neck" segment despawning when leaving
 * 
 */
/*static*/ void DeoremSegmentNeckDespawn(void)
{
    gCurrentSprite.yPosition += DEOREM_LEAVING_SPEED;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
        gCurrentSprite.status = 0;
}

/**
 * @brief 22cbc | f8 | Initializes a deorem segment to be dying
 * 
 */
/*static*/ void DeoremSegmentDyingInit(void)
{
    u8 timer;

    timer = CONVERT_SECONDS(.1f);

    switch (gCurrentSprite.roomSlot)
    {
        case DEOREM_SEGMENT_NECK_1:
            timer *= 2;
            break;

        case DEOREM_SEGMENT_NECK_2:
            timer *= 3;
            break;

        case DEOREM_SEGMENT_UP_JUNCTION:
            timer *= 4;
            break;
       
        case DEOREM_SEGMENT_UP_1:
            timer *= 5;
            break;

        case DEOREM_SEGMENT_UP_2:
            timer *= 6;
            break;

        case DEOREM_SEGMENT_UP_3:
            timer *= 7;
            break;

        case DEOREM_SEGMENT_UP_4:
            timer *= 8;
            break;

        case DEOREM_SEGMENT_UP_5:
            timer *= 9;
            break;

        case DEOREM_SEGMENT_19:
            timer *= 10;
            break;

         case DEOREM_SEGMENT_DOWN_JUNCTION:
            timer *= 11;
            break;

        case DEOREM_SEGMENT_DOWN_1:
            timer *= 12;
            break;

        case DEOREM_SEGMENT_DOWN_2:
            timer *= 13;
            break;

        case DEOREM_SEGMENT_DOWN_3:
            timer *= 14;
            break;

        case DEOREM_SEGMENT_DOWN_4:
            timer *= 15;
            break;

        case DEOREM_SEGMENT_DOWN_5:
            timer *= 16;
            break;

        case DEOREM_SEGMENT_TAIL:
            timer *= 17;
            break;
    }

    gCurrentSprite.work0 = CONVERT_SECONDS(1.f) + timer;

    gCurrentSprite.pose = DEOREM_SEGMENT_POSE_DYING;
    SPRITE_CLEAR_ISFT(gCurrentSprite);
    gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
}

/**
 * @brief 22db4 | 94 | Handles the death of a Deorem segment
 * 
 */
/*static*/ void DeoremSegmentDying(void)
{
    u16 xPosition;
    u16 yPosition;
    s32 newXPos;
    u16 roomSlot;
    u8 rng;
    u8 randomMovement;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    xPosition = gCurrentSprite.xPosition;
    roomSlot = gCurrentSprite.roomSlot;
    rng = gSpriteRng;
    randomMovement = rng * (PIXEL_SIZE / 2);

    if (roomSlot >= DEOREM_SEGMENT_NECK_JUNCTION)
        randomMovement += THREE_QUARTER_BLOCK_SIZE;

    if (roomSlot % 2)
        newXPos = xPosition + randomMovement + roomSlot;
    else
        newXPos = xPosition - (randomMovement + roomSlot);
    xPosition = newXPos;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        yPosition = gCurrentSprite.yPosition;
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, xPosition, FALSE, PE_SPRITE_EXPLOSION_BIG);

        if (yPosition > gBossWork.work1 + BLOCK_SIZE * 7 || yPosition < gBossWork.work1 + BLOCK_SIZE * 2)
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 22e48 | e0 | Initialize a Deorem eye sprite
 * 
 */
/*static*/ void DeoremEyeInit(void)
{
    gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING_WHOLE;
    gCurrentSprite.scaling = Q_8_8(1.f);
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawOrder = 11;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = THREE_QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

    gCurrentSprite.pOam = sDeoremEyeOam_Pulsing;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.frozenPaletteRowOffset = 4;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pose = DEOREM_EYE_POSE_IDLE_INIT;

    // Duration of the fight
    gCurrentSprite.yPositionSpawn = CONVERT_SECONDS(30.f);

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED) &&
        !EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED))
    {
        // Half the time if it's the first encounter
        gCurrentSprite.yPositionSpawn /= 2;
    }

    if (gCurrentSprite.xPosition > gSamusData.xPosition)
    {
        gCurrentSprite.rotation = PI;
        gCurrentSprite.work0 = PI;
    }
    else
    {
        gCurrentSprite.rotation = 0;
        gCurrentSprite.work0 = 0;
    }
    
    gCurrentSprite.work2 = 0;
}

/**
 * @brief 22f28 | 10 | Initializes the Deorem eye to be idle
 * 
 */
/*static*/ void DeoremEyeIdleInit(void)
{
    gCurrentSprite.pose = DEOREM_EYE_POSE_IDLE;
}

/**
 * @brief 22f38 | 19c | Handles the movement of the eye
 * 
 */
/*static*/ void DeoremEyeMove(void)
{
    u8 ramSlot;
    s32 samusY;
    s32 samusX;
    s32 spriteY;
    s32 spriteX;
    s32 targetRotation;
    s32 rotation;
    u32 deltaRotation;
    s32 temp;

    deltaRotation = PI / 64;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    rotation = gCurrentSprite.work0;
    samusY = (s16)(gSamusData.yPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE));
    samusX = (s16)gSamusData.xPosition;
    spriteY = (s16)gSpriteData[ramSlot].yPosition;
    spriteX = (s16)gSpriteData[ramSlot].xPosition;

    if (samusY < spriteY)
    {
        if (spriteX - BLOCK_SIZE < samusX && spriteX + BLOCK_SIZE > samusX)
            targetRotation = PI + PI_2;

        if (samusX > spriteX)
        {
            if (spriteY - samusY < BLOCK_SIZE)
                targetRotation = 0;
            else
                targetRotation = PI + PI_3_4;
        }
        else
        {
            if (spriteY - samusY < BLOCK_SIZE)
                targetRotation = PI;
            else
                targetRotation = PI + PI_4;
        }
    }
    else
    {
        if (spriteX - BLOCK_SIZE < samusX && spriteX + BLOCK_SIZE > samusX)
        {
            targetRotation = PI_2;
        }
        else
        {
            if (samusX > spriteX)
            {
                if (samusY - spriteY < BLOCK_SIZE)
                    targetRotation = 0;
                else
                    targetRotation = PI_4;
            }
            else
            {
                if (samusY - spriteY < BLOCK_SIZE)
                    targetRotation = PI;
                else
                    targetRotation = PI_3_4;
            }
        }
    }

    if (targetRotation == 0)
    {
        if ((u16)(rotation - 1) < PI - 1)
            rotation = (s16)(rotation - deltaRotation);
        else if (rotation >= PI)
            rotation = (s16)(rotation + deltaRotation);
    }
    else if (targetRotation == PI_4)
    {
        if ((u16)(rotation - PI_4 - 1) < PI - 1)
            rotation = (s16)(rotation - deltaRotation);
        else if ((u16)(rotation - PI_4) >= PI)
            rotation = (s16)(rotation + deltaRotation);
    }
    else if (targetRotation == PI_2)
    {
        if ((u16)(rotation - PI_2 - 1) < PI - 1)
            rotation = (s16)(rotation - deltaRotation);
        else if ((u16)(rotation - PI_2) >= PI)
            rotation = (s16)(rotation + deltaRotation);
    }
    else if (targetRotation == PI_3_4)
    {
        if ((u16)(rotation - PI_3_4 - 1) < PI - 1)
            rotation = (s16)(rotation - deltaRotation);
        else if ((u16)(rotation - PI_3_4) >= PI)
            rotation = (s16)(rotation + deltaRotation);
    }
    else if (targetRotation == PI)
    {
        if ((u16)(rotation - 1) < PI - 1)
            rotation = (s16)(rotation + deltaRotation);
        else if (rotation > PI)
            rotation = (s16)(rotation - deltaRotation);
    }
    else if (targetRotation == PI + PI_4)
    {
        if ((u16)(rotation - PI_4 - 1) < PI - 1)
            rotation = (s16)(rotation + deltaRotation);
        else if ((u16)(rotation - PI_4 - 1) >= PI)
            rotation = (s16)(rotation - deltaRotation);
    }
    else if (targetRotation == PI + PI_2)
    {
        if ((u16)(rotation - PI_2 - 1) < PI - 1)
            rotation = (s16)(rotation + deltaRotation);
        else if ((u16)(rotation - PI_2 - 1) >= PI)
            rotation = (s16)(rotation - deltaRotation);
    }
    else if (targetRotation == PI + PI_3_4)
    {
        if ((u16)(rotation - PI_3_4 - 1) < PI - 1)
            rotation = (s16)(rotation + deltaRotation);
        else if ((u16)(rotation - PI_3_4 - 1) >= PI)
            rotation = (s16)(rotation - deltaRotation);
    }

    gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - DEOREM_EYE_Y_OFFSET;
    gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition - DEOREM_EYE_X_OFFSET;
    gCurrentSprite.work0 = rotation;
    gCurrentSprite.rotation = rotation;
}

/**
 * @brief 230d4 | 9c | Main loop for the deorem eye
 * 
 */
/*static*/ void DeoremEyeIdle(void)
{
    u8 rng;

    if (gCurrentSprite.pOam == sDeoremEyeOam_Pulsing)
    {
        if (SpriteUtilHasCurrentAnimationEnded())
        {
            rng = gSpriteRng;
            
            if (rng < SPRITE_RNG_PROB(.625f))
            {
                gCurrentSprite.pOam = sDeoremEyeOam_Idle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.work2 = (rng + CONVERT_SECONDS(2.f / 15)) * CONVERT_SECONDS(1.f / 15);
            }
        }
    }
    else if (gCurrentSprite.work2 != 0 && APPLY_DELTA_TIME_DEC(gCurrentSprite.work2) == 0)
    {
        gCurrentSprite.pOam = sDeoremEyeOam_Pulsing;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    DeoremEyeMove();

    // Update fight duration timer
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED) ||
        EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED) ||
        gCurrentSprite.health != DEOREM_MAX_HEALTH)
    {   
        // Timer only goes down if Deorem has been hit
        if (gCurrentSprite.yPositionSpawn != 0)
            APPLY_DELTA_TIME_DEC(gCurrentSprite.yPositionSpawn);
    }
}

/**
 * @brief 23170 | 38 | Initialize the Gfx for the eye dying (also sets Deorem pose to 62)
 * 
 */
/*static*/ void DeoremEyeDyingInit(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    gSpriteData[ramSlot].pose = SPRITE_POSE_DESTROYED;
    gCurrentSprite.pose = DEOREM_EYE_POSE_DYING_SPINNING;
    gCurrentSprite.pOam = sDeoremEyeOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 231a8 | 80 | Handles the eye spinning when Deorem is dying (body still here)
 * 
 */
/*static*/ void DeoremEyeDyingSpinning(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    
    gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - (DEOREM_EYE_Y_OFFSET - PIXEL_SIZE);
    gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition - DEOREM_EYE_X_OFFSET;

    if (gSpriteData[ramSlot].pose == DEOREM_POSE_DEATH && gSpriteData[ramSlot].work0 <= CONVERT_SECONDS(.5f))
        gCurrentSprite.rotation += PI / 16;
    else
        gCurrentSprite.rotation += PI / 32;
    
    if (gSpriteData[ramSlot].pose == DEOREM_POSE_DEATH && gSpriteData[ramSlot].work0 < 2)
    {
        gCurrentSprite.pose = DEOREM_EYE_POSE_DYING_MOVING;
        gCurrentSprite.work0 = CONVERT_SECONDS(2.f);
    }
}

/**
 * @brief 23228 | b0 | Handles the eye spinning and moving when Deorem is dying (body dying/not here)
 * 
 */
/*static*/ void DeoremEyeDyingMoving(void)
{
    u16 targetX;
    u8 timer;

    gCurrentSprite.rotation += PI / 16 + PI / 32;
    if (gCurrentSprite.work0 < CONVERT_SECONDS(1.f) + TWO_THIRD_SECOND)
        gCurrentSprite.yPosition -= ONE_SUB_PIXEL;

    targetX = gBossWork.work2 + DEOREM_WIDTH / 2;
    if (gCurrentSprite.xPosition < targetX - DEOREM_EYE_DYING_SPEED)
        gCurrentSprite.xPosition += DEOREM_EYE_DYING_SPEED;
    else if (gCurrentSprite.xPosition > targetX + DEOREM_EYE_DYING_SPEED)
        gCurrentSprite.xPosition -= DEOREM_EYE_DYING_SPEED;

    timer = APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (MOD_AND(timer, CONVERT_SECONDS(1.f / 15)) == 0)
    {
        if (MOD_BLOCK_AND(timer, CONVERT_SECONDS(1.f / 15)) != 0)
        {
            gCurrentSprite.paletteRow = SPRITE_GET_STUN_PALETTE(gCurrentSprite);
        }
        else
        {
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
            if (timer == 0)
            {
                gCurrentSprite.status = 0;
                DeoremSpawnChargeBeam(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
                SoundPlay(SOUND_DEOREM_SPAWNING_CHARGE_BEAM);
            }
        }
    }
}

/**
 * @brief 232d8 | dc | Initialize a Deorem thorn sprite
 * 
 */
/*static*/ void DeoremThornInit(void)
{
    gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING_SINGLE;
    
    gCurrentSprite.scaling = Q_8_8(1.f);
    gCurrentSprite.rotation = 0;
    
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    
    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    
    gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE - PIXEL_SIZE);
    gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE - PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
    
    gCurrentSprite.pOam = sDeoremThornOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.work3 = ONE_THIRD_SECOND;
    gCurrentSprite.pose = DEOREM_THORN_POSE_SPAWNING;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.rotation = PI;
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.rotation = 0;
    }

    gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
    
    gCurrentSprite.yPosition -= EIGHTH_BLOCK_SIZE + PIXEL_SIZE;
}

/**
 * @brief 233b4 | 70 | Handles the spinning animation when the thorn is spawning, before is moves
 * 
 */
/*static*/ void DeoremThornSpawning(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work3);
    if (gCurrentSprite.work3 == 0)
    {
        gCurrentSprite.pose = DEOREM_THORN_POSE_MOVING;
        SoundPlay(SOUND_DEOREM_THORN_EJECTING);
    }

    // Alternate between being in front and behind the deorem segments
    if (gCurrentSprite.work3 % CONVERT_SECONDS(1.f / 30))
        gCurrentSprite.drawOrder = 5;
    else
        gCurrentSprite.drawOrder = 3;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.rotation += PI_4;
    else
        gCurrentSprite.rotation -= PI_4;
}

/**
 * @brief 23424 | fc | Handles the movement of the Deorem thorn
 * 
 */
/*static*/ void DeoremThornMovement(void)
{
    u8 offset;
    u16 xMovement;
    s32 movement;

    offset = gCurrentSprite.work3;
    movement = sDeoremThornYVelocity[offset];
    
    if (movement == SHORT_MAX)
    {
        movement = sDeoremThornYVelocity[offset - 1];
        gCurrentSprite.yPosition += movement;
    }
    else
    {
        offset++;
        gCurrentSprite.work3 = offset;
        gCurrentSprite.yPosition += movement;
    }

    xMovement = PIXEL_SIZE;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (offset >= 36)
        {
            gCurrentSprite.rotation = PI + PI_4 + PI * .1875f;
        }
        else if (offset >= 33)
        {
            gCurrentSprite.rotation = PI + PI_4 + PI / 8;
        }
        else if (offset >= 29)
        {
            if (gCurrentSprite.rotation >= PI + PI_4)
                gCurrentSprite.rotation = PI + PI_4;
            else
                gCurrentSprite.rotation += PI / 16;
        }
        else
        {
            gCurrentSprite.rotation += PI / 8;
        }

        gCurrentSprite.xPosition += xMovement;
    }
    else
    {
        if (offset >= 36)
        {
            gCurrentSprite.rotation = PI + PI_2 + PI / 16;
        }
        else if (offset >= 33)
        {
            gCurrentSprite.rotation = PI + PI_2 + PI / 8;
        }
        else if (offset >= 29)
        {
            if (gCurrentSprite.rotation <= PI + PI_3_4)
                gCurrentSprite.rotation = PI + PI_3_4;
            else
                gCurrentSprite.rotation -= PI / 16;
        }
        else
        {
            gCurrentSprite.rotation -= PI / 8;
        }
        
        gCurrentSprite.xPosition -= xMovement;
    }

    if (offset > 32)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck != COLLISION_AIR)
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 23520 | 238 | Deorem AI
 * 
 */
void Deorem(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            DeoremInit();
            break;

        case DEOREM_POSE_WAITING_FOR_FIGHT:
            DeoremWaitingForFight();
            break;

        case DEOREM_POSE_SPAWN_GOING_DOWN:
            DeoremSpawnGoingDown();
            break;

        case DEOREM_POSE_SPAWN_DELAY_BEFORE_GOING_UP:
            DeoremSpawnDelayBeforeGoingUp();
            break;

        case DEOREM_POSE_SPAWN_GOING_UP:
            DeoremSpawnGoingUp();
            break;

        case DEOREM_POSE_SPAWN_DELAY_BEFORE_HEAD_EMERGES:
            DeoremSpawnDelayBeforeHead();
            break;

        case DEOREM_POSE_SPAWN_HEAD_EMERGES:
            DeoremSpawnHead();
            break;

        case DEOREM_POSE_MAIN:
            DeoremMainLoop();
            break;

        case DEOREM_POSE_RETRACTING:
            DeoremRetracting();
            break;

        case DEOREM_POSE_THORNS_DOWN_SEGMENT:
        case DEOREM_POSE_THORNS_UP_SEGMENT:
            DeoremThrowingThorns();
            break;

        case DEOREM_POSE_AFTER_THORNS:
            DeoremAfterThorns();
            break;

        case SPRITE_POSE_DESTROYED:
            DeoremDyingInit();

        case DEOREM_POSE_DYING_GOING_DOWN:
            DeoremDying();
            break;

        case DEOREM_POSE_DEATH:
            DeoremDeath();
            break;

        case DEOREM_POSE_WAIT_TO_LEAVE:
            DeoremWaitToLeave();
            break;

        case DEOREM_POSE_START_LEAVING:
            DeoremStartLeaving();
            break;

        case DEOREM_POSE_LEAVING:
            DeoremLeaving();
            break;

        case DEOREM_POSE_LEAVING_IN_GROUND:
            DeoremLeavingInGroundDebris();
            break;

        case DEOREM_POSE_CALL_SPAWN_CHARGE_BEAM:
            DeoremCallSpawnChargeBeam();
    }
}

/**
 * @brief 23758 | 2c8 | Deorem segment AI
 * 
 */
void DeoremSegment(void)
{
    u32 ramSlot = gCurrentSprite.primarySpriteRamSlot;
    u8 deoremAbsolutePaletteRow;

    if (gSpriteData[ramSlot].pose >= SPRITE_POSE_DESTROYED)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        if (gSpriteData[ramSlot].pose == DEOREM_POSE_DEATH && gCurrentSprite.pose < SPRITE_POSE_DESTROYED)
            gCurrentSprite.pose = SPRITE_POSE_DESTROYED;
    }

    deoremAbsolutePaletteRow = gSpriteData[ramSlot].absolutePaletteRow;
    if (deoremAbsolutePaletteRow == 2)
        gCurrentSprite.absolutePaletteRow = deoremAbsolutePaletteRow;

    if (gSpriteData[ramSlot].paletteRow == SPRITE_GET_STUN_PALETTE(gSpriteData[ramSlot]))
    {
        gCurrentSprite.paletteRow = SPRITE_GET_STUN_PALETTE(gCurrentSprite);
        APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);
    }
    else if (gSpriteData[ramSlot].paletteRow == gSpriteData[ramSlot].absolutePaletteRow)
    {
        gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            DeoremSegmentInit();
            break;

        case DEOREM_SEGMENT_POSE_DOWN_SEGMENT_SPAWNING:
            DeoremSegmentSpawnGoingDown();
            break;

        case DEOREM_SEGMENT_POSE_DOWN_SEGMENT_AFTER_SPAWNING:
            DeoremSegmentSpawnGoingDownAfter();
            break;

        case DEOREM_SEGMENT_POSE_DOWN_SEGMENT_IDLE:
            DeoremSegmentDownIdle();
            break;

        case DEOREM_SEGMENT_POSE_UP_SEGMENT_SPAWNING:
            DeoremSegmentSpawnGoingUp();
            break;

        case DEOREM_SEGMENT_POSE_UP_SEGMENT_AFTER_SPAWNING:
            DeoremSegmentSpawnGoingUpAfter();
            break;

        case DEOREM_SEGMENT_POSE_UP_SEGMENT_IDLE:
            DeoremSegmentUpIdle();
            break;

        case DEOREM_SEGMENT_POSE_GOING_DOWN:
            DeoremSegmentGoingDown();
            break;

        case DEOREM_SEGMENT_POSE_GOING_UP:
            DeoremSegmentGoingUp();
            break;

        case DEOREM_SEGMENT_POSE_NECK_SEGMENT_IDLE:
            DeoremSegmentNeckIdle();
            break;

        case SPRITE_POSE_DESTROYED:
            DeoremSegmentDyingInit();

        case DEOREM_SEGMENT_POSE_DYING:
            DeoremSegmentDying();
            break;

        case DEOREM_SEGMENT_POSE_UP_LEAVING:
            DeoremSegmentUpLeaving();
            break;

        case DEOREM_SEGMENT_POSE_UP_DESPAWN:
            DeoremSegmentUpDespawn();
            break;

        case DEOREM_SEGMENT_POSE_DOWN_DESPAWN:
            DeoremSegmentDownDespawn();
            break;

        case DEOREM_SEGMENT_POSE_NECK_LEAVING:
            DeoremSegmentNeckLeaving();
            break;

        case DEOREM_SEGMENT_POSE_NECK_BURROW:
            DeoremSegmentNeckBurrow();
            break;

        case DEOREM_SEGMENT_POSE_NECK_DESPAWN:
            DeoremSegmentNeckDespawn();
            break;
    }
}

/**
 * @brief 23a20 | e0 | Deorem Eye
 * 
 */
void DeoremEye(void)
{
    u8 ramSlot;
    u8 isft;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    if (gCurrentSprite.pose < DEOREM_EYE_POSE_DYING_MOVING)
    {
        ramSlot = gCurrentSprite.primarySpriteRamSlot;
        isft = SPRITE_GET_ISFT(gCurrentSprite);
        if (isft && gSpriteData[ramSlot].pose < SPRITE_POSE_DESTROYED)
        {
            gSpriteData[ramSlot].invincibilityStunFlashTimer = gCurrentSprite.invincibilityStunFlashTimer;
            if (isft == CONVERT_SECONDS(.25f + 1.f / 60))
            {
                gSpriteData[ramSlot].pOam = sDeoremOam_ClosedFast;
                gSpriteData[ramSlot].animationDurationCounter = 0;
                gSpriteData[ramSlot].currentAnimationFrame = 0;

                gSpriteData[ramSlot].hitboxBottom = BLOCK_SIZE;
                if (gCurrentSprite.health <= DEOREM_MAX_HEALTH / 3)
                    gSpriteData[ramSlot].absolutePaletteRow = 2;

                gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                SoundPlay(SOUND_DEOREM_CLOSING_JAW_FAST);
            }
        }
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            DeoremEyeInit();
            break;

        case DEOREM_EYE_POSE_IDLE_INIT:
            DeoremEyeIdleInit();
            break;

        case DEOREM_EYE_POSE_IDLE:
            DeoremEyeIdle();
            break;

        case SPRITE_POSE_DESTROYED:
            DeoremEyeDyingInit();

        case DEOREM_EYE_POSE_DYING_SPINNING:
            DeoremEyeDyingSpinning();
            break;

        case DEOREM_EYE_POSE_DYING_MOVING:
            DeoremEyeDyingMoving();
    }
}

/**
 * @brief 23b00 | 4c | Deorem Thorn AI
 * 
 */
void DeoremThorn(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            DeoremThornInit();
            
        case DEOREM_THORN_POSE_SPAWNING:
            DeoremThornSpawning();
            break;

        case DEOREM_THORN_POSE_MOVING:
            DeoremThornMovement();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
    }
}
