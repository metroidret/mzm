#include "data/sprites/imago.h"
#include "macros.h"

#include "sprites_AI/imago.h"

static const s16 sImagoMultiSpriteData_Idle_Frame0[IMAGO_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [IMAGO_PART_LEFT_WING_INTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_LEFT_WING_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_LEFT_WING_EXTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_LEFT_WING_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -QUARTER_BLOCK_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = (HALF_BLOCK_SIZE + PIXEL_SIZE)
    },
    [IMAGO_PART_BODY] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_BODY_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = EIGHTH_BLOCK_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_RIGHT_WING_INTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_RIGHT_WING_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_RIGHT_WING_EXTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_RIGHT_WING_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(HALF_BLOCK_SIZE - PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = (HALF_BLOCK_SIZE - PIXEL_SIZE)
    },
    [IMAGO_PART_CORE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_CORE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_IMAGO] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_FLYING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    }
};

static const s16 sImagoMultiSpriteData_Growling_Unused_Frame0[IMAGO_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [IMAGO_PART_LEFT_WING_INTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_LEFT_WING_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_LEFT_WING_EXTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_LEFT_WING_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -QUARTER_BLOCK_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = (HALF_BLOCK_SIZE + PIXEL_SIZE)
    },
    [IMAGO_PART_BODY] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_BODY_GROWLING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_RIGHT_WING_INTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_RIGHT_WING_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_RIGHT_WING_EXTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_RIGHT_WING_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(HALF_BLOCK_SIZE - PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = (HALF_BLOCK_SIZE - PIXEL_SIZE)
    },
    [IMAGO_PART_CORE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_CORE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_IMAGO] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_FLYING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    }
};

static const s16 sImagoMultiSpriteData_ShootingNeedles_Frame0[IMAGO_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [IMAGO_PART_LEFT_WING_INTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_LEFT_WING_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_LEFT_WING_EXTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_LEFT_WING_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -QUARTER_BLOCK_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = (HALF_BLOCK_SIZE + PIXEL_SIZE)
    },
    [IMAGO_PART_BODY] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_BODY_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 8,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_RIGHT_WING_INTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_RIGHT_WING_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_RIGHT_WING_EXTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_RIGHT_WING_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(HALF_BLOCK_SIZE - PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = (HALF_BLOCK_SIZE - PIXEL_SIZE)
    },
    [IMAGO_PART_CORE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_CORE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_IMAGO] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_SHOOTING_NEEDLES,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    }
};

static const s16 sImagoMultiSpriteData_ShootingNeedles_Frame1[IMAGO_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [IMAGO_PART_LEFT_WING_INTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_LEFT_WING_SHOOTING_NEEDLES,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_LEFT_WING_EXTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_LEFT_WING_SHOOTING_NEEDLES,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -QUARTER_BLOCK_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = (HALF_BLOCK_SIZE + PIXEL_SIZE)
    },
    [IMAGO_PART_BODY] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_BODY_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 8,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_RIGHT_WING_INTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_RIGHT_WING_SHOOTING_NEEDLES,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_RIGHT_WING_EXTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_RIGHT_WING_SHOOTING_NEEDLES,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(HALF_BLOCK_SIZE - PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = (HALF_BLOCK_SIZE - PIXEL_SIZE)
    },
    [IMAGO_PART_CORE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_CORE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_IMAGO] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_SHOOTING_NEEDLES,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    }
};

static const s16 sImagoMultiSpriteData_RechargingNeedles_Frame0[IMAGO_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [IMAGO_PART_LEFT_WING_INTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_LEFT_WING_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_LEFT_WING_EXTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_LEFT_WING_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -QUARTER_BLOCK_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = (HALF_BLOCK_SIZE + PIXEL_SIZE)
    },
    [IMAGO_PART_BODY] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_BODY_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 8,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_RIGHT_WING_INTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_RIGHT_WING_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_RIGHT_WING_EXTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_RIGHT_WING_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(HALF_BLOCK_SIZE - PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = (HALF_BLOCK_SIZE - PIXEL_SIZE)
    },
    [IMAGO_PART_CORE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_CORE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_IMAGO] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_RECHARGING_NEEDLES,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    }
};

