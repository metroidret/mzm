#include "sprites_ai/searchlight.h"
#include "gba/display.h"
#include "macros.h"

#include "data/sprites/searchlight.h"

#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"

#include "structs/display.h"
#include "structs/clipdata.h"
#include "structs/sprite.h"

#define SEARCHLIGHT_POSE_IDLE 0x9
#define SEARCHLIGHT_POSE_ACTIVATING 0x23
#define SEARCHLIGHT_POSE_ACTIVATE_ALARM 0x25

/**
 * @brief 49bd0 | 1fc | Searchlight AI
 * 
 */
void Searchlight(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            if (gAlarmTimer != 0)
            {
                 // Kill if alarm is active
                gCurrentSprite.status = 0;
                break;
            }

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);

            gCurrentSprite.hitboxTop = -THREE_QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = THREE_QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxLeft = -THREE_QUARTER_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = THREE_QUARTER_BLOCK_SIZE;

            gCurrentSprite.pOam = sSearchlightOam_Moving;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.samusCollision = SSC_CHECK_COLLIDING;
            gCurrentSprite.pose = SEARCHLIGHT_POSE_IDLE;
            gCurrentSprite.bgPriority = BGCNT_GET_PRIORITY(gIoRegistersBackup.BG1CNT);
            gCurrentSprite.drawOrder = 1;

            // Set initial direction based on sprite ID
            if (gCurrentSprite.spriteId == PSPRITE_SEARCHLIGHT)
                gCurrentSprite.status |= (SPRITE_STATUS_FACING_RIGHT | SPRITE_STATUS_FACING_DOWN);
            else if (gCurrentSprite.spriteId == PSPRITE_SEARCHLIGHT2)
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            else if (gCurrentSprite.spriteId == PSPRITE_SEARCHLIGHT3)
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            break;

        case SEARCHLIGHT_POSE_IDLE:
            // Flicker
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
                gAlarmTimer = ALARM_TIMER_ACTIVE_TIMER; // Activate alarm

            if (gAlarmTimer != 0)
            {
                // Alarm active, set activating behavior
                gCurrentSprite.pose = SEARCHLIGHT_POSE_ACTIVATING;
                gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);
                gCurrentSprite.samusCollision = SSC_NONE;
            }
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    // Move right
                    SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + BLOCK_SIZE);
                    if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT; // Change direction if colliding with stop enemy
                    else
                        gCurrentSprite.xPosition += PIXEL_SIZE / 2;
                }
                else
                {
                    // Move left
                    SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - BLOCK_SIZE);
                    if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT; // Change direction if colliding with stop enemy
                    else
                        gCurrentSprite.xPosition -= PIXEL_SIZE / 2;
                }

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                {
                    // Move down
                    SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition);
                    if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN; // Change direction if colliding with stop enemy
                    else
                        gCurrentSprite.yPosition += PIXEL_SIZE / 2;
                }
                else
                {
                    // Move up
                    SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition);
                    if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN; // Change direction if colliding with stop enemy
                    else
                        gCurrentSprite.yPosition -= PIXEL_SIZE / 2;
                }
            }
            break;

        case SEARCHLIGHT_POSE_ACTIVATING:
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (gCurrentSprite.work0 == 0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.pose = SEARCHLIGHT_POSE_ACTIVATE_ALARM;
            }
            break;


        case SEARCHLIGHT_POSE_ACTIVATE_ALARM:
            // Constantly activate alarm
            gAlarmTimer = ALARM_TIMER_ACTIVE_TIMER;
            break;
    }
}
