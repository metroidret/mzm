#include "data/sprites/reo.h"
#include "macros.h"

const s16 sReoIdleYMovement[65] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1,
    2, 2, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0, -1, 0, -1, 0, -1, 0,
    -1, -1, -1, -2, -2, -1, -1, -1, 0, -1, 0, -1,
    0, -1, 0, -1, 0, 0, 0, 0, SHORT_MAX
};

const s16 sReoIdleXMovement[81] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1,
    1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 1,
    0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1,
    0, -1, 0, -1, 0, -1, 0, -1, -1, -1, -1, -1,
    -1, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1,
    0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0, SHORT_MAX
};

const u32 sReoGreenWingsGfx[277] = INCBIN_U32("data/sprites/reo_green_wings.gfx.lz");
const u16 sReoGreenWingsPal[16] = INCBIN_U16("data/sprites/reo_green_wings.pal");
const u32 sReoPurpleWingsGfx[277] = INCBIN_U32("data/sprites/reo_purple_wings.gfx.lz");
const u16 sReoPurpleWingsPal[16] = INCBIN_U16("data/sprites/reo_purple_wings.pal");

static const u16 sReoOam_Idle_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21c, 8, 0)
};

static const u16 sReoOam_Idle_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-19, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(3, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-16, -9, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21c, 8, 0)
};

static const u16 sReoOam_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21c, 8, 0)
};

static const u16 sReoOam_Moving_Unused_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21c, 8, 0)
};

static const u16 sReoOam_Moving_Unused_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-18, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(3, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21c, 8, 0)
};

static const u16 sReoOam_Moving_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-21, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21c, 8, 0)
};

static const u16 sReoOam_UnusedFrame[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-21, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21c, 8, 0)
};

static const u16 sReoOam_Idle_Unused_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sReoOam_Idle_Unused_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-18, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(2, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21c, 8, 0)
};

static const u16 sReoOam_Idle_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21c, 8, 0)
};

static const u16 sReoOam_Idle_Unused_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sReoOam_Idle_Unused_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-19, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(3, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sReoOam_Idle_Unused_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sReoOam_Moving_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-19, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(3, -2, OAM_DIMS_16x16, OAM_X_FLIP, 0x210, 8, 0)
};

static const u16 sReoOam_Moving_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-20, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(3, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(3, -3, OAM_DIMS_16x16, OAM_X_FLIP, 0x210, 8, 0)
};

static const u16 sReoOam_Moving_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-23, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-19, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(3, -3, OAM_DIMS_16x16, OAM_X_FLIP, 0x210, 8, 0)
};

static const u16 sReoOam_Moving_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, -1, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0)
};

static const u16 sReoOam_Moving_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-19, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-16, -1, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0)
};

static const u16 sReoOam_Moving_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-22, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(6, -8, OAM_DIMS_16x8, OAM_X_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0)
};

const struct FrameData sReoOam_Unused1[5] = {
    [0] = {
        .pFrame = sReoOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sReoOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sReoOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sReoOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sReoOam_Idle[5] = {
    [0] = {
        .pFrame = sReoOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sReoOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sReoOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sReoOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sReoOam_Idle_Unused[9] = {
    [0] = {
        .pFrame = sReoOam_Idle_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sReoOam_Idle_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sReoOam_Idle_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sReoOam_Idle_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sReoOam_Idle_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sReoOam_Idle_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sReoOam_Idle_Unused_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sReoOam_Idle_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sReoOam_Moving[13] = {
    [0] = {
        .pFrame = sReoOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sReoOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sReoOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sReoOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sReoOam_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sReoOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sReoOam_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sReoOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sReoOam_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sReoOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sReoOam_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [11] = {
        .pFrame = sReoOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sReoOam_Unused2[21] = {
    [0] = {
        .pFrame = sReoOam_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sReoOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sReoOam_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sReoOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sReoOam_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sReoOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sReoOam_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sReoOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sReoOam_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sReoOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sReoOam_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [11] = {
        .pFrame = sReoOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = {
        .pFrame = sReoOam_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sReoOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [14] = {
        .pFrame = sReoOam_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [15] = {
        .pFrame = sReoOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [16] = {
        .pFrame = sReoOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [17] = {
        .pFrame = sReoOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [18] = {
        .pFrame = sReoOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [19] = {
        .pFrame = sReoOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [20] = FRAME_DATA_TERMINATOR
};

const struct FrameData sReoOam_Unused3[9] = {
    [0] = {
        .pFrame = sReoOam_Idle_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sReoOam_Idle_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sReoOam_Idle_Unused_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sReoOam_Idle_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sReoOam_Idle_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sReoOam_Idle_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sReoOam_Idle_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sReoOam_Idle_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sReoOam_Moving_Unused[5] = {
    [0] = {
        .pFrame = sReoOam_Moving_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sReoOam_Moving_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sReoOam_Moving_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sReoOam_Moving_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};
