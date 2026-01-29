#include "sprites_ai/gunship.h"
#include "gba.h"
#include "sprites_ai/message_banner.h"

#include "data/sprites/gunship.h"

#include "constants/audio.h"
#include "constants/color_fading.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/event.h"
#include "constants/samus.h"
#include "constants/text.h"

#include "structs/connection.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/hud.h"
#include "structs/sprite.h"
#include "structs/samus.h"

#define GUNSHIP_POSE_IDLE 0x9
#define GUNSHIP_POSE_CHECK_ESCAPE 0xF
#define GUNSHIP_POSE_SAMUS_ENTERING_WHEN_ESCAPING 0x11
#define GUNSHIP_POSE_START_ESCAPING 0x13
#define GUNSHIP_POSE_TAKING_OFF 0x15
#define GUNSHIP_POSE_FLYING 0x17
#define GUNSHIP_POSE_DO_NOTHING_ESCAPE 0x19
#define GUNSHIP_POSE_SAMUS_ENTERING 0x22
#define GUNSHIP_POSE_REFILL 0x23
#define GUNSHIP_POSE_AFTER_REFILL 0x24
#define GUNSHIP_POSE_SAMUS_LEAVE 0x25
#define GUNSHIP_POSE_SAMUS_LEAVING 0x27
#define GUNSHIP_POSE_RELEASE_SAMUS 0x28
#define GUNSHIP_POSE_SAMUS_RELEASED 0x29
#define GUNSHIP_POSE_CHECK_SAMUS_ON_TOP_AFTER_RELEASED 0x2A
#define GUNSHIP_POSE_SAVING 0x42
#define GUNSHIP_POSE_AFTER_SAVE 0x43
#define GUNSHIP_POSE_LANDING 0x55
#define GUNSHIP_POSE_UNKNOWN 0x57
#define GUNSHIP_POSE_DO_NOTHING 0x59

// Gunship part

MAKE_ENUM(u8, GunshipPartId) {
    GUNSHIP_PART_MAIN,
    GUNSHIP_PART_ENTRANCE_FRONT,
    GUNSHIP_PART_ENTRANCE_BACK,
    GUNSHIP_PART_PLATFORM,
    GUNSHIP_PART_FLAMES_HORIZONTAL,
    GUNSHIP_PART_FLAMES_VERTICAL
};

#define GUNSHIP_PART_POSE_ENTRANCE_FRONT_IDLE 0x8
#define GUNSHIP_PART_POSE_ENTRANCE_FRONT_OPENING_CLOSING 0x9
#define GUNSHIP_PART_POSE_ENTRANCE_BACK_IDLE 0xE
#define GUNSHIP_PART_POSE_ENTRANCE_BACK_OPENING_CLOSING 0xF
#define GUNSHIP_PART_POSE_CHECK_SET_VERTICAL_FLAMES 0x32
#define GUNSHIP_PART_POSE_VERTICAL_FLAME_IDLE 0x33
#define GUNSHIP_PART_POSE_CHECK_SET_HORIZONTAL_FLAMES 0x34
#define GUNSHIP_PART_POSE_CHECK_SET_VERTICAL_FLAMES_BEFORE_LANDING 0x35
#define GUNSHIP_PART_POSE_CHECK_SET_HORIZONTAL_FLAMES_BEFORE_LANDING 0x36
#define GUNSHIP_PART_POSE_FLICKER_FLAMES_UNUSED 0x37
#define GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_UP 0x42
#define GUNSHIP_PART_POSE_PLATFORM_GO_UP 0x43
#define GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_DOWN 0x44
#define GUNSHIP_PART_POSE_PLATFORM_GO_DOWN 0x45

#define GUNSHIP_START_FLYING(flyDuration)       \
do {                                            \
    gCurrentSprite.pose = GUNSHIP_POSE_FLYING;  \
    gCurrentSprite.work0 = flyDuration;         \
    gCurrentSprite.work3 = 0;                   \
} while (0)

/**
 * @brief 44c24 | 84 | Updates the flames palette
 * 
 */
static void GunshipFlickerFlames(void)
{
    u32 timer;
    u8 row;
    u8 offset;
    
    if (!(gCurrentSprite.status & SPRITE_STATUS_MOSAIC) && gCurrentSprite.work2 == CONVERT_SECONDS(1.f / 15))
    {
        row = gCurrentSprite.scaling;

        // Update palette row
        if (row & 0x80)
        {
            if (row > 0x80)
                gCurrentSprite.scaling--;

            if (gCurrentSprite.scaling == 0x80)
                gCurrentSprite.scaling = 0;
        }
        else
        {
            if (row < 2)
                gCurrentSprite.scaling++;

            if (gCurrentSprite.scaling == 2)
                gCurrentSprite.scaling |= 0x80;
        }

        // Transfer palette
        offset = MOD_AND(gCurrentSprite.scaling, 128);
        DMA3_COPY_16(&sGunshipFlashingPal[offset * PAL_ROW], PALRAM_OBJ + 10 * PAL_ROW_SIZE, PAL_ROW);
    }
}

/**
 * @brief 44ca8 | b0 | Updates the entrance palette
 * 
 */
