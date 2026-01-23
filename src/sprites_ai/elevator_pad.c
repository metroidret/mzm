#include "sprites_ai/elevator_pad.h"
#include "macros.h"

#include "data/sprites/elevator_pad.h"

#include "constants/sprite.h"
#include "constants/samus.h"

#include "structs/sprite.h"
#include "structs/samus.h"

#define ELEVATOR_PAD_POSE_IDLE 0x9

/**
 * @brief 2872c | b8 | Elevator pad AI
 * 
 */
void ElevatorPad(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.yPosition -= EIGHTH_BLOCK_SIZE;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = ELEVATOR_PAD_POSE_IDLE;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -PIXEL_SIZE;
        gCurrentSprite.hitboxBottom = PIXEL_SIZE;
        gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
        gCurrentSprite.hitboxRight = PIXEL_SIZE;

        gCurrentSprite.pOam = sElevatorPadOam_Idle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    if (gSamusData.pose == SPOSE_USING_AN_ELEVATOR)
    {
        // Sync position
        gCurrentSprite.yPosition = gSamusData.yPosition;
        gCurrentSprite.xPosition = gSamusData.xPosition;

        if (gCurrentSprite.pOam == sElevatorPadOam_Idle)
        {
            // Set moving
            gCurrentSprite.pOam = sElevatorPadOam_Moving;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
    else
    {
        if (gCurrentSprite.pOam == sElevatorPadOam_Moving)
        {
            // Set idle
            gCurrentSprite.pOam = sElevatorPadOam_Idle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
}
