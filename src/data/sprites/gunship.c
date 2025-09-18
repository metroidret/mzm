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

const u32 sGunshipGfx[1027] = INCBIN_U32("data/sprites/Gunship.gfx.lz");
const u16 sGunshipPal[48] = INCBIN_U16("data/sprites/Gunship.pal");
const u16 sGunshipFlashingPal[8 * 16] = INCBIN_U16("data/sprites/GunshipFlashingPal.pal");

static const u16 sGunshipOam_Idle_Frame0[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-115, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 768, 9, 0),
    OAM_ENTRY(-107, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 769, 9, 0),
    OAM_ENTRY(-99, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 770, 9, 0),
    OAM_ENTRY(-67, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 774, 9, 0),
    OAM_ENTRY(107, -8, OAM_DIMS_8x16, OAM_X_FLIP, 768, 9, 0),
    OAM_ENTRY(99, -12, OAM_DIMS_8x8, OAM_X_FLIP, 769, 9, 0),
    OAM_ENTRY(67, -17, OAM_DIMS_32x8, OAM_X_FLIP, 770, 9, 0),
    OAM_ENTRY(59, -17, OAM_DIMS_8x8, OAM_X_FLIP, 774, 9, 0),
    OAM_ENTRY(-54, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 576, 9, 0),
    OAM_ENTRY(38, -21, OAM_DIMS_16x16, OAM_X_FLIP, 576, 9, 0),
    OAM_ENTRY(-40, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(8, -37, OAM_DIMS_32x16, OAM_X_FLIP, 512, 9, 0),
    OAM_ENTRY(-128, -24, OAM_DIMS_64x32, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-64, -53, OAM_DIMS_64x64, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_64x32, OAM_X_FLIP, 640, 8, 0),
    OAM_ENTRY(0, -53, OAM_DIMS_64x64, OAM_X_FLIP, 520, 8, 0),
};

static const u16 sGunshipOam_Idle_Frame1[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-115, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 832, 9, 0),
    OAM_ENTRY(-107, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 833, 9, 0),
    OAM_ENTRY(-99, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 834, 9, 0),
    OAM_ENTRY(-67, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 838, 9, 0),
    OAM_ENTRY(107, -8, OAM_DIMS_8x16, OAM_X_FLIP, 832, 9, 0),
    OAM_ENTRY(99, -12, OAM_DIMS_8x8, OAM_X_FLIP, 833, 9, 0),
    OAM_ENTRY(67, -17, OAM_DIMS_32x8, OAM_X_FLIP, 834, 9, 0),
    OAM_ENTRY(59, -17, OAM_DIMS_8x8, OAM_X_FLIP, 838, 9, 0),
    OAM_ENTRY(-54, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 578, 9, 0),
    OAM_ENTRY(38, -21, OAM_DIMS_16x16, OAM_X_FLIP, 578, 9, 0),
    OAM_ENTRY(-40, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(8, -37, OAM_DIMS_32x16, OAM_X_FLIP, 512, 9, 0),
    OAM_ENTRY(-128, -24, OAM_DIMS_64x32, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-64, -53, OAM_DIMS_64x64, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_64x32, OAM_X_FLIP, 640, 8, 0),
    OAM_ENTRY(0, -53, OAM_DIMS_64x64, OAM_X_FLIP, 520, 8, 0),
};

