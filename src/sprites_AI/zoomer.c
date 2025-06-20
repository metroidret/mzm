#include "sprites_AI/zoomer.h"
#include "macros.h"

#include "data/sprites/zoomer.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/game_state.h"
#include "structs/sprite.h"

#define ZOOMER_TURNING_DIRECTION work1
#define ZOOMER_FALLING_SPEED_OFFSET work3

/**
 * @brief 16694 | 96 | Checks if a zoomer is colliding with air
 * 
 * @return u8 bool, colliding with air
 */
u8 ZoomerCheckCollidingWithAir(void)
{
    u8 colliding;

    colliding = FALSE;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition) == COLLISION_AIR &&
                SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition) == COLLISION_AIR)
                colliding = TRUE;
        }
        else
        {
            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition - PIXEL_SIZE) == COLLISION_AIR &&
                SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition - PIXEL_SIZE) == COLLISION_AIR)
                colliding = TRUE;
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - PIXEL_SIZE, gCurrentSprite.xPosition - HALF_BLOCK_SIZE) == COLLISION_AIR &&
                SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - PIXEL_SIZE, gCurrentSprite.xPosition + HALF_BLOCK_SIZE) == COLLISION_AIR)
                colliding = TRUE;
        }
        else
        {
            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - HALF_BLOCK_SIZE) == COLLISION_AIR &&
                SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE) == COLLISION_AIR)
                colliding = TRUE;
        }
    }

    return colliding;
}

/**
 * @brief 16728 | 80 | Updates the hitbox of a zoomer
 * 
 */
void ZoomerUpdateHitbox(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE - PIXEL_SIZE);
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE - PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -(THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE);
            gCurrentSprite.hitboxRight = PIXEL_SIZE;
        }
        else
        {
            gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE - PIXEL_SIZE);
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE - PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
            gCurrentSprite.hitboxRight = THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE;
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
            gCurrentSprite.hitboxTop = -PIXEL_SIZE;
            gCurrentSprite.hitboxBottom = THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE - PIXEL_SIZE);
            gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE - PIXEL_SIZE;
        }
        else
        {
            gCurrentSprite.hitboxTop = -(THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE);
            gCurrentSprite.hitboxBottom = PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE - PIXEL_SIZE);
            gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE - PIXEL_SIZE;
        }
    }
}

/**
 * @brief 167a8 | 30 | Sets the crawling OAM for a zoomer
 * 
 */
void ZoomerSetCrawlingOAM(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        gCurrentSprite.pOam = sZoomerOAM_OnWall;
    else
        gCurrentSprite.pOam = sZoomerOAM_OnGround;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 167d8 | 30 | Sets the falling OAM for a zoomer
 * 
 */
void ZoomerSetFallingOAM(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        gCurrentSprite.pOam = sZoomerOAM_OnWall;
    else
        gCurrentSprite.pOam = sZoomerOAM_Falling;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 16808 | 114 | Initializes a zoomer sprite
 * 
 */
void ZoomerInit(void)
{
    SpriteUtilChooseRandomXDirection();
    gCurrentSprite.pose = ZOOMER_POSE_IDLE;

    // Check surroundings
    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) & COLLISION_FLAGS_UNKNOWN_F0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
    }
    else if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + PIXEL_SIZE), gCurrentSprite.xPosition) & COLLISION_FLAGS_UNKNOWN_F0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
        gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
        gCurrentSprite.yPosition -= BLOCK_SIZE;
    }
    else if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE)) & COLLISION_FLAGS_UNKNOWN_F0)
    {
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
        gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
        gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
    }
    else if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition + HALF_BLOCK_SIZE) & COLLISION_FLAGS_UNKNOWN_F0)
    {
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
        gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
        gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
    }
    else
    {
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    ZoomerSetCrawlingOAM();
    ZoomerUpdateHitbox();

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    // Check set other palette
    if (gCurrentSprite.spriteId == PSPRITE_ZOOMER_RED)
    {
        gCurrentSprite.absolutePaletteRow = 1;
        gCurrentSprite.paletteRow = 1;
    }
}

