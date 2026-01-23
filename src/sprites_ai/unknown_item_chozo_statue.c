#include "sprites_ai/unknown_item_chozo_statue.h"
#define CHOZO_STATUE_IGNORE_FUNCTIONS
#include "sprites_ai/chozo_statue.h"

#include "data/sprites/unknown_item_chozo_statue.h"

#include "constants/audio.h"
#include "constants/in_game_cutscene.h"
#include "constants/clipdata.h"
#include "constants/game_state.h"
#include "constants/sprite.h"
#include "constants/samus.h"
#include "constants/text.h"

#include "structs/audio.h"
#include "structs/clipdata.h"
#include "structs/game_state.h"
#include "structs/hud.h"
#include "structs/scroll.h"
#include "structs/sprite.h"
#include "structs/samus.h"

#define UNKNOWN_ITEM_CHOZO_STATUE_POSE_IDLE 0x9
#define UNKNOWN_ITEM_CHOZO_STATUE_POSE_DO_NOTHING 0xF
#define UNKNOWN_ITEM_CHOZO_STATUE_POSE_REGISTER_HINT 0x22
#define UNKNOWN_ITEM_CHOZO_STATUE_POSE_HINT_FLASHING 0x23
#define UNKNOWN_ITEM_CHOZO_STATUE_POSE_SITTING_INIT 0x24
#define UNKNOWN_ITEM_CHOZO_STATUE_POSE_SITTING 0x25
#define UNKNOWN_ITEM_CHOZO_STATUE_POSE_DELAY_AFTER_SITTING 0x27
#define UNKNOWN_ITEM_CHOZO_STATUE_POSE_WAIT_FOR_ITEM_TO_BE_COLLECTED 0x29
#define UNKNOWN_ITEM_CHOZO_STATUE_POSE_TIMER_AFTER_ITEM 0x2B
#define UNKNOWN_ITEM_CHOZO_STATUE_POSE_REFILL_INIT 0x2E
#define UNKNOWN_ITEM_CHOZO_STATUE_POSE_REFILL 0x2F
#define UNKNOWN_ITEM_CHOZO_STATUE_POSE_SLEEPING_INIT 0x30
#define UNKNOWN_ITEM_CHOZO_STATUE_POSE_SLEEPING 0x31

// Chozo statue part

#define UNKNOWN_ITEM_CHOZO_STATUE_HAND_X_OFFSET (THREE_QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE)
#define UNKNOWN_ITEM_CHOZO_STATUE_HAND_Y_OFFSET (QUARTER_BLOCK_SIZE + ONE_SUB_PIXEL)

#define UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_HINT 0x9
#define UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_LEG_IDLE 0xF
#define UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_SITTING 0x23
#define UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_SEATED 0x24
#define UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_REFILL 0x25
#define UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_REFILL 0x27
#define UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_SLEEPING_INIT 0x29
#define UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_SLEEPING 0x2B
#define UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_EYE_OPENING_INIT 0x42
#define UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_EYE_OPENING 0x43
#define UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_EYE_CLOSING_INIT 0x44
#define UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_EYE_CLOSING 0x45
#define UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_GLOW_IDLE 0x4F
#define UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_DO_NOTHING 0x61

// Chozo status refill

#define UNKNOWN_ITEM_CHOZO_STATUE_REFILL_POSE_IDLE 0x9

static const struct FrameData* sUnknownItemChozoStatueFrameDataPointers[UNKNOWN_ITEM_CHOZO_STATUE_OAM_END] = {
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_LEG_STANDING] = sUnknownItemChozoStatuePartOam_LegStanding,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_LEG_SITTING] = sUnknownItemChozoStatuePartOam_LegSitting,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_LEG_SEATED] = sUnknownItemChozoStatuePartOam_LegSeated,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_IDLE] = sUnknownItemChozoStatueOam_Idle,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_EYE_OPENED] = sUnknownItemChozoStatuePartOam_EyeOpened,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_EYE_CLOSING] = sUnknownItemChozoStatuePartOam_EyeClosing,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_EYE_OPENING] = sUnknownItemChozoStatuePartOam_EyeOpening,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_EYE_CLOSED] = sUnknownItemChozoStatuePartOam_EyeClosed,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_ARM_IDLE] = sUnknownItemChozoStatuePartOam_ArmIdle,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_ARM_GLOW] = sUnknownItemChozoStatuePartOam_ArmGlow,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_ARM_SAMUS_GRABBED] = sUnknownItemChozoStatuePartOam_ArmSamusGrabbed,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_BALL_NORMAL_CLOSED] = sChozoBallOam_UnknownClosed,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_BALL_NORMAL_REVEALING] = sChozoBallOam_UnknownRevealing,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_BALL_NORMAL_REVEALED] = sChozoBallOam_UnknownRevealed,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_REFILL] = sUnknownItemChozoStatueRefillOam,
    [UNKNOWN_ITEM_CHOZO_STATUE_OAM_REFILL_GLOW_IDLE] = sUnknownItemChozoStatuePartOam_GlowIdle
};

