#include "macros.h"
#include "sprites_AI/acid_worm.h"

#include "data/sprites/acid_worm.h"
#include "data/sprite_data.h"
#include "data/generic_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/clipdata.h"
#include "structs/connection.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/samus.h"
#include "structs/sprite.h"
#include "structs/scroll.h"

// Acid worm

#define ACID_WORM_EXTENDING_SPEED (PIXEL_SIZE / 2)

// Acid worm body

enum AcidWormPartPart {
    ACID_WORM_PART_MAIN,
    ACID_WORM_PART_AROUND_MOUTH,
    ACID_WORM_PART_WEAK_POINT,
    ACID_WORM_PART_BELOW_WEAK_POINT,
    ACID_WORM_PART_ABOVE_SEGMENTS,
    ACID_WORM_PART_SEGMENT1,
    ACID_WORM_PART_SEGMENT2,
    ACID_WORM_PART_SEGMENT3,
    ACID_WORM_PART_SEGMENT4,
    ACID_WORM_PART_SEGMENT5
};

#define ACID_WORM_PART_POSE_IDLE 0x9
#define ACID_WORM_PART_POSE_MOVING 0x43
#define ACID_WORM_PART_POSE_DYING 0x67

#define ACID_WORM_PART_ROTATION_OFFSET (0.0625f)

// Acid worm spit

#define ACID_WORM_SPIT_MOVING 0x9
#define ACID_WORM_SPIT_POSE_EXPLODING 0x43
#define ACID_WORM_SPIT_POSE_EXPLODING_ON_ACID 0x45

enum AcidWormSpitBehavior {
    ACID_WORM_SPIT_BEHAVIOR_MIDDLE,
    ACID_WORM_SPIT_BEHAVIOR_FAR,
    ACID_WORM_SPIT_BEHAVIOR_CLOSE,
};

#define ACID_WORM_SPAWN_RANGE (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE - PIXEL_SIZE)

/**
 * @brief 3d860 | 118 | Handles the rotation on the half-half circle of every part
 * 
 */
static void AcidWormHandleRotation(void)
{
    s32 offset;
    u8 arrayOffset;
    s32 posOffset;
    s32 positionOffset;
    s32 position;
    s32 sine;
    s32 sine_;
    s32 temp;
    s32 c;
    u8 angle;
    
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        angle = gCurrentSprite.rotation + PI;
    else
        angle = gCurrentSprite.rotation;

    if (gSubSpriteData1.work3 == TRUE)
        offset = PI * 3;
    else
        offset = PI * 2;

    arrayOffset = gCurrentSprite.work3;
    sine = sAcidWormSwingingMovement[arrayOffset];
    if (sine == SHORT_MAX)
    {
        sine = sAcidWormSwingingMovement[0];
        arrayOffset = 0;
    }
    gCurrentSprite.work3 = arrayOffset + 1;

    if (gCurrentSprite.health != 0)
        posOffset = (s16)(offset + MUL_SHIFT(sine, 4) * (gCurrentSprite.roomSlot / 4 + 1));
    else
        posOffset = (s16)(offset + sine * 16);

    temp = sine_ = SIN(angle);
    if (temp < 0)
    {
        temp = Q_8_8_TO_S16(-temp * posOffset);
        gCurrentSprite.yPosition = gSubSpriteData1.yPosition - temp;
    }
    else
    {
        temp = Q_8_8_TO_S16(sine_ * posOffset);
        gCurrentSprite.yPosition = gSubSpriteData1.yPosition + temp;
    }

    c = COS(angle);
    position = (s16)gSubSpriteData1.xPosition;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        position = (s16)(position + offset);
    else
        position = (s16)(position - offset);

    if (c < 0)
    {
        c = Q_8_8_TO_S16(-c * posOffset);
        gCurrentSprite.xPosition = position - c;
    }
    else
    {
        c = Q_8_8_TO_S16(c * posOffset);
        gCurrentSprite.xPosition = position + c;
    }
}

/**
 * @brief 3d978 | 40 | Handles the semi movement horizontal wiggle movement
 * 
 */
static void AcidWormWiggleHorizontally(void)
{
    s32 movement;
    u8 offset;

    offset = gCurrentSprite.work2;
    movement = sAcidWormHeadRandomXVelocity[offset];
    if (movement == SHORT_MAX)
    {
        movement = sAcidWormHeadRandomXVelocity[20]; // -1
        offset = 20;
    }

    gCurrentSprite.work2 = offset + 1;
    gCurrentSprite.xPosition += movement;
}

/**
 * @brief 3d9b8 | 48 | Updates the clipdata of the 2 blocks on the ground
 * 
 * @param caa Clipdata affecting action
 * @param yPosition Y Position
 * @param xPosition X Position
 */
static void AcidWormChangeTwoGroundCcaa(u8 caa, u16 yPosition, u16 xPosition)
{
    // Left block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition - HALF_BLOCK_SIZE);

    // Right block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition + HALF_BLOCK_SIZE);
}

/**
 * @brief 3da50 | 58 | Updates the clipdata of the first 2 blocks of the big block on the ground
 * 
 * @param caa Clipdata affecting action
 */
static void AcidWormChangeBigBlockDownCcaa(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    // Spawn position, corresponds to where the sprite is placed in the room (big block, bottom left)
    yPosition = gCurrentSprite.yPositionSpawn;
    xPosition = gCurrentSprite.xPositionSpawn;

    // Left block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - HALF_BLOCK_SIZE);

    // Right block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + HALF_BLOCK_SIZE);

    // Play particle effect if acid worm is dying
    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ACID_WORM_KILLED))
        ParticleSet(yPosition - BLOCK_SIZE, xPosition - QUARTER_BLOCK_SIZE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
}

/**
 * @brief 3da50 | 58 | Updates the clipdata of the 2 middle blocks of the big block on the ground
 * 
 * @param caa Clipdata affecting action
 */
static void AcidWormChangeBigBlockMiddleCcaa(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPositionSpawn - BLOCK_SIZE;
    xPosition = gCurrentSprite.xPositionSpawn;

    // Left block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - HALF_BLOCK_SIZE);

    // Right block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + HALF_BLOCK_SIZE);

    // Play particle effect if acid worm is dying
    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ACID_WORM_KILLED))
        ParticleSet(yPosition - BLOCK_SIZE, xPosition + QUARTER_BLOCK_SIZE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
}

/**
 * @brief 3daa8 | e4 | Updates the clipdata of the 2 top blocks of the big block on the ground
 * 
 * @param caa Clipdata affecting action
 */
