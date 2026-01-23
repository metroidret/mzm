#include "sprites_ai/kraid.h"
#include "gba.h"
#include "macros.h"

#include "data/sprites/kraid.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/color_fading.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/particle.h"
#include "constants/projectile.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/bg_clip.h"
#include "structs/connection.h"
#include "structs/clipdata.h"
#include "structs/game_state.h"
#include "structs/in_game_timer.h"
#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/scroll.h"
#include "structs/projectile.h"

#define KRAID_POSE_GO_UP 0x1
#define KRAID_POSE_CHECK_FULLY_UP 0x2
#define KRAID_POSE_FIRST_STEP_INIT 0x8
#define KRAID_POSE_FIRST_STEP 0x9
#define KRAID_POSE_STANDING_INIT 0xE
#define KRAID_POSE_STANDING 0xF
#define KRAID_POSE_STANDING_BETWEEN_STEPS_INIT 0x10
#define KRAID_POSE_STANDING_BETWEEN_STEPS 0x11
#define KRAID_POSE_SECOND_STEP_INIT 0x22
#define KRAID_POSE_SECOND_STEP 0x23
#define KRAID_POSE_DYING_INIT 0x62
#define KRAID_POSE_DYING 0x67
#define KRAID_POSE_DEAD_STATIONARY 0x68

// Kraid part

#define KRAID_PART_POSE_IDLE 0xE
#define KRAID_PART_POSE_CHECK_ATTACK 0x12
#define KRAID_PART_POSE_CHECK_THROW_NAILS 0x10
#define KRAID_PART_POSE_CHECK_SPAWN_SPIKES 0x42
#define KRAID_PART_POSE_SPAWN_SPIKES 0x43
#define KRAID_PART_POSE_CHECK_PROJECTILES 0x44
#define KRAID_PART_POSE_DYING_INIT 0x62
#define KRAID_PART_POSE_ARM_DYING 0x67
#define KRAID_PART_POSE_DYING_STATIONNARY 0x68

// Kraid spike

#define KRAID_SPIKE_POSE_DELAY_BEFORE_MOVING 0x9
#define KRAID_SPIKE_POSE_MOVING 0x23
#define KRAID_SPIKE_POSE_IN_WALL 0x25

#define DESTROYED_BLOCK_STATUS_TOP (1 << 0)
#define DESTROYED_BLOCK_STATUS_MIDDLE (1 << 1)
#define DESTROYED_BLOCK_STATUS_BOTTOM (1 << 2)

// Kraid nail

enum KraidNailType {
    KRAID_NAIL_TYPE_SLOW_ROTATION,
    KRAID_NAIL_TYPE_FAST_ROTATION
};

#define KRAID_NAIL_POSE_MOVING 0x9

static const struct FrameData* sKraidFrameDataPointers[KRAID_OAM_END] = {
    [KRAID_OAM_MOUTH_CLOSED] = sKraidOam_MouthClosed,
    [KRAID_OAM_MOUTH_CLOSED_BLINK] = sKraidOam_MouthClosedBlink,
    [KRAID_OAM_OPENING_MOUTH] = sKraidOam_OpeningMouth,
    [KRAID_OAM_MOUTH_OPENED] = sKraidOam_MouthOpened,
    [KRAID_OAM_RISING] = sKraidOam_Rising,
    [KRAID_OAM_CLOSING_MOUTH] = sKraidOam_ClosingMouth,
    [KRAID_OAM_2cac5c] = sKraidPartOam_2cac5c,
    [KRAID_OAM_LEFT_ARM_IDLE] = sKraidPartOam_LeftArmIdle,
    [KRAID_OAM_LEFT_ARM_DYING] = sKraidPartOam_LeftArmDying,
    [KRAID_OAM_LEFT_ARM_THROWING_NAILS] = sKraidPartOam_LeftArmThrowingNails,
    [KRAID_OAM_2cadc4] = sKraidPartOam_2cadc4,
    [KRAID_OAM_RIGHT_ARM_IDLE] = sKraidPartOam_RightArmIdle,
    [KRAID_OAM_RIGHT_ARM_Attacking] = sKraidPartOam_RightArmAttacking,
    [KRAID_OAM_RIGHT_ARM_DYING] = sKraidPartOam_RightArmDying,
    [KRAID_OAM_LEFT_FEET_RISING] = sKraidPartOam_LeftFeetRising,
    [KRAID_OAM_LEFT_FEET_IDLE_1] = sKraidPartOam_LeftFeetIdle1,
    [KRAID_OAM_LEFT_FEET_MOVING_RIGHT] = sKraidPartOam_LeftFeetMovingRight,
    [KRAID_OAM_LEFT_FEET_IDLE_2] = sKraidPartOam_LeftFeetIdle2,
    [KRAID_OAM_LEFT_FEET_MOVED_RIGHT] = sKraidPartOam_LeftFeetMovedRight,
    [KRAID_OAM_LEFT_FEET_MOVING_LEFT] = sKraidPartOam_LeftFeetMovingLeft,
    [KRAID_OAM_LEFT_FEET_MOVED_LEFT] = sKraidPartOam_LeftFeetMovedLeft,
    [KRAID_OAM_RIGHT_FEET_RISING] = sKraidPartOam_RightFeetRising,
    [KRAID_OAM_RIGHT_FEET_IDLE_1] = sKraidPartOam_RightFeetIdle1,
    [KRAID_OAM_RIGHT_FEET_MOVED_RIGHT] = sKraidPartOam_RightFeetMovedRight,
    [KRAID_OAM_RIGHT_FEET_IDLE_2] = sKraidPartOam_RightFeetIdle2,
    [KRAID_OAM_RIGHT_FEET_MOVING_RIGHT] = sKraidPartOam_RightFeetMovingRight,
    [KRAID_OAM_RIGHT_FEET_MOVED_LEFT] = sKraidPartOam_RightFeetMovedLeft,
    [KRAID_OAM_RIGHT_FEET_MOVING_LEFT] = sKraidPartOam_RightFeetMovingLeft,
    [KRAID_OAM_TOP_HOLE_LEFT] = sKraidPartOam_TopHoleLeft,
    [KRAID_OAM_TOP_HOLE_RIGHT] = sKraidPartOam_TopHoleRight,
    [KRAID_OAM_MIDDLE_HOLE_LEFT] = sKraidPartOam_MiddleHoleLeft,
    [KRAID_OAM_MIDDLE_HOLE_RIGHT] = sKraidPartOam_MiddleHoleRight,
    [KRAID_OAM_BOTTOM_HOLE_LEFT] = sKraidPartOam_BottomHoleLeft,
    [KRAID_OAM_BOTTOM_HOLE_RIGHT] = sKraidPartOam_BottomHoleRight,
    [KRAID_OAM_NAIL] = sKraidNailOam,
    [KRAID_OAM_2cb29c] = sKraidOam_2cb29c,
    [KRAID_OAM_2cb2ac] = sKraidOam_2cb2ac,
    [KRAID_OAM_SPIKE] = sKraidSpikeOam
};

/**
 * @brief 183d8 | 68 | Synchronize the sub sprites of Kraid
 * 
 */
static void KraidSyncSubSprites(void)
{
    MultiSpriteDataInfo_T pData;
    u16 oamIdx;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];
    
    if (gCurrentSprite.pOam != sKraidFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sKraidFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

/**
 * @brief 18440 | 1ac | Checks if a projectile is colliding with Kraid's belly
 * 
 */
static void KraidCheckProjectilesCollidingWithBelly(void)
{
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u16 projY;
    u16 projX;
    struct ProjectileData* pProj;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    spriteTop = spriteY + gCurrentSprite.hitboxTop;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottom;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeft;
    spriteRight = spriteX + gCurrentSprite.hitboxRight;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if (!(pProj->status & PROJ_STATUS_EXISTS))
            continue;

        if (!(pProj->status & PROJ_STATUS_CAN_AFFECT_ENVIRONMENT))
            continue;

        if (pProj->movementStage <= PROJECTILE_STAGE_SPAWNING)
            continue;

        // Ignore all non beam and non missile projectiles
        if (pProj->type >= PROJ_TYPE_BOMB)
            continue;

        // Check colliding
        if (pProj->xPosition > spriteLeft && pProj->xPosition < spriteRight &&
            pProj->yPosition > spriteTop && pProj->yPosition < spriteBottom)
        {
            // Kill projectile
            pProj->status = 0;
            projY = pProj->yPosition;
            projX = pProj->xPosition;

            // Set effects
            if (MOD_AND(gSpriteRng, 2))
            {
                SpriteDebrisInit(0, 0x12, projY + QUARTER_BLOCK_SIZE, projX - EIGHTH_BLOCK_SIZE);
                SpriteDebrisInit(0, 0x13, projY - (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2),
                    projX + QUARTER_BLOCK_SIZE + PIXEL_SIZE);
            }
            else
            {
                SpriteDebrisInit(0, 0x12, projY, projX + QUARTER_BLOCK_SIZE - PIXEL_SIZE);
                SpriteDebrisInit(0, 0x13, projY - (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE),
                    projX - (HALF_BLOCK_SIZE - PIXEL_SIZE / 2));
            }

            ScreenShakeStartHorizontal(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
            ParticleSet(projY, projX, PE_SPRITE_EXPLOSION_SMALL);

            // Set particle
            switch (pProj->type)
            {
                case PROJ_TYPE_BEAM:
                case PROJ_TYPE_CHARGED_BEAM:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
                    break;
                    
                case PROJ_TYPE_LONG_BEAM:
                case PROJ_TYPE_CHARGED_LONG_BEAM:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                    break;
                    
                case PROJ_TYPE_ICE_BEAM:
                case PROJ_TYPE_CHARGED_ICE_BEAM:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                    break;
                    
                case PROJ_TYPE_WAVE_BEAM:
                case PROJ_TYPE_CHARGED_WAVE_BEAM:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                    break;

                case PROJ_TYPE_MISSILE:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_MISSILE);
                    break;

                case PROJ_TYPE_SUPER_MISSILE:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
            }
        }
    }
}

