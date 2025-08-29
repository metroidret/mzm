#include "sprites_AI/parasite.h"
#include "sprites_AI/geron.h"
#include "gba/display.h"

#include "data/sprites/parasite.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/sprite.h"
#include "constants/projectile.h"
#include "constants/sprite_util.h"
#include "constants/samus.h"

#include "structs/connection.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/projectile.h"

/**
 * 2fef0 | 54 | Counts the number of parasite that grabbed samus, used to know if samus should take damage
 * 
 * @return 1 if count greater than 3, 0 otherwise
 */
u32 ParasiteCount(void)
{
    struct SpriteData* pSprite;
    u8 count;

    count = 0;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == SSC_PARASITE)
        {
            if (pSprite->pose == PARASITE_POSE_SAMUS_GRABBED)
                count++;

            if (count > 3)
                return TRUE;
        }
    }

    return FALSE;
}

/**
 * @brief 2ff44 | 12c | Initializes a parasite sprite
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteInit(struct SpriteData* pSprite)
{
    u8 spriteId;
    u8 gfxSlot;
    u8 roomSlot;
    u16 yPosition;
    u16 xPosition;

    pSprite->hitboxTop = -PIXEL_SIZE;
    pSprite->hitboxBottom = 0;
    pSprite->hitboxLeft = -PIXEL_SIZE;
    pSprite->hitboxRight = PIXEL_SIZE;

    pSprite->drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    pSprite->drawDistanceBottom = SUB_PIXEL_TO_PIXEL(QUARTER_BLOCK_SIZE);
    pSprite->drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

    pSprite->pOam = sParasiteOam_Idle;
    pSprite->animationDurationCounter = 0;
    pSprite->currentAnimationFrame = 0;

    pSprite->samusCollision = SSC_PARASITE;
    pSprite->health = 1;

    gSubSpriteData1.work2 = 0;
    SpriteUtilChooseRandomXFlip();

    pSprite->pose = PARASITE_POSE_IDLE_INIT;

    spriteId = pSprite->spriteId;

    if (spriteId == PSPRITE_PARASITE_MULTIPLE)
    {
        // Check lock doors
        if (gEquipment.beamBombs & BBF_BOMBS && !EventFunction(EVENT_ACTION_CHECKING, EVENT_BUGS_KILLED))
        {
            LOCK_DOORS();
        }

        // Check is main parasite (spawned via room data and not with SpriteSpawnPrimary since it adds the Not Drawn flag)
        if (pSprite->status & SPRITE_STATUS_NOT_DRAWN)
        {
            // Sub parasite
            gfxSlot = gSpriteRng;
            pSprite->status &= ~SPRITE_STATUS_NOT_DRAWN;
            pSprite->xPosition += gfxSlot * gfxSlot;
        }
        else
        {
            // Main parasite
            gfxSlot = pSprite->spritesetGfxSlot;
            roomSlot = pSprite->roomSlot;
            yPosition = pSprite->yPosition;
            xPosition = pSprite->xPosition;

            // Spawn sub parasites
            SpriteSpawnPrimary(spriteId, roomSlot, gfxSlot, yPosition, xPosition - EIGHTH_BLOCK_SIZE, 0);
            SpriteSpawnPrimary(spriteId, roomSlot, gfxSlot, yPosition, xPosition + EIGHTH_BLOCK_SIZE + PIXEL_SIZE, 0);
            SpriteSpawnPrimary(spriteId, roomSlot, gfxSlot, yPosition, xPosition - (EIGHTH_BLOCK_SIZE + PIXEL_SIZE), 0);
            SpriteSpawnPrimary(spriteId, roomSlot, gfxSlot, yPosition, xPosition + EIGHTH_BLOCK_SIZE, 0);
            SpriteSpawnPrimary(spriteId, roomSlot, gfxSlot, yPosition, xPosition, 0);
        }
    }
}

/**
 * @brief 30070 | 90 | Initializes a parasite to be grabbing Samus
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteGrabSamus(struct SpriteData* pSprite)
{
    u16 samusY;
    u16 samusX;

    pSprite->pose = PARASITE_POSE_SAMUS_GRABBED;

    pSprite->pOam = sParasiteOam_Attached;
    pSprite->currentAnimationFrame = 0;
    pSprite->animationDurationCounter = 0;

    pSprite->work0 = 0;

    // Get samus position
    samusY = gSamusData.yPosition + gSamusPhysics.hitboxTop;
    samusX = gSamusData.xPosition + gSamusPhysics.hitboxLeft;

    // Get Y offset
    if (pSprite->yPosition < samusY)
        pSprite->yPositionSpawn = 0;
    else
        pSprite->yPositionSpawn = pSprite->yPosition - samusY;

    // Get X offset
    if (pSprite->xPosition < samusX)
        pSprite->xPositionSpawn = 0;
    else
        pSprite->xPositionSpawn = pSprite->xPosition - samusX;

    // Set vertical direction
    if (pSprite->yPosition > gSamusData.yPosition - BLOCK_SIZE)
        pSprite->status &= ~SPRITE_STATUS_Y_FLIP;
    else
        pSprite->status |= SPRITE_STATUS_Y_FLIP;
}

/**
 * @brief 30100 | 190 | Handles a parasite having samus grabbed
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteSamusGrabbed(struct SpriteData* pSprite)
{
    u16 samusY;
    u16 samusX;
    u16 xVelocity;
    
    if (gSamusData.pose == SPOSE_SCREW_ATTACKING)
    {
        // Set expelled
        pSprite->pose = PARASITE_POSE_EXPULSED_INIT;
        
        xVelocity = gSpriteRng;
        if (gSpriteRng < SPRITE_RNG_PROB(0.375f))
            xVelocity = PIXEL_SIZE + PIXEL_SIZE / 2;

        pSprite->work2 = xVelocity;
    }
    else
    {
        if (gParasiteRelated == 0)
            gParasiteRelated = CONVERT_SECONDS(1.5f);

        // Check update vertical direction
        if (pSprite->status & SPRITE_STATUS_Y_FLIP)
        {
            if (gSamusData.yPosition + gSamusPhysics.hitboxBottom < pSprite->yPosition + EIGHTH_BLOCK_SIZE)
            {
                pSprite->status &= ~SPRITE_STATUS_Y_FLIP;
                pSprite->work0 = gSpriteRng;
            }
        }
        else
        {
            if (gSamusData.yPosition + gSamusPhysics.hitboxTop > pSprite->yPosition - EIGHTH_BLOCK_SIZE)
            {
                pSprite->status |= SPRITE_STATUS_Y_FLIP;
                pSprite->work0 = gSpriteRng;
            }
        }

        // Check update horizontal direction
        if (pSprite->status & SPRITE_STATUS_X_FLIP)
        {
            if (gSamusData.xPosition + gSamusPhysics.hitboxRight < pSprite->xPosition + EIGHTH_BLOCK_SIZE)
            {
                pSprite->status &= ~SPRITE_STATUS_X_FLIP;
                pSprite->work0 = gSpriteRng;
            }
        }
        else
        {
            if (gSamusData.xPosition + gSamusPhysics.hitboxLeft > pSprite->xPosition - EIGHTH_BLOCK_SIZE)
            {
                pSprite->status |= SPRITE_STATUS_X_FLIP;
                pSprite->work0 = gSpriteRng;
            }
        }

        // Update position offsets
        if (pSprite->work0 == 0)
        {
            // Update Y offset
            if (pSprite->status & SPRITE_STATUS_Y_FLIP)
            {
                if (gSpriteRng != 0)
                    pSprite->yPositionSpawn += ONE_SUB_PIXEL;
            }
            else
            {
                if (gSpriteRng != 0)
                    pSprite->yPositionSpawn -= ONE_SUB_PIXEL;
            }
            
            // Update X offset
            if (pSprite->status & SPRITE_STATUS_X_FLIP)
            {
                if (gSpriteRng != pSprite->primarySpriteRamSlot)
                    pSprite->xPositionSpawn += ONE_SUB_PIXEL;
            }
            else
            {
                if (gSpriteRng != pSprite->primarySpriteRamSlot)
                    pSprite->xPositionSpawn -= ONE_SUB_PIXEL;
            }
        }
        else
        {
            APPLY_DELTA_TIME_DEC(pSprite->work0);
        }

        // Get samus position
        samusY = gSamusData.yPosition + gSamusPhysics.hitboxTop;
        samusX = gSamusData.xPosition + gSamusPhysics.hitboxLeft;
        
        // Update position
        pSprite->yPosition = samusY + pSprite->yPositionSpawn;
        pSprite->xPosition = samusX + pSprite->xPositionSpawn;
    }
}

/**
 * @brief 30290 | 30 | Initializes a parasite to be expelled
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteExpelledInit(struct SpriteData* pSprite)
{
    pSprite->pose = PARASITE_POSE_EXPULSED_UP;

    pSprite->pOam = sParasiteOam_Expelled;
    pSprite->currentAnimationFrame = 0;
    pSprite->animationDurationCounter = 0;

    pSprite->work3 = EIGHTH_BLOCK_SIZE;
    pSprite->status &= ~SPRITE_STATUS_Y_FLIP;
}

/**
 * @brief 302c0 | a0 | Handles a parasite being expelled up
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteExpelledUp(struct SpriteData* pSprite)
{
    u8 velocity;
    u16 yPosition;
    u16 xPosition;

    // Update Y position
    velocity = pSprite->work3--;
    if (velocity != 0)
    {
        pSprite->yPosition -= velocity;
    }
    else
    {
        pSprite->work3 = 0;
        pSprite->pose = PARASITE_POSE_EXPULSED_DOWN;
    }

    yPosition = pSprite->yPosition;
    xPosition = pSprite->xPosition;

    // Prevent going through ceiling
    if (SpriteUtilGetCollisionAtPosition(yPosition - (QUARTER_BLOCK_SIZE + PIXEL_SIZE), xPosition) == COLLISION_SOLID)
        pSprite->yPosition = (yPosition & BLOCK_POSITION_FLAG) + (BLOCK_SIZE + QUARTER_BLOCK_SIZE);

    // Update X position
    if (pSprite->status & SPRITE_STATUS_X_FLIP)
    {
        if (!(SpriteUtilGetCollisionAtPosition(yPosition, xPosition + QUARTER_BLOCK_SIZE) & COLLISION_FLAGS_UNKNOWN_F0))
            pSprite->xPosition += pSprite->work2;
    }
    else
    {
        if (!(SpriteUtilGetCollisionAtPosition(yPosition, xPosition - QUARTER_BLOCK_SIZE) & COLLISION_FLAGS_UNKNOWN_F0))
            pSprite->xPosition -= pSprite->work2;
    }
}

/**
 * @brief 30360 | a8 | Handles a parasite (multiple) being expelled up
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteMultipleExpelledUp(struct SpriteData* pSprite)
{
    u8 velocity;
    u16 yPosition;
    u16 xPosition;

    // Update Y position
    velocity = pSprite->work3--;
    if (velocity != 0)
    {
        pSprite->yPosition -= velocity;
    }
    else
    {
        pSprite->work3 = 0;
        pSprite->pose = PARASITE_POSE_EXPULSED_DOWN;
    }

    yPosition = pSprite->yPosition;
    xPosition = pSprite->xPosition;

    // Prevent going through ceiling
    if (ClipdataProcess(yPosition - (QUARTER_BLOCK_SIZE + PIXEL_SIZE), xPosition) & CLIPDATA_TYPE_SOLID_FLAG)
        pSprite->yPosition = (yPosition & BLOCK_POSITION_FLAG) + (BLOCK_SIZE + QUARTER_BLOCK_SIZE);

    // Update X position
    if (pSprite->status & SPRITE_STATUS_X_FLIP)
    {
        if (!(ClipdataProcess(yPosition, xPosition + QUARTER_BLOCK_SIZE) & CLIPDATA_TYPE_SOLID_FLAG))
            pSprite->xPosition += pSprite->work2;
    }
    else
    {
        if (!(ClipdataProcess(yPosition, xPosition - QUARTER_BLOCK_SIZE) & CLIPDATA_TYPE_SOLID_FLAG))
            pSprite->xPosition -= pSprite->work2;
    }
}

/**
 * @brief 30408 | e8 | Handles a parasite being expelled (going down)
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteExpelledDown(struct SpriteData* pSprite)
{
    u16 oldY;
    u16 yPosition;
    u16 xPosition;
    s32 blockTop;
    s16 velocity;

    oldY = pSprite->yPosition;

    velocity = pSprite->work3;
    if (velocity < QUARTER_BLOCK_SIZE + PIXEL_SIZE)
        pSprite->work3 = velocity + PIXEL_SIZE / 2;

    pSprite->yPosition += velocity;

    yPosition = pSprite->yPosition;
    xPosition = pSprite->xPosition;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(yPosition, xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        if (gSpriteRng > SPRITE_RNG_PROB(.5f))
        {
            pSprite->pOam = sParasiteOam_Landing;
            pSprite->currentAnimationFrame = 0;
            pSprite->animationDurationCounter = 0;
        }
        else
        {
            pSprite->pOam = sParasiteOam_Tumbling;
            pSprite->currentAnimationFrame = 0;
            pSprite->animationDurationCounter = 0;
            pSprite->work0 = gSpriteRng * CONVERT_SECONDS(1.f / 30) + CONVERT_SECONDS(.5f + 1.f / 30);
        }

        pSprite->pose = PARASITE_POSE_LANDING;
        pSprite->yPosition = blockTop;
    }
    else
    {
        if (pSprite->status & SPRITE_STATUS_X_FLIP)
        {
            if (!(SpriteUtilGetCollisionAtPosition(yPosition, xPosition + QUARTER_BLOCK_SIZE) & COLLISION_FLAGS_UNKNOWN_F0))
                pSprite->xPosition += pSprite->work2;
        }
        else
        {
            if (!(SpriteUtilGetCollisionAtPosition(yPosition, xPosition - QUARTER_BLOCK_SIZE) & COLLISION_FLAGS_UNKNOWN_F0))
                pSprite->xPosition -= pSprite->work2;
        }

        SpriteUtilCheckInRoomEffect(oldY, yPosition, xPosition, SPLASH_SMALL);
    }
}

/**
 * @brief 304f0 | dc | Handles a parasite (multiple) being expelled (going down)
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteMultipleExpelledDown(struct SpriteData* pSprite)
{
    s16 velocity;
    u32 yPosition;
    s32 xPosition;

    velocity = pSprite->work3;
    if (velocity < QUARTER_BLOCK_SIZE + PIXEL_SIZE)
        pSprite->work3 += 2;
    
    pSprite->yPosition += velocity;

    yPosition = pSprite->yPosition;
    xPosition = pSprite->xPosition;

    if (ClipdataProcess(yPosition, xPosition) & CLIPDATA_TYPE_SOLID_FLAG && yPosition >= (yPosition & BLOCK_POSITION_FLAG))
    {
        pSprite->yPosition = yPosition & BLOCK_POSITION_FLAG;
        pSprite->pose = PARASITE_POSE_LANDING;

        if (gSpriteRng > SPRITE_RNG_PROB(.5f))
        {
            pSprite->pOam = sParasiteOam_Landing;
            pSprite->currentAnimationFrame = 0;
            pSprite->animationDurationCounter = 0;
        }
        else
        {
            pSprite->pOam = sParasiteOam_Tumbling;
            pSprite->currentAnimationFrame = 0;
            pSprite->animationDurationCounter = 0;
            pSprite->work0 = gSpriteRng * CONVERT_SECONDS(1.f / 30) + CONVERT_SECONDS(.5f + 1.f / 30);
        }

        return;
    }

    if (pSprite->status & SPRITE_STATUS_X_FLIP)
    {
        if (!(ClipdataProcess(yPosition, xPosition + QUARTER_BLOCK_SIZE) & CLIPDATA_TYPE_SOLID_FLAG))
            pSprite->xPosition += pSprite->work2;
    }
    else
    {
        if (!(ClipdataProcess(yPosition, xPosition - QUARTER_BLOCK_SIZE) & CLIPDATA_TYPE_SOLID_FLAG))
            pSprite->xPosition -= pSprite->work2;
    }
}

/**
 * @brief 305cc | b8 | Handles a parasite jumping up
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteJumpingUp(struct SpriteData* pSprite)
{
    u16 yPosition;
    u16 xPosition;
    u8 velocity;

    if (pSprite->status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        pSprite->pose = PARASITE_POSE_SAMUS_GRABBED_INIT;
        return;
    }

    // Update Y position
    velocity = pSprite->work3--;
    if (velocity != 0)
    {
        pSprite->yPosition -= velocity;
    }
    else
    {
        pSprite->work3 = 0;
        pSprite->pose = PARASITE_POSE_JUMPING_DOWN;
    }

    yPosition = pSprite->yPosition;
    xPosition = pSprite->xPosition;

    // Prevent going through ceiling
    if (SpriteUtilGetCollisionAtPosition(yPosition - (QUARTER_BLOCK_SIZE + PIXEL_SIZE), xPosition) == COLLISION_SOLID)
        pSprite->yPosition = (yPosition & BLOCK_POSITION_FLAG) + BLOCK_SIZE + QUARTER_BLOCK_SIZE;
    
    // Update X position
    if (pSprite->status & SPRITE_STATUS_X_FLIP)
    {
        if (!(SpriteUtilGetCollisionAtPosition(yPosition, xPosition + QUARTER_BLOCK_SIZE) & COLLISION_FLAGS_UNKNOWN_F0))
            pSprite->xPosition += pSprite->work2;
    }
    else
    {
        if (!(SpriteUtilGetCollisionAtPosition(yPosition, xPosition - QUARTER_BLOCK_SIZE) & COLLISION_FLAGS_UNKNOWN_F0))
            pSprite->xPosition -= pSprite->work2;
    }
}

/**
 * @brief 30684 | bc | Handles a parasite (multiple) jumping up
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteMultipleJumpingUp(struct SpriteData* pSprite)
{
    u16 yPosition;
    u16 xPosition;
    u8 velocity;

    if (pSprite->status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        pSprite->pose = PARASITE_POSE_SAMUS_GRABBED_INIT;
        return;
    }

    // Update Y position
    velocity = pSprite->work3--;
    if (velocity != 0)
    {
        pSprite->yPosition -= velocity;
    }
    else
    {
        pSprite->work3 = 0;
        pSprite->pose = PARASITE_POSE_JUMPING_DOWN;
    }

    yPosition = pSprite->yPosition;
    xPosition = pSprite->xPosition;

    // Prevent going through ceiling
    if (ClipdataProcess(yPosition - (QUARTER_BLOCK_SIZE + PIXEL_SIZE), xPosition) & CLIPDATA_TYPE_SOLID_FLAG)
        pSprite->yPosition = (yPosition & BLOCK_POSITION_FLAG) + BLOCK_SIZE + QUARTER_BLOCK_SIZE;
    
    // Update X position
    if (pSprite->status & SPRITE_STATUS_X_FLIP)
    {
        if (!(ClipdataProcess(yPosition, xPosition + QUARTER_BLOCK_SIZE) & CLIPDATA_TYPE_SOLID_FLAG))
            pSprite->xPosition += pSprite->work2;
    }
    else
    {
        if (!(ClipdataProcess(yPosition, xPosition - QUARTER_BLOCK_SIZE) & CLIPDATA_TYPE_SOLID_FLAG))
            pSprite->xPosition -= pSprite->work2;
    }
}

/**
 * @brief 30740 | cc | Handles a parasite jumping down
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteJumpingDown(struct SpriteData* pSprite)
{
    u16 oldY;
    u16 yPosition;
    u16 xPosition;
    u32 topEdge;
    s32 velocity;

    oldY = pSprite->yPosition;

    if (pSprite->status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        pSprite->pose = PARASITE_POSE_SAMUS_GRABBED_INIT;
        return;
    }

    // Update Y position
    velocity = pSprite->work3;
    if (velocity < QUARTER_BLOCK_SIZE)
        pSprite->work3 = velocity + PIXEL_SIZE / 2;

    pSprite->yPosition += velocity;

    yPosition = pSprite->yPosition;
    xPosition = pSprite->xPosition;

    // Check ground
    topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(yPosition, xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        pSprite->pOam = sParasiteOam_Landing;
        pSprite->currentAnimationFrame = 0;
        pSprite->animationDurationCounter = 0;

        pSprite->pose = PARASITE_POSE_LANDING;
        pSprite->yPosition = topEdge;
    }
    else
    {
        // Update X position
        if (pSprite->status & SPRITE_STATUS_X_FLIP)
        {
            if (!(SpriteUtilGetCollisionAtPosition(yPosition, xPosition + QUARTER_BLOCK_SIZE) & COLLISION_FLAGS_UNKNOWN_F0))
                pSprite->xPosition += pSprite->work2;
        }
        else
        {
            if (!(SpriteUtilGetCollisionAtPosition(yPosition, xPosition - QUARTER_BLOCK_SIZE) & COLLISION_FLAGS_UNKNOWN_F0))
                pSprite->xPosition -= pSprite->work2;
        }

        SpriteUtilCheckInRoomEffect(oldY, yPosition, xPosition, SPLASH_SMALL);
    }
}

/**
 * @brief 3080c | c0 | Handles a parasite (multiple) jumping (going down)
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteMultipleJumpingDown(struct SpriteData* pSprite)
{
    s32 yPosition;
    u16 xPosition;
    u32 topEdge;
    s32 velocity;

    if (pSprite->status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        pSprite->pose = PARASITE_POSE_SAMUS_GRABBED_INIT;
        return;
    }

    // Update Y position
    velocity = pSprite->work3;
    if (velocity < QUARTER_BLOCK_SIZE)
        pSprite->work3 = velocity + PIXEL_SIZE / 2;

    pSprite->yPosition += velocity;

    yPosition = pSprite->yPosition;
    xPosition = pSprite->xPosition;

    // Check ground
    if (ClipdataProcess(yPosition, xPosition) & CLIPDATA_TYPE_SOLID_FLAG && yPosition >= (yPosition & BLOCK_POSITION_FLAG))
    {
        pSprite->pOam = sParasiteOam_Landing;
        pSprite->currentAnimationFrame = 0;
        pSprite->animationDurationCounter = 0;

        pSprite->pose = PARASITE_POSE_LANDING;
        pSprite->yPosition = (u16)yPosition & BLOCK_POSITION_FLAG;
    }
    else
    {
        // Update X position
        if (pSprite->status & SPRITE_STATUS_X_FLIP)
        {
            if (!(ClipdataProcess(yPosition, xPosition + QUARTER_BLOCK_SIZE) & CLIPDATA_TYPE_SOLID_FLAG))
                pSprite->xPosition += pSprite->work2;
        }
        else
        {
            if (!(ClipdataProcess(yPosition, xPosition - QUARTER_BLOCK_SIZE) & CLIPDATA_TYPE_SOLID_FLAG))
                pSprite->xPosition -= pSprite->work2;
        }
    }
}

/**
 * @brief 308cc | 50 | Initializes a parasite to be idle
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteIdleInit(struct SpriteData* pSprite)
{
    u8 velocity;

    pSprite->pose = PARASITE_POSE_IDLE;

    pSprite->pOam = sParasiteOam_Idle;
    pSprite->currentAnimationFrame = 0;
    pSprite->animationDurationCounter = 0;

    velocity = gSpriteRng / 2;
    if (velocity < PIXEL_SIZE + PIXEL_SIZE / 2)
        velocity = PIXEL_SIZE + PIXEL_SIZE / 2;

    pSprite->work2 = velocity;
    pSprite->work0 = MOD_AND((MOD_AND(pSprite->xPosition / HALF_BLOCK_SIZE, SPRITE_RNG_MAX) + gSpriteRng), SPRITE_RNG_MAX);
}

/**
 * @brief 3091c | 198 | Handles a parasite being idle
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteIdle(struct SpriteData* pSprite)
{
    u32 timer;
    u16 velocity;

    if (pSprite->status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        pSprite->pose = PARASITE_POSE_SAMUS_GRABBED_INIT;
        return;
    }

    SpriteUtilAlignYPositionOnSlopeAtOrigin();

    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
    {
        pSprite->pose = PARASITE_POSE_FALLING_INIT;
        return;
    }

    if (SpriteUtilGetCollisionAtPosition(pSprite->yPosition - QUARTER_BLOCK_SIZE, pSprite->xPosition) == COLLISION_SOLID)
    {
        pSprite->pose = PARASITE_POSE_DYING_INIT;
        return;
    }

    timer = pSprite->work0;
    if (gFrameCounter8Bit / SPRITE_RNG_MAX == timer)
    {
        pSprite->pOam = sParasiteOam_LandingAfterFalling;
        pSprite->currentAnimationFrame = 0;
        pSprite->animationDurationCounter = 0;

        pSprite->work0 = gSpriteRng * 3;
        pSprite->pose = PARASITE_POSE_LANDING;
    }
    else if (gFrameCounter8Bit / SPRITE_RNG_MAX == timer + 1 || gFrameCounter8Bit / SPRITE_RNG_MAX == timer - 1)
    {
        pSprite->pose = PARASITE_POSE_JUMPING_UP;

        pSprite->pOam = sParasiteOam_JumpingUp;
        pSprite->currentAnimationFrame = 0;
        pSprite->animationDurationCounter = 0;

        if (gSpriteRng < SPRITE_RNG_PROB(.25f))
            pSprite->work3 = SPRITE_RNG_PROB(.25f);
        else
            pSprite->work3 = gSpriteRng;

        if (pSprite->status & SPRITE_STATUS_ONSCREEN)
        {
            timer = pSprite->work3;
            if (timer < SPRITE_RNG_PROB(.5f))
                SoundPlayNotAlreadyPlaying(SOUND_PARASITE_JUMPING_1);
            else if (timer >= SPRITE_RNG_PROB(.75f))
                SoundPlayNotAlreadyPlaying(SOUND_PARASITE_JUMPING_3);
            else
                SoundPlayNotAlreadyPlaying(SOUND_PARASITE_JUMPING_2);
        }
    }
    else
    {
        if (gParasiteRelated == 0)
        {
            if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE + HALF_BLOCK_SIZE, BLOCK_SIZE + EIGHTH_BLOCK_SIZE) != NSLR_OUT_OF_RANGE)
                gParasiteRelated = CONVERT_SECONDS(1.5f);

            timer = MOD_AND(timer, 2);
            timer++;
        }
        else
            timer = pSprite->work2;

        velocity = timer;

        if (pSprite->status & SPRITE_STATUS_X_FLIP)
        {
            if (gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0 &&
                SpriteUtilGetCollisionAtPosition(pSprite->yPosition - QUARTER_BLOCK_SIZE, pSprite->xPosition + QUARTER_BLOCK_SIZE) == COLLISION_SOLID)
            {
                pSprite->pose = PARASITE_POSE_TURNING_AROUND_INIT;
            }
            else
            {
                pSprite->xPosition += velocity;
            }
        }
        else
        {
            if (gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0 &&
                SpriteUtilGetCollisionAtPosition(pSprite->yPosition - QUARTER_BLOCK_SIZE, pSprite->xPosition - QUARTER_BLOCK_SIZE) == COLLISION_SOLID)
            {
                pSprite->pose = PARASITE_POSE_TURNING_AROUND_INIT;
            }
            else
            {
                pSprite->xPosition -= velocity;
            }
        }
    }
}

/**
 * @brief 30ab4 | 1a4 | Handles a parasite (multiple) being idle
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteMultipleIdle(struct SpriteData* pSprite)
{
    u32 timer;
    u8 rng;
    u16 velocity;
    u32 clipdata;

    if (pSprite->status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        pSprite->pose = PARASITE_POSE_SAMUS_GRABBED_INIT;
        return;
    }

    if (MOD_AND(pSprite->primarySpriteRamSlot, 2))
    {
        if (MOD_AND(gFrameCounter8Bit, 2))
        {
            clipdata = ClipdataProcess(pSprite->yPosition, pSprite->xPosition);
            if (!(clipdata & CLIPDATA_TYPE_SOLID_FLAG))
            {
                pSprite->pose = PARASITE_POSE_FALLING_INIT;
                return;
            }
        }
    }
    else
    {
        if (MOD_AND(gFrameCounter8Bit, 2) == 0)
        {
            clipdata = ClipdataProcess(pSprite->yPosition, pSprite->xPosition);
            if (!(clipdata & CLIPDATA_TYPE_SOLID_FLAG))
            {
                pSprite->pose = PARASITE_POSE_FALLING_INIT;
                return;
            }
        }
    }

    timer = pSprite->work0;
    rng = gFrameCounter8Bit / SPRITE_RNG_MAX;
    if (rng == timer)
    {
        pSprite->pOam = sParasiteOam_LandingAfterFalling;
        pSprite->currentAnimationFrame = 0;
        pSprite->animationDurationCounter = 0;

        pSprite->work0 = gSpriteRng * 3;
        pSprite->pose = PARASITE_POSE_LANDING;
    }
    else if (rng == timer + 1 || rng == timer - 1)
    {
        pSprite->pose = PARASITE_POSE_JUMPING_UP;

        pSprite->pOam = sParasiteOam_JumpingUp;
        pSprite->currentAnimationFrame = 0;
        pSprite->animationDurationCounter = 0;

        if (gSpriteRng < SPRITE_RNG_PROB(.25f))
            pSprite->work3 = SPRITE_RNG_PROB(.25f);
        else
            pSprite->work3 = gSpriteRng;

        if (pSprite->status & SPRITE_STATUS_ONSCREEN)
        {
            timer = pSprite->work3;
            if (timer < SPRITE_RNG_PROB(.5f))
                SoundPlayNotAlreadyPlaying(SOUND_PARASITE_JUMPING_1);
            else if (timer >= SPRITE_RNG_PROB(.75f))
                SoundPlayNotAlreadyPlaying(SOUND_PARASITE_JUMPING_3);
            else
                SoundPlayNotAlreadyPlaying(SOUND_PARASITE_JUMPING_2);
        }
    }
    else
    {
        if (gParasiteRelated == 0)
        {
            if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE + HALF_BLOCK_SIZE, BLOCK_SIZE + NSLR_RIGHT) != NSLR_OUT_OF_RANGE)
                gParasiteRelated = CONVERT_SECONDS(1.5f);

            velocity = MOD_AND(timer, 2) + 1;
        }
        else
            velocity = pSprite->work2;

        if (pSprite->status & SPRITE_STATUS_X_FLIP)
        {
            clipdata = ClipdataProcess(pSprite->yPosition - QUARTER_BLOCK_SIZE, pSprite->xPosition + QUARTER_BLOCK_SIZE);
            if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
                pSprite->pose = PARASITE_POSE_TURNING_AROUND_INIT;
            else
                pSprite->xPosition += velocity;
        }
        else
        {
            clipdata = ClipdataProcess(pSprite->yPosition - QUARTER_BLOCK_SIZE, pSprite->xPosition - QUARTER_BLOCK_SIZE);
            if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
                pSprite->pose = PARASITE_POSE_TURNING_AROUND_INIT;
            else
                pSprite->xPosition -= velocity;
        }
    }
}

/**
 * @brief 30c58 | 1c | Initializes a parasite to turn around
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteTurningAroundInit(struct SpriteData* pSprite)
{
    pSprite->pose = PARASITE_POSE_TURNING_AROUND_FIRST_PART;

    pSprite->pOam = sParasiteOam_TurningAround;
    pSprite->currentAnimationFrame = 0;
    pSprite->animationDurationCounter = 0;
}

/**
 * @brief 30c74 | 24 | Handles the first part of a parasite turning around
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteTurningAroundFirstPart(struct SpriteData* pSprite)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        pSprite->status ^= SPRITE_STATUS_X_FLIP;
        pSprite->pose = PARASITE_POSE_TURNING_AROUND_SECOND_PART;
    }
}

/**
 * @brief 30c98 | 1c | Handles the second part of a parasite turning around
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteTurningAroundSecondPart(struct SpriteData* pSprite)
{
    if (SpriteUtilHasCurrentAnimationNearlyEnded())
        pSprite->pose = PARASITE_POSE_IDLE_INIT;
}

/**
 * @brief 30cb4 | 20 | Initializes a parasite to be landing
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteLandingInit(struct SpriteData* pSprite)
{
    pSprite->pose = PARASITE_POSE_LANDING;

    pSprite->pOam = sParasiteOam_LandingAfterFalling;
    pSprite->currentAnimationFrame = 0;
    pSprite->animationDurationCounter = 0;

    pSprite->work0 = CONVERT_SECONDS(.5f);
}

/**
 * @brief 30cd4 | a0 | Handles a parasite landing
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteLanding(struct SpriteData* pSprite)
{
    u8 setPose;

    if (!(ClipdataProcess(pSprite->yPosition, pSprite->xPosition) & CLIPDATA_TYPE_SOLID_FLAG))
    {
        pSprite->pose = PARASITE_POSE_FALLING_INIT;
        return;
    }

    setPose = FALSE;

    if (pSprite->pOam == sParasiteOam_LandingAfterFalling)
    {
        // Landing after falling
        APPLY_DELTA_TIME_DEC(pSprite->work0);
        if (pSprite->work0 == 0)
            setPose++;
    }
    else if (pSprite->pOam == sParasiteOam_Tumbling)
    {
        // Check set back on feet
        APPLY_DELTA_TIME_DEC(pSprite->work0);
        if (pSprite->work0 == 0)
        {
            pSprite->pOam = sParasiteOam_TurningBackOnFeet;
            pSprite->currentAnimationFrame = 0;
            pSprite->animationDurationCounter = 0;
        }
    }
    else if (SpriteUtilHasCurrentAnimationNearlyEnded())
    {
        setPose++; // Anim ended, set pose
    }

    if (setPose)
    {
        // Set random pose
        if (gSpriteRng > SPRITE_RNG_PROB(.375f))
            pSprite->pose = PARASITE_POSE_IDLE_INIT;
        else
            pSprite->pose = PARASITE_POSE_TURNING_AROUND_INIT;
    }
}

/**
 * @brief 30d74 | 10 | Initializes a parasite to be falling
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteFallingInit(struct SpriteData* pSprite)
{
    pSprite->pose = PARASITE_POSE_FALLING;
    pSprite->work3 = 0;
}

/**
 * @brief 30d84 | 74 | Handles a parasite falling
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteFalling(struct SpriteData* pSprite)
{
    s32 offset;
    s32 movement;
    u16 oldY;
    u32 topEdge;
    s32 newMovement;

    oldY = pSprite->yPosition;
    offset = pSprite->work3;
    movement = sSpritesFallingSpeed[offset];
    
    if (movement == SHORT_MAX)
    {
        newMovement = sSpritesFallingSpeed[offset - 1];
        pSprite->yPosition += newMovement;
    }
    else
    {
        pSprite->work3++;
        pSprite->yPosition += movement;
    }

    topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pSprite->yPosition, pSprite->xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        pSprite->yPosition = topEdge;
        pSprite->pose = PARASITE_POSE_LANDING_INIT;
    }
    else
    {
        SpriteUtilCheckInRoomEffect(oldY, pSprite->yPosition, pSprite->xPosition, SPLASH_SMALL);
    }
}

/**
 * @brief 30df8 | 3c | Initializes a parasite to be dying
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteDyingInit(struct SpriteData* pSprite)
{
    pSprite->status &= ~(SPRITE_STATUS_ROTATION_SCALING_SINGLE | SPRITE_STATUS_Y_FLIP);
    pSprite->pose = PARASITE_POSE_DYING;

    pSprite->pOam = sParasiteOam_Dying;
    pSprite->currentAnimationFrame = 0;
    pSprite->animationDurationCounter = 0;

    pSprite->bgPriority = BGCNT_GET_PRIORITY(gIoRegistersBackup.BG1CNT);
}

/**
 * @brief 30e34 | 20 | Handles a parasite dying
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteDying(struct SpriteData* pSprite)
{
    pSprite->ignoreSamusCollisionTimer = DELTA_TIME;

    if (SpriteUtilHasCurrentAnimationEnded())
        pSprite->status = 0;
}

/**
 * @brief 30e54 | 60 | Handles a parasite (multiple) dying
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteMultipleDying(struct SpriteData* pSprite)
{
    pSprite->ignoreSamusCollisionTimer = DELTA_TIME;

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        pSprite->status = 0;
        gSpriteData[pSprite->primarySpriteRamSlot].status = 0;

        if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_BUGS_KILLED) && SpriteUtilCountPrimarySprites(PSPRITE_PARASITE_MULTIPLE) == 0)
        {
            EventFunction(EVENT_ACTION_SETTING, EVENT_BUGS_KILLED);
            gDoorUnlockTimer = -ONE_THIRD_SECOND;
        }
    }
}

/**
 * @brief 30eb4 | 98 | Initializes a parasite to be grabbing a Geron
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteGrabGeron(struct SpriteData* pSprite)
{
    u16 geronY;
    u16 geronX;
    u8 ramSlot;

    pSprite->pose = PARASITE_POSE_GERON_GRABBED;

    pSprite->pOam = sParasiteOam_Attached;
    pSprite->currentAnimationFrame = 0;
    pSprite->animationDurationCounter = 0;

    pSprite->work0 = 0;

    ramSlot = pSprite->work1;

    // Get geron position
    geronY = gSpriteData[ramSlot].yPosition + gSpriteData[ramSlot].hitboxTop;
    geronX = gSpriteData[ramSlot].xPosition + gSpriteData[ramSlot].hitboxLeft;

    // Get Y offset
    if (pSprite->yPosition < geronY)
        pSprite->yPositionSpawn = 0;
    else
        pSprite->yPositionSpawn = pSprite->yPosition - geronY;

    // Get X offset
    if (pSprite->xPosition < geronX)
        pSprite->xPositionSpawn = 0;
    else
        pSprite->xPositionSpawn = pSprite->xPosition - geronX;

    // Set vertical direction
    if (pSprite->yPosition > gSpriteData[ramSlot].yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE))
        pSprite->status &= ~SPRITE_STATUS_Y_FLIP;
    else
        pSprite->status |= SPRITE_STATUS_Y_FLIP;
}

/**
 * @brief 30f4c | 19c | Handles a parasite having a Geron grabbed 
 * 
 * @param pSprite Sprite data pointer
 */
