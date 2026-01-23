#include "sprites_ai/sidehopper.h"
#include "macros.h"

#include "data/sprites/sidehopper.h"
#include "data/sprite_data.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/particle.h"

#include "structs/sprite.h"

#define SIDEHOPPER_POSE_JUMP_WARNING_INIT 0x8
#define SIDEHOPPER_POSE_JUMP_WARNING 0x9
#define SIDEHOPPER_POSE_IDLE 0xF
#define SIDEHOPPER_POSE_FALLING 0x1F
#define SIDEHOPPER_POSE_JUMPING 0x23
#define SIDEHOPPER_POSE_LANDING 0x25

#define HEAD_HITBOX (BLOCK_SIZE + HALF_BLOCK_SIZE - PIXEL_SIZE)
#define FEET_HITBOX (0)
#define HEAD_DRAW_DISTANCE (SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE))
#define FEET_DRAW_DISTANCE (SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE))

/**
 * @brief 3f684 | 20 | Checks if samus is near the dessgeega on the sides in a 5 block range
 * 
 * @return u8 1 if near, 0 otherwise
 */
static u8 SidehopperCheckSamusNearLeftRight(void)
{
    u8 result;

    result = FALSE;
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 5, BLOCK_SIZE * 5) != NSLR_OUT_OF_RANGE)
    {
        result = TRUE;
        SpriteUtilMakeSpriteFaceSamusDirection();
    }

    return result;
}

/**
 * @brief 3f6a4 | d0 | Initializes a sidehopper sprite
 * 
 */
static void SidehopperInit(void)
{
    // Check for a ceiling block
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + PIXEL_SIZE), gCurrentSprite.xPosition);

    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
    {
        // Put on the ceiling if there's one
        gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
        gCurrentSprite.yPosition -= BLOCK_SIZE;
    }

    gCurrentSprite.work0 = 0;
    #ifdef BUGFIX
    gCurrentSprite.work1 = MOD_AND(gSpriteRng, 4);
    #endif // BUGFIX
    gCurrentSprite.pose = SIDEHOPPER_POSE_IDLE;

    if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
    {
        gCurrentSprite.drawDistanceTop = FEET_DRAW_DISTANCE;
        gCurrentSprite.drawDistanceBottom = HEAD_DRAW_DISTANCE;
        gCurrentSprite.hitboxTop = -FEET_HITBOX;
        gCurrentSprite.hitboxBottom = HEAD_HITBOX;
    }
    else
    {
        gCurrentSprite.drawDistanceTop = HEAD_DRAW_DISTANCE;
        gCurrentSprite.drawDistanceBottom = FEET_DRAW_DISTANCE;
        gCurrentSprite.hitboxTop = -HEAD_HITBOX;
        gCurrentSprite.hitboxBottom = FEET_HITBOX;
    }

    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE);
    gCurrentSprite.hitboxLeft = -(BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

    gCurrentSprite.pOam = sSidehopperOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    SpriteUtilChooseRandomXDirection();
}

/**
 * @brief 3f774 | 50 | Initializes a sidehopper to do the jump warning
 * 
 */
static void SidehopperJumpWarningInit(void)
{
    gCurrentSprite.pose = SIDEHOPPER_POSE_JUMP_WARNING;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sSidehopperOam_JumpWarning;
}

/**
 * @brief 3f794 | 80 | Initializes a sidehopper to jump
 * 
 */
static void SidehopperJumpingInit(void)
{
    gCurrentSprite.pose = SIDEHOPPER_POSE_JUMPING;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.pOam = sSidehopperOam_Jumping;

    if (MOD_AND(gSpriteRng, 2))
        gCurrentSprite.work2 = TRUE;
    else
        gCurrentSprite.work2 = FALSE;

    if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        gCurrentSprite.hitboxBottom = 0x70;
    else
        gCurrentSprite.hitboxTop = -0x70;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_SIDEHOPPER_JUMPING);
}

/**
 * @brief 3f814 | 50 | Initializes a sidehopper to land
 * 
 */
static void SidehopperLandingInit(void)
{
    gCurrentSprite.pose = SIDEHOPPER_POSE_LANDING;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pOam = sSidehopperOam_Landing;

    if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        gCurrentSprite.hitboxBottom = 0x5C;
    else
        gCurrentSprite.hitboxTop = -0x5C;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_SIDEHOPPER_LANDING);
}

/**
 * @brief 3f864 | 74 | Initializes a sidehopper to be idle
 * 
 */
static void SidehopperIdleInit(void)
{
    if (SidehopperCheckSamusNearLeftRight())
    {
        SidehopperJumpWarningInit();
        return;
    }

    gCurrentSprite.pose = SIDEHOPPER_POSE_IDLE;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work0 = 0;

    gCurrentSprite.work1 = MOD_AND(gSpriteRng, 4);

    if (gSpriteRng >= SPRITE_RNG_PROB(.5f))
    {
        gCurrentSprite.pOam = sSidehopperOam_Idle;
    }
    else
    {
        gCurrentSprite.pOam = sSidehopperOam_ShakingHead;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_SIDEHOPPER_SHAKING_HEAD);
    }
}

