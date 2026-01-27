#include "data/cutscenes/ridley_landing_data.h"
#include "cutscenes/ridley_landing.h"
#include "gba.h"
#include "macros.h"

const struct CutscenePageData sRidleyLandingPageData[5] = {
    [0] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1F,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    },
    [1] = {
        .graphicsPage = 0,
        .tiletablePage = 0x12,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0x8000
    },
    [2] = {
        .graphicsPage = 2,
        .tiletablePage = 0x14,
        .priority = 1,
        .bg = DCNT_BG1,
        .screenSize = 0
    },
    [3] = {
        .graphicsPage = 2,
        .tiletablePage = 0x15,
        .priority = 0,
        .bg = DCNT_BG0,
        .screenSize = 0
    },
    [4] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1F,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    }
};

const struct CutsceneScrollingInfo sRidleyLandingScrollingInfo[3] = {
    [0] = {
        .direction = 1,
        .length = 0x318,
        .speed = 2,
        .maxDelay = 0
    },
    [1] = {
        .direction = 1,
        .length = 0x178,
        .speed = 3,
        .maxDelay = 0
    },
    [2] = {
        .direction = 1,
        .length = 0x158,
        .speed = 4,
        .maxDelay = 0
    }
};


const struct FrameData sRidleyLandingOAM_ShipBottomPart[2] = {
    [0] = {
        .pFrame = sRidleyLandingOAM_ShipBottomPart_Frame0,
        .timer = CONVERT_SECONDS(2.f) + CONVERT_SECONDS(2.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyLandingOAM_ShipMiddlePart[2] = {
    [0] = {
        .pFrame = sRidleyLandingOAM_ShipMiddlePart_Frame0,
        .timer = CONVERT_SECONDS(2.f) + CONVERT_SECONDS(2.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyLandingOAM_ShipTopPart[2] = {
    [0] = {
        .pFrame = sRidleyLandingOAM_ShipTopPart_Frame0,
        .timer = CONVERT_SECONDS(2.f) + CONVERT_SECONDS(2.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyLandingOAM_Ridley[2] = {
    [0] = {
        .pFrame = sRidleyLandingOAM_Ridley_Frame0,
        .timer = CONVERT_SECONDS(2.f) + CONVERT_SECONDS(2.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct OamArray sRidleyLandingCutsceneOAM[RIDLEY_LANDING_OAM_ID_COUNT] = {
    [RIDLEY_LANDING_OAM_ID_NONE] = {
        .pOam = sRidleyLandingOAM_ShipInSpace,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [RIDLEY_LANDING_OAM_ID_MOTHER_SHIP_IN_SPACE] = {
        .pOam = sRidleyLandingOAM_ShipInSpace,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    }, 
    [RIDLEY_LANDING_OAM_ID_MOTHER_SHIP_BOTTOM_PART] = {
        .pOam = sRidleyLandingOAM_ShipBottomPart,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_LANDING_OAM_ID_MOTHER_SHIP_MIDDLE_PART] = {
        .pOam = sRidleyLandingOAM_ShipMiddlePart,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_LANDING_OAM_ID_MOTHER_SHIP_TOP_PART] = {
        .pOam = sRidleyLandingOAM_ShipTopPart,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_LANDING_OAM_ID_SMOKE_PARTICLES] = {
        .pOam = sRidleyLandingOAM_SmokeParticles,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [RIDLEY_LANDING_OAM_ID_SMOKE_PARTICLES_DISAPPEARING] = {
        .pOam = sRidleyLandingOAM_SmokeParticles,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [RIDLEY_LANDING_OAM_ID_7] = {
        .pOam = sRidleyLandingOAM_SmokeParticles,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [RIDLEY_LANDING_OAM_ID_RIDLEY] = {
        .pOam = sRidleyLandingOAM_Ridley,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_LANDING_OAM_ID_ROCKS] = {
        .pOam = sRidleyLandingOAM_Rocks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_LANDING_OAM_ID_ROCKS_AND_RIDLEY_SHADOW] = {
        .pOam = sRidleyLandingOAM_Rocks,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END
    }
};

const u16 sRidleyLandingOAM_ShipInSpace_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-56, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 0x0, 8, 0),
    OAM_ENTRY(8, -40, OAM_DIMS_32x64, OAM_NO_FLIP, 0x8, 8, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0xac, 8, 0)
};

const struct FrameData sRidleyLandingOAM_ShipInSpace[2] = {
    [0] = {
        .pFrame = sRidleyLandingOAM_ShipInSpace_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const u16 sRidleyLandingOAM_ShipBottomPart_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-128, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 0x200, 0, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 0x210, 0, 0),
    OAM_ENTRY(64, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 0x218, 0, 0)
};

const u16 sRidleyLandingOAM_ShipMiddlePart_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-128, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x100, 0, 0),
    OAM_ENTRY(-64, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x108, 0, 0),
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x110, 0, 0),
    OAM_ENTRY(64, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x118, 0, 0)
};

const u16 sRidleyLandingOAM_ShipTopPart_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-64, -128, OAM_DIMS_64x64, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(0, -128, OAM_DIMS_64x64, OAM_NO_FLIP, 0x10, 0, 0)
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame0[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-80, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x360, 1, 0),
    OAM_ENTRY(-64, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x362, 1, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 1, 0),
    OAM_ENTRY(-64, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a2, 1, 0),
    OAM_ENTRY(48, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x360, 1, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x362, 1, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 1, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a2, 1, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c0, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x363, 1, 0),
    OAM_ENTRY(24, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x365, 1, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a3, 1, 0),
    OAM_ENTRY(24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a5, 1, 0),
    OAM_ENTRY(-56, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x363, 1, 0),
    OAM_ENTRY(-40, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x365, 1, 0),
    OAM_ENTRY(-56, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a3, 1, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a5, 1, 0),
    OAM_ENTRY(-88, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x340, 1, 0),
    OAM_ENTRY(40, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c6, 1, 0),
    OAM_ENTRY(-64, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c6, 1, 0)
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame1[OAM_DATA_SIZE(21)] = {
    21,
    OAM_ENTRY(-80, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x363, 1, 0),
    OAM_ENTRY(-64, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x365, 1, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a3, 1, 0),
    OAM_ENTRY(-64, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a5, 1, 0),
    OAM_ENTRY(-56, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x366, 1, 0),
    OAM_ENTRY(-40, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x368, 1, 0),
    OAM_ENTRY(-56, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a6, 1, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a8, 1, 0),
    OAM_ENTRY(48, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x363, 1, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x365, 1, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a3, 1, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a5, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x366, 1, 0),
    OAM_ENTRY(24, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x368, 1, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a6, 1, 0),
    OAM_ENTRY(24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a8, 1, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 1, 0),
    OAM_ENTRY(-32, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c0, 1, 0),
    OAM_ENTRY(-88, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x341, 1, 0),
    OAM_ENTRY(72, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c0, 1, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x340, 1, 0)
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame2[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(-64, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c0, 1, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x360, 1, 0),
    OAM_ENTRY(16, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x362, 1, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 1, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a2, 1, 0),
    OAM_ENTRY(-80, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x366, 1, 0),
    OAM_ENTRY(-64, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x368, 1, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a6, 1, 0),
    OAM_ENTRY(-64, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a8, 1, 0),
    OAM_ENTRY(-56, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x369, 1, 0),
    OAM_ENTRY(-40, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x36b, 1, 0),
    OAM_ENTRY(-56, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a9, 1, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3ab, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x369, 1, 0),
    OAM_ENTRY(24, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x36b, 1, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a9, 1, 0),
    OAM_ENTRY(24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3ab, 1, 0),
    OAM_ENTRY(48, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x366, 1, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x368, 1, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a6, 1, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a8, 1, 0),
    OAM_ENTRY(-32, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 1, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x341, 1, 0),
    OAM_ENTRY(-88, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x342, 1, 0),
    OAM_ENTRY(72, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 1, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c4, 1, 0),
    OAM_ENTRY(40, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c0, 1, 0)
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame3[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-64, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 1, 0),
    OAM_ENTRY(-80, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x369, 1, 0),
    OAM_ENTRY(-64, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x36b, 1, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a9, 1, 0),
    OAM_ENTRY(-64, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3ab, 1, 0),
    OAM_ENTRY(48, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x369, 1, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x36b, 1, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a9, 1, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3ab, 1, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c6, 1, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x342, 1, 0),
    OAM_ENTRY(-32, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c4, 1, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x363, 1, 0),
    OAM_ENTRY(16, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x365, 1, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a3, 1, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a5, 1, 0),
    OAM_ENTRY(-88, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x343, 1, 0),
    OAM_ENTRY(40, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 1, 0),
    OAM_ENTRY(72, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c4, 1, 0)
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame4[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x343, 1, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x366, 1, 0),
    OAM_ENTRY(16, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x368, 1, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a6, 1, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a8, 1, 0),
    OAM_ENTRY(-32, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c6, 1, 0),
    OAM_ENTRY(72, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c6, 1, 0),
    OAM_ENTRY(-64, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c4, 1, 0),
    OAM_ENTRY(40, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c4, 1, 0)
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x343, 1, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x360, 1, 0),
    OAM_ENTRY(32, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x362, 1, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 1, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a2, 1, 0),
    OAM_ENTRY(40, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c6, 1, 0),
    OAM_ENTRY(-64, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c6, 1, 0)
};

const struct FrameData sRidleyLandingOAM_SmokeParticles[7] = {
    [0] = {
        .pFrame = sRidleyLandingOAM_SmokeParticles_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sRidleyLandingOAM_SmokeParticles_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sRidleyLandingOAM_SmokeParticles_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sRidleyLandingOAM_SmokeParticles_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sRidleyLandingOAM_SmokeParticles_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sRidleyLandingOAM_SmokeParticles_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const u16 sRidleyLandingOAM_Ridley_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-56, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(8, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 0x8, 0, 0)
};

const u16 sRidleyLandingOAM_Rocks_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-64, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 0x70, 1, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 0x78, 1, 0),
    OAM_ENTRY(32, -56, OAM_DIMS_32x16, OAM_NO_FLIP, 0x1c, 1, 0),
    OAM_ENTRY(32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 0x5c, 1, 0),
    OAM_ENTRY(-80, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x12e, 1, 0)
};

const u16 sRidleyLandingOAM_Rocks_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(0, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 0x308, 1, 0),
    OAM_ENTRY(-80, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c4, 1, 0),
    OAM_ENTRY(32, -56, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2ac, 1, 0),
    OAM_ENTRY(32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2ec, 1, 0),
    OAM_ENTRY(-64, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 0x300, 1, 0)
};

const u16 sRidleyLandingOAM_Rocks_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(0, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 0x318, 1, 0),
    OAM_ENTRY(-64, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 0x310, 1, 0),
    OAM_ENTRY(-80, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c0, 1, 0),
    OAM_ENTRY(32, -56, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2bc, 1, 0),
    OAM_ENTRY(32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2fc, 1, 0)
};

const u16 sRidleyLandingOAM_Rocks_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(0, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 0x1b8, 1, 0),
    OAM_ENTRY(-64, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 0x1b0, 1, 0),
    OAM_ENTRY(-80, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x26e, 1, 0),
    OAM_ENTRY(32, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x17c, 1, 0),
    OAM_ENTRY(48, -56, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1e, 1, 0)
};

const struct FrameData sRidleyLandingOAM_Rocks[5] = {
    [0] = {
        .pFrame = sRidleyLandingOAM_Rocks_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sRidleyLandingOAM_Rocks_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sRidleyLandingOAM_Rocks_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sRidleyLandingOAM_Rocks_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};



const u16 sCutscene_3a09d4_Pal[9 * 16] = INCBIN_U16("data/cutscenes/ridley_landing/3a09d4.pal");
const u16 sCutsceneZebesPal[13 * 16] = INCBIN_U16("data/cutscenes/ridley_landing/cutscene_zebes.pal");
const u16 sCutsceneMotherShipPal[5 * 16] = INCBIN_U16("data/cutscenes/ridley_landing/cutscene_mother_ship.pal");
const u16 sRidleyLandingRidleyAndRocksPal[2 * 16] = INCBIN_U16("data/cutscenes/ridley_landing/objects.pal");
const u16 sRidleyLandingSkyBackgroundPal[5 * 16] = INCBIN_U16("data/cutscenes/ridley_landing/sky_background.pal");

const u32 sRidleyLandingZebesBackgroundGfx[3167] = INCBIN_U32("data/cutscenes/ridley_landing/zebes_background.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_1[38] = INCBIN_U32("data/cutscenes/ridley_landing/mother_ship_1.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_2[59] = INCBIN_U32("data/cutscenes/ridley_landing/mother_ship_2.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_3[65] = INCBIN_U32("data/cutscenes/ridley_landing/mother_ship_3.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_4[88] = INCBIN_U32("data/cutscenes/ridley_landing/mother_ship_4.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_5[90] = INCBIN_U32("data/cutscenes/ridley_landing/mother_ship_5.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_6[97] = INCBIN_U32("data/cutscenes/ridley_landing/mother_ship_6.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_7[75] = INCBIN_U32("data/cutscenes/ridley_landing/mother_ship_7.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_8[40] = INCBIN_U32("data/cutscenes/ridley_landing/mother_ship_8.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_9[18] = INCBIN_U32("data/cutscenes/ridley_landing/mother_ship_9.gfx.lz");
const u32 sCutsceneZebesMotherShipBackgroundGfx[5067] = INCBIN_U32("data/cutscenes/ridley_landing/cutscene_zebes_mother_ship_background.gfx.lz");
const u32 sCutsceneZebesGroundGfx[477] = INCBIN_U32("data/cutscenes/ridley_landing/cutscene_zebes_ground.gfx.lz");
const u32 sCutsceneZebesRockyBackgroundGfx[1514] = INCBIN_U32("data/cutscenes/ridley_landing/cutscene_zebes_rocky_background.gfx.lz");
const u32 sCutsceneMotherShipEscapeShipParticlesGfx[2955] = INCBIN_U32("data/cutscenes/ridley_landing/cutscene_mother_ship_escape_ship_particles.gfx.lz");
const u32 sRidleyLandingRidleyAndRockShadowGfx[2788] = INCBIN_U32("data/cutscenes/ridley_landing/ridley_and_rock.gfx.lz");
const u32 sRidleyLandingRidleyFlyingBackgroundGfx[2970] = INCBIN_U32("data/cutscenes/ridley_landing/ridley_flying_background.gfx.lz");
const u32 sRidleyLandingZebesBackgroundTileTable[545] = INCBIN_U32("data/cutscenes/ridley_landing/zebes_background.tt");
const u32 sCutsceneZebesMotherShipBackgroundTileTable[640] = INCBIN_U32("data/cutscenes/ridley_landing/cutscene_zebes_mother_ship_background.tt");
const u32 sCutscene_3b5168_TileTable[261] = INCBIN_U32("data/cutscenes/ridley_landing/3b5168.tt");
const u32 sCutsceneZebesGroundTileTable[111] = INCBIN_U32("data/cutscenes/ridley_landing/cutscene_zebes_ground.tt");
const u32 sRidleyLandingRidleyFlyingBackgroundTileTable[368] = INCBIN_U32("data/cutscenes/ridley_landing/ridley_flying_background.tt");