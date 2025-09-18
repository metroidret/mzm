#include "data/sprites/mother_brain.h"
#include "macros.h"

#include "sprites_AI/mother_brain.h"

static const s16 sMotherBrainMultiSpriteData_Part0[MOTHER_BRAIN_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [MOTHER_BRAIN_PART_BEAM_SHOOTER] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = MOTHER_BRAIN_OAM_BEAM_SPAWNING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE - PIXEL_SIZE
    },
    [MOTHER_BRAIN_PART_BODY] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = MOTHER_BRAIN_OAM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [MOTHER_BRAIN_PART_EYE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = MOTHER_BRAIN_OAM_EYE_CLOSED,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE - PIXEL_SIZE
    },
    [MOTHER_BRAIN_PART_BOTTOM] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = MOTHER_BRAIN_OAM_BOTTOM,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = BLOCK_SIZE + HALF_BLOCK_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    }
};

static const s16 sMotherBrainMultiSpriteData_Part1[MOTHER_BRAIN_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [MOTHER_BRAIN_PART_BEAM_SHOOTER] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = MOTHER_BRAIN_OAM_BEAM_SPAWNING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = HALF_BLOCK_SIZE - PIXEL_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE - PIXEL_SIZE
    },
    [MOTHER_BRAIN_PART_BODY] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = MOTHER_BRAIN_OAM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = PIXEL_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [MOTHER_BRAIN_PART_EYE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = MOTHER_BRAIN_OAM_EYE_CLOSED,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = HALF_BLOCK_SIZE - PIXEL_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE - PIXEL_SIZE
    },
    [MOTHER_BRAIN_PART_BOTTOM] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = MOTHER_BRAIN_OAM_BOTTOM,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = BLOCK_SIZE + HALF_BLOCK_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    }
};

static const s16 sMotherBrainMultiSpriteData_Part2[MOTHER_BRAIN_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [MOTHER_BRAIN_PART_BEAM_SHOOTER] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = MOTHER_BRAIN_OAM_BEAM_SPAWNING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = HALF_BLOCK_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE - PIXEL_SIZE
    },
    [MOTHER_BRAIN_PART_BODY] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = MOTHER_BRAIN_OAM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = EIGHTH_BLOCK_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [MOTHER_BRAIN_PART_EYE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = MOTHER_BRAIN_OAM_EYE_CLOSED,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = HALF_BLOCK_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE - PIXEL_SIZE
    },
    [MOTHER_BRAIN_PART_BOTTOM] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = MOTHER_BRAIN_OAM_BOTTOM,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = BLOCK_SIZE + HALF_BLOCK_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    }
};

static const s16 sMotherBrainMultiSpriteData_Part3[MOTHER_BRAIN_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [MOTHER_BRAIN_PART_BEAM_SHOOTER] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = MOTHER_BRAIN_OAM_BEAM_SPAWNING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = HALF_BLOCK_SIZE + PIXEL_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE - PIXEL_SIZE
    },
    [MOTHER_BRAIN_PART_BODY] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = MOTHER_BRAIN_OAM_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = QUARTER_BLOCK_SIZE - PIXEL_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [MOTHER_BRAIN_PART_EYE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = MOTHER_BRAIN_OAM_EYE_CLOSED,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = HALF_BLOCK_SIZE + PIXEL_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE - PIXEL_SIZE
    },
    [MOTHER_BRAIN_PART_BOTTOM] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = MOTHER_BRAIN_OAM_BOTTOM,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = BLOCK_SIZE + HALF_BLOCK_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    }
};

