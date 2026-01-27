#include "sprites_ai/imago.h"
#include "macros.h"

#include "data/sprites/imago.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/event.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/clipdata.h"
#include "structs/connection.h"
#include "structs/game_state.h"
#include "structs/samus.h"
#include "structs/sprite.h"

MAKE_ENUM(u8, ImagoMovementStage) {
    IMAGO_MOVEMENT_STAGE_MOVING_HORIZONTALLY,
    IMAGO_MOVEMENT_STAGE_MOVING_VERTICALLY,
    IMAGO_MOVEMENT_STAGE_GO_UP
};

#define IMAGO_POSE_WAIT_FOR_LAST_EGG 0x1
#define IMAGO_POSE_SPAWN 0x2
#define IMAGO_POSE_COMING_DOWN_INIT 0x8
#define IMAGO_POSE_COMING_DOWN 0x9
#define IMAGO_POSE_MOVE_HORIZONTALLY 0x23
#define IMAGO_POSE_GOING_UP 0x25
#define IMAGO_POSE_ATTACKING_INIT 0x26
#define IMAGO_POSE_ATTACKING_GOING_DOWN 0x27
#define IMAGO_POSE_ATTACKING_GOING_UP 0x29
#define IMAGO_POSE_DYING_INIT 0x62
#define IMAGO_POSE_CHECK_SAMUS_AT_SUPER_MISSILE 0x67
#define IMAGO_POSE_CHARGING_THROUGH_WALL 0x68
#define IMAGO_POSE_DESTROY_WALL 0x69
#define IMAGO_POSE_DYING 0x6A
#define IMAGO_POSE_SET_EVENT 0x6C

#define IMAGO_SIZE (BLOCK_SIZE * 4)

#define IMAGO_HEAD_HITBOX (BLOCK_SIZE)
#define IMAGO_TAIL_HITBOX (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE)

#define IMAGO_CLOSE_DISTANCE (BLOCK_SIZE * 8 - QUARTER_BLOCK_SIZE + PIXEL_SIZE)
#define IMAGO_NEAR_DISTANCE (BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2)

// Imago part

#define IMAGO_PART_POSE_BODY_SPAWN 0x1
#define IMAGO_PART_POSE_BODY_UPDATE_PALETTE 0x8
#define IMAGO_PART_POSE_CORE_SYNC_PALETTE 0xE
#define IMAGO_PART_POSE_IDLE 0x42

#define IMAGO_PART_BODY_HITBOX_LEFT (HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE)
#define IMAGO_PART_BODY_HITBOX_RIGHT (BLOCK_SIZE * 3)

// Imago needle

#define IMAGO_NEEDLE_POSE_MOVING 0x9
#define IMAGO_NEEDLE_POSE_EXPLODING 0x42

// Imago damaged stinger

#define IMAGO_DAMAGED_STINGER_POSE_FALLING 0x9
#define IMAGO_DAMAGED_STINGER_POSE_DISAPPEARING 0x23

// Imago egg

#define IMAGO_EGG_POSE_IDLE 0x9
#define IMAGO_EGG_POSE_BREAKING 0x23
#define IMAGO_EGG_POSE_DISAPPEARING 0x25

#define IMAGO_EGG_PART_NORMAL 0x0
#define IMAGO_EGG_PART_LAST 0x80

static const struct FrameData* sImagoFrameDataPointers[IMAGO_OAM_COUNT] = {
    [IMAGO_OAM_BODY_IDLE] = sImagoPartOam_BodyIdle,
    [IMAGO_OAM_BODY_GROWLING] = sImagoPartOam_BodyGrowling,
    [IMAGO_OAM_BROKEN_STINGER] = sImagoOam_BrokenStinger,
    [IMAGO_OAM_LEFT_WING_IDLE] = sImagoPartOam_LeftWingIdle,
    [IMAGO_OAM_LEFT_WING_SHOOTING_NEEDLES] = sImagoPartOam_LeftWingShootingNeedles,
    [IMAGO_OAM_LEFT_WING_DYING] = sImagoPartOam_LeftWingDying,
    [IMAGO_OAM_RIGHT_WING_IDLE] = sImagoPartOam_RightWingIdle,
    [IMAGO_OAM_RIGHT_WING_SHOOTING_NEEDLES] = sImagoPartOam_RightWingShootingNeedles,
    [IMAGO_OAM_RIGHT_WING_DYING] = sImagoPartOam_RightWingDying,
    [IMAGO_OAM_CORE] = sImagoPartOam_Core,
    [IMAGO_OAM_FLYING] = sImagoOam_Flying,
    [IMAGO_OAM_SHOOTING_NEEDLES] = sImagoOam_ShootingNeedles,
    [IMAGO_OAM_RECHARGING_NEEDLES] = sImagoOam_RechargingNeedles,
    [IMAGO_OAM_DAMAGED_STINGER] = sImagoDamagedStingerOam,
    [IMAGO_OAM_NEEDLE] = sImagoNeedleOam,
    [IMAGO_OAM_DAMAGED_STINGER_UNUSED] = sImagoDamagedStingerOam_Unused,
    [IMAGO_OAM_EGG_BREAKING] = sImagoEggOam_Breaking
};

/**
 * @brief 41e4c | 88 | Sync the sub sprites of Imago
 * 
 */
static void ImagoSyncSubSprites(void)
{
    MultiSpriteDataInfo_T pData;
    u16 oamidx;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    oamidx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];
    
    if (gCurrentSprite.pOam != sImagoFrameDataPointers[oamidx])
    {
        gCurrentSprite.pOam = sImagoFrameDataPointers[oamidx];
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
 * @brief 41ed4 | 17c | Handles Imago shooting the needles
 * 
 */
static void ImagoShootNeedles(void)
{
    u32 health;
    u8 inRange;

    health = gCurrentSprite.health;
    if (health == 0)
        return;

    inRange = FALSE;
    if (gSubSpriteData1.pMultiOam == sImagoMultiSpriteData_Idle)
    {
        // Check samus in range for the needles
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                inRange = TRUE;
        }
        else
        {
            if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                inRange = TRUE;
        }

        // Check should shoot needles (health < 2/3) or no ammo, and in range
        if ((gCurrentSprite.health < gSubSpriteData1.health * 2 / 3 ||
            gEquipment.currentMissiles + gEquipment.currentSuperMissiles == 0) && inRange)
        {
            // Set shooting
            gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_ShootingNeedles;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
        }
    }
    else if (gSubSpriteData1.pMultiOam == sImagoMultiSpriteData_ShootingNeedles)
    {
        if (gCurrentSprite.currentAnimationFrame == FRAME_DATA_LAST_ANIM_FRAME(sImagoOam_ShootingNeedles) &&
            gCurrentSprite.animationDurationCounter == DELTA_TIME)
        {
            // Spawn needle
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                SpriteSpawnSecondary(SSPRITE_IMAGO_NEEDLE, gCurrentSprite.roomSlot,
                    gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                    gCurrentSprite.yPosition + (BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE - PIXEL_SIZE),
                    gCurrentSprite.xPosition + (HALF_BLOCK_SIZE - PIXEL_SIZE), SPRITE_STATUS_X_FLIP);
            }
            else
            {
                SpriteSpawnSecondary(SSPRITE_IMAGO_NEEDLE, gCurrentSprite.roomSlot,
                    gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                    gCurrentSprite.yPosition + (BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE - PIXEL_SIZE),
                    gCurrentSprite.xPosition - HALF_BLOCK_SIZE, 0);
            }
        }
        
        // Check speed up animation
        if (gCurrentSprite.health < gSubSpriteData1.health / 3)
        {
            APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);
            APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);
        }

        if (SpriteUtilHasSubSprite1AnimationEnded())
        {
            // Set recharging needles
            gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_RechargingNeedles;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
        }
    }
    else if (gSubSpriteData1.pMultiOam == sImagoMultiSpriteData_RechargingNeedles)
    {
        // Check speed up animation
        if (health < gSubSpriteData1.health / 3)
        {
            APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);
            APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);
        }

        if (SpriteUtilHasSubSprite1AnimationEnded())
        {
            // Set idle
            gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_Idle;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
        }
    }
}

