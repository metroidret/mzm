#include "data/cutscenes/mecha_sees_samus_data.h"
#include "cutscenes/mecha_sees_samus.h"
#include "gba.h"
#include "macros.h"

const struct CutscenePageData sMechaRidleySeesSamusPagesData[1] = {
    [0] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = 0,
        .bg = DCNT_BG0,
        .screenSize = 0
    }
};

const struct OamArray sMechaSeesSamusCutsceneOam[5] = {
    [0] = {
        .pOam = sMechaSeesSamusOAM_FocusingEye,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [1] = {
        .pOam = sMechaSeesSamusOAM_OpeningEye,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [2] = {
        .pOam = sMechaSeesSamusOAM_OpeningEye,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [3] = {
        .pOam = sMechaSeesSamusOAM_FocusingEye,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [4] = {
        .pOam = sMechaSeesSamusOAM_FocusingEye,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    }
};

const u16 sMechaSeesSamusOAM_FocusingEye_Frame0[OAM_DATA_SIZE(36)] = {
    36,
    OAM_ENTRY(-72, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 0x5, 8, 0),
    OAM_ENTRY(-8, -72, OAM_DIMS_8x32, OAM_NO_FLIP, 0xd, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 0x8d, 8, 0),
    OAM_ENTRY(-72, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x105, 8, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x109, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x10d, 8, 0),
    OAM_ENTRY(8, -72, OAM_DIMS_64x64, OAM_X_FLIP, 0x5, 8, 0),
    OAM_ENTRY(0, -72, OAM_DIMS_8x32, OAM_X_FLIP, 0xd, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_8x32, OAM_X_FLIP, 0x8d, 8, 0),
    OAM_ENTRY(40, -8, OAM_DIMS_32x8, OAM_X_FLIP, 0x105, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_32x8, OAM_X_FLIP, 0x109, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x10d, 8, 0),
    OAM_ENTRY(-72, 8, OAM_DIMS_64x64, OAM_Y_FLIP, 0x5, 8, 0),
    OAM_ENTRY(-8, 40, OAM_DIMS_8x32, OAM_Y_FLIP, 0xd, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x32, OAM_Y_FLIP, 0x8d, 8, 0),
    OAM_ENTRY(-72, 0, OAM_DIMS_32x8, OAM_Y_FLIP, 0x105, 8, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_32x8, OAM_Y_FLIP, 0x109, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0x10d, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_64x64, OAM_XY_FLIP, 0x5, 8, 0),
    OAM_ENTRY(0, 40, OAM_DIMS_8x32, OAM_XY_FLIP, 0xd, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x32, OAM_XY_FLIP, 0x8d, 8, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_32x8, OAM_XY_FLIP, 0x105, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_XY_FLIP, 0x109, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 0x10d, 8, 0),
    OAM_ENTRY(-72, 8, OAM_DIMS_64x64, OAM_Y_FLIP, 0x5, 8, 0),
    OAM_ENTRY(-8, 40, OAM_DIMS_8x32, OAM_Y_FLIP, 0xd, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x32, OAM_Y_FLIP, 0x8d, 8, 0),
    OAM_ENTRY(-72, 0, OAM_DIMS_32x8, OAM_Y_FLIP, 0x105, 8, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_32x8, OAM_Y_FLIP, 0x109, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0x10d, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_64x64, OAM_XY_FLIP, 0x5, 8, 0),
    OAM_ENTRY(0, 40, OAM_DIMS_8x32, OAM_XY_FLIP, 0xd, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x32, OAM_XY_FLIP, 0x8d, 8, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_32x8, OAM_XY_FLIP, 0x105, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_XY_FLIP, 0x109, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 0x10d, 8, 0)
};

const u16 sMechaSeesSamusOAM_FocusingEye_Frame1[OAM_DATA_SIZE(36)] = {
    36,
    OAM_ENTRY(-72, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 0xe, 8, 0),
    OAM_ENTRY(-8, -72, OAM_DIMS_8x32, OAM_NO_FLIP, 0x16, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 0x96, 8, 0),
    OAM_ENTRY(-72, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x10e, 8, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x112, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x116, 8, 0),
    OAM_ENTRY(8, -72, OAM_DIMS_64x64, OAM_X_FLIP, 0xe, 8, 0),
    OAM_ENTRY(0, -72, OAM_DIMS_8x32, OAM_X_FLIP, 0x16, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_8x32, OAM_X_FLIP, 0x96, 8, 0),
    OAM_ENTRY(40, -8, OAM_DIMS_32x8, OAM_X_FLIP, 0x10e, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_32x8, OAM_X_FLIP, 0x112, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x116, 8, 0),
    OAM_ENTRY(-72, 8, OAM_DIMS_64x64, OAM_Y_FLIP, 0xe, 8, 0),
    OAM_ENTRY(-8, 40, OAM_DIMS_8x32, OAM_Y_FLIP, 0x16, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x32, OAM_Y_FLIP, 0x96, 8, 0),
    OAM_ENTRY(-72, 0, OAM_DIMS_32x8, OAM_Y_FLIP, 0x10e, 8, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_32x8, OAM_Y_FLIP, 0x112, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0x116, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_64x64, OAM_XY_FLIP, 0xe, 8, 0),
    OAM_ENTRY(0, 40, OAM_DIMS_8x32, OAM_XY_FLIP, 0x16, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x32, OAM_XY_FLIP, 0x96, 8, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_32x8, OAM_XY_FLIP, 0x10e, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_XY_FLIP, 0x112, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 0x116, 8, 0),
    OAM_ENTRY(-72, 8, OAM_DIMS_64x64, OAM_Y_FLIP, 0xe, 8, 0),
    OAM_ENTRY(-8, 40, OAM_DIMS_8x32, OAM_Y_FLIP, 0x16, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x32, OAM_Y_FLIP, 0x96, 8, 0),
    OAM_ENTRY(-72, 0, OAM_DIMS_32x8, OAM_Y_FLIP, 0x10e, 8, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_32x8, OAM_Y_FLIP, 0x112, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0x116, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_64x64, OAM_XY_FLIP, 0xe, 8, 0),
    OAM_ENTRY(0, 40, OAM_DIMS_8x32, OAM_XY_FLIP, 0x16, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x32, OAM_XY_FLIP, 0x96, 8, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_32x8, OAM_XY_FLIP, 0x10e, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_XY_FLIP, 0x112, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 0x116, 8, 0)
};

const u16 sMechaSeesSamusOAM_FocusingEye_Frame2[OAM_DATA_SIZE(24)] = {
    24,
    OAM_ENTRY(-72, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 0x17, 8, 0),
    OAM_ENTRY(-8, -72, OAM_DIMS_8x32, OAM_NO_FLIP, 0x1f, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 0x9f, 8, 0),
    OAM_ENTRY(-72, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x117, 8, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x11b, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x11f, 8, 0),
    OAM_ENTRY(8, -72, OAM_DIMS_64x64, OAM_X_FLIP, 0x17, 8, 0),
    OAM_ENTRY(0, -72, OAM_DIMS_8x32, OAM_X_FLIP, 0x1f, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_8x32, OAM_X_FLIP, 0x9f, 8, 0),
    OAM_ENTRY(40, -8, OAM_DIMS_32x8, OAM_X_FLIP, 0x117, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_32x8, OAM_X_FLIP, 0x11b, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x11f, 8, 0),
    OAM_ENTRY(-72, 8, OAM_DIMS_64x64, OAM_Y_FLIP, 0x17, 8, 0),
    OAM_ENTRY(-8, 40, OAM_DIMS_8x32, OAM_Y_FLIP, 0x1f, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x32, OAM_Y_FLIP, 0x9f, 8, 0),
    OAM_ENTRY(-72, 0, OAM_DIMS_32x8, OAM_Y_FLIP, 0x117, 8, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_32x8, OAM_Y_FLIP, 0x11b, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0x11f, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_64x64, OAM_XY_FLIP, 0x17, 8, 0),
    OAM_ENTRY(0, 40, OAM_DIMS_8x32, OAM_XY_FLIP, 0x1f, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x32, OAM_XY_FLIP, 0x9f, 8, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_32x8, OAM_XY_FLIP, 0x117, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_32x8, OAM_XY_FLIP, 0x11b, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 0x11f, 8, 0)
};

const u16 sMechaSeesSamusOAM_OpeningEye_Frame0[OAM_DATA_SIZE(23)] = {
    23,
    OAM_ENTRY(-40, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 0x1c4, 9, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_64x64, OAM_NO_FLIP, 0x2c4, 9, 0),
    OAM_ENTRY(-40, 56, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3c4, 9, 0),
    OAM_ENTRY(-8, 56, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3c8, 9, 0),
    OAM_ENTRY(-72, -40, OAM_DIMS_32x64, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(-72, 24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x340, 9, 0),
    OAM_ENTRY(-72, 56, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3c0, 9, 0),
    OAM_ENTRY(-64, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 0x221, 9, 0),
    OAM_ENTRY(-48, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 0x223, 9, 0),
    OAM_ENTRY(-56, -56, OAM_DIMS_16x8, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(-48, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1e3, 9, 0),
    OAM_ENTRY(24, -72, OAM_DIMS_16x32, OAM_NO_FLIP, 0x1cc, 9, 0),
    OAM_ENTRY(24, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x24c, 9, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2cc, 9, 0),
    OAM_ENTRY(24, 24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x34c, 9, 0),
    OAM_ENTRY(24, 56, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3cc, 9, 0),
    OAM_ENTRY(40, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x1ee, 9, 0),
    OAM_ENTRY(40, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x26e, 9, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2ee, 9, 0),
    OAM_ENTRY(40, 32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x36e, 9, 0),
    OAM_ENTRY(56, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x230, 9, 0),
    OAM_ENTRY(56, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2b0, 9, 0),
    OAM_ENTRY(56, 16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x330, 9, 0)
};

const u16 sMechaSeesSamusOAM_OpeningEye_Frame1[OAM_DATA_SIZE(30)] = {
    30,
    OAM_ENTRY(-56, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 0x1d4, 9, 0),
    OAM_ENTRY(-56, -8, OAM_DIMS_64x64, OAM_NO_FLIP, 0x2d4, 9, 0),
    OAM_ENTRY(-48, 56, OAM_DIMS_32x16, OAM_NO_FLIP, 0x3d5, 9, 0),
    OAM_ENTRY(-72, -56, OAM_DIMS_16x32, OAM_NO_FLIP, 0x212, 9, 0),
    OAM_ENTRY(-72, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x292, 9, 0),
    OAM_ENTRY(-72, 8, OAM_DIMS_16x32, OAM_NO_FLIP, 0x312, 9, 0),
    OAM_ENTRY(-72, 40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x392, 9, 0),
    OAM_ENTRY(-16, 56, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3d9, 9, 0),
    OAM_ENTRY(0, 56, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3db, 9, 0),
    OAM_ENTRY(8, -72, OAM_DIMS_16x32, OAM_NO_FLIP, 0x1dc, 9, 0),
    OAM_ENTRY(8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25c, 9, 0),
    OAM_ENTRY(24, -72, OAM_DIMS_16x32, OAM_NO_FLIP, 0x1de, 9, 0),
    OAM_ENTRY(40, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 0x180, 9, 0),
    OAM_ENTRY(32, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x25e, 9, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2de, 9, 0),
    OAM_ENTRY(32, 24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x35e, 9, 0),
    OAM_ENTRY(32, 56, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3de, 9, 0),
    OAM_ENTRY(16, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x29c, 9, 0),
    OAM_ENTRY(16, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x31c, 9, 0),
    OAM_ENTRY(16, 24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x35c, 9, 0),
    OAM_ENTRY(16, 56, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3dc, 9, 0),
    OAM_ENTRY(48, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x12e, 9, 0),
    OAM_ENTRY(64, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 0x130, 9, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1ae, 9, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1b0, 9, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x131, 9, 0),
    OAM_ENTRY(64, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x133, 9, 0),
    OAM_ENTRY(48, 32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1b1, 9, 0),
    OAM_ENTRY(64, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1b3, 9, 0),
    OAM_ENTRY(48, 40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x134, 9, 0)
};

const u16 sMechaSeesSamusOAM_OpeningEye_Frame2[OAM_DATA_SIZE(31)] = {
    31,
    OAM_ENTRY(48, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2, 9, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_8x32, OAM_NO_FLIP, 0x4, 9, 0),
    OAM_ENTRY(48, 8, OAM_DIMS_16x32, OAM_NO_FLIP, 0x82, 9, 0),
    OAM_ENTRY(64, 8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x84, 9, 0),
    OAM_ENTRY(48, 40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x102, 9, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x32, OAM_NO_FLIP, 0x40, 9, 0),
    OAM_ENTRY(32, 24, OAM_DIMS_16x32, OAM_NO_FLIP, 0xc0, 9, 0),
    OAM_ENTRY(32, 56, OAM_DIMS_16x16, OAM_NO_FLIP, 0x140, 9, 0),
    OAM_ENTRY(24, 56, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1, 9, 0),
    OAM_ENTRY(-56, -72, OAM_DIMS_64x32, OAM_NO_FLIP, 0x123, 9, 0),
    OAM_ENTRY(8, -72, OAM_DIMS_16x32, OAM_NO_FLIP, 0x12b, 9, 0),
    OAM_ENTRY(24, -72, OAM_DIMS_8x32, OAM_NO_FLIP, 0x12d, 9, 0),
    OAM_ENTRY(-56, -40, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1a3, 9, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1a7, 9, 0),
    OAM_ENTRY(-48, -32, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1a9, 9, 0),
    OAM_ENTRY(32, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1a1, 9, 0),
    OAM_ENTRY(-72, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x136, 9, 0),
    OAM_ENTRY(-56, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x138, 9, 0),
    OAM_ENTRY(-72, 16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1b6, 9, 0),
    OAM_ENTRY(-56, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1b8, 9, 0),
    OAM_ENTRY(-48, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x199, 9, 0),
    OAM_ENTRY(-32, 16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1bb, 9, 0),
    OAM_ENTRY(-40, 32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x13c, 9, 0),
    OAM_ENTRY(-40, 64, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1bc, 9, 0),
    OAM_ENTRY(-56, 32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x13a, 9, 0),
    OAM_ENTRY(-72, 32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x138, 9, 0),
    OAM_ENTRY(-56, 48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x17a, 9, 0),
    OAM_ENTRY(-40, 24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1f0, 9, 0),
    OAM_ENTRY(-24, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1f2, 9, 0),
    OAM_ENTRY(-72, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1ce, 9, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1b5, 9, 0)
};


const struct FrameData sMechaSeesSamusOAM_FocusingEye[4] = {
    [0] = {
        .pFrame = sMechaSeesSamusOAM_FocusingEye_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sMechaSeesSamusOAM_FocusingEye_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sMechaSeesSamusOAM_FocusingEye_Frame2,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMechaSeesSamusOAM_OpeningEye[4] = {
    [0] = {
        .pFrame = sMechaSeesSamusOAM_OpeningEye_Frame0,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [1] = {
        .pFrame = sMechaSeesSamusOAM_OpeningEye_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sMechaSeesSamusOAM_OpeningEye_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const u32 sMechaSeesSamusMetalGfx[2382] = INCBIN_U32("data/cutscenes/mecha_sees_samus/metal.gfx.lz");
const u32 sMechaSeesSamusCoverEyeGfx[2671] = INCBIN_U32("data/cutscenes/mecha_sees_samus/eye_cover.gfx.lz");
const u16 sMechaSeesSamusPal[10 * 16] = INCBIN_U16("data/cutscenes/mecha_sees_samus/palette.pal");
const u32 sMechaSeesSamusCoverMetalTileTable[368] = INCBIN_U32("data/cutscenes/mecha_sees_samus/metal.tt");