static void GunshipEntranceFlashingAnim(void)
{
    u8 flag;
    u8 row;
    u8 offset;

    if (!(gCurrentSprite.status & SPRITE_STATUS_MOSAIC) && APPLY_DELTA_TIME_DEC(gCurrentSprite.work2) == 0)
    {
        if (gCurrentSprite.pOam == sGunshipOam_Refilling)
            gCurrentSprite.work2 = CONVERT_SECONDS(1.f / 30);
        else if (gCurrentSprite.pOam == sGunshipOam_Flying)
            gCurrentSprite.work2 = CONVERT_SECONDS(1.f / 15);
        else
            gCurrentSprite.work2 = CONVERT_SECONDS(2.f / 15);

        row = gCurrentSprite.work1;

        // Update palette row
        if (row & 0x80)
        {
            if (gCurrentSprite.work1 > 0x80)
                gCurrentSprite.work1--;

            if (gCurrentSprite.work1 == 0x80)
                gCurrentSprite.work1 = 0;
        }
        else
        {
            if (gCurrentSprite.work1 < 4)
                gCurrentSprite.work1++;

            if (gCurrentSprite.work1 == 4)
                gCurrentSprite.work1 |= 0x80;
        }

        // Transfer palette
        offset = MOD_AND(gCurrentSprite.work1, 128);
        DMA3_COPY_16(&sGunshipFlashingPal[0x38 + offset * PAL_ROW], // Not sure
            PALRAM_OBJ + 9 * PAL_ROW_SIZE + PAL_ROW_SIZE / 2, PAL_ROW / 2);
    }
}

/**
 * @brief 44d58 | 64 | Checks if samus is entering the gunship
 * 
 * @return u8 1 if entering, 0 otherwise
 */
static u8 GunshipCheckSamusEnter(void)
{
    u16 samusX;
    
    if (!SpriteUtilCheckCrouchingOrMorphed())
    {
        samusX = gSamusData.xPosition;
        if (gCurrentSprite.xPosition - THREE_QUARTER_BLOCK_SIZE < samusX && gCurrentSprite.xPosition + THREE_QUARTER_BLOCK_SIZE > samusX)
        {
            SamusSetPose(SPOSE_TURNING_FROM_FACING_THE_FOREGROUND);
            gSamusData.timer = 1 * DELTA_TIME;
            gSamusData.standingStatus = STANDING_ENEMY;
            gSamusData.xPosition = gCurrentSprite.xPosition;

            gCurrentSprite.work0 = CONVERT_SECONDS(.9f + 1.f / 30);
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;
            gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_ON_TOP;
            return TRUE;
        }
    }
    
    return FALSE;
}

/**
 * @brief 44dbc | 1e0 | Initializes a gunship sprite
 * 
 */
static void GunshipInit(void)
{
    u8 introCutscene;

    introCutscene = FALSE;

    // Check if landing
    if (gLastDoorUsed == 0)
    {
        introCutscene = TRUE;
        gCurrentSprite.yPosition -= BLOCK_SIZE * 6;
        SoundPlay(SOUND_GUNSHIP_LANDING);
    }

    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;

    gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 3 + PIXEL_SIZE);
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = -BLOCK_SIZE;
    gCurrentSprite.hitboxRight = BLOCK_SIZE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 7 + HALF_BLOCK_SIZE) + 0;

    gCurrentSprite.pOam = sGunshipOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.work2 = CONVERT_SECONDS(2.f / 15);
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work0 = 0;
    gCurrentSprite.work3 = 0;

    gSubSpriteData1.work3 = FALSE;

    // Spawn entrance
    SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_FRONT, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_BACK, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

    if (gSamusData.pose == SPOSE_SAVING_LOADING_GAME)
    {
        // Loading game from gunship
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_LEAVE;
        gCurrentSprite.work0 = CONVERT_SECONDS(.5f);

        gSamusData.timer = 0;
        gSamusData.lastWallTouchedMidAir = TRUE;
        gCurrentSprite.yPositionSpawn = 5 * BLOCK_SIZE + QUARTER_BLOCK_SIZE + PIXEL_SIZE;
        gSubSpriteData1.work3 = TRUE;

        SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_PLATFORM, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    }
    else if (introCutscene)
    {
        // Landing
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = GUNSHIP_POSE_LANDING;
        gCurrentSprite.work0 = CONVERT_SECONDS(3.2f);

        SamusSetPose(SPOSE_SAVING_LOADING_GAME);
        gSamusData.timer = 1 * DELTA_TIME;
        gSamusData.lastWallTouchedMidAir = TRUE;

        SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_FLAMES_VERTICAL, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

        UpdateMusicPriority(0);
        gHideHud = TRUE;
    }
    else
    {
        // Idle
        SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_PLATFORM, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - BLOCK_SIZE * 3 + HALF_BLOCK_SIZE, gCurrentSprite.xPosition, 0);
        
        gCurrentSprite.yPositionSpawn = 0;
        gCurrentSprite.samusCollision = SSC_CAN_STAND_ON_TOP;

        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
            gCurrentSprite.pose = GUNSHIP_POSE_CHECK_ESCAPE;
        else
            gCurrentSprite.pose = GUNSHIP_POSE_IDLE;

        gCurrentSprite.drawOrder = 12;
    }
}

/**
 * @brief 44f9c | 48 | Handles the gunship landing during the intro
 * 
 */
static void GunshipLanding(void)
{
    if (gCurrentSprite.work0 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        gCurrentSprite.yPosition += PIXEL_SIZE / 2;
        gSamusData.yPosition = gCurrentSprite.yPosition - PIXEL_SIZE;
        gSamusData.xPosition = gCurrentSprite.xPosition;

        if (gCurrentSprite.work0 == CONVERT_SECONDS(.5f))
        {
            // Start intro
            StartEffectForCutscene(EFFECT_CUTSCENE_INTRO_TEXT);
            gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
        }
    }
}

/**
 * @brief 44fe4 | 40 | Handles the gunship being idle
 * 
 */
