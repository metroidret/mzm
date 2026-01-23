#include "sprites_ai/save_platform.h"
#include "sprites_ai/message_banner.h"

#include "data/sprites/save_platform.h"

#include "constants/audio.h"
#include "constants/escape.h"
#include "constants/sprite.h"
#include "constants/samus.h"
#include "constants/text.h"

#include "structs/game_state.h"
#include "structs/hud.h"
#include "structs/sprite.h"
#include "structs/samus.h"

#define SAVE_PLATFORM_POSE_IDLE 0x9
#define SAVE_PLATFORM_POSE_OPENING 0x23
#define SAVE_PLATFORM_POSE_OPENED 0x25
#define SAVE_PLATFORM_POSE_CLOSING 0x27
#define SAVE_PLATFORM_POSE_RELEASE_SAMUS 0x28
#define SAVE_PLATFORM_POSE_AFTER_SAVE 0x29
#define SAVE_PLATFORM_POSE_SAVE_PROMPT 0x42
#define SAVE_PLATFORM_POSE_SAVING 0x43
#define SAVE_PLATFORM_POSE_OPENED_OFF_INIT 0x45
#define SAVE_PLATFORM_POSE_SPAWN_SAVE_DONE_MESSAGE 0x47
#define SAVE_PLATFORM_POSE_WAIT_FOR_MESSAGE_OUT 0x49
#define SAVE_PLATFORM_POSE_DELAY_BEFORE_RELEASING 0x4B
#define SAVE_PLATFORM_POSE_OFF 0x51

// Save platform part

enum SavePlatformPart {
    SAVE_PLATFORM_PART_TUBE,
    SAVE_PLATFORM_PART_TUBE_SHADOW,
    SAVE_PLATFORM_PART_RAY,
    SAVE_PLATFORM_PART_TOP
};

#define SAVE_PLATFORM_PART_POSE_TUBE_SPAWNING 0x9
#define SAVE_PLATFORM_PART_POSE_TUBE_CHECK_SHADOW_DISAPPEARED 0x23
#define SAVE_PLATFORM_PART_POSE_TUBE_IDLE 0x25
#define SAVE_PLATFORM_PART_POSE_TUBE_DESPAWNING 0x27
#define SAVE_PLATFORM_PART_POSE_TUBE_SHADOW_IDLE 0x29
#define SAVE_PLATFORM_PART_POSE_RAY_IDLE 0x2B
#define SAVE_PLATFORM_PART_POSE_TOP_IDLE 0x43
#define SAVE_PLATFORM_PART_POSE_TOP_EXTENDING_INIT 0x44
#define SAVE_PLATFORM_PART_POSE_TOP_EXTENDING 0x45
#define SAVE_PLATFORM_PART_POSE_TOP_RETRACTING_INIT 0x46
#define SAVE_PLATFORM_PART_POSE_TOP_RETRACTING 0x47

/**
 * @brief 1f9b0 | 38 | Checks if Samus is standing on a save platform
 * 
 * @return u8 bool, samus standing on platform
 */
u8 SavePlatformDetectSamus(void)
{
    u8 colliding;
    s32 samusY;
    s32 samusX;
    s32 spriteY;
    s32 spriteX;

    colliding = FALSE;
    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;

    if (samusY == spriteY - (BLOCK_SIZE + ONE_SUB_PIXEL) && spriteX - BLOCK_SIZE < samusX && spriteX + BLOCK_SIZE > samusX)
        colliding = TRUE;

    return colliding;
}

/**
 * @brief 1f9e8 | 128 | Initializes a save platform sprite
 * 
 */
static void SavePlatformInit(void)
{
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.yPositionSpawn = 0;
    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
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
        gCurrentSprite.pOam = sSavePlatformOam_IdleOff;
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_OFF;
    }
    else if (gIsLoadingFile)
    {
        SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_PART, SAVE_PLATFORM_PART_TUBE, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

        gCurrentSprite.pOam = sSavePlatformOam_OpenedOff;
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_RELEASE_SAMUS;
        gCurrentSprite.yPositionSpawn = CONVERT_SECONDS(5.f) + TWO_THIRD_SECOND;
    }
    else
    {
        gCurrentSprite.pOam = sSavePlatformOam_Idle;
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_IDLE;
    }

    gCurrentSprite.work3 = SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_PART, SAVE_PLATFORM_PART_TOP,
        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
        gCurrentSprite.yPosition - BLOCK_SIZE * 8, gCurrentSprite.xPosition, 0);
}

/**
 * @brief 1fb10 | 58 | Handles a save platform being idle
 * 
 */
