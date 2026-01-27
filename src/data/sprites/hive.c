#include "data/sprites/hive.h"
#include "macros.h"

const s16 sMellowIdleYVelocity[65] = {
    0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
    2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1,
    -2, -2, -2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2,
    -1, -1, -1, -1, 0, 0, 0, 0, SHORT_MAX
};

const s16 sMellowIdleXVelocity[81] = {
    0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7,
    7, 7, 6, 6, 6, 5, 5, 5, 4, 4, 4, 3, 3, 2, 2, 1, 1, 0, 0, 0, 0,
    -1, -1, -2, -2, -3, -3, -4, -4, -4, -5, -5, -5, -6, -6, -6, -7,
    -7, -7, -7, -7, -7, -6, -6, -6, -5, -5, -5, -4, -4, -4, -3, -3,
    -2, -2, -1, -1, 0, 0, SHORT_MAX
};

const u32 sHiveGfx[1799] = INCBIN_U32("data/sprites/hive.gfx.lz");
const u16 sHivePal[96] = INCBIN_U16("data/sprites/hive.pal");

static const u16 sMellowOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sMellowOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x220, 8, 0)
};

static const u16 sMellowOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sMellowOam_Idle_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x224, 8, 0)
};

static const u16 sHiveOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -33, OAM_DIMS_32x64, OAM_NO_FLIP, 0x210, 9, 0)
};

static const u16 sHiveOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -34, OAM_DIMS_32x64, OAM_NO_FLIP, 0x214, 9, 0)
};

static const u16 sHiveOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -34, OAM_DIMS_32x64, OAM_NO_FLIP, 0x218, 9, 0)
};

static const u16 sHiveOam_Idle_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -34, OAM_DIMS_32x64, OAM_NO_FLIP, 0x21c, 9, 0)
};

static const u16 sHiveRootsOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(7, 17, OAM_DIMS_8x16, OAM_X_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-17, 17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(1, 23, OAM_DIMS_8x8, OAM_X_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-11, 23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0)
};

static const u16 sHiveRootsOam_Idle_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-17, 17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(1, 23, OAM_DIMS_8x8, OAM_X_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-11, 23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x245, 9, 0),
    OAM_ENTRY(7, 17, OAM_DIMS_8x16, OAM_X_FLIP, 0x247, 9, 0)
};

static const u16 sHiveRootsOam_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(7, 17, OAM_DIMS_8x16, OAM_X_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-17, 17, OAM_DIMS_8x16, OAM_NO_FLIP, 0x247, 9, 0),
    OAM_ENTRY(1, 23, OAM_DIMS_8x8, OAM_X_FLIP, 0x245, 9, 0),
    OAM_ENTRY(-13, 23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x245, 9, 0)
};

static const u16 sHiveOam_Phase2_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -33, OAM_DIMS_32x64, OAM_NO_FLIP, 0x208, 10, 0)
};

static const u16 sHiveOam_Phase2_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -33, OAM_DIMS_32x64, OAM_NO_FLIP, 0x20c, 10, 0)
};

static const u16 sHiveOam_Phase2_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -33, OAM_DIMS_32x32, OAM_NO_FLIP, 0x308, 10, 0),
    OAM_ENTRY(-16, -1, OAM_DIMS_32x32, OAM_NO_FLIP, 0x310, 10, 0)
};

static const u16 sHiveOam_Phase2_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -33, OAM_DIMS_32x32, OAM_NO_FLIP, 0x30c, 10, 0),
    OAM_ENTRY(-16, -1, OAM_DIMS_32x32, OAM_NO_FLIP, 0x314, 10, 0)
};

static const u16 sHiveOam_Phase3_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -1, OAM_DIMS_32x32, OAM_NO_FLIP, 0x300, 11, 0),
    OAM_ENTRY(-8, -33, OAM_DIMS_16x32, OAM_NO_FLIP, 0x318, 11, 0)
};

