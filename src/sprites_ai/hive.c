#include "sprites_ai/hive.h"
#include "macros.h"
#include "gba/display.h"

#include "data/sprites/hive.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/bg_clip.h"
#include "structs/display.h"
#include "structs/sprite.h"
#include "structs/samus.h"

#define HIVE_POSE_PHASE_1 0x9
#define HIVE_POSE_PHASE_2 0x23
#define HIVE_POSE_PHASE_3 0x25
#define HIVE_POSE_DEAD 0x67

#define HIVE_ROOTS_POSE_IDLE 0x9

#define MELLOW_POSE_IDLE 0x9
#define MELLOW_POSE_MOVE_INIT 0x22
#define MELLOW_POSE_MOVE 0x23
#define MELLOW_POSE_FLEEING 0x25

#define MELLOW_SWARM_POSE_IDLE 0x9

/**
 * @brief 24a10 | 2c | Spawns 2 particle effects
 * 
 */
static void HiveSpawnParticle(void)
{
    u16 xPosition;
    u16 yPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    ParticleSet(yPosition - HALF_BLOCK_SIZE, xPosition, PE_MEDIUM_DUST);
    ParticleSet(yPosition + BLOCK_SIZE + HALF_BLOCK_SIZE, xPosition, PE_TWO_MEDIUM_DUST);
}

/**
 * @brief 24a3c | 124 | Initializes a hive sprite
 * 
 */
static void HiveInit(void)
{
    u8 roomSlot;
    u8 gfxSlot;
    u16 yPosition;
    u16 xPosition;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_THREE_HIVES_DESTROYED))
    {
        // Kill if the 3 hives were destroyed
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + QUARTER_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2);
    gCurrentSprite.hitboxBottom = BLOCK_SIZE * 2;
    gCurrentSprite.hitboxLeft = -THREE_QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxRight = THREE_QUARTER_BLOCK_SIZE;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;
    gCurrentSprite.frozenPaletteRowOffset = 1;

    gCurrentSprite.pOam = sHiveOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.drawOrder = 5;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.pose = 9;
    gCurrentSprite.work0 = 0;
    
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;
    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    roomSlot = gCurrentSprite.roomSlot;
    
    // Spawn rooms
    SpriteSpawnSecondary(SSPRITE_HIVE_ROOTS, roomSlot, gfxSlot, gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, 0);

    // Spawn mellows
    SpriteSpawnPrimary(PSPRITE_MELLOW, roomSlot, gfxSlot,
        yPosition + BLOCK_SIZE, xPosition - (HALF_BLOCK_SIZE - ONE_SUB_PIXEL), 0);
    SpriteSpawnPrimary(PSPRITE_MELLOW, roomSlot, gfxSlot,
        yPosition + HALF_BLOCK_SIZE, xPosition + QUARTER_BLOCK_SIZE, 0);
    SpriteSpawnPrimary(PSPRITE_MELLOW, roomSlot, gfxSlot,
        yPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE), xPosition - QUARTER_BLOCK_SIZE, 0);
    SpriteSpawnPrimary(PSPRITE_MELLOW, roomSlot, gfxSlot,
        yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), xPosition + (HALF_BLOCK_SIZE - ONE_SUB_PIXEL), 0);
}

/**
 * @brief 24b60 | 54 | Counts the mellow linked to the current hive
 * 
 * @return u8 Number of mellows
 */
static u8 HiveCountMellows(void)
{
    u8 count;
    u8 roomSlot;
    u8 collision;
    struct SpriteData* pSprite;

    count = 0;
    collision = SSC_MELLOW;
    // For current hive only
    roomSlot = gCurrentSprite.roomSlot;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (!(pSprite->status & SPRITE_STATUS_EXISTS))
            continue;

        if (pSprite->samusCollision == collision && pSprite->roomSlot == roomSlot)
            count++;
    }

    return count;
}

/**
 * @brief 24bb4 | 78 | Handles the phase 1 of the hive
 * 
 */
static void HivePhase1(void)
{
    if (HiveCountMellows() < 4)
    {
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    }
    
    if (gCurrentSprite.health < GET_PSPRITE_HEALTH(gCurrentSprite.spriteId) / 2)
    {
        gCurrentSprite.frozenPaletteRowOffset = 2;

        gCurrentSprite.pOam = sHiveOam_Phase2;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = HIVE_POSE_PHASE_2;
        SoundPlayNotAlreadyPlaying(SOUND_HIVE_SHRINKING);
        HiveSpawnParticle();
    }
}