static void KraidOpenCloseRoutineAndProjectileCollision(void)
{
    struct SpriteData* pSprite;
    struct ProjectileData* pProj;
    const struct FrameData* pOam;
    u8 closed;
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u16 projY;
    u16 projX;
    u16 yTopOffset;
    u16 yBottomOffset;
    u16 damage;
    u8 effect;
    u8 damaged;

    pSprite = &gCurrentSprite;

    // Update opening mouth timer
    if (gSubSpriteData1.work2 != 0)
        gSubSpriteData1.work2--;

    // Update animations and check whether or not the mouth is open

    if (pSprite->pOam == sKraidOam_MouthClosed)
    {
        // Closed
        closed = TRUE;
        if (gSubSpriteData1.work2 != 0)
        {
            // Opening mouth timer active, set opening
            pSprite->pOam = sKraidOam_OpeningMouth;
            pSprite->animationDurationCounter = 0;
            pSprite->currentAnimationFrame = 0;

            SoundPlay(SOUND_KRAID_OPENING_MOUTH);
        }
        else if (SpriteUtilHasCurrentAnimationEnded() && gSpriteRng < SPRITE_RNG_PROB(5.f / 16))
        {
            // Random blinking animation
            pSprite->pOam = sKraidOam_MouthClosedBlink;
            pSprite->animationDurationCounter = 0;
            pSprite->currentAnimationFrame = 0;
        }
    }
    else if (pSprite->pOam == sKraidOam_MouthClosedBlink)
    {
        closed = TRUE;
        if (gSubSpriteData1.work2 != 0)
        {
            // Opening mouth timer active, set opening
            pSprite->pOam = sKraidOam_OpeningMouth;
            pSprite->animationDurationCounter = 0;
            pSprite->currentAnimationFrame = 0;

            SoundPlay(SOUND_KRAID_OPENING_MOUTH);
        }
        else if (SpriteUtilHasCurrentAnimationEnded())
        {
            // Back to normal animation
            pSprite->pOam = sKraidOam_MouthClosed;
            pSprite->animationDurationCounter = 0;
            pSprite->currentAnimationFrame = 0;
        }
    }
    else if (pSprite->pOam == sKraidOam_OpeningMouth)
    {
        if (pSprite->currentAnimationFrame >= (s32)(FRAME_DATA_NBR_OF_FRAMES(sKraidOam_OpeningMouth) * .75f))
        {
            // Enable projectile collision
            closed = FALSE;
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                // Set opened
                pSprite->pOam = sKraidOam_MouthOpened;
                pSprite->animationDurationCounter = 0;
                pSprite->currentAnimationFrame = 0;
            }
        }
        else
        {
            // Not yet opened
            closed = TRUE;
        }
    }
    else if (pSprite->pOam == sKraidOam_ClosingMouth)
    {
        if (pSprite->currentAnimationFrame <= 1)
        {
            // Not yet closed
            closed = FALSE;
        }
        else
        {
            // Closed
            closed = TRUE;
            if (gSubSpriteData1.work2 != 0)
            {
                // Opening mouth timer active, set opening
                pSprite->pOam = sKraidOam_OpeningMouth;
                pSprite->animationDurationCounter = 0;
                pSprite->currentAnimationFrame = 0;

                SoundPlay(SOUND_KRAID_OPENING_MOUTH);
            }
            else if (SpriteUtilHasCurrentAnimationEnded())
            {
                // Random animation
                if (MOD_AND(gSpriteRng, 2))
                    pSprite->pOam = sKraidOam_MouthClosed;
                else
                    pSprite->pOam = sKraidOam_MouthClosedBlink;

                pSprite->animationDurationCounter = 0;
                pSprite->currentAnimationFrame = 0;
            }
        }
    }
    else
    {
        pOam = sKraidOam_Rising;
        closed = FALSE;
        if (pSprite->pOam != pOam && gSubSpriteData1.work2 == 0)
        {
            pSprite->pOam = sKraidOam_ClosingMouth;
            pSprite->animationDurationCounter = 0;
            pSprite->currentAnimationFrame = 0;
        }
    }

    // Get Y size of mouth
    if (!closed)
    {
        yTopOffset = BLOCK_SIZE + QUARTER_BLOCK_SIZE - PIXEL_SIZE;
        yBottomOffset = QUARTER_BLOCK_SIZE;
    }
    else
    {
        yTopOffset = BLOCK_SIZE + PIXEL_SIZE;
        yBottomOffset = QUARTER_BLOCK_SIZE + PIXEL_SIZE;
    }

    spriteY = pSprite->yPosition;
    spriteX = pSprite->xPosition;
    spriteTop = spriteY + pSprite->hitboxTop;
    spriteBottom = spriteY + pSprite->hitboxBottom;
    spriteLeft = spriteX + pSprite->hitboxLeft;
    spriteRight = spriteX + pSprite->hitboxRight;

    // Loop through every projectile for custom collision
    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if (!(pProj->status & PROJ_STATUS_EXISTS))
            continue;

        if (!(pProj->status & PROJ_STATUS_CAN_AFFECT_ENVIRONMENT))
            continue;

        if (pProj->movementStage <= PROJECTILE_STAGE_SPAWNING)
            continue;

        if (pProj->xPosition > spriteLeft && pProj->xPosition < spriteRight &&
            pProj->yPosition > spriteTop && pProj->yPosition < spriteBottom)
        {
            projY = pProj->yPosition;
            projX = pProj->xPosition;
            damaged = FALSE;

            // Check collide with mouth interior
            if (projY > spriteY - yTopOffset && projY < spriteY + yBottomOffset &&
                pProj->direction == ACD_FORWARD && !(pProj->status & PROJ_STATUS_X_FLIP))
            {
                // Get damage and particle effect
                // Plasma beam isn't taken into account and is treated the same as doing nothing
                if (pProj->type == PROJ_TYPE_MISSILE)
                {
                    damaged = TRUE;
                    damage = MISSILE_DAMAGE;
                    effect = PE_HITTING_SOMETHING_WITH_MISSILE;
                }
                else if (pProj->type == PROJ_TYPE_SUPER_MISSILE)
                {
                    damaged = TRUE;
                    damage = SUPER_MISSILE_DAMAGE;
                    effect = PE_HITTING_SOMETHING_WITH_SUPER_MISSILE;
                }
                else if (pProj->type == PROJ_TYPE_CHARGED_BEAM)
                {
                    damaged = TRUE;
                    damage = CHARGED_NORMAL_BEAM_DAMAGE;
                    effect = PE_HITTING_SOMETHING_WITH_NORMAL_BEAM;
                }
                else if (pProj->type == PROJ_TYPE_CHARGED_LONG_BEAM)
                {
                    damaged = TRUE;
                    damage = CHARGED_LONG_BEAM_DAMAGE;
                    effect = PE_HITTING_SOMETHING_WITH_LONG_BEAM;
                }
                else if (pProj->type == PROJ_TYPE_CHARGED_ICE_BEAM)
                {
                    damaged = TRUE;
                    if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
                        damage = CHARGED_ICE_LONG_BEAM_DAMAGE;
                    else
                        damage = CHARGED_ICE_BEAM_DAMAGE;

                    effect = PE_HITTING_SOMETHING_WITH_ICE_BEAM;
                }
                else if (pProj->type == PROJ_TYPE_CHARGED_WAVE_BEAM)
                {
                    damaged = TRUE;
                    if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
                    {
                        if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
                        {
                            damage = CHARGED_WAVE_ICE_LONG_BEAM_DAMAGE;
                            effect = PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA;
                        }
                        else
                        {
                            damage = CHARGED_WAVE_LONG_BEAM_DAMAGE;
                            effect = PE_HITTING_SOMETHING_WITH_WAVE_BEAM;
                        }
                    }
                    else
                    {
                        if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
                        {
                            damage = CHARGED_WAVE_ICE_BEAM_DAMAGE;
                            effect = PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA;
                        }
                        else
                        {
                            damage = CHARGED_WAVE_BEAM_DAMAGE;
                            effect = PE_HITTING_SOMETHING_WITH_WAVE_BEAM;
                        }
                    }
                }
                else
                {
                    pProj->status = 0;
                    if (SPRITE_GET_ISFT(*pSprite) < CONVERT_SECONDS(.05f))
                    {
                        SPRITE_CLEAR_AND_SET_ISFT(*pSprite, CONVERT_SECONDS(.05f));
                    }

                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_INVINCIBLE);
                    break;
                }

                if (!damaged)
                    break;
                
                if (!closed)
                {
                    SPRITE_CLEAR_AND_SET_ISFT(*pSprite, CONVERT_SECONDS(.25f + 1.f / 30));
                    SoundPlay(SOUND_KRAID_DAMAGED);
                }
                else
                {
                    SPRITE_CLEAR_AND_SET_ISFT(*pSprite, CONVERT_SECONDS(1.f / 30));

                    // Set opening mouth timer to 3 seconds
                    gSubSpriteData1.work2 = CONVERT_SECONDS(3.f);
                    damage = 0;
                }

                if (pSprite->health > damage)
                {
                    // Damage kraid
                    pSprite->health -= damage;

                    // Check update palette (both sprite and BG2)
                    if (pSprite->health < DIV_SHIFT(GET_PSPRITE_HEALTH(PSPRITE_KRAID), 4))
                    {
                        pSprite->absolutePaletteRow = 3;

                        DMA_SET(3, &sKraidPal[PAL_ROW * 4 + PAL_ROW * 3], PALRAM_BASE + PAL_ROW_SIZE * 10, C_32_2_16(DMA_ENABLE, PAL_ROW));
                    }
                    else if (pSprite->health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 3)
                    {
                        pSprite->absolutePaletteRow = 2;

                        DMA_SET(3, &sKraidPal[PAL_ROW * 4 + PAL_ROW * 2], PALRAM_BASE + PAL_ROW_SIZE * 10, C_32_2_16(DMA_ENABLE, PAL_ROW));
                    }
                    else if (pSprite->health < DIV_SHIFT(GET_PSPRITE_HEALTH(PSPRITE_KRAID), 4) * 3)
                    {
                        pSprite->absolutePaletteRow = 1;

                        DMA_SET(3, &sKraidPal[PAL_ROW * 4 + PAL_ROW * 1], PALRAM_BASE + PAL_ROW_SIZE * 10, C_32_2_16(DMA_ENABLE, PAL_ROW));
                    }
                }
                else
                {
                    // Kill kraid
                    pSprite->health = 0;
                    pSprite->properties |= SP_DESTROYED;
                    pSprite->freezeTimer = 0;
                    pSprite->pose = KRAID_POSE_DYING_INIT;
                    pSprite->ignoreSamusCollisionTimer = DELTA_TIME;
                }

                pSprite->properties |= SP_DAMAGED;
                gSubSpriteData1.health = pSprite->health;
                pProj->status = 0;
                ParticleSet(projY, projX, effect);
                break;
            }

            // Projectile didn't collide directly with head, make missiles tumble otherwise destroy
            if (pProj->type == PROJ_TYPE_MISSILE)
                ProjectileStartTumblingMissileCurrentSprite(pProj, PROJ_TYPE_MISSILE);
            else if (pProj->type == PROJ_TYPE_SUPER_MISSILE)
                ProjectileStartTumblingMissileCurrentSprite(pProj, PROJ_TYPE_SUPER_MISSILE);
            else
                pProj->status = 0;

            if (SPRITE_GET_ISFT(*pSprite) < CONVERT_SECONDS(.05f))
            {
                SPRITE_CLEAR_AND_SET_ISFT(*pSprite, CONVERT_SECONDS(.05f));
            }

            ParticleSet(projY, projX, PE_HITTING_SOMETHING_INVINCIBLE);
            break;
        }
    }
}

/**
 * @brief 18a5c | 1a0 | Spawns random sprite debris on the ceiling
 * 
 * @param timer Timer
 */
