#include "data/cutscenes/enter_tourian_data.h"
#include "macros.h"
#include "gba.h"

#include "data/sprites/metroid.h"

const struct CutscenePageData sEnterTourianPageData[2] = {
    [0] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1E,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    },
    [1] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1C,
        .priority = 1,
        .bg = DCNT_BG1,
        .screenSize = 0x4000
    }
};

static const struct FrameData sEnterTourianOAM_SpacePirate[2] = {
    [0] = {
        .pFrame = sEnterTourianOAM_SpacePirate_Frame0,
        .timer = CONVERT_SECONDS(2.f) + CONVERT_SECONDS(2.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct OamArray sEnterTourianOam[7] = {
    [0] = {
        .pOam = sEnterTourianOAM_Empty,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [1] = {
        .pOam = sEnterTourianOAM_SpacePirate,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [2] = {
        .pOam = sMetroidShellOam_Idle,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [3] = {
        .pOam = sMetroidOam_Moving,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [4] = {
        .pOam = sMetroidOam_Moving,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [5] = {
        .pOam = sMetroidOam_Moving,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [6] = {
        .pOam = sMetroidOam_SamusGrabbed,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    }
};

const u16 sEnterTourianOAM_SpacePirate_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-40, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x0, 4, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x4, 4, 0),
    OAM_ENTRY(24, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8, 4, 0),
    OAM_ENTRY(-40, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x44, 4, 0)
};

const struct FrameData sEnterTourianOAM_Empty[1] = {
    [0] = FRAME_DATA_TERMINATOR
};

const u16 sEnterTourianBackgroundPal[10 * 16] = INCBIN_U16("data/cutscenes/enter_tourian/background.pal");
const u16 sEnterTourianMetroidPal[6 * 16] = INCBIN_U16("data/cutscenes/enter_tourian/metroid.pal");
const u32 sEnterTourianBackgroundGfx[3110] = INCBIN_U32("data/cutscenes/enter_tourian/background.gfx.lz");
const u32 sEnterTourianForegroundGfx[2483] = INCBIN_U32("data/cutscenes/enter_tourian/foreground.gfx.lz");
const u32 sEnterTourianDeadSpacePirateGfx_1[55] = INCBIN_U32("data/cutscenes/enter_tourian/dead_space_pirate_1.gfx.lz");
const u32 sEnterTourianDeadSpacePirateGfx_2[77] = INCBIN_U32("data/cutscenes/enter_tourian/dead_space_pirate_2.gfx.lz");
const u32 sEnterTourianDeadSpacePirateGfx_3[32] = INCBIN_U32("data/cutscenes/enter_tourian/dead_space_pirate_3.gfx.lz");
const u32 sEnterTourianBackgroundTileTable[385] = INCBIN_U32("data/cutscenes/enter_tourian/background.tt");
const u32 sEnterTourianForegroundTileTable[385] = INCBIN_U32("data/cutscenes/enter_tourian/foreground.tt");
