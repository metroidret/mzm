#include "data/color_fading_data.h"
#include "color_fading.h"
#include "macros.h"

const struct ColorFadingData sColorFadingData[COLOR_FADING_END] = {
    [0] = {
        .isWhite = FALSE,
        .pUpdateFunction = NULL,
        .firstColorSet = 0,
        .pProcessFunction = NULL,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_EMPTY
    },
    [COLOR_FADING_FLASH] = {
        .isWhite = TRUE,
        .pUpdateFunction = ColorFadingUpdate_Default,
        .firstColorSet = 0,
        .pProcessFunction = ColorFadingProcess_Default,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_2
    },
    [COLOR_FADING_CANCEL] = {
        .isWhite = FALSE,
        .pUpdateFunction = ColorFadingUpdate_Default,
        .firstColorSet = 0,
        .pProcessFunction = ColorFadingProcess_Default,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_2
    },
    [COLOR_FADING_WHITE] = {
        .isWhite = TRUE,
        .pUpdateFunction = ColorFadingUpdate_DoorTransition,
        .firstColorSet = 1,
        .pProcessFunction = ColorFadingProcess_DoorTransition,
        .secondColorSet = 1,
        .bgColorMask = 0xFFFD,
        .objColorMask = 0xFFC7,
        .fadeFunction = COLOR_FADING_FUNCTION_1
    },
    [COLOR_FADING_DOOR_TRANSITION] = {
        .isWhite = FALSE,
        .pUpdateFunction = ColorFadingUpdate_DoorTransition,
        .firstColorSet = 1,
        .pProcessFunction = ColorFadingProcess_DoorTransition,
        .secondColorSet = 1,
        .bgColorMask = 0xFFFD,
        .objColorMask = 0xFFC7,
        .fadeFunction = COLOR_FADING_FUNCTION_1
    },
    [COLOR_FADING_FLASH2] = {
        .isWhite = TRUE,
        .pUpdateFunction = ColorFadingUpdate_Default,
        .firstColorSet = 0,
        .pProcessFunction = ColorFadingProcess_Default,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = 0xFFC7,
        .fadeFunction = COLOR_FADING_FUNCTION_1
    },
    [COLOR_FADING_NO_TRANSITION] = {
        .isWhite = FALSE,
        .pUpdateFunction = ColorFadingUpdate_Default,
        .firstColorSet = 0,
        .pProcessFunction = ColorFadingProcess_Default,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = 0xFFC7,
        .fadeFunction = COLOR_FADING_FUNCTION_1
    },
    [COLOR_FADING_FLASH_NO_TRANSITION] = {
        .isWhite = TRUE,
        .pUpdateFunction = ColorFadingUpdate_Default,
        .firstColorSet = 4,
        .pProcessFunction = ColorFadingProcess_Default,
        .secondColorSet = 4,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_2
    },
    [COLOR_FADING_NO_TRANSITION_HUD_HIDE] = {
        .isWhite = FALSE,
        .pUpdateFunction = ColorFadingUpdate_Default,
        .firstColorSet = 4,
        .pProcessFunction = ColorFadingProcess_Default,
        .secondColorSet = 4,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_2
    },
    [COLOR_FADING_SLOW_WHITE] = {
        .isWhite = TRUE,
        .pUpdateFunction = ColorFadingUpdate_Default,
        .firstColorSet = 3,
        .pProcessFunction = ColorFadingProcess_Default,
        .secondColorSet = 3,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_2
    },
    [COLOR_FADING_SLOW_BLACK] = {
        .isWhite = FALSE,
        .pUpdateFunction = ColorFadingUpdate_Default,
        .firstColorSet = 3,
        .pProcessFunction = ColorFadingProcess_Default,
        .secondColorSet = 3,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_2
    },
    [COLOR_FADING_AFTER_ENTER_MOTHER_SHIP] = {
        .isWhite = FALSE,
        .pUpdateFunction = ColorFadingUpdate_Default,
        .firstColorSet = 0,
        .pProcessFunction = ColorFadingProcess_Default,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_1
    },
    [COLOR_FADING_ESCAPE_FAILED] = {
        .isWhite = TRUE,
        .pUpdateFunction = NULL,
        .firstColorSet = 0,
        .pProcessFunction = ColorFadingProcess_EscapeFailed,
        .secondColorSet = 3,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_2
    },
    [COLOR_FADING_DEMO_ENDING_AUTO] = {
        .isWhite = FALSE,
        .pUpdateFunction = NULL,
        .firstColorSet = 0,
        .pProcessFunction = ColorFadingProcess_BeforeDemoEnding,
        .secondColorSet = 2,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_2
    },
    [COLOR_FADING_DEMO_ENDING_WITH_INPUT] = {
        .isWhite = FALSE,
        .pUpdateFunction = NULL,
        .firstColorSet = 0,
        .pProcessFunction = ColorFadingProcess_BeforeDemoEnding,
        .secondColorSet = 2,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_2
    },
    [COLOR_FADING_CHOZODIA_ESCAPE] = {
        .isWhite = FALSE,
        .pUpdateFunction = NULL,
        .firstColorSet = 0,
        .pProcessFunction = ColorFadingProcess_ChozodiaEscape,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_2
    },
    [COLOR_FADING_TOURIAN_ESCAPE] = {
        .isWhite = TRUE,
        .pUpdateFunction = NULL,
        .firstColorSet = 0,
        .pProcessFunction = ColorFadingProcess_TourianEscape,
        .secondColorSet = 4,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_2
    },
    [COLOR_FADING_GETTING_FULLY_POWERED] = {
        .isWhite = TRUE,
        .pUpdateFunction = NULL,
        .firstColorSet = 0,
        .pProcessFunction = ColorFadingProcess_GettingFullyPowered,
        .secondColorSet = 3,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_2
    },
    [COLOR_FADING_RIDLEY_SPAWN] = {
        .isWhite = FALSE,
        .pUpdateFunction = NULL,
        .firstColorSet = 0,
        .pProcessFunction = ColorFadingProcess_BeforeRidleySpawn,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_2
    },
    [COLOR_FADING_STATUE_CUTSCENE] = {
        .isWhite = FALSE,
        .pUpdateFunction = NULL,
        .firstColorSet = 0,
        .pProcessFunction = ColorFadingProcess_StatueOpening,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_2
    },
    [COLOR_FADING_INTRO_TEXT] = {
        .isWhite = FALSE,
        .pUpdateFunction = NULL,
        .firstColorSet = 0,
        .pProcessFunction = ColorFadingProcess_BeforeIntroText,
        .secondColorSet = 4,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_2
    },
    [COLOR_FADING_LANDING_SHIP] = {
        .isWhite = FALSE,
        .pUpdateFunction = ColorFadingProcess_BeforeLandingShip,
        .firstColorSet = 0,
        .pProcessFunction = NULL,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_2
    },
    [COLOR_FADING_SAMUS_IN_BLUE_SHIP] = {
        .isWhite = FALSE,
        .pUpdateFunction = NULL,
        .firstColorSet = 0,
        .pProcessFunction = ColorFadingProcess_BeforeBlueShip,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = USHORT_MAX,
        .fadeFunction = COLOR_FADING_FUNCTION_2
    },
    [COLOR_FADING_TO_WHITE] = {
        .isWhite = TRUE,
        .pUpdateFunction = NULL,
        .firstColorSet = 0,
        .pProcessFunction = NULL,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = 0xFFFC,
        .fadeFunction = COLOR_FADING_FUNCTION_3
    },
    [COLOR_FADING_TO_BLACK] = {
        .isWhite = FALSE,
        .pUpdateFunction = NULL,
        .firstColorSet = 0,
        .pProcessFunction = NULL,
        .secondColorSet = 0,
        .bgColorMask = USHORT_MAX,
        .objColorMask = 0xFFFC,
        .fadeFunction = COLOR_FADING_FUNCTION_3
    },
};