static void ParasiteGeronGrabbed(struct SpriteData* pSprite)
{
    u8 ramSlot;
    u16 geronY;
    u16 geronX;
    u16 xVelocity;
    
    ramSlot = pSprite->work1;

    if (gSpriteData[ramSlot].pose == GERON_POSE_DELAY_BEFORE_DESTROYED)
    {
        // Set expelled
        pSprite->pose = PARASITE_POSE_EXPULSED_INIT;
        
        xVelocity = gSpriteRng;
        if (gSpriteRng < SPRITE_RNG_PROB(.375f))
            xVelocity = PIXEL_SIZE + PIXEL_SIZE / 2;

        pSprite->work2 = xVelocity;
        pSprite->samusCollision = SSC_PARASITE;
        pSprite->status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    }
    else
    {
        if (gParasiteRelated == 0)
            gParasiteRelated = CONVERT_SECONDS(1.5f);

        // Check update vertical direction
        if (pSprite->status & SPRITE_STATUS_Y_FLIP)
        {
            if (gSpriteData[ramSlot].yPosition < pSprite->yPosition + EIGHTH_BLOCK_SIZE)
            {
                pSprite->status &= ~SPRITE_STATUS_Y_FLIP;
                pSprite->work0 = gSpriteRng;
            }
        }
        else
        {
            if (gSpriteData[ramSlot].yPosition + gSpriteData[ramSlot].hitboxTop > pSprite->yPosition - EIGHTH_BLOCK_SIZE)
            {
                pSprite->status |= SPRITE_STATUS_Y_FLIP;
                pSprite->work0 = gSpriteRng;
            }
        }

        // Check update horizontal direction
        if (pSprite->status & SPRITE_STATUS_X_FLIP)
        {
            if (gSpriteData[ramSlot].xPosition + gSpriteData[ramSlot].hitboxRight < pSprite->xPosition + EIGHTH_BLOCK_SIZE)
            {
                pSprite->status &= ~SPRITE_STATUS_X_FLIP;
                pSprite->work0 = gSpriteRng;
            }
        }
        else
        {
            if (gSpriteData[ramSlot].xPosition + gSpriteData[ramSlot].hitboxLeft > pSprite->xPosition - EIGHTH_BLOCK_SIZE)
            {
                pSprite->status |= SPRITE_STATUS_X_FLIP;
                pSprite->work0 = gSpriteRng;
            }
        }

        // Update position offsets
        if (pSprite->work0 == 0)
        {
            // Update Y offset
            if (pSprite->status & SPRITE_STATUS_Y_FLIP)
            {
                if (gSpriteRng != 0)
                    pSprite->yPositionSpawn += ONE_SUB_PIXEL;
            }
            else
            {
                if (gSpriteRng != 0)
                    pSprite->yPositionSpawn -= ONE_SUB_PIXEL;
            }
            
            // Update X offset
            if (pSprite->status & SPRITE_STATUS_X_FLIP)
            {
                if (gSpriteRng != pSprite->primarySpriteRamSlot)
                    pSprite->xPositionSpawn += ONE_SUB_PIXEL;
            }
            else
            {
                if (gSpriteRng != pSprite->primarySpriteRamSlot)
                    pSprite->xPositionSpawn -= ONE_SUB_PIXEL;
            }
        }
        else
            pSprite->work0--;

        // Get geron position
        geronY = gSpriteData[ramSlot].yPosition + gSpriteData[ramSlot].hitboxTop;
        geronX = gSpriteData[ramSlot].xPosition + gSpriteData[ramSlot].hitboxLeft;
        
        // Update position
        pSprite->yPosition = geronY + pSprite->yPositionSpawn;
        pSprite->xPosition = geronX + pSprite->xPositionSpawn;
    }
}