static void KraidRandomSpriteDebrisOnCeiling(u8 timer)
{
    u16 yPosition;
    u16 xPosition;
    u8 rng;
    u8 rng2;

    if (gSubSpriteData1.health != 0)
    {
        yPosition = gSamusData.yPosition - BLOCK_SIZE * 7;
        xPosition = gSamusData.xPosition;
    }
    else
    {
        yPosition = gBg1YPosition - (BLOCK_SIZE - PIXEL_SIZE);
        xPosition = gSubSpriteData1.xPosition + BLOCK_SIZE * 3;
    }

    rng = gSpriteRng;
    rng2 = MOD_AND(gFrameCounter8Bit, 8);

    if (MOD_AND(gFrameCounter8Bit, 2))
    {
        SpriteDebrisInit(0, 0x5, yPosition + rng,
            xPosition - (BLOCK_SIZE * 4 + THREE_QUARTER_BLOCK_SIZE - PIXEL_SIZE) + rng * QUARTER_BLOCK_SIZE);
        SpriteDebrisInit(0, 0x5, yPosition, xPosition - (BLOCK_SIZE * 11 - PIXEL_SIZE) + rng2 * PIXEL_SIZE);
    }
    else
    {
        SpriteDebrisInit(0, 0x7, yPosition - rng, xPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE) - rng * HALF_BLOCK_SIZE);
        SpriteDebrisInit(0, 0x7, yPosition, xPosition - (BLOCK_SIZE * 6 + QUARTER_BLOCK_SIZE) - rng2 * QUARTER_BLOCK_SIZE);
    }

    if (rng >= SPRITE_RNG_PROB(.5f))
    {
        SpriteDebrisInit(0, 0x8, yPosition,
            xPosition - (BLOCK_SIZE * 3 + THREE_QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2) + rng2 * QUARTER_BLOCK_SIZE);
        SpriteDebrisInit(0, 0x6, yPosition,
            xPosition + (BLOCK_SIZE * 4 + THREE_QUARTER_BLOCK_SIZE - PIXEL_SIZE) - rng2 * QUARTER_BLOCK_SIZE);
    }
    else
    {
        SpriteDebrisInit(0, 0x5, yPosition, xPosition + BLOCK_SIZE * 3 + EIGHTH_BLOCK_SIZE - rng2 * QUARTER_BLOCK_SIZE);
        SpriteDebrisInit(0, 0x5, yPosition,
            xPosition - (BLOCK_SIZE * 5 + HALF_BLOCK_SIZE - PIXEL_SIZE / 2) + rng2 * QUARTER_BLOCK_SIZE);
    }

    if (MOD_AND(timer, 4) == 0)
    {
        if (MOD_AND(rng, 2))
            SpriteDebrisInit(0, 0x6, yPosition, xPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE) + rng2 * QUARTER_BLOCK_SIZE);
        else
            SpriteDebrisInit(0, 0x8, yPosition, xPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE) - rng2 * QUARTER_BLOCK_SIZE);

        if (rng >= SPRITE_RNG_PROB(.5f))
        {
            SpriteDebrisInit(0, 0x7, yPosition, xPosition - rng2 * HALF_BLOCK_SIZE);
            SpriteDebrisInit(0, 0x8, yPosition, xPosition + BLOCK_SIZE - rng2 * QUARTER_BLOCK_SIZE);
        }
        else
        {
            SpriteDebrisInit(0, 0x5, yPosition,
                xPosition - (BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE - PIXEL_SIZE / 2) + rng2 * QUARTER_BLOCK_SIZE);
            SpriteDebrisInit(0, 0x6, yPosition, xPosition + rng2 * PIXEL_SIZE);
        }
    }
}

/**
 * @brief 18bfc | 1c | Changes the hitbox of something
 * 
 */
static void KraidPartHitboxChange_1Unused(void)
{
    gCurrentSprite.hitboxTop = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxRight = BLOCK_SIZE * 4 + EIGHTH_BLOCK_SIZE;
}

/**
 * @brief 18c18 | 11c | Updates the arm (idling) hitbox
 * 
 */
static void KraidPartUpdateRightArmIdlingHitbox(void)
{
    if (gCurrentSprite.animationDurationCounter != DELTA_TIME)
        return;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 4 + EIGHTH_BLOCK_SIZE;
            break;

        case 1:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 5 + HALF_BLOCK_SIZE - PIXEL_SIZE;
            break;

        case 2:
            gCurrentSprite.hitboxTop = -THREE_QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 5 + HALF_BLOCK_SIZE - PIXEL_SIZE;
            break;

        case 3:
            gCurrentSprite.hitboxTop = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 5 + HALF_BLOCK_SIZE - PIXEL_SIZE;
            break;

        case 4:
            gCurrentSprite.hitboxTop = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 5 + HALF_BLOCK_SIZE - PIXEL_SIZE;
            break;

        case 5:
            gCurrentSprite.hitboxTop = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 4;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 5 + HALF_BLOCK_SIZE - PIXEL_SIZE;
            break;

        case 6:
            gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 5 + HALF_BLOCK_SIZE - PIXEL_SIZE;
            break;

        case 7:
            gCurrentSprite.hitboxTop = -BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 5 + HALF_BLOCK_SIZE - PIXEL_SIZE;
            break;

        case 8:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE;
            break;

        case 9:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 4 + HALF_BLOCK_SIZE;
            break;
    }
}

/**
 * @brief 18d34 | 154 | Updates the arm (attacking) hitbox
 * 
 */
static void KraidPartUpdateRightArmAttackingHitbox(void)
{
    if (gCurrentSprite.animationDurationCounter != DELTA_TIME)
        return;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 4 + HALF_BLOCK_SIZE;
            SoundPlay(SOUND_KRAID_RIGHT_ARM_DYING_1);
            break;

        case 1:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2);
            gCurrentSprite.hitboxBottom = -BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 4 + HALF_BLOCK_SIZE;
            break;

        case 2:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 3);
            gCurrentSprite.hitboxBottom = -BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 3 + EIGHTH_BLOCK_SIZE;
            break;

        case 3:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 4);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 2;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 3 - EIGHTH_BLOCK_SIZE;
            break;

        case 4:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 5);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxLeft = BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            SoundPlay(SOUND_KRAID_RIGHT_ARM_DYING_2);
            break;

        case 5:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 5);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE * 3);
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 4;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 4 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
            break;

        case 6:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 5);
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 4 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 6 + THREE_QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
            break;

        case 7:
            gCurrentSprite.hitboxTop = EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 4;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 6 + HALF_BLOCK_SIZE;
            break;

        case 8:
            gCurrentSprite.hitboxTop = BLOCK_SIZE + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = BLOCK_SIZE * 2;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 6;
            break;

        case 9:
            gCurrentSprite.hitboxTop = BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 5;
            break;

        case 10:
            gCurrentSprite.hitboxTop = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 4 + HALF_BLOCK_SIZE;
            break;

        case 11:
            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = BLOCK_SIZE * 2;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
            break;
    }
}

/**
 * @brief 18e88 | 28 | Changes the hitbox of something
 * 
 */
static void KraidPartHitboxChange_2Unused(void)
{
    if (gCurrentSprite.animationDurationCounter == DELTA_TIME)
    {
        gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
        gCurrentSprite.hitboxBottom = -HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = EIGHTH_BLOCK_SIZE;
        gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE;
    }
}

/**
 * @brief 18eb0 | 11c | Updates the left arm (idling) hitbox
 * 
 */
static void KraidPartUpdateLeftArmIdlingHitbox(void)
{
    
    if (gCurrentSprite.animationDurationCounter != DELTA_TIME)
        return;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE;
            break;

        case 1:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE;
            break;

        case 2:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + PIXEL_SIZE);
            gCurrentSprite.hitboxBottom = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE;
            break;

        case 3:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE;
            break;

        case 4:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            break;

        case 5:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE;
            break;

        case 6:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxLeft = QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE;
            break;

        case 7:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = PIXEL_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE;
            break;

        case 8:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = PIXEL_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE;
            break;

        case 9:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE;
            break;
    }
}

/**
 * @brief 18fcc | 138 | Updates the arm (dying) hitbox
 * 
 */
static void KraidPartUpdateLeftArmDyingHitbox(void)
{
    if (gCurrentSprite.animationDurationCounter != DELTA_TIME)
        return;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2;
            SoundPlay(SOUND_KRAID_LEFT_ARM_DYING_1);
            break;

        case 1:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 3);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE;
            break;

        case 2:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxLeft = -BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE + QUARTER_BLOCK_SIZE;
            break;

        case 3:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 5 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxLeft = -BLOCK_SIZE;
            gCurrentSprite.hitboxRight = THREE_QUARTER_BLOCK_SIZE;
            break;

        case 4:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 7 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE * 6);
            gCurrentSprite.hitboxLeft = -BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE;
            SoundPlay(SOUND_KRAID_LEFT_ARM_DYING_2);
            break;

        case 5:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 7);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE * 5);
            gCurrentSprite.hitboxLeft = BLOCK_SIZE + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            break;

        case 6:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE * 3);
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 4 + HALF_BLOCK_SIZE;
            break;

        case 7:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxLeft = BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 3;
            break;

        case 8:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = PIXEL_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2;
            break;

        case 9:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE;
            break;
    }
}

/**
 * @brief 19104 | 22c | Updates the arm (attacking) hitbox
 * 
 */
static void KraidPartUpdateLeftArmAttackingHitbox(void)
{
    if (gCurrentSprite.animationDurationCounter != DELTA_TIME)
        return;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2;
            SoundPlay(SOUND_KRAID_LEFT_ARM_ATTACKING_1);
            break;

        case 1:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE - EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE;
            break;

        case 2:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + THREE_QUARTER_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -THREE_QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;
            break;

        case 3:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxLeft = -(BLOCK_SIZE * 2);
            gCurrentSprite.hitboxRight = -HALF_BLOCK_SIZE;
            break;

        case 4:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 4);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE * 2);
            gCurrentSprite.hitboxLeft = -(BLOCK_SIZE * 2);
            gCurrentSprite.hitboxRight = -HALF_BLOCK_SIZE;
            break;

        case 5:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 4);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxLeft = -(BLOCK_SIZE * 2);
            gCurrentSprite.hitboxRight = -HALF_BLOCK_SIZE;
            break;

        case 6:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 6);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE * 4);
            gCurrentSprite.hitboxLeft = -(BLOCK_SIZE * 2);
            gCurrentSprite.hitboxRight = -EIGHTH_BLOCK_SIZE;
            SoundPlay(SOUND_KRAID_LEFT_ARM_ATTACKING_2);
            break;

        case 7:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 5 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE * 4 + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxLeft = EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2;
            break;

        case 8:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 4);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE * 3);
            gCurrentSprite.hitboxLeft = BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            break;

        case 9:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -THREE_QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            break;

        case 10:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE;
            break;

        case 11:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = PIXEL_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE;
            break;

        case 12:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2);
            gCurrentSprite.hitboxBottom = -BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = PIXEL_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE;
            break;

        case 13:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE;
            break;

        case 14:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2;
            break;

        case 15:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE;
            SoundPlay(SOUND_KRAID_LEFT_ARM_ATTACKING_3);
            break;

        case 16:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            break;

        case 17:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
            break;

        case 18:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = PIXEL_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2;
            break;

        case 19:
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = PIXEL_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE;
            break;
    }
}

/**
 * @brief 19330 | 20 | Moves the BG2 to the right
 * 
 * @param movement Movement
 */
static void KraidMoveBg2ToRight(u8 movement)
{
    gSubSpriteData1.xPosition += movement;
    gBg2Movement.xOffset -= movement;
}

/**
 * @brief 19350 | 20 | Moves the BG2 to the left
 * 
 * @param movement Movement
 */
static void KraidMoveBg2ToLeft(u8 movement)
{
    gSubSpriteData1.xPosition -= movement;
    gBg2Movement.xOffset += movement;
}

/**
 * @brief 19370 | 22c | Initializes a Kraid sprite
 * 
 */