const struct MultiSpriteData sMotherBrainMultiSpriteData[7] = {
    [0] = {
        .pData = sMotherBrainMultiSpriteData_Part0,
        .timer = CONVERT_SECONDS(.2f + 1.f / 30)
    },
    [1] = {
        .pData = sMotherBrainMultiSpriteData_Part1,
        .timer = CONVERT_SECONDS(.2f + 1.f / 30)
    },
    [2] = {
        .pData = sMotherBrainMultiSpriteData_Part2,
        .timer = CONVERT_SECONDS(.1f + 1.f / 30)
    },
    [3] = {
        .pData = sMotherBrainMultiSpriteData_Part3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = {
        .pData = sMotherBrainMultiSpriteData_Part2,
        .timer = CONVERT_SECONDS(.1f + 1.f / 30)
    },
    [5] = {
        .pData = sMotherBrainMultiSpriteData_Part1,
        .timer = CONVERT_SECONDS(.2f + 1.f / 30)
    },
    [6] = MULTI_SPRITE_DATA_TERMINATOR
};

const u8 sMotherBrainDynamicPaletteData[19][2] = {
    { 2, 6 },
    { 3, 6 },
    { 4, 6 },
    { 3, 6 },
    { 2, 6 },
    { 0, 2 },
    { 2, 6 },
    { 3, 6 },
    { 4, 6 },
    { 3, 6 },
    { 2, 6 },
    { 0, 2 },
    { 2, 3 },
    { 3, 3 },
    { 4, 3 },
    { 3, 3 },
    { 2, 3 },
    { 0, 1 },
    { SCHAR_MAX + 1, SCHAR_MAX + 1 }
};

const u32 sMotherBrainGfx[1871] = INCBIN_U32("data/sprites/MotherBrain.gfx.lz");
const u16 sMotherBrainPal[96] = INCBIN_U16("data/sprites/MotherBrain.pal");

static const u16 sMotherBrainOam_Idle_Frame0[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-41, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 602, 8, 1),
    OAM_ENTRY(-40, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 848, 8, 1),
    OAM_ENTRY(-36, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 850, 8, 1),
    OAM_ENTRY(15, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 1),
    OAM_ENTRY(-5, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 1),
    OAM_ENTRY(-35, -28, OAM_DIMS_16x16, OAM_X_FLIP, 844, 8, 1),
    OAM_ENTRY(-40, -17, OAM_DIMS_8x32, OAM_NO_FLIP, 512, 8, 1),
    OAM_ENTRY(-32, -22, OAM_DIMS_16x32, OAM_NO_FLIP, 513, 8, 1),
    OAM_ENTRY(-32, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 641, 8, 1),
    OAM_ENTRY(-24, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 679, 8, 1),
    OAM_ENTRY(-16, -30, OAM_DIMS_32x32, OAM_NO_FLIP, 515, 8, 1),
    OAM_ENTRY(-16, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 643, 8, 1),
    OAM_ENTRY(16, -30, OAM_DIMS_16x32, OAM_NO_FLIP, 519, 8, 1),
    OAM_ENTRY(16, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 647, 8, 1),
    OAM_ENTRY(32, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 648, 8, 1),
    OAM_ENTRY(22, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 846, 8, 1),
    OAM_ENTRY(10, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 1),
    OAM_ENTRY(-19, -38, OAM_DIMS_8x16, OAM_X_FLIP, 539, 8, 1),
    OAM_ENTRY(-43, -23, OAM_DIMS_16x16, OAM_X_FLIP, 844, 8, 1),
};

static const u16 sMotherBrainOam_Idle_Frame1[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-42, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 602, 8, 1),
    OAM_ENTRY(-40, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 848, 8, 1),
    OAM_ENTRY(-36, 7, OAM_DIMS_16x16, OAM_NO_FLIP, 850, 8, 1),
    OAM_ENTRY(13, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 846, 8, 1),
    OAM_ENTRY(-5, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 1),
    OAM_ENTRY(-33, -29, OAM_DIMS_16x16, OAM_X_FLIP, 846, 8, 1),
    OAM_ENTRY(-40, -17, OAM_DIMS_8x32, OAM_NO_FLIP, 640, 8, 1),
    OAM_ENTRY(-32, -22, OAM_DIMS_16x32, OAM_NO_FLIP, 521, 8, 1),
    OAM_ENTRY(-32, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 649, 8, 1),
    OAM_ENTRY(-24, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 687, 8, 1),
    OAM_ENTRY(-16, -30, OAM_DIMS_32x32, OAM_NO_FLIP, 523, 8, 1),
    OAM_ENTRY(-16, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 651, 8, 1),
    OAM_ENTRY(16, -30, OAM_DIMS_16x32, OAM_NO_FLIP, 527, 8, 1),
    OAM_ENTRY(16, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 655, 8, 1),
    OAM_ENTRY(32, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 656, 8, 1),
    OAM_ENTRY(24, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 844, 8, 1),
    OAM_ENTRY(11, -39, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 1),
    OAM_ENTRY(-18, -38, OAM_DIMS_8x16, OAM_X_FLIP, 538, 8, 1),
    OAM_ENTRY(-42, -24, OAM_DIMS_16x16, OAM_X_FLIP, 844, 8, 1),
};

