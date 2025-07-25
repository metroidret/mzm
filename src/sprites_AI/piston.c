#include "sprites_AI/piston.h"
#include "macros.h"
#include "gba/display.h"

#include "data/sprites/piston.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/sprite.h"

#include "structs/display.h"
#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/clipdata.h"

#define PISTON_POSE_IDLE_INIT 0x8
#define PISTON_POSE_CHECK_FOR_PROJECTILES 0x9
#define PISTON_POSE_OPENING 0x23
#define PISTON_POSE_OPENED 0x25

/**
 * @brief 31708 | 54 | Updates the clipdata of the 4 piston blocks
 * 
 * @param caa Clipdata affecting action
 */
static void PistonChangeBodyClipdata(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 1 + HALF_BLOCK_SIZE), xPosition);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), xPosition);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), xPosition);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 4 + HALF_BLOCK_SIZE), xPosition);
}

/**
 * @brief 3175c | 20 | Updates the clipdata of the bottom block of the piston
 * 
 * @param caa Clipdata affecting action
 */
static void PistonChangeOneBelowClipdata(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - HALF_BLOCK_SIZE, xPosition);
}

/**
 * @brief 3177c | 28 | Updates the clipdata of the top block of the piston
 * 
 * @param caa Clipdata affecting action
 */
static void PistonChangeOneUpperClipdata(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 5 + HALF_BLOCK_SIZE), xPosition);
}

/**
 * @brief 317a4 | 40 | Checks if samus is colliding with the piston
 * 
 * @return u8 bool, colliding
 */
static u8 PistonSamusCollision(void)
{
    // Not 100% what this function is supposed to do, my best guess is that it was supposed
    // to check if samus is in the pison when retracting, but pistons can't retract in the final game

    u8 result;
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;

    result = FALSE;
    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;

    if (spriteY - (BLOCK_SIZE - QUARTER_BLOCK_SIZE) < samusY && spriteY + (BLOCK_SIZE - QUARTER_BLOCK_SIZE) > samusY
        && spriteX - (BLOCK_SIZE - QUARTER_BLOCK_SIZE) < samusX && spriteX + (BLOCK_SIZE - QUARTER_BLOCK_SIZE) > samusX)
    {
        result = TRUE;
    }

    return result;
}

/**
 * @brief 317e4 | 4c | Checks if samus is colliding with the piston upper part when it goes up
 * 
 * @return u8 bool, samus in
 */
static u8 PistonCheckSamusIn(void)
{
    u8 result;
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;

    result = FALSE;
    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;
    spriteY = gCurrentSprite.yPosition - BLOCK_SIZE * 5; // Offset to the top of the piston
    spriteX = gCurrentSprite.xPosition;

    if (spriteY - (BLOCK_SIZE - QUARTER_BLOCK_SIZE) < samusY && spriteY + (BLOCK_SIZE - QUARTER_BLOCK_SIZE) > samusY
        && spriteX - (BLOCK_SIZE - QUARTER_BLOCK_SIZE) < samusX && spriteX + (BLOCK_SIZE - QUARTER_BLOCK_SIZE) > samusX)
    {
        result = TRUE;
    }

    return result;
}

/**
 * @brief 31830 | 60 | Initializes a piston sprite
 * 
 */
static void PistonInit(void)
{
    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 6 + QUARTER_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxLeft = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.health = 256;
    gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
    gCurrentSprite.bgPriority = BGCNT_GET_PRIORITY(gIoRegistersBackup.BG1CNT);

    // Set hitbox
    PistonChangeBodyClipdata(CAA_MAKE_NON_POWER_GRIP);
}

/**
 * @brief 31890 | 2c | Initializes a piston to be idle
 * 
 */
static void PistonIdleInit(void)
{
    gCurrentSprite.pOam = sPistonOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = PISTON_POSE_CHECK_FOR_PROJECTILES;

    gCurrentSprite.hitboxTop = -(BLOCK_SIZE + THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE);
    gCurrentSprite.hitboxBottom = -(BLOCK_SIZE + HALF_BLOCK_SIZE + PIXEL_SIZE * 3);
}

/**
 * @brief 318bc | 88 | Detects if a projectile is hitting the pistol
 * 
 */
static void PistonCheckProjectile(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        if (SPRITE_GET_ISFT(gCurrentSprite) == CONVERT_SECONDS(.25f + 1.f / 60))
        {
            // Projectile detected
            SPRITE_CLEAR_ISFT(gCurrentSprite);
            gCurrentSprite.health = 256;

            gCurrentSprite.pOam = sPistonOam_Opening;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = PISTON_POSE_OPENING;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            SoundPlay(SOUND_PISTON_EXTENDING);
        }
    }
    else if (!PistonSamusCollision())
    {
        PistonChangeOneBelowClipdata(CAA_MAKE_NON_POWER_GRIP);
        gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    }
}

/**
 * @brief 31944 | 58 | Handles the piston opening
 * 
 */
static void PistonOpen(void)
{
    if (gCurrentSprite.currentAnimationFrame == 2 && gCurrentSprite.animationDurationCounter == 1)
    {
        // Remove collision of the bottom part
        PistonChangeOneBelowClipdata(CAA_REMOVE_SOLID);
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
    }

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        // Opening animation done, set opened behavior
        gCurrentSprite.pOam = sPistonOam_Opened;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = PISTON_POSE_OPENED;
        gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + THREE_QUARTER_BLOCK_SIZE + PIXEL_SIZE);
        gCurrentSprite.hitboxBottom = -(BLOCK_SIZE * 2 + THREE_QUARTER_BLOCK_SIZE - PIXEL_SIZE);
    }
}

/**
 * @brief 3199c | 34 | Handles the piston being opened
 * 
 */
static void PistonOpened(void)
{
    // Check should set the top solid (not already solid and samus not in the block)
    if (!(gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING) && !PistonCheckSamusIn())
    {
        // Set collision of top part
        PistonChangeOneUpperClipdata(CAA_MAKE_NON_POWER_GRIP);

        // Set flag to know collision has been set
        gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
    }
}

/**
 * @brief 319d0 | d4 | Piston AI
 * 
 */
void Piston(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            PistonInit();

        case PISTON_POSE_IDLE_INIT:
            PistonIdleInit();
        
        case PISTON_POSE_CHECK_FOR_PROJECTILES:
            PistonCheckProjectile();
            break;

        case PISTON_POSE_OPENING:
            PistonOpen();
            break;

        case PISTON_POSE_OPENED:
            PistonOpened();
            break;
    }
}
