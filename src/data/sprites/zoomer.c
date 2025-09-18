#include "data/sprites/zoomer.h"
#include "macros.h"

const u32 sZoomerGfx[379] = INCBIN_U32("data/sprites/Zoomer.gfx.lz");
const u16 sZoomerPal[32] = INCBIN_U16("data/sprites/Zoomer.pal");

static const u16 sZoomerOam_Falling_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(4, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 527, 8, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_8x8, OAM_X_FLIP, 527, 8, 0),
};

static const u16 sZoomerOam_Falling_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(4, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_8x8, OAM_X_FLIP, 528, 8, 0),
};

static const u16 sZoomerOam_Falling_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 517, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 559, 8, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_8x8, OAM_X_FLIP, 559, 8, 0),
};

static const u16 sZoomerOam_OnGround_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(4, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_8x8, OAM_X_FLIP, 551, 8, 0),
};

static const u16 sZoomerOam_OnGround_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(4, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_8x8, OAM_X_FLIP, 552, 8, 0),
};

static const u16 sZoomerOam_OnGround_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 517, 8, 0),
    OAM_ENTRY(4, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 551, 8, 0),
    OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
};

static const u16 sZoomerOam_OnGround_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 552, 8, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_8x8, OAM_X_FLIP, 520, 8, 0),
};

static const u16 sZoomerOam_TurningEdgeLeft_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 529, 8, 0),
    OAM_ENTRY(-9, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 535, 8, 0),
    OAM_ENTRY(7, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
};

static const u16 sZoomerOam_TurningEdgeLeft_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(11, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sZoomerOam_TurningEdgeLeft_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 533, 8, 0),
    OAM_ENTRY(-6, -15, OAM_DIMS_16x8, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(10, -7, OAM_DIMS_8x16, OAM_NO_FLIP, 541, 8, 0),
};

static const u16 sZoomerOam_OnWall_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(1, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 569, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(0, 1, OAM_DIMS_8x8, OAM_Y_FLIP, 574, 8, 0),
};

static const u16 sZoomerOam_OnWall_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(2, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(2, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 569, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(0, 1, OAM_DIMS_8x8, OAM_Y_FLIP, 575, 8, 0),
};

static const u16 sZoomerOam_OnWall_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 525, 8, 0),
    OAM_ENTRY(1, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 569, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 574, 8, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_8x8, OAM_Y_FLIP, 542, 8, 0),
};

static const u16 sZoomerOam_OnWall_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 569, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 575, 8, 0),
    OAM_ENTRY(0, 1, OAM_DIMS_8x8, OAM_Y_FLIP, 543, 8, 0),
};

static const u16 sZoomerOam_TurningCornerRight_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 529, 8, 0),
    OAM_ENTRY(-9, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 535, 8, 0),
    OAM_ENTRY(7, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
};

static const u16 sZoomerOam_TurningCornerRight_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-10, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-10, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(6, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sZoomerOam_TurningCornerRight_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-11, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 533, 8, 0),
    OAM_ENTRY(-11, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(5, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 541, 8, 0),
};

static const u16 sZoomerOam_TurningCornerLeft_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-2, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 533, 8, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(14, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 541, 8, 0),
};

static const u16 sZoomerOam_TurningCornerLeft_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sZoomerOam_TurningCornerLeft_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 529, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 535, 8, 0),
    OAM_ENTRY(15, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
};

static const u16 sZoomerOam_WalkingOnLeftSlope_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-10, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 578, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 580, 8, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 579, 8, 0),
};

static const u16 sZoomerOam_WalkingOnLeftSlope_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-10, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(6, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 578, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 582, 8, 0),
};

static const u16 sZoomerOam_WalkingOnLeftSlope_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(7, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 578, 8, 0),
    OAM_ENTRY(-7, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 584, 8, 0),
};

static const u16 sZoomerOam_WalkingOnLeftSlope_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(7, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 578, 8, 0),
    OAM_ENTRY(-9, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 586, 8, 0),
};

static const u16 sZoomerOam_WalkingOnRightSlope_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -16, OAM_DIMS_16x16, OAM_X_FLIP, 576, 8, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x16, OAM_X_FLIP, 578, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_X_FLIP, 580, 8, 0),
    OAM_ENTRY(8, -10, OAM_DIMS_8x8, OAM_X_FLIP, 579, 8, 0),
};

static const u16 sZoomerOam_WalkingOnRightSlope_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -15, OAM_DIMS_16x16, OAM_X_FLIP, 576, 8, 0),
    OAM_ENTRY(-14, -15, OAM_DIMS_8x16, OAM_X_FLIP, 578, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_X_FLIP, 582, 8, 0),
};

static const u16 sZoomerOam_WalkingOnRightSlope_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -15, OAM_DIMS_16x16, OAM_X_FLIP, 576, 8, 0),
    OAM_ENTRY(-15, -15, OAM_DIMS_8x16, OAM_X_FLIP, 578, 8, 0),
    OAM_ENTRY(-9, -10, OAM_DIMS_16x16, OAM_X_FLIP, 584, 8, 0),
};

static const u16 sZoomerOam_WalkingOnRightSlope_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -16, OAM_DIMS_16x16, OAM_X_FLIP, 576, 8, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_8x16, OAM_X_FLIP, 578, 8, 0),
    OAM_ENTRY(-7, -10, OAM_DIMS_16x16, OAM_X_FLIP, 586, 8, 0),
};

const struct FrameData sZoomerOam_Falling[5] = {
    [0] = {
        .pFrame = sZoomerOam_Falling_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZoomerOam_Falling_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZoomerOam_Falling_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sZoomerOam_Falling_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoomerOam_OnGround[5] = {
    [0] = {
        .pFrame = sZoomerOam_OnGround_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZoomerOam_OnGround_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZoomerOam_OnGround_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sZoomerOam_OnGround_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoomerOam_TurningEdgeLeft[4] = {
    [0] = {
        .pFrame = sZoomerOam_TurningEdgeLeft_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZoomerOam_TurningEdgeLeft_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZoomerOam_TurningEdgeLeft_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoomerOam_TurningEdgeRight[4] = {
    [0] = {
        .pFrame = sZoomerOam_TurningEdgeLeft_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZoomerOam_TurningEdgeLeft_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZoomerOam_TurningEdgeLeft_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoomerOam_OnWall[5] = {
    [0] = {
        .pFrame = sZoomerOam_OnWall_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZoomerOam_OnWall_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZoomerOam_OnWall_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sZoomerOam_OnWall_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoomerOam_TurningCornerRight[4] = {
    [0] = {
        .pFrame = sZoomerOam_TurningCornerRight_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZoomerOam_TurningCornerRight_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZoomerOam_TurningCornerRight_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoomerOam_TurningCornerLeft[4] = {
    [0] = {
        .pFrame = sZoomerOam_TurningCornerLeft_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZoomerOam_TurningCornerLeft_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZoomerOam_TurningCornerLeft_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoomerOam_WalkingOnLeftSlope[5] = {
    [0] = {
        .pFrame = sZoomerOam_WalkingOnLeftSlope_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZoomerOam_WalkingOnLeftSlope_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZoomerOam_WalkingOnLeftSlope_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sZoomerOam_WalkingOnLeftSlope_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZoomerOam_WalkingOnRightSlope[5] = {
    [0] = {
        .pFrame = sZoomerOam_WalkingOnRightSlope_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZoomerOam_WalkingOnRightSlope_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZoomerOam_WalkingOnRightSlope_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sZoomerOam_WalkingOnRightSlope_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};
