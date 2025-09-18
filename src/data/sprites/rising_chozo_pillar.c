#include "data/sprites/rising_chozo_pillar.h"
#include "macros.h"

const u32 sRisingChozoPillarGfx[671] = INCBIN_U32("data/sprites/RisingChozoPillar.gfx.lz");
const u16 sRisingChozoPillarPal[64] = INCBIN_U16("data/sprites/RisingChozoPillar.pal");

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 532, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame7[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 520, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame8[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame9[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame10[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 532, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame11[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 9, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame12[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 520, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 9, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame13[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 9, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame14[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 9, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame15[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 532, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 9, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame16[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 10, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame17[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 520, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 10, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame18[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 10, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame19[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 10, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame20[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 532, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 10, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame21[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 11, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame22[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 664, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_8x32, OAM_X_FLIP, 664, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 756, 8, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 756, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame23[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 665, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_8x32, OAM_X_FLIP, 665, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 724, 8, 0),
    OAM_ENTRY(-16, 9, OAM_DIMS_32x8, OAM_Y_FLIP, 724, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame24[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 640, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame25[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 644, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame26[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 648, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawned_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 720, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 652, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 580, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 584, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 596, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 580, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 584, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame9[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame10[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 596, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame11[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 580, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 9, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame12[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 584, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 9, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame13[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 9, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame14[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 9, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame15[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 596, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 9, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame16[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 580, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 10, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame17[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 584, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 10, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame18[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 10, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame19[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 10, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame20[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 596, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 10, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame21[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 11, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame22[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 664, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_8x32, OAM_X_FLIP, 664, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 756, 8, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 756, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame23[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 704, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 665, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_8x32, OAM_X_FLIP, 665, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 724, 8, 0),
    OAM_ENTRY(-16, 9, OAM_DIMS_32x8, OAM_Y_FLIP, 724, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame24[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 704, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame25[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 708, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame26[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 712, 8, 0),
};

static const u16 sRisingChozoPillarPlatformOam_Spawned_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 716, 8, 0),
};

static const u16 sRisingChozoPillarPlatformShadowOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 656, 8, 0),
};

static const u16 sRisingChozoPillarPlatformShadowOam_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 660, 8, 0),
};

static const u16 sRisingChozoPillarPlatformShadowOam_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 692, 8, 0),
};

const struct FrameData sRisingChozoPillarPlatformOam_NoShadowSpawning[28] = {
    [0] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame9,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame11,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [12] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame12,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame13,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [14] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame14,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [15] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame15,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [16] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame16,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [17] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame17,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [18] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame18,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [19] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame19,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [20] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame20,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [21] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame21,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [22] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame22,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [23] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame23,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [24] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame24,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [25] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame25,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [26] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawning_Frame26,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [27] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRisingChozoPillarPlatformOam_NoShadowSpawned[2] = {
    [0] = {
        .pFrame = sRisingChozoPillarPlatformOam_Slot0Spawned_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRisingChozoPillarPlatformOam_ShadowSpawning[28] = {
    [0] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame9,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame11,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [12] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame12,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame13,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [14] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame14,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [15] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame15,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [16] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame16,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [17] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame17,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [18] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame18,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [19] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame19,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [20] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame20,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [21] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame21,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [22] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame22,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [23] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame23,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [24] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame24,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [25] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame25,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [26] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawning_Frame26,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [27] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRisingChozoPillarPlatformOam_ShadowSpawned[2] = {
    [0] = {
        .pFrame = sRisingChozoPillarPlatformOam_Spawned_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRisingChozoPillarPlatformShadowOam[4] = {
    [0] = {
        .pFrame = sRisingChozoPillarPlatformShadowOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sRisingChozoPillarPlatformShadowOam_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sRisingChozoPillarPlatformShadowOam_Frame2,
        .timer = UCHAR_MAX
    },
    [3] = FRAME_DATA_TERMINATOR
};
