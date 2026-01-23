#include "sprites_ai/rising_chozo_pillar.h"
#include "macros.h"

#include "data/sprites/rising_chozo_pillar.h"
#include "data/sprites/enemy_drop.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/sprite.h"

#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/sprite.h"

#define RISING_CHOZO_PILLAR_POSE_WAIT_FOR_POWER_GRIP 0x8
#define RISING_CHOZO_PILLAR_POSE_EXTENDING 0x9
#define RISING_CHOZO_PILLAR_POSE_SPAWN_3_PLATFORMS 0x22
#define RISING_CHOZO_PILLAR_POSE_SPAWN_2_PLATFORMS 0x23
#define RISING_CHOZO_PILLAR_POSE_SPAWN_1_PLATFORMS 0x24
#define RISING_CHOZO_PILLAR_POSE_EXTENDED 0x25
#define RISING_CHOZO_PILLAR_POSE_KILL 0x26

#define RISING_CHOZO_PILLAR_PLATFORM_POSE_SPAWNING 0x8
#define RISING_CHOZO_PILLAR_PLATFORM_POSE_IDLE 0x9

enum ChozoPillarPlatformPart {
    CHOZO_PILLAR_PLATFORM_NO_SHADOW,
    CHOZO_PILLAR_PLATFORM_SHADOW
};

/**
 * 4854c | a8 | Spawns random sprite debris depending on the parameters
 * 
 * @param yPosition Y Position
 * @param xPosition X Position 
 * @param rng Set of debris to use
 */
static void RisingChozoPillarRandomSpriteDebris(u16 yPosition, u16 xPosition, u8 rng)
{
    switch (rng)
    {
        case 1:
            SpriteDebrisInit(0, 0x11, yPosition - (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE), xPosition);
            SpriteDebrisInit(0, 0x12, yPosition - QUARTER_BLOCK_SIZE, xPosition + (BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2));
            break;

        case 3:
            SpriteDebrisInit(0, 0x13, yPosition - (QUARTER_BLOCK_SIZE + PIXEL_SIZE),
                xPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE - PIXEL_SIZE));
            SpriteDebrisInit(0, 4, yPosition - (EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2), xPosition + (HALF_BLOCK_SIZE - PIXEL_SIZE / 2));
            break;

        case 7:
            SpriteDebrisInit(0, 0x11, yPosition - EIGHTH_BLOCK_SIZE, xPosition - (THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE / 2));
            SpriteDebrisInit(0, 0x12, yPosition - (THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE),
                xPosition + (BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE));
            break;

        case 12:
            SpriteDebrisInit(0, 0x13, yPosition - HALF_BLOCK_SIZE, xPosition + (HALF_BLOCK_SIZE - PIXEL_SIZE / 2));
            SpriteDebrisInit(0, 4, yPosition - PIXEL_SIZE, xPosition - (BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE - PIXEL_SIZE / 2));
    }
}

/**
 * 485f4 | ac | Spawns random particles depending on the parameters
 * 
 * @param yPosition Y Position
 * @param xPosition X Position 
 * @param rng Set of particles to use
 */
static void RisingChozoPillarRandomParticles(u16 yPosition, u16 xPosition, u8 rng)
{
    switch (rng)
    {
        case 1:
            ParticleSet(yPosition, xPosition - (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE), PE_TWO_MEDIUM_DUST);
            break;

        case 16:
            ParticleSet(yPosition, xPosition + (BLOCK_SIZE - PIXEL_SIZE), PE_SECOND_MEDIUM_DUST);
            break;

        case 33:
            ParticleSet(yPosition, xPosition - (BLOCK_SIZE - PIXEL_SIZE), PE_SECOND_MEDIUM_DUST);
            break;

        case 50:
            ParticleSet(yPosition, xPosition + (QUARTER_BLOCK_SIZE + PIXEL_SIZE), PE_MEDIUM_DUST);
            break;

        case 66:
            ParticleSet(yPosition, xPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE), PE_TWO_MEDIUM_DUST);
            break;

        case 84:
            ParticleSet(yPosition, xPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE), PE_SECOND_MEDIUM_DUST);
            ParticleSet(yPosition, xPosition, PE_SECOND_TWO_MEDIUM_DUST);
            break;

        case 100:
            ParticleSet(yPosition, xPosition - (QUARTER_BLOCK_SIZE + PIXEL_SIZE), PE_SECOND_TWO_MEDIUM_DUST);
            break;

        case 110:
            ParticleSet(yPosition, xPosition + (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE), PE_MEDIUM_DUST);
    }
}

