#include "data/sprites/gamet.h"
#include "macros.h"

const u32 sGametBlueGfx[168] = INCBIN_U32("data/sprites/GametBlue.gfx.lz");
const u16 sGametBluePal[16] = INCBIN_U16("data/sprites/GametBlue.pal");
const u32 sGametRedGfx[168] = INCBIN_U32("data/sprites/GametRed.gfx.lz");
const u16 sGametRedPal[16] = INCBIN_U16("data/sprites/GametRed.pal");

static const u16 sGametOam_Idle_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sGametOam_Idle_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sGametOam_Idle_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 517, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sGametOam_Moving_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 521, 8, 0),
};

static const u16 sGametOam_Moving_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 521, 8, 0),
};

static const u16 sGametOam_Moving_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 517, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

const struct FrameData sGametOam_Idle[5] = {
    [0] = {
        .pFrame = sGametOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGametOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sGametOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sGametOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGametOam_Moving[5] = {
    [0] = {
        .pFrame = sGametOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sGametOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sGametOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sGametOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};