/**
 * @brief 24c2c | 78 | Handles the phase 2 of the hive
 * 
 */
static void HivePhase2(void)
{
    if (HiveCountMellows() < 4)
    {
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    }
    
    if (gCurrentSprite.health < GET_PSPRITE_HEALTH(gCurrentSprite.spriteId) / 4)
    {
        gCurrentSprite.frozenPaletteRowOffset = 3;

        gCurrentSprite.pOam = sHiveOam_Phase3;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = HIVE_POSE_PHASE_3;
        SoundPlayNotAlreadyPlaying(SOUND_HIVE_SHRINKING);
        HiveSpawnParticle();
    }
}

/**
 * @brief 24ca4 | 30 | Handles the phase 3 of the hive
 * 
 */
static void HivePhase3(void)
{
    if (HiveCountMellows() < 4)
    {
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    }
}

/**
 * @brief 24cd4 | 10c | Handles the hive dying
 * 
 */
static void HiveDying(void)
{
    u8 count;
    u8 collision;
    struct SpriteData* pSprite;
    u8 param;
    u8 pose;

    count = 0;
    param = PSPRITE_HIVE;

    // Count hives
    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (!(pSprite->status & SPRITE_STATUS_EXISTS))
            continue;

        if (pSprite->properties & SP_SECONDARY_SPRITE)
            continue;

        if (pSprite->spriteId == param && pSprite->health != 0)
            count++;
    }

    if (count == 0) // Set event if all hives are dead
        EventFunction(EVENT_ACTION_SETTING, EVENT_THREE_HIVES_DESTROYED);

    pose = MELLOW_POSE_IDLE;
    param = gCurrentSprite.roomSlot;
    collision = SSC_MELLOW;

    // Set mellows of current hive to fleeing behavior
    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (!(pSprite->status & SPRITE_STATUS_EXISTS))
            continue;

        if (pSprite->samusCollision == collision && pSprite->roomSlot == param && pSprite->pose == pose)
        {
            pSprite->pose = MELLOW_POSE_FLEEING;
            pSprite->properties |= SP_KILL_OFF_SCREEN;
        }
    }

    if (gCurrentSprite.pose > SPRITE_POSE_DESTROYED || gCurrentSprite.work0 != 0)
    {
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition + BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
            gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
    else
    {
        // Set killed behavior
        gCurrentSprite.pose = HIVE_POSE_DEAD;
        gCurrentSprite.pOam = sHiveOam_Dying;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.samusCollision = SSC_NONE;
        SoundPlayNotAlreadyPlaying(SOUND_HIVE_DEAD);
        HiveSpawnParticle();
    }
}

/**
 * @brief 24de0 | 10 | Sets the ignore samus collision timer to 1
 * 
 */
static void HiveDead(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
}

/**
 * @brief 24df0 | 64 | Initializes a hive roots sprite
 * 
 */
static void HiveRootsInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(0);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + QUARTER_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -PIXEL_SIZE;
    gCurrentSprite.hitboxBottom = PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
    gCurrentSprite.hitboxRight = PIXEL_SIZE;

    gCurrentSprite.pose = HIVE_ROOTS_POSE_IDLE;

    gCurrentSprite.pOam = sHiveRootsOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.frozenPaletteRowOffset = 1;
}

/**
 * @brief 24e54 | 24 | Synchronizes the position of the roots with the hive
 * 
 */
static void HiveRootsIdle(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
    gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;
}

/**
 * @brief 24e78 | 150 | Initializes a mellow sprite
 * 
 * @param pSprite Sprite data pointer
 */
