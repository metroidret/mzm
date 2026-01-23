#include "sprites_ai/security_laser.h"
#include "macros.h"
#include "gba.h"

#include "data/sprites/security_laser.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/sprite.h"

#include "structs/sprite.h"

#define SECURITY_LASER_SMALL 0x2
#define SECURITY_LASER_MEDIUM 0x3
#define SECURITY_LASER_LARGE 0x4
#define SECURITY_LASER_VERY_LARGE 0x5
#define SECURITY_LASER_VERTICAL 0x80

#define SECURITY_LASER_POSE_IDLE 0x9
#define SECURITY_LASER_POSE_DISAPPEARING 0xB
#define SECURITY_LASER_POSE_UNUSED 0xC
#define SECURITY_LASER_POSE_SET_ALARM 0x23

/**
 * @brief 37cbc | 21c | Initializes a security laser sprite
 * 
 */
static void SecurityLaserInit(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.spriteId == PSPRITE_SECURITY_LASER_VERTICAL || gCurrentSprite.spriteId == PSPRITE_SECURITY_LASER_VERTICAL2)
    {
        // Initialize vertical laser
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

        // Get size
        if (SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOam_VerticalSmall;
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 1 + HALF_BLOCK_SIZE + PIXEL_SIZE);
            gCurrentSprite.work1 = SECURITY_LASER_VERTICAL | SECURITY_LASER_SMALL;
        }
        else if (SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOam_VerticalMedium;
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + PIXEL_SIZE);
            gCurrentSprite.work1 = SECURITY_LASER_VERTICAL | SECURITY_LASER_MEDIUM;
        }
        else if (SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 4 + HALF_BLOCK_SIZE), xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOam_VerticalLarge;
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE + PIXEL_SIZE);
            gCurrentSprite.work1 = SECURITY_LASER_VERTICAL | SECURITY_LASER_LARGE;
        }
        else
        {
            gCurrentSprite.pOam = sSecurityLaserOam_VerticalVeryLarge;
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5);
            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE + PIXEL_SIZE);
            gCurrentSprite.work1 = SECURITY_LASER_VERTICAL | SECURITY_LASER_VERY_LARGE;
        }

        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = -EIGHTH_BLOCK_SIZE;
        gCurrentSprite.hitboxRight = EIGHTH_BLOCK_SIZE;
    }
    else
    {
        // Initialize horizontal laser
        // Get size
        if (SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition + BLOCK_SIZE * 2) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOam_HorizontalSmall;
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 1 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 1 + PIXEL_SIZE;
            gCurrentSprite.work1 = SECURITY_LASER_SMALL;
        }
        else if (SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition + BLOCK_SIZE * 3) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOam_HorizontalMedium;
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + PIXEL_SIZE;
            gCurrentSprite.work1 = SECURITY_LASER_MEDIUM;
        }
        else if (SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition + BLOCK_SIZE * 4) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOam_HorizontalLarge;
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 3 + PIXEL_SIZE;
            gCurrentSprite.work1 = SECURITY_LASER_LARGE;
        }
        else
        {
            gCurrentSprite.pOam = sSecurityLaserOam_HorizontalVeryLarge;
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 4 + PIXEL_SIZE;
            gCurrentSprite.work1 = SECURITY_LASER_VERY_LARGE;
        }

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);

        gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
        gCurrentSprite.hitboxBottom = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
        gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
    }

    gCurrentSprite.samusCollision = SSC_CHECK_COLLIDING;
    gCurrentSprite.drawOrder = 2;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    
    TransparencyUpdateBldcnt(0x1, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
        BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL);

    if (gAlarmTimer != 0)
    {
        // Set aware
        gCurrentSprite.pose = SECURITY_LASER_POSE_SET_ALARM;
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.work2 = FALSE;
        gCurrentSprite.work3 = BLDALPHA_MAX_VALUE;
    }
    else
    {
        // Set idle
        gCurrentSprite.pose = SECURITY_LASER_POSE_IDLE;
        gCurrentSprite.work2 = TRUE;
        gCurrentSprite.work3 = BLDALPHA_MAX_VALUE / 2;
    }
}

