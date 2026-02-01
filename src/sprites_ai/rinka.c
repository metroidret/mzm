#include "sprites_ai/rinka.h"
#include "sprites_ai/zebetite_and_cannon.h"
#include "gba/display.h"
#include "syscalls.h"
#include "macros.h"

#include "data/sprites/rinka.h"
#include "data/sprites/zebetite_and_cannon.h"
#include "data/sprite_data.h"

#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/event.h"
#include "constants/samus.h"

#include "structs/display.h"
#include "structs/sprite.h"
#include "structs/samus.h"

#define RINKA_POSE_SPAWNING_INIT 0x8
#define RINKA_POSE_SPAWNING 0x9
#define RINKA_POSE_MOVING 0x23

/**
 * @brief 3630c | 98 | Initializes a rinka sprite
 * 
 */
static void RinkaInit(void)
{
    gCurrentSprite.hitboxTop = -SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + QUARTER_BLOCK_SIZE);
    gCurrentSprite.hitboxBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + QUARTER_BLOCK_SIZE);
    gCurrentSprite.hitboxLeft = -SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + QUARTER_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + QUARTER_BLOCK_SIZE);

    gCurrentSprite.drawDistanceTop = EIGHTH_BLOCK_SIZE;
    gCurrentSprite.drawDistanceBottom = EIGHTH_BLOCK_SIZE;
    gCurrentSprite.drawDistanceHorizontal = EIGHTH_BLOCK_SIZE;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;

    // Get spawn tile position
    gCurrentSprite.work3 = SUB_PIXEL_TO_BLOCK_(gCurrentSprite.yPosition - HALF_BLOCK_SIZE);
    gCurrentSprite.work2 = SUB_PIXEL_TO_BLOCK_(gCurrentSprite.xPosition - HALF_BLOCK_SIZE);

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.bgPriority = BGCNT_GET_PRIORITY(gIoRegistersBackup.BG1CNT);
    gCurrentSprite.work1 = 0;

    if (gCurrentSprite.spriteId != PSPRITE_RINKA_GREEN && gCurrentSprite.spriteId != PSPRITE_RINKA_ORANGE)
        gCurrentSprite.frozenPaletteRowOffset = 1;
}

/**
 * @brief 363a4 | 3c | Initializes a rinka to be spawning
 * 
 */
static void RinkaSpawningInit(void)
{
    gCurrentSprite.pose = RINKA_POSE_SPAWNING;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    if (gCurrentSprite.spriteId == PSPRITE_RINKA_GREEN)
    {
        gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
        gCurrentSprite.pOam = sRinkaGreenOam_Spawning;
    }
    else
    {
        gCurrentSprite.pOam = sRinkaOrangeOam_Spawning;
    }
}

/**
 * @brief 363e0 | 94 | Handles a rinka respawning
 * 
 */
static void RinkaRespawn(void)
{
    // Set spawn position
    gCurrentSprite.yPosition = (gCurrentSprite.work3 * BLOCK_SIZE) + (HALF_BLOCK_SIZE);
    gCurrentSprite.xPosition = (gCurrentSprite.work2 * BLOCK_SIZE) + (HALF_BLOCK_SIZE);

    RinkaSpawningInit();
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.invincibilityStunFlashTimer = 0;
    gCurrentSprite.paletteRow = 0;
    gCurrentSprite.frozenPaletteRowOffset = 0;
    gCurrentSprite.absolutePaletteRow = 0;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    gCurrentSprite.freezeTimer = 0;

    #if defined(BUGFIX)
    gCurrentSprite.standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;
    #endif

    // Set spawn delay
    if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
        gCurrentSprite.work1 = ONE_THIRD_SECOND; // Green rinka
    else
        gCurrentSprite.work1 = CONVERT_SECONDS(1.f); // Orange rinka

    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES;
    // Duplicated code
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
}

/**
 * @brief 36474 | 118 | Handles a rinka spawning
 * 
 */