static const s16 sImagoMultiSpriteData_Dying_Frame0[IMAGO_PART_END][MULTI_SPRITE_DATA_ELEMENT_END] = {
    [IMAGO_PART_LEFT_WING_INTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_LEFT_WING_DYING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_LEFT_WING_EXTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_LEFT_WING_SHOOTING_NEEDLES,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = (HALF_BLOCK_SIZE + PIXEL_SIZE)
    },
    [IMAGO_PART_BODY] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_BODY_IDLE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_RIGHT_WING_INTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_RIGHT_WING_DYING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -QUARTER_BLOCK_SIZE,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = QUARTER_BLOCK_SIZE - PIXEL_SIZE
    },
    [IMAGO_PART_RIGHT_WING_EXTERNAL] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_RIGHT_WING_DYING,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = -(HALF_BLOCK_SIZE + PIXEL_SIZE),
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = THREE_QUARTER_BLOCK_SIZE
    },
    [IMAGO_PART_CORE] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_CORE,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    },
    [IMAGO_PART_IMAGO] = {
        [MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX] = IMAGO_OAM_BROKEN_STINGER,
        [MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET]  = 0,
        [MULTI_SPRITE_DATA_ELEMENT_X_OFFSET]  = 0
    }
};

const struct MultiSpriteData sImagoMultiSpriteData_Idle[2] = {
    [0] = {
        .pData = sImagoMultiSpriteData_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sImagoMultiSpriteData_Growling_Unused[2] = {
    [0] = {
        .pData = sImagoMultiSpriteData_Growling_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sImagoMultiSpriteData_ShootingNeedles[3] = {
    [0] = {
        .pData = sImagoMultiSpriteData_ShootingNeedles_Frame0,
        .timer = ONE_THIRD_SECOND
    },
    [1] = {
        .pData = sImagoMultiSpriteData_ShootingNeedles_Frame1,
        .timer = CONVERT_SECONDS(0.29f)
    },
    [2] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sImagoMultiSpriteData_RechargingNeedles[2] = {
    [0] = {
        .pData = sImagoMultiSpriteData_RechargingNeedles_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = MULTI_SPRITE_DATA_TERMINATOR
};

const struct MultiSpriteData sImagoMultiSpriteData_Dying[2] = {
    [0] = {
        .pData = sImagoMultiSpriteData_Dying_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = MULTI_SPRITE_DATA_TERMINATOR
};

const s16 sImagoDamagedStingerFallingYVelocity[10] = {
    0, 1, 2, 4, 8, 12, 16, 20, 24, SHORT_MAX
};

const s16 sImagoAttackingXVelocity[49] = {
    -1, -1, -1, -1, -2, -2, -2, -2, -3, -3, -4, -5,
    -6, -5, -4, -3, -2, -2, -2, -2, -1, -1, -1, -1,
    1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 5, 6, 5, 4, 3,
    2, 2, 2, 2, 1, 1, 1, 1, SHORT_MAX
};

const u8 sImagoDynamicPaletteData[9][2] = {
    { 2, 12 },
    { 1, 6 },
    { 0, 8 },
    { 1, 4 },
    { 2, 22 },
    { 1, 6 },
    { 0, 8 },
    { 1, 4 },
    { 128, 128 }
};

const u32 sImagoGfx[1503] = INCBIN_U32("data/sprites/Imago.gfx.lz");
const u16 sImagoPal[96] = INCBIN_U16("data/sprites/Imago.pal");

static const u16 sImagoPartOam_BodyIdle_Frame0[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-39, -35, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-7, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-15, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 591, 8, 0),
    OAM_ENTRY(1, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 593, 8, 0),
    OAM_ENTRY(-15, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 655, 8, 0),
    OAM_ENTRY(1, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 657, 8, 0),
    OAM_ENTRY(-50, -29, OAM_DIMS_32x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-18, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-50, -13, OAM_DIMS_32x8, OAM_NO_FLIP, 582, 8, 0),
    OAM_ENTRY(-18, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-18, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 618, 8, 0),
    OAM_ENTRY(-56, -14, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-24, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-56, 18, OAM_DIMS_32x8, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-24, 18, OAM_DIMS_16x8, OAM_NO_FLIP, 644, 8, 0),
    OAM_ENTRY(-47, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-14, -39, OAM_DIMS_32x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-14, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 658, 8, 0),
};

static const u16 sImagoPartOam_BodyIdle_Frame1[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-39, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-7, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-15, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 591, 8, 0),
    OAM_ENTRY(1, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 593, 8, 0),
    OAM_ENTRY(-15, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 655, 8, 0),
    OAM_ENTRY(1, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 657, 8, 0),
    OAM_ENTRY(-51, -30, OAM_DIMS_32x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-19, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-51, -14, OAM_DIMS_32x8, OAM_NO_FLIP, 582, 8, 0),
    OAM_ENTRY(-19, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-19, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 618, 8, 0),
    OAM_ENTRY(-57, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-25, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-57, 16, OAM_DIMS_32x8, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-25, 16, OAM_DIMS_16x8, OAM_NO_FLIP, 644, 8, 0),
    OAM_ENTRY(-48, 7, OAM_DIMS_32x16, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-15, -38, OAM_DIMS_32x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-15, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 658, 8, 0),
};

static const u16 sImagoPartOam_BodyIdle_Frame2[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-40, -35, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-8, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 591, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 593, 8, 0),
    OAM_ENTRY(-16, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 655, 8, 0),
    OAM_ENTRY(0, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 657, 8, 0),
    OAM_ENTRY(-51, -29, OAM_DIMS_32x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-19, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-51, -13, OAM_DIMS_32x8, OAM_NO_FLIP, 582, 8, 0),
    OAM_ENTRY(-19, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-19, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 618, 8, 0),
    OAM_ENTRY(-57, -14, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-25, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-57, 18, OAM_DIMS_32x8, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-25, 18, OAM_DIMS_16x8, OAM_NO_FLIP, 644, 8, 0),
    OAM_ENTRY(-48, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-15, -38, OAM_DIMS_32x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-15, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 658, 8, 0),
};

static const u16 sImagoPartOam_BodyIdle_Frame4[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-40, -35, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-8, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 591, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 593, 8, 0),
    OAM_ENTRY(-16, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 655, 8, 0),
    OAM_ENTRY(0, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 657, 8, 0),
    OAM_ENTRY(-51, -29, OAM_DIMS_32x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-19, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-51, -13, OAM_DIMS_32x8, OAM_NO_FLIP, 582, 8, 0),
    OAM_ENTRY(-19, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-19, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 618, 8, 0),
    OAM_ENTRY(-57, -14, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-25, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-57, 18, OAM_DIMS_32x8, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-25, 18, OAM_DIMS_16x8, OAM_NO_FLIP, 644, 8, 0),
    OAM_ENTRY(-49, 7, OAM_DIMS_32x16, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-15, -37, OAM_DIMS_32x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-15, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 658, 8, 0),
};

static const u16 sImagoOam_BrokenStinger_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -13, OAM_DIMS_32x16, OAM_NO_FLIP, 816, 10, 0),
    OAM_ENTRY(-7, 3, OAM_DIMS_32x8, OAM_NO_FLIP, 880, 10, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 648, 10, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 616, 10, 0),
};

static const u16 sImagoOam_BrokenStinger_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(0, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 852, 10, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 854, 10, 0),
    OAM_ENTRY(16, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 616, 10, 0),
    OAM_ENTRY(16, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 648, 10, 0),
    OAM_ENTRY(11, 11, OAM_DIMS_8x8, OAM_NO_FLIP, 616, 10, 0),
};