static void GunshipIdle(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP)
    {
        // Check samus entering
        gCurrentSprite.drawOrder = 4;
        if (GunshipCheckSamusEnter())
            gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_ENTERING;
    }
    else
    {
        gCurrentSprite.drawOrder = 12;
    }
}

/**
 * @brief 45024 | cc | Handles Samus entering the gunship
 * 
 */
static void GunshipSamusEntering(void)
{
    u8 ramSlot;

    if (APPLY_DELTA_TIME_DEC(gCurrentSprite.work0) == 0)
    {
        gCurrentSprite.pose = GUNSHIP_POSE_REFILL;
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f + 1.f / 12);

        // Check close entrance
        ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_FRONT);
        if (ramSlot != UCHAR_MAX)
        {
            gSpriteData[ramSlot].pOam = sGunshipPartOam_EntranceFrontClosing;
            gSpriteData[ramSlot].animationDurationCounter = 0;
            gSpriteData[ramSlot].currentAnimationFrame = 0;
            gSpriteData[ramSlot].pose = GUNSHIP_PART_POSE_ENTRANCE_FRONT_OPENING_CLOSING;

            ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_BACK);
            if (ramSlot != UCHAR_MAX)
            {
                gSpriteData[ramSlot].pOam = sGunshipPartOam_EntranceBackClosing;
                gSpriteData[ramSlot].animationDurationCounter = 0;
                gSpriteData[ramSlot].currentAnimationFrame = 0;
                gSpriteData[ramSlot].pose = GUNSHIP_PART_POSE_ENTRANCE_BACK_OPENING_CLOSING;

                SoundPlay(SOUND_GUNSHIP_CLOSING);
                SoundFade(SOUND_GUNSHIP_PLATFORM_MOVING, CONVERT_SECONDS(1.f / 6)); 
            }
        }
    }
    else if (gCurrentSprite.work0 < TWO_THIRD_SECOND + CONVERT_SECONDS(1.f / 15))
    {
        // Move samus
        gSamusData.yPosition += PIXEL_SIZE;
    }
    else if (gCurrentSprite.work0 == TWO_THIRD_SECOND + CONVERT_SECONDS(1.f / 15))
    {
        SoundPlay(SOUND_GUNSHIP_PLATFORM_MOVING); 
    }
}

/**
 * @brief 450f0 | 15c | Handles the gunship refilling Samus
 * 
 */
static void GunshipRefill(void)
{
    if (gCurrentSprite.work0 > CONVERT_SECONDS(.1f))
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == CONVERT_SECONDS(.1f))
        {
            gCurrentSprite.pOam = sGunshipOam_Refilling;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            SoundPlay(SOUND_GUNSHIP_REFILL);
        }
    }
    else if (gCurrentSprite.work0 == 5)
    {
        // Refill energy
        if (!SpriteUtilRefillEnergy())
        {
            gCurrentSprite.work0--;
            gEnergyRefillAnimation = 13;
        }
    }
    else if (gCurrentSprite.work0 == 4)
    {
        // Refill missiles
        if (gEnergyRefillAnimation != 0)
        {
            gEnergyRefillAnimation--;
        }
        else if (!SpriteUtilRefillMissiles())
        {
            gCurrentSprite.work0--;

            if (gEquipment.maxMissiles != 0)
                gMissileRefillAnimation = 13;
        }
    }
    else if (gCurrentSprite.work0 == 3)
    {
        // Refill super missiles
        if (gMissileRefillAnimation != 0)
        {
            gMissileRefillAnimation--;
        }
        else if (!SpriteUtilRefillSuperMissiles())
        {
            gCurrentSprite.work0--;

            if (gEquipment.maxSuperMissiles != 0)
                gSuperMissileRefillAnimation = 13;
        }
    }
    else if (gCurrentSprite.work0 == 2)
    {
        // Refill power bombs
        if (gSuperMissileRefillAnimation != 0)
        {
            gSuperMissileRefillAnimation--;
        }
        else if (!SpriteUtilRefillPowerBombs())
        {
            gCurrentSprite.work0--;
    
            if (gEquipment.maxPowerBombs != 0)
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
    }
    else
    {
        // Spawn message banner
        gCurrentSprite.pose = GUNSHIP_POSE_AFTER_REFILL;
        gCurrentSprite.work0 = CONVERT_SECONDS(.5f);

        gCurrentSprite.rotation = SpriteSpawnPrimary(PSPRITE_MESSAGE_BANNER, MESSAGE_WEAPONS_AND_ENERGY_RESTORED,
            SPRITE_GFX_SLOT_SPECIAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
        SoundFade(SOUND_GUNSHIP_REFILL, CONVERT_SECONDS(.25f));
    }
}

/**
 * @brief 4524c | 90 | Handles the behavior of the gunship after a refill
 * 
 */
static void GunshipAfterRefill(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.rotation;
    if (gSpriteData[ramSlot].pose == MESSAGE_BANNER_POSE_REMOVAL_ANIMATION)
    {
        if (gCurrentSprite.work0 != 0)
        {
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (gCurrentSprite.work0 == 0)
            {
                // Spawn save prompt
                gCurrentSprite.rotation = SpriteSpawnPrimary(PSPRITE_MESSAGE_BANNER, MESSAGE_SAVE_PROMPT,
                    SPRITE_GFX_SLOT_SPECIAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            }
        }
        else
        {
            // Check is save prompt
            if (gSpriteData[ramSlot].work1 == TRUE)
            {
                // Saving
                gCurrentSprite.pose = GUNSHIP_POSE_SAVING;
                gCurrentSprite.work0 = CONVERT_SECONDS(.5f);
                SoundPlay(SOUND_GUNSHIP_SAVING);
            }
            else
            {
                // Not saving
                gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_LEAVE;
                gCurrentSprite.work0 = CONVERT_SECONDS(.5f);
            }
        }
    }
}

/**
 * @brief 452dc | 44 | Handles the gunship saving
 * 
 */
static void GunshipSaving(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);

    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = GUNSHIP_POSE_AFTER_SAVE;
        gCurrentSprite.rotation = SpriteSpawnPrimary(PSPRITE_MESSAGE_BANNER, MESSAGE_SAVE_COMPLETE,
            SPRITE_GFX_SLOT_SPECIAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    }
}

/**
 * @brief 45320 | 38 | Handles the behavior of the gunship after saving
 * 
 */
static void GunshipAfterSave(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.rotation;
    if (gSpriteData[ramSlot].pose == MESSAGE_BANNER_POSE_REMOVAL_ANIMATION)
    {
        // Eject samus
        gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_LEAVE;
        gCurrentSprite.work0 = CONVERT_SECONDS(.5f);
    }
}

/**
 * @brief 45358 | b8 | Handles the gunship starting to eject samus
 * 
 */
static void GunshipSamusLeave(void)
{
    u8 ramSlot;

    if (APPLY_DELTA_TIME_DEC(gCurrentSprite.work0) == 0)
    {
        gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_LEAVING;
        gCurrentSprite.work0 = TWO_THIRD_SECOND + CONVERT_SECONDS(1.f / 15);
        SoundPlay(SOUND_GUNSHIP_PLATFORM_MOVING);
    }
    else if (gCurrentSprite.work0 == CONVERT_SECONDS(1.f / 6))
    {
        // Check open entrance
        ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_FRONT);
        if (ramSlot != UCHAR_MAX)
        {
            gSpriteData[ramSlot].pOam = sGunshipPartOam_EntranceFrontOpening;
            gSpriteData[ramSlot].animationDurationCounter = 0;
            gSpriteData[ramSlot].currentAnimationFrame = 0;

            ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_BACK);
            if (ramSlot != UCHAR_MAX)
            {
                gSpriteData[ramSlot].pOam = sGunshipPartOam_EntranceBackOpening;
                gSpriteData[ramSlot].animationDurationCounter = 0;
                gSpriteData[ramSlot].currentAnimationFrame = 0;

                gCurrentSprite.pOam = sGunshipOam_Idle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                SoundPlay(SOUND_GUNSHIP_OPENING);
            }
        }
    }
}

