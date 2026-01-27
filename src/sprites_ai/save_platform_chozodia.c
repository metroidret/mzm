#include "sprites_ai/save_platform_chozodia.h"
#include "sprites_ai/message_banner.h"
#include "gba.h"

#include "data/sprites/save_platform_chozodia.h"

#include "constants/audio.h"
#include "constants/escape.h"
#include "constants/sprite.h"
#include "constants/samus.h"
#include "constants/text.h"

#include "structs/game_state.h"
#include "structs/hud.h"
#include "structs/sprite.h"
#include "structs/samus.h"

#define SAVE_PLATFORM_CHOZODIA_POSE_IDLE 0x9
#define SAVE_PLATFORM_CHOZODIA_POSE_OPENING 0x23
#define SAVE_PLATFORM_CHOZODIA_POSE_OPENED 0x25
#define SAVE_PLATFORM_CHOZODIA_POSE_CLOSING 0x27
#define SAVE_PLATFORM_CHOZODIA_POSE_RELEASE_SAMUS 0x28
#define SAVE_PLATFORM_CHOZODIA_POSE_AFTER_SAVE 0x29
#define SAVE_PLATFORM_CHOZODIA_POSE_SAVE_PROMPT 0x42
#define SAVE_PLATFORM_CHOZODIA_POSE_SAVING 0x43
#define SAVE_PLATFORM_CHOZODIA_POSE_OPENED_OFF_INIT 0x45
#define SAVE_PLATFORM_CHOZODIA_POSE_SPAWN_SAVE_DONE_MESSAGE 0x47
#define SAVE_PLATFORM_CHOZODIA_POSE_WAIT_FOR_MESSAGE_OUT 0x49
#define SAVE_PLATFORM_CHOZODIA_POSE_DELAY_BEFORE_RELEASING 0x4B
#define SAVE_PLATFORM_CHOZODIA_POSE_OFF 0x51
#define SAVE_PLATFORM_CHOZODIA_POSE_CHECK_REFILL 0x54
#define SAVE_PLATFORM_CHOZODIA_POSE_REFILL 0x55
#define SAVE_PLATFORM_CHOZODIA_POSE_AFTER_REFILL 0x56

// Save platform chozodia part

MAKE_ENUM(u8, SavePlatformChozodiaPartId) {
    SAVE_PLATFORM_CHOZODIA_PART_TUBE,
    SAVE_PLATFORM_CHOZODIA_PART_TUBE_SHADOW,
    SAVE_PLATFORM_CHOZODIA_PART_RAY,
    SAVE_PLATFORM_CHOZODIA_PART_TOP,
    SAVE_PLATFORM_CHOZODIA_PART_REFILL_LIGHT
};

#define SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_SPAWNING 0x9
#define SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_CHECK_SHADOW_DISAPPEARED 0x23
#define SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_IDLE 0x25
#define SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_DESPAWNING 0x27
#define SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_SHADOW_IDLE 0x29
#define SAVE_PLATFORM_CHOZODIA_PART_POSE_RAY_IDLE 0x2B
#define SAVE_PLATFORM_CHOZODIA_PART_POSE_REFILL_LIGHT_IDLE 0x33
#define SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_IDLE 0x43
#define SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_EXTENDING_INIT 0x44
#define SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_EXTENDING 0x45
#define SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_RETRACTING_INIT 0x46
#define SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_RETRACTING 0x47

/**
 * @brief 46708 | 168 | Initializes a save platform (Chozodia) sprite
 * 
 */