static void RinkaSpawning(void)
{
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;

    // Spawn delay
    if (gCurrentSprite.work1 != 0)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work1);
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6 + 1.f / 60);
        }
    }
    else
    {
        // Vulnerability delay
        if (gCurrentSprite.work0 != 0)
        {
            gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (gCurrentSprite.work0 == 0)
                gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        }
        else if (SpriteUtilHasCurrentAnimationEnded())
        {
            if (gCurrentSprite.spriteId == PSPRITE_RINKA_GREEN)
                gCurrentSprite.pOam = sRinkaGreenOam_Moving;
            else
                gCurrentSprite.pOam = sRinkaOrangeOam_Moving;

            gCurrentSprite.pose = RINKA_POSE_MOVING;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.scaling = 0;

            samusY = gSamusData.yPosition - (BLOCK_SIZE - PIXEL_SIZE);
            samusX = gSamusData.xPosition;
            spriteY = gCurrentSprite.yPosition;
            spriteX = gCurrentSprite.xPosition;

            // Set destination position
            gCurrentSprite.yPositionSpawn = samusY;
            gCurrentSprite.xPositionSpawn = samusX;

            // Set direction
            if (samusY < spriteY)
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            else
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

                
            if (samusX < spriteX)
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            else
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        }
    }
}

/**
 * @brief 3658c | 234 | Handles a rinka moving
 * 
 */