/**
 * @brief 45410 | 28 | Handles samus leaving the gunship
 * 
 */
static void GunshipSamusLeaving(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        if (gHideHud)
        {
            gCurrentSprite.pose = GUNSHIP_POSE_DO_NOTHING;
            gCurrentSprite.work0 = CONVERT_SECONDS(5.f / 6);
        }
        else
        {
            gCurrentSprite.pose = GUNSHIP_POSE_RELEASE_SAMUS;
        }

        SoundFade(SOUND_GUNSHIP_PLATFORM_MOVING, CONVERT_SECONDS(1.f / 6));
    }
    else
    {
        gSamusData.yPosition -= PIXEL_SIZE;
    }
}

/**
 * @brief 45468 | 24 | Handles the gunship releasing samus
 * 
 */
static void GunshipReleaseSamus(void)
{
    if (gCurrentSprite.yPositionSpawn == 0)
    {
        SamusSetPose(SPOSE_FACING_THE_FOREGROUND);
        gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_RELEASED;
    }
}

/**
 * @brief 4548c | 28 | Called after samus is released
 * 
 */
static void GunshipSamusReleased(void)
{
    if (gSamusData.pose != SPOSE_FACING_THE_FOREGROUND)
    {
        gCurrentSprite.pose = GUNSHIP_POSE_CHECK_SAMUS_ON_TOP_AFTER_RELEASED;
        gCurrentSprite.samusCollision = SSC_CAN_STAND_ON_TOP;
    }
}

/**
 * @brief 454b4 | 28 | Checks if samus is still on the gunship after being released
 * 
 */
static void GunshipCheckSamusOnTopAfterLeaving(void)
{
    if (!(gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP))
    {
        gCurrentSprite.drawOrder = 12;
        gCurrentSprite.pose = GUNSHIP_POSE_IDLE;
    }
}

/**
 * @brief 454dc | 50 | Checks if samus should escape
 * 
 */
static void GunshipCheckEscapeZebes(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP && GunshipCheckSamusEnter())
    {
        // Samus entering ship

        gCurrentSprite.drawOrder = 4;
        gCurrentSprite.pose = GUNSHIP_POSE_SAMUS_ENTERING_WHEN_ESCAPING;

        // Set event and update minimap
        EventFunction(EVENT_ACTION_SETTING, EVENT_ESCAPED_ZEBES);
        MinimapUpdateChunk(EVENT_ESCAPED_ZEBES);
        SoundFade(SOUND_ESCAPE_BEEP, CONVERT_SECONDS(1.f));
        UpdateMusicPriority(0);
    }
}

/**
 * @brief 4552c | e4 | Handles samus entering the gunship when escaping
 * 
 */