/**
 * @brief 42050 | 68 | Updates the dynamic palette of the Imago core
 * 
 */
static void ImagoCoreFlashingAnim(void)
{
    u8 offset;
    u8 palette;
    u8 delay;

    if (SPRITE_GET_ISFT(gCurrentSprite) == 0)
    {
        // Update delay
        if (gCurrentSprite.scaling != 0)
        {
            gCurrentSprite.scaling--;
        }
        else
        {
            // Update offset
            offset = gCurrentSprite.rotation++;

            // Get palette row
            palette = sImagoDynamicPaletteData[offset][0];

            if (palette == 0x80)
            {
                // Reset offset
                gCurrentSprite.rotation = 1;
                offset = 0;
                palette = sImagoDynamicPaletteData[offset][0];
            }

            // Get new delay
            delay = sImagoDynamicPaletteData[offset][1];

            // Update palette and delay
            gCurrentSprite.absolutePaletteRow = palette;
            gCurrentSprite.paletteRow = palette;
            gCurrentSprite.scaling = delay;
        }
    }
}

/**
 * @brief 420b8 | 34 | Updates the side hitbox of Imago
 * 
 */
static void ImagoSetSidesHitbox(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = -IMAGO_HEAD_HITBOX;
        gCurrentSprite.hitboxRight = IMAGO_TAIL_HITBOX;
    }
    else
    {
        gCurrentSprite.hitboxLeft = -IMAGO_TAIL_HITBOX;
        gCurrentSprite.hitboxRight = IMAGO_HEAD_HITBOX;
    }
}

/**
 * @brief 420ec | 23c | Initializes an Imago sprite
 * 
 */
static void ImagoInit(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;
    u16 status;
    u16 health;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_IMAGO_KILLED))
    {
        gCurrentSprite.status = 0;
        return;
    }

    // Lock door, store initial max supers
    LOCK_DOORS();
    gSubSpriteData1.work4 = gEquipment.maxSuperMissiles;

    // Set in ceiling
    gCurrentSprite.yPosition -= BLOCK_SIZE * 6;
    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

    yPosition = gSubSpriteData1.yPosition;
    xPosition = gSubSpriteData1.xPosition;

    gCurrentSprite.yPositionSpawn = yPosition;
    gCurrentSprite.xPositionSpawn = xPosition;


    gCurrentSprite.status |= (SPRITE_STATUS_X_FLIP | SPRITE_STATUS_IGNORE_PROJECTILES);

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -PIXEL_SIZE;
    gCurrentSprite.hitboxBottom = BLOCK_SIZE * 2;
    ImagoSetSidesHitbox();

    gCurrentSprite.frozenPaletteRowOffset = 1;
    gCurrentSprite.scaling = 0;
    gCurrentSprite.rotation = 0;

    gCurrentSprite.samusCollision = SSC_HURTS_BIG_KNOCKBACK;
    gCurrentSprite.work0 = CONVERT_SECONDS(1.f) + ONE_THIRD_SECOND;
    health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.health = health;
    gSubSpriteData1.health = health;

    gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    // Last egg destroyed flag
    gSubSpriteData1.work3 = FALSE;
    gSubSpriteData1.work2 = 0;
    gCurrentSprite.pose = IMAGO_POSE_WAIT_FOR_LAST_EGG;
    gCurrentSprite.drawOrder = 5;
    gCurrentSprite.roomSlot = IMAGO_PART_IMAGO;

    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    status = gCurrentSprite.status & SPRITE_STATUS_X_FLIP;

    // Spawn parts
    SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_LEFT_WING_INTERNAL, gfxSlot, ramSlot, yPosition, xPosition, status);
    SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_LEFT_WING_EXTERNAL, gfxSlot, ramSlot, yPosition, xPosition, status);
    SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_BODY, gfxSlot, ramSlot, yPosition, xPosition, status);
    SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_RIGHT_WING_INTERNAL, gfxSlot, ramSlot, yPosition, xPosition, status);
    SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_RIGHT_WING_EXTERNAL, gfxSlot, ramSlot, yPosition, xPosition, status);
    SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_CORE, gfxSlot, ramSlot, yPosition, xPosition, status);

    // Spawn eggs
    SpriteSpawnSecondary(SSPRITE_IMAGO_EGG, IMAGO_EGG_PART_LAST, gfxSlot, ramSlot,
        yPosition + BLOCK_SIZE * 14, xPosition + BLOCK_SIZE * 3, 0);
    SpriteSpawnSecondary(SSPRITE_IMAGO_EGG, IMAGO_EGG_PART_NORMAL, gfxSlot, ramSlot,
        yPosition + BLOCK_SIZE * 15, xPosition + BLOCK_SIZE * 7, 0);
    SpriteSpawnSecondary(SSPRITE_IMAGO_EGG, IMAGO_EGG_PART_NORMAL, gfxSlot, ramSlot,
        yPosition + BLOCK_SIZE * 16, xPosition + BLOCK_SIZE * 12, 0);
    SpriteSpawnSecondary(SSPRITE_IMAGO_EGG, IMAGO_EGG_PART_NORMAL, gfxSlot, ramSlot,
        yPosition + BLOCK_SIZE * 18, xPosition + BLOCK_SIZE * 22, 0);
    SpriteSpawnSecondary(SSPRITE_IMAGO_EGG, IMAGO_EGG_PART_NORMAL, gfxSlot, ramSlot,
        yPosition + BLOCK_SIZE * 22, xPosition + BLOCK_SIZE * 42, 0);
}

/**
 * @brief 42328 | 24 | Checks if the last egg has been destroyed
 * 
 */