static const u16 sImagoPartOam_BodyIdle_Frame3[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-40, -35, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-8, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 591, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 593, 8, 0),
    OAM_ENTRY(-16, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 655, 8, 0),
    OAM_ENTRY(0, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 657, 8, 0),
    OAM_ENTRY(-51, -29, OAM_DIMS_32x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-19, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-51, -13, OAM_DIMS_32x8, OAM_NO_FLIP, 582, 8, 0),
    OAM_ENTRY(-19, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-19, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 618, 8, 0),
    OAM_ENTRY(-57, -14, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-25, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-57, 18, OAM_DIMS_32x8, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-25, 18, OAM_DIMS_16x8, OAM_NO_FLIP, 644, 8, 0),
    OAM_ENTRY(-48, 9, OAM_DIMS_32x16, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-15, -38, OAM_DIMS_32x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-15, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 658, 8, 0),
};

static const u16 sImagoPartOam_BodyGrowling_Frame2[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-39, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-7, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-15, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 591, 8, 0),
    OAM_ENTRY(1, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 593, 8, 0),
    OAM_ENTRY(-15, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 655, 8, 0),
    OAM_ENTRY(1, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 657, 8, 0),
    OAM_ENTRY(-51, -30, OAM_DIMS_32x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-19, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-51, -14, OAM_DIMS_32x8, OAM_NO_FLIP, 582, 8, 0),
    OAM_ENTRY(-19, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-19, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 618, 8, 0),
    OAM_ENTRY(-57, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-25, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-57, 16, OAM_DIMS_32x8, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-25, 16, OAM_DIMS_16x8, OAM_NO_FLIP, 644, 8, 0),
    OAM_ENTRY(-48, 9, OAM_DIMS_32x16, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-15, -38, OAM_DIMS_32x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-15, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 658, 8, 0),
};

