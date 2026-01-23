#include "sprites_ai/mother_brain.h"
#include "macros.h"
#include "gba/display.h"

#include "data/sprites/mother_brain.h"
#include "data/sprites/zebetite_and_cannon.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/in_game_cutscene.h"
#include "constants/particle.h"
#include "constants/projectile.h"
#include "constants/sprite.h"
#include "constants/text.h"

#include "structs/clipdata.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/in_game_timer.h"
#include "structs/samus.h"
#include "structs/scroll.h"
#include "structs/sprite.h"

#define MOTHER_BRAIN_POSE_WAITING_GLASS 0x1
#define MOTHER_BRAIN_POSE_MAIN_LOOP 0x9
#define MOTHER_BRAIN_POSE_DYING 0x67
#define MOTHER_BRAIN_POSE_START_ESCAPE 0x68


#define MOTHER_BRAIN_PART_POSE_IDLE 0x8
#define MOTHER_BRAIN_PART_POSE_SPAWN_BLOCK 0xE
#define MOTHER_BRAIN_PART_POSE_GLASS_STAGE_1 0xF
#define MOTHER_BRAIN_PART_POSE_GLASS_STAGE_2 0x11
#define MOTHER_BRAIN_PART_POSE_GLASS_STAGE_3 0x13
#define MOTHER_BRAIN_PART_POSE_GLASS_BROKEN 0x15
#define MOTHER_BRAIN_PART_POSE_UPDATE 0x32
#define MOTHER_BRAIN_PART_POSE_GLASS_BREAKING 0x62

#define MOTHER_BRAIN_BEAM_POSE_MOVING 0x9
#define MOTHER_BRAIN_BLOCK_POSE_IDLE 0x9
#define MOTHER_BRAIN_GLASS_BREAKING_POSE_BREAKING 0x9

enum MotherBrainFightStage {
    MB_FIGHT_STAGE_IN_GLASS,
    MB_FIGHT_STAGE_ACTIVE,
    MB_FIGHT_STAGE_DYING,
    MB_FIGHT_STAGE_DEAD,
};

// Damage threshold at which mother closes her eye
#define MOTHER_BRAIN_DAMAGE_THRESHOLD (SUPER_MISSILE_DAMAGE)

static const struct FrameData* sMotherBrainFrameDataPointers[MOTHER_BRAIN_OAM_END] = {
    [MOTHER_BRAIN_OAM_IDLE] = sMotherBrainOam_Idle,
    [MOTHER_BRAIN_OAM_CHARGING_BEAM] = sMotherBrainOam_ChargingBeam,
    [MOTHER_BRAIN_OAM_EYE_CLOSED] = sMotherBrainPartOam_EyeClosed,
    [MOTHER_BRAIN_OAM_2fa934] = sMotherBrainPartOam_2fa934,
    [MOTHER_BRAIN_OAM_EYE_OPENING] = sMotherBrainPartOam_EyeOpening,
    [MOTHER_BRAIN_OAM_2fa984] = sMotherBrainPartOam_2fa984,
    [MOTHER_BRAIN_OAM_EYE_DYING] = sMotherBrainPartOam_EyeDying,
    [MOTHER_BRAIN_OAM_BOTTOM] = sMotherBrainPartOam_Bottom,
    [MOTHER_BRAIN_OAM_BEAM_SPAWNING] = sMotherBrainPartOam_BeamSpawning,
    [MOTHER_BRAIN_OAM_BEAM_MOVING] = sMotherBrainBeamOam_Moving
};

/**
 * @brief 3c964 | 68 | Synchronize the sub sprites of Mother Brain
 * 
 */
