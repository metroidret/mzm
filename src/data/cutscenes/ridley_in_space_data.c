#include "data/cutscenes/ridley_in_space_data.h"
#include "cutscenes/ridley_in_space.h"
#include "gba.h"
#include "macros.h"

const struct CutsceneScrollingInfo sRidleyInSpaceScrollingInfo[2] = {
    [0] = {
        .direction = 1,
        .length = -BLOCK_SIZE * 10,
        .speed = -4,
        .maxDelay = 0
    },
    [1] = {
        .direction = 0,
        .length = -BLOCK_SIZE,
        .speed = -4,
        .maxDelay = 2
    }
};

const struct CutscenePageData sRidleyInSpacePageData[6] = {
    [0] = {
        .graphicsPage = 2,
        .tiletablePage = 0,
        .priority = BGCNT_LOW_PRIORITY,
        .bg = DCNT_BG3,
        .screenSize = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT
    },
    [1] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1C,
        .priority = BGCNT_LOW_PRIORITY,
        .bg = DCNT_BG3,
        .screenSize = BGCNT_SIZE_256x512 << BGCNT_SCREEN_SIZE_SHIFT
    },
    [2] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1E,
        .priority = BGCNT_HIGH_MID_PRIORITY,
        .bg = DCNT_BG1,
        .screenSize = BGCNT_SIZE_256x512 << BGCNT_SCREEN_SIZE_SHIFT
    },
    [3] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1D,
        .priority = BGCNT_LOW_PRIORITY,
        .bg = DCNT_BG3,
        .screenSize = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT
    },
    [4] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1F,
        .priority = BGCNT_LOW_MID_PRIORITY,
        .bg = DCNT_BG2,
        .screenSize = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT
    },
    [5] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1E,
        .priority = BGCNT_HIGH_MID_PRIORITY,
        .bg = DCNT_BG1,
        .screenSize = BGCNT_SIZE_256x256 << BGCNT_SCREEN_SIZE_SHIFT
    }
};

const struct CutscenePaletteData sRidleyInSpacePaletteData = {
    .active = TRUE,
    .timer = 0,
    .paletteRow = 0,
    .maxTimer = 2
};

const u8 sRidleyInSpaceRedAlertPaletteRows[10] = {
    0, 1, 2, 3, 4, 5, 4, 3, 2, 1
};