/**
 * @brief 1691c | 18 | Initializes a zoomer to be idle
 * 
 */
void ZoomerIdleInit(void)
{
    ZoomerSetCrawlingOAM();
    gCurrentSprite.pose = ZOOMER_POSE_IDLE;
}

/**
 * @brief 16934 | 3e8 | Handles a zoomer crawling
 * 
 */
void ZoomerCrawling(void)
{
    u16 speed;
    u8 turning;
    u8 collision;

    if (gCurrentSprite.spriteId == PSPRITE_ZOOMER_RED)
        speed = PIXEL_SIZE * 3 / 4;
    else
        speed = PIXEL_SIZE / 2;

    turning = FALSE;

    if (ZoomerCheckCollidingWithAir())
    {
        gCurrentSprite.pose = ZOOMER_POSE_FALLING_INIT;
        return;
    }

    if (SpriteUtilShouldFall())
    {
        if (gCurrentSprite.status & (SPRITE_STATUS_Y_FLIP | SPRITE_STATUS_FACING_DOWN))
            gCurrentSprite.pose = ZOOMER_POSE_FALLING_INIT;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
                if (!(collision & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.ZOOMER_TURNING_DIRECTION = ZOOMER_TURNING_DIRECTION_BOTTOM_LEFT_EDGE;
                }
                else
                {
                    collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition - PIXEL_SIZE);
                    if (collision == COLLISION_SOLID)
                    {
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.ZOOMER_TURNING_DIRECTION = ZOOMER_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER;
                    }
                    else
                        gCurrentSprite.yPosition += speed;
                }
            }
            else
            {
                collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - PIXEL_SIZE, gCurrentSprite.xPosition);
                if (!(collision & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.ZOOMER_TURNING_DIRECTION = ZOOMER_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER;
                }
                else
                {
                    collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition - PIXEL_SIZE);
                    if (collision == COLLISION_SOLID)
                    {
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.ZOOMER_TURNING_DIRECTION = ZOOMER_TURNING_DIRECTION_BOTTOM_LEFT_EDGE;
                    }
                    else
                        gCurrentSprite.yPosition -= speed;
                }
            }
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - PIXEL_SIZE);
                if (!(collision & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.ZOOMER_TURNING_DIRECTION = ZOOMER_TURNING_DIRECTION_TOP_LEFT_CORNER;
                }
                else
                {
                    collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition);
                    if (collision == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.ZOOMER_TURNING_DIRECTION = ZOOMER_TURNING_DIRECTION_TOP_LEFT_EDGE;
                    }
                    else
                        gCurrentSprite.yPosition += speed;
                }
            }
            else
            {
                collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - PIXEL_SIZE, gCurrentSprite.xPosition - PIXEL_SIZE);
                if (!(collision & COLLISION_FLAGS_UNKNOWN_F0))
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.ZOOMER_TURNING_DIRECTION = ZOOMER_TURNING_DIRECTION_TOP_LEFT_EDGE;
                }
                else
                {
                    collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition);
                    if (collision == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.ZOOMER_TURNING_DIRECTION = ZOOMER_TURNING_DIRECTION_TOP_LEFT_CORNER;
                    }
                    else
                        gCurrentSprite.yPosition -= speed;
                }
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - PIXEL_SIZE, gCurrentSprite.xPosition);
                if (!(collision & COLLISION_FLAGS_UNKNOWN_F))
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.ZOOMER_TURNING_DIRECTION = ZOOMER_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE;
                }
                else
                {
                    collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
                    if (collision == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.ZOOMER_TURNING_DIRECTION = ZOOMER_TURNING_DIRECTION_TOP_RIGHT_CORNER;
                    }
                    else
                        gCurrentSprite.xPosition += speed;
                }
            }
            else
            {
                collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - PIXEL_SIZE, gCurrentSprite.xPosition - PIXEL_SIZE);
                if (!(collision & COLLISION_FLAGS_UNKNOWN_F))
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.ZOOMER_TURNING_DIRECTION = ZOOMER_TURNING_DIRECTION_TOP_RIGHT_CORNER;
                }
                else
                {
                    collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
                    if (collision == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.ZOOMER_TURNING_DIRECTION = ZOOMER_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE;
                    }
                    else
                        gCurrentSprite.xPosition -= speed;
                }
            }
        }
        else
        {
            unk_f594();

            if (gPreviousVerticalCollisionCheck == COLLISION_AIR || gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
            {
                if (gCurrentSprite.pOam != sZoomerOAM_OnGround)
                {
                    gCurrentSprite.pOam = sZoomerOAM_OnGround;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
                    if (collision == COLLISION_AIR)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.ZOOMER_TURNING_DIRECTION = ZOOMER_TURNING_DIRECTION_BOTTOM_LEFT_CORNER;
                    }
                    else
                    {
                        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - PIXEL_SIZE, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
                        if (collision == COLLISION_SOLID)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                            turning = TRUE;
                            gCurrentSprite.ZOOMER_TURNING_DIRECTION = ZOOMER_TURNING_DIRECTION_TOP_RIGHT_EDGE;
                        }
                        else
                            gCurrentSprite.xPosition += speed;
                    }
                }
                else
                {
                    collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - PIXEL_SIZE);
                    if (collision == COLLISION_AIR)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.ZOOMER_TURNING_DIRECTION = ZOOMER_TURNING_DIRECTION_TOP_RIGHT_EDGE;
                    }
                    else
                    {
                        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - PIXEL_SIZE, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
                        if (collision == COLLISION_SOLID)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                            turning = TRUE;
                            gCurrentSprite.ZOOMER_TURNING_DIRECTION = ZOOMER_TURNING_DIRECTION_BOTTOM_LEFT_CORNER;
                        }
                        else
                            gCurrentSprite.xPosition -= speed;
                    }
                }
            }
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gPreviousVerticalCollisionCheck == COLLISION_LEFT_SLIGHT_FLOOR_SLOPE || gPreviousVerticalCollisionCheck == COLLISION_LEFT_STEEP_FLOOR_SLOPE)
                    {
                        if (gCurrentSprite.pOam != sZoomerOAM_WalkingOnLeftSlope)
                        {
                            gCurrentSprite.pOam = sZoomerOAM_WalkingOnLeftSlope;
                            gCurrentSprite.animationDurationCounter = 0;
                            gCurrentSprite.currentAnimationFrame = 0;
                        }

                        gCurrentSprite.xPosition += speed;
                    }
                    else
                    {
                        if (gCurrentSprite.pOam != sZoomerOAM_WalkingOnRightSlope)
                        {
                            gCurrentSprite.pOam = sZoomerOAM_WalkingOnRightSlope;
                            gCurrentSprite.animationDurationCounter = 0;
                            gCurrentSprite.currentAnimationFrame = 0;
                        }

                        gCurrentSprite.xPosition += (speed * 2 / 3);

                        // 2 * DELTA_TIME
                        if (MOD_AND(gFrameCounter8Bit, 2) && gCurrentSprite.animationDurationCounter != 0)
                            APPLY_DELTA_TIME_DEC(gCurrentSprite.animationDurationCounter);
                    }
                }
                else
                {
                    if (gPreviousVerticalCollisionCheck == COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE || gPreviousVerticalCollisionCheck == COLLISION_RIGHT_STEEP_FLOOR_SLOPE)
                    {
                        if (gCurrentSprite.pOam != sZoomerOAM_WalkingOnRightSlope)
                        {
                            gCurrentSprite.pOam = sZoomerOAM_WalkingOnRightSlope;
                            gCurrentSprite.animationDurationCounter = 0;
                            gCurrentSprite.currentAnimationFrame = 0;
                        }

                        gCurrentSprite.xPosition -= speed;
                    }
                    else
                    {
                        if (gCurrentSprite.pOam != sZoomerOAM_WalkingOnLeftSlope)
                        {
                            gCurrentSprite.pOam = sZoomerOAM_WalkingOnLeftSlope;
                            gCurrentSprite.animationDurationCounter = 0;
                            gCurrentSprite.currentAnimationFrame = 0;
                        }

                        gCurrentSprite.xPosition -= (speed * 2 / 3);

                        // 2 * DELTA_TIME
                        if (MOD_AND(gFrameCounter8Bit, 2) && gCurrentSprite.animationDurationCounter != 0)
                            APPLY_DELTA_TIME_DEC(gCurrentSprite.animationDurationCounter);
                    }
                }
            }
        }
    }

    if (turning)
        gCurrentSprite.pose = ZOOMER_POSE_TURNING_AROUND_INIT;
}

