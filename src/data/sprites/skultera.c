#include "data/sprites/skultera.h"
#include "macros.h"

const u32 sSkulteraGfx[285] = INCBIN_U32("data/sprites/Skultera.gfx.lz");
const u16 sSkulteraPal[16] = INCBIN_U16("data/sprites/Skultera.pal");

static const u16 sSkulteraOam_Idle_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-17, -31, OAM_DIMS_32x16, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-17, -15, OAM_DIMS_32x8, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 563, 8, 0),
    OAM_ENTRY(1, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(5, -12, OAM_DIMS_8x8, OAM_Y_FLIP, 513, 8, 0),
    OAM_ENTRY(11, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sSkulteraOam_Idle_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-26, -31, OAM_DIMS_32x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-25, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 566, 8, 0),
    OAM_ENTRY(-26, -15, OAM_DIMS_32x8, OAM_NO_FLIP, 534, 8, 0),
    OAM_ENTRY(-1, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(10, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 549, 8, 0),
};

static const u16 sSkulteraOam_Idle_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-26, -31, OAM_DIMS_32x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-26, -15, OAM_DIMS_32x16, OAM_NO_FLIP, 534, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_8x8, OAM_Y_FLIP, 513, 8, 0),
    OAM_ENTRY(7, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(11, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 517, 8, 0),
};

static const u16 sSkulteraOam_Idle_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-18, -30, OAM_DIMS_32x16, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-18, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(1, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(5, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(10, -14, OAM_DIMS_8x8, OAM_Y_FLIP, 549, 8, 0),
};

static const u16 sSkulteraOam_TurningAround_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-26, -31, OAM_DIMS_32x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-25, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 566, 8, 0),
    OAM_ENTRY(-26, -15, OAM_DIMS_32x8, OAM_NO_FLIP, 534, 8, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(6, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(11, -12, OAM_DIMS_8x8, OAM_Y_FLIP, 549, 8, 0),
};

static const u16 sSkulteraOam_TurningAround_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-14, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 526, 8, 0),
    OAM_ENTRY(-14, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(2, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 562, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(1, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(6, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSkulteraOam_TurningAround_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(-2, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(3, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 517, 8, 0),
};

static const u16 sSkulteraOam_TurningAround_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -31, OAM_DIMS_16x16, OAM_X_FLIP, 526, 8, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_16x16, OAM_X_FLIP, 538, 8, 0),
    OAM_ENTRY(-19, -15, OAM_DIMS_8x8, OAM_X_FLIP, 512, 8, 0),
    OAM_ENTRY(-3, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 515, 8, 0),
};

static const u16 sSkulteraOam_TurningAround_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -31, OAM_DIMS_32x16, OAM_X_FLIP, 522, 8, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_32x16, OAM_X_FLIP, 534, 8, 0),
    OAM_ENTRY(-18, -15, OAM_DIMS_8x8, OAM_X_FLIP, 513, 8, 0),
};

static const u16 sSkulteraOam_TurningAround_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-21, -30, OAM_DIMS_32x16, OAM_X_FLIP, 519, 8, 0),
    OAM_ENTRY(-21, -14, OAM_DIMS_32x16, OAM_X_FLIP, 531, 8, 0),
    OAM_ENTRY(-15, -12, OAM_DIMS_8x8, OAM_X_FLIP, 514, 8, 0),
    OAM_ENTRY(-18, -15, OAM_DIMS_8x8, OAM_X_FLIP, 512, 8, 0),
};

static const u16 sSkulteraOam_TurningAround_Frame6[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-18, -31, OAM_DIMS_32x16, OAM_X_FLIP, 519, 8, 0),
    OAM_ENTRY(-18, -15, OAM_DIMS_32x8, OAM_X_FLIP, 531, 8, 0),
    OAM_ENTRY(-19, -7, OAM_DIMS_32x8, OAM_X_FLIP, 563, 8, 0),
    OAM_ENTRY(-12, -15, OAM_DIMS_8x8, OAM_X_FLIP, 512, 8, 0),
    OAM_ENTRY(-17, -12, OAM_DIMS_8x8, OAM_X_FLIP, 514, 8, 0),
    OAM_ENTRY(-19, -14, OAM_DIMS_8x8, OAM_X_FLIP, 516, 8, 0),
};

static const u16 sSkulteraOam_TurningAround_Frame7[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-6, -31, OAM_DIMS_32x16, OAM_X_FLIP, 522, 8, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_32x8, OAM_X_FLIP, 566, 8, 0),
    OAM_ENTRY(-6, -15, OAM_DIMS_32x8, OAM_X_FLIP, 534, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_X_FLIP, 514, 8, 0),
    OAM_ENTRY(-13, -15, OAM_DIMS_8x8, OAM_X_FLIP, 512, 8, 0),
    OAM_ENTRY(-18, -14, OAM_DIMS_8x8, OAM_X_FLIP, 517, 8, 0),
};


const struct FrameData sSkulteraOam_Idle[5] = {
    [0] = {
        .pFrame = sSkulteraOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sSkulteraOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sSkulteraOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sSkulteraOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkulteraOam_TurningAround[9] = {
    [0] = {
        .pFrame = sSkulteraOam_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(13.f / 60)
    },
    [1] = {
        .pFrame = sSkulteraOam_TurningAround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sSkulteraOam_TurningAround_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sSkulteraOam_TurningAround_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sSkulteraOam_TurningAround_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sSkulteraOam_TurningAround_Frame5,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sSkulteraOam_TurningAround_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [7] = {
        .pFrame = sSkulteraOam_TurningAround_Frame7,
        .timer = CONVERT_SECONDS(13.f / 60)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkulteraOam_ChasingSamus[5] = {
    [0] = {
        .pFrame = sSkulteraOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sSkulteraOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sSkulteraOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sSkulteraOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};
