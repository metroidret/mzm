#include "data/sprites/mella.h"
#include "macros.h"

const s16 sMellaIdleYMovement[65] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1,
    2, 2, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0, -1, 0, -1, 0, -1, 0,
    -1, -1, -1, -2, -2, -1, -1, -1, 0, -1, 0, -1,
    0, -1, 0, -1, 0, 0, 0, 0, SHORT_MAX
};

const s16 sMellaIdleXMovement[49] = {
    1, 0, 1, 0, 1, 1, 1, 2, 2, 1, 1, 1, 0, 1, 0,
    1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0,
    -1, 0, -1, 0, -1, 0, -1, -1, -1, -2, -2, -1,
    -1, -1, 0, -1, 0, -1, SHORT_MAX
};

const u16 sMellaGoingDownYMovement[6] = {
    1, 2, 3, 4, 5, 6
};

const u16 sMellaGoingUpYMovement[7] = {
    0, 1, 2, 3, 4, 5, 6
};

const u16 sMellaMovingXMovement[7] = {
    0, 1, 2, 3, 4, 5, 6 
};

const u32 sMellaGfx[162] = INCBIN_U32("data/sprites/mella.gfx.lz");
const u16 sMellaPal[16] = INCBIN_U16("data/sprites/mella.pal");

static const u16 sMellaOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sMellaOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sMellaOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0)
};

static const u16 sMellaOam_Idle_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0)
};

static const u16 sMellaOam_Idle_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0)
};

static const u16 sMellaOam_Idle_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0)
};

static const u16 sMellaOam_Idle_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sMellaOam_Idle_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21c, 8, 0)
};

static const u16 sMellaOam_Moving_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x224, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sMellaOam_Moving_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sMellaOam_Moving_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sMellaOam_Moving_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0)
};

static const u16 sMellaOam_Moving_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0)
};

static const u16 sMellaOam_Moving_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x20c, 8, 0)
};

const struct FrameData sMellaOam_Idle[9] = {
    [0] = {
        .pFrame = sMellaOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sMellaOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sMellaOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sMellaOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sMellaOam_Idle_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sMellaOam_Idle_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sMellaOam_Idle_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [7] = {
        .pFrame = sMellaOam_Idle_Frame7,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMellowOAM_Moving[9] = {
    [0] = {
        .pFrame = sMellaOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMellaOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sMellaOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMellaOam_Moving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMellaOam_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sMellaOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sMellaOam_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sMellaOam_Idle_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = FRAME_DATA_TERMINATOR
};