static const u16 sGunshipOam_Idle_Frame2[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-115, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 775, 9, 0),
    OAM_ENTRY(-107, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 776, 9, 0),
    OAM_ENTRY(-99, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 777, 9, 0),
    OAM_ENTRY(-67, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 781, 9, 0),
    OAM_ENTRY(107, -8, OAM_DIMS_8x16, OAM_X_FLIP, 775, 9, 0),
    OAM_ENTRY(99, -12, OAM_DIMS_8x8, OAM_X_FLIP, 776, 9, 0),
    OAM_ENTRY(67, -17, OAM_DIMS_32x8, OAM_X_FLIP, 777, 9, 0),
    OAM_ENTRY(59, -17, OAM_DIMS_8x8, OAM_X_FLIP, 781, 9, 0),
    OAM_ENTRY(-54, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 580, 9, 0),
    OAM_ENTRY(38, -21, OAM_DIMS_16x16, OAM_X_FLIP, 580, 9, 0),
    OAM_ENTRY(-40, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(8, -37, OAM_DIMS_32x16, OAM_X_FLIP, 512, 9, 0),
    OAM_ENTRY(-128, -24, OAM_DIMS_64x32, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-64, -53, OAM_DIMS_64x64, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_64x32, OAM_X_FLIP, 640, 8, 0),
    OAM_ENTRY(0, -53, OAM_DIMS_64x64, OAM_X_FLIP, 520, 8, 0),
};

static const u16 sGunshipOam_Idle_Frame3[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-115, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 839, 9, 0),
    OAM_ENTRY(-107, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 840, 9, 0),
    OAM_ENTRY(-99, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 841, 9, 0),
    OAM_ENTRY(-67, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 845, 9, 0),
    OAM_ENTRY(107, -8, OAM_DIMS_8x16, OAM_X_FLIP, 839, 9, 0),
    OAM_ENTRY(99, -12, OAM_DIMS_8x8, OAM_X_FLIP, 840, 9, 0),
    OAM_ENTRY(67, -17, OAM_DIMS_32x8, OAM_X_FLIP, 841, 9, 0),
    OAM_ENTRY(59, -17, OAM_DIMS_8x8, OAM_X_FLIP, 845, 9, 0),
    OAM_ENTRY(-54, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 582, 9, 0),
    OAM_ENTRY(38, -21, OAM_DIMS_16x16, OAM_X_FLIP, 582, 9, 0),
    OAM_ENTRY(-40, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(8, -37, OAM_DIMS_32x16, OAM_X_FLIP, 512, 9, 0),
    OAM_ENTRY(-128, -24, OAM_DIMS_64x32, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-64, -53, OAM_DIMS_64x64, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_64x32, OAM_X_FLIP, 640, 8, 0),
    OAM_ENTRY(0, -53, OAM_DIMS_64x64, OAM_X_FLIP, 520, 8, 0),
};

static const u16 sGunshipPartOam_EntranceFrontClosed_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 528, 8, 0),
    OAM_ENTRY(-30, -49, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(14, -49, OAM_DIMS_16x16, OAM_X_FLIP, 518, 8, 0),
};

static const u16 sGunshipPartOam_EntranceFrontOpening_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 528, 8, 0),
    OAM_ENTRY(-31, -50, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(15, -50, OAM_DIMS_16x16, OAM_X_FLIP, 518, 8, 0),
};

static const u16 sGunshipPartOam_EntranceFrontOpening_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 528, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 518, 8, 0),
};

static const u16 sGunshipPartOam_EntranceFrontOpening_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 528, 8, 0),
    OAM_ENTRY(-33, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(17, -51, OAM_DIMS_16x16, OAM_X_FLIP, 518, 8, 0),
};

static const u16 sGunshipPartOam_EntranceFrontOpening_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 528, 8, 0),
    OAM_ENTRY(-35, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(19, -51, OAM_DIMS_16x16, OAM_X_FLIP, 518, 8, 0),
};

static const u16 sGunshipPartOam_EntranceFrontOpened_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-26, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 538, 9, 0),
    OAM_ENTRY(18, -46, OAM_DIMS_8x8, OAM_X_FLIP, 538, 9, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 528, 8, 0),
    OAM_ENTRY(-34, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(18, -51, OAM_DIMS_16x16, OAM_X_FLIP, 518, 8, 0),
};

static const u16 sGunshipPartOam_EntranceFrontOpened_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-26, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 570, 9, 0),
    OAM_ENTRY(18, -46, OAM_DIMS_8x8, OAM_X_FLIP, 570, 9, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 528, 8, 0),
    OAM_ENTRY(-34, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(18, -51, OAM_DIMS_16x16, OAM_X_FLIP, 518, 8, 0),
};