static void SavePlatformChozodiaInit(void)
{
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.yPositionSpawn = 0;
    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -PIXEL_SIZE;
    gCurrentSprite.hitboxBottom = PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
    gCurrentSprite.hitboxRight = PIXEL_SIZE;

    if (gAlarmTimer != 0)
        gCurrentSprite.work2 = TRUE;
    else
        gCurrentSprite.work2 = FALSE;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);

    if (gCurrentSprite.work2 || EscapeDetermineTimer() != ESCAPE_NONE)
    {
        gCurrentSprite.pOam = sSavePlatformChozodiaOam_OpenedOff;
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_OFF;
    }
    else if (gIsLoadingFile)
    {
        SpriteSpawnSecondary(SSPRITE_CHOZODIA_SAVE_PLATFORM_PART, SAVE_PLATFORM_CHOZODIA_PART_TUBE,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

        gCurrentSprite.pOam = sSavePlatformChozodiaOam_IdleOff;
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_RELEASE_SAMUS;
        gCurrentSprite.yPositionSpawn = CONVERT_SECONDS(5.f) + TWO_THIRD_SECOND;
    }
    else
    {
        gCurrentSprite.pOam = sSavePlatformChozodiaOam_Idle;
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_IDLE;
    }

    gCurrentSprite.work3 = SpriteSpawnSecondary(SSPRITE_CHOZODIA_SAVE_PLATFORM_PART, SAVE_PLATFORM_CHOZODIA_PART_TOP,
        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
        gCurrentSprite.yPosition - BLOCK_SIZE * 8, gCurrentSprite.xPosition, 0);

    if (gCurrentSprite.pose == SAVE_PLATFORM_CHOZODIA_POSE_OFF)
    {
        gCurrentSprite.paletteRow = 3;
        gSpriteData[gCurrentSprite.work3].paletteRow = 3;
    }

    TransparencyUpdateBldcnt(0x1, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
        BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL |
        BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL);
    
    TransparencySpriteUpdateBldalpha(0, BLDALPHA_MAX_VALUE, 0, BLDALPHA_MAX_VALUE);
}

/**
 * @brief 46870 | 58 | Handles a save platform (Chozodia) being idle
 * 
 */
static void SavePlatformChozodiaSamusDetection(void)
{
    if (SavePlatformDetectSamus() && !SpriteUtilCheckCrouchingOrMorphed())
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_OPENING;
            gCurrentSprite.pOam = sSavePlatformChozodiaOam_Opening;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            SoundPlay(SOUND_CHOZODIA_SAVE_PLATFORM_OPENING);
        }
    }
    else
    {
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);
    }
}

/**
 * @brief 468c8 | 2c | Handles a save platform opening
 * 
 */
static void SavePlatformChozodiaCheckOpeningAnimEnded(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_OPENED;
        gCurrentSprite.pOam = sSavePlatformChozodiaOam_Opened;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 468f4 | 78 | Handles a save platform (Chozodia) being opened
 * 
 */
static void SavePlatformChozodiaSecondSamusDetection(void)
{
    if (SavePlatformDetectSamus())
    {
        if (!SpriteUtilCheckCrouchingOrMorphed())
        {
            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_CHECK_REFILL;
            gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 15);
            gSamusData.xPosition = gCurrentSprite.xPosition;

            if (gSamusData.invincibilityTimer != 0)
                gSamusData.invincibilityTimer = 0;

            SamusSetPose(SPOSE_TURNING_FROM_FACING_THE_FOREGROUND);
            gSamusData.timer = TRUE;
            gDisablePause = TRUE;
        }
    }
    else
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_CLOSING;
        gCurrentSprite.pOam = sSavePlatformChozodiaOam_Closing;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        SoundPlay(SOUND_CHOZODIA_SAVE_PLATFORM_CLOSING);
    }
}

/**
 * @brief 4696c | 30 | Handles a save platform (Chozodia) closing
 * 
 */
static void SavePlatformChozodiaCheckClosingAnimEnded(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_IDLE;
        gCurrentSprite.pOam = sSavePlatformChozodiaOam_Idle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);
    }
}

/**
 * @brief 4699c | 34 | Handles a save platform (Chozodia) releasing Samus
 * 
 */
static void SavePlatformChozodiaReleaseSamus(void)
{
    if (gCurrentSprite.yPositionSpawn != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.yPositionSpawn);
        return;
    }

    gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_AFTER_SAVE;
    SamusSetPose(SPOSE_FACING_THE_FOREGROUND);
    gDisablePause = FALSE;
}

/**
 * @brief 469d0 | 34 | Handles a save platform after a save
 * 
 */
static void SavePlatformChozodiaSamusDetectionOut(void)
{
    if (!SavePlatformDetectSamus())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_CLOSING;
        gCurrentSprite.pOam = sSavePlatformChozodiaOam_Closing;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        SoundPlay(SOUND_CHOZODIA_SAVE_PLATFORM_CLOSING);
    }
}

/**
 * @brief 46a04 | c0 | Checks if Samus needs a refill
 * 
 */
