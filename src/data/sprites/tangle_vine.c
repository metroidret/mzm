#include "data/sprites/tangle_vine.h"
#include "macros.h"

#include "sprites_ai/tangle_vine.h"

static const s16 sTangleVineGerutaMultiSpriteData_Idle_Frame0[TANGLE_VINE_GERUTA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [TANGLE_VINE_GERUTA_PART_GRIP] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA_GRIP,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = -EIGHTH_BLOCK_SIZE
    },
    [TANGLE_VINE_GERUTA_PART_GERUTA] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3 + EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = HALF_BLOCK_SIZE
    },
    [TANGLE_VINE_GERUTA_PART_ROOT] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA_ROOT,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    }
};

static const s16 sTangleVineGerutaMultiSpriteData_Idle_Frame1[TANGLE_VINE_GERUTA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [TANGLE_VINE_GERUTA_PART_GRIP] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA_GRIP,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [TANGLE_VINE_GERUTA_PART_GERUTA] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3 + PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = HALF_BLOCK_SIZE - PIXEL_SIZE
    },
    [TANGLE_VINE_GERUTA_PART_ROOT] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA_ROOT,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    }
};

static const s16 sTangleVineGerutaMultiSpriteData_Idle_Frame2[TANGLE_VINE_GERUTA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [TANGLE_VINE_GERUTA_PART_GRIP] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA_GRIP,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [TANGLE_VINE_GERUTA_PART_GERUTA] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = HALF_BLOCK_SIZE - PIXEL_SIZE
    },
    [TANGLE_VINE_GERUTA_PART_ROOT] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA_ROOT,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    }
};

static const s16 sTangleVineGerutaMultiSpriteData_Idle_Frame3[TANGLE_VINE_GERUTA_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [TANGLE_VINE_GERUTA_PART_GRIP] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA_GRIP,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = EIGHTH_BLOCK_SIZE
    },
    [TANGLE_VINE_GERUTA_PART_GERUTA] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(BLOCK_SIZE * 3 - PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [TANGLE_VINE_GERUTA_PART_ROOT] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = TANGLE_VINE_OAM_GERUTA_ROOT,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    }
};

const struct MultiSpriteData sTangleVineGerutaMultiSpriteData_Idle[5] = {
    [0] = {
        .pData = sTangleVineGerutaMultiSpriteData_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pData = sTangleVineGerutaMultiSpriteData_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pData = sTangleVineGerutaMultiSpriteData_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pData = sTangleVineGerutaMultiSpriteData_Idle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = MULTI_SPRITE_DATA_TERMINATOR
};

const u32 sTangleVineGfx[1298] = INCBIN_U32("data/sprites/tangle_vine.gfx.lz");
const u16 sTangleVinePal[80] = INCBIN_U16("data/sprites/tangle_vine.pal");

const u16 sTangleVineTallOam_OnGround_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x248, 9, 0),
    OAM_ENTRY(-6, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2c8, 9, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x258, 9, 0),
    OAM_ENTRY(-11, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x310, 9, 0),
};

const u16 sTangleVineTallOam_OnGround_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-5, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(-5, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2ca, 9, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x259, 9, 0),
    OAM_ENTRY(-12, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0x310, 9, 0),
};

const u16 sTangleVineTallOam_OnGround_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2cc, 9, 0),
    OAM_ENTRY(-10, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x25a, 9, 0),
    OAM_ENTRY(-12, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x310, 9, 0),
};

const u16 sTangleVineTallOam_OnGround_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x24e, 9, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2ce, 9, 0),
    OAM_ENTRY(-11, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x25b, 9, 0),
    OAM_ENTRY(-13, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x310, 9, 0),
};

const u16 sTangleVineTallOam_OnCeiling_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, 32, OAM_DIMS_16x32, OAM_Y_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x2cc, 9, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x25a, 9, 0),
    OAM_ENTRY(-12, 28, OAM_DIMS_8x8, OAM_Y_FLIP, 0x310, 9, 0),
};

const u16 sTangleVineTallOam_OnCeiling_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, 32, OAM_DIMS_16x32, OAM_Y_FLIP, 0x24e, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x2ce, 9, 0),
    OAM_ENTRY(-11, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x25b, 9, 0),
    OAM_ENTRY(-13, 28, OAM_DIMS_8x8, OAM_Y_FLIP, 0x310, 9, 0),
};