static void AcidWormChangeBigBlockTopCcaa(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPositionSpawn - (BLOCK_SIZE * 2);
    xPosition = gCurrentSprite.xPositionSpawn;

    // Left block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - HALF_BLOCK_SIZE);

    // Right block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + HALF_BLOCK_SIZE);

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ACID_WORM_KILLED))
        return;

    // If acid worm dying, play effects
    ParticleSet(yPosition - BLOCK_SIZE, xPosition - (EIGHTH_BLOCK_SIZE), PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);

    yPosition -= BLOCK_SIZE * 2;

    SpriteDebrisInit(0, 0x11, yPosition - (BLOCK_SIZE + ONE_SUB_PIXEL * 2), xPosition - HALF_BLOCK_SIZE);
    SpriteDebrisInit(0, 0x12, yPosition, xPosition - (THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE));

    SpriteDebrisInit(0, 0x13, yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE - PIXEL_SIZE), xPosition - (BLOCK_SIZE - ONE_SUB_PIXEL * 2));
    SpriteDebrisInit(0, 4, yPosition, xPosition - HALF_BLOCK_SIZE);

    SpriteDebrisInit(0, 0x11, yPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE), xPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE + ONE_SUB_PIXEL * 2));
    SpriteDebrisInit(0, 0x12, yPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE - PIXEL_SIZE), xPosition + HALF_BLOCK_SIZE);

    SpriteDebrisInit(0, 0x13, yPosition, xPosition + (BLOCK_SIZE + EIGHTH_BLOCK_SIZE));
    SpriteDebrisInit(0, 4, yPosition - (BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE - PIXEL_SIZE), xPosition + (THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE));
}

/**
 * @brief 3db8c | 24 | Plays the retracting sound
 * 
 */
static void AcidWormPlayRetractingSound(void)
{
    if (gSubSpriteData1.work3 == FALSE)
    {
        // Extended into block
        SoundPlay(SOUND_ACID_WORM_RETRACT);
    }
    else
    {
        // Extended above block
        SoundPlay(SOUND_ACID_WORM_RETRACT_FROM_SPIT);
    }
}

/**
 * @brief 3dbb0 | 44 | Checks if the acid worm is colliding with samus when extending
 * 
 * @return u8 bool, colliding
 */
static u8 AcidWormCollidingWithSamusWhenExtending(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;

        gCurrentSprite.pOam = sAcidWormOam_MouthClosed;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = ACID_WORM_POSE_RETRACTING;

        AcidWormPlayRetractingSound();
        return TRUE;
    }

    return FALSE;
}

/**
 * @brief 3dbf4 | 224 | Initializes an acid worm sprite
 * 
 */
static void AcidWormInit(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;

    gCurrentSprite.hitboxTop = -THREE_QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = (THREE_QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    gCurrentSprite.hitboxLeft = -(THREE_QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = (THREE_QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);

    gCurrentSprite.pOam = sAcidWormOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    
    gCurrentSprite.samusCollision = SSC_ACID_WORM_MOUTH;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;

    gCurrentSprite.pose = ACID_WORM_POSE_CHECK_SAMUS_ON_ZIPLINE;
    gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN | SPRITE_STATUS_IGNORE_PROJECTILES;

    gCurrentSprite.work3 = 0;
    gCurrentSprite.work2 = 20;

    gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
    gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    gSubSpriteData1.yPosition = yPosition;
    gSubSpriteData1.xPosition = xPosition;
    gCurrentSprite.yPositionSpawn = yPosition;
    gCurrentSprite.xPositionSpawn = xPosition;

    gSubSpriteData1.work3 = FALSE;
    gSubSpriteData1.work2 = FALSE;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ACID_WORM_KILLED))
    {
        // Acid worm killed, remove block and bring liquid down
        gEffectYPositionOffset = BLOCK_SIZE * 9 + HALF_BLOCK_SIZE;

        AcidWormChangeBigBlockDownCcaa(CAA_REMOVE_SOLID);
        AcidWormChangeBigBlockMiddleCcaa(CAA_REMOVE_SOLID);
        AcidWormChangeBigBlockTopCcaa(CAA_REMOVE_SOLID);
        AcidWormChangeTwoGroundCcaa(CAA_REMOVE_SOLID, yPosition, xPosition);

        gCurrentSprite.status = 0;
        return;
    }

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
    {
        gCurrentSprite.status = 0; // No ziplines, kill sprite
        return;
    }

    LOCK_DOORS(); // Lock doors
    gSubSpriteData1.health = gCurrentSprite.yPositionSpawn - (BLOCK_SIZE * 2); // Acid base position
    gCurrentSprite.roomSlot = ACID_WORM_PART_MAIN;

    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    
    // Spawn body
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_PART, ACID_WORM_PART_AROUND_MOUTH,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 1, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_PART, ACID_WORM_PART_WEAK_POINT,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 2, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_PART, ACID_WORM_PART_BELOW_WEAK_POINT,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 3, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_PART, ACID_WORM_PART_ABOVE_SEGMENTS,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 4, xPosition, 0);

    // Spawn segments
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_PART, ACID_WORM_PART_SEGMENT1,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 5, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_PART, ACID_WORM_PART_SEGMENT2,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 6, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_PART, ACID_WORM_PART_SEGMENT3,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 7, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_PART, ACID_WORM_PART_SEGMENT4,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 8, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_ACID_WORM_PART, ACID_WORM_PART_SEGMENT5,
        gfxSlot, ramSlot, yPosition + BLOCK_SIZE * 9, xPosition, 0);
}

/**
 * @brief 3de18 | 20 | Checks if samus is on a zipline
 * 
 */
static void AcidWormCheckSamusOnZipline(void)
{
    if (SpriteUtilCheckOnZipline())
    {
        gCurrentSprite.pose = ACID_WORM_POSE_CHECK_SPAWN;
        FadeMusic(CONVERT_SECONDS(0.3f));
    }
}

/**
 * @brief 3de38 | 84 | Checks if the acid worm should spawn
 * 
 */
static void AcidWormSpawnStart(void)
{
    // On zipline
    if (!SpriteUtilCheckOnZipline())
        return;

    // In range
    if (gSamusData.xPosition > gCurrentSprite.xPositionSpawn - ACID_WORM_SPAWN_RANGE && 
        gSamusData.xPosition < gCurrentSprite.xPositionSpawn + ACID_WORM_SPAWN_RANGE)
    {
        // Set ignore projectiles
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        gSubSpriteData1.work2 = TRUE;
        gCurrentSprite.pose = ACID_WORM_POSE_SPAWN_EXTEND;
        gCurrentSprite.work0 = 0;

        // Destroy bottom
        AcidWormChangeBigBlockDownCcaa(CAA_REMOVE_SOLID);

        ScreenShakeStartVertical(CONVERT_SECONDS(1.f), 0x80 | 1);
        ScreenShakeStartHorizontal(CONVERT_SECONDS(1.f), 0x80 | 1);

        SoundPlay(SOUND_ACID_WORM_DESTROYING_BLOCKS);
        SoundPlay(SOUND_ACID_WORM_STRAIGHT_EXTEND);

        PlayMusic(MUSIC_WORMS_BATTLE, 0);
    }
}

/**
 * @brief 3debc | 90 | Handles the acid worm extending when spawning
 * 
 */
static void AcidWormSpawnExtending(void)
{
    u16 oldY;

    oldY = gCurrentSprite.yPosition;

    // Check if extended 7 blocks
    if (gCurrentSprite.yPosition < gCurrentSprite.yPositionSpawn - BLOCK_SIZE * 7)
    {
        gCurrentSprite.pose = ACID_WORM_POSE_SPAWN_ON_TOP;
        gCurrentSprite.pOam = sAcidWormOam_SpawnOnTop;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        SoundPlay(SOUND_ACID_WORM_SCREAM);
    }
    else
    {
        // Go up and play going out of acid effect
        gCurrentSprite.yPosition -= QUARTER_BLOCK_SIZE;
        if (SpriteUtilCheckOutOfRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE))
            SoundPlay(SOUND_ACID_WORM_SPLASHING);

        // Lower acid
        gEffectYPositionOffset += ONE_SUB_PIXEL;

        // Gradually destroy big block
        gCurrentSprite.work0++;
        if (gCurrentSprite.work0 == 4)
            AcidWormChangeBigBlockMiddleCcaa(CAA_REMOVE_SOLID);
        else if (gCurrentSprite.work0 == 8)
            AcidWormChangeBigBlockTopCcaa(CAA_REMOVE_SOLID);
    }
}

