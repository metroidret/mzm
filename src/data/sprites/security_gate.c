#include "data/sprites/security_gate.h"
#include "macros.h"

const u32 sSecurityGateGfx[122] = INCBIN_U32("data/sprites/SecurityGate.gfx.lz");
const u16 sSecurityGatePal[16] = INCBIN_U16("data/sprites/SecurityGate.pal");

static const u16 sSecurityGateOam_Opened_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 556, 8, 0),
};

static const u16 sSecurityGateOam_Closing_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -64, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
};

static const u16 sSecurityGateOam_Closing_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -64, OAM_DIMS_16x8, OAM_NO_FLIP, 550, 8, 0),
};

static const u16 sSecurityGateOam_Closing_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sSecurityGateOam_Closing_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sSecurityGateOam_Closing_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x8, OAM_NO_FLIP, 544, 8, 0),
};

static const u16 sSecurityGateOam_Closing_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x8, OAM_NO_FLIP, 552, 8, 0),
};

static const u16 sSecurityGateOam_Closing_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityGateOam_Closing_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sSecurityGateOam_Closing_Frame8[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x8, OAM_NO_FLIP, 552, 8, 0),
};

static const u16 sSecurityGateOam_Closing_Frame9[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-8, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x8, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityGateOam_Closing_Frame10[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sSecurityGateOam_Closing_Frame11[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSecurityGateOam_Closing_Frame12[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x8, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityGateOam_Closing_Frame13[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-8, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x8, OAM_NO_FLIP, 544, 8, 0),
};

static const u16 sSecurityGateOam_Closing_Frame14[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSecurityGateOam_Closing_Frame15[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x8, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-8, -56, OAM_DIMS_16x8, OAM_NO_FLIP, 544, 8, 0),
};

static const u16 sSecurityGateOam_Closing_Frame16[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-8, -53, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-8, -69, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
};

static const u16 sSecurityGateOam_Closed_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-8, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x8, OAM_NO_FLIP, 554, 8, 0),
};

static const u16 sSecurityGateOam_Closed_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 526, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-8, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x8, OAM_NO_FLIP, 554, 8, 0),
};

static const u16 sSecurityGateOam_Closed_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 534, 8, 0),
    OAM_ENTRY(-8, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x8, OAM_NO_FLIP, 554, 8, 0),
};

const struct FrameData sSecurityGateOam_Opened[2] = {
    [0] = {
        .pFrame = sSecurityGateOam_Opened_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityGateOam_Closing[18] = {
    [0] = {
        .pFrame = sSecurityGateOam_Closing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSecurityGateOam_Closing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSecurityGateOam_Closing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSecurityGateOam_Closing_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSecurityGateOam_Closing_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSecurityGateOam_Closing_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sSecurityGateOam_Closing_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sSecurityGateOam_Closing_Frame7,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sSecurityGateOam_Closing_Frame8,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sSecurityGateOam_Closing_Frame9,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sSecurityGateOam_Closing_Frame10,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [11] = {
        .pFrame = sSecurityGateOam_Closing_Frame11,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = {
        .pFrame = sSecurityGateOam_Closing_Frame12,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [13] = {
        .pFrame = sSecurityGateOam_Closing_Frame13,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [14] = {
        .pFrame = sSecurityGateOam_Closing_Frame14,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [15] = {
        .pFrame = sSecurityGateOam_Closing_Frame15,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [16] = {
        .pFrame = sSecurityGateOam_Closing_Frame16,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [17] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityGateOam_Closed[4] = {
    [0] = {
        .pFrame = sSecurityGateOam_Closed_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sSecurityGateOam_Closed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sSecurityGateOam_Closed_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityGateOam_Opening[18] = {
    [0] = {
        .pFrame = sSecurityGateOam_Closing_Frame16,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSecurityGateOam_Closing_Frame15,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSecurityGateOam_Closing_Frame14,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSecurityGateOam_Closing_Frame13,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSecurityGateOam_Closing_Frame12,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSecurityGateOam_Closing_Frame11,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sSecurityGateOam_Closing_Frame10,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sSecurityGateOam_Closing_Frame9,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sSecurityGateOam_Closing_Frame8,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sSecurityGateOam_Closing_Frame7,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sSecurityGateOam_Closing_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [11] = {
        .pFrame = sSecurityGateOam_Closing_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = {
        .pFrame = sSecurityGateOam_Closing_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [13] = {
        .pFrame = sSecurityGateOam_Closing_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [14] = {
        .pFrame = sSecurityGateOam_Closing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [15] = {
        .pFrame = sSecurityGateOam_Closing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [16] = {
        .pFrame = sSecurityGateOam_Closing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [17] = FRAME_DATA_TERMINATOR
};
