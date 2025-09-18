#include "data/sprites/acid_worm.h"
#include "macros.h"

const s16 sAcidWormSpitCloseYVelocity[16] = {
    0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xE, 0x10, 0x12, SHORT_MAX
};

const s16 sAcidWormSpitFarYVelocity[26] = {
    -0x10, -0xC, -0x8, -0x4, -0x3, -0x2, -0x1, 0x0, 0x0, 0x0, 0x1, 0x2, 0x3, 0x4,
    0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xE, 0x10, 0x12, SHORT_MAX
};

const s16 sAcidWormSpitMiddleYVelocity[20] = {
    0x0, 0x0, 0x0, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB,
    0xC, 0xE, 0x10, 0x12, SHORT_MAX
};

const s16 sAcidWormSwingingMovement[33] = {
    0x0, 0x0, 0x0, 0x0, -0x1, -0x1, -0x1, -0x1, -0x2, -0x2, -0x2, -0x2, -0x1, -0x1, -0x1, -0x1,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x2, 0x2, 0x2, 0x2, 0x1, 0x1, 0x1, 0x1, SHORT_MAX
};

const s16 sAcidWormHeadRandomXVelocity[45] = {
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    -0x1, -0x1, -0x2, -0x2, -0x3, -0x4, -0x4, -0x3, -0x2, -0x2, -0x1, -0x1, 0x1, 0x1, 0x2, 0x2, 0x3,
    0x4, 0x4, 0x3, 0x2, 0x2, 0x1, 0x1, SHORT_MAX
};

const u32 sAcidWormGfx[1000] = INCBIN_U32("data/sprites/AcidWorm.gfx.lz");
const u16 sAcidWormPal[64] = INCBIN_U16("data/sprites/AcidWorm.pal");

