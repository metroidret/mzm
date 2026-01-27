#include "data/sprites/gunship.h"
#include "macros.h"

const s16 sGunshipTakingOffYVelocity[153] = {
0, 0, -1, 0, 0, -1, 0, 0, 0, -1, 0, -1, 0, -1, 0,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1,
-2, -1, -2, -1, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -3, -3, -3, -3, -4, -4, -4, -4, -2, -2, -2,
-2, -2, -2, -2, -2, -1, -2, -1, -2, -1, -2, -1,
-2, 0, -1, 0, -1, 0, -1, 0, -1, 0, 0, -1, 0, 0,
-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0,
1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0,
1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1,
0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,
-1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, SHORT_MAX
};

const s16 sGunshipFlyingYVelocity[22] = {
    -3, -3, -3, -3, -4, -4, -4, -4, -5, -5, -6, -6,
    -7, -7, -8, -12, -16, -20, -24, -28, -32, SHORT_MAX
};

const u32 sGunshipGfx[1027] = INCBIN_U32("data/sprites/gunship.gfx.lz");
const u16 sGunshipPal[48] = INCBIN_U16("data/sprites/gunship.pal");
const u16 sGunshipFlashingPal[8 * 16] = INCBIN_U16("data/sprites/gunship_flashing_pal.pal");

static const u16 sGunshipOam_Idle_Frame0[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-115, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x300, 9, 0),
    OAM_ENTRY(-107, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-99, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 0x302, 9, 0),
    OAM_ENTRY(-67, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x306, 9, 0),
    OAM_ENTRY(107, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x300, 9, 0),
    OAM_ENTRY(99, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x301, 9, 0),
    OAM_ENTRY(67, -17, OAM_DIMS_32x8, OAM_X_FLIP, 0x302, 9, 0),
    OAM_ENTRY(59, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-54, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(38, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 9, 0),
    OAM_ENTRY(-40, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(8, -37, OAM_DIMS_32x16, OAM_X_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-128, -24, OAM_DIMS_64x32, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-64, -53, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_64x32, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(0, -53, OAM_DIMS_64x64, OAM_X_FLIP, 0x208, 8, 0)
};

static const u16 sGunshipOam_Idle_Frame1[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-115, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x340, 9, 0),
    OAM_ENTRY(-107, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x341, 9, 0),
    OAM_ENTRY(-99, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 0x342, 9, 0),
    OAM_ENTRY(-67, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x346, 9, 0),
    OAM_ENTRY(107, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x340, 9, 0),
    OAM_ENTRY(99, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x341, 9, 0),
    OAM_ENTRY(67, -17, OAM_DIMS_32x8, OAM_X_FLIP, 0x342, 9, 0),
    OAM_ENTRY(59, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x346, 9, 0),
    OAM_ENTRY(-54, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x242, 9, 0),
    OAM_ENTRY(38, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x242, 9, 0),
    OAM_ENTRY(-40, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(8, -37, OAM_DIMS_32x16, OAM_X_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-128, -24, OAM_DIMS_64x32, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-64, -53, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_64x32, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(0, -53, OAM_DIMS_64x64, OAM_X_FLIP, 0x208, 8, 0)
};

static const u16 sGunshipOam_Idle_Frame2[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-115, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-107, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x308, 9, 0),
    OAM_ENTRY(-99, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 0x309, 9, 0),
    OAM_ENTRY(-67, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(107, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x307, 9, 0),
    OAM_ENTRY(99, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x308, 9, 0),
    OAM_ENTRY(67, -17, OAM_DIMS_32x8, OAM_X_FLIP, 0x309, 9, 0),
    OAM_ENTRY(59, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(-54, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(38, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-40, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(8, -37, OAM_DIMS_32x16, OAM_X_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-128, -24, OAM_DIMS_64x32, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-64, -53, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_64x32, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(0, -53, OAM_DIMS_64x64, OAM_X_FLIP, 0x208, 8, 0)
};

static const u16 sGunshipOam_Idle_Frame3[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-115, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x347, 9, 0),
    OAM_ENTRY(-107, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x348, 9, 0),
    OAM_ENTRY(-99, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 0x349, 9, 0),
    OAM_ENTRY(-67, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x34d, 9, 0),
    OAM_ENTRY(107, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x347, 9, 0),
    OAM_ENTRY(99, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x348, 9, 0),
    OAM_ENTRY(67, -17, OAM_DIMS_32x8, OAM_X_FLIP, 0x349, 9, 0),
    OAM_ENTRY(59, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x34d, 9, 0),
    OAM_ENTRY(-54, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(38, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-40, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(8, -37, OAM_DIMS_32x16, OAM_X_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-128, -24, OAM_DIMS_64x32, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-64, -53, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_64x32, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(0, -53, OAM_DIMS_64x64, OAM_X_FLIP, 0x208, 8, 0)
};

static const u16 sGunshipPartOam_EntranceFrontClosed_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-30, -49, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(14, -49, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0)
};

static const u16 sGunshipPartOam_EntranceFrontOpening_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-31, -50, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(15, -50, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0)
};

static const u16 sGunshipPartOam_EntranceFrontOpening_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0)
};

static const u16 sGunshipPartOam_EntranceFrontOpening_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-33, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(17, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0)
};

static const u16 sGunshipPartOam_EntranceFrontOpening_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-35, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(19, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0)
};

static const u16 sGunshipPartOam_EntranceFrontOpened_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-26, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 9, 0),
    OAM_ENTRY(18, -46, OAM_DIMS_8x8, OAM_X_FLIP, 0x21a, 9, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-34, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(18, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0)
};

static const u16 sGunshipPartOam_EntranceFrontOpened_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-26, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 9, 0),
    OAM_ENTRY(18, -46, OAM_DIMS_8x8, OAM_X_FLIP, 0x23a, 9, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-34, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(18, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0)
};

static const u16 sGunshipPartOam_EntranceFrontOpened_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-26, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25a, 9, 0),
    OAM_ENTRY(18, -46, OAM_DIMS_8x8, OAM_X_FLIP, 0x25a, 9, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-34, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(18, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0)
};