/**
 * @brief 16d1c | 194 | Initializes a zoomer to be turning around
 * 
 */
void ZoomerTurningAroundInit(void)
{
    gCurrentSprite.pose = ZOOMER_POSE_TURNING_AROUND;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    switch (gCurrentSprite.ZOOMER_TURNING_DIRECTION)
    {
        case ZOOMER_TURNING_DIRECTION_BOTTOM_LEFT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZoomerOAM_TurningEdgeLeft;
            else
                gCurrentSprite.pOam = sZoomerOAM_TurningCornerRight;

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
            break;

        case ZOOMER_TURNING_DIRECTION_TOP_RIGHT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZoomerOAM_TurningEdgeLeft;
            else
                gCurrentSprite.pOam = sZoomerOAM_TurningCornerRight;

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
            break;

        case ZOOMER_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZoomerOAM_TurningCornerRight;
            else
                gCurrentSprite.pOam = sZoomerOAM_TurningEdgeLeft;

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            break;

        case ZOOMER_TURNING_DIRECTION_TOP_RIGHT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZoomerOAM_TurningCornerRight;
            else
                gCurrentSprite.pOam = sZoomerOAM_TurningEdgeLeft;

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            break;
        
        case ZOOMER_TURNING_DIRECTION_TOP_LEFT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZoomerOAM_TurningCornerLeft;
            else
                gCurrentSprite.pOam = sZoomerOAM_TurningEdgeRight;

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
            break;

        case ZOOMER_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZoomerOAM_TurningEdgeRight;
            else
                gCurrentSprite.pOam = sZoomerOAM_TurningCornerLeft;

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
            break;

        case ZOOMER_TURNING_DIRECTION_TOP_LEFT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZoomerOAM_TurningCornerLeft;
            else
                gCurrentSprite.pOam = sZoomerOAM_TurningEdgeRight;

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            break;

        case ZOOMER_TURNING_DIRECTION_BOTTOM_LEFT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZoomerOAM_TurningEdgeRight;
            else
                gCurrentSprite.pOam = sZoomerOAM_TurningCornerLeft;

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 16eb0 | 1cc | Handles a zoomer turning around
 * 
 */
void ZoomerTurningAround(void)
{
    if (!SpriteUtilCheckEndCurrentSpriteAnim())
        return;

    gCurrentSprite.pose = ZOOMER_POSE_IDLE;

    switch (gCurrentSprite.ZOOMER_TURNING_DIRECTION)
    {
        case ZOOMER_TURNING_DIRECTION_BOTTOM_LEFT_CORNER:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.yPosition -= HALF_BLOCK_SIZE - PIXEL_SIZE;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
            }

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            break;

        case ZOOMER_TURNING_DIRECTION_TOP_RIGHT_EDGE:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition += BLOCK_SIZE;
            }

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            break;

        case ZOOMER_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition += HALF_BLOCK_SIZE - PIXEL_SIZE;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
            }

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            break;

        case ZOOMER_TURNING_DIRECTION_TOP_RIGHT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition += HALF_BLOCK_SIZE;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition += BLOCK_SIZE;
            }

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            break;

        case ZOOMER_TURNING_DIRECTION_TOP_LEFT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.yPosition += BLOCK_SIZE;
            }
            else
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;

            gCurrentSprite.status &= ~(SPRITE_STATUS_X_FLIP | SPRITE_STATUS_Y_FLIP);
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            break;
        
        case ZOOMER_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.yPosition += BLOCK_SIZE;
            }
            else
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;

            gCurrentSprite.status &= ~(SPRITE_STATUS_X_FLIP | SPRITE_STATUS_Y_FLIP);
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            break;

        case ZOOMER_TURNING_DIRECTION_TOP_LEFT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition += HALF_BLOCK_SIZE - PIXEL_SIZE;
            }

            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            break;
        
        case ZOOMER_TURNING_DIRECTION_BOTTOM_LEFT_EDGE:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
            }

            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            break;

        default:
            gCurrentSprite.status = 0;
    }

    ZoomerSetCrawlingOAM();
    ZoomerUpdateHitbox();
}