static void SavePlatformChozodiaCheckRefill(void)
{
    u8 isFull;

    isFull = FALSE;

    if (gCurrentSprite.work0 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        return;
    }

    if (gEquipment.suitType == SUIT_SUITLESS)
    {
        if (gEquipment.currentEnergy == gEquipment.maxEnergy)
            isFull = TRUE;
    }
    else
    {
        if (gEquipment.currentEnergy == gEquipment.maxEnergy && gEquipment.currentMissiles == gEquipment.maxMissiles &&
            gEquipment.currentSuperMissiles == gEquipment.maxSuperMissiles)
        {
            if (gEquipment.currentPowerBombs == gEquipment.maxPowerBombs)
                isFull = TRUE;
        }
    }

    if (isFull)
    {
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_SAVE_PROMPT;
    }
    else
    {
        gSamusData.timer = FALSE;
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_REFILL;
        gCurrentSprite.work0 = 5;

        SpriteSpawnSecondary(SSPRITE_CHOZODIA_SAVE_PLATFORM_PART, SAVE_PLATFORM_CHOZODIA_PART_REFILL_LIGHT,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

        TransparencySpriteUpdateBldalpha(BLDALPHA_MAX_VALUE / 2 - 1, BLDALPHA_MAX_VALUE, 0, BLDALPHA_MAX_VALUE);
        SoundPlay(SOUND_CHOZODIA_SAVE_PLATFORM_REFILL);
    }
}

/**
 * @brief 46ac4 | 194 | Handles a save platform (Chozodia) refilling Samus
 * 
 */
static void SavePlatformChozodiaRefill(void)
{
    if (gEquipment.suitType == SUIT_SUITLESS)
    {
        if (gCurrentSprite.work0 == 5)
        {
            if (!SpriteUtilRefillEnergy())
            {
                gCurrentSprite.work0--;
                gEnergyRefillAnimation = 13;
            }
        }
        else if (gCurrentSprite.work0 == 4)
        {
            if (gEnergyRefillAnimation != 0)
                gEnergyRefillAnimation--;
            else
                gCurrentSprite.work0--;
        }
        else if (gCurrentSprite.work0 != 0)
        {
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                gSamusData.timer = TRUE;
                TransparencySpriteUpdateBldalpha(0, BLDALPHA_MAX_VALUE, 0, BLDALPHA_MAX_VALUE);
                SoundFade(SOUND_CHOZODIA_SAVE_PLATFORM_REFILL, ONE_THIRD_SECOND);
            }
        }
        else
        {
            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_AFTER_REFILL;
            gCurrentSprite.work1 = SpriteSpawnPrimary(PSPRITE_MESSAGE_BANNER, MESSAGE_ENERGY_TANK_RECHARGE_COMPLETE,
                SPRITE_GFX_SLOT_SPECIAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
        }
    }
    else
    {
        if (gCurrentSprite.work0 == 5)
        {
            if (!SpriteUtilRefillEnergy())
            {
                gCurrentSprite.work0--;
                gEnergyRefillAnimation = 13;
            }
        }
        else if (gCurrentSprite.work0 == 4)
        {
            if (gEnergyRefillAnimation != 0)
            {
                gEnergyRefillAnimation--;
            }
            else if (!SpriteUtilRefillMissiles())
            {
                gCurrentSprite.work0--;
                gMissileRefillAnimation = 13;
            }
        }
        else if (gCurrentSprite.work0 == 3)
        {
            if (gMissileRefillAnimation != 0)
            {
                gMissileRefillAnimation--;
            }
            else if (!SpriteUtilRefillSuperMissiles())
            {
                gCurrentSprite.work0--;
                gSuperMissileRefillAnimation = 13;
            }
        }
        else if (gCurrentSprite.work0 == 2)
        {
            if (gSuperMissileRefillAnimation != 0)
            {
                gSuperMissileRefillAnimation--;
            }
            else if (!SpriteUtilRefillPowerBombs())
            {
                gCurrentSprite.work0--;
                gPowerBombRefillAnimation = 13;
            }
        }
        else if (gPowerBombRefillAnimation != 0)
        {
            gPowerBombRefillAnimation--;
        }
        else if (gCurrentSprite.work0 != 0)
        {
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                gSamusData.timer = TRUE;
                TransparencySpriteUpdateBldalpha(0, BLDALPHA_MAX_VALUE, 0, BLDALPHA_MAX_VALUE);
                SoundFade(SOUND_CHOZODIA_SAVE_PLATFORM_REFILL, ONE_THIRD_SECOND);
            }
        }
        else
        {
            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_AFTER_REFILL;
            gCurrentSprite.work1 = SpriteSpawnPrimary(PSPRITE_MESSAGE_BANNER, MESSAGE_WEAPONS_AND_ENERGY_RESTORED,
                SPRITE_GFX_SLOT_SPECIAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
        }
    }
}

/**
 * @brief 46c58 | 38 | Handles a save platform (Complete) waiting for the "Refill complete" message to be done
 * 
 */
static void SavePlatformChozodiaAfterRefill(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.work1;
    if (gSpriteData[ramSlot].pose == MESSAGE_BANNER_POSE_REMOVAL_ANIMATION)
    {
        gCurrentSprite.work0 = ONE_THIRD_SECOND;
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_SAVE_PROMPT;
    }
}

/**
 * @brief 46c90 | d0 | Handles a save platform (Chozodia) during a save prompt
 * 
 */
static void SavePlatformChozodiaSavePrompt(void)
{
    u8 ramSlot;

    if (gCurrentSprite.work0 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.work1 = SpriteSpawnPrimary(PSPRITE_MESSAGE_BANNER, MESSAGE_SAVE_PROMPT,
                SPRITE_GFX_SLOT_SPECIAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
        }

        return;
    }

    ramSlot = gCurrentSprite.work1;
    if (gSpriteData[ramSlot].pose == MESSAGE_BANNER_POSE_REMOVAL_ANIMATION)
    {
        if (gSpriteData[ramSlot].work1 == TRUE)
        {
            gCurrentSprite.pOam = sSavePlatformChozodiaOam_Saving;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_SAVING;

            SpriteSpawnSecondary(SSPRITE_CHOZODIA_SAVE_PLATFORM_PART, SAVE_PLATFORM_CHOZODIA_PART_TUBE,
                gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition,
                gCurrentSprite.xPosition, 0);

            gSpriteData[gCurrentSprite.work3].pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_EXTENDING_INIT;
            gSamusData.timer = FALSE;
            SoundPlay(SOUND_SAVING);
        }
        else
        {
            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_DELAY_BEFORE_RELEASING;
            gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);
        }
    }
}