static const u16 sImagoPartOam_BodyGrowling_Frame3[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-40, -35, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-8, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 591, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 593, 8, 0),
    OAM_ENTRY(-16, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 655, 8, 0),
    OAM_ENTRY(0, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 657, 8, 0),
    OAM_ENTRY(-51, -29, OAM_DIMS_32x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-19, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-51, -13, OAM_DIMS_32x8, OAM_NO_FLIP, 582, 8, 0),
    OAM_ENTRY(-19, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-19, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 618, 8, 0),
    OAM_ENTRY(-57, -14, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-25, -14, OAM_DIMS_16x32, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-57, 18, OAM_DIMS_32x8, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-25, 18, OAM_DIMS_16x8, OAM_NO_FLIP, 644, 8, 0),
    OAM_ENTRY(-48, 12, OAM_DIMS_32x16, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-15, -38, OAM_DIMS_32x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-15, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 658, 8, 0),
};

static const u16 sImagoPartOam_BodyGrowling_Frame4[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-40, -35, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-8, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 591, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x16, OAM_NO_FLIP, 593, 8, 0),
    OAM_ENTRY(-16, -3, OAM_DIMS_16x8, OAM_NO_FLIP, 655, 8, 0),
    OAM_ENTRY(0, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 657, 8, 0),
    OAM_ENTRY(-51, -30, OAM_DIMS_32x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-19, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-51, -14, OAM_DIMS_32x8, OAM_NO_FLIP, 582, 8, 0),
    OAM_ENTRY(-19, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 586, 8, 0),
    OAM_ENTRY(-19, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 618, 8, 0),
    OAM_ENTRY(-57, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-25, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-57, 16, OAM_DIMS_32x8, OAM_NO_FLIP, 640, 8, 0),
    OAM_ENTRY(-25, 16, OAM_DIMS_16x8, OAM_NO_FLIP, 644, 8, 0),
    OAM_ENTRY(-49, 12, OAM_DIMS_32x16, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-15, -37, OAM_DIMS_32x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-15, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 658, 8, 0),
};

static const u16 sImagoPartOam_LeftWingIdle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-9, -11, OAM_DIMS_32x16, OAM_Y_FLIP, 727, 8, 0),
    OAM_ENTRY(23, -11, OAM_DIMS_16x16, OAM_Y_FLIP, 731, 8, 0),
};

static const u16 sImagoPartOam_LeftWingIdle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-10, -14, OAM_DIMS_32x8, OAM_NO_FLIP, 791, 8, 0),
    OAM_ENTRY(22, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 795, 8, 0),
};

static const u16 sImagoPartOam_LeftWingIdle_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-11, -23, OAM_DIMS_32x16, OAM_NO_FLIP, 727, 8, 0),
    OAM_ENTRY(21, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 731, 8, 0),
};

static const u16 sImagoPartOam_LeftWingIdle_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(7, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 589, 8, 0),
    OAM_ENTRY(-1, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 620, 8, 0),
    OAM_ENTRY(-9, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 614, 8, 0),
};

static const u16 sImagoPartOam_LeftWingIdle_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -55, OAM_DIMS_16x32, OAM_NO_FLIP, 733, 8, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 861, 8, 0),
};

static const u16 sImagoPartOam_RightWingIdle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-52, -15, OAM_DIMS_32x16, OAM_XY_FLIP, 727, 8, 0),
    OAM_ENTRY(-68, -15, OAM_DIMS_16x16, OAM_XY_FLIP, 731, 8, 0),
};

static const u16 sImagoPartOam_RightWingIdle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-50, -18, OAM_DIMS_32x8, OAM_X_FLIP, 791, 8, 0),
    OAM_ENTRY(-66, -18, OAM_DIMS_16x8, OAM_X_FLIP, 795, 8, 0),
};

static const u16 sImagoPartOam_RightWingIdle_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-50, -26, OAM_DIMS_32x16, OAM_X_FLIP, 727, 8, 0),
    OAM_ENTRY(-66, -26, OAM_DIMS_16x16, OAM_X_FLIP, 731, 8, 0),
};

static const u16 sImagoPartOam_RightWingIdle_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-55, -41, OAM_DIMS_16x16, OAM_X_FLIP, 589, 8, 0),
    OAM_ENTRY(-47, -33, OAM_DIMS_16x16, OAM_X_FLIP, 620, 8, 0),
    OAM_ENTRY(-39, -25, OAM_DIMS_16x16, OAM_X_FLIP, 614, 8, 0),
};

static const u16 sImagoPartOam_RightWingIdle_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-39, -55, OAM_DIMS_16x32, OAM_X_FLIP, 733, 8, 0),
    OAM_ENTRY(-39, -23, OAM_DIMS_16x16, OAM_X_FLIP, 861, 8, 0),
};