static const u16 sGunshipPartOam_EntranceFrontOpened_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-26, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27a, 9, 0),
    OAM_ENTRY(18, -46, OAM_DIMS_8x8, OAM_X_FLIP, 0x27a, 9, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-34, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(18, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x206, 8, 0)
};

static const u16 sGunshipPartOam_EntranceBackCLosed_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(8, -53, OAM_DIMS_16x16, OAM_X_FLIP, 0x290, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d8, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x2d8, 8, 0)
};

static const u16 sGunshipPartOam_EntranceBackOpening_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -54, OAM_DIMS_32x16, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(8, -54, OAM_DIMS_16x16, OAM_X_FLIP, 0x290, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d8, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x2d8, 8, 0)
};

static const u16 sGunshipPartOam_EntranceBackOpening_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -56, OAM_DIMS_32x16, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(8, -56, OAM_DIMS_16x16, OAM_X_FLIP, 0x290, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d8, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x2d8, 8, 0)
};

static const u16 sGunshipPartOam_EntranceBackOpening_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -58, OAM_DIMS_32x16, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(8, -58, OAM_DIMS_16x16, OAM_X_FLIP, 0x290, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d8, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x2d8, 8, 0)
};

static const u16 sGunshipPartOam_EntranceBackOpening_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -60, OAM_DIMS_32x16, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(8, -60, OAM_DIMS_16x16, OAM_X_FLIP, 0x290, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d8, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x2d8, 8, 0)
};

static const u16 sGunshipPartOam_EntranceBackOpening_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -59, OAM_DIMS_32x16, OAM_NO_FLIP, 0x290, 8, 0),
    OAM_ENTRY(8, -59, OAM_DIMS_16x16, OAM_X_FLIP, 0x290, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d8, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x2d8, 8, 0)
};

