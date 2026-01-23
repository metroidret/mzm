#include "sprites_ai/viola.h"
#include "macros.h"

#include "data/sprites/viola.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"

#define VIOLA_POSE_MOVE_RIGHT 0x9
#define VIOLA_POSE_FALLING_INIT 0x1E
#define VIOLA_POSE_FALLING 0x1F
#define VIOLA_POSE_MOVE_LEFT 0x23
#define VIOLA_POSE_MOVE_DOWN 0x25
#define VIOLA_POSE_MOVE_UP 0x27

#define VIOLA_SPEED (PIXEL_SIZE / 2)

#define VIOLA_SIZE (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE)

/**
 * @brief 3743c | 120 | Initializes a viola sprite
 * 
 */
static void ViolaInit(void)
{
    SpriteUtilChooseRandomXDirection();
    gCurrentSprite.yPosition -= (HALF_BLOCK_SIZE);

    // Check for solid blocks around
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + (HALF_BLOCK_SIZE), gCurrentSprite.xPosition);
    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
    {
        gCurrentSprite.yPosition += EIGHTH_BLOCK_SIZE;
        gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE), gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        {
            gCurrentSprite.yPosition -= EIGHTH_BLOCK_SIZE;
            gCurrentSprite.pose = VIOLA_POSE_MOVE_LEFT;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE));
            if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
            {
                gCurrentSprite.xPosition -= EIGHTH_BLOCK_SIZE;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_DOWN;
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
                if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
                {
                    gCurrentSprite.xPosition += EIGHTH_BLOCK_SIZE;
                    gCurrentSprite.pose = VIOLA_POSE_MOVE_UP;
                }
                else
                {
                    gCurrentSprite.status = 0;
                    return;
                }
            }
        }
    }

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    gCurrentSprite.pOam = sViolaOam_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE);
    gCurrentSprite.hitboxBottom = QUARTER_BLOCK_SIZE + PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE);
    gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE + PIXEL_SIZE;

    // Set speed
    if (gCurrentSprite.spriteId == PSPRITE_VIOLA_ORANGE)
        gCurrentSprite.work2 = VIOLA_SPEED * 2;
    else
        gCurrentSprite.work2 = VIOLA_SPEED;
}

/**
 * @brief 3755c | 1a8 | Handles the viola moving to the right
 * 
 */
static void ViolaMoveRight(void)
{
    u16 velocity;
    u16 yPosition;
    u16 xPosition;
    u32 topEdge;

    velocity = gCurrentSprite.work2;
    yPosition = gCurrentSprite.yPosition + VIOLA_SIZE;
    xPosition = gCurrentSprite.xPosition;

    // Check should fall
    SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + (VIOLA_SIZE + PIXEL_SIZE));
    if (gPreviousCollisionCheck == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - HALF_BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            gCurrentSprite.pose = VIOLA_POSE_FALLING_INIT;
            return;
        }
    }

    // Handle slope movement
    topEdge = SpriteUtilCheckVerticalCollisionAtPosition(yPosition - PIXEL_SIZE, xPosition);
    if ((gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F) >= COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
    {
        gCurrentSprite.yPosition = topEdge - VIOLA_SIZE;
    }
    else
    {
        topEdge = SpriteUtilCheckVerticalCollisionAtPosition(yPosition, xPosition);
        if ((gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F) >= COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
        {
            gCurrentSprite.yPosition = topEdge - VIOLA_SIZE;
        }
        else
        {
            topEdge = SpriteUtilCheckVerticalCollisionAtPosition(yPosition + PIXEL_SIZE, xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                gCurrentSprite.yPosition = topEdge - VIOLA_SIZE;
        }
    }

    // Check should change direction or not
    yPosition = gCurrentSprite.yPosition + VIOLA_SIZE;
    if (gPreviousVerticalCollisionCheck == COLLISION_AIR || (gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - VIOLA_SIZE);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + VIOLA_SIZE);
                if (gPreviousCollisionCheck == COLLISION_AIR)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    gCurrentSprite.pose = VIOLA_POSE_MOVE_DOWN;
                }
                else
                {
                    gCurrentSprite.xPosition += velocity;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(yPosition - PIXEL_SIZE, xPosition + VIOLA_SIZE);
                if (gPreviousCollisionCheck == COLLISION_SOLID)
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    gCurrentSprite.pose = VIOLA_POSE_MOVE_UP;
                }
                else
                {
                    gCurrentSprite.xPosition += velocity;
                }
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + (VIOLA_SIZE - PIXEL_SIZE));
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - (VIOLA_SIZE + PIXEL_SIZE));
                if (gPreviousCollisionCheck == COLLISION_AIR)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    gCurrentSprite.pose = VIOLA_POSE_MOVE_UP;
                }
                else
                {
                    gCurrentSprite.xPosition -= velocity;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(yPosition - PIXEL_SIZE, xPosition - (VIOLA_SIZE + PIXEL_SIZE));
                if (gPreviousCollisionCheck == COLLISION_SOLID)
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    gCurrentSprite.pose = VIOLA_POSE_MOVE_DOWN;
                }
                else
                {
                    gCurrentSprite.xPosition -= velocity;
                }
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.xPosition += velocity;
        else
            gCurrentSprite.xPosition -= velocity;
    }
}

/**
 * @brief 37704 | 148 | Handles the viola moving left
 * 
 */
