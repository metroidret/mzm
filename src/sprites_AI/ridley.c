#include "sprites_AI/ridley.h"
#include "gba.h"
#include "macros.h"

#include "data/sprites/ridley.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/color_fading.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/particle.h"

#include "structs/connection.h"
#include "structs/clipdata.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/samus.h"
#include "structs/scroll.h"
#include "structs/sprite.h"

#define RIDLEY_GROUND_POSITION (BLOCK_SIZE * 18 - ONE_SUB_PIXEL)

#define RIDLEY_POSE_CHECK_PLAY_CUTSCENE 0x1
#define RIDLEY_POSE_SPAWNING 0x2
#define RIDLEY_POSE_IDLE_INIT 0x8
#define RIDLEY_POSE_IDLE 0x9
#define RIDLEY_POSE_TURNING_AROUND_INIT 0xA
#define RIDLEY_POSE_TURNING_AROUND_FIRST_PART 0xB
#define RIDLEY_POSE_TURNING_AROUND_SECOND_PART 0xC
#define RIDLEY_POSE_SMALL_FIREBALLS_ATTACK_INIT 0x22
#define RIDLEY_POSE_SMALL_FIREBALLS_ATTACK 0x23
#define RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK_INIT 0x2A
#define RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK 0x2B
#define RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT 0x2C
#define RIDLEY_POSE_BIG_FIREBALLS_ATTACK 0x2D
#define RIDLEY_POSE_TAIL_ATTACKS_INIT 0x34
#define RIDLEY_POSE_TAIL_ATTACKS 0x35
#define RIDLEY_POSE_DYING 0x67

// Spawning
enum RidleySpawningAction {
    RIDLEY_SPAWNING_ACTION_GOING_DOWN,
    RIDLEY_SPAWNING_ACTION_DELAY_BEFORE_OPENING_MOUTH,
    RIDLEY_SPAWNING_ACTION_OPENING_MOUTH,
    RIDLEY_SPAWNING_ACTION_SPITTING_FIREBALLS,
    RIDLEY_SPAWNING_ACTION_CLOSING_MOUTH,
    RIDLEY_SPAWNING_ACTION_TURNING_AROUND_INIT,
    RIDLEY_SPAWNING_ACTION_TURNING_AROUND_FIRST_PART,
    RIDLEY_SPAWNING_ACTION_TURNING_AROUND_SECOND_PART,
    RIDLEY_SPAWNING_ACTION_TAKING_OFF,
    RIDLEY_SPAWNING_ACTION_UNKNOWN,
};

// Samus grabbed
enum RidleySamusGrabbedAction {
    RIDLEY_SAMUS_GRABBED_ACTION_NONE,
    RIDLEY_SAMUS_GRABBED_ACTION_CARRYING_SAMUS,
    RIDLEY_SAMUS_GRABBED_ACTION_LIFTING_SAMUS,
    RIDLEY_SAMUS_GRABBED_ACTION_SAMUS_LIFTED,
    RIDLEY_SAMUS_GRABBED_ACTION_OPENING_MOUTH,
    RIDLEY_SAMUS_GRABBED_ACTION_SPITTING_FIREBALLS,
    RIDLEY_SAMUS_GRABBED_ACTION_RELEASING_SAMUS
};


// Small fireball attack
enum RidleySmallFireballsAttackAction {
    RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_GOING_DOWN,
    RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_DELAY_BEFORE_OPENING_MOUTH,
    RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_OPENING_MOUTH,
    RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_SPITTING_FIREBALLS,
    RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_CLOSING_MOUTH,
    RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_5,
    RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_6,
    RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_7,
    RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_TAKING_OFF
};

#define RIDLEY_LEFT_HITBOX (BLOCK_SIZE * 2)
#define RIDLEY_RIGHT_HITBOX (BLOCK_SIZE + HALF_BLOCK_SIZE)

// Ridley tail

#define RIDLEY_TAIL_POSE_IDLE 0x9
#define RIDLEY_TAIL_POSE_MOVE_TO_ATTACK 0x43
#define RIDLEY_TAIL_POSE_SETTING_UP_ATTACK 0x45
#define RIDLEY_TAIL_POSE_CHARGING_ATTACK 0x47
#define RIDLEY_TAIL_POSE_FIRST_VERTICAL_ATTACK 0x49
#define RIDLEY_TAIL_POSE_VERTICAL_ATTACK 0x4B
#define RIDLEY_TAIL_POSE_LAST_VERTICAL_ATTACK 0x4D
#define RIDLEY_TAIL_POSE_DIAGONAL_ATTACK 0x4F
#define RIDLEY_TAIL_POSE_BACK_TO_IDLE 0x51

// Ridley part

#define RIDLEY_PART_POSE_IDLE 0x9
#define RIDLEY_PART_POSE_DYING 0x62

#define CLAW_LEFT_HITBOX (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE)
#define CLAW_RIGHT_HITBOX (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE)

// Ridley fireball

enum RidleyFireballType {
    RIDLEY_FIREBALL_TYPE_TOP,
    RIDLEY_FIREBALL_TYPE_MIDDLE_TOP,
    RIDLEY_FIREBALL_TYPE_MIDDLE,
    RIDLEY_FIREBALL_TYPE_MIDDLE_BOTTOM,
    RIDLEY_FIREBALL_TYPE_BOTTOM,

    RIDLEY_FIREBALL_TYPE_FLOATING_PATTERN = 1 << 7,
    RIDLEY_FIREBALL_TYPE_SAMUS_GRABBED = RIDLEY_FIREBALL_TYPE_FLOATING_PATTERN | 8
};

#define RIDLEY_FIREBALL_POSE_MOVE_DESCENDING_PATTERN 0x9
#define RIDLEY_FIREBALL_POSE_MOVE_ASCENDING_PATTERN 0x23
#define RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL_INIT 0x24
#define RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL 0x25
#define RIDLEY_FIREBALL_POSE_MOVE_FLOATING_PATTERN 0x27
#define RIDLEY_FIREBALL_POSE_MOVE_DIAGONAL_PATTERN 0x29
#define RIDLEY_FIREBALL_POSE_DESTROY 0x42

#define RIDLEY_FIREBALL_ASCENDING_Y_TARGET_OFFSET (THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE / 2)

static const struct FrameData* sRidleyFrameDataPointers[RIDLEY_OAM_END] = {
    [RIDLEY_OAM_IDLE] = sRidleyOam_Idle,
    [RIDLEY_OAM_SPITTING_FIREBALLS] = sRidleyOam_SpittingFireballs,
    [RIDLEY_OAM_TURNING_AROUND_FIRST_PART] = sRidleyOam_TurningAroundFirstPart,
    [RIDLEY_OAM_TURNING_AROUND_SECOND_PART] = sRidleyOam_TurningAroundSecondPart,
    [RIDLEY_OAM_HEAD_IDLE] = sRidleyPartOam_HeadIdle,
    [RIDLEY_OAM_OPENING_MOUTH] = sRidleyPartOam_OpeningMouth,
    [RIDLEY_OAM_MOUTH_OPENED] = sRidleyPartOam_MouthOpened,
    [RIDLEY_OAM_HEAD_DYING] = sRidleyPartOam_HeadDying,
    [RIDLEY_OAM_HEAD_TURNING_AROUND] = sRidleyPartOam_HeadTurningAround,
    [RIDLEY_OAM_CLAW_IDLE] = sRidleyPartOam_ClawIdle,
    [RIDLEY_OAM_CLAW_SPITTING_FIREBALLS] = sRidleyPartOam_ClawSpittingFireballs,
    [RIDLEY_OAM_CLAW_TURNING_AROUND_FIRST_PART] = sRidleyPartOam_ClawTurningAroundFirstPart,
    [RIDLEY_OAM_CLAW_TURNING_AROUND_SECOND_PART] = sRidleyPartOam_ClawTurningAroundSecondPart,
    [RIDLEY_OAM_CLAW_CARRYING_SAMUS] = sRidleyPartOam_ClawCarryingSamus,
    [RIDLEY_OAM_CLAW_LIFTING_SAMUS] = sRidleyPartOam_ClawLiftingSamus,
    [RIDLEY_OAM_CLAW_SAMUS_LIFTED] = sRidleyPartOam_ClawSamusLifted,
    [RIDLEY_OAM_CLAW_RELEASING_SAMUS] = sRidleyPartOam_ClawReleasingSamus,
    [RIDLEY_OAM_LEFT_WING_IDLE] = sRidleyPartOam_LeftWingIdle,
    [RIDLEY_OAM_RIGHT_WING_IDLE] = sRidleyPartOam_RightWingIdle,
    [RIDLEY_OAM_LEFT_WING_UNUSED] = sRidleyPartOam_LeftWing_Unused,
    [RIDLEY_OAM_RIGHT_WING_UNUSED] = sRidleyPartOam_RightWing_Unused,
    [RIDLEY_OAM_LEFT_WING_SPITTING_FIREBALLS] = sRidleyPartOam_LeftWingSpittingFireballs,
    [RIDLEY_OAM_RIGHT_WING_SPITTING_FIREBALLS] = sRidleyPartOam_RightWingSpittingFireballs,
    [RIDLEY_OAM_TAIL_PART] = sRidleyTailOam_Part,
    [RIDLEY_OAM_TAIL_TIP_POINTING_DOWN] = sRidleyTailOam_TipPointingDown,
    [RIDLEY_OAM_TAIL_TIP_POINTING_UP] = sRidleyTailOam_TipPointingUp,
    [RIDLEY_OAM_TAIL_TIP_POINTING_DIAGONALLY_DOWN_RIGHT] = sRidleyTailOam_TipPointingDiagonallyDownRight,
    [RIDLEY_OAM_TAIL_TIP_POINTING_DIAGONALLY_UP_RIGHT] = sRidleyTailOam_TipPointingDiagonallyUpRight,
    [RIDLEY_OAM_TAIL_TIP_POINTING_DIAGONALLY_DOWN_LEFT] = sRidleyTailOam_TipPointingDiagonallyDownLeft,
    [RIDLEY_OAM_TAIL_TIP_POINTING_DIAGONALLY_UP_LEFT] = sRidleyTailOam_TipPointingDiagonallyUpLeft,
    [RIDLEY_OAM_SQUARE] = sRidleyOam_Square,
    [RIDLEY_OAM_FIREBALL_SMALL] = sRidleyFireballOam_Small,
    [RIDLEY_OAM_FIREBALL_BIG] = sRidleyFireballOam_Big
};

/**
 * @brief 31aa4 | 9c | Synchronize the sub sprites of Ridley
 * 
 */
static void RidleySyncSubSprites(void)
{
    MultiSpriteDataInfo_T pData;
    u16 oamIdx;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];
    
    if (gCurrentSprite.pOam != sRidleyFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sRidleyFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition - pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
    else
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];

    if (gCurrentSprite.roomSlot == RIDLEY_PART_TAIL)
    {
        gSubSpriteData2.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData2.xPosition = gCurrentSprite.xPosition;
    }
}

/**
 * @brief 31b40 | 88 | Synchronize the sub sprites of the Ridley tail
 * 
 */
static void RidleyTailSyncSubSprites(void)
{
    MultiSpriteDataInfo_T pData;
    u16 oamIdx;

    pData = gSubSpriteData2.pMultiOam[gSubSpriteData2.currentAnimationFrame].pData;
    oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];
    
    if (gCurrentSprite.pOam != sRidleyFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sRidleyFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = gSubSpriteData2.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition = gSubSpriteData2.xPosition - pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
    else
        gCurrentSprite.xPosition = gSubSpriteData2.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

/**
 * @brief 31bc8 | 44 | Handles the floating Y movement when idle
 * 
 */
static void RidleyIdleYFloatingMovement(void)
{
    u8 offset;
    s32 movement;

    offset = gCurrentSprite.work3;
    movement = sRidleyIdleYOffsets[offset];
    if (movement == SHORT_MAX)
    {
        movement = sRidleyIdleYOffsets[0]; // 0
        offset = 0;
    }

    gCurrentSprite.work3 = offset + 1;
    gSubSpriteData1.yPosition += movement;
}

/**
 * @brief 31c0c | 4c | Handles the floating Y movement when spitting fireballs after spawning
 * 
 */
static void RidleySpawnSpittingFireballsYFloatingMovement(void)
{
    u8 offset;
    s32 movement;

    if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
    {
        offset = gCurrentSprite.work3;
        movement = sRidleySpawningSpittingFireballsYOffsets[offset];
        if (movement == SHORT_MAX)
        {
            movement = sRidleySpawningSpittingFireballsYOffsets[0]; // 0
            offset = 0;
        }

        gCurrentSprite.work3 = offset + 1;
        gSubSpriteData1.yPosition += movement;
    }
}

/**
 * @brief 31c58 | 180 | Updates the health of Ridley
 * 
 */
static void RidleyUpdateHealth(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
        case RIDLEY_POSE_CHECK_PLAY_CUTSCENE:
        case RIDLEY_POSE_SPAWNING:
        case RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK_INIT:
        case RIDLEY_POSE_BIG_FIREBALLS_ATTACK:
        case RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT:
        case RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK:
        case RIDLEY_POSE_TAIL_ATTACKS_INIT:
        case RIDLEY_POSE_TAIL_ATTACKS:
            gBossWork.work3 = 0;
            break;

        default:
            if (SPRITE_GET_ISFT(gCurrentSprite) == CONVERT_SECONDS(.25f + 1.f / 60))
                SoundPlayNotAlreadyPlaying(SOUND_RIDLEY_DAMAGED);

            if (gCurrentSprite.health == 0 && gSubSpriteData1.health != 0)
            {
                // Dead
                gCurrentSprite.pose = RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK_INIT;
                gBossWork.work3 = 0;
            }
            else
            {
                // Update received damage
                gBossWork.work3 += gSubSpriteData1.health - gCurrentSprite.health;
                if (gBossWork.work3 > 200)
                {
                    // Agressive threshold, set big fireballs
                    gCurrentSprite.pose = RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK_INIT;
                    gBossWork.work3 = 0;
                }
            }

            gSubSpriteData1.health = gCurrentSprite.health;
    }
}