static const u16 sGunshipPartOam_EntranceFrontOpened_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-26, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 602, 9, 0),
    OAM_ENTRY(18, -46, OAM_DIMS_8x8, OAM_X_FLIP, 602, 9, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 528, 8, 0),
    OAM_ENTRY(-34, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(18, -51, OAM_DIMS_16x16, OAM_X_FLIP, 518, 8, 0),
};

static const u16 sGunshipPartOam_EntranceFrontOpened_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-26, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 634, 9, 0),
    OAM_ENTRY(18, -46, OAM_DIMS_8x8, OAM_X_FLIP, 634, 9, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_X_FLIP, 528, 8, 0),
    OAM_ENTRY(-34, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(18, -51, OAM_DIMS_16x16, OAM_X_FLIP, 518, 8, 0),
};

static const u16 sGunshipPartOam_EntranceBackCLosed_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 656, 8, 0),
    OAM_ENTRY(8, -53, OAM_DIMS_16x16, OAM_X_FLIP, 656, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 728, 8, 0),
};

static const u16 sGunshipPartOam_EntranceBackOpening_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -54, OAM_DIMS_32x16, OAM_NO_FLIP, 656, 8, 0),
    OAM_ENTRY(8, -54, OAM_DIMS_16x16, OAM_X_FLIP, 656, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 728, 8, 0),
};

static const u16 sGunshipPartOam_EntranceBackOpening_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -56, OAM_DIMS_32x16, OAM_NO_FLIP, 656, 8, 0),
    OAM_ENTRY(8, -56, OAM_DIMS_16x16, OAM_X_FLIP, 656, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 728, 8, 0),
};

static const u16 sGunshipPartOam_EntranceBackOpening_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -58, OAM_DIMS_32x16, OAM_NO_FLIP, 656, 8, 0),
    OAM_ENTRY(8, -58, OAM_DIMS_16x16, OAM_X_FLIP, 656, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 728, 8, 0),
};

static const u16 sGunshipPartOam_EntranceBackOpening_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -60, OAM_DIMS_32x16, OAM_NO_FLIP, 656, 8, 0),
    OAM_ENTRY(8, -60, OAM_DIMS_16x16, OAM_X_FLIP, 656, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 728, 8, 0),
};

static const u16 sGunshipPartOam_EntranceBackOpening_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -59, OAM_DIMS_32x16, OAM_NO_FLIP, 656, 8, 0),
    OAM_ENTRY(8, -59, OAM_DIMS_16x16, OAM_X_FLIP, 656, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 728, 8, 0),
};

static const u16 sGunshipPartOam_EntranceBackOpening_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -61, OAM_DIMS_32x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(8, -61, OAM_DIMS_16x16, OAM_X_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 728, 8, 0),
};

static const u16 sGunshipPartOam_EntranceBackOpening_Frame6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -61, OAM_DIMS_32x16, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(8, -61, OAM_DIMS_16x16, OAM_X_FLIP, 532, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 728, 8, 0),
};

static const u16 sGunshipPartOam_EntranceBackOpening_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -60, OAM_DIMS_32x16, OAM_NO_FLIP, 596, 8, 0),
    OAM_ENTRY(8, -60, OAM_DIMS_16x16, OAM_X_FLIP, 596, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 728, 8, 0),
};

static const u16 sGunshipPartOam_EntranceBackOpened_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -57, OAM_DIMS_16x8, OAM_NO_FLIP, 536, 9, 0),
    OAM_ENTRY(-4, -57, OAM_DIMS_8x8, OAM_NO_FLIP, 537, 9, 0),
    OAM_ENTRY(1, -57, OAM_DIMS_16x8, OAM_X_FLIP, 536, 9, 0),
    OAM_ENTRY(-24, -60, OAM_DIMS_32x16, OAM_NO_FLIP, 660, 8, 0),
    OAM_ENTRY(8, -60, OAM_DIMS_16x16, OAM_X_FLIP, 660, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 728, 8, 0),
};