/**
 * @brief 150a8 | 88 | Synchronize the sub sprites of an unknown item chozo statue
 * 
 */
static void UnknownItemChozoStatueSyncSubSprites(void)
{
    MultiSpriteDataInfo_T pData;
    u16 oamIdx;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];
    
    if (gCurrentSprite.pOam != sUnknownItemChozoStatueFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sUnknownItemChozoStatueFrameDataPointers[oamIdx];
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
 * @brief 15130 | 1f8 | Initializes an unknown item chozo statue sprite
 * 
 */
static void UnknownItemChozoStatueInit(void)
{
    u8 behavior;
    u8 gfxSlot;
    u8 ramSlot;
    u16 yPosition;
    u16 xPosition;
    u8 newRamSlot;

    gCurrentSprite.properties |= (SP_ALWAYS_ACTIVE | SP_SOLID_FOR_PROJECTILES);

    ChozoStatueSetDirection();
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition + HALF_BLOCK_SIZE;
    else
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition - HALF_BLOCK_SIZE;

    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = PIXEL_SIZE;
    gCurrentSprite.hitboxBottom = PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = PIXEL_SIZE;
    gCurrentSprite.hitboxRight = PIXEL_SIZE;

    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.health = 1;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gSubSpriteData1.work2 = 0;
    gSubSpriteData1.work3 = FALSE;

    behavior = ChozoStatueGetBehavior(gCurrentSprite.spriteId);
    if (behavior > CHOZO_STATUE_BEHAVIOR_REFILL)
    {
        // Is hint
        gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_POSE_IDLE;
        if (behavior == CHOZO_STATUE_BEHAVIOR_HINT_TAKEN)
        {
            // Set seated
            gSubSpriteData1.pMultiOam = sUnknownItemChozoStatueMultiSpriteData_Seated;
            ChozoStatueSeatedChangeClipdata(CAA_MAKE_NON_POWER_GRIP);
        }
        else
        {
            // Set standing
            gSubSpriteData1.work3 = TRUE;
            gSubSpriteData1.pMultiOam = sUnknownItemChozoStatueMultiSpriteData_Standing;
            ChozoStatueStandingChangeClipdata(CAA_MAKE_NON_POWER_GRIP, CAA_MAKE_SOLID_GRIPPABLE);
        }
    }
    else
    {
        // Is item
        gSubSpriteData1.pMultiOam = sUnknownItemChozoStatueMultiSpriteData_Seated;
        ChozoStatueSeatedChangeClipdata(CAA_MAKE_NON_POWER_GRIP);

        if (behavior == CHOZO_STATUE_BEHAVIOR_ITEM)
        {
            // Item
            gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_POSE_WAIT_FOR_ITEM_TO_BE_COLLECTED;

            // Spawn chozo ball
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                SpriteSpawnSecondary(SSPRITE_CHOZO_BALL, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
                    gSubSpriteData1.xPosition + (THREE_QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE), 0);
            }
            else
            {
                SpriteSpawnSecondary(SSPRITE_CHOZO_BALL, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
                    gSubSpriteData1.xPosition - (THREE_QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE), 0);
            }
        }
        else
        {
            gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_POSE_IDLE; // Refill
        }
    }

    gCurrentSprite.roomSlot = UNKNOWN_ITEM_CHOZO_STATUE_PART_HEAD;

    yPosition = gSubSpriteData1.yPosition;
    xPosition = gSubSpriteData1.xPosition;
    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    // Spawn eye
    gCurrentSprite.work1 = SpriteSpawnSecondary(SSPRITE_UNKNOWN_ITEM_CHOZO_STATUE_PART, UNKNOWN_ITEM_CHOZO_STATUE_PART_EYE,
        gfxSlot, ramSlot, yPosition, xPosition, gCurrentSprite.status & SPRITE_STATUS_X_FLIP);

    // Spawn arm
    behavior = SpriteSpawnSecondary(SSPRITE_UNKNOWN_ITEM_CHOZO_STATUE_PART, UNKNOWN_ITEM_CHOZO_STATUE_PART_ARM,
        gfxSlot, ramSlot, yPosition, xPosition, gCurrentSprite.status & SPRITE_STATUS_X_FLIP);

    // Spawn leg
    SpriteSpawnSecondary(SSPRITE_UNKNOWN_ITEM_CHOZO_STATUE_PART, UNKNOWN_ITEM_CHOZO_STATUE_PART_LEG, gfxSlot, ramSlot,
        yPosition, xPosition, gCurrentSprite.status & SPRITE_STATUS_X_FLIP);

    // Spawn glow
    newRamSlot = SpriteSpawnSecondary(SSPRITE_UNKNOWN_ITEM_CHOZO_STATUE_PART, UNKNOWN_ITEM_CHOZO_STATUE_PART_GLOW, gfxSlot,
        ramSlot, yPosition, xPosition, gCurrentSprite.status & SPRITE_STATUS_X_FLIP);
    gSpriteData[newRamSlot].work1 = behavior;
}