/**
 * @brief 31dd8 | 68 | Checks if Ridley is grabbing Samus
 * 
 * @param yPosition Y position
 * @param xPosition X position
 * @return u8 bool, grabbing
 */
u32 RidleyCheckGrabbing(u16 yPosition, u16 xPosition)
{
    u16 xOffset;
    
    yPosition += BLOCK_SIZE * 4;

    if (gSamusData.xPosition > xPosition)
        xOffset = xPosition + (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE);
    else
        xOffset = xPosition - (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE);

    if (SpriteUtilGetCollisionAtPosition(yPosition, xOffset + gSamusPhysics.hitboxLeft) == COLLISION_AIR &&
        SpriteUtilGetCollisionAtPosition(yPosition, xOffset + gSamusPhysics.hitboxRight) == COLLISION_AIR)
    {
        return TRUE;
    }

    return FALSE;
}

/**
 * @brief 31e40 | 256 | Handles the claw being idle
 * 
 * @param ramSlot Ridley's ram slot
 */
static void RidleyPartClawIdle(u8 ramSlot)
{
    u8 updatePosition;
    u8 interval;
    u16 yPosition;
    u16 xPosition;

    updatePosition = FALSE;

    // Check samus is grabbed
    if (!(gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING))
        return;

    // Get damage interval
    if (gDifficulty == DIFF_EASY)
    {
        if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
            interval = CONVERT_SECONDS(2.f / 15) - 1;
        else
            interval = CONVERT_SECONDS(1.f / 15) - 1;
    }
    else if (gDifficulty == DIFF_HARD)
    {
        if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
            interval = CONVERT_SECONDS(1.f / 30) - 1;
        else
            interval = CONVERT_SECONDS(1.f / 60) - 1;
    }
    else
    {
        if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
            interval = CONVERT_SECONDS(1.f / 15) - 1;
        else
            interval = CONVERT_SECONDS(1.f / 30) - 1;
    }

    // Apply damage
    if (!(gFrameCounter8Bit & interval))
    {
        if (gEquipment.currentEnergy > 1)
        {
            // Damage
            gEquipment.currentEnergy--;
            gSamusData.invincibilityTimer = CONVERT_SECONDS(.15f - 1.f / 60);
        }
        else
        {
            // Kill samus
            gEquipment.currentEnergy = 0;
            SamusSetPose(SPOSE_HURT_REQUEST);
        }
    }

    if (gSamusData.pose != SPOSE_MIDAIR)
        SamusSetPose(SPOSE_MIDAIR);

    // Get Samus position
    switch (gCurrentSprite.work1)
    {
        case RIDLEY_SAMUS_GRABBED_ACTION_NONE:
        case RIDLEY_SAMUS_GRABBED_ACTION_CARRYING_SAMUS:
            updatePosition++;

            yPosition = gCurrentSprite.yPosition + BLOCK_SIZE * 4;
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE);
            else
                xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE);
            break;

        case RIDLEY_SAMUS_GRABBED_ACTION_LIFTING_SAMUS:
            updatePosition++;

            switch (gCurrentSprite.currentAnimationFrame)
            {
                case 0:
                    yPosition = gCurrentSprite.yPosition + BLOCK_SIZE * 3 + THREE_QUARTER_BLOCK_SIZE - PIXEL_SIZE;
                    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                        xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 3 - EIGHTH_BLOCK_SIZE);
                    else
                        xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE * 3 - EIGHTH_BLOCK_SIZE);
                    break;
                
                case 1:
                    yPosition = gCurrentSprite.yPosition + BLOCK_SIZE * 3 + HALF_BLOCK_SIZE - PIXEL_SIZE;
                    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                        xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE);
                    else
                        xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE);
                    break;
                
                case 2:
                    yPosition = gCurrentSprite.yPosition + BLOCK_SIZE * 3;
                    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                        xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 3 + THREE_QUARTER_BLOCK_SIZE - PIXEL_SIZE);
                    else
                        xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE * 3 + THREE_QUARTER_BLOCK_SIZE - PIXEL_SIZE);
                    break;
                
                case 3:
                    yPosition = gCurrentSprite.yPosition + BLOCK_SIZE * 2 + HALF_BLOCK_SIZE - PIXEL_SIZE;
                    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                        xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE);
                    else
                        xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE);
                    break;
                
                case 4:
                    yPosition = gCurrentSprite.yPosition + BLOCK_SIZE * 2 - PIXEL_SIZE;
                    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                        xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE);
                    else
                        xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE);
                    break;
            }
            break;

        case RIDLEY_SAMUS_GRABBED_ACTION_SAMUS_LIFTED:
        case RIDLEY_SAMUS_GRABBED_ACTION_OPENING_MOUTH:
        case RIDLEY_SAMUS_GRABBED_ACTION_SPITTING_FIREBALLS:
            updatePosition++;

            yPosition = gCurrentSprite.yPosition + BLOCK_SIZE + HALF_BLOCK_SIZE;

            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                xPosition = gCurrentSprite.xPosition + BLOCK_SIZE * 4;
            else
                xPosition = gCurrentSprite.xPosition - BLOCK_SIZE * 4;
            break;
    }

    if (updatePosition)
    {
        if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gSamusPhysics.hitboxLeft) == COLLISION_AIR &&
            SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gSamusPhysics.hitboxRight) == COLLISION_AIR)
        {
            gSamusData.yPosition = yPosition;
            gSamusData.xPosition = xPosition;
        }
        else
        {
            // Release
            gSpriteData[ramSlot].pose = RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT;
            gBossWork.work3 = 0;
        }
    }
    
}

/**
 * @brief 320a8 | 30 | Checks if a screen shake should start when Ridley does the vertical tail attack
 * 
 */
static void RidleyTailCheckStartScreenShakeVerticalTailAttack(void)
{
    if (gCurrentSprite.yPositionSpawn + QUARTER_BLOCK_SIZE + PIXEL_SIZE < RIDLEY_GROUND_POSITION &&
        gCurrentSprite.yPosition + QUARTER_BLOCK_SIZE + PIXEL_SIZE > RIDLEY_GROUND_POSITION - ONE_SUB_PIXEL)
    {
        ScreenShakeStartVertical(ONE_THIRD_SECOND, 0x80 | 1);
    }

    gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
}

/**
 * @brief 320d8 | b0 | Handles Ridley's X movement when doing a tail attack
 * 
 * @param movement X Movement
 * @return u8  1 if hitting solid, 0 otherwise
 */
static u8 RidleyTailAttacksXMove(u16 movement)
{
    u8 ramSlot;
    u8 result;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    result = FALSE;
    
    if (gSpriteData[ramSlot].status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Check on right
        SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition + BLOCK_SIZE,
            gSubSpriteData1.xPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE));

        if (gPreviousCollisionCheck != COLLISION_AIR)
            result = TRUE;
        else
            gSubSpriteData1.xPosition += movement;
    }
    else
    {
        // Check on left
        SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition + BLOCK_SIZE,
            gSubSpriteData1.xPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE));

        if (gPreviousCollisionCheck != COLLISION_AIR)
            result = TRUE;
        else
            gSubSpriteData1.xPosition -= movement;
    }

    // Check flip
    if (result)
        gSpriteData[ramSlot].status ^= SPRITE_STATUS_FACING_RIGHT;
    
    return result;
}

/**
 * @brief 32188 | 44 | Handles Ridley's Y movement when doing a tail attack
 * 
 * @param movement Y Movement
 */
static void RidleyTailAttacksYMove(u16 movement)
{
    if (gSamusData.yPosition >= gSubSpriteData1.yPosition &&
        gSubSpriteData1.yPosition < (BLOCK_SIZE * 11 + HALF_BLOCK_SIZE) &&
        gCurrentSprite.yPosition + QUARTER_BLOCK_SIZE + PIXEL_SIZE < RIDLEY_GROUND_POSITION)
    {
        gSubSpriteData1.yPosition += movement;
    }
}

/**
 * @brief 321cc | 58 | Spawns an ascending fireball
 * 
 * @param timer Influences room slot
 */
static void RidleySpawnAscendingFireball(u16 timer)
{
    u16 status;
    u16 xPosition;
    u16 yPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        status = SPRITE_STATUS_FACING_RIGHT;
        xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE);
    }
    else
    {
        status = 0;
        xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE);
    }

    yPosition = gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE);
    SpriteSpawnSecondary(SSPRITE_RIDLEY_FIREBALL, MOD_AND(timer / 16, 16), gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, status);
}

/**
 * @brief 32224 | 284 | Initializes Ridley
 * 
 */