/**
 * @brief 1707c | 18 | Initializes a zoomer to be landing (unused)
 * 
 */
void ZoomerLandingInit_Unused(void)
{
    gCurrentSprite.pose = ZOOMER_POSE_LANDING;
    ZoomerSetFallingOAM();
}

/**
 * @brief 17094 | 30 | Handles a zoomer landing
 * 
 */
void ZoomerLanding(void)
{
    if (ZoomerCheckCollidingWithAir())
        gCurrentSprite.pose = ZOOMER_POSE_FALLING_INIT;
    else if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = ZOOMER_POSE_IDLE_INIT;
}

/**
 * @brief 170c4 | 68 | Initializes a zoomer to be falling
 * 
 */
void ZoomerFallingInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
        else
            gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
    }
    else if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        gCurrentSprite.yPosition += HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

    gCurrentSprite.pose = ZOOMER_POSE_FALLING;
    gCurrentSprite.ZOOMER_FALLING_SPEED_OFFSET = 0;
    gCurrentSprite.status &= ~(SPRITE_STATUS_X_FLIP | SPRITE_STATUS_Y_FLIP | SPRITE_STATUS_FACING_DOWN);

    ZoomerUpdateHitbox();
    ZoomerSetFallingOAM();
}

/**
 * @brief 1712c | 84 | Handles a zoomer falling
 * 
 */