static void ImagoWaitForLastEgg(void)
{
    // Last egg destroyed flag
    if (gSubSpriteData1.work3)
    {
        gCurrentSprite.pose = IMAGO_POSE_SPAWN;
        FadeMusic(CONVERT_SECONDS(3.f / 5));
    }
}

/**
 * @brief 4234c | 38 | Handles Imago spawning
 * 
 */
static void ImagoSpawn(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);

    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = IMAGO_POSE_COMING_DOWN_INIT;
        PlayMusic(MUSIC_IMAGO_BATTLE, 0);
    }
}

/**
 * @brief 42384 | b0 | Initializes Imago coming down
 * 
 */
static void ImagoComingDownInit(void)
{
    if (gCurrentSprite.health == 0)
    {
        if (!(gCurrentSprite.status & SPRITE_STATUS_X_FLIP))
        {
            gCurrentSprite.pose = IMAGO_POSE_CHECK_SAMUS_AT_SUPER_MISSILE;
            return;
        }
    }
    else
    {
        gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_Idle;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
    }

    gCurrentSprite.work0 = 0;
    gCurrentSprite.work1 = 0;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.work2 = 0;
    }
    else
    {
        // Set base X velocity
        if (gCurrentSprite.health < gSubSpriteData1.health / 3)
            gCurrentSprite.work2 = EIGHTH_BLOCK_SIZE;
        else if (gCurrentSprite.health < gSubSpriteData1.health * 2 / 3)
            gCurrentSprite.work2 = EIGHTH_BLOCK_SIZE;
        else
            gCurrentSprite.work2 = 0;
    }

    gCurrentSprite.work3 = 0;
    gCurrentSprite.pose = IMAGO_POSE_COMING_DOWN;
    ImagoSetSidesHitbox();
}

/**
 * @brief 42434 | c4 | Handles Imago coming down
 * 
 */
static void ImagoComingDown(void)
{
    u32 blockTop;
    u8 checkGround;

    checkGround = FALSE;

    // Move X
    if (MOD_AND(gCurrentSprite.work0++, 16) == 0 && gCurrentSprite.work2 < QUARTER_BLOCK_SIZE - PIXEL_SIZE)
        gCurrentSprite.work2 += ONE_SUB_PIXEL;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gSubSpriteData1.xPosition += gCurrentSprite.work2;

    // Check should check ground
    if (gSubSpriteData1.yPosition + IMAGO_SIZE > gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 14)
        checkGround++;
    
    if (checkGround)
    {
        // Check for ground
        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gSubSpriteData1.yPosition + IMAGO_SIZE, gSubSpriteData1.xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            // Set moving horizontally
            gSubSpriteData1.yPosition = blockTop - IMAGO_SIZE;
            gCurrentSprite.pose = IMAGO_POSE_MOVE_HORIZONTALLY;
            return;
        }
    }
    
    // Move Y
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gSubSpriteData1.yPosition += QUARTER_BLOCK_SIZE - PIXEL_SIZE;
    else
        gSubSpriteData1.yPosition += QUARTER_BLOCK_SIZE + PIXEL_SIZE;
}

/**
 * @brief 424f8 | 2b8 | Handles Imago moving horizontally through the room
 * 
 */
static void ImagoMoveHorizontally(void)
{
    u8 ySpeedMask;
    u8 movementStage;
    u16 xPosition;
    u16 yPosition;
    u32 blockTop;

    ImagoShootNeedles();

    movementStage = IMAGO_MOVEMENT_STAGE_MOVING_HORIZONTALLY;

    // Move X
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (MOD_AND(gCurrentSprite.work0++, 16) == 0 && gCurrentSprite.work2 < QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE)
            gCurrentSprite.work2 += ONE_SUB_PIXEL;

        ySpeedMask = 1;

        if (gSubSpriteData1.xPosition > gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 46)
        {
            movementStage = IMAGO_MOVEMENT_STAGE_GO_UP;
        }
        else
        {
            if (gSubSpriteData1.xPosition > gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 36)
                movementStage = IMAGO_MOVEMENT_STAGE_MOVING_VERTICALLY;

            gSubSpriteData1.xPosition += gCurrentSprite.work2;
        }
    }
    else
    {
        if (gCurrentSprite.health < gSubSpriteData1.health / 3)
        {
            if (MOD_AND(gCurrentSprite.work0++, 8) == 0 && gCurrentSprite.work2 < QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE)
                gCurrentSprite.work2 += ONE_SUB_PIXEL;

            ySpeedMask = 3;

            if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn)
                movementStage = IMAGO_MOVEMENT_STAGE_GO_UP;
            else
            {
                if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 22)
                    movementStage = IMAGO_MOVEMENT_STAGE_MOVING_VERTICALLY;

                gSubSpriteData1.xPosition -= gCurrentSprite.work2;
            }
        }
        else if (gCurrentSprite.health < gSubSpriteData1.health * 2 / 3)
        {
            if (MOD_AND(gCurrentSprite.work0++, 16) == 0 && gCurrentSprite.work2 < QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE)
                gCurrentSprite.work2 += ONE_SUB_PIXEL;

            ySpeedMask = 3;

            if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn)
                movementStage = IMAGO_MOVEMENT_STAGE_GO_UP;
            else
            {
                if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 16)
                    movementStage = IMAGO_MOVEMENT_STAGE_MOVING_VERTICALLY;

                gSubSpriteData1.xPosition -= gCurrentSprite.work2;
            }
        }
        else
        {
            if (MOD_AND(gCurrentSprite.work0++, 16) == 0 && gCurrentSprite.work2 < QUARTER_BLOCK_SIZE)
                gCurrentSprite.work2++;

            ySpeedMask = 3;

            if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn)
                movementStage = IMAGO_MOVEMENT_STAGE_GO_UP;
            else
            {
                if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 11)
                    movementStage = IMAGO_MOVEMENT_STAGE_MOVING_VERTICALLY;

                gSubSpriteData1.xPosition -= gCurrentSprite.work2;
            }
        }
    }

    if (movementStage != IMAGO_MOVEMENT_STAGE_MOVING_HORIZONTALLY)
    {
        if (!(ySpeedMask & gCurrentSprite.work1++) && gCurrentSprite.work3 < QUARTER_BLOCK_SIZE - PIXEL_SIZE)
            gCurrentSprite.work3 += ONE_SUB_PIXEL;

        gSubSpriteData1.yPosition -= gCurrentSprite.work3;
        if (movementStage == IMAGO_MOVEMENT_STAGE_GO_UP)
        {
            gCurrentSprite.pose = IMAGO_POSE_GOING_UP;
            return;
        }
    }

    yPosition = gSubSpriteData1.yPosition + IMAGO_SIZE;
    xPosition = gSubSpriteData1.xPosition;

    // "Hover" over the ground
    blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition - PIXEL_SIZE, xPosition);
    if ((gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F) >= COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
    {
        gSubSpriteData1.yPosition = blockTop - IMAGO_SIZE;
        return;
    }
    
    blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition, xPosition);
    if ((gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F) >= COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
    {
        gSubSpriteData1.yPosition = blockTop - IMAGO_SIZE;
        return;
    }

    blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition + PIXEL_SIZE, xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gSubSpriteData1.yPosition = blockTop - IMAGO_SIZE;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteUtilCheckVerticalCollisionAtPosition(yPosition, xPosition - QUARTER_BLOCK_SIZE);
        if (gPreviousVerticalCollisionCheck == COLLISION_LEFT_STEEP_FLOOR_SLOPE || gPreviousVerticalCollisionCheck == COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
        {
            blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition + BLOCK_SIZE, xPosition);
            gSubSpriteData1.yPosition = blockTop - IMAGO_SIZE;
        }
    }
    else
    {
        SpriteUtilCheckVerticalCollisionAtPosition(yPosition, xPosition + QUARTER_BLOCK_SIZE);
        if (gPreviousVerticalCollisionCheck == COLLISION_RIGHT_STEEP_FLOOR_SLOPE || gPreviousVerticalCollisionCheck == COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE)
        {
            blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition + BLOCK_SIZE, xPosition);
            gSubSpriteData1.yPosition = blockTop - IMAGO_SIZE;
        }
    }
}