/**
 * @brief 37ed8 | 13c | Handles a security laser being idle
 * 
 */
static void SecurityLaserIdle(void)
{
    struct SpriteData* pSprite;

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gAlarmTimer = ALARM_TIMER_ACTIVE_TIMER;

        for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
        {
            if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == SSC_SPACE_PIRATE)
                pSprite->status |= SPRITE_STATUS_MOSAIC;
        }
    }
    else if (gAlarmTimer == 0)
    {
        return;
    }

    gCurrentSprite.pose = SECURITY_LASER_POSE_DISAPPEARING;
    gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    // Set disappearing OAM
    switch (gCurrentSprite.work1)
    {
        case SECURITY_LASER_SMALL:
            gCurrentSprite.pOam = sSecurityLaserOam_HorizontalSmallDisappearing;
            break;

        case SECURITY_LASER_MEDIUM:
            gCurrentSprite.pOam = sSecurityLaserOam_HorizontalMediumDisappearing;
            break;

        case SECURITY_LASER_LARGE:
            gCurrentSprite.pOam = sSecurityLaserOam_HorizontalLargeDisappearing;
            break;

        case SECURITY_LASER_VERY_LARGE:
            gCurrentSprite.pOam = sSecurityLaserOam_HorizontalVeryLargeDisappearing;
            break;

        case SECURITY_LASER_VERTICAL | SECURITY_LASER_SMALL:
            gCurrentSprite.pOam = sSecurityLaserOam_VerticalSmallDisappearing;
            break;

        case SECURITY_LASER_VERTICAL | SECURITY_LASER_MEDIUM:
            gCurrentSprite.pOam = sSecurityLaserOam_VerticalMediumDisappearing;
            break;

        case SECURITY_LASER_VERTICAL | SECURITY_LASER_LARGE:
            gCurrentSprite.pOam = sSecurityLaserOam_VerticalLargeDisappearing;
            break;

        case SECURITY_LASER_VERTICAL | SECURITY_LASER_VERY_LARGE:
            gCurrentSprite.pOam = sSecurityLaserOam_VerticalVeryLargeDisappearing;
            break;

        default:
            gCurrentSprite.status = 0;
            return;
    }

    SoundPlay(SOUND_SECURITY_LASER_TRIPPED);
}

/**
 * @brief 38014 | d4 | Checks if the despawning animation has ended
 * 
 */
static void SecurityLaserCheckDespawnAnimEnded(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = SECURITY_LASER_POSE_SET_ALARM;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;

        switch (gCurrentSprite.work1)
        {
            case SECURITY_LASER_SMALL:
                gCurrentSprite.pOam = sSecurityLaserOam_HorizontalSmall;
                break;

            case SECURITY_LASER_MEDIUM:
                gCurrentSprite.pOam = sSecurityLaserOam_HorizontalMedium;
                break;

            case SECURITY_LASER_LARGE:
                gCurrentSprite.pOam = sSecurityLaserOam_HorizontalLarge;
                break;

            case SECURITY_LASER_VERY_LARGE:
                gCurrentSprite.pOam = sSecurityLaserOam_HorizontalVeryLarge;
                break;

            case SECURITY_LASER_VERTICAL | SECURITY_LASER_SMALL:
                gCurrentSprite.pOam = sSecurityLaserOam_VerticalSmall;
                break;

            case SECURITY_LASER_VERTICAL | SECURITY_LASER_MEDIUM:
                gCurrentSprite.pOam = sSecurityLaserOam_VerticalMedium;
                break;

            case SECURITY_LASER_VERTICAL | SECURITY_LASER_LARGE:
                gCurrentSprite.pOam = sSecurityLaserOam_VerticalLarge;
                break;

            case SECURITY_LASER_VERTICAL | SECURITY_LASER_VERY_LARGE:
                gCurrentSprite.pOam = sSecurityLaserOam_VerticalVeryLarge;
                break;

            default:
                gCurrentSprite.status = 0;
        }
    }
}