/**
 * @brief 310e8 | 118 | Handles the collision with the projectiles
 *
 * @param pSprite Sprite data pointer
 */
static void ParasiteBombCollision(struct SpriteData* pSprite)
{
    struct ProjectileData* pProj;
    u8 status;
    u16 projTop;
    u16 projBottom;
    u16 projLeft;
    u16 projRight;

    u8 kill;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;

    u16 yPos, hitboxBottom;

    if (pSprite->invincibilityStunFlashTimer & SPRITE_ISFT_POWER_BOMB_STUNNED)
    {
        pSprite->pose = PARASITE_POSE_DYING_INIT;
        return;
    }
    
    kill = FALSE;

    yPos = pSprite->yPosition;
    spriteTop = yPos + pSprite->hitboxTop;

    spriteBottom = yPos;
    hitboxBottom = pSprite->hitboxBottom;
    spriteBottom += hitboxBottom;

    spriteLeft = pSprite->xPosition + pSprite->hitboxLeft;
    spriteRight = pSprite->xPosition + pSprite->hitboxRight;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        status = pProj->status;
        if (status & PROJ_STATUS_EXISTS && pProj->type == PROJ_TYPE_BOMB && pProj->movementStage == BOMB_STAGE_EXPLODING)
        {
            projTop = pProj->yPosition + pProj->hitboxTop;
            projBottom = pProj->yPosition + pProj->hitboxBottom;
            projLeft = pProj->xPosition + pProj->hitboxLeft;
            projRight = pProj->xPosition + pProj->hitboxRight;

            if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, projTop, projBottom, projLeft, projRight))
            {
                kill++;
                break;
            }
        }
    }

    if (kill)
    {
        pSprite->pose = PARASITE_POSE_DYING_INIT;
        return;
    }
    
    pSprite->invincibilityStunFlashTimer = 0;
    pSprite->health = 1;
    pSprite->pose = PARASITE_POSE_EXPULSED_INIT;

    kill = gSpriteRng / 2;
    if (kill < SPRITE_RNG_PROB(.5625f))
        kill = SPRITE_RNG_PROB(.5625f);

    pSprite->work2 = kill;

    SpriteUtilMakeSpriteFaceAwayFromSamusDirection();
}