static void GunshipSamusEnteringWhenEscaping(void)
{
    u8 ramSlot;

    if (APPLY_DELTA_TIME_DEC(gCurrentSprite.work0) == 0)
    {
        gCurrentSprite.pose = GUNSHIP_POSE_START_ESCAPING;
        gCurrentSprite.work0 = CONVERT_SECONDS(2.f);

        // Check close entrance
        ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_FRONT);
        if (ramSlot != UCHAR_MAX)
        {
            gSpriteData[ramSlot].pOam = sGunshipPartOam_EntranceFrontClosing;
            gSpriteData[ramSlot].animationDurationCounter = 0;
            gSpriteData[ramSlot].currentAnimationFrame = 0;
            gSpriteData[ramSlot].pose = GUNSHIP_PART_POSE_ENTRANCE_FRONT_OPENING_CLOSING;

            ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_BACK);
            if (ramSlot != UCHAR_MAX)
            {
                gSpriteData[ramSlot].pOam = sGunshipPartOam_EntranceBackClosing;
                gSpriteData[ramSlot].animationDurationCounter = 0;
                gSpriteData[ramSlot].currentAnimationFrame = 0;
                gSpriteData[ramSlot].pose = GUNSHIP_PART_POSE_ENTRANCE_BACK_OPENING_CLOSING;

                ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_PLATFORM);
                if (ramSlot != UCHAR_MAX)
                {
                    gSpriteData[ramSlot].status = 0;

                    SoundPlay(SOUND_GUNSHIP_CLOSING);
                    SoundFade(SOUND_GUNSHIP_PLATFORM_MOVING, CONVERT_SECONDS(1.f / 6));
                }
            }
        }
    }
    else if (gCurrentSprite.work0 < TWO_THIRD_SECOND + CONVERT_SECONDS(1.f / 15))
    {
        // Move samus
        gSamusData.yPosition += PIXEL_SIZE;
    }
    else if (gCurrentSprite.work0 == TWO_THIRD_SECOND + CONVERT_SECONDS(1.f / 15))
    {
        SoundPlay(SOUND_GUNSHIP_PLATFORM_MOVING); 
    }
}

/**
 * @brief 45610 | 78 | Handles the gunship starting to escape
 * 
 */
static void GunshipStartEscaping(void)
{
    if (APPLY_DELTA_TIME_DEC(gCurrentSprite.work0) == 0)
    {
        // Set taking off
        gCurrentSprite.pose = GUNSHIP_POSE_TAKING_OFF;
        gCurrentSprite.work0 = CONVERT_SECONDS(2.5f) + 2 * DELTA_TIME;
        gCurrentSprite.work3 = 0;
        gCurrentSprite.scaling = 0;

        // Spawn flames
        SpriteSpawnSecondary(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_FLAMES_HORIZONTAL, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    }
    else if (gCurrentSprite.work0 == CONVERT_SECONDS(1.f / 15))
    {
        gCurrentSprite.pOam = sGunshipOam_Flying;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        SoundPlay(SOUND_GUNSHIP_FLYING_OFF);
    }
}

/**
 * @brief 45688 | 80 | Handles the gunship taking off before flying
 * 
 */
static void GunshipTakingOff(void)
{
    u8 offset;
    s32 movement;

    GunshipFlickerFlames();

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        GUNSHIP_START_FLYING(CONVERT_SECONDS(2) + TWO_THIRD_SECOND);
    }
    else
    {
        offset = gCurrentSprite.work3;
        movement = sGunshipTakingOffYVelocity[offset];
        if (movement == SHORT_MAX)
        {
            movement = sGunshipTakingOffYVelocity[offset - 1];
            gCurrentSprite.yPosition += movement;
            gSamusData.yPosition += movement;
            
        }
        else
        {
            gCurrentSprite.work3++;
            gCurrentSprite.yPosition += movement;
            gSamusData.yPosition += movement;
        }
    }
}

/**
 * @brief 45708 | 8c | Handles the ship flying when escaping
 * 
 */
static void GunshipFlying(void)
{
    u8 offset;
    s32 movement;

    if (APPLY_DELTA_TIME_DEC(gCurrentSprite.work0) == 0)
    {
        gCurrentSprite.pose = GUNSHIP_POSE_DO_NOTHING_ESCAPE;
    }
    else
    {
        if (gCurrentSprite.work0 == CONVERT_SECONDS(5.f / 6))
        {
            StartEffectForCutscene(EFFECT_CUTSCENE_EXITING_ZEBES);
            gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
        }

        GunshipFlickerFlames();

        offset = gCurrentSprite.work3;
        movement = sGunshipFlyingYVelocity[offset];
        if (movement == SHORT_MAX)
        {
            movement = sGunshipFlyingYVelocity[offset - 1];
            gCurrentSprite.yPosition += movement;
            gSamusData.yPosition += movement;
        }
        else
        {
            gCurrentSprite.work3 = offset + 1;
            gCurrentSprite.yPosition += movement;
            gSamusData.yPosition += movement;
        }
    }
}

/**
 * @brief 45794 | 1a0 | Initializes a gunship part sprite
 * 
 */
