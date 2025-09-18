#include "data/sprites/enemy_drop.h"
#include "macros.h"

static const u16 sEnemyDropOam_SmallEnergy_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 387, 4, 0),
};

static const u16 sEnemyDropOam_SmallEnergy_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 419, 4, 0),
};

static const u16 sEnemyDropOam_SmallEnergy_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 388, 4, 0),
};

static const u16 sEnemyDropOam_SmallEnergy_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 420, 4, 0),
};

static const u16 sEnemyDropOam_LargeEnergy_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 448, 4, 0),
};

static const u16 sEnemyDropOam_LargeEnergy_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 450, 4, 0),
};

static const u16 sEnemyDropOam_LargeEnergy_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 452, 4, 0),
};

static const u16 sEnemyDropOam_LargeEnergy_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 454, 4, 0),
};

static const u16 sEnemyDropOam_Missile_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 389, 4, 0),
};

static const u16 sEnemyDropOam_Missile_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 400, 4, 0),
};

static const u16 sEnemyDropOam_SuperMissile_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 390, 4, 0),
};

static const u16 sEnemyDropOam_SuperMissile_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 401, 4, 0),
};

static const u16 sEnemyDropOam_PowerBomb_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 331, 4, 0),
};

static const u16 sEnemyDropOam_PowerBomb_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 364, 4, 0),
};

static const u16 sEnemyDropOam_MultipleLargeEnergySlot1_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-15, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 448, 4, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 448, 4, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 448, 4, 0),
};

static const u16 sEnemyDropOam_MultipleLargeEnergySlot1_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-15, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 450, 4, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 450, 4, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 450, 4, 0),
};

static const u16 sEnemyDropOam_MultipleLargeEnergySlot1_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-15, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 452, 4, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 452, 4, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 452, 4, 0),
};

static const u16 sEnemyDropOam_MultipleLargeEnergySlot1_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-15, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 454, 4, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 454, 4, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 454, 4, 0),
};

static const u16 sEnemyDropOam_MultipleLargeEnergySlot3_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 448, 4, 0),
    OAM_ENTRY(-15, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 448, 4, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 448, 4, 0),
};

static const u16 sEnemyDropOam_MultipleLargeEnergySlot3_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 450, 4, 0),
    OAM_ENTRY(-15, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 450, 4, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 450, 4, 0),
};

static const u16 sEnemyDropOam_MultipleLargeEnergySlot3_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 452, 4, 0),
    OAM_ENTRY(-15, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 452, 4, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 452, 4, 0),
};

static const u16 sEnemyDropOam_MultipleLargeEnergySlot3_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 454, 4, 0),
    OAM_ENTRY(-15, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 454, 4, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 454, 4, 0),
};

static const u16 sEnemyDropOam_MultipleLargeEnergySlot2_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 448, 4, 0),
    OAM_ENTRY(-13, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 448, 4, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 448, 4, 0),
};

static const u16 sEnemyDropOam_MultipleLargeEnergySlot2_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 450, 4, 0),
    OAM_ENTRY(-13, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 450, 4, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 450, 4, 0),
};

static const u16 sEnemyDropOam_MultipleLargeEnergySlot2_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 452, 4, 0),
    OAM_ENTRY(-13, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 452, 4, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 452, 4, 0),
};

static const u16 sEnemyDropOam_MultipleLargeEnergySlot2_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 454, 4, 0),
    OAM_ENTRY(-13, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 454, 4, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 454, 4, 0),
};

const struct FrameData sEnemyDropOam_SmallEnergy[5] = {
    [0] = {
        .pFrame = sEnemyDropOam_SmallEnergy_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sEnemyDropOam_SmallEnergy_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sEnemyDropOam_SmallEnergy_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sEnemyDropOam_SmallEnergy_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnemyDropOam_LargeEnergy[5] = {
    [0] = {
        .pFrame = sEnemyDropOam_LargeEnergy_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sEnemyDropOam_LargeEnergy_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sEnemyDropOam_LargeEnergy_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sEnemyDropOam_LargeEnergy_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnemyDropOam_Missile[3] = {
    [0] = {
        .pFrame = sEnemyDropOam_Missile_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sEnemyDropOam_Missile_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnemyDropOam_SuperMissile[3] = {
    [0] = {
        .pFrame = sEnemyDropOam_SuperMissile_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sEnemyDropOam_SuperMissile_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnemyDropOam_PowerBomb[3] = {
    [0] = {
        .pFrame = sEnemyDropOam_PowerBomb_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sEnemyDropOam_PowerBomb_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnemyDropOam_MultipleLargeEnergySlot1[5] = {
    [0] = {
        .pFrame = sEnemyDropOam_MultipleLargeEnergySlot1_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sEnemyDropOam_MultipleLargeEnergySlot1_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sEnemyDropOam_MultipleLargeEnergySlot1_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sEnemyDropOam_MultipleLargeEnergySlot1_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnemyDropOam_MultipleLargeEnergySlot3[5] = {
    [0] = {
        .pFrame = sEnemyDropOam_MultipleLargeEnergySlot3_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sEnemyDropOam_MultipleLargeEnergySlot3_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sEnemyDropOam_MultipleLargeEnergySlot3_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sEnemyDropOam_MultipleLargeEnergySlot3_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sEnemyDropOam_MultipleLargeEnergySlot2[5] = {
    [0] = {
        .pFrame = sEnemyDropOam_MultipleLargeEnergySlot2_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sEnemyDropOam_MultipleLargeEnergySlot2_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sEnemyDropOam_MultipleLargeEnergySlot2_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sEnemyDropOam_MultipleLargeEnergySlot2_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};
