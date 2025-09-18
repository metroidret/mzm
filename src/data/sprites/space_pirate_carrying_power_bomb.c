#include "data/sprites/space_pirate_carrying_power_bomb.h"
#include "macros.h"

const u32 sFakePowerBombGfx[115] = INCBIN_U32("data/sprites/FakePowerBomb.gfx.lz");
const u16 sFakePowerBombPal[16] = INCBIN_U16("data/sprites/FakePowerBomb.pal");

static const u16 sFakePowerBombOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sFakePowerBombOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sFakePowerBombOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sFakePowerBombOam_Idle_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
};

const struct FrameData sFakePowerBombOam_Idle[5] = {
    [0] = {
        .pFrame = sFakePowerBombOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sFakePowerBombOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sFakePowerBombOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sFakePowerBombOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = FRAME_DATA_TERMINATOR
};