static void ViolaMoveLeft(void)
{
    u16 velocity;
    u16 yPosition;
    u16 xPosition;
    u32 blockY;

    blockY = gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
    gCurrentSprite.yPosition += VIOLA_SIZE;

    velocity = gCurrentSprite.work2;
    yPosition = blockY - PIXEL_SIZE;
    xPosition = gCurrentSprite.xPosition;

    // Check should fall
    SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + (VIOLA_SIZE + PIXEL_SIZE));
    if (gPreviousCollisionCheck == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - HALF_BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            gCurrentSprite.pose = VIOLA_POSE_FALLING_INIT;
            return;
        }
    }

    // Check should change direction or not
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - VIOLA_SIZE);
        if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + VIOLA_SIZE);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_DOWN;
            }
            else
                gCurrentSprite.xPosition += velocity;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + PIXEL_SIZE, xPosition + VIOLA_SIZE);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_UP;
            }
            else
                gCurrentSprite.xPosition += velocity;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + (VIOLA_SIZE - PIXEL_SIZE));
        if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - (VIOLA_SIZE + PIXEL_SIZE));
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_UP;
            }
            else
                gCurrentSprite.xPosition -= velocity;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + PIXEL_SIZE, xPosition - (VIOLA_SIZE + PIXEL_SIZE));
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_DOWN;
            }
            else
                gCurrentSprite.xPosition -= velocity;
        }
    }
}

/**
 * @brief 3784c | 148 | Handles a viola moving down
 * 
 */
static void ViolaMoveDown(void)
{
    u16 velocity;
    u16 yPosition;
    u16 xPosition;
    u32 blockX;

    blockX = gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
    gCurrentSprite.xPosition += VIOLA_SIZE;

    velocity = gCurrentSprite.work2;
    yPosition = gCurrentSprite.yPosition;
    xPosition = blockX - PIXEL_SIZE;

    // Check should fall
    SpriteUtilCheckCollisionAtPosition(yPosition + (VIOLA_SIZE + PIXEL_SIZE), xPosition);
    if (gPreviousCollisionCheck == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - (VIOLA_SIZE + EIGHTH_BLOCK_SIZE), xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            gCurrentSprite.pose = VIOLA_POSE_FALLING_INIT;
            return;
        }
    }

    // Check should change direction or not
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - VIOLA_SIZE, xPosition);
        if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + VIOLA_SIZE, xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_LEFT;
            }
            else
            {
                gCurrentSprite.yPosition += velocity;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + VIOLA_SIZE, xPosition + PIXEL_SIZE);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
            }
            else
            {
                gCurrentSprite.yPosition += velocity;
            }
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(yPosition + (VIOLA_SIZE - PIXEL_SIZE), xPosition);
        if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition - (VIOLA_SIZE + PIXEL_SIZE), xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
            }
            else
            {
                gCurrentSprite.yPosition -= velocity;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition - (VIOLA_SIZE + PIXEL_SIZE), xPosition + PIXEL_SIZE);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_LEFT;
            }
            else
            {
                gCurrentSprite.yPosition -= velocity;
            }
        }
    }
}

/**
 * @brief 37994 | 14c | Handles the viola moving up
 * 
 */
static void ViolaMoveUp(void)
{
    u16 velocity;
    u16 yPosition;
    u16 xPosition;
    u32 blockX;

    blockX = gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
    gCurrentSprite.xPosition += HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

    velocity = gCurrentSprite.work2;
    yPosition = gCurrentSprite.yPosition;
    xPosition = blockX + BLOCK_SIZE;

    // Check should fall
    SpriteUtilCheckCollisionAtPosition(yPosition + (VIOLA_SIZE + PIXEL_SIZE), xPosition);
    if (gPreviousCollisionCheck == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            gCurrentSprite.pose = VIOLA_POSE_FALLING_INIT;
            return;
        }
    }

    // Check should change direction or not
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - VIOLA_SIZE, xPosition);
        if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + VIOLA_SIZE, xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_LEFT;
            }
            else
            {
                gCurrentSprite.yPosition += velocity;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + VIOLA_SIZE, xPosition - PIXEL_SIZE);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
            }
            else
            {
                gCurrentSprite.yPosition += velocity;
            }
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(yPosition + (VIOLA_SIZE - PIXEL_SIZE), xPosition);
        if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition - (VIOLA_SIZE + PIXEL_SIZE), xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
            }
            else
            {
                gCurrentSprite.yPosition -= velocity;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition - (VIOLA_SIZE + PIXEL_SIZE), xPosition - PIXEL_SIZE);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_LEFT;
            }
            else
            {
                gCurrentSprite.yPosition -= velocity;
            }
        }
    }
}

/**
 * @brief 37ae0 | 18 | Initializes a viola to be falling
 * 
 */
static void ViolaFallingInit(void)
{
    gCurrentSprite.pose = VIOLA_POSE_FALLING;
    gCurrentSprite.work3 = 0;
}

/**
 * @brief 37af8 | 78 | Handles a viola falling
 * 
 */
static void ViolaFalling(void)
{
    u8 offset;
    s32 movement;
    u32 topEdge;

    topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition + VIOLA_SIZE, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.yPosition = topEdge - VIOLA_SIZE;
        gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
        SpriteUtilChooseRandomXDirection();
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
            gCurrentSprite.work3 = offset + 1;
            gCurrentSprite.yPosition += movement;
        }
    }
}

/**
 * @brief 37b70 | 14c | Viola AI
 * 
 */
void Viola(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_VIOLA_DAMAGED);
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
            ViolaInit();
            break;

        case VIOLA_POSE_MOVE_RIGHT:
            ViolaMoveRight();
            break;

        case VIOLA_POSE_MOVE_LEFT:
            ViolaMoveLeft();
            break;

        case VIOLA_POSE_MOVE_DOWN:
            ViolaMoveDown();
            break;

        case VIOLA_POSE_MOVE_UP:
            ViolaMoveUp();
            break;

        case VIOLA_POSE_FALLING_INIT:
            ViolaFallingInit();

        case VIOLA_POSE_FALLING:
            ViolaFalling();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
    }
}