static void MotherBrainSyncSubSpritesPosition(void)
{
    MultiSpriteDataInfo_T pData;
    u16 oamIdx;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];

    if (gCurrentSprite.pOam != sMotherBrainFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sMotherBrainFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

/**
 * @brief 3c9cc | 80 | Updates the palette of mother brain when firing
 * 
 */
static void MotherBrainUpdatePalette(void)
{
    u8 timer;
    u8 offset;
    u8 newTimer;

    if (gCurrentSprite.scaling != 0)
    {
        gCurrentSprite.scaling--;
        gCurrentSprite.paletteRow = sMotherBrainDynamicPaletteData[gCurrentSprite.rotation][0];
    }
    else
    {
        offset = gCurrentSprite.rotation++;
        timer = sMotherBrainDynamicPaletteData[offset][0];
        if (timer == SCHAR_MAX + 1)
        {
            gCurrentSprite.rotation = 1;
            offset = 0;
            timer = sMotherBrainDynamicPaletteData[offset][0];
        }

        newTimer = sMotherBrainDynamicPaletteData[offset][1];
        if (offset == 0 || offset == 6)
            SoundPlay(SOUND_MOTHER_BRAIN_CHARGING);

        gCurrentSprite.paletteRow = timer;
        gCurrentSprite.scaling = newTimer;
    }
}

/**
 * @brief 3ca4c | 144 | Initializes mother brain
 * 
 */
static void MotherBrainInit(void)
{
    u8 gfxSlot;
    u8 ramSlot;
    u16 yPosition;
    u16 xPosition;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ESCAPED_ZEBES) ||
        EventFunction(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
    {
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

    yPosition = gSubSpriteData1.yPosition;
    xPosition = gSubSpriteData1.xPosition;
    gBossWork.work1 = yPosition;
    gBossWork.work2 = xPosition;
    gBossWork.work3 = 0;
    gBossWork.work4 = 0;
    gBossWork.work5 = 0;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);

    gCurrentSprite.hitboxTop = -(BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE);
    gCurrentSprite.hitboxBottom = BLOCK_SIZE + HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = BLOCK_SIZE * 2;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.work0 = 0;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.scaling = 0;
    gCurrentSprite.rotation = 0;
    gCurrentSprite.work2 = 0;
    
    gSubSpriteData1.pMultiOam = sMotherBrainMultiSpriteData;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gSubSpriteData1.work3 = MB_FIGHT_STAGE_IN_GLASS;

    gCurrentSprite.pose = MOTHER_BRAIN_POSE_WAITING_GLASS;
    gCurrentSprite.roomSlot = MOTHER_BRAIN_PART_BODY;

    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    gSubSpriteData1.work4 = SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_PART, MOTHER_BRAIN_PART_BEAM_SHOOTER,
        gfxSlot, ramSlot, yPosition, xPosition, 0);

    gSubSpriteData1.work5 = SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_PART, MOTHER_BRAIN_PART_EYE,
        gfxSlot, ramSlot, yPosition, xPosition, 0);

    gSubSpriteData1.work6 = SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_PART, MOTHER_BRAIN_PART_BOTTOM,
        gfxSlot, ramSlot, yPosition, xPosition, 0);
}

/**
 * @brief 3cb90 | 6c | Checks if the glass broke, starts battle behaviors
 * 
 */
static void MotherBrainCheckGlassBroke(void)
{
    u8 eyeSlot;

    eyeSlot = gSubSpriteData1.work5;
    if (gSubSpriteData1.work3 == MB_FIGHT_STAGE_ACTIVE)
    {
        gCurrentSprite.pose = MOTHER_BRAIN_POSE_MAIN_LOOP;
        gSpriteData[eyeSlot].health = gCurrentSprite.health;
        gBossWork.work4 = gCurrentSprite.health;

        // Open eye
        gSpriteData[eyeSlot].pOam = sMotherBrainPartOam_EyeOpening;
        gSpriteData[eyeSlot].animationDurationCounter = 0;
        gSpriteData[eyeSlot].currentAnimationFrame = 0;
        SoundPlay(SOUND_MOTHER_BRAIN_EYE_OPENING);
    }
}

/**
 * @brief 3cbfc | 3fc | Mother brain main behavior loop
 * 
 */