static void AcidWormSpawnStayingOnTop(void)
{
    // Idle movement
    AcidWormWiggleHorizontally();

    // Go down if anim ended
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = ACID_WORM_POSE_SPAWN_RETRACT;
        gCurrentSprite.pOam = sAcidWormOam_MouthClosed;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        SoundPlay(SOUND_ACID_WORM_STRAIGHT_GOING_DOWN);
    }
}

/**
 * @brief 3df84 | 80 | Handles the acid worm retracting when spawning
 * 
 */
static void AcidWormSpawnRetracting(void)
{
    u16 oldY;

    // Idle movement
    AcidWormWiggleHorizontally();

    // Check has reached bottom
    if (gCurrentSprite.yPosition >= gCurrentSprite.yPositionSpawn)
    {
        gCurrentSprite.pose = ACID_WORM_POSE_IDLE_INIT;

        // Enable rotation/scaling
        gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING_WHOLE;

        gCurrentSprite.scaling = Q_8_8(1.f);
        gCurrentSprite.rotation = 0;

        // Set timer before the acid worm tries to extend
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f);
    }
    else
    {
        oldY = gCurrentSprite.yPosition;

        // Go down
        gCurrentSprite.yPosition += QUARTER_BLOCK_SIZE;
        if (SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE))
            SoundPlay(SOUND_ACID_WORM_SPLASHING);

        // Check should rise liquid
        if (gEffectYPosition > gSubSpriteData1.health)
            gEffectYPositionOffset -= ONE_SUB_PIXEL;
    }
}

/**
 * @brief 3e004 | 2c | Initializes the acid worm to be idle
 * 
 */
static void AcidWormIdleInit(void)
{
    // Set idle
    gCurrentSprite.pOam = sAcidWormOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = ACID_WORM_POSE_IDLE;
    gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
}

/**
 * @brief 3e030 | c0 | Handles the idle animation and Samus detection
 * 
 */
static void AcidWormIdle(void)
{
    u32 samusY;
    u32 spritePos;

    if (gEffectYPosition > gSubSpriteData1.health)
        gEffectYPositionOffset -= ONE_SUB_PIXEL;

    samusY = gSamusData.yPosition;
    spritePos = gCurrentSprite.yPosition;
    
    if (samusY > gEffectYPosition || samusY > spritePos)
    {
        // If samus ever goes below the acid, or below the worm, restart the wait to extend
        // Otherwise the boss will do its extending attacks while Samus isn't even there
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f);
        return;
    }

    do {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 != 0)
            return;

        if (spritePos - samusY - (BLOCK_SIZE + QUARTER_BLOCK_SIZE + ONE_SUB_PIXEL) >= BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE - ONE_SUB_PIXEL)
            gSubSpriteData1.work3 = TRUE;
        else if (gSamusData.xPosition <= gCurrentSprite.xPositionSpawn - BLOCK_SIZE * 7)
            gSubSpriteData1.work3 = TRUE;
        else if (gSamusData.xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 7)
            gSubSpriteData1.work3 = FALSE;
        else
            gSubSpriteData1.work3 = TRUE;

        // This is needed for the code to match, might be a debug leftover like a print or something
        gSubSpriteData1.health += 0;
    } while(0);

    gCurrentSprite.pOam = sAcidWormOam_Warning;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    
    gCurrentSprite.pose = ACID_WORM_POSE_CHECK_WARNING_ENDED;

    SpriteUtilMakeSpriteFaceSamusDirection();
    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;

    SoundPlay(SOUND_ACID_WORM_OPENING_MOUTH);
}

/**
 * @brief 3e0f0 | 5c | Checks if the warning animation before extending has ended
 * 
 */
static void AcidWormCheckWarningAnimEnded(void)
{
    AcidWormHandleRotation();

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        // Init extending
        gCurrentSprite.pOam = sAcidWormOam_Moving;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = ACID_WORM_POSE_EXTENDING;
        // Delay before moving
        gCurrentSprite.work0 = CONVERT_SECONDS(2.f / 15);

        if (gSubSpriteData1.health == gCurrentSprite.yPositionSpawn - BLOCK_SIZE * 3)
            gEffectYPositionOffset = -BLOCK_SIZE;
        else
            gEffectYPositionOffset = 0;
    }
}

/**
 * @brief 3e14c | 35c | Handles the acid worm extending
 * 
 */