static void MellowInit(struct SpriteData* pSprite)
{
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_THREE_HIVES_DESTROYED))
    {
        pSprite->status = 0;
        return;
    }

    pSprite->status &= ~SPRITE_STATUS_NOT_DRAWN;

    pSprite->drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    pSprite->drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    pSprite->drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(THREE_QUARTER_BLOCK_SIZE);

    pSprite->hitboxTop = -(QUARTER_BLOCK_SIZE - PIXEL_SIZE);
    pSprite->hitboxBottom = (QUARTER_BLOCK_SIZE - PIXEL_SIZE);
    pSprite->hitboxLeft = -HALF_BLOCK_SIZE;
    pSprite->hitboxRight = HALF_BLOCK_SIZE;

    pSprite->animationDurationCounter = 0;
    pSprite->currentAnimationFrame = 0;
    pSprite->samusCollision = SSC_MELLOW;
    
    pSprite->health = GET_PSPRITE_HEALTH(pSprite->spriteId);
    if (pSprite->roomSlot != 0x88)
    {
        pSprite->pOam = sMellowOam_Idle;
        pSprite->pose = MELLOW_POSE_IDLE;
        pSprite->work3 = MUL_SHIFT(gSpriteRng, 4);
        if (gSpriteRng & 0x1)
            pSprite->work2 = 0x14;
        else
            pSprite->work2 = 0x3C;
        
        if (pSprite->xPosition & 0x1)
            pSprite->drawOrder = 3;
        else
            pSprite->drawOrder = 6;
    }
    else
    {
        pSprite->pOam = sMellowOam_SamusDetected;
        pSprite->bgPriority = BGCNT_GET_PRIORITY(gIoRegistersBackup.BG1CNT);
        pSprite->drawOrder = 3;
        pSprite->work1 = 0;
        pSprite->work2 = 1;
        pSprite->work0 = 0;
        pSprite->work3 = 1;
        pSprite->xPositionSpawn = gSpriteRng & 0x3;
        pSprite->pose = MELLOW_POSE_MOVE;
        pSprite->scaling = 0x20;
        SpriteUtilMakeSpriteFaceSamusDirection();
        if (pSprite->yPosition > gSamusData.yPosition + gSamusPhysics.hitboxTop)
            pSprite->status &= ~SPRITE_STATUS_FACING_DOWN;
        else
            pSprite->status |= SPRITE_STATUS_FACING_DOWN;
    }
}

/**
 * @brief 24fc8 | c0 | Handles a mellow being idle
 * 
 * @param pSprite Sprite data pointer
 */
static void MellowIdle(struct SpriteData* pSprite)
{
    s32 movement;
    u8 offset;

    // Idle Y
    offset = pSprite->work3;
    movement = sMellowIdleYVelocity[offset];

    if (movement == SHORT_MAX)
    {
        movement = sMellowIdleYVelocity[0];
        offset = 0;
    }

    // Idle X
    pSprite->work3 = offset + 1;
    pSprite->yPosition += movement;

    offset = pSprite->work2;
    movement = sMellowIdleXVelocity[offset];

    if (movement == SHORT_MAX)
    {
        movement = sMellowIdleXVelocity[0];
        offset = 0;
    }

    pSprite->work2 = offset + 1;
    pSprite->xPosition += movement;

    if (pSprite->work2 == 1 || pSprite->work2 == ARRAY_SIZE(sMellowIdleXVelocity) / 2 + 1)
    {
        if (pSprite->drawOrder == 3)
            pSprite->drawOrder = 6;
        else
            pSprite->drawOrder = 3;
    }

    // Detect samus
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 5, BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE) != NSLR_OUT_OF_RANGE)
    {
        pSprite->pose = MELLOW_POSE_MOVE_INIT;
        pSprite->pOam = sMellowOam_SamusDetected;
        pSprite->animationDurationCounter = 0;
        pSprite->currentAnimationFrame = 0;

        pSprite->bgPriority = BGCNT_GET_PRIORITY(gIoRegistersBackup.BG1CNT);
        pSprite->drawOrder = 3;
    }
}

/**
 * @brief 25088 | 48 | Handles the mellow fleeing
 * 
 * @param pSprite Sprite data pointer
 */
static void MellowFleeing(struct SpriteData* pSprite)
{
    u8 rng;
    s16 movement;

    rng = gSpriteRng / 4;
    movement = rng + EIGHTH_BLOCK_SIZE;
    if (pSprite->work2 < ARRAY_SIZE(sMellowIdleXVelocity) / 2)
        pSprite->xPosition += movement;
    else
        pSprite->xPosition -= movement;

    movement = rng + PIXEL_SIZE;
    if (pSprite->work3 < ARRAY_SIZE(sMellowIdleYVelocity) / 2)
        pSprite->yPosition += movement;
    else
        pSprite->yPosition -= movement;
}

/**
 * @brief 250d0 | 68 | Initializes a mellow sprite to be in samus detected behavior
 * 
 * @param pSprite Sprite data pointer
 */
