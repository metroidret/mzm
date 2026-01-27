#include "data/cutscenes/ridley_spawn_data.h"
#include "cutscenes/ridley_spawn.h"
#include "gba.h"
#include "macros.h"

const struct CutscenePageData sRidleySpawnPageData[4] = {
    [0] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    },
    [1] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1D,
        .priority = 1,
        .bg = DCNT_BG1,
        .screenSize = 0
    },
    [2] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1E,
        .priority = 2,
        .bg = DCNT_BG2,
        .screenSize = 0
    },
    [3] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    }
};

const struct FrameData sRidleySpawnOAM_RidleyFlyingReflection[2] = {
    [0] = {
        .pFrame = sRidleySpawnOAM_RidleyFlyingReflection_Frame0,
        .timer = CONVERT_SECONDS(2.f) + CONVERT_SECONDS(2.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleySpawnOAM_RidleyFlying[2] = {
    [0] = {
        .pFrame = sRidleySpawnOAM_RidleyFlying_Frame0,
        .timer = CONVERT_SECONDS(2.f) + CONVERT_SECONDS(2.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleySpawnOAM_RidleyScreaming[2] = {
    [0] = {
        .pFrame = sRidleySpawnOAM_RidleyScreaming_Frame0,
        .timer = CONVERT_SECONDS(2.f) + CONVERT_SECONDS(2.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct OamArray sRidleySpawnOam[RIDLEY_SPAWN_OAM_ID_COUNT] = {
    [RIDLEY_SPAWN_OAM_ID_NONE] = {
        .pOam = sRidleySpawnOAM_RidleyFlyingReflection,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [RIDLEY_SPAWN_OAM_ID_RIDLEY_FLYING_REFLECTION] = {
        .pOam = sRidleySpawnOAM_RidleyFlyingReflection,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_SPAWN_OAM_ID_RIDLEY_FLYING] = {
        .pOam = sRidleySpawnOAM_RidleyFlying,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_SPAWN_OAM_ID_RIDLEY_SCREAMING] = {
        .pOam = sRidleySpawnOAM_RidleyScreaming,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_SPAWN_OAM_ID_SAMUS] = {
        .pOam = sRidleySpawnOAM_Samus,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    }
};

const u16 sRidleySpawnOAM_Samus_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-64, -48, OAM_DIMS_64x64, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -48, OAM_DIMS_64x64, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-64, 16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x10, 1, 0),
    OAM_ENTRY(0, 16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x18, 1, 0)
};

const u16 sRidleySpawnOAM_RidleyFlyingReflection_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-96, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x100, 2, 0),
    OAM_ENTRY(-32, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x108, 2, 0),
    OAM_ENTRY(-96, 0, OAM_DIMS_64x32, OAM_NO_FLIP, 0x200, 2, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_64x32, OAM_NO_FLIP, 0x208, 2, 0),
    OAM_ENTRY(32, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x110, 2, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_64x32, OAM_NO_FLIP, 0x210, 2, 0),
    OAM_ENTRY(96, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x158, 1, 0)
};

const struct FrameData sRidleySpawnOAM_Samus[2] = {
    [0] = {
        .pFrame = sRidleySpawnOAM_Samus_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const u16 sRidleySpawnOAM_RidleyFlying_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-64, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 0x100, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 0x108, 0, 0)
};

const u16 sRidleySpawnOAM_RidleyScreaming_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-64, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x10, 0, 0),
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 0x110, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 0x118, 0, 0)
};

const struct FrameData sRidleySpawnOAM_RidleyFlyingAndScreaming_Unused[3] = {
    [0] = {
        .pFrame = sRidleySpawnOAM_RidleyFlying_Frame0,
        .timer = CONVERT_SECONDS(5.f / 6)
    },
    [1] = {
        .pFrame = sRidleySpawnOAM_RidleyScreaming_Frame0,
        .timer = CONVERT_SECONDS(5.f / 6)
    },
    [2] = FRAME_DATA_TERMINATOR
};


const u16 sRidleySpawnSamusPal[3 * 16] = INCBIN_U16("data/cutscenes/ridley_spawn/samus.pal");
const u16 sRidleySpawnSamusVariaPal[3 * 16] = INCBIN_U16("data/cutscenes/ridley_spawn/samus_varia.pal");
const u16 sRidleySpawnBackgroundPal[13 * 16] = INCBIN_U16("data/cutscenes/ridley_spawn/background.pal");
const u16 sRidleySpawnRidleyScreamingPal[1 * 16] = INCBIN_U16("data/cutscenes/ridley_spawn/ridley_screaming.pal");
const u32 sRidleySpawnBackgroundGfx[2830] = INCBIN_U32("data/cutscenes/ridley_spawn/background.gfx.lz");
const u32 sRidleySpawnSamusAndRidleyGfx[2215] = INCBIN_U32("data/cutscenes/ridley_spawn/samus_and_ridley.gfx.lz");
const u32 sRidleySpawnSamusHelmetFaceGfx[3164] = INCBIN_U32("data/cutscenes/ridley_spawn/samus_helmet_face.gfx.lz");
const u32 sRidleySpawnScreamingGfx[1663] = INCBIN_U32("data/cutscenes/ridley_spawn/ridley_screaming.gfx.lz");
const u32 sRidleySpawnBackgroundTileTable[368] = INCBIN_U32("data/cutscenes/ridley_spawn/background.tt");
const u32 sRidleySpawnSamusHelmetTileTable[368] = INCBIN_U32("data/cutscenes/ridley_spawn/samus_helmet.tt");
const u32 sRidleySpawnSamusFaceTileTable[189] = INCBIN_U32("data/cutscenes/ridley_spawn/samus_face.tt");