/**
 * @brief 427b0 | c4 | Handles Imago going up
 * 
 */
static void ImagoGoingUp(void)
{
    // Check increase Y velocity
    if (MOD_AND(gCurrentSprite.work1++, 4) == 0 && gCurrentSprite.work3 < QUARTER_BLOCK_SIZE - PIXEL_SIZE)
        gCurrentSprite.work3 += ONE_SUB_PIXEL;

    if (gSubSpriteData1.yPosition < gCurrentSprite.yPositionSpawn)
    {
        // Arrived at ceiling
        gSubSpriteData1.yPosition = gCurrentSprite.yPositionSpawn;
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            // Set X destination
            gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 48;
            // Check if Samus in range for the attack
            if (gSubSpriteData1.xPosition < gSamusData.xPosition && gCurrentSprite.health != 0)
            {
                // Set attacking
                gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 46;
                gCurrentSprite.work2 = 0;
                gCurrentSprite.pose = IMAGO_POSE_ATTACKING_INIT;
            }
            else
            {
                // Set coming down
                gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
                gCurrentSprite.pose = IMAGO_POSE_COMING_DOWN_INIT;
            }
        }
        else
        {
            // Set X destination
            gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn;
            // Check if Samus in range for the attack
            if (gSubSpriteData1.xPosition + BLOCK_SIZE * 2 > gSamusData.xPosition && gCurrentSprite.health != 0)
            {
                // Set attacking
                gCurrentSprite.work2 = ARRAY_SIZE(sImagoAttackingXVelocity) / 2;
                gCurrentSprite.pose = IMAGO_POSE_ATTACKING_INIT;
            }
            else
            {
                // Set coming down
                gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
                gCurrentSprite.pose = IMAGO_POSE_COMING_DOWN_INIT;
            }
        }
    }
    else
    {
        gSubSpriteData1.yPosition -= gCurrentSprite.work3; // Move
    }
}

/**
 * @brief 42874 | 24 | Initializes Imago to be attacking
 * 
 */
static void ImagoAttackingInit(void)
{
    gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = IMAGO_POSE_ATTACKING_GOING_DOWN;
}

/**
 * @brief 42898 | a8 | Handles Imago going down when attacking
 * 
 */
static void ImagoAttackingGoingDown(void)
{
    u8 offset;
    s32 movement;
    u8 checkGround;
    u32 blockTop;

    checkGround = FALSE;

    // Move X
    offset = gCurrentSprite.work2;
    movement = sImagoAttackingXVelocity[offset];
    if (movement == SHORT_MAX)
    {
        movement = sImagoAttackingXVelocity[0]; // -1
        offset = 0;
    }

    gCurrentSprite.work2 = offset + 1;
    gSubSpriteData1.xPosition += movement * 2;

    // Check should check for ground
    if (gSubSpriteData1.yPosition + IMAGO_SIZE > gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 14)
        checkGround = TRUE;

    if (checkGround)
    {
        // Check for ground
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            movement = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
        else
            movement = IMAGO_SIZE;

        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gSubSpriteData1.yPosition + movement, gSubSpriteData1.xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            // Touched ground, set going up
            gSubSpriteData1.yPosition = blockTop - movement;
            gCurrentSprite.pose = IMAGO_POSE_ATTACKING_GOING_UP;
            gCurrentSprite.work3 = QUARTER_BLOCK_SIZE - PIXEL_SIZE;
            return;
        }
    }

    // Move Y
    gSubSpriteData1.yPosition += QUARTER_BLOCK_SIZE + PIXEL_SIZE;
}

/**
 * @brief 42940 | bc | Handles Imago going up when attacking
 * 
 */
static void ImagoAttackingGoingUp(void)
{
    s32 movement;
    u8 offset;
    u32 blockTop;

    // Move X
    offset = gCurrentSprite.work2;
    movement = sImagoAttackingXVelocity[offset];
    if (movement == SHORT_MAX)
    {
        movement = sImagoAttackingXVelocity[0]; // -1
        offset = 0;
    }
    gCurrentSprite.work2 = offset + 1;
    gSubSpriteData1.xPosition += movement * 2;

    if (gSubSpriteData1.yPosition < gCurrentSprite.yPositionSpawn)
    {
        // Arrived at ceiling
        gSubSpriteData1.yPosition = gCurrentSprite.yPositionSpawn;
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            // Check should attack again
            if (gSubSpriteData1.xPosition < gSamusData.xPosition && gCurrentSprite.health != 0)
            {
                // In range, set attacking
                gCurrentSprite.pose = IMAGO_POSE_ATTACKING_GOING_DOWN;
            }
            else
            {
                // Out of range or dying, set coming down
                gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 48;
                gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
                gCurrentSprite.pose = IMAGO_POSE_COMING_DOWN_INIT;
            }
        }
        else
        {
            // Check should attack again
            if (gSubSpriteData1.xPosition + BLOCK_SIZE * 2 > gSamusData.xPosition && gCurrentSprite.health != 0)
            {
                // In range, set attacking
                gCurrentSprite.pose = IMAGO_POSE_ATTACKING_GOING_DOWN;
            }
            else
            {
                // Out of range or dying, set coming down
                gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn;
                gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
                gCurrentSprite.pose = IMAGO_POSE_COMING_DOWN_INIT;
            }
        }
    }
    else
    {
        // Move Y
        gSubSpriteData1.yPosition -= QUARTER_BLOCK_SIZE + PIXEL_SIZE;
    }
}

/**
 * @brief 429fc | 94 | Initializes Imago to be dying
 * 
 */