static const u16 sGunshipPartOam_EntranceBackOpened_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -57, OAM_DIMS_16x8, OAM_NO_FLIP, 568, 9, 0),
    OAM_ENTRY(-4, -57, OAM_DIMS_8x8, OAM_NO_FLIP, 569, 9, 0),
    OAM_ENTRY(1, -57, OAM_DIMS_16x8, OAM_X_FLIP, 568, 9, 0),
    OAM_ENTRY(-24, -60, OAM_DIMS_32x16, OAM_NO_FLIP, 660, 8, 0),
    OAM_ENTRY(8, -60, OAM_DIMS_16x16, OAM_X_FLIP, 660, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 728, 8, 0),
};

static const u16 sGunshipPartOam_EntranceBackOpened_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -57, OAM_DIMS_16x8, OAM_NO_FLIP, 600, 9, 0),
    OAM_ENTRY(-4, -57, OAM_DIMS_8x8, OAM_NO_FLIP, 601, 9, 0),
    OAM_ENTRY(1, -57, OAM_DIMS_16x8, OAM_X_FLIP, 600, 9, 0),
    OAM_ENTRY(-24, -60, OAM_DIMS_32x16, OAM_NO_FLIP, 660, 8, 0),
    OAM_ENTRY(8, -60, OAM_DIMS_16x16, OAM_X_FLIP, 660, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 728, 8, 0),
};

static const u16 sGunshipPartOam_EntranceBackOpened_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-17, -57, OAM_DIMS_16x8, OAM_NO_FLIP, 632, 9, 0),
    OAM_ENTRY(-4, -57, OAM_DIMS_8x8, OAM_NO_FLIP, 633, 9, 0),
    OAM_ENTRY(1, -57, OAM_DIMS_16x8, OAM_X_FLIP, 632, 9, 0),
    OAM_ENTRY(-24, -60, OAM_DIMS_32x16, OAM_NO_FLIP, 660, 8, 0),
    OAM_ENTRY(8, -60, OAM_DIMS_16x16, OAM_X_FLIP, 660, 8, 0),
    OAM_ENTRY(-16, -53, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(-32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 728, 8, 0),
    OAM_ENTRY(16, -51, OAM_DIMS_16x16, OAM_X_FLIP, 728, 8, 0),
};

static const u16 sGunshipPartOam_Platform_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 724, 9, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_16x8, OAM_X_FLIP, 724, 9, 0),
};

static const u16 sGunshipPartOam_Platform_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 756, 9, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_16x8, OAM_X_FLIP, 756, 9, 0),
};

static const u16 sGunshipPartOam_Platform_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 726, 9, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_16x8, OAM_X_FLIP, 726, 9, 0),
};

static const u16 sGunshipPartOam_Platform_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 758, 9, 0),
    OAM_ENTRY(0, -2, OAM_DIMS_16x8, OAM_X_FLIP, 758, 9, 0),
};

