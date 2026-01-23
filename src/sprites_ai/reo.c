#include "sprites_ai/reo.h"
#include "macros.h"

#include "data/sprites/reo.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"
#include "structs/samus.h"

#define REO_POSE_IDLE_INIT 0x8
#define REO_POSE_IDLE 0x9
#define REO_POSE_MOVING_INIT 0x22
#define REO_POSE_MOVING 0x23

/**
 * @brief 1cc98 | 88 | Initializes a reo sprite
 * 
 */
static void ReoInit(void)
{
    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -(BLOCK_SIZE - EIGHTH_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = BLOCK_SIZE - EIGHTH_BLOCK_SIZE;

    gCurrentSprite.pOam = sReoOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    SpriteUtilChooseRandomXDirection();

    if (gSpriteRng > SPRITE_RNG_PROB(.5f))
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

    gCurrentSprite.pose = REO_POSE_IDLE_INIT;
}

/**
 * @brief 1cd20 | 24 | Initializes a reo to be idle
 * 
 */
static void ReoIdleInit(void)
{
    u8 offset;
    
    gCurrentSprite.pose = REO_POSE_IDLE;
    offset = gSpriteRng * 4;
    gCurrentSprite.work2 = offset;
    gCurrentSprite.work3 = gCurrentSprite.work2;
}

/**
 * @brief 1cd44 | 84 | Handles a reo being idle
 * 
 */
static void ReoIdle(void)
{
    s32 movement;
    u8 offset;

    // Y movement
    offset = gCurrentSprite.work3;
    movement = sReoIdleYMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sReoIdleYMovement[0];
        offset = 0;
    }
    gCurrentSprite.work3 = offset + 1;
    gCurrentSprite.yPosition += movement;
    
    // X movement
    offset = gCurrentSprite.work2;
    movement = sReoIdleXMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sReoIdleXMovement[0];
        offset = 0;
    }
    gCurrentSprite.work2 = offset + 1;
    gCurrentSprite.xPosition += movement;

    // Check samus is in range
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 8, BLOCK_SIZE * 7) != NSLR_OUT_OF_RANGE)
        gCurrentSprite.pose = REO_POSE_MOVING_INIT;
}

/**
 * @brief 1cdc8 | 88 | Initializes a reo to be moving
 * 
 */
static void ReoMovingInit(void)
{
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work2 = ONE_SUB_PIXEL;
    gCurrentSprite.work0 = 0;
    gCurrentSprite.work3 = ONE_SUB_PIXEL;

    gCurrentSprite.xPositionSpawn = MOD_AND(gSpriteRng, SPRITE_RNG_PROB(.25f));
    gCurrentSprite.pose = REO_POSE_MOVING;
    gCurrentSprite.scaling = CONVERT_SECONDS(.5f + 1.f / 30);

    gCurrentSprite.pOam = sReoOam_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    SpriteUtilMakeSpriteFaceSamusDirection();

    if (gCurrentSprite.yPosition > gSamusData.yPosition + gSamusPhysics.hitboxTop)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
}

/**
 * @brief 1ce50 | 394 | Handles a reo moving
 * 
 */
