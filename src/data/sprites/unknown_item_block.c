#include "data/sprites/unknown_item_block.h"
#include "macros.h"

const u32 sPlasmaBeamBlockGfx[306] = INCBIN_U32("data/sprites/PlasmaBeamBlock.gfx.lz");
const u16 sPlasmaBeamBlockPal[16] = INCBIN_U16("data/sprites/PlasmaBeamBlock.pal");
const u32 sGravityBlockGfx[303] = INCBIN_U32("data/sprites/GravitySuitBlock.gfx.lz");
const u16 sGravityBlockPal[16] = INCBIN_U16("data/sprites/GravitySuitBlock.pal");
const u32 sSpaceJumpBlockGfx[297] = INCBIN_U32("data/sprites/SpaceJumpBlock.gfx.lz");
const u16 sSpaceJumpBlockPal[16] = INCBIN_U16("data/sprites/SpaceJumpBlock.pal");

static const u16 sUnknownItemBlockOam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sUnknownItemBlockOam_Activated_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 520, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 520, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 520, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sUnknownItemBlockOam_Activated_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 522, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 522, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 522, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sUnknownItemBlockOam_Activated_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 524, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 524, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 524, 8, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sUnknownItemBlockOam_Exploding_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 530, 8, 0),
};

static const u16 sUnknownItemBlockOam_Exploding_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-17, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-17, 1, OAM_DIMS_32x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(9, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(9, 1, OAM_DIMS_8x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-17, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(9, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 530, 8, 0),
};

static const u16 sUnknownItemBlockOam_Exploding_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-18, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-18, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(10, -18, OAM_DIMS_8x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(10, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-18, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(10, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 530, 8, 0),
};

static const u16 sUnknownItemBlockOam_Exploding_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-19, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-19, -3, OAM_DIMS_32x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(11, -13, OAM_DIMS_8x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(11, -3, OAM_DIMS_8x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-14, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-2, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-14, 11, OAM_DIMS_16x8, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-2, 11, OAM_DIMS_16x8, OAM_NO_FLIP, 530, 8, 0),
};

static const u16 sUnknownItemBlockOam_Exploding_Frame4[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-21, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-21, -5, OAM_DIMS_32x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-12, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(4, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-12, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(4, 5, OAM_DIMS_8x16, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(5, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(5, 3, OAM_DIMS_16x8, OAM_NO_FLIP, 530, 8, 0),
};

static const u16 sUnknownItemBlockOam_Exploding_Frame5[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-26, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-8, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-8, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 530, 8, 0),
};

static const u16 sUnknownItemBlockOam_Exploding_Frame6[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-4, 16, OAM_DIMS_8x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 530, 8, 0),
};

static const u16 sUnknownItemBlockOam_Exploding_Frame7[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-48, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(32, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 526, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 526, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 526, 8, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 526, 8, 0),
    OAM_ENTRY(-4, 16, OAM_DIMS_8x16, OAM_NO_FLIP, 526, 8, 0),
    OAM_ENTRY(-4, 32, OAM_DIMS_8x16, OAM_NO_FLIP, 526, 8, 0),
};

static const u16 sUnknownItemBlockOam_Exploding_Frame8[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(0, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 560, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 560, 8, 0),
    OAM_ENTRY(32, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 560, 8, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 560, 8, 0),
    OAM_ENTRY(64, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 560, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 527, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 527, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 527, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 527, 8, 0),
    OAM_ENTRY(-4, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 527, 8, 0),
};

static const u16 sUnknownItemBlockOam_Exploding_Frame9[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(80, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 560, 8, 0),
    OAM_ENTRY(-4, -96, OAM_DIMS_8x16, OAM_NO_FLIP, 527, 8, 0),
};

const u16 sUnknownItemBlockLightOam_Idle_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-16, -4, OAM_DIMS_16x8, OAM_X_FLIP, 560, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_16x8, OAM_X_FLIP, 560, 8, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_16x8, OAM_X_FLIP, 560, 8, 0),
    OAM_ENTRY(-64, -4, OAM_DIMS_16x8, OAM_X_FLIP, 560, 8, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_16x8, OAM_X_FLIP, 560, 8, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x16, OAM_Y_FLIP, 527, 8, 0),
    OAM_ENTRY(-4, 16, OAM_DIMS_8x16, OAM_Y_FLIP, 527, 8, 0),
    OAM_ENTRY(-4, 32, OAM_DIMS_8x16, OAM_Y_FLIP, 527, 8, 0),
    OAM_ENTRY(-4, 48, OAM_DIMS_8x16, OAM_Y_FLIP, 527, 8, 0),
    OAM_ENTRY(-4, 64, OAM_DIMS_8x16, OAM_Y_FLIP, 527, 8, 0),
};

const u16 sUnknownItemBlockLightOam_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-96, -4, OAM_DIMS_16x8, OAM_X_FLIP, 560, 8, 0),
    OAM_ENTRY(-4, 80, OAM_DIMS_8x16, OAM_Y_FLIP, 527, 8, 0),
};

const struct FrameData sUnknownItemBlockOam_Idle[2] = {
    [0] = {
        .pFrame = sUnknownItemBlockOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sUnknownItemBlockOam_Activated[7] = {
    [0] = {
        .pFrame = sUnknownItemBlockOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sUnknownItemBlockOam_Activated_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sUnknownItemBlockOam_Activated_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sUnknownItemBlockOam_Activated_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sUnknownItemBlockOam_Activated_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sUnknownItemBlockOam_Activated_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sUnknownItemBlockOam_Exploding[11] = {
    [0] = {
        .pFrame = sUnknownItemBlockOam_Exploding_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sUnknownItemBlockOam_Exploding_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sUnknownItemBlockOam_Exploding_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sUnknownItemBlockOam_Exploding_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sUnknownItemBlockOam_Exploding_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sUnknownItemBlockOam_Exploding_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sUnknownItemBlockOam_Exploding_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sUnknownItemBlockOam_Exploding_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sUnknownItemBlockOam_Exploding_Frame8,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sUnknownItemBlockOam_Exploding_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sUnknownItemBlockLightOam_Idle[3] = {
    [0] = {
        .pFrame = sUnknownItemBlockLightOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sUnknownItemBlockLightOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};