static void ImagoDyingInit(void)
{
    // Spawn damaged stinger
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteSpawnSecondary(SSPRITE_IMAGO_DAMAGED_STINGER, gCurrentSprite.roomSlot,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition + (HALF_BLOCK_SIZE - PIXEL_SIZE), SPRITE_STATUS_X_FLIP);
    }
    else
    {
        SpriteSpawnSecondary(SSPRITE_IMAGO_DAMAGED_STINGER, gCurrentSprite.roomSlot,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition - HALF_BLOCK_SIZE, 0);
    }

    // Set dying
    gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_Dying;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.samusCollision = SSC_NONE;
    // Retrieve previous pose
    gCurrentSprite.pose = gSubSpriteData1.work2;
}

/**
 * @brief 42a90 | 68 | Checks if Samus is at the super missile when Imago is dying
 * 
 */
static void ImagoCheckSamusAtSuperMissile(void)
{
    u8 atLocation;

    // Check at location
    atLocation = FALSE;
    if (gSamusData.xPosition > gCurrentSprite.xPositionSpawn)
    {
        if (gSamusData.xPosition - gCurrentSprite.xPositionSpawn < BLOCK_SIZE * 3)
            atLocation = TRUE;
    }
    else
    {
        if (gCurrentSprite.xPositionSpawn - gSamusData.xPosition < BLOCK_SIZE * 3)
            atLocation = TRUE;
    }

    if (atLocation)
    {
        // Set going through wall
        gCurrentSprite.pose = IMAGO_POSE_CHARGING_THROUGH_WALL;
        gCurrentSprite.drawOrder = 12;

        // Set position
        gSubSpriteData1.yPosition = gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 11 + HALF_BLOCK_SIZE;
        gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 16;
    }
}

/**
 * @brief 42af8 | 100 | Handles Imago charging through the wall
 * 
 */
static void ImagoChargeThroughWall(void)
{
    ClipdataAffectingAction caa;
    u16 yPosition;
    u16 xPosition;

    caa = CAA_REMOVE_SOLID;
    yPosition = gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 5 + HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPositionSpawn;

    if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition - BLOCK_SIZE * 3) != COLLISION_AIR)
    {
        ScreenShakeStartHorizontal(CONVERT_SECONDS(.5f), 0x80 | 1);
        gCurrentSprite.pose = IMAGO_POSE_DESTROY_WALL;
        gCurrentSprite.work0 = 0;

        // Right part
        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition + BLOCK_SIZE * 2);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition + BLOCK_SIZE * 2);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition + BLOCK_SIZE * 8, xPosition + BLOCK_SIZE * 2);

        ParticleSet(yPosition + BLOCK_SIZE * 8, xPosition + BLOCK_SIZE * 2, PE_SPRITE_EXPLOSION_HUGE);
        
        // Left part
        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition + BLOCK_SIZE * 1);
        
        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition + BLOCK_SIZE * 1);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition + BLOCK_SIZE * 1);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition + BLOCK_SIZE * 8, xPosition + BLOCK_SIZE * 1);

        ParticleSet(yPosition + BLOCK_SIZE * 7, xPosition + BLOCK_SIZE * 1, PE_SPRITE_EXPLOSION_HUGE);
        SoundPlay(SOUND_IMAGO_DESTROYING_WALL);
    }
    else
    {
        gSubSpriteData1.xPosition -= QUARTER_BLOCK_SIZE; // Move
    }
}

/**
 * @brief 42bf8 | 378 | Handles Imago destroying the wall
 * 
 */
static void ImagoDestroyWall(void)
{
    ClipdataAffectingAction caa;
    u16 yPosition;
    u16 xPosition;
    
    caa = CAA_REMOVE_SOLID;
    yPosition = gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 5 + HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPositionSpawn;

    switch (gCurrentSprite.work0++)
    {
        case 0:
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition);
            
            ParticleSet(yPosition + BLOCK_SIZE * 7, xPosition, PE_SPRITE_EXPLOSION_HUGE);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 4, xPosition - BLOCK_SIZE);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition - BLOCK_SIZE);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition - BLOCK_SIZE);
            
            ParticleSet(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE, PE_SPRITE_EXPLOSION_HUGE);
            ParticleSet(yPosition + BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE, xPosition - (BLOCK_SIZE + 8), PE_SPRITE_EXPLOSION_HUGE);
            break;

        case CONVERT_SECONDS(.1f + 1.f / 30):
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 4, xPosition - BLOCK_SIZE * 2);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition - BLOCK_SIZE * 2);
            
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 2);
            
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition - BLOCK_SIZE * 2);
            
            ParticleSet(yPosition + BLOCK_SIZE * 7, xPosition - BLOCK_SIZE * 2, PE_SPRITE_EXPLOSION_HUGE);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 4, xPosition - BLOCK_SIZE * 3);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition - BLOCK_SIZE * 3);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 3);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition - BLOCK_SIZE * 3);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 8, xPosition - BLOCK_SIZE * 3);
            
            ParticleSet(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 3, PE_SPRITE_EXPLOSION_HUGE);
            break;

        case CONVERT_SECONDS(.25f + 1.f / 60):
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition - BLOCK_SIZE * 4);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 4);
            
            ParticleSet(yPosition + BLOCK_SIZE * 8, xPosition - BLOCK_SIZE * 4, PE_SPRITE_EXPLOSION_HUGE);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition - BLOCK_SIZE * 5);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 5);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition - BLOCK_SIZE * 5);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 8, xPosition - BLOCK_SIZE * 5);
            
            ParticleSet(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 5, PE_SPRITE_EXPLOSION_HUGE);
            break;

        case CONVERT_SECONDS(.4f):
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition - BLOCK_SIZE * 6);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 6);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition - BLOCK_SIZE * 6);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 8, xPosition - BLOCK_SIZE * 6);
            
            ParticleSet(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 6, PE_SPRITE_EXPLOSION_HUGE);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 7);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition - BLOCK_SIZE * 7);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 8, xPosition - BLOCK_SIZE * 7);
            
            ParticleSet(yPosition + BLOCK_SIZE * 8, xPosition - BLOCK_SIZE * 8, PE_SPRITE_EXPLOSION_HUGE);
            break;

        case CONVERT_SECONDS(.45f + 1.f / 60):
            // Reached indestructible wall
            gCurrentSprite.pose = IMAGO_POSE_DYING;
            gCurrentSprite.work0 = 0;
            ScreenShakeStartVertical(CONVERT_SECONDS(.5f), 0x80 | 1);
            ScreenShakeStartHorizontal(CONVERT_SECONDS(1.f), 0x80 | 1);
            FadeMusic(CONVERT_SECONDS(14.f / 15));
            break;
    }

    // Move
    gSubSpriteData1.xPosition -= QUARTER_BLOCK_SIZE;
    gSubSpriteData1.yPosition += PIXEL_SIZE / 2;
}