/**
 * @brief 3f8d8 | 24 | Initializes a sidehopper to be falling
 * 
 */
static void SidehopperFallingInit(void)
{
    gCurrentSprite.pose = SIDEHOPPER_POSE_FALLING;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.pOam = sSidehopperOam_Jumping;
}

/**
 * @brief 3f8fc | 5c | Handles a sidehopper doing the jump warning when on the ground
 * 
 */
static void SidehopperJumpWarningGround(void)
{
    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SidehopperFallingInit();
                return;
            }
        }
    }
    
    if (SpriteUtilHasCurrentAnimationEnded())
        SidehopperJumpingInit();
}

/**
 * @brief 3f958 | 14 | Handles a sidehopper doing the jump warning when on the ceiling
 * 
 */
static void SidehopperJumpWarningCeiling(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
        SidehopperJumpingInit();
}

/**
 * @brief 3f96c | 1e8 | Handles a sidehopper jumping when on the ground
 * 
 */
static void SidehopperJumpingGround(void)
{
    u8 colliding;
    u8 offset;
    s32 movement;
    u32 blockTop;

    colliding = FALSE;

    if (gCurrentSprite.work2)
        movement = sSidehopperLowJumpVelocity[gCurrentSprite.work3 / 4];
    else
        movement = sSidehopperHighJumpVelocity[gCurrentSprite.work3 / 4];

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxRight + PIXEL_SIZE);

        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            colliding++;
            gCurrentSprite.xPosition -= PIXEL_SIZE + PIXEL_SIZE / 2;
        }
        else if (movement > 0)
        {
            gCurrentSprite.xPosition += PIXEL_SIZE;
        }
        else
        {
            gCurrentSprite.xPosition += PIXEL_SIZE + ONE_SUB_PIXEL;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft - PIXEL_SIZE);

        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            colliding++;
            gCurrentSprite.xPosition += PIXEL_SIZE + PIXEL_SIZE / 2;
        }
        else if (movement > 0)
        {
            gCurrentSprite.xPosition -= PIXEL_SIZE;
        }
        else
        {
            gCurrentSprite.xPosition -= PIXEL_SIZE + ONE_SUB_PIXEL;
        }
    }

    gCurrentSprite.yPosition += movement;
    if (gCurrentSprite.work3 < ARRAY_SIZE(sSidehopperLowJumpVelocity) * 4 - 1)
        gCurrentSprite.work3++;

    if (movement > 0)
    {
        if (colliding)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;

        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            gCurrentSprite.yPosition = blockTop;
            SidehopperLandingInit();
            return;
        }

        if (!colliding)
        {
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                colliding++;
            else
            {
                blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
                if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                    colliding++;
            }
    
            if (colliding)
            {
                gCurrentSprite.yPosition = blockTop;
                SidehopperLandingInit();
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTop,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);

            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                colliding++;
                gCurrentSprite.xPosition -= PIXEL_SIZE + PIXEL_SIZE / 2;
                SidehopperFallingInit();
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTop,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);

            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                colliding++;
                gCurrentSprite.xPosition += PIXEL_SIZE + PIXEL_SIZE / 2;
                SidehopperFallingInit();
            }
        }

        if (colliding)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
    }
}

/**
 * @brief 3fb54 | 1fc | Handles a sidehopper jumping when on the ceiling
 * 
 */
static void SidehopperJumpingCeiling(void)
{
    u8 colliding;
    u8 offset;
    s32 movement;
    u32 blockTop;

    colliding = FALSE;

    if (gCurrentSprite.work2)
        movement = sSidehopperLowJumpVelocity[gCurrentSprite.work3 / 4];
    else
        movement = sSidehopperHighJumpVelocity[gCurrentSprite.work3 / 4];

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxRight + PIXEL_SIZE);

        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            colliding++;
            gCurrentSprite.xPosition -= PIXEL_SIZE + PIXEL_SIZE / 2;
        }
        else if (movement > 0)
        {
            gCurrentSprite.xPosition += PIXEL_SIZE;
        }
        else
        {
            gCurrentSprite.xPosition += PIXEL_SIZE + ONE_SUB_PIXEL;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft - PIXEL_SIZE);

        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            colliding++;
            gCurrentSprite.xPosition += PIXEL_SIZE + PIXEL_SIZE / 2;
        }
        else if (movement > 0)
        {
            gCurrentSprite.xPosition -= PIXEL_SIZE;
        }
        else
        {
            gCurrentSprite.xPosition -= PIXEL_SIZE + ONE_SUB_PIXEL;
        }
    }

    gCurrentSprite.yPosition -= movement;
    if (gCurrentSprite.work3 < ARRAY_SIZE(sSidehopperLowJumpVelocity) * 4 - 1)
        gCurrentSprite.work3++;

    if (movement < 0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxBottom,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);

            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                colliding++;
                gCurrentSprite.xPosition -= PIXEL_SIZE + PIXEL_SIZE / 2;
                SidehopperFallingInit();
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxBottom,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);

            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                colliding++;
                gCurrentSprite.xPosition += PIXEL_SIZE + PIXEL_SIZE / 2;
                SidehopperFallingInit();
            }
        }

        if (colliding)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
    }
    else
    {
        if (colliding)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;

        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
        {
            gCurrentSprite.yPosition = blockTop + BLOCK_SIZE;
            SidehopperLandingInit();
            return;
        }

        if (!colliding)
        {
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
            if (gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
            {
                colliding++;
            }
            else
            {
                blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
                if (gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F)
                    colliding++;
            }
    
            if (colliding)
            {
                gCurrentSprite.yPosition = blockTop + BLOCK_SIZE;
                SidehopperLandingInit();
            }
        }
    }
}

