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

const u32 sMellaGfx[162] = INCBIN_U32("data/sprites/Mella.gfx.lz");
const u16 sMellaPal[16] = INCBIN_U16("data/sprites/Mella.pal");

static const u16 sMellaOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sMellaOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sMellaOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sMellaOam_Idle_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
};

static const u16 sMellaOam_Idle_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sMellaOam_Idle_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 532, 8, 0),
};

static const u16 sMellaOam_Idle_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sMellaOam_Idle_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sMellaOam_Moving_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 548, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sMellaOam_Moving_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 552, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sMellaOam_Moving_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 556, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sMellaOam_Moving_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 560, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sMellaOam_Moving_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 564, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sMellaOam_Moving_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 568, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 524, 8, 0),
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
