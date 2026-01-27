#include "data/menus/title_screen_data.h"
#include "gba.h"
#include "macros.h"

const u16 sTitleScreenPal[15 * 16] = INCBIN_U16("data/menus/title_screen/palette.pal");
const u16 sTitleScreenPromptPal[5 * 16] = INCBIN_U16("data/menus/title_screen/prompt.pal");

#ifdef REGION_EU
const u16 sTitleScreenUnselectedMenuPal[1 * 16] = INCBIN_U16("data/menus/title_screen/unselected_menu.pal");
#endif // REGION_EU

static const u16 sTitleScreenOam_Comet_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 14, 0)
};

static const u16 sTitleScreenOam_Comet_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 14, 0)
};

static const u16 sTitleScreenOam_Comet_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 14, 0)
};

static const u16 sTitleScreenOam_CometFlying_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8, 14, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x26, 14, 0)
};

static const u16 sTitleScreenOam_SparkleIdle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa, 14, 0)
};

static const u16 sTitleScreenOam_SparkleIdle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc, 14, 0)
};

static const u16 sTitleScreenOam_SparkleIdle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xe, 14, 0)
};

static const u16 sTitleScreenOam_SparkleIdle_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x10, 14, 0)
};

static const u16 sTitleScreenOam_SparkleDisappearing_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa, 14, 0)
};

static const u16 sTitleScreenOam_SparkleDisappearing_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc, 14, 0)
};

static const u16 sTitleScreenOam_SparkleDisappearing_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xe, 14, 0)
};

static const u16 sTitleScreenOam_SparkleDisappearing_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x12, 14, 0)
};

static const u16 sTitleScreenOam_SparkleDisappearing_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x16, 14, 0)
};