static void GunshipPartInit(void)
{
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    gCurrentSprite.hitboxTop = 0;
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = 0;
    gCurrentSprite.hitboxRight = 0;

    switch (gCurrentSprite.roomSlot)
    {
        case GUNSHIP_PART_ENTRANCE_FRONT:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = 0;
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE + HALF_BLOCK_SIZE);
            
            gCurrentSprite.pOam = sGunshipPartOam_EntranceFrontClosed;

            if (gSamusData.pose == SPOSE_SAVING_LOADING_GAME)
                gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_FRONT_OPENING_CLOSING;
            else
                gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_FRONT_IDLE;
            break;

        case GUNSHIP_PART_ENTRANCE_BACK:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(4 * BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = 0;
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE);

            gCurrentSprite.drawOrder = 14;
            gCurrentSprite.pOam = sGunshipPartOam_EntranceBackClosed;

            if (gSamusData.pose == SPOSE_SAVING_LOADING_GAME)
                gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_BACK_OPENING_CLOSING;
            else
                gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_BACK_IDLE;
            break;

        case GUNSHIP_PART_PLATFORM:
            gCurrentSprite.drawDistanceTop = 0;
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.drawOrder = 13;
            gCurrentSprite.pOam = sGunshipPartOam_Platform;

            if (gSamusData.pose == SPOSE_SAVING_LOADING_GAME)
            {
                gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_DOWN;
                gCurrentSprite.yPosition += -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            }
            else
                gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_UP;
            break;

        case GUNSHIP_PART_FLAMES_HORIZONTAL:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(6 * BLOCK_SIZE);

            gCurrentSprite.drawOrder = 15;
            gCurrentSprite.pOam = sGunshipPartOam_FlamesHorizontal;
            gCurrentSprite.pose = GUNSHIP_PART_POSE_CHECK_SET_VERTICAL_FLAMES;
            break;

        case GUNSHIP_PART_FLAMES_VERTICAL:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(6 * BLOCK_SIZE);

            gCurrentSprite.drawOrder = 15;
            gCurrentSprite.pOam = sGunshipPartOam_FlamesVertical;
            gCurrentSprite.pose = GUNSHIP_PART_POSE_CHECK_SET_HORIZONTAL_FLAMES;
            gCurrentSprite.work0 = CONVERT_SECONDS(1.f) + ONE_THIRD_SECOND;
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 45934 | 40 | Checks if the horizontal flames should become the vertical flames
 * 
 */
static void GunshipPartCheckSetVerticalFlames(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[ramSlot].pose == GUNSHIP_POSE_FLYING)
    {
        gCurrentSprite.pOam = sGunshipPartOam_FlamesVertical;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = GUNSHIP_PART_POSE_VERTICAL_FLAME_IDLE;
    }
}

/**
 * @brief 45974 | 38 | Checks if the vertical flames should become the horizontal flames
 * 
 */
static void GunshipPartCheckSetHorizontalFlames(void)
{
    if (gCurrentSprite.work0 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.pOam = sGunshipPartOam_FlamesHorizontal;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.work0 = CONVERT_SECONDS(.25f);
            gCurrentSprite.pose = GUNSHIP_PART_POSE_CHECK_SET_VERTICAL_FLAMES_BEFORE_LANDING;
        }
    }
}

/**
 * @brief 459ac | 38 | Checks if the horizontal flames should become the vertical flames (before landing)
 * 
 */
static void GunshipPartCheckSetVerticalFlamesBeforeLanding(void)
{
    if (gCurrentSprite.work0 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.pOam = sGunshipPartOam_FlamesVertical;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);
            gCurrentSprite.pose = GUNSHIP_PART_POSE_CHECK_SET_HORIZONTAL_FLAMES_BEFORE_LANDING;
        }
    }
}

/**
 * @brief 459e4 | 5c | Checks if the vertical flames should become the horizontal flames (before landing)
 * 
 */
static void GunshipPartCheckSetHorizontalFlamesBeforeLanding(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (gCurrentSprite.work0 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.pOam = sGunshipPartOam_FlamesHorizontal;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }

    if (gSpriteData[ramSlot].pose == GUNSHIP_POSE_UNKNOWN)
    {
        gCurrentSprite.pose = GUNSHIP_PART_POSE_FLICKER_FLAMES_UNUSED;
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f);
    }
}

/**
 * @brief 45a40 | 28 | Flickers the flames, unused
 * 
 */
static void GunshipPartFlickFlames_Unused(void)
{
    gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
        gCurrentSprite.status = 0;
}

/**
 * @brief 45a68 | a8 | Handles the front part of the entrance being idle
 * 
 */