static const u16 sGunshipOam_Flying_Frame0[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(-115, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 768, 9, 0),
    OAM_ENTRY(-107, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 769, 9, 0),
    OAM_ENTRY(-99, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 770, 9, 0),
    OAM_ENTRY(-67, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 774, 9, 0),
    OAM_ENTRY(107, -8, OAM_DIMS_8x16, OAM_X_FLIP, 768, 9, 0),
    OAM_ENTRY(99, -12, OAM_DIMS_8x8, OAM_X_FLIP, 769, 9, 0),
    OAM_ENTRY(67, -17, OAM_DIMS_32x8, OAM_X_FLIP, 770, 9, 0),
    OAM_ENTRY(59, -17, OAM_DIMS_8x8, OAM_X_FLIP, 774, 9, 0),
    OAM_ENTRY(-54, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 576, 9, 0),
    OAM_ENTRY(38, -21, OAM_DIMS_16x16, OAM_X_FLIP, 576, 9, 0),
    OAM_ENTRY(-40, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(8, -37, OAM_DIMS_32x16, OAM_X_FLIP, 512, 9, 0),
    OAM_ENTRY(-128, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-96, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 644, 8, 0),
    OAM_ENTRY(-64, -45, OAM_DIMS_64x32, OAM_NO_FLIP, 552, 8, 0),
    OAM_ENTRY(-128, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 782, 10, 0),
    OAM_ENTRY(-96, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 786, 10, 0),
    OAM_ENTRY(-64, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 846, 10, 0),
    OAM_ENTRY(-32, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 850, 10, 0),
    OAM_ENTRY(96, -24, OAM_DIMS_32x16, OAM_X_FLIP, 640, 8, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_32x16, OAM_X_FLIP, 644, 8, 0),
    OAM_ENTRY(0, -45, OAM_DIMS_64x32, OAM_X_FLIP, 552, 8, 0),
    OAM_ENTRY(96, -8, OAM_DIMS_32x16, OAM_X_FLIP, 782, 10, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_32x16, OAM_X_FLIP, 786, 10, 0),
    OAM_ENTRY(32, -13, OAM_DIMS_32x16, OAM_X_FLIP, 846, 10, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_32x16, OAM_X_FLIP, 850, 10, 0),
};

static const u16 sGunshipOam_Flying_Frame1[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(-115, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 832, 9, 0),
    OAM_ENTRY(-107, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 833, 9, 0),
    OAM_ENTRY(-99, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 834, 9, 0),
    OAM_ENTRY(-67, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 838, 9, 0),
    OAM_ENTRY(107, -8, OAM_DIMS_8x16, OAM_X_FLIP, 832, 9, 0),
    OAM_ENTRY(99, -12, OAM_DIMS_8x8, OAM_X_FLIP, 833, 9, 0),
    OAM_ENTRY(67, -17, OAM_DIMS_32x8, OAM_X_FLIP, 834, 9, 0),
    OAM_ENTRY(59, -17, OAM_DIMS_8x8, OAM_X_FLIP, 838, 9, 0),
    OAM_ENTRY(-54, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 578, 9, 0),
    OAM_ENTRY(38, -21, OAM_DIMS_16x16, OAM_X_FLIP, 578, 9, 0),
    OAM_ENTRY(-40, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(8, -37, OAM_DIMS_32x16, OAM_X_FLIP, 512, 9, 0),
    OAM_ENTRY(-128, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-96, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 644, 8, 0),
    OAM_ENTRY(-64, -45, OAM_DIMS_64x32, OAM_NO_FLIP, 552, 8, 0),
    OAM_ENTRY(-128, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 782, 10, 0),
    OAM_ENTRY(-96, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 786, 10, 0),
    OAM_ENTRY(-64, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 846, 10, 0),
    OAM_ENTRY(-32, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 850, 10, 0),
    OAM_ENTRY(96, -24, OAM_DIMS_32x16, OAM_X_FLIP, 640, 8, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_32x16, OAM_X_FLIP, 644, 8, 0),
    OAM_ENTRY(0, -45, OAM_DIMS_64x32, OAM_X_FLIP, 552, 8, 0),
    OAM_ENTRY(96, -8, OAM_DIMS_32x16, OAM_X_FLIP, 782, 10, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_32x16, OAM_X_FLIP, 786, 10, 0),
    OAM_ENTRY(32, -13, OAM_DIMS_32x16, OAM_X_FLIP, 846, 10, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_32x16, OAM_X_FLIP, 850, 10, 0),
};

static const u16 sGunshipOam_Flying_Frame2[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(-115, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 775, 9, 0),
    OAM_ENTRY(-107, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 776, 9, 0),
    OAM_ENTRY(-99, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 777, 9, 0),
    OAM_ENTRY(-67, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 781, 9, 0),
    OAM_ENTRY(107, -8, OAM_DIMS_8x16, OAM_X_FLIP, 775, 9, 0),
    OAM_ENTRY(99, -12, OAM_DIMS_8x8, OAM_X_FLIP, 776, 9, 0),
    OAM_ENTRY(67, -17, OAM_DIMS_32x8, OAM_X_FLIP, 777, 9, 0),
    OAM_ENTRY(59, -17, OAM_DIMS_8x8, OAM_X_FLIP, 781, 9, 0),
    OAM_ENTRY(-54, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 580, 9, 0),
    OAM_ENTRY(38, -21, OAM_DIMS_16x16, OAM_X_FLIP, 580, 9, 0),
    OAM_ENTRY(-40, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(8, -37, OAM_DIMS_32x16, OAM_X_FLIP, 512, 9, 0),
    OAM_ENTRY(-128, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-96, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 644, 8, 0),
    OAM_ENTRY(-64, -45, OAM_DIMS_64x32, OAM_NO_FLIP, 552, 8, 0),
    OAM_ENTRY(-128, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 782, 10, 0),
    OAM_ENTRY(-96, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 786, 10, 0),
    OAM_ENTRY(-64, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 846, 10, 0),
    OAM_ENTRY(-32, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 850, 10, 0),
    OAM_ENTRY(96, -24, OAM_DIMS_32x16, OAM_X_FLIP, 640, 8, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_32x16, OAM_X_FLIP, 644, 8, 0),
    OAM_ENTRY(0, -45, OAM_DIMS_64x32, OAM_X_FLIP, 552, 8, 0),
    OAM_ENTRY(96, -8, OAM_DIMS_32x16, OAM_X_FLIP, 782, 10, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_32x16, OAM_X_FLIP, 786, 10, 0),
    OAM_ENTRY(32, -13, OAM_DIMS_32x16, OAM_X_FLIP, 846, 10, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_32x16, OAM_X_FLIP, 850, 10, 0),
};

static const u16 sGunshipOam_Flying_Frame3[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(-115, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 839, 9, 0),
    OAM_ENTRY(-107, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 840, 9, 0),
    OAM_ENTRY(-99, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 841, 9, 0),
    OAM_ENTRY(-67, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 845, 9, 0),
    OAM_ENTRY(107, -8, OAM_DIMS_8x16, OAM_X_FLIP, 839, 9, 0),
    OAM_ENTRY(99, -12, OAM_DIMS_8x8, OAM_X_FLIP, 840, 9, 0),
    OAM_ENTRY(67, -17, OAM_DIMS_32x8, OAM_X_FLIP, 841, 9, 0),
    OAM_ENTRY(59, -17, OAM_DIMS_8x8, OAM_X_FLIP, 845, 9, 0),
    OAM_ENTRY(-54, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 582, 9, 0),
    OAM_ENTRY(38, -21, OAM_DIMS_16x16, OAM_X_FLIP, 582, 9, 0),
    OAM_ENTRY(-40, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(8, -37, OAM_DIMS_32x16, OAM_X_FLIP, 512, 9, 0),
    OAM_ENTRY(-128, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-96, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 644, 8, 0),
    OAM_ENTRY(-64, -45, OAM_DIMS_64x32, OAM_NO_FLIP, 552, 8, 0),
    OAM_ENTRY(-128, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 782, 10, 0),
    OAM_ENTRY(-96, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 786, 10, 0),
    OAM_ENTRY(-64, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 846, 10, 0),
    OAM_ENTRY(-32, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 850, 10, 0),
    OAM_ENTRY(96, -24, OAM_DIMS_32x16, OAM_X_FLIP, 640, 8, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_32x16, OAM_X_FLIP, 644, 8, 0),
    OAM_ENTRY(0, -45, OAM_DIMS_64x32, OAM_X_FLIP, 552, 8, 0),
    OAM_ENTRY(96, -8, OAM_DIMS_32x16, OAM_X_FLIP, 782, 10, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_32x16, OAM_X_FLIP, 786, 10, 0),
    OAM_ENTRY(32, -13, OAM_DIMS_32x16, OAM_X_FLIP, 846, 10, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_32x16, OAM_X_FLIP, 850, 10, 0),
};

static const u16 sGunshipPartOam_FlamesHorizontal_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-88, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 854, 9, 0),
    OAM_ENTRY(-56, -12, OAM_DIMS_16x16, OAM_X_FLIP, 854, 9, 0),
    OAM_ENTRY(-88, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 854, 9, 0),
    OAM_ENTRY(-56, 4, OAM_DIMS_16x8, OAM_XY_FLIP, 854, 9, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 854, 9, 0),
    OAM_ENTRY(72, -12, OAM_DIMS_16x16, OAM_X_FLIP, 854, 9, 0),
    OAM_ENTRY(40, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 854, 9, 0),
    OAM_ENTRY(72, 4, OAM_DIMS_16x8, OAM_XY_FLIP, 854, 9, 0),
};

static const u16 sGunshipPartOam_FlamesHorizontal_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-96, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 790, 9, 0),
    OAM_ENTRY(-96, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 790, 9, 0),
    OAM_ENTRY(-64, -12, OAM_DIMS_32x16, OAM_X_FLIP, 790, 9, 0),
    OAM_ENTRY(-64, 4, OAM_DIMS_32x8, OAM_XY_FLIP, 790, 9, 0),
    OAM_ENTRY(32, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 790, 9, 0),
    OAM_ENTRY(32, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 790, 9, 0),
    OAM_ENTRY(64, -12, OAM_DIMS_32x16, OAM_X_FLIP, 790, 9, 0),
    OAM_ENTRY(64, 4, OAM_DIMS_32x8, OAM_XY_FLIP, 790, 9, 0),
};