static const u16 sMotherBrainOam_Idle_Frame2[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-42, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 602, 8, 1),
    OAM_ENTRY(-41, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 848, 8, 1),
    OAM_ENTRY(-37, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 850, 8, 1),
    OAM_ENTRY(16, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 844, 8, 1),
    OAM_ENTRY(-4, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 1),
    OAM_ENTRY(-32, -30, OAM_DIMS_16x16, OAM_X_FLIP, 846, 8, 1),
    OAM_ENTRY(-40, -17, OAM_DIMS_8x32, OAM_NO_FLIP, 768, 8, 1),
    OAM_ENTRY(-32, -22, OAM_DIMS_16x32, OAM_NO_FLIP, 529, 8, 1),
    OAM_ENTRY(-32, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 657, 8, 1),
    OAM_ENTRY(-24, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 695, 8, 1),
    OAM_ENTRY(-16, -30, OAM_DIMS_32x32, OAM_NO_FLIP, 531, 8, 1),
    OAM_ENTRY(-16, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 659, 8, 1),
    OAM_ENTRY(16, -30, OAM_DIMS_16x32, OAM_NO_FLIP, 535, 8, 1),
    OAM_ENTRY(16, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 663, 8, 1),
    OAM_ENTRY(32, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 601, 8, 1),
    OAM_ENTRY(24, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 844, 8, 1),
    OAM_ENTRY(9, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 846, 8, 1),
    OAM_ENTRY(-18, -38, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 1),
    OAM_ENTRY(-42, -26, OAM_DIMS_16x16, OAM_X_FLIP, 846, 8, 1),
};

static const u16 sMotherBrainPartOam_EyeClosed_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -14, OAM_DIMS_16x8, OAM_X_FLIP, 705, 8, 1),
    OAM_ENTRY(-30, -6, OAM_DIMS_32x16, OAM_X_FLIP, 707, 8, 1),
};

static const u16 sMotherBrainPartOam_EyeClosed_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 737, 8, 1),
    OAM_ENTRY(-30, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 710, 8, 1),
};

static const u16 sMotherBrainPartOam_EyeClosed_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -14, OAM_DIMS_16x8, OAM_X_FLIP, 769, 8, 1),
    OAM_ENTRY(-30, -6, OAM_DIMS_32x16, OAM_X_FLIP, 771, 8, 1),
};

static const u16 sMotherBrainPartOam_EyeOpening_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 801, 8, 1),
    OAM_ENTRY(-30, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 774, 8, 1),
};

static const u16 sMotherBrainPartOam_EyeOpening_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -14, OAM_DIMS_16x8, OAM_X_FLIP, 833, 8, 1),
    OAM_ENTRY(-30, -6, OAM_DIMS_32x16, OAM_X_FLIP, 835, 8, 1),
};

static const u16 sMotherBrainPartOam_EyeOpening_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-14, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 865, 8, 1),
    OAM_ENTRY(-30, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 838, 8, 1),
};

static const u16 sMotherBrainPartOam_Bottom_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 540, 8, 1),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 542, 8, 1),
    OAM_ENTRY(4, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 540, 8, 1),
    OAM_ENTRY(14, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 842, 8, 1),
    OAM_ENTRY(-32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 714, 8, 1),
};

static const u16 sMotherBrainPartOam_Bottom_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 540, 8, 1),
    OAM_ENTRY(-2, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 542, 8, 1),
    OAM_ENTRY(4, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 540, 8, 1),
    OAM_ENTRY(14, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 842, 8, 1),
    OAM_ENTRY(-32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 714, 8, 1),
};

static const u16 sMotherBrainPartOam_Bottom_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 540, 8, 1),
    OAM_ENTRY(-2, -15, OAM_DIMS_16x32, OAM_NO_FLIP, 542, 8, 1),
    OAM_ENTRY(4, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 540, 8, 1),
    OAM_ENTRY(14, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 842, 8, 1),
    OAM_ENTRY(-32, -15, OAM_DIMS_64x32, OAM_NO_FLIP, 714, 8, 1),
};

static const u16 sMotherBrainPartOam_Bottom_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 540, 8, 1),
    OAM_ENTRY(-2, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 542, 8, 1),
    OAM_ENTRY(4, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 540, 8, 1),
    OAM_ENTRY(14, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 842, 8, 1),
    OAM_ENTRY(-32, -14, OAM_DIMS_64x32, OAM_NO_FLIP, 714, 8, 1),
};

static const u16 sMotherBrainPartOam_BeamSpawning_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 670, 9, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 766, 9, 0),
};

static const u16 sMotherBrainPartOam_BeamSpawning_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(20, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 670, 9, 0),
    OAM_ENTRY(20, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 766, 9, 0),
    OAM_ENTRY(4, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 698, 9, 0),
    OAM_ENTRY(4, -2, OAM_DIMS_16x8, OAM_NO_FLIP, 730, 9, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 696, 9, 0),
};

static const u16 sMotherBrainPartOam_BeamSpawning_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 796, 9, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 824, 9, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 824, 9, 0),
};

