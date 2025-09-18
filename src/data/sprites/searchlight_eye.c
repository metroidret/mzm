#include "data/sprites/searchlight_eye.h"
#include "macros.h"

const u32 sSearchlightEyeGfx[177] = INCBIN_U32("data/sprites/SearchlightEye.gfx.lz");
const u16 sSearchlightEyePal[16] = INCBIN_U16("data/sprites/SearchlightEye.pal");

static const u16 sSearchlightEyeOam_Idle_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSearchlightEyeOam_Idle_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSearchlightEyeOam_Idle_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 517, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSearchlightEyeOam_Idle_Frame10[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 523, 8, 0),
};

static const u16 sSearchlightEyeBeamOAM_Idle_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-112, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sSearchlightEyeBeamOAM_Idle_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_Y_FLIP, 540, 8, 0),
    OAM_ENTRY(-48, -8, OAM_DIMS_32x16, OAM_Y_FLIP, 540, 8, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_32x16, OAM_Y_FLIP, 540, 8, 0),
    OAM_ENTRY(-112, -8, OAM_DIMS_32x16, OAM_Y_FLIP, 540, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_32x16, OAM_Y_FLIP, 540, 8, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_32x16, OAM_Y_FLIP, 540, 8, 0),
    OAM_ENTRY(80, -8, OAM_DIMS_32x16, OAM_Y_FLIP, 540, 8, 0),
};

static const u16 sSearchlightEyeBeamOAM_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSearchlightEyeBeamOAM_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sSearchlightEyeProjectileOAM_Moving_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-10, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 537, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 569, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 569, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 570, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 570, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 571, 8, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 571, 8, 0),
};

static const u16 sSearchlightEyeProjectileOAM_Moving_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-9, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 537, 8, 0),
    OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 569, 8, 0),
    OAM_ENTRY(3, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 569, 8, 0),
    OAM_ENTRY(11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 570, 8, 0),
    OAM_ENTRY(11, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 570, 8, 0),
    OAM_ENTRY(-2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 571, 8, 0),
    OAM_ENTRY(-2, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 571, 8, 0),
};

static const u16 sSearchlightEyeProjectileOAM_Moving_Frame4[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-10, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 537, 8, 0),
    OAM_ENTRY(7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 569, 8, 0),
    OAM_ENTRY(7, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 569, 8, 0),
    OAM_ENTRY(-3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 570, 8, 0),
    OAM_ENTRY(-3, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 570, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 571, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 571, 8, 0),
};

static const u16 sSearchlightEyeProjectileOAM_Moving_Frame6[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-9, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-9, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 537, 8, 0),
    OAM_ENTRY(-2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 569, 8, 0),
    OAM_ENTRY(-2, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 569, 8, 0),
    OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 570, 8, 0),
    OAM_ENTRY(3, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 570, 8, 0),
    OAM_ENTRY(13, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 571, 8, 0),
    OAM_ENTRY(13, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 571, 8, 0),
};

static const u16 sSearchlightEyeOam_Shooting_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 525, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 527, 8, 0),
};

static const u16 sSearchlightEyeOam_Shooting_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 533, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 535, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 516, 8, 0),
};

const struct FrameData sSearchlightEyeOam_Idle[13] = {
    [0] = {
        .pFrame = sSearchlightEyeOam_Idle_Frame0,
        .timer = ONE_THIRD_SECOND
    },
    [1] = {
        .pFrame = sSearchlightEyeOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sSearchlightEyeOam_Idle_Frame2,
        .timer = ONE_THIRD_SECOND
    },
    [3] = {
        .pFrame = sSearchlightEyeOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = {
        .pFrame = sSearchlightEyeOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [5] = {
        .pFrame = sSearchlightEyeOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sSearchlightEyeOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [7] = {
        .pFrame = sSearchlightEyeOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [8] = {
        .pFrame = sSearchlightEyeOam_Idle_Frame0,
        .timer = ONE_THIRD_SECOND
    },
    [9] = {
        .pFrame = sSearchlightEyeOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [10] = {
        .pFrame = sSearchlightEyeOam_Idle_Frame10,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [11] = {
        .pFrame = sSearchlightEyeOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSearchlightEyeBeamOAM_Idle[5] = {
    [0] = {
        .pFrame = sSearchlightEyeBeamOAM_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSearchlightEyeBeamOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSearchlightEyeBeamOAM_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSearchlightEyeBeamOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSearchlightEyeBeamOAM_Unused[2] = {
    [0] = {
        .pFrame = sSearchlightEyeBeamOAM_Unused_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSearchlightEyeProjectileOAM_Moving[9] = {
    [0] = {
        .pFrame = sSearchlightEyeProjectileOAM_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSearchlightEyeBeamOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSearchlightEyeProjectileOAM_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSearchlightEyeBeamOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSearchlightEyeProjectileOAM_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSearchlightEyeBeamOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sSearchlightEyeProjectileOAM_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sSearchlightEyeBeamOAM_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSearchlightEyeOam_Shooting[4] = {
    [0] = {
        .pFrame = sSearchlightEyeOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sSearchlightEyeOam_Shooting_Frame1,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [2] = {
        .pFrame = sSearchlightEyeOam_Shooting_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};