static void RidleyInit(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u16 health;
    u8 ramSlot;
    u8 caa;

    gBossWork.work1 = gCurrentSprite.yPosition;
    gBossWork.work2 = gCurrentSprite.xPosition;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_KILLED))
    {
        // Already dead, destroy blocks
        yPosition = gBossWork.work1 + (BLOCK_SIZE * 6 + HALF_BLOCK_SIZE);
        xPosition = gBossWork.work2;
        caa = CAA_REMOVE_SOLID;

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 6);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 5);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 6);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 7);

        gCurrentSprite.status = 0;
        return;
    }
    
    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_GRAVITY_SUIT_OBTAINED))
    {
        // Has gravity
        gCurrentSprite.status = 0;
        return;
    }

    // Lock doors
    LOCK_DOORS();

    gCurrentSprite.drawOrder = 8;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
    gCurrentSprite.hitboxBottom = BLOCK_SIZE * 2;
    
    // Move in ceiling
    gCurrentSprite.yPosition -= BLOCK_SIZE * 8;
    gCurrentSprite.xPosition -= BLOCK_SIZE;

    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

    health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.health = health;
    gSubSpriteData1.health = health;

    // Damage threshold
    gBossWork.work3 = 0;

    gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = RIDLEY_POSE_CHECK_PLAY_CUTSCENE;
    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_X_FLIP | SPRITE_STATUS_FACING_RIGHT | SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.roomSlot = RIDLEY_PART_BODY;

    yPosition = gSubSpriteData1.yPosition;
    xPosition = gSubSpriteData1.xPosition;
    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    // Spawn left wing
    SpriteSpawnSecondary(SSPRITE_RIDLEY_PART, RIDLEY_PART_LEFT_WING, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    // Spawn head
    gSubSpriteData1.work4 = SpriteSpawnSecondary(SSPRITE_RIDLEY_PART, RIDLEY_PART_HEAD,
        gfxSlot, ramSlot, yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    // Spawn tail
    SpriteSpawnSecondary(SSPRITE_RIDLEY_PART, RIDLEY_PART_TAIL, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_TIP, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_LEFT_MOST, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_LEFT_MIDDLE, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_LEFT_RIGHT, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_RIGHT_MOST, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_RIGHT_MIDDLE, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_RIGHT_LEFT, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_BODY_ATTACHMENT, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    // Spawn claw
    gSubSpriteData1.work5 = SpriteSpawnSecondary(SSPRITE_RIDLEY_PART, RIDLEY_PART_CLAW,
        gfxSlot, ramSlot, yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    // Spawn right wing
    SpriteSpawnSecondary(SSPRITE_RIDLEY_PART, RIDLEY_PART_RIGHT_WING, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);
}

/**
 * @brief 324a8 | b4 | Checks if the cutscene should play
 * 
 */
static void RidleyCheckPlayCutscene(void)
{
    u16 spriteX;
    u16 samusX;
    u8 inRange;

    inRange = FALSE;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gSamusData.yPosition == RIDLEY_GROUND_POSITION)
    {
        spriteX = gBossWork.work2 + HALF_BLOCK_SIZE;
        samusX = gSamusData.xPosition;

        if (spriteX + BLOCK_SIZE * 5 > samusX && spriteX + BLOCK_SIZE * 4 < samusX)
        {
            // Left of platform
            inRange++;
        }
        else if (spriteX + BLOCK_SIZE * 7 < samusX)
        {
            // Near door
            inRange++;
        }

        // In range and facing left
        if (inRange && gSamusData.direction & KEY_LEFT)
        {
            gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
            gCurrentSprite.pose = RIDLEY_POSE_SPAWNING;

            gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;

            gCurrentSprite.work1 = 0;
            gCurrentSprite.work3 = 0;

            // Timer
            gCurrentSprite.scaling = CONVERT_SECONDS(5.f);

            StartEffectForCutscene(EFFECT_CUTSCENE_RIDLEY_SPAWN);
        }
    }
}

/**
 * @brief 3255c | 6e4 | Handles Ridley spawning
 * 
 */
static void RidleySpawning(void)
{
    u16 yPosition;
    u16 yMovement;
    u16 xPosition;
    u8 turning;

    turning = FALSE;
    switch (gCurrentSprite.work1)
    {
        case RIDLEY_SPAWNING_ACTION_GOING_DOWN:
            // Move down
            yMovement = gSubSpriteData1.yPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            if (yMovement < RIDLEY_GROUND_POSITION)
            {
                yMovement = RIDLEY_GROUND_POSITION - yMovement;
                if (yMovement > HALF_BLOCK_SIZE)
                    yMovement = HALF_BLOCK_SIZE;

                gSubSpriteData1.yPosition += yMovement;
            }
            else
            {
                yPosition = gBossWork.work1 + (BLOCK_SIZE * 6 + HALF_BLOCK_SIZE);
                xPosition = gBossWork.work2;
                if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition - BLOCK_SIZE * 6) != COLLISION_AIR)
                {
                    // Destroy ground
                    turning = CAA_REMOVE_SOLID;

                    // Left blocks
                    gCurrentClipdataAffectingAction = turning;
                    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 6);

                    gCurrentClipdataAffectingAction = turning;
                    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 5);
                    
                    // Right blocks
                    gCurrentClipdataAffectingAction = turning;
                    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 6);
                    
                    gCurrentClipdataAffectingAction = turning;
                    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 7);

                    ParticleSet(yPosition + HALF_BLOCK_SIZE, xPosition - (BLOCK_SIZE * 5 + HALF_BLOCK_SIZE), PE_SPRITE_EXPLOSION_HUGE);
                    ParticleSet(yPosition + HALF_BLOCK_SIZE, xPosition + (BLOCK_SIZE * 6 + HALF_BLOCK_SIZE), PE_SPRITE_EXPLOSION_HUGE);
                    SoundPlay(SOUND_RIDLEY_EXPLODING_GROUND);
                }

                gSubSpriteData1.yPosition = RIDLEY_GROUND_POSITION - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                ScreenShakeStartVertical(CONVERT_SECONDS(.5f), 0x80 | 1);

                gCurrentSprite.work1++;
                gCurrentSprite.work0 = CONVERT_SECONDS(.5f);
                gCurrentSprite.work3 = 0;

                SoundPlay(SOUND_RIDLEY_HITTING_GROUND);
            }
            break;

        case RIDLEY_SPAWNING_ACTION_DELAY_BEFORE_OPENING_MOUTH:
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (gCurrentSprite.work0 == 0)
            {
                gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_OpeningMouth;
                gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;

                SoundPlay(SOUND_RIDLEY_OPENING_MOUTH);
                gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 12);
                gCurrentSprite.work1++;
            }
            break;

        case RIDLEY_SPAWNING_ACTION_OPENING_MOUTH:
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (gCurrentSprite.work0 == 0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_SpittingFireballs;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_MouthOpened;
                gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.work5].pOam = sRidleyPartOam_ClawSpittingFireballs;
                gSpriteData[gSubSpriteData1.work5].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.work5].currentAnimationFrame = 0;

                gCurrentSprite.work1++;
                SoundPlay(SOUND_RIDLEY_SPITTING_FIREBALLS);
            }
            break;

        case RIDLEY_SPAWNING_ACTION_SPITTING_FIREBALLS:
            // Spawn fireballs
            if (MOD_AND(gCurrentSprite.scaling, CONVERT_SECONDS(.25f + 1.f / 60)) == 0)
                RidleySpawnAscendingFireball(gCurrentSprite.scaling);

            if (gCurrentSprite.scaling != 0)
            {
                APPLY_DELTA_TIME_DEC(gCurrentSprite.scaling);

                // Check turn if samus is behind
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                        turning++;
                }
                else
                {
                    if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                        turning++;
                }

                if (!turning)
                    break;
            }
            
            gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_OpeningMouth;
            gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
            gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;

            gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 12);
            gCurrentSprite.work1++;
            SoundFade(SOUND_RIDLEY_SPITTING_FIREBALLS, CONVERT_SECONDS(.5f));
            break;

        case RIDLEY_SPAWNING_ACTION_CLOSING_MOUTH:
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (gCurrentSprite.work0 == 0)
            {
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_HeadIdle;
                gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.work5].pOam = sRidleyPartOam_ClawIdle;
                gSpriteData[gSubSpriteData1.work5].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.work5].currentAnimationFrame = 0;

                // Check turning
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                        turning++;
                }
                else
                {
                    if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                        turning++;
                }

                if (turning)
                {
                    // Set turning
                    gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);
                    gCurrentSprite.work1++;
                }
                else
                {
                    // Set taking off
                    gCurrentSprite.work1 = RIDLEY_SPAWNING_ACTION_TAKING_OFF;
                    gCurrentSprite.work0 = CONVERT_SECONDS(.5f);
                }
            }
            break;

        case RIDLEY_SPAWNING_ACTION_TURNING_AROUND_INIT:
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (gCurrentSprite.work0 == 0)
            {
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_TurningAroundFirstPart;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_HeadTurningAround;
                gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.work5].pOam = sRidleyPartOam_ClawTurningAroundFirstPart;
                gSpriteData[gSubSpriteData1.work5].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.work5].currentAnimationFrame = 0;

                gCurrentSprite.work1++;
            }
            break;
            
        case RIDLEY_SPAWNING_ACTION_TURNING_AROUND_FIRST_PART:
            if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_TurningAroundSecondPart;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.work5].pOam = sRidleyPartOam_ClawTurningAroundSecondPart;
                gSpriteData[gSubSpriteData1.work5].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.work5].currentAnimationFrame = 0;

                gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.work1++;

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
                else
                    gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            }
            break;
            
        case RIDLEY_SPAWNING_ACTION_TURNING_AROUND_SECOND_PART:
            if (SpriteUtilHasSubSprite1AnimationEnded())
            {
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_HeadIdle;
                gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.work5].pOam = sRidleyPartOam_ClawIdle;
                gSpriteData[gSubSpriteData1.work5].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.work5].currentAnimationFrame = 0;

                gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);
                gCurrentSprite.work1 = RIDLEY_SPAWNING_ACTION_DELAY_BEFORE_OPENING_MOUTH;
            }
            break;

        case RIDLEY_SPAWNING_ACTION_TAKING_OFF:
            if (gCurrentSprite.work0 == 0)
            {
                // Move Y on 8 blocks
                yMovement = RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8;
                if (yMovement < gSubSpriteData1.yPosition)
                {
                    yMovement = gSubSpriteData1.yPosition - (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8);
                    yMovement /= 4;

                    CLAMP(yMovement, PIXEL_SIZE, HALF_BLOCK_SIZE);

                    gSubSpriteData1.yPosition -= yMovement;
                }
                else
                {
                    // Set idle
                    gCurrentSprite.pose = RIDLEY_POSE_IDLE_INIT;
                    gSubSpriteData1.health = gCurrentSprite.health;
                }
            }
            else
            {
                APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            }

            return;

        case RIDLEY_SPAWNING_ACTION_UNKNOWN:
            if (gCurrentSprite.work0 != 0)
            {
                APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
                return;
            }

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition,
                    gSubSpriteData1.xPosition + (BLOCK_SIZE * 5 + THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3)) != COLLISION_AIR)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                else
                    gSubSpriteData1.xPosition += QUARTER_BLOCK_SIZE;
            }
            else
            {
                if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition,
                    gSubSpriteData1.xPosition - (BLOCK_SIZE * 5 + THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3)) != COLLISION_AIR)
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                else
                    gSubSpriteData1.xPosition -= QUARTER_BLOCK_SIZE;
            }

            if (APPLY_DELTA_TIME_DEC(gCurrentSprite.work2) == 0)
            {
                if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                    gCurrentSprite.status |= (SPRITE_STATUS_X_FLIP | SPRITE_STATUS_FACING_RIGHT);
                else
                    gCurrentSprite.status &= ~(SPRITE_STATUS_X_FLIP | SPRITE_STATUS_FACING_RIGHT);
                
                gCurrentSprite.work1 = RIDLEY_SPAWNING_ACTION_GOING_DOWN;
            }

        default:
            return;
    }
    
    RidleySpawnSpittingFireballsYFloatingMovement();
}

/**
 * @brief 32c40 | b8 | Initializes Ridley to be idle
 * 
 */
static void RidleyIdleInit(void)
{
    u8 clawSlot;
    u16 range;

    clawSlot = gSubSpriteData1.work5;

    // Update multi sprite data
    gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    // Update head
    gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_HeadIdle;
    gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
    gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;

    // Update claw
    gSpriteData[clawSlot].pOam = sRidleyPartOam_ClawIdle;
    gSpriteData[clawSlot].animationDurationCounter = 0;
    gSpriteData[clawSlot].currentAnimationFrame = 0;
    gSpriteData[clawSlot].samusCollision = SSC_RIDLEY_CLAW;

    gCurrentSprite.work1 = 0;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.pose = RIDLEY_POSE_IDLE;

    range = BLOCK_SIZE * 10 - ONE_SUB_PIXEL;
    if (range < gSubSpriteData1.yPosition)
    {
        gCurrentSprite.work0 = 0;
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
    }
    else
    {
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f);
        gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    }
}

/**
 * @brief 32cf8 | 5fc | Handles Ridley being idle
 * 
 */