const struct FrameData sRidleyInSpaceOAM_LeftBlueShip[2] = {
    [0] = {
        .pFrame = sRidleyInSpaceOAM_LeftBlueShip_Frame0,
        .timer = CONVERT_SECONDS(2.f) + CONVERT_SECONDS(2.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyInSpaceOAM_RightBlueShip[2] = {
    [0] = {
        .pFrame = sRidleyInSpaceOAM_RightBlueShip_Frame0,
        .timer = CONVERT_SECONDS(2.f) + CONVERT_SECONDS(2.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyInSpaceOAM_MotherShip[2] = {
    [0] = {
        .pFrame = sRidleyInSpaceOAM_MotherShip_Frame0,
        .timer = CONVERT_SECONDS(2.f) + CONVERT_SECONDS(2.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyInSpaceOAM_MotherShipLeavingBack[2] = {
    [0] = {
        .pFrame = sRidleyInSpaceOAM_MotherShipLeavingBack_Frame0,
        .timer = CONVERT_SECONDS(2.f) + CONVERT_SECONDS(2.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyInSpaceOAM_MotherShipLeavingFront[2] = {
    [0] = {
        .pFrame = sRidleyInSpaceOAM_MotherShipLeavingFront_Frame0,
        .timer = CONVERT_SECONDS(2.f) + CONVERT_SECONDS(2.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyInSpaceOAM_ViewOfShipParticle[2] = {
    [0] = {
        .pFrame = sRidleyInSpaceOAM_ViewOfShipParticle_Frame0,
        .timer = CONVERT_SECONDS(2.f) + CONVERT_SECONDS(2.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyInSpaceOAM_387010[2] = {
    [0] = {
        .pFrame = sRidleyInSpaceOAM_ShipLeavingParticle_Frame2,
        .timer = CONVERT_SECONDS(2.f) + CONVERT_SECONDS(2.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyInSpaceOAM_ViewOfShipParticleSecond[2] = {
    [0] = {
        .pFrame = sRidleyInSpaceOAM_ViewOfShipParticleSecond_Frame0,
        .timer = CONVERT_SECONDS(2.f) + CONVERT_SECONDS(2.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct OamArray sRidleyInSpaceCutsceneOAM[RIDLEY_IN_SPACE_OAM_ID_COUNT] = {
    [RIDLEY_IN_SPACE_OAM_ID_NONE] = {
        .pOam = sRidleyInSpaceOAM_39d7e8,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [RIDLEY_IN_SPACE_OAM_ID_LEFT_BLUE_SHIP] = {
        .pOam = sRidleyInSpaceOAM_LeftBlueShip,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_IN_SPACE_OAM_ID_RIGHT_BLUE_SHIP] = {
        .pOam = sRidleyInSpaceOAM_RightBlueShip,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_IN_SPACE_OAM_ID_MOTHER_SHIP] = {
        .pOam = sRidleyInSpaceOAM_MotherShip,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_IN_SPACE_OAM_ID_MOTHER_SHIP_LEAVING_BACK] = {
        .pOam = sRidleyInSpaceOAM_MotherShipLeavingBack,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_IN_SPACE_OAM_ID_MOTHER_SHIP_LEAVING_FRONT] = {
        .pOam = sRidleyInSpaceOAM_MotherShipLeavingFront,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_IN_SPACE_OAM_ID_VIEW_OF_SHIP_PARTICLE] = {
        .pOam = sRidleyInSpaceOAM_ViewOfShipParticle,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_IN_SPACE_OAM_ID_7] = {
        .pOam = sRidleyInSpaceOAM_387010,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_IN_SPACE_OAM_ID_VIEW_OF_SHIP_PARTICLE2] = {
        .pOam = sRidleyInSpaceOAM_ViewOfShipParticleSecond,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [RIDLEY_IN_SPACE_OAM_ID_SHIP_LEAVING_PARTICLE] = {
        .pOam = sRidleyInSpaceOAM_ShipLeavingParticle,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [RIDLEY_IN_SPACE_OAM_ID_SHIP_LEAVING_PARTICLE2] = {
        .pOam = sRidleyInSpaceOAM_ShipLeavingParticleSecond,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    }
};

const u32 sRidleyInSpaceShipsGfx[1565] = INCBIN_U32("data/cutscenes/ridley_in_space/ship.gfx.lz");
const u32 sRidleyInSpaceRidleySittingGfx[3848] = INCBIN_U32("data/cutscenes/ridley_in_space/ridley_sitting.gfx.lz");
const u32 sRidleyInSpaceShipInteriorGfx[4391] = INCBIN_U32("data/cutscenes/ridley_in_space/ship_interior.gfx.lz");
const u32 sRidleyInSpaceRidleySuspiciousGfx[1961] = INCBIN_U32("data/cutscenes/ridley_in_space/ridley_suspicious.gfx.lz");
const u32 sRidleyInSpaceShipInterior2Gfx[4235] = INCBIN_U32("data/cutscenes/ridley_in_space/ship_interior_2.gfx.lz");
const u32 sRidleyInSpaceMotherShipLeavingGfx[1497] = INCBIN_U32("data/cutscenes/ridley_in_space/mother_ship_leaving.gfx.lz");
const u32 sRidleyInSpaceSpaceBackgroundGfx[5470] = INCBIN_U32("data/cutscenes/ridley_in_space/space_background.gfx.lz");


const u16 sRidleyInSpaceOAM_LeftBlueShip_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x180, 1, 0)
};

const u16 sRidleyInSpaceOAM_RightBlueShip_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x188, 1, 0)
};

const u16 sRidleyInSpaceOAM_MotherShip_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-120, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-56, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(8, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x12, 0, 0),
    OAM_ENTRY(72, -64, OAM_DIMS_32x64, OAM_NO_FLIP, 0x1a, 0, 0),
    OAM_ENTRY(104, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x1e, 0, 0),
    OAM_ENTRY(104, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x9e, 0, 0),
    OAM_ENTRY(-48, 0, OAM_DIMS_64x32, OAM_NO_FLIP, 0x10b, 0, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_32x32, OAM_NO_FLIP, 0x113, 0, 0)
};

const u16 sRidleyInSpaceOAM_39d7a6_FrameUnused[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1dc, 2, 0)
};

const u16 sRidleyInSpaceOAM_39d7ae_FrameUnused[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1dd, 2, 0)
};

const u16 sRidleyInSpaceOAM_39d7b6_FrameUnused[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1de, 2, 0)
};

const u16 sRidleyInSpaceOAM_39d7be_FrameUnused[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1df, 2, 0)
};

const u16 sRidleyInSpaceOAM_39d7c6_FrameUnused[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1fc, 2, 0)
};

const u16 sRidleyInSpaceOAM_39d7ce_FrameUnused[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1fd, 2, 0)
};

const u16 sRidleyInSpaceOAM_39d7d6_FrameUnused[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1fe, 2, 0)
};

const u16 sRidleyInSpaceOAM_39d7de_FrameUnused[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1ff, 2, 0)
};

const struct FrameData sRidleyInSpaceOAM_39d7e8[2] = {
    [0] = {
        .pFrame = sRidleyInSpaceOAM_LeftBlueShip_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const u16 sRidleyInSpaceOAM_MotherShipLeavingBack_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-64, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 0x10, 0, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 0x18, 0, 0)
};

const u16 sRidleyInSpaceOAM_MotherShipLeavingFront_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-64, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x0, 1, 0),
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 0x100, 1, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x64, OAM_NO_FLIP, 0x108, 1, 0)
};

const u16 sRidleyInSpaceOAM_ShipLeavingParticle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1dc, 2, 0)
};

const u16 sRidleyInSpaceOAM_ViewOfShipParticleSecond_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1dd, 2, 0)
};

const u16 sRidleyInSpaceOAM_ShipLeavingParticle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1de, 2, 0)
};

const u16 sRidleyInSpaceOAM_ViewOfShipParticle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1df, 2, 0)
};

const u16 sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1fc, 2, 0)
};

const u16 sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1fd, 2, 0)
};