static void ReoMove(void)
{
    u16 yPosition;
    u16 xPosition;
    u16 otherY;
    u16 otherX;
    
    u8 spriteId;
    u8 ramSlot;
    u16 offset;
    u8 collision;
    
    u16 ySpeedCap;
    u16 xSpeedCap;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;
    offset = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
    spriteId = gCurrentSprite.spriteId;

    for (ramSlot = gCurrentSprite.primarySpriteRamSlot + 1; ramSlot < MAX_AMOUNT_OF_SPRITES; ramSlot++)
    {
        if (!(gSpriteData[ramSlot].status & SPRITE_STATUS_EXISTS))
            continue;

        if (gSpriteData[ramSlot].properties & SP_SECONDARY_SPRITE)
            continue;
        
        if (gSpriteData[ramSlot].spriteId != spriteId)
            continue;

        otherY = gSpriteData[ramSlot].yPosition;
        otherX = gSpriteData[ramSlot].xPosition;

        if (yPosition + offset > otherY - offset && yPosition - offset < otherY + offset &&
            xPosition + offset > otherX - offset && xPosition - offset < otherX + offset)
        {
            if (gSpriteData[ramSlot].freezeTimer == 0)
            {
                if (yPosition > otherY)
                {
                    if (SpriteUtilGetCollisionAtPosition(otherY - HALF_BLOCK_SIZE, otherX) == COLLISION_AIR)
                        gSpriteData[ramSlot].yPosition -= PIXEL_SIZE;
                }
                else
                {
                    if (SpriteUtilGetCollisionAtPosition(otherY + HALF_BLOCK_SIZE, otherX) == COLLISION_AIR)
                        gSpriteData[ramSlot].yPosition += PIXEL_SIZE;
                }

                if (xPosition > otherX)
                {
                    if (SpriteUtilGetCollisionAtPosition(otherY, otherX - HALF_BLOCK_SIZE) == COLLISION_AIR)
                        gSpriteData[ramSlot].xPosition -= PIXEL_SIZE;
                }
                else
                {
                    if (SpriteUtilGetCollisionAtPosition(otherY, otherX + HALF_BLOCK_SIZE) == COLLISION_AIR)
                        gSpriteData[ramSlot].xPosition += PIXEL_SIZE;
                }
            }

            break;
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
    else
        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);

    if (collision != COLLISION_AIR)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.work1 = 0;
        gCurrentSprite.work2 = ONE_SUB_PIXEL;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition);
    else
        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition);

    if (collision != COLLISION_AIR)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_DOWN;
        gCurrentSprite.work0 = 0;
        gCurrentSprite.work3 = ONE_SUB_PIXEL;
    }

    otherY = gSamusData.yPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    otherX = gSamusData.xPosition;
    
    if (spriteId == PSPRITE_REO_PURPLE_WINGS)
    {
        ySpeedCap = HALF_BLOCK_SIZE;
        xSpeedCap = BLOCK_SIZE;
    }
    else
    {
        ySpeedCap = QUARTER_BLOCK_SIZE;
        xSpeedCap = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.xPosition > otherX - PIXEL_SIZE)
            {
                gCurrentSprite.work1 = gCurrentSprite.work2;
            }
            else
            {
                if (gCurrentSprite.work2 < xSpeedCap)
                    gCurrentSprite.work2++;

                gCurrentSprite.xPosition += DIV_SHIFT(gCurrentSprite.work2, 4);
            }
        }
        else
        {
            if (--gCurrentSprite.work1 != 0)
            {
                gCurrentSprite.xPosition += DIV_SHIFT(gCurrentSprite.work1, 4);
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.work2 = 1;
            }
        }
    }
    else
    {
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.xPosition < otherX + PIXEL_SIZE)
            {
                gCurrentSprite.work1 = gCurrentSprite.work2;
            }
            else
            {
                if (gCurrentSprite.work2 < xSpeedCap)
                    gCurrentSprite.work2++;

                gCurrentSprite.xPosition -= DIV_SHIFT(gCurrentSprite.work2, 4);
            }
        }
        else
        {
            if (--gCurrentSprite.work1 != 0)
            {
                gCurrentSprite.xPosition -= DIV_SHIFT(gCurrentSprite.work1, 4);
            }
            else
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.work2 = 1;
            }
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.work0 == 0)
        {
            if (gCurrentSprite.yPosition > otherY - PIXEL_SIZE)
            {
                gCurrentSprite.work0 = gCurrentSprite.work3;
            }
            else
            {
                if (gCurrentSprite.work3 < ySpeedCap)
                    gCurrentSprite.work3++;

                gCurrentSprite.yPosition += DIV_SHIFT(gCurrentSprite.work3, 4);
            }
        }
        else
        {
            if (--gCurrentSprite.work0 != 0)
            {
                gCurrentSprite.yPosition += DIV_SHIFT(gCurrentSprite.work0, 4);
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
                gCurrentSprite.work3 = 1;
            }
        }

        SpriteUtilCheckInRoomEffect(yPosition, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_SMALL);
    }
    else
    {
        if (gCurrentSprite.work0 == 0)
        {
            if (gCurrentSprite.yPosition < otherY + PIXEL_SIZE)
            {
                gCurrentSprite.work0 = gCurrentSprite.work3;
            }
            else
            {
                if (gCurrentSprite.work3 < ySpeedCap)
                    gCurrentSprite.work3++;

                gCurrentSprite.yPosition -= DIV_SHIFT(gCurrentSprite.work3, 4);
            }
        }
        else
        {
            if (--gCurrentSprite.work0 != 0)
            {
                gCurrentSprite.yPosition -= DIV_SHIFT(gCurrentSprite.work0, 4);
            }
            else
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                gCurrentSprite.work3 = 1;
            }
        }

        SpriteUtilCheckOutOfRoomEffect(yPosition, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_SMALL);
    }

    APPLY_DELTA_TIME_DEC(gCurrentSprite.scaling);
    if (gCurrentSprite.scaling == 0)
    {
        gCurrentSprite.scaling = CONVERT_SECONDS(.5f + 1.f / 30);
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_REO_MOVING);
    }
}

/**
 * @brief 1d1e4 | 134 | Reo AI
 * 
 */
void Reo(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_REO_DAMAGED);
    }

    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    if (SpriteUtilIsSpriteStunned())
        return;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ReoInit();
            break;

        case REO_POSE_IDLE_INIT:
            ReoIdleInit();
            break;

        case REO_POSE_IDLE:
            ReoIdle();
            break;

        case REO_POSE_MOVING_INIT:
            ReoMovingInit();

        case REO_POSE_MOVING:
            ReoMove();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
    }
}