static const u16 sAcidWormPartOam_Unused2_Frame0[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-15, -9, OAM_DIMS_32x32, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-16, 9, OAM_DIMS_32x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-17, 26, OAM_DIMS_32x32, OAM_NO_FLIP, 654, 8, 0),
    OAM_ENTRY(-16, -26, OAM_DIMS_32x32, OAM_NO_FLIP, 641, 8, 0),
    OAM_ENTRY(10, -44, OAM_DIMS_8x16, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(4, -41, OAM_DIMS_8x16, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(-4, -39, OAM_DIMS_8x16, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(-12, -42, OAM_DIMS_8x16, OAM_X_FLIP, 542, 8, 0),
    OAM_ENTRY(-18, -44, OAM_DIMS_8x16, OAM_X_FLIP, 543, 8, 0),
    OAM_ENTRY(12, -49, OAM_DIMS_8x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(6, -50, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -50, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-14, -50, OAM_DIMS_8x16, OAM_X_FLIP, 539, 8, 0),
    OAM_ENTRY(-20, -49, OAM_DIMS_8x16, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_32x32, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-16, 44, OAM_DIMS_32x32, OAM_NO_FLIP, 658, 8, 0),
    OAM_ENTRY(-16, 57, OAM_DIMS_32x32, OAM_NO_FLIP, 658, 8, 0),
};

static const u16 sAcidWormPartOam_Unused2_Frame1[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-16, -10, OAM_DIMS_32x32, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-15, 8, OAM_DIMS_32x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-14, 25, OAM_DIMS_32x32, OAM_NO_FLIP, 654, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 673, 8, 0),
    OAM_ENTRY(10, -41, OAM_DIMS_8x16, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(4, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(-4, -36, OAM_DIMS_8x16, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(-12, -39, OAM_DIMS_8x16, OAM_X_FLIP, 542, 8, 0),
    OAM_ENTRY(-18, -41, OAM_DIMS_8x16, OAM_X_FLIP, 543, 8, 0),
    OAM_ENTRY(12, -46, OAM_DIMS_8x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(6, -47, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -47, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-14, -47, OAM_DIMS_8x16, OAM_X_FLIP, 539, 8, 0),
    OAM_ENTRY(-20, -46, OAM_DIMS_8x16, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(-16, -37, OAM_DIMS_32x32, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-13, 42, OAM_DIMS_32x32, OAM_NO_FLIP, 658, 8, 0),
    OAM_ENTRY(-14, 56, OAM_DIMS_32x32, OAM_NO_FLIP, 658, 8, 0),
};

static const u16 sAcidWormPartOam_Unused2_Frame2[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-15, -10, OAM_DIMS_32x32, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-13, 7, OAM_DIMS_32x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-14, 24, OAM_DIMS_32x32, OAM_NO_FLIP, 654, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 673, 8, 0),
    OAM_ENTRY(10, -42, OAM_DIMS_8x16, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(4, -39, OAM_DIMS_8x16, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(-4, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(-12, -40, OAM_DIMS_8x16, OAM_X_FLIP, 542, 8, 0),
    OAM_ENTRY(-18, -42, OAM_DIMS_8x16, OAM_X_FLIP, 543, 8, 0),
    OAM_ENTRY(12, -47, OAM_DIMS_8x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(6, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-14, -48, OAM_DIMS_8x16, OAM_X_FLIP, 539, 8, 0),
    OAM_ENTRY(-20, -47, OAM_DIMS_8x16, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(-16, -38, OAM_DIMS_32x32, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-15, 41, OAM_DIMS_32x32, OAM_NO_FLIP, 658, 8, 0),
    OAM_ENTRY(-15, 55, OAM_DIMS_32x32, OAM_NO_FLIP, 658, 8, 0),
};

static const u16 sAcidWormOam_Spitting_Frame4[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(10, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(4, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(-12, -18, OAM_DIMS_8x16, OAM_X_FLIP, 542, 8, 0),
    OAM_ENTRY(-18, -20, OAM_DIMS_8x16, OAM_X_FLIP, 543, 8, 0),
    OAM_ENTRY(12, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(6, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-14, -26, OAM_DIMS_8x16, OAM_X_FLIP, 539, 8, 0),
    OAM_ENTRY(-20, -25, OAM_DIMS_8x16, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 513, 8, 0),
};

static const u16 sAcidWormOam_Spitting_Frame3[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(10, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 607, 8, 0),
    OAM_ENTRY(4, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 606, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 605, 8, 0),
    OAM_ENTRY(-12, -18, OAM_DIMS_8x16, OAM_X_FLIP, 606, 8, 0),
    OAM_ENTRY(-18, -20, OAM_DIMS_8x16, OAM_X_FLIP, 607, 8, 0),
    OAM_ENTRY(12, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(6, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 603, 8, 0),
    OAM_ENTRY(-4, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 602, 8, 0),
    OAM_ENTRY(-14, -26, OAM_DIMS_8x16, OAM_X_FLIP, 603, 8, 0),
    OAM_ENTRY(-20, -25, OAM_DIMS_8x16, OAM_X_FLIP, 604, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 513, 8, 0),
};

static const u16 sAcidWormOam_Spitting_Frame2[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(9, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 671, 8, 0),
    OAM_ENTRY(2, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 670, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 669, 8, 0),
    OAM_ENTRY(-10, -17, OAM_DIMS_8x16, OAM_X_FLIP, 670, 8, 0),
    OAM_ENTRY(-17, -21, OAM_DIMS_8x16, OAM_X_FLIP, 671, 8, 0),
    OAM_ENTRY(10, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 668, 8, 0),
    OAM_ENTRY(6, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 667, 8, 0),
    OAM_ENTRY(-4, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 666, 8, 0),
    OAM_ENTRY(-13, -27, OAM_DIMS_8x16, OAM_X_FLIP, 667, 8, 0),
    OAM_ENTRY(-18, -24, OAM_DIMS_8x16, OAM_X_FLIP, 668, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 513, 8, 0),
};

static const u16 sAcidWormOam_Spitting_Frame0[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(8, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 671, 8, 0),
    OAM_ENTRY(1, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 670, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 669, 8, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_8x16, OAM_X_FLIP, 670, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_8x16, OAM_X_FLIP, 671, 8, 0),
    OAM_ENTRY(9, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 668, 8, 0),
    OAM_ENTRY(5, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 667, 8, 0),
    OAM_ENTRY(-4, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 666, 8, 0),
    OAM_ENTRY(-12, -27, OAM_DIMS_8x16, OAM_X_FLIP, 667, 8, 0),
    OAM_ENTRY(-17, -25, OAM_DIMS_8x16, OAM_X_FLIP, 668, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 513, 8, 0),
};

static const u16 sAcidWormOam_MouthClosed_Frame2[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-4, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 733, 8, 0),
    OAM_ENTRY(1, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 734, 8, 0),
    OAM_ENTRY(-9, -18, OAM_DIMS_8x16, OAM_X_FLIP, 734, 8, 0),
    OAM_ENTRY(7, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 735, 8, 0),
    OAM_ENTRY(-15, -21, OAM_DIMS_8x16, OAM_X_FLIP, 735, 8, 0),
    OAM_ENTRY(-4, -29, OAM_DIMS_8x16, OAM_NO_FLIP, 730, 8, 0),
    OAM_ENTRY(8, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 732, 8, 0),
    OAM_ENTRY(-16, -26, OAM_DIMS_8x16, OAM_X_FLIP, 732, 8, 0),
    OAM_ENTRY(4, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 731, 8, 0),
    OAM_ENTRY(-11, -28, OAM_DIMS_8x16, OAM_X_FLIP, 731, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 513, 8, 0),
};

static const u16 sAcidWormOam_Idle_Frame0[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(2, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 600, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 664, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_X_FLIP, 600, 8, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_8x16, OAM_X_FLIP, 537, 8, 0),
    OAM_ENTRY(1, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 726, 8, 0),
    OAM_ENTRY(-3, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 598, 8, 0),
    OAM_ENTRY(-4, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 662, 8, 0),
    OAM_ENTRY(-18, -25, OAM_DIMS_16x16, OAM_X_FLIP, 726, 8, 0),
    OAM_ENTRY(-12, -27, OAM_DIMS_16x16, OAM_X_FLIP, 598, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 513, 8, 0),
};

static const u16 sAcidWormOam_Idle_Frame1[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(2, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 665, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 8, 0),
    OAM_ENTRY(-4, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 664, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_X_FLIP, 728, 8, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_8x16, OAM_X_FLIP, 665, 8, 0),
    OAM_ENTRY(1, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 726, 8, 0),
    OAM_ENTRY(1, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 663, 8, 0),
    OAM_ENTRY(-4, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 662, 8, 0),
    OAM_ENTRY(-17, -25, OAM_DIMS_16x16, OAM_X_FLIP, 726, 8, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_8x16, OAM_X_FLIP, 663, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 513, 8, 0),
};

static const u16 sAcidWormOam_Idle_Frame2[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(1, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 665, 8, 0),
    OAM_ENTRY(-1, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 664, 8, 0),
    OAM_ENTRY(-15, -19, OAM_DIMS_16x16, OAM_X_FLIP, 728, 8, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_8x16, OAM_X_FLIP, 665, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 726, 8, 0),
    OAM_ENTRY(1, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 663, 8, 0),
    OAM_ENTRY(-4, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 662, 8, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_16x16, OAM_X_FLIP, 726, 8, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_8x16, OAM_X_FLIP, 663, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 513, 8, 0),
};

static const u16 sAcidWormOam_Moving_Frame0[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(11, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(-12, -17, OAM_DIMS_8x16, OAM_X_FLIP, 542, 8, 0),
    OAM_ENTRY(-19, -19, OAM_DIMS_8x16, OAM_X_FLIP, 543, 8, 0),
    OAM_ENTRY(14, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(7, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-15, -25, OAM_DIMS_8x16, OAM_X_FLIP, 539, 8, 0),
    OAM_ENTRY(-22, -24, OAM_DIMS_8x16, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 513, 8, 0),
};

static const u16 sAcidWormOam_Moving_Frame1[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(12, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(-13, -17, OAM_DIMS_8x16, OAM_X_FLIP, 542, 8, 0),
    OAM_ENTRY(-20, -19, OAM_DIMS_8x16, OAM_X_FLIP, 543, 8, 0),
    OAM_ENTRY(15, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(8, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-16, -25, OAM_DIMS_8x16, OAM_X_FLIP, 539, 8, 0),
    OAM_ENTRY(-23, -23, OAM_DIMS_8x16, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_32x32, OAM_NO_FLIP, 513, 8, 0),
};

static const u16 sAcidWormPartOam_AroundMouth_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 641, 8, 0),
};

static const u16 sAcidWormPartOam_WeakPoint_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sAcidWormPartOam_WeakPoint_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 522, 8, 0),
};

static const u16 sAcidWormPartOam_WeakPoint_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 526, 8, 0),
};

static const u16 sAcidWormPartOam_BelowWeakPoint_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 530, 8, 0),
};

static const u16 sAcidWormPartOam_AboveSegments_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 654, 8, 0),
};

static const u16 sAcidWormPartOam_Segment_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 658, 8, 0),
};

static const u16 sAcidWormSpitOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 646, 8, 0),
};

static const u16 sAcidWormSpitOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 648, 8, 0),
};

static const u16 sAcidWormSpitOam_Moving_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 710, 8, 0),
};