/**
 * @brief 42f70 | 204 | Handles Imago dying
 * 
 */
static void ImagoDying(void)
{
    if (MOD_AND(gCurrentSprite.work0, 16) == 0)
    {
        if (MOD_BLOCK_AND(gCurrentSprite.work0, 16))
        {
            ParticleSet(gSubSpriteData1.yPosition + BLOCK_SIZE + HALF_BLOCK_SIZE,
                gSubSpriteData1.xPosition - (BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2), PE_TWO_MEDIUM_DUST);
        }
        else
        {
            ParticleSet(gSubSpriteData1.yPosition + BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
                gSubSpriteData1.xPosition - (THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE / 2), PE_MEDIUM_DUST);
        }
    }

    switch (gCurrentSprite.work0++)
    {
        case 0:
            ParticleSet(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            break;

        case CONVERT_SECONDS(.15f):
            ParticleSet(gSubSpriteData1.yPosition + HALF_BLOCK_SIZE, gSubSpriteData1.xPosition - BLOCK_SIZE * 2, PE_SPRITE_EXPLOSION_HUGE);
            break;
        
        case CONVERT_SECONDS(.3f):
            ParticleSet(gSubSpriteData1.yPosition - HALF_BLOCK_SIZE, gSubSpriteData1.xPosition + HALF_BLOCK_SIZE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            break;
        
        case CONVERT_SECONDS(.45f):
            ParticleSet(gSubSpriteData1.yPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE), gSubSpriteData1.xPosition - BLOCK_SIZE, PE_SPRITE_EXPLOSION_BIG);
            break;

        case CONVERT_SECONDS(.6f):
            ParticleSet(gSubSpriteData1.yPosition - HALF_BLOCK_SIZE, gSubSpriteData1.xPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            break;

        case CONVERT_SECONDS(.75f):
            ParticleSet(gSubSpriteData1.yPosition - THREE_QUARTER_BLOCK_SIZE, gSubSpriteData1.xPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE), PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            break;

        case CONVERT_SECONDS(.9f):
            ParticleSet(gSubSpriteData1.yPosition + QUARTER_BLOCK_SIZE, gSubSpriteData1.xPosition - (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE - PIXEL_SIZE), PE_SPRITE_EXPLOSION_HUGE);
            gCurrentSprite.pose = IMAGO_POSE_SET_EVENT;
            gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
            SoundPlay(SOUND_IMAGO_DYING);
            PlayMusic(MUSIC_BOSS_KILLED, 0);
    }
}

/**
 * @brief 43174 | 44 | Checks if the Imago event should be set
 * 
 */
static void ImagoSetEvent(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    if (gEquipment.maxSuperMissiles > gSubSpriteData1.work4)
    {
        // More supers than at the beginning of the fight
        // Unlock doors
        gDoorUnlockTimer = -CONVERT_SECONDS(1.f);
        gCurrentSprite.status = 0;
        // Set event
        EventFunction(EVENT_ACTION_SETTING, EVENT_IMAGO_KILLED);
    }
}

/**
 * @brief 431b8 | 30 | Sets the sides hitboxes of body Imago part
 * 
 */
static void ImagoPartSetBodySidesHitbox(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = -IMAGO_PART_BODY_HITBOX_LEFT;
        gCurrentSprite.hitboxRight = IMAGO_PART_BODY_HITBOX_RIGHT;
    }
    else
    {
        gCurrentSprite.hitboxLeft = -IMAGO_PART_BODY_HITBOX_RIGHT;
        gCurrentSprite.hitboxRight = IMAGO_PART_BODY_HITBOX_LEFT;
    }
}

/**
 * @brief 431e8 | 13c | Initializes an Imago part sprite
 * 
 */
static void ImagoPartInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.pose = IMAGO_PART_POSE_IDLE;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    switch (gCurrentSprite.roomSlot)
    {
        case IMAGO_PART_LEFT_WING_INTERNAL:
        case IMAGO_PART_LEFT_WING_EXTERNAL:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.drawOrder = 2;
            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case IMAGO_PART_BODY:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2);
            gCurrentSprite.hitboxBottom = 0;
            ImagoPartSetBodySidesHitbox();

            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.health = 1;
            gCurrentSprite.pose = IMAGO_PART_POSE_BODY_SPAWN;
            break;

        case IMAGO_PART_RIGHT_WING_INTERNAL:
        case IMAGO_PART_RIGHT_WING_EXTERNAL:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
            
            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case IMAGO_PART_CORE:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
            
            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 1;
            gCurrentSprite.pose = IMAGO_PART_POSE_CORE_SYNC_PALETTE;
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 43324 | 3c | Handles the spawn of the Imago body
 * 
 */
static void ImagoPartBodySpawn(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (gSpriteData[ramSlot].pose >= IMAGO_POSE_COMING_DOWN_INIT)
    {
        // Fight started, set vulnerable
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = IMAGO_PART_POSE_BODY_UPDATE_PALETTE;
    }
}

/**
 * @brief 43360 | 64 | Handles updating the palette row of the body based on health
 * 
 */
static void ImagoPartUpdateBodyPalette(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[ramSlot].health < gSubSpriteData1.health / 3)
    {
        // 1/3 of health left
        gCurrentSprite.absolutePaletteRow = 5;
        gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }
    else if (gSpriteData[ramSlot].health < gSubSpriteData1.health * 2 / 3)
    {
        // 2/3 of health left
        gCurrentSprite.absolutePaletteRow = 4;
        gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }

    ImagoPartSetBodySidesHitbox();
}

/**
 * @brief 433c4 | 34 | Synchronizes the palette of the part with the palette of Imago
 * 
 */
static void ImagoPartSyncPalette(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    gCurrentSprite.paletteRow = gSpriteData[ramSlot].paletteRow;
    gCurrentSprite.absolutePaletteRow = gSpriteData[ramSlot].absolutePaletteRow;
}

/**
 * @brief 433f8 | 420 | Imago AI
 * 
 */
