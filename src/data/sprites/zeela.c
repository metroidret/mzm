#include "data/sprites/zeela.h"
#include "macros.h"

const s16 sZeelaEyesFallingFromUpSpeed[16] = {
    -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, SHORT_MAX
};

const s16 sZeelaEyesFallingFromBottomSpeed[12] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, SHORT_MAX
};

const u32 sZeelaGfx[578] = INCBIN_U32("data/sprites/zeela.gfx.lz");
const u16 sZeelaPal[32] = INCBIN_U16("data/sprites/zeela.pal");

static const u16 sZeelaOam_OnGround_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0)
};

static const u16 sZeelaOam_OnGround_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x266, 8, 0)
};

static const u16 sZeelaOam_OnGround_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x242, 8, 0)
};

static const u16 sZeelaOam_OnGround_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x243, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x245, 8, 0)
};

static const u16 sZeelaOam_TurningEdgeLeft_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(4, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-4, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20f, 8, 0)
};

static const u16 sZeelaOam_TurningEdgeLeft_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(8, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25a, 8, 0)
};

static const u16 sZeelaOam_TurningEdgeLeft_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(7, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-1, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25e, 8, 0)
};

static const u16 sZeelaOam_OnWall_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x246, 8, 0)
};

static const u16 sZeelaOam_OnWall_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(16, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x267, 8, 0)
};

static const u16 sZeelaOam_OnWall_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24a, 8, 0)
};

static const u16 sZeelaOam_OnWall_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(0, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24c, 8, 0)
};

static const u16 sZeelaOam_TurningCornerRight_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-4, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20f, 8, 0)
};

static const u16 sZeelaOam_TurningCornerRight_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-12, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25a, 8, 0)
};

static const u16 sZeelaOam_TurningCornerRight_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-6, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25e, 8, 0)
};

static const u16 sZeelaOam_TurningCornerLeft_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(10, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(2, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25e, 8, 0)
};

static const u16 sZeelaOam_TurningCornerLeft_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(11, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-5, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25a, 8, 0)
};

static const u16 sZeelaOam_TurningCornerLeft_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(10, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(2, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20f, 8, 0)
};

static const u16 sZeelaOam_WalkingOnSlope_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(2, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-6, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20f, 8, 0)
};

static const u16 sZeelaOam_WalkingOnSlope_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-5, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x252, 8, 0)
};

static const u16 sZeelaOam_WalkingOnSlope_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x255, 8, 0)
};

static const u16 sZeelaOam_WalkingOnSlope_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-13, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(3, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-5, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sZeelaOam_FallingOnGround_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x268, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0)
};

static const u16 sZeelaOam_FallingOnGround_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26a, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x266, 8, 0)
};

static const u16 sZeelaOam_FallingOnGround_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x242, 8, 0)
};

static const u16 sZeelaOam_FallingOnGround_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x276, 8, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x243, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x245, 8, 0)
};

static const u16 sZeelaOam_FallingOnGround_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x270, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 8, 0)
};

static const u16 sZeelaOam_FallingOnGround_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x266, 8, 0)
};

static const u16 sZeelaOam_FallingOnGround_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26c, 8, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x242, 8, 0)
};

static const u16 sZeelaOam_FallingOnGround_Frame7[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26e, 8, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x243, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x245, 8, 0)
};

static const u16 sZeelaOam_FallingOnWall_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(9, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x279, 8, 0),
    OAM_ENTRY(9, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x279, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x246, 8, 0)
};

static const u16 sZeelaOam_FallingOnWall_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(8, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27a, 8, 0),
    OAM_ENTRY(10, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27a, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(16, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x267, 8, 0)
};

static const u16 sZeelaOam_FallingOnWall_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27e, 8, 0),
    OAM_ENTRY(9, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27e, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24a, 8, 0)
};

static const u16 sZeelaOam_FallingOnWall_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(9, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27d, 8, 0),
    OAM_ENTRY(8, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27d, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(0, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24c, 8, 0)
};

static const u16 sZeelaOam_FallingOnWall_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(9, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27c, 8, 0),
    OAM_ENTRY(9, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27c, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x246, 8, 0)
};

static const u16 sZeelaOam_FallingOnWall_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(8, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27d, 8, 0),
    OAM_ENTRY(10, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27d, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(16, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x267, 8, 0)
};

static const u16 sZeelaOam_FallingOnWall_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27b, 8, 0),
    OAM_ENTRY(9, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27b, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24a, 8, 0)
};