static void MotherBrainMainLoop(void)
{
    u8 palette;
    u8 beamShooterSlot;
    u8 eyeSlot;
    u8 bottomSlot;
    u32 counter;

    beamShooterSlot = gSubSpriteData1.work4;
    eyeSlot = gSubSpriteData1.work5;
    bottomSlot = gSubSpriteData1.work6;

    palette = gSpriteData[eyeSlot].paletteRow;
    
    gCurrentSprite.paletteRow = palette;
    gSpriteData[bottomSlot].paletteRow = palette;

    if (gSpriteData[eyeSlot].health == 0)
    {
        // Set dying behavior
        gCurrentSprite.pose = MOTHER_BRAIN_POSE_DYING;
        gCurrentSprite.pOam = sMotherBrainOam_ChargingBeam;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.invincibilityStunFlashTimer = CONVERT_SECONDS(2.f);
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.health = 1;
        gCurrentSprite.paletteRow = 0;

        gSpriteData[eyeSlot].paletteRow = 0;
        gSpriteData[bottomSlot].paletteRow = 0;
               
        gSpriteData[eyeSlot].pOam = sMotherBrainPartOam_EyeDying;
        gSpriteData[eyeSlot].animationDurationCounter = 0;
        gSpriteData[eyeSlot].currentAnimationFrame = 0;
        gSpriteData[eyeSlot].samusCollision = SSC_NONE;

        gSpriteData[beamShooterSlot].status = 0;
        gSubSpriteData1.work3 = MB_FIGHT_STAGE_DYING;

        // Set event
        EventFunction(EVENT_ACTION_SETTING, EVENT_MOTHER_BRAIN_KILLED);
        SoundPlay(SOUND_MOTHER_BRAIN_DYING);
        return;
    }

    if (gCurrentSprite.pOam == sMotherBrainOam_ChargingBeam)
    {
        // Delay before charging
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.pOam = sMotherBrainOam_Idle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
    else
    {
        if (gCurrentSprite.currentAnimationFrame == 1 && gCurrentSprite.animationDurationCounter == 1)
            SoundPlay(SOUND_MOTHER_BRAIN_IDLE);

        if (SPRITE_GET_ISFT(gSpriteData[eyeSlot]) == 0x10)
        {
            SoundPlay(SOUND_MOTHER_BRAIN_DAMAGED);
            if (gSpriteData[eyeSlot].health < gBossWork.work4)
            {
                // Damage dealt, check should close eye
                // Add damage to counter
                gBossWork.work5 += (gBossWork.work4 - gSpriteData[eyeSlot].health);
                gBossWork.work4 = gSpriteData[eyeSlot].health;

                // Get counter threshold
                if (gDifficulty == DIFF_EASY)
                    counter = MOTHER_BRAIN_DAMAGE_THRESHOLD * 2;
                else if (gDifficulty == DIFF_HARD)
                    counter = MOTHER_BRAIN_DAMAGE_THRESHOLD * .6;
                else
                    counter = MOTHER_BRAIN_DAMAGE_THRESHOLD;

                if (gBossWork.work5 >= counter)
                {
                    // Set closing behavior
                    gBossWork.work5 = 0;
                    gSpriteData[eyeSlot].pOam = sMotherBrainPartOam_EyeClosing;
                    gSpriteData[eyeSlot].animationDurationCounter = 0;
                    gSpriteData[eyeSlot].currentAnimationFrame = 0;
                    gSpriteData[eyeSlot].properties |= SP_IMMUNE_TO_PROJECTILES;
                    SoundPlay(SOUND_MOTHER_BRAIN_EYE_CLOSING);
                    gCurrentSprite.work2 = DELTA_TIME;
                }
            }
        }
    }

    if (gSpriteData[eyeSlot].pOam == sMotherBrainPartOam_EyeClosing)
    {
        // Check should close
        if (SpriteUtilHasAnimationEnded(eyeSlot))
        {
            gSpriteData[eyeSlot].pOam = sMotherBrainPartOam_EyeClosed;
            gSpriteData[eyeSlot].animationDurationCounter = 0;
            gSpriteData[eyeSlot].currentAnimationFrame = 0;
        }
    }
    else if (gSpriteData[eyeSlot].pOam == sMotherBrainPartOam_EyeClosed)
    {
        // Check should start charging beam
        if (gSubSpriteData1.yPosition + BLOCK_SIZE * 2 >= gSamusData.yPosition)
        {
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work2);
            if (gCurrentSprite.work2 == 0)
            {
                // Set charging beam behavior
                gCurrentSprite.pOam = sMotherBrainOam_ChargingBeam;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                gCurrentSprite.work1 = CONVERT_SECONDS(1.2f);
                gCurrentSprite.work0 = CONVERT_SECONDS(1.2f);
                gCurrentSprite.scaling = 0;
                gCurrentSprite.rotation = 0;
            }
        }
    }
    else if (gSpriteData[eyeSlot].pOam == sMotherBrainPartOam_EyeOpening)
    {
        if (gCurrentSprite.work1 == 0)
        {
            // Check should close eye
            if (gSubSpriteData1.yPosition + (BLOCK_SIZE * 2) < gSamusData.yPosition)
            {
                // Samus fell below the blocks, set closing behavior
                gSpriteData[eyeSlot].pOam = sMotherBrainPartOam_EyeClosing;
                gSpriteData[eyeSlot].animationDurationCounter = 0;
                gSpriteData[eyeSlot].currentAnimationFrame = 0;
                gSpriteData[eyeSlot].properties |= SP_IMMUNE_TO_PROJECTILES;
                SoundPlay(SOUND_MOTHER_BRAIN_EYE_CLOSING);
                gCurrentSprite.work2 = CONVERT_SECONDS(1.f);
            }
            return;
        }
    }

    if (gCurrentSprite.work1 == 0)
        return;
   
    // Shooting beam
    if (APPLY_DELTA_TIME_DEC(gCurrentSprite.work1) == 0)
    {
        if (palette != 0xE)
        {
            // Set normal palette
            gCurrentSprite.paletteRow = 0;
            gSpriteData[eyeSlot].paletteRow = 0;
            gSpriteData[bottomSlot].paletteRow = 0;
        }
    }
    else
    {
        if (gCurrentSprite.work1 == CONVERT_SECONDS(.2f))
        {
            // Spawn beam
            SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_BEAM, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gSpriteData[beamShooterSlot].yPosition,
                gSpriteData[beamShooterSlot].xPosition + BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE - PIXEL_SIZE, 0);

            // Hide beam shooter
            gSpriteData[beamShooterSlot].status |= SPRITE_STATUS_NOT_DRAWN;
        }
        else if (gCurrentSprite.work1 == ONE_THIRD_SECOND)
        {
            // Open eye
            gSpriteData[eyeSlot].pOam = sMotherBrainPartOam_EyeOpening;
            gSpriteData[eyeSlot].animationDurationCounter = 0;
            gSpriteData[eyeSlot].currentAnimationFrame = 0;

            // Make eye vulnerable
            gSpriteData[eyeSlot].properties &= ~SP_IMMUNE_TO_PROJECTILES;
            SoundPlay(SOUND_MOTHER_BRAIN_EYE_OPENING);
        }
        else if (gCurrentSprite.work1 == CONVERT_SECONDS(.4f))
        {
            // Set beam shooter behavior
            gSpriteData[beamShooterSlot].pOam = sMotherBrainPartOam_BeamSpawning;
            gSpriteData[beamShooterSlot].animationDurationCounter = 0;
            gSpriteData[beamShooterSlot].currentAnimationFrame = 0;
            gSpriteData[beamShooterSlot].status &= ~SPRITE_STATUS_NOT_DRAWN;
            SoundPlay(SOUND_MOTHER_BRAIN_SHOOTING);
        }

        if (palette != 0xE)
        {
            // Update palette
            MotherBrainUpdatePalette();
            gSpriteData[eyeSlot].paletteRow = gCurrentSprite.paletteRow;
            gSpriteData[bottomSlot].paletteRow = gCurrentSprite.paletteRow;
        }
    }
}