static void KraidInit(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;
    u8 partSlot;

    LOCK_DOORS();
    gCurrentSprite.yPosition -= HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
    gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;

    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;
    yPosition = gSubSpriteData1.yPosition;
    xPosition = gSubSpriteData1.xPosition;
    gCurrentSprite.yPositionSpawn = yPosition;
    gCurrentSprite.xPositionSpawn = xPosition;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -(BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE);
    gCurrentSprite.hitboxBottom = BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE;
    
    gCurrentSprite.work0 = CONVERT_SECONDS(2.f);
    gCurrentSprite.work1 = 0;
    gCurrentSprite.samusCollision = SSC_HURTS_KNOCKBACK_IF_INVINCIBLE;

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(PSPRITE_KRAID);
    gSubSpriteData1.health = gCurrentSprite.health;

    gSubSpriteData1.work3 = 0;
    gSubSpriteData1.work2 = 0;
    gSubSpriteData1.work1 = 0;

    gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_Rising;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pOam = sKraidOam_Rising;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = KRAID_POSE_GO_UP;
    gCurrentSprite.roomSlot = KRAID_PART_KRAID;

    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_BELLY, gfxSlot, ramSlot, yPosition, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_LEFT_ARM, gfxSlot, ramSlot, yPosition, xPosition, 0);

    // Store RAM slot of the left holes in work variable to be used when shooting spikes
    partSlot = SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_TOP_HOLE_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0);
    gSpriteData[partSlot].work1 = partSlot;
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_TOP_HOLE_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0);

    partSlot = SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_MIDDLE_HOLE_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0);
    gSpriteData[partSlot].work1 = partSlot;
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_MIDDLE_HOLE_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0);

    partSlot = SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_BOTTOM_HOLE_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0);
    gSpriteData[partSlot].work1 = partSlot;
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_BOTTOM_HOLE_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0);

    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_LEFT_FEET, gfxSlot, ramSlot, yPosition, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_RIGHT_ARM, gfxSlot, ramSlot, yPosition, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_RIGHT_FEET, gfxSlot, ramSlot, yPosition, xPosition, 0);

    gSubSpriteData1.yPosition += BLOCK_SIZE * 2;
    gBg2Movement.yOffset -= BLOCK_SIZE * 2;
}

/**
 * @brief 1959c | 50 | Handles kraid moving up at the beginning of the fight
 * 
 * @return u8 1 if done rising, 0 otherwise
 */
static u8 KraidMoveUp(void)
{
    KraidRandomSpriteDebrisOnCeiling(gCurrentSprite.work1);

    if (MOD_AND(gSubSpriteData1.yPosition, QUARTER_BLOCK_SIZE) == 0)
        ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 6), 0x80 | 1);

    if (gSubSpriteData1.yPosition > gCurrentSprite.yPositionSpawn)
    {
        gSubSpriteData1.yPosition -= ONE_SUB_PIXEL;
        gBg2Movement.yOffset += ONE_SUB_PIXEL;
        return FALSE;
    }

    return TRUE;
}

/**
 * @brief 19640 | 2c | Makes kraid go up at the beginning of the fight
 * 
 */
static void KraidGoUp(void)
{
    if (gCurrentSprite.work1 == 0)
        SoundPlay(SOUND_KRAID_RISING);

    APPLY_DELTA_TIME_INC(gCurrentSprite.work1);

    KraidMoveUp();

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = KRAID_POSE_CHECK_FULLY_UP;
        gCurrentSprite.pOam = sKraidOam_ClosingMouth;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 19640 | 2c | Checks if kraid is fully up
 * 
 */
static void KraidCheckFullyUp(void)
{
    APPLY_DELTA_TIME_INC(gCurrentSprite.work1);
    if (KraidMoveUp())
        gCurrentSprite.pose = KRAID_POSE_STANDING_INIT;
}

/**
 * @brief 1966c | 1a4 | Handles Kraid moving a feet
 * 
 * @return u8 
 */
static u8 KraidMoveFeet(void)
{
    u8 offset;
    u16 yPosition;
    u16 xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gSubSpriteData1.health >= GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 3)
            offset = BLOCK_SIZE;
        else if (gDifficulty == DIFF_EASY)
            offset = BLOCK_SIZE;
        else
            offset = BLOCK_SIZE * 3;

        if (gCurrentSprite.xPositionSpawn + offset < gSubSpriteData1.xPosition)
            return 2;

        if (gSubSpriteData1.currentAnimationFrame < 5)
        {
            KraidMoveBg2ToRight(ONE_SUB_PIXEL);
            yPosition = BLOCK_SIZE * 39 + HALF_BLOCK_SIZE;
            xPosition = gSubSpriteData1.xPosition + BLOCK_SIZE * 5;

            if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition) != COLLISION_AIR)
            {
                gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                ClipdataProcess(yPosition, xPosition);

                ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_HUGE);

                SpriteDebrisInit(0, 0x11, yPosition - QUARTER_BLOCK_SIZE, xPosition);
                SpriteDebrisInit(0, 0x12, yPosition, xPosition + EIGHTH_BLOCK_SIZE + PIXEL_SIZE);
                SpriteDebrisInit(0, 0x13, yPosition - (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2),
                    xPosition + QUARTER_BLOCK_SIZE + PIXEL_SIZE);
                SpriteDebrisInit(0, 0x4, yPosition - (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE),
                    xPosition - (HALF_BLOCK_SIZE - PIXEL_SIZE / 2));

                SoundPlay(SOUND_138);
                yPosition -= BLOCK_SIZE * 8;
                xPosition -= BLOCK_SIZE;

                if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition) != COLLISION_AIR)
                {
                    gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                    ClipdataProcess(yPosition, xPosition);

                    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);

                    SpriteDebrisInit(0, 0x11, yPosition - QUARTER_BLOCK_SIZE, xPosition);
                    SpriteDebrisInit(0, 0x12, yPosition, xPosition + EIGHTH_BLOCK_SIZE + PIXEL_SIZE);
                    SpriteDebrisInit(0, 0x13, yPosition - (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2),
                        xPosition + QUARTER_BLOCK_SIZE + PIXEL_SIZE);
                    SpriteDebrisInit(0, 0x4, yPosition - (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE),
                        xPosition - (HALF_BLOCK_SIZE - PIXEL_SIZE / 2));
                }
            }
        }
    }
    else
    {
        if (gSubSpriteData1.health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 3)
            offset = BLOCK_SIZE;
        else
            offset = 0;

        if (gCurrentSprite.xPositionSpawn + offset > gSubSpriteData1.xPosition)
            return 1;

        if (gSubSpriteData1.currentAnimationFrame < 5)
        {
            KraidMoveBg2ToLeft(ONE_SUB_PIXEL);
        }
    }

    return 0;
}

/**
 * @brief 19810 | 44 | Initializes Kraid to do the first step
 * 
 */
static void KraidFirstStepInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_MovingLeftFeetToRight;
    else
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_MovingRightFeetToLeft;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = KRAID_POSE_FIRST_STEP;
}

/**
 * @brief 19854 | e0 | Handles Kraid doing the first step
 * 
 */
static void KraidFirstStep(void)
{
    u8 feetStatus;

    feetStatus = KraidMoveFeet();
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        if (gSubSpriteData1.work1 != 0)
        {
            if (gSubSpriteData1.work1 <= CONVERT_SECONDS(.05f))
            {
                APPLY_DELTA_TIME_INC(gSubSpriteData1.work1);
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = KRAID_POSE_SECOND_STEP_INIT;
            }
            else
            {
                gSubSpriteData1.work1 = 0;
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = KRAID_POSE_STANDING_BETWEEN_STEPS_INIT;
            }
        }
        else
        {
            if (gSubSpriteData1.health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 4)
                gCurrentSprite.pose = KRAID_POSE_SECOND_STEP_INIT;
            else
                gCurrentSprite.pose = KRAID_POSE_STANDING_BETWEEN_STEPS_INIT;
            
            if (feetStatus != 0)
            {
                if (gSubSpriteData1.health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 3 && feetStatus == 2)
                    gCurrentSprite.pose = KRAID_POSE_STANDING_BETWEEN_STEPS_INIT;
                else
                    gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
            }
        }
    }
}

/**
 * @brief 19934 | 44 | Initializes Kraid to do the second step
 * 
 */
static void KraidSecondStepInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_MovingRightFeetToRight;
    else
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_MovingLeftFeetToLeft;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = KRAID_POSE_SECOND_STEP;
}

/**
 * @brief 19978 | e0 | Handles Kraid doing the second step
 * 
 */
static void KraidSecondStep(void)
{
    u8 feetStatus;

    feetStatus = KraidMoveFeet();
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        if (gSubSpriteData1.work1 != 0)
        {
            if (gSubSpriteData1.work1 <= CONVERT_SECONDS(.05f))
            {
                APPLY_DELTA_TIME_INC(gSubSpriteData1.work1);
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = KRAID_POSE_FIRST_STEP_INIT;
            }
            else
            {
                gSubSpriteData1.work1 = 0;
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = KRAID_POSE_STANDING_INIT;
            }
        }
        else
        {
            if (gSubSpriteData1.health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 4)
                gCurrentSprite.pose = KRAID_POSE_FIRST_STEP_INIT;
            else
                gCurrentSprite.pose = KRAID_POSE_STANDING_INIT;
            
            if (feetStatus != 0)
            {
                if (gSubSpriteData1.health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 3 && feetStatus == 2)
                    gCurrentSprite.pose = KRAID_POSE_STANDING_INIT;
                else
                    gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
            }
        }
    }
}

/**
 * @brief 19a58 | 24 | Initializes Kraid to be standing
 * 
 */
static void KraidStandingInit(void)
{
    gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_Standing;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = KRAID_POSE_STANDING;
}

/**
 * @brief 19a7c | 38 | Handles Kraid standing
 * 
 */
static void KraidStanding(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        gCurrentSprite.pose = KRAID_POSE_FIRST_STEP_INIT;
        if (gSubSpriteData1.work1 == 1)
        {
            gSubSpriteData1.work1++;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        }
    }
}

/**
 * @brief 19ab4 | 24 | Initializes Kraid to be standing (between steps)
 * 
 */
static void KraidStandingBetweenStepsInit(void)
{
    gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_StandingBetweenSteps;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = KRAID_POSE_STANDING_BETWEEN_STEPS;
}

/**
 * @brief 19ad8 | 38 | Handles Kraid (between steps)
 * 
 */
static void KraidStandingBetweenSteps(void)
{
    if (SpriteUtilHasSubSprite1AnimationNearlyEnded())
    {
        // Start second step
        gCurrentSprite.pose = KRAID_POSE_SECOND_STEP_INIT;
        if (gSubSpriteData1.work1 == 1)
        {
            gSubSpriteData1.work1++;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        }
    }
}

/**
 * @brief 19b10 | 24 | Prevents samus from going through Kraid
 * 
 */
static void KraidPreventSamusGoingThrough(void)
{
    u16 xPosition;

    xPosition = gSubSpriteData1.xPosition + BLOCK_SIZE * 3;
    
    if (gSamusData.xPosition < xPosition)
        gSamusData.xPosition = xPosition;
}

/**
 * @brief 19b34 | b0 | Initializes Kraid to be dying
 * 
 */