const u16 sTangleVineTallOam_OnCeiling_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, 32, OAM_DIMS_16x32, OAM_Y_FLIP, 0x248, 9, 0),
    OAM_ENTRY(-7, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x2c8, 9, 0),
    OAM_ENTRY(-11, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x258, 9, 0),
    OAM_ENTRY(-12, 28, OAM_DIMS_8x8, OAM_Y_FLIP, 0x310, 9, 0),
};

const u16 sTangleVineTallOam_OnCeiling_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-5, 32, OAM_DIMS_16x32, OAM_Y_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(-5, 0, OAM_DIMS_16x32, OAM_Y_FLIP, 0x2ca, 9, 0),
    OAM_ENTRY(-10, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x259, 9, 0),
    OAM_ENTRY(-12, 29, OAM_DIMS_8x8, OAM_Y_FLIP, 0x310, 9, 0),
};

const u16 sTangleVineMediumOam_OnGround_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x250, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d0, 9, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x25e, 9, 0),
};

const u16 sTangleVineMediumOam_OnGround_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x252, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d2, 9, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x25f, 9, 0),
};

const u16 sTangleVineMediumOam_OnGround_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x254, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d4, 9, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x25c, 9, 0),
};

const u16 sTangleVineMediumOam_OnGround_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x256, 9, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2d6, 9, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x25d, 9, 0),
};

const u16 sTangleVineMediumOam_OnCeiling_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, 16, OAM_DIMS_16x32, OAM_Y_FLIP, 0x252, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x2d2, 9, 0),
    OAM_ENTRY(-11, 0, OAM_DIMS_8x32, OAM_XY_FLIP, 0x25c, 9, 0),
};

const u16 sTangleVineMediumOam_OnCeiling_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, 16, OAM_DIMS_16x32, OAM_Y_FLIP, 0x254, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x2d4, 9, 0),
    OAM_ENTRY(-9, 0, OAM_DIMS_8x32, OAM_XY_FLIP, 0x25d, 9, 0),
};

const u16 sTangleVineMediumOam_OnCeiling_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, 16, OAM_DIMS_16x32, OAM_Y_FLIP, 0x256, 9, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x2d6, 9, 0),
    OAM_ENTRY(-6, 0, OAM_DIMS_8x32, OAM_XY_FLIP, 0x25c, 9, 0),
};

const u16 sTangleVineMediumOam_OnCeiling_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, 16, OAM_DIMS_16x32, OAM_Y_FLIP, 0x250, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x2d0, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x32, OAM_XY_FLIP, 0x25d, 9, 0),
};

const u16 sTangleVineShortOam_OnGround_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x258, 9, 0),
    OAM_ENTRY(-5, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 0x310, 9, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x32, OAM_X_FLIP, 0x25c, 9, 0),
};

const u16 sTangleVineShortOam_OnGround_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x259, 9, 0),
    OAM_ENTRY(-5, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x310, 9, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x32, OAM_X_FLIP, 0x25d, 9, 0),
};

const u16 sTangleVineShortOam_OnGround_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x25a, 9, 0),
    OAM_ENTRY(-6, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x310, 9, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x32, OAM_X_FLIP, 0x25e, 9, 0),
};

const u16 sTangleVineShortOam_OnGround_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-3, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x25b, 9, 0),
    OAM_ENTRY(-6, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 0x310, 9, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x32, OAM_X_FLIP, 0x25f, 9, 0),
};

const u16 sTangleVineShortOam_OnCeiling_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x258, 9, 0),
    OAM_ENTRY(0, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x311, 9, 0),
    OAM_ENTRY(-3, 27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x312, 9, 0),
};

const u16 sTangleVineShortOam_OnCeiling_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x259, 9, 0),
    OAM_ENTRY(1, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x311, 9, 0),
    OAM_ENTRY(-6, 27, OAM_DIMS_8x8, OAM_NO_FLIP, 0x312, 9, 0),
};

const u16 sTangleVineShortOam_OnCeiling_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x25a, 9, 0),
    OAM_ENTRY(0, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x311, 9, 0),
    OAM_ENTRY(-5, 26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x312, 9, 0),
};

const u16 sTangleVineShortOam_OnCeiling_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x25b, 9, 0),
    OAM_ENTRY(-1, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x311, 9, 0),
    OAM_ENTRY(-5, 28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x312, 9, 0),
};

const u16 sTangleVineCurvedOam_OnGround_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -32, OAM_DIMS_8x32, OAM_X_FLIP, 0x25c, 9, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x32, OAM_X_FLIP, 0x25e, 9, 0),
    OAM_ENTRY(1, -33, OAM_DIMS_8x8, OAM_X_FLIP, 0x312, 9, 0),
};