static const u16 sHiveOam_Phase3_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -1, OAM_DIMS_32x32, OAM_NO_FLIP, 0x304, 11, 0),
    OAM_ENTRY(-8, -33, OAM_DIMS_16x32, OAM_NO_FLIP, 0x31a, 11, 0)
};

static const u16 sHiveOam_Phase3_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -1, OAM_DIMS_32x32, OAM_NO_FLIP, 0x284, 11, 0),
    OAM_ENTRY(-8, -33, OAM_DIMS_16x32, OAM_NO_FLIP, 0x318, 11, 0)
};

static const u16 sHiveOam_Dying_Frame8[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-16, 15, OAM_DIMS_32x16, OAM_NO_FLIP, 0x344, 12, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_32x16, OAM_NO_FLIP, 0x304, 12, 0),
    OAM_ENTRY(-8, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x378, 12, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x358, 12, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x338, 12, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x318, 12, 0),
    OAM_ENTRY(-5, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x242, 12, 0)
};

static const u16 sHiveOam_Dying_Frame9[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x378, 12, 0),
    OAM_ENTRY(-8, -6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x358, 12, 0),
    OAM_ENTRY(-8, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x338, 12, 0),
    OAM_ENTRY(-8, -19, OAM_DIMS_16x8, OAM_NO_FLIP, 0x318, 12, 0),
    OAM_ENTRY(-16, 18, OAM_DIMS_32x8, OAM_NO_FLIP, 0x344, 12, 0),
    OAM_ENTRY(-16, 23, OAM_DIMS_32x8, OAM_NO_FLIP, 0x364, 12, 0),
    OAM_ENTRY(-16, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 0x324, 12, 0),
    OAM_ENTRY(-16, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x304, 12, 0),
    OAM_ENTRY(-5, -27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x242, 12, 0),
    OAM_ENTRY(-5, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0x243, 12, 0)
};

static const u16 sHiveOam_Dying_Frame10[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2c0, 12, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x209, 12, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x242, 12, 0),
    OAM_ENTRY(-5, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x243, 12, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x241, 12, 0)
};

static const u16 sHiveOam_Dying_Frame11[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x280, 12, 0),
    OAM_ENTRY(-5, 10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x242, 12, 0),
    OAM_ENTRY(-5, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x243, 12, 0),
    OAM_ENTRY(-5, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x243, 11, 0)
};

static const u16 sHiveOam_Dying_Frame12[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x31c, 12, 0)
};

static const u16 sHiveOam_Dying_Frame13[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x33c, 12, 0)
};

static const u16 sHiveOam_Dying_Frame14[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x35c, 12, 0)
};

static const u16 sHiveOam_Dying_Frame30[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x37c, 11, 0)
};