void ZoomerFalling(void)
{
    u16 yPosition;
    u8 offset;
    s32 movement;
    u32 blockTop;
    s32 newMovement;

    yPosition = gCurrentSprite.yPosition;

    offset = gCurrentSprite.ZOOMER_FALLING_SPEED_OFFSET;
    movement = sSpritesFallingSpeed[offset];

    if (movement == SHORT_MAX)
    {
        newMovement = sSpritesFallingSpeed[offset - 1];
        gCurrentSprite.yPosition += newMovement;
    }
    else
    {
        gCurrentSprite.ZOOMER_FALLING_SPEED_OFFSET++;
        gCurrentSprite.yPosition += movement;
    }

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.yPosition = blockTop;
        gCurrentSprite.pose = ZOOMER_POSE_LANDING;
        SpriteUtilChooseRandomXDirection();
    }
    else
        SpriteUtilCheckInRoomEffect(yPosition, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_BIG);
}

/**
 * @brief 171b0 | 5c | Handles a zoomer dying
 * 
 */
void ZoomerDeath(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            xPosition -= HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
        else
            xPosition += HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
            yPosition += HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
        else
            yPosition -= HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
    }

    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
}

/**
 * @brief 1720c | 11c | Zoomer AI
 * 
 */
void Zoomer(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_ZOOMER_DAMAGED);
    }

    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
    }
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;

        switch (gCurrentSprite.pose)
        {
            case SPRITE_POSE_UNINITIALIZED:
                ZoomerInit();
                break;

            case ZOOMER_POSE_IDLE_INIT:
                ZoomerIdleInit();

            case ZOOMER_POSE_IDLE:
                ZoomerCrawling();
                break;

            case ZOOMER_POSE_TURNING_AROUND_INIT:
                ZoomerTurningAroundInit();

            case ZOOMER_POSE_TURNING_AROUND:
                ZoomerTurningAround();
                break;

            case ZOOMER_POSE_LANDING_INIT:
                ZoomerLandingInit_Unused();

            case ZOOMER_POSE_LANDING:
                ZoomerLanding();
                break;

            case ZOOMER_POSE_FALLING_INIT:
                ZoomerFallingInit();

            case ZOOMER_POSE_FALLING:
                ZoomerFalling();
                break;

            default:
                ZoomerDeath();
        }
    }
}
