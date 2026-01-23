#include "sprites_ai/tangle_vine.h"
#include "macros.h"

#include "data/sprites/tangle_vine.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"

#define TANGLE_VINE_GERUTA_POSE_IDLE 0x9
#define TANGLE_VINE_GERUTA_POSE_NO_GERUTA 0x23

enum TangleVineGerutaStatus {
    TANGLE_VINE_GERUTA_STATUS_VINE_DEAD,
    TANGLE_VINE_GERUTA_STATUS_GERUTA_DEAD,
    TANGLE_VINE_GERUTA_STATUS_FULL
};

#define TANGLE_VINE_GERUTA_PART_IDLE 0xF

#define TANGLE_VINE_POSE_IDLE 0x9

static const struct FrameData* sTangleVineFrameDataPointers[TANGLE_VINE_OAM_END] = {
    [TANGLE_VINE_OAM_TALL_ON_GROUND] = sTangleVineTallOam_OnGround,
    [TANGLE_VINE_OAM_MEDIUM_ON_GROUND] = sTangleVineMediumOam_OnGround,
    [TANGLE_VINE_OAM_SHORT_ON_GROUND] = sTangleVineShortOam_OnGround,
    [TANGLE_VINE_OAM_CURVED_ON_GROUND] = sTangleVineCurvedOam_OnGround,
    [TANGLE_VINE_OAM_TALL_ON_CEILING] = sTangleVineTallOam_OnCeiling,
    [TANGLE_VINE_OAM_MEDIUM_ON_CEILING] = sTangleVineMediumOam_OnCeiling,
    [TANGLE_VINE_OAM_SHORT_ON_CEILING] = sTangleVineShortOam_OnCeiling,
    [TANGLE_VINE_OAM_CURVED_ON_CEILING] = sTangleVineCurvedOam_OnCeiling,
    [TANGLE_VINE_OAM_GERUTA_GRIP] = sTangleVineGerutaPartOam_Grip,
    [TANGLE_VINE_OAM_GERUTA_ROOT] = sTangleVineGerutaOam_Root,
    [TANGLE_VINE_OAM_GERUTA_FULL] = sTangleVineGerutaOam_Full,
    [TANGLE_VINE_OAM_RED_GERUTA_OAM] = sTangleVineRedGerutaOam,
    [TANGLE_VINE_OAM_GERUTA] = sTangleVineGerutaPartOam_Geruta
};

/**
 * @brief 413c4 | 88 | Synchronize the sub sprites of a tangle vine
 * 
 */
void TangleVineSyncSprites(void)
{
    MultiSpriteDataInfo_T pData;
    u16 oamIdx;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];
    
    if (gCurrentSprite.pOam != sTangleVineFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sTangleVineFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition - pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
    else
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

/**
 * @brief 4144c | 1a0 | Tangle vine (geruta) AI
 * 
 */
void TangleVineGeruta(void)
{
    u8 gfxSlot;
    u32 ramSlot;
    u16 yPosition;
    u16 xPosition;
    u8 newRamSlot;
    u8 counter;

    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_TANGLE_VINE_DAMAGE);
    }

    counter = 0;
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE - PIXEL_SIZE);
        gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE - PIXEL_SIZE;

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;
        gCurrentSprite.pose = TANGLE_VINE_GERUTA_POSE_IDLE;

        gCurrentSprite.pOam = sTangleVineGerutaOam_Root;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gSubSpriteData1.pMultiOam = sTangleVineGerutaMultiSpriteData_Idle;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        gSubSpriteData1.health = TANGLE_VINE_GERUTA_STATUS_VINE_DEAD;
        gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

        gCurrentSprite.frozenPaletteRowOffset = 1;
        gCurrentSprite.drawOrder = 5;
        gCurrentSprite.roomSlot = TANGLE_VINE_GERUTA_PART_ROOT;

        yPosition = gSubSpriteData1.yPosition;
        xPosition = gSubSpriteData1.xPosition;
        gfxSlot = gCurrentSprite.spritesetGfxSlot;
        ramSlot = gCurrentSprite.primarySpriteRamSlot;

        newRamSlot = SpriteSpawnSecondary(SSPRITE_TANGLE_VINE_GERUTA_PART, TANGLE_VINE_GERUTA_PART_GRIP,
            gfxSlot, ramSlot, yPosition, xPosition, 0);

        if (newRamSlot >= MAX_AMOUNT_OF_SPRITES)
            counter = TRUE;

        newRamSlot = SpriteSpawnSecondary(SSPRITE_TANGLE_VINE_GERUTA_PART, TANGLE_VINE_GERUTA_PART_GERUTA,
            gfxSlot, ramSlot, yPosition, xPosition, 0);

        if (newRamSlot >= MAX_AMOUNT_OF_SPRITES)
            counter++;

        if (counter != 0)
            gCurrentSprite.status = 0;
        else
            gSubSpriteData1.health = TANGLE_VINE_GERUTA_STATUS_FULL;
    }
    else 
    {
        if (gCurrentSprite.pose >= SPRITE_POSE_DESTROYED)
        {
            gSubSpriteData1.health = TANGLE_VINE_GERUTA_STATUS_VINE_DEAD;
            ParticleSet(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + PIXEL_SIZE / 2),
                gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE, TRUE, PE_SPRITE_EXPLOSION_BIG);
            return;
        }

        if (gCurrentSprite.pose == TANGLE_VINE_GERUTA_POSE_IDLE && gSubSpriteData1.health == TANGLE_VINE_GERUTA_STATUS_GERUTA_DEAD)
        {
            gCurrentSprite.pOam = sTangleVineGerutaOam_Full;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = TANGLE_VINE_GERUTA_POSE_NO_GERUTA;
        }
    }

    SpriteUtilUpdateSubSprite1Anim();
    SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOam();
}