static void AcidWormExtend(void)
{
    u16 spawnHealth;
    u16 xPosition;
    u16 yPosition;
    u8 speed;
    u8 checks;

    spawnHealth = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    if (gCurrentSprite.work0 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);

        if (gCurrentSprite.work0 == 0)
        {
            if (!gSubSpriteData1.work3)
            {
                if (gCurrentSprite.health <= spawnHealth / 4)
                    SoundPlay(SOUND_ACID_WORM_EXTEND_FAST);
                else if (gCurrentSprite.health <= spawnHealth / 2)
                    SoundPlay(SOUND_ACID_WORM_EXTEND_NORMAL);
                else
                    SoundPlay(SOUND_ACID_WORM_EXTEND_SLOW);
            }
            else
                SoundPlay(SOUND_ACID_WORM_EXTEND_TO_SPIT);
        }

        return;
    }

    // Make liquid go down
    gEffectYPositionOffset += ONE_SUB_PIXEL;

    // Get speed based on destination or health
    if (!gSubSpriteData1.work3)
    {
        // Normal extend

        if (gCurrentSprite.health <= spawnHealth / 4)
            speed = ACID_WORM_EXTENDING_SPEED * 2;
        else if (gCurrentSprite.health <= spawnHealth / 2)
            speed = ACID_WORM_EXTENDING_SPEED * 1.5;
        else
            speed = ACID_WORM_EXTENDING_SPEED;
    }
    else
    {
        // Extending to spit
        speed = ACID_WORM_EXTENDING_SPEED;
    }

    checks = 0;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.rotation >= PI_2 - 1)
            checks++; // Fully rotated
        else
            gCurrentSprite.rotation += speed;

        if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE)
            gSubSpriteData1.xPosition += speed;
        else
            checks++; // X Movement done
    }
    else
    {
        if ((u8)(gCurrentSprite.rotation - 1) <= PI + PI_2 - 1)
            checks++; // Fully rotated
        else
            gCurrentSprite.rotation -= speed;

        if (gSubSpriteData1.xPosition > gCurrentSprite.xPositionSpawn - BLOCK_SIZE)
            gSubSpriteData1.xPosition -= speed;
        else
            checks++; // X Movement done
    }
    
    if (gSubSpriteData1.yPosition > gCurrentSprite.yPositionSpawn - THREE_QUARTER_BLOCK_SIZE)
        gSubSpriteData1.yPosition -= speed;
    else
        checks++; // Y Movement done

    yPosition = gCurrentSprite.yPosition;
    AcidWormHandleRotation();

    if (SpriteUtilCheckOutOfRoomEffect(yPosition, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE))
        SoundPlay(SOUND_ACID_WORM_SPLASHING);

    if (!AcidWormCollidingWithSamusWhenExtending() && checks == 3) // Everything done
    {
        // Extend done
        gCurrentSprite.pose = ACID_WORM_POSE_EXTENDED;

        // If not spitting
        if (!gSubSpriteData1.work3)
        {
            yPosition = gCurrentSprite.yPosition;
            xPosition = gCurrentSprite.xPosition;

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                xPosition += BLOCK_SIZE;
            else
                xPosition -= BLOCK_SIZE;

            // Set effects depending on health
            if (gCurrentSprite.health <= spawnHealth / 4)
            {
                ScreenShakeStartVertical(TWO_THIRD_SECOND, 0x80 | 1);
                ScreenShakeStartHorizontal(TWO_THIRD_SECOND, 0x80 | 1);

                SpriteDebrisInit(0, 0x11, yPosition - (BLOCK_SIZE + PIXEL_SIZE / 2), xPosition - HALF_BLOCK_SIZE);
                SpriteDebrisInit(0, 0x4, yPosition, xPosition);
                SpriteDebrisInit(0, 0x12, yPosition, xPosition + (BLOCK_SIZE - EIGHTH_BLOCK_SIZE - PIXEL_SIZE));

                SpriteDebrisInit(0, 0x13, yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE - PIXEL_SIZE),
                    xPosition - (BLOCK_SIZE - PIXEL_SIZE / 2));
                SpriteDebrisInit(0, 0x4, yPosition + HALF_BLOCK_SIZE, xPosition + HALF_BLOCK_SIZE);
                SpriteDebrisInit(0, 0x12, yPosition + BLOCK_SIZE, xPosition);

                ParticleSet(yPosition + HALF_BLOCK_SIZE, xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    
                // Timer to stay
                gCurrentSprite.work0 = CONVERT_SECONDS(2.f);
                SoundPlay(SOUND_ACID_WORM_CRASHING_FAST);
            }
            else if (gCurrentSprite.health <= spawnHealth / 2)
            {
                ScreenShakeStartVertical(ONE_THIRD_SECOND, 0x80 | 1);
                ScreenShakeStartHorizontal(ONE_THIRD_SECOND, 0x80 | 1);

                SpriteDebrisInit(0, 0x11, yPosition - (BLOCK_SIZE + PIXEL_SIZE / 2), xPosition - HALF_BLOCK_SIZE);
                SpriteDebrisInit(0, 0x12, yPosition, xPosition + (BLOCK_SIZE - EIGHTH_BLOCK_SIZE - PIXEL_SIZE));
                SpriteDebrisInit(0, 0x13, yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE - PIXEL_SIZE),
                    xPosition - (BLOCK_SIZE - PIXEL_SIZE / 2));
                SpriteDebrisInit(0, 0x4, yPosition + HALF_BLOCK_SIZE, xPosition + HALF_BLOCK_SIZE);

                ParticleSet(yPosition + HALF_BLOCK_SIZE, xPosition, PE_SPRITE_EXPLOSION_BIG);

                // Timer to stay
                gCurrentSprite.work0 = CONVERT_SECONDS(2.f) + ONE_THIRD_SECOND;
                SoundPlay(SOUND_ACID_WORM_CRASHING_NORMAL);
            }
            else
            {
                ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
                ScreenShakeStartHorizontal(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
    
                SpriteDebrisInit(0, 0x12, yPosition - (BLOCK_SIZE + PIXEL_SIZE / 2), xPosition - HALF_BLOCK_SIZE);
                SpriteDebrisInit(0, 0x4, yPosition + HALF_BLOCK_SIZE, xPosition + HALF_BLOCK_SIZE);
    
                ParticleSet(yPosition + HALF_BLOCK_SIZE, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);

                // Timer to stay
                gCurrentSprite.work0 = CONVERT_SECONDS(2.f) + TWO_THIRD_SECOND;
                SoundPlay(SOUND_ACID_WORM_CRASHING_SLOW);
            }

            // Update timer based on difficulty
            if (gDifficulty == DIFF_EASY)
                gCurrentSprite.work0 += CONVERT_SECONDS(1.f);
            else if (gDifficulty == DIFF_HARD)
                gCurrentSprite.work0 -= ONE_THIRD_SECOND;

            gCurrentSprite.pOam = sAcidWormOam_MouthClosed;
            gCurrentSprite.work1 = 0;
        }
        else
        {
            // Set spitting
            gCurrentSprite.pOam = sAcidWormOam_Spitting;
        }

        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 3e4a8 | 210 | Handles the acid worm being fully extended (hooked to block or spitting)
 * 
 */
static void AcidWormExtended(void)
{
    u8 finishedSpitting;

    finishedSpitting = FALSE;
    AcidWormHandleRotation();

    if (!gSubSpriteData1.work3)
    {
        // Hooked to block
        if (!AcidWormCollidingWithSamusWhenExtending())
        {
            if (MOD_AND(gCurrentSprite.work1, 32) == 0)
                SoundPlay(SOUND_ACID_WORM_HOOKED_ON_BLOCK);

            gCurrentSprite.work1++;

            // Timer until retracting
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (gCurrentSprite.work0 == 0)
            {
                gCurrentSprite.pose = ACID_WORM_POSE_RETRACTING;
                AcidWormPlayRetractingSound();
            }
        }

        return;
    }

    // Not hooked, spitting
    if (gSamusData.xPosition > gCurrentSprite.xPositionSpawn - BLOCK_SIZE * 7 &&
        gSamusData.xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 7)
    {
        finishedSpitting++;
    }
    else if (SpriteUtilHasCurrentAnimationEnded())
    {
        finishedSpitting++;
    }

    if (gCurrentSprite.currentAnimationFrame == 1 && gCurrentSprite.animationDurationCounter == 1)
    {
        SoundPlay(SOUND_ACID_WORM_OPENING_MOUTH_TO_SPIT);
    }
    else if (gCurrentSprite.currentAnimationFrame == 2 && gCurrentSprite.animationDurationCounter == 1)
    {
        SoundPlay(SOUND_ACID_WORM_SPITTING);
    }
    else if (gCurrentSprite.currentAnimationFrame == 5 && gCurrentSprite.animationDurationCounter == 1)
    {
        // First spit
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, ACID_WORM_SPIT_BEHAVIOR_MIDDLE, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + THREE_QUARTER_BLOCK_SIZE, SPRITE_STATUS_X_FLIP);
        }
        else
        {
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, ACID_WORM_SPIT_BEHAVIOR_MIDDLE, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition,
                gCurrentSprite.xPosition - THREE_QUARTER_BLOCK_SIZE, 0);
        }
    }
    else if (gCurrentSprite.currentAnimationFrame == 7 && gCurrentSprite.animationDurationCounter == 1)
    {
        // Second spit
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, ACID_WORM_SPIT_BEHAVIOR_FAR, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + THREE_QUARTER_BLOCK_SIZE, SPRITE_STATUS_X_FLIP);
        }
        else
        {
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, ACID_WORM_SPIT_BEHAVIOR_FAR, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition,
                gCurrentSprite.xPosition - THREE_QUARTER_BLOCK_SIZE, 0);
        }
    }
    else if (gCurrentSprite.currentAnimationFrame == 9 && gCurrentSprite.animationDurationCounter == 1)
    {
        // Third spit
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, ACID_WORM_SPIT_BEHAVIOR_CLOSE, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + THREE_QUARTER_BLOCK_SIZE, SPRITE_STATUS_X_FLIP);
        }
        else
        {
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_SPIT, ACID_WORM_SPIT_BEHAVIOR_CLOSE, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition,
                gCurrentSprite.xPosition - THREE_QUARTER_BLOCK_SIZE, 0);
        }
    }

    if (finishedSpitting)
    {
        gCurrentSprite.pOam = sAcidWormOam_MouthClosed;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = ACID_WORM_POSE_RETRACTING;
        AcidWormPlayRetractingSound();
    }
}

