#include "data/sprites/zebbo.h"
#include "macros.h"

const u32 sZebboGreenGfx[124] = INCBIN_U32("data/sprites/ZebboGreen.gfx.lz");
const u16 sZebboGreenPal[16] = INCBIN_U16("data/sprites/ZebboGreen.pal");
const u32 sZebboYellowGfx[124] = INCBIN_U32("data/sprites/ZebboYellow.gfx.lz");
const u16 sZebboYellowPal[16] = INCBIN_U16("data/sprites/ZebboYellow.pal");

static const u16 sZebboOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sZebboOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sZebboOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sZebboOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sZebboOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sZebboOam_Moving_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
};

const struct FrameData sZebboOam_Idle[5] = {
    [0] = {
        .pFrame = sZebboOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZebboOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZebboOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sZebboOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZebboOam_Moving[5] = {
    [0] = {
        .pFrame = sZebboOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZebboOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sZebboOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sZebboOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};
