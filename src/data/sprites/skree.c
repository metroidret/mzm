#include "data/sprites/skree.h"
#include "macros.h"

const s16 sSkreeFallingSpeed[8] = {
    PIXEL_SIZE / 2 * 1,
    PIXEL_SIZE / 2 * 2,
    PIXEL_SIZE / 2 * 3,
    PIXEL_SIZE / 2 * 4,
    PIXEL_SIZE / 2 * 6,
    PIXEL_SIZE / 2 * 7,
    PIXEL_SIZE / 2 * 8,
    SHORT_MAX
};

const u32 sSkreeGreenGfx[264] = INCBIN_U32("data/sprites/skree_green.gfx.lz");
const u16 sSkreeGreenPal[16] = INCBIN_U16("data/sprites/skree_green.pal");
const u32 sSkreeBlueGfx[264] = INCBIN_U32("data/sprites/skree_blue.gfx.lz");
const u16 sSkreeBluePal[16] = INCBIN_U16("data/sprites/skree_blue.pal");

static const u16 sSkreeOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, 16, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0)
};

static const u16 sSkreeOam_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0)
};

static const u16 sSkreeOam_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, 16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-12, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x211, 8, 0)
};

static const u16 sSkreeOam_Idle_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0)
};

static const u16 sSkreeOam_Spinning_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, 16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, 16, OAM_DIMS_16x8, OAM_X_FLIP, 0x20a, 8, 0)
};

static const u16 sSkreeOam_Spinning_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-16, 16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, 16, OAM_DIMS_16x8, OAM_X_FLIP, 0x206, 8, 0)
};

static const u16 sSkreeOam_CrashingUnused_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 0x202, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_XY_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x16, OAM_XY_FLIP, 0x202, 8, 0)
};

static const u16 sSkreeOam_CrashingUnused_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20e, 8, 0)
};

static const u16 sSkreeOam_CrashingUnused_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_Y_FLIP, 0x212, 8, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x211, 8, 0)
};

static const u16 sSkreeOam_CrashingUnused_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 0x215, 8, 0)
};

static const u16 sSkreeOam_CrashingUnused2_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_16x8, OAM_Y_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_XY_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x8, OAM_XY_FLIP, 0x20a, 8, 0)
};

static const u16 sSkreeOam_CrashingUnused2_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_16x8, OAM_Y_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_XY_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x8, OAM_XY_FLIP, 0x206, 8, 0)
};

static const u16 sSkreeExplosionOAM_GoingUp_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-5, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-5, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sSkreeExplosionOAM_GoingUp_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-5, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-5, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x238, 8, 0)
};

static const u16 sSkreeExplosionOAM_GoingUp_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x238, 8, 0)
};

static const u16 sSkreeExplosionOAM_GoingDown_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-6, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23a, 8, 0),
    OAM_ENTRY(-6, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0)
};

static const u16 sSkreeExplosionOAM_GoingDown_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-6, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21a, 8, 0)
};

static const u16 sSkreeExplosionOAM_GoingDown_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-6, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x219, 8, 0)
};

const struct FrameData sSkreeOam_Idle[5] = {
    [0] = {
        .pFrame = sSkreeOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sSkreeOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sSkreeOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sSkreeOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkreeOam_Spinning[6] = {
    [0] = {
        .pFrame = sSkreeOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sSkreeOam_Spinning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSkreeOam_Spinning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSkreeOam_Spinning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSkreeOam_Spinning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkreeOam_GoingDown[5] = {
    [0] = {
        .pFrame = sSkreeOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSkreeOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSkreeOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSkreeOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkreeOam_Crashing[5] = {
    [0] = {
        .pFrame = sSkreeOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSkreeOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSkreeOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSkreeOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkreeOam_CrashingUnused[5] = {
    [0] = {
        .pFrame = sSkreeOam_CrashingUnused_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sSkreeOam_CrashingUnused_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sSkreeOam_CrashingUnused_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sSkreeOam_CrashingUnused_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkreeOam_CrashingUnused2[6] = {
    [0] = {
        .pFrame = sSkreeOam_CrashingUnused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sSkreeOam_CrashingUnused2_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSkreeOam_CrashingUnused2_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSkreeOam_CrashingUnused2_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSkreeOam_CrashingUnused2_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkreeOam_CrashingUnused3[5] = {
    [0] = {
        .pFrame = sSkreeOam_CrashingUnused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSkreeOam_CrashingUnused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSkreeOam_CrashingUnused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSkreeOam_CrashingUnused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkreeOam_CrashingUnused4[5] = {
    [0] = {
        .pFrame = sSkreeOam_CrashingUnused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSkreeOam_CrashingUnused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSkreeOam_CrashingUnused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSkreeOam_CrashingUnused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkreeExplosionOAM_GoingDown[4] = {
    [0] = {
        .pFrame = sSkreeExplosionOAM_GoingDown_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sSkreeExplosionOAM_GoingDown_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sSkreeExplosionOAM_GoingDown_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSkreeExplosionOAM_GoingUp[4] = {
    [0] = {
        .pFrame = sSkreeExplosionOAM_GoingUp_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sSkreeExplosionOAM_GoingUp_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sSkreeExplosionOAM_GoingUp_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};
