#include "data/sprites/dessgeega.h"

#include "macros.h"

const s16 sDessgeegaHighJumpYVelocity[10] = {
    -8, -16, -16, -8, -4, 0, 4, 8, 16, 16
};

const s16 sDessgeegaLowJumpYVelocity[10] = {
    -4, -8, -4, -2, 0, 4, 8, 16, 16, 16 
};

const u32 sDessgeegaGfx[270] = INCBIN_U32("data/sprites/dessgeega.gfx.lz");
const u16 sDessgeegaPal[16] = INCBIN_U16("data/sprites/dessgeega.pal");

static const u16 sDessGeegaOam_Idle_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -23, OAM_DIMS_8x8, OAM_X_FLIP, 0x229, 8, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_8x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-22, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-22, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x224, 8, 0),
    OAM_ENTRY(6, -28, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(6, -12, OAM_DIMS_16x8, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x224, 8, 0)
};

static const u16 sDessGeegaOam_Idle_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-22, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-22, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, -27, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_16x8, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x200, 8, 0)
};

static const u16 sDessGeegaOam_Idle_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -26, OAM_DIMS_8x8, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-22, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-22, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(6, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(6, -10, OAM_DIMS_16x8, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x220, 8, 0)
};

static const u16 sDessGeegaOam_JumpWarning_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(0, -21, OAM_DIMS_8x8, OAM_X_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-22, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-22, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(6, -10, OAM_DIMS_16x8, OAM_X_FLIP, 0x204, 8, 0)
};

static const u16 sDessGeegaOam_JumpWarning_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x8, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_8x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-22, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x220, 8, 0),
    OAM_ENTRY(6, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x204, 8, 0)
};

static const u16 sDessGeegaOam_Landing_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -31, OAM_DIMS_8x8, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -31, OAM_DIMS_8x8, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(0, -23, OAM_DIMS_8x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-22, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(6, -13, OAM_DIMS_16x8, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-22, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-6, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(6, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-2, -27, OAM_DIMS_8x16, OAM_X_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-23, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(7, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x200, 8, 0)
};

static const u16 sDessGeegaOam_Jumping_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-8, -31, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -39, OAM_DIMS_8x8, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(0, -31, OAM_DIMS_8x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-22, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-20, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_16x8, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-22, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-6, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(6, -32, OAM_DIMS_16x16, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-2, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x219, 8, 0)
};

static const u16 sDessGeegaOam_Jumping_Frame1[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_8x8, OAM_X_FLIP, 0x209, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-22, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-20, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(6, -17, OAM_DIMS_16x8, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(4, -9, OAM_DIMS_16x8, OAM_X_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-22, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-6, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(6, -33, OAM_DIMS_16x16, OAM_X_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-2, -33, OAM_DIMS_8x16, OAM_X_FLIP, 0x219, 8, 0)
};

static const u16 sDessGeegaOam_Screaming_Frame1[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(0, -26, OAM_DIMS_8x8, OAM_X_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-22, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-22, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, -27, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_16x8, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-6, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-2, -18, OAM_DIMS_8x8, OAM_X_FLIP, 0x22a, 8, 0)
};

static const u16 sDessGeegaOam_Screaming_Frame2[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(0, -26, OAM_DIMS_8x8, OAM_X_FLIP, 0x211, 8, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x16, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-22, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-22, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(6, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(6, -10, OAM_DIMS_16x8, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-6, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-2, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x22a, 8, 0)
};

static const u16 sDessGeegaOam_Screaming_Frame3[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(0, -27, OAM_DIMS_8x8, OAM_X_FLIP, 0x213, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-23, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-23, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-22, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(7, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(7, -9, OAM_DIMS_16x8, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(6, -3, OAM_DIMS_16x8, OAM_X_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-7, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-1, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x22a, 8, 0)
};

static const u16 sDessGeegaOam_Screaming_Frame4[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(0, -27, OAM_DIMS_8x8, OAM_X_FLIP, 0x211, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-8, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-8, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-22, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-22, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(6, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(6, -10, OAM_DIMS_16x8, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-6, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-2, -17, OAM_DIMS_8x8, OAM_X_FLIP, 0x22a, 8, 0)
};

static const u16 sDessGeegaOam_Screaming_Frame5[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(0, -28, OAM_DIMS_8x8, OAM_X_FLIP, 0x213, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-23, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-23, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-23, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(7, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(7, -11, OAM_DIMS_16x8, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(7, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x220, 8, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x8, OAM_X_FLIP, 0x22a, 8, 0)
};

const struct FrameData sDessGeegaOam_Idle[5] = {
    [0] = {
        .pFrame = sDessGeegaOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sDessGeegaOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sDessGeegaOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sDessGeegaOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDessGeegaOam_Screaming[12] = {
    [0] = {
        .pFrame = sDessGeegaOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sDessGeegaOam_Screaming_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sDessGeegaOam_Screaming_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sDessGeegaOam_Screaming_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sDessGeegaOam_Screaming_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sDessGeegaOam_Screaming_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sDessGeegaOam_Screaming_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sDessGeegaOam_Screaming_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sDessGeegaOam_Screaming_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sDessGeegaOam_Screaming_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = {
        .pFrame = sDessGeegaOam_Screaming_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDessGeegaOam_JumpWarning[4] = {
    [0] = {
        .pFrame = sDessGeegaOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sDessGeegaOam_JumpWarning_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sDessGeegaOam_JumpWarning_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDessGeegaOam_Jumping[3] = {
    [0] = {
        .pFrame = sDessGeegaOam_Jumping_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sDessGeegaOam_Jumping_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDessGeegaOam_Landing[5] = {
    [0] = {
        .pFrame = sDessGeegaOam_Landing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sDessGeegaOam_JumpWarning_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sDessGeegaOam_JumpWarning_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sDessGeegaOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};
