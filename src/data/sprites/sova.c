#include "data/sprites/sova.h"
#include "macros.h"

const u32 sSovaGfx[851] = INCBIN_U32("data/sprites/sova.gfx.lz");
const u16 sSovaPal[3 * 16] = INCBIN_U16("data/sprites/sova.pal");

static const u16 sSovaOam_OnGround_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-12, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sSovaOam_OnGround_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-20, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x203, 8, 0)
};

static const u16 sSovaOam_OnGround_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-12, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-8, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0)
};

static const u16 sSovaOam_OnGround_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-20, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22e, 8, 0)
};

static const u16 sSovaOam_OnGround_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 0x272, 8, 0)
};

static const u16 sSovaOam_OnGround_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 8, 0)
};

static const u16 sSovaOam_WalkingOnRightSlope_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x296, 8, 0),
    OAM_ENTRY(-6, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x240, 8, 0)
};

static const u16 sSovaOam_WalkingOnLeftSlope_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x296, 8, 0),
    OAM_ENTRY(-23, -20, OAM_DIMS_32x16, OAM_X_FLIP, 0x240, 8, 0)
};

static const u16 sSovaOam_WalkingOnRightSlope_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x298, 8, 0),
    OAM_ENTRY(-14, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x243, 8, 0)
};

static const u16 sSovaOam_WalkingOnRightSlope_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x298, 8, 0),
    OAM_ENTRY(-6, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-2, -23, OAM_DIMS_8x8, OAM_Y_FLIP, 0x26b, 8, 0)
};

static const u16 sSovaOam_WalkingOnRightSlope_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29a, 8, 0),
    OAM_ENTRY(-6, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(1, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x26b, 8, 0)
};

static const u16 sSovaOam_WalkingOnRightSlope_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29a, 8, 0),
    OAM_ENTRY(-6, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(2, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24b, 8, 0)
};

static const u16 sSovaOam_WalkingOnLeftSlope_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29c, 8, 0),
    OAM_ENTRY(-14, -20, OAM_DIMS_32x16, OAM_X_FLIP, 0x243, 8, 0)
};

static const u16 sSovaOam_WalkingOnLeftSlope_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29c, 8, 0),
    OAM_ENTRY(-23, -20, OAM_DIMS_32x16, OAM_X_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-3, -23, OAM_DIMS_8x8, OAM_XY_FLIP, 0x26b, 8, 0)
};

static const u16 sSovaOam_WalkingOnLeftSlope_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29e, 8, 0),
    OAM_ENTRY(-6, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-5, -28, OAM_DIMS_8x8, OAM_X_FLIP, 0x26b, 8, 0)
};

static const u16 sSovaOam_WalkingOnLeftSlope_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29e, 8, 0),
    OAM_ENTRY(-6, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x24e, 8, 0),
    OAM_ENTRY(-6, -32, OAM_DIMS_8x8, OAM_X_FLIP, 0x24b, 8, 0)
};

static const u16 sSovaOam_WalkingOnLeft_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(4, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(12, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0)
};

static const u16 sSovaOam_WalkingOnLeft_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -11, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(4, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(12, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x256, 8, 0)
};

static const u16 sSovaOam_WalkingOnLeft_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -11, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(4, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x257, 8, 0)
};

static const u16 sSovaOam_WalkingOnLeft_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(4, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(12, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27b, 8, 0)
};

static const u16 sSovaOam_WalkingOnLeft_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(12, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27b, 8, 0)
};

static const u16 sSovaOam_WalkingOnLeft_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(16, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25b, 8, 0)
};

static const u16 sSovaOam_WalkingOnRight_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(4, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(12, -18, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0)
};

static const u16 sSovaOam_WalkingOnRight_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(4, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(12, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x256, 8, 0)
};

static const u16 sSovaOam_WalkingOnRight_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(4, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x257, 8, 0)
};

static const u16 sSovaOam_WalkingOnRight_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(4, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(12, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27b, 8, 0)
};

static const u16 sSovaOam_WalkingOnRight_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(4, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(12, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27b, 8, 0)
};

static const u16 sSovaOam_WalkingOnRight_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(4, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(16, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25b, 8, 0)
};

static const u16 sSovaOam_WalkingOnCeiling_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-12, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x280, 8, 0)
};

static const u16 sSovaOam_WalkingOnCeiling_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-20, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x283, 8, 0)
};

static const u16 sSovaOam_WalkingOnCeiling_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-12, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x287, 8, 0)
};

static const u16 sSovaOam_WalkingOnCeiling_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-20, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x28a, 8, 0)
};

static const u16 sSovaOam_WalkingOnCeiling_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28e, 8, 0)
};

static const u16 sSovaOam_WalkingOnCeiling_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-8, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x290, 8, 0)
};

static const u16 sSovaOam_TurningRight_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_X_FLIP, 0x296, 8, 0),
    OAM_ENTRY(-9, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x207, 8, 0)
};

static const u16 sSovaOam_TurningRight_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(1, -15, OAM_DIMS_32x16, OAM_NO_FLIP, 0x247, 8, 0)
};