static void KraidDyingInit(void)
{
    if (gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_Standing ||
        gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingRightFeetToRight ||
        gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToLeft)
    {
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_Dying1;
    }
    else
    {
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_Dying2;
    }

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    if (gCurrentSprite.pOam != sKraidOam_OpeningMouth && gCurrentSprite.pOam != sKraidOam_MouthOpened)
    {
        gCurrentSprite.pOam = sKraidOam_OpeningMouth;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.pose = KRAID_POSE_DYING;
    gCurrentSprite.work0 = CONVERT_SECONDS(1.f) + TWO_THIRD_SECOND;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work2 = CONVERT_SECONDS(3.f) + ONE_THIRD_SECOND;
    gCurrentSprite.health = 1;
    gCurrentSprite.invincibilityStunFlashTimer = EIGHTH_BLOCK_SIZE;
    gCurrentSprite.drawOrder = 12;
    EventFunction(EVENT_ACTION_SETTING, EVENT_KRAID_KILLED);
    MinimapUpdateChunk(EVENT_KRAID_KILLED);
    SoundPlay(SOUND_KRAID_DYING_1);
}

/**
 * @brief 19be4 | 160 | Handles Kraid dying
 * 
 */
static void KraidDying(void)
{
    u8 rng;

    if (gCurrentSprite.pOam == sKraidOam_OpeningMouth && SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pOam = sKraidOam_MouthOpened;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    KraidRandomSpriteDebrisOnCeiling(gCurrentSprite.work1);
    KraidPreventSamusGoingThrough();

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    APPLY_DELTA_TIME_INC(gCurrentSprite.work1);

    // Set dust effects
    if (MOD_AND(gCurrentSprite.work1, 32) == 0)
    {
        ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition - (BLOCK_SIZE * 3) + gCurrentSprite.work1 * PIXEL_SIZE / 2, PE_SECOND_MEDIUM_DUST);
        ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition + (BLOCK_SIZE * 3) - gCurrentSprite.work1 * PIXEL_SIZE / 2, PE_SECOND_TWO_MEDIUM_DUST);
    }

    if (gCurrentSprite.work0 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        return;
    }

    // Check play cutscene
    if (gCurrentSprite.work2 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work2);
        if (gCurrentSprite.work2 == DELTA_TIME)
            StartEffectForCutscene(EFFECT_CUTSCENE_STATUE_OPENING);
        else if (gCurrentSprite.work2 == 0)
            SoundPlay(SOUND_KRAID_DYING_3);
    }

    // Play effects
    if (MOD_AND(gCurrentSprite.work1, 16) == 0)
    {
        ScreenShakeStartVertical(ONE_THIRD_SECOND, 0x80 | 1);
        ParticleSet(gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE) + gSpriteRng * QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition - (BLOCK_SIZE * 3 + EIGHTH_BLOCK_SIZE) + gCurrentSprite.work1 * ONE_SUB_PIXEL, PE_SPRITE_EXPLOSION_HUGE);
    }

    if (MOD_AND(gCurrentSprite.work1 - 8, 16) == 0)
    {
        ParticleSet(gCurrentSprite.yPosition + BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE - PIXEL_SIZE - gSpriteRng * QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition + BLOCK_SIZE * 3 + THREE_QUARTER_BLOCK_SIZE - gCurrentSprite.work1 * ONE_SUB_PIXEL, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }

    if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition) != COLLISION_AIR)
    {
        gCurrentSprite.pose = KRAID_POSE_DEAD_STATIONARY;
        gCurrentSprite.work0 = CONVERT_SECONDS(2.f);
        SoundPlay(SOUND_KRAID_DYING_2);
    }
    else
    {
        gSubSpriteData1.yPosition += ONE_SUB_PIXEL;
        gBg2Movement.yOffset -= ONE_SUB_PIXEL;
    }
}

/**
 * @brief 19d44 | 184 | Handles Kraid being stationary while dying
 * 
 */
static void KraidBeforeDeath(void)
{
    u8 rng;
    u8 timer;
    u32 yOffset;

    KraidRandomSpriteDebrisOnCeiling(gCurrentSprite.work1);
    KraidPreventSamusGoingThrough();

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    rng = gSpriteRng;
    gCurrentSprite.work1++;

    timer = gCurrentSprite.work1;
    if (MOD_AND(timer, 8) == 0)
    {
        if (MOD_BLOCK_AND(timer, 8))
        {
            ScreenShakeStartVertical(ONE_THIRD_SECOND, 0x80 | 1);
            ParticleSet(gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE) + rng * QUARTER_BLOCK_SIZE,
                gCurrentSprite.xPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE) + timer * PIXEL_SIZE / 2, PE_SPRITE_EXPLOSION_HUGE);
            yOffset = (timer * PIXEL_SIZE / 2);
            ParticleSet(gCurrentSprite.yPosition + (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE - PIXEL_SIZE) - rng * QUARTER_BLOCK_SIZE,
                gCurrentSprite.xPosition + BLOCK_SIZE * 3 - yOffset, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
        }
        else
        {
            ParticleSet(gCurrentSprite.yPosition + rng * QUARTER_BLOCK_SIZE,
                gCurrentSprite.xPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE) - timer * PIXEL_SIZE / 2, PE_SPRITE_EXPLOSION_HUGE);
            ParticleSet(gCurrentSprite.yPosition - rng * EIGHTH_BLOCK_SIZE,
                gCurrentSprite.xPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE) + timer * PIXEL_SIZE / 2, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
        }
    }

    if (MOD_AND(timer, 16) == 0)
    {
        if (MOD_BLOCK_AND(timer, 16))
        {
            ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition - (BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE) + gCurrentSprite.work0 * PIXEL_SIZE / 2, PE_SPRITE_EXPLOSION_MEDIUM);
            ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition + (BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE) - gCurrentSprite.work0 * PIXEL_SIZE / 2, PE_SPRITE_EXPLOSION_BIG);
        }
        else
        {
            ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE + PIXEL_SIZE / 2) + gCurrentSprite.work0 * PIXEL_SIZE / 2, PE_SPRITE_EXPLOSION_BIG);
            ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition + (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE + PIXEL_SIZE / 2) - gCurrentSprite.work0 * PIXEL_SIZE / 2, PE_SPRITE_EXPLOSION_MEDIUM);
        }
    }

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        // Set dead
        SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE * 3, gSubSpriteData1.xPosition, FALSE, PE_MAIN_BOSS_DEATH);
        FadeCurrentMusicAndQueueNextMusic(ONE_THIRD_SECOND, MUSIC_BOSS_KILLED, 0);
        // Remove BG2
        IoUpdateDispcnt(FALSE, DCNT_BG2);
        gInGameTimerAtBosses[0] = gInGameTimer;
    }
}

/**
 * @brief 19ec8 | 360 | Initializes a Kraid part sprite
 * 
 */
static void KraidPartInit(void)
{
    gCurrentSprite.health = 1000;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.pose = KRAID_PART_POSE_IDLE;

    switch (gCurrentSprite.roomSlot)
    {
        case KRAID_PART_BELLY:
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.samusCollision = SSC_HURTS_KNOCKBACK_IF_INVINCIBLE;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 8);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = BLOCK_SIZE * 7 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE;

            gCurrentSprite.drawOrder = 1;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_PROJECTILES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        case KRAID_PART_TOP_HOLE_LEFT:
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.frozenPaletteRowOffset = 4;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

            gCurrentSprite.drawOrder = 11;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_SPAWN_SPIKES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        case KRAID_PART_TOP_HOLE_RIGHT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 4;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -PIXEL_SIZE;
            gCurrentSprite.hitboxBottom = PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
            gCurrentSprite.hitboxRight = PIXEL_SIZE;

            gCurrentSprite.drawOrder = 13;
            break;

        case KRAID_PART_MIDDLE_HOLE_LEFT:
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.frozenPaletteRowOffset = 4;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + QUARTER_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE + QUARTER_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = BLOCK_SIZE + QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = THREE_QUARTER_BLOCK_SIZE;

            gCurrentSprite.drawOrder = 11;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_SPAWN_SPIKES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        case KRAID_PART_MIDDLE_HOLE_RIGHT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 4;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + QUARTER_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom =  SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal =  SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -PIXEL_SIZE;
            gCurrentSprite.hitboxBottom = PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
            gCurrentSprite.hitboxRight = PIXEL_SIZE;

            gCurrentSprite.drawOrder = 13;
            break;

        case KRAID_PART_BOTTOM_HOLE_LEFT:
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.frozenPaletteRowOffset = 4;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + QUARTER_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE + QUARTER_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

            gCurrentSprite.drawOrder = 11;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_SPAWN_SPIKES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        case KRAID_PART_BOTTOM_HOLE_RIGHT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 4;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -PIXEL_SIZE;
            gCurrentSprite.hitboxBottom = PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
            gCurrentSprite.hitboxRight = PIXEL_SIZE;

            gCurrentSprite.drawOrder = 13;
            break;

        case KRAID_PART_LEFT_ARM:
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            
            gCurrentSprite.drawDistanceTop = BLOCK_SIZE * 2;
            gCurrentSprite.drawDistanceBottom = (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = BLOCK_SIZE + HALF_BLOCK_SIZE;

            gCurrentSprite.drawOrder = 2;
            gCurrentSprite.pOam = sKraidPartOam_LeftArmIdle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_THROW_NAILS;
            break;

        case KRAID_PART_RIGHT_ARM:
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 6);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 7 + HALF_BLOCK_SIZE);

            gCurrentSprite.drawOrder = 15;
            gCurrentSprite.bgPriority = BGCNT_LOW_PRIORITY;

            gCurrentSprite.pOam = sKraidPartOam_RightArmIdle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_ATTACK;
            gCurrentSprite.work0 = 0;
            break;

        case KRAID_PART_LEFT_FEET:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -PIXEL_SIZE;
            gCurrentSprite.hitboxBottom = PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
            gCurrentSprite.hitboxRight = PIXEL_SIZE;

            gCurrentSprite.drawOrder = 3;
            break;

        case KRAID_PART_RIGHT_FEET:
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 7);

            gCurrentSprite.hitboxTop = BLOCK_SIZE * 2;
            gCurrentSprite.hitboxBottom = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 3;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 5 + THREE_QUARTER_BLOCK_SIZE;

            gCurrentSprite.drawOrder = 14;
            gCurrentSprite.bgPriority = BGCNT_LOW_PRIORITY;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_PROJECTILES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 1a228 | e8 | Handles the left arm throwing the nails
 * 
 */
