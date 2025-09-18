#include "data/cutscenes/getting_fully_powered_suit_data.h"
#include "cutscenes/getting_fully_powered_suit.h"
#include "gba.h"
#include "macros.h"

const struct CutscenePageData sGettingFullyPoweredSuitPageData[3] = {
    [0] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1E,
        .priority = 2,
        .bg = DCNT_BG2,
        .screenSize = 0x8000
    },
    [1] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1C,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0x8000
    },
    [2] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1F,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    }
};

const struct CutscenePaletteData sGettingFullyPoweredSuitPaletteData = {
    .active = TRUE,
    .timer = 0,
    .paletteRow = 0,
    .maxTimer = 2
};

const u8 sGettingFullyPoweredSuitRingPaletteRows[7] = {
    0, 1, 2, 3, 4, 5, 6
};

const u16 sGettingFullyPoweredSuitRingSparklesPositions[OAM_RING_SPARKLES_AMOUNT][2] = {
    [0] = {
        -(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE + 8), 0x18
    },
    [1] = {
        -(BLOCK_SIZE + HALF_BLOCK_SIZE + 8), HALF_BLOCK_SIZE + 8
    },
    [2] = {
        BLOCK_SIZE * 3 + 8, 0x18
    },
    [3] = {
        BLOCK_SIZE + QUARTER_BLOCK_SIZE, HALF_BLOCK_SIZE + 12
    },
    [4] = {
        BLOCK_SIZE * 4 + HALF_BLOCK_SIZE -8, -QUARTER_BLOCK_SIZE
    },
    [5] = {
        -(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE), -20
    }
};

const u16 sGettingFullyPoweredSuitUpSparklesXPositions[6] = {
    BLOCK_SIZE * 6 + HALF_BLOCK_SIZE, BLOCK_SIZE * 10 + 8, BLOCK_SIZE * 5,
    BLOCK_SIZE * 12 + QUARTER_BLOCK_SIZE, BLOCK_SIZE * 3, 0
};

const struct OamArray sGettingFullyPoweredSuitCutsceneOam[GETTING_FULLY_POWERED_SUIT_OAM_ID_END] = {
    [0] = {
        .pOam = sGettingFullyPoweredSuitOam_SparkleGoingUp,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [GETTING_FULLY_POWERED_SUIT_OAM_ID_SPARKLE_GOING_UP] = {
        .pOam = sGettingFullyPoweredSuitOam_SparkleGoingUp,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [GETTING_FULLY_POWERED_SUIT_OAM_ID_SPARKLE_AROUND_RING1] = {
        .pOam = sGettingFullyPoweredSuitOam_SparkleAroundRing1,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [GETTING_FULLY_POWERED_SUIT_OAM_ID_SPARKLE_AROUND_RING2] = {
        .pOam = sGettingFullyPoweredSuitOam_SparkleAroundRing2,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [GETTING_FULLY_POWERED_SUIT_OAM_ID_RING_BOTTOM] = {
        .pOam = sGettingFullyPoweredSuitOam_RingBottom,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [GETTING_FULLY_POWERED_SUIT_OAM_ID_RING_TOP] = {
        .pOam = sGettingFullyPoweredSuitOam_RingTop,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
};

const u16 sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 128, 10, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 64, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0, 10, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 192, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 256, 10, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 64, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 320, 10, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0, 10, 0),
    OAM_ENTRY(-8, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 128, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 64, 10, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 192, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0, 10, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 256, 10, 0),
    OAM_ENTRY(-8, 3, OAM_DIMS_8x16, OAM_NO_FLIP, 320, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 82, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 2, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 6, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame9[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 10, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_RingBottom_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-80, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 195, 10, 0),
    OAM_ENTRY(-48, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 199, 10, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 203, 10, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 207, 10, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 211, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_RingBottom_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-72, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 324, 10, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 328, 10, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 332, 10, 0),
    OAM_ENTRY(24, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 336, 10, 0),
    OAM_ENTRY(56, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 340, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_RingTop_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-88, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 130, 10, 0),
    OAM_ENTRY(-56, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 134, 10, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 138, 10, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 142, 10, 0),
    OAM_ENTRY(40, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 146, 10, 0),
    OAM_ENTRY(72, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 150, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_RingTop_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-80, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 259, 10, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 263, 10, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 267, 10, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 271, 10, 0),
    OAM_ENTRY(48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 275, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 18, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 20, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 22, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 24, 10, 0),
};

const u16 sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 26, 10, 0),
};

const struct FrameData sGettingFullyPoweredSuitOam_SparkleGoingUp[7] = {
    [0] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleGoingUp_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGettingFullyPoweredSuitOam_SparkleAroundRing1[11] = {
    [0] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame9,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGettingFullyPoweredSuitOam_RingBottom[3] = {
    [0] = {
        .pFrame = sGettingFullyPoweredSuitOam_RingBottom_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGettingFullyPoweredSuitOam_RingBottom_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGettingFullyPoweredSuitOam_RingTop[3] = {
    [0] = {
        .pFrame = sGettingFullyPoweredSuitOam_RingTop_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGettingFullyPoweredSuitOam_RingTop_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGettingFullyPoweredSuitOam_SparkleAroundRing2[9] = {
    [0] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing1_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sGettingFullyPoweredSuitOam_SparkleAroundRing2_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};


const u16 sGettingFullyPoweredSuitPal[19 * 16] = INCBIN_U16("data/cutscenes/GettingFullyPoweredSuit/Palette.pal");
const u32 sGettingFullyPoweredSuitSamusGfx[2608] = INCBIN_U32("data/cutscenes/GettingFullyPoweredSuit/Samus.gfx.lz");
const u32 sGettingFullyPoweredSuitRingSparklesGfx[646] = INCBIN_U32("data/cutscenes/GettingFullyPoweredSuit/RingSparkles.gfx.lz");
const u32 sGettingFullyPoweredSuitSamusTileTable[387] = INCBIN_U32("data/cutscenes/GettingFullyPoweredSuit/Samus.tt");
const u8 sGettingFullyPoweredSuitBackgroundGfx[13872] = INCBIN_U8("data/cutscenes/GettingFullyPoweredSuit/Background.gfx.lz");
const u32 sGettingFullyPoweredSuitBackgroundTileTable[734] = INCBIN_U32("data/cutscenes/GettingFullyPoweredSuit/Background.tt");
const u16 sGettingFullyPoweredSuitRingPal[7 * 16] = INCBIN_U16("data/cutscenes/GettingFullyPoweredSuit/RingPalette.pal");