void Imago(void)
{
    u16 xDistance;
    u16 yDistance;
    u32 health;
    u8 pose;

    if (gCurrentSprite.pose < IMAGO_POSE_DYING_INIT && gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_IMAGO_DAMAGED);
    }

    if (MOD_AND(gFrameCounter8Bit, 16) == 0)
    {
        health = gCurrentSprite.health;
        pose = gCurrentSprite.pose - 8;

        if (pose < IMAGO_POSE_DESTROY_WALL - 8)
        {
            if (gSubSpriteData1.yPosition > gSamusData.yPosition)
                yDistance = gSubSpriteData1.yPosition - gSamusData.yPosition;
            else
                yDistance = gSamusData.yPosition - gSubSpriteData1.yPosition;
    
            if (gSubSpriteData1.xPosition > gSamusData.xPosition)
            {
                xDistance = gSubSpriteData1.xPosition - gSamusData.xPosition;
                if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) || yDistance > IMAGO_CLOSE_DISTANCE)
                {
                    gSamusData.yPosition += 0; // Needed to produce matching ASM.
                    SoundPlay(SOUND_IMAGO_BUZZING_FAR_RIGHT);
                    if (health == 0)
                        SoundPlay(SOUND_IMAGO_BURNING_FAR_RIGHT);
                }
                else if (xDistance < IMAGO_NEAR_DISTANCE)
                {
                    SoundPlay(SOUND_IMAGO_BUZZING_CLOSE_RIGHT);
                    if (health == 0)
                        SoundPlay(SOUND_IMAGO_BURNING_CLOSE_RIGHT);
                }
                else
                {
                    SoundPlay(SOUND_IMAGO_BUZZING_NEAR_RIGHT);
                    if (health == 0)
                        SoundPlay(SOUND_IMAGO_BURNING_NEAR_RIGHT);
                }
            }
            else
            {
                xDistance = gSamusData.xPosition - gSubSpriteData1.xPosition;
                if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) || yDistance > IMAGO_CLOSE_DISTANCE)
                {
                    SoundPlay(SOUND_IMAGO_BUZZING_FAR_LEFT);
                    if (health == 0)
                        SoundPlay(SOUND_IMAGO_BURNING_FAR_LEFT);
                }
                else if (xDistance < IMAGO_NEAR_DISTANCE)
                {
                    SoundPlay(SOUND_IMAGO_BUZZING_CLOSE_LEFT);
                    if (health == 0)
                        SoundPlay(SOUND_IMAGO_BURNING_CLOSE_LEFT);
                }
                else
                {
                    SoundPlay(SOUND_IMAGO_BUZZING_NEAR_LEFT);
                    if (health == 0)
                        SoundPlay(SOUND_IMAGO_BURNING_NEAR_LEFT);
                }
            }
        }
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ImagoInit();
            break;

        case IMAGO_POSE_WAIT_FOR_LAST_EGG:
            ImagoWaitForLastEgg();
            break;

        case IMAGO_POSE_SPAWN:
            ImagoSpawn();
            break;

        case IMAGO_POSE_COMING_DOWN_INIT:
            ImagoComingDownInit();
            break;

        case IMAGO_POSE_COMING_DOWN:
            ImagoComingDown();
            break;

        case IMAGO_POSE_MOVE_HORIZONTALLY:
            ImagoMoveHorizontally();
            break;

        case IMAGO_POSE_GOING_UP:
            ImagoGoingUp();
            break;

        case IMAGO_POSE_ATTACKING_INIT:
            ImagoAttackingInit();
        
        case IMAGO_POSE_ATTACKING_GOING_DOWN:
            ImagoAttackingGoingDown();
            break;

        case IMAGO_POSE_ATTACKING_GOING_UP:
            ImagoAttackingGoingUp();
            break;

        #ifndef BUGFIX
        case IMAGO_POSE_DYING_INIT:
            ImagoDyingInit();
            break;
        #endif // !BUGFIX

        case IMAGO_POSE_CHECK_SAMUS_AT_SUPER_MISSILE:
            ImagoCheckSamusAtSuperMissile();
            break;

        case IMAGO_POSE_CHARGING_THROUGH_WALL:
            ImagoChargeThroughWall();
            break;

        case IMAGO_POSE_DESTROY_WALL:
            ImagoDestroyWall();
            break;

        case IMAGO_POSE_DYING:
            ImagoDying();
            break;

        case IMAGO_POSE_SET_EVENT:
            ImagoSetEvent();
            break;
        
        #ifdef BUGFIX
        default:
            ImagoDyingInit();
            break;
        #endif // BUGFIX
    }

    if (gCurrentSprite.pose <= IMAGO_POSE_DYING && gCurrentSprite.status)
    {
        gSubSpriteData1.work2 = gCurrentSprite.pose;
        if (gCurrentSprite.health == 0 && gCurrentSprite.pose <= IMAGO_POSE_CHARGING_THROUGH_WALL)
        {
            if (MOD_AND(gFrameCounter8Bit, 4) == 0)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                    ParticleSet(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition - BLOCK_SIZE, PE_SPRITE_EXPLOSION_MEDIUM);
                else
                    ParticleSet(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition + BLOCK_SIZE, PE_SPRITE_EXPLOSION_MEDIUM);

                if (gCurrentSprite.pose <= IMAGO_POSE_CHECK_SAMUS_AT_SUPER_MISSILE)
                {
                    if (MOD_BLOCK_AND(gFrameCounter8Bit, 4))
                        gCurrentSprite.paletteRow = SPRITE_GET_STUN_PALETTE(gCurrentSprite);
                    else
                        gCurrentSprite.paletteRow = 0;
                }
                else
                {
                    gCurrentSprite.paletteRow = 0;
                }
            }
        }
        else
            ImagoCoreFlashingAnim();

        SpriteUtilUpdateSubSprite1Anim();
        ImagoSyncSubSprites();
    }
}

/**
 * @brief 43818 | 1b0 | Imago part AI
 * 
 */
void ImagoPart(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[ramSlot].status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;

    if (gSpriteData[ramSlot].health == 0)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        
        if (gSpriteData[ramSlot].pose >= IMAGO_POSE_CHARGING_THROUGH_WALL)
        {
            switch (gCurrentSprite.roomSlot)
            {
                case IMAGO_PART_LEFT_WING_INTERNAL:
                case IMAGO_PART_LEFT_WING_EXTERNAL:
                    gCurrentSprite.drawOrder = 9;
                    break;

                case IMAGO_PART_BODY:
                    gCurrentSprite.drawOrder = 10;
                    break;

                case IMAGO_PART_RIGHT_WING_INTERNAL:
                case IMAGO_PART_RIGHT_WING_EXTERNAL:
                case IMAGO_PART_CORE:
                    gCurrentSprite.drawOrder = 11;
            }
        }
    }

    if (gSpriteData[ramSlot].pose > IMAGO_POSE_DYING)
    {
        switch (gCurrentSprite.roomSlot)
        {
            case IMAGO_PART_LEFT_WING_INTERNAL:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - QUARTER_BLOCK_SIZE,
                    gSubSpriteData1.xPosition + BLOCK_SIZE + EIGHTH_BLOCK_SIZE, FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                break;

            case IMAGO_PART_LEFT_WING_EXTERNAL:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE),
                    gSubSpriteData1.xPosition, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
                break;

            case IMAGO_PART_BODY:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition + THREE_QUARTER_BLOCK_SIZE,
                    gSubSpriteData1.xPosition - (HALF_BLOCK_SIZE - PIXEL_SIZE), FALSE, PE_SPRITE_EXPLOSION_BIG);
                break;

            case IMAGO_PART_RIGHT_WING_INTERNAL:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - THREE_QUARTER_BLOCK_SIZE,
                    gSubSpriteData1.xPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE), FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
                break;

            case IMAGO_PART_RIGHT_WING_EXTERNAL:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition + HALF_BLOCK_SIZE,
                    gSubSpriteData1.xPosition - (BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE), FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                break;

            case IMAGO_PART_CORE:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE,
                    gSubSpriteData1.xPosition - (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2),
                    FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
                break;

            default:
                gCurrentSprite.status = 0;
        }
    }
    else
    {
        switch (gCurrentSprite.pose)
        {
            case SPRITE_POSE_UNINITIALIZED:
                ImagoPartInit();
                break;

            case IMAGO_PART_POSE_BODY_SPAWN:
                ImagoPartBodySpawn();
                break;

            case IMAGO_PART_POSE_BODY_UPDATE_PALETTE:
                ImagoPartUpdateBodyPalette();
                break;

            case IMAGO_PART_POSE_CORE_SYNC_PALETTE:
                ImagoPartSyncPalette();
        }

        ImagoSyncSubSprites();
    }
}

