#include "data/sprites/save_platform.h"
#include "macros.h"

const u32 sSavePlatformGfx[603] = INCBIN_U32("data/sprites/save_platform.gfx.lz");
const u16 sSavePlatformPal[64] = INCBIN_U16("data/sprites/save_platform.pal");

static const u16 sSavePlatformOam_Idle_Frame0[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-34, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(18, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-24, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(8, -1, OAM_DIMS_16x8, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0)
};

static const u16 sSavePlatformOam_Idle_Frame1[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-34, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(18, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-24, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(8, -1, OAM_DIMS_16x8, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0)
};

static const u16 sSavePlatformOam_Idle_Frame2[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-34, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(18, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-24, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(8, -1, OAM_DIMS_16x8, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0)
};

static const u16 sSavePlatformOam_Idle_Frame3[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x244, 8, 0),
    OAM_ENTRY(-34, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(18, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-24, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(8, -1, OAM_DIMS_16x8, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0)
};

static const u16 sSavePlatformOam_Opening_Frame0[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a1, 8, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a1, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2c2, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a0, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_32x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-25, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(9, -1, OAM_DIMS_16x8, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x286, 8, 0),
    OAM_ENTRY(-25, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(9, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x248, 8, 0),
    OAM_ENTRY(-34, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(18, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2e0, 8, 0)
};

static const u16 sSavePlatformOam_Opening_Frame1[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-13, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a1, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a1, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2c2, 8, 0),
    OAM_ENTRY(-25, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 8, 0),
    OAM_ENTRY(17, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a0, 8, 0),
    OAM_ENTRY(-25, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(9, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-26, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(10, -1, OAM_DIMS_16x8, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x286, 8, 0),
    OAM_ENTRY(-26, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(10, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-34, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(18, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2e0, 8, 0)
};

static const u16 sSavePlatformOam_Opening_Frame2[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-14, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a1, 8, 0),
    OAM_ENTRY(6, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a1, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2c2, 8, 0),
    OAM_ENTRY(-26, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 8, 0),
    OAM_ENTRY(18, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a0, 8, 0),
    OAM_ENTRY(-26, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(-16, -3, OAM_DIMS_32x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-26, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(10, 0, OAM_DIMS_16x8, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-27, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(11, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_32x16, OAM_NO_FLIP, 0x286, 8, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-34, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(18, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2e0, 8, 0)
};

static const u16 sSavePlatformOam_Opened_Frame0[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-14, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a1, 8, 0),
    OAM_ENTRY(6, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a1, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2c2, 8, 0),
    OAM_ENTRY(-26, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 8, 0),
    OAM_ENTRY(18, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a0, 8, 0),
    OAM_ENTRY(-26, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(10, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-26, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(10, 1, OAM_DIMS_16x8, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-27, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(11, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x286, 8, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-34, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(18, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2e0, 8, 0)
};

static const u16 sSavePlatformOam_Opened_Frame1[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-14, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a1, 8, 0),
    OAM_ENTRY(6, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a1, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2c2, 8, 0),
    OAM_ENTRY(-26, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 8, 0),
    OAM_ENTRY(18, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a0, 8, 0),
    OAM_ENTRY(-26, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(10, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-26, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(10, 1, OAM_DIMS_16x8, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-27, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(11, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x286, 8, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-34, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(18, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2e0, 8, 0)
};

static const u16 sSavePlatformOam_Opened_Frame2[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-14, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a1, 8, 0),
    OAM_ENTRY(6, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a1, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2c2, 8, 0),
    OAM_ENTRY(-26, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 8, 0),
    OAM_ENTRY(18, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a0, 8, 0),
    OAM_ENTRY(-26, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(10, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-26, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(10, 1, OAM_DIMS_16x8, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-27, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(11, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x286, 8, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-34, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(18, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2e0, 8, 0)
};

static const u16 sSavePlatformOam_Opened_Frame5[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-14, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a1, 8, 0),
    OAM_ENTRY(6, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a1, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2c2, 8, 0),
    OAM_ENTRY(-26, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2a0, 8, 0),
    OAM_ENTRY(18, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x2a0, 8, 0),
    OAM_ENTRY(-26, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(10, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(-26, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(10, 1, OAM_DIMS_16x8, OAM_X_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-27, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x256, 8, 0),
    OAM_ENTRY(11, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x256, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x286, 8, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-34, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(18, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2e0, 8, 0)
};

static const u16 sSavePlatformPartOam_TopIdle_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, -22, OAM_DIMS_32x16, OAM_Y_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-24, -13, OAM_DIMS_16x8, OAM_Y_FLIP, 0x280, 8, 0),
    OAM_ENTRY(8, -13, OAM_DIMS_16x8, OAM_XY_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_32x16, OAM_Y_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-24, -1, OAM_DIMS_16x8, OAM_Y_FLIP, 0x280, 8, 0),
    OAM_ENTRY(8, -1, OAM_DIMS_16x8, OAM_XY_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, 32, OAM_DIMS_32x8, OAM_Y_FLIP, 0x2f2, 8, 0),
    OAM_ENTRY(8, 32, OAM_DIMS_16x8, OAM_XY_FLIP, 0x2f2, 8, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_32x32, OAM_Y_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x32, OAM_XY_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_32x32, OAM_Y_FLIP, 0x28e, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x32, OAM_XY_FLIP, 0x28e, 8, 0)
};

static const u16 sSavePlatformPartOam_TopExtending_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, -9, OAM_DIMS_32x16, OAM_Y_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-16, -21, OAM_DIMS_32x16, OAM_Y_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-25, -13, OAM_DIMS_16x8, OAM_Y_FLIP, 0x280, 8, 0),
    OAM_ENTRY(9, -13, OAM_DIMS_16x8, OAM_XY_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-25, -1, OAM_DIMS_16x8, OAM_Y_FLIP, 0x280, 8, 0),
    OAM_ENTRY(9, -1, OAM_DIMS_16x8, OAM_XY_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, 36, OAM_DIMS_32x8, OAM_Y_FLIP, 0x2f2, 8, 0),
    OAM_ENTRY(8, 36, OAM_DIMS_16x8, OAM_XY_FLIP, 0x2f2, 8, 0),
    OAM_ENTRY(-24, 4, OAM_DIMS_32x32, OAM_Y_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(8, 4, OAM_DIMS_16x32, OAM_XY_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-24, -28, OAM_DIMS_32x32, OAM_Y_FLIP, 0x28e, 8, 0),
    OAM_ENTRY(8, -28, OAM_DIMS_16x32, OAM_XY_FLIP, 0x28e, 8, 0)
};

static const u16 sSavePlatformPartOam_TopExtending_Frame1[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, -20, OAM_DIMS_32x16, OAM_Y_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-26, -13, OAM_DIMS_16x8, OAM_Y_FLIP, 0x280, 8, 0),
    OAM_ENTRY(10, -13, OAM_DIMS_16x8, OAM_XY_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_Y_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-26, -1, OAM_DIMS_16x8, OAM_Y_FLIP, 0x280, 8, 0),
    OAM_ENTRY(10, -1, OAM_DIMS_16x8, OAM_XY_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, 40, OAM_DIMS_32x8, OAM_Y_FLIP, 0x2f2, 8, 0),
    OAM_ENTRY(8, 40, OAM_DIMS_16x8, OAM_XY_FLIP, 0x2f2, 8, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_32x32, OAM_Y_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x32, OAM_XY_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_32x32, OAM_Y_FLIP, 0x28e, 8, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_16x32, OAM_XY_FLIP, 0x28e, 8, 0)
};

static const u16 sSavePlatformPartOam_TopExtending_Frame2[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, -19, OAM_DIMS_32x16, OAM_Y_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-27, -13, OAM_DIMS_16x8, OAM_Y_FLIP, 0x280, 8, 0),
    OAM_ENTRY(11, -13, OAM_DIMS_16x8, OAM_XY_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_32x16, OAM_Y_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-27, -1, OAM_DIMS_16x8, OAM_Y_FLIP, 0x280, 8, 0),
    OAM_ENTRY(11, -1, OAM_DIMS_16x8, OAM_XY_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, 44, OAM_DIMS_32x8, OAM_Y_FLIP, 0x2f2, 8, 0),
    OAM_ENTRY(8, 44, OAM_DIMS_16x8, OAM_XY_FLIP, 0x2f2, 8, 0),
    OAM_ENTRY(-24, 12, OAM_DIMS_32x32, OAM_Y_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(8, 12, OAM_DIMS_16x32, OAM_XY_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-24, -20, OAM_DIMS_32x32, OAM_Y_FLIP, 0x28e, 8, 0),
    OAM_ENTRY(8, -20, OAM_DIMS_16x32, OAM_XY_FLIP, 0x28e, 8, 0)
};

static const u16 sSavePlatformPartOam_TopExtending_Frame3[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, -18, OAM_DIMS_32x16, OAM_Y_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-28, -13, OAM_DIMS_16x8, OAM_Y_FLIP, 0x280, 8, 0),
    OAM_ENTRY(12, -13, OAM_DIMS_16x8, OAM_XY_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x16, OAM_Y_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-28, -1, OAM_DIMS_16x8, OAM_Y_FLIP, 0x280, 8, 0),
    OAM_ENTRY(12, -1, OAM_DIMS_16x8, OAM_XY_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, 50, OAM_DIMS_32x8, OAM_Y_FLIP, 0x2f2, 8, 0),
    OAM_ENTRY(8, 50, OAM_DIMS_16x8, OAM_XY_FLIP, 0x2f2, 8, 0),
    OAM_ENTRY(-24, 18, OAM_DIMS_32x32, OAM_Y_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(8, 18, OAM_DIMS_16x32, OAM_XY_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-24, -14, OAM_DIMS_32x32, OAM_Y_FLIP, 0x28e, 8, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_16x32, OAM_XY_FLIP, 0x28e, 8, 0)
};

static const u16 sSavePlatformPartOam_TopExtending_Frame4[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, -19, OAM_DIMS_32x16, OAM_Y_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-27, -13, OAM_DIMS_16x8, OAM_Y_FLIP, 0x280, 8, 0),
    OAM_ENTRY(11, -13, OAM_DIMS_16x8, OAM_XY_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_32x16, OAM_Y_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-27, -1, OAM_DIMS_16x8, OAM_Y_FLIP, 0x280, 8, 0),
    OAM_ENTRY(11, -1, OAM_DIMS_16x8, OAM_XY_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, 49, OAM_DIMS_32x8, OAM_Y_FLIP, 0x2f2, 8, 0),
    OAM_ENTRY(8, 49, OAM_DIMS_16x8, OAM_XY_FLIP, 0x2f2, 8, 0),
    OAM_ENTRY(-24, 17, OAM_DIMS_32x32, OAM_Y_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(8, 17, OAM_DIMS_16x32, OAM_XY_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-24, -15, OAM_DIMS_32x32, OAM_Y_FLIP, 0x28e, 8, 0),
    OAM_ENTRY(8, -15, OAM_DIMS_16x32, OAM_XY_FLIP, 0x28e, 8, 0)
};

static const u16 sSavePlatformPartOam_TopExtended_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-16, -20, OAM_DIMS_32x16, OAM_Y_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-26, -13, OAM_DIMS_16x8, OAM_Y_FLIP, 0x280, 8, 0),
    OAM_ENTRY(10, -13, OAM_DIMS_16x8, OAM_XY_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_Y_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-26, -1, OAM_DIMS_16x8, OAM_Y_FLIP, 0x280, 8, 0),
    OAM_ENTRY(10, -1, OAM_DIMS_16x8, OAM_XY_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-24, 48, OAM_DIMS_32x8, OAM_Y_FLIP, 0x2f2, 8, 0),
    OAM_ENTRY(8, 48, OAM_DIMS_16x8, OAM_XY_FLIP, 0x2f2, 8, 0),
    OAM_ENTRY(-24, 16, OAM_DIMS_32x32, OAM_Y_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(8, 16, OAM_DIMS_16x32, OAM_XY_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_Y_FLIP, 0x28e, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x32, OAM_XY_FLIP, 0x28e, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeSpawning_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -52, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27f, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeSpawning_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -52, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeSpawning_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeSpawning_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -60, OAM_DIMS_8x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-4, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 0x258, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeSpawning_Frame8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -64, OAM_DIMS_8x32, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeSpawning_Frame10[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -68, OAM_DIMS_8x32, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-4, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeSpawning_Frame12[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -72, OAM_DIMS_8x32, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeSpawning_Frame14[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -76, OAM_DIMS_8x32, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-4, -52, OAM_DIMS_8x32, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeSpawning_Frame16[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -80, OAM_DIMS_8x32, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeSpawning_Frame18[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-5, -80, OAM_DIMS_8x32, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-5, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-3, -80, OAM_DIMS_8x32, OAM_X_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-3, -48, OAM_DIMS_8x32, OAM_X_FLIP, 0x219, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeSpawning_Frame20[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -80, OAM_DIMS_8x32, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-9, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(1, -80, OAM_DIMS_8x32, OAM_X_FLIP, 0x219, 8, 0),
    OAM_ENTRY(1, -48, OAM_DIMS_8x32, OAM_X_FLIP, 0x219, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeSpawning_Frame22[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -80, OAM_DIMS_8x32, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-12, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(4, -80, OAM_DIMS_8x32, OAM_X_FLIP, 0x219, 8, 0),
    OAM_ENTRY(4, -48, OAM_DIMS_8x32, OAM_X_FLIP, 0x219, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeSpawning_Frame24[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-13, -80, OAM_DIMS_8x32, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-13, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(5, -80, OAM_DIMS_8x32, OAM_X_FLIP, 0x219, 8, 0),
    OAM_ENTRY(5, -48, OAM_DIMS_8x32, OAM_X_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-13, -32, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-13, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeSpawning_Frame26[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-13, -32, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-13, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-14, -80, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-14, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(6, -80, OAM_DIMS_8x32, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(6, -48, OAM_DIMS_8x32, OAM_X_FLIP, 0x21a, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeSpawning_Frame28[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-13, -32, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-13, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-15, -80, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-15, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(7, -80, OAM_DIMS_8x32, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(7, -48, OAM_DIMS_8x32, OAM_X_FLIP, 0x21a, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeSpawning_Frame32[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-13, -32, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-13, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-16, -80, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -80, OAM_DIMS_8x32, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_8x32, OAM_X_FLIP, 0x21b, 8, 0)
};

static const u16 sSavePlatformPartOam_Tube_Unused_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -80, OAM_DIMS_32x32, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_32x32, OAM_NO_FLIP, 0x210, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeShadow_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-20, -80, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-20, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(12, -80, OAM_DIMS_8x32, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(12, -48, OAM_DIMS_8x32, OAM_X_FLIP, 0x21c, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeShadow_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-18, -80, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-18, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(10, -80, OAM_DIMS_8x32, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(10, -48, OAM_DIMS_8x32, OAM_X_FLIP, 0x21d, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeShadow_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-15, -80, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-15, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(7, -80, OAM_DIMS_8x32, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(7, -48, OAM_DIMS_8x32, OAM_X_FLIP, 0x21d, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeShadow_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -80, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-11, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(3, -80, OAM_DIMS_8x32, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(3, -48, OAM_DIMS_8x32, OAM_X_FLIP, 0x21d, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeShadow_Frame8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -80, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-7, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-1, -80, OAM_DIMS_8x32, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-1, -48, OAM_DIMS_8x32, OAM_X_FLIP, 0x21c, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeShadow_Frame10[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -80, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeDespawning_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-13, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-16, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-16, -66, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-16, -46, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -80, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -66, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -46, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-13, -32, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeDespawning_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-13, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-16, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-16, -68, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-16, -44, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -80, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -68, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -44, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-13, -32, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeDespawning_Frame4[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-13, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-16, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-16, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -80, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -72, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -40, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-13, -32, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeDespawning_Frame6[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-13, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-16, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-16, -76, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-16, -36, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -80, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -76, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -36, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-13, -32, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeDespawning_Frame8[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-13, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-16, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -80, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-13, -32, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x21b, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeDespawning_Frame10[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-13, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-16, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -80, OAM_DIMS_8x8, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-13, -24, OAM_DIMS_8x8, OAM_Y_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_8x8, OAM_Y_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_8x8, OAM_XY_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-13, -72, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23f, 8, 0),
    OAM_ENTRY(-16, -76, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -76, OAM_DIMS_8x8, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-13, -32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x23f, 8, 0),
    OAM_ENTRY(-16, -28, OAM_DIMS_8x8, OAM_Y_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -28, OAM_DIMS_8x8, OAM_XY_FLIP, 0x21b, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeDespawning_Frame12[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-13, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-16, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -80, OAM_DIMS_8x8, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-13, -24, OAM_DIMS_8x8, OAM_Y_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_8x8, OAM_Y_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_8x8, OAM_XY_FLIP, 0x21b, 8, 0)
};

static const u16 sSavePlatformPartOam_TubeDespawning_Frame14[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-13, -84, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-16, -84, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -84, OAM_DIMS_8x8, OAM_X_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-13, -20, OAM_DIMS_8x8, OAM_Y_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_8x8, OAM_Y_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(8, -20, OAM_DIMS_8x8, OAM_XY_FLIP, 0x21b, 8, 0)
};

static const u16 sSavePlatformPartOam_Ray_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x296, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x296, 9, 0)
};

static const u16 sSavePlatformPartOam_Ray_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2b6, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x2b6, 9, 0)
};

static const u16 sSavePlatformPartOam_Ray_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2d6, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x2d6, 9, 0)
};

static const u16 sSavePlatformPartOam_Ray_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2f6, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x2f6, 9, 0)
};

static const u16 sSavePlatformPartOam_Empty[4] = {
    0x1,
    0xfc, 0x1fc, 0x25f
};

const struct FrameData sSavePlatformOam_Idle[7] = {
    [0] = {
        .pFrame = sSavePlatformOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sSavePlatformOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sSavePlatformOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sSavePlatformOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = {
        .pFrame = sSavePlatformOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sSavePlatformOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformOam_Opening[4] = {
    [0] = {
        .pFrame = sSavePlatformOam_Opening_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sSavePlatformOam_Opening_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sSavePlatformOam_Opening_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformOam_Opened[7] = {
    [0] = {
        .pFrame = sSavePlatformOam_Opened_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sSavePlatformOam_Opened_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sSavePlatformOam_Opened_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sSavePlatformOam_Opened_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = {
        .pFrame = sSavePlatformOam_Opened_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sSavePlatformOam_Opened_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformOam_Saving[7] = {
    [0] = {
        .pFrame = sSavePlatformOam_Opened_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSavePlatformOam_Opened_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSavePlatformOam_Opened_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSavePlatformOam_Opened_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSavePlatformOam_Opened_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSavePlatformOam_Opened_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformOam_OpenedOff[2] = {
    [0] = {
        .pFrame = sSavePlatformOam_Opened_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformOam_Closing[4] = {
    [0] = {
        .pFrame = sSavePlatformOam_Opening_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sSavePlatformOam_Opening_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sSavePlatformOam_Opening_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformOam_IdleOff[2] = {
    [0] = {
        .pFrame = sSavePlatformOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOam_TopIdle[2] = {
    [0] = {
        .pFrame = sSavePlatformPartOam_TopIdle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOam_TopExtending[6] = {
    [0] = {
        .pFrame = sSavePlatformPartOam_TopExtending_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sSavePlatformPartOam_TopExtending_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sSavePlatformPartOam_TopExtending_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sSavePlatformPartOam_TopExtending_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sSavePlatformPartOam_TopExtending_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOam_TopExtended[2] = {
    [0] = {
        .pFrame = sSavePlatformPartOam_TopExtended_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOam_TopRetracting[6] = {
    [0] = {
        .pFrame = sSavePlatformPartOam_TopExtending_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sSavePlatformPartOam_TopExtending_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sSavePlatformPartOam_TopExtending_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sSavePlatformPartOam_TopExtending_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sSavePlatformPartOam_TopExtending_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOam_TubeSpawning[39] = {
    [0] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame8,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame10,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [11] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame12,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [13] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [14] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame14,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [15] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [16] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame16,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [17] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [18] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame18,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [19] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [20] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame20,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [21] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [22] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame22,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [23] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [24] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame24,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [25] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [26] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame26,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [27] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [28] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame28,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [29] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [30] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame28,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [31] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [32] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame32,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [33] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [34] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame32,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [35] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [36] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame32,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [37] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [38] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOam_TubeShadow[13] = {
    [0] = {
        .pFrame = sSavePlatformPartOam_TubeShadow_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSavePlatformPartOam_TubeShadow_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSavePlatformPartOam_TubeShadow_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sSavePlatformPartOam_TubeShadow_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sSavePlatformPartOam_TubeShadow_Frame8,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sSavePlatformPartOam_TubeShadow_Frame10,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [11] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOam_TubeIdle[3] = {
    [0] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame32,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOam_Tube_Unused[5] = {
    [0] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame32,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSavePlatformPartOam_Tube_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSavePlatformPartOam_TubeSpawning_Frame32,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOam_TubeDespawning[17] = {
    [0] = {
        .pFrame = sSavePlatformPartOam_TubeDespawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSavePlatformPartOam_TubeDespawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSavePlatformPartOam_TubeDespawning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sSavePlatformPartOam_TubeDespawning_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sSavePlatformPartOam_TubeDespawning_Frame8,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sSavePlatformPartOam_TubeDespawning_Frame10,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [11] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = {
        .pFrame = sSavePlatformPartOam_TubeDespawning_Frame12,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [13] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [14] = {
        .pFrame = sSavePlatformPartOam_TubeDespawning_Frame14,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [15] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSavePlatformPartOam_Ray[9] = {
    [0] = {
        .pFrame = sSavePlatformPartOam_Ray_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSavePlatformPartOam_Ray_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSavePlatformPartOam_Ray_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sSavePlatformPartOam_Ray_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sSavePlatformPartOam_Empty,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = FRAME_DATA_TERMINATOR
};
