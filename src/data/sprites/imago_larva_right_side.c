#include "data/sprites/imago_larva_right_side.h"
#include "macros.h"

const u32 sImagoLarvaRightSideGfx[592] = INCBIN_U32("data/sprites/imago_larva_right_side.gfx.lz");
const u16 sImagoLarvaRightSidePal[32] = INCBIN_U16("data/sprites/imago_larva_right_side.pal");

static const u16 sImagoLarvaRightSideOam_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-48, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 2),
    OAM_ENTRY(-48, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 2),
    OAM_ENTRY(-32, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 2),
    OAM_ENTRY(-32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 2),
    OAM_ENTRY(-16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 2),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 2),
    OAM_ENTRY(0, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 2),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 2),
    OAM_ENTRY(16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 8, 2),
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 2),
    OAM_ENTRY(32, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 2),
    OAM_ENTRY(32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 2)
};

static const u16 sImagoLarvaRightSideOam_Frame1[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-47, -49, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 2),
    OAM_ENTRY(-47, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 2),
    OAM_ENTRY(-32, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 2),
    OAM_ENTRY(-32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 2),
    OAM_ENTRY(-16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 2),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 2),
    OAM_ENTRY(0, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 2),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 2),
    OAM_ENTRY(16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 8, 2),
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 2),
    OAM_ENTRY(32, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 2),
    OAM_ENTRY(32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 2)
};

static const u16 sImagoLarvaRightSideOam_Frame2[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-46, -50, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 2),
    OAM_ENTRY(-46, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 2),
    OAM_ENTRY(-31, -49, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 2),
    OAM_ENTRY(-31, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 2),
    OAM_ENTRY(-16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 2),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 2),
    OAM_ENTRY(0, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 2),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 2),
    OAM_ENTRY(16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 8, 2),
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 2),
    OAM_ENTRY(32, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 2),
    OAM_ENTRY(32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 2)
};

static const u16 sImagoLarvaRightSideOam_Frame3[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-46, -50, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 2),
    OAM_ENTRY(-46, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 2),
    OAM_ENTRY(-30, -50, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 2),
    OAM_ENTRY(-30, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 2),
    OAM_ENTRY(-15, -49, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 2),
    OAM_ENTRY(-15, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 2),
    OAM_ENTRY(0, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 2),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 2),
    OAM_ENTRY(16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 8, 2),
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 2),
    OAM_ENTRY(32, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 2),
    OAM_ENTRY(32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 2)
};

static const u16 sImagoLarvaRightSideOam_Frame4[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-47, -49, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 2),
    OAM_ENTRY(-47, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 2),
    OAM_ENTRY(-31, -50, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 2),
    OAM_ENTRY(-31, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 2),
    OAM_ENTRY(-15, -50, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 2),
    OAM_ENTRY(-15, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 2),
    OAM_ENTRY(0, -49, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 2),
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 2),
    OAM_ENTRY(16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 8, 2),
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 2),
    OAM_ENTRY(32, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 2),
    OAM_ENTRY(32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 2)
};

static const u16 sImagoLarvaRightSideOam_Frame5[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-48, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 2),
    OAM_ENTRY(-48, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 2),
    OAM_ENTRY(-32, -49, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 2),
    OAM_ENTRY(-32, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 2),
    OAM_ENTRY(-16, -50, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 2),
    OAM_ENTRY(-16, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 2),
    OAM_ENTRY(0, -50, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 2),
    OAM_ENTRY(0, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 2),
    OAM_ENTRY(16, -49, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 8, 2),
    OAM_ENTRY(16, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 2),
    OAM_ENTRY(32, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 2),
    OAM_ENTRY(32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 2)
};

static const u16 sImagoLarvaRightSideOam_Frame6[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-48, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 2),
    OAM_ENTRY(-48, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 2),
    OAM_ENTRY(-32, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 2),
    OAM_ENTRY(-32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 2),
    OAM_ENTRY(-16, -49, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 2),
    OAM_ENTRY(-16, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 2),
    OAM_ENTRY(0, -50, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 2),
    OAM_ENTRY(0, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 2),
    OAM_ENTRY(15, -50, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 8, 2),
    OAM_ENTRY(15, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 2),
    OAM_ENTRY(30, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 2),
    OAM_ENTRY(30, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 2)
};

static const u16 sImagoLarvaRightSideOam_Frame7[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-48, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 2),
    OAM_ENTRY(-48, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 2),
    OAM_ENTRY(-32, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 2),
    OAM_ENTRY(-32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 2),
    OAM_ENTRY(-16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 2),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 2),
    OAM_ENTRY(0, -49, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 2),
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 2),
    OAM_ENTRY(15, -50, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 8, 2),
    OAM_ENTRY(15, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 2),
    OAM_ENTRY(30, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 2),
    OAM_ENTRY(30, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 2)
};

