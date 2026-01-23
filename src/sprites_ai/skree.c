#include "sprites_ai/skree.h"
#include "macros.h"
#include "gba/display.h"

#include "data/sprites/skree.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/display.h"
#include "structs/sprite.h"
#include "structs/samus.h"

#define SKREE_POSE_IDLE_INIT 0x8
#define SKREE_POSE_IDLE 0x9
#define SKREE_POSE_SPINNING_INIT 0x22
#define SKREE_POSE_SPINNING 0x23
#define SKREE_POSE_GOING_DOWN_INIT 0x34
#define SKREE_POSE_GOING_DOWN 0x35
#define SKREE_POSE_CRASHING 0x37

#define SKREE_EXPLOSION_PART_GOING_UP 0x0
#define SKREE_EXPLOSION_PART_GOING_DOWN 0x1

#define SKREE_EXPLOSION_POSE_MOVING 0x9

#define SKREE_Y_RANGE (BLOCK_SIZE * 10 + PIXEL_SIZE)
#define SKREE_X_RANGE (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2)

/**
 * @brief 1c644 | 50 | Initializes a skree sprite
 * 
 */
static void SkreeInit(void)
{
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(0);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    gCurrentSprite.hitboxTop = 0;
    gCurrentSprite.hitboxBottom = BLOCK_SIZE + HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.yPosition -= BLOCK_SIZE;
}

/**
 * @brief 1c694 | 1c | Initializes a skree to be idle
 * 
 */
static void SkreeIdleInit(void)
{
    gCurrentSprite.pOam = sSkreeOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = SKREE_POSE_IDLE;
}

/**
 * @brief 1c6b0 | 50 | Checks if samus is in the range of the skree
 * 
 */
static void SkreeDetectSamus(void)
{
    if (gSamusData.yPosition <= gCurrentSprite.yPosition)
        return;

    if (gSamusData.yPosition - gCurrentSprite.yPosition >= SKREE_Y_RANGE)
        return;

    if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
        return;

    if (gSamusData.xPosition <= gCurrentSprite.xPosition - SKREE_X_RANGE)
        return;

    if (gSamusData.xPosition >= gCurrentSprite.xPosition + SKREE_X_RANGE)
        return;

    // Set spinning
    gCurrentSprite.pose = SKREE_POSE_SPINNING_INIT;
}

/**
 * @brief 1c700 | 1c | Initializes a skree to be spinning
 * 
 */
static void SkreeSpinningInit(void)
{
    gCurrentSprite.pOam = sSkreeOam_Spinning;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = SKREE_POSE_SPINNING;
}

/**
 * @brief 1c71c | 1c | Checks if the spin animation ended
 * 
 */
static void SkreeCheckSpinAnimEnded(void)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        gCurrentSprite.pose = SKREE_POSE_GOING_DOWN_INIT;
}

/**
 * @brief 1c738 | 68 | Initializes a skree to be going down
 * 
 */
static void SkreeGoingDownInit(void)
{
    gCurrentSprite.pOam = sSkreeOam_GoingDown;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.work3 = 0;
    gCurrentSprite.work2 = 0;
    gCurrentSprite.pose = SKREE_POSE_GOING_DOWN;

    if (gCurrentSprite.xPosition > gSamusData.xPosition)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(SOUND_SKREE_GOING_DOWN);
}

/**
 * @brief 1c7a0 | fc | Handles a skree going down
 * 
 */
static void SkreeGoDown(void)
{
    u32 blockTop;
    u32 xMovement;
    u32 yMovement;
    u32 offset;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.hitboxBottom + gCurrentSprite.yPosition,
        gCurrentSprite.xPosition);

    if (gPreviousVerticalCollisionCheck != 0)
    {
        gCurrentSprite.yPosition = blockTop - gCurrentSprite.hitboxBottom;
        gCurrentSprite.pose = SKREE_POSE_CRASHING;
        gCurrentSprite.work0 = 0;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlay(SOUND_SKREE_CRASHING);
    }
    else
    {
        xMovement = gCurrentSprite.work2 / 4;

        offset = gCurrentSprite.work3;
        yMovement = sSkreeFallingSpeed[offset];
        if (yMovement == SHORT_MAX)
        {
            yMovement = sSkreeFallingSpeed[offset - 1];
            gCurrentSprite.yPosition += yMovement;
        }
        else
        {
            gCurrentSprite.work3++;
            gCurrentSprite.yPosition += yMovement;
        }

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                return;

            gCurrentSprite.xPosition += xMovement;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
                return;

            gCurrentSprite.xPosition -= xMovement;
        }

        // X speed threshold
        if (xMovement < QUARTER_BLOCK_SIZE)
            gCurrentSprite.work2++;
    }
}

/**
 * @brief 1c89c | 128 | Handles a skree crashing on the ground
 * 
 */