/**
 * @brief 3cff8 | cc | Handles the death of mother brain
 * 
 */
static void MotherBrainDeath(void)
{
    u8 bottomSlot;
    u8 eyeSlot;

    eyeSlot = gSubSpriteData1.work5;
    bottomSlot = gSubSpriteData1.work6;

    if (gCurrentSprite.invincibilityStunFlashTimer != 0)
    {
        gSpriteData[eyeSlot].paletteRow = gCurrentSprite.paletteRow;
        gSpriteData[bottomSlot].paletteRow = gCurrentSprite.paletteRow;
        if (MOD_AND(gCurrentSprite.invincibilityStunFlashTimer, CONVERT_SECONDS(1.f + 1.f / 15)) == 0)
            MakeBackgroundFlash(BG_FLASH_QUICK_YELLOW);
    }
    else
    {
        gSpriteData[eyeSlot].status = 0;
        gSpriteData[bottomSlot].status = 0;
        gCurrentSprite.pose = MOTHER_BRAIN_POSE_START_ESCAPE;
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f);
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;

        ParticleSet(gSubSpriteData1.yPosition + (BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2),
            gSubSpriteData1.xPosition - (BLOCK_SIZE - PIXEL_SIZE), PE_MAIN_BOSS_DEATH);
        ParticleSet(gSubSpriteData1.yPosition + (BLOCK_SIZE - PIXEL_SIZE),
            gSubSpriteData1.xPosition + BLOCK_SIZE + QUARTER_BLOCK_SIZE, PE_MAIN_BOSS_DEATH);

            gInGameTimerAtBosses[1] = gInGameTimer;
        SoundPlay(SOUND_MOTHER_BRAIN_DEATH_EXPLOSION);
        MakeBackgroundFlash(BG_FLASH_QUICK_YELLOW);
    }
}

