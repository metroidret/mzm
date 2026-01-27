#include "data/sprites/rising_chozo_pillar.h"
#include "macros.h"

const u32 sRisingChozoPillarGfx[671] = INCBIN_U32("data/sprites/rising_chozo_pillar.gfx.lz");
const u16 sRisingChozoPillarPal[64] = INCBIN_U16("data/sprites/rising_chozo_pillar.pal");

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame7[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame8[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame9[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame10[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame11[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 9, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame12[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 9, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame13[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 9, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame14[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 9, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame15[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 9, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame16[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 10, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame17[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 10, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame18[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 10, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame19[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 10, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame20[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 10, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame21[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 11, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame22[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x298, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_8x32, OAM_X_FLIP, 0x298, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2f4, 8, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x2f4, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame23[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x299, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_8x32, OAM_X_FLIP, 0x299, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2d4, 8, 0),
    OAM_ENTRY(-16, 9, OAM_DIMS_32x8, OAM_Y_FLIP, 0x2d4, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame24[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x280, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame25[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x284, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawning_Frame26[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x288, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Slot0Spawned_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d0, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x28c, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x244, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x248, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x254, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x248, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame9[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame10[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x240, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame11[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x244, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 9, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame12[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x248, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 9, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame13[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 9, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame14[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 9, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame15[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x240, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x254, 10, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 9, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame16[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x244, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 10, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame17[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x248, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 10, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame18[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 10, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame19[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 10, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame20[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x254, 11, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 10, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame21[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 11, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame22[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x298, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_8x32, OAM_X_FLIP, 0x298, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2f4, 8, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_32x8, OAM_Y_FLIP, 0x2f4, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame23[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x299, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_8x32, OAM_X_FLIP, 0x299, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2d4, 8, 0),
    OAM_ENTRY(-16, 9, OAM_DIMS_32x8, OAM_Y_FLIP, 0x2d4, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame24[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2c0, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame25[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2c4, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawning_Frame26[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2c8, 8, 0)
};

static const u16 sRisingChozoPillarPlatformOam_Spawned_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2cc, 8, 0)
};

static const u16 sRisingChozoPillarPlatformShadowOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sRisingChozoPillarPlatformShadowOam_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x294, 8, 0)
};

static const u16 sRisingChozoPillarPlatformShadowOam_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2b4, 8, 0)
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