static void KraidPartThrowNails(void)
{
    u8 ramSlot;
    u8 threshold;
    u8 nbrDrops;
    
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    // Check can throw the nails
    if (gSpriteData[ramSlot].pose < KRAID_POSE_FIRST_STEP_INIT)
        return;

    // Check already throwing
    if (gCurrentSprite.pOam == sKraidPartOam_LeftArmIdle)
    {
        if (MOD_AND(gFrameCounter8Bit, 128) == 0)
        {
            // Try throw
            nbrDrops = SpriteUtilCountDrops();
            if (gDifficulty == DIFF_EASY)
                threshold = 1;
            else
                threshold = 3;

            if (nbrDrops < threshold)
            {
                // Set throwing
                gCurrentSprite.pOam = sKraidPartOam_LeftArmThrowingNails;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
        }
    }
    else
    {
        // Throw
        if (gCurrentSprite.currentAnimationFrame == 7 && gCurrentSprite.animationDurationCounter == CONVERT_SECONDS(1.f / 15))
        {
            SpriteSpawnSecondary(SSPRITE_KRAID_NAIL, KRAID_NAIL_TYPE_SLOW_ROTATION, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE),
                gCurrentSprite.xPosition + BLOCK_SIZE * 2, 0);
        }
        else if (gCurrentSprite.currentAnimationFrame == 8 && gCurrentSprite.animationDurationCounter == DELTA_TIME)
        {
            SpriteSpawnSecondary(SSPRITE_KRAID_NAIL, KRAID_NAIL_TYPE_FAST_ROTATION, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - (BLOCK_SIZE * 3),
                gCurrentSprite.xPosition + BLOCK_SIZE * 3 + HALF_BLOCK_SIZE, 0);
        }

        if (SpriteUtilHasCurrentAnimationEnded())
        {
            // Set idle
            gCurrentSprite.pOam = sKraidPartOam_LeftArmIdle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
}

/**
 * @brief 1a310 | d4 | Checks if samus is near enough for the arm attack
 * 
 */
static void KraidPartCheckAttack(void)
{
    u32 nslr;
    u8 ramSlot;
    u8 attack;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    nslr = NSLR_OUT_OF_RANGE;
    attack = FALSE;

    if (gSpriteData[ramSlot].status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        // Already attacking
        if (SpriteUtilHasCurrentAnimationEnded())
        {
            // Set idle
            gSpriteData[ramSlot].status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            gCurrentSprite.pOam = sKraidPartOam_RightArmIdle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
    else
    {
        // Delay before attacking
        if (gCurrentSprite.work0 != 0)
        {
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        }
        else
        {
            nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 2, BLOCK_SIZE * 8 + (HALF_BLOCK_SIZE));
            gCurrentSprite.work0 = CONVERT_SECONDS(3.f);
        }

        // Check can attack
        if (gSubSpriteData1.health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 4 * 3 && nslr == NSLR_RIGHT)
            attack++;

        if (attack)
        {
            // Set attacking
            gCurrentSprite.pOam = sKraidPartOam_RightArmAttacking;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gSpriteData[ramSlot].status |= SPRITE_STATUS_SAMUS_COLLIDING;
        }
    }
}

/**
 * @brief 1a3e4 | c | Calls KraidCheckProjectilesCollidingWithBelly
 * 
 */
static void KraidPartCallKraidCheckProjectilesCollidingWithBelly(void)
{
    KraidCheckProjectilesCollidingWithBelly();
}

/**
 * @brief 1a3f0 | 11c | Checks if the spikes should spawn
 * 
 */
static void KraidPartCheckShouldSpawnSpikes(void)
{
    u8 ramSlot;
    u8 roomSlot;
    u8 lowHealth;
    u8 i;
    s32 spriteId;
    u32 health;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    roomSlot = gCurrentSprite.roomSlot;

    // Don't try to spawn if not fully up
    if (gSpriteData[ramSlot].pose < KRAID_POSE_FIRST_STEP_INIT)
        return;

    // Handle belly collision
    KraidCheckProjectilesCollidingWithBelly();

    // Check is low health
    if (gSubSpriteData1.health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 3)
        lowHealth = TRUE;
    else
        lowHealth = FALSE;

    if (roomSlot == KRAID_PART_BOTTOM_HOLE_LEFT)
    {
        if (gSubSpriteData1.health >= DIV_SHIFT(GET_PSPRITE_HEALTH(PSPRITE_KRAID), 4) * 3 &&
            gSamusData.yPosition < gCurrentSprite.yPosition - BLOCK_SIZE * 2)
            return;

        // Don't start to spawn spikes if there's already one
        spriteId = SSPRITE_KRAID_SPIKE;
        for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
        {
            if (gSpriteData[i].status & SPRITE_STATUS_EXISTS && gSpriteData[i].properties & SP_SECONDARY_SPRITE &&
                gSpriteData[i].spriteId == spriteId)
                return;
        }

        // Set bottom hole shooting spikes flag
        gSpriteData[ramSlot].status &= ~SPRITE_STATUS_MOSAIC;

        // 1 frame delay
        gCurrentSprite.yPositionSpawn = DELTA_TIME;
    }
    else if (roomSlot == KRAID_PART_MIDDLE_HOLE_LEFT)
    {
        // Check bottom hole is shooting spikes
        if (gSpriteData[ramSlot].status & SPRITE_STATUS_MOSAIC)
            return;

        // 1 second delay
        gCurrentSprite.yPositionSpawn = CONVERT_SECONDS(1.f);
    }
    else
    {
        // Check bottom hole is shooting spikes and low health
        if (gSpriteData[ramSlot].status & SPRITE_STATUS_MOSAIC || !lowHealth)
            return;

        // 2 second delay
        gCurrentSprite.yPositionSpawn = CONVERT_SECONDS(2.f);
    }

    gCurrentSprite.pose = KRAID_PART_POSE_SPAWN_SPIKES;
}

/**
 * @brief 1a50c | 8c | Spawn a spike
 * 
 */
static void KraidPartSpawnSpike(void)
{
    u8 ramSlot;
    u8 roomSlot;
    u8 spikeSlot;

    KraidCheckProjectilesCollidingWithBelly();

    // Delay before shooting
    APPLY_DELTA_TIME_DEC(gCurrentSprite.yPositionSpawn);
    if (gCurrentSprite.yPositionSpawn == 0)
    {
        ramSlot = gCurrentSprite.primarySpriteRamSlot;
        roomSlot = gCurrentSprite.roomSlot;

        if (roomSlot == KRAID_PART_BOTTOM_HOLE_LEFT)
            gSpriteData[ramSlot].status |= SPRITE_STATUS_MOSAIC;

        // Spawn spike
        spikeSlot = SpriteSpawnSecondary(SSPRITE_KRAID_SPIKE, roomSlot,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.work1,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

        if (spikeSlot < MAX_AMOUNT_OF_SPRITES)
            gSpriteData[spikeSlot].xPositionSpawn = gSpriteData[ramSlot].xPositionSpawn;

        gCurrentSprite.pose = KRAID_PART_POSE_CHECK_SPAWN_SPIKES;
    }
}

/**
 * @brief 1a598 | b0 | Initializes a Kraid part to be dying
 * 
 */
static void KraidPartDyingInit(void)
{
    switch (gCurrentSprite.roomSlot)
    {
        case KRAID_PART_LEFT_ARM:
            gCurrentSprite.pOam = sKraidPartOam_LeftArmDying;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.yPositionSpawn = CONVERT_SECONDS(6.f) + TWO_THIRD_SECOND;
            gCurrentSprite.pose = KRAID_PART_POSE_ARM_DYING;
            gCurrentSprite.drawOrder = 10;
            break;

        case KRAID_PART_RIGHT_ARM:
            gCurrentSprite.pOam = sKraidPartOam_RightArmDying;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.yPositionSpawn = CONVERT_SECONDS(6.f) + TWO_THIRD_SECOND;
            gCurrentSprite.pose = KRAID_PART_POSE_ARM_DYING;
            break;

        case KRAID_PART_LEFT_FEET:
            gCurrentSprite.drawOrder = 10;
            gCurrentSprite.pose = KRAID_PART_POSE_DYING_STATIONNARY;
            break;

        case KRAID_PART_TOP_HOLE_LEFT:
        case KRAID_PART_TOP_HOLE_RIGHT:
        case KRAID_PART_MIDDLE_HOLE_LEFT:
        case KRAID_PART_MIDDLE_HOLE_RIGHT:
        case KRAID_PART_BOTTOM_HOLE_LEFT:
        case KRAID_PART_BOTTOM_HOLE_RIGHT:
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.pose = KRAID_PART_POSE_DYING_STATIONNARY;
            break;

        case KRAID_PART_BELLY:
        case KRAID_PART_RIGHT_FEET:
        default:
            gCurrentSprite.pose = KRAID_PART_POSE_DYING_STATIONNARY;
    }
}

/**
 * @brief 1a648 | 80 | Handles the arm while Kraid is dying and sinking
 * 
 */
static void KraidPartDyingSinking(void)
{
    if (gCurrentSprite.yPositionSpawn != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.yPositionSpawn);
        if (gCurrentSprite.roomSlot == KRAID_PART_RIGHT_ARM || gCurrentSprite.roomSlot == KRAID_PART_LEFT_ARM)
            gCurrentSprite.animationDurationCounter += CONVERT_SECONDS(1.f / 60);
    }
    else
    {
        if (gCurrentSprite.roomSlot == KRAID_PART_RIGHT_ARM)
        {
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.pOam = sKraidPartOam_RightArmIdle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.drawDistanceTop = (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
                gCurrentSprite.drawDistanceBottom = (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
                gCurrentSprite.pose = KRAID_PART_POSE_DYING_STATIONNARY;
            }
        }
        else if (gCurrentSprite.roomSlot == KRAID_PART_LEFT_ARM)
        {
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.pOam = sKraidPartOam_LeftArmIdle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.drawDistanceTop = BLOCK_SIZE;
                gCurrentSprite.drawDistanceBottom = (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
                gCurrentSprite.pose = KRAID_PART_POSE_DYING_STATIONNARY;
            }
        }
    }
}

/**
 * @brief 1a6c8 | 188 | Handles the death of a Kraid part
 * 
 */
static void KraidPartDyingStationary(void)
{
    u8 ramSlot;
    
    // Speed up arm animation
    if (gCurrentSprite.roomSlot == KRAID_PART_RIGHT_ARM || gCurrentSprite.roomSlot == KRAID_PART_LEFT_ARM)
        gCurrentSprite.animationDurationCounter += CONVERT_SECONDS(1.f / 30);

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (gSpriteData[ramSlot].spriteId == PSPRITE_KRAID)
        return;

    // Kraid is dead, kill the part
    switch (gCurrentSprite.roomSlot)
    {
        case KRAID_PART_BELLY:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE,
                gSubSpriteData1.xPosition - BLOCK_SIZE * 2, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_TOP_HOLE_LEFT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE * 2,
                gSubSpriteData1.xPosition + BLOCK_SIZE * 4, FALSE, PE_SPRITE_EXPLOSION_BIG);
            break;

        case KRAID_PART_TOP_HOLE_RIGHT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE * 3,
                gSubSpriteData1.xPosition - BLOCK_SIZE * 6, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_MIDDLE_HOLE_LEFT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE * 4,
                gSubSpriteData1.xPosition + BLOCK_SIZE * 4, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_MIDDLE_HOLE_RIGHT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE * 5,
                gSubSpriteData1.xPosition - BLOCK_SIZE, FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            break;

        case KRAID_PART_BOTTOM_HOLE_LEFT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE,
                gSubSpriteData1.xPosition + BLOCK_SIZE * 3, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_BOTTOM_HOLE_RIGHT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE * 2,
                gSubSpriteData1.xPosition - BLOCK_SIZE * 5, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_LEFT_ARM:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE * 3,
                gSubSpriteData1.xPosition + BLOCK_SIZE * 3, FALSE, PE_SPRITE_EXPLOSION_BIG);
            break;

        case KRAID_PART_RIGHT_ARM:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE * 4,
                gSubSpriteData1.xPosition - BLOCK_SIZE, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_LEFT_FEET:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE * 5,
                gSubSpriteData1.xPosition + BLOCK_SIZE * 2, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_RIGHT_FEET:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE,
                gSubSpriteData1.xPosition - BLOCK_SIZE * 3, FALSE, PE_SPRITE_EXPLOSION_BIG);
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 1a850 | 1ec | Handles the movement of a Kraid nail
 * 
 */
static void KraidNailMovement(void)
{
    u16 velocity;
    u32 spawnX;
    u32 spawnY;
    u16 distanceYDown;
    u16 distanceYUp;
    u16 distanceXLeft;
    u16 distanceXRight;
    s32 totalDistance;
    u16 samusY;
    u16 spriteY;
    u8 acceleration;

    velocity = PIXEL_SIZE;
    if (gDifficulty == DIFF_HARD)
        velocity = EIGHTH_BLOCK_SIZE;

    acceleration = ++gCurrentSprite.work1;
    if (acceleration == 0)
    {
        gCurrentSprite.status = 0;
        return;
    }

    velocity *= acceleration;

    #ifdef REGION_US_BETA
    spawnY = gCurrentSprite.work3 * BLOCK_SIZE + HALF_BLOCK_SIZE;
    spawnX = gCurrentSprite.work2 * BLOCK_SIZE + HALF_BLOCK_SIZE;
    #else // !REGION_US_BETA
    spawnY = gCurrentSprite.work3 * BLOCK_SIZE;
    spawnX = gCurrentSprite.work2 * BLOCK_SIZE;
    #endif // REGION_US_BETA

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
                gCurrentSprite.yPosition = spawnY + (velocity * ((s32)(distanceYUp << 0xA) / totalDistance) >> 0xA);
                gCurrentSprite.xPosition = spawnX + (velocity * ((s32)(distanceXRight << 0xA) / totalDistance) >> 0xA);
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYDown * distanceYDown);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = spawnY - (velocity * ((s32)(distanceYDown << 0xA) / totalDistance) >> 0xA);
                gCurrentSprite.xPosition = spawnX + (velocity * ((s32)(distanceXRight << 0xA) / totalDistance) >> 0xA);
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
                gCurrentSprite.yPosition = spawnY + (velocity * ((s32)(distanceYUp << 0xA) / totalDistance) >> 0xA);
                gCurrentSprite.xPosition = spawnX - (velocity * ((s32)(distanceXLeft << 0xA) / totalDistance) >> 0xA);
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYDown * distanceYDown);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = spawnY - (velocity * ((s32)(distanceYDown << 0xA) / totalDistance) >> 0xA);
                gCurrentSprite.xPosition = spawnX - (velocity * ((s32)(distanceXLeft << 0xA) / totalDistance) >> 0xA);
            }
        }
    }
}