/**
 * @brief 3d0c4 | 6c | Starts the escape
 * 
 */
static void MotherBrainStartEscape(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        // Kill sprite
        gCurrentSprite.status = 0;
        // Spawn banner and effects
        SpriteSpawnPrimary(PSPRITE_MESSAGE_BANNER, MESSAGE_ZEBES_ESCAPE, 0, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
        SpriteSpawnPrimary(PSPRITE_EXPLOSION_ZEBES_ESCAPE, 0, 0, gCurrentSprite.yPosition + BLOCK_SIZE * 4, gCurrentSprite.xPosition, 0);
        PlayMusic(MUSIC_ESCAPE, 0x40);
        SoundPlay(SOUND_ESCAPE_BEEP);
        gSubSpriteData1.work3 = MB_FIGHT_STAGE_DEAD;
    }
}

/**
 * @brief 3d130 | 158 | Initializes a mother brain part sprite
 * 
 */
static void MotherBrainPartInit(void)
{
    u16 health;
    
    switch (gCurrentSprite.roomSlot)
    {
        case MOTHER_BRAIN_PART_BEAM_SHOOTER:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);

            gCurrentSprite.hitboxTop = -PIXEL_SIZE;
            gCurrentSprite.hitboxBottom = PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -PIXEL_SIZE,
            gCurrentSprite.hitboxRight = PIXEL_SIZE;

            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_UPDATE;

            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.health = 1;
            break;

        case MOTHER_BRAIN_PART_EYE:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = PIXEL_SIZE;
            
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.drawOrder = 5;
            gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_IDLE;
            break;

        case MOTHER_BRAIN_PART_BOTTOM:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + QUARTER_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 4 - EIGHTH_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -(BLOCK_SIZE * 2 + THREE_QUARTER_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + THREE_QUARTER_BLOCK_SIZE;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 6;
            gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_SPAWN_BLOCK;

            health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.health = health;
            gBossWork.work3 = health;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 3d288 | a4 | Updates the hitbox of the mother brain eye
 * 
 */
static void MotherBrainPartHitboxInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        return;
    }

    gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 1:
            gCurrentSprite.hitboxTop = -QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE;
            break;

        case 2:
            gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            break;

        case 3:
            gCurrentSprite.hitboxTop = -THREE_QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = THREE_QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            break;

        default:
            gCurrentSprite.hitboxTop = -EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
            gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;
    }
}

/**
 * @brief 3d32c | 4 | Empty function
 * 
 */
static void MotherBrainPart_Empty(void)
{
    return;
}

/**
 * @brief 3d330 | 74 | Spawns the mother brain block sprite if necessary
 * 
 */
static void MotherBrainSpawnBlock(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gSubSpriteData1.yPosition - (BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
    xPosition = gSubSpriteData1.xPosition + (BLOCK_SIZE * 11 + HALF_BLOCK_SIZE);

    if (gSamusData.xPosition < xPosition - (BLOCK_SIZE - PIXEL_SIZE))
    {
        #ifdef BUGFIX
        u8 blockSlot = SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_BLOCK, 0, SPRITE_GFX_SLOT_SPECIAL,
            gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, 0);
        if (blockSlot != UCHAR_MAX)
        {
            gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_STAGE_1;
            gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        }
        #else // !BUGFIX
        SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_BLOCK, 0, SPRITE_GFX_SLOT_SPECIAL,
            gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, 0);
        gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_STAGE_1;
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        #endif // BUGFIX
    }
}

/**
 * @brief 3d3a4 | 40 | First stage of the glass
 * 
 */
