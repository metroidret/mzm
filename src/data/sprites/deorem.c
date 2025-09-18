#include "data/sprites/deorem.h"
#include "macros.h"

const s16 sDeoremSegmentXVelocity[33] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0,
    SHORT_MAX
};

const s16 sDeoremThornYVelocity[40] = {
    -8, -7, -6, -5, -4, -3, -2, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9,
    10, 10, 10, 10, 10,
    SHORT_MAX
};

const u32 sDeoremGfx[1569] = INCBIN_U32("data/sprites/Deorem.gfx.lz");
const u16 sDeoremPal[16 * 5] = INCBIN_U16("data/sprites/Deorem.pal");

static const u16 sDeoremSegmentOam_Middle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-33, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 528, 9, 0),
};

static const u16 sDeoremSegmentOam_Middle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -17, OAM_DIMS_64x32, OAM_NO_FLIP, 520, 9, 0),
};

static const u16 sDeoremSegmentOam_Middle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-33, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 512, 9, 0),
};

static const u16 sDeoremSegmentOam_Junction_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -15, OAM_DIMS_64x32, OAM_NO_FLIP, 528, 9, 0),
    OAM_ENTRY(-16, 7, OAM_DIMS_32x16, OAM_NO_FLIP, 796, 9, 0),
};

static const u16 sDeoremSegmentOam_Junction_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -15, OAM_DIMS_64x32, OAM_NO_FLIP, 520, 9, 0),
    OAM_ENTRY(-17, 7, OAM_DIMS_32x16, OAM_NO_FLIP, 796, 9, 0),
};

static const u16 sDeoremSegmentOam_Junction_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -14, OAM_DIMS_64x32, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(-18, 7, OAM_DIMS_32x16, OAM_NO_FLIP, 796, 9, 0),
};

static const u16 sDeoremSegmentOam_Tail_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, -44, OAM_DIMS_32x32, OAM_NO_FLIP, 536, 9, 0),
    OAM_ENTRY(-17, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 656, 9, 0),
    OAM_ENTRY(-25, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 817, 9, 0),
    OAM_ENTRY(15, -3, OAM_DIMS_8x8, OAM_X_FLIP, 816, 9, 0),
};

static const u16 sDeoremSegmentOam_Tail_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -45, OAM_DIMS_32x32, OAM_NO_FLIP, 536, 9, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_32x32, OAM_NO_FLIP, 652, 9, 0),
    OAM_ENTRY(-24, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 818, 9, 0),
    OAM_ENTRY(16, -2, OAM_DIMS_8x8, OAM_X_FLIP, 818, 9, 0),
};

static const u16 sDeoremSegmentOam_Tail_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-14, -44, OAM_DIMS_32x32, OAM_NO_FLIP, 536, 9, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 648, 9, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_8x8, OAM_X_FLIP, 817, 9, 0),
    OAM_ENTRY(-24, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 816, 9, 0),
};

static const u16 sDeoremThornOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 788, 9, 0),
};

static const u16 sDeoremEyeOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 661, 12, 0),
};

static const u16 sDeoremEyeOam_Pulsing_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 790, 12, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 661, 12, 0),
};

static const u16 sDeoremEyeOam_Pulsing_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 792, 12, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 661, 12, 0),
};

static const u16 sDeoremEyeOam_Pulsing_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 794, 12, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 661, 12, 0),
};

static const u16 sDeoremOam_Closing_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-39, -7, OAM_DIMS_32x32, OAM_NO_FLIP, 668, 8, 0),
    OAM_ENTRY(6, -7, OAM_DIMS_32x32, OAM_X_FLIP, 668, 8, 0),
    OAM_ENTRY(-32, -18, OAM_DIMS_64x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-16, -26, OAM_DIMS_32x8, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-16, 14, OAM_DIMS_32x8, OAM_NO_FLIP, 802, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 780, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 784, 8, 0),
};

