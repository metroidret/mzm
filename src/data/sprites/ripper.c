#include "data/sprites/ripper.h"
#include "macros.h"

const u32 sRipperBrownGfx[141] = INCBIN_U32("data/sprites/ripper_brown.gfx.lz");
const u16 sRipperBrownPal[16] = INCBIN_U16("data/sprites/ripper_brown.pal");
const u32 sRipperPurpleGfx[141] = INCBIN_U32("data/sprites/ripper_purple.gfx.lz");
const u16 sRipperPurplePal[16] = INCBIN_U16("data/sprites/ripper_purple.pal");

static const u16 sRipperOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sRipperOam_Moving_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0)
};

static const u16 sRipperOam_Moving_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0)
};

static const u16 sRipperOam_TurningAround_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0)
};

static const u16 sRipperOam_TurningAround_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0)
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
