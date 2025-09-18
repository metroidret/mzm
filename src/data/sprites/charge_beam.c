#include "data/sprites/charge_beam.h"

#include "macros.h"

const s16 sChargeBeamIdleYMovement[66] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, -1, -1, -1,
    -1, -1, -1, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0,
    0, SHORT_MAX
};

const u32 sChargeBeamGfx[243] = INCBIN_U32("data/sprites/ChargeBeam.gfx.lz");
const u16 sChargeBeamPal[16] = INCBIN_U16("data/sprites/ChargeBeam.pal");

static const u16 sChargeBeamOam_Visible_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-9, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 530, 8, 0),
};

static const u16 sChargeBeamOam_Visible_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-9, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 532, 8, 0),
};

static const u16 sChargeBeamOam_Visible_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 534, 8, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 530, 8, 0),
};

static const u16 sChargeBeamGlowOam_Idle_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 514, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 514, 8, 0),
};

static const u16 sChargeBeamGlowOam_Idle_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 518, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 518, 8, 0),
};

static const u16 sChargeBeamGlowOam_Idle_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 522, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 522, 8, 0),
};

static const u16 sChargeBeamGlowOam_Idle_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 526, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 526, 8, 0),
};

static const u16 sChargeBeamGlowOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 155, 8, 0),
};

static const u16 sChargeBeamOam_Spawning_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 535, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 535, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 535, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 535, 8, 0),
};

static const u16 sChargeBeamOam_Spawning_Frame1[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-17, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 535, 8, 0),
    OAM_ENTRY(1, -17, OAM_DIMS_16x16, OAM_X_FLIP, 535, 8, 0),
    OAM_ENTRY(-17, 1, OAM_DIMS_16x16, OAM_Y_FLIP, 535, 8, 0),
    OAM_ENTRY(1, 1, OAM_DIMS_16x16, OAM_XY_FLIP, 535, 8, 0),
    OAM_ENTRY(-5, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 568, 8, 0),
    OAM_ENTRY(-5, 1, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-17, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(1, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 567, 8, 0),
};

static const u16 sChargeBeamOam_Spawning_Frame2[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-18, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 535, 8, 0),
    OAM_ENTRY(2, -18, OAM_DIMS_16x16, OAM_X_FLIP, 535, 8, 0),
    OAM_ENTRY(-18, 2, OAM_DIMS_16x16, OAM_Y_FLIP, 535, 8, 0),
    OAM_ENTRY(2, 2, OAM_DIMS_16x16, OAM_XY_FLIP, 535, 8, 0),
    OAM_ENTRY(-6, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-6, 3, OAM_DIMS_8x16, OAM_Y_FLIP, 536, 8, 0),
    OAM_ENTRY(-19, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(3, -6, OAM_DIMS_16x8, OAM_X_FLIP, 567, 8, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 568, 8, 0),
};

static const u16 sChargeBeamOam_Spawning_Frame3[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-19, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 535, 8, 0),
    OAM_ENTRY(3, -19, OAM_DIMS_16x16, OAM_X_FLIP, 535, 8, 0),
    OAM_ENTRY(-19, 3, OAM_DIMS_16x16, OAM_Y_FLIP, 535, 8, 0),
    OAM_ENTRY(3, 3, OAM_DIMS_16x16, OAM_XY_FLIP, 535, 8, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-8, 4, OAM_DIMS_8x16, OAM_Y_FLIP, 536, 8, 0),
    OAM_ENTRY(-20, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_16x8, OAM_X_FLIP, 567, 8, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 568, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_8x16, OAM_X_FLIP, 536, 8, 0),
    OAM_ENTRY(-20, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 567, 8, 0),
    OAM_ENTRY(4, 0, OAM_DIMS_16x8, OAM_XY_FLIP, 567, 8, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_8x16, OAM_XY_FLIP, 536, 8, 0),
};