const u16 sTangleVineCurvedOam_OnGround_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -32, OAM_DIMS_8x32, OAM_X_FLIP, 0x25d, 9, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x32, OAM_X_FLIP, 0x25f, 9, 0),
    OAM_ENTRY(0, -35, OAM_DIMS_8x8, OAM_X_FLIP, 0x312, 9, 0),
};

const u16 sTangleVineCurvedOam_OnGround_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -32, OAM_DIMS_8x32, OAM_X_FLIP, 0x25e, 9, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x32, OAM_X_FLIP, 0x25c, 9, 0),
    OAM_ENTRY(-2, -36, OAM_DIMS_8x8, OAM_X_FLIP, 0x312, 9, 0),
};

const u16 sTangleVineCurvedOam_OnGround_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -32, OAM_DIMS_8x32, OAM_X_FLIP, 0x25f, 9, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_8x32, OAM_X_FLIP, 0x25d, 9, 0),
    OAM_ENTRY(-5, -37, OAM_DIMS_8x8, OAM_X_FLIP, 0x312, 9, 0),
};

const u16 sTangleVineCurvedOam_OnCeiling_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x25c, 9, 0),
    OAM_ENTRY(-2, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x25e, 9, 0),
    OAM_ENTRY(-9, 28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x311, 9, 0),
};

const u16 sTangleVineCurvedOam_OnCeiling_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x25d, 9, 0),
    OAM_ENTRY(-2, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x25f, 9, 0),
    OAM_ENTRY(-8, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x311, 9, 0),
};

const u16 sTangleVineCurvedOam_OnCeiling_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x25e, 9, 0),
    OAM_ENTRY(-2, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x25c, 9, 0),
    OAM_ENTRY(-6, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x311, 9, 0),
};

const u16 sTangleVineCurvedOam_OnCeiling_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x25f, 9, 0),
    OAM_ENTRY(-2, 0, OAM_DIMS_8x32, OAM_Y_FLIP, 0x25d, 9, 0),
    OAM_ENTRY(-4, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x311, 9, 0),
};

const u16 sTangleVineOam_Unused_Frame[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x240, 9, 0),
};

const u16 sTangleVineGerutaPartOam_Grip_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -65, OAM_DIMS_16x32, OAM_NO_FLIP, 0x242, 9, 0),
};

const u16 sTangleVineGerutaPartOam_Grip_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -63, OAM_DIMS_16x32, OAM_NO_FLIP, 0x244, 9, 0),
};

const u16 sTangleVineGerutaPartOam_Grip_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(1, -61, OAM_DIMS_16x32, OAM_NO_FLIP, 0x246, 9, 0),
};

const u16 sTangleVineGerutaPartOam_Grip_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x240, 9, 0),
};

const u16 sTangleVineGerutaPartOam_Grip_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -65, OAM_DIMS_16x32, OAM_NO_FLIP, 0x242, 9, 0),
};

const u16 sTangleVineGerutaPartOam_Grip_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -63, OAM_DIMS_16x32, OAM_NO_FLIP, 0x244, 9, 0),
};

const u16 sTangleVineGerutaPartOam_Grip_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(1, -61, OAM_DIMS_16x32, OAM_NO_FLIP, 0x246, 9, 0),
};

const u16 sTangleVineGerutaOam_Full_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x288, 9, 0),
    OAM_ENTRY(-3, -63, OAM_DIMS_16x32, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(-7, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2c8, 9, 0),
    OAM_ENTRY(-1, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 0x261, 9, 0),
};

const u16 sTangleVineGerutaOam_Full_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -65, OAM_DIMS_16x32, OAM_NO_FLIP, 0x242, 9, 0),
    OAM_ENTRY(-6, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(-6, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2ca, 9, 0),
};

const u16 sTangleVineGerutaOam_Full_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -63, OAM_DIMS_16x32, OAM_NO_FLIP, 0x244, 9, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2cc, 9, 0),
};

const u16 sTangleVineGerutaOam_Full_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28e, 9, 0),
    OAM_ENTRY(-3, -63, OAM_DIMS_16x32, OAM_NO_FLIP, 0x246, 9, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2ce, 9, 0),
    OAM_ENTRY(-8, -56, OAM_DIMS_16x8, OAM_NO_FLIP, 0x26e, 9, 0),
};

