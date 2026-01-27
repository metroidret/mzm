#include "data/cutscenes/before_ruins_test_data.h"
#include "gba.h"
#include "macros.h"

const struct CutscenePageData sBeforeRuinsTestPageData[9] = {
    [0] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1E,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0x4000
    },
    [1] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1C,
        .priority = 2,
        .bg = DCNT_BG2,
        .screenSize = 0x4000
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
        .tiletablePage = 0x1E,
        .priority = 2,
        .bg = DCNT_BG2,
        .screenSize = 0
    },
    [4] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1C,
        .priority = 1,
        .bg = DCNT_BG1,
        .screenSize = 0x4000
    },
    [5] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = 0,
        .bg = DCNT_BG0,
        .screenSize = 0
    },
    [6] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1E,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    },
    [7] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1C,
        .priority = 1,
        .bg = DCNT_BG1,
        .screenSize = 0
    },
    [8] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1D,
        .priority = 2,
        .bg = DCNT_BG2,
        .screenSize = 0
    }
};

const u16 sBeforeRuinsTestChozoWallSidesPal[10 * 16] = INCBIN_U16("data/cutscenes/before_ruins_test/chozo_wall_sides.pal");
const u16 sBeforeRuinsTestChozoWallPal[8 * 16] = INCBIN_U16("data/cutscenes/before_ruins_test/chozo_wall.pal");
const u16 sBeforeRuinsTestSamusCloseUpPal[16 * 16] = INCBIN_U16("data/cutscenes/before_ruins_test/samus_close_up.pal");

const u32 sBeforeRuinsTestLeftSideOfChozoWallGfx[4049] = INCBIN_U32("data/cutscenes/before_ruins_test/left_side_chozo_wall.gfx.lz");
const u32 sBeforeRuinsTestRightSideOfChozoWallGfx[3987] = INCBIN_U32("data/cutscenes/before_ruins_test/right_side_chozo_wall.gfx.lz");
const u32 sBeforeRuinsTestChozoWallBackgroundGfx[6446] = INCBIN_U32("data/cutscenes/before_ruins_test/chozo_wall_background.gfx.lz");
const u32 sBeforeRuinsTestYoungSamusAndGreyVoiceGfx[1792] = INCBIN_U32("data/cutscenes/before_ruins_test/young_samus_and_grey_voice.gfx.lz");
const u32 sBeforeRuinsTestYoungSamusAndGreyVoiceCloseUpGfx[3818] = INCBIN_U32("data/cutscenes/before_ruins_test/young_samus_and_grey_voice_close_up.gfx.lz");
const u32 sBeforeRuinsTestYoungSamusCloseUpGfx[2979] = INCBIN_U32("data/cutscenes/before_ruins_test/young_samus_close_up.gfx.lz");
const u32 sBeforeRuinsTestSamusCloseUpGfx[5285] = INCBIN_U32("data/cutscenes/before_ruins_test/samus_close_up.gfx.lz");

const u32 sBeforeRuinsTestLeftSideOfChozoWallTileTable[368] = INCBIN_U32("data/cutscenes/before_ruins_test/left_side_chozo_wall.tt");
const u32 sBeforeRuinsTestRightSideOfChozoWallTileTable[369] = INCBIN_U32("data/cutscenes/before_ruins_test/right_side_chozo_wall.tt");
const u32 sBeforeRuinsTestChozoWallBackgroundTileTable[551] = INCBIN_U32("data/cutscenes/before_ruins_test/chozo_wall_background.tt");
const u32 sBeforeRuinsTestYoungSamusAndGreyVoiceTileTable[185] = INCBIN_U32("data/cutscenes/before_ruins_test/young_samus_and_grey_voice.tt");
const u32 sBeforeRuinsTestYoungSamusAndGreyVoiceCloseUpTileTable[452] = INCBIN_U32("data/cutscenes/before_ruins_test/young_samus_and_grey_voice_close_up.tt");
const u32 sBeforeRuinsTestYoungSamusCloseUpTileTable[368] = INCBIN_U32("data/cutscenes/before_ruins_test/young_samus_close_up.tt");
const u32 sBeforeRuinsTestSamusCloseUpEyesClosedTileTable[251] = INCBIN_U32("data/cutscenes/before_ruins_test/samus_close_up_eyes_closed.tt");
const u32 sBeforeRuinsTestSamusCloseUpEyesOpenedTileTable[232] = INCBIN_U32("data/cutscenes/before_ruins_test/samus_close_up_eyes_opened.tt");
const u32 sBeforeRuinsTestSamusCloseUpOutlineTileTable[333] = INCBIN_U32("data/cutscenes/before_ruins_test/samus_close_up_outline.tt");