static void RidleyIdle(void)
{
    u8 samusGrabbed;
    u8 startSlide;
    u8 turningAround;
    u8 clawSlot;
    u16 yMovement;
    u16 xMovement;
    u8 action;

    turningAround = FALSE;
    samusGrabbed = FALSE;
    startSlide = FALSE;

    clawSlot = gSubSpriteData1.work5;
    action = gSpriteData[clawSlot].work1;

    if (gSpriteData[clawSlot].status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        // Samus grabbed behavior
        samusGrabbed = TRUE;

        if (action == RIDLEY_SAMUS_GRABBED_ACTION_NONE)
        {
            gSpriteData[clawSlot].pOam = sRidleyPartOam_ClawCarryingSamus;
            gSpriteData[clawSlot].animationDurationCounter = 0;
            gSpriteData[clawSlot].currentAnimationFrame = 0;
            gSpriteData[clawSlot].drawOrder = 8;
            
            gSpriteData[clawSlot].work1 = RIDLEY_SAMUS_GRABBED_ACTION_CARRYING_SAMUS;
            gSpriteData[clawSlot].work0 = ONE_THIRD_SECOND;
        }
        else if (action == RIDLEY_SAMUS_GRABBED_ACTION_CARRYING_SAMUS)
        {
            APPLY_DELTA_TIME_DEC(gSpriteData[clawSlot].work0);
            if (gSpriteData[clawSlot].work0 == 0)
            {
                gSpriteData[clawSlot].pOam = sRidleyPartOam_ClawLiftingSamus;
                gSpriteData[clawSlot].animationDurationCounter = 0;
                gSpriteData[clawSlot].currentAnimationFrame = 0;

                gSpriteData[clawSlot].work1 = RIDLEY_SAMUS_GRABBED_ACTION_LIFTING_SAMUS;
                gSpriteData[clawSlot].work0 = CONVERT_SECONDS(.5f - 1.f / 30);
                SoundPlay(SOUND_RIDLEY_LIFTING_SAMUS);
            }
        }
        else if (action == RIDLEY_SAMUS_GRABBED_ACTION_LIFTING_SAMUS)
        {
            APPLY_DELTA_TIME_DEC(gSpriteData[clawSlot].work0);
            if (gSpriteData[clawSlot].work0 == 0)
            {
                gSpriteData[clawSlot].pOam = sRidleyPartOam_ClawSamusLifted;
                gSpriteData[clawSlot].animationDurationCounter = 0;
                gSpriteData[clawSlot].currentAnimationFrame = 0;
                
                gSpriteData[clawSlot].work1 = RIDLEY_SAMUS_GRABBED_ACTION_SAMUS_LIFTED;
                gSpriteData[clawSlot].work0 = ONE_THIRD_SECOND;
            }
        }
        else if (action == RIDLEY_SAMUS_GRABBED_ACTION_SAMUS_LIFTED)
        {
            APPLY_DELTA_TIME_DEC(gSpriteData[clawSlot].work0);
            if (gSpriteData[clawSlot].work0 == 0)
            {
                gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_OpeningMouth;
                gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;
                
                SoundPlay(SOUND_RIDLEY_OPENING_MOUTH);
                gSpriteData[clawSlot].work1 = RIDLEY_SAMUS_GRABBED_ACTION_OPENING_MOUTH;
                gSpriteData[clawSlot].work0 = CONVERT_SECONDS(1.f / 12);
            }
        }
        else if (action == RIDLEY_SAMUS_GRABBED_ACTION_OPENING_MOUTH)
        {
            APPLY_DELTA_TIME_DEC(gSpriteData[clawSlot].work0);
            if (gSpriteData[clawSlot].work0 == 0)
            {
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_SpittingFireballs;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_MouthOpened;
                gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;
                
                gSpriteData[clawSlot].work1 = RIDLEY_SAMUS_GRABBED_ACTION_SPITTING_FIREBALLS;
                gSpriteData[clawSlot].work0 = 0;
                gSpriteData[clawSlot].work2 = 0;
            }
        }
        else if (action == RIDLEY_SAMUS_GRABBED_ACTION_SPITTING_FIREBALLS)
        {
            if (MOD_AND(gSpriteData[clawSlot].work0++, 16) == 0)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                {
                    SpriteSpawnSecondary(SSPRITE_RIDLEY_FIREBALL, RIDLEY_FIREBALL_TYPE_SAMUS_GRABBED,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                        gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
                        gCurrentSprite.xPosition + (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE), SPRITE_STATUS_FACING_RIGHT);
                }
                else
                {
                    SpriteSpawnSecondary(SSPRITE_RIDLEY_FIREBALL, RIDLEY_FIREBALL_TYPE_SAMUS_GRABBED,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                        gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
                        gCurrentSprite.xPosition - (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE), 0);
                }

                SoundPlay(SOUND_RIDLEY_SPITTING_FIREBALLS_ON_SAMUS);
            }

            // Update release timer
            if (gChangedInput & (KEY_A | KEY_B | KEY_ALL_DIRECTIONS))
                gSpriteData[clawSlot].work2 += 4;
            else if (gSpriteData[clawSlot].work2 != 0)
                gSpriteData[clawSlot].work2--;

            // Check release Samus (timer overflowed or mashed enough keys)
            if (gSpriteData[clawSlot].work0 == 0 || gSpriteData[clawSlot].work2 > 16)
            {
                // Release Samus
                gSpriteData[clawSlot].pOam = sRidleyPartOam_ClawReleasingSamus;
                gSpriteData[clawSlot].animationDurationCounter = 0;
                gSpriteData[clawSlot].currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_OpeningMouth;
                gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;

                gSpriteData[clawSlot].status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
                gSpriteData[clawSlot].work1 = RIDLEY_SAMUS_GRABBED_ACTION_RELEASING_SAMUS;
                gSpriteData[clawSlot].work0 = 5;
                gSpriteData[clawSlot].drawOrder = 9;
                gSpriteData[clawSlot].ignoreSamusCollisionTimer = CONVERT_SECONDS(.5f + 1.f / 60);
            }
        }
    }
    else
    {
        if (action == RIDLEY_SAMUS_GRABBED_ACTION_RELEASING_SAMUS)
        {
            APPLY_DELTA_TIME_DEC(gSpriteData[clawSlot].work0);
            if (gSpriteData[clawSlot].work0 == 0)
            {
                gCurrentSprite.pose = RIDLEY_POSE_IDLE_INIT;
                gSpriteData[clawSlot].work1 = RIDLEY_SAMUS_GRABBED_ACTION_NONE;
            }
        }
    }

    if (gCurrentSprite.work0 != 0)
    {
        if (!samusGrabbed)
        {
            // Check start new attack
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (SpriteUtilCheckCrouchingOrMorphed() && gSpriteRng > 7 && gCurrentSprite.work0 == 0)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                    {
                        // Samus in front
                        if (gSpriteRng > 13)
                        {
                            gCurrentSprite.pose = RIDLEY_POSE_TAIL_ATTACKS_INIT;
                            return;
                        }
                        else
                        {
                            gCurrentSprite.pose = RIDLEY_POSE_SMALL_FIREBALLS_ATTACK_INIT;
                            return;
                        }
                    }
                }
                else
                {
                    if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                    {
                        // Samus in front
                        if (gSpriteRng >= SPRITE_RNG_PROB(.875f))
                        {
                            gCurrentSprite.pose = RIDLEY_POSE_TAIL_ATTACKS_INIT;
                            return;
                        }
                        else
                        {
                            gCurrentSprite.pose = RIDLEY_POSE_SMALL_FIREBALLS_ATTACK_INIT;
                            return;
                        }
                    }
                }
            }
            
            // Check start big fireballs attack
            if (MOD_AND(gFrameCounter8Bit, 16) == 0 && gSpriteRng > 8 && gCurrentSprite.work0 <= CONVERT_SECONDS(.15f))
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                    {
                        // Samus in front
                        gCurrentSprite.pose = RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT;
                        return;
                    }
                }
                else
                {
                    if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                    {
                        // Samus in front
                        gCurrentSprite.pose = RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT;
                        return;
                    }
                }
            }
        }

        RidleyIdleYFloatingMovement();
    }
    else
    {
        // Update Ridley position

        if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
        {
            yMovement = gSubSpriteData1.yPosition + BLOCK_SIZE * 4 + PIXEL_SIZE;
            if (yMovement < RIDLEY_GROUND_POSITION)
            {
                // Going down
                yMovement = RIDLEY_GROUND_POSITION - yMovement;
                yMovement /= 4;

                if (yMovement > QUARTER_BLOCK_SIZE)
                    yMovement = QUARTER_BLOCK_SIZE;

                gSubSpriteData1.yPosition += yMovement;
                if (yMovement == 0)
                {
                    if (gCurrentSprite.work1 <= CONVERT_SECONDS(.25f + 1.f / 60))
                        APPLY_DELTA_TIME_INC(gCurrentSprite.work1);

                    // Check should start slide
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    {
                        if (gSubSpriteData1.xPosition + BLOCK_SIZE * 3 < gSamusData.xPosition)
                            startSlide++;
                    }
                    else
                    {
                        if (gSubSpriteData1.xPosition - BLOCK_SIZE * 3 > gSamusData.xPosition)
                            startSlide++;
                    }
                }
            }
            
            if ((gCurrentSprite.work1 > CONVERT_SECONDS(.25f + 1.f / 60) && !startSlide) || samusGrabbed)
            {
                gCurrentSprite.work1 = 0;
                gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
            }
        }
        else
        {
            // Going up

            // Get destination
            if (samusGrabbed)
                yMovement = RIDLEY_GROUND_POSITION - BLOCK_SIZE * 11;
            else
                yMovement = RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8;

            if (yMovement < gSubSpriteData1.yPosition)
            {
                yMovement = gSubSpriteData1.yPosition - yMovement;
                yMovement /= 4;

                CLAMP(yMovement, PIXEL_SIZE, QUARTER_BLOCK_SIZE);

                gSubSpriteData1.yPosition -= yMovement;
            }
            else
            {
                gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
                gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);
            }
        }
    }

    if (!samusGrabbed)
    {
        // Move X
        yMovement = BLOCK_SIZE * 4 + PIXEL_SIZE;

        // Get X movement
        if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
        {
            if (startSlide)
                xMovement = EIGHTH_BLOCK_SIZE;
            else
                xMovement = PIXEL_SIZE / 2;            
        }
        else
        {
            xMovement = EIGHTH_BLOCK_SIZE;
        }

        // Apply movement, check turning around
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition + yMovement) != COLLISION_AIR)
                turningAround++;
            else
                gSubSpriteData1.xPosition += xMovement;
        }
        else
        {
            if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition - yMovement) != COLLISION_AIR)
                turningAround++;
            else
                gSubSpriteData1.xPosition -= xMovement;
        }

        // Check turn around
        if (turningAround && (gCurrentSprite.work0 != 0 || (gCurrentSprite.work1 > CONVERT_SECONDS(.25f + 1.f / 60) && startSlide)))
            gCurrentSprite.pose = RIDLEY_POSE_TURNING_AROUND_INIT;
    }
    else
    {
        // Move X when samus grabbed
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition + BLOCK_SIZE * 7) != COLLISION_AIR)
                gSubSpriteData1.xPosition -= PIXEL_SIZE / 2;
        }
        else
        {
            if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition - BLOCK_SIZE * 7) != COLLISION_AIR)
                gSubSpriteData1.xPosition += PIXEL_SIZE / 2;
        }
    }
}

/**
 * @brief 332f4 | 88 | Initializes Ridley to be turning around
 * 
 */
static void RidleyTurningAroundInit(void)
{
    // Update multi sprite data
    gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_TurningAroundFirstPart;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    // Update head
    gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_HeadTurningAround;
    gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
    gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;

    // Update claw
    gSpriteData[gSubSpriteData1.work5].pOam = sRidleyPartOam_ClawTurningAroundFirstPart;
    gSpriteData[gSubSpriteData1.work5].animationDurationCounter = 0;
    gSpriteData[gSubSpriteData1.work5].currentAnimationFrame = 0;

    gCurrentSprite.pose = RIDLEY_POSE_TURNING_AROUND_FIRST_PART;
}

/**
 * @brief 3337c | 94 | Handles the first part of Ridley turning around
 * 
 */
static void RidleyTurningAroundFirstPart(void)
{
    RidleyIdleYFloatingMovement();

    if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        gCurrentSprite.pose = RIDLEY_POSE_TURNING_AROUND_SECOND_PART;

        // Update multi sprite data
        gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_TurningAroundSecondPart;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        // Update claw
        gSpriteData[gSubSpriteData1.work5].pOam = sRidleyPartOam_ClawTurningAroundSecondPart;
        gSpriteData[gSubSpriteData1.work5].animationDurationCounter = 0;
        gSpriteData[gSubSpriteData1.work5].currentAnimationFrame = 0;

        // Flip
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        if(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
    }
}

/**
 * @brief 33410 | 94 | Handles the second part of Ridley turning around
 * 
 */
static void RidleyTurningAroundSecondPart(void)
{
    RidleyIdleYFloatingMovement();

    if (SpriteUtilHasSubSprite1AnimationEnded())
    {
        // Set idle
        gCurrentSprite.pose = RIDLEY_POSE_IDLE;
        
        // Update multi sprite data
        gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        // Update head
        gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_HeadIdle;
        gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
        gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;

        // Update claw
        gSpriteData[gSubSpriteData1.work5].pOam = sRidleyPartOam_ClawIdle;
        gSpriteData[gSubSpriteData1.work5].animationDurationCounter = 0;
        gSpriteData[gSubSpriteData1.work5].currentAnimationFrame = 0;
    }
}

/**
 * @brief 334a4 | 68 | Initializes Ridley for the small fireball attack
 * 
 */
static void RidleySmallFireballsAttackInit(void)
{
    u8 clawSlot;

    clawSlot = gSubSpriteData1.work5;

    gSpriteData[clawSlot].pOam = sRidleyPartOam_ClawSpittingFireballs;
    gSpriteData[clawSlot].animationDurationCounter = 0;
    gSpriteData[clawSlot].currentAnimationFrame = 0;

    gSpriteData[clawSlot].status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
    gSpriteData[clawSlot].samusCollision = SSC_NONE;
    gSpriteData[clawSlot].work1 = 0;
    gSpriteData[clawSlot].drawOrder = 9;

    gCurrentSprite.pose = RIDLEY_POSE_SMALL_FIREBALLS_ATTACK;
    gCurrentSprite.work1 = RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_GOING_DOWN;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.scaling = CONVERT_SECONDS(3.f);
}