/**
 * @brief 46d60 | 40 | Handles a save platform (Chozodia) saving
 * 
 */
static void SavePlatformChozodiaSaving(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.work3;
    if (MOD_AND(gCurrentSprite.currentAnimationFrame, 2))
    {
        gCurrentSprite.paletteRow = 0;
        gSpriteData[ramSlot].paletteRow = 0;
    }
    else
    {
        gCurrentSprite.paletteRow = 2;
        gSpriteData[ramSlot].paletteRow = 2;
    }
}

/**
 * @brief 46da0 | 44 | Initializes a save platform (Chozodia) to be opened (off)
 * 
 */
static void SavePlatformChozodiaOpenedOffInit(void)
{
    gCurrentSprite.pOam = sSavePlatformChozodiaOam_IdleOff;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_SPAWN_SAVE_DONE_MESSAGE;
    gCurrentSprite.work0 = CONVERT_SECONDS(1.f);
    gCurrentSprite.paletteRow = 0;
    gSpriteData[gCurrentSprite.work3].paletteRow = 0;
}

/**
 * @brief 46de4 | 44 | Spawns the "save complete" message
 * 
 */
static void SavePlatformChozodiaSpawnSaveDoneMessage(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_WAIT_FOR_MESSAGE_OUT;
        gCurrentSprite.work1 = SpriteSpawnPrimary(PSPRITE_MESSAGE_BANNER, MESSAGE_SAVE_COMPLETE,
            SPRITE_GFX_SLOT_SPECIAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 46e28 | 38 | Handles a save platform (Chozodia) waiting for the "Save complete" message to be done
 * 
 */
static void SavePlatformChozodiaCheckMessageBannerOut(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.work1;

    if (gSpriteData[ramSlot].pose == MESSAGE_BANNER_POSE_REMOVAL_ANIMATION)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_DELAY_BEFORE_RELEASING;
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);
    }
}

/**
 * @brief 46e60 | 24 | Handles the delay before a save platform (Chozodia) releases Samus
 * 
 */
static void SavePlatformChozodiaDelayBeforeReleasingSamus(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_POSE_RELEASE_SAMUS;
}

/**
 * @brief 46e84 | 1b6 | Initializes a save platform (Chozodia) part sprite
 * 
 */
