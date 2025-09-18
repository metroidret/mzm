#include "data/sprites/ripper.h"
#include "macros.h"

const u32 sRipperBrownGfx[141] = INCBIN_U32("data/sprites/RipperBrown.gfx.lz");
const u16 sRipperBrownPal[16] = INCBIN_U16("data/sprites/RipperBrown.pal");
const u32 sRipperPurpleGfx[141] = INCBIN_U32("data/sprites/RipperPurple.gfx.lz");
const u16 sRipperPurplePal[16] = INCBIN_U16("data/sprites/RipperPurple.pal");

static const u16 sRipperOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sRipperOam_Moving_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sRipperOam_Moving_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sRipperOam_TurningAround_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sRipperOam_TurningAround_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 524, 8, 0),
};

const struct FrameData sRipperOam_Moving[5] = {
    [0] = {
        .pFrame = sRipperOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sRipperOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sRipperOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [3] = {
        .pFrame = sRipperOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRipperOam_TurningAround[3] = {
    [0] = {
        .pFrame = sRipperOam_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sRipperOam_TurningAround_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRipperOam_TurningAroundPart2[3] = {
    [0] = {
        .pFrame = sRipperOam_TurningAround_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sRipperOam_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};