/**
 * @brief 3350c | 330 | Handles ridley doing the small fireballs attack
 * 
 */
static void RidleySmallFireballsAttack(void)
{
    u8 stopAttack;
    u16 yMovement;

    stopAttack = FALSE;

    switch (gCurrentSprite.work1)
    {
        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_GOING_DOWN:
            yMovement = gSubSpriteData1.yPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            if (yMovement < RIDLEY_GROUND_POSITION)
            {
                // Go down
                yMovement = RIDLEY_GROUND_POSITION - yMovement;
                if (yMovement > HALF_BLOCK_SIZE)
                    yMovement = HALF_BLOCK_SIZE;

                gSubSpriteData1.yPosition += yMovement;
            }
            else
            {
                // Reached ground
                gSubSpriteData1.yPosition = RIDLEY_GROUND_POSITION - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                ScreenShakeStartVertical(CONVERT_SECONDS(.5f), 0x80 | 1);

                gCurrentSprite.work1++;
                gCurrentSprite.work0 = CONVERT_SECONDS(.5f);
                gCurrentSprite.work3 = 0;

                SoundPlay(SOUND_RIDLEY_HITTING_GROUND);
            }
            break;

        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_DELAY_BEFORE_OPENING_MOUTH:
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (gCurrentSprite.work0 == 0)
            {
                // Update head
                gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_OpeningMouth;
                gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;

                SoundPlay(SOUND_RIDLEY_OPENING_MOUTH);
                gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 12);
                gCurrentSprite.work1++;
            }
            break;

        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_OPENING_MOUTH:
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (gCurrentSprite.work0 == 0)
            {
                // Set spitting fireballs behavior
                // Update multi sprite data
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_SpittingFireballs;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                // Update head
                gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_MouthOpened;
                gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;

                gCurrentSprite.work1++;
                SoundPlay(SOUND_RIDLEY_SPITTING_FIREBALLS);
            }
            break;

        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_SPITTING_FIREBALLS:
            // Spawn fireball
            if (MOD_AND(gCurrentSprite.scaling, CONVERT_SECONDS(.25f + 1.f / 60)) == 0)
                RidleySpawnAscendingFireball(gCurrentSprite.scaling);

            if (gCurrentSprite.scaling != 0)
            {
                APPLY_DELTA_TIME_DEC(gCurrentSprite.scaling);
                // Check stop attack if samus is behind Ridley
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                        stopAttack++;
                }
                else
                {
                    if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                        stopAttack++;
                }

                if (!stopAttack)
                    break;
            }

            // Update head
            gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_OpeningMouth;
            gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
            gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;

            gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 12);
            gCurrentSprite.work1++;
            SoundFade(SOUND_RIDLEY_SPITTING_FIREBALLS, CONVERT_SECONDS(.5f));
            break;

        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_CLOSING_MOUTH:
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (gCurrentSprite.work0 == 0)
            {
                // Update multi sprite data
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                // Update head
                gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_HeadIdle;
                gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;

                // Update claw
                gSpriteData[gSubSpriteData1.work5].pOam = sRidleyPartOam_ClawIdle;
                gSpriteData[gSubSpriteData1.work5].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.work5].currentAnimationFrame = 0;

                gCurrentSprite.work1 = RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_TAKING_OFF;
                gCurrentSprite.work0 = CONVERT_SECONDS(.5f);
            }
            break;

        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_TAKING_OFF:
            if (gCurrentSprite.work0 != 0)
            {
                APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
                break;
            }

            yMovement = (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8);
            if (yMovement < gSubSpriteData1.yPosition)
            {
                // Move upwards
                yMovement = gSubSpriteData1.yPosition - (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8);
                yMovement /= 4;
                CLAMP(yMovement, PIXEL_SIZE, HALF_BLOCK_SIZE);

                gSubSpriteData1.yPosition -= yMovement;
            }
            else
            {
                // Set idle
                gCurrentSprite.pose = RIDLEY_POSE_IDLE_INIT;
            }
            break;
    }
}

/**
 * @brief 3383c | 78 | Initializes Ridley for any tail attack
 * 
 */
static void RidleyTailAttacksInit(void)
{
    u8 clawSlot;

    clawSlot = gSubSpriteData1.work5;

    gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_HeadIdle;
    gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
    gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;

    gSpriteData[clawSlot].pOam = sRidleyPartOam_ClawIdle;
    gSpriteData[clawSlot].animationDurationCounter = 0;
    gSpriteData[clawSlot].currentAnimationFrame = 0;
}

/**
 * @brief 338b4 | 4 | Empty function (tail attacks)
 * 
 */
static void Ridley_Empty(void)
{
    return;
}

/**
 * @brief 338b8 | 11c | Initializes Ridley for the big fireballs attack
 * 
 */
static void RidleyBigFireballsAttackInit(void)
{
    u8 clawSlot;
    u8 pose;

    clawSlot = gSubSpriteData1.work5;

    gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_SpittingFireballs;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    if (gCurrentSprite.pose == RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT)
    {
        // Normal attack
        gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_MouthOpened;
        gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
        gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;
        pose = RIDLEY_POSE_BIG_FIREBALLS_ATTACK;
    }
    else
    {
        // Attack forced because Ridley got hurt
        gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_HeadDying;
        gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
        gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;
        pose = RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK;
    }

    // Update claw
    gSpriteData[clawSlot].pOam = sRidleyPartOam_ClawSpittingFireballs;
    gSpriteData[clawSlot].animationDurationCounter = 0;
    gSpriteData[clawSlot].currentAnimationFrame = 0;

    gSpriteData[clawSlot].status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
    gSpriteData[clawSlot].samusCollision = SSC_NONE;
    gSpriteData[clawSlot].work1 = 0;
    gSpriteData[clawSlot].drawOrder = 9;

    if (gCurrentSprite.health == 0)
    {
        // Set dying
        gCurrentSprite.pose = RIDLEY_POSE_DYING;
        gCurrentSprite.work0 = 0;
        gCurrentSprite.work1 = CONVERT_SECONDS(2.5f);
        gCurrentSprite.work2 = CONVERT_SECONDS(3.f);
        gCurrentSprite.work3 = DELTA_TIME;
        SoundPlay(SOUND_RIDLEY_DYING_1);
    }
    else
    {
        // Set doing attack
        gCurrentSprite.pose = pose;
        gCurrentSprite.work0 = CONVERT_SECONDS(5.f / 6);
    }
}

/**
 * @brief 339d4 | 12c | Handles ridley doing the big fireballs attack
 * 
 */
static void RidleyBigFireballsAttack(void)
{
    u16 yPosition;
    u16 xPosition;
    u16 status;

    if (APPLY_DELTA_TIME_DEC(gCurrentSprite.work0) == 0)
    {
        // Set new pose
        if (gCurrentSprite.pose == RIDLEY_POSE_BIG_FIREBALLS_ATTACK)
        {
            // Idle if started the attack normally
            gCurrentSprite.pose = RIDLEY_POSE_IDLE_INIT;
        }
        else
        {
            // Tail attack init if started the attack because Ridley got hurt
            gCurrentSprite.pose = RIDLEY_POSE_TAIL_ATTACKS_INIT;
        }
    }
    else if (gCurrentSprite.work0 == CONVERT_SECONDS(1.f / 15))
    {
        // Update head
        gSpriteData[gSubSpriteData1.work4].pOam = sRidleyPartOam_OpeningMouth;
        gSpriteData[gSubSpriteData1.work4].animationDurationCounter = 0;
        gSpriteData[gSubSpriteData1.work4].currentAnimationFrame = 0;
    }
    else if (gCurrentSprite.work0 == ONE_THIRD_SECOND)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            status = SPRITE_STATUS_FACING_RIGHT;
            xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE);
        }
        else
        {
            status = 0;
            xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE);
        }

        yPosition = gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE);

        // Spawn fireballs, floating pattern
        SpriteSpawnSecondary(SSPRITE_RIDLEY_BIG_FIREBALL, RIDLEY_FIREBALL_TYPE_FLOATING_PATTERN | RIDLEY_FIREBALL_TYPE_TOP,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_RIDLEY_BIG_FIREBALL, RIDLEY_FIREBALL_TYPE_FLOATING_PATTERN | RIDLEY_FIREBALL_TYPE_MIDDLE_TOP,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_RIDLEY_BIG_FIREBALL, RIDLEY_FIREBALL_TYPE_FLOATING_PATTERN | RIDLEY_FIREBALL_TYPE_MIDDLE,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_RIDLEY_BIG_FIREBALL, RIDLEY_FIREBALL_TYPE_FLOATING_PATTERN | RIDLEY_FIREBALL_TYPE_MIDDLE_BOTTOM,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_RIDLEY_BIG_FIREBALL, RIDLEY_FIREBALL_TYPE_FLOATING_PATTERN | RIDLEY_FIREBALL_TYPE_BOTTOM,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, status);

        SoundPlay(SOUND_RIDLEY_SPITTING_BIG_FIREBALLS);
    }
}

/**
 * @brief 33b00 | 214 | Handles ridley dying
 * 
 */
static void RidleyDying(void)
{
    u8 rngParam1;
    u8 rngParam2;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gCurrentSprite.work2 != 0)
    {
        if (gCurrentSprite.work2 > 2)
        {
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work2);
        }
        else
        {
            if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 5))
                APPLY_DELTA_TIME_DEC(gCurrentSprite.work2);

            if (gCurrentSprite.work2 == DELTA_TIME)
                StartEffectForCutscene(EFFECT_CUTSCENE_STATUE_OPENING);
            else if (gCurrentSprite.work2 == 0)
                FadeMusic(CONVERT_SECONDS(2.5f));
        }
    }

    // Slowly move to ground
    if (gSubSpriteData1.yPosition < (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 3))
        gSubSpriteData1.yPosition += ONE_SUB_PIXEL;

    rngParam1 = gSpriteRng;
    rngParam2 = gFrameCounter8Bit;

    // Play effects
    if (MOD_AND(gCurrentSprite.work0, CONVERT_SECONDS(.5f + 1.f / 30)) == 0)
    {
        if (MOD_BLOCK_AND(gCurrentSprite.work0, CONVERT_SECONDS(.5f + 1.f / 30)))
        {
            ParticleSet(gCurrentSprite.yPosition - (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2) + rngParam1 * PIXEL_SIZE,
                gCurrentSprite.xPosition + (BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE - PIXEL_SIZE / 2) - rngParam1 * PIXEL_SIZE, PE_SPRITE_EXPLOSION_HUGE);
        }
        else
        {
            ParticleSet(gCurrentSprite.yPosition + (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2) - rngParam1 * PIXEL_SIZE,
                gCurrentSprite.xPosition - (BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE - PIXEL_SIZE / 2) + rngParam1 * PIXEL_SIZE, PE_SPRITE_EXPLOSION_BIG);
        }
    }

    if (MOD_AND(gCurrentSprite.work3, CONVERT_SECONDS(.5f + 1.f / 30)) == 0)
    {
        if (MOD_BLOCK_AND(gCurrentSprite.work3, CONVERT_SECONDS(.5f + 1.f / 30)))
        {
            ParticleSet(gCurrentSprite.yPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE) + rngParam2 / PIXEL_SIZE,
                gCurrentSprite.xPosition + (BLOCK_SIZE - PIXEL_SIZE) - rngParam2 / PIXEL_SIZE, PE_MAIN_BOSS_DEATH);
        }
        else
        {
            ParticleSet(gCurrentSprite.yPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE) - rngParam2 / PIXEL_SIZE,
                gCurrentSprite.xPosition - (BLOCK_SIZE - PIXEL_SIZE) + rngParam2 / PIXEL_SIZE, PE_MAIN_BOSS_DEATH);
        }
    }

    APPLY_DELTA_TIME_INC(gCurrentSprite.work0);
    APPLY_DELTA_TIME_INC(gCurrentSprite.work3);

    if (gCurrentSprite.work2 == 0)
    {
        // After cutscene

        // Add more effects
        if (MOD_AND(gCurrentSprite.work0, CONVERT_SECONDS(.25f + 1.f / 60)) == 0)
        {
            if (MOD_BLOCK_AND(gCurrentSprite.work0, CONVERT_SECONDS(2.f / 15)))
            {
                ParticleSet(gCurrentSprite.yPosition - rngParam1 * EIGHTH_BLOCK_SIZE,
                    gCurrentSprite.xPosition - rngParam1 * EIGHTH_BLOCK_SIZE, PE_SPRITE_EXPLOSION_BIG);
            }
            else
            {
                ParticleSet(gCurrentSprite.yPosition - rngParam1 * PIXEL_SIZE,
                    gCurrentSprite.xPosition - rngParam1 * PIXEL_SIZE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            }
        }

        if (MOD_AND(gCurrentSprite.work3, CONVERT_SECONDS(.25f + 1.f / 60)) == 0)
        {
            if (MOD_BLOCK_AND(gCurrentSprite.work3, CONVERT_SECONDS(2.f / 15)))
            {
                ParticleSet(gCurrentSprite.yPosition - BLOCK_SIZE - rngParam1 * EIGHTH_BLOCK_SIZE,
                    gCurrentSprite.xPosition + HALF_BLOCK_SIZE + rngParam1 * EIGHTH_BLOCK_SIZE, PE_SPRITE_EXPLOSION_BIG);
            }
            else
            {
                ParticleSet(gCurrentSprite.yPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE) + rngParam1 * EIGHTH_BLOCK_SIZE,
                    gCurrentSprite.xPosition + HALF_BLOCK_SIZE + rngParam1 * (PIXEL_SIZE / 2), PE_SPRITE_EXPLOSION_BIG);
            }
        }

        // Flicker
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
        if (APPLY_DELTA_TIME_DEC(gCurrentSprite.work1) == 0)
        {
            // Kill sprite
            gCurrentSprite.status = 0;
            // Unlock doors
            gDoorUnlockTimer = -CONVERT_SECONDS(1.f);
            // Set event
            EventFunction(EVENT_ACTION_SETTING, EVENT_RIDLEY_KILLED);
            // Update minimap
            MinimapUpdateChunk(EVENT_RIDLEY_KILLED);
            PlayMusic(MUSIC_BOSS_KILLED, 0);
        }
        else if (gCurrentSprite.work1 == CONVERT_SECONDS(2.5f) - DELTA_TIME)
        {
            SoundPlay(SOUND_RIDLEY_DYING_2);
        }
    }
}