static const u16 sDeoremOam_Closed_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-40, -9, OAM_DIMS_32x32, OAM_NO_FLIP, 668, 8, 0),
    OAM_ENTRY(7, -9, OAM_DIMS_32x32, OAM_X_FLIP, 668, 8, 0),
    OAM_ENTRY(-32, -19, OAM_DIMS_64x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-16, -27, OAM_DIMS_32x8, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-16, 13, OAM_DIMS_32x8, OAM_NO_FLIP, 802, 8, 0),
    OAM_ENTRY(-16, -9, OAM_DIMS_32x16, OAM_NO_FLIP, 780, 8, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_32x8, OAM_Y_FLIP, 784, 8, 0),
};

static const u16 sDeoremOam_Closed_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-40, -10, OAM_DIMS_32x32, OAM_NO_FLIP, 668, 8, 0),
    OAM_ENTRY(7, -10, OAM_DIMS_32x32, OAM_X_FLIP, 668, 8, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_64x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-16, -28, OAM_DIMS_32x8, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-16, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 802, 8, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 776, 8, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_32x8, OAM_Y_FLIP, 784, 8, 0),
};

static const u16 sDeoremOam_Closed_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-39, -11, OAM_DIMS_32x32, OAM_NO_FLIP, 668, 8, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_32x32, OAM_X_FLIP, 668, 8, 0),
    OAM_ENTRY(-32, -21, OAM_DIMS_64x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-16, -29, OAM_DIMS_32x8, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-16, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 802, 8, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 780, 8, 0),
    OAM_ENTRY(-16, 2, OAM_DIMS_32x8, OAM_Y_FLIP, 784, 8, 0),
};

static const u16 sDeoremOam_Opening_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-40, -10, OAM_DIMS_32x32, OAM_NO_FLIP, 668, 8, 0),
    OAM_ENTRY(7, -10, OAM_DIMS_32x32, OAM_X_FLIP, 668, 8, 0),
    OAM_ENTRY(-32, -19, OAM_DIMS_64x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-16, -27, OAM_DIMS_32x8, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-16, 13, OAM_DIMS_32x8, OAM_NO_FLIP, 802, 8, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 780, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 784, 8, 0),
};

static const u16 sDeoremOam_Opening_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-41, -12, OAM_DIMS_32x32, OAM_NO_FLIP, 665, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_32x32, OAM_X_FLIP, 665, 8, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_64x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-16, -28, OAM_DIMS_32x8, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-16, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 802, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 784, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 784, 8, 0),
};

static const u16 sDeoremOam_Opening_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-43, -25, OAM_DIMS_32x32, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(10, -25, OAM_DIMS_32x32, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(-32, -21, OAM_DIMS_64x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-16, -29, OAM_DIMS_32x8, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-16, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 802, 8, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_32x8, OAM_NO_FLIP, 784, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_32x8, OAM_Y_FLIP, 784, 8, 0),
};

static const u16 sDeoremOam_Opening_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-43, -27, OAM_DIMS_32x32, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(10, -27, OAM_DIMS_32x32, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(-32, -22, OAM_DIMS_64x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-16, -30, OAM_DIMS_32x8, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-16, 10, OAM_DIMS_32x8, OAM_NO_FLIP, 802, 8, 0),
};

static const u16 sDeoremOam_Opened_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-42, -28, OAM_DIMS_32x32, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(9, -28, OAM_DIMS_32x32, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(-32, -23, OAM_DIMS_64x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-16, -31, OAM_DIMS_32x8, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-16, 9, OAM_DIMS_32x8, OAM_NO_FLIP, 802, 8, 0),
};

static const u16 sDeoremOam_Opened_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-43, -25, OAM_DIMS_32x32, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(10, -25, OAM_DIMS_32x32, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(-32, -21, OAM_DIMS_64x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-16, -29, OAM_DIMS_32x8, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-16, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 802, 8, 0),
};

static const u16 sDeoremOam_Warning_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-43, -25, OAM_DIMS_32x32, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(10, -25, OAM_DIMS_32x32, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(-32, -21, OAM_DIMS_64x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-16, -29, OAM_DIMS_32x8, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-16, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 802, 8, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 780, 8, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_32x8, OAM_Y_FLIP, 784, 8, 0),
};