static const u16 sMotherBrainPartOam_BeamSpawning_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(32, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 668, 9, 0),
    OAM_ENTRY(20, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 666, 9, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 696, 9, 0),
};

static const u16 sMotherBrainBeamOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-48, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 664, 9, 0),
};

static const u16 sMotherBrainBeamOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-52, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 792, 9, 0),
};

static const u16 sMotherBrainGlassBreakingOam_Breaking_Frame0[OAM_DATA_SIZE(23)] = {
    23,
    OAM_ENTRY(-41, -53, OAM_DIMS_16x32, OAM_NO_FLIP, 722, 9, 0),
    OAM_ENTRY(-20, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 724, 9, 0),
    OAM_ENTRY(-48, -7, OAM_DIMS_16x32, OAM_Y_FLIP, 722, 9, 0),
    OAM_ENTRY(-28, -2, OAM_DIMS_8x16, OAM_Y_FLIP, 724, 9, 0),
    OAM_ENTRY(-45, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 786, 9, 0),
    OAM_ENTRY(-48, -30, OAM_DIMS_16x16, OAM_XY_FLIP, 786, 9, 0),
    OAM_ENTRY(-19, 1, OAM_DIMS_8x32, OAM_NO_FLIP, 788, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 789, 9, 0),
    OAM_ENTRY(21, -20, OAM_DIMS_8x32, OAM_X_FLIP, 788, 9, 0),
    OAM_ENTRY(16, -48, OAM_DIMS_32x32, OAM_XY_FLIP, 789, 9, 0),
    OAM_ENTRY(40, -24, OAM_DIMS_16x32, OAM_X_FLIP, 722, 9, 0),
    OAM_ENTRY(48, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 724, 9, 0),
    OAM_ENTRY(40, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 634, 9, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 635, 9, 0),
    OAM_ENTRY(-3, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 786, 9, 0),
    OAM_ENTRY(-6, -60, OAM_DIMS_16x16, OAM_XY_FLIP, 786, 9, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_32x32, OAM_Y_FLIP, 789, 9, 0),
    OAM_ENTRY(-21, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 725, 9, 0),
    OAM_ENTRY(12, -50, OAM_DIMS_16x16, OAM_Y_FLIP, 725, 9, 0),
    OAM_ENTRY(0, -29, OAM_DIMS_16x16, OAM_XY_FLIP, 725, 9, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_X_FLIP, 786, 9, 0),
    OAM_ENTRY(19, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 786, 9, 0),
    OAM_ENTRY(-38, -64, OAM_DIMS_32x32, OAM_X_FLIP, 789, 9, 0),
};

static const u16 sMotherBrainGlassBreakingOam_Breaking_Frame2[OAM_DATA_SIZE(23)] = {
    23,
    OAM_ENTRY(-44, -55, OAM_DIMS_16x32, OAM_NO_FLIP, 722, 9, 0),
    OAM_ENTRY(-21, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 724, 9, 0),
    OAM_ENTRY(-51, -6, OAM_DIMS_16x32, OAM_Y_FLIP, 722, 9, 0),
    OAM_ENTRY(-30, -1, OAM_DIMS_8x16, OAM_Y_FLIP, 724, 9, 0),
    OAM_ENTRY(-47, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 786, 9, 0),
    OAM_ENTRY(-50, -31, OAM_DIMS_16x16, OAM_XY_FLIP, 786, 9, 0),
    OAM_ENTRY(-21, 2, OAM_DIMS_8x32, OAM_NO_FLIP, 788, 9, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_32x32, OAM_NO_FLIP, 789, 9, 0),
    OAM_ENTRY(22, -21, OAM_DIMS_8x32, OAM_X_FLIP, 788, 9, 0),
    OAM_ENTRY(18, -50, OAM_DIMS_32x32, OAM_XY_FLIP, 789, 9, 0),
    OAM_ENTRY(44, -25, OAM_DIMS_16x32, OAM_X_FLIP, 722, 9, 0),
    OAM_ENTRY(51, -41, OAM_DIMS_8x16, OAM_NO_FLIP, 724, 9, 0),
    OAM_ENTRY(44, 18, OAM_DIMS_8x8, OAM_NO_FLIP, 634, 9, 0),
    OAM_ENTRY(34, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 635, 9, 0),
    OAM_ENTRY(-5, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 786, 9, 0),
    OAM_ENTRY(-8, -63, OAM_DIMS_16x16, OAM_XY_FLIP, 786, 9, 0),
    OAM_ENTRY(18, 1, OAM_DIMS_32x32, OAM_Y_FLIP, 789, 9, 0),
    OAM_ENTRY(-23, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 725, 9, 0),
    OAM_ENTRY(13, -52, OAM_DIMS_16x16, OAM_Y_FLIP, 725, 9, 0),
    OAM_ENTRY(0, -30, OAM_DIMS_16x16, OAM_XY_FLIP, 725, 9, 0),
    OAM_ENTRY(18, -18, OAM_DIMS_16x16, OAM_X_FLIP, 786, 9, 0),
    OAM_ENTRY(21, -34, OAM_DIMS_16x16, OAM_Y_FLIP, 786, 9, 0),
    OAM_ENTRY(-40, -66, OAM_DIMS_32x32, OAM_X_FLIP, 789, 9, 0),
};