/**
 * @brief 3e6b8 | 1ac | Handles the acid worm retracting
 * 
 */
static void AcidWormRetracting(void)
{
    u16 spriteY;
    u16 samusY;
    u8 checks;
    u16 speed;

    speed = PIXEL_SIZE / 2;
    checks = 0;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.rotation < 3)
        {
            // Finished rotation
            checks++;
            gCurrentSprite.rotation = 0;
        }
        else
        {
            gCurrentSprite.rotation -= 2;
        }

        if (gSubSpriteData1.xPosition > gCurrentSprite.xPositionSpawn)
        {
            gSubSpriteData1.xPosition -= speed;
        }
        else
        {
            checks++;
            gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn;
        }
    }
    else
    {
        if (gCurrentSprite.rotation < 3)
        {
            // Finished rotation
            checks++;
            gCurrentSprite.rotation = 0;
        }
        else
        {
            gCurrentSprite.rotation += 2;
        }

        if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn)
        {
            gSubSpriteData1.xPosition -= -speed;
        }
        else
        {
            checks++;
            gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn;
        }
    }

    if (gSubSpriteData1.yPosition < gCurrentSprite.yPositionSpawn)
    {
        gSubSpriteData1.yPosition += PIXEL_SIZE / 2;
    }
    else
    {
        gSubSpriteData1.yPosition = gCurrentSprite.yPositionSpawn;
        checks++;
    }

    // Move acid up until it reaches the base position
    if (gEffectYPosition > gSubSpriteData1.health)
        gEffectYPositionOffset -= ONE_SUB_PIXEL;

    spriteY = gCurrentSprite.yPosition;

    AcidWormHandleRotation();

    if (SpriteUtilCheckInRoomEffect(spriteY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE))
        SoundPlay(SOUND_ACID_WORM_SPLASHING);

    samusY = gSamusData.yPosition;
    spriteY = gCurrentSprite.yPosition;

    // Check everything done
    if (checks == 3)
    {
        if (gCurrentSprite.health <= GET_PSPRITE_HEALTH(gCurrentSprite.spriteId) / 2 && gDifficulty != DIFF_EASY)
        {
            gCurrentSprite.status ^= SPRITE_STATUS_MOSAIC;

            // Check should raise acid
            if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC &&
                (u32)(spriteY - samusY - (BLOCK_SIZE + QUARTER_BLOCK_SIZE + ONE_SUB_PIXEL)) < (BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE - ONE_SUB_PIXEL) &&
                gSamusData.xPosition > gCurrentSprite.xPositionSpawn - BLOCK_SIZE * 7 &&
                gSamusData.xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 7)
            {
                gCurrentSprite.pose = ACID_WORM_POSE_RAISING_ACID;

                gCurrentSprite.pOam = sAcidWormOam_Moving;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                gCurrentSprite.work0 = TWO_THIRD_SECOND;
                SoundPlay(SOUND_ACID_WORM_RAISING_ACID);
            }
            else
            {
                gCurrentSprite.pose = ACID_WORM_POSE_IDLE_INIT;
                gCurrentSprite.work0 = CONVERT_SECONDS(1.f) + MOD_AND(gSpriteRng, 8) * 8;
            }
        }
        else
        {
            gCurrentSprite.pose = ACID_WORM_POSE_IDLE_INIT;
            gCurrentSprite.work0 = CONVERT_SECONDS(1.f) + ONE_THIRD_SECOND + MOD_AND(gSpriteRng, 8) * 8;
        }
    }
}

/**
 * @brief 3e864 | 68 | Handles the acid worm bringing the acid up
 * 
 */
static void AcidWormRaiseAcid(void)
{
    // Check start screen shake
    if (MOD_AND(gFrameCounter8Bit, 16) == 0)
        ScreenShakeStartHorizontal(CONVERT_SECONDS(1.f / 6), 0x80 | 1);

    // Delay before starting
    if (gCurrentSprite.work0 != 0)
    {
        gCurrentSprite.work0--;
        return;
    }

    // Offset up
    gEffectYPositionOffset -= ONE_SUB_PIXEL;

    // Check reached max
    if (gEffectYPosition < gCurrentSprite.yPositionSpawn - BLOCK_SIZE * 5)
    {
        gCurrentSprite.pose = ACID_WORM_POSE_BRINGING_DOWN_ACID;
        SoundPlay(SOUND_ACID_WORM_LOWERING_ACID);
    }
}

/**
 * @brief 3e8cc | 70 | Handles the acid worm bringing the acid down
 * 
 */
static void AcidWormAcidGoDown(void)
{
    // Offset down
    gEffectYPositionOffset += ONE_SUB_PIXEL;
    
    // Check start screen shake
    if (MOD_AND(gFrameCounter8Bit, 16) == 0)
        ScreenShakeStartHorizontal(CONVERT_SECONDS(1.f / 6), 0x80 | 1);

    // Check reached min
    if (gEffectYPosition > gCurrentSprite.yPositionSpawn - BLOCK_SIZE * 3)
    {
        gCurrentSprite.pose = ACID_WORM_POSE_IDLE_INIT;
        gCurrentSprite.work0 = 1;
        gEffectYPositionOffset = -BLOCK_SIZE;

        if (gSubSpriteData1.health == gCurrentSprite.yPositionSpawn - BLOCK_SIZE * 2)
            gSubSpriteData1.health = gCurrentSprite.yPositionSpawn - BLOCK_SIZE * 3;
    }
}

/**
 * @brief 3e93c | 24 | Initializes the acid worm to be dying
 * 
 */
static void AcidWormDeathGfxInit(void)
{
    gCurrentSprite.pOam = sAcidWormOam_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = ACID_WORM_POSE_DYING_ANIM;
    gCurrentSprite.invincibilityStunFlashTimer = CONVERT_SECONDS(1.f) + ONE_THIRD_SECOND;
}

/**
 * @brief 3e960 | 88 | Handles the flashing animation when the acid worm is dying
 * 
 */