static const u16 sZeelaOam_FallingOnWall_Frame7[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(9, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27a, 8, 0),
    OAM_ENTRY(8, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27a, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(0, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x24c, 8, 0)
};

static const u16 sZeelaEyesOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27f, 8, 0)
};

static const u16 sZeelaEyesOam_Spinning_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x268, 8, 0)
};

static const u16 sZeelaEyesOam_Spinning_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x270, 8, 0)
};

static const u16 sZeelaEyesOam_Exploding_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x25c, 8, 0)
};

static const u16 sZeelaEyesOam_Exploding_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(3, -11, OAM_DIMS_8x8, OAM_Y_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(3, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25d, 8, 0),
    OAM_ENTRY(-11, 3, OAM_DIMS_8x8, OAM_Y_FLIP, 0x25d, 8, 0)
};

static const u16 sZeelaEyesOam_Exploding_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-13, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25f, 8, 0),
    OAM_ENTRY(5, -13, OAM_DIMS_8x8, OAM_XY_FLIP, 0x25f, 8, 0),
    OAM_ENTRY(5, 5, OAM_DIMS_8x8, OAM_XY_FLIP, 0x25f, 8, 0),
    OAM_ENTRY(-13, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25f, 8, 0)
};

const struct FrameData sZeelaOam_OnGround[5] = {
    [0] = {
        .pFrame = sZeelaOam_OnGround_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sZeelaOam_OnGround_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sZeelaOam_OnGround_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sZeelaOam_OnGround_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaOam_TurningEdgeLeft[4] = {
    [0] = {
        .pFrame = sZeelaOam_TurningEdgeLeft_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZeelaOam_TurningEdgeLeft_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZeelaOam_TurningEdgeLeft_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaOam_TurningEdgeRight[4] = {
    [0] = {
        .pFrame = sZeelaOam_TurningEdgeLeft_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZeelaOam_TurningEdgeLeft_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZeelaOam_TurningEdgeLeft_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaOam_OnWall[5] = {
    [0] = {
        .pFrame = sZeelaOam_OnWall_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sZeelaOam_OnWall_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sZeelaOam_OnWall_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sZeelaOam_OnWall_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaOam_TurningCornerRight[4] = {
    [0] = {
        .pFrame = sZeelaOam_TurningCornerRight_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZeelaOam_TurningCornerRight_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZeelaOam_TurningCornerRight_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaOam_TurningCornerLeft[4] = {
    [0] = {
        .pFrame = sZeelaOam_TurningCornerLeft_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZeelaOam_TurningCornerLeft_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZeelaOam_TurningCornerLeft_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaOam_WalkingOnSlope[5] = {
    [0] = {
        .pFrame = sZeelaOam_WalkingOnSlope_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sZeelaOam_WalkingOnSlope_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sZeelaOam_WalkingOnSlope_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sZeelaOam_WalkingOnSlope_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaOam_FallingOnGround[9] = {
    [0] = {
        .pFrame = sZeelaOam_FallingOnGround_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sZeelaOam_FallingOnGround_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sZeelaOam_FallingOnGround_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sZeelaOam_FallingOnGround_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = {
        .pFrame = sZeelaOam_FallingOnGround_Frame4,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sZeelaOam_FallingOnGround_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [6] = {
        .pFrame = sZeelaOam_FallingOnGround_Frame6,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [7] = {
        .pFrame = sZeelaOam_FallingOnGround_Frame7,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaOam_FallingOnWall[9] = {
    [0] = {
        .pFrame = sZeelaOam_FallingOnWall_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sZeelaOam_FallingOnWall_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sZeelaOam_FallingOnWall_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sZeelaOam_FallingOnWall_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = {
        .pFrame = sZeelaOam_FallingOnWall_Frame4,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sZeelaOam_FallingOnWall_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [6] = {
        .pFrame = sZeelaOam_FallingOnWall_Frame6,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [7] = {
        .pFrame = sZeelaOam_FallingOnWall_Frame7,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaEyesOam_Idle[2] = {
    [0] = {
        .pFrame = sZeelaEyesOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaEyesOam_Spinning_Unused[5] = {
    [0] = {
        .pFrame = sZeelaEyesOam_Spinning_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [1] = {
        .pFrame = sZeelaEyesOam_Spinning_Unused_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sZeelaEyesOam_Spinning_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [3] = {
        .pFrame = sZeelaEyesOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZeelaEyesOam_Exploding[4] = {
    [0] = {
        .pFrame = sZeelaEyesOam_Exploding_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZeelaEyesOam_Exploding_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZeelaEyesOam_Exploding_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = FRAME_DATA_TERMINATOR
};
