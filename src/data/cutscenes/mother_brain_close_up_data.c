#include "data/cutscenes/mother_brain_close_up_data.h"
#include "cutscenes/mother_brain_close_up.h"
#include "gba.h"
#include "macros.h"

const u16 sTourianEscapeOam_375d10_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-112, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 384, 15, 0),
    OAM_ENTRY(-48, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 392, 15, 0),
    OAM_ENTRY(16, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 400, 15, 0),
    OAM_ENTRY(80, -64, OAM_DIMS_32x64, OAM_NO_FLIP, 408, 15, 0),
    OAM_ENTRY(-48, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 648, 15, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 656, 15, 0),
    OAM_ENTRY(80, 0, OAM_DIMS_32x64, OAM_NO_FLIP, 664, 15, 0),
    OAM_ENTRY(-112, 64, OAM_DIMS_64x32, OAM_NO_FLIP, 896, 15, 0),
    OAM_ENTRY(-48, 64, OAM_DIMS_64x32, OAM_NO_FLIP, 904, 15, 0),
    OAM_ENTRY(16, 64, OAM_DIMS_64x32, OAM_NO_FLIP, 912, 15, 0),
    OAM_ENTRY(80, 64, OAM_DIMS_32x32, OAM_NO_FLIP, 920, 15, 0),
    OAM_ENTRY(-112, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 640, 15, 0),
};

static const struct FrameData sTourianEscapeOam_375d10[2] = {
    [0] = {
        .pFrame = sTourianEscapeOam_375d10_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct CutscenePageData sMotherBrainCloseUpPageData[5] = {
    [0] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1F,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    },
    [1] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1E,
        .priority = 2,
        .bg = DCNT_BG2,
        .screenSize = 0
    },
    [2] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1F,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    },
    [3] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1D,
        .priority = 0,
        .bg = DCNT_BG0,
        .screenSize = 0
    },
    [4] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1C,
        .priority = 1,
        .bg = DCNT_BG1,
        .screenSize = 0
    }
};

const struct CutsceneScreenShakeInfo sMotherBrainCloseUpScreenShakeInfo = {
    .type = 1,
    .maxDelay = 4,
    .set = 0
};

const struct OamArray sMotherBrainCloseUpCutsceneOam[MOTHER_BRAIN_CLOSE_UP_OAM_ID_END] = {
    [0] = {
        .pOam = sMotherBrainCloseUpOam_Bubble,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [MOTHER_BRAIN_CLOSE_UP_OAM_ID_BUBBLE] = {
        .pOam = sMotherBrainCloseUpOam_Bubble,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MOTHER_BRAIN_CLOSE_UP_OAM_ID_UNUSED_EYE] = {
        .pOam = sMotherBrainCloseUpOam_EyeOpening,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MOTHER_BRAIN_CLOSE_UP_OAM_ID_EYE_OPENING] = {
        .pOam = sMotherBrainCloseUpOam_EyeOpening,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [MOTHER_BRAIN_CLOSE_UP_OAM_ID_ELEVATOR_ANIMATION] = {
        .pOam = sMotherBrainCloseUpOam_ElevatorAnimation,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [MOTHER_BRAIN_CLOSE_UP_OAM_ID_EYE_OPENED] = {
        .pOam = sMotherBrainCloseUpOam_EyeOpened,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MOTHER_BRAIN_CLOSE_UP_OAM_ID_EYE_FOCUSING] = {
        .pOam = sMotherBrainCloseUpOam_EyeOpened,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
};

static const u16 sMotherBrainCloseUpOam_EyeOpening_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 272, 0, 0),
};

static const u16 sMotherBrainCloseUpOam_EyeOpening_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 264, 0, 0),
};

static const u16 sMotherBrainCloseUpOam_EyeOpening_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 256, 0, 0),
};

static const u16 sMotherBrainCloseUpOam_EyeOpening_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 16, 0, 0),
};

static const u16 sMotherBrainCloseUpOam_EyeOpening_Frame8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 8, 0, 0),
};

static const u16 sMotherBrainCloseUpOam_EyeOpening_Frame9[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 0, 0, 0),
};