static void MellowMoveInit(struct SpriteData* pSprite)
{
    pSprite->work1 = 0;
    pSprite->work2 = 1;
    pSprite->work0 = 0;
    pSprite->work3 = 1;

    pSprite->xPositionSpawn = 0;
    pSprite->pose = MELLOW_POSE_MOVE;
    pSprite->scaling = CONVERT_SECONDS(.5f + 1.f / 30);

    SpriteUtilMakeSpriteFaceSamusDirection();
    if (pSprite->yPosition > gSamusData.yPosition + gSamusPhysics.hitboxTop)
        pSprite->status &= ~SPRITE_STATUS_FACING_DOWN;
    else
        pSprite->status |= SPRITE_STATUS_FACING_DOWN;
}

/**
 * @brief 25138 | 3fc | Handles the mellow movement in samus detected behavior
 * 
 * @param pSprite Sprite data pointer
 */
static void MellowMove(struct SpriteData* pSprite)
{
    struct SpriteData* pMellow;
    u8 offset;

    u8 verticalLimit;
    u8 horizontalLimit;
    u8 flip;
    
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u32 newPos;
    u8 ramSlot;

    flip = FALSE;
    offset = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

    spriteTop = pSprite->yPosition - offset;
    spriteBottom = pSprite->yPosition + offset;
    spriteLeft = pSprite->xPosition - offset;
    spriteRight = pSprite->xPosition + offset;

    ramSlot = pSprite->primarySpriteRamSlot + 1;
    
    for (pMellow = gSpriteData + ramSlot; pMellow < gSpriteData + MAX_AMOUNT_OF_SPRITES; pMellow++)
    {
        pMellow++,pMellow--; // Needed to produce matching ASM.
        if (!(pMellow->status & SPRITE_STATUS_EXISTS))
            continue;

        if (pMellow->samusCollision != SSC_MELLOW)
            continue;

        spriteY = pMellow->yPosition;
        spriteX = pMellow->xPosition;
        if (spriteBottom > spriteY - offset && spriteTop < spriteY + offset &&
            spriteRight > spriteX - offset && spriteLeft < spriteX + offset)
        {
            if (pMellow->freezeTimer == 0)
            {
                if (pSprite->yPosition > spriteY)
                    pMellow->yPosition -= PIXEL_SIZE;
                else
                    pMellow->yPosition += PIXEL_SIZE;

                if (pSprite->xPosition > spriteX)
                    pMellow->xPosition -= PIXEL_SIZE;
                else
                    pMellow->xPosition += PIXEL_SIZE;
            }
            break;
        }
    }

    if (pSprite->roomSlot == 0x88)
    {
        verticalLimit = 0x14;
        horizontalLimit = gSpriteRng + 0x1E;
        spriteY = gSamusData.yPosition - (gSpriteRng * 4 + 0xDC);
        spriteX = gSamusData.xPosition;

        switch (pSprite->xPositionSpawn)
        {
            case 1:
                spriteY -= BLOCK_SIZE * 2;
                if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
                    spriteX += BLOCK_SIZE * 4;
                else
                    spriteX -= BLOCK_SIZE * 4;
                break;

            case 3:
                spriteY += BLOCK_SIZE / 2;
                if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
                    spriteX -= BLOCK_SIZE * 4;
                else
                    spriteX += BLOCK_SIZE * 4;
                break;
        }
    }
    else
    {
        spriteY = gSamusData.yPosition + gSamusPhysics.hitboxTop;
        spriteX = gSamusData.xPosition;
        verticalLimit = 0x1E;
        horizontalLimit = 0x28;

        switch (pSprite->xPositionSpawn)
        {
            case 1:
                spriteY -= BLOCK_SIZE / 2;
                if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
                    spriteX += BLOCK_SIZE - BLOCK_SIZE / 4;
                else
                    spriteX -= BLOCK_SIZE - BLOCK_SIZE / 4;
                break;

            case 3:
                spriteY += BLOCK_SIZE / 2;
                if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
                    spriteX -= BLOCK_SIZE - BLOCK_SIZE / 4;
                else
                    spriteX += BLOCK_SIZE - BLOCK_SIZE / 4;
                break;
        }
    }

    if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (pSprite->work1 == 0)
        {
            if (pSprite->xPosition <= spriteX - 4)
            {
                if (pSprite->work2 < horizontalLimit)
                    pSprite->work2++;

                pSprite->xPosition += (pSprite->work2 >> 2);
            }
            else
                pSprite->work1 = pSprite->work2;
        }
        else
        {
            if (--pSprite->work1 != 0)
                pSprite->xPosition += (pSprite->work1 >> 2);
            else
                flip++;
        }
    }
    else
    {
        if (pSprite->work1 == 0)
        {
            if (pSprite->xPosition < spriteX + 4)
                pSprite->work1 = pSprite->work2;
            else
            {
                if (pSprite->work2 < horizontalLimit)
                    pSprite->work2++;

                offset = (pSprite->work2 >> 2);
                newPos = pSprite->xPosition - offset;
                if (newPos & 0x8000)
                {
                    flip++;
                    pSprite->work1 = 0;
                    pSprite->xPosition = 0;
                }
                else
                    pSprite->xPosition = newPos;
            }
        }
        else
        {
            if (--pSprite->work1 != 0)
            {
                offset = (pSprite->work1 >> 2);
                newPos = pSprite->xPosition - offset;
                if (newPos & 0x8000)
                {
                    flip++;
                    pSprite->work1 = 0x0;
                    pSprite->xPosition = 0x0;
                }
                else
                    pSprite->xPosition = newPos;
            }
            else
                flip++;
        }
    }

    if (flip)
    {
        pSprite->status ^= SPRITE_STATUS_FACING_RIGHT;
        pSprite->work2 = 1;
        pSprite->xPositionSpawn++;
        if (pSprite->xPositionSpawn > 3)
            pSprite->xPositionSpawn = 0;
    }

    flip = FALSE;
    
    if (pSprite->status & SPRITE_STATUS_FACING_DOWN)
    {
        if (pSprite->work0 == 0)
        {
            if (pSprite->yPosition > spriteY - 4)
                pSprite->work0 = pSprite->work3;
            else
            {
                if (pSprite->work3 < verticalLimit)
                    pSprite->work3++;

                pSprite->yPosition += (pSprite->work3 >> 2);
            }
        }
        else
        {
            if (--pSprite->work0 != 0)
                pSprite->yPosition += (pSprite->work0 >> 2);
            else
                flip++;
        }
    }
    else
    {
        if (pSprite->work0 == 0)
        {
            if (pSprite->yPosition < spriteY + 4)
                pSprite->work0 = pSprite->work3;
            else
            {
                if (pSprite->work3 < verticalLimit)
                    pSprite->work3++;

                offset = (pSprite->work3 >> 2);
                newPos = pSprite->yPosition - offset;
                if (newPos & 0x8000)
                {
                    flip++;
                    pSprite->work0 = 0;
                    pSprite->yPosition = 0;
                }
                else
                    pSprite->yPosition = newPos;
            }
        }
        else
        {
            if (--pSprite->work0 != 0)
            {
                offset = (pSprite->work0 >> 2);
                newPos = pSprite->yPosition - offset;
                if (newPos & 0x8000)
                {
                    flip++;
                    pSprite->work0 = 0;
                    pSprite->yPosition = 0;
                }
                else
                    pSprite->yPosition = newPos;
            }
            else
                flip++;
        }
    }

    if (flip)
    {
        pSprite->status ^= SPRITE_STATUS_FACING_DOWN;
        pSprite->work3 = 1;
    }

    pSprite->scaling--;
    if (pSprite->scaling == 0)
    {
        pSprite->scaling = 32;
        if (pSprite->status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_MELLOW_MOVING);
    }
}

