#include "sprites_ai/security_gate.h"
#include "macros.h"

#include "data/sprites/security_gate.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/particle.h"

#include "structs/clipdata.h"
#include "structs/sprite.h"

#define SECURITY_GATE_POSE_IDLE 0x9
#define SECURITY_GATE_POSE_CLOSING 0x23
#define SECURITY_GATE_POSE_CLOSED 0x25
#define SECURITY_GATE_POSE_OPENING 0x27

/**
 * @brief 2eaf8 | 50 | Updates the clipdata of the security gate
 * 
 * @param caa Clipdata affecting action
 */
static void SecurityGateChangeClipdata(ClipdataAffectingAction caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    // Bottom
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 0 + HALF_BLOCK_SIZE), xPosition);
    // Middle bottom
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 1 + HALF_BLOCK_SIZE), xPosition);
    // Middle top
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), xPosition);
    // Top
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), xPosition);
}

/**
 * @brief 2eb48 | 40 | Opens the gate
 * 
 */
static void SecurityGateOpen(void)
{
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    gCurrentSprite.pOam = sSecurityGateOam_Opening;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = SECURITY_GATE_POSE_OPENING;
    SecurityGateChangeClipdata(CAA_REMOVE_SOLID); // Remove collision
    SoundPlayNotAlreadyPlaying(SOUND_SECURITY_GATE_OPENING);
}

/**
 * @brief 2eb88 | 38 | Starts the closing of the gate
 * 
 */
static void SecurityGateClose(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.pOam = sSecurityGateOam_Closing;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = SECURITY_GATE_POSE_CLOSING;
    SoundPlayNotAlreadyPlaying(SOUND_SECURITY_GATE_CLOSING);
}

/**
 * @brief 2ebc0 | a8 | Initializes a security gate default open sprite
 * 
 */
static void SecurityGateDefaultOpenInit(void)
{
    if (gAlarmTimer != 0) // Check if should be closed or open
    {
        gCurrentSprite.pOam = sSecurityGateOam_Closed;
        gCurrentSprite.pose = SECURITY_GATE_POSE_CLOSED;
        gCurrentSprite.work0 = TRUE;
        SecurityGateChangeClipdata(CAA_MAKE_NON_POWER_GRIP); // Set collision
    }
    else
    {
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pOam = sSecurityGateOam_Opened;
        gCurrentSprite.pose = SECURITY_GATE_POSE_IDLE;
    }

    gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 4);
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.health = 1;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
}

/**
 * @brief 2ec68 | 18 | Checks if the alarm timer is different than 0, if yes closes the gate
 * 
 */
static void SecurityGateDefaultOpenCheckAlarm(void)
{
    if (gAlarmTimer != 0)
        SecurityGateClose();
}

/**
 * @brief 2ec80 | 38 | Checks if the closing animation has ended
 * 
 */
static void SecurityGateCheckClosingAnimEnded(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pOam = sSecurityGateOam_Closed;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = SECURITY_GATE_POSE_CLOSED;
        gCurrentSprite.work0 = FALSE;
        gCurrentSprite.work3 = 0;
    }
}

/**
 * @brief 2ecb8 | 60 | Called after the alarm is done, opens the gate if necessary
 * 
 */
static void SecurityGateDefaultOpenOpenAfterAlarm(void)
{
    if (!gCurrentSprite.work0 && !SpriteCheckCollidingWithSamus()) // ?
    {
        SecurityGateChangeClipdata(CAA_MAKE_NON_POWER_GRIP);
        gCurrentSprite.work0++;
    }

    if (gAlarmTimer == 0)
    {
        APPLY_DELTA_TIME_INC(gCurrentSprite.work3);
        if (gCurrentSprite.work3 > TWO_THIRD_SECOND)
            SecurityGateOpen();
    }
    else
    {
        gCurrentSprite.work3 = 0;
    }
}

/**
 * @brief 2ed18 | 28 | Checks if the opening animation has ended
 * 
 */
static void SecurityGateOpening(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pOam = sSecurityGateOam_Opened;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = SECURITY_GATE_POSE_IDLE;
    }
}

/**
 * @brief 2ed40 | 40 | Handles the death of the security gate, unused
 * 
 */
static void SecurityGateDeath(void)
{
    u16 yPosition;
    u16 xPosition;

    SecurityGateChangeClipdata(CAA_REMOVE_SOLID);

    yPosition = gCurrentSprite.yPosition - BLOCK_SIZE;
    xPosition = gCurrentSprite.xPosition;
    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_HUGE);
    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
}

/**
 * @brief 2ed80 | a4 | Initializes a security gate default closed sprite
 * 
 */
static void SecurityGateDefaultClosedInit(void)
{
    if (gAlarmTimer != 0)
    {
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pOam = sSecurityGateOam_Opened;
        gCurrentSprite.pose = SECURITY_GATE_POSE_IDLE;
    }
    else
    {
        gCurrentSprite.pOam = sSecurityGateOam_Closed;
        gCurrentSprite.pose = SECURITY_GATE_POSE_CLOSED;
        gCurrentSprite.work0 = TRUE;
        SecurityGateChangeClipdata(CAA_MAKE_NON_POWER_GRIP);
    }

    gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 4);
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.health = 1;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
}

/**
 * @brief 2ee24 | 18 | Checks if the alarm timer is 0, if yes closes the gate
 * 
 */
static void SecurityGateDefaultClosedCheckAlarm(void)
{
    if (gAlarmTimer == 0)
        SecurityGateClose();
}

/**
 * @brief 2ee3c | 3c | Checks if the alarm timer isn't 0, if yes calls SecurityGateOpen
 * 
 */
static void SecurityGateDefaultClosedCloseAfterAlarm(void)
{
    if (!gCurrentSprite.work0 && !SpriteCheckCollidingWithSamus())
    {
        SecurityGateChangeClipdata(CAA_MAKE_NON_POWER_GRIP);
        gCurrentSprite.work0++;
    }

    if (gAlarmTimer != 0)
        SecurityGateOpen();
}

/**
 * @brief 2ee78 | f0 | Security Gate Default Open AI
 * 
 */
void SecurityGateDefaultOpen(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            SecurityGateDefaultOpenInit();
            break;

        case SECURITY_GATE_POSE_IDLE:
            SecurityGateDefaultOpenCheckAlarm();
            break;

        case SECURITY_GATE_POSE_CLOSING:
            SecurityGateCheckClosingAnimEnded();
            break;

        case SECURITY_GATE_POSE_CLOSED:
            SecurityGateDefaultOpenOpenAfterAlarm();
            break;

        case SECURITY_GATE_POSE_OPENING:
            SecurityGateOpening();
            break;

        default:
            SecurityGateDeath();
    }
}

/**
 * @brief 2ef68 | f0 | Security Gate Default Closed AI
 * 
 */
void SecurityGateDefaultClosed(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            SecurityGateDefaultClosedInit();
            break;

        case SECURITY_GATE_POSE_IDLE:
            SecurityGateDefaultClosedCheckAlarm();
            break;

        case SECURITY_GATE_POSE_CLOSING:
            SecurityGateCheckClosingAnimEnded();
            break;

        case SECURITY_GATE_POSE_CLOSED:
            SecurityGateDefaultClosedCloseAfterAlarm();
            break;

        case SECURITY_GATE_POSE_OPENING:
            SecurityGateOpening();
            break;

        default:
            SecurityGateDeath();
    }
}