const u16 sTangleVineGerutaOam_Root_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-1, -57, OAM_DIMS_8x8, OAM_NO_FLIP, 0x261, 9, 0),
    OAM_ENTRY(-7, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2c8, 9, 0),
    OAM_ENTRY(-7, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x288, 9, 0),
};

const u16 sTangleVineGerutaOam_Root_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(-5, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2ca, 9, 0),
};

const u16 sTangleVineGerutaOam_Root_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2cc, 9, 0),
};

const u16 sTangleVineGerutaOam_Root_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2ce, 9, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28e, 9, 0),
};

const u16 sTangleVineGerutaOam_Root_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-1, -57, OAM_DIMS_8x8, OAM_NO_FLIP, 0x261, 9, 0),
    OAM_ENTRY(-7, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2c8, 9, 0),
    OAM_ENTRY(-7, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x288, 9, 0),
};

const u16 sTangleVineGerutaOam_Root_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x24a, 9, 0),
    OAM_ENTRY(-5, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2ca, 9, 0),
};

const u16 sTangleVineGerutaOam_Root_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2cc, 9, 0),
};

const u16 sTangleVineGerutaOam_Root_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2ce, 9, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28e, 9, 0),
};

const u16 sTangleVineRedGerutaOam_Frame0[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-11, -69, OAM_DIMS_16x32, OAM_X_FLIP, 0x2c2, 10, 0),
    OAM_ENTRY(-6, -43, OAM_DIMS_16x8, OAM_NO_FLIP, 0x316, 10, 0),
    OAM_ENTRY(-9, -50, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2d8, 10, 0),
    OAM_ENTRY(-6, -43, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 10, 0),
    OAM_ENTRY(8, -45, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 10, 0),
    OAM_ENTRY(-21, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 10, 0),
    OAM_ENTRY(4, -39, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 10, 0),
    OAM_ENTRY(-17, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 10, 0),
    OAM_ENTRY(-5, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2c0, 10, 0),
};

const u16 sTangleVineRedGerutaOam_Frame1[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-5, -43, OAM_DIMS_16x8, OAM_NO_FLIP, 0x316, 10, 0),
    OAM_ENTRY(-12, -69, OAM_DIMS_16x32, OAM_X_FLIP, 0x2c4, 10, 0),
    OAM_ENTRY(-7, -49, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2da, 10, 0),
    OAM_ENTRY(-5, -43, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 10, 0),
    OAM_ENTRY(9, -45, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 10, 0),
    OAM_ENTRY(-20, -44, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 10, 0),
    OAM_ENTRY(5, -39, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 10, 0),
    OAM_ENTRY(-16, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 10, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2c2, 10, 0),
};

const u16 sTangleVineRedGerutaOam_Frame2[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-6, -41, OAM_DIMS_16x8, OAM_NO_FLIP, 0x316, 10, 0),
    OAM_ENTRY(-13, -68, OAM_DIMS_16x32, OAM_X_FLIP, 0x2c6, 10, 0),
    OAM_ENTRY(-9, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2dc, 10, 0),
    OAM_ENTRY(-5, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 10, 0),
    OAM_ENTRY(9, -43, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 10, 0),
    OAM_ENTRY(-20, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 10, 0),
    OAM_ENTRY(5, -37, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 10, 0),
    OAM_ENTRY(-16, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 10, 0),
    OAM_ENTRY(-5, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2c4, 10, 0),
};

const u16 sTangleVineRedGerutaOam_Frame3[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-11, -69, OAM_DIMS_16x32, OAM_X_FLIP, 0x2c0, 10, 0),
    OAM_ENTRY(-6, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 0x316, 10, 0),
    OAM_ENTRY(-9, -49, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2da, 10, 0),
    OAM_ENTRY(-6, -42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 10, 0),
    OAM_ENTRY(8, -44, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 10, 0),
    OAM_ENTRY(-21, -43, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 10, 0),
    OAM_ENTRY(4, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 10, 0),
    OAM_ENTRY(-17, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 10, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2c6, 10, 0),
};

const u16 sTangleVineGerutaPartOam_Geruta_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(6, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-23, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
};

const u16 sTangleVineGerutaPartOam_Geruta_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-20, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-1, -3, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-14, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
};

const u16 sTangleVineGerutaPartOam_Geruta_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-21, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(6, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-20, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_16x16, OAM_X_FLIP, 0x210, 8, 0),
};

const u16 sTangleVineGerutaPartOam_Geruta_Frame6[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-20, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-1, -3, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-14, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
};