/**
 * @brief 1aa3c | 474 | Kraid AI
 * 
 */
void Kraid(void)
{
    if (gCurrentSprite.pose != 0 && gSubSpriteData1.health != 0)
        KraidOpenCloseRoutineAndProjectileCollision();

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            KraidInit();
            break;

        case KRAID_POSE_GO_UP:
            KraidGoUp();
            break;

        case KRAID_POSE_CHECK_FULLY_UP:
            KraidCheckFullyUp();
            break;

        case KRAID_POSE_FIRST_STEP_INIT:
            KraidFirstStepInit();

        case KRAID_POSE_FIRST_STEP:
            KraidFirstStep();
            break;

        case KRAID_POSE_SECOND_STEP_INIT:
            KraidSecondStepInit();

        case KRAID_POSE_SECOND_STEP:
            KraidSecondStep();
            break;

        case KRAID_POSE_STANDING_INIT:
            KraidStandingInit();

        case KRAID_POSE_STANDING:
            KraidStanding();
            break;

        case KRAID_POSE_STANDING_BETWEEN_STEPS_INIT:
            KraidStandingBetweenStepsInit();

        case KRAID_POSE_STANDING_BETWEEN_STEPS:
            KraidStandingBetweenSteps();
            break;

        case KRAID_POSE_DYING_INIT:
            KraidDyingInit();

        case KRAID_POSE_DYING:
            KraidDying();
            break;

        case KRAID_POSE_DEAD_STATIONARY:
            KraidBeforeDeath();
    }

    if (gCurrentSprite.spriteId == PSPRITE_KRAID)
    {
        SpriteUtilUpdateSubSprite1Anim();
        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();

        if (gSubSpriteData1.animationDurationCounter == 1)
        {
            if (gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_Rising ||
                gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_Standing)
            {
                if (gSubSpriteData1.currentAnimationFrame == 1)
                    gBg2Movement.yOffset -= 4;
                else if (gSubSpriteData1.currentAnimationFrame == 2)
                    gBg2Movement.yOffset += 4;
            }
            else if (gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_StandingBetweenSteps)
            {
                if (gSubSpriteData1.currentAnimationFrame == 1)
                    gBg2Movement.yOffset -= 4;
                else if (gSubSpriteData1.currentAnimationFrame == 2)
                    gBg2Movement.yOffset += 4;
            }
            else if (gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToRight ||
                gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingRightFeetToLeft)
            {
                if (gSubSpriteData1.currentAnimationFrame == 1)
                    gBg2Movement.xOffset -= 4;
                else if (gSubSpriteData1.currentAnimationFrame == 2)
                    gBg2Movement.xOffset -= 4;
                else if (gSubSpriteData1.currentAnimationFrame == 3)
                    gBg2Movement.xOffset -= 4;
                else if (gSubSpriteData1.currentAnimationFrame == 4)
                    gBg2Movement.yOffset -= 4;
                else if (gSubSpriteData1.currentAnimationFrame == 5)
                {
                    gBg2Movement.yOffset += 4;
                    ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
                    SoundPlay(SOUND_KRAID_STOMPING_FEET);
                    if (gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToRight)
                    {
                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            gSubSpriteData1.xPosition - (HALF_BLOCK_SIZE + 12), PE_SECOND_MEDIUM_DUST);

                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            gSubSpriteData1.xPosition - (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE), PE_SECOND_MEDIUM_DUST);
                    }
                    else
                    {
                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            gSubSpriteData1.xPosition + (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE + 12), PE_SECOND_MEDIUM_DUST);

                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            gSubSpriteData1.xPosition + (BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE), PE_SECOND_MEDIUM_DUST);
                    }
                }
            }
            else if (gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingRightFeetToRight ||
                gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToLeft)
            {
                if (gSubSpriteData1.currentAnimationFrame == 1)
                    gBg2Movement.xOffset += 4;
                else if (gSubSpriteData1.currentAnimationFrame == 2)
                    gBg2Movement.xOffset += 4;
                else if (gSubSpriteData1.currentAnimationFrame == 3)
                    gBg2Movement.xOffset += 4;
                else if (gSubSpriteData1.currentAnimationFrame == 4)
                    gBg2Movement.yOffset -= 4;
                else if (gSubSpriteData1.currentAnimationFrame == 5)
                {
                    gBg2Movement.yOffset += 4;
                    ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
                    SoundPlay(SOUND_KRAID_STOMPING_FEET);
                    if (gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToLeft)
                    {
                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            gSubSpriteData1.xPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE + 4), PE_SECOND_MEDIUM_DUST);

                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            gSubSpriteData1.xPosition - (BLOCK_SIZE * 3 + 8), PE_SECOND_MEDIUM_DUST);
                    }
                    else
                    {
                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            gSubSpriteData1.xPosition + (BLOCK_SIZE * 4 + 10), PE_SECOND_MEDIUM_DUST);

                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            gSubSpriteData1.xPosition + (BLOCK_SIZE * 5 + HALF_BLOCK_SIZE + 14), PE_SECOND_MEDIUM_DUST);
                    }
                }
            }
        }

        if (gSubSpriteData1.work1 != 0)
            gSubSpriteData1.animationDurationCounter += CONVERT_SECONDS(1.f / 15);

        gLockScreen.lock = LOCK_SCREEN_TYPE_POSITION;
        gLockScreen.yPositionCenter = gSamusData.yPosition;
        gLockScreen.xPositionCenter = gSamusData.xPosition - BLOCK_SIZE * 5;

        if (gCurrentSprite.paletteRow == 0xE - gCurrentSprite.frozenPaletteRowOffset)
        {
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN))
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
        }
    }
    else
    {
        gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;
    }
}

/**
 * @brief 1aeb0 | 198 | Kraid part AI
 * 
 */
void KraidPart(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    gCurrentSprite.absolutePaletteRow = gSpriteData[ramSlot].absolutePaletteRow;
    gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;

    if (gSubSpriteData1.health == 0)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        if (gCurrentSprite.pose < KRAID_PART_POSE_DYING_INIT)
        {
            gCurrentSprite.pose = KRAID_PART_POSE_DYING_INIT;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        }
    }
    
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            KraidPartInit();
            break;

        case KRAID_PART_POSE_CHECK_THROW_NAILS:
            KraidPartThrowNails();
            break;

        case KRAID_PART_POSE_CHECK_ATTACK:
            KraidPartCheckAttack();
            break;

        case KRAID_PART_POSE_CHECK_SPAWN_SPIKES:
            KraidPartCheckShouldSpawnSpikes();
            break;

        case KRAID_PART_POSE_SPAWN_SPIKES:
            KraidPartSpawnSpike();
            break;

        case KRAID_PART_POSE_CHECK_PROJECTILES:
            KraidPartCallKraidCheckProjectilesCollidingWithBelly();
            break;

        case KRAID_PART_POSE_DYING_INIT:
            KraidPartDyingInit();
            break;

        case KRAID_PART_POSE_ARM_DYING:
            KraidPartDyingSinking();
            break;

        case KRAID_PART_POSE_DYING_STATIONNARY:
            KraidPartDyingStationary();
    }

    if (gCurrentSprite.spriteId != SSPRITE_KRAID_PART)
        return;

    // Check update hitbox
    if (gCurrentSprite.roomSlot == KRAID_PART_RIGHT_ARM)
    {
        if (gCurrentSprite.pOam == sKraidPartOam_RightArmIdle)
            KraidPartUpdateRightArmIdlingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOam_RightArmAttacking)
            KraidPartUpdateRightArmAttackingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOam_2cadc4)
            KraidPartHitboxChange_1Unused();
        else
            gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    }
    else if (gCurrentSprite.roomSlot == KRAID_PART_LEFT_ARM)
    {
        if (gCurrentSprite.pOam == sKraidPartOam_LeftArmIdle)
            KraidPartUpdateLeftArmIdlingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOam_LeftArmDying)
            KraidPartUpdateLeftArmDyingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOam_LeftArmThrowingNails)
            KraidPartUpdateLeftArmAttackingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOam_2cac5c)
            KraidPartHitboxChange_2Unused();
        else
            gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    }
    else
    {
        KraidSyncSubSprites();
        if (gSubSpriteData1.work1 != 0 && (gCurrentSprite.roomSlot == KRAID_PART_LEFT_FEET || gCurrentSprite.roomSlot == KRAID_PART_RIGHT_FEET))
        {
            if (gCurrentSprite.animationDurationCounter < CONVERT_SECONDS(.2f))
                gCurrentSprite.animationDurationCounter += CONVERT_SECONDS(1.f / 15);
        }

    }
}

/**
 * @brief 1b048 | 4ac | Kraid spike AI
 * 
 */
