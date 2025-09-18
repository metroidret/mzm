#include "data/sprites/squeept.h"
#include "macros.h"

const s16 sSqueeptRisingMovement[65] = {
    -18, -18, -18, -18, -16, -16, -16, -16, -14,
    -14, -14, -14, -12, -12, -12, -12, -12, -12,
    -12, -12, -11, -11, -11, -11, -10, -10, -10,
    -10, -9, -9, -9, -9, -8, -8, -8, -8, -8, -8,
    -8, -8, -7, -7, -7, -7, -6, -6, -6, -6, -5,
    -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -3,
    -2, -2, -2, -2, SHORT_MAX
};

const s16 sSqueeptFallingMovement[16] = {
    4, 4, 4, 6, 6, 8, 8, 10, 10, 12, 12, 14,
    14, 16, 16, SHORT_MAX
};

const u32 sSqueeptGfx[263] = INCBIN_U32("data/sprites/Squeept.gfx.lz");
const u16 sSqueeptPal[16] = INCBIN_U16("data/sprites/Squeept.pal");

static const u16 sSqueeptOam_GoingUp_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 557, 8, 0),
    OAM_ENTRY(-1, 3, OAM_DIMS_8x8, OAM_X_FLIP, 557, 8, 0),
    OAM_ENTRY(-16, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-15, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-7, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-1, -13, OAM_DIMS_16x16, OAM_X_FLIP, 512, 8, 0),
    OAM_ENTRY(6, -1, OAM_DIMS_8x16, OAM_X_FLIP, 518, 8, 0),
    OAM_ENTRY(-2, -1, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
};

static const u16 sSqueeptOam_GoingUp_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-16, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-1, -14, OAM_DIMS_16x16, OAM_X_FLIP, 514, 8, 0),
    OAM_ENTRY(-16, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-8, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(7, -1, OAM_DIMS_8x16, OAM_X_FLIP, 518, 8, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
    OAM_ENTRY(-4, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 527, 8, 0),
};

static const u16 sSqueeptOam_GoingUp_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-16, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-1, -14, OAM_DIMS_16x16, OAM_X_FLIP, 516, 8, 0),
    OAM_ENTRY(-16, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-8, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(7, -1, OAM_DIMS_8x16, OAM_X_FLIP, 518, 8, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
    OAM_ENTRY(-4, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 526, 8, 0),
};

static const u16 sSqueeptOam_GoingUp_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-15, -1, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-7, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-1, -13, OAM_DIMS_16x16, OAM_X_FLIP, 512, 8, 0),
    OAM_ENTRY(6, -1, OAM_DIMS_8x16, OAM_X_FLIP, 518, 8, 0),
    OAM_ENTRY(-2, -1, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
};

static const u16 sSqueeptOam_GoingUp_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-1, -13, OAM_DIMS_16x16, OAM_X_FLIP, 514, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(7, 0, OAM_DIMS_8x16, OAM_X_FLIP, 518, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
};

static const u16 sSqueeptOam_GoingUp_Frame5[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-1, -13, OAM_DIMS_16x16, OAM_X_FLIP, 516, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(7, 0, OAM_DIMS_8x16, OAM_X_FLIP, 518, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
};

static const u16 sSqueeptOam_TurningAround_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 525, 8, 0),
    OAM_ENTRY(-1, -13, OAM_DIMS_16x16, OAM_X_FLIP, 520, 8, 0),
    OAM_ENTRY(7, 3, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
};

static const u16 sSqueeptOam_TurningAround_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_X_FLIP, 522, 8, 0),
};

static const u16 sSqueeptOam_TurningAround_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 522, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 522, 8, 0),
};

static const u16 sSqueeptOam_TurningAround_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -9, OAM_DIMS_16x16, OAM_Y_FLIP, 520, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_8x8, OAM_Y_FLIP, 525, 8, 0),
    OAM_ENTRY(-1, -9, OAM_DIMS_16x16, OAM_XY_FLIP, 520, 8, 0),
    OAM_ENTRY(7, -17, OAM_DIMS_8x8, OAM_XY_FLIP, 525, 8, 0),
};

static const u16 sSqueeptOam_TurningAround_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_Y_FLIP, 512, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_8x16, OAM_Y_FLIP, 518, 8, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_8x8, OAM_Y_FLIP, 519, 8, 0),
    OAM_ENTRY(-1, -4, OAM_DIMS_16x16, OAM_XY_FLIP, 512, 8, 0),
    OAM_ENTRY(7, -17, OAM_DIMS_8x16, OAM_XY_FLIP, 518, 8, 0),
    OAM_ENTRY(-1, -9, OAM_DIMS_8x8, OAM_XY_FLIP, 519, 8, 0),
};

static const u16 sSqueeptOam_GoingDown_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -3, OAM_DIMS_16x16, OAM_Y_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-1, -3, OAM_DIMS_16x16, OAM_XY_FLIP, 512, 8, 0),
    OAM_ENTRY(-1, -16, OAM_DIMS_8x16, OAM_X_FLIP, 524, 8, 0),
};

static const u16 sSqueeptOam_GoingDown_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_Y_FLIP, 512, 8, 0),
    OAM_ENTRY(-9, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-1, -4, OAM_DIMS_16x16, OAM_XY_FLIP, 512, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_8x16, OAM_X_FLIP, 524, 8, 0),
};

const struct FrameData sSqueeptOam_TurningAround[6] = {
    [0] = {
        .pFrame = sSqueeptOam_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [1] = {
        .pFrame = sSqueeptOam_TurningAround_Frame1,
        .timer = CONVERT_SECONDS(0.15f)
    },
    [2] = {
        .pFrame = sSqueeptOam_TurningAround_Frame2,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [3] = {
        .pFrame = sSqueeptOam_TurningAround_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sSqueeptOam_TurningAround_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSqueeptOam_TurningAround_Unused[6] = {
    [0] = {
        .pFrame = sSqueeptOam_TurningAround_Frame4,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [1] = {
        .pFrame = sSqueeptOam_TurningAround_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sSqueeptOam_TurningAround_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sSqueeptOam_TurningAround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSqueeptOam_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSqueeptOam_GoingDown[3] = {
    [0] = {
        .pFrame = sSqueeptOam_GoingDown_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sSqueeptOam_GoingDown_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSqueeptOam_GoingUp[8] = {
    [0] = {
        .pFrame = sSqueeptOam_GoingUp_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSqueeptOam_GoingUp_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSqueeptOam_GoingUp_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSqueeptOam_GoingUp_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSqueeptOam_GoingUp_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSqueeptOam_GoingUp_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sSqueeptOam_GoingUp_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = FRAME_DATA_TERMINATOR
};