static const u16 sDeoremOam_Warning_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-43, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(10, -24, OAM_DIMS_32x32, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(-32, -21, OAM_DIMS_64x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-16, -29, OAM_DIMS_32x8, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-16, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 802, 8, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 780, 8, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_32x8, OAM_Y_FLIP, 784, 8, 0),
};

static const u16 sDeoremOam_Warning_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-41, -12, OAM_DIMS_32x32, OAM_NO_FLIP, 665, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_32x32, OAM_X_FLIP, 665, 8, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_64x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-16, -28, OAM_DIMS_32x8, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-16, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 802, 8, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 780, 8, 0),
    OAM_ENTRY(-16, 2, OAM_DIMS_32x8, OAM_Y_FLIP, 784, 8, 0),
};

static const u16 sDeoremOam_Warning_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-40, -11, OAM_DIMS_32x32, OAM_NO_FLIP, 668, 8, 0),
    OAM_ENTRY(7, -11, OAM_DIMS_32x32, OAM_X_FLIP, 668, 8, 0),
    OAM_ENTRY(-32, -20, OAM_DIMS_64x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-16, -28, OAM_DIMS_32x8, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-16, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 802, 8, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 780, 8, 0),
    OAM_ENTRY(-16, 2, OAM_DIMS_32x8, OAM_Y_FLIP, 784, 8, 0),
};

static const u16 sDeoremOam_Warning_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-39, -9, OAM_DIMS_32x32, OAM_NO_FLIP, 668, 8, 0),
    OAM_ENTRY(6, -9, OAM_DIMS_32x32, OAM_X_FLIP, 668, 8, 0),
    OAM_ENTRY(-32, -19, OAM_DIMS_64x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-16, -27, OAM_DIMS_32x8, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-16, 13, OAM_DIMS_32x8, OAM_NO_FLIP, 802, 8, 0),
    OAM_ENTRY(-16, -9, OAM_DIMS_32x16, OAM_NO_FLIP, 780, 8, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_32x8, OAM_Y_FLIP, 784, 8, 0),
};