void Hive(void)
{
    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent(SSPRITE_HIVE_ROOTS, gCurrentSprite.primarySpriteRamSlot);
        gCurrentSprite.work0 = gCurrentSprite.freezeTimer;
        return;
    }

    if (SpriteUtilIsSpriteStunned())
        return;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            HiveInit();
            break;

        case HIVE_POSE_PHASE_1:
            HivePhase1();
            break;

        case HIVE_POSE_PHASE_2:
            HivePhase2();
            break;

        case HIVE_POSE_PHASE_3:
            HivePhase3();
            break;

        case HIVE_POSE_DEAD:
            HiveDead();
            break;

        default:
            HiveDying();
    }
}

/**
 * @brief 255b8 | ac | Hive roots AI
 * 
 */
void HiveRoots(void)
{
    u8 hiveSlot;

    hiveSlot = gCurrentSprite.primarySpriteRamSlot;
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    if (gSpriteData[hiveSlot].spriteId == PSPRITE_HIVE)
    {
        gCurrentSprite.paletteRow = gSpriteData[hiveSlot].paletteRow;
        if (gSpriteData[hiveSlot].health < GET_PSPRITE_HEALTH(gSpriteData[hiveSlot].spriteId) / 2 && gSpriteData[hiveSlot].freezeTimer == 0)
        {
            gCurrentSprite.status = 0;
            return;
        }
    }
    else
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (gSpriteData[hiveSlot].status == 0)
    {
        gCurrentSprite.status = 0;
        return;
    }

    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
        HiveRootsInit();

    HiveRootsIdle();
}

