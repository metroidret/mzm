#include "sprites_AI/worker_robot.h"
#include "macros.h"

#include "data/sprites/worker_robot.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/samus.h"
#include "constants/projectile.h"

#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/projectile.h"

#define WORKER_ROBOT_POSE_WALKING_INIT 0x8
#define WORKER_ROBOT_POSE_WALKING 0x9
#define WORKER_ROBOT_POSE_BACK_TO_SLEEP_INIT 0xA
#define WORKER_ROBOT_POSE_BACK_TO_SLEEP 0xB
#define WORKER_ROBOT_POSE_TURNING_AROUND 0xC
#define WORKER_ROBOT_POSE_CHECK_TURNING_AROUND_ENDED 0xD
#define WORKER_ROBOT_POSE_STANDING_INIT 0xE
#define WORKER_ROBOT_POSE_STANDING 0xF
#define WORKER_ROBOT_POSE_SLEEPING_INIT 0x10
#define WORKER_ROBOT_POSE_SLEEPING 0x11
#define WORKER_ROBOT_POSE_WAKING_UP_INIT 0x12
#define WORKER_ROBOT_POSE_WAKING_UP 0x13
#define WORKER_ROBOT_POSE_FALLING_INIT 0x1E
#define WORKER_ROBOT_POSE_FALLING 0x1F
#define WORKER_ROBOT_POSE_FALLING_SLEEPING_INIT 0x20
#define WORKER_ROBOT_POSE_FALLING_SLEEPING 0x21

/**
 * @brief 2f534 | c4 | Checks if samus is in front of the worker robot
 * 
 * @return u8 bool, in front
 */
static u8 WorkerRobotCheckSamusInFront(void)
{
    u16 spriteY;
    u32 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u16 samusY;
    u32 samusX;
    u16 samusTop;
    u16 samusBottom;
    u16 samusLeft;
    u16 samusRight;

    if (!(gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP))
    {
        spriteY = gCurrentSprite.yPosition;
        spriteX = gCurrentSprite.xPosition;
        spriteTop = spriteY - (2 * BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE);
        spriteBottom = spriteY + 0;
        spriteLeft = spriteX - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
        spriteRight = spriteX + (BLOCK_SIZE + EIGHTH_BLOCK_SIZE);

        samusY = gSamusData.yPosition;
        samusX = gSamusData.xPosition;
        samusTop = gSamusData.yPosition + gSamusPhysics.hitboxTop;
        samusBottom = gSamusData.yPosition + gSamusPhysics.hitboxBottom;
        samusLeft = gSamusData.xPosition + gSamusPhysics.hitboxLeft;
        samusRight = gSamusData.xPosition + gSamusPhysics.hitboxRight;

        if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight,
            samusTop, samusBottom, samusLeft, samusRight))
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                if (spriteX < samusX)
                    return TRUE;
            }
            else
            {
                if (spriteX > samusX)
                    return TRUE;
            }
        }
    }
    
    return FALSE;
}

/**
 * @brief 2f5f8 | 90 | Initializes a worker robot
 * 
 */
static void WorkerRobotInit(void)
{
    gCurrentSprite.hitboxTop = -(BLOCK_SIZE + 3 * QUARTER_BLOCK_SIZE + PIXEL_SIZE);
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = -(EIGHTH_BLOCK_SIZE * 3 + PIXEL_SIZE);
    gCurrentSprite.hitboxRight = EIGHTH_BLOCK_SIZE * 3 + PIXEL_SIZE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    gCurrentSprite.pOam = sWorkerRobotOam_Sleeping;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.samusCollision = SSC_SOLID;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    SpriteUtilMakeSpriteFaceAwayFromSamusXFlip();

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;

    gCurrentSprite.pose = WORKER_ROBOT_POSE_SLEEPING;
}

/**
 * @brief 2f688 | 20 | Initializes a worker robot to be sleeping
 * 
 */
static void WorkerRobotSleepingInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_SLEEPING;
    gCurrentSprite.pOam = sWorkerRobotOam_Sleeping;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;
}

/**
 * @brief 2f6a8 | 38 | handles a worker robot sleeping
 * 
 */
static void WorkerRobotSleeping(void)
{
    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) == COLLISION_AIR)
        gCurrentSprite.pose = WORKER_ROBOT_POSE_FALLING_SLEEPING_INIT;
    else if (MOD_AND(gCurrentSprite.invincibilityStunFlashTimer, 128)) // CONVERT_SECONDS(2.f + 2.f / 15)
        gCurrentSprite.pose = WORKER_ROBOT_POSE_WAKING_UP_INIT;
}