/**
 * @brief 415ec | 130 | Tangle vine (geruta) part AI
 * 
 */
void TangleVineGerutaPart(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.pose = TANGLE_VINE_GERUTA_PART_IDLE;

        if (gCurrentSprite.roomSlot == TANGLE_VINE_GERUTA_PART_GRIP)
        {
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.health = 0;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 3;
        }
        else if (gCurrentSprite.roomSlot == TANGLE_VINE_GERUTA_PART_GERUTA)
        {
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE;

            gCurrentSprite.health = 1;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        }
        else
        {
            gCurrentSprite.status = 0;
        }
    }

    if (gCurrentSprite.roomSlot == TANGLE_VINE_GERUTA_PART_GRIP)
    {
        if (gSubSpriteData1.health != TANGLE_VINE_GERUTA_STATUS_FULL)
        {
            gCurrentSprite.status = 0;
            return;
        }
        else
        {
            gCurrentSprite.paletteRow = gSpriteData[ramSlot].paletteRow;
        }
    }
    else if (gCurrentSprite.roomSlot == TANGLE_VINE_GERUTA_PART_GERUTA)
    {
        if (gCurrentSprite.health == 0)
        {
            gSubSpriteData1.health = TANGLE_VINE_GERUTA_STATUS_GERUTA_DEAD;
            ParticleSet(gCurrentSprite.yPosition + EIGHTH_BLOCK_SIZE, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
            SoundPlay(SOUND_SPRITE_EXPLOSION_MEDIUM);
            gCurrentSprite.status = 0;
            return;
        }
        
        if (gSubSpriteData1.health == TANGLE_VINE_GERUTA_STATUS_VINE_DEAD)
        {
            SpriteSpawnPrimary(PSPRITE_GERUTA_RED, 0x80, 5, gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition, 0);
            gCurrentSprite.status = 0;
            return;
        }
    }

    TangleVineSyncSprites();
}

/**
 * @brief 417ac | cc | Tangle vine (red geruta) AI
 * 
 */
void TangleVineRedGeruta(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_TANGLE_VINE_DAMAGE);
    }

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE);
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE + PIXEL_SIZE);
        gCurrentSprite.hitboxRight = (HALF_BLOCK_SIZE + PIXEL_SIZE);

        gCurrentSprite.pOam = sTangleVineRedGerutaOam;
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = TANGLE_VINE_POSE_IDLE;
        gCurrentSprite.frozenPaletteRowOffset = 2;
    }
    else if (gCurrentSprite.pose >= SPRITE_POSE_DESTROYED)
    {
        ParticleSet(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE,
            PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + PIXEL_SIZE / 2),
            gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}

/**
 * @brief 417e8 | d0 | Tangle vine (imago right) AI
 * 
 */
void TangleVineLarvaRight(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_TANGLE_VINE_DAMAGE);
    }

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.yPosition -= QUARTER_BLOCK_SIZE;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 3);
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = 0;
        gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE + PIXEL_SIZE;

        gCurrentSprite.pOam = sTangleVineLarvaRightOam;
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = TANGLE_VINE_POSE_IDLE;
        gCurrentSprite.frozenPaletteRowOffset = 2;
    }
    else if (gCurrentSprite.pose >= SPRITE_POSE_DESTROYED)
    {
        ParticleSet(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE, PE_SPRITE_EXPLOSION_BIG);
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - (BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE),
            gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}

/**
 * @brief 418b8 | d4 | Tangle vine (imago left) AI
 * 
 */
