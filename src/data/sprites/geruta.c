#include "data/sprites/geruta.h"
#include "macros.h"

const u32 sGerutaRedGfx[321] = INCBIN_U32("data/sprites/geruta_red.gfx.lz");
const u16 sGerutaRedPal[16] = INCBIN_U16("data/sprites/geruta_red.pal");
const u32 sGerutaGreenGfx[308] = INCBIN_U32("data/sprites/geruta_green.gfx.lz");
const u16 sGerutaGreenPal[16] = INCBIN_U16("data/sprites/geruta_green.pal");

static const u16 sGerutaOam_Idle_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-23, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(5, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(1, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-17, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0)
};

static const u16 sGerutaOam_Idle_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, -13, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-23, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0)
};

static const u16 sGerutaOam_Warning_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-23, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(2, -5, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-19, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0)
};

static const u16 sGerutaOam_Warning_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-22, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(5, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-21, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(5, -6, OAM_DIMS_16x16, OAM_X_FLIP, 0x210, 8, 0)
};

static const u16 sGerutaOam_Launching_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-2, -3, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-15, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(6, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-23, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0)
};

static const u16 sGerutaOam_Launching_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-2, -6, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-15, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-23, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0)
};

static const u16 sGerutaOam_Launching_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(5, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-23, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-2, -13, OAM_DIMS_16x16, OAM_XY_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-15, -13, OAM_DIMS_16x16, OAM_Y_FLIP, 0x212, 8, 0)
};

static const u16 sGerutaOam_Launching_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-2, -14, OAM_DIMS_16x16, OAM_XY_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-15, -13, OAM_DIMS_16x16, OAM_Y_FLIP, 0x212, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-23, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0)
};

static const u16 sGerutaOam_GoingDown_Frame0[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-10, -14, OAM_DIMS_8x8, OAM_Y_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(3, -14, OAM_DIMS_8x8, OAM_Y_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-21, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-11, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(0, -3, OAM_DIMS_8x8, OAM_X_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-14, -12, OAM_DIMS_16x16, OAM_Y_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-2, -12, OAM_DIMS_16x16, OAM_XY_FLIP, 0x214, 8, 0)
};

static const u16 sGerutaOam_GoingDown_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-22, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-11, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-11, -19, OAM_DIMS_8x16, OAM_XY_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(3, -19, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-14, -12, OAM_DIMS_16x16, OAM_Y_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-2, -12, OAM_DIMS_16x16, OAM_XY_FLIP, 0x214, 8, 0)
};

static const u16 sGerutaOam_GoingDown_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-21, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-11, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(2, -2, OAM_DIMS_8x8, OAM_X_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-14, -12, OAM_DIMS_16x16, OAM_Y_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-3, -12, OAM_DIMS_16x16, OAM_XY_FLIP, 0x214, 8, 0)
};

static const u16 sGerutaOam_GoingDown_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(2, -16, OAM_DIMS_8x8, OAM_Y_FLIP, 0x23b, 8, 0),
    OAM_ENTRY(-10, -15, OAM_DIMS_8x8, OAM_Y_FLIP, 0x23b, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-23, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-12, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-3, -14, OAM_DIMS_16x16, OAM_XY_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-14, -13, OAM_DIMS_16x16, OAM_Y_FLIP, 0x214, 8, 0)
};

static const u16 sGerutaOam_Bouncing_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-23, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(5, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0)
};

static const u16 sGerutaOam_Bouncing_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(6, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-23, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-13, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23b, 8, 0),
    OAM_ENTRY(6, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23b, 8, 0),
    OAM_ENTRY(-16, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(0, -3, OAM_DIMS_16x16, OAM_X_FLIP, 0x210, 8, 0)
};

static const u16 sGerutaOam_GoingUp_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(5, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-22, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-2, -1, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-15, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-12, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(4, 10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0)
};

static const u16 sGerutaOam_GoingUp_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(5, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-15, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-12, 5, OAM_DIMS_8x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(3, 6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21c, 8, 0)
};

static const u16 sGerutaOam_GoingUp_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(5, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-22, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-2, -1, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-15, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-12, 9, OAM_DIMS_8x16, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(3, 10, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0)
};

static const u16 sGerutaOam_GoingUp_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(5, -7, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-15, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-11, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23b, 8, 0),
    OAM_ENTRY(3, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23b, 8, 0)
};

static const u16 sGerutaOam_BouncingOnCeiling_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-21, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(4, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-2, -5, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-15, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0)
};

static const u16 sGerutaOam_BouncingOnCeiling_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-23, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(6, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-1, -4, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-17, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0)
};

const struct FrameData sGerutaOam_Idle[3] = {
    [0] = {
        .pFrame = sGerutaOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sGerutaOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerutaOam_Warning[4] = {
    [0] = {
        .pFrame = sGerutaOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGerutaOam_Warning_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sGerutaOam_Warning_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerutaOam_Launching[5] = {
    [0] = {
        .pFrame = sGerutaOam_Launching_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sGerutaOam_Launching_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sGerutaOam_Launching_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sGerutaOam_Launching_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerutaOam_GoingDown[5] = {
    [0] = {
        .pFrame = sGerutaOam_GoingDown_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sGerutaOam_GoingDown_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sGerutaOam_GoingDown_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sGerutaOam_GoingDown_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerutaOam_Bouncing[3] = {
    [0] = {
        .pFrame = sGerutaOam_Bouncing_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sGerutaOam_Bouncing_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerutaOam_GoingUp[5] = {
    [0] = {
        .pFrame = sGerutaOam_GoingUp_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sGerutaOam_GoingUp_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sGerutaOam_GoingUp_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sGerutaOam_GoingUp_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGerutaOam_BouncingOnCeiling[3] = {
    [0] = {
        .pFrame = sGerutaOam_BouncingOnCeiling_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sGerutaOam_BouncingOnCeiling_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};