/**
 * @brief 3fd50 | 14 | Checks if the landing animation as ended
 * 
 */
static void SidehopperCheckLandingAnimEnded(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
        SidehopperIdleInit();
}

/**
 * @brief 3fd64 | a4 | Handles a dessgeega falling from the ground
 * 
 */
static void SidehopperFallingGround(void)
{
    u8 colliding;
    u32 blockTop;
    u8 offset;
    s32 movement;

    colliding = FALSE;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        colliding++;
    }
    else
    {
        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            colliding++;
        }
        else
        {
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                colliding++;
        }
    }

    if (colliding)
    {
        gCurrentSprite.yPosition = blockTop;
        SidehopperLandingInit();
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
 * @brief 3fe08 | a8 | Handles a dessgeega falling from the ceiling
 * 
 */
static void SidehopperFallingCeiling(void)
{
    u8 colliding;
    u32 blockTop;
    u8 offset;
    s32 movement;

    colliding = FALSE;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        colliding++;
    }
    else
    {
        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            colliding++;
        }
        else
        {
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                colliding++;
        }
    }

    if (colliding)
    {
        gCurrentSprite.yPosition = blockTop + BLOCK_SIZE;
        SidehopperLandingInit();
    }
    else
    {
        offset = gCurrentSprite.work3;
        movement = sSpritesFallingCeilingSpeed[offset];

        if (movement == SHORT_MAX)
        {
            movement = sSpritesFallingCeilingSpeed[offset - 1];
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
 * @brief 3feb0 | 9c | Handles a sidehopper being idle on the ground
 * 
 */
static void SidehopperIdleGround(void)
{
    if (SidehopperCheckSamusNearLeftRight())
    {
        SidehopperJumpWarningInit();
        return;
    }

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight);
    if (gPreviousCollisionCheck == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            SidehopperFallingInit();
            return;
        }
    }

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        if (gCurrentSprite.work0++ == gCurrentSprite.work1)
        {
            SidehopperJumpWarningInit();
        }
        else
        {
            if (gCurrentSprite.pOam == sSidehopperOam_ShakingHead && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(SOUND_SIDEHOPPER_SHAKING_HEAD);
        }
    }
}

/**
 * @brief 3ff4c | 5c | Handles a sidehopper being idle on the ceiling
 * 
 */
static void SidehopperIdleCeiling(void)
{
    if (SidehopperCheckSamusNearLeftRight())
    {
        SidehopperJumpWarningInit();
        return;
    }

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        if (gCurrentSprite.work0++ == gCurrentSprite.work1)
        {
            SidehopperJumpWarningInit();
        }
        else
        {
            if (gCurrentSprite.pOam == sSidehopperOam_ShakingHead && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(SOUND_SIDEHOPPER_SHAKING_HEAD);
        }
    }
}

/**
 * @brief 3ffa8 | 38 | Handles the death of a sidehopper
 * 
 */
static void SidehopperDeath(void)
{
    u16 yPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        yPosition = gCurrentSprite.yPosition + (THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE);
    else
        yPosition = gCurrentSprite.yPosition - (THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE);

    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
}

/**
 * @brief 3ffe0 | 198 | Sidehopper AI
 * 
 */
void Sidehopper(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_SIDEHOPPER_DAMAGED);
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
            SidehopperInit();
            break;

        case SIDEHOPPER_POSE_JUMP_WARNING_INIT:
            SidehopperJumpWarningInit();

        case SIDEHOPPER_POSE_JUMP_WARNING:
            if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
                SidehopperJumpWarningCeiling();
            else
                SidehopperJumpWarningGround();
            break;

        case SIDEHOPPER_POSE_JUMPING:
            if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
                SidehopperJumpingCeiling();
            else
                SidehopperJumpingGround();
            break;

        case SIDEHOPPER_POSE_LANDING:
            SidehopperCheckLandingAnimEnded();
            break;

        case SIDEHOPPER_POSE_IDLE:
            if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
                SidehopperIdleCeiling();
            else
                SidehopperIdleGround();
            break;

        case SIDEHOPPER_POSE_FALLING:
            if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
                SidehopperFallingCeiling();
            else
                SidehopperFallingGround();
            break;

        default:
            SidehopperDeath();
    }
}
