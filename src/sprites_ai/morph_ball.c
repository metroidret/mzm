#include "sprites_ai/morph_ball.h"
#include "macros.h"

#include "data/sprites/morph_ball.h"

#include "constants/sprite.h"
#include "constants/samus.h"
#include "constants/text.h"

#include "structs/sprite.h"
#include "structs/samus.h"

#define MORPH_BALL_POSE_IDLE 0x9
#define MORPH_BALL_POSE_BEING_ACQUIRED 0x23

#define MORPH_BALL_OUTSIDE_POSE_IDLE 0x9

/**
 * @brief 13080 | ac | Initializes a morph ball sprite
 * 
 */
static void MorphBallInit(void)
{
    if (gEquipment.suitMisc & SMF_MORPH_BALL)
    {
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE - PIXEL_SIZE);
    gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE - PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE - PIXEL_SIZE);
    gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE - PIXEL_SIZE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

    gCurrentSprite.pOam = sMorphBallOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.samusCollision = SSC_CHECK_COLLIDING;
    gCurrentSprite.health = 1;
    gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
    gCurrentSprite.pose = MORPH_BALL_POSE_IDLE;
    gCurrentSprite.drawOrder = 3;

    // Spawn outside
    SpriteSpawnSecondary(SSPRITE_MORPH_BALL_OUTSIDE, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
}

/**
 * @brief 1312c | 74 | Handles a morph ball sprite being idle
 * 
 */
static void MorphBallGet(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gPreventMovementTimer = SAMUS_ITEM_PMT;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

        gCurrentSprite.pose = MORPH_BALL_POSE_BEING_ACQUIRED;

        gCurrentSprite.work0 = 0;

        // Give morph ball
        gEquipment.suitMisc |= SMF_MORPH_BALL;

        SpriteSpawnPrimary(PSPRITE_MESSAGE_BANNER, MESSAGE_MORPH_BALL, SPRITE_GFX_SLOT_SPECIAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    }
}

/**
 * @brief 131a0 | 3c | Handles a morph ball being acquired
 * 
 */
static void MorphBallFlashAnim(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    // Flicker (timer will always be 0 though)
    if (MOD_AND(gCurrentSprite.work0, 2) == 0)
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    // Check message banner disappeared
    if (gPreventMovementTimer < SAMUS_ITEM_PMT - 1 * DELTA_TIME)
        gCurrentSprite.status = 0;
}

/**
 * @brief 131dc | 58 | Initializes a morph ball outside sprite
 * 
 */
static void MorphBallOutsideInit(void)
{
    gCurrentSprite.hitboxTop = -PIXEL_SIZE;
    gCurrentSprite.hitboxBottom = PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
    gCurrentSprite.hitboxRight = PIXEL_SIZE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

    gCurrentSprite.pOam = sMorphBallOutsideOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawOrder = 2;
    gCurrentSprite.pose = MORPH_BALL_OUTSIDE_POSE_IDLE;
}

/**
 * @brief 13234 | 3c | Handles a morph ball outside being acquired 
 * 
 */
static void MorphBallOutsideFlashAnim(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    gCurrentSprite.status = gSpriteData[ramSlot].status;

    if (gSpriteData[ramSlot].properties & SP_ALWAYS_ACTIVE)
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
}

/**
 * @brief 13270 | 38 | Morph ball AI
 * 
 */
void MorphBall(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            MorphBallInit();
            break;

        case MORPH_BALL_POSE_IDLE:
            MorphBallGet();
            break;

        case MORPH_BALL_POSE_BEING_ACQUIRED:
            MorphBallFlashAnim();
    }
}

/**
 * @brief 132a8 | 2c | Morph ball outside AI
 * 
 */
void MorphBallOutside(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            MorphBallOutsideInit();

        case MORPH_BALL_OUTSIDE_POSE_IDLE:
            MorphBallOutsideFlashAnim();
    }
}