static const struct FrameData sTitleScreenOam_Comet[4] = {
    [0] = {
        .pFrame = sTitleScreenOam_Comet_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTitleScreenOam_Comet_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sTitleScreenOam_Comet_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTitleScreenOam_CometFlying[2] = {
    [0] = {
        .pFrame = sTitleScreenOam_CometFlying_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTitleScreenOam_SparkleIdle[5] = {
    [0] = {
        .pFrame = sTitleScreenOam_SparkleIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTitleScreenOam_SparkleIdle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sTitleScreenOam_SparkleIdle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sTitleScreenOam_SparkleIdle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTitleScreenOam_SparkleDisappearing[6] = {
    [0] = {
        .pFrame = sTitleScreenOam_SparkleDisappearing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTitleScreenOam_SparkleDisappearing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sTitleScreenOam_SparkleDisappearing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sTitleScreenOam_SparkleDisappearing_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sTitleScreenOam_SparkleDisappearing_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const u32 sTitleScreenTitleGfx[1095] = INCBIN_U32("data/menus/title_screen/title.gfx.lz");
const u32 sTitleScreenSparklesGfx[256] = INCBIN_U32("data/menus/title_screen/sparkles.gfx.lz");
const u32 sTitleScreenSpaceBackgroundGfx[3203] = INCBIN_U32("data/menus/title_screen/space_background.gfx.lz");
const u32 sTitleScreenSpaceBackgroundDecorationGfx[797] = INCBIN_U32("data/menus/title_screen/space_background_decoration.gfx.lz");
const u32 sTitleScreenSpaceAndGroundBackgroundGfx[1920] = INCBIN_U32("data/menus/title_screen/space_and_ground_background.gfx.lz");

#ifdef REGION_EU
const u32 sTitleScreenEnglishMenuGfx_Top[85] = INCBIN_U32("data/menus/title_screen/english_menu_top.gfx.lz");
const u32 sTitleScreenEnglishMenuGfx_Bottom[72] = INCBIN_U32("data/menus/title_screen/english_menu_bottom.gfx.lz");
const u32 sTitleScreenGermanMenuGfx_Top[89] = INCBIN_U32("data/menus/title_screen/german_menu_top.gfx.lz");
const u32 sTitleScreenGermanMenuGfx_Bottom[75] = INCBIN_U32("data/menus/title_screen/german_menu_bottom.gfx.lz");
const u32 sTitleScreenFrenchMenuGfx_Top[63] = INCBIN_U32("data/menus/title_screen/french_menu_top.gfx.lz");
const u32 sTitleScreenFrenchMenuGfx_Bottom[55] = INCBIN_U32("data/menus/title_screen/french_menu_bottom.gfx.lz");
const u32 sTitleScreenItalianMenuGfx_Top[79] = INCBIN_U32("data/menus/title_screen/italian_menu_top.gfx.lz");
const u32 sTitleScreenItalianMenuGfx_Bottom[62] = INCBIN_U32("data/menus/title_screen/italian_menu_bottom.gfx.lz");
const u32 sTitleScreenSpanishMenuGfx_Top[64] = INCBIN_U32("data/menus/title_screen/spanish_menu_top.gfx.lz");
const u32 sTitleScreenSpanishMenuGfx_Bottom[45] = INCBIN_U32("data/menus/title_screen/spanish_menu_bottom.gfx.lz");
#endif // REGION_EU

const u32 sTitleScreenTitleTileTable[] = INCBIN_U32("data/menus/title_screen/title.tt");
const u32 sTitleScreenSpaceBackgroundTileTable[702] = INCBIN_U32("data/menus/title_screen/space_background.tt");

const u8 sTitleScreenRomInfoPosition[4] = {
    BLOCK_SIZE * 2 + 8, BLOCK_SIZE + QUARTER_BLOCK_SIZE, 'P', 'x'
};

#if defined(REGION_EU)
const u8 sTitleScreenRomInfoTime[12] = "01/14 14:30";
#elif defined(REGION_US_BETA)
const u8 sTitleScreenRomInfoTime[12] = "12/02 22:00";
#else // !(REGION_EU || REGION_US_BETA)
const u8 sTitleScreenRomInfoTime[12] = "12/04 22:00";
#endif

#ifndef REGION_EU
const u8 sTitleScreenRomInfoRegionUSA[4] = "USA";
const u8 sTitleScreenRomInfoRegionEUR[4] = "EUR";
const u8 sTitleScreenRomInfoRegionJPN[4] = "JPN";
#endif // !REGION_EU

const struct TitleScreenPageData sTitleScreenPageData[2] = {
    [0] = {
        .tiletablePage = 2,
        .graphicsPage = 3,
        .priority = 1,
        .screenSize = 0,
        .bg = DCNT_BG1,
        .tiletablePointer = sTitleScreenTitleTileTable
    },
    [1] = {
        .tiletablePage = 0,
        .graphicsPage = 1,
        .priority = 3,
        .screenSize = 0x8000,
        .bg = DCNT_BG3,
        .tiletablePointer = sTitleScreenSpaceBackgroundTileTable
    }
};

const struct MenuOamData sTitleScreenTopSparkleBaseOam = {
    .yPosition = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE,
    .xPosition = BLOCK_SIZE + QUARTER_BLOCK_SIZE,
    .unk_4 = 0,
    .unk_5 = 0,
    .unk_6 = 0,
    .unk_7 = 0,
    .animationDurationCounter = 0,
    .currentAnimationFrame = 0,
    .oamID = TITLE_SCREEN_OAM_ID_SPARKLE_IDLE,
    .priority = 0,
    .objMode = 0,
    .ended = FALSE,
    .notDrawn = FALSE,
    .exists = TRUE,
    .boundBackground = 0,
    .unk_E = 0 
};

const struct MenuOamData sTitleScreenBottomSparkleBaseOam = {
    .yPosition = BLOCK_SIZE * 5 - 8,
    .xPosition = BLOCK_SIZE * 14 + 8,
    .unk_4 = 0,
    .unk_5 = 0,
    .unk_6 = 0,
    .unk_7 = 0,
    .animationDurationCounter = 0,
    .currentAnimationFrame = 0,
    .oamID = TITLE_SCREEN_OAM_ID_SPARKLE_IDLE,
    .priority = 0,
    .objMode = 0,
    .ended = FALSE,
    .notDrawn = FALSE,
    .exists = TRUE,
    .boundBackground = 0,
    .unk_E = 0 
};

const struct OamArray sTitleScreenOam[TITLE_SCREEN_OAM_ID_COUNT] = {
    [TITLE_SCREEN_OAM_ID_NONE] = {
        .pOam = sTitleScreenOam_Comet,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [TITLE_SCREEN_OAM_ID_COMET_SPAWNING] = {
        .pOam = sTitleScreenOam_Comet,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [TITLE_SCREEN_OAM_ID_COMET_APPEARING] = {
        .pOam = sTitleScreenOam_Comet,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [TITLE_SCREEN_OAM_ID_COMET_FLYING] = {
        .pOam = sTitleScreenOam_CometFlying,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [TITLE_SCREEN_OAM_ID_SPARKLE_IDLE] = {
        .pOam = sTitleScreenOam_SparkleIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [TITLE_SCREEN_OAM_ID_SPARKLE_GROWING] = {
        .pOam = sTitleScreenOam_SparkleIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [TITLE_SCREEN_OAM_ID_SPARKLE_DISAPPEARING] = {
        .pOam = sTitleScreenOam_SparkleDisappearing,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    }
};