static const u16 sGunshipPartOam_EntranceBackOpening_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -61, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(8, -61, OAM_DIMS_16x16, OAM_X_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d8, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x2d8, 8, 0)
};

static const u16 sGunshipPartOam_EntranceBackOpening_Frame6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -61, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(8, -61, OAM_DIMS_16x16, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d8, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x2d8, 8, 0)
};

static const u16 sGunshipPartOam_EntranceBackOpening_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -60, OAM_DIMS_32x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(8, -60, OAM_DIMS_16x16, OAM_X_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d8, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x2d8, 8, 0)
};

static const u16 sGunshipPartOam_EntranceBackOpened_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -57, OAM_DIMS_16x8, OAM_NO_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-4, -57, OAM_DIMS_8x8, OAM_NO_FLIP, 0x219, 9, 0),
    OAM_ENTRY(1, -57, OAM_DIMS_16x8, OAM_X_FLIP, 0x218, 9, 0),
    OAM_ENTRY(-24, -60, OAM_DIMS_32x16, OAM_NO_FLIP, 0x294, 8, 0),
    OAM_ENTRY(8, -60, OAM_DIMS_16x16, OAM_X_FLIP, 0x294, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d8, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x2d8, 8, 0)
};

static const u16 sGunshipPartOam_EntranceBackOpened_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -57, OAM_DIMS_16x8, OAM_NO_FLIP, 0x238, 9, 0),
    OAM_ENTRY(-4, -57, OAM_DIMS_8x8, OAM_NO_FLIP, 0x239, 9, 0),
    OAM_ENTRY(1, -57, OAM_DIMS_16x8, OAM_X_FLIP, 0x238, 9, 0),
    OAM_ENTRY(-24, -60, OAM_DIMS_32x16, OAM_NO_FLIP, 0x294, 8, 0),
    OAM_ENTRY(8, -60, OAM_DIMS_16x16, OAM_X_FLIP, 0x294, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d8, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x2d8, 8, 0)
};

static const u16 sGunshipPartOam_EntranceBackOpened_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -57, OAM_DIMS_16x8, OAM_NO_FLIP, 0x258, 9, 0),
    OAM_ENTRY(-4, -57, OAM_DIMS_8x8, OAM_NO_FLIP, 0x259, 9, 0),
    OAM_ENTRY(1, -57, OAM_DIMS_16x8, OAM_X_FLIP, 0x258, 9, 0),
    OAM_ENTRY(-24, -60, OAM_DIMS_32x16, OAM_NO_FLIP, 0x294, 8, 0),
    OAM_ENTRY(8, -60, OAM_DIMS_16x16, OAM_X_FLIP, 0x294, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d8, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x2d8, 8, 0)
};

static const u16 sGunshipPartOam_EntranceBackOpened_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -57, OAM_DIMS_16x8, OAM_NO_FLIP, 0x278, 9, 0),
    OAM_ENTRY(-4, -57, OAM_DIMS_8x8, OAM_NO_FLIP, 0x279, 9, 0),
    OAM_ENTRY(1, -57, OAM_DIMS_16x8, OAM_X_FLIP, 0x278, 9, 0),
    OAM_ENTRY(-24, -60, OAM_DIMS_32x16, OAM_NO_FLIP, 0x294, 8, 0),
    OAM_ENTRY(8, -60, OAM_DIMS_16x16, OAM_X_FLIP, 0x294, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d8, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 0x2d8, 8, 0)
};

static const u16 sGunshipPartOam_Platform_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2d4, 9, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_16x8, OAM_X_FLIP, 0x2d4, 9, 0)
};

static const u16 sGunshipPartOam_Platform_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f4, 9, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_16x8, OAM_X_FLIP, 0x2f4, 9, 0)
};

static const u16 sGunshipPartOam_Platform_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2d6, 9, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_16x8, OAM_X_FLIP, 0x2d6, 9, 0)
};