static void SavePlatformSamusDetection(void)
{
    if (SavePlatformDetectSamus() && !SpriteUtilCheckCrouchingOrMorphed())
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.pose = SAVE_PLATFORM_POSE_OPENING;
            gCurrentSprite.pOam = sSavePlatformOam_Opening;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            SoundPlay(SOUND_SAVE_PLATFORM_OPENING);
        }
    }
    else
    {
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);
    }
}

/**
 * @brief 1fb68 | 2c | Handles a save platform opening
 * 
 */
static void SavePlatformCheckOpeningAnimEnded(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_OPENED;
        gCurrentSprite.pOam = sSavePlatformOam_Opened;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 1fb94 | 80 | Handles a save platform being opened
 * 
 */
static void SavePlatformSecondSamusDetection(void)
{
    if (SavePlatformDetectSamus())
    {
        if (!SpriteUtilCheckCrouchingOrMorphed())
        {
            gCurrentSprite.pose = SAVE_PLATFORM_POSE_SAVE_PROMPT;
            gCurrentSprite.work0 = 0x4;
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
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_CLOSING;
        gCurrentSprite.pOam = sSavePlatformOam_Closing;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        SoundPlay(SOUND_SAVE_PLATFORM_CLOSING);
    }
}

/**
 * @brief 1fc14 | 30 | Handles a save platform closing
 * 
 */
static void SavePlatformCheckClosingAnimEnded(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_IDLE;
        gCurrentSprite.pOam = sSavePlatformOam_Idle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);
    }
}

/**
 * @brief 1fc44 | 34 | Handles a save platform releasing Samus
 * 
 */
static void SavePlatformReleaseSamus(void)
{
    if (gCurrentSprite.yPositionSpawn != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.yPositionSpawn);
        return;
    }

    gCurrentSprite.pose = SAVE_PLATFORM_POSE_AFTER_SAVE;
    SamusSetPose(SPOSE_FACING_THE_FOREGROUND);
    gDisablePause = FALSE;
}

/**
 * @brief 1fc78 | 38 | Handles a save platform after a save
 * 
 */
static void SavePlatformSamusDetectionOut(void)
{
    if (!SavePlatformDetectSamus())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_CLOSING;
        gCurrentSprite.pOam = sSavePlatformOam_Closing;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        SoundPlay(SOUND_SAVE_PLATFORM_CLOSING);
    }
}

/**
 * @brief 1fcb0 | d0 | Handles a save platform during a save prompt
 * 
 */
static void SavePlatformSavePrompt(void)
{
    u8 msgBannerSlot;

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
    else

    // Message banner
    msgBannerSlot = gCurrentSprite.work1;
    if (gSpriteData[msgBannerSlot].pose == MESSAGE_BANNER_POSE_REMOVAL_ANIMATION)
    {
        if (gSpriteData[msgBannerSlot].work1 == TRUE)
        {
            gCurrentSprite.pOam = sSavePlatformOam_Saving;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = SAVE_PLATFORM_POSE_SAVING;
            SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_PART, SAVE_PLATFORM_PART_TUBE, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

            gSpriteData[gCurrentSprite.work3].pose = SAVE_PLATFORM_PART_POSE_TOP_EXTENDING_INIT;
            gSamusData.timer = FALSE;
            SoundPlay(SOUND_SAVING);
        }
        else
        {
            gCurrentSprite.pose = SAVE_PLATFORM_POSE_DELAY_BEFORE_RELEASING;
            gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);
        }
    }
}

/**
 * @brief 1fd80 | 40 | Handles a save platform saving
 * 
 */
static void SavePlatformSaving(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.work3;
    if (MOD_AND(gCurrentSprite.currentAnimationFrame, 2))
    {
        gCurrentSprite.paletteRow = 0;
        gSpriteData[ramSlot].paletteRow = gCurrentSprite.paletteRow;
    }
    else
    {
        gCurrentSprite.paletteRow = 2;
        gSpriteData[ramSlot].paletteRow = gCurrentSprite.paletteRow;
    }
}

/**
 * @brief 1fdc0 | 44 | Initializes a save platform to be opened (off)
 * 
 */
static void SavePlatformOpenedOffInit(void)
{
    gCurrentSprite.pOam = sSavePlatformOam_OpenedOff;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = SAVE_PLATFORM_POSE_SPAWN_SAVE_DONE_MESSAGE;
    gCurrentSprite.work0 = CONVERT_SECONDS(1.f);
    gCurrentSprite.paletteRow = 0;
    gSpriteData[gCurrentSprite.work3].paletteRow = 0;
}

/**
 * @brief 1fe04 | 44 | Spawns the "save complete" message
 * 
 */
static void SavePlatformSpawnSaveDoneMessage(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_WAIT_FOR_MESSAGE_OUT;
        gCurrentSprite.work1 = SpriteSpawnPrimary(PSPRITE_MESSAGE_BANNER, MESSAGE_SAVE_COMPLETE, 
            SPRITE_GFX_SLOT_SPECIAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    }
}

