#include "data/sprites/zeela.h"
#include "macros.h"

const s16 sZeelaEyesFallingFromUpSpeed[16] = {
    -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, SHORT_MAX
};

const s16 sZeelaEyesFallingFromBottomSpeed[12] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, SHORT_MAX
};

const u32 sZeelaGfx[578] = INCBIN_U32("data/sprites/Zeela.gfx.lz");
const u16 sZeelaPal[32] = INCBIN_U16("data/sprites/Zeela.pal");

static const u16 sZeelaOam_OnGround_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sZeelaOam_OnGround_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 517, 8, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 614, 8, 0),
};

static const u16 sZeelaOam_OnGround_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 578, 8, 0),
};

static const u16 sZeelaOam_OnGround_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 579, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 581, 8, 0),
};

static const u16 sZeelaOam_TurningEdgeLeft_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 558, 8, 0),
    OAM_ENTRY(4, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 560, 8, 0),
    OAM_ENTRY(-4, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 527, 8, 0),
};

static const u16 sZeelaOam_TurningEdgeLeft_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(8, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 602, 8, 0),
};

static const u16 sZeelaOam_TurningEdgeLeft_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(7, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(-1, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 606, 8, 0),
};

static const u16 sZeelaOam_OnWall_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 582, 8, 0),
};

static const u16 sZeelaOam_OnWall_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 584, 8, 0),
    OAM_ENTRY(16, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 615, 8, 0),
};

static const u16 sZeelaOam_OnWall_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(0, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 586, 8, 0),
};

static const u16 sZeelaOam_OnWall_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(0, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 588, 8, 0),
};

static const u16 sZeelaOam_TurningCornerRight_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 558, 8, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 560, 8, 0),
    OAM_ENTRY(-4, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 527, 8, 0),
};

static const u16 sZeelaOam_TurningCornerRight_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-12, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 602, 8, 0),
};

static const u16 sZeelaOam_TurningCornerRight_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(-6, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 606, 8, 0),
};

static const u16 sZeelaOam_TurningCornerLeft_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(10, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(2, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 606, 8, 0),
};

static const u16 sZeelaOam_TurningCornerLeft_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(11, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-5, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 602, 8, 0),
};

static const u16 sZeelaOam_TurningCornerLeft_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 558, 8, 0),
    OAM_ENTRY(10, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 560, 8, 0),
    OAM_ENTRY(2, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 527, 8, 0),
};

static const u16 sZeelaOam_WalkingOnSlope_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 558, 8, 0),
    OAM_ENTRY(2, -14, OAM_DIMS_8x16, OAM_NO_FLIP, 560, 8, 0),
    OAM_ENTRY(-6, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 527, 8, 0),
};

static const u16 sZeelaOam_WalkingOnSlope_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-13, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 529, 8, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-5, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 594, 8, 0),
};

static const u16 sZeelaOam_WalkingOnSlope_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 534, 8, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 597, 8, 0),
};

static const u16 sZeelaOam_WalkingOnSlope_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-13, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(3, -12, OAM_DIMS_8x16, OAM_NO_FLIP, 569, 8, 0),
    OAM_ENTRY(-5, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sZeelaOam_FallingOnGround_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 616, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sZeelaOam_FallingOnGround_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 618, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 517, 8, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 614, 8, 0),
};

static const u16 sZeelaOam_FallingOnGround_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 578, 8, 0),
};

static const u16 sZeelaOam_FallingOnGround_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 630, 8, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 579, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 581, 8, 0),
};

static const u16 sZeelaOam_FallingOnGround_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 624, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sZeelaOam_FallingOnGround_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 626, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 517, 8, 0),
    OAM_ENTRY(2, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 614, 8, 0),
};

static const u16 sZeelaOam_FallingOnGround_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 620, 8, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 578, 8, 0),
};

static const u16 sZeelaOam_FallingOnGround_Frame7[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 622, 8, 0),
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 579, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 581, 8, 0),
};

static const u16 sZeelaOam_FallingOnWall_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(9, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 633, 8, 0),
    OAM_ENTRY(9, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 633, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 582, 8, 0),
};

static const u16 sZeelaOam_FallingOnWall_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(8, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 634, 8, 0),
    OAM_ENTRY(10, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 634, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 584, 8, 0),
    OAM_ENTRY(16, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 615, 8, 0),
};

static const u16 sZeelaOam_FallingOnWall_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 638, 8, 0),
    OAM_ENTRY(9, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 638, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(0, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 586, 8, 0),
};

static const u16 sZeelaOam_FallingOnWall_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(9, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 637, 8, 0),
    OAM_ENTRY(8, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 637, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(0, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 588, 8, 0),
};

static const u16 sZeelaOam_FallingOnWall_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(9, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(9, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 582, 8, 0),
};

static const u16 sZeelaOam_FallingOnWall_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(8, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 637, 8, 0),
    OAM_ENTRY(10, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 637, 8, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 584, 8, 0),
    OAM_ENTRY(16, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 615, 8, 0),
};

static const u16 sZeelaOam_FallingOnWall_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 635, 8, 0),
    OAM_ENTRY(9, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 635, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(0, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 586, 8, 0),
};

static const u16 sZeelaOam_FallingOnWall_Frame7[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(9, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 634, 8, 0),
    OAM_ENTRY(8, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 634, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(0, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 588, 8, 0),
};

static const u16 sZeelaEyesOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 639, 8, 0),
};

static const u16 sZeelaEyesOam_Spinning_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 616, 8, 0),
};

static const u16 sZeelaEyesOam_Spinning_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 624, 8, 0),
};

static const u16 sZeelaEyesOam_Exploding_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 604, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 604, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_X_FLIP, 604, 8, 0),
};

static const u16 sZeelaEyesOam_Exploding_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 605, 8, 0),
    OAM_ENTRY(3, -11, OAM_DIMS_8x8, OAM_Y_FLIP, 605, 8, 0),
    OAM_ENTRY(3, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 605, 8, 0),
    OAM_ENTRY(-11, 3, OAM_DIMS_8x8, OAM_Y_FLIP, 605, 8, 0),
};

static const u16 sZeelaEyesOam_Exploding_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-13, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 607, 8, 0),
    OAM_ENTRY(5, -13, OAM_DIMS_8x8, OAM_XY_FLIP, 607, 8, 0),
    OAM_ENTRY(5, 5, OAM_DIMS_8x8, OAM_XY_FLIP, 607, 8, 0),
    OAM_ENTRY(-13, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 607, 8, 0),
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