static void GunshipPartEntranceFrontIdle(void)
{
    if (gSubSpriteData1.work3 == TRUE)
    {
        if (gCurrentSprite.pOam == sGunshipPartOam_EntranceFrontClosed)
        {
            gCurrentSprite.pOam = sGunshipPartOam_EntranceFrontOpening;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
        else if (gCurrentSprite.pOam == sGunshipPartOam_EntranceFrontOpening)
        {
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.pOam = sGunshipPartOam_EntranceFrontOpened;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
        }
        else if (gCurrentSprite.pOam == sGunshipPartOam_EntranceFrontClosing)
        {
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.pOam = sGunshipPartOam_EntranceFrontOpening;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
        }
    }
    else
    {
        if (gCurrentSprite.pOam == sGunshipPartOam_EntranceFrontOpened)
        {
            gCurrentSprite.pOam = sGunshipPartOam_EntranceFrontClosing;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
        else if (gCurrentSprite.pOam == sGunshipPartOam_EntranceFrontClosing)
        {
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.pOam = sGunshipPartOam_EntranceFrontClosed;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
        }
        else if (gCurrentSprite.pOam == sGunshipPartOam_EntranceFrontOpening)
        {
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.pOam = sGunshipPartOam_EntranceFrontClosing;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }            
        }
    }
}

/**
 * @brief 45b10 | 5c | Handles the front part of the entrance opening/closing
 * 
 */
static void GunshipPartEntranceFrontOpenClose(void)
{
    if (gCurrentSprite.pOam == sGunshipPartOam_EntranceFrontClosing)
    {
        if (SpriteUtilHasCurrentAnimationEnded())
        {
            gCurrentSprite.pOam = sGunshipPartOam_EntranceFrontClosed;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
    else if (gCurrentSprite.pOam == sGunshipPartOam_EntranceFrontOpening)
    {
        if (SpriteUtilHasCurrentAnimationEnded())
        {
            gCurrentSprite.pOam = sGunshipPartOam_EntranceFrontOpened;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_FRONT_IDLE;
        }
    }
}

/**
 * @brief 45b6c | f8 | Handles the back part of the entrance being idle
 * 
 */
static void GunshipPartEntranceBackIdle(void)
{
    if (gSubSpriteData1.work3 == TRUE)
    {
        if (gCurrentSprite.pOam == sGunshipPartOam_EntranceBackClosed)
        {
            gCurrentSprite.pOam = sGunshipPartOam_EntranceBackOpening;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(SOUND_GUNSHIP_OPENING);
        }
        else if (gCurrentSprite.pOam == sGunshipPartOam_EntranceBackOpening)
        {
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.pOam = sGunshipPartOam_EntranceBackOpened;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
        }
        else if (gCurrentSprite.pOam == sGunshipPartOam_EntranceBackClosing)
        {
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.pOam = sGunshipPartOam_EntranceBackOpening;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                SoundPlay(SOUND_GUNSHIP_OPENING);
            }
        }
    }
    else
    {
        if (gCurrentSprite.pOam == sGunshipPartOam_EntranceBackOpened)
        {
            gCurrentSprite.pOam = sGunshipPartOam_EntranceBackClosing;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            SoundPlay(SOUND_GUNSHIP_CLOSING);
        }
        else if (gCurrentSprite.pOam == sGunshipPartOam_EntranceBackClosing)
        {
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.pOam = sGunshipPartOam_EntranceBackClosed;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
        }
        else if (gCurrentSprite.pOam == sGunshipPartOam_EntranceBackOpening)
        {
            if (SpriteUtilHasCurrentAnimationEnded())
            {
                gCurrentSprite.pOam = sGunshipPartOam_EntranceBackClosing;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                SoundPlay(SOUND_GUNSHIP_CLOSING);
            }
        }
    }
}

/**
 * @brief 45c64 | 5c | Handles the back part of the entrance opening/closing
 * 
 */
static void GunshipPartEntranceBackOpenClose(void)
{
    if (gCurrentSprite.pOam == sGunshipPartOam_EntranceBackClosing)
    {
        if (SpriteUtilHasCurrentAnimationEnded())
        {
            gCurrentSprite.pOam = sGunshipPartOam_EntranceBackClosed;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
    else if (gCurrentSprite.pOam == sGunshipPartOam_EntranceBackOpening)
    {
        if (SpriteUtilHasCurrentAnimationEnded())
        {
            gCurrentSprite.pOam = sGunshipPartOam_EntranceBackOpened;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.pose = GUNSHIP_PART_POSE_ENTRANCE_BACK_IDLE;
        }
    }
}

/**
 * @brief 45cc0 | 54 | Checks if the platform should go up
 * 
 */
static void GunshipPartCheckPlatformGoUp(void)
{
    u8 ramSlot;

    ramSlot = SpriteUtilFindSecondaryWithRoomSlot(SSPRITE_GUNSHIP_PART, GUNSHIP_PART_ENTRANCE_BACK);
    if (ramSlot != UCHAR_MAX && gSubSpriteData1.work3 == TRUE && gSpriteData[ramSlot].pOam == sGunshipPartOam_EntranceBackOpening)
    {
        gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_GO_UP;
        gCurrentSprite.work0 = CONVERT_SECONDS(2.f / 15);
    }
}

/**
 * @brief 45d14 | 50 | Handles the platform moving up
 * 
 */
static void GunshipPartPlatformGoUp(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (gCurrentSprite.work0 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        return;
    }

    if (gSpriteData[ramSlot].yPosition - (BLOCK_SIZE * 3 + PIXEL_SIZE) > gCurrentSprite.yPosition)
    {
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - (BLOCK_SIZE * 3 + PIXEL_SIZE);
        gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_DOWN;
    }
    else
    {
        gCurrentSprite.yPosition -= PIXEL_SIZE;
    }
}

/**
 * @brief 45d64 | 98 | Checks if the platform should go down
 * 
 */
static void GunshipPartCheckPlatformGoDown(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (!gSubSpriteData1.work3)
    {
        gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_GO_DOWN;
        gCurrentSprite.work0 = CONVERT_SECONDS(2.f / 15);
    }
    else if (gSpriteData[ramSlot].pose == GUNSHIP_POSE_SAMUS_ENTERING &&
        gSpriteData[ramSlot].work0 < TWO_THIRD_SECOND + CONVERT_SECONDS(1.f / 15))
    {
        gCurrentSprite.yPosition += PIXEL_SIZE;
    }
    else if (gSpriteData[ramSlot].pose == GUNSHIP_POSE_SAMUS_LEAVING &&
        gSpriteData[ramSlot].work0 < TWO_THIRD_SECOND + CONVERT_SECONDS(1.f / 15))
    {
        gCurrentSprite.yPosition -= PIXEL_SIZE;
    }
    else if (gSpriteData[ramSlot].pose == GUNSHIP_POSE_SAMUS_ENTERING_WHEN_ESCAPING &&
        gSpriteData[ramSlot].work0 < TWO_THIRD_SECOND + CONVERT_SECONDS(1.f / 15))
    {
        gCurrentSprite.yPosition += PIXEL_SIZE;
    }
}

/**
 * @brief 45dfc | 50 | Handles the platform moving down 
 * 
 */
static void GunshipPartPlatformGoDown(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (gCurrentSprite.work0 != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        return;
    }

    if (gSpriteData[ramSlot].yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE) < gCurrentSprite.yPosition)
    {
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition -  (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
        gCurrentSprite.pose = GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_UP;
    }
    else
    {
        gCurrentSprite.yPosition += PIXEL_SIZE;
    }
}

/**
 * @brief 45e4c | 24c | Gunship AI
 * 
 */
void Gunship(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            GunshipInit();
            break;

        case GUNSHIP_POSE_IDLE:
            GunshipIdle();
            break;

        case GUNSHIP_POSE_SAMUS_ENTERING:
            GunshipSamusEntering();
            break;

        case GUNSHIP_POSE_REFILL:
            GunshipRefill();
            break;

        case GUNSHIP_POSE_AFTER_REFILL:
            GunshipAfterRefill();
            break;

        case GUNSHIP_POSE_SAMUS_LEAVE:
            GunshipSamusLeave();
            break;

        case GUNSHIP_POSE_SAMUS_LEAVING:
            GunshipSamusLeaving();
            break;

        case GUNSHIP_POSE_RELEASE_SAMUS:
            GunshipReleaseSamus();
            break;

        case GUNSHIP_POSE_SAMUS_RELEASED:
            GunshipSamusReleased();
            break;

        case GUNSHIP_POSE_CHECK_SAMUS_ON_TOP_AFTER_RELEASED:
            GunshipCheckSamusOnTopAfterLeaving();
            break;

        case GUNSHIP_POSE_SAVING:
            GunshipSaving();
            break;

        case GUNSHIP_POSE_AFTER_SAVE:
            GunshipAfterSave();
            break;

        case GUNSHIP_POSE_CHECK_ESCAPE:
            GunshipCheckEscapeZebes();
            break;

        case GUNSHIP_POSE_SAMUS_ENTERING_WHEN_ESCAPING:
            GunshipSamusEnteringWhenEscaping();
            break;

        case GUNSHIP_POSE_START_ESCAPING:
            GunshipStartEscaping();
            break;

        case GUNSHIP_POSE_TAKING_OFF:
            GunshipTakingOff();
            break;

        case GUNSHIP_POSE_FLYING:
            GunshipFlying();
            break;

        case GUNSHIP_POSE_LANDING:
            GunshipLanding();
            break;
    }

    // Check set samus near flag
    if (!gSubSpriteData1.work3)
    {
        // Check set
        if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 20, BLOCK_SIZE * 7) != NSLR_OUT_OF_RANGE)
            gSubSpriteData1.work3 = TRUE;
    }
    else
    {
        // Check remove
        if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 20, BLOCK_SIZE * 9) == NSLR_OUT_OF_RANGE)
            gSubSpriteData1.work3 = FALSE;
    }

    GunshipEntranceFlashingAnim();

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ESCAPED_ZEBES) && gCurrentSprite.yPositionSpawn != 0)
    {
        gCurrentSprite.yPositionSpawn--;
        if (gCurrentSprite.yPositionSpawn == 0)
            gDisablePause = FALSE;
    }
}

