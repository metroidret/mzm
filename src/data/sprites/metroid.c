#include "data/sprites/metroid.h"
#include "macros.h"

const s16 sMetroidSpawningYMovement[65] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 2, 2, 1,
    1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    -1, 0, -1, 0, -1, 0, -1, 0, -1, -1, -1, -2, -2, -1,
    -1, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0, SHORT_MAX
};

const s16 sMetroidSpawningXMovement[81] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, -1, 0, -1, 0,
    -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -1, -1, -1,
    -1, -1, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0, SHORT_MAX 
};

const u32 sMetroidGfx[793] = INCBIN_U32("data/sprites/metroid.gfx.lz");
const u16 sMetroidPal[80] = INCBIN_U16("data/sprites/metroid.pal");
const u16 sMetroidPal_SamusGrabbed[80] = INCBIN_U16("data/sprites/metroid_samus_grabbed.pal");

static const u16 sMetroidShellOam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -17, OAM_DIMS_32x32, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(12, -17, OAM_DIMS_8x32, OAM_NO_FLIP, 0x208, 8, 0)
};

static const u16 sMetroidShellOam_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -17, OAM_DIMS_32x32, OAM_NO_FLIP, 0x284, 8, 0),
    OAM_ENTRY(12, -17, OAM_DIMS_8x32, OAM_NO_FLIP, 0x288, 8, 0)
};

static const u16 sMetroidOam_Moving_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x304, 8, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_16x16, OAM_X_FLIP, 0x304, 8, 0)
};

static const u16 sMetroidOam_Moving_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x300, 8, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x306, 8, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_16x16, OAM_X_FLIP, 0x306, 8, 0)
};

static const u16 sMetroidOam_Moving_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2a0, 8, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x308, 8, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_16x16, OAM_X_FLIP, 0x308, 8, 0)
};

static const u16 sMetroidOam_Moving_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2a0, 8, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x308, 8, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_16x16, OAM_X_FLIP, 0x308, 8, 0)
};

static const u16 sMetroidOam_Moving_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24a, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2a0, 8, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x308, 8, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_16x16, OAM_X_FLIP, 0x308, 8, 0)
};

static const u16 sMetroidOam_Moving_Frame9[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2ca, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x300, 8, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x306, 8, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_16x16, OAM_X_FLIP, 0x306, 8, 0)
};

const u16 sMetroidOam_Moving_Frame10[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2ea, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x32a, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x300, 8, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x306, 8, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_16x16, OAM_X_FLIP, 0x306, 8, 0)
};

static const u16 sMetroidOam_Spawning_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -33, OAM_DIMS_64x64, OAM_NO_FLIP, 0x210, 8, 0)
};

static const u16 sMetroidOam_Spawning_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -33, OAM_DIMS_64x64, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sMetroidOam_SamusGrabbed_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 12, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x240, 12, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x304, 12, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_16x16, OAM_X_FLIP, 0x304, 12, 0)
};

static const u16 sMetroidOam_SamusGrabbed_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2c0, 12, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x300, 12, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x306, 12, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_16x16, OAM_X_FLIP, 0x306, 12, 0)
};

static const u16 sMetroidOam_SamusGrabbed_Frame7[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x260, 12, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2a0, 12, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x308, 12, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_16x16, OAM_X_FLIP, 0x308, 12, 0)
};

static const u16 sMetroidOam_SamusGrabbed_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20a, 12, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x260, 12, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2a0, 12, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x308, 12, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_16x16, OAM_X_FLIP, 0x308, 12, 0)
};

static const u16 sMetroidOam_SamusGrabbed_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24a, 12, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x260, 12, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2a0, 12, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x308, 12, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_16x16, OAM_X_FLIP, 0x308, 12, 0)
};

static const u16 sMetroidOam_SamusGrabbed_Frame8[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x28a, 12, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2ca, 12, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2c0, 12, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x300, 12, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x306, 12, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_16x16, OAM_X_FLIP, 0x306, 12, 0)
};

static const u16 sMetroidOam_SamusGrabbed_Frame9[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2ea, 12, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x32a, 12, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2c0, 12, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x300, 12, 0),
    OAM_ENTRY(-16, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x306, 12, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_16x16, OAM_X_FLIP, 0x306, 12, 0)
};

const struct FrameData sMetroidShellOam_Idle[3] = {
    [0] = {
        .pFrame = sMetroidShellOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sMetroidShellOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMetroidOam_Moving[17] = {
    [0] = {
        .pFrame = sMetroidOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sMetroidOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sMetroidOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMetroidOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMetroidOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sMetroidOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [6] = {
        .pFrame = sMetroidOam_Moving_Frame6,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [7] = {
        .pFrame = sMetroidOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [8] = {
        .pFrame = sMetroidOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [9] = {
        .pFrame = sMetroidOam_Moving_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = {
        .pFrame = sMetroidOam_Moving_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sMetroidOam_Moving_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [12] = {
        .pFrame = sMetroidOam_Moving_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [13] = {
        .pFrame = sMetroidOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [14] = {
        .pFrame = sMetroidOam_Moving_Frame6,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [15] = {
        .pFrame = sMetroidOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMetroidOam_SamusGrabbed[15] = {
    [0] = {
        .pFrame = sMetroidOam_SamusGrabbed_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMetroidOam_SamusGrabbed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sMetroidOam_SamusGrabbed_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMetroidOam_SamusGrabbed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMetroidOam_SamusGrabbed_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sMetroidOam_SamusGrabbed_Frame5,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sMetroidOam_SamusGrabbed_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = {
        .pFrame = sMetroidOam_SamusGrabbed_Frame7,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [8] = {
        .pFrame = sMetroidOam_SamusGrabbed_Frame8,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sMetroidOam_SamusGrabbed_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = {
        .pFrame = sMetroidOam_SamusGrabbed_Frame8,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sMetroidOam_SamusGrabbed_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [12] = {
        .pFrame = sMetroidOam_SamusGrabbed_Frame5,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [13] = {
        .pFrame = sMetroidOam_SamusGrabbed_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [14] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMetroidOam_Spawning[3] = {
    [0] = {
        .pFrame = sMetroidOam_Spawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sMetroidOam_Spawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = FRAME_DATA_TERMINATOR
};
