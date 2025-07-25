#include "data/sprites/holtz.h"
#include "macros.h"

const s16 sHoltzIdleYVelocity[65] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1,
    1, 2, 2, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, -1,
    0, -1, 0, -1, -1, -1, -2, -2, -1, -1, -1,
    0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0, SHORT_MAX
};

const u32 sHoltzGfx[200] = INCBIN_U32("data/sprites/Holtz.gfx.lz");
const u16 sHoltzPal[16] = INCBIN_U16("data/sprites/Holtz.pal");

static const u16 sHoltzOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0x1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x23c
};

static const u16 sHoltzOam_Idle_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x200,
    0x1, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x9, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21e
};

static const u16 sHoltzOam_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x200,
    0x2, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x9, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sHoltzOam_Idle_Frame3[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x2, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xa, 0x1f8, OBJ_SPRITE_OAM | 0x22a,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21e
};

static const u16 sHoltzOam_Warning_Frame1[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1f8, OBJ_SPRITE_OAM | 0x224,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1f8, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x23c
};

static const u16 sHoltzOam_Warning_Frame2[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1f8, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21e
};

static const u16 sHoltzOam_Warning_Frame3[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sHoltzOam_Warning_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21a
};

static const u16 sHoltzOam_Warning_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c
};

static const u16 sHoltzOam_Warning_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sHoltzOam_Warning_Frame7[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x8, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21a
};

static const u16 sHoltzOam_Warning_Frame8[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x3, 0x1f8, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xb, 0x1f8, OBJ_SPRITE_OAM | 0x224,
    OBJ_SHAPE_HORIZONTAL | 0xff, 0x8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sHoltzOam_GoingDown_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x7, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c
};

static const u16 sHoltzOam_GoingDown_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x8, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x210
};

static const u16 sHoltzOam_IdleAware_Frame2[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0x5, 0x1fc, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x23c
};

static const u16 sHoltzOam_GoingUp_Frame2[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0x7, 0x1fc, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x23c
};

static const u16 sHoltzOam_GoingUp_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1f8, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_VERTICAL | 0x6, 0x1fc, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x23c
};

static const u16 sHoltzOam_GoingUp_Frame0[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x22a,
    OBJ_SHAPE_VERTICAL | 0x5, 0x1fc, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x23c
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