static const u16 sImagoPartOam_Core_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-26, -21, OAM_DIMS_32x32, OAM_NO_FLIP, 736, 9, 0),
};

static const u16 sImagoPartOam_Core_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-26, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 800, 9, 0),
    OAM_ENTRY(-26, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 736, 9, 0),
    OAM_ENTRY(-9, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 802, 9, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 738, 9, 0),
    OAM_ENTRY(-18, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 801, 9, 0),
    OAM_ENTRY(-26, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 9, 0),
    OAM_ENTRY(-9, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 770, 9, 0),
    OAM_ENTRY(-15, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 769, 9, 0),
};

static const u16 sImagoPartOam_Core_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-28, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 800, 9, 0),
    OAM_ENTRY(-28, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 736, 9, 0),
    OAM_ENTRY(-9, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 802, 9, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 738, 9, 0),
    OAM_ENTRY(-19, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 801, 9, 0),
    OAM_ENTRY(-27, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 768, 9, 0),
    OAM_ENTRY(-10, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 770, 9, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 769, 9, 0),
};

static const u16 sImagoOam_Flying_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-12, 18, OAM_DIMS_16x16, OAM_NO_FLIP, 823, 9, 0),
    OAM_ENTRY(-15, -28, OAM_DIMS_32x32, OAM_NO_FLIP, 680, 9, 0),
    OAM_ENTRY(-15, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 808, 9, 0),
    OAM_ENTRY(-15, -20, OAM_DIMS_32x32, OAM_NO_FLIP, 684, 9, 0),
    OAM_ENTRY(-15, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 812, 9, 0),
    OAM_ENTRY(-15, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 876, 9, 0),
    OAM_ENTRY(-15, 1, OAM_DIMS_32x32, OAM_NO_FLIP, 772, 9, 0),
};

static const u16 sImagoOam_Flying_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-10, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 823, 9, 0),
    OAM_ENTRY(-15, -29, OAM_DIMS_32x32, OAM_NO_FLIP, 680, 9, 0),
    OAM_ENTRY(-15, 3, OAM_DIMS_32x8, OAM_NO_FLIP, 808, 9, 0),
    OAM_ENTRY(-14, -20, OAM_DIMS_32x32, OAM_NO_FLIP, 684, 9, 0),
    OAM_ENTRY(-14, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 812, 9, 0),
    OAM_ENTRY(-14, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 876, 9, 0),
    OAM_ENTRY(-13, 1, OAM_DIMS_32x32, OAM_NO_FLIP, 772, 9, 0),
};

static const u16 sImagoOam_Flying_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-9, 20, OAM_DIMS_16x16, OAM_NO_FLIP, 823, 9, 0),
    OAM_ENTRY(-14, -30, OAM_DIMS_32x32, OAM_NO_FLIP, 680, 9, 0),
    OAM_ENTRY(-14, 2, OAM_DIMS_32x8, OAM_NO_FLIP, 808, 9, 0),
    OAM_ENTRY(-13, -21, OAM_DIMS_32x32, OAM_NO_FLIP, 684, 9, 0),
    OAM_ENTRY(-12, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 812, 9, 0),
    OAM_ENTRY(-12, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 876, 9, 0),
    OAM_ENTRY(-12, 2, OAM_DIMS_32x32, OAM_NO_FLIP, 772, 9, 0),
};

static const u16 sImagoOam_Flying_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-10, 18, OAM_DIMS_16x16, OAM_NO_FLIP, 823, 9, 0),
    OAM_ENTRY(-15, -30, OAM_DIMS_32x32, OAM_NO_FLIP, 680, 9, 0),
    OAM_ENTRY(-15, 2, OAM_DIMS_32x8, OAM_NO_FLIP, 808, 9, 0),
    OAM_ENTRY(-14, -22, OAM_DIMS_32x32, OAM_NO_FLIP, 684, 9, 0),
    OAM_ENTRY(-13, -5, OAM_DIMS_32x16, OAM_NO_FLIP, 812, 9, 0),
    OAM_ENTRY(-13, 11, OAM_DIMS_32x8, OAM_NO_FLIP, 876, 9, 0),
    OAM_ENTRY(-13, 0, OAM_DIMS_32x32, OAM_NO_FLIP, 772, 9, 0),
};