static void MotherBrainPartGlassStage1(void)
{
    gCurrentSprite.invincibilityStunFlashTimer = 0;
    // 3/4 of health
    if (gCurrentSprite.health <= DIV_SHIFT(gBossWork.work3 * 3, 4))
    {
        gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_STAGE_2;
        // Edit BG
        BgClipCallMotherBrainUpdateGlass(1);
        SoundPlay(SOUND_MOTHER_BRAIN_JAR_DAMAGE_1);
    }
}

/**
 * @brief 3d3e4 | 3c | Second stage of the glass
 * 
 */
static void MotherBrainPartGlassStage2(void)
{
    gCurrentSprite.invincibilityStunFlashTimer = 0;
    // 2/4 of health
    if (gCurrentSprite.health <= gBossWork.work3 / 2)
    {
        gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_STAGE_3;
        // Edit BG
        BgClipCallMotherBrainUpdateGlass(2);
        SoundPlay(SOUND_MOTHER_BRAIN_JAR_DAMAGE_2);
    }
}

/**
 * @brief 3d420 | 3c | Third stage of the glass
 * 
 */
static void MotherBrainPartGlassStage3(void)
{
    gCurrentSprite.invincibilityStunFlashTimer = 0;
    // 1/4 of health
    if (gCurrentSprite.health <= gBossWork.work3 / 4)
    {
        gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_BROKEN;
        // Edit BG
        BgClipCallMotherBrainUpdateGlass(3);
        SoundPlay(SOUND_MOTHER_BRAIN_JAR_DAMAGE_3);
    }
}

/**
 * @brief 3d45c | 10 | Sets the invincibility stun flash timer to 0
 * 
 */
static void MotherBrainPartGlassBroken(void)
{
    gCurrentSprite.invincibilityStunFlashTimer = 0;
}

/**
 * @brief 3d46c | 54 | Breaks the mother brain glass
 * 
 */
static void MotherBrainPartSpawnGlassBreaking(void)
{
    gCurrentSprite.invincibilityStunFlashTimer = 0;
    gCurrentSprite.pose = MOTHER_BRAIN_PART_POSE_GLASS_BROKEN;
    gSubSpriteData1.work3 = MB_FIGHT_STAGE_ACTIVE;

    // Spawn glass
    SpriteSpawnSecondary(SSPRITE_MOTHER_BRAIN_GLASS_BREAKING, 0, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);

    // Remove in BG
    BgClipCallMotherBrainUpdateGlass(4);
    SoundPlay(SOUND_MOTHER_BRAIN_JAR_SHATTER);
}

/**
 * @brief 3d4c0 | e0 | Mother brain AI
 * 
 */
void MotherBrain(void)
{
    u8 mbSize;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            MotherBrainInit();
            break;

        case MOTHER_BRAIN_POSE_WAITING_GLASS:
            MotherBrainCheckGlassBroke();
            break;

        case MOTHER_BRAIN_POSE_MAIN_LOOP:
            MotherBrainMainLoop();
            break;

        case MOTHER_BRAIN_POSE_DYING:
            MotherBrainDeath();
            break;

        case MOTHER_BRAIN_POSE_START_ESCAPE:
            MotherBrainStartEscape();
            break;
    }

    if (gCurrentSprite.pose < MOTHER_BRAIN_PART_POSE_IDLE)
    {
        SpriteUtilUpdateSubSprite1Anim();
        MotherBrainSyncSubSpritesPosition();
    }
    else
    {
        SpriteUtilUpdateSubSprite1Anim();
        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    }

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && gSubSpriteData1.work3 < MB_FIGHT_STAGE_DEAD
        && gSamusData.xPosition < gSubSpriteData1.xPosition + BLOCK_SIZE * 12)
    {
        // Lock the screen if 
        gLockScreen.lock = LOCK_SCREEN_TYPE_POSITION;
        gLockScreen.yPositionCenter = gBossWork.work1;
        gLockScreen.xPositionCenter = gSubSpriteData1.xPosition + BLOCK_SIZE * 5;

        // Mother brain has a bigger hitbox while in her glass
        if (gSubSpriteData1.work3 == MB_FIGHT_STAGE_IN_GLASS)
            mbSize = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE - PIXEL_SIZE;
        else
            mbSize = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;

        // Prevent samus from going through mother brain, since this only moves her position
        // and doesn't touch her velocity, it's possible to charge a speedboost by running against mother brain
        // while she is dying
        if (gSamusData.xPosition < gBossWork.work2 + mbSize)
            gSamusData.xPosition = gBossWork.work2 + mbSize;
    }
    else
    {
        gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;
    }
}

