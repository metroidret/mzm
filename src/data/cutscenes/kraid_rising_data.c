#include "data/cutscenes/kraid_rising_data.h"
#include "cutscenes/kraid_rising.h"
#include "gba.h"
#include "macros.h"

const struct CutscenePageData sKraidRisingPagesData[4] = {
    {
        .graphicsPage = 2,
        .tiletablePage = 0x1E,
        .priority = BGCNT_HIGH_MID_PRIORITY,
        .bg = DCNT_BG1,
        .screenSize = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT
    },
    {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = BGCNT_HIGH_MID_PRIORITY,
        .bg = DCNT_BG1,
        .screenSize = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT
    },
    {
        .graphicsPage = 0,
        .tiletablePage = 0xF,
        .priority = BGCNT_LOW_MID_PRIORITY,
        .bg = DCNT_BG2,
        .screenSize = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT
    },
    {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = BGCNT_LOW_PRIORITY,
        .bg = DCNT_BG3,
        .screenSize = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT
    }
};

const struct CutsceneScreenShakeInfo sKraidRisingScreenShakeData = {
    .type = 1,
    .maxDelay = 4,
    .set = 0
};

const struct CutsceneScrollingInfo sKraidRisingScrollingInfo = {
    .direction = 1,
    .length = BLOCK_SIZE + QUARTER_BLOCK_SIZE,
    .speed = 4,
    .maxDelay = 8
};

const struct OamArray sKraidRisingCutsceneOam[KRAID_RISING_OAM_ID_COUNT] = {
    [KRAID_RISING_OAM_ID_NONE] = {
        .pOam = sKraidRisingOam_Samus,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [KRAID_RISING_OAM_ID_SAMUS] = {
        .pOam = sKraidRisingOam_Samus,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [KRAID_RISING_OAM_ID_DEBRIS] = {
        .pOam = sKraidRisingOam_Debris,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [KRAID_RISING_OAM_ID_SMALL_PUFF] = {
        .pOam = sKraidRisingOam_SmallPuff,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [KRAID_RISING_OAM_ID_BIG_PUFF] = {
        .pOam = sKraidRisingOam_BigPuff,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    }
};

const u16 sKraidRisingOam_Samus_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -48, OAM_DIMS_64x64, OAM_NO_FLIP, 0x0, 0, 0)
};

const u16 sKraidRisingOam_Samus_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -49, OAM_DIMS_64x64, OAM_NO_FLIP, 0x0, 0, 0)
};

const u16 sKraidRisingOam_Debris_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8, 1, 0)
};

const u16 sKraidRisingOam_Debris_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x9, 1, 0)
};

const u16 sKraidRisingOam_Debris_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa, 1, 0)
};

const u16 sKraidRisingOam_Debris_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xb, 1, 0)
};

const u16 sKraidRisingOam_SmallPuff_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x28, 1, 0)
};

const u16 sKraidRisingOam_SmallPuff_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2a, 1, 0)
};

const u16 sKraidRisingOam_SmallPuff_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2c, 1, 0)
};

const u16 sKraidRisingOam_SmallPuff_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2e, 1, 0)
};

const u16 sKraidRisingOam_BigPuff_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x68, 1, 0)
};

const u16 sKraidRisingOam_BigPuff_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x6c, 1, 0)
};

const u16 sKraidRisingOam_BigPuff_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x70, 1, 0)
};

const u16 sKraidRisingOam_BigPuff_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x74, 1, 0)
};

const struct FrameData sKraidRisingOam_Samus[3] = {
    [0] = {
        .pFrame = sKraidRisingOam_Samus_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sKraidRisingOam_Samus_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKraidRisingOam_Debris[5] = {
    [0] = {
        .pFrame = sKraidRisingOam_Debris_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sKraidRisingOam_Debris_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sKraidRisingOam_Debris_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sKraidRisingOam_Debris_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKraidRisingOam_SmallPuff[5] = {
    [0] = {
        .pFrame = sKraidRisingOam_SmallPuff_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sKraidRisingOam_SmallPuff_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sKraidRisingOam_SmallPuff_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sKraidRisingOam_SmallPuff_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKraidRisingOam_BigPuff[5] = {
    [0] = {
        .pFrame = sKraidRisingOam_BigPuff_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sKraidRisingOam_BigPuff_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sKraidRisingOam_BigPuff_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sKraidRisingOam_BigPuff_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const u16 sKraidRisingCloseUpPal[5 * 16] = INCBIN_U16("data/cutscenes/kraid_rising/close_up.pal");
const u16 sKraidRisingSamusPal[1 * 16] = INCBIN_U16("data/cutscenes/kraid_rising/samus.pal");
const u16 sKraidRisingParticlesPal[1 * 16] = INCBIN_U16("data/cutscenes/kraid_rising/particles.pal");
const u16 sKraidRisingSamusVariaPal[1 * 16] = INCBIN_U16("data/cutscenes/kraid_rising/samus_varia.pal");
const u16 sKraidRisingRisingPal[7 * 16] = INCBIN_U16("data/cutscenes/kraid_rising/rising.pal");
const u32 sKraidRisingKraidCloseUpGfx[3087] = INCBIN_U32("data/cutscenes/kraid_rising/close_up.gfx.lz");
const u32 sKraidRisingOamGfx[753] = INCBIN_U32("data/cutscenes/kraid_rising/oam.gfx.lz");
const u32 sKraidRisingKraidRisingGfx[1609] = INCBIN_U32("data/cutscenes/kraid_rising/kraid_rising.gfx.lz");
const u32 sKraidRisingCaveBackgroundGfx[1327] = INCBIN_U32("data/cutscenes/kraid_rising/cave_background.gfx.lz");
const u32 sKraidRisingKraidCloseUpEyesClosedTileTable[368] = INCBIN_U32("data/cutscenes/kraid_rising/kraid_close_up_eyes_closed.tt");
const u32 sKraidRisingKraidCloseUpEyesBarelyOpenedTileTable[368] = INCBIN_U32("data/cutscenes/kraid_rising/kraid_close_up_eyes_barely_opened.tt");
const u32 sKraidRisingKraidCloseUpEyesALittleOpenedTileTable[368] = INCBIN_U32("data/cutscenes/kraid_rising/kraid_close_up_eyes_a_little_opened.tt");
const u32 sKraidRisingKraidCloseUpEyesOpenedTileTable[368] = INCBIN_U32("data/cutscenes/kraid_rising/kraid_close_up_eyes_opened.tt");
const u32 sKraidRisingKraidRisingTileTable[295] = INCBIN_U32("data/cutscenes/kraid_rising/kraid_rising.tt");
const u32 sKraidRisingCaveBackgroundTileTable[370] = INCBIN_U32("data/cutscenes/kraid_rising/cave_background.tt");