/**
 * @brief 31200 | 27c | Parasite (multiple) AI
 * 
 */
void ParasiteMultiple(void)
{
    struct SpriteData* pSprite;

    pSprite = &gCurrentSprite;

    if (SPRITE_GET_ISFT(*pSprite) != 0 && pSprite->pose < PARASITE_POSE_DYING)
        ParasiteBombCollision(pSprite);

    switch (pSprite->pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ParasiteInit(pSprite);
            break;

        case PARASITE_POSE_IDLE_INIT:
            ParasiteIdleInit(pSprite);
        break;

        case PARASITE_POSE_IDLE:
            ParasiteMultipleIdle(pSprite);
            break;

        case PARASITE_POSE_TURNING_AROUND_INIT:
            ParasiteTurningAroundInit(pSprite);

        case PARASITE_POSE_TURNING_AROUND_FIRST_PART:
            ParasiteTurningAroundFirstPart(pSprite);
            break;

        case PARASITE_POSE_TURNING_AROUND_SECOND_PART:
            ParasiteTurningAroundSecondPart(pSprite);
            break;

        case PARASITE_POSE_LANDING_INIT:
            ParasiteLandingInit(pSprite);

        case PARASITE_POSE_LANDING:
            ParasiteLanding(pSprite);
            break;

        case PARASITE_POSE_FALLING_INIT:
            ParasiteFallingInit(pSprite);

        case PARASITE_POSE_FALLING:
            ParasiteFalling(pSprite);
            break;

        case PARASITE_POSE_SAMUS_GRABBED_INIT:
            ParasiteGrabSamus(pSprite);

        case PARASITE_POSE_SAMUS_GRABBED:
            ParasiteSamusGrabbed(pSprite);
            break;

        case PARASITE_POSE_EXPULSED_INIT:
            ParasiteExpelledInit(pSprite);
        
        case PARASITE_POSE_EXPULSED_UP:
            ParasiteMultipleExpelledUp(pSprite);
            break;

        case PARASITE_POSE_EXPULSED_DOWN:
            ParasiteMultipleExpelledDown(pSprite);
            break;

        case PARASITE_POSE_JUMPING_UP:
            ParasiteMultipleJumpingUp(pSprite);
            break;

        case PARASITE_POSE_JUMPING_DOWN:
            ParasiteMultipleJumpingDown(pSprite);
            break;

        case PARASITE_POSE_DYING_INIT:
            ParasiteDyingInit(pSprite);

        case PARASITE_POSE_DYING:
            ParasiteMultipleDying(pSprite);
    }

    pSprite->status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
}

