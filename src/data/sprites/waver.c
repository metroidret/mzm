#include "data/sprites/waver.h"
#include "macros.h"

const u32 sWaverGfx[289] = INCBIN_U32("data/sprites/waver.gfx.lz");
const u16 sWaverPal[16] = INCBIN_U16("data/sprites/waver.pal");

static const u16 sWaverOam_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-20, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x216, 8, 0)
};

static const u16 sWaverOam_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-12, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sWaverOam_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-20, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x207, 8, 0)
};

static const u16 sWaverOam_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-12, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20b, 8, 0)
};

static const u16 sWaverOam_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-20, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x236, 8, 0)
};

static const u16 sWaverOam_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-20, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x21a, 8, 0)
};

const struct FrameData sWaverOam[7] = {
    [0] = {
        .pFrame = sWaverOam_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sWaverOam_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sWaverOam_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sWaverOam_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sWaverOam_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sWaverOam_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};
