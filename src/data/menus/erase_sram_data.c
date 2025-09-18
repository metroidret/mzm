#include "data/menus/erase_sram_data.h"
#include "macros.h"
#include "constants/audio.h"

const u16 sEraseSramMenuObjectsPal[7 * 16] = INCBIN_U16("data/menus/EraseSram/Objects.pal");
const u16 sEraseSramMenuBackgroundPal[15 * 16 - 1] = INCBIN_U16("data/menus/EraseSram/Background.pal");

static const u16 sEraseSramOam_ConfirmWindowNoSelected_Frame0[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-72, 24, OAM_DIMS_32x16, OAM_NO_FLIP, 152, 2, 0),
    OAM_ENTRY(-40, 24, OAM_DIMS_32x16, OAM_NO_FLIP, 156, 2, 0),
    OAM_ENTRY(16, 24, OAM_DIMS_32x16, OAM_NO_FLIP, 216, 5, 0),
    OAM_ENTRY(48, 24, OAM_DIMS_32x16, OAM_NO_FLIP, 220, 5, 0),
    OAM_ENTRY(-96, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 128, 2, 0),
    OAM_ENTRY(-32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 136, 2, 0),
    OAM_ENTRY(32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 144, 2, 0),
    OAM_ENTRY(-112, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 256, 3, 0),
    OAM_ENTRY(-112, 32, OAM_DIMS_64x32, OAM_NO_FLIP, 512, 3, 0),
    OAM_ENTRY(48, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 260, 3, 0),
    OAM_ENTRY(48, 32, OAM_DIMS_64x32, OAM_NO_FLIP, 516, 3, 0),
    OAM_ENTRY(-48, -32, OAM_DIMS_32x64, OAM_NO_FLIP, 260, 3, 0),
    OAM_ENTRY(-48, 32, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 3, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x64, OAM_NO_FLIP, 260, 3, 0),
    OAM_ENTRY(-16, 32, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 3, 0),
    OAM_ENTRY(16, -32, OAM_DIMS_32x64, OAM_NO_FLIP, 260, 3, 0),
    OAM_ENTRY(16, 32, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 3, 0),
};

static const u16 sEraseSramOam_ConfirmWindowYesSelected_Frame0[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-72, 24, OAM_DIMS_32x16, OAM_NO_FLIP, 152, 5, 0),
    OAM_ENTRY(-40, 24, OAM_DIMS_32x16, OAM_NO_FLIP, 156, 5, 0),
    OAM_ENTRY(16, 24, OAM_DIMS_32x16, OAM_NO_FLIP, 216, 2, 0),
    OAM_ENTRY(48, 24, OAM_DIMS_32x16, OAM_NO_FLIP, 220, 2, 0),
    OAM_ENTRY(-96, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 128, 2, 0),
    OAM_ENTRY(-32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 136, 2, 0),
    OAM_ENTRY(32, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 144, 2, 0),
    OAM_ENTRY(-112, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 256, 3, 0),
    OAM_ENTRY(-112, 32, OAM_DIMS_64x32, OAM_NO_FLIP, 512, 3, 0),
    OAM_ENTRY(48, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 260, 3, 0),
    OAM_ENTRY(48, 32, OAM_DIMS_64x32, OAM_NO_FLIP, 516, 3, 0),
    OAM_ENTRY(-48, -32, OAM_DIMS_32x64, OAM_NO_FLIP, 260, 3, 0),
    OAM_ENTRY(-48, 32, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 3, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x64, OAM_NO_FLIP, 260, 3, 0),
    OAM_ENTRY(-16, 32, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 3, 0),
    OAM_ENTRY(16, -32, OAM_DIMS_32x64, OAM_NO_FLIP, 260, 3, 0),
    OAM_ENTRY(16, 32, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 3, 0),
};

static const u16 sEraseSramOam_CursorIdle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 269, 4, 0),
};

static const u16 sEraseSramOam_CursorIdle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(9, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 269, 4, 0),
};

static const u16 sEraseSramOam_CursorIdle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(10, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 269, 4, 0),
};