void KraidSpike(void)
{
    u8 ramSlot;
    u16 xPosition;
    u16 yPosition;
    u16 caf;
    u16 timer;
    u8 mainPalette;
    u8 palette;

    if (gSubSpriteData1.health == 0)
        gCurrentSprite.pose = SPRITE_POSE_DESTROYED;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    palette = gCurrentSprite.absolutePaletteRow;
    mainPalette = gSpriteData[ramSlot].absolutePaletteRow;
    if (gCurrentSprite.absolutePaletteRow != mainPalette)
    {
        gCurrentSprite.absolutePaletteRow = mainPalette;
        if (gCurrentSprite.paletteRow == 0)
            gCurrentSprite.paletteRow = mainPalette;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.pose = KRAID_SPIKE_POSE_DELAY_BEFORE_MOVING;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            gCurrentSprite.drawDistanceTop = QUARTER_BLOCK_SIZE;
            gCurrentSprite.drawDistanceBottom = QUARTER_BLOCK_SIZE;
            gCurrentSprite.drawDistanceHorizontal = THREE_QUARTER_BLOCK_SIZE;

            gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = EIGHTH_BLOCK_SIZE;

            gCurrentSprite.drawOrder = 12;
            gCurrentSprite.pOam = sKraidSpikeOam;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.work0 = ONE_THIRD_SECOND;
            SoundPlay(SOUND_KRAID_SPIKE_SPAWNING);
            
        case KRAID_SPIKE_POSE_DELAY_BEFORE_MOVING:
            caf = gCurrentSprite.currentAnimationFrame;
            if (caf <= 4)
            {
                if (caf == 1)
                    gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;
                else if (caf == 2)
                    gCurrentSprite.hitboxRight = BLOCK_SIZE;
                else if (caf == 3)
                    gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE;
                else if (caf == 4)
                    gCurrentSprite.hitboxRight = BLOCK_SIZE * 2;
            }
            else
            {
                gCurrentSprite.samusCollision = SSC_HURTS_RIGHT_CAN_STAND_ON_TOP;
                gCurrentSprite.hitboxLeft = QUARTER_BLOCK_SIZE;
                gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
                if (gCurrentSprite.work0 != 0)
                {
                    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
                }
                else
                {
                    gCurrentSprite.pose = KRAID_SPIKE_POSE_MOVING;
                    gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 15);
                    SoundPlay(SOUND_KRAID_SPIKE_EMERGING);
                }
            }

            gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
            gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;
            break;

        case KRAID_SPIKE_POSE_MOVING:
            if (gCurrentSprite.work0 != 0)
            {
                APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
                if (gCurrentSprite.work0 == 0)
                    gCurrentSprite.drawOrder = 4;
            }

            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP &&
                SpriteUtilGetCollisionAtPosition(gSamusData.yPosition - HALF_BLOCK_SIZE, gSamusData.xPosition + HALF_BLOCK_SIZE) == COLLISION_AIR)
            {
                gSamusData.xPosition += EIGHTH_BLOCK_SIZE;
            }

            gCurrentSprite.xPosition += EIGHTH_BLOCK_SIZE;
            yPosition = gCurrentSprite.yPosition;
            xPosition = gCurrentSprite.xPosition + BLOCK_SIZE * 2;

            if (gCurrentSprite.roomSlot == KRAID_PART_TOP_HOLE_LEFT)
                yPosition -= HALF_BLOCK_SIZE;

            if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition) != COLLISION_AIR)
            {
                if (xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 13)
                {
                    gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                    ClipdataProcess(yPosition, xPosition);

                    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);

                    SpriteDebrisInit(0, 0x11, yPosition - (HALF_BLOCK_SIZE - PIXEL_SIZE - PIXEL_SIZE / 2) - gSpriteRng, xPosition);
                    SpriteDebrisInit(0, 0x12, yPosition - QUARTER_BLOCK_SIZE,
                        xPosition + EIGHTH_BLOCK_SIZE + gSpriteRng);
                    SpriteDebrisInit(0, 0x13, yPosition - BLOCK_SIZE - gSpriteRng,
                        xPosition + QUARTER_BLOCK_SIZE);
                    SpriteDebrisInit(0, 0x4, yPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2),
                        xPosition - (HALF_BLOCK_SIZE - PIXEL_SIZE) - gSpriteRng);

                    if (gCurrentSprite.roomSlot == KRAID_PART_TOP_HOLE_LEFT)
                    {
                        if (!(gSubSpriteData1.work3 & DESTROYED_BLOCK_STATUS_TOP))
                        {
                            gSubSpriteData1.work3 |= DESTROYED_BLOCK_STATUS_TOP;
                            SoundPlay(SOUND_KRAID_SPIKE_DESTROYING_PLATFORM);
                        }
                    }
                    else if (gCurrentSprite.roomSlot == KRAID_PART_MIDDLE_HOLE_LEFT)
                    {
                        if (!(gSubSpriteData1.work3 & DESTROYED_BLOCK_STATUS_MIDDLE))
                        {
                            gSubSpriteData1.work3 |= DESTROYED_BLOCK_STATUS_MIDDLE;
                            SoundPlay(SOUND_KRAID_SPIKE_DESTROYING_BLOCKS);
                        }

                        gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                        ClipdataProcess(yPosition - BLOCK_SIZE, xPosition);
                        gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                        ClipdataProcess(yPosition - BLOCK_SIZE * 2, xPosition);

                        ParticleSet(yPosition - BLOCK_SIZE * 2, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
                    }
                    else if (gCurrentSprite.roomSlot == KRAID_PART_BOTTOM_HOLE_LEFT)
                    {
                        if (!(gSubSpriteData1.work3 & DESTROYED_BLOCK_STATUS_BOTTOM))
                        {
                            gSubSpriteData1.work3 |= DESTROYED_BLOCK_STATUS_BOTTOM;
                            SoundPlay(SOUND_KRAID_SPIKE_DESTROYING_BLOCKS);
                        }

                        gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                        ClipdataProcess(yPosition - BLOCK_SIZE, xPosition);
                        gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                        ClipdataProcess(yPosition + BLOCK_SIZE, xPosition);
    
                        ParticleSet(yPosition + BLOCK_SIZE, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
                    }
                }
                else
                {
                    if (gCurrentSprite.roomSlot == KRAID_PART_TOP_HOLE_LEFT)
                    {
                        yPosition += HALF_BLOCK_SIZE;
                    }
                    else if (gCurrentSprite.roomSlot == KRAID_PART_MIDDLE_HOLE_LEFT)
                    {
                        if (SpriteUtilGetCollisionAtPosition(yPosition - BLOCK_SIZE * 3, xPosition - HALF_BLOCK_SIZE) != COLLISION_AIR)
                        {
                            gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                            ClipdataProcess(yPosition - BLOCK_SIZE * 3, xPosition - HALF_BLOCK_SIZE);
                            ParticleSet(yPosition - BLOCK_SIZE * 3, xPosition - HALF_BLOCK_SIZE, PE_SPRITE_EXPLOSION_MEDIUM);
                        }

                        if (SpriteUtilGetCollisionAtPosition(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 2 + HALF_BLOCK_SIZE) != COLLISION_AIR)
                        {
                            gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                            ClipdataProcess(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                            ParticleSet(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 2 + HALF_BLOCK_SIZE, PE_SPRITE_EXPLOSION_MEDIUM);
                        }

                        if (SpriteUtilGetCollisionAtPosition(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 3 + HALF_BLOCK_SIZE) != COLLISION_AIR)
                        {
                            gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                            ClipdataProcess(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
                            ParticleSet(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 3 + HALF_BLOCK_SIZE, PE_SPRITE_EXPLOSION_MEDIUM);
                        }
                    }

                    SpriteDebrisInit(0, 0x11, yPosition - gSpriteRng, xPosition + QUARTER_BLOCK_SIZE);
                    SpriteDebrisInit(0, 0x12, yPosition + QUARTER_BLOCK_SIZE, xPosition + gSpriteRng * PIXEL_SIZE / 2);
                    SpriteDebrisInit(0, 0x13, yPosition + gSpriteRng, xPosition - QUARTER_BLOCK_SIZE);
                    SpriteDebrisInit(0, 0x4, yPosition - QUARTER_BLOCK_SIZE, xPosition - gSpriteRng * PIXEL_SIZE / 2);
                    gCurrentSprite.yPositionSpawn = CONVERT_SECONDS(6.f);
                    gCurrentSprite.pose = KRAID_SPIKE_POSE_IN_WALL;
                    gCurrentSprite.drawOrder = 4;
                    SoundPlay(SOUND_KRAID_SPIKE_HITTING_WALL);
                }
            }
            break;

        case KRAID_SPIKE_POSE_IN_WALL:
            timer = APPLY_DELTA_TIME_DEC(gCurrentSprite.yPositionSpawn);
            if (timer <= CONVERT_SECONDS(1.f) && MOD_AND(timer, 4) == 0)
            {
                if (MOD_BLOCK_AND(timer, 4))
                {
                    gCurrentSprite.paletteRow = SPRITE_GET_STUN_PALETTE(gCurrentSprite);
                }
                else
                {
                    gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
                    if (timer == 0)
                        gCurrentSprite.pose = SPRITE_POSE_DESTROYED;
                }
            }
            break;

        default:
            if (gCurrentSprite.standingOnSprite != SAMUS_STANDING_ON_SPRITE_OFF && gSamusData.standingStatus == STANDING_ENEMY)
                gSamusData.standingStatus = STANDING_MIDAIR;

            gCurrentSprite.status = 0;
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition + BLOCK_SIZE + QUARTER_BLOCK_SIZE, PE_SPRITE_EXPLOSION_HUGE);
            SoundPlay(SOUND_138);
            break;
    }
}

/**
 * @brief 1b4f4 | 1c4 | Kraid nail AI
 * 
 */
void KraidNail(void)
{
    u16 dstY;
    u16 dstX;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.pose = KRAID_NAIL_POSE_MOVING;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE - PIXEL_SIZE);
            gCurrentSprite.hitboxBottom = (HALF_BLOCK_SIZE - PIXEL_SIZE);
            gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE - PIXEL_SIZE);
            gCurrentSprite.hitboxRight = (HALF_BLOCK_SIZE - PIXEL_SIZE);

            gCurrentSprite.pOam = sKraidNailOam;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.bgPriority = BGCNT_HIGH_MID_PRIORITY;
            gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING_SINGLE;
            gCurrentSprite.scaling = Q_8_8(1.f);
            gCurrentSprite.work1 = 0;

            #ifdef REGION_US_BETA
            gCurrentSprite.work3 = SUB_PIXEL_TO_BLOCK_(gCurrentSprite.yPosition - HALF_BLOCK_SIZE);
            gCurrentSprite.work2 = SUB_PIXEL_TO_BLOCK_(gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
            #else // !REGION_US_BETA
            gCurrentSprite.work3 = SUB_PIXEL_TO_BLOCK(gCurrentSprite.yPosition);
            gCurrentSprite.work2 = SUB_PIXEL_TO_BLOCK(gCurrentSprite.xPosition);
            #endif // REGION_US_BETA

            if (gCurrentSprite.roomSlot != 0)
            {
                dstY = gSamusData.yPosition;
                gCurrentSprite.rotation = BLOCK_SIZE;
            }
            else
            {
                dstY = gSamusData.yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                gCurrentSprite.rotation = 0;
            }

            dstX = gSamusData.xPosition;

            #ifdef REGION_US_BETA
            if (dstY < gCurrentSprite.yPosition)
            {
                if (gCurrentSprite.yPosition - dstY < HALF_BLOCK_SIZE)
                    dstY = gSamusData.yPosition - HALF_BLOCK_SIZE;
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            }
            else
            {
                if (dstY - gCurrentSprite.yPosition < HALF_BLOCK_SIZE)
                    dstY = gSamusData.yPosition + HALF_BLOCK_SIZE;
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            }
            #else // !REGION_US_BETA
            if (dstY < BLOCK_TO_SUB_PIXEL(gCurrentSprite.work3))
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            else
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            #endif // REGION_US_BETA

            if (dstX < gCurrentSprite.xPosition)
                dstX = gSamusData.xPosition + BLOCK_SIZE;

            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.yPositionSpawn = dstY;
            gCurrentSprite.xPositionSpawn = dstX;

        case KRAID_NAIL_POSE_MOVING:
            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
            {
                ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SMALL);
                if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlay(SOUND_SPRITE_EXPLOSION_SMALL);
                gCurrentSprite.status = 0;
            }
            else
            {
                if (gDifficulty == DIFF_HARD)
                {
                    if (gCurrentSprite.roomSlot != KRAID_NAIL_TYPE_SLOW_ROTATION)
                        gCurrentSprite.rotation += (u32)(PI * .15625f);
                    else
                        gCurrentSprite.rotation += (u32)(PI * .171875f);
                }
                else
                {
                    if (gCurrentSprite.roomSlot != KRAID_NAIL_TYPE_SLOW_ROTATION)
                        gCurrentSprite.rotation += (u32)(PI * .09375f);
                    else
                        gCurrentSprite.rotation += (u32)(PI * .109375);
                }

                if (gCurrentSprite.health == 0)
                    gCurrentSprite.pose = SPRITE_POSE_STOPPED;
                else
                    KraidNailMovement();
            }
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}
