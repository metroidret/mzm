#include "data/sprites/holtz.h"
#include "macros.h"

const s16 sHoltzIdleYVelocity[65] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1,
    1, 2, 2, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, -1,
    0, -1, 0, -1, -1, -1, -2, -2, -1, -1, -1,
    0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0, SHORT_MAX
};

const u32 sHoltzGfx[200] = INCBIN_U32("data/sprites/holtz.gfx.lz");
const u16 sHoltzPal[16] = INCBIN_U16("data/sprites/holtz.pal");

static const u16 sHoltzOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-24, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x23c, 8, 0)
};

static const u16 sHoltzOam_Idle_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-15, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-7, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(9, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-23, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x21e, 8, 0)
};

static const u16 sHoltzOam_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-15, -7, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-7, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(9, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-23, -3, OAM_DIMS_16x8, OAM_X_FLIP, 0x21c, 8, 0)
};

static const u16 sHoltzOam_Idle_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -7, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(8, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-24, -3, OAM_DIMS_16x8, OAM_X_FLIP, 0x21e, 8, 0)
};

static const u16 sHoltzOam_Warning_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x224, 8, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(7, -1, OAM_DIMS_16x8, OAM_Y_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-23, -1, OAM_DIMS_16x8, OAM_XY_FLIP, 0x23c, 8, 0)
};

static const u16 sHoltzOam_Warning_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -9, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(7, -2, OAM_DIMS_16x8, OAM_Y_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-23, -2, OAM_DIMS_16x8, OAM_XY_FLIP, 0x21e, 8, 0)
};

static const u16 sHoltzOam_Warning_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -9, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(7, -2, OAM_DIMS_16x8, OAM_Y_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-23, -2, OAM_DIMS_16x8, OAM_XY_FLIP, 0x21c, 8, 0)
};

static const u16 sHoltzOam_Warning_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(7, -3, OAM_DIMS_16x8, OAM_Y_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-23, -3, OAM_DIMS_16x8, OAM_XY_FLIP, 0x21a, 8, 0)
};

static const u16 sHoltzOam_Warning_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-24, -3, OAM_DIMS_16x8, OAM_X_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0)
};

static const u16 sHoltzOam_Warning_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -7, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-24, -2, OAM_DIMS_16x8, OAM_X_FLIP, 0x21c, 8, 0)
};

static const u16 sHoltzOam_Warning_Frame7[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -7, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(8, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-24, -2, OAM_DIMS_16x8, OAM_X_FLIP, 0x21a, 8, 0)
};

static const u16 sHoltzOam_Warning_Frame8[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, 11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x224, 8, 0),
    OAM_ENTRY(8, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-24, -1, OAM_DIMS_16x8, OAM_X_FLIP, 0x21c, 8, 0)
};

static const u16 sHoltzOam_GoingDown_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(7, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-23, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0)
};

static const u16 sHoltzOam_GoingDown_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -7, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-24, -3, OAM_DIMS_16x8, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-16, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0)
};

static const u16 sHoltzOam_IdleAware_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-4, 5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-24, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x23c, 8, 0)
};

static const u16 sHoltzOam_GoingUp_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -9, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-4, 7, OAM_DIMS_8x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-24, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x23c, 8, 0)
};

static const u16 sHoltzOam_GoingUp_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-4, 6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-24, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x23c, 8, 0)
};

static const u16 sHoltzOam_GoingUp_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -9, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22a, 8, 0),
    OAM_ENTRY(-4, 5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(8, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-24, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x23c, 8, 0)
};

const struct FrameData sHoltzOam_Idle[5] = {
    [0] = {
        .pFrame = sHoltzOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sHoltzOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sHoltzOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sHoltzOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHoltzOam_Warning[10] = {
    [0] = {
        .pFrame = sHoltzOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [1] = {
        .pFrame = sHoltzOam_Warning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sHoltzOam_Warning_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sHoltzOam_Warning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sHoltzOam_Warning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [5] = {
        .pFrame = sHoltzOam_Warning_Frame5,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [6] = {
        .pFrame = sHoltzOam_Warning_Frame6,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [7] = {
        .pFrame = sHoltzOam_Warning_Frame7,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [8] = {
        .pFrame = sHoltzOam_Warning_Frame8,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHoltzOam_GoingDown[3] = {
    [0] = {
        .pFrame = sHoltzOam_GoingDown_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sHoltzOam_GoingDown_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHoltzOam_IdleAware[4] = {
    [0] = {
        .pFrame = sHoltzOam_GoingDown_Frame0,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [1] = {
        .pFrame = sHoltzOam_Warning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [2] = {
        .pFrame = sHoltzOam_IdleAware_Frame2,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHoltzOam_GoingUp[8] = {
    [0] = {
        .pFrame = sHoltzOam_GoingUp_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sHoltzOam_GoingUp_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sHoltzOam_GoingUp_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sHoltzOam_GoingUp_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sHoltzOam_GoingUp_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sHoltzOam_GoingUp_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sHoltzOam_IdleAware_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHoltzOam_BonkingOnCeiling[10] = {
    [0] = {
        .pFrame = sHoltzOam_IdleAware_Frame2,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [1] = {
        .pFrame = sHoltzOam_Warning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [2] = {
        .pFrame = sHoltzOam_Warning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sHoltzOam_Warning_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sHoltzOam_Warning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sHoltzOam_Warning_Frame7,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [6] = {
        .pFrame = sHoltzOam_Warning_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sHoltzOam_Warning_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sHoltzOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = FRAME_DATA_TERMINATOR
};