static const u16 sEraseSramOam_CursorSelecting_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 270, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_4118d6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(9, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 270, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_4118de[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(10, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 270, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_4118e6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(12, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 349, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_4118ee[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(13, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 350, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_4118f6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(10, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 351, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_4118fe[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 284, 4, 0),
};

static const u16 sEraseSramOam_QuestionWindowNoSelected_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-72, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 24, 2, 0),
    OAM_ENTRY(-40, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 28, 2, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 88, 5, 0),
    OAM_ENTRY(48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 92, 5, 0),
};

static const u16 sEraseSramOam_QuestionWindowYesSelected_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-72, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 24, 5, 0),
    OAM_ENTRY(-40, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 28, 5, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 88, 2, 0),
    OAM_ENTRY(48, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 92, 2, 0),
};

static const u16 sEraseSramOam_UnusedFrame_41193a[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 401, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 403, 4, 0),
    OAM_ENTRY(10, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 285, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_41194e[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 404, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 406, 4, 0),
    OAM_ENTRY(11, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 285, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_411962[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 407, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 409, 4, 0),
    OAM_ENTRY(12, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 286, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_411976[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 410, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 412, 4, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 286, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_41198a[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 282, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 284, 4, 0),
    OAM_ENTRY(10, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 285, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_41199e[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 282, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 284, 4, 0),
    OAM_ENTRY(11, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 285, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_4119b2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 282, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 284, 4, 0),
    OAM_ENTRY(12, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 286, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_4119c6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 282, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 284, 4, 0),
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 286, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_4119da[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 282, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 284, 4, 0),
    OAM_ENTRY(10, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 285, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_4119ee[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 282, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 284, 4, 0),
    OAM_ENTRY(11, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 285, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_411a02[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 282, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 284, 4, 0),
    OAM_ENTRY(12, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 286, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_411a16[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 286, 4, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 282, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 284, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_411a2a[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(10, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 285, 4, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 282, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 284, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_411a3e[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(11, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 285, 4, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 343, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 345, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_411a52[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(12, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 286, 4, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 279, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 281, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_411a66[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 286, 4, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 279, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 281, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_411a7a[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 279, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 281, 4, 0),
    OAM_ENTRY(10, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 285, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_411a8e[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 279, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 281, 4, 0),
    OAM_ENTRY(11, -17, OAM_DIMS_8x16, OAM_NO_FLIP, 285, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_411aa2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 343, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 345, 4, 0),
    OAM_ENTRY(12, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 286, 4, 0),
};

static const u16 sEraseSramOam_UnusedFrame_411ab6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(11, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 286, 4, 0),
    OAM_ENTRY(-12, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 282, 4, 0),
    OAM_ENTRY(4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 284, 4, 0),
};

static const struct FrameData sEraseSramOam_CursorIdle[4] = {
    [0] = {
        .pFrame = sEraseSramOam_CursorIdle_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sEraseSramOam_CursorIdle_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sEraseSramOam_CursorIdle_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [3] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sEraseSramOam_CursorSelecting[7] = {
    [0] = {
        .pFrame = sEraseSramOam_CursorIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sEraseSramOam_CursorSelecting_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sEraseSramOam_CursorIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sEraseSramOam_CursorSelecting_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sEraseSramOam_CursorIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sEraseSramOam_CursorSelecting_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sEraseSramOam_QuestionWindowNoSelected[2] = {
    [0] = {
        .pFrame = sEraseSramOam_QuestionWindowNoSelected_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sEraseSramOam_QuestionWindowYesSelected[2] = {
    [0] = {
        .pFrame = sEraseSramOam_QuestionWindowYesSelected_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sEraseSramOam_ConfirmWindowNoSelected[2] = {
    [0] = {
        .pFrame = sEraseSramOam_ConfirmWindowNoSelected_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sEraseSramOam_ConfirmWindowYesSelected[2] = {
    [0] = {
        .pFrame = sEraseSramOam_ConfirmWindowYesSelected_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const u32 sEraseSramMenuObjectsGfx[477] = INCBIN_U32("data/menus/EraseSram/Objects.gfx.lz");
const u32 sEraseSramMenuFirstBoxGfx[118] = INCBIN_U32("data/menus/EraseSram/FirstBox.gfx.lz");

const u32 sEraseSramMenuConfirmJapaneseGfx[245] = INCBIN_U32("data/menus/EraseSram/ConfirmJapanese.gfx.lz");
const u32 sEraseSramMenuConfirmEnglishGfx[191] = INCBIN_U32("data/menus/EraseSram/ConfirmEnglish.gfx.lz");
const u32 sEraseSramMenuConfirmFrenchGfx[209] = INCBIN_U32("data/menus/EraseSram/ConfirmFrench.gfx.lz");
const u32 sEraseSramMenuConfirmGermanGfx[222] = INCBIN_U32("data/menus/EraseSram/ConfirmGerman.gfx.lz");
const u32 sEraseSramMenuConfirmItalianGfx[201] = INCBIN_U32("data/menus/EraseSram/ConfirmItalian.gfx.lz");
const u32 sEraseSramMenuConfirmSpanishGfx[204] = INCBIN_U32("data/menus/EraseSram/ConfirmSpanish.gfx.lz");

const u32 sEraseSramMenuQuestionJapaneseGfx[245] = INCBIN_U32("data/menus/EraseSram/QuestionJapanese.gfx.lz");
const u32 sEraseSramMenuQuestionEnglishGfx[185] = INCBIN_U32("data/menus/EraseSram/QuestionEnglish.gfx.lz");
const u32 sEraseSramMenuQuestionFrenchGfx[187] = INCBIN_U32("data/menus/EraseSram/QuestionFrench.gfx.lz");
const u32 sEraseSramMenuQuestionGermanGfx[205] = INCBIN_U32("data/menus/EraseSram/QuestionGerman.gfx.lz");
const u32 sEraseSramMenuQuestionItalianGfx[221] = INCBIN_U32("data/menus/EraseSram/QuestionItalian.gfx.lz");
const u32 sEraseSramMenuQuestionSpanishGfx[208] = INCBIN_U32("data/menus/EraseSram/QuestionSpanish.gfx.lz");

const u32 sEraseSramMenuBoxTileTable[137] = INCBIN_U32("data/menus/EraseSram/Box.tt");
const u32 sEraseSramMenuBackgroundTileTable[368] = INCBIN_U32("data/menus/EraseSram/Background.tt");

const u8 sEraseSramQuestionWindowNoSelectedOamId = ERASE_SRAM_OAM_ID_QUESTION_WINDOW_NO_SELECTED;
const u8 sEraseSramQuestionWindowYesSelectedOamId = ERASE_SRAM_OAM_ID_QUESTION_WINDOW_YES_SELECTED;
const u8 sEraseSramConfirmWindowNoSelectedOamId = ERASE_SRAM_OAM_ID_CONFIRM_WINDOW_NO_SELECTED;
const u8 sEraseSramConfirmWindowYesSelectedOamId = ERASE_SRAM_OAM_ID_CONFIRM_WINDOW_YES_SELECTED;

const u16 sEraseSramMenuSoundsID[ERASE_SRAM_SOUND_END] = {
    [0] = 0,
    [ERASE_SRAM_SOUND_CONFIRM] = SOUND_ACCEPT_CONFIRM_MENU,
    [ERASE_SRAM_SOUND_SELECT_YES] = SOUND_YES_NO_CURSOR_SELECTING_YES,
    [ERASE_SRAM_SOUND_REFUSE] = SOUND_REFUSE_MENU,
    [ERASE_SRAM_SOUND_CURSOR] = SOUND_SUB_MENU_CURSOR
};

// (x,y) coordinates
const u16 sEraseSramMenuCursorPosition[2][2] = {
    [0] = {
        BLOCK_SIZE * 8, BLOCK_SIZE * 5 + HALF_BLOCK_SIZE
    },
    [1] = {
        BLOCK_SIZE * 8 - 8, BLOCK_SIZE * 5 + HALF_BLOCK_SIZE + 8
    }
};

// (x,y) coordinates
const u16 sEraseSramMenuCursorPositionOffset[ERASE_SRAM_OPTION_END][2] = {
    [ERASE_SRAM_OPTION_QUESTION_NO] = {
        -(BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE), -EIGHTH_BLOCK_SIZE
    },
    [ERASE_SRAM_OPTION_QUESTION_YES] = {
        QUARTER_BLOCK_SIZE, -EIGHTH_BLOCK_SIZE
    },
    [ERASE_SRAM_OPTION_CONFIRM_NO] = {
        -(BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE), BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [ERASE_SRAM_OPTION_CONFIRM_YES] = {
        QUARTER_BLOCK_SIZE, BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    }
};

const struct OamArray sEraseSramMenuOam[ERASE_SRAM_OAM_ID_END] = {
    [0] = {
        .pOam = sEraseSramOam_CursorIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [ERASE_SRAM_OAM_ID_CURSOR_IDLE] = {
        .pOam = sEraseSramOam_CursorIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [ERASE_SRAM_OAM_ID_CURSOR_SELECTING] = {
        .pOam = sEraseSramOam_CursorSelecting,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [ERASE_SRAM_OAM_ID_QUESTION_WINDOW_NO_SELECTED] = {
        .pOam = sEraseSramOam_QuestionWindowNoSelected,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [ERASE_SRAM_OAM_ID_QUESTION_WINDOW_YES_SELECTED] = {
        .pOam = sEraseSramOam_QuestionWindowYesSelected,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [ERASE_SRAM_OAM_ID_CONFIRM_WINDOW_NO_SELECTED] = {
        .pOam = sEraseSramOam_ConfirmWindowNoSelected,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [ERASE_SRAM_OAM_ID_CONFIRM_WINDOW_YES_SELECTED] = {
        .pOam = sEraseSramOam_ConfirmWindowYesSelected,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
};