/**
 * @brief 1fe48 | 38 | Handles a save platform waiting for the "Save complete" message to be done
 * 
 */
static void SavePlatformCheckMessageBannerOut(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.work1;
    if (gSpriteData[ramSlot].pose == MESSAGE_BANNER_POSE_REMOVAL_ANIMATION)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_DELAY_BEFORE_RELEASING;
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);
    }
}

/**
 * @brief 1fe80 | 24 | Handles the delay before a save platform releases Samus
 * 
 */
static void SavePlatformDelayBeforeReleasingSamus(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
        gCurrentSprite.pose = SAVE_PLATFORM_POSE_RELEASE_SAMUS;
}

/**
 * @brief 1fea4 | 16c | Initializes a save platform part sprite
 * 
 */
static void SavePlatformPartInit(void)
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
        case SAVE_PLATFORM_PART_TUBE:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
            if (gSpriteData[ramSlot].pose == SAVE_PLATFORM_POSE_RELEASE_SAMUS)
            {
                gCurrentSprite.pOam = sSavePlatformPartOam_TubeIdle;
                gCurrentSprite.yPositionSpawn = CONVERT_SECONDS(5.f + 1.f / 6);
                gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_IDLE;
            }
            else
            {
                gCurrentSprite.pOam = sSavePlatformPartOam_TubeSpawning;
                gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_SPAWNING;
            }
            break;

        case SAVE_PLATFORM_PART_TUBE_SHADOW:
            gCurrentSprite.drawOrder = 12;
            gCurrentSprite.pOam = sSavePlatformPartOam_TubeShadow;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

            gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_SHADOW_IDLE;
            break;

        case SAVE_PLATFORM_PART_RAY:
            gCurrentSprite.drawOrder = 5;
            gCurrentSprite.pOam = sSavePlatformPartOam_Ray;
            
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

            gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_RAY_IDLE;
            gCurrentSprite.work0 = CONVERT_SECONDS(1.6f);
            break;

        case SAVE_PLATFORM_PART_TOP:
            gCurrentSprite.drawOrder = 3;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);

            gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TOP_IDLE;
            if (gSpriteData[ramSlot].pose == SAVE_PLATFORM_POSE_RELEASE_SAMUS)
                gCurrentSprite.pOam = sSavePlatformPartOam_TopExtended;
            else
                gCurrentSprite.pOam = sSavePlatformPartOam_TopIdle;
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 20010 | 4 | Empty function
 * 
 */
static void SavePlatformPart_Empty(void)
{
    return;
}

/**
 * @brief 20014 | 1c | Initializes the top part to be extending
 * 
 */
static void SavePlatformPartExtendingInit(void)
{
    gCurrentSprite.pOam = sSavePlatformPartOam_TopExtending;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TOP_EXTENDING;
}

/**
 * @brief 20030 | 2c | Handles the top part extending
 * 
 */
static void SavePlatformPartTopExtending(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TOP_IDLE;
        gCurrentSprite.pOam = sSavePlatformPartOam_TopExtended;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 2005c | 34 | Initializes the top part to be retracting
 * 
 */
static void SavePlatformPartTopRetractingInit(void)
{
    gCurrentSprite.pOam = sSavePlatformPartOam_TopRetracting;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TOP_RETRACTING;
    gSamusData.timer = TRUE;
    SoundPlay(SOUND_SAVE_PLATFORM_RETRACTING);
}

/**
 * @brief 20090 | 2c | Handles the top part retracting
 * 
 */
static void SavePlatformPartTopRetracting(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TOP_IDLE;
        gCurrentSprite.pOam = sSavePlatformPartOam_TopIdle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 200bc | 50 | Handles the tube part spawning
 * 
 */
static void SavePlatformPartTubeSpawning(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_CHECK_SHADOW_DISAPPEARED;
        gCurrentSprite.pOam = sSavePlatformPartOam_TubeIdle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.work1 = SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_PART, SAVE_PLATFORM_PART_TUBE_SHADOW,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    }
}

/**
 * @brief 2010c | 54 | Handles the tube part spawning the ray part
 * 
 */
static void SavePlatformPartSpawnRay(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.work1;
    if (gSpriteData[ramSlot].status == 0)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_IDLE;
        gCurrentSprite.yPositionSpawn = CONVERT_SECONDS(2.f);
        SpriteSpawnSecondary(SSPRITE_SAVE_PLATFORM_PART, SAVE_PLATFORM_PART_RAY, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    }
}

/**
 * @brief 20160 | 30 | Handles the tube part being idle
 * 
 */
static void SavePlatformPartTubeIdle(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.yPositionSpawn);
    if (gCurrentSprite.yPositionSpawn == 0)
    {
        gCurrentSprite.pose = SAVE_PLATFORM_PART_POSE_TUBE_DESPAWNING;
        gCurrentSprite.pOam = sSavePlatformPartOam_TubeDespawning;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 20190 | 3c | handles the tube part despawning
 * 
 */
static void SavePlatformPartTubeDespawning(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.status = 0;
        gSpriteData[gSpriteData[gCurrentSprite.primarySpriteRamSlot].work3].pose = SAVE_PLATFORM_PART_POSE_TOP_RETRACTING_INIT;
    }
}

/**
 * @brief 201cc | 18 | Handles the tube shadow part being idle
 * 
 */
static void SavePlatformPartTubeShadowIdle(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
        gCurrentSprite.status = 0;
}

/**
 * @brief 201e4 | 44 | Handles the ray part being idle
 * 
 */
static void SavePlatformPartRayIdle(void)
{
    gCurrentSprite.yPosition -= PIXEL_SIZE;
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);

    if (gCurrentSprite.work0 == 0)
    {
        gSpriteData[gCurrentSprite.primarySpriteRamSlot].pose = SAVE_PLATFORM_POSE_OPENED_OFF_INIT;
        gCurrentSprite.status = 0;
    }
}