static const u16 sImagoOam_Flying_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-12, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 823, 9, 0),
    OAM_ENTRY(-15, -27, OAM_DIMS_32x32, OAM_NO_FLIP, 680, 9, 0),
    OAM_ENTRY(-15, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 808, 9, 0),
    OAM_ENTRY(-14, -20, OAM_DIMS_32x32, OAM_NO_FLIP, 684, 9, 0),
    OAM_ENTRY(-15, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 812, 9, 0),
    OAM_ENTRY(-15, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 876, 9, 0),
    OAM_ENTRY(-15, 2, OAM_DIMS_32x32, OAM_NO_FLIP, 772, 9, 0),
};

static const u16 sImagoOam_ShootingNeedles_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-10, 21, OAM_DIMS_16x16, OAM_NO_FLIP, 823, 9, 0),
    OAM_ENTRY(-15, -27, OAM_DIMS_32x32, OAM_NO_FLIP, 680, 9, 0),
    OAM_ENTRY(-15, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 808, 9, 0),
    OAM_ENTRY(-13, -20, OAM_DIMS_32x32, OAM_NO_FLIP, 684, 9, 0),
    OAM_ENTRY(-13, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 812, 9, 0),
    OAM_ENTRY(-13, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 876, 9, 0),
    OAM_ENTRY(-13, 3, OAM_DIMS_32x32, OAM_NO_FLIP, 772, 9, 0),
};

static const u16 sImagoOam_ShootingNeedles_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-5, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 825, 9, 0),
    OAM_ENTRY(-14, -28, OAM_DIMS_32x32, OAM_NO_FLIP, 680, 9, 0),
    OAM_ENTRY(-14, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 808, 9, 0),
    OAM_ENTRY(-11, -21, OAM_DIMS_32x32, OAM_NO_FLIP, 684, 9, 0),
    OAM_ENTRY(-9, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 812, 9, 0),
    OAM_ENTRY(-9, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 876, 9, 0),
    OAM_ENTRY(-9, 2, OAM_DIMS_32x32, OAM_NO_FLIP, 772, 9, 0),
};

static const u16 sImagoOam_ShootingNeedles_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-4, 17, OAM_DIMS_16x16, OAM_NO_FLIP, 827, 9, 0),
    OAM_ENTRY(-12, -29, OAM_DIMS_32x32, OAM_NO_FLIP, 680, 9, 0),
    OAM_ENTRY(-12, 3, OAM_DIMS_32x8, OAM_NO_FLIP, 808, 9, 0),
    OAM_ENTRY(-10, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 684, 9, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_32x16, OAM_NO_FLIP, 812, 9, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_32x8, OAM_NO_FLIP, 876, 9, 0),
    OAM_ENTRY(-7, -2, OAM_DIMS_32x32, OAM_NO_FLIP, 772, 9, 0),
};

static const u16 sImagoOam_ShootingNeedles_Frame9[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-15, -28, OAM_DIMS_32x32, OAM_NO_FLIP, 680, 9, 0),
    OAM_ENTRY(-15, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 808, 9, 0),
    OAM_ENTRY(-15, -20, OAM_DIMS_32x32, OAM_NO_FLIP, 684, 9, 0),
    OAM_ENTRY(-15, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 812, 9, 0),
    OAM_ENTRY(-15, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 876, 9, 0),
    OAM_ENTRY(-15, 1, OAM_DIMS_32x32, OAM_NO_FLIP, 772, 9, 0),
};

static const u16 sImagoNeedleOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 725, 9, 0),
};

static const u16 sImagoOam_RechargingNeedles_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-15, -28, OAM_DIMS_32x32, OAM_NO_FLIP, 680, 9, 0),
    OAM_ENTRY(-15, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 808, 9, 0),
    OAM_ENTRY(-15, -20, OAM_DIMS_32x32, OAM_NO_FLIP, 684, 9, 0),
    OAM_ENTRY(-15, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 812, 9, 0),
    OAM_ENTRY(-15, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 876, 9, 0),
    OAM_ENTRY(-15, 9, OAM_DIMS_32x16, OAM_NO_FLIP, 708, 9, 0),
    OAM_ENTRY(-8, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 823, 9, 0),
    OAM_ENTRY(-15, 17, OAM_DIMS_32x16, OAM_NO_FLIP, 836, 9, 0),
};

static const u16 sImagoOam_RechargingNeedles_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-15, -28, OAM_DIMS_32x32, OAM_NO_FLIP, 680, 9, 0),
    OAM_ENTRY(-15, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 808, 9, 0),
    OAM_ENTRY(-15, -20, OAM_DIMS_32x32, OAM_NO_FLIP, 684, 9, 0),
    OAM_ENTRY(-15, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 812, 9, 0),
    OAM_ENTRY(-15, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 876, 9, 0),
    OAM_ENTRY(-15, 9, OAM_DIMS_32x16, OAM_NO_FLIP, 708, 9, 0),
    OAM_ENTRY(-11, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 823, 9, 0),
    OAM_ENTRY(-15, 17, OAM_DIMS_32x16, OAM_NO_FLIP, 836, 9, 0),
};

