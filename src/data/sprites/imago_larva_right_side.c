#include "data/sprites/imago_larva_right_side.h"
#include "macros.h"

const u32 sImagoLarvaRightSideGfx[592] = INCBIN_U32("data/sprites/ImagoLarvaRightSide.gfx.lz");
const u16 sImagoLarvaRightSidePal[32] = INCBIN_U16("data/sprites/ImagoLarvaRightSide.pal");

static const u16 sImagoLarvaRightSideOam_Frame0[OAM_DATA_SIZE(12)] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0xa00,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xf0, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xe0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa4a,
    0xf0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa16
};

static const u16 sImagoLarvaRightSideOam_Frame1[OAM_DATA_SIZE(12)] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1d1, OBJ_SPRITE_OAM | 0xa00,
    0xef, OBJ_SIZE_16x16 | 0x1d1, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xf0, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xe0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa4a,
    0xf0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa16
};

static const u16 sImagoLarvaRightSideOam_Frame2[OAM_DATA_SIZE(12)] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1d2, OBJ_SPRITE_OAM | 0xa00,
    0xee, OBJ_SIZE_16x16 | 0x1d2, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1e1, OBJ_SPRITE_OAM | 0xa02,
    0xef, OBJ_SIZE_16x16 | 0x1e1, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xf0, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xe0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa4a,
    0xf0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa16
};

static const u16 sImagoLarvaRightSideOam_Frame3[OAM_DATA_SIZE(12)] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1d2, OBJ_SPRITE_OAM | 0xa00,
    0xee, OBJ_SIZE_16x16 | 0x1d2, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1e2, OBJ_SPRITE_OAM | 0xa02,
    0xee, OBJ_SIZE_16x16 | 0x1e2, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1f1, OBJ_SPRITE_OAM | 0xa04,
    0xef, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xf0, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xe0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa4a,
    0xf0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa16
};

static const u16 sImagoLarvaRightSideOam_Frame4[OAM_DATA_SIZE(12)] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1d1, OBJ_SPRITE_OAM | 0xa00,
    0xef, OBJ_SIZE_16x16 | 0x1d1, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1e1, OBJ_SPRITE_OAM | 0xa02,
    0xee, OBJ_SIZE_16x16 | 0x1e1, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1f1, OBJ_SPRITE_OAM | 0xa04,
    0xee, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xef, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xf0, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xe0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa4a,
    0xf0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa16
};

static const u16 sImagoLarvaRightSideOam_Frame5[OAM_DATA_SIZE(12)] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0xa00,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xef, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xee, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xee, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xef, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xe0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa4a,
    0xf0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa16
};

static const u16 sImagoLarvaRightSideOam_Frame6[OAM_DATA_SIZE(12)] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0xa00,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xef, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xee, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0xf, OBJ_SPRITE_OAM | 0xa08,
    0xee, OBJ_SIZE_16x16 | 0xf, OBJ_SPRITE_OAM | 0xa14,
    0xdf, OBJ_SIZE_16x16 | 0x1e, OBJ_SPRITE_OAM | 0xa4a,
    0xef, OBJ_SIZE_16x16 | 0x1e, OBJ_SPRITE_OAM | 0xa16
};

static const u16 sImagoLarvaRightSideOam_Frame7[OAM_DATA_SIZE(12)] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0xa00,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xef, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0xf, OBJ_SPRITE_OAM | 0xa08,
    0xee, OBJ_SIZE_16x16 | 0xf, OBJ_SPRITE_OAM | 0xa14,
    0xde, OBJ_SIZE_16x16 | 0x1e, OBJ_SPRITE_OAM | 0xa4a,
    0xee, OBJ_SIZE_16x16 | 0x1e, OBJ_SPRITE_OAM | 0xa16
};

static const u16 sImagoLarvaRightSideOam_Frame8[OAM_DATA_SIZE(12)] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0xa00,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_SIZE_16x32 | 0xf, OBJ_SPRITE_OAM | 0xa08,
    0xef, OBJ_SIZE_16x16 | 0xf, OBJ_SPRITE_OAM | 0xa14,
    0xde, OBJ_SIZE_16x16 | 0x1e, OBJ_SPRITE_OAM | 0xa4a,
    0xee, OBJ_SIZE_16x16 | 0x1e, OBJ_SPRITE_OAM | 0xa16
};

static const u16 sImagoLarvaRightSideOam_Frame9[OAM_DATA_SIZE(12)] = {
    0xc,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0xa00,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xf0, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xdf, OBJ_SIZE_16x16 | 0x1f, OBJ_SPRITE_OAM | 0xa4a,
    0xef, OBJ_SIZE_16x16 | 0x1f, OBJ_SPRITE_OAM | 0xa16
};

static const u16 sImagoLarvaRightSideOam_Frame11[OAM_DATA_SIZE(14)] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa18,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0xa58,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0xa00,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xf0, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xe0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa4a,
    0xf0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa16
};

static const u16 sImagoLarvaRightSideOam_Frame12[OAM_DATA_SIZE(14)] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa1c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0xa5c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0xa00,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0xa0c,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e0, OBJ_SPRITE_OAM | 0xa02,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0xa0e,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0xa04,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0xa10,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0xa06,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0xa12,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0xa08,
    0xf0, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0xa14,
    0xe0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa4a,
    0xf0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0xa16
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