/**
 * @brief 20228 | 1a8 | Save platform AI
 * 
 */
void SavePlatform(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            SavePlatformInit();
            break;

        case SAVE_PLATFORM_POSE_IDLE:
            SavePlatformSamusDetection();
            break;

        case SAVE_PLATFORM_POSE_OPENING:
            SavePlatformCheckOpeningAnimEnded();
            break;

        case SAVE_PLATFORM_POSE_OPENED:
            SavePlatformSecondSamusDetection();
            break;

        case SAVE_PLATFORM_POSE_CLOSING:
            SavePlatformCheckClosingAnimEnded();
            break;

        case SAVE_PLATFORM_POSE_RELEASE_SAMUS:
            SavePlatformReleaseSamus();
            break;

        case SAVE_PLATFORM_POSE_AFTER_SAVE:
            SavePlatformSamusDetectionOut();
            break;

        case SAVE_PLATFORM_POSE_SAVE_PROMPT:
            SavePlatformSavePrompt();
            break;

        case SAVE_PLATFORM_POSE_SAVING:
            SavePlatformSaving();
            break;

        case SAVE_PLATFORM_POSE_OPENED_OFF_INIT:
            SavePlatformOpenedOffInit();
            break;

        case SAVE_PLATFORM_POSE_SPAWN_SAVE_DONE_MESSAGE:
            SavePlatformSpawnSaveDoneMessage();
            break;

        case SAVE_PLATFORM_POSE_WAIT_FOR_MESSAGE_OUT:
            SavePlatformCheckMessageBannerOut();
            break;

        case SAVE_PLATFORM_POSE_DELAY_BEFORE_RELEASING:
            SavePlatformDelayBeforeReleasingSamus();
    }
}

/**
 * @brief 203d0 | 194 | Save platform part AI
 * 
 */
void SavePlatformPart(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            SavePlatformPartInit();
            break;

        case SAVE_PLATFORM_PART_POSE_TUBE_SPAWNING:
            SavePlatformPartTubeSpawning();
            break;

        case SAVE_PLATFORM_PART_POSE_TUBE_CHECK_SHADOW_DISAPPEARED:
            SavePlatformPartSpawnRay();
            break;

        case SAVE_PLATFORM_PART_POSE_TUBE_IDLE:
            SavePlatformPartTubeIdle();
            break;

        case SAVE_PLATFORM_PART_POSE_TUBE_DESPAWNING:
            SavePlatformPartTubeDespawning();
            break;

        case SAVE_PLATFORM_PART_POSE_TUBE_SHADOW_IDLE:
            SavePlatformPartTubeShadowIdle();
            break;

        case SAVE_PLATFORM_PART_POSE_RAY_IDLE:
            SavePlatformPartRayIdle();
            break;

        case SAVE_PLATFORM_PART_POSE_TOP_IDLE:
            SavePlatformPart_Empty();
            break;

        case SAVE_PLATFORM_PART_POSE_TOP_EXTENDING_INIT:
            SavePlatformPartExtendingInit();
            break;

        case SAVE_PLATFORM_PART_POSE_TOP_EXTENDING:
            SavePlatformPartTopExtending();
            break;

        case SAVE_PLATFORM_PART_POSE_TOP_RETRACTING_INIT:
            SavePlatformPartTopRetractingInit();
            break;

        case SAVE_PLATFORM_PART_POSE_TOP_RETRACTING:
            SavePlatformPartTopRetracting();
    }
}