/**
 * @brief 2f6e0 | 38 | Initializes a worker robot to be waking up
 * 
 */
static void WorkerRobotWakingUpInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_WAKING_UP;

    gCurrentSprite.pOam = sWorkerRobotOam_WakingUp;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_WORKER_ROBOT_WAKING_UP);
}

/**
 * @brief 2f718 | 1c | Handles a worker robot waking up
 * 
 */
static void WorkerRobotWakingUp(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = WORKER_ROBOT_POSE_STANDING_INIT;
}

/**
 * @brief 2f734 | 19c | Checks for a projectile collision when a worker robot is walking 
 * 
 */
static void WorkerRobotWalkingDetectProjectile(void)
{
    struct ProjectileData* pProj;
    u8 type;
    u8 onSide;
    u8 status;
    u32 statusCheck;
    
    u16 projY;
    u16 projX;
    u16 projTop;
    u16 projBottom;
    u16 projLeft;
    u16 projRight;
    
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;

    statusCheck = PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
    onSide = FALSE;
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    spriteTop = spriteY + gCurrentSprite.hitboxTop;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottom;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeft;
    spriteRight = spriteX + gCurrentSprite.hitboxRight;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        status = pProj->status;
        if ((status & statusCheck) != statusCheck)
            continue;

        type = pProj->type;
        if (type != PROJ_TYPE_MISSILE && type != PROJ_TYPE_SUPER_MISSILE)
            continue;

        projY = pProj->yPosition;
        projX = pProj->xPosition;
        projTop = projY + pProj->hitboxTop;
        projBottom = projY + pProj->hitboxBottom;
        projLeft = projX + pProj->hitboxLeft;
        projRight = projX + pProj->hitboxRight;
            
        if (!SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, projTop, projBottom, projLeft, projRight))
            continue;

        if (pProj->direction == ACD_FORWARD)
        {
            onSide++;
        }
        else if (pProj->direction == ACD_DIAGONALLY_UP || pProj->direction == ACD_DIAGONALLY_DOWN)
        {
            if (projY > spriteTop && projY < spriteBottom)
                onSide++;
        }
        
        if (onSide)
        {
            if (pProj->status & PROJ_STATUS_X_FLIP)
            {
                projX = spriteLeft;
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;

                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                {
                    if (gCurrentSprite.pOam != sWorkerRobotOam_Walking)
                        gCurrentSprite.pOam = sWorkerRobotOam_Walking;
                }
                else
                {
                    if (gCurrentSprite.pOam != sWorkerRobotOam_WalkingBackwards)
                        gCurrentSprite.pOam = sWorkerRobotOam_WalkingBackwards;
                }
            }
            else
            {
                projX = spriteRight;
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;

                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                {
                    if (gCurrentSprite.pOam != sWorkerRobotOam_WalkingBackwards)
                        gCurrentSprite.pOam = sWorkerRobotOam_WalkingBackwards;
                }
                else
                {
                    if (gCurrentSprite.pOam != sWorkerRobotOam_Walking)
                        gCurrentSprite.pOam = sWorkerRobotOam_Walking;
                }
            }
            
            gCurrentSprite.animationDurationCounter = 0;
        }

        if (type == PROJ_TYPE_SUPER_MISSILE)
        {
            ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
            if (onSide)
                gCurrentSprite.work1 = CONVERT_SECONDS(1.f);
        }
        else
        {
            ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_MISSILE);
            if (onSide)
                gCurrentSprite.work1 = CONVERT_SECONDS(.5f);
        }

        pProj->status = 0;
        break;
    }
}

/**
 * @brief 2f8d0 | 3c | Initializes a worker robot to be standing
 * 
 */
static void WorkerRobotStandingInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_STANDING;

    gCurrentSprite.pOam = sWorkerRobotOam_Standing;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.work0 = CONVERT_SECONDS(.5f);
    gCurrentSprite.work1 = 0;
    gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + PIXEL_SIZE);
}

/**
 * @brief 2f90c | 3c | handles a worker robot standing
 * 
 */
static void WorkerRobotStanding(void)
{
    WorkerRobotWalkingDetectProjectile();
    if (gCurrentSprite.work1 != 0)
    {
        gCurrentSprite.pose = WORKER_ROBOT_POSE_WALKING;
    }
    else
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == 0)
            gCurrentSprite.pose = WORKER_ROBOT_POSE_WALKING_INIT;
    }
}

/**
 * @brief 2f948 | 20 | Initializes a worker robot to be walking
 * 
 */
static void WorkerRobotWalkingInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_WALKING;
    gCurrentSprite.pOam = sWorkerRobotOam_Walking;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;
}