static const u8 sColorFading_345f58[8] = {
    3, 7, 11, 15, 19, 23, 27, 32
};

static const u8 sColorFading_345f60[16] = {
    2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32
};

static const u8 sColorFading_345f70[32] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
    18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32
};

static const u8 sColorFading_345f90[60] = {
    1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6,
    6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10, 11, 11, 12,
    12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 19, 20, 21,
    22, 23, 24, 26, 28, 30, 32
};

static const u8 sColorFading_345fcc[1] = {
    32
};

const struct ColorFadingColorInfo sColorFadingColorInfo[COLOR_FADING_SPEED_END] = {
    [COLOR_FADING_SPEED_FASTER] = {
        .colorArray = sColorFading_345f58,
        .size = ARRAY_SIZE(sColorFading_345f58)
    },
    [COLOR_FADING_SPEED_FAST] = {
        .colorArray = sColorFading_345f60,
        .size = ARRAY_SIZE(sColorFading_345f60)
    },
    [COLOR_FADING_SPEED_NORMAL] = {
        .colorArray = sColorFading_345f70,
        .size = ARRAY_SIZE(sColorFading_345f70)
    },
    [COLOR_FADING_SPEED_SLOW] = {
        .colorArray = sColorFading_345f90,
        .size = ARRAY_SIZE(sColorFading_345f90)
    },
    [COLOR_FADING_SPEED_INSTANT] = {
        .colorArray = sColorFading_345fcc,
        .size = ARRAY_SIZE(sColorFading_345fcc)
    }
};