static const u16 sMotherBrainGlassBreakingOam_Breaking_Frame4[OAM_DATA_SIZE(23)] = {
    23,
    OAM_ENTRY(-52, -51, OAM_DIMS_16x32, OAM_NO_FLIP, 722, 9, 0),
    OAM_ENTRY(-27, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 724, 9, 0),
    OAM_ENTRY(-57, 4, OAM_DIMS_16x32, OAM_Y_FLIP, 722, 9, 0),
    OAM_ENTRY(-34, 2, OAM_DIMS_8x16, OAM_Y_FLIP, 724, 9, 0),
    OAM_ENTRY(-51, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 786, 9, 0),
    OAM_ENTRY(-54, -30, OAM_DIMS_16x16, OAM_XY_FLIP, 786, 9, 0),
    OAM_ENTRY(-24, 5, OAM_DIMS_8x32, OAM_NO_FLIP, 788, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 789, 9, 0),
    OAM_ENTRY(27, -19, OAM_DIMS_8x32, OAM_X_FLIP, 788, 9, 0),
    OAM_ENTRY(21, -52, OAM_DIMS_32x32, OAM_XY_FLIP, 789, 9, 0),
    OAM_ENTRY(48, -19, OAM_DIMS_16x32, OAM_X_FLIP, 722, 9, 0),
    OAM_ENTRY(54, -37, OAM_DIMS_8x16, OAM_NO_FLIP, 724, 9, 0),
    OAM_ENTRY(45, 26, OAM_DIMS_8x8, OAM_NO_FLIP, 634, 9, 0),
    OAM_ENTRY(36, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 635, 9, 0),
    OAM_ENTRY(-9, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 786, 9, 0),
    OAM_ENTRY(-12, -63, OAM_DIMS_16x16, OAM_XY_FLIP, 786, 9, 0),
    OAM_ENTRY(19, 5, OAM_DIMS_32x32, OAM_Y_FLIP, 789, 9, 0),
    OAM_ENTRY(-28, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 725, 9, 0),
    OAM_ENTRY(16, -54, OAM_DIMS_16x16, OAM_Y_FLIP, 725, 9, 0),
    OAM_ENTRY(0, -27, OAM_DIMS_16x16, OAM_XY_FLIP, 725, 9, 0),
    OAM_ENTRY(19, -16, OAM_DIMS_16x16, OAM_X_FLIP, 786, 9, 0),
    OAM_ENTRY(22, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 786, 9, 0),
    OAM_ENTRY(-47, -64, OAM_DIMS_32x32, OAM_X_FLIP, 789, 9, 0),
};

static const u16 sMotherBrainGlassBreakingOam_Breaking_Frame6[OAM_DATA_SIZE(23)] = {
    23,
    OAM_ENTRY(-56, -40, OAM_DIMS_16x32, OAM_XY_FLIP, 722, 9, 0),
    OAM_ENTRY(-32, -24, OAM_DIMS_8x16, OAM_XY_FLIP, 724, 9, 0),
    OAM_ENTRY(-62, 20, OAM_DIMS_16x32, OAM_Y_FLIP, 722, 9, 0),
    OAM_ENTRY(-39, 18, OAM_DIMS_8x16, OAM_Y_FLIP, 724, 9, 0),
    OAM_ENTRY(-53, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 786, 9, 0),
    OAM_ENTRY(-56, 0, OAM_DIMS_16x16, OAM_X_FLIP, 786, 9, 0),
    OAM_ENTRY(-26, 15, OAM_DIMS_8x32, OAM_NO_FLIP, 788, 9, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_32x32, OAM_Y_FLIP, 789, 9, 0),
    OAM_ENTRY(32, 3, OAM_DIMS_8x32, OAM_XY_FLIP, 788, 9, 0),
    OAM_ENTRY(27, -38, OAM_DIMS_32x32, OAM_X_FLIP, 789, 9, 0),
    OAM_ENTRY(56, 8, OAM_DIMS_16x32, OAM_Y_FLIP, 722, 9, 0),
    OAM_ENTRY(64, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 724, 9, 0),
    OAM_ENTRY(49, 51, OAM_DIMS_8x8, OAM_NO_FLIP, 634, 9, 0),
    OAM_ENTRY(40, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 635, 9, 0),
    OAM_ENTRY(-19, -32, OAM_DIMS_16x16, OAM_X_FLIP, 786, 9, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_16x16, OAM_Y_FLIP, 786, 9, 0),
    OAM_ENTRY(23, 30, OAM_DIMS_32x32, OAM_NO_FLIP, 789, 9, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 725, 9, 0),
    OAM_ENTRY(27, -48, OAM_DIMS_16x16, OAM_X_FLIP, 725, 9, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 725, 9, 0),
    OAM_ENTRY(21, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 786, 9, 0),
    OAM_ENTRY(18, -22, OAM_DIMS_16x16, OAM_XY_FLIP, 786, 9, 0),
    OAM_ENTRY(-51, -56, OAM_DIMS_32x32, OAM_XY_FLIP, 789, 9, 0),
};

