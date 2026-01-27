#include "data/sprites/zipline_generator.h"
#include "macros.h"

const u32 sZiplineGeneratorGfx[1124] = INCBIN_U32("data/sprites/zipline_generator.gfx.lz");
const u16 sZiplineGeneratorPal[64] = INCBIN_U16("data/sprites/zipline_generator.pal");

static const u16 sZiplineGeneratorPartOam_ConductorDeactivated_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-24, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x284, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-32, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23f, 8, 0)
};

static const u16 sZiplineGeneratorPartOam_ConductorActivating_Frame1[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-4, -82, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2ae, 8, 0),
    OAM_ENTRY(-23, -96, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-23, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 0x28e, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28f, 8, 0),
    OAM_ENTRY(15, -88, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2ce, 8, 0),
    OAM_ENTRY(15, -72, OAM_DIMS_8x16, OAM_X_FLIP, 0x26e, 8, 0),
    OAM_ENTRY(-24, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x284, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-32, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23f, 8, 0)
};

static const u16 sZiplineGeneratorPartOam_ConductorActivating_Frame2[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-4, -82, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b1, 8, 0),
    OAM_ENTRY(-23, -96, OAM_DIMS_8x32, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-23, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 0x291, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x292, 8, 0),
    OAM_ENTRY(15, -88, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d1, 8, 0),
    OAM_ENTRY(15, -72, OAM_DIMS_8x16, OAM_X_FLIP, 0x271, 8, 0),
    OAM_ENTRY(-24, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x284, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-32, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23f, 8, 0)
};

static const u16 sZiplineGeneratorPartOam_ConductorActivating_Frame3[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-4, -82, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2b4, 8, 0),
    OAM_ENTRY(-23, -96, OAM_DIMS_8x32, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-23, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 0x294, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x295, 8, 0),
    OAM_ENTRY(15, -88, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2d4, 8, 0),
    OAM_ENTRY(15, -72, OAM_DIMS_8x16, OAM_X_FLIP, 0x274, 8, 0),
    OAM_ENTRY(-24, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x280, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x282, 8, 0),
    OAM_ENTRY(8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x284, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-32, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23f, 8, 0)
};

static const u16 sZiplineGeneratorOam_Deactivated_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c4, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22d, 8, 0)
};

static const u16 sZiplineGeneratorOam_Activating_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x286, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2cf, 8, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c6, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2c8, 8, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c4, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22d, 8, 0)
};

static const u16 sZiplineGeneratorOam_Activating_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x288, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d2, 8, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2ca, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2cc, 8, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c4, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22d, 8, 0)
};

static const u16 sZiplineGeneratorOam_Activating_Frame3[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28a, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d5, 8, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x27c, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2bc, 8, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c0, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c4, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22d, 8, 0)
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x217, 8, 0)
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x219, 8, 0)
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0)
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21d, 8, 0)
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0)
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x219, 8, 0)
};

static const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x24c, 8, 0)
};

static const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x25f, 9, 0)
};

static const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2de, 9, 0)
};

static const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 1, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25b, 9, 0)
};

static const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -16, OAM_DIMS_8x32, OAM_XY_FLIP, 0x25f, 9, 0)
};

static const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_XY_FLIP, 0x2de, 9, 0)
};

static const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -9, OAM_DIMS_32x8, OAM_XY_FLIP, 0x25b, 9, 0)
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x277, 9, 0)
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x278, 9, 0)
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x257, 9, 0)
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_X_FLIP, 0x278, 9, 0)
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x2dc, 9, 0)
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2fa, 9, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x24c, 8, 0)
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f9, 9, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x28c, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x28c, 8, 0)
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2f8, 9, 0)
};

const struct FrameData sZiplineGeneratorPartOam_ConductorDeactivated[2] = {
    [0] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorDeactivated_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineGeneratorOam_Deactivated[2] = {
    [0] = {
        .pFrame = sZiplineGeneratorOam_Deactivated_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineGeneratorPartOam_ConductorActivating[7] = {
    [0] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorDeactivated_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame2,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [3] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [4] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame2,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [5] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineGeneratorOam_Activating[7] = {
    [0] = {
        .pFrame = sZiplineGeneratorOam_Deactivated_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame2,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [3] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [4] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame2,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [5] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineGeneratorPartOam_ConductorActivated[7] = {
    [0] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorDeactivated_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sZiplineGeneratorPartOam_ConductorActivating_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineGeneratorOam_Activated[7] = {
    [0] = {
        .pFrame = sZiplineGeneratorOam_Deactivated_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sZiplineGeneratorOam_Activating_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineGeneratorPartOam_MorphSymbolActivating[7] = {
    [0] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivating_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivating_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivating_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivating_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivating_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineGeneratorPartOam_MorphSymbolActivated[9] = {
    [0] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivated_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivated_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivated_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivated_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivated_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivated_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivated_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sZiplineGeneratorPartOam_MorphSymbolActivated_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZiplineGeneratorPartOam_ElectricityActivating[12] = {
    [0] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [7] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [9] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sZiplineGeneratorPartOam_ElectricityActivating_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [11] = FRAME_DATA_TERMINATOR
};