/**
 * @brief 15328 | 4 | Empty function
 * 
 */
static void UnknownItemChozoStatue_Empty(void)
{
    return;
}

/**
 * @brief 1532c | 50 | Registers the hint
 * 
 */
static void UnknownItemChozoStatueRegisterHint(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.work1;

    gSpriteData[ramSlot].pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_EYE_OPENING_INIT;

    gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_POSE_HINT_FLASHING;
    gCurrentSprite.work0 = CONVERT_SECONDS(2.f);
    gCurrentSprite.work2 = CONVERT_SECONDS(.2f);
    gCurrentSprite.work3 = 0;

    ChozoStatueRegisterItem(gCurrentSprite.spriteId);
    FadeMusic(CONVERT_SECONDS(1.f));
}

/**
 * @brief 1537c | bc | Handles the flashing before a chozo statue hint
 * 
 */
static void UnknownItemChozoStatueHintFlashing(void)
{
    u8 armSlot;

    armSlot = gCurrentSprite.work1;

    if (gSpriteData[armSlot].pose != CHOZO_STATUE_PART_POSE_DO_NOTHING)
        return;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_POSE_SITTING_INIT;
        gCurrentSprite.paletteRow = 0;

        // Start hint
        gPauseScreenFlag = PAUSE_SCREEN_CHOZO_HINT;

        PlayMusic(MUSIC_CHOZO_STATUE_HINT, 0);
    }
    else
    {
        if (gCurrentSprite.work0 == CONVERT_SECONDS(2.f) - DELTA_TIME)
        {
            MakeBackgroundFlash(BG_FLASH_SLIGHT_YELLOW);
            SoundPlay(SOUND_CHOZO_STATUE_HINT);
        }
        else if (gCurrentSprite.work0 >= CONVERT_SECONDS(2.f))
        {
            return;
        }

        // Update palette
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work2);
        if (gCurrentSprite.work2 == 0)
        {
            // Reset delay
            gCurrentSprite.work2 = CONVERT_SECONDS(.2f);
            // Change row
            gCurrentSprite.paletteRow = sUnknownItemChozoStatueFlashingPaletteRows[gCurrentSprite.work3];

            // Update offset
            if (gCurrentSprite.work3 >= ARRAY_SIZE(sUnknownItemChozoStatueFlashingPaletteRows) - 1)
                gCurrentSprite.work3 = 0;
            else
                gCurrentSprite.work3++;
        }
    }
}

/**
 * @brief 15438 | 40 | Initializes an unknown item chozo statue to be sitting
 * 
 */
static void UnknownItemChozoStatueSittingInit(void)
{
    gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_POSE_SITTING;

    gSubSpriteData1.pMultiOam = sUnknownItemChozoStatueMultiSpriteData_Sitting;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    ChozoStatueStandingChangeClipdata(CAA_REMOVE_SOLID, CAA_REMOVE_SOLID);
    SoundPlay(SOUND_CHOZO_STATUE_SITTING_DOWN);
    gSlowScrollingTimer = CONVERT_SECONDS(1.f);
}

/**
 * @brief 15478 | 4c | Handles an unknown item chozo statue sitting
 * 
 */
static void UnknownItemChozoStatueSitting(void)
{
    SpriteUtilUpdateSubSprite1Timer();

    if (gSubSpriteData1.work2 != 0)
        SpawnChozoStatueMovement(gSubSpriteData1.work2);

    if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        gSubSpriteData1.pMultiOam = sUnknownItemChozoStatueMultiSpriteData_Seated;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_POSE_DELAY_AFTER_SITTING;
        gCurrentSprite.work0 = CONVERT_SECONDS(.5f);
        ChozoStatueSeatedChangeClipdata(CAA_MAKE_NON_POWER_GRIP);
    }
}

/**
 * @brief 154c4 | 24 | Handles the delay before the refill after the statue sat down
 * 
 */
static void UnknownItemChozoStatueDelayBeforeRefillAfterHint(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
        gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_POSE_IDLE;
}

/**
 * @brief 154e8 | 2c | Waits for the item to be grabbed
 * 
 */
static void UnknownItemChozoStatueWaitForItemToBeCollected(void)
{
    u8 behavior = ChozoStatueGetBehavior(gCurrentSprite.spriteId);
    // Check behavior
    if (behavior == CHOZO_STATUE_BEHAVIOR_REFILL)
    {
        // Hint behavior, thus item was took
        gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_POSE_TIMER_AFTER_ITEM;
        gCurrentSprite.work0 = TWO_THIRD_SECOND;
    }
}