static const u16 sMotherBrainGlassBreakingOam_Breaking_Frame8[OAM_DATA_SIZE(23)] = {
    23,
    OAM_ENTRY(-59, -19, OAM_DIMS_16x32, OAM_NO_FLIP, 722, 9, 0),
    OAM_ENTRY(-38, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 724, 9, 0),
    OAM_ENTRY(-64, 39, OAM_DIMS_16x32, OAM_Y_FLIP, 722, 9, 0),
    OAM_ENTRY(-44, 42, OAM_DIMS_8x16, OAM_Y_FLIP, 724, 9, 0),
    OAM_ENTRY(-60, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 786, 9, 0),
    OAM_ENTRY(-57, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 786, 9, 0),
    OAM_ENTRY(-29, 44, OAM_DIMS_8x32, OAM_NO_FLIP, 788, 9, 0),
    OAM_ENTRY(-8, 32, OAM_DIMS_32x32, OAM_NO_FLIP, 789, 9, 0),
    OAM_ENTRY(36, 32, OAM_DIMS_8x32, OAM_X_FLIP, 788, 9, 0),
    OAM_ENTRY(32, -16, OAM_DIMS_32x32, OAM_XY_FLIP, 789, 9, 0),
    OAM_ENTRY(59, 29, OAM_DIMS_16x32, OAM_X_FLIP, 722, 9, 0),
    OAM_ENTRY(69, 11, OAM_DIMS_8x16, OAM_NO_FLIP, 724, 9, 0),
    OAM_ENTRY(52, 64, OAM_DIMS_8x8, OAM_NO_FLIP, 634, 9, 0),
    OAM_ENTRY(43, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 635, 9, 0),
    OAM_ENTRY(-20, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 786, 9, 0),
    OAM_ENTRY(-23, -24, OAM_DIMS_16x16, OAM_XY_FLIP, 786, 9, 0),
    OAM_ENTRY(24, 49, OAM_DIMS_32x32, OAM_Y_FLIP, 789, 9, 0),
    OAM_ENTRY(-34, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 725, 9, 0),
    OAM_ENTRY(35, -31, OAM_DIMS_16x16, OAM_Y_FLIP, 725, 9, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_16x16, OAM_XY_FLIP, 725, 9, 0),
    OAM_ENTRY(20, 16, OAM_DIMS_16x16, OAM_X_FLIP, 786, 9, 0),
    OAM_ENTRY(23, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 786, 9, 0),
    OAM_ENTRY(-56, -40, OAM_DIMS_32x32, OAM_X_FLIP, 789, 9, 0),
};