static const u16 sGunshipPartOam_Platform_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f6, 9, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_16x8, OAM_X_FLIP, 0x2f6, 9, 0)
};

static const u16 sGunshipOam_Flying_Frame0[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(-115, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x300, 9, 0),
    OAM_ENTRY(-107, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x301, 9, 0),
    OAM_ENTRY(-99, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 0x302, 9, 0),
    OAM_ENTRY(-67, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x306, 9, 0),
    OAM_ENTRY(107, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x300, 9, 0),
    OAM_ENTRY(99, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x301, 9, 0),
    OAM_ENTRY(67, -17, OAM_DIMS_32x8, OAM_X_FLIP, 0x302, 9, 0),
    OAM_ENTRY(59, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x306, 9, 0),
    OAM_ENTRY(-54, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(38, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 9, 0),
    OAM_ENTRY(-40, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(8, -37, OAM_DIMS_32x16, OAM_X_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-128, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-96, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x284, 8, 0),
    OAM_ENTRY(-64, -45, OAM_DIMS_64x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-128, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x30e, 10, 0),
    OAM_ENTRY(-96, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x312, 10, 0),
    OAM_ENTRY(-64, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x34e, 10, 0),
    OAM_ENTRY(-32, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x352, 10, 0),
    OAM_ENTRY(96, -24, OAM_DIMS_32x16, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_32x16, OAM_X_FLIP, 0x284, 8, 0),
    OAM_ENTRY(0, -45, OAM_DIMS_64x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(96, -8, OAM_DIMS_32x16, OAM_X_FLIP, 0x30e, 10, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_32x16, OAM_X_FLIP, 0x312, 10, 0),
    OAM_ENTRY(32, -13, OAM_DIMS_32x16, OAM_X_FLIP, 0x34e, 10, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_32x16, OAM_X_FLIP, 0x352, 10, 0)
};

static const u16 sGunshipOam_Flying_Frame1[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(-115, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x340, 9, 0),
    OAM_ENTRY(-107, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x341, 9, 0),
    OAM_ENTRY(-99, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 0x342, 9, 0),
    OAM_ENTRY(-67, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x346, 9, 0),
    OAM_ENTRY(107, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x340, 9, 0),
    OAM_ENTRY(99, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x341, 9, 0),
    OAM_ENTRY(67, -17, OAM_DIMS_32x8, OAM_X_FLIP, 0x342, 9, 0),
    OAM_ENTRY(59, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x346, 9, 0),
    OAM_ENTRY(-54, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x242, 9, 0),
    OAM_ENTRY(38, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x242, 9, 0),
    OAM_ENTRY(-40, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(8, -37, OAM_DIMS_32x16, OAM_X_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-128, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-96, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x284, 8, 0),
    OAM_ENTRY(-64, -45, OAM_DIMS_64x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-128, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x30e, 10, 0),
    OAM_ENTRY(-96, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x312, 10, 0),
    OAM_ENTRY(-64, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x34e, 10, 0),
    OAM_ENTRY(-32, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x352, 10, 0),
    OAM_ENTRY(96, -24, OAM_DIMS_32x16, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_32x16, OAM_X_FLIP, 0x284, 8, 0),
    OAM_ENTRY(0, -45, OAM_DIMS_64x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(96, -8, OAM_DIMS_32x16, OAM_X_FLIP, 0x30e, 10, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_32x16, OAM_X_FLIP, 0x312, 10, 0),
    OAM_ENTRY(32, -13, OAM_DIMS_32x16, OAM_X_FLIP, 0x34e, 10, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_32x16, OAM_X_FLIP, 0x352, 10, 0)
};

static const u16 sGunshipOam_Flying_Frame2[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(-115, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x307, 9, 0),
    OAM_ENTRY(-107, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x308, 9, 0),
    OAM_ENTRY(-99, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 0x309, 9, 0),
    OAM_ENTRY(-67, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(107, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x307, 9, 0),
    OAM_ENTRY(99, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x308, 9, 0),
    OAM_ENTRY(67, -17, OAM_DIMS_32x8, OAM_X_FLIP, 0x309, 9, 0),
    OAM_ENTRY(59, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x30d, 9, 0),
    OAM_ENTRY(-54, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(38, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-40, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(8, -37, OAM_DIMS_32x16, OAM_X_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-128, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-96, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x284, 8, 0),
    OAM_ENTRY(-64, -45, OAM_DIMS_64x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-128, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x30e, 10, 0),
    OAM_ENTRY(-96, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x312, 10, 0),
    OAM_ENTRY(-64, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x34e, 10, 0),
    OAM_ENTRY(-32, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x352, 10, 0),
    OAM_ENTRY(96, -24, OAM_DIMS_32x16, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_32x16, OAM_X_FLIP, 0x284, 8, 0),
    OAM_ENTRY(0, -45, OAM_DIMS_64x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(96, -8, OAM_DIMS_32x16, OAM_X_FLIP, 0x30e, 10, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_32x16, OAM_X_FLIP, 0x312, 10, 0),
    OAM_ENTRY(32, -13, OAM_DIMS_32x16, OAM_X_FLIP, 0x34e, 10, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_32x16, OAM_X_FLIP, 0x352, 10, 0)
};

static const u16 sGunshipOam_Flying_Frame3[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(-115, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x347, 9, 0),
    OAM_ENTRY(-107, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x348, 9, 0),
    OAM_ENTRY(-99, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 0x349, 9, 0),
    OAM_ENTRY(-67, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x34d, 9, 0),
    OAM_ENTRY(107, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x347, 9, 0),
    OAM_ENTRY(99, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x348, 9, 0),
    OAM_ENTRY(67, -17, OAM_DIMS_32x8, OAM_X_FLIP, 0x349, 9, 0),
    OAM_ENTRY(59, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x34d, 9, 0),
    OAM_ENTRY(-54, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(38, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-40, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(8, -37, OAM_DIMS_32x16, OAM_X_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-128, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-96, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x284, 8, 0),
    OAM_ENTRY(-64, -45, OAM_DIMS_64x32, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-128, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x30e, 10, 0),
    OAM_ENTRY(-96, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x312, 10, 0),
    OAM_ENTRY(-64, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x34e, 10, 0),
    OAM_ENTRY(-32, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x352, 10, 0),
    OAM_ENTRY(96, -24, OAM_DIMS_32x16, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_32x16, OAM_X_FLIP, 0x284, 8, 0),
    OAM_ENTRY(0, -45, OAM_DIMS_64x32, OAM_X_FLIP, 0x228, 8, 0),
    OAM_ENTRY(96, -8, OAM_DIMS_32x16, OAM_X_FLIP, 0x30e, 10, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_32x16, OAM_X_FLIP, 0x312, 10, 0),
    OAM_ENTRY(32, -13, OAM_DIMS_32x16, OAM_X_FLIP, 0x34e, 10, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_32x16, OAM_X_FLIP, 0x352, 10, 0)
};

static const u16 sGunshipPartOam_FlamesHorizontal_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-88, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x356, 9, 0),
    OAM_ENTRY(-56, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x356, 9, 0),
    OAM_ENTRY(-88, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x356, 9, 0),
    OAM_ENTRY(-56, 4, OAM_DIMS_16x8, OAM_XY_FLIP, 0x356, 9, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x356, 9, 0),
    OAM_ENTRY(72, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x356, 9, 0),
    OAM_ENTRY(40, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x356, 9, 0),
    OAM_ENTRY(72, 4, OAM_DIMS_16x8, OAM_XY_FLIP, 0x356, 9, 0)
};

static const u16 sGunshipPartOam_FlamesHorizontal_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-96, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x316, 9, 0),
    OAM_ENTRY(-96, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x316, 9, 0),
    OAM_ENTRY(-64, -12, OAM_DIMS_32x16, OAM_X_FLIP, 0x316, 9, 0),
    OAM_ENTRY(-64, 4, OAM_DIMS_32x8, OAM_XY_FLIP, 0x316, 9, 0),
    OAM_ENTRY(32, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x316, 9, 0),
    OAM_ENTRY(32, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 0x316, 9, 0),
    OAM_ENTRY(64, -12, OAM_DIMS_32x16, OAM_X_FLIP, 0x316, 9, 0),
    OAM_ENTRY(64, 4, OAM_DIMS_32x8, OAM_XY_FLIP, 0x316, 9, 0)
};

static const u16 sGunshipPartOam_FlamesHorizontal_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x280, 8, 0)
};

static const u16 sGunshipPartOam_FlamesVertical_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-94, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2da, 9, 0),
    OAM_ENTRY(-66, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2da, 9, 0),
    OAM_ENTRY(62, -8, OAM_DIMS_32x16, OAM_X_FLIP, 0x2da, 9, 0),
    OAM_ENTRY(34, -12, OAM_DIMS_32x16, OAM_X_FLIP, 0x2da, 9, 0)
};

static const u16 sGunshipPartOam_FlamesVertical_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-90, -4, OAM_DIMS_16x32, OAM_NO_FLIP, 0x31a, 9, 0),
    OAM_ENTRY(-74, -4, OAM_DIMS_8x32, OAM_X_FLIP, 0x31a, 9, 0),
    OAM_ENTRY(-62, -8, OAM_DIMS_16x32, OAM_NO_FLIP, 0x31a, 9, 0),
    OAM_ENTRY(-46, -8, OAM_DIMS_8x32, OAM_X_FLIP, 0x31a, 9, 0),
    OAM_ENTRY(74, -4, OAM_DIMS_16x32, OAM_X_FLIP, 0x31a, 9, 0),
    OAM_ENTRY(66, -4, OAM_DIMS_8x32, OAM_NO_FLIP, 0x31a, 9, 0),
    OAM_ENTRY(46, -8, OAM_DIMS_16x32, OAM_X_FLIP, 0x31a, 9, 0),
    OAM_ENTRY(38, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x31a, 9, 0)
};

static const u16 sGunshipPartOam_FlamesVertical_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-86, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x29e, 9, 0),
    OAM_ENTRY(-86, 16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x31e, 9, 0),
    OAM_ENTRY(-58, -20, OAM_DIMS_16x32, OAM_NO_FLIP, 0x29e, 9, 0),
    OAM_ENTRY(-58, 12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x31e, 9, 0),
    OAM_ENTRY(70, -16, OAM_DIMS_16x32, OAM_X_FLIP, 0x29e, 9, 0),
    OAM_ENTRY(70, 16, OAM_DIMS_16x32, OAM_X_FLIP, 0x31e, 9, 0),
    OAM_ENTRY(42, -20, OAM_DIMS_16x32, OAM_X_FLIP, 0x29e, 9, 0),
    OAM_ENTRY(42, 12, OAM_DIMS_16x32, OAM_X_FLIP, 0x31e, 9, 0)
};