static const u16 sMotherBrainCloseUpOam_Unused_375db4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 576, 1, 0),
};

static const u16 sMotherBrainCloseUpOam_Unused_375dbc[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 578, 1, 0),
};

static const u16 sMotherBrainCloseUpOam_Bubble_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 1, 0),
    OAM_ENTRY(-4, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 514, 1, 0),
    OAM_ENTRY(-1, 17, OAM_DIMS_8x8, OAM_NO_FLIP, 515, 1, 0),
    OAM_ENTRY(-3, 27, OAM_DIMS_8x8, OAM_NO_FLIP, 516, 1, 0),
};

static const u16 sMotherBrainCloseUpOam_Bubble_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 1, 0),
    OAM_ENTRY(-8, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 514, 1, 0),
    OAM_ENTRY(2, 17, OAM_DIMS_8x8, OAM_NO_FLIP, 515, 1, 0),
    OAM_ENTRY(-4, 27, OAM_DIMS_8x8, OAM_NO_FLIP, 516, 1, 0),
};

static const u16 sMotherBrainCloseUpOam_Bubble_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-5, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 1, 0),
    OAM_ENTRY(-6, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 514, 1, 0),
    OAM_ENTRY(1, 17, OAM_DIMS_8x8, OAM_NO_FLIP, 515, 1, 0),
    OAM_ENTRY(-3, 27, OAM_DIMS_8x8, OAM_NO_FLIP, 516, 1, 0),
};

static const u16 sMotherBrainCloseUpOam_Bubble_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 1, 0),
    OAM_ENTRY(-3, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 514, 1, 0),
    OAM_ENTRY(-2, 17, OAM_DIMS_8x8, OAM_NO_FLIP, 515, 1, 0),
    OAM_ENTRY(-1, 27, OAM_DIMS_8x8, OAM_NO_FLIP, 516, 1, 0),
};

static const u16 sMotherBrainCloseUpOam_Bubble_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 1, 0),
    OAM_ENTRY(0, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 514, 1, 0),
    OAM_ENTRY(-4, 17, OAM_DIMS_8x8, OAM_NO_FLIP, 515, 1, 0),
    OAM_ENTRY(-3, 27, OAM_DIMS_8x8, OAM_NO_FLIP, 516, 1, 0),
};