void TangleVineLarvaLeft(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_TANGLE_VINE_DAMAGE);
    }

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.xPosition -= QUARTER_BLOCK_SIZE;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 3);
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE + PIXEL_SIZE);
        gCurrentSprite.hitboxRight = 0;

        gCurrentSprite.pOam = sTangleVineLarvaLeftOam;
        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = TANGLE_VINE_POSE_IDLE;
        gCurrentSprite.frozenPaletteRowOffset = 2;
        gCurrentSprite.drawOrder = 5;
    }
    else if (gCurrentSprite.pose >= SPRITE_POSE_DESTROYED)
    {
        ParticleSet(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition + QUARTER_BLOCK_SIZE, PE_SPRITE_EXPLOSION_BIG);
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - (BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE),
            gCurrentSprite.xPosition - QUARTER_BLOCK_SIZE, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}

/**
 * @brief 4198c | 130 | Tangle vine (tall) AI
 * 
 */
void TangleVineTall(void)
{
    u16 yPosition;

    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_TANGLE_VINE_DAMAGE);
    }

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);
            gCurrentSprite.drawDistanceBottom = 0;
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 4 - EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

            gCurrentSprite.pOam = sTangleVineTallOam_OnGround;
        }
        else
        {
            gCurrentSprite.drawDistanceTop = 0;
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = BLOCK_SIZE * 4 - EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

            gCurrentSprite.pOam = sTangleVineTallOam_OnCeiling;

            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;

        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = TANGLE_VINE_POSE_IDLE;
        gCurrentSprite.frozenPaletteRowOffset = 1;
    }
    else if (gCurrentSprite.pose >= SPRITE_POSE_DESTROYED)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
            yPosition = gCurrentSprite.yPosition + BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE;
        else
            yPosition = gCurrentSprite.yPosition - BLOCK_SIZE;

        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}

/**
 * @brief 41abc | 130 | Tangle vine (medium) AI
 * 
 */
void TangleVineMedium(void)
{
    u16 yPosition;

    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_TANGLE_VINE_DAMAGE);
    }

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
            gCurrentSprite.drawDistanceBottom = 0;
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 3 - EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

            gCurrentSprite.pOam = sTangleVineMediumOam_OnGround;
        }
        else
        {
            gCurrentSprite.drawDistanceTop = 0;
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = BLOCK_SIZE * 3 - EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

            gCurrentSprite.pOam = sTangleVineMediumOam_OnCeiling;

            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;

        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = TANGLE_VINE_POSE_IDLE;
        gCurrentSprite.frozenPaletteRowOffset = 1;
    }
    else if (gCurrentSprite.pose >= SPRITE_POSE_DESTROYED)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
            yPosition = gCurrentSprite.yPosition + BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE;
        else
            yPosition = gCurrentSprite.yPosition - THREE_QUARTER_BLOCK_SIZE;

        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
    }
}

/**
 * @brief 41bec | 130 | Tangle vine (curved) AI
 * 
 */
void TangleVineCurved(void)
{
    u16 yPosition;

    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_TANGLE_VINE_DAMAGE);
    }

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = 0;
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2);
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;

            gCurrentSprite.pOam = sTangleVineCurvedOam_OnGround;
        }
        else
        {
            gCurrentSprite.drawDistanceTop = 0;
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = BLOCK_SIZE * 2;
            gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;

            gCurrentSprite.pOam = sTangleVineCurvedOam_OnCeiling;

            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;

        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = TANGLE_VINE_POSE_IDLE;
        gCurrentSprite.frozenPaletteRowOffset = 1;
    }
    else if (gCurrentSprite.pose >= SPRITE_POSE_DESTROYED)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
            yPosition = gCurrentSprite.yPosition + BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
        else
            yPosition = gCurrentSprite.yPosition - (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);

        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
    }
}

/**
 * @brief 41d1c | 130 | Tangle vine (short) AI
 * 
 */
void TangleVineShort(void)
{
    u16 yPosition;

    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_TANGLE_VINE_DAMAGE);
    }

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = 0;
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;

            gCurrentSprite.pOam = sTangleVineShortOam_OnGround;
        }
        else
        {
            gCurrentSprite.drawDistanceTop = 0;
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;

            gCurrentSprite.pOam = sTangleVineShortOam_OnCeiling;

            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_SOLID;

        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = TANGLE_VINE_POSE_IDLE;
        gCurrentSprite.frozenPaletteRowOffset = 1;
    }
    else if (gCurrentSprite.pose >= SPRITE_POSE_DESTROYED)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
            yPosition = gCurrentSprite.yPosition + BLOCK_SIZE;
        else
            yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;

        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}
