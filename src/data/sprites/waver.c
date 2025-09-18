#include "data/sprites/waver.h"
#include "macros.h"

const u32 sWaverGfx[289] = INCBIN_U32("data/sprites/Waver.gfx.lz");
const u16 sWaverPal[16] = INCBIN_U16("data/sprites/Waver.pal");

static const u16 sWaverOam_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-20, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sWaverOam_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-12, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sWaverOam_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-20, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 519, 8, 0),
};

static const u16 sWaverOam_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-12, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 523, 8, 0),
};

static const u16 sWaverOam_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -11, OAM_DIMS_32x16, OAM_NO_FLIP, 526, 8, 0),
    OAM_ENTRY(-20, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 566, 8, 0),
};

static const u16 sWaverOam_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-20, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-20, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 538, 8, 0),
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
