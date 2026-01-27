#ifndef KRAID_DATA_H
#define KRAID_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

MAKE_ENUM(u8, KraidOam) {
    KRAID_OAM_MOUTH_CLOSED,
    KRAID_OAM_MOUTH_CLOSED_BLINK,
    KRAID_OAM_OPENING_MOUTH,
    KRAID_OAM_MOUTH_OPENED,
    KRAID_OAM_RISING,
    KRAID_OAM_CLOSING_MOUTH,
    KRAID_OAM_2cac5c,
    KRAID_OAM_LEFT_ARM_IDLE,
    KRAID_OAM_LEFT_ARM_DYING,
    KRAID_OAM_LEFT_ARM_THROWING_NAILS,
    KRAID_OAM_2cadc4,
    KRAID_OAM_RIGHT_ARM_IDLE,
    KRAID_OAM_RIGHT_ARM_Attacking,
    KRAID_OAM_RIGHT_ARM_DYING,
    KRAID_OAM_LEFT_FEET_RISING,
    KRAID_OAM_LEFT_FEET_IDLE_1,
    KRAID_OAM_LEFT_FEET_MOVING_RIGHT,
    KRAID_OAM_LEFT_FEET_IDLE_2,
    KRAID_OAM_LEFT_FEET_MOVED_RIGHT,
    KRAID_OAM_LEFT_FEET_MOVING_LEFT,
    KRAID_OAM_LEFT_FEET_MOVED_LEFT,
    KRAID_OAM_RIGHT_FEET_RISING,
    KRAID_OAM_RIGHT_FEET_IDLE_1,
    KRAID_OAM_RIGHT_FEET_MOVED_RIGHT,
    KRAID_OAM_RIGHT_FEET_IDLE_2,
    KRAID_OAM_RIGHT_FEET_MOVING_RIGHT,
    KRAID_OAM_RIGHT_FEET_MOVED_LEFT,
    KRAID_OAM_RIGHT_FEET_MOVING_LEFT,
    KRAID_OAM_TOP_HOLE_LEFT,
    KRAID_OAM_TOP_HOLE_RIGHT,
    KRAID_OAM_MIDDLE_HOLE_LEFT,
    KRAID_OAM_MIDDLE_HOLE_RIGHT,
    KRAID_OAM_BOTTOM_HOLE_LEFT,
    KRAID_OAM_BOTTOM_HOLE_RIGHT,
    KRAID_OAM_NAIL,
    KRAID_OAM_2cb29c,
    KRAID_OAM_2cb2ac,
    KRAID_OAM_SPIKE,

    KRAID_OAM_COUNT
};

extern const struct MultiSpriteData sKraidMultiSpriteData_Rising[2];

extern const struct MultiSpriteData sKraidMultiSpriteData_Standing[4];

extern const struct MultiSpriteData sKraidMultiSpriteData_StandingBetweenSteps[4];

extern const struct MultiSpriteData sKraidMultiSpriteData_MovingLeftFeetToRight[7];

extern const struct MultiSpriteData sKraidMultiSpriteData_MovingRightFeetToRight[7];

extern const struct MultiSpriteData sKraidMultiSpriteData_MovingLeftFeetToLeft[7];

extern const struct MultiSpriteData sKraidMultiSpriteData_MovingRightFeetToLeft[7];

extern const struct MultiSpriteData sKraidMultiSpriteData_Dying1[2];

extern const struct MultiSpriteData sKraidMultiSpriteData_Dying2[2];

extern const u32 sKraidGfx[2725];
extern const u16 sKraidPal[128];

extern const struct FrameData sKraidOam_MouthClosed[6];

extern const struct FrameData sKraidOam_MouthClosedBlink[11];

extern const struct FrameData sKraidOam_OpeningMouth[9];

extern const struct FrameData sKraidOam_MouthOpened[7];

extern const struct FrameData sKraidOam_Rising[3];

extern const struct FrameData sKraidOam_ClosingMouth[5];

extern const struct FrameData sKraidPartOam_2cac5c[2];

extern const struct FrameData sKraidPartOam_LeftArmIdle[11];

extern const struct FrameData sKraidPartOam_LeftArmDying[11];

extern const struct FrameData sKraidPartOam_LeftArmThrowingNails[21];

extern const struct FrameData sKraidPartOam_2cadc4[2];

extern const struct FrameData sKraidPartOam_RightArmIdle[11];

extern const struct FrameData sKraidPartOam_RightArmAttacking[13];

extern const struct FrameData sKraidPartOam_RightArmDying[13];

extern const struct FrameData sKraidPartOam_LeftFeetRising[2];

extern const struct FrameData sKraidPartOam_LeftFeetIdle1[5];

extern const struct FrameData sKraidPartOam_LeftFeetMovingRight[8];

extern const struct FrameData sKraidPartOam_LeftFeetIdle2[5];

extern const struct FrameData sKraidPartOam_LeftFeetMovedRight[9];

extern const struct FrameData sKraidPartOam_LeftFeetMovingLeft[8];

extern const struct FrameData sKraidPartOam_LeftFeetMovedLeft[5];

extern const struct FrameData sKraidPartOam_RightFeetRising[2];

extern const struct FrameData sKraidPartOam_RightFeetIdle1[5];

extern const struct FrameData sKraidPartOam_RightFeetMovedRight[9];

extern const struct FrameData sKraidPartOam_RightFeetIdle2[5];

extern const struct FrameData sKraidPartOam_RightFeetMovingRight[8];

extern const struct FrameData sKraidPartOam_RightFeetMovedLeft[5];

extern const struct FrameData sKraidPartOam_RightFeetMovingLeft[8];

extern const struct FrameData sKraidPartOam_TopHoleLeft[5];

extern const struct FrameData sKraidPartOam_TopHoleRight[5];

extern const struct FrameData sKraidPartOam_MiddleHoleRight[5];

extern const struct FrameData sKraidPartOam_MiddleHoleLeft[5];

extern const struct FrameData sKraidPartOam_BottomHoleRight[5];

extern const struct FrameData sKraidPartOam_BottomHoleLeft[5];

extern const struct FrameData sKraidNailOam[2];

extern const struct FrameData sKraidOam_2cb29c[2];

extern const struct FrameData sKraidOam_2cb2ac[2];

extern const struct FrameData sKraidSpikeOam[9];

#endif /* KRAID_DATA_H */