static const u16 sSovaOam_TurningRight_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-1, -6, OAM_DIMS_8x16, OAM_X_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(3, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(12, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25b, 8, 0)
};

static const u16 sSovaOam_TurningEdgeLeft_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x296, 8, 0),
    OAM_ENTRY(-19, -21, OAM_DIMS_32x16, OAM_X_FLIP, 0x207, 8, 0)
};

static const u16 sSovaOam_TurningEdgeLeft_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-11, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-2, -19, OAM_DIMS_32x16, OAM_NO_FLIP, 0x247, 8, 0)
};

static const u16 sSovaOam_TurningEdgeLeft_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -14, OAM_DIMS_8x16, OAM_X_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-2, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(7, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25b, 8, 0)
};

static const u16 sSovaOam_TurningCornerLeft_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-2, -2, OAM_DIMS_16x8, OAM_X_FLIP, 0x296, 8, 0),
    OAM_ENTRY(-13, -15, OAM_DIMS_32x16, OAM_X_FLIP, 0x207, 8, 0)
};

static const u16 sSovaOam_TurningCornerLeft_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -6, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(4, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x247, 8, 0)
};

static const u16 sSovaOam_TurningCornerLeft_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(4, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x259, 8, 0),
    OAM_ENTRY(13, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25b, 8, 0)
};

static const u16 sSovaOam_Falling_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-20, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x203, 8, 0)
};

static const u16 sSovaOam_Falling_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-12, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-8, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0)
};

static const u16 sSovaOam_Falling_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-12, -21, OAM_DIMS_32x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0)
};

static const u16 sSovaOam_Falling_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-8, -29, OAM_DIMS_16x8, OAM_NO_FLIP, 0x272, 8, 0)
};

static const u16 sSovaOam_Falling_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x236, 8, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-4, -33, OAM_DIMS_8x8, OAM_NO_FLIP, 0x273, 8, 0)
};


const struct FrameData sSovaOam_OnGround[7] = {
    [0] = {
        .pFrame = sSovaOam_OnGround_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sSovaOam_OnGround_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sSovaOam_OnGround_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sSovaOam_OnGround_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sSovaOam_OnGround_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sSovaOam_OnGround_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaOam_WalkingOnLeftSlope[7] = {
    [0] = {
        .pFrame = sSovaOam_WalkingOnLeftSlope_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sSovaOam_WalkingOnLeftSlope_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sSovaOam_WalkingOnLeftSlope_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sSovaOam_WalkingOnLeftSlope_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sSovaOam_WalkingOnLeftSlope_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sSovaOam_WalkingOnLeftSlope_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaOam_WalkingOnRightSlope[7] = {
    [0] = {
        .pFrame = sSovaOam_WalkingOnRightSlope_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sSovaOam_WalkingOnRightSlope_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sSovaOam_WalkingOnRightSlope_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sSovaOam_WalkingOnRightSlope_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sSovaOam_WalkingOnRightSlope_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sSovaOam_WalkingOnRightSlope_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaOam_WalkingOnLeft[7] = {
    [0] = {
        .pFrame = sSovaOam_WalkingOnLeft_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sSovaOam_WalkingOnLeft_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sSovaOam_WalkingOnLeft_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sSovaOam_WalkingOnLeft_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sSovaOam_WalkingOnLeft_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sSovaOam_WalkingOnLeft_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaOam_WalkingOnRight[7] = {
    [0] = {
        .pFrame = sSovaOam_WalkingOnRight_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sSovaOam_WalkingOnRight_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sSovaOam_WalkingOnRight_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sSovaOam_WalkingOnRight_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sSovaOam_WalkingOnRight_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sSovaOam_WalkingOnRight_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaOam_WalkingOnCeiling[7] = {
    [0] = {
        .pFrame = sSovaOam_WalkingOnCeiling_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sSovaOam_WalkingOnCeiling_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sSovaOam_WalkingOnCeiling_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sSovaOam_WalkingOnCeiling_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sSovaOam_WalkingOnCeiling_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sSovaOam_WalkingOnCeiling_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaOam_TurningCornerRight[4] = {
    [0] = {
        .pFrame = sSovaOam_TurningRight_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sSovaOam_TurningRight_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sSovaOam_TurningRight_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaOam_TurningEdgeRight[4] = {
    [0] = {
        .pFrame = sSovaOam_TurningRight_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sSovaOam_TurningRight_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sSovaOam_TurningRight_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaOam_TurningEdgeLeft[4] = {
    [0] = {
        .pFrame = sSovaOam_TurningEdgeLeft_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sSovaOam_TurningEdgeLeft_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sSovaOam_TurningEdgeLeft_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaOam_TurningCornerLeft[4] = {
    [0] = {
        .pFrame = sSovaOam_TurningCornerLeft_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sSovaOam_TurningCornerLeft_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sSovaOam_TurningCornerLeft_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSovaOam_Falling[7] = {
    [0] = {
        .pFrame = sSovaOam_OnGround_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sSovaOam_Falling_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sSovaOam_Falling_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sSovaOam_Falling_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sSovaOam_Falling_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sSovaOam_Falling_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};
