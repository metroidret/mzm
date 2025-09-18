#include "data/sprites/polyp.h"
#include "macros.h"

const s16 sPolypProjectileYVelocity[44] = {
    -16, -16, -14, -14, -12, -12, -10, -10, -8, -8, -8, -8,
    -6, -6, -6, -6, -5, -5, -4, -4, -3, -2, -1, 0, 0, 0, 0, 0, 1,
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16, 18, SHORT_MAX
};

const u32 sPolypGfx[241] = INCBIN_U32("data/sprites/Polyp.gfx.lz");
const u16 sPolypPal[16] = INCBIN_U16("data/sprites/Polyp.pal");

static const u16 sPolypOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -9, OAM_DIMS_32x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-16, -9, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-16, -13, OAM_DIMS_32x8, OAM_NO_FLIP, 548, 8, 0),
    OAM_ENTRY(-16, -1, OAM_DIMS_32x8, OAM_NO_FLIP, 544, 8, 0),
};

static const u16 sPolypOam_Idle_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -9, OAM_DIMS_32x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-16, -9, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 548, 8, 0),
    OAM_ENTRY(-16, -1, OAM_DIMS_32x8, OAM_NO_FLIP, 544, 8, 0),
};

static const u16 sPolypOam_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -9, OAM_DIMS_32x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-16, -1, OAM_DIMS_32x8, OAM_NO_FLIP, 544, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 548, 8, 0),
};

static const u16 sPolypOam_Warning_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_32x8, OAM_NO_FLIP, 544, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 548, 8, 0),
}; 

static const u16 sPolypOam_Warning_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_32x8, OAM_NO_FLIP, 544, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-16, -9, OAM_DIMS_32x8, OAM_NO_FLIP, 548, 8, 0),
};

static const u16 sPolypOam_Warning_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 544, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 548, 8, 0),
};

static const u16 sPolypOam_Warning_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 544, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 548, 8, 0),
};

static const u16 sPolypOam_AfterSpitting_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 544, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-16, -9, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x8, OAM_NO_FLIP, 548, 8, 0),
};

static const u16 sPolypProjectileOam_Right_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sPolypProjectileOam_Right_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 530, 8, 0),
};

static const u16 sPolypProjectileOam_Right_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 532, 8, 0),
};

static const u16 sPolypProjectileOam_Right_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sPolypProjectileOam_Left_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 528, 8, 0),
};

static const u16 sPolypProjectileOam_Left_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 530, 8, 0),
};

static const u16 sPolypProjectileOam_Left_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 532, 8, 0),
};

static const u16 sPolypProjectileOam_Left_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 534, 8, 0),
};

static const u16 sPolypProjectileOam_Exploding_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sPolypProjectileOam_Exploding_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 8, 0),
};

static const u16 sPolypProjectileOam_Exploding_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sPolypProjectileOam_Exploding_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 542, 8, 0),
};

const struct FrameData sPolypOam_Idle[5] = {
    [0] = {
        .pFrame = sPolypOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sPolypOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sPolypOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [3] = {
        .pFrame = sPolypOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPolypOam_Warning[5] = {
    [0] = {
        .pFrame = sPolypOam_Warning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sPolypOam_Warning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sPolypOam_Warning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sPolypOam_Warning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPolypOam_Spitting[2] = {
    [0] = {
        .pFrame = sPolypOam_Warning_Frame2,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPolypOam_AfterSpitting[4] = {
    [0] = {
        .pFrame = sPolypOam_Warning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sPolypOam_Warning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sPolypOam_AfterSpitting_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPolypOam_Retracting[3] = {
    [0] = {
        .pFrame = sPolypOam_Warning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sPolypOam_Warning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPolypProjectileOam_Right[5] = {
    [0] = {
        .pFrame = sPolypProjectileOam_Right_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sPolypProjectileOam_Right_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sPolypProjectileOam_Right_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sPolypProjectileOam_Right_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPolypProjectileOam_Left[5] = {
    [0] = {
        .pFrame = sPolypProjectileOam_Left_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sPolypProjectileOam_Left_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sPolypProjectileOam_Left_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sPolypProjectileOam_Left_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPolypProjectileOam_Exploding[5] = {
    [0] = {
        .pFrame = sPolypProjectileOam_Exploding_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sPolypProjectileOam_Exploding_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sPolypProjectileOam_Exploding_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sPolypProjectileOam_Exploding_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};