/**
 * @brief 33d14 | 148 | Initializes a Ridley part sprite
 * 
 */
static void RidleyPartInit(void)
{
    gCurrentSprite.pose = RIDLEY_PART_POSE_IDLE;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    switch (gCurrentSprite.roomSlot)
    {
        case RIDLEY_PART_LEFT_WING:
            gCurrentSprite.drawOrder = 6;
            
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case RIDLEY_PART_HEAD:
            gCurrentSprite.drawOrder = 7;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            break;

        case RIDLEY_PART_CLAW:
            gCurrentSprite.drawOrder = 9;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5 + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = BLOCK_SIZE + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);

            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.work1 = 0;
            break;

        case RIDLEY_PART_TAIL:
            gCurrentSprite.drawOrder = 8;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case RIDLEY_PART_RIGHT_WING:
            gCurrentSprite.drawOrder = 10;
            
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        default:
            gCurrentSprite.status = 0;
    }

    RidleySyncSubSprites();
}

/**
 * @brief 33e5c | 70 | Plays the wing flapping sound
 * 
 * @param ramSlot Ridley's ram slot
 */
static void RidleyPartWingPlaySound(u8 ramSlot)
{
    if (gSpriteData[ramSlot].pose == SPRITE_POSE_UNINITIALIZED || gSpriteData[ramSlot].pose == RIDLEY_POSE_CHECK_PLAY_CUTSCENE)
        return;

    if (gSpriteData[ramSlot].pose == RIDLEY_POSE_DYING && gSpriteData[ramSlot].work2 == 0)
        return;

    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == DELTA_TIME)
    {
        if (gCurrentSprite.pOam == sRidleyPartOam_LeftWingIdle)
            SoundPlay(SOUND_RIDLEY_WINGS_FLAPPING);
        else if (gCurrentSprite.pOam == sRidleyPartOam_LeftWingSpittingFireballs)
            SoundPlay(SOUND_RIDLEY_WINGS_FLAPPING_FAST);
    }
}

/**
 * @brief 33ecc | 38 | Updates the frozen palette offset of a wing
 * 
 */
static void RidleyPartWingSetPaletteOffset(void)
{
    u16 part;
    u16 flag;

    part = gCurrentSprite.pOam[gCurrentSprite.currentAnimationFrame].pFrame[3];
    // Mask for the palette number in the oam
    flag = 0xF << 12;
    
    if ((part & flag) == 1 << 15)
        gCurrentSprite.frozenPaletteRowOffset = 0;
    else
        gCurrentSprite.frozenPaletteRowOffset = 1;
}

/**
 * @brief 33f04 | Synchronizes the palette of a Ridley part with Ridley
 * 
 * @param ramSlot Ridley's RAM slot
 */
static void RidleyPartSyncPalette(u8 ramSlot)
{
    if (gSpriteData[ramSlot].paletteRow == NBR_OF_PALETTE_ROWS - SPRITE_STUN_PALETTE_OFFSET)
        gCurrentSprite.paletteRow = NBR_OF_PALETTE_ROWS - gCurrentSprite.frozenPaletteRowOffset - SPRITE_STUN_PALETTE_OFFSET;
    else
        gCurrentSprite.paletteRow = gSpriteData[ramSlot].absolutePaletteRow;
}

/**
 * @brief 33f48 | 2c | Updates the side hitboxes of the claw
 * 
 */
static void RidleyPartClawUpdateSidesHitbox(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = CLAW_RIGHT_HITBOX;
        gCurrentSprite.hitboxRight = CLAW_LEFT_HITBOX;
    }
    else
    {
        gCurrentSprite.hitboxLeft = -CLAW_LEFT_HITBOX;
        gCurrentSprite.hitboxRight = -CLAW_RIGHT_HITBOX;
    }
}

/**
 * @brief 33f74 | 146 | Handles a Ridley tail dying
 * 
 */
static void RidleyTailDead(void)
{
    u8 rng;

    rng = gSpriteRng;
    switch (gCurrentSprite.roomSlot)
    {
        case RIDLEY_TAIL_PART_BODY_ATTACHMENT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE + PIXEL_SIZE) + rng * ONE_SUB_PIXEL,
                gSubSpriteData1.xPosition + (BLOCK_SIZE + HALF_BLOCK_SIZE+ PIXEL_SIZE) - rng * PIXEL_SIZE / 2, FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            break;

        case RIDLEY_TAIL_PART_RIGHT_LEFT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE) - rng * ONE_SUB_PIXEL,
                gSubSpriteData1.xPosition - rng * PIXEL_SIZE / 2, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case RIDLEY_TAIL_PART_RIGHT_MIDDLE:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition + THREE_QUARTER_BLOCK_SIZE + rng * ONE_SUB_PIXEL,
                gSubSpriteData1.xPosition - (HALF_BLOCK_SIZE - PIXEL_SIZE) - rng * PIXEL_SIZE / 2, FALSE, PE_SPRITE_EXPLOSION_BIG);
            break;

        case RIDLEY_TAIL_PART_RIGHT_MOST:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - THREE_QUARTER_BLOCK_SIZE + rng * ONE_SUB_PIXEL,
                gSubSpriteData1.xPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE) + rng * PIXEL_SIZE / 2, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case RIDLEY_TAIL_PART_LEFT_RIGHT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition + HALF_BLOCK_SIZE - rng * ONE_SUB_PIXEL,
                gSubSpriteData1.xPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE) + rng * PIXEL_SIZE / 2, FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            break;

        case RIDLEY_TAIL_PART_LEFT_MIDDLE:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE) - rng * ONE_SUB_PIXEL,
                gSubSpriteData1.xPosition - (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE - PIXEL_SIZE) - rng * PIXEL_SIZE / 2, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case RIDLEY_TAIL_PART_LEFT_MOST:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE) - rng * ONE_SUB_PIXEL,
                gSubSpriteData1.xPosition + (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE) + rng * PIXEL_SIZE / 2, FALSE, PE_SPRITE_EXPLOSION_BIG);
            break;

        case RIDLEY_TAIL_PART_TIP:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition + (BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE) + rng * ONE_SUB_PIXEL,
                gSubSpriteData1.xPosition - (BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE) + rng * PIXEL_SIZE / 2, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            SoundPlay(SOUND_RIDLEY_TAIL_DYING);
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 340b8 | 9c | Initializes a Ridley tail sprite
 * 
 */
static void RidleyTailInit(void)
{
    gCurrentSprite.pose = RIDLEY_TAIL_POSE_IDLE;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    gCurrentSprite.health = 1;
    gCurrentSprite.drawOrder = 11;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    if (gCurrentSprite.roomSlot == RIDLEY_TAIL_PART_TIP)
    {
        // Set multi sprite data
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_Idle;
        gSubSpriteData2.animationDurationCounter = 0;
        gSubSpriteData2.currentAnimationFrame = 0;

        gCurrentSprite.yPositionSpawn = 0;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -THREE_QUARTER_BLOCK_SIZE;
        gCurrentSprite.hitboxBottom = THREE_QUARTER_BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -THREE_QUARTER_BLOCK_SIZE;
        gCurrentSprite.hitboxRight = THREE_QUARTER_BLOCK_SIZE;
    }
    else
    {
        // Initialize parts
        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;
    }
}

/**
 * @brief 34154 | 74 | Handles a Ridley tail being idle
 * 
 */
static void RidleyTailIdle(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSubSpriteData1.pMultiOam != sRidleyMultiSpriteData_SpittingFireballs && gSubSpriteData2.pMultiOam == sRidleyTailMultiSpriteData_Dying)
    {
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_Idle;
        gSubSpriteData2.animationDurationCounter = 0;
        gSubSpriteData2.currentAnimationFrame = 0;
    }
    
    if (gSpriteData[ramSlot].pose == RIDLEY_POSE_TAIL_ATTACKS_INIT)
    {
        gCurrentSprite.pose = RIDLEY_TAIL_POSE_MOVE_TO_ATTACK;

        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_MoveToAttack;
        gSubSpriteData2.animationDurationCounter = 0;
        gSubSpriteData2.currentAnimationFrame = 0;
    }
}

/**
 * @brief 341c8 | 30 | Checks if the moving tail to attack animation ended
 * 
 */
static void RidleyTailCheckMovingToAttackAnimEnded(void)
{
    if (SpriteUtilHasSubSprite2AnimationEnded())
    {
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_SettingUpDiagonalTailAttack;
        gSubSpriteData2.animationDurationCounter = 0;
        gSubSpriteData2.currentAnimationFrame = 0;

        gCurrentSprite.pose = RIDLEY_TAIL_POSE_SETTING_UP_ATTACK;
    }
}

/**
 * @brief 341f8 | 80 | Handles the tail setting up an attack
 * 
 */
static void RidleyTailSettingUpAttack(void)
{
    if (gSubSpriteData2.currentAnimationFrame == 3 && gSubSpriteData2.animationDurationCounter == DELTA_TIME)
        SoundPlay(SOUND_RIDLEY_TAIL_SPINNING);

    if (SpriteUtilHasSubSprite2AnimationEnded())
    {
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack;
        gSubSpriteData2.animationDurationCounter = 0;
        gSubSpriteData2.currentAnimationFrame = 0;

        gCurrentSprite.pose = RIDLEY_TAIL_POSE_CHARGING_ATTACK;

        // Number of swipes
        if (gDifficulty == DIFF_EASY)
            gCurrentSprite.work0 = 2;
        else
            gCurrentSprite.work0 = gSpriteRng / 2 + 2;
    }

    if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8))
        gSubSpriteData1.yPosition -= PIXEL_SIZE / 2;
}

/**
 * @brief 34278 | 128 | Handles the Ridley tail charging the attack
 * 
 */