/**
 * @brief 3d5a0 | a0 | Mother brain part AI
 * 
 */
void MotherBrainPart(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            MotherBrainPartInit();
            MotherBrainSyncSubSpritesPosition();
            return;

        case MOTHER_BRAIN_PART_POSE_UPDATE:
            MotherBrainPartHitboxInit();
            break;

        case MOTHER_BRAIN_PART_POSE_IDLE:
            MotherBrainPart_Empty();
            break;

        case MOTHER_BRAIN_PART_POSE_SPAWN_BLOCK:
            MotherBrainSpawnBlock();
            break;

        case MOTHER_BRAIN_PART_POSE_GLASS_STAGE_1:
            MotherBrainPartGlassStage1();
            break;

        case MOTHER_BRAIN_PART_POSE_GLASS_STAGE_2:
            MotherBrainPartGlassStage2();
            break;

        case MOTHER_BRAIN_PART_POSE_GLASS_STAGE_3:
            MotherBrainPartGlassStage3();
            break;

        case MOTHER_BRAIN_PART_POSE_GLASS_BROKEN:
            MotherBrainPartGlassBroken();
            break;

        case MOTHER_BRAIN_PART_POSE_GLASS_BREAKING:
            if (gCurrentSprite.roomSlot == MOTHER_BRAIN_PART_BOTTOM)
                MotherBrainPartSpawnGlassBreaking();
            break;
    }

    if (gCurrentSprite.roomSlot == MOTHER_BRAIN_PART_BOTTOM)
        MotherBrainSyncSubSpritesPosition();
    else
        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
}

/**
 * @brief 3d640 | e4 | Mother brain beam AI
 * 
 */
void MotherBrainBeam(void)
{
    if (gSubSpriteData1.work3 >= MB_FIGHT_STAGE_DYING)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.properties |= SP_KILL_OFF_SCREEN | SP_IMMUNE_TO_PROJECTILES;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);

            gCurrentSprite.hitboxTop = -THREE_QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = THREE_QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

            gCurrentSprite.pOam = sMotherBrainBeamOam_Moving;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = MOTHER_BRAIN_BEAM_POSE_MOVING;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_IGNORE_INVINCIBILITY;
            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.bgPriority = BGCNT_GET_PRIORITY(gIoRegistersBackup.BG1CNT);
            gCurrentSprite.health = 1;
            gCurrentSprite.work0 = 16;

        case MOTHER_BRAIN_BEAM_POSE_MOVING:
            gCurrentSprite.xPosition += QUARTER_BLOCK_SIZE - PIXEL_SIZE;
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck != COLLISION_AIR)
            {
                ParticleSet(gCurrentSprite.yPosition + (HALF_BLOCK_SIZE - PIXEL_SIZE),
                    gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_BIG);
                gCurrentSprite.status = 0;
                SoundPlay(SOUND_MOTHER_BRAIN_LASER_EXPLODING);
            }
    }
}

/**
 * @brief 3d724 | a8 | Mother brain block AI
 * 
 */
void MotherBrainBlock(void)
{
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

        gCurrentSprite.pOam = sMotherBrainBlockOam;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        
        gCurrentSprite.pose = MOTHER_BRAIN_BLOCK_POSE_IDLE;
        gCurrentSprite.samusCollision = SSC_CHECK_COLLIDING;
    }
    else if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        }
        else
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            
            gCurrentClipdataAffectingAction = CAA_MAKE_NON_POWER_GRIP;
            ClipdataProcess(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        }
    }
}

/**
 * @brief 3d7cc | 94 | Mother brain glass breaking AI
 * 
 */
void MotherBrainGlassBreaking(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.pOam = sMotherBrainGlassBreakingOam_Breaking;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = MOTHER_BRAIN_GLASS_BREAKING_POSE_BREAKING;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.bgPriority = BGCNT_GET_PRIORITY(gIoRegistersBackup.BG1CNT);
            break;

        case MOTHER_BRAIN_GLASS_BREAKING_POSE_BREAKING:
            if (SpriteUtilHasCurrentAnimationEnded())
                gCurrentSprite.status = 0;
    }
}