const struct FrameData sGunshipOam_Idle[7] = {
    [0] = {
        .pFrame = sGunshipOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sGunshipOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sGunshipOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [3] = {
        .pFrame = sGunshipOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = {
        .pFrame = sGunshipOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [5] = {
        .pFrame = sGunshipOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGunshipOam_Refilling[7] = {
    [0] = {
        .pFrame = sGunshipOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGunshipOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sGunshipOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sGunshipOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sGunshipOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sGunshipOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGunshipPartOam_EntranceFrontClosed[2] = {
    [0] = {
        .pFrame = sGunshipPartOam_EntranceFrontClosed_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGunshipPartOam_EntranceFrontOpening[5] = {
    [0] = {
        .pFrame = sGunshipPartOam_EntranceFrontOpening_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sGunshipPartOam_EntranceFrontOpening_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sGunshipPartOam_EntranceFrontOpening_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sGunshipPartOam_EntranceFrontOpening_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGunshipPartOam_EntranceFrontOpened[7] = {
    [0] = {
        .pFrame = sGunshipPartOam_EntranceFrontOpened_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sGunshipPartOam_EntranceFrontOpened_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sGunshipPartOam_EntranceFrontOpened_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [3] = {
        .pFrame = sGunshipPartOam_EntranceFrontOpened_Frame3,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = {
        .pFrame = sGunshipPartOam_EntranceFrontOpened_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [5] = {
        .pFrame = sGunshipPartOam_EntranceFrontOpened_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGunshipPartOam_EntranceFrontClosing[6] = {
    [0] = {
        .pFrame = sGunshipPartOam_EntranceFrontOpened_Frame0,
        .timer = CONVERT_SECONDS(7.f / 15)
    },
    [1] = {
        .pFrame = sGunshipPartOam_EntranceFrontOpening_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sGunshipPartOam_EntranceFrontOpening_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sGunshipPartOam_EntranceFrontOpening_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sGunshipPartOam_EntranceFrontOpening_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGunshipPartOam_EntranceBackClosed[2] = {
    [0] = {
        .pFrame = sGunshipPartOam_EntranceBackCLosed_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGunshipPartOam_EntranceBackOpening[9] = {
    [0] = {
        .pFrame = sGunshipPartOam_EntranceBackOpening_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sGunshipPartOam_EntranceBackOpening_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sGunshipPartOam_EntranceBackOpening_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sGunshipPartOam_EntranceBackOpening_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sGunshipPartOam_EntranceBackOpening_Frame4,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [5] = {
        .pFrame = sGunshipPartOam_EntranceBackOpening_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sGunshipPartOam_EntranceBackOpening_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sGunshipPartOam_EntranceBackOpening_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGunshipPartOam_EntranceBackOpened[7] = {
    [0] = {
        .pFrame = sGunshipPartOam_EntranceBackOpened_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sGunshipPartOam_EntranceBackOpened_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sGunshipPartOam_EntranceBackOpened_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [3] = {
        .pFrame = sGunshipPartOam_EntranceBackOpened_Frame3,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = {
        .pFrame = sGunshipPartOam_EntranceBackOpened_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [5] = {
        .pFrame = sGunshipPartOam_EntranceBackOpened_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGunshipPartOam_EntranceBackClosing[9] = {
    [0] = {
        .pFrame = sGunshipPartOam_EntranceBackOpening_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGunshipPartOam_EntranceBackOpening_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sGunshipPartOam_EntranceBackOpening_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sGunshipPartOam_EntranceBackOpening_Frame4,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = {
        .pFrame = sGunshipPartOam_EntranceBackOpening_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sGunshipPartOam_EntranceBackOpening_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sGunshipPartOam_EntranceBackOpening_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sGunshipPartOam_EntranceBackOpening_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGunshipPartOam_Platform[5] = {
    [0] = {
        .pFrame = sGunshipPartOam_Platform_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sGunshipPartOam_Platform_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sGunshipPartOam_Platform_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sGunshipPartOam_Platform_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGunshipOam_Flying[7] = {
    [0] = {
        .pFrame = sGunshipOam_Flying_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sGunshipOam_Flying_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sGunshipOam_Flying_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sGunshipOam_Flying_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sGunshipOam_Flying_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sGunshipOam_Flying_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGunshipPartOam_FlamesHorizontal[4] = {
    [0] = {
        .pFrame = sGunshipPartOam_FlamesHorizontal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sGunshipPartOam_FlamesHorizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sGunshipPartOam_FlamesHorizontal_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGunshipPartOam_FlamesVertical[4] = {
    [0] = {
        .pFrame = sGunshipPartOam_FlamesVertical_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sGunshipPartOam_FlamesVertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sGunshipPartOam_FlamesVertical_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};