/**
 * @brief 380e8 | 1c | Continuously sets the alarm
 * 
 */
static void SecurityLaserSetAlarm(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    gAlarmTimer = ALARM_TIMER_ACTIVE_TIMER;
}

/**
 * @brief 38104 | cc | Unused code
 * 
 */
static void SecurityLaser_Unused(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (SpriteUtilHasCurrentAnimationEnded())
    {
        gCurrentSprite.pose = SECURITY_LASER_POSE_IDLE;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        switch (gCurrentSprite.work1)
        {
            case SECURITY_LASER_SMALL:
                gCurrentSprite.pOam = sSecurityLaserOam_HorizontalSmall;
                break;

            case SECURITY_LASER_MEDIUM:
                gCurrentSprite.pOam = sSecurityLaserOam_HorizontalMedium;
                break;

            case SECURITY_LASER_LARGE:
                gCurrentSprite.pOam = sSecurityLaserOam_HorizontalLarge;
                break;

            case SECURITY_LASER_VERY_LARGE:
                gCurrentSprite.pOam = sSecurityLaserOam_HorizontalVeryLarge;
                break;

            case SECURITY_LASER_VERTICAL | SECURITY_LASER_SMALL:
                gCurrentSprite.pOam = sSecurityLaserOam_VerticalSmall;
                break;

            case SECURITY_LASER_VERTICAL | SECURITY_LASER_MEDIUM:
                gCurrentSprite.pOam = sSecurityLaserOam_VerticalMedium;
                break;

            case SECURITY_LASER_VERTICAL | SECURITY_LASER_LARGE:
                gCurrentSprite.pOam = sSecurityLaserOam_VerticalLarge;
                break;

            case SECURITY_LASER_VERTICAL | SECURITY_LASER_VERY_LARGE:
                gCurrentSprite.pOam = sSecurityLaserOam_VerticalVeryLarge;
                break;

            default:
                gCurrentSprite.status = 0;
        }
    }
}

/**
 * @brief 381d0 | 138 | Security laser AI
 * 
 */
void SecurityLaser(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            SecurityLaserInit();
            break;

        case SECURITY_LASER_POSE_IDLE:
            SecurityLaserIdle();
            break;

        case SECURITY_LASER_POSE_DISAPPEARING:
            SecurityLaserCheckDespawnAnimEnded();
            break;

        case SECURITY_LASER_POSE_SET_ALARM:
            SecurityLaserSetAlarm();
            break;

        case SECURITY_LASER_POSE_UNUSED:
            SecurityLaser_Unused();
    }

    if (gCurrentSprite.spriteId == PSPRITE_SECURITY_LASER_VERTICAL || gCurrentSprite.spriteId == PSPRITE_SECURITY_LASER_HORIZONTAL)
    {
        if (gAlarmTimer != 0)
        {
            if (gCurrentSprite.work2)
            {
                gCurrentSprite.work2--;
                if (gCurrentSprite.work2 == 0 && gCurrentSprite.work3 < BLDALPHA_MAX_VALUE)
                {
                    gCurrentSprite.work3++;
                    gCurrentSprite.work2 = TRUE;
                }
            }
        }
        else if (gCurrentSprite.work3 != BLDALPHA_MAX_VALUE / 2)            
        {
            gCurrentSprite.work3 = BLDALPHA_MAX_VALUE / 2;
            gCurrentSprite.work2 = TRUE;
        }

        TransparencySpriteUpdateBldalpha(0, gCurrentSprite.work3, 0, BLDALPHA_MAX_VALUE);
    }
}