static void RidleyTailChargingAttack(void)
{
    u8 ramSlot;
    u8 doDiagonal;

    if (gSubSpriteData2.currentAnimationFrame == 3 && gSubSpriteData2.animationDurationCounter == DELTA_TIME)
        SoundPlay(SOUND_RIDLEY_TAIL_SPINNING);

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    doDiagonal = FALSE;

    if (!SpriteUtilHasSubSprite2AnimationEnded())
        return;

    gSpriteData[ramSlot].pose = RIDLEY_POSE_TAIL_ATTACKS;

    // Flip and check do diagonal attack or not
    if (gSpriteData[ramSlot].status & SPRITE_STATUS_X_FLIP)
    {
        if (gSubSpriteData1.xPosition - BLOCK_SIZE * 2 > gSamusData.xPosition)
            gSpriteData[ramSlot].status &= ~SPRITE_STATUS_FACING_RIGHT;
        else
        {
            gSpriteData[ramSlot].status |= SPRITE_STATUS_FACING_RIGHT;
            doDiagonal = TRUE;
        }
    }
    else
    {
        if (gSubSpriteData1.xPosition + BLOCK_SIZE * 2 > gSamusData.xPosition)
        {
            gSpriteData[ramSlot].status &= ~SPRITE_STATUS_FACING_RIGHT;
            doDiagonal = TRUE;
        }
        else
            gSpriteData[ramSlot].status |= SPRITE_STATUS_FACING_RIGHT;
    }

    if (doDiagonal)
    {
        // Do diagonal
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_DiagonalTailAttack;
        gSubSpriteData2.animationDurationCounter = 0;
        gSubSpriteData2.currentAnimationFrame = 0;

        gCurrentSprite.pose = RIDLEY_TAIL_POSE_DIAGONAL_ATTACK;
    }
    else
    {
        // No diagonal
        if (gDifficulty == DIFF_EASY)
        {
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_LastVerticalAttack;
            gSubSpriteData2.animationDurationCounter = 0;
            gSubSpriteData2.currentAnimationFrame = 0;

            // Only 1 attack if easy
            gCurrentSprite.pose = RIDLEY_TAIL_POSE_LAST_VERTICAL_ATTACK;
            gCurrentSprite.work0 = 0;
        }
        else
        {
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_ChargingVerticalTailAttack;
            gSubSpriteData2.animationDurationCounter = 0;
            gSubSpriteData2.currentAnimationFrame = 0;

            gCurrentSprite.pose = RIDLEY_TAIL_POSE_FIRST_VERTICAL_ATTACK;
        }
    }
}

/**
 * @brief 343a0 | 80 | Handles the first vertical attack
 * 
 */
static void RidleyTailFirstVerticalAttack(void)
{
    if (gSubSpriteData2.currentAnimationFrame == 3 && gSubSpriteData2.animationDurationCounter == DELTA_TIME)
        SoundPlay(SOUND_RIDLEY_TAIL_VERTICAL_SWIPE);

    if (SpriteUtilHasSubSprite2AnimationEnded())
    {
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_VerticalTailAttack;
        gSubSpriteData2.animationDurationCounter = 0;
        gSubSpriteData2.currentAnimationFrame = 0;
        gCurrentSprite.pose = RIDLEY_TAIL_POSE_VERTICAL_ATTACK;
    }
    else
    {
        if (gSubSpriteData2.currentAnimationFrame < 8)
            RidleyTailAttacksYMove(QUARTER_BLOCK_SIZE - PIXEL_SIZE);
        else if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8))
            gSubSpriteData1.yPosition -= EIGHTH_BLOCK_SIZE;

        RidleyTailAttacksXMove(PIXEL_SIZE / 2);
        RidleyTailCheckStartScreenShakeVerticalTailAttack();
    }
}

/**
 * @brief 34420 | ec | Handles the Ridley tail doing the vertical attack
 * 
 */
static void RidleyTailVerticalAttack(void)
{
    u8 stopAttack;
    u8 ramSlot;

    if (gSubSpriteData2.currentAnimationFrame == 0 && gSubSpriteData2.animationDurationCounter == DELTA_TIME)
        SoundPlay(SOUND_RIDLEY_TAIL_VERTICAL_SWIPE);

    stopAttack = FALSE;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (SpriteUtilHasSubSprite2AnimationEnded())
    {
        // Check stop attack
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0)
        {
            stopAttack++;
        }
        else
        {
            // Stop if samus is behind Ridley
            if (gSpriteData[ramSlot].status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                    stopAttack++;
            }
            else
            {
                if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                    stopAttack++;
            }
        }

        if (stopAttack)
        {
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_LastVerticalAttack;
            gSubSpriteData2.animationDurationCounter = 0;
            gSubSpriteData2.currentAnimationFrame = 0;

            gCurrentSprite.pose = RIDLEY_TAIL_POSE_LAST_VERTICAL_ATTACK;
            return;
        }
    }
    
    if (gSubSpriteData2.currentAnimationFrame < 5)
        RidleyTailAttacksYMove(QUARTER_BLOCK_SIZE - PIXEL_SIZE);
    else if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8))
        gSubSpriteData1.yPosition -= EIGHTH_BLOCK_SIZE;

    RidleyTailAttacksXMove(PIXEL_SIZE);
    RidleyTailCheckStartScreenShakeVerticalTailAttack();
}

/**
 * @brief 3450c | a8 | Handles the last vertical attack
 * 
 */
static void RidleyTailLastVerticalAttack(void)
{
    if (gSubSpriteData2.currentAnimationFrame == 0 && gSubSpriteData2.animationDurationCounter == DELTA_TIME)
        SoundPlay(SOUND_RIDLEY_TAIL_VERTICAL_SWIPE);

    if (SpriteUtilHasSubSprite2AnimationEnded())
    {
        // Check still has swipes left
        if (gCurrentSprite.work0 != 0)
        {
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack;
            gSubSpriteData2.animationDurationCounter = 0;
            gSubSpriteData2.currentAnimationFrame = 0;
            gCurrentSprite.pose = RIDLEY_TAIL_POSE_CHARGING_ATTACK;
        }
        else
        {
            // Back to idle
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_BackToIdle;
            gSubSpriteData2.animationDurationCounter = 0;
            gSubSpriteData2.currentAnimationFrame = 0;
            gCurrentSprite.pose = RIDLEY_TAIL_POSE_BACK_TO_IDLE;
        }
    }
    else
    {
        if (gSubSpriteData2.currentAnimationFrame < 5)
            RidleyTailAttacksYMove(QUARTER_BLOCK_SIZE - PIXEL_SIZE);
        else if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8))
            gSubSpriteData1.yPosition -= EIGHTH_BLOCK_SIZE;

        RidleyTailAttacksXMove(PIXEL_SIZE / 2);
        RidleyTailCheckStartScreenShakeVerticalTailAttack();
    }
}

/**
 * @brief 345b4 | 88 | Handles the Ridley tail doing the diagonal attack
 * 
 */
static void RidleyTailDiagonalAttack(void)
{
    if (gSubSpriteData2.currentAnimationFrame == 3 && gSubSpriteData2.animationDurationCounter == DELTA_TIME)
        SoundPlay(SOUND_RIDLEY_TAIL_DIAGONAL_SWIPE);

    // Commented out code probably
    if (gCurrentSprite.status) {}

    if (SpriteUtilHasSubSprite2AnimationEnded())
    {
        // Decrement swipe counter
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0)
        {
            // No more swipes, set back to idle
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_BackToIdle;
            gSubSpriteData2.animationDurationCounter = 0;
            gSubSpriteData2.currentAnimationFrame = 0;
            gCurrentSprite.pose = RIDLEY_TAIL_POSE_BACK_TO_IDLE;
        }
        else
        {
            // Start new swipe
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack;
            gSubSpriteData2.animationDurationCounter = 0;
            gSubSpriteData2.currentAnimationFrame = 0;
            gCurrentSprite.pose = RIDLEY_TAIL_POSE_CHARGING_ATTACK;
        }
    }
    else
    {
        RidleyTailAttacksYMove(PIXEL_SIZE);
        RidleyTailAttacksXMove(PIXEL_SIZE);
    }
}

/**
 * @brief 3463c | 84 | Checks if the back to idle animation ended
 * 
 */
static void RidleyTailCheckBackToIdleAnimEnded(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8))
        gSubSpriteData1.yPosition -= EIGHTH_BLOCK_SIZE;

    if (SpriteUtilHasSubSprite2AnimationEnded())
    {
        // Update multi sprite data
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_Idle;
        gSubSpriteData2.animationDurationCounter = 0;
        gSubSpriteData2.currentAnimationFrame = 0;

        // Set the tail and Ridley to idle
        gCurrentSprite.pose = RIDLEY_TAIL_POSE_IDLE;
        gSpriteData[ramSlot].pose = RIDLEY_POSE_IDLE_INIT;

        if (gSpriteData[ramSlot].status & SPRITE_STATUS_X_FLIP)
            gSpriteData[ramSlot].status |= SPRITE_STATUS_FACING_RIGHT;
        else
            gSpriteData[ramSlot].status &= ~SPRITE_STATUS_FACING_RIGHT;
    }
}

/**
 * @brief 346c0 | 50 | Checks if a Ridley fireball should slide off a wall
 * 
 */
static void RidleyFireballCheckSlideOnWall(void)
{
    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
    {
        // Touched ground, destroy
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_DESTROY;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Check wall on right
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxRight) != COLLISION_AIR)
        {
            gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL_INIT;
        }
    }
    else
    {
        // Check wall on left
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft) != COLLISION_AIR)
        {
            gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL_INIT;
        }
    }
}

/**
 * @brief 34710 | 14c | Initializes a Ridley fireball sprite
 * 
 */
static void RidleyFireballInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING_SINGLE;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

    gCurrentSprite.bgPriority = BGCNT_GET_PRIORITY(gIoRegistersBackup.BG1CNT);
    gCurrentSprite.drawOrder = 2;
    
    if (gCurrentSprite.spriteId == SSPRITE_RIDLEY_BIG_FIREBALL)
    {
        // Big fireball
        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
        gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
        gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

        gCurrentSprite.pOam = sRidleyFireballOam_Big;
    }
    else
    {
        // Small fireball
        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE - PIXEL_SIZE);
        gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE - PIXEL_SIZE;
        gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE - PIXEL_SIZE);
        gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE - PIXEL_SIZE;

        gCurrentSprite.pOam = sRidleyFireballOam_Small;
    }
    
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.rotation = 0;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;

    // Set pattern
    if (gCurrentSprite.roomSlot == RIDLEY_FIREBALL_TYPE_SAMUS_GRABBED)
    {
        // Diagonal pattern (when Samus is grabbed)
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT_NO_KNOCKBACK;
        gCurrentSprite.scaling = Q_8_8(.5f);
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_MOVE_DIAGONAL_PATTERN;
    }
    else if (gCurrentSprite.roomSlot & RIDLEY_FIREBALL_TYPE_FLOATING_PATTERN)
    {
        // Floating pattern (big fireballs)
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
        gCurrentSprite.scaling = Q_8_8(1.f);
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_MOVE_FLOATING_PATTERN;
    }
    else
    {
        // Descending pattern (small fireballs)
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;

        gCurrentSprite.scaling = Q_8_8(.5f);

        gCurrentSprite.work0 = CONVERT_SECONDS(.25f + 1.f / 60);
        gCurrentSprite.work2 = 0;
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_MOVE_DESCENDING_PATTERN;

        if (gCurrentSprite.yPosition < gSamusData.yPosition)
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
    }
}

/**
 * @brief 3485c | 50 | Handles a Ridley fireball moving in a diagonal pattern
 * 
 */
static void RidleyFireballMoveDiagonalPattern(void)
{
    if (gCurrentSprite.scaling < Q_8_8(.94f))
    {
        gCurrentSprite.yPosition = gSpriteData[gCurrentSprite.primarySpriteRamSlot].yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.scaling += Q_8_8(.065f);
    }
    else
    {
        // Move
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.xPosition += EIGHTH_BLOCK_SIZE;
        else
            gCurrentSprite.xPosition -= EIGHTH_BLOCK_SIZE;

        gCurrentSprite.yPosition += EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2;

        RidleyFireballCheckSlideOnWall();
    }
}

/**
 * @brief 348b4 | 6c | Handles a Ridley fireball moving in a floating pattern
 * 
 */
static void RidleyFireballMoveFloatingPattern(void)
{
    u8 part;
    
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.xPosition += PIXEL_SIZE;
    else
        gCurrentSprite.xPosition -= PIXEL_SIZE;

    // Update Y position
    part = gCurrentSprite.roomSlot & ~RIDLEY_FIREBALL_TYPE_FLOATING_PATTERN;
    switch (part)
    {
        case RIDLEY_FIREBALL_TYPE_MIDDLE_TOP:
            gCurrentSprite.yPosition -= PIXEL_SIZE;
            break;

        case RIDLEY_FIREBALL_TYPE_MIDDLE:
            gCurrentSprite.yPosition += PIXEL_SIZE;
            break;

        case RIDLEY_FIREBALL_TYPE_MIDDLE_BOTTOM:
            gCurrentSprite.yPosition += EIGHTH_BLOCK_SIZE;
            break;

        case RIDLEY_FIREBALL_TYPE_BOTTOM:
            gCurrentSprite.yPosition += QUARTER_BLOCK_SIZE - PIXEL_SIZE;
    }

    RidleyFireballCheckSlideOnWall();
}

/**
 * @brief 34920 | 74 | Handles a Ridley fireball moving in a descending pattern
 * 
 */