static void AcidWormDeathFlashingAnim(void)
{
    u8 isft;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    AcidWormHandleRotation();

    if (!SPRITE_GET_ISFT(gCurrentSprite))
        return;

    isft = --gCurrentSprite.invincibilityStunFlashTimer;
    
    if (!(isft & 0x3))
    {
        if (isft & 0x4)
        {
            gCurrentSprite.paletteRow = SPRITE_GET_STUN_PALETTE(gCurrentSprite);
        }
        else
        {
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
            if (isft == 0)
            {
                ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);

                gCurrentSprite.pose = ACID_WORM_POSE_DYING;
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.work0 = DELTA_TIME;
            }
        }    
    }
}

/**
 * @brief 3e9e8 | d0 | Handles the acid worm death
 * 
 */
static void AcidWormDying(void)
{
    // Check acid reached bottom 
    if (gEffectYPosition > gCurrentSprite.yPositionSpawn + (BLOCK_SIZE * 7 + HALF_BLOCK_SIZE))
    {
        if (!gSubSpriteData1.work2)
        {
            gCurrentSprite.status = 0;
            PlayMusic(MUSIC_BOSS_KILLED, 0);
        }

        return;
    }

    if (!gSubSpriteData1.work2)
    {
        if (gEffectYPosition < gCurrentSprite.yPositionSpawn)
        {
            if (MOD_AND(gFrameCounter8Bit, 32) == 0)
                ParticleSet(gCurrentSprite.yPositionSpawn + (BLOCK_SIZE + EIGHTH_BLOCK_SIZE) + gSpriteRng * 8,
                    gCurrentSprite.xPositionSpawn, PE_SECOND_TWO_MEDIUM_DUST);
        }
        else
        {
            gEffectYPositionOffset += ONE_SUB_PIXEL;
        }
    }

    // Check play effects
    if (gCurrentSprite.work0 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);

        if (gCurrentSprite.work0 == 0)
            SoundPlay(SOUND_ACID_WORM_DEAD);
    }
    else
    {
        gEffectYPositionOffset += ONE_SUB_PIXEL;
        if (MOD_AND(gFrameCounter8Bit, 16) == 0)
        {
            ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
            ScreenShakeStartHorizontal(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
        }
    }
}

/**
 * @brief 3eab8 | 258 | Initializes an acid worm body sprite
 * 
 */
static void AcidWormPartInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_IGNORE_INVINCIBILITY_NO_CONTACT_DAMAGE;
    gCurrentSprite.pose = ACID_WORM_PART_POSE_MOVING;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.health = 0x400;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    // Set starting index for the array that will determine the horizontal wiggle
    gCurrentSprite.work2 = 20 - (gCurrentSprite.roomSlot * 2);

    switch (gCurrentSprite.roomSlot)
    {
        case ACID_WORM_PART_AROUND_MOUTH:
            gCurrentSprite.hitboxTop = -QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;
    
            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.pOam = sAcidWormPartOam_AroundMouth;

            gCurrentSprite.work0 = PI * ACID_WORM_PART_ROTATION_OFFSET * 1;
            gCurrentSprite.work3 = 0x8;
            break;

        case ACID_WORM_PART_WEAK_POINT:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE - QUARTER_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = (BLOCK_SIZE - QUARTER_BLOCK_SIZE);
            gCurrentSprite.hitboxLeft = -(BLOCK_SIZE - QUARTER_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = (BLOCK_SIZE - QUARTER_BLOCK_SIZE);

            gCurrentSprite.drawOrder = 2;
            gCurrentSprite.pOam = sAcidWormPartOam_WeakPoint;

            gCurrentSprite.work0 = PI * ACID_WORM_PART_ROTATION_OFFSET * 2;
            gCurrentSprite.properties &= ~SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.work3 = 0x10;
            break;

        case ACID_WORM_PART_BELOW_WEAK_POINT:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE - QUARTER_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = (BLOCK_SIZE - QUARTER_BLOCK_SIZE);
            gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);

            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.pOam = sAcidWormPartOam_BelowWeakPoint;

            gCurrentSprite.work0 = PI * ACID_WORM_PART_ROTATION_OFFSET * 3;
            gCurrentSprite.work3 = 0x18;
            break;

        case ACID_WORM_PART_ABOVE_SEGMENTS:
            gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE + PIXEL_SIZE);
            gCurrentSprite.hitboxBottom = (HALF_BLOCK_SIZE + PIXEL_SIZE);
            gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE + PIXEL_SIZE);
            gCurrentSprite.hitboxRight = (HALF_BLOCK_SIZE + PIXEL_SIZE);

            gCurrentSprite.drawOrder = 4;
            gCurrentSprite.pOam = sAcidWormPartOam_AboveSegments;

            gCurrentSprite.work0 = PI * ACID_WORM_PART_ROTATION_OFFSET * 4;
            gCurrentSprite.work3 = 0x20;
            break;

        case ACID_WORM_PART_SEGMENT1:
            gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

            gCurrentSprite.drawOrder = 5;
            gCurrentSprite.pOam = sAcidWormPartOam_Segment;

            gCurrentSprite.work0 = PI * ACID_WORM_PART_ROTATION_OFFSET * 5;
            gCurrentSprite.work3 = 0x0;
            break;
            
        case ACID_WORM_PART_SEGMENT2:
            gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

            gCurrentSprite.drawOrder = 5;
            gCurrentSprite.pOam = sAcidWormPartOam_Segment;

            gCurrentSprite.work0 = PI * ACID_WORM_PART_ROTATION_OFFSET * 6;
            gCurrentSprite.work3 = 0x8;
            break;

        case ACID_WORM_PART_SEGMENT3:
            gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

            gCurrentSprite.drawOrder = 5;
            gCurrentSprite.pOam = sAcidWormPartOam_Segment;

            gCurrentSprite.work0 = PI * ACID_WORM_PART_ROTATION_OFFSET * 7;
            gCurrentSprite.work3 = 0x10;
            break;

        case ACID_WORM_PART_SEGMENT4:
            gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

            gCurrentSprite.drawOrder = 5;
            gCurrentSprite.pOam = sAcidWormPartOam_Segment;

            gCurrentSprite.work0 = PI * ACID_WORM_PART_ROTATION_OFFSET * 8;
            gCurrentSprite.work3 = 0x18;
            break;

        case ACID_WORM_PART_SEGMENT5:
            gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

            gCurrentSprite.drawOrder = 5;
            gCurrentSprite.pOam = sAcidWormPartOam_Segment;

            gCurrentSprite.work0 = PI * ACID_WORM_PART_ROTATION_OFFSET * 9;
            gCurrentSprite.work3 = 0x20;
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 3ed10 | 10c | Handles the movement of the acid worm body
 * 
 */