const struct FrameData sMellowOam_Idle[6] = {
    [0] = {
        .pFrame = sMellowOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sMellowOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sMellowOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMellowOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sMellowOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMellowOam_SamusDetected[6] = {
    [0] = {
        .pFrame = sMellowOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMellowOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sMellowOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sMellowOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMellowOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHiveOam_Idle[19] = {
    [0] = {
        .pFrame = sHiveOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sHiveOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(11.f / 60)
    },
    [2] = {
        .pFrame = sHiveOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sHiveOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(11.f / 60)
    },
    [4] = {
        .pFrame = sHiveOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sHiveOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [6] = {
        .pFrame = sHiveOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [7] = {
        .pFrame = sHiveOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [8] = {
        .pFrame = sHiveOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [9] = {
        .pFrame = sHiveOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [10] = {
        .pFrame = sHiveOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [11] = {
        .pFrame = sHiveOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [12] = {
        .pFrame = sHiveOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [13] = {
        .pFrame = sHiveOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [14] = {
        .pFrame = sHiveOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [15] = {
        .pFrame = sHiveOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [16] = {
        .pFrame = sHiveOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [17] = {
        .pFrame = sHiveOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [18] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHiveRootsOam_Idle[4] = {
    [0] = {
        .pFrame = sHiveRootsOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sHiveRootsOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sHiveRootsOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHiveOam_Phase2[12] = {
    [0] = {
        .pFrame = sHiveOam_Phase2_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sHiveOam_Phase2_Frame1,
        .timer = CONVERT_SECONDS(0.15f)
    },
    [2] = {
        .pFrame = sHiveOam_Phase2_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sHiveOam_Phase2_Frame3,
        .timer = CONVERT_SECONDS(0.15f)
    },
    [4] = {
        .pFrame = sHiveOam_Phase2_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sHiveOam_Phase2_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sHiveOam_Phase2_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [7] = {
        .pFrame = sHiveOam_Phase2_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [8] = {
        .pFrame = sHiveOam_Phase2_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [9] = {
        .pFrame = sHiveOam_Phase2_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [10] = {
        .pFrame = sHiveOam_Phase2_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHiveOam_Phase3[13] = {
    [0] = {
        .pFrame = sHiveOam_Phase3_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sHiveOam_Phase3_Frame1,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [2] = {
        .pFrame = sHiveOam_Phase3_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sHiveOam_Phase3_Frame1,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [4] = {
        .pFrame = sHiveOam_Phase3_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sHiveOam_Phase3_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sHiveOam_Phase3_Frame2,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [7] = {
        .pFrame = sHiveOam_Phase3_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = {
        .pFrame = sHiveOam_Phase3_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sHiveOam_Phase3_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sHiveOam_Phase3_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [11] = {
        .pFrame = sHiveOam_Phase3_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sHiveOam_Dying[32] = {
    [0] = {
        .pFrame = sHiveOam_Phase3_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sHiveOam_Phase3_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sHiveOam_Phase3_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sHiveOam_Phase3_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sHiveOam_Phase3_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sHiveOam_Phase3_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sHiveOam_Phase3_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sHiveOam_Phase3_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sHiveOam_Dying_Frame8,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sHiveOam_Dying_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = {
        .pFrame = sHiveOam_Dying_Frame10,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [11] = {
        .pFrame = sHiveOam_Dying_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [12] = {
        .pFrame = sHiveOam_Dying_Frame12,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [13] = {
        .pFrame = sHiveOam_Dying_Frame13,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [14] = {
        .pFrame = sHiveOam_Dying_Frame14,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [15] = {
        .pFrame = sHiveOam_Dying_Frame13,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [16] = {
        .pFrame = sHiveOam_Dying_Frame12,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [17] = {
        .pFrame = sHiveOam_Dying_Frame13,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [18] = {
        .pFrame = sHiveOam_Dying_Frame14,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [19] = {
        .pFrame = sHiveOam_Dying_Frame13,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [20] = {
        .pFrame = sHiveOam_Dying_Frame12,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [21] = {
        .pFrame = sHiveOam_Dying_Frame13,
        .timer = CONVERT_SECONDS(0.15f)
    },
    [22] = {
        .pFrame = sHiveOam_Dying_Frame14,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [23] = {
        .pFrame = sHiveOam_Dying_Frame13,
        .timer = CONVERT_SECONDS(0.15f)
    },
    [24] = {
        .pFrame = sHiveOam_Dying_Frame12,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [25] = {
        .pFrame = sHiveOam_Dying_Frame13,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [26] = {
        .pFrame = sHiveOam_Dying_Frame14,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [27] = {
        .pFrame = sHiveOam_Dying_Frame13,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [28] = {
        .pFrame = sHiveOam_Dying_Frame12,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [29] = {
        .pFrame = sHiveOam_Dying_Frame13,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [30] = {
        .pFrame = sHiveOam_Dying_Frame30,
        .timer = UCHAR_MAX
    },
    [31] = FRAME_DATA_TERMINATOR
};