/**
 * @brief 2f968 | 25c | Handles a worker robot walking 
 * 
 */
static void WorkerRobotWalking(void)
{
    u16 movement;
    u32 collision;

    SpriteUtilAlignYPositionOnSlopeAtOrigin();

    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE) == COLLISION_AIR)
        {
            collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);   

            if (collision == COLLISION_AIR)
            {
                gCurrentSprite.pose = WORKER_ROBOT_POSE_FALLING_INIT;

                if (gCurrentSprite.work1 == 0)
                    return;

                gCurrentSprite.work1 = 0;
                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                {
                    if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                }
                else
                {
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                }
                
                return;
            }
        }
    }

    movement = 1;
    WorkerRobotWalkingDetectProjectile();

    if (gCurrentSprite.work1 != 0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && MOD_AND(gCurrentSprite.currentAnimationFrame, 4) == 3 &&
            gCurrentSprite.animationDurationCounter == 6)
        {
            SoundPlayNotAlreadyPlaying(SOUND_WORKER_ROBOT_FOOTSTEPS);
        }

        // Multiply by 5 the animation speed
        APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);
        APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);
        APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);
        APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);

        movement = gCurrentSprite.work1 / 4;
        if (movement > EIGHTH_BLOCK_SIZE)
            movement = EIGHTH_BLOCK_SIZE;
        else if (movement == 0)
            movement = ONE_SUB_PIXEL;

        gCurrentSprite.work1--;

        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                
                gCurrentSprite.pose = WORKER_ROBOT_POSE_STANDING_INIT;
            }
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                
                gCurrentSprite.pose = WORKER_ROBOT_POSE_STANDING_INIT;
            }
            return;
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && MOD_AND(gCurrentSprite.currentAnimationFrame, 4) == 3 &&
            gCurrentSprite.animationDurationCounter == 8)
        {
            SoundPlayNotAlreadyPlaying(SOUND_WORKER_ROBOT_FOOTSTEPS);
        }

        if (WorkerRobotCheckSamusInFront())
        {
            gCurrentSprite.pose = WORKER_ROBOT_POSE_BACK_TO_SLEEP_INIT;
            return;
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        {
            if (gCurrentSprite.work1 == 0 &&
                SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE) == COLLISION_AIR)
            {
                gCurrentSprite.pose = WORKER_ROBOT_POSE_BACK_TO_SLEEP_INIT;
                return;
            }
            
            if ((u8)SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE),
                gCurrentSprite.xPosition + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE) == COLLISION_SOLID)
            {
                if (gCurrentSprite.work1 == 0)
                    gCurrentSprite.pose = WORKER_ROBOT_POSE_BACK_TO_SLEEP_INIT;
                return;
            }
        }

        gCurrentSprite.xPosition += movement;
        if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP)
            gSamusData.xPosition += movement;
    }
    else
    {
        if (gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        {
            if (gCurrentSprite.work1 == 0 &&
                SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - HALF_BLOCK_SIZE) == COLLISION_AIR)
            {
                gCurrentSprite.pose = WORKER_ROBOT_POSE_BACK_TO_SLEEP_INIT;
                return;
            }
            
            if ((u8)SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE),
                gCurrentSprite.xPosition - (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE)) == COLLISION_SOLID)
            {
                if (gCurrentSprite.work1 == 0)
                    gCurrentSprite.pose = WORKER_ROBOT_POSE_BACK_TO_SLEEP_INIT;
                return;
            }
        }

        gCurrentSprite.xPosition -= movement;
        if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP)
            gSamusData.xPosition -= movement;
    }
}

/**
 * @brief 2fbc4 | 38 | Initializes a worker robot to be going back to sleep
 * 
 */
static void WorkerRobotBackToSleepInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_BACK_TO_SLEEP;

    gCurrentSprite.pOam = sWorkerRobotOam_BackToSleep;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_WORKER_ROBOT_FALLING_ASLEEP);
}

/**
 * @brief 2fbfc | 34 | Handles a worker robot going back to sleep
 * 
 */
static void WorkerRobotBackToSleep(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = WORKER_ROBOT_POSE_TURNING_AROUND;

        gCurrentSprite.pOam = sWorkerRobotOam_GoingToSleep;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.hitboxTop = -(BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE);
    }
}

/**
 * @brief 2fc30 | 4c | Initializes a worker robot to be turning around
 * 
 */