static const u16 sImagoOam_RechargingNeedles_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-15, -28, OAM_DIMS_32x32, OAM_NO_FLIP, 680, 9, 0),
    OAM_ENTRY(-15, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 808, 9, 0),
    OAM_ENTRY(-15, -20, OAM_DIMS_32x32, OAM_NO_FLIP, 684, 9, 0),
    OAM_ENTRY(-15, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 812, 9, 0),
    OAM_ENTRY(-15, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 876, 9, 0),
    OAM_ENTRY(-15, 9, OAM_DIMS_32x16, OAM_NO_FLIP, 708, 9, 0),
    OAM_ENTRY(-13, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 823, 9, 0),
    OAM_ENTRY(-15, 17, OAM_DIMS_32x16, OAM_NO_FLIP, 836, 9, 0),
};

static const u16 sImagoDamagedStingerOam_Frame0[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-24, -30, OAM_DIMS_32x32, OAM_NO_FLIP, 688, 9, 0),
    OAM_ENTRY(-15, -28, OAM_DIMS_32x32, OAM_NO_FLIP, 680, 9, 0),
    OAM_ENTRY(-15, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 808, 9, 0),
    OAM_ENTRY(-15, -20, OAM_DIMS_32x32, OAM_NO_FLIP, 684, 9, 0),
    OAM_ENTRY(-15, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 812, 9, 0),
    OAM_ENTRY(-15, 12, OAM_DIMS_32x8, OAM_NO_FLIP, 876, 9, 0),
    OAM_ENTRY(-15, 9, OAM_DIMS_32x16, OAM_NO_FLIP, 708, 9, 0),
    OAM_ENTRY(-13, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 823, 9, 0),
    OAM_ENTRY(-15, 17, OAM_DIMS_32x16, OAM_NO_FLIP, 836, 9, 0),
};

static const u16 sImagoEggOam_Standing_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 631, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 695, 9, 0),
};

static const u16 sImagoEggOam_Breaking_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 695, 9, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 535, 9, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 536, 9, 0),
};

static const u16 sImagoEggOam_Breaking_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-13, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 574, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 695, 9, 0),
    OAM_ENTRY(-1, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 536, 9, 0),
};

static const u16 sImagoEggOam_Breaking_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 638, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 695, 9, 0),
    OAM_ENTRY(-2, -21, OAM_DIMS_16x16, OAM_X_FLIP, 574, 9, 0),
};

static const u16 sImagoEggOam_Breaking_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 570, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 539, 9, 0),
    OAM_ENTRY(-22, -9, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 9, 0),
};

static const u16 sImagoEggOam_Breaking_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 602, 9, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 539, 9, 0),
    OAM_ENTRY(-23, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 9, 0),
};

static const u16 sImagoEggOam_Breaking_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 539, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 634, 9, 0),
    OAM_ENTRY(-23, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 9, 0),
};

static const u16 sImagoEggOam_Breaking_Frame7[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 539, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 666, 9, 0),
    OAM_ENTRY(-23, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 9, 0),
};

static const u16 sImagoEggOam_Breaking_Frame8[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 539, 9, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 698, 9, 0),
    OAM_ENTRY(-23, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 9, 0),
};