static const u16 sMotherBrainGlassBreakingOam_Breaking_Frame10[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-62, 0, OAM_DIMS_16x32, OAM_XY_FLIP, 722, 9, 0),
    OAM_ENTRY(-40, 22, OAM_DIMS_8x16, OAM_XY_FLIP, 724, 9, 0),
    OAM_ENTRY(-59, 27, OAM_DIMS_16x16, OAM_Y_FLIP, 786, 9, 0),
    OAM_ENTRY(-62, 43, OAM_DIMS_16x16, OAM_X_FLIP, 786, 9, 0),
    OAM_ENTRY(36, 9, OAM_DIMS_32x32, OAM_X_FLIP, 789, 9, 0),
    OAM_ENTRY(72, 24, OAM_DIMS_8x16, OAM_Y_FLIP, 724, 9, 0),
    OAM_ENTRY(46, 49, OAM_DIMS_8x8, OAM_NO_FLIP, 635, 9, 0),
    OAM_ENTRY(-23, 17, OAM_DIMS_16x16, OAM_X_FLIP, 786, 9, 0),
    OAM_ENTRY(-20, 1, OAM_DIMS_16x16, OAM_Y_FLIP, 786, 9, 0),
    OAM_ENTRY(-34, 37, OAM_DIMS_16x16, OAM_Y_FLIP, 725, 9, 0),
    OAM_ENTRY(39, -2, OAM_DIMS_16x16, OAM_X_FLIP, 725, 9, 0),
    OAM_ENTRY(0, 25, OAM_DIMS_16x16, OAM_X_FLIP, 725, 9, 0),
    OAM_ENTRY(24, 33, OAM_DIMS_16x16, OAM_NO_FLIP, 786, 9, 0),
    OAM_ENTRY(21, 17, OAM_DIMS_16x16, OAM_XY_FLIP, 786, 9, 0),
    OAM_ENTRY(-56, -20, OAM_DIMS_32x32, OAM_XY_FLIP, 789, 9, 0),
};

static const u16 sMotherBrainGlassBreakingOam_Breaking_Frame12[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-64, 31, OAM_DIMS_16x32, OAM_NO_FLIP, 722, 9, 0),
    OAM_ENTRY(-42, 48, OAM_DIMS_8x16, OAM_NO_FLIP, 724, 9, 0),
    OAM_ENTRY(37, 40, OAM_DIMS_32x32, OAM_XY_FLIP, 789, 9, 0),
    OAM_ENTRY(-20, 40, OAM_DIMS_16x16, OAM_NO_FLIP, 786, 9, 0),
    OAM_ENTRY(-23, 24, OAM_DIMS_16x16, OAM_XY_FLIP, 786, 9, 0),
    OAM_ENTRY(-35, 51, OAM_DIMS_16x16, OAM_NO_FLIP, 725, 9, 0),
    OAM_ENTRY(44, 22, OAM_DIMS_16x16, OAM_Y_FLIP, 725, 9, 0),
    OAM_ENTRY(0, 47, OAM_DIMS_16x16, OAM_XY_FLIP, 725, 9, 0),
    OAM_ENTRY(24, 56, OAM_DIMS_16x16, OAM_X_FLIP, 786, 9, 0),
    OAM_ENTRY(27, 40, OAM_DIMS_16x16, OAM_Y_FLIP, 786, 9, 0),
    OAM_ENTRY(-56, 5, OAM_DIMS_32x32, OAM_X_FLIP, 789, 9, 0),
    OAM_ENTRY(72, 48, OAM_DIMS_8x16, OAM_NO_FLIP, 724, 9, 0),
};

static const u16 sMotherBrainGlassBreakingOam_Breaking_Frame14[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-64, 49, OAM_DIMS_16x32, OAM_XY_FLIP, 722, 9, 0),
    OAM_ENTRY(-23, 58, OAM_DIMS_16x16, OAM_X_FLIP, 786, 9, 0),
    OAM_ENTRY(-20, 42, OAM_DIMS_16x16, OAM_Y_FLIP, 786, 9, 0),
    OAM_ENTRY(44, 40, OAM_DIMS_16x16, OAM_XY_FLIP, 725, 9, 0),
    OAM_ENTRY(0, 65, OAM_DIMS_16x16, OAM_NO_FLIP, 725, 9, 0),
    OAM_ENTRY(-57, 32, OAM_DIMS_32x32, OAM_XY_FLIP, 789, 9, 0),
};

static const u16 sMotherBrainGlassBreakingOam_Breaking_Frame16[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-64, 64, OAM_DIMS_16x32, OAM_NO_FLIP, 722, 9, 0),
    OAM_ENTRY(-24, 64, OAM_DIMS_16x16, OAM_XY_FLIP, 786, 9, 0),
    OAM_ENTRY(-21, 80, OAM_DIMS_16x16, OAM_NO_FLIP, 786, 9, 0),
    OAM_ENTRY(45, 64, OAM_DIMS_16x16, OAM_NO_FLIP, 725, 9, 0),
    OAM_ENTRY(0, 80, OAM_DIMS_16x16, OAM_XY_FLIP, 725, 9, 0),
    OAM_ENTRY(-48, 56, OAM_DIMS_32x32, OAM_Y_FLIP, 789, 9, 0),
};

static const u16 sMotherBrainGlassBreakingOam_Breaking_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 664, 9, 0),
};