const u16 sTangleVineGerutaPartOam_Geruta_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-22, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(7, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(0, -3, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
};

const u16 sTangleVineGerutaPartOam_Geruta_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-22, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(7, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(0, -3, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
};

const u16 sTangleVineGerutaPartOam_Geruta_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(7, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-22, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(3, -4, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-18, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
};

const u16 sTangleVineGerutaPartOam_Geruta_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-7, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-22, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(6, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(2, -4, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-16, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
};

const u16 sTangleVineLarvaRightOam_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2c0, 10, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x313, 10, 0),
    OAM_ENTRY(3, -56, OAM_DIMS_8x16, OAM_Y_FLIP, 0x313, 10, 0),
};

const u16 sTangleVineLarvaRightOam_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2c2, 10, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x313, 10, 0),
    OAM_ENTRY(1, -55, OAM_DIMS_8x16, OAM_Y_FLIP, 0x313, 10, 0),
};

const u16 sTangleVineLarvaRightOam_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2c4, 10, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x313, 10, 0),
    OAM_ENTRY(0, -55, OAM_DIMS_8x16, OAM_Y_FLIP, 0x313, 10, 0),
};

const u16 sTangleVineLarvaRightOam_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2c6, 10, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x313, 10, 0),
    OAM_ENTRY(0, -56, OAM_DIMS_8x16, OAM_Y_FLIP, 0x313, 10, 0),
};

const u16 sTangleVineLarvaLeftOam_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -39, OAM_DIMS_16x32, OAM_X_FLIP, 0x2c0, 10, 0),
    OAM_ENTRY(-3, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x313, 10, 0),
    OAM_ENTRY(-11, -55, OAM_DIMS_8x16, OAM_XY_FLIP, 0x313, 10, 0),
};

const u16 sTangleVineLarvaLeftOam_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-10, -38, OAM_DIMS_16x32, OAM_X_FLIP, 0x2c2, 10, 0),
    OAM_ENTRY(-3, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x313, 10, 0),
    OAM_ENTRY(-8, -53, OAM_DIMS_8x16, OAM_XY_FLIP, 0x313, 10, 0),
};

const u16 sTangleVineLarvaLeftOam_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-11, -38, OAM_DIMS_16x32, OAM_X_FLIP, 0x2c4, 10, 0),
    OAM_ENTRY(-3, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x313, 10, 0),
    OAM_ENTRY(-8, -53, OAM_DIMS_8x16, OAM_XY_FLIP, 0x313, 10, 0),
};

const u16 sTangleVineLarvaLeftOam_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-11, -39, OAM_DIMS_16x32, OAM_X_FLIP, 0x2c6, 10, 0),
    OAM_ENTRY(-3, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x313, 10, 0),
    OAM_ENTRY(-7, -55, OAM_DIMS_8x16, OAM_XY_FLIP, 0x313, 10, 0),
};

