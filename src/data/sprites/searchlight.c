#include "data/sprites/searchlight.h"
#include "macros.h"

const u32 sSearchlightGfx[172] = INCBIN_U32("data/sprites/searchlight.gfx.lz");
const u16 sSearchlightPal[16] = INCBIN_U16("data/sprites/searchlight.pal");

static const u16 sSearchlightOam_Moving_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-32, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-32, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_32x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-32, 16, OAM_DIMS_32x16, OAM_Y_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x16, OAM_Y_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, 16, OAM_DIMS_32x16, OAM_XY_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_XY_FLIP, 0x204, 8, 0)
};

static const u16 sSearchlightOam_Moving_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-32, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-32, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_32x16, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-32, 16, OAM_DIMS_32x16, OAM_Y_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x16, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(0, 16, OAM_DIMS_32x16, OAM_XY_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_XY_FLIP, 0x20c, 8, 0)
};

static const u16 sSearchlightOam_Moving_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-32, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-32, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x16, OAM_X_FLIP, 0x210, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_32x16, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-32, 16, OAM_DIMS_32x16, OAM_Y_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x16, OAM_Y_FLIP, 0x214, 8, 0),
    OAM_ENTRY(0, 16, OAM_DIMS_32x16, OAM_XY_FLIP, 0x210, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_XY_FLIP, 0x214, 8, 0)
};

static const u16 sSearchlightOam_Moving_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-32, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-32, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x16, OAM_X_FLIP, 0x218, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_32x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-32, 16, OAM_DIMS_32x16, OAM_Y_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x16, OAM_Y_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(0, 16, OAM_DIMS_32x16, OAM_XY_FLIP, 0x218, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_XY_FLIP, 0x21c, 8, 0)
};

const struct FrameData sSearchlightOam_Moving[7] = {
    [0] = {
        .pFrame = sSearchlightOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sSearchlightOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sSearchlightOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sSearchlightOam_Moving_Frame3,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = {
        .pFrame = sSearchlightOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sSearchlightOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSearchlightOam_Unused[5] = {
    [0] = {
        .pFrame = sSearchlightOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sSearchlightOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sSearchlightOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sSearchlightOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};