const struct FrameData sMotherBrainOam_Idle[12] = {
    [0] = {
        .pFrame = sMotherBrainOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(5.f / 6)
    },
    [1] = {
        .pFrame = sMotherBrainOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sMotherBrainOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sMotherBrainOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sMotherBrainOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sMotherBrainOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [6] = {
        .pFrame = sMotherBrainOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sMotherBrainOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.5f)
    },
    [8] = {
        .pFrame = sMotherBrainOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sMotherBrainOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = {
        .pFrame = sMotherBrainOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
};

const struct FrameData sMotherBrainOam_ChargingBeam[5] = {
    [0] = {
        .pFrame = sMotherBrainOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sMotherBrainOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sMotherBrainOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sMotherBrainOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotherBrainPartOam_EyeClosed[12] = {
    [0] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame0,
        .timer = CONVERT_SECONDS(5.f / 6)
    },
    [1] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame2,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [6] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame0,
        .timer = CONVERT_SECONDS(0.5f)
    },
    [8] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotherBrainPartOam_2fa934[5] = {
    [0] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotherBrainPartOam_EyeOpening[5] = {
    [0] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sMotherBrainPartOam_EyeOpening_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sMotherBrainPartOam_EyeOpening_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sMotherBrainPartOam_EyeOpening_Frame3,
        .timer = UCHAR_MAX
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotherBrainPartOam_2fa984[8] = {
    [0] = {
        .pFrame = sMotherBrainPartOam_EyeOpening_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMotherBrainPartOam_EyeOpening_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sMotherBrainPartOam_EyeOpening_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sMotherBrainPartOam_EyeOpening_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotherBrainPartOam_EyeDying[5] = {
    [0] = {
        .pFrame = sMotherBrainPartOam_EyeOpening_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sMotherBrainPartOam_EyeOpening_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sMotherBrainPartOam_EyeOpening_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sMotherBrainPartOam_EyeOpening_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotherBrainPartOam_Bottom[7] = {
    [0] = {
        .pFrame = sMotherBrainPartOam_Bottom_Frame0,
        .timer = CONVERT_SECONDS(7.f / 30)
    },
    [1] = {
        .pFrame = sMotherBrainPartOam_Bottom_Frame1,
        .timer = CONVERT_SECONDS(7.f / 30)
    },
    [2] = {
        .pFrame = sMotherBrainPartOam_Bottom_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sMotherBrainPartOam_Bottom_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sMotherBrainPartOam_Bottom_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sMotherBrainPartOam_Bottom_Frame1,
        .timer = CONVERT_SECONDS(7.f / 30)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotherBrainPartOam_BeamSpawning[5] = {
    [0] = {
        .pFrame = sMotherBrainPartOam_BeamSpawning_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sMotherBrainPartOam_BeamSpawning_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sMotherBrainPartOam_BeamSpawning_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sMotherBrainPartOam_BeamSpawning_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotherBrainBeamOam_Moving[3] = {
    [0] = {
        .pFrame = sMotherBrainBeamOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sMotherBrainBeamOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotherBrainGlassBreakingOam_Breaking[18] = {
    [0] = {
        .pFrame = sMotherBrainGlassBreakingOam_Breaking_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sMotherBrainGlassBreakingOam_Breaking_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sMotherBrainGlassBreakingOam_Breaking_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sMotherBrainGlassBreakingOam_Breaking_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sMotherBrainGlassBreakingOam_Breaking_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sMotherBrainGlassBreakingOam_Breaking_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sMotherBrainGlassBreakingOam_Breaking_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sMotherBrainGlassBreakingOam_Breaking_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sMotherBrainGlassBreakingOam_Breaking_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [9] = {
        .pFrame = sMotherBrainGlassBreakingOam_Breaking_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = {
        .pFrame = sMotherBrainGlassBreakingOam_Breaking_Frame10,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [11] = {
        .pFrame = sMotherBrainGlassBreakingOam_Breaking_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = {
        .pFrame = sMotherBrainGlassBreakingOam_Breaking_Frame12,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [13] = {
        .pFrame = sMotherBrainGlassBreakingOam_Breaking_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [14] = {
        .pFrame = sMotherBrainGlassBreakingOam_Breaking_Frame14,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [15] = {
        .pFrame = sMotherBrainGlassBreakingOam_Breaking_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [16] = {
        .pFrame = sMotherBrainGlassBreakingOam_Breaking_Frame16,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [17] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotherBrainPartOam_EyeClosing[4] = {
    [0] = {
        .pFrame = sMotherBrainPartOam_EyeOpening_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sMotherBrainPartOam_EyeOpening_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sMotherBrainPartOam_EyeClosed_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = FRAME_DATA_TERMINATOR
};