static const u16 sChargeBeamOam_Spawning_Frame4[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-20, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 535, 8, 0),
    OAM_ENTRY(4, -20, OAM_DIMS_16x16, OAM_X_FLIP, 535, 8, 0),
    OAM_ENTRY(-20, 4, OAM_DIMS_16x16, OAM_Y_FLIP, 535, 8, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_16x16, OAM_XY_FLIP, 535, 8, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-8, 5, OAM_DIMS_8x16, OAM_Y_FLIP, 536, 8, 0),
    OAM_ENTRY(-21, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_16x8, OAM_X_FLIP, 567, 8, 0),
    OAM_ENTRY(0, -21, OAM_DIMS_8x16, OAM_X_FLIP, 536, 8, 0),
    OAM_ENTRY(-21, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 567, 8, 0),
    OAM_ENTRY(5, 0, OAM_DIMS_16x8, OAM_XY_FLIP, 567, 8, 0),
    OAM_ENTRY(0, 5, OAM_DIMS_8x16, OAM_XY_FLIP, 536, 8, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sChargeBeamOam_Spawning_Frame8[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 535, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 535, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 535, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 535, 8, 0),
    OAM_ENTRY(-20, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-20, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 571, 8, 0),
    OAM_ENTRY(4, -20, OAM_DIMS_16x8, OAM_X_FLIP, 528, 8, 0),
    OAM_ENTRY(12, -20, OAM_DIMS_8x16, OAM_X_FLIP, 528, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 541, 8, 0),
    OAM_ENTRY(-20, 12, OAM_DIMS_16x8, OAM_Y_FLIP, 528, 8, 0),
    OAM_ENTRY(-20, 4, OAM_DIMS_8x16, OAM_Y_FLIP, 528, 8, 0),
    OAM_ENTRY(-24, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(4, 12, OAM_DIMS_16x8, OAM_XY_FLIP, 528, 8, 0),
    OAM_ENTRY(12, 4, OAM_DIMS_8x16, OAM_XY_FLIP, 528, 8, 0),
    OAM_ENTRY(-4, 16, OAM_DIMS_8x8, OAM_XY_FLIP, 571, 8, 0),
};

static const u16 sChargeBeamOam_Spawning_Frame9[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x16, OAM_X_FLIP, 542, 8, 0),
    OAM_ENTRY(-12, 4, OAM_DIMS_16x8, OAM_Y_FLIP, 542, 8, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_8x8, OAM_XY_FLIP, 542, 8, 0),
    OAM_ENTRY(-28, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(-4, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 571, 8, 0),
    OAM_ENTRY(20, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 541, 8, 0),
    OAM_ENTRY(-4, 20, OAM_DIMS_8x8, OAM_XY_FLIP, 571, 8, 0),
    OAM_ENTRY(-21, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-24, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(5, -24, OAM_DIMS_16x8, OAM_X_FLIP, 528, 8, 0),
    OAM_ENTRY(16, -21, OAM_DIMS_8x16, OAM_X_FLIP, 528, 8, 0),
    OAM_ENTRY(5, 16, OAM_DIMS_16x8, OAM_XY_FLIP, 528, 8, 0),
    OAM_ENTRY(16, 5, OAM_DIMS_8x16, OAM_XY_FLIP, 528, 8, 0),
    OAM_ENTRY(-21, 16, OAM_DIMS_16x8, OAM_Y_FLIP, 528, 8, 0),
    OAM_ENTRY(-24, 5, OAM_DIMS_8x16, OAM_Y_FLIP, 528, 8, 0),
};

static const u16 sChargeBeamOam_Spawning_Frame10[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-31, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(23, -8, OAM_DIMS_8x16, OAM_X_FLIP, 541, 8, 0),
    OAM_ENTRY(-8, -31, OAM_DIMS_16x8, OAM_NO_FLIP, 571, 8, 0),
    OAM_ENTRY(-8, 23, OAM_DIMS_16x8, OAM_Y_FLIP, 571, 8, 0),
    OAM_ENTRY(-24, -27, OAM_DIMS_16x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-27, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(8, -27, OAM_DIMS_16x8, OAM_X_FLIP, 528, 8, 0),
    OAM_ENTRY(19, -24, OAM_DIMS_8x16, OAM_X_FLIP, 528, 8, 0),
    OAM_ENTRY(8, 19, OAM_DIMS_16x8, OAM_XY_FLIP, 528, 8, 0),
    OAM_ENTRY(19, 8, OAM_DIMS_8x16, OAM_XY_FLIP, 528, 8, 0),
    OAM_ENTRY(-24, 19, OAM_DIMS_16x8, OAM_Y_FLIP, 528, 8, 0),
    OAM_ENTRY(-27, 8, OAM_DIMS_8x16, OAM_Y_FLIP, 528, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 571, 8, 0),
    OAM_ENTRY(-4, 24, OAM_DIMS_8x8, OAM_Y_FLIP, 571, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(24, -4, OAM_DIMS_8x8, OAM_X_FLIP, 541, 8, 0),
};

static const u16 sChargeBeamOam_Spawning_Frame11[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 566, 8, 0),
};

const struct FrameData sChargeBeamOam_Visible[5] = {
    [0] = {
        .pFrame = sChargeBeamOam_Visible_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sChargeBeamOam_Visible_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sChargeBeamOam_Visible_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sChargeBeamOam_Visible_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargeBeamOam_Spawning[13] = {
    [0] = {
        .pFrame = sChargeBeamOam_Spawning_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sChargeBeamOam_Spawning_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sChargeBeamOam_Spawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sChargeBeamOam_Spawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [4] = {
        .pFrame = sChargeBeamOam_Spawning_Frame4,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [5] = {
        .pFrame = sChargeBeamOam_Spawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [6] = {
        .pFrame = sChargeBeamOam_Spawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [7] = {
        .pFrame = sChargeBeamOam_Spawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [8] = {
        .pFrame = sChargeBeamOam_Spawning_Frame8,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [9] = {
        .pFrame = sChargeBeamOam_Spawning_Frame9,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [10] = {
        .pFrame = sChargeBeamOam_Spawning_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sChargeBeamOam_Spawning_Frame11,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargeBeamGlowOam_Idle[15] = {
    [0] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [2] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [4] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [6] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [8] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [10] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [12] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sChargeBeamGlowOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / FRAMES_PER_SECOND)
    },
    [14] = FRAME_DATA_TERMINATOR
};
