#include "data/sprites/power_grip.h"
#include "macros.h"

const u32 sPowerGripGfx[279] = INCBIN_U32("data/sprites/power_grip.gfx.lz");
const u16 sPowerGripPal[32] = INCBIN_U16("data/sprites/power_grip.pal");

static const u16 sPowerGripOAM_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sPowerGripOAM_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0)
};

static const u16 sPowerGripOAM_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sPowerGripGlowOAM_Idle_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x208, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x208, 9, 0)
};

static const u16 sPowerGripGlowOAM_Idle_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20a, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x20c, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20c, 9, 0)
};

static const u16 sPowerGripGlowOAM_Idle_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20e, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x210, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x210, 9, 0)
};

static const u16 sPowerGripGlowOAM_Idle_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x214, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x214, 9, 0)
};

static const u16 sPowerGripGlowOAM_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x216, 9, 0)
};

const struct FrameData sPowerGripOAM_Idle[5] = {
    [0] = {
        .pFrame = sPowerGripOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sPowerGripOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sPowerGripOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sPowerGripOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPowerGripGlowOAM_Idle[15] = {
    [0] = {
        .pFrame = sPowerGripGlowOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sPowerGripGlowOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sPowerGripGlowOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sPowerGripGlowOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sPowerGripGlowOAM_Idle_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sPowerGripGlowOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sPowerGripGlowOAM_Idle_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sPowerGripGlowOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sPowerGripGlowOAM_Idle_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sPowerGripGlowOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sPowerGripGlowOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sPowerGripGlowOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = {
        .pFrame = sPowerGripGlowOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sPowerGripGlowOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [14] = FRAME_DATA_TERMINATOR
};
