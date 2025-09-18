#include "data/sprites/zipline_generator.h"
#include "macros.h"

const u32 sZiplineGeneratorGfx[1124] = INCBIN_U32("data/sprites/ZiplineGenerator.gfx.lz");
const u16 sZiplineGeneratorPal[64] = INCBIN_U16("data/sprites/ZiplineGenerator.pal");

static const u16 sZiplineGeneratorPartOam_ConductorDeactivated_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-24, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-24, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 644, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-32, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 575, 8, 0),
};

static const u16 sZiplineGeneratorPartOam_ConductorActivating_Frame1[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-4, -82, OAM_DIMS_8x8, OAM_NO_FLIP, 686, 8, 0),
    OAM_ENTRY(-23, -96, OAM_DIMS_8x32, OAM_NO_FLIP, 526, 8, 0),
    OAM_ENTRY(-23, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 654, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 527, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 655, 8, 0),
    OAM_ENTRY(15, -88, OAM_DIMS_8x16, OAM_NO_FLIP, 718, 8, 0),
    OAM_ENTRY(15, -72, OAM_DIMS_8x16, OAM_X_FLIP, 622, 8, 0),
    OAM_ENTRY(-24, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-24, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 644, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-32, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 575, 8, 0),
};

static const u16 sZiplineGeneratorPartOam_ConductorActivating_Frame2[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-4, -82, OAM_DIMS_8x8, OAM_NO_FLIP, 689, 8, 0),
    OAM_ENTRY(-23, -96, OAM_DIMS_8x32, OAM_NO_FLIP, 529, 8, 0),
    OAM_ENTRY(-23, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 657, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 658, 8, 0),
    OAM_ENTRY(15, -88, OAM_DIMS_8x16, OAM_NO_FLIP, 721, 8, 0),
    OAM_ENTRY(15, -72, OAM_DIMS_8x16, OAM_X_FLIP, 625, 8, 0),
    OAM_ENTRY(-24, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-24, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 644, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-32, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 575, 8, 0),
};

static const u16 sZiplineGeneratorPartOam_ConductorActivating_Frame3[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-4, -82, OAM_DIMS_8x8, OAM_NO_FLIP, 692, 8, 0),
    OAM_ENTRY(-23, -96, OAM_DIMS_8x32, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-23, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 660, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 533, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 661, 8, 0),
    OAM_ENTRY(15, -88, OAM_DIMS_8x16, OAM_NO_FLIP, 724, 8, 0),
    OAM_ENTRY(15, -72, OAM_DIMS_8x16, OAM_X_FLIP, 628, 8, 0),
    OAM_ENTRY(-24, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-24, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(8, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 644, 8, 0),
    OAM_ENTRY(-24, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-32, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 575, 8, 0),
};

static const u16 sZiplineGeneratorOam_Deactivated_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 704, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 708, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 556, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 557, 8, 0),
};

static const u16 sZiplineGeneratorOam_Activating_Frame1[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 646, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 719, 8, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 710, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 712, 8, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 704, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 708, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 556, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 557, 8, 0),
};

static const u16 sZiplineGeneratorOam_Activating_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 648, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 722, 8, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 714, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 716, 8, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 704, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 708, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 556, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 557, 8, 0),
};

static const u16 sZiplineGeneratorOam_Activating_Frame3[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 650, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 725, 8, 0),
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 700, 8, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 704, 8, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 708, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 556, 8, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 557, 8, 0),
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 535, 8, 0),
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 537, 8, 0),
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 539, 8, 0),
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 541, 8, 0),
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 588, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 588, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 588, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 588, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 539, 8, 0),
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivating_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 652, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 652, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 652, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 652, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 537, 8, 0),
};

static const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 588, 8, 0),
};

static const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 607, 9, 0),
};

static const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 734, 9, 0),
};

static const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 1, OAM_DIMS_32x8, OAM_NO_FLIP, 603, 9, 0),
};

static const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -16, OAM_DIMS_8x32, OAM_XY_FLIP, 607, 9, 0),
};

static const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_XY_FLIP, 734, 9, 0),
};

static const u16 sZiplineGeneratorPartOam_ElectricityActivating_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -9, OAM_DIMS_32x8, OAM_XY_FLIP, 603, 9, 0),
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 631, 9, 0),
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 632, 9, 0),
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 599, 9, 0),
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_X_FLIP, 632, 9, 0),
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 732, 9, 0),
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 762, 9, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 588, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 588, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 588, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 588, 8, 0),
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 761, 9, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 652, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 652, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 652, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 652, 8, 0),
};

static const u16 sZiplineGeneratorPartOam_MorphSymbolActivated_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 760, 9, 0),
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