const struct FrameData sImagoPartOam_BodyIdle[8] = {
    [0] = {
        .pFrame = sImagoPartOam_BodyIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sImagoPartOam_BodyIdle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sImagoPartOam_BodyIdle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sImagoPartOam_BodyIdle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sImagoPartOam_BodyIdle_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sImagoPartOam_BodyIdle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sImagoPartOam_BodyIdle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sImagoPartOam_BodyGrowling[16] = {
    [0] = {
        .pFrame = sImagoPartOam_BodyIdle_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sImagoPartOam_BodyIdle_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sImagoPartOam_BodyGrowling_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sImagoPartOam_BodyGrowling_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sImagoPartOam_BodyGrowling_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sImagoPartOam_BodyGrowling_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sImagoPartOam_BodyGrowling_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sImagoPartOam_BodyGrowling_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = {
        .pFrame = sImagoPartOam_BodyGrowling_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sImagoPartOam_BodyGrowling_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sImagoPartOam_BodyGrowling_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [11] = {
        .pFrame = sImagoPartOam_BodyGrowling_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [12] = {
        .pFrame = sImagoPartOam_BodyGrowling_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [13] = {
        .pFrame = sImagoPartOam_BodyIdle_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [14] = {
        .pFrame = sImagoPartOam_BodyIdle_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [15] = FRAME_DATA_TERMINATOR
};

const struct FrameData sImagoOam_BrokenStinger[3] = {
    [0] = {
        .pFrame = sImagoOam_BrokenStinger_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sImagoOam_BrokenStinger_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sImagoPartOam_LeftWingIdle[8] = {
    [0] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sImagoPartOam_LeftWingShootingNeedles[6] = {
    [0] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sImagoPartOam_LeftWingDying[7] = {
    [0] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [3] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sImagoPartOam_LeftWingIdle_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sImagoPartOam_RightWingIdle[8] = {
    [0] = {
        .pFrame = sImagoPartOam_RightWingIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sImagoPartOam_RightWingIdle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sImagoPartOam_RightWingIdle_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sImagoPartOam_RightWingIdle_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sImagoPartOam_RightWingIdle_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sImagoPartOam_RightWingIdle_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sImagoPartOam_RightWingIdle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sImagoPartOam_RightWingShootingNeedles[6] = {
    [0] = {
        .pFrame = sImagoPartOam_RightWingIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sImagoPartOam_RightWingIdle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sImagoPartOam_RightWingIdle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sImagoPartOam_RightWingIdle_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sImagoPartOam_RightWingIdle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sImagoPartOam_RightWingDying[5] = {
    [0] = {
        .pFrame = sImagoPartOam_RightWingIdle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sImagoPartOam_RightWingIdle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sImagoPartOam_RightWingIdle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = {
        .pFrame = sImagoPartOam_RightWingIdle_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sImagoPartOam_Core[9] = {
    [0] = {
        .pFrame = sImagoPartOam_Core_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sImagoPartOam_Core_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sImagoPartOam_Core_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sImagoPartOam_Core_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sImagoPartOam_Core_Frame0,
        .timer = CONVERT_SECONDS(11.f / 30)
    },
    [5] = {
        .pFrame = sImagoPartOam_Core_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sImagoPartOam_Core_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = {
        .pFrame = sImagoPartOam_Core_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sImagoOam_Flying[9] = {
    [0] = {
        .pFrame = sImagoOam_Flying_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sImagoOam_Flying_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sImagoOam_Flying_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sImagoOam_Flying_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sImagoOam_Flying_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sImagoOam_Flying_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sImagoOam_Flying_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sImagoOam_Flying_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sImagoOam_ShootingNeedles[11] = {
    [0] = {
        .pFrame = sImagoOam_Flying_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sImagoOam_Flying_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sImagoOam_ShootingNeedles_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sImagoOam_ShootingNeedles_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sImagoOam_ShootingNeedles_Frame4,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [5] = {
        .pFrame = sImagoOam_ShootingNeedles_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sImagoOam_ShootingNeedles_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sImagoOam_Flying_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sImagoOam_Flying_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sImagoOam_ShootingNeedles_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sImagoOam_RechargingNeedles[4] = {
    [0] = {
        .pFrame = sImagoOam_RechargingNeedles_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sImagoOam_RechargingNeedles_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sImagoOam_RechargingNeedles_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sImagoDamagedStingerOam[2] = {
    [0] = {
        .pFrame = sImagoDamagedStingerOam_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sImagoNeedleOam[2] = {
    [0] = {
        .pFrame = sImagoNeedleOam_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sImagoDamagedStingerOam_Unused[9] = {
    [0] = {
        .pFrame = sImagoOam_Flying_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sImagoOam_Flying_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sImagoOam_Flying_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sImagoOam_Flying_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sImagoOam_Flying_Frame0,
        .timer = CONVERT_SECONDS(11.f / 30)
    },
    [5] = {
        .pFrame = sImagoOam_Flying_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sImagoOam_Flying_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = {
        .pFrame = sImagoOam_Flying_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sImagoEggOam_Breaking[10] = {
    [0] = {
        .pFrame = sImagoEggOam_Standing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sImagoEggOam_Breaking_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sImagoEggOam_Breaking_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sImagoEggOam_Breaking_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sImagoEggOam_Breaking_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sImagoEggOam_Breaking_Frame5,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sImagoEggOam_Breaking_Frame6,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [7] = {
        .pFrame = sImagoEggOam_Breaking_Frame7,
        .timer = CONVERT_SECONDS(7.f / 30)
    },
    [8] = {
        .pFrame = sImagoEggOam_Breaking_Frame8,
        .timer = UCHAR_MAX
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sImagoEggOam_Standing[2] = {
    [0] = {
        .pFrame = sImagoEggOam_Standing_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