static const u16 sAcidWormSpitOam_Exploding_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 712, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_X_FLIP, 745, 8, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_8x8, OAM_Y_FLIP, 745, 8, 0),
    OAM_ENTRY(-1, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 712, 8, 0),
};

static const u16 sAcidWormSpitOam_Exploding_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 712, 8, 0),
    OAM_ENTRY(3, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 712, 8, 0),
    OAM_ENTRY(-7, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 713, 8, 0),
    OAM_ENTRY(-1, -7, OAM_DIMS_8x8, OAM_XY_FLIP, 713, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_X_FLIP, 744, 8, 0),
};

static const u16 sAcidWormSpitOam_Exploding_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(1, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 712, 8, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_8x8, OAM_X_FLIP, 744, 8, 0),
    OAM_ENTRY(0, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 712, 8, 0),
    OAM_ENTRY(-12, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 712, 8, 0),
    OAM_ENTRY(-9, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 744, 8, 0),
    OAM_ENTRY(-2, -6, OAM_DIMS_8x8, OAM_XY_FLIP, 744, 8, 0),
    OAM_ENTRY(-1, -5, OAM_DIMS_8x8, OAM_XY_FLIP, 744, 8, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_8x8, OAM_Y_FLIP, 744, 8, 0),
};

static const u16 sAcidWormSpitOam_Exploding_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(1, 4, OAM_DIMS_8x8, OAM_X_FLIP, 744, 8, 0),
    OAM_ENTRY(3, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 712, 8, 0),
    OAM_ENTRY(-11, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 744, 8, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_8x8, OAM_XY_FLIP, 744, 8, 0),
    OAM_ENTRY(3, -7, OAM_DIMS_8x8, OAM_XY_FLIP, 744, 8, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 744, 8, 0),
};


