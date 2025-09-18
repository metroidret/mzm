#include "data/sprites/viola.h"
#include "macros.h"

const u32 sViolaBlueGfx[302] = INCBIN_U32("data/sprites/ViolaBlue.gfx.lz");
const u16 sViolaBluePal[16] = INCBIN_U16("data/sprites/ViolaBlue.pal");
const u32 sViolaOrangeGfx[305] = INCBIN_U32("data/sprites/ViolaOrange.gfx.lz");
const u16 sViolaOrangePal[16] = INCBIN_U16("data/sprites/ViolaOrange.pal");

static const u16 sViolaOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sViolaOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sViolaOam_Moving_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sViolaOam_Moving_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sViolaOam_Moving_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sViolaOam_Moving_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
};

static const u16 sViolaOam_Moving_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 524, 8, 0),
};

static const u16 sViolaOam_Moving_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 526, 8, 0),
};

static const u16 sViolaOam_Moving_Frame8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sViolaOam_MovingOffsetUp_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sViolaOam_MovingOffsetUp_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sViolaOam_MovingOffsetUp_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sViolaOam_MovingOffsetUp_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sViolaOam_MovingOffsetUp_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sViolaOam_MovingOffsetUp_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
};

static const u16 sViolaOam_MovingOffsetUp_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 524, 8, 0),
};

static const u16 sViolaOam_MovingOffsetUp_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 526, 8, 0),
};

static const u16 sViolaOam_MovingOffsetUp_Frame8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sViolaOam_MovingOffsetRight_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sViolaOam_MovingOffsetRight_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sViolaOam_MovingOffsetRight_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sViolaOam_MovingOffsetRight_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sViolaOam_MovingOffsetRight_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sViolaOam_MovingOffsetRight_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
};

static const u16 sViolaOam_MovingOffsetRight_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 524, 8, 0),
};

static const u16 sViolaOam_MovingOffsetRight_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 526, 8, 0),
};

static const u16 sViolaOam_MovingOffsetRight_Frame8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sViolaOam_MovingOffsetDown_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sViolaOam_MovingOffsetDown_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sViolaOam_MovingOffsetDown_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sViolaOam_MovingOffsetDown_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sViolaOam_MovingOffsetDown_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sViolaOam_MovingOffsetDown_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
};

static const u16 sViolaOam_MovingOffsetDown_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 524, 8, 0),
};

static const u16 sViolaOam_MovingOffsetDown_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 526, 8, 0),
};

static const u16 sViolaOam_MovingOffsetDown_Frame8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
};

const struct FrameData sViolaOam_Moving[17] = {
    [0] = {
        .pFrame = sViolaOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sViolaOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sViolaOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sViolaOam_Moving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = {
        .pFrame = sViolaOam_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [5] = {
        .pFrame = sViolaOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [6] = {
        .pFrame = sViolaOam_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [7] = {
        .pFrame = sViolaOam_Moving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [8] = {
        .pFrame = sViolaOam_Moving_Frame8,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [9] = {
        .pFrame = sViolaOam_Moving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [10] = {
        .pFrame = sViolaOam_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [11] = {
        .pFrame = sViolaOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [12] = {
        .pFrame = sViolaOam_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [13] = {
        .pFrame = sViolaOam_Moving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [14] = {
        .pFrame = sViolaOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [15] = {
        .pFrame = sViolaOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sViolaOam_MovingOffsetUp[17] = {
    [0] = {
        .pFrame = sViolaOam_MovingOffsetUp_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sViolaOam_MovingOffsetUp_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sViolaOam_MovingOffsetUp_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sViolaOam_MovingOffsetUp_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = {
        .pFrame = sViolaOam_MovingOffsetUp_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [5] = {
        .pFrame = sViolaOam_MovingOffsetUp_Frame5,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [6] = {
        .pFrame = sViolaOam_MovingOffsetUp_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [7] = {
        .pFrame = sViolaOam_MovingOffsetUp_Frame7,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [8] = {
        .pFrame = sViolaOam_MovingOffsetUp_Frame8,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [9] = {
        .pFrame = sViolaOam_MovingOffsetUp_Frame7,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [10] = {
        .pFrame = sViolaOam_MovingOffsetUp_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [11] = {
        .pFrame = sViolaOam_MovingOffsetUp_Frame5,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [12] = {
        .pFrame = sViolaOam_MovingOffsetUp_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [13] = {
        .pFrame = sViolaOam_MovingOffsetUp_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [14] = {
        .pFrame = sViolaOam_MovingOffsetUp_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [15] = {
        .pFrame = sViolaOam_MovingOffsetUp_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sViolaOam_MovingOffsetRight[17] = {
    [0] = {
        .pFrame = sViolaOam_MovingOffsetRight_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sViolaOam_MovingOffsetRight_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sViolaOam_MovingOffsetRight_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sViolaOam_MovingOffsetRight_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = {
        .pFrame = sViolaOam_MovingOffsetRight_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [5] = {
        .pFrame = sViolaOam_MovingOffsetRight_Frame5,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [6] = {
        .pFrame = sViolaOam_MovingOffsetRight_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [7] = {
        .pFrame = sViolaOam_MovingOffsetRight_Frame7,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [8] = {
        .pFrame = sViolaOam_MovingOffsetRight_Frame8,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [9] = {
        .pFrame = sViolaOam_MovingOffsetRight_Frame7,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [10] = {
        .pFrame = sViolaOam_MovingOffsetRight_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [11] = {
        .pFrame = sViolaOam_MovingOffsetRight_Frame5,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [12] = {
        .pFrame = sViolaOam_MovingOffsetRight_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [13] = {
        .pFrame = sViolaOam_MovingOffsetRight_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [14] = {
        .pFrame = sViolaOam_MovingOffsetRight_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [15] = {
        .pFrame = sViolaOam_MovingOffsetRight_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [16] = FRAME_DATA_TERMINATOR
};

const struct FrameData sViolaOam_MovingOffsetDown[17] = {
    [0] = {
        .pFrame = sViolaOam_MovingOffsetDown_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sViolaOam_MovingOffsetDown_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sViolaOam_MovingOffsetDown_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sViolaOam_MovingOffsetDown_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = {
        .pFrame = sViolaOam_MovingOffsetDown_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [5] = {
        .pFrame = sViolaOam_MovingOffsetDown_Frame5,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [6] = {
        .pFrame = sViolaOam_MovingOffsetDown_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [7] = {
        .pFrame = sViolaOam_MovingOffsetDown_Frame7,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [8] = {
        .pFrame = sViolaOam_MovingOffsetDown_Frame8,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [9] = {
        .pFrame = sViolaOam_MovingOffsetDown_Frame7,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [10] = {
        .pFrame = sViolaOam_MovingOffsetDown_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [11] = {
        .pFrame = sViolaOam_MovingOffsetDown_Frame5,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [12] = {
        .pFrame = sViolaOam_MovingOffsetDown_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [13] = {
        .pFrame = sViolaOam_MovingOffsetDown_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [14] = {
        .pFrame = sViolaOam_MovingOffsetDown_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [15] = {
        .pFrame = sViolaOam_MovingOffsetDown_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [16] = FRAME_DATA_TERMINATOR
};