void Mellow(void)
{
    struct SpriteData* pSprite;

    pSprite = &gCurrentSprite;

    if (pSprite->properties & SP_DAMAGED)
    {
        pSprite->properties &= ~SP_DAMAGED;
        if (pSprite->status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_MELLOW_DAMAGED);
    }
    
    if (pSprite->freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    if (SPRITE_GET_ISFT(*pSprite) > CONVERT_SECONDS(.15f) && pSprite->pose < SPRITE_POSE_DESTROYED)
    {
        if (pSprite->animationDurationCounter != 0)
            APPLY_DELTA_TIME_DEC(pSprite->animationDurationCounter);

        return;
    }

    switch (pSprite->pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            MellowInit(pSprite);
            break;

        case MELLOW_POSE_IDLE:
            MellowIdle(pSprite);
            break;

        case MELLOW_POSE_MOVE_INIT:
            MellowMoveInit(pSprite);

        case MELLOW_POSE_MOVE:
            MellowMove(pSprite);
            break;

        case MELLOW_POSE_FLEEING:
            MellowFleeing(pSprite);
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, pSprite->yPosition, pSprite->xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}

void MellowSwarm(void)
{
    u8 count;
    struct SpriteData* pSprite;
    u8 collision;
    u16 x_pos;
    u16 y_pos;

    count = 0;
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_THREE_HIVES_DESTROYED))
        {
            gCurrentSprite.status = 0;
            return;
        }

        gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    
        gCurrentSprite.hitboxTop = -PIXEL_SIZE;
        gCurrentSprite.hitboxBottom = PIXEL_SIZE;
        gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
        gCurrentSprite.hitboxRight = PIXEL_SIZE;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);

        gCurrentSprite.samusCollision = SSC_NONE;

        gCurrentSprite.pOam = sMellowOam_Idle;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = MELLOW_SWARM_POSE_IDLE;

        if (SUB_PIXEL_TO_PIXEL(gSamusData.xPosition) - SUB_PIXEL_TO_PIXEL(gBg1XPosition) > SUB_PIXEL_TO_PIXEL(SCREEN_SIZE_X_SUB_PIXEL) / 2)
            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;

        gCurrentSprite.yPositionSpawn = 0xF0;

        if (gCurrentSprite.spriteId == PSPRITE_MELLOW_SWARM_HEALTH_BASED)
        {
            if (gEquipment.currentEnergy >= 400)
                gCurrentSprite.work2 = 15;
            else if (gEquipment.currentEnergy >= 300)
                gCurrentSprite.work2 = 12;
            else if (gEquipment.currentEnergy >= 200)
                gCurrentSprite.work2 = 9;
            else if (gEquipment.currentEnergy >= 100)
                gCurrentSprite.work2 = 6;
            else
                gCurrentSprite.work2 = 3;
        }
        else
        {
            gCurrentSprite.work2 = 5;
        }

        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN && gCurrentSprite.yPositionSpawn != 0x0)
    {
        gCurrentSprite.yPositionSpawn--;
    }
    else
    {
        collision = SSC_MELLOW;
        pSprite = gSpriteData;
        while (pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES)
        {
            if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == collision)
            {
                count++;
            }
            pSprite++;
        }

        if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN))
        {
            if (count >= gCurrentSprite.work2)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                return;
            }
        }
        else
        {
            if (count <= 0x13)
                gCurrentSprite.yPositionSpawn = 0xF0;
            else
                return;
        }

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            x_pos = gSamusData.xPosition + (gSpriteRng * 0x20);
        else
            x_pos = gSamusData.xPosition + (gSpriteRng * -0x20);
        if (x_pos & 0x8000)
            x_pos = 0x0;
        y_pos = (u16)(gBg1YPosition - ((gSpriteRng * 0x2) + 0x10));
        SpriteSpawnPrimary(PSPRITE_MELLOW, 0x88, gCurrentSprite.spritesetGfxSlot, y_pos, x_pos, 0x0);
    }
}
