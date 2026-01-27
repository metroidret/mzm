#ifndef MECHA_RIDLEY_DATA_H
#define MECHA_RIDLEY_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

MAKE_ENUM(u8, MechaRidleyOam) {
    MECHA_RIDLEY_OAM_TAIL,
    MECHA_RIDLEY_OAM_RING,
    MECHA_RIDLEY_OAM_COVER,
    MECHA_RIDLEY_OAM_TORSO,
    MECHA_RIDLEY_OAM_CORE_IDLE,
    MECHA_RIDLEY_OAM_HEAD_IDLE,
    MECHA_RIDLEY_OAM_HEAD_OPENING_MOUTH,
    MECHA_RIDLEY_OAM_HEAD_SPITTING_FIREBALLS,
    MECHA_RIDLEY_OAM_HEAD_CLOSING_MOUTH,
    MECHA_RIDLEY_OAM_EYE_IDLE,
    MECHA_RIDLEY_OAM_EYE_GLOWING,
    MECHA_RIDLEY_OAM_EYE_SHOOTING_LASER_FORWARD,
    MECHA_RIDLEY_OAM_EYE_SHOOTING_LASER_SLIGHTLY_DOWN,
    MECHA_RIDLEY_OAM_EYE_SHOOTING_LASER_DOWN,
    MECHA_RIDLEY_OAM_EYE_SHOOTING_LASER_SLIGHTLY_UP,
    MECHA_RIDLEY_OAM_EYE_SHOOTING_LASER_UP,
    MECHA_RIDLEY_OAM_EYE_INACTIVE,
    MECHA_RIDLEY_OAM_LEFT_ARM_CRAWLING_FORWARD,
    MECHA_RIDLEY_OAM_RIGHT_ARM_CRAWLING_FORWARD,
    MECHA_RIDLEY_OAM_LEFT_ARM_HOLDING_UP,
    MECHA_RIDLEY_OAM_RIGHT_ARM_HOLDING_UP,
    MECHA_RIDLEY_OAM_LEFT_ARM_HELD_UP,
    MECHA_RIDLEY_OAM_RIGHT_ARM_HELD_UP,
    MECHA_RIDLEY_OAM_LEFT_ARM_LAYING_DOWN,
    MECHA_RIDLEY_OAM_RIGHT_ARM_LAYING_DOWN,
    MECHA_RIDLEY_OAM_LEFT_ARM_TREMBLING,
    MECHA_RIDLEY_OAM_RIGHT_ARM_TREMBLING,
    MECHA_RIDLEY_OAM_LEFT_ARM_IDLE,
    MECHA_RIDLEY_OAM_RIGHT_ARM_IDLE,
    MECHA_RIDLEY_OAM_LEFT_ARM_SWINGING,
    MECHA_RIDLEY_OAM_NECK_LOW,
    MECHA_RIDLEY_OAM_NECK_MIDDLE,
    MECHA_RIDLEY_OAM_NECK_HIGH,
    MECHA_RIDLEY_OAM_NECK_ROTATE_LOW,
    MECHA_RIDLEY_OAM_NECK_ROTATE_MIDDLE,
    MECHA_RIDLEY_OAM_NECK_ROTATE_HIGH,
    MECHA_RIDLEY_OAM_NECK_LOW_TO_MIDDLE,
    MECHA_RIDLEY_OAM_NECK_MIDDLE_TO_HIGH,
    MECHA_RIDLEY_OAM_NECK_HIGH_TO_MIDDLE,
    MECHA_RIDLEY_OAM_NECK_MIDDLE_TO_LOW,
    MECHA_RIDLEY_OAM_NECK_LOW_TO_HIGH,
    MECHA_RIDLEY_OAM_NECK_HIGH_TO_LOW,
    MECHA_RIDLEY_OAM_NECK_LOW_2,
    MECHA_RIDLEY_OAM_NECK_MIDDLE_2,
    MECHA_RIDLEY_OAM_NECK_HIGH_2,
    MECHA_RIDLEY_OAM_MISSILE_LAUNCHER_CLOSED,
    MECHA_RIDLEY_OAM_MISSILE_LAUNCHER_OPENING,
    MECHA_RIDLEY_OAM_MISSILE_LAUNCHER_OPENED,
    MECHA_RIDLEY_OAM_MISSILE_LAUNCHER_CLOSING,
    MECHA_RIDLEY_OAM_MISSILE,
    MECHA_RIDLEY_OAM_FIREBALL,
    MECHA_RIDLEY_OAM_LASER_FORWARD,
    MECHA_RIDLEY_OAM_LASER_SLIGHTLY_DOWN,
    MECHA_RIDLEY_OAM_LASER_DOWN,
    MECHA_RIDLEY_OAM_LASER_SLIGHTLY_UP,
    MECHA_RIDLEY_OAM_LASER_UP,
    MECHA_RIDLEY_OAM_LEFT_ARM_DYING,
    MECHA_RIDLEY_OAM_RIGHT_ARM_DYING,
    MECHA_RIDLEY_OAM_NECK_DYING,
    MECHA_RIDLEY_OAM_LEFT_ARM_CRAWLING_BACKWARDS,
    MECHA_RIDLEY_OAM_RIGHT_ARM_CRAWLING_BACKWARDS,
    MECHA_RIDLEY_OAM_LEFT_ARM_SWINGING_AT_GROUND,
    MECHA_RIDLEY_OAM_LEFT_ARM_SWINGING_AT_CLOSE_GROUND,

    MECHA_RIDLEY_OAM_COUNT
};

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_CrawlingForwardLow[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_CrawlingForwardMiddle[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_CrawlingForwardHigh[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_Crawling_Unused1[2];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_Crawling_Unused2[2];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_Crawling_Unused3[2];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_DyingStandingLow[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_DyingStandingMiddle[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_DyingStandingHigh[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_RaisingArmLow[4];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_RaisingArmMiddle[4];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_RaisingArmHigh[4];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_StandingLow[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_StandingMiddle[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_StandingHigh[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_SmallSwipeLow[6];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_SmallSwipeMiddle[6];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_SmallSwipeHigh[6];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_ShakingHeadLow[10];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_ShakingHeadMiddle[10];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_ShakingHeadHigh[10];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_LowToMiddle[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_MiddleToHigh[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_HighToMiddle[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_MiddleToLow[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_LowToHigh[5];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_HighToLow[5];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_OpeningMouthLow[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_SpittingFireballsLow[4];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_ClosingMouthLow[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_OpeningMouthMiddle[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_SpittingFireballsMiddle[4];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_ClosingMouthMiddle[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_OpeningMouthHigh[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_SpittingFireballsHigh[4];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_ClosingMouthHigh[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_FiringMissilesArmsUpLow[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_FiringMissilesArmsUpMiddle[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_FiringMissilesArmsUpHigh[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_FiringMissilesLow[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_FiringMissilesMiddle[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_FiringMissilesHigh[3];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_Dying[11];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_CrawlingBackwardsLow[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_CrawlingBackwardsMiddle[7];

extern const struct MultiSpriteData sMechaRidleyMultiSpriteData_CrawlingBackwardsHigh[7];

extern const u8 sMechaRidleyGreenGlowPaletteData[7][2];

extern const u32 sMechaRidleyGfx[2525];
extern const u32 sMechaRidleyWeaponsGfx[1024];
extern const u32 sMechaRidleyDestroyedGfx[336];

extern const u16 sMechaRidleyPal[129];

extern const u16 sMechaRidley_8323aaa_Pal[12];
extern const u16 sMechaRidleyGreenGlowPal[4 * 16];
extern const u16 sMechaRidley_8323b42_Pal[4];
extern const u16 sMechaRidley_8323b4a_Pal[12];
extern const u16 sMechaRidley_8323b62_Pal[3];

extern const u16 sMechaRidleyFadingPal[7 * 16];

extern const struct FrameData sMechaRidleyPartOam_Tail[2];
extern const struct FrameData sMechaRidleyPartOam_Ring[2];
extern const struct FrameData sMechaRidleyPartOam_Cover[2];
extern const struct FrameData sMechaRidleyPartOam_Torso[2];

extern const struct FrameData sMechaRidleyOam_Idle[5];

extern const struct FrameData sMechaRidleyPartOam_HeadIdle[2];
extern const struct FrameData sMechaRidleyPartOam_HeadOpeningMouth[4];
extern const struct FrameData sMechaRidleyPartOam_HeadSpittingFireballs[4];
extern const struct FrameData sMechaRidleyPartOam_HeadClosingMouth[4];

extern const struct FrameData sMechaRidleyPartOam_EyeIdle[7];
extern const struct FrameData sMechaRidleyPartOam_EyeGlowing[5];
extern const struct FrameData sMechaRidleyPartOam_EyeShootingLaserForward[8];
extern const struct FrameData sMechaRidleyPartOam_EyeShootingLaserSlightlyDown[8];
extern const struct FrameData sMechaRidleyPartOam_EyeShootingLaserDown[8];
extern const struct FrameData sMechaRidleyPartOam_EyeShootingLaserSlightlyUp[8];
extern const struct FrameData sMechaRidleyPartOam_EyeShootingLaserUp[8];
extern const struct FrameData sMechaRidleyPartOam_EyeInactive[3];

extern const struct FrameData sMechaRidleyPartOam_LeftArmCrawlingForward[12];
extern const struct FrameData sMechaRidleyPartOam_RightArmCrawlingForward[12];
extern const struct FrameData sMechaRidleyPartOam_LeftArmHoldingUp[6];
extern const struct FrameData sMechaRidleyPartOam_RightArmHoldingUp[6];
extern const struct FrameData sMechaRidleyPartOam_LeftArmHeldUp[2];
extern const struct FrameData sMechaRidleyPartOam_RightArmHeldUp[2];
extern const struct FrameData sMechaRidleyPartOam_LeftArmLayingDown[5];
extern const struct FrameData sMechaRidleyPartOam_RightArmLayingDown[5];
extern const struct FrameData sMechaRidleyPartOam_LeftArmTrembling[7];
extern const struct FrameData sMechaRidleyPartOam_RightArmTrembling[7];
extern const struct FrameData sMechaRidleyPartOam_LeftArmIdle[2];
extern const struct FrameData sMechaRidleyPartOam_RightArmIdle[2];
extern const struct FrameData sMechaRidleyPartOam_LeftArmSwinging[9];

extern const struct FrameData sMechaRidleyPartOam_NeckLow[2];
extern const struct FrameData sMechaRidleyPartOam_NeckMiddle[2];
extern const struct FrameData sMechaRidleyPartOam_NeckHigh[2];
extern const struct FrameData sMechaRidleyPartOam_NeckRotateLow[10];
extern const struct FrameData sMechaRidleyPartOam_NeckRotateMiddle[10];
extern const struct FrameData sMechaRidleyPartOam_NeckRotateHigh[10];
extern const struct FrameData sMechaRidleyPartOam_NeckLowToMiddle[3];
extern const struct FrameData sMechaRidleyPartOam_NeckMiddleToHigh[3];
extern const struct FrameData sMechaRidleyPartOam_NeckHighToMiddle[3];
extern const struct FrameData sMechaRidleyPartOam_NeckMiddleToLow[3];
extern const struct FrameData sMechaRidleyPartOam_NeckLowToHigh[5];
extern const struct FrameData sMechaRidleyPartOam_NeckHighToLow[5];
extern const struct FrameData sMechaRidleyPartOam_NeckLow_2[2];
extern const struct FrameData sMechaRidleyPartOam_NeckMiddle_2[2];
extern const struct FrameData sMechaRidleyPartOam_NeckHigh_2[2];

extern const struct FrameData sMechaRidleyPartOam_MissileLauncherClosed[2];
extern const struct FrameData sMechaRidleyPartOam_MissileLauncherOpening[9];
extern const struct FrameData sMechaRidleyPartOam_MissileLauncherOpened[3];
extern const struct FrameData sMechaRidleyPartOam_MissileLauncherClosing[9];

extern const struct FrameData sMechaRidleyMissileOam[2];

extern const struct FrameData sMechaRidleyFireballOam[5];

extern const struct FrameData sMechaRidleyLaserOam_Forward[4];
extern const struct FrameData sMechaRidleyLaserOam_SlightlyDown[4];
extern const struct FrameData sMechaRidleyLaserOam_Down[4];
extern const struct FrameData sMechaRidleyLaserOam_SlightlyUp[4];
extern const struct FrameData sMechaRidleyLaserOam_Up[4];

extern const struct FrameData sMechaRidleyPartOam_LeftArmDying[11];
extern const struct FrameData sMechaRidleyPartOam_RightArmDying[11];
extern const struct FrameData sMechaRidleyPartOam_NeckDying[11];

extern const struct FrameData sMechaRidleyPartOam_LeftArmCrawlingBackwards[12];
extern const struct FrameData sMechaRidleyPartOam_RightArmCrawlingBackwards[12];
extern const struct FrameData sMechaRidleyPartOam_LeftArmSwingingAtGround[11];
extern const struct FrameData sMechaRidleyPartOam_LeftArmSwingingAtCloseGround[11];

extern const struct FrameData sMechaRidleyPartOam_EyeDying[3];

#endif /* MECHA_RIDLEY_DATA_H */
