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

const struct OamArray sRidleyLandingCutsceneOAM[RIDLEY_LANDING_OAM_ID_END] = {
    [0] = {
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
    [7] = {
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
    },
};

const u16 sRidleyLandingOAM_ShipInSpace_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-56, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 0, 8, 0),
    OAM_ENTRY(8, -40, OAM_DIMS_32x64, OAM_NO_FLIP, 8, 8, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 172, 8, 0),
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
    OAM_ENTRY(-128, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 512, 0, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 520, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 528, 0, 0),
    OAM_ENTRY(64, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 536, 0, 0),
};

const u16 sRidleyLandingOAM_ShipMiddlePart_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-128, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 256, 0, 0),
    OAM_ENTRY(-64, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 264, 0, 0),
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 272, 0, 0),
    OAM_ENTRY(64, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 280, 0, 0),
};

const u16 sRidleyLandingOAM_ShipTopPart_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-64, -128, OAM_DIMS_64x64, OAM_NO_FLIP, 8, 0, 0),
    OAM_ENTRY(0, -128, OAM_DIMS_64x64, OAM_NO_FLIP, 16, 0, 0),
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame0[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-80, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 864, 1, 0),
    OAM_ENTRY(-64, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 866, 1, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 928, 1, 0),
    OAM_ENTRY(-64, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 930, 1, 0),
    OAM_ENTRY(48, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 864, 1, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 866, 1, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 928, 1, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 930, 1, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 960, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 867, 1, 0),
    OAM_ENTRY(24, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 869, 1, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 931, 1, 0),
    OAM_ENTRY(24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 933, 1, 0),
    OAM_ENTRY(-56, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 867, 1, 0),
    OAM_ENTRY(-40, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 869, 1, 0),
    OAM_ENTRY(-56, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 931, 1, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 933, 1, 0),
    OAM_ENTRY(-88, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 832, 1, 0),
    OAM_ENTRY(40, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 966, 1, 0),
    OAM_ENTRY(-64, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 966, 1, 0),
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame1[OAM_DATA_SIZE(21)] = {
    21,
    OAM_ENTRY(-80, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 867, 1, 0),
    OAM_ENTRY(-64, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 869, 1, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 931, 1, 0),
    OAM_ENTRY(-64, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 933, 1, 0),
    OAM_ENTRY(-56, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 870, 1, 0),
    OAM_ENTRY(-40, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 872, 1, 0),
    OAM_ENTRY(-56, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 934, 1, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 936, 1, 0),
    OAM_ENTRY(48, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 867, 1, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 869, 1, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 931, 1, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 933, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 870, 1, 0),
    OAM_ENTRY(24, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 872, 1, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 934, 1, 0),
    OAM_ENTRY(24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 936, 1, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 962, 1, 0),
    OAM_ENTRY(-32, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 960, 1, 0),
    OAM_ENTRY(-88, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 833, 1, 0),
    OAM_ENTRY(72, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 960, 1, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 832, 1, 0),
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame2[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(-64, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 960, 1, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 864, 1, 0),
    OAM_ENTRY(16, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 866, 1, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 928, 1, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 930, 1, 0),
    OAM_ENTRY(-80, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 870, 1, 0),
    OAM_ENTRY(-64, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 872, 1, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 934, 1, 0),
    OAM_ENTRY(-64, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 936, 1, 0),
    OAM_ENTRY(-56, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 873, 1, 0),
    OAM_ENTRY(-40, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 875, 1, 0),
    OAM_ENTRY(-56, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 937, 1, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 939, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 873, 1, 0),
    OAM_ENTRY(24, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 875, 1, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 937, 1, 0),
    OAM_ENTRY(24, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 939, 1, 0),
    OAM_ENTRY(48, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 870, 1, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 872, 1, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 934, 1, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 936, 1, 0),
    OAM_ENTRY(-32, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 962, 1, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 833, 1, 0),
    OAM_ENTRY(-88, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 834, 1, 0),
    OAM_ENTRY(72, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 962, 1, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 964, 1, 0),
    OAM_ENTRY(40, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 960, 1, 0),
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame3[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-64, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 962, 1, 0),
    OAM_ENTRY(-80, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 873, 1, 0),
    OAM_ENTRY(-64, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 875, 1, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 937, 1, 0),
    OAM_ENTRY(-64, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 939, 1, 0),
    OAM_ENTRY(48, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 873, 1, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 875, 1, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 937, 1, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 939, 1, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 966, 1, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 834, 1, 0),
    OAM_ENTRY(-32, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 964, 1, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 867, 1, 0),
    OAM_ENTRY(16, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 869, 1, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 931, 1, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 933, 1, 0),
    OAM_ENTRY(-88, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 835, 1, 0),
    OAM_ENTRY(40, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 962, 1, 0),
    OAM_ENTRY(72, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 964, 1, 0),
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame4[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 835, 1, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 870, 1, 0),
    OAM_ENTRY(16, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 872, 1, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 934, 1, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 936, 1, 0),
    OAM_ENTRY(-32, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 966, 1, 0),
    OAM_ENTRY(72, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 966, 1, 0),
    OAM_ENTRY(-64, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 964, 1, 0),
    OAM_ENTRY(40, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 964, 1, 0),
};

const u16 sRidleyLandingOAM_SmokeParticles_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 835, 1, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 864, 1, 0),
    OAM_ENTRY(32, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 866, 1, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 928, 1, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 930, 1, 0),
    OAM_ENTRY(40, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 966, 1, 0),
    OAM_ENTRY(-64, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 966, 1, 0),
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
    OAM_ENTRY(-56, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 0, 0, 0),
    OAM_ENTRY(8, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 8, 0, 0),
};