const u16 sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1fe, 2, 0)
};

const u16 sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1ff, 2, 0)
};

const struct FrameData sRidleyInSpaceOAM_ShipLeavingParticle[5] = {
    [0] = {
        .pFrame = sRidleyInSpaceOAM_ShipLeavingParticle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sRidleyInSpaceOAM_ViewOfShipParticleSecond_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sRidleyInSpaceOAM_ShipLeavingParticle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sRidleyInSpaceOAM_ViewOfShipParticle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyInSpaceOAM_ShipLeavingParticleSecond[5] = {
    [0] = {
        .pFrame = sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const u16 sRidleyInSpaceShipsPal[3 * 16] = INCBIN_U16("data/cutscenes/ridley_in_space/ships.pal");
const u16 sRidleyInSpace_39d910_Pal[6 * 16] = INCBIN_U16("data/cutscenes/ridley_in_space/39d910.pal");
const u16 sRidleyInSpaceRedAlertPal[6 * 16] = INCBIN_U16("data/cutscenes/ridley_in_space/red_alert.pal");
const u16 sRidleyInSpaceShipInteriorPal[15 * 16] = INCBIN_U16("data/cutscenes/ridley_in_space/ship_interior.pal");
const u16 sRidleyInSpace_39dc70_Pal[3 * 16] = INCBIN_U16("data/cutscenes/ridley_in_space/39dc70.pal");
const u16 sRidleyInSpaceSpaceBackgroundPal[5 * 16] = INCBIN_U16("data/cutscenes/ridley_in_space/space_background.pal");

const u32 sRidleyInSpaceRidleySittingTileTable[449] = INCBIN_U32("data/cutscenes/ridley_in_space/ridley_sitting.tt");
const u32 sRidleyInSpaceShipInteriorTileTable[559] = INCBIN_U32("data/cutscenes/ridley_in_space/ship_interior.tt");
const u32 sRidleyInSpaceRidleySuspiciousEyesOpenTileTable[287] = INCBIN_U32("data/cutscenes/ridley_in_space/ridley_suspicious_eyes_open.tt");
const u32 sRidleyInSpaceRidleySuspiciousEyesSquintedTileTable[287] = INCBIN_U32("data/cutscenes/ridley_in_space/ridley_suspicious_squinted_eyes.tt");
const u32 sRidleyInSpaceShipInteriorTileTable2[385] = INCBIN_U32("data/cutscenes/ridley_in_space/ship_interior_2.tt");
const u32 sRidleyInSpaceSpaceBackgroundTileTable[577] = INCBIN_U32("data/cutscenes/ridley_in_space/s_pace_background.tt");