const struct FrameData sMotherBrainCloseUpOam_EyeOpening[11] = {
    [0] = {
        .pFrame = sMotherBrainCloseUpOam_EyeOpening_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sMotherBrainCloseUpOam_EyeOpening_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sMotherBrainCloseUpOam_EyeOpening_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sMotherBrainCloseUpOam_EyeOpening_Frame3,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = {
        .pFrame = sMotherBrainCloseUpOam_EyeOpening_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sMotherBrainCloseUpOam_EyeOpening_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sMotherBrainCloseUpOam_EyeOpening_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sMotherBrainCloseUpOam_EyeOpening_Frame3,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [8] = {
        .pFrame = sMotherBrainCloseUpOam_EyeOpening_Frame8,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [9] = {
        .pFrame = sMotherBrainCloseUpOam_EyeOpening_Frame9,
        .timer = CONVERT_SECONDS(1.0f)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotherBrainCloseUpOam_Bubble[6] = {
    [0] = {
        .pFrame = sMotherBrainCloseUpOam_Bubble_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sMotherBrainCloseUpOam_Bubble_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sMotherBrainCloseUpOam_Bubble_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sMotherBrainCloseUpOam_Bubble_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sMotherBrainCloseUpOam_Bubble_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = FRAME_DATA_TERMINATOR
};

static const u16 sMotherBrainCloseUpOam_EyeOpened_Frame0[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-72, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 0, 0, 0),
    OAM_ENTRY(-72, -8, OAM_DIMS_64x64, OAM_NO_FLIP, 256, 0, 0),
    OAM_ENTRY(-8, -72, OAM_DIMS_8x32, OAM_NO_FLIP, 8, 0, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 136, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 264, 0, 0),
    OAM_ENTRY(-8, 24, OAM_DIMS_8x32, OAM_NO_FLIP, 392, 0, 0),
    OAM_ENTRY(-48, 56, OAM_DIMS_32x16, OAM_NO_FLIP, 515, 0, 0),
    OAM_ENTRY(-16, 56, OAM_DIMS_16x16, OAM_NO_FLIP, 519, 0, 0),
    OAM_ENTRY(8, -72, OAM_DIMS_64x64, OAM_X_FLIP, 0, 0, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_64x64, OAM_X_FLIP, 256, 0, 0),
    OAM_ENTRY(0, -72, OAM_DIMS_8x32, OAM_X_FLIP, 8, 0, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_8x32, OAM_X_FLIP, 136, 0, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x32, OAM_X_FLIP, 264, 0, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_8x32, OAM_X_FLIP, 392, 0, 0),
    OAM_ENTRY(16, 56, OAM_DIMS_32x16, OAM_X_FLIP, 515, 0, 0),
    OAM_ENTRY(0, 56, OAM_DIMS_16x16, OAM_X_FLIP, 519, 0, 0),
};

static const u16 sMotherBrainCloseUpOam_EyeOpened_Frame1[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-72, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 9, 0, 0),
    OAM_ENTRY(-72, -8, OAM_DIMS_64x64, OAM_NO_FLIP, 265, 0, 0),
    OAM_ENTRY(-8, -72, OAM_DIMS_8x32, OAM_NO_FLIP, 17, 0, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 145, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 273, 0, 0),
    OAM_ENTRY(-8, 24, OAM_DIMS_8x32, OAM_NO_FLIP, 401, 0, 0),
    OAM_ENTRY(-48, 56, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 0, 0),
    OAM_ENTRY(-16, 56, OAM_DIMS_16x16, OAM_NO_FLIP, 528, 0, 0),
    OAM_ENTRY(8, -72, OAM_DIMS_64x64, OAM_X_FLIP, 9, 0, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_64x64, OAM_X_FLIP, 265, 0, 0),
    OAM_ENTRY(0, -72, OAM_DIMS_8x32, OAM_X_FLIP, 17, 0, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_8x32, OAM_X_FLIP, 145, 0, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x32, OAM_X_FLIP, 273, 0, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_8x32, OAM_X_FLIP, 401, 0, 0),
    OAM_ENTRY(16, 56, OAM_DIMS_32x16, OAM_X_FLIP, 524, 0, 0),
    OAM_ENTRY(0, 56, OAM_DIMS_16x16, OAM_X_FLIP, 528, 0, 0),
};

static const u16 sMotherBrainCloseUpOam_EyeOpened_Frame2[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-72, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 18, 0, 0),
    OAM_ENTRY(-72, -8, OAM_DIMS_64x64, OAM_NO_FLIP, 274, 0, 0),
    OAM_ENTRY(-48, 56, OAM_DIMS_32x16, OAM_NO_FLIP, 533, 0, 0),
    OAM_ENTRY(-16, 56, OAM_DIMS_16x16, OAM_NO_FLIP, 537, 0, 0),
    OAM_ENTRY(-8, -72, OAM_DIMS_8x32, OAM_NO_FLIP, 26, 0, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 154, 0, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 282, 0, 0),
    OAM_ENTRY(-8, 24, OAM_DIMS_8x32, OAM_NO_FLIP, 410, 0, 0),
    OAM_ENTRY(8, -72, OAM_DIMS_64x64, OAM_X_FLIP, 18, 0, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_64x64, OAM_X_FLIP, 274, 0, 0),
    OAM_ENTRY(16, 56, OAM_DIMS_32x16, OAM_X_FLIP, 533, 0, 0),
    OAM_ENTRY(0, 56, OAM_DIMS_16x16, OAM_X_FLIP, 537, 0, 0),
    OAM_ENTRY(0, -72, OAM_DIMS_8x32, OAM_X_FLIP, 26, 0, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_8x32, OAM_X_FLIP, 154, 0, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x32, OAM_X_FLIP, 282, 0, 0),
    OAM_ENTRY(0, 24, OAM_DIMS_8x32, OAM_X_FLIP, 410, 0, 0),
};

static const u16 sMotherBrainCloseUpOam_ElevatorAnimation_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY_MODE(8, 16, OAM_DIMS_64x32, OAM_XY_FLIP, 576, 1, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-8, 32, OAM_DIMS_16x16, OAM_Y_FLIP, 584, 1, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-72, 16, OAM_DIMS_64x32, OAM_Y_FLIP, 576, 1, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
};

static const u16 sMotherBrainCloseUpOam_ElevatorAnimation_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY_MODE(-80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 704, 1, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 708, 1, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 712, 1, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(48, -8, OAM_DIMS_32x16, OAM_X_FLIP, 704, 1, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(16, -8, OAM_DIMS_32x16, OAM_X_FLIP, 708, 1, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(0, -8, OAM_DIMS_16x16, OAM_X_FLIP, 712, 1, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
};

static const u16 sMotherBrainCloseUpOam_ElevatorAnimation_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY_MODE(8, -48, OAM_DIMS_64x32, OAM_X_FLIP, 576, 1, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 584, 1, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-72, -48, OAM_DIMS_64x32, OAM_NO_FLIP, 576, 1, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
};

const struct FrameData sMotherBrainCloseUpOam_EyeOpened[4] = {
    [0] = {
        .pFrame = sMotherBrainCloseUpOam_EyeOpened_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sMotherBrainCloseUpOam_EyeOpened_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sMotherBrainCloseUpOam_EyeOpened_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotherBrainCloseUpOam_ElevatorAnimation[4] = {
    [0] = {
        .pFrame = sMotherBrainCloseUpOam_ElevatorAnimation_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sMotherBrainCloseUpOam_ElevatorAnimation_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sMotherBrainCloseUpOam_ElevatorAnimation_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const u16 sMotherBrainCloseUpPal[6 * 16] = INCBIN_U16("data/cutscenes/MotherBrainCloseUp/Palette.pal");
const u16 sMotherBrainCloseUpBackgroundPal[5 * 16] = INCBIN_U16("data/cutscenes/MotherBrainCloseUp/Background.pal");
const u16 sMotherBrainCloseUpSamusPal[5 * 16] = INCBIN_U16("data/cutscenes/MotherBrainCloseUp/Samus.pal");
const u16 sMotherBrainCloseUpSamusVariaPal[5 * 16] = INCBIN_U16("data/cutscenes/MotherBrainCloseUp/SamusVaria.pal");
const u16 sMotherBrainCloseUpEyePal[2 * 16] = INCBIN_U16("data/cutscenes/MotherBrainCloseUp/Eye.pal");
const u16 sMotherBrainCloseUpBigEyePal[2 * 16] = INCBIN_U16("data/cutscenes/MotherBrainCloseUp/BigEye.pal");

const u32 sMotherBrainCloseUpMotherBrainGfx[2722] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/MotherBrain.gfx.lz");
const u32 sMotherBrainCloseUpBackgroundGfx[2422] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/Background.gfx.lz");
const u32 sMotherBrainCloseUpSamusGfx[2999] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/Samus.gfx.lz");
const u32 sMotherBrainCloseUpEyeGfx[1134] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/Eye.gfx.lz");
const u32 sMotherBrainCloseUpBigEyeGfx[2309] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/BigEye.gfx.lz");

const u32 sMotherBrainCloseUpMotherBrainTileTable[369] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/MotherBrain.tt");
const u32 sMotherBrainCloseUpBackgroundTileTable[369] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/Background.tt");
const u32 sMotherBrainCloseUpSamusTileTable[368] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/Samus.tt");
const u32 sMotherBrainCloseUpGlassTileTable[67] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/Glass.tt");

const u32 sMotherBrainCloseUpTankViewGfx[3944] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/TankView.gfx.lz");
const u32 sMotherBrainCloseUpTankViewTileTable[368] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/TankView.tt");
const u16 sMotherBrainCloseUpTankViewPal[8 * 16] = INCBIN_U16("data/cutscenes/MotherBrainCloseUp/TankView.pal");