static const u16 sGunshipPartOam_FlamesHorizontal_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 640, 8, 0),
};

static const u16 sGunshipPartOam_FlamesVertical_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-94, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 730, 9, 0),
    OAM_ENTRY(-66, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 730, 9, 0),
    OAM_ENTRY(62, -8, OAM_DIMS_32x16, OAM_X_FLIP, 730, 9, 0),
    OAM_ENTRY(34, -12, OAM_DIMS_32x16, OAM_X_FLIP, 730, 9, 0),
};

static const u16 sGunshipPartOam_FlamesVertical_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-90, -4, OAM_DIMS_16x32, OAM_NO_FLIP, 794, 9, 0),
    OAM_ENTRY(-74, -4, OAM_DIMS_8x32, OAM_X_FLIP, 794, 9, 0),
    OAM_ENTRY(-62, -8, OAM_DIMS_16x32, OAM_NO_FLIP, 794, 9, 0),
    OAM_ENTRY(-46, -8, OAM_DIMS_8x32, OAM_X_FLIP, 794, 9, 0),
    OAM_ENTRY(74, -4, OAM_DIMS_16x32, OAM_X_FLIP, 794, 9, 0),
    OAM_ENTRY(66, -4, OAM_DIMS_8x32, OAM_NO_FLIP, 794, 9, 0),
    OAM_ENTRY(46, -8, OAM_DIMS_16x32, OAM_X_FLIP, 794, 9, 0),
    OAM_ENTRY(38, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 794, 9, 0),
};

static const u16 sGunshipPartOam_FlamesVertical_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-86, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 670, 9, 0),
    OAM_ENTRY(-86, 16, OAM_DIMS_16x32, OAM_NO_FLIP, 798, 9, 0),
    OAM_ENTRY(-58, -20, OAM_DIMS_16x32, OAM_NO_FLIP, 670, 9, 0),
    OAM_ENTRY(-58, 12, OAM_DIMS_16x32, OAM_NO_FLIP, 798, 9, 0),
    OAM_ENTRY(70, -16, OAM_DIMS_16x32, OAM_X_FLIP, 670, 9, 0),
    OAM_ENTRY(70, 16, OAM_DIMS_16x32, OAM_X_FLIP, 798, 9, 0),
    OAM_ENTRY(42, -20, OAM_DIMS_16x32, OAM_X_FLIP, 670, 9, 0),
    OAM_ENTRY(42, 12, OAM_DIMS_16x32, OAM_X_FLIP, 798, 9, 0),
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