const struct FrameData sTangleVineTallOam_OnGround[5] = {
    [0] = {
        .pFrame = sTangleVineTallOam_OnGround_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sTangleVineTallOam_OnGround_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sTangleVineTallOam_OnGround_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sTangleVineTallOam_OnGround_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTangleVineMediumOam_OnGround[5] = {
    [0] = {
        .pFrame = sTangleVineMediumOam_OnGround_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sTangleVineMediumOam_OnGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sTangleVineMediumOam_OnGround_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sTangleVineMediumOam_OnGround_Frame3,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTangleVineShortOam_OnGround[5] = {
    [0] = {
        .pFrame = sTangleVineShortOam_OnGround_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sTangleVineShortOam_OnGround_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sTangleVineShortOam_OnGround_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sTangleVineShortOam_OnGround_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTangleVineCurvedOam_OnGround[7] = {
    [0] = {
        .pFrame = sTangleVineCurvedOam_OnGround_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sTangleVineCurvedOam_OnGround_Frame1,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [2] = {
        .pFrame = sTangleVineCurvedOam_OnGround_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sTangleVineCurvedOam_OnGround_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sTangleVineCurvedOam_OnGround_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sTangleVineCurvedOam_OnGround_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTangleVineTallOam_OnCeiling[5] = {
    [0] = {
        .pFrame = sTangleVineTallOam_OnCeiling_Frame0,
        .timer = CONVERT_SECONDS(13.f / 60)
    },
    [1] = {
        .pFrame = sTangleVineTallOam_OnCeiling_Frame1,
        .timer = CONVERT_SECONDS(13.f / 60)
    },
    [2] = {
        .pFrame = sTangleVineTallOam_OnCeiling_Frame2,
        .timer = CONVERT_SECONDS(13.f / 60)
    },
    [3] = {
        .pFrame = sTangleVineTallOam_OnCeiling_Frame3,
        .timer = CONVERT_SECONDS(13.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTangleVineMediumOam_OnCeiling[5] = {
    [0] = {
        .pFrame = sTangleVineMediumOam_OnCeiling_Frame0,
        .timer = CONVERT_SECONDS(11.f / 60)
    },
    [1] = {
        .pFrame = sTangleVineMediumOam_OnCeiling_Frame1,
        .timer = CONVERT_SECONDS(11.f / 60)
    },
    [2] = {
        .pFrame = sTangleVineMediumOam_OnCeiling_Frame2,
        .timer = CONVERT_SECONDS(11.f / 60)
    },
    [3] = {
        .pFrame = sTangleVineMediumOam_OnCeiling_Frame3,
        .timer = CONVERT_SECONDS(11.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTangleVineShortOam_OnCeiling[5] = {
    [0] = {
        .pFrame = sTangleVineShortOam_OnCeiling_Frame0,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [1] = {
        .pFrame = sTangleVineShortOam_OnCeiling_Frame1,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [2] = {
        .pFrame = sTangleVineShortOam_OnCeiling_Frame2,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [3] = {
        .pFrame = sTangleVineShortOam_OnCeiling_Frame3,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTangleVineCurvedOam_OnCeiling[5] = {
    [0] = {
        .pFrame = sTangleVineCurvedOam_OnCeiling_Frame0,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [1] = {
        .pFrame = sTangleVineCurvedOam_OnCeiling_Frame1,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [2] = {
        .pFrame = sTangleVineCurvedOam_OnCeiling_Frame2,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [3] = {
        .pFrame = sTangleVineCurvedOam_OnCeiling_Frame3,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTangleVineGerutaPartOam_Grip[9] = {
    [0] = {
        .pFrame = sTangleVineGerutaPartOam_Grip_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTangleVineGerutaPartOam_Grip_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sTangleVineGerutaPartOam_Grip_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sTangleVineGerutaPartOam_Grip_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sTangleVineGerutaPartOam_Grip_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sTangleVineGerutaPartOam_Grip_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sTangleVineGerutaPartOam_Grip_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sTangleVineGerutaPartOam_Grip_Frame7,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTangleVineGerutaOam_Root[9] = {
    [0] = {
        .pFrame = sTangleVineGerutaOam_Root_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTangleVineGerutaOam_Root_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sTangleVineGerutaOam_Root_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sTangleVineGerutaOam_Root_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sTangleVineGerutaOam_Root_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sTangleVineGerutaOam_Root_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sTangleVineGerutaOam_Root_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sTangleVineGerutaOam_Root_Frame7,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTangleVineGerutaOam_Full[5] = {
    [0] = {
        .pFrame = sTangleVineGerutaOam_Full_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sTangleVineGerutaOam_Full_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sTangleVineGerutaOam_Full_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sTangleVineGerutaOam_Full_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTangleVineRedGerutaOam[5] = {
    [0] = {
        .pFrame = sTangleVineRedGerutaOam_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sTangleVineRedGerutaOam_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sTangleVineRedGerutaOam_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sTangleVineRedGerutaOam_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTangleVineGerutaPartOam_Geruta[9] = {
    [0] = {
        .pFrame = sTangleVineGerutaPartOam_Geruta_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTangleVineGerutaPartOam_Geruta_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sTangleVineGerutaPartOam_Geruta_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sTangleVineGerutaPartOam_Geruta_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sTangleVineGerutaPartOam_Geruta_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sTangleVineGerutaPartOam_Geruta_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sTangleVineGerutaPartOam_Geruta_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sTangleVineGerutaPartOam_Geruta_Frame7,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTangleVineLarvaRightOam[5] = {
    [0] = {
        .pFrame = sTangleVineLarvaRightOam_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sTangleVineLarvaRightOam_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sTangleVineLarvaRightOam_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sTangleVineLarvaRightOam_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTangleVineLarvaLeftOam[5] = {
    [0] = {
        .pFrame = sTangleVineLarvaLeftOam_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sTangleVineLarvaLeftOam_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sTangleVineLarvaLeftOam_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sTangleVineLarvaLeftOam_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};