static void WorkerRobotTurningAroundInit(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.status &= ~(SPRITE_STATUS_X_FLIP | SPRITE_STATUS_FACING_RIGHT);
        else
            gCurrentSprite.status |= (SPRITE_STATUS_X_FLIP | SPRITE_STATUS_FACING_RIGHT);

        gCurrentSprite.pose = WORKER_ROBOT_POSE_CHECK_TURNING_AROUND_ENDED;

        gCurrentSprite.pOam = sWorkerRobotOam_TurningAround;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 2fc7c | 1c | Handles a worker robot turning around
 * 
 */
static void WorkerRobotCheckTurningAroundAnimEnded(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = WORKER_ROBOT_POSE_SLEEPING_INIT;
}

/**
 * @brief 2fc98 | 28 | Initializes a worker robot to be falling
 * 
 */
static void WorkerRobotFallingInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_FALLING;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.work1 = 0;

    gCurrentSprite.pOam = sWorkerRobotOam_Walking;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 2fcc0 | 80 | Handles a worker robot falling
 * 
 */
static void WorkerRobotFalling(void)
{
    u32 blockTop;
    s32 movement;
    u8 offset;

    APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);
    APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.yPosition = blockTop;
        gCurrentSprite.pose = WORKER_ROBOT_POSE_STANDING_INIT;
        SoundPlay(SOUND_WORKER_ROBOT_LANDING);
    }
    else
    {
        offset = gCurrentSprite.work3;
        movement = sSpritesFallingSpeed[offset];

        if (movement == SHORT_MAX)
        {
            movement = sSpritesFallingSpeed[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            gCurrentSprite.work3++;
            gCurrentSprite.yPosition += movement;
        }
    }
}

/**
 * @brief 2fd40 | 1c | Intiializes a worker robot to be falling while sleeping
 * 
 */
static void WorkerRobotFallingSleepInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_FALLING_SLEEPING;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.work1 = 0;
}

/**
 * @brief 2fd5c | 78 | Handles a worker robot falling while sleeping
 * 
 */
static void WorkerRobotFallingSleep(void)
{
    u32 blockTop;
    s32 movement;
    u8 offset;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.yPosition = blockTop;
        gCurrentSprite.pose = WORKER_ROBOT_POSE_SLEEPING_INIT;
        SoundPlay(SOUND_WORKER_ROBOT_LANDING);
    }
    else
    {
        offset = gCurrentSprite.work3;
        movement = sWorkerRobotSleepingFallingSpeed[offset];

        if (movement == SHORT_MAX)
        {
            movement = sWorkerRobotSleepingFallingSpeed[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            gCurrentSprite.work3++;
            gCurrentSprite.yPosition += movement;
        }
    }
}

/**
 * @brief 2fdd4 | 11c c| Worker robot AI
 * 
 */
void WorkerRobot(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            WorkerRobotInit();

        case WORKER_ROBOT_POSE_SLEEPING_INIT:
            WorkerRobotSleepingInit();

        case WORKER_ROBOT_POSE_SLEEPING:
            WorkerRobotSleeping();
            break;

        case WORKER_ROBOT_POSE_WAKING_UP_INIT:
            WorkerRobotWakingUpInit();

        case WORKER_ROBOT_POSE_WAKING_UP:
            WorkerRobotWakingUp();
            break;

        case WORKER_ROBOT_POSE_STANDING_INIT:
            WorkerRobotStandingInit();

        case WORKER_ROBOT_POSE_STANDING:
            WorkerRobotStanding();
            break;

        case WORKER_ROBOT_POSE_WALKING_INIT:
            WorkerRobotWalkingInit();

        case WORKER_ROBOT_POSE_WALKING:
            WorkerRobotWalking();
            break;

        case WORKER_ROBOT_POSE_BACK_TO_SLEEP_INIT:
            WorkerRobotBackToSleepInit();

        case WORKER_ROBOT_POSE_BACK_TO_SLEEP:
            WorkerRobotBackToSleep();
            break;

        case WORKER_ROBOT_POSE_TURNING_AROUND:
            WorkerRobotTurningAroundInit();
            break;

        case WORKER_ROBOT_POSE_CHECK_TURNING_AROUND_ENDED:
            WorkerRobotCheckTurningAroundAnimEnded();
            break;

        case WORKER_ROBOT_POSE_FALLING_INIT:
            WorkerRobotFallingInit();

        case WORKER_ROBOT_POSE_FALLING:
            WorkerRobotFalling();
            break;

        case WORKER_ROBOT_POSE_FALLING_SLEEPING_INIT:
            WorkerRobotFallingSleepInit();

        case WORKER_ROBOT_POSE_FALLING_SLEEPING:
            WorkerRobotFallingSleep();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE - PIXEL_SIZE / 2), gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}