/**
 * @brief 15514 | 24 | Timer after the item is grabbed, unknown purpose
 * 
 */
static void UnknownItemChozoStatueTimerAfterItemGrabbed(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
        gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_POSE_IDLE;
}

/**
 * @brief 15538 | 48 | Initializes an unknown item chozo statue for a refill
 * 
 */
static void UnknownItemChozoStatueRefillInit(void)
{
    gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_POSE_REFILL;
    gCurrentSprite.work2 = CONVERT_SECONDS(1.f / 15);
    gCurrentSprite.work3 = 0;

    SpriteSpawnSecondary(SSPRITE_UNKNOWN_ITEM_CHOZO_STATUE_REFILL, 0, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSamusData.yPosition - (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE), gSamusData.xPosition, 0);
}

/**
 * @brief 15580 | 4c | Handles an unknown item chozo statue refilling Samus
 * 
 */
static void UnknownItemChozoStatueRefillSamus(void)
{
    // Update palette
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work2);
    if (gCurrentSprite.work2 == 0)
    {
        // Reset delay
        gCurrentSprite.work2 = CONVERT_SECONDS(1.f / 15);
        // Change row
        gCurrentSprite.paletteRow = sUnknownItemChozoStatueFlashingPaletteRows[gCurrentSprite.work3];
        
        // Update offset
        if (gCurrentSprite.work3 >= ARRAY_SIZE(sUnknownItemChozoStatueFlashingPaletteRows) - 1)
            gCurrentSprite.work3 = 0;
        else
            gCurrentSprite.work3++;
    }
}

/**
 * @brief 155cc | 20 | Initializes an unknown item chozo statue to be sleeping
 * 
 */
static void UnknownItemChozoStatueSleepingInit(void)
{
    gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_POSE_SLEEPING;
    gCurrentSprite.paletteRow = 0;
    gCurrentSprite.work0 = CONVERT_SECONDS(1.f + 1.f / 6);
}

/**
 * @brief 155ec | 58 | Handles an unknown item chozo statue sleeping
 * 
 */
static void UnknownItemChozoStatueSleeping(void)
{
    u8 ramSlot;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        // Close eye
        ramSlot = gCurrentSprite.work1;
        gSpriteData[ramSlot].pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_EYE_CLOSING_INIT;

        gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_POSE_DO_NOTHING;

        // Replay room music if hint
        if (gSubSpriteData1.work3)
            PlayMusic(gMusicTrackInfo.currentRoomTrack, 0);
    }
}

/**
 * @brief 15644 | 174 | Initializes an unknown item chozo statue sprite
 * 
 */
static void UnknownItemChozoStatuePartInit(void)
{
    u8 ramSlot;
    u8 behavior;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawOrder = 2;
    
    gCurrentSprite.hitboxTop = PIXEL_SIZE;
    gCurrentSprite.hitboxBottom = PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = PIXEL_SIZE;
    gCurrentSprite.hitboxRight = PIXEL_SIZE;

    behavior = ChozoStatueGetBehavior(gSpriteData[ramSlot].spriteId);

    switch (gCurrentSprite.roomSlot)
    {
        case UNKNOWN_ITEM_CHOZO_STATUE_PART_ARM:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);

            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            if (behavior == CHOZO_STATUE_BEHAVIOR_HINT)
                gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_HINT;
            else
                gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_REFILL;

            if (behavior == CHOZO_STATUE_BEHAVIOR_ITEM)
                gCurrentSprite.pOam = sUnknownItemChozoStatuePartOam_ArmIdle;
            else
                gCurrentSprite.pOam = sUnknownItemChozoStatuePartOam_ArmGlow;
            break;
    
        case UNKNOWN_ITEM_CHOZO_STATUE_PART_LEG:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);

            if (behavior == CHOZO_STATUE_BEHAVIOR_HINT)
                gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_LEG_IDLE;
            else
                gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_DO_NOTHING;
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_PART_EYE:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

            gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_DO_NOTHING;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            if (behavior == CHOZO_STATUE_BEHAVIOR_HINT)
                gCurrentSprite.pOam = sUnknownItemChozoStatuePartOam_EyeClosed;
            else
                gCurrentSprite.pOam = sUnknownItemChozoStatuePartOam_EyeOpened;
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_PART_GLOW:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(THREE_QUARTER_BLOCK_SIZE);

            gCurrentSprite.pOam = sUnknownItemChozoStatuePartOam_GlowIdle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_GLOW_IDLE;
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 157b8 | 5c | Handles the glow being idle
 * 
 */
