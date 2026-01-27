#include "data/sprites/escape_gate.h"

#include "macros.h"

const u8 sEscapeGateAndTimerGfx[2048] = INCBIN_U8("data/sprites/escape_gate_and_timer.gfx");
const u16 sEscapeGateAndTimerPal[16] = INCBIN_U16("data/sprites/escape_gate_and_timer.pal");
const u16 sEscapeGateFlashingPal[96] = INCBIN_U16("data/sprites/escape_gate_flashing.pal");

static const u16 sEscapeGateOam_Closed_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -64, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cb, 15, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cf, 15, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d3, 15, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d7, 15, 0),
    OAM_ENTRY(-16, -38, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3db, 15, 0)
};

static const u16 sEscapeGateOam_Opening_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -64, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cb, 15, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cf, 15, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d3, 15, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d7, 15, 0),
    OAM_ENTRY(-16, -38, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3fb, 15, 0)
};

static const u16 sEscapeGateOam_Opening_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -64, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cb, 15, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cf, 15, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d3, 15, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d7, 15, 0)
};

static const u16 sEscapeGateOam_Opening_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -66, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cb, 15, 0),
    OAM_ENTRY(-16, -50, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cf, 15, 0),
    OAM_ENTRY(-16, -30, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d3, 15, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d7, 15, 0)
};

static const u16 sEscapeGateOam_Opening_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -67, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cb, 15, 0),
    OAM_ENTRY(-16, -51, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cf, 15, 0),
    OAM_ENTRY(-16, -29, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d3, 15, 0),
    OAM_ENTRY(-16, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d7, 15, 0)
};

static const u16 sEscapeGateOam_Opening_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -68, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cb, 15, 0),
    OAM_ENTRY(-16, -52, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cf, 15, 0),
    OAM_ENTRY(-16, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d3, 15, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d7, 15, 0)
};

static const u16 sEscapeGateOam_Opening_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -70, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cb, 15, 0),
    OAM_ENTRY(-16, -54, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cf, 15, 0),
    OAM_ENTRY(-16, -26, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d3, 15, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d7, 15, 0)
};

static const u16 sEscapeGateOam_Opening_Frame7[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -56, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cf, 15, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d3, 15, 0),
    OAM_ENTRY(-16, -64, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3eb, 15, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3d7, 15, 0)
};

static const u16 sEscapeGateOam_Opening_Frame8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -58, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cf, 15, 0),
    OAM_ENTRY(-16, -22, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d3, 15, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3d7, 15, 0),
    OAM_ENTRY(-16, -66, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3eb, 15, 0)
};

static const u16 sEscapeGateOam_Opening_Frame9[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -60, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cf, 15, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d3, 15, 0),
    OAM_ENTRY(-16, -68, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3eb, 15, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3d7, 15, 0)
};

static const u16 sEscapeGateOam_Opening_Frame10[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -62, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cf, 15, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d3, 15, 0),
    OAM_ENTRY(-16, -70, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3eb, 15, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3d7, 15, 0)
};

static const u16 sEscapeGateOam_Opening_Frame11[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -64, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cf, 15, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d3, 15, 0),
    OAM_ENTRY(-16, -72, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3eb, 15, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3d7, 15, 0)
};

static const u16 sEscapeGateOam_Opening_Frame12[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -66, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cf, 15, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d3, 15, 0)
};

static const u16 sEscapeGateOam_Opening_Frame13[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -68, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cf, 15, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d3, 15, 0)
};

static const u16 sEscapeGateOam_Opening_Frame14[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -70, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cf, 15, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d3, 15, 0)
};

static const u16 sEscapeGateOam_Opening_Frame15[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -72, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3cf, 15, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d3, 15, 0)
};

static const u16 sEscapeGateOam_Opening_Frame16[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -66, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3ef, 15, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3d3, 15, 0)
};

const struct FrameData sEscapeGateOam_Closed[2] = {
    [0] = {
        .pFrame = sEscapeGateOam_Closed_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEscapeGateOam_Opening[18] = {
    [0] = {
        .pFrame = sEscapeGateOam_Closed_Frame0,
        .timer = CONVERT_SECONDS(5.f / 6)
    },
    [1] = {
        .pFrame = sEscapeGateOam_Opening_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sEscapeGateOam_Opening_Frame2,
        .timer = CONVERT_SECONDS(5.f / 6)
    },
    [3] = {
        .pFrame = sEscapeGateOam_Opening_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sEscapeGateOam_Opening_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [5] = {
        .pFrame = sEscapeGateOam_Opening_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sEscapeGateOam_Opening_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sEscapeGateOam_Opening_Frame7,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sEscapeGateOam_Opening_Frame8,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sEscapeGateOam_Opening_Frame9,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sEscapeGateOam_Opening_Frame10,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [11] = {
        .pFrame = sEscapeGateOam_Opening_Frame11,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = {
        .pFrame = sEscapeGateOam_Opening_Frame12,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [13] = {
        .pFrame = sEscapeGateOam_Opening_Frame13,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [14] = {
        .pFrame = sEscapeGateOam_Opening_Frame14,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [15] = {
        .pFrame = sEscapeGateOam_Opening_Frame15,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [16] = {
        .pFrame = sEscapeGateOam_Opening_Frame16,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [17] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEscapeGateOam_Opened[2] = {
    [0] = {
        .pFrame = sEscapeGateOam_Opening_Frame16,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