const u16 sRidleyLandingOAM_Rocks_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-64, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 112, 1, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 120, 1, 0),
    OAM_ENTRY(32, -56, OAM_DIMS_32x16, OAM_NO_FLIP, 28, 1, 0),
    OAM_ENTRY(32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 92, 1, 0),
    OAM_ENTRY(-80, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 302, 1, 0),
};

const u16 sRidleyLandingOAM_Rocks_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(0, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 776, 1, 0),
    OAM_ENTRY(-80, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 708, 1, 0),
    OAM_ENTRY(32, -56, OAM_DIMS_32x16, OAM_NO_FLIP, 684, 1, 0),
    OAM_ENTRY(32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 748, 1, 0),
    OAM_ENTRY(-64, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 768, 1, 0),
};

const u16 sRidleyLandingOAM_Rocks_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(0, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 792, 1, 0),
    OAM_ENTRY(-64, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 784, 1, 0),
    OAM_ENTRY(-80, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 704, 1, 0),
    OAM_ENTRY(32, -56, OAM_DIMS_32x16, OAM_NO_FLIP, 700, 1, 0),
    OAM_ENTRY(32, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 764, 1, 0),
};

const u16 sRidleyLandingOAM_Rocks_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(0, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 440, 1, 0),
    OAM_ENTRY(-64, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 432, 1, 0),
    OAM_ENTRY(-80, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 622, 1, 0),
    OAM_ENTRY(32, -48, OAM_DIMS_32x16, OAM_NO_FLIP, 380, 1, 0),
    OAM_ENTRY(48, -56, OAM_DIMS_16x8, OAM_NO_FLIP, 30, 1, 0),
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



const u16 sCutscene_3a09d4_Pal[9 * 16] = INCBIN_U16("data/cutscenes/RidleyLanding/3a09d4.pal");
const u16 sCutsceneZebesPal[13 * 16] = INCBIN_U16("data/cutscenes/RidleyLanding/CutsceneZebes.pal");
const u16 sCutsceneMotherShipPal[5 * 16] = INCBIN_U16("data/cutscenes/RidleyLanding/CutsceneMotherShip.pal");
const u16 sRidleyLandingRidleyAndRocksPal[2 * 16] = INCBIN_U16("data/cutscenes/RidleyLanding/Objects.pal");
const u16 sRidleyLandingSkyBackgroundPal[5 * 16] = INCBIN_U16("data/cutscenes/RidleyLanding/SkyBackground.pal");

const u32 sRidleyLandingZebesBackgroundGfx[3167] = INCBIN_U32("data/cutscenes/RidleyLanding/ZebesBackground.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_1[38] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_1.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_2[59] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_2.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_3[65] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_3.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_4[88] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_4.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_5[90] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_5.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_6[97] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_6.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_7[75] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_7.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_8[40] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_8.gfx.lz");
const u32 sRidleyLandingMotherShipGfx_9[18] = INCBIN_U32("data/cutscenes/RidleyLanding/MotherShip_9.gfx.lz");
const u32 sCutsceneZebesMotherShipBackgroundGfx[5067] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneZebesMotherShipBackground.gfx.lz");
const u32 sCutsceneZebesGroundGfx[477] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneZebesGround.gfx.lz");
const u32 sCutsceneZebesRockyBackgroundGfx[1514] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneZebesRockyBackground.gfx.lz");
const u32 sCutsceneMotherShipEscapeShipParticlesGfx[2955] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneMotherShipEscapeShipParticles.gfx.lz");
const u32 sRidleyLandingRidleyAndRockShadowGfx[2788] = INCBIN_U32("data/cutscenes/RidleyLanding/RidleyAndRock.gfx.lz");
const u32 sRidleyLandingRidleyFlyingBackgroundGfx[2970] = INCBIN_U32("data/cutscenes/RidleyLanding/RidleyFlyingBackground.gfx.lz");
const u32 sRidleyLandingZebesBackgroundTileTable[545] = INCBIN_U32("data/cutscenes/RidleyLanding/ZebesBackground.tt");
const u32 sCutsceneZebesMotherShipBackgroundTileTable[640] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneZebesMotherShipBackground.tt");
const u32 sCutscene_3b5168_TileTable[261] = INCBIN_U32("data/cutscenes/RidleyLanding/3b5168.tt");
const u32 sCutsceneZebesGroundTileTable[111] = INCBIN_U32("data/cutscenes/RidleyLanding/CutsceneZebesGround.tt");
const u32 sRidleyLandingRidleyFlyingBackgroundTileTable[368] = INCBIN_U32("data/cutscenes/RidleyLanding/RidleyFlyingBackground.tt");