/**
 * @brief 486a0 | e4 | Spawns three platforms and sets the collision for them
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param caa Clipdata affecting action
 */
static void RisingChozoPillarSpawnThreePlatforms(u16 yPosition, u16 xPosition, u8 caa)
{
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 3, xPosition + BLOCK_SIZE * 3);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 3, xPosition + BLOCK_SIZE * 4);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 11, xPosition + BLOCK_SIZE * 3);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 11, xPosition + BLOCK_SIZE * 4);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 19, xPosition + BLOCK_SIZE * 3);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 19, xPosition + BLOCK_SIZE * 4);

    // Spawn platforms
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, CHOZO_PILLAR_PLATFORM_SHADOW, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, yPosition - (BLOCK_SIZE * 3),  xPosition + (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), 0);

    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, CHOZO_PILLAR_PLATFORM_SHADOW, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, yPosition - (BLOCK_SIZE * 11),  xPosition + (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), 0);

    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, CHOZO_PILLAR_PLATFORM_SHADOW, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, yPosition - (BLOCK_SIZE * 19), xPosition + (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), 0);
}

/**
 * 48784 | b8 | Spawns two platforms and sets the collision for them
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param caa Clipdata affecting action
 */
static void RisingChozoPillarSpawnTwoPlatforms(u16 yPosition, u16 xPosition, u8 caa)
{
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 7, xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 7, xPosition + BLOCK_SIZE);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 24, xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 24, xPosition + BLOCK_SIZE);

    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, CHOZO_PILLAR_PLATFORM_NO_SHADOW, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, yPosition - BLOCK_SIZE * 7, xPosition + HALF_BLOCK_SIZE, 0);

    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, CHOZO_PILLAR_PLATFORM_NO_SHADOW, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, yPosition - BLOCK_SIZE * 24, xPosition + HALF_BLOCK_SIZE, 0);
}

/**
 * 4883c | 68 | 
 * Spawns one platform and sets the collision for it
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param caa Clipdata affecting action
 */
static void RisingChozoPillarSpawnOnePlatform(u16 yPosition, u16 xPosition, u8 caa)
{
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 15, xPosition + BLOCK_SIZE * 6);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 15, xPosition + BLOCK_SIZE * 7);

    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, CHOZO_PILLAR_PLATFORM_NO_SHADOW, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, yPosition - BLOCK_SIZE * 15, xPosition + BLOCK_SIZE * 6 + HALF_BLOCK_SIZE, 0);
}

/**
 * 488a4 | 248 | Rising Chozo Pillar AI
 * 
 */