static void SavePlatformChozodiaPartInit(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.hitboxTop = -PIXEL_SIZE;
    gCurrentSprite.hitboxBottom = PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
    gCurrentSprite.hitboxRight = PIXEL_SIZE;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    switch (gCurrentSprite.roomSlot)
    {
        case SAVE_PLATFORM_CHOZODIA_PART_TUBE:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

            if (gSpriteData[ramSlot].pose == SAVE_PLATFORM_CHOZODIA_POSE_RELEASE_SAMUS)
            {
                gCurrentSprite.pOam = sSavePlatformChozodiaPartOam_TubeIdle;
                gCurrentSprite.yPositionSpawn = CONVERT_SECONDS(5.f + 1.f / 6);
                gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_IDLE;
            }
            else
            {
                gCurrentSprite.pOam = sSavePlatformChozodiaPartOam_TubeSpawning;
                gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_SPAWNING;
            }
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_TUBE_SHADOW:
            gCurrentSprite.drawOrder = 12;
            gCurrentSprite.pOam = sSavePlatformChozodiaPartOam_TubeShadow;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_SHADOW_IDLE;
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_RAY:
            gCurrentSprite.drawOrder = 5;
            gCurrentSprite.pOam = sSavePlatformChozodiaPartOam_Ray;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_RAY_IDLE;
            gCurrentSprite.work0 = CONVERT_SECONDS(1.6f);
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_TOP:
            gCurrentSprite.drawOrder = 3;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);

            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_IDLE;

            if (gSpriteData[ramSlot].pose == SAVE_PLATFORM_CHOZODIA_POSE_RELEASE_SAMUS)
                gCurrentSprite.pOam = sSavePlatformChozodiaPartOam_TopExtended;
            else
                gCurrentSprite.pOam = sSavePlatformChozodiaPartOam_TopIdle;
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_REFILL_LIGHT:
            gCurrentSprite.drawOrder = 5;
            gCurrentSprite.pOam = sSavePlatformChozodiaPartOam_RefillLight;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + QUARTER_BLOCK_SIZE);

            gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_REFILL_LIGHT_IDLE;
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 4703c | 2c | Handles the refill light part being idle
 * 
 */
static void SavePlatformChozodiaPartRefillLightIdle(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (gSpriteData[ramSlot].pose == SAVE_PLATFORM_CHOZODIA_POSE_AFTER_REFILL)
        gCurrentSprite.status = 0;
}

/**
 * @brief 47068 | 4 | Empty function
 * 
 */
static void SavePlatformChozodiaPart_Empty(void)
{
    return;
}

/**
 * @brief 4706c | 1c | Initializes the top part to be extending
 * 
 */
static void SavePlatformChozodiaPartTopExtendingInit(void)
{
    gCurrentSprite.pOam = sSavePlatformChozodiaPartOam_TopExtending;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_EXTENDING;
}

/**
 * @brief 47088 | 2c | Handles the top part extending
 * 
 */