/**
 * @brief 3147c | 28c | Parasite AI
 * 
 */
void Parasite(void)
{
    struct SpriteData* pSprite;

    pSprite = &gCurrentSprite;

    if (SPRITE_GET_ISFT(*pSprite) != 0 && pSprite->pose < PARASITE_POSE_DYING)
        ParasiteBombCollision(pSprite);

    switch (pSprite->pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ParasiteInit(pSprite);
            break;

        case PARASITE_POSE_IDLE_INIT:
            ParasiteIdleInit(pSprite);

        case PARASITE_POSE_IDLE:
            ParasiteIdle(pSprite);
            break;

        case PARASITE_POSE_TURNING_AROUND_INIT:
            ParasiteTurningAroundInit(pSprite);

        case PARASITE_POSE_TURNING_AROUND_FIRST_PART:
            ParasiteTurningAroundFirstPart(pSprite);
            break;

        case PARASITE_POSE_TURNING_AROUND_SECOND_PART:
            ParasiteTurningAroundSecondPart(pSprite);
            break;

        case PARASITE_POSE_LANDING_INIT:
            ParasiteLandingInit(pSprite);

        case PARASITE_POSE_LANDING:
            ParasiteLanding(pSprite);
            break;

        case PARASITE_POSE_FALLING_INIT:
            ParasiteFallingInit(pSprite);

        case PARASITE_POSE_FALLING:
            ParasiteFalling(pSprite);
            break;

        case PARASITE_POSE_SAMUS_GRABBED_INIT:
            ParasiteGrabSamus(pSprite);

        case PARASITE_POSE_SAMUS_GRABBED:
            ParasiteSamusGrabbed(pSprite);
            break;

        case PARASITE_POSE_EXPULSED_INIT:
            ParasiteExpelledInit(pSprite);
        
        case PARASITE_POSE_EXPULSED_UP:
            ParasiteExpelledUp(pSprite);
            break;

        case PARASITE_POSE_EXPULSED_DOWN:
            ParasiteExpelledDown(pSprite);
            break;

        case PARASITE_POSE_JUMPING_UP:
            ParasiteJumpingUp(pSprite);
            break;

        case PARASITE_POSE_JUMPING_DOWN:
            ParasiteJumpingDown(pSprite);
            break;

        case PARASITE_POSE_GERON_GRABBED_INIT:
            ParasiteGrabGeron(pSprite);
            break;

        case PARASITE_POSE_GERON_GRABBED:
            ParasiteGeronGrabbed(pSprite);
            break;

        case PARASITE_POSE_DYING_INIT:
            ParasiteDyingInit(pSprite);

        case PARASITE_POSE_DYING:
            ParasiteDying(pSprite);
    }

    pSprite->status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
}