static const u16 sImagoLarvaRightSideOam_Frame8[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-48, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 2),
    OAM_ENTRY(-48, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 2),
    OAM_ENTRY(-32, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 2),
    OAM_ENTRY(-32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 2),
    OAM_ENTRY(-16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 2),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 2),
    OAM_ENTRY(0, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 2),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 2),
    OAM_ENTRY(15, -49, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 8, 2),
    OAM_ENTRY(15, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 2),
    OAM_ENTRY(30, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 2),
    OAM_ENTRY(30, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 2)
};

static const u16 sImagoLarvaRightSideOam_Frame9[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-48, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 2),
    OAM_ENTRY(-48, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 2),
    OAM_ENTRY(-32, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 2),
    OAM_ENTRY(-32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 2),
    OAM_ENTRY(-16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 2),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 2),
    OAM_ENTRY(0, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 2),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 2),
    OAM_ENTRY(16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 8, 2),
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 2),
    OAM_ENTRY(31, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 2),
    OAM_ENTRY(31, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 2)
};

static const u16 sImagoLarvaRightSideOam_Frame11[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 2),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x258, 8, 2),
    OAM_ENTRY(-48, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 2),
    OAM_ENTRY(-48, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 2),
    OAM_ENTRY(-32, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 2),
    OAM_ENTRY(-32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 2),
    OAM_ENTRY(-16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 2),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 2),
    OAM_ENTRY(0, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 2),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 2),
    OAM_ENTRY(16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 8, 2),
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 2),
    OAM_ENTRY(32, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 2),
    OAM_ENTRY(32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 2)
};

static const u16 sImagoLarvaRightSideOam_Frame12[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-16, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x21c, 8, 2),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 2),
    OAM_ENTRY(-48, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 2),
    OAM_ENTRY(-48, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 2),
    OAM_ENTRY(-32, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 2),
    OAM_ENTRY(-32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 2),
    OAM_ENTRY(-16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 2),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 2),
    OAM_ENTRY(0, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 2),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 2),
    OAM_ENTRY(16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 8, 2),
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 2),
    OAM_ENTRY(32, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24a, 8, 2),
    OAM_ENTRY(32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 2)
};

const struct FrameData sImagoLarvaRightSideOam[35] = {
    [0] = {
        .pFrame = sImagoLarvaRightSideOam_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sImagoLarvaRightSideOam_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sImagoLarvaRightSideOam_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sImagoLarvaRightSideOam_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sImagoLarvaRightSideOam_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sImagoLarvaRightSideOam_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sImagoLarvaRightSideOam_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [7] = {
        .pFrame = sImagoLarvaRightSideOam_Frame7,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [8] = {
        .pFrame = sImagoLarvaRightSideOam_Frame8,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [9] = {
        .pFrame = sImagoLarvaRightSideOam_Frame9,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [10] = {
        .pFrame = sImagoLarvaRightSideOam_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [11] = {
        .pFrame = sImagoLarvaRightSideOam_Frame11,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [12] = {
        .pFrame = sImagoLarvaRightSideOam_Frame12,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [13] = {
        .pFrame = sImagoLarvaRightSideOam_Frame11,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [14] = {
        .pFrame = sImagoLarvaRightSideOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [15] = {
        .pFrame = sImagoLarvaRightSideOam_Frame11,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [16] = {
        .pFrame = sImagoLarvaRightSideOam_Frame12,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [17] = {
        .pFrame = sImagoLarvaRightSideOam_Frame11,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [18] = {
        .pFrame = sImagoLarvaRightSideOam_Frame0,
        .timer = CONVERT_SECONDS(1.0f)
    },
    [19] = {
        .pFrame = sImagoLarvaRightSideOam_Frame11,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [20] = {
        .pFrame = sImagoLarvaRightSideOam_Frame12,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [21] = {
        .pFrame = sImagoLarvaRightSideOam_Frame11,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [22] = {
        .pFrame = sImagoLarvaRightSideOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [23] = {
        .pFrame = sImagoLarvaRightSideOam_Frame11,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [24] = {
        .pFrame = sImagoLarvaRightSideOam_Frame12,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [25] = {
        .pFrame = sImagoLarvaRightSideOam_Frame11,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [26] = {
        .pFrame = sImagoLarvaRightSideOam_Frame0,
        .timer = CONVERT_SECONDS(1.0f)
    },
    [27] = {
        .pFrame = sImagoLarvaRightSideOam_Frame11,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [28] = {
        .pFrame = sImagoLarvaRightSideOam_Frame12,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [29] = {
        .pFrame = sImagoLarvaRightSideOam_Frame11,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [30] = {
        .pFrame = sImagoLarvaRightSideOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [31] = {
        .pFrame = sImagoLarvaRightSideOam_Frame11,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [32] = {
        .pFrame = sImagoLarvaRightSideOam_Frame12,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [33] = {
        .pFrame = sImagoLarvaRightSideOam_Frame11,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [34] = FRAME_DATA_TERMINATOR
};