static void SavePlatformChozodiaPartTopExtending(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_IDLE;

        gCurrentSprite.pOam = sSavePlatformChozodiaPartOam_TopExtended;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 470b4 | 34 | Initializes the top part to be retracting
 * 
 */
static void SavePlatformChozodiaPartTopRetractingInit(void)
{
    gCurrentSprite.pOam = sSavePlatformChozodiaPartOam_TopRetracting;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_RETRACTING;

    gSamusData.timer = TRUE;
    SoundPlay(SOUND_SAVE_PLATFORM_RETRACTING);
}

/**
 * @brief 470e8 | 2c | Handles the top part retracting
 * 
 */
static void SavePlatformChozodiaPartTopRetracting(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_IDLE;

        gCurrentSprite.pOam = sSavePlatformChozodiaPartOam_TopIdle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 47114 | 50 | Handles the tube part spawning
 * 
 */
static void SavePlatformChozodiaPartTubeSpawning(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_CHECK_SHADOW_DISAPPEARED;
        
        gCurrentSprite.pOam = sSavePlatformChozodiaPartOam_TubeIdle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.work1 = SpriteSpawnSecondary(SSPRITE_CHOZODIA_SAVE_PLATFORM_PART, SAVE_PLATFORM_CHOZODIA_PART_TUBE_SHADOW,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 47164 | 54 | Handles the tube part spawning the ray part
 * 
 */
static void SavePlatformChozodiaPartSpawnRay(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.work1;

    if (gSpriteData[ramSlot].status == 0)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_IDLE;
        gCurrentSprite.yPositionSpawn = CONVERT_SECONDS(2.f);
        SpriteSpawnSecondary(SSPRITE_CHOZODIA_SAVE_PLATFORM_PART, SAVE_PLATFORM_CHOZODIA_PART_RAY,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 471b8 | 30 | Handles the tube part being idle
 * 
 */
static void SavePlatformChozodiaPartTubeIdle(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.yPositionSpawn);
    if (gCurrentSprite.yPositionSpawn == 0)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_DESPAWNING;
        gCurrentSprite.pOam = sSavePlatformChozodiaPartOam_TubeDespawning;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 471e8 | 3c | Handles the tube part despawning
 * 
 */
static void SavePlatformChozodiaPartTubeDespawning(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.status = 0;
        gSpriteData[gSpriteData[gCurrentSprite.primarySpriteRamSlot].work3].pose = SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_RETRACTING_INIT;
    }
}

/**
 * @brief 47224 | 18 | Handles the shadow part being idle
 * 
 */
static void SavePlatformChozodiaPartTubeShadowIdle(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
        gCurrentSprite.status = 0;
}

/**
 * @brief 4723c | 44 | Handles the ray part being idle
 * 
 */
static void SavePlatformChozodiaPartRayIdle(void)
{
    gCurrentSprite.yPosition -= PIXEL_SIZE;
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);

    if (gCurrentSprite.work0 == 0)
    {
        gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose = SAVE_PLATFORM_CHOZODIA_POSE_OPENED_OFF_INIT;
        gCurrentSprite.status = 0;
    }
}

/**
 * @brief 47280 | 1e8 | Save platform (Chozodia) AI
 * 
 */
void SavePlatformChozodia(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            SavePlatformChozodiaInit();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_IDLE:
            SavePlatformChozodiaSamusDetection();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_OPENING:
            SavePlatformChozodiaCheckOpeningAnimEnded();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_OPENED:
            SavePlatformChozodiaSecondSamusDetection();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_CLOSING:
            SavePlatformChozodiaCheckClosingAnimEnded();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_RELEASE_SAMUS:
            SavePlatformChozodiaReleaseSamus();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_AFTER_SAVE:
            SavePlatformChozodiaSamusDetectionOut();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_SAVE_PROMPT:
            SavePlatformChozodiaSavePrompt();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_SAVING:
            SavePlatformChozodiaSaving();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_OPENED_OFF_INIT:
            SavePlatformChozodiaOpenedOffInit();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_SPAWN_SAVE_DONE_MESSAGE:
            SavePlatformChozodiaSpawnSaveDoneMessage();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_WAIT_FOR_MESSAGE_OUT:
            SavePlatformChozodiaCheckMessageBannerOut();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_DELAY_BEFORE_RELEASING:
            SavePlatformChozodiaDelayBeforeReleasingSamus();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_CHECK_REFILL:
            SavePlatformChozodiaCheckRefill();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_REFILL:
            SavePlatformChozodiaRefill();
            break;

        case SAVE_PLATFORM_CHOZODIA_POSE_AFTER_REFILL:
            SavePlatformChozodiaAfterRefill();
            break;
    }
}

/**
 * @brief 47468 | 198 | Save platform (Chozodia) part AI
 * 
 */
void SavePlatformChozodiaPart(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            SavePlatformChozodiaPartInit();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_SPAWNING:
            SavePlatformChozodiaPartTubeSpawning();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_CHECK_SHADOW_DISAPPEARED:
            SavePlatformChozodiaPartSpawnRay();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_IDLE:
            SavePlatformChozodiaPartTubeIdle();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_DESPAWNING:
            SavePlatformChozodiaPartTubeDespawning();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TUBE_SHADOW_IDLE:
            SavePlatformChozodiaPartTubeShadowIdle();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_RAY_IDLE:
            SavePlatformChozodiaPartRayIdle();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_IDLE:
            SavePlatformChozodiaPart_Empty();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_EXTENDING_INIT:
            SavePlatformChozodiaPartTopExtendingInit();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_EXTENDING:
            SavePlatformChozodiaPartTopExtending();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_RETRACTING_INIT:
            SavePlatformChozodiaPartTopRetractingInit();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_TOP_RETRACTING:
            SavePlatformChozodiaPartTopRetracting();
            break;

        case SAVE_PLATFORM_CHOZODIA_PART_POSE_REFILL_LIGHT_IDLE:
            SavePlatformChozodiaPartRefillLightIdle();
            break;
    }
}