static void RidleyFireballMoveDescendingPattern(void)
{
    u16 movement;
    
    movement = gCurrentSprite.work2++;

    if (gCurrentSprite.scaling < Q_8_8(.94f))
        gCurrentSprite.scaling += Q_8_8(.065f);

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.xPosition += movement;
    else
        gCurrentSprite.xPosition -= movement;

    gCurrentSprite.yPosition += PIXEL_SIZE * 3;
    gCurrentSprite.work0--;

    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_MOVE_ASCENDING_PATTERN;
        gCurrentSprite.work1 = 0;
        gCurrentSprite.work2 = QUARTER_BLOCK_SIZE;
        gCurrentSprite.work0 = 0;
        gCurrentSprite.work3 = QUARTER_BLOCK_SIZE;
    }
}

/**
 * @brief 34994 | 50 | Handles a Ridley fireball moving in an ascending pattern
 * 
 */
static void RidleyFireballMoveAscendingPattern(void)
{
    u16 yOffset;
    u16 yTarget;

    if (gCurrentSprite.roomSlot == RIDLEY_FIREBALL_TYPE_MIDDLE_BOTTOM)
        yOffset = RIDLEY_FIREBALL_ASCENDING_Y_TARGET_OFFSET * 1;
    else if (gCurrentSprite.roomSlot == RIDLEY_FIREBALL_TYPE_MIDDLE)
        yOffset = RIDLEY_FIREBALL_ASCENDING_Y_TARGET_OFFSET * 2;
    else if (gCurrentSprite.roomSlot == RIDLEY_FIREBALL_TYPE_MIDDLE_TOP)
        yOffset = RIDLEY_FIREBALL_ASCENDING_Y_TARGET_OFFSET * 3;
    else
        yOffset = 0;

    yTarget = gSubSpriteData1.yPosition + BLOCK_SIZE + EIGHTH_BLOCK_SIZE - yOffset;
    SpriteUtilRidleyFireballMove(yTarget, gSamusData.xPosition, HALF_BLOCK_SIZE, HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE, 2);
    RidleyFireballCheckSlideOnWall();
}

/**
 * @brief 349e4 | 18 | Initializes a Ridley fireball to be sliding on a wall
 * 
 */
static void RidleyFireballSlideOnWallInit(void)
{
    gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL;
    gCurrentSprite.work3 = ONE_SUB_PIXEL * 4;
}

/**
 * @brief 349fc | 3c | Handles a Ridley fireball sliding on a wall
 * 
 */
static void RidleyFireballSlideOnWall(void)
{
    u16 movement;

    movement = gCurrentSprite.work3 / 4;
    
    if (movement < QUARTER_BLOCK_SIZE + PIXEL_SIZE)
        gCurrentSprite.work3 += ONE_SUB_PIXEL;

    gCurrentSprite.yPosition += movement;
    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_DESTROY;
}

/**
 * @brief 34a38 | 2ec | Ridley AI
 * 
 */
void Ridley(void)
{
    RidleyUpdateHealth();

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            RidleyInit();
            break;

        case RIDLEY_POSE_CHECK_PLAY_CUTSCENE:
            RidleyCheckPlayCutscene();
            break;
        
        case RIDLEY_POSE_SPAWNING:
            RidleySpawning();
            break;

        case RIDLEY_POSE_IDLE_INIT:
            RidleyIdleInit();
        
        case RIDLEY_POSE_IDLE:
            RidleyIdle();
            break;

        case RIDLEY_POSE_TURNING_AROUND_INIT:
            RidleyTurningAroundInit();

        case RIDLEY_POSE_TURNING_AROUND_FIRST_PART:
            RidleyTurningAroundFirstPart();
            break;

        case RIDLEY_POSE_TURNING_AROUND_SECOND_PART:
            RidleyTurningAroundSecondPart();
            break;

        case RIDLEY_POSE_SMALL_FIREBALLS_ATTACK_INIT:
            RidleySmallFireballsAttackInit();

        case RIDLEY_POSE_SMALL_FIREBALLS_ATTACK:
            RidleySmallFireballsAttack();
            break;

        case RIDLEY_POSE_TAIL_ATTACKS_INIT:
            RidleyTailAttacksInit();
            break;

        case RIDLEY_POSE_TAIL_ATTACKS:
            Ridley_Empty();
            break;

        case RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK_INIT:
        case RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT:
            RidleyBigFireballsAttackInit();
            break;

        case RIDLEY_POSE_BIG_FIREBALLS_ATTACK:
        case RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK:
            RidleyBigFireballsAttack();
            break;

        case RIDLEY_POSE_DYING:
            RidleyDying();
    }

    if (gCurrentSprite.status & SPRITE_STATUS_EXISTS)
    {
        if (gCurrentSprite.paletteRow != NBR_OF_PALETTE_ROWS - SPRITE_STUN_PALETTE_OFFSET)
        {
            if (gCurrentSprite.health < GET_PSPRITE_HEALTH(gCurrentSprite.spriteId) / 4)
            {
                gCurrentSprite.paletteRow = 5;
                gCurrentSprite.absolutePaletteRow = gCurrentSprite.paletteRow;
            }
            else if (gCurrentSprite.health < GET_PSPRITE_HEALTH(gCurrentSprite.spriteId) / 2)
            {
                gCurrentSprite.paletteRow = 3;
                gCurrentSprite.absolutePaletteRow = gCurrentSprite.paletteRow;
            }
        }

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.hitboxLeft = -RIDLEY_RIGHT_HITBOX;
            gCurrentSprite.hitboxRight = RIDLEY_LEFT_HITBOX;
        }
        else
        {
            gCurrentSprite.hitboxLeft = -RIDLEY_LEFT_HITBOX;
            gCurrentSprite.hitboxRight = RIDLEY_RIGHT_HITBOX;
        }

        if (gSamusData.yPosition < (BLOCK_SIZE * 13 - ONE_SUB_PIXEL) && !(gSpriteData[gSubSpriteData1.work5].status & SPRITE_STATUS_SAMUS_COLLIDING))
        {
            gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;
        }
        else
        {
            gLockScreen.lock = LOCK_SCREEN_TYPE_POSITION;
            gLockScreen.yPositionCenter = gSamusData.yPosition - BLOCK_SIZE * 2;
            gLockScreen.xPositionCenter = gSamusData.xPosition;
        }
    }
    else
    {
        gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;
    }

    SpriteUtilUpdateSubSprite1Anim();
    RidleySyncSubSprites();
}

/**
 * @brief 34d24 | 310 | Ridley tail AI
 * 
 */
void RidleyTail(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    gCurrentSprite.paletteRow = gSpriteData[ramSlot].paletteRow;

    if (gSpriteData[ramSlot].health == 0 && gCurrentSprite.pose < SPRITE_POSE_DESTROYED)
    {
        gCurrentSprite.pose = SPRITE_POSE_DESTROYED;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_Dying;
        gSubSpriteData2.animationDurationCounter = 0;
        gSubSpriteData2.currentAnimationFrame = 0;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        if (!(gSpriteData[ramSlot].status & SPRITE_STATUS_NOT_DRAWN))
            gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    }

    // Sync flip
    if (gSpriteData[ramSlot].status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;

    if (gCurrentSprite.roomSlot != RIDLEY_TAIL_PART_TIP)
    {
        if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
        {
            RidleyTailInit();
        }
        else if (gCurrentSprite.pose == SPRITE_POSE_DESTROYED)
        {
            if (gSpriteData[ramSlot].status & SPRITE_STATUS_NOT_DRAWN)
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            if (gSpriteData[ramSlot].status == 0)
            {
                RidleyTailDead();
                return;
            }
        }
        
        RidleyTailSyncSubSprites();
    }
    else
    {
        switch (gCurrentSprite.pose)
        {
            case SPRITE_POSE_UNINITIALIZED:
                RidleyTailInit();
                break;

            case RIDLEY_TAIL_POSE_IDLE:
                RidleyTailIdle();
                break;

            case RIDLEY_TAIL_POSE_MOVE_TO_ATTACK:
                RidleyTailCheckMovingToAttackAnimEnded();
                break;

            case RIDLEY_TAIL_POSE_SETTING_UP_ATTACK:
                RidleyTailSettingUpAttack();
                break;

            case RIDLEY_TAIL_POSE_CHARGING_ATTACK:
                RidleyTailChargingAttack();
                break;

            case RIDLEY_TAIL_POSE_FIRST_VERTICAL_ATTACK:
                RidleyTailFirstVerticalAttack();
                break;

            case RIDLEY_TAIL_POSE_VERTICAL_ATTACK:
                RidleyTailVerticalAttack();
                break;

            case RIDLEY_TAIL_POSE_LAST_VERTICAL_ATTACK:
                RidleyTailLastVerticalAttack();
                break;

            case RIDLEY_TAIL_POSE_DIAGONAL_ATTACK:
                RidleyTailDiagonalAttack();
                break;

            case RIDLEY_TAIL_POSE_BACK_TO_IDLE:
                RidleyTailCheckBackToIdleAnimEnded();
                break;
            
            default:
                if (gSpriteData[ramSlot].status & SPRITE_STATUS_NOT_DRAWN)
                    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                else
                    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

                if (gSpriteData[ramSlot].status == 0)
                {
                    RidleyTailDead();
                    return;
                }
        }

        SpriteUtilUpdateSubSprite2Anim();
        RidleyTailSyncSubSprites();
    }
}

/**
 * @brief 35034 | 168 | Ridley part AI
 * 
 */
void RidleyPart(void)
{
    u8 ramSlot;
    u8 part;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    part = gCurrentSprite.roomSlot;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        RidleyPartInit();
        return;
    }

    if (gCurrentSprite.pose == RIDLEY_PART_POSE_DYING)
    {
        if (part != RIDLEY_PART_TAIL)
        {
            if (part == RIDLEY_PART_LEFT_WING)
                RidleyPartWingPlaySound(ramSlot);

            if (gSpriteData[ramSlot].status & SPRITE_STATUS_NOT_DRAWN)
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        }

        if (gSpriteData[ramSlot].status == 0)
        {
            gCurrentSprite.status = 0;
            return;
        }

    }
    else if (gSpriteData[ramSlot].health == 0 && gCurrentSprite.pose < RIDLEY_PART_POSE_DYING)
    {
        // Set dying
        gCurrentSprite.pose = RIDLEY_PART_POSE_DYING;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    }

    // Sync flip
    if (gSpriteData[ramSlot].status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;

    if (part != RIDLEY_PART_TAIL && gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        if (!(gSpriteData[ramSlot].status & SPRITE_STATUS_NOT_DRAWN))
            gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    }

    switch (part)
    {
        case RIDLEY_PART_LEFT_WING:
            RidleyPartWingPlaySound(ramSlot);

        case RIDLEY_PART_RIGHT_WING:
            RidleyPartWingSetPaletteOffset();
            RidleyPartSyncPalette(ramSlot);
            RidleySyncSubSprites();
            break;

        case RIDLEY_PART_CLAW:
            RidleyPartClawIdle(ramSlot);
            RidleyPartClawUpdateSidesHitbox();

        case RIDLEY_PART_HEAD:
            RidleyPartSyncPalette(ramSlot);
            SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOam();
            break;

        default:
            RidleyPartSyncPalette(ramSlot);
            RidleySyncSubSprites();
    }
}

/**
 * @brief 35034 | 168 | Ridley fireball AI
 * 
 */
void RidleyFireball(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            RidleyFireballInit();
            break;

        case RIDLEY_FIREBALL_POSE_MOVE_DESCENDING_PATTERN:
            RidleyFireballMoveDescendingPattern();
            break;

        case RIDLEY_FIREBALL_POSE_MOVE_ASCENDING_PATTERN:
            RidleyFireballMoveAscendingPattern();
            break;

        case RIDLEY_FIREBALL_POSE_MOVE_FLOATING_PATTERN:
            RidleyFireballMoveFloatingPattern();
            break;

        case RIDLEY_FIREBALL_POSE_MOVE_DIAGONAL_PATTERN:
            RidleyFireballMoveDiagonalPattern();
            break;

        case RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL_INIT:
            RidleyFireballSlideOnWallInit();
        
        case RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL:
            RidleyFireballSlideOnWall();
            break;

        case RIDLEY_FIREBALL_POSE_DESTROY:
            gCurrentSprite.status = 0;
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
            SoundPlay(SOUND_RIDLEY_FIREBALL_EXPLODING);
            return;

        default:
            if (gCurrentSprite.spriteId == SSPRITE_RIDLEY_BIG_FIREBALL)
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
            else
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.rotation += HALF_BLOCK_SIZE;
    else
        gCurrentSprite.rotation -= HALF_BLOCK_SIZE;
}