/**
 * @brief 439c8 | ec | Imago needle AI
 * 
 */
void ImagoNeedle(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(QUARTER_BLOCK_SIZE - PIXEL_SIZE);
            gCurrentSprite.hitboxBottom = (QUARTER_BLOCK_SIZE - PIXEL_SIZE);
            gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE - PIXEL_SIZE);
            gCurrentSprite.hitboxRight = (QUARTER_BLOCK_SIZE - PIXEL_SIZE);

            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.pOam = sImagoNeedleOam;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
            gCurrentSprite.pose = IMAGO_NEEDLE_POSE_MOVING;
            SoundPlay(SOUND_IMAGO_NEEDLE_SHOT);
            break;

        case IMAGO_NEEDLE_POSE_MOVING:
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                gCurrentSprite.xPosition += QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
            else
                gCurrentSprite.xPosition -= QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

            gCurrentSprite.yPosition += QUARTER_BLOCK_SIZE - PIXEL_SIZE;

            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
                gCurrentSprite.pose = IMAGO_NEEDLE_POSE_EXPLODING;
            break;

        case IMAGO_NEEDLE_POSE_EXPLODING:
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SMALL);
            SoundPlay(SOUND_SPRITE_EXPLOSION_SMALL);
            gCurrentSprite.status = 0;
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}

/**
 * @brief 43ab4 | 1a4 | Imago damaged stinger AI
 * 
 */
void ImagoDamagedStinger(void)
{
    s32 movement;
    u8 offset;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = (BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

            gCurrentSprite.pOam = sImagoDamagedStingerOam;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 1;
            gCurrentSprite.drawOrder = 12;
            gCurrentSprite.pose = IMAGO_DAMAGED_STINGER_POSE_FALLING;
            gCurrentSprite.work0 = 0;
            gCurrentSprite.work2 = CONVERT_SECONDS(1.f / 6);
            gCurrentSprite.work3 = 0;
            SoundPlay(SOUND_IMAGO_DAMAGED_STINGER_DETACHING);

        case IMAGO_DAMAGED_STINGER_POSE_FALLING:
            if (MOD_AND(gCurrentSprite.work0, 8) == 0)
                ParticleSet(gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_BIG);

            // Move Y
            offset = gCurrentSprite.work3;
            movement = sImagoDamagedStingerFallingYVelocity[offset];
            if (movement == SHORT_MAX)
            {
                movement = sImagoDamagedStingerFallingYVelocity[offset - 1];
                gCurrentSprite.yPosition += movement;
            }
            else
            {
                gCurrentSprite.work3++;
                gCurrentSprite.yPosition += movement;
            }

            APPLY_DELTA_TIME_INC(gCurrentSprite.work0);
            if (gCurrentSprite.work2 != 0)
            {
                APPLY_DELTA_TIME_DEC(gCurrentSprite.work2);
            }
            else if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
            {
                // Touched ground
                gCurrentSprite.work0 = CONVERT_SECONDS(1.f);
                gCurrentSprite.pose = IMAGO_DAMAGED_STINGER_POSE_DISAPPEARING;
                ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
            }
            break;

        case IMAGO_DAMAGED_STINGER_POSE_DISAPPEARING:
            if (APPLY_DELTA_TIME_DEC(gCurrentSprite.work0) == 0)
            {
                ParticleSet(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                gCurrentSprite.status = 0;
                SoundPlay(SOUND_IMAGO_DAMAGED_STINGER_EXPLODING);
            }
            else if (gCurrentSprite.work0 <= TWO_THIRD_SECOND && MOD_AND(gCurrentSprite.work0, 4) == 0)
            {
                // Make blink
                if (MOD_BLOCK_AND(gCurrentSprite.work0, 4))
                    gCurrentSprite.paletteRow = SPRITE_GET_STUN_PALETTE(gCurrentSprite);
                else
                    gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
            }
            break;
    }
}

/**
 * @brief 43c58 | 130 | Imago egg AI
 * 
 */
void ImagoEgg(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE + PIXEL_SIZE);
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE - PIXEL_SIZE);
            gCurrentSprite.hitboxRight = (HALF_BLOCK_SIZE - PIXEL_SIZE);

            gCurrentSprite.health = 1;
            gCurrentSprite.pOam = sImagoEggOam_Standing;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.samusCollision = SSC_SOLID_CHECK_COLLIDING;
            gCurrentSprite.pose = IMAGO_EGG_POSE_IDLE;
            break;

        case IMAGO_EGG_POSE_IDLE:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            {
                gCurrentSprite.pOam = sImagoEggOam_Breaking;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                gCurrentSprite.pose = IMAGO_EGG_POSE_BREAKING;
                gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                gCurrentSprite.health = 0;

                SoundPlay(SOUND_IMAGO_EGG_BREAKING);
                // Set last egg broken flag
                if (gCurrentSprite.roomSlot == IMAGO_EGG_PART_LAST)
                    gSubSpriteData1.work3 = TRUE;
            }
            break;

        case IMAGO_EGG_POSE_BREAKING:
            if (gCurrentSprite.currentAnimationFrame > 2)
            {
                gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
                gCurrentSprite.samusCollision = SSC_NONE;
                gCurrentSprite.pose = IMAGO_EGG_POSE_DISAPPEARING;
                gCurrentSprite.work0 = CONVERT_SECONDS(3.f);
            }
            break;

        case IMAGO_EGG_POSE_DISAPPEARING:
            if (gCurrentSprite.work0 < CONVERT_SECONDS(1.f))
                gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (gCurrentSprite.work0 == 0)
                gCurrentSprite.status = 0;
            break;

        default:
            // Set last egg broken flag
            if (gCurrentSprite.roomSlot == IMAGO_EGG_PART_LAST)
                gSubSpriteData1.work3 = TRUE;
            
            SpriteUtilSpriteDeath(DEATH_NO_DEATH_OR_RESPAWNING_ALREADY_HAS_DROP,
                gCurrentSprite.yPosition - (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE),
                gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
            gCurrentSprite.status = 0;
    }
}