void RisingChozoPillar(void)
{
    u8 caa;
    u16 yPosition;
    u16 xPosition;
    u16 debrisY;
    u16 debrisX;

    caa = CAA_MAKE_SOLID_GRIPPABLE;
    yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPosition;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED))
            {
                // Already extended, spawn all platforms
                RisingChozoPillarSpawnThreePlatforms(yPosition, xPosition, caa);
                RisingChozoPillarSpawnTwoPlatforms(yPosition, xPosition, caa);
                RisingChozoPillarSpawnOnePlatform(yPosition, xPosition, caa);
                gCurrentSprite.status = 0;
                break;
            }

            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.pOam = sEnemyDropOam_LargeEnergy;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.pose = RISING_CHOZO_PILLAR_POSE_WAIT_FOR_POWER_GRIP;
            break;

        case RISING_CHOZO_PILLAR_POSE_WAIT_FOR_POWER_GRIP:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_POWER_GRIP_OBTAINED))
            {
                gCurrentSprite.pose = RISING_CHOZO_PILLAR_POSE_EXTENDING;
                gCurrentSprite.scaling = 704;
                SoundPlay(SOUND_RISING_CHOZO_PILLAR_RISING);
            }
            break;

        case RISING_CHOZO_PILLAR_POSE_EXTENDING:
            if (MOD_AND(gCurrentSprite.scaling, 32) == 0)
                ScreenShakeStartVertical(CONVERT_SECONDS(.5f), 0x80 | 1);

            APPLY_DELTA_TIME_DEC(gCurrentSprite.scaling);
            if (gCurrentSprite.scaling != 0)
            {
                gBg2Movement.yOffset += PIXEL_SIZE / 2;
            }
            else
            {
                gCurrentSprite.pose = RISING_CHOZO_PILLAR_POSE_SPAWN_3_PLATFORMS;
                SoundFade(SOUND_RISING_CHOZO_PILLAR_RISING, CONVERT_SECONDS(1.f / 6));
            }

            debrisY = yPosition + HALF_BLOCK_SIZE;
            debrisX = xPosition + BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            RisingChozoPillarRandomSpriteDebris(debrisY, debrisX, MOD_AND(gCurrentSprite.scaling, 16));
            RisingChozoPillarRandomParticles(debrisY, debrisX, MOD_AND(gCurrentSprite.scaling, 128));
            break;

        case RISING_CHOZO_PILLAR_POSE_SPAWN_3_PLATFORMS:
            gCurrentSprite.pose = RISING_CHOZO_PILLAR_POSE_SPAWN_2_PLATFORMS;
            RisingChozoPillarSpawnThreePlatforms(yPosition, xPosition, caa);
            break;

        case RISING_CHOZO_PILLAR_POSE_SPAWN_2_PLATFORMS:
            gCurrentSprite.pose = RISING_CHOZO_PILLAR_POSE_SPAWN_1_PLATFORMS;
            RisingChozoPillarSpawnTwoPlatforms(yPosition, xPosition, caa);
            break;

        case RISING_CHOZO_PILLAR_POSE_SPAWN_1_PLATFORMS:
            gCurrentSprite.pose = RISING_CHOZO_PILLAR_POSE_EXTENDED;
            RisingChozoPillarSpawnOnePlatform(yPosition, xPosition, caa);
            break;

        case RISING_CHOZO_PILLAR_POSE_EXTENDED:
            gCurrentSprite.pose = RISING_CHOZO_PILLAR_POSE_KILL;
            break;

        case RISING_CHOZO_PILLAR_POSE_KILL:
            EventFunction(EVENT_ACTION_SETTING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED);
            gCurrentSprite.status = 0;
    }
}

/**
 * 48aec | 124 | Chozo Pillar Platform AI 
 * 
 */
void ChozoPillarPlatform(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.yPosition += PIXEL_SIZE;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED))
            {
                gCurrentSprite.pose = RISING_CHOZO_PILLAR_PLATFORM_POSE_IDLE;
                if (gCurrentSprite.roomSlot != CHOZO_PILLAR_PLATFORM_NO_SHADOW)
                {
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOam_ShadowSpawned;
                    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM_SHADOW, 0, gCurrentSprite.spritesetGfxSlot,
                        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
                }
                else
                {
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOam_NoShadowSpawned;
                }
            }
            else
            {
                gCurrentSprite.pose = RISING_CHOZO_PILLAR_PLATFORM_POSE_SPAWNING;
                if (gCurrentSprite.roomSlot != CHOZO_PILLAR_PLATFORM_NO_SHADOW)
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOam_ShadowSpawning;
                else
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOam_NoShadowSpawning;

                SoundPlay(SOUND_RISING_CHOZO_PILLAR_PLATFORM_SPAWNING);
            }
            break;

        case RISING_CHOZO_PILLAR_PLATFORM_POSE_SPAWNING:
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.pose = RISING_CHOZO_PILLAR_PLATFORM_POSE_IDLE;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                if (gCurrentSprite.roomSlot != CHOZO_PILLAR_PLATFORM_NO_SHADOW)
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOam_ShadowSpawned;
                else
                    gCurrentSprite.pOam = sRisingChozoPillarPlatformOam_NoShadowSpawned;
            }
            else
            {
                if (gCurrentSprite.roomSlot != CHOZO_PILLAR_PLATFORM_NO_SHADOW &&
                    gCurrentSprite.currentAnimationFrame == 21 &&
                    gCurrentSprite.animationDurationCounter == DELTA_TIME)
                {
                    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM_SHADOW, 0, gCurrentSprite.spritesetGfxSlot,
                        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
                }
            }
    }
}

/**
 * 48c10 | 6c | Chozo Pillar Platform Shadow AI
 * 
 */
void ChozoPillarPlatformShadow(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_NONE;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(0);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

        gCurrentSprite.hitboxTop = 0;
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = 0;
        gCurrentSprite.hitboxRight = 0;

        gCurrentSprite.pose = 8;

        gCurrentSprite.pOam = sRisingChozoPillarPlatformShadowOam;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.drawOrder = 12;
    }
}