static void UnknownItemChozoStatuePartGlowIdle(void)
{
    u8 ramSlot;

    // Arm part slot
    ramSlot = gCurrentSprite.work1;

    if (gSpriteData[ramSlot].pOam == sUnknownItemChozoStatuePartOam_ArmGlow)
    {
        // Display if arm has glow
        if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
    else
    {
        if (!(gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN))
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    }
}

/**
 * @brief 15814 | a0 | Detects if Samus in in the hand (for a hint)
 * 
 */
static void UnknownItemChozoStatuePartArmCheckGrabSamusHint(void)
{
    u8 ramSlot;
    u16 xPosition;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    xPosition = gCurrentSprite.xPosition;

    // Get X offset
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        xPosition += UNKNOWN_ITEM_CHOZO_STATUE_HAND_X_OFFSET;
    else
        xPosition -= UNKNOWN_ITEM_CHOZO_STATUE_HAND_X_OFFSET;

    if (gSpriteData[ramSlot].pose != UNKNOWN_ITEM_CHOZO_STATUE_POSE_IDLE)
        return;

    // Check in correct Y position
    if (gSamusData.yPosition != gCurrentSprite.yPosition - UNKNOWN_ITEM_CHOZO_STATUE_HAND_Y_OFFSET)
        return;

    // Check X range
    if (gSamusData.xPosition <= xPosition - QUARTER_BLOCK_SIZE || gSamusData.xPosition >= xPosition + QUARTER_BLOCK_SIZE)
        return;

    if (gSamusData.pose == SPOSE_MORPH_BALL || gSamusData.pose == SPOSE_ROLLING)
    {
        // Set pose
        SamusSetPose(SPOSE_GRABBED_BY_CHOZO_STATUE);
        
        // Update statue
        gSpriteData[ramSlot].pose = UNKNOWN_ITEM_CHOZO_STATUE_POSE_REGISTER_HINT;
        
        gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_SITTING;

        // Set samus grabbed
        gCurrentSprite.pOam = sUnknownItemChozoStatuePartOam_ArmSamusGrabbed;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gDisablePause = TRUE;
    }
}

/**
 * @brief 158b4 | 30 | Synchronizes Samus's position with the hand position
 * 
 */
static void UnknownItemChozoStatuePartSyncSamusPosition(void)
{
    gSamusData.yPosition = gCurrentSprite.yPosition - UNKNOWN_ITEM_CHOZO_STATUE_HAND_Y_OFFSET;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gSamusData.xPosition = gCurrentSprite.xPosition + UNKNOWN_ITEM_CHOZO_STATUE_HAND_X_OFFSET;
    else
        gSamusData.xPosition = gCurrentSprite.xPosition - UNKNOWN_ITEM_CHOZO_STATUE_HAND_X_OFFSET;
}

/**
 * @brief 158e4 | 44 | Handles the arm part sitting
 * 
 */
static void UnknownItemChozoStatuePartArmSitting(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    // Check set seated
    if (gSpriteData[ramSlot].pose == UNKNOWN_ITEM_CHOZO_STATUE_POSE_DELAY_AFTER_SITTING)
        gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_SEATED;

    UnknownItemChozoStatuePartSyncSamusPosition();

    // Spawn echo
    if (gSubSpriteData1.work2)
        SpawnChozoStatueMovement(gSubSpriteData1.work2);
}

/**
 * @brief 15928 | 40 | Handles the arm part being seated
 * 
 */
static void UnknownItemChozoStatuePartArmSeated(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    UnknownItemChozoStatuePartSyncSamusPosition();

    if (gSpriteData[ramSlot].pose == UNKNOWN_ITEM_CHOZO_STATUE_POSE_IDLE)
    {
        gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_REFILL;
        gDisablePause = FALSE;
    }
}

/**
 * @brief 15968 | fc | Detects if Samus in in the hand (for a refill)
 * 
 */
static void UnknownItemChozoStatuePartArmCheckGrabSamusRefill(void)
{
    u8 ramSlot;
    u8 isGrabbed;
    u16 xPosition;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    // Update oam
    if (gCurrentSprite.pOam == sUnknownItemChozoStatuePartOam_ArmIdle && gPreventMovementTimer == 0 &&
        ChozoStatueGetBehavior(gSpriteData[ramSlot].spriteId) != CHOZO_STATUE_BEHAVIOR_ITEM)
    {
        gCurrentSprite.pOam = sUnknownItemChozoStatuePartOam_ArmGlow;
    }

    isGrabbed = FALSE;
    xPosition = gCurrentSprite.xPosition;

    // Get X offset
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        xPosition += UNKNOWN_ITEM_CHOZO_STATUE_HAND_X_OFFSET;
    else
        xPosition -= UNKNOWN_ITEM_CHOZO_STATUE_HAND_X_OFFSET;

    if (gSpriteData[ramSlot].pose != UNKNOWN_ITEM_CHOZO_STATUE_POSE_IDLE)
        return;

    // Check in correct Y position
    if (gSamusData.yPosition != gCurrentSprite.yPosition - UNKNOWN_ITEM_CHOZO_STATUE_HAND_Y_OFFSET)
        return;

    // Check X range
    if (gSamusData.xPosition <= xPosition - QUARTER_BLOCK_SIZE || gSamusData.xPosition >= xPosition + QUARTER_BLOCK_SIZE)
        return;

    if (gSamusData.pose == SPOSE_MORPH_BALL)
    {
        #ifdef BUGFIX
        if (gPreventMovementTimer == 0)
        #endif // BUGFIX
        {
            // Set grabbed
            SamusSetPose(SPOSE_GRABBED_BY_CHOZO_STATUE);
            isGrabbed++;
        }
    }
    else if (gSamusData.pose == SPOSE_GRABBED_BY_CHOZO_STATUE)
    {
        // Already grabbed
        isGrabbed++;
    }

    if (isGrabbed)
    {
        gSpriteData[ramSlot].pose = UNKNOWN_ITEM_CHOZO_STATUE_POSE_REFILL_INIT;
        gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_REFILL;

        UnknownItemChozoStatuePartSyncSamusPosition();

        gCurrentSprite.pOam = sUnknownItemChozoStatuePartOam_ArmSamusGrabbed;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.work0 = CONVERT_SECONDS(.5f);
    }
}

/**
 * @brief 15a64 | 140 | Refills Samus
 * 
 */
static void UnknownItemChozoStatuePartArmRefill(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[ramSlot].pose != UNKNOWN_ITEM_CHOZO_STATUE_POSE_REFILL)
        return;

    if (gCurrentSprite.work0 == CONVERT_SECONDS(.5f) - DELTA_TIME * 0)
    {
        // Refill energy
        if (!SpriteUtilRefillEnergy())
        {
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            gEnergyRefillAnimation = 13;
        }
    }
    else if (gCurrentSprite.work0 == CONVERT_SECONDS(.5f) - DELTA_TIME * 1)
    {
        // Refill missiles
        if (gEnergyRefillAnimation != 0)
        {
            gEnergyRefillAnimation--;
        }
        else if (!SpriteUtilRefillMissiles())
        {
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            gMissileRefillAnimation = 13;
        }
    }
    else if (gCurrentSprite.work0 == CONVERT_SECONDS(.5f) - DELTA_TIME * 2)
    {
        // Refill super missiles
        if (gMissileRefillAnimation != 0)
        {
            gMissileRefillAnimation--;
        }
        else if (!SpriteUtilRefillSuperMissiles())
        {
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            gSuperMissileRefillAnimation = 13;
        }
    }
    else if (gCurrentSprite.work0 == CONVERT_SECONDS(.5f) - DELTA_TIME * 3)
    {
        // Refill power bombs
        if (gSuperMissileRefillAnimation != 0)
        {
            gSuperMissileRefillAnimation--;
        }
        else if (!SpriteUtilRefillPowerBombs())
        {
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            gPowerBombRefillAnimation = 13;
        }
    }
    else
    {
        // Check refill anim ended
        if (gPowerBombRefillAnimation != 0)
        {
            gPowerBombRefillAnimation--;
        }
        else if (gCurrentSprite.work0 != 0)
        {
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        }
        else
        {
            // Set sleeping
            gSpriteData[ramSlot].pose = UNKNOWN_ITEM_CHOZO_STATUE_POSE_SLEEPING_INIT;
            gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_SLEEPING_INIT;

            // Spawn refill correct ended message
            if (gEquipment.maxMissiles == 0 && gEquipment.maxSuperMissiles == 0 && gEquipment.maxPowerBombs == 0)
            {
                // Only energy
                SpriteSpawnPrimary(PSPRITE_MESSAGE_BANNER, MESSAGE_ENERGY_TANK_RECHARGE_COMPLETE, SPRITE_GFX_SLOT_SPECIAL,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            }
            else
            {
                // Energy and weapons
                SpriteSpawnPrimary(PSPRITE_MESSAGE_BANNER, MESSAGE_WEAPONS_AND_ENERGY_RESTORED, SPRITE_GFX_SLOT_SPECIAL,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            }
        }
    }
}

/**
 * @brief 15ba4 | 4 | Empty function
 * 
 */
static void UnknownItemChozoStatuePart_Empty(void)
{
    return;
}

/**
 * @brief 15ba8 | 28 | Initializes the arm part to be sleeping
 * 
 */
static void UnknownItemChozoStatuePartSleepingInit(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[ramSlot].pose == UNKNOWN_ITEM_CHOZO_STATUE_POSE_SLEEPING)
        gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_SLEEPING;
}

/**
 * @brief 15bd8 | 28 | Handles the arm part sleeping
 * 
 */
static void UnknownItemChozoStatuePartArmSleeping(void)
{
    // Check release samus
    if (gPreventMovementTimer == 0 && gCurrentSprite.pOam == sUnknownItemChozoStatuePartOam_ArmSamusGrabbed)
    {
        // Release samus
        gCurrentSprite.pOam = sUnknownItemChozoStatuePartOam_ArmIdle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        SamusSetPose(SPOSE_MORPH_BALL);
    }
}

/**
 * @brief 15c10 | 20 | Initializes the eye part to be opening
 * 
 */
static void UnknownItemChozoStatuePartEyeOpeningInit(void)
{
    gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_EYE_OPENING;

    gCurrentSprite.pOam = sUnknownItemChozoStatuePartOam_EyeOpening;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 15c30 | 2c | Handles the eye part opening
 * 
 */
static void UnknownItemChozoStatuePartEyeOpening(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_DO_NOTHING;

        // Set opened
        gCurrentSprite.pOam = sUnknownItemChozoStatuePartOam_EyeOpened;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 15c5c | 20 | Initializes the eye part to be closing
 * 
 */
static void UnknownItemChozoStatuePartEyeClosingInit(void)
{
    gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_EYE_CLOSING;

    gCurrentSprite.pOam = sUnknownItemChozoStatuePartOam_EyeClosing;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 15c7c | 2c | Handles the eye part closing
 * 
 */
static void UnknownItemChozoStatuePartEyeClosing(void)
{
    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_DO_NOTHING;

        // Set closed
        gCurrentSprite.pOam = sUnknownItemChozoStatuePartOam_EyeClosed;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 15c7c | 2c | Handles the leg part being idle
 * 
 */
static void UnknownItemChozoStatuePartLegIdle(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[ramSlot].pose == UNKNOWN_ITEM_CHOZO_STATUE_POSE_SITTING)
    {
        // Spawn echo
        if (gSubSpriteData1.work2 != 0)
            SpawnChozoStatueMovement(gSubSpriteData1.work2);
    }
    else if (gSpriteData[ramSlot].pose == UNKNOWN_ITEM_CHOZO_STATUE_POSE_DELAY_AFTER_SITTING)
    {
        gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_DO_NOTHING;
    }
}

/**
 * @brief 15cf0 | 148 | Unknown item chozo statue AI
 * 
 */
void UnknownItemChozoStatue(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            UnknownItemChozoStatueInit();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_POSE_IDLE:
            UnknownItemChozoStatue_Empty();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_POSE_REGISTER_HINT:
            UnknownItemChozoStatueRegisterHint();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_POSE_HINT_FLASHING:
            UnknownItemChozoStatueHintFlashing();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_POSE_SITTING_INIT:
            UnknownItemChozoStatueSittingInit();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_POSE_SITTING:
            UnknownItemChozoStatueSitting();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_POSE_DELAY_AFTER_SITTING:
            UnknownItemChozoStatueDelayBeforeRefillAfterHint();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_POSE_WAIT_FOR_ITEM_TO_BE_COLLECTED:
            UnknownItemChozoStatueWaitForItemToBeCollected();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_POSE_TIMER_AFTER_ITEM:
            UnknownItemChozoStatueTimerAfterItemGrabbed();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_POSE_REFILL_INIT:
            UnknownItemChozoStatueRefillInit();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_POSE_REFILL:
            UnknownItemChozoStatueRefillSamus();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_POSE_SLEEPING_INIT:
            UnknownItemChozoStatueSleepingInit();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_POSE_SLEEPING:
            UnknownItemChozoStatueSleeping();
    }

    SpriteUtilUpdateSubSprite1Anim();
    UnknownItemChozoStatueSyncSubSprites();
}

/**
 * @brief 15e38 | 248 | Unknown item chozo statue AI
 * 
 */
void UnknownItemChozoStatuePart(void)
{
    u8 ramSlot;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            UnknownItemChozoStatuePartInit();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_HINT:
            UnknownItemChozoStatuePartArmCheckGrabSamusHint();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_SITTING:
            UnknownItemChozoStatuePartArmSitting();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_SEATED:
            UnknownItemChozoStatuePartArmSeated();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_REFILL:
            UnknownItemChozoStatuePartArmCheckGrabSamusRefill();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_REFILL:
            UnknownItemChozoStatuePartArmRefill();
            UnknownItemChozoStatuePart_Empty();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_SLEEPING_INIT:
            UnknownItemChozoStatuePartSleepingInit();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_ARM_SLEEPING:
            UnknownItemChozoStatuePartArmSleeping();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_EYE_OPENING_INIT:
            UnknownItemChozoStatuePartEyeOpeningInit();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_EYE_OPENING:
            UnknownItemChozoStatuePartEyeOpening();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_EYE_CLOSING_INIT:
            UnknownItemChozoStatuePartEyeClosingInit();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_EYE_CLOSING:
            UnknownItemChozoStatuePartEyeClosing();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_LEG_IDLE:
            UnknownItemChozoStatuePartLegIdle();
            break;

        case UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_GLOW_IDLE:
            UnknownItemChozoStatuePartGlowIdle();

        case UNKNOWN_ITEM_CHOZO_STATUE_PART_POSE_DO_NOTHING:
            break;
    }

    if (gCurrentSprite.roomSlot == UNKNOWN_ITEM_CHOZO_STATUE_PART_LEG)
        UnknownItemChozoStatueSyncSubSprites();
    else
        SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOam();

    gCurrentSprite.paletteRow = gSpriteData[ramSlot].paletteRow;
}

/**
 * @brief 16080 | a8 | Unknown item chozo statue refill AI
 * 
 */
void UnknownItemChozoStatueRefill(void)
{
    u8 ramSlot;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawOrder = 1;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        
        gCurrentSprite.hitboxTop = PIXEL_SIZE;
        gCurrentSprite.hitboxBottom = PIXEL_SIZE;
        gCurrentSprite.hitboxLeft = PIXEL_SIZE;
        gCurrentSprite.hitboxRight = PIXEL_SIZE;

        gCurrentSprite.pose = UNKNOWN_ITEM_CHOZO_STATUE_REFILL_POSE_IDLE;

        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sUnknownItemChozoStatueRefillOam;

        SoundPlay(SOUND_CHOZO_STATUE_REFILL);
    }
    else if (gSpriteData[ramSlot].pose == UNKNOWN_ITEM_CHOZO_STATUE_POSE_SLEEPING)
    {
        gCurrentSprite.status = 0;
        SoundFade(SOUND_CHOZO_STATUE_REFILL, CONVERT_SECONDS(.5f));
    }
}

/**
 * @brief 16128 | 104 | Updates the clipdata for a standing chozo statue
 * 
 * @param bodyCaa Clipdata affecting action (for the body)
 * @param handCaa Clipdata affecting action (for the hand)
 */
void ChozoStatueStandingChangeClipdata(u8 bodyCaa, u8 handCaa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gSubSpriteData1.yPosition;
    xPosition = gSubSpriteData1.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        xPosition += HALF_BLOCK_SIZE;

        gCurrentClipdataAffectingAction = handCaa;
        ClipdataProcess(yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), xPosition + BLOCK_SIZE * 2);
        gCurrentClipdataAffectingAction = bodyCaa;
        ClipdataProcess(yPosition - (BLOCK_SIZE * 4 + HALF_BLOCK_SIZE), xPosition + BLOCK_SIZE * 1);
        gCurrentClipdataAffectingAction = bodyCaa;
        ClipdataProcess(yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), xPosition + BLOCK_SIZE * 1);
    }
    else
    {
        xPosition -= HALF_BLOCK_SIZE;

        gCurrentClipdataAffectingAction = handCaa;
        ClipdataProcess(yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), xPosition - BLOCK_SIZE * 2);
        gCurrentClipdataAffectingAction = bodyCaa;
        ClipdataProcess(yPosition - (BLOCK_SIZE * 4 + HALF_BLOCK_SIZE), xPosition - BLOCK_SIZE * 1);
        gCurrentClipdataAffectingAction = bodyCaa;
        ClipdataProcess(yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), xPosition - BLOCK_SIZE * 1);
    }

    gCurrentClipdataAffectingAction = bodyCaa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 0 + HALF_BLOCK_SIZE), xPosition);

    gCurrentClipdataAffectingAction = bodyCaa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 1 + HALF_BLOCK_SIZE), xPosition);

    gCurrentClipdataAffectingAction = bodyCaa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), xPosition);

    gCurrentClipdataAffectingAction = bodyCaa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), xPosition);

    gCurrentClipdataAffectingAction = bodyCaa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 4 + HALF_BLOCK_SIZE), xPosition);
}

/**
 * @brief 1622c | 80 | Updates the clipdata of a seated chozo statue
 * 
 * @param caa Clipdata affecting action
 */
void ChozoStatueSeatedChangeClipdata(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gSubSpriteData1.yPosition;
    xPosition = gSubSpriteData1.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition - HALF_BLOCK_SIZE, xPosition + HALF_BLOCK_SIZE);
        xPosition -= HALF_BLOCK_SIZE;
    }
    else
    {
        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition - HALF_BLOCK_SIZE, xPosition - HALF_BLOCK_SIZE);
        xPosition += HALF_BLOCK_SIZE;
    }

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 0 + HALF_BLOCK_SIZE), xPosition);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 1 + HALF_BLOCK_SIZE), xPosition);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), xPosition);
}