static void AcidWormPartMove(void)
{
    u32 mainBodySlot;
    u16 oldY;
    u16 health;
    
    mainBodySlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[mainBodySlot].pose == ACID_WORM_POSE_SPAWN_EXTEND) 
    {
        // Extending, so just move upwards and check for a splash effect

        oldY = gCurrentSprite.yPosition;
        gCurrentSprite.yPosition -= QUARTER_BLOCK_SIZE;

        // Only check for a splash effect for every other part?
        if (!(gCurrentSprite.roomSlot & 0x1))
            SpriteUtilCheckOutOfRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE);
    }
    else if (gSpriteData[mainBodySlot].pose == ACID_WORM_POSE_SPAWN_RETRACT)
    {
        // Extending, move downwards, wiggle and check for a splash effect

        AcidWormWiggleHorizontally();

        oldY = gCurrentSprite.yPosition;
        gCurrentSprite.yPosition += QUARTER_BLOCK_SIZE;

        // Only check for a splash effect for every other part?
        if (!(gCurrentSprite.roomSlot & 0x1))
            SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE);
    }
    else if (gSpriteData[mainBodySlot].pose == ACID_WORM_POSE_SPAWN_ON_TOP)
    {
        // Fully extended horizontally at the beginning of the fight, so just wiggle
        AcidWormWiggleHorizontally();
    }
    else if (gSpriteData[mainBodySlot].pose == ACID_WORM_POSE_IDLE_INIT)
    {
        gCurrentSprite.pose = ACID_WORM_PART_POSE_IDLE;
        gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING_SINGLE;
        gCurrentSprite.scaling = Q_8_8(1.f);
        gCurrentSprite.rotation = 0;
    }

    if (gSpriteData[mainBodySlot].pose > ACID_WORM_POSE_CHECK_SPAWN)
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;

    if ((gCurrentSprite.roomSlot == ACID_WORM_PART_WEAK_POINT) && (gCurrentSprite.health < 0x400))
    {
        gSpriteData[mainBodySlot].invincibilityStunFlashTimer = gCurrentSprite.invincibilityStunFlashTimer;
        SPRITE_CLEAR_ISFT(gCurrentSprite);
        health = 0x400 - gCurrentSprite.health;
        if (gSpriteData[mainBodySlot].health > health)
        {
            gSpriteData[mainBodySlot].health -= health;
            gCurrentSprite.health = 0x400;
        }
    }
}

/**
 * @brief 3ee1c | 1fc | Main loop for the acid worm body
 * 
 */
static void AcidWormPartIdle(void)
{
    u32 slot;
    u8 pose;
    u16 oldY;
    u8 rotationOffset;
    u16 health;
    u16 health2;

    slot = gCurrentSprite.primarySpriteRamSlot;
    rotationOffset = gCurrentSprite.work0;

    health = gSpriteData[slot].health;

    if (health == 0)
    {
        gCurrentSprite.pose = ACID_WORM_PART_POSE_DYING;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.health = health;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        return;
    }

    if (gSpriteData[slot].status & SPRITE_STATUS_FACING_RIGHT)
    {
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.rotation = gSpriteData[slot].rotation - rotationOffset;
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.rotation = rotationOffset + gSpriteData[slot].rotation;
    }

    if (!(gSpriteData[slot].status & SPRITE_STATUS_FACING_DOWN))
    {
        oldY = gCurrentSprite.yPosition;
        AcidWormHandleRotation();

        pose = gSpriteData[slot].pose;

        if (pose == ACID_WORM_POSE_EXTENDING)
        {
            if (MOD_AND(gCurrentSprite.roomSlot, 2) == 0)
                SpriteUtilCheckOutOfRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE);
        }
        else if (pose == ACID_WORM_POSE_RETRACTING)
        {
            if ((MOD_AND(gCurrentSprite.roomSlot, 2) == 0))
                SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_HUGE);
        }
    }

    if (gCurrentSprite.roomSlot != ACID_WORM_PART_WEAK_POINT)
        return;

    if (gCurrentSprite.health < 0x400)
    {
        gSpriteData[slot].invincibilityStunFlashTimer = gCurrentSprite.invincibilityStunFlashTimer;

        SPRITE_CLEAR_ISFT(gCurrentSprite);

        health2 = 0x400 - gCurrentSprite.health;
        health = gSpriteData[slot].health;

        if (gSpriteData[slot].health > health2)
        {
            gSpriteData[slot].health -= health2;
            gCurrentSprite.health = 0x400;
            
            if (gSpriteData[slot].health <= GET_PSPRITE_HEALTH(gSpriteData[slot].spriteId) / 4)
                gSpriteData[slot].absolutePaletteRow = 2;
            else if (gSpriteData[slot].health <= DIV_SHIFT(GET_PSPRITE_HEALTH(gSpriteData[slot].spriteId), 2))
                gSpriteData[slot].absolutePaletteRow = 1;

            SoundPlay(SOUND_ACID_WORM_HURT);
        }
        else
        {
            gSpriteData[slot].pose = ACID_WORM_POSE_DYING_INIT;
            gSpriteData[slot].health = 0;
            gSpriteData[slot].samusCollision = SSC_NONE;

            gCurrentSprite.health = 0;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

            SoundPlay(SOUND_ACID_WORM_DYING);
            return;
        }
    }

    if (gSpriteData[slot].rotation != 0)
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    else
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
}

/**
 * @brief 3f018 | c8 | Handles the death of an acid worm body
 * 
 */
static void AcidWormPartDeath(void)
{
    u8 mainSpriteSlot;
    u8 roomSlot;
    u8 effect;

    mainSpriteSlot = gCurrentSprite.primarySpriteRamSlot;
    // Remove collision
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    AcidWormHandleRotation();

    if (gSpriteData[mainSpriteSlot].invincibilityStunFlashTimer != 0)
    {
        // Flashing effect
        gCurrentSprite.paletteRow = gSpriteData[mainSpriteSlot].paletteRow;
        return;
    }

    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 != 0)
        return;

    roomSlot = gCurrentSprite.roomSlot;
    effect = PE_SPRITE_EXPLOSION_BIG;

    if (roomSlot != ACID_WORM_PART_WEAK_POINT)
    {
        effect = PE_SPRITE_EXPLOSION_MEDIUM;
        if (roomSlot == ACID_WORM_PART_SEGMENT5)
        {
            // Last segment
            gSubSpriteData1.work2 = FALSE;

            ParticleSet(gSpriteData[mainSpriteSlot].yPositionSpawn + BLOCK_SIZE + HALF_BLOCK_SIZE,
                gSpriteData[mainSpriteSlot].xPositionSpawn, PE_SPRITE_EXPLOSION_BIG);

            ParticleSet(gSpriteData[mainSpriteSlot].yPositionSpawn + BLOCK_SIZE, gSpriteData[mainSpriteSlot].xPositionSpawn, PE_SPRITE_EXPLOSION_BIG);

            // Open path
            AcidWormChangeTwoGroundCcaa(CAA_REMOVE_SOLID, gSpriteData[mainSpriteSlot].yPositionSpawn, gSpriteData[mainSpriteSlot].xPositionSpawn);

            // Set event and open door
            EventFunction(EVENT_ACTION_SETTING, EVENT_ACID_WORM_KILLED);
            gDoorUnlockTimer = -ONE_THIRD_SECOND;
            FadeMusic(CONVERT_SECONDS(4.5f));
        }
    }

    // Kill sprite
    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, FALSE, effect);
}

/**
 * @brief 3f0e0 | 8c | Initialize an acid worm spit sprite
 * 
 */
static void AcidWormSpitInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;

    gCurrentSprite.pOam = sAcidWormSpitOam_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);

    gCurrentSprite.work3 = 0;
    gCurrentSprite.pose = ACID_WORM_SPIT_MOVING;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
}

/**
 * @brief 3f16c | 118 | Handles the movement of an acid worm spit
 * 
 */
