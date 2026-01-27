#include "data/sprites/ripper.h"
#include "macros.h"

const u32 sRipper2Gfx[212] = INCBIN_U32("data/sprites/ripper2.gfx.lz");
const u16 sRipper2Pal[16] = INCBIN_U16("data/sprites/ripper2.pal");

static const u16 sRipper2Oam_Moving_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(12, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0)
};

static const u16 sRipper2Oam_Moving_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(12, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20e, 8, 0)
};

static const u16 sRipper2Oam_Moving_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(12, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20a, 8, 0)
};

static const u16 sRipper2Oam_TurningAround_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0)
};

static const u16 sRipper2Oam_TurningAround_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_16x16, OAM_Y_FLIP, 0x212, 8, 0)
};

const struct FrameData sRipper2Oam_Moving[5] = {
    [0] = {
        .pFrame = sRipper2Oam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sRipper2Oam_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sRipper2Oam_Moving_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sRipper2Oam_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRipper2Oam_TurningAround[3] = {
    [0] = {
        .pFrame = sRipper2Oam_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sRipper2Oam_TurningAround_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRipper2Oam_TurningAroundPart2[3] = {
    [0] = {
        .pFrame = sRipper2Oam_TurningAround_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sRipper2Oam_TurningAround_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};