/**
 * @brief 46098 | 1e4 | Gunship part AI
 * 
 */
void GunshipPart(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (gCurrentSprite.roomSlot == GUNSHIP_PART_ENTRANCE_FRONT)
    {
        if (gSpriteData[ramSlot].drawOrder == 4)
            gCurrentSprite.drawOrder = 3;
        else
            gCurrentSprite.drawOrder = 11;
    }

    if (gCurrentSprite.roomSlot != GUNSHIP_PART_PLATFORM)
    {
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
        gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            GunshipPartInit();
            break;

        case GUNSHIP_PART_POSE_ENTRANCE_FRONT_IDLE:
            GunshipPartEntranceFrontIdle();
            break;

        case GUNSHIP_PART_POSE_ENTRANCE_FRONT_OPENING_CLOSING:
            GunshipPartEntranceFrontOpenClose();
            break;

        case GUNSHIP_PART_POSE_ENTRANCE_BACK_IDLE:
            GunshipPartEntranceBackIdle();
            break;

        case GUNSHIP_PART_POSE_ENTRANCE_BACK_OPENING_CLOSING:
            GunshipPartEntranceBackOpenClose();
            break;

        case GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_UP:
            GunshipPartCheckPlatformGoUp();
            break;

        case GUNSHIP_PART_POSE_PLATFORM_GO_UP:
            GunshipPartPlatformGoUp();
            break;

        case GUNSHIP_PART_POSE_PLATFORM_CHECK_GO_DOWN:
            GunshipPartCheckPlatformGoDown();
            break;

        case GUNSHIP_PART_POSE_PLATFORM_GO_DOWN:
            GunshipPartPlatformGoDown();
            break;

        case GUNSHIP_PART_POSE_CHECK_SET_VERTICAL_FLAMES:
            GunshipPartCheckSetVerticalFlames();
            break;

        case GUNSHIP_PART_POSE_CHECK_SET_HORIZONTAL_FLAMES:
            GunshipPartCheckSetHorizontalFlames();
            break;

        case GUNSHIP_PART_POSE_CHECK_SET_VERTICAL_FLAMES_BEFORE_LANDING:
            GunshipPartCheckSetVerticalFlamesBeforeLanding();
            break;

        case GUNSHIP_PART_POSE_CHECK_SET_HORIZONTAL_FLAMES_BEFORE_LANDING:
            GunshipPartCheckSetHorizontalFlamesBeforeLanding();
            break;

        case GUNSHIP_PART_POSE_FLICKER_FLAMES_UNUSED:
            GunshipPartFlickFlames_Unused();
            break;
    }
}