static void AcidWormSpitMove(void)
{
    u32 offset;
    s32 yMovement;
    u16 xMovement;

    if (gCurrentSprite.roomSlot == ACID_WORM_SPIT_BEHAVIOR_CLOSE)
    {
        xMovement = PIXEL_SIZE / 2;
        offset = gCurrentSprite.work3;
        yMovement = sAcidWormSpitCloseYVelocity[offset];
        if (yMovement == SHORT_MAX)
        {
            yMovement = sAcidWormSpitCloseYVelocity[offset - 1];
            gCurrentSprite.yPosition += yMovement;
        }
        else
        {
            gCurrentSprite.work3++;
            gCurrentSprite.yPosition += yMovement;
        }
    }
    else if (gCurrentSprite.roomSlot == ACID_WORM_SPIT_BEHAVIOR_FAR)
    {
        xMovement = EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2;
        offset = gCurrentSprite.work3;
        yMovement = sAcidWormSpitFarYVelocity[offset];
        if (yMovement == SHORT_MAX)
        {
            yMovement = sAcidWormSpitFarYVelocity[offset - 1];
            gCurrentSprite.yPosition += yMovement;
        }
        else
        {
            gCurrentSprite.work3++;
            gCurrentSprite.yPosition += yMovement;
        }
    }
    else
    {
        xMovement = EIGHTH_BLOCK_SIZE - ONE_SUB_PIXEL;
        offset = gCurrentSprite.work3;
        yMovement = sAcidWormSpitMiddleYVelocity[offset];
        if (yMovement == SHORT_MAX)
        {
            yMovement = sAcidWormSpitMiddleYVelocity[offset - 1];
            gCurrentSprite.yPosition += yMovement;
        }
        else
        {
            gCurrentSprite.work3++;
            gCurrentSprite.yPosition += yMovement;
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition += xMovement;
    else
        gCurrentSprite.xPosition -= xMovement;

    if (gCurrentSprite.yPosition >= gEffectYPosition)
    {
        gCurrentSprite.yPosition = gEffectYPosition;

        gCurrentSprite.pOam = sAcidWormSpitOam_Exploding;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = ACID_WORM_SPIT_POSE_EXPLODING_ON_ACID;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
            gCurrentSprite.pose = SPRITE_POSE_STOPPED;
    }
}

/**
 * @brief 3f284 | 48 | Initializes an acid worm spit sprite to be exploding
 * 
 */
static void AcidWormSpitExplodingInit(void)
{
    gCurrentSprite.pOam = sAcidWormSpitOam_Exploding;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = ACID_WORM_SPIT_POSE_EXPLODING;
    gCurrentSprite.bgPriority = MOD_AND(gIoRegistersBackup.BG1CNT, 4);
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    SoundPlay(SOUND_ACID_WORM_SPIT_EXPLODING);
}

/**
 * @brief 3f2cc | 24 | Checks if the explosion animation has ended
 * 
 */
static void AcidWormSpitExploding(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    if (SpriteUtilHasCurrentAnimationEnded())
        gCurrentSprite.status = 0; // Kill sprite
}

/**
 * @brief 3f2f0 | 2c | Checks if the explosion animation has ended (on acid)
 * 
 */
static void AcidWormSpitCheckExplodingOnAcidAnimEnded(void)
{
    // Sync position
    gCurrentSprite.yPosition = gEffectYPosition;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (SpriteUtilHasCurrentAnimationEnded())
        gCurrentSprite.status = 0; // Kill sprite
}

/**
 * @brief 3f31c | 264 | Acid worm AI
 * 
 */
void AcidWorm(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            AcidWormInit();
            break;

        case ACID_WORM_POSE_CHECK_SAMUS_ON_ZIPLINE:
            AcidWormCheckSamusOnZipline();
            break;

        case ACID_WORM_POSE_CHECK_SPAWN:
            AcidWormSpawnStart();
            break;

        case ACID_WORM_POSE_SPAWN_EXTEND:
            AcidWormSpawnExtending();
            break;

        case ACID_WORM_POSE_SPAWN_ON_TOP:
            AcidWormSpawnStayingOnTop();
            break;

        case ACID_WORM_POSE_SPAWN_RETRACT:
            AcidWormSpawnRetracting();
            break;

        case ACID_WORM_POSE_IDLE_INIT:
            AcidWormIdleInit();

        case ACID_WORM_POSE_IDLE:
            AcidWormIdle();
            break;

        case ACID_WORM_POSE_CHECK_WARNING_ENDED:
            AcidWormCheckWarningAnimEnded();
            break;

        case ACID_WORM_POSE_EXTENDING:
            AcidWormExtend();
            break;

        case ACID_WORM_POSE_RETRACTING:
            AcidWormRetracting();
            break;

        case ACID_WORM_POSE_EXTENDED:
            AcidWormExtended();
            break;

        case ACID_WORM_POSE_RAISING_ACID:
            AcidWormRaiseAcid();
            break;

        case ACID_WORM_POSE_BRINGING_DOWN_ACID:
            AcidWormAcidGoDown();
            break;

        case ACID_WORM_POSE_DYING_INIT:
            AcidWormDeathGfxInit();
            break;

        case ACID_WORM_POSE_DYING_ANIM:
            AcidWormDeathFlashingAnim();
            break;

        case ACID_WORM_POSE_DYING:
            AcidWormDying();
            break;
    }

    // Lock screen if not dead
    if (gSubSpriteData1.work2)
    {
        gLockScreen.lock = LOCK_SCREEN_TYPE_MIDDLE;
        gLockScreen.yPositionCenter = gCurrentSprite.yPositionSpawn - BLOCK_SIZE * 4;
        gLockScreen.xPositionCenter = gCurrentSprite.xPositionSpawn;
    }
    else
    {
        gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;
    }
}

/**
 * @brief 3f580 | a4 | Acid worm body AI
 * 
 */
void AcidWormPart(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    // Sync palette
    gCurrentSprite.absolutePaletteRow = gSpriteData[ramSlot].absolutePaletteRow;
    if (gSpriteData[ramSlot].paletteRow == SPRITE_GET_STUN_PALETTE(gSpriteData[ramSlot]))
    {
        gCurrentSprite.paletteRow = SPRITE_GET_STUN_PALETTE(gCurrentSprite);
        gCurrentSprite.animationDurationCounter++;
    }
    else if (gSpriteData[ramSlot].paletteRow == gSpriteData[ramSlot].absolutePaletteRow)
        gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            AcidWormPartInit();
            break;

        case ACID_WORM_PART_POSE_MOVING:
            AcidWormPartMove();
            break;

        case ACID_WORM_PART_POSE_IDLE:
            AcidWormPartIdle();
            break;

        case ACID_WORM_PART_POSE_DYING:
            AcidWormPartDeath();
    }
}

/**
 * @brief 3f624 | 60 | Acid worm spit AI
 * 
 */
void AcidWormSpit(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            AcidWormSpitInit();
            break;

        case ACID_WORM_SPIT_MOVING:
            AcidWormSpitMove();
            break;

        case SPRITE_POSE_STOPPED:
            AcidWormSpitExplodingInit();

        case ACID_WORM_SPIT_POSE_EXPLODING:
            AcidWormSpitExploding();
            break;

        case ACID_WORM_SPIT_POSE_EXPLODING_ON_ACID:
            AcidWormSpitCheckExplodingOnAcidAnimEnded();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}
