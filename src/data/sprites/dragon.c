#include "data/sprites/dragon.h"

#include "macros.h"

const s16 sDragonFireballYMovement[40] = {
    -12, -12, -12, -12, -10, -10, -10, -10, -8, -8, -8, -8,
    -6, -6, -6, -6, -5, -5, -4, -4, -3, -2, -1, 0, 1, 2, 3,
    4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16, 18, SHORT_MAX
};

const s16 sDragonFireballOamRotation[40] = {
    0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 6, 8, 10, 12, 14, 16, 16,
    20, 24, 28, 29, 30, 31, 32, 33, 34, 35, 36, 40, 44, 48,
    52, 56, 60, 64, 64, 64, 64, 64, SHORT_MAX
};

const u32 sDragonGfx[512] = INCBIN_U32("data/sprites/Dragon.gfx.lz");
const u16 sDragonPal[16 * 2] = INCBIN_U16("data/sprites/Dragon.pal");

static const u16 sDragonOam_Spitting_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -26, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-10, 3, OAM_DIMS_16x32, OAM_NO_FLIP, 525, 8, 0),
};

static const u16 sDragonOam_Spitting_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-15, -27, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-9, 3, OAM_DIMS_16x32, OAM_NO_FLIP, 525, 8, 0),
};

static const u16 sDragonOam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-9, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 587, 8, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sDragonOam_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -22, OAM_DIMS_32x32, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-9, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 587, 8, 0),
};

static const u16 sDragonOam_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_8x32, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 581, 8, 0),
    OAM_ENTRY(-9, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 587, 8, 0),
};

static const u16 sDragonOam_TurningAround_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -23, OAM_DIMS_32x32, OAM_NO_FLIP, 527, 8, 0),
    OAM_ENTRY(-7, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 533, 8, 0),
};

static const u16 sDragonOam_TurningAround_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -22, OAM_DIMS_16x32, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-7, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 597, 8, 0),
};

static const u16 sDragonOam_Unused_0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -22, OAM_DIMS_16x32, OAM_X_FLIP, 531, 8, 0),
    OAM_ENTRY(-4, 5, OAM_DIMS_16x16, OAM_X_FLIP, 597, 8, 0),
};

static const u16 sDragonOam_Unused_1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -23, OAM_DIMS_32x32, OAM_X_FLIP, 527, 8, 0),
    OAM_ENTRY(-5, 5, OAM_DIMS_16x16, OAM_X_FLIP, 533, 8, 0),
};

static const u16 sDragonFireballOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 602, 8, 0),
};

static const u16 sDragonFireballOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 604, 8, 0),
};

static const u16 sDragonFireballOam_Moving_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 606, 8, 0),
};

static const u16 sDragonFireballOam_Exploding_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 8, 0),
};

static const u16 sDragonFireballOam_Exploding_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sDragonFireballOam_Exploding_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 542, 8, 0),
};

static const u16 sDragonFireballOam_Exploding_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 542, 9, 0),
};

const struct FrameData sDragonOam_Idle[4] = {
    [0] = {
        .pFrame = sDragonOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(.2f)
    },
    [1] = {
        .pFrame = sDragonOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(.2f)
    },
    [2] = {
        .pFrame = sDragonOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(.2f)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDragonOam_Warning[3] = {
    [0] = {
        .pFrame = sDragonOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sDragonOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDragonOam_Spitting[3] = {
    [0] = {
        .pFrame = sDragonOam_Spitting_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sDragonOam_Spitting_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDragonOam_TurningAround[3] = {
    [0] = {
        .pFrame = sDragonOam_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sDragonOam_TurningAround_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDragonOam_TurningAroundPart2[3] = {
    [0] = {
        .pFrame = sDragonOam_TurningAround_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sDragonOam_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDragonFireballOam_Moving[4] = {
    [0] = {
        .pFrame = sDragonFireballOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sDragonFireballOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sDragonFireballOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDragonFireballOam_Exploding[5] = {
    [0] = {
        .pFrame = sDragonFireballOam_Exploding_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sDragonFireballOam_Exploding_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sDragonFireballOam_Exploding_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sDragonFireballOam_Exploding_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};