static void SkreeCrashGround(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;
    u8 spriteId;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    APPLY_DELTA_TIME_INC(gCurrentSprite.work0);
    switch (gCurrentSprite.work0)
    {
        case DELTA_TIME:
            yPosition += BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
            SpriteDebrisInit(0, 0x11, yPosition - QUARTER_BLOCK_SIZE, xPosition);
            SpriteDebrisInit(0, 0x12, yPosition, xPosition + (QUARTER_BLOCK_SIZE - PIXEL_SIZE));

            SpriteDebrisInit(0, 0x13, yPosition - (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2),
                xPosition + (QUARTER_BLOCK_SIZE + PIXEL_SIZE));

            SpriteDebrisInit(0, 4, yPosition - (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE),
                xPosition - (QUARTER_BLOCK_SIZE + (QUARTER_BLOCK_SIZE - PIXEL_SIZE) + PIXEL_SIZE / 2));
            break;

        case TWO_THIRD_SECOND:
            gCurrentSprite.pOam = sSkreeOam_Crashing;
            break;

        case CONVERT_SECONDS(1.f):
            gfxSlot = gCurrentSprite.spritesetGfxSlot;
            ramSlot = gCurrentSprite.primarySpriteRamSlot;

            if (gCurrentSprite.spriteId == PSPRITE_SKREE_BLUE)
                spriteId = SSPRITE_BLUE_SKREE_EXPLOSION;
            else
                spriteId = SSPRITE_SKREE_EXPLOSION;
            
            SpriteSpawnSecondary(spriteId, SKREE_EXPLOSION_PART_GOING_UP, gfxSlot, ramSlot,
                yPosition - EIGHTH_BLOCK_SIZE, xPosition, 0);

            SpriteSpawnSecondary(spriteId, SKREE_EXPLOSION_PART_GOING_UP, gfxSlot, ramSlot,
                yPosition - EIGHTH_BLOCK_SIZE, xPosition, SPRITE_STATUS_X_FLIP);

            SpriteSpawnSecondary(spriteId, SKREE_EXPLOSION_PART_GOING_DOWN, gfxSlot, ramSlot,
                yPosition + EIGHTH_BLOCK_SIZE, xPosition - (QUARTER_BLOCK_SIZE - PIXEL_SIZE), 0);

            SpriteSpawnSecondary(spriteId, SKREE_EXPLOSION_PART_GOING_DOWN, gfxSlot, ramSlot,
                yPosition + EIGHTH_BLOCK_SIZE, xPosition + (QUARTER_BLOCK_SIZE - PIXEL_SIZE), SPRITE_STATUS_X_FLIP);

            gCurrentSprite.status = 0;

            ParticleSet(yPosition + HALF_BLOCK_SIZE + PIXEL_SIZE, xPosition, PE_SPRITE_EXPLOSION_HUGE);
            SoundPlay(SOUND_SKREE_EXPLODING);
    }
}

/**
 * @brief 1c9c4 | b4 | Initializes a skree explosion sprite
 * 
 */
static void SkreeExplosionInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -(QUARTER_BLOCK_SIZE - PIXEL_SIZE);
    gCurrentSprite.hitboxBottom = QUARTER_BLOCK_SIZE - PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE - PIXEL_SIZE);
    gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE - PIXEL_SIZE;
    
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    
    gCurrentSprite.pose = SKREE_EXPLOSION_POSE_MOVING;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.bgPriority = BGCNT_GET_PRIORITY(gIoRegistersBackup.BG1CNT);
    
    gCurrentSprite.yPosition += HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
    gCurrentSprite.status |= SPRITE_STATUS_DOUBLE_SIZE | SPRITE_STATUS_ROTATION_SCALING_WHOLE;
    gCurrentSprite.scaling = Q_8_8(1.f);
    gCurrentSprite.rotation = 0;

    if (gCurrentSprite.roomSlot != SKREE_EXPLOSION_PART_GOING_UP)
        gCurrentSprite.pOam = sSkreeExplosionOAM_GoingDown;
    else
        gCurrentSprite.pOam = sSkreeExplosionOAM_GoingUp;
}

/**
 * @brief 1ca78 | 68 | Handles the movement of a skree explosion sprite
 * 
 */
static void SkreeExplosionMove(void)
{
    if (gCurrentSprite.currentAnimationFrame > 1)
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.xPosition += EIGHTH_BLOCK_SIZE;
        gCurrentSprite.rotation += PI_4;
    }
    else
    {
        gCurrentSprite.xPosition -= EIGHTH_BLOCK_SIZE;
        gCurrentSprite.rotation -= PI_4;
    }

    if (gCurrentSprite.roomSlot != SKREE_EXPLOSION_PART_GOING_UP)
        gCurrentSprite.yPosition += PIXEL_SIZE;
    else
        gCurrentSprite.yPosition -= PIXEL_SIZE;

    if (SpriteUtilHasCurrentAnimationEnded())
        gCurrentSprite.status = 0;
}

/**
 * @brief 1cae0 | 194 | Skree AI
 * 
 */
void Skree(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_SKREE_DAMAGED);
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
            SkreeInit();

        case SKREE_POSE_IDLE_INIT:
            SkreeIdleInit();

        case SKREE_POSE_IDLE:
            SkreeDetectSamus();
            break;

        case SKREE_POSE_SPINNING_INIT:
            SkreeSpinningInit();

        case SKREE_POSE_SPINNING:
            SkreeCheckSpinAnimEnded();
            break;

        case SKREE_POSE_GOING_DOWN_INIT:
            SkreeGoingDownInit();

        case SKREE_POSE_GOING_DOWN:
            SkreeGoDown();
            break;

        case SKREE_POSE_CRASHING:
            SkreeCrashGround();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition + (THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE),
                gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
    }
}

/**
 * @brief 1cc74 | 24 | Skree explosion AI
 * 
 */
void SkreeExplosion(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            SkreeExplosionInit();

        case SKREE_EXPLOSION_POSE_MOVING:
            SkreeExplosionMove();
    }
}