const struct FrameData sDeoremSegmentOam_Middle[5] = {
    [0] = {
        .pFrame = sDeoremSegmentOam_Middle_Frame0,
        .timer = CONVERT_SECONDS(.2f)
    },
    [1] = {
        .pFrame = sDeoremSegmentOam_Middle_Frame1,
        .timer = CONVERT_SECONDS(.2f)
    },
    [2] = {
        .pFrame = sDeoremSegmentOam_Middle_Frame2,
        .timer = CONVERT_SECONDS(.2f)
    },
    [3] = {
        .pFrame = sDeoremSegmentOam_Middle_Frame1,
        .timer = CONVERT_SECONDS(.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremSegmentOam_Junction[5] = {
    [0] = {
        .pFrame = sDeoremSegmentOam_Junction_Frame0,
        .timer = CONVERT_SECONDS(.2f)
    },
    [1] = {
        .pFrame = sDeoremSegmentOam_Junction_Frame1,
        .timer = CONVERT_SECONDS(.2f)
    },
    [2] = {
        .pFrame = sDeoremSegmentOam_Junction_Frame2,
        .timer = CONVERT_SECONDS(.2f)
    },
    [3] = {
        .pFrame = sDeoremSegmentOam_Junction_Frame1,
        .timer = CONVERT_SECONDS(.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremSegmentOam_Tail[5] = {
    [0] = {
        .pFrame = sDeoremSegmentOam_Tail_Frame0,
        .timer = CONVERT_SECONDS(.2f)
    },
    [1] = {
        .pFrame = sDeoremSegmentOam_Tail_Frame1,
        .timer = CONVERT_SECONDS(.2f)
    },
    [2] = {
        .pFrame = sDeoremSegmentOam_Tail_Frame2,
        .timer = CONVERT_SECONDS(.2f)
    },
    [3] = {
        .pFrame = sDeoremSegmentOam_Tail_Frame1,
        .timer = CONVERT_SECONDS(.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremThornOam_Idle[2] = {
    [0] = {
        .pFrame = sDeoremThornOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremEyeOam_Idle[2] = {
    [0] = {
        .pFrame = sDeoremEyeOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremEyeOam_Pulsing[6] = {
    [0] = {
        .pFrame = sDeoremEyeOam_Pulsing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sDeoremEyeOam_Pulsing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sDeoremEyeOam_Pulsing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sDeoremEyeOam_Pulsing_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = {
        .pFrame = sDeoremEyeOam_Pulsing_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_ClosedSlow[5] = {
    [0] = {
        .pFrame = sDeoremOam_Closed_Frame0,
        .timer = CONVERT_SECONDS(.2f)
    },
    [1] = {
        .pFrame = sDeoremOam_Closed_Frame1,
        .timer = CONVERT_SECONDS(.2f)
    },
    [2] = {
        .pFrame = sDeoremOam_Closed_Frame2,
        .timer = CONVERT_SECONDS(.2f)
    },
    [3] = {
        .pFrame = sDeoremOam_Closed_Frame1,
        .timer = CONVERT_SECONDS(.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_Opening[5] = {
    [0] = {
        .pFrame = sDeoremOam_Opening_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sDeoremOam_Opening_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sDeoremOam_Opening_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sDeoremOam_Opening_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_OpenedSlow[5] = {
    [0] = {
        .pFrame = sDeoremOam_Opened_Frame0,
        .timer = CONVERT_SECONDS(.2f)
    },
    [1] = {
        .pFrame = sDeoremOam_Opening_Frame3,
        .timer = CONVERT_SECONDS(.2f)
    },
    [2] = {
        .pFrame = sDeoremOam_Opened_Frame2,
        .timer = CONVERT_SECONDS(.2f)
    },
    [3] = {
        .pFrame = sDeoremOam_Opening_Frame3,
        .timer = CONVERT_SECONDS(.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_Closing[5] = {
    [0] = {
        .pFrame = sDeoremOam_Opening_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sDeoremOam_Opening_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sDeoremOam_Opening_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sDeoremOam_Closing_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_Warning[9] = {
    [0] = {
        .pFrame = sDeoremOam_Warning_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sDeoremOam_Warning_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = {
        .pFrame = sDeoremOam_Warning_Frame2,
        .timer = CONVERT_SECONDS(.05f)
    },
    [3] = {
        .pFrame = sDeoremOam_Warning_Frame3,
        .timer = CONVERT_SECONDS(.05f)
    },
    [4] = {
        .pFrame = sDeoremOam_Warning_Frame4,
        .timer = CONVERT_SECONDS(.05f)
    },
    [5] = {
        .pFrame = sDeoremOam_Warning_Frame3,
        .timer = CONVERT_SECONDS(.05f)
    },
    [6] = {
        .pFrame = sDeoremOam_Warning_Frame2,
        .timer = CONVERT_SECONDS(.05f)
    },
    [7] = {
        .pFrame = sDeoremOam_Warning_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_GoingDown[3] = {
    [0] = {
        .pFrame = sDeoremOam_Warning_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sDeoremOam_Warning_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_OpenedFast[5] = {
    [0] = {
        .pFrame = sDeoremOam_Opened_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sDeoremOam_Opening_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sDeoremOam_Opened_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sDeoremOam_Opening_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_ClosedFast[5] = {
    [0] = {
        .pFrame = sDeoremOam_Closed_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sDeoremOam_Closed_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = {
        .pFrame = sDeoremOam_Closed_Frame2,
        .timer = CONVERT_SECONDS(.05f)
    },
    [3] = {
        .pFrame = sDeoremOam_Closed_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sDeoremOam_Dying[5] = {
    [0] = {
        .pFrame = sDeoremOam_Opening_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sDeoremOam_Opening_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = {
        .pFrame = sDeoremOam_Opening_Frame2,
        .timer = CONVERT_SECONDS(.05f)
    },
    [3] = {
        .pFrame = sDeoremOam_Opening_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};