const struct FrameData sAcidWormOam_Idle[5] = {
    [0] = {
        .pFrame = sAcidWormOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sAcidWormOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sAcidWormOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(7.f / 15)
    },
    [3] = {
        .pFrame = sAcidWormOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAcidWormOam_Moving[3] = {
    [0] = {
        .pFrame = sAcidWormOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sAcidWormOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAcidWormOam_Spitting[15] = {
    [0] = {
        .pFrame = sAcidWormOam_Spitting_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sAcidWormOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(11.f / 30)
    },
    [2] = {
        .pFrame = sAcidWormOam_Spitting_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sAcidWormOam_Spitting_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sAcidWormOam_Spitting_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sAcidWormOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sAcidWormOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sAcidWormOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sAcidWormOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sAcidWormOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sAcidWormOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sAcidWormOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [12] = {
        .pFrame = sAcidWormOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sAcidWormOam_Spitting_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [14] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAcidWormOam_MouthClosed[5] = {
    [0] = {
        .pFrame = sAcidWormOam_Spitting_Frame2,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [1] = {
        .pFrame = sAcidWormOam_Spitting_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sAcidWormOam_MouthClosed_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sAcidWormOam_Spitting_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAcidWormPartOam_AroundMouth[2] = {
    [0] = {
        .pFrame = sAcidWormPartOam_AroundMouth_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAcidWormPartOam_WeakPoint[9] = {
    [0] = {
        .pFrame = sAcidWormPartOam_WeakPoint_Frame0,
        .timer = ONE_THIRD_SECOND
    },
    [1] = {
        .pFrame = sAcidWormPartOam_WeakPoint_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sAcidWormPartOam_WeakPoint_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sAcidWormPartOam_WeakPoint_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = {
        .pFrame = sAcidWormPartOam_WeakPoint_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [5] = {
        .pFrame = sAcidWormPartOam_WeakPoint_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sAcidWormPartOam_WeakPoint_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = {
        .pFrame = sAcidWormPartOam_WeakPoint_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAcidWormPartOam_Unused[5] = {
    [0] = {
        .pFrame = sAcidWormPartOam_WeakPoint_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sAcidWormPartOam_WeakPoint_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sAcidWormPartOam_WeakPoint_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sAcidWormPartOam_WeakPoint_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAcidWormPartOam_BelowWeakPoint[2] = {
    [0] = {
        .pFrame = sAcidWormPartOam_BelowWeakPoint_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAcidWormPartOam_AboveSegments[2] = {
    [0] = {
        .pFrame = sAcidWormPartOam_AboveSegments_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAcidWormPartOam_Segment[2] = {
    [0] = {
        .pFrame = sAcidWormPartOam_Segment_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAcidWormPartOam_Unused2[5] = {
    [0] = {
        .pFrame = sAcidWormPartOam_Unused2_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sAcidWormPartOam_Unused2_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sAcidWormPartOam_Unused2_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sAcidWormPartOam_Unused2_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAcidWormSpitOam_Moving[4] = {
    [0] = {
        .pFrame = sAcidWormSpitOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sAcidWormSpitOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sAcidWormSpitOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAcidWormSpitOam_Exploding[6] = {
    [0] = {
        .pFrame = sAcidWormSpitOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sAcidWormSpitOam_Exploding_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sAcidWormSpitOam_Exploding_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sAcidWormSpitOam_Exploding_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sAcidWormSpitOam_Exploding_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAcidWormOam_Warning[14] = {
    [0] = {
        .pFrame = sAcidWormOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sAcidWormOam_Spitting_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sAcidWormOam_Spitting_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sAcidWormOam_Spitting_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sAcidWormOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sAcidWormOam_Spitting_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sAcidWormOam_Spitting_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sAcidWormOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = {
        .pFrame = sAcidWormOam_Spitting_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sAcidWormOam_Spitting_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sAcidWormOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [11] = {
        .pFrame = sAcidWormOam_Spitting_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [12] = {
        .pFrame = sAcidWormOam_Spitting_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [13] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAcidWormOam_SpawnOnTop[24] = {
    [0] = {
        .pFrame = sAcidWormOam_Spitting_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sAcidWormOam_Spitting_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sAcidWormOam_Spitting_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sAcidWormOam_Spitting_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sAcidWormOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sAcidWormOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sAcidWormOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sAcidWormOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sAcidWormOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sAcidWormOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = {
        .pFrame = sAcidWormOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [11] = {
        .pFrame = sAcidWormOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [12] = {
        .pFrame = sAcidWormOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [13] = {
        .pFrame = sAcidWormOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [14] = {
        .pFrame = sAcidWormOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [15] = {
        .pFrame = sAcidWormOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [16] = {
        .pFrame = sAcidWormOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [17] = {
        .pFrame = sAcidWormOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [18] = {
        .pFrame = sAcidWormOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [19] = {
        .pFrame = sAcidWormOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [20] = {
        .pFrame = sAcidWormOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [21] = {
        .pFrame = sAcidWormOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [22] = {
        .pFrame = sAcidWormOam_Spitting_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [23] = FRAME_DATA_TERMINATOR
};