static void RinkaMove(void)
{
    u16 velocity;
    u32 spawnY;
    u32 spawnX;
    u8 respawn;
    u16 distanceYDown;
    u16 distanceYUp;
    u16 distanceXLeft;
    u16 distanceXRight;
    s32 totalDistance;
    u16 samusY;
    u16 spriteY;
    u16 acceleration;

    respawn = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
        velocity = PIXEL_SIZE + ONE_SUB_PIXEL;
    else
        velocity = PIXEL_SIZE;

    acceleration = ++gCurrentSprite.scaling;
    velocity *= acceleration;

    spawnY = gCurrentSprite.work3 * BLOCK_SIZE + HALF_BLOCK_SIZE;
    spawnX = gCurrentSprite.work2 * BLOCK_SIZE + HALF_BLOCK_SIZE;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        distanceYUp = gCurrentSprite.yPositionSpawn - spawnY;
    else
        distanceYDown = spawnY - gCurrentSprite.yPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        distanceXRight = gCurrentSprite.xPositionSpawn - spawnX;
    else
        distanceXLeft = spawnX - gCurrentSprite.xPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYUp * distanceYUp);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((s32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((s32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYDown * distanceYDown);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = spawnY - ((velocity * ((s32)(distanceYDown << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((s32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYUp * distanceYUp);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((s32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX - ((velocity * ((s32)(distanceXLeft << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYDown * distanceYDown);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = spawnY - ((velocity * ((s32)(distanceYDown << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX - ((velocity * ((s32)(distanceXLeft << 0xA) / totalDistance) >> 0xA));
            }
        }
    }

    if (!(gCurrentSprite.xPosition & 0x8000))
    {
        if (gCurrentSprite.xPosition > gSamusData.xPosition)
        {
            if (gCurrentSprite.xPosition - gSamusData.xPosition > BLOCK_SIZE * 16)
                respawn++;
        }
        else
        {
            if (gSamusData.xPosition - gCurrentSprite.xPosition > BLOCK_SIZE * 16)
                respawn++;
        }
    }
    else
    {
        respawn++;
    }

    if (!(gCurrentSprite.yPosition & 0x8000))
    {
        if (gCurrentSprite.yPosition > gSamusData.yPosition)
        {
            if (gCurrentSprite.yPosition - gSamusData.yPosition > BLOCK_SIZE * 16)
                respawn++;
        }
        else
        {
            if (gSamusData.yPosition - gCurrentSprite.yPosition > BLOCK_SIZE * 16)
                respawn++;
        }
    }
    else
    {
        respawn++;
    }

    if (respawn)
        RinkaRespawn();
}

/**
 * @brief 367c0 | 20 | Initializes a rinka mother brain to be spawning
 * 
 */
static void RinkaMotherBrainSpawningInit(void)
{
    gCurrentSprite.pose = RINKA_POSE_SPAWNING;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.pOam = sRinkaMotherBrainOam_Spawning;
}

/**
 * @brief 367e0 | 184 | Handles a rinka mother brain respawning
 * 
 */
static void RinkaMotherBrainRespawn(void)
{
    u16 spriteY;
    u16 spriteX;
    u16 samusX;
    s32 distance;

    spriteY = gCurrentSprite.work3 * BLOCK_SIZE + HALF_BLOCK_SIZE;
    spriteX = gCurrentSprite.work2 * BLOCK_SIZE + HALF_BLOCK_SIZE;
    samusX = gSamusData.xPosition;

    // Check should be first or second place
    switch (gCurrentSprite.spriteId)
    {
        case PSPRITE_RINKA_MOTHER_BRAIN2:
            distance = (BLOCK_SIZE * 20) / HALF_BLOCK_SIZE;
            if (samusX < spriteX && spriteX - samusX > distance * HALF_BLOCK_SIZE)
            {
                gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                spriteY += BLOCK_SIZE;
                spriteX -= BLOCK_SIZE * 40;
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            }
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN3:
            distance = (BLOCK_SIZE * 17) / HALF_BLOCK_SIZE;
            if (samusX < spriteX && spriteX - samusX > distance * HALF_BLOCK_SIZE)
            {
                gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                spriteY -= BLOCK_SIZE;
                spriteX -= BLOCK_SIZE * 34;
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            }
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN4:
            distance = (BLOCK_SIZE * 12) / HALF_BLOCK_SIZE;
            if (samusX < spriteX && spriteX - samusX > distance * HALF_BLOCK_SIZE)
            {
                gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                spriteX -= BLOCK_SIZE * 24;
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            }
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN5:
            distance = (BLOCK_SIZE * 15) / HALF_BLOCK_SIZE;
            if (samusX < spriteX && spriteX - samusX > distance * HALF_BLOCK_SIZE)
            {
                gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                spriteX -= BLOCK_SIZE * 30;
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            }
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN6:
            distance = (BLOCK_SIZE * 10) / HALF_BLOCK_SIZE;
            if (samusX < spriteX && spriteX - samusX > distance * HALF_BLOCK_SIZE)
            {
                gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
                spriteX -= BLOCK_SIZE * 20;
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            }
            break;
    }

    gCurrentSprite.yPosition = spriteY;
    gCurrentSprite.xPosition = spriteX;
    RinkaMotherBrainSpawningInit();

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    gCurrentSprite.invincibilityStunFlashTimer = 0;
    gCurrentSprite.paletteRow = 0;
    gCurrentSprite.frozenPaletteRowOffset = 1;
    gCurrentSprite.absolutePaletteRow = 0;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    gCurrentSprite.freezeTimer = 0;
    gCurrentSprite.work1 = CONVERT_SECONDS(1.f);
    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    #if defined(BUGFIX)
    gCurrentSprite.standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;
    #endif
}

/**
 * @brief 36964 | 110 | Handles a rinka mother brain spawning
 * 
 */
static void RinkaMotherBrainSpawning(void)
{
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;

    // Spawn delay
    if (gCurrentSprite.work1 != 0)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work1);
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6 + 1.f / 60);;
        }
        else
        {
            RinkaMotherBrainRespawn();
        }
    }
    else
    {
        // Vulnerability delay
        if (gCurrentSprite.work0 != 0)
        {
            gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (gCurrentSprite.work0 == 0)
                gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        }
        else if (SpriteUtilHasCurrentAnimationEnded())
        {
            gCurrentSprite.pOam = sRinkaMotherBrainOam_Moving;

            gCurrentSprite.pose = RINKA_POSE_MOVING;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.scaling = 0;

            samusY = gSamusData.yPosition - (BLOCK_SIZE - PIXEL_SIZE);
            samusX = gSamusData.xPosition;
            spriteY = gCurrentSprite.yPosition;
            spriteX = gCurrentSprite.xPosition;

            // Set destination position
            gCurrentSprite.yPositionSpawn = samusY;
            gCurrentSprite.xPositionSpawn = samusX;

            // Set direction
            if (samusY < spriteY)
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            else
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

                
            if (samusX < spriteX)
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            else
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        }
    }
}

/**
 * @brief 36a74 | 2c0 | Handles the movement of a rinka mother brain
 * 
 */
static void RinkaMotherBrainMove(void)
{
    u16 velocity;
    u8 tileY;
    u8 tileX;
    u16 spawnY;
    u16 spawnX;
    u16 distanceYDown;
    u16 distanceYUp;
    u16 distanceXLeft;
    u16 distanceXRight;
    u8 respawn;
    s32 totalDistance;
    u16 samusY;
    u16 spriteY;
    u16 acceleration;

    respawn = FALSE;

    acceleration = ++gCurrentSprite.scaling;
    velocity = acceleration * PIXEL_SIZE;

    tileX = gCurrentSprite.work2;
    tileY = gCurrentSprite.work3;

    // Check spawn at second place
    switch (gCurrentSprite.spriteId)
    {
        case PSPRITE_RINKA_MOTHER_BRAIN2:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            {
                tileX -= HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
                tileY += ONE_SUB_PIXEL;
            }
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN3:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            {
                tileX -= HALF_BLOCK_SIZE + PIXEL_SIZE / 2;
                tileY -= ONE_SUB_PIXEL;
            }
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN4:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
                tileX -= QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN5:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
                tileX -= HALF_BLOCK_SIZE - PIXEL_SIZE / 2;
            break;

        case PSPRITE_RINKA_MOTHER_BRAIN6:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
                tileX -= QUARTER_BLOCK_SIZE + PIXEL_SIZE;
            break;
    }

    spawnY = BLOCK_TO_SUB_PIXEL(tileY) + HALF_BLOCK_SIZE;
    spawnX = BLOCK_TO_SUB_PIXEL(tileX) + HALF_BLOCK_SIZE;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        distanceYUp = gCurrentSprite.yPositionSpawn - spawnY;
    else
        distanceYDown = spawnY - gCurrentSprite.yPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        distanceXRight = gCurrentSprite.xPositionSpawn - spawnX;
    else
        distanceXLeft = spawnX - gCurrentSprite.xPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYUp * distanceYUp);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((s32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((s32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYDown * distanceYDown);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = spawnY - ((velocity * ((s32)(distanceYDown << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((s32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYUp * distanceYUp);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((s32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX - ((velocity * ((s32)(distanceXLeft << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYDown * distanceYDown);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = spawnY - ((velocity * ((s32)(distanceYDown << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX - ((velocity * ((s32)(distanceXLeft << 0xA) / totalDistance) >> 0xA));
            }
        }
    }

    if (!(gCurrentSprite.xPosition & 0x8000))
    {
        if (gCurrentSprite.xPosition > gSamusData.xPosition)
        {
            if ((gCurrentSprite.xPosition - gSamusData.xPosition) > BLOCK_SIZE * 16)
                respawn++;
        }
        else
        {
            if ((gSamusData.xPosition - gCurrentSprite.xPosition) > BLOCK_SIZE * 16)
                respawn++;
        }
    }
    else
    {
        respawn++;
    }

    if (!(gCurrentSprite.yPosition & 0x8000))
    {
        if (gCurrentSprite.yPosition > gSamusData.yPosition)
        {
            if ((gCurrentSprite.yPosition - gSamusData.yPosition) > BLOCK_SIZE * 16)
                respawn++;
        }
        else
        {
            if ((gSamusData.yPosition - gCurrentSprite.yPosition) > BLOCK_SIZE * 16)
                respawn++;
        }
    }
    else
    {
        respawn++;
    }

    if (respawn)
        RinkaMotherBrainRespawn();
}

/**
 * @brief 36d34 | 9c | Rinka AI
 * 
 */
void Rinka(void)
{
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
            RinkaInit();
            
        case RINKA_POSE_SPAWNING_INIT:
            RinkaSpawningInit();

        case RINKA_POSE_SPAWNING:
            RinkaSpawning();
            break;

        case RINKA_POSE_MOVING:
            RinkaMove();
            break;

        default:
            if (SpriteUtilCheckHasDrops())
            {
                SpriteUtilSpriteDeath(DEATH_NO_DEATH_OR_RESPAWNING_ALREADY_HAS_DROP, gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
            else
            {
                SpriteUtilSpriteDeath(DEATH_RESPAWNING, gCurrentSprite.yPosition, gCurrentSprite.xPosition,
                    TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
            RinkaRespawn();
    }
}

/**
 * @brief 36dd0 | f4 | Rinka mother brain AI
 * 
 */
void RinkaMotherBrain(void)
{
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
    {
        // Kill if mother brain is dead
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        {
            if (!(gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN))
                ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SMALL);
        }

        if (gCurrentSprite.standingOnSprite != SAMUS_STANDING_ON_SPRITE_OFF && gSamusData.standingStatus == STANDING_ENEMY)
        {
            gSamusData.standingStatus = STANDING_MIDAIR;
            gCurrentSprite.standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;
        }

        gCurrentSprite.status = 0;
        return;
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
            RinkaInit();
            
        case RINKA_POSE_SPAWNING_INIT:
            RinkaMotherBrainSpawningInit();

        case RINKA_POSE_SPAWNING:
            RinkaMotherBrainSpawning();
            break;

        case RINKA_POSE_MOVING:
            RinkaMotherBrainMove();
            break;

        default:
            if (SpriteUtilCheckHasDrops())
            {
                SpriteUtilSpriteDeath(DEATH_NO_DEATH_OR_RESPAWNING_ALREADY_HAS_DROP, gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
            else
            {
                SpriteUtilSpriteDeath(DEATH_RESPAWNING, gCurrentSprite.yPosition, gCurrentSprite.xPosition,
                    TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            }
            RinkaMotherBrainRespawn();
    }
}
