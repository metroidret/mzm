#include "data/projectile_data.h"
#include "structs/particle.h"
#include "macros.h"

const s16 sTumblingMissileSpeed[16] = {
    -12, -10, -8, -6,
     -4,  -2,  0,  0,
      1,   2,  4,  8,
     12,  16, 20,  SHORT_MAX
};

const u8 sProjectile_Array326cc8_Unused[64] = {
    24, 0, 16, 0, 8, 0, 4, 0, 4, 0, 8, 0, 16, 0, 24, 0,
    32, 0, 20, 0, 8, 0, 4, 0, 4, 0, 8, 0, 20, 0, 32, 0,
    24, 0, 20, 0, 16, 0, 12, 0, 12, 0, 8, 0, 4, 0, 0, 0,
    0, 0, 4, 0, 8, 0, 12, 0, 12, 0, 16, 0, 20, 0, 24, 0
};

static const u16 sBombOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x14d, 4, 0)
};

static const u16 sBombOam_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x14e, 4, 0)
};

static const u16 sBombOam_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x14f, 4, 0)
};

static const u16 sBombOam_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x150, 4, 0)
};

static const u16 sPowerBombOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x14b, 4, 0)
};

static const u16 sPowerBombOam_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x14c, 4, 0)
};

static const u16 sPowerBombOam_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x16b, 4, 0)
};

const struct FrameData sBombOam_Slow[5] = {
    [0] = {
        .pFrame = sBombOam_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sBombOam_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sBombOam_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [3] = {
        .pFrame = sBombOam_Frame3,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBombOam_Fast[5] = {
    [0] = {
        .pFrame = sBombOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sBombOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sBombOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sBombOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPowerBombOam_Slow[4] = {
    [0] = {
        .pFrame = sPowerBombOam_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sPowerBombOam_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sPowerBombOam_Frame2,
        .timer = CONVERT_SECONDS(.1f)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPowerBombOam_Fast[4] = {
    [0] = {
        .pFrame = sPowerBombOam_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPowerBombOam_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = {
        .pFrame = sPowerBombOam_Frame2,
        .timer = CONVERT_SECONDS(.05f)
    },
    [3] = FRAME_DATA_TERMINATOR
};

static const u16 sMissileOam_Horizontal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(3, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x78, 4, 0)
};

static const u16 sMissileOam_Horizontal_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(7, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xd1, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x78, 4, 0)
};

static const u16 sMissileOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(1, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x5c, 4, 0)
};

static const u16 sMissileOam_Diagonal_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x5c, 4, 0),
    OAM_ENTRY(3, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf0, 3, 0)
};

static const u16 sMissileOam_Vertical_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x185, 4, 0)
};

static const u16 sMissileOam_Vertical_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf1, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x185, 4, 0)
};

static const u16 sSuperMissileOam_Horizontal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(2, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xd3, 3, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x7a, 4, 0)
};

static const u16 sSuperMissileOam_Horizontal_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x7a, 4, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xd1, 3, 0)
};

static const u16 sSuperMissileOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0xd3, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x5e, 4, 0)
};

static const u16 sSuperMissileOam_Diagonal_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x5e, 4, 0),
    OAM_ENTRY(3, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf0, 3, 0)
};

static const u16 sSuperMissileOam_Vertical_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0xd3, 3, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x186, 4, 0)
};

static const u16 sSuperMissileOam_Vertical_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x186, 4, 0),
    OAM_ENTRY(-4, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf1, 3, 0)
};

static const u16 sMissileOam_Tumbling_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x78, 4, 0)
};

static const u16 sMissileOam_Tumbling_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x5c, 4, 0)
};

static const u16 sMissileOam_Tumbling_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x185, 4, 0)
};

static const u16 sMissileOam_Tumbling_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x5c, 4, 0)
};

static const u16 sMissileOam_Tumbling_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x78, 4, 0)
};

static const u16 sMissileOam_Tumbling_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 0x5c, 4, 0)
};

static const u16 sMissileOam_Tumbling_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_Y_FLIP, 0x185, 4, 0)
};

static const u16 sMissileOam_Tumbling_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 0x5c, 4, 0)
};

static const u16 sSuperMissileOam_Tumbling_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x7a, 4, 0)
};

static const u16 sSuperMissileOam_Tumbling_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x5e, 4, 0)
};

static const u16 sSuperMissileOam_Tumbling_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x186, 4, 0)
};

static const u16 sSuperMissileOam_Tumbling_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x5e, 4, 0)
};

static const u16 sSuperMissileOam_Tumbling_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_X_FLIP, 0x7a, 4, 0)
};

static const u16 sSuperMissileOam_Tumbling_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 0x5e, 4, 0)
};

static const u16 sSuperMissileOam_Tumbling_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x16, OAM_Y_FLIP, 0x186, 4, 0)
};

static const u16 sSuperMissileOam_Tumbling_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 0x5e, 4, 0)
};

static const u16 sParticleMissileTrailOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xd5, 3, 0)
};

static const u16 sParticleMissileTrailOam_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf5, 3, 0)
};

static const u16 sParticleMissileTrailOam_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xf6, 3, 0)
};

static const u16 sParticleSuperMissileTrailOam_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x159, 4, 0)
};

static const u16 sParticleMissileTrailOam_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x15a, 4, 0)
};

static const u16 sParticleMissileTrailOam_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x15b, 4, 0)
};

static const u16 sParticleMissileTrailOam_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x15c, 4, 0)
};

static const u16 sParticleMissileTrailOam_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x15d, 4, 0)
};

static const u16 sParticleSuperMissileTrailOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xd0, 3, 0)
};

const struct FrameData sMissileOam_Horizontal[3] = {
    [0] = {
        .pFrame = sMissileOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMissileOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMissileOam_Diagonal[3] = {
    [0] = {
        .pFrame = sMissileOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMissileOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMissileOam_Vertical[3] = {
    [0] = {
        .pFrame = sMissileOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMissileOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSuperMissileOam_Horizontal[3] = {
    [0] = {
        .pFrame = sSuperMissileOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSuperMissileOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSuperMissileOam_Diagonal[3] = {
    [0] = {
        .pFrame = sSuperMissileOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSuperMissileOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSuperMissileOam_Vertical[3] = {
    [0] = {
        .pFrame = sSuperMissileOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSuperMissileOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMissileOam_Tumbling[9] = {
    [0] = {
        .pFrame = sMissileOam_Tumbling_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sMissileOam_Tumbling_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = {
        .pFrame = sMissileOam_Tumbling_Frame2,
        .timer = CONVERT_SECONDS(.05f)
    },
    [3] = {
        .pFrame = sMissileOam_Tumbling_Frame3,
        .timer = CONVERT_SECONDS(.05f)
    },
    [4] = {
        .pFrame = sMissileOam_Tumbling_Frame4,
        .timer = CONVERT_SECONDS(.05f)
    },
    [5] = {
        .pFrame = sMissileOam_Tumbling_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [6] = {
        .pFrame = sMissileOam_Tumbling_Frame6,
        .timer = CONVERT_SECONDS(.05f)
    },
    [7] = {
        .pFrame = sMissileOam_Tumbling_Frame7,
        .timer = CONVERT_SECONDS(.05f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSuperMissileOam_Tumbling[9] = {
    [0] = {
        .pFrame = sSuperMissileOam_Tumbling_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sSuperMissileOam_Tumbling_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = {
        .pFrame = sSuperMissileOam_Tumbling_Frame2,
        .timer = CONVERT_SECONDS(.05f)
    },
    [3] = {
        .pFrame = sSuperMissileOam_Tumbling_Frame3,
        .timer = CONVERT_SECONDS(.05f)
    },
    [4] = {
        .pFrame = sSuperMissileOam_Tumbling_Frame4,
        .timer = CONVERT_SECONDS(.05f)
    },
    [5] = {
        .pFrame = sSuperMissileOam_Tumbling_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [6] = {
        .pFrame = sSuperMissileOam_Tumbling_Frame6,
        .timer = CONVERT_SECONDS(.05f)
    },
    [7] = {
        .pFrame = sSuperMissileOam_Tumbling_Frame7,
        .timer = CONVERT_SECONDS(.05f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleMissileTrailOam[8] = {
    [0] = {
        .pFrame = sParticleMissileTrailOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleMissileTrailOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleMissileTrailOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleMissileTrailOam_Frame3,
        .timer = CONVERT_SECONDS(.05f)
    },
    [4] = {
        .pFrame = sParticleMissileTrailOam_Frame4,
        .timer = CONVERT_SECONDS(.05f)
    },
    [5] = {
        .pFrame = sParticleMissileTrailOam_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [6] = {
        .pFrame = sParticleMissileTrailOam_Frame6,
        .timer = CONVERT_SECONDS(.05f)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSuperMissileTrailOam[9] = {
    [0] = {
        .pFrame = sParticleSuperMissileTrailOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleMissileTrailOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleMissileTrailOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleSuperMissileTrailOam_Frame3,
        .timer = CONVERT_SECONDS(.05f)
    },
    [4] = {
        .pFrame = sParticleMissileTrailOam_Frame3,
        .timer = CONVERT_SECONDS(.05f)
    },
    [5] = {
        .pFrame = sParticleMissileTrailOam_Frame4,
        .timer = CONVERT_SECONDS(.05f)
    },
    [6] = {
        .pFrame = sParticleMissileTrailOam_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [7] = {
        .pFrame = sParticleMissileTrailOam_Frame6,
        .timer = CONVERT_SECONDS(.05f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const u16 sBeamPal[16 * 6] = INCBIN_U16("data/weapons/beams.pal");

const u8 sNormalBeamGfx_Top[512] = INCBIN_U8("data/weapons/normal_beam_top.gfx");
const u8 sNormalBeamGfx_Bottom[512] = INCBIN_U8("data/weapons/normal_beam_bottom.gfx");
const u8 sNormalBeamGfx_Charged_Top[512] = INCBIN_U8("data/weapons/normal_beam_charged_top.gfx");
const u8 sNormalBeamGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/normal_beam_charged_bottom.gfx");

static const u16 sNormalBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-6, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x80, 2, 0)
};

static const u16 sNormalBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-6, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0xa0, 2, 0)
};

static const u16 sNormalBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x82, 2, 0)
};

static const u16 sNormalBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x84, 2, 0)
};

static const u16 sNormalBeamOam_Vertical_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x86, 2, 0)
};

static const u16 sNormalBeamOam_Vertical_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x87, 2, 0)
};

static const u16 sNormalBeamOam_Horizontal_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa8, 2, 0)
};

static const u16 sNormalBeamOam_Horizontal_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa8, 2, 0)
};

static const u16 sNormalBeamOam_Diagonal_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa9, 2, 0)
};

static const u16 sNormalBeamOam_Diagonal_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa9, 2, 0)
};

static const u16 sNormalBeamOam_Vertical_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xaa, 2, 0)
};

static const u16 sNormalBeamOam_Vertical_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xaa, 2, 0)
};

static const u16 sChargedNormalBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc2, 2, 0)
};

static const u16 sChargedNormalBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc2, 2, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(9, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc2, 2, 0)
};

static const u16 sChargedNormalBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc6, 2, 0)
};

static const u16 sChargedNormalBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc6, 2, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc6, 2, 0)
};

static const u16 sChargedNormalBeamOam_Vertical_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc8, 2, 0),
    OAM_ENTRY(-8, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0xca, 2, 0)
};

static const u16 sChargedNormalBeamOam_Vertical_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xca, 2, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc8, 2, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0xca, 2, 0)
};

static const u16 sChargedNormalBeamOam_Horizontal_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xce, 2, 0)
};

static const u16 sChargedNormalBeamOam_Horizontal_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xcf, 2, 0)
};

static const u16 sChargedNormalBeamOam_Horizontal_Unused_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xee, 2, 0)
};

static const u16 sChargedNormalBeamOam_Horizontal_Unused_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xef, 2, 0)
};

const struct FrameData sNormalBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sNormalBeamOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        sNormalBeamOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNormalBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sNormalBeamOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        sNormalBeamOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNormalBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sNormalBeamOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        sNormalBeamOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNormalBeamOam_Horizontal_Unused[3] = {
    [0] = {
        .pFrame = sNormalBeamOam_Horizontal_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        sNormalBeamOam_Horizontal_Unused_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNormalBeamOam_Diagonal_Unused[3] = {
    [0] = {
        .pFrame = sNormalBeamOam_Diagonal_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        sNormalBeamOam_Diagonal_Unused_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sNormalBeamOam_Vertical_Unused[3] = {
    [0] = {
        .pFrame = sNormalBeamOam_Vertical_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        sNormalBeamOam_Vertical_Unused_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedNormalBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sChargedNormalBeamOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedNormalBeamOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedNormalBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sChargedNormalBeamOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedNormalBeamOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedNormalBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sChargedNormalBeamOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedNormalBeamOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedNormalBeamOam_Horizontal_Unused[5] = {
    [0] = {
        .pFrame = sChargedNormalBeamOam_Horizontal_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sChargedNormalBeamOam_Horizontal_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sChargedNormalBeamOam_Horizontal_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sChargedNormalBeamOam_Horizontal_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const u8 sLongBeamGfx_Top[512] = INCBIN_U8("data/weapons/long_beam_top.gfx");
const u8 sLongBeamGfx_Bottom[512] = INCBIN_U8("data/weapons/long_beam_bottom.gfx");
const u8 sLongBeamGfx_Charged_Top[512] = INCBIN_U8("data/weapons/long_beam_charged_top.gfx");
const u8 sLongBeamGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/long_beam_charged_bottom.gfx");

static const u16 sLongBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x80, 2, 0)
};

static const u16 sLongBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0xa0, 2, 0)
};

static const u16 sLongBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0)
};

static const u16 sLongBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc2, 2, 0)
};

static const u16 sLongBeamOam_Vertical_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x82, 2, 0)
};

static const u16 sLongBeamOam_Vertical_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x83, 2, 0)
};

static const u16 sChargedLongBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x86, 2, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0xc6, 2, 0)
};

static const u16 sChargedLongBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0xc6, 2, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x86, 2, 0),
    OAM_ENTRY(11, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0xc6, 2, 0)
};

static const u16 sChargedLongBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(2, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0)
};

static const u16 sChargedLongBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(1, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0)
};

static const u16 sChargedLongBeamOam_Vertical_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -6, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8c, 2, 0)
};

static const u16 sChargedLongBeamOam_Vertical_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8c, 2, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(-8, 11, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8c, 2, 0)
};

static const u16 sParticleChargedLongBeamTrailOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xce, 2, 0)
};

static const u16 sParticleChargedLongBeamTrailOam_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8e, 2, 0)
};

static const u16 sParticleChargedLongBeamTrailOam_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xcf, 2, 0)
};

static const u16 sParticleChargedLongBeamTrailOam_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xef, 2, 0)
};

const struct FrameData sLongBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sLongBeamOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sLongBeamOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sLongBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sLongBeamOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sLongBeamOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sLongBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sLongBeamOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sLongBeamOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedLongBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sChargedLongBeamOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedLongBeamOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedLongBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sChargedLongBeamOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedLongBeamOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedLongBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sChargedLongBeamOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedLongBeamOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleChargedLongBeamTrailOam[5] = {
    [0] = {
        .pFrame = sParticleChargedLongBeamTrailOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleChargedLongBeamTrailOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleChargedLongBeamTrailOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleChargedLongBeamTrailOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const u8 sIceBeamGfx_Top[512] = INCBIN_U8("data/weapons/ice_beam_top.gfx");
const u8 sIceBeamGfx_Bottom[512] = INCBIN_U8("data/weapons/ice_beam_bottom.gfx");
const u8 sIceBeamGfx_Charged_Top[512] = INCBIN_U8("data/weapons/ice_beam_charged_top.gfx");
const u8 sIceBeamGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/ice_beam_charged_bottom.gfx");

static const u16 sIceBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x80, 2, 0)
};

static const u16 sIceBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x82, 2, 0)
};

static const u16 sIceBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x84, 2, 0)
};

static const u16 sIceBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-6, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x86, 2, 0)
};

static const u16 sIceBeamOam_Vertical_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x88, 2, 0)
};

static const u16 sIceBeamOam_Vertical_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8a, 2, 0)
};

static const u16 sIceBeamOam_Horizontal_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8c, 2, 0)
};

static const u16 sIceBeamOam_Horizontal_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8c, 2, 0)
};

static const u16 sIceBeamOam_Diagonal_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8d, 2, 0)
};

static const u16 sIceBeamOam_Diagonal_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8d, 2, 0)
};

static const u16 sIceBeamOam_Vertical_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8e, 2, 0)
};

static const u16 sIceBeamOam_Vertical_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8e, 2, 0)
};

static const u16 sChargedIceBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(10, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc2, 2, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc3, 2, 0),
    OAM_ENTRY(15, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe2, 2, 0)
};

static const u16 sChargedIceBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc3, 2, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe2, 2, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(17, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc2, 2, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc3, 2, 0),
    OAM_ENTRY(26, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe2, 2, 0)
};

static const u16 sChargedIceBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc5, 2, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc7, 2, 0)
};

static const u16 sChargedIceBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc7, 2, 0),
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc5, 2, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc7, 2, 0)
};

static const u16 sChargedIceBeamOam_Vertical_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc9, 2, 0),
    OAM_ENTRY(-4, 10, OAM_DIMS_8x8, OAM_NO_FLIP, 0xcb, 2, 0),
    OAM_ENTRY(-8, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0xcc, 2, 0),
    OAM_ENTRY(-4, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 0xeb, 2, 0)
};

static const u16 sChargedIceBeamOam_Vertical_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xcc, 2, 0),
    OAM_ENTRY(-4, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xeb, 2, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc9, 2, 0),
    OAM_ENTRY(-4, 17, OAM_DIMS_8x8, OAM_NO_FLIP, 0xcb, 2, 0),
    OAM_ENTRY(-8, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0xcc, 2, 0),
    OAM_ENTRY(-4, 26, OAM_DIMS_8x8, OAM_NO_FLIP, 0xeb, 2, 0)
};

static const u16 sParticleChargedIceBeamTrailOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8c, 2, 0)
};

static const u16 sParticleChargedIceBeamTrailOam_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xce, 2, 0)
};

static const u16 sParticleChargedIceBeamTrailOam_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xae, 2, 0)
};

static const u16 sParticleChargedIceBeamTrailOam_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xaf, 2, 0)
};

static const u16 sParticleChargedIceBeamTrailOam_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8f, 2, 0)
};

const struct FrameData sIceBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sIceBeamOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sIceBeamOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIceBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sIceBeamOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sIceBeamOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIceBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sIceBeamOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sIceBeamOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIceBeamOam_Horizontal_Unused[3] = {
    [0] = {
        .pFrame = sIceBeamOam_Horizontal_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sIceBeamOam_Horizontal_Unused_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIceBeamOam_Diagonal_Unused[3] = {
    [0] = {
        .pFrame = sIceBeamOam_Diagonal_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sIceBeamOam_Diagonal_Unused_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sIceBeamOam_Vertical_Unused[3] = {
    [0] = {
        .pFrame = sIceBeamOam_Vertical_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sIceBeamOam_Vertical_Unused_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedIceBeamOam_Horizontal[3] = {
    [0] = {
        .pFrame = sChargedIceBeamOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedIceBeamOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedIceBeamOam_Diagonal[3] = {
    [0] = {
        .pFrame = sChargedIceBeamOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedIceBeamOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedIceBeamOam_Vertical[3] = {
    [0] = {
        .pFrame = sChargedIceBeamOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedIceBeamOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleChargedIceBeamTrailOam[6] = {
    [0] = {
        .pFrame = sParticleChargedIceBeamTrailOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleChargedIceBeamTrailOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleChargedIceBeamTrailOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleChargedIceBeamTrailOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sParticleChargedIceBeamTrailOam_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const u8 sWaveBeamGfx_Top[512] = INCBIN_U8("data/weapons/wave_beam_top.gfx");
const u8 sWaveBeamGfx_Bottom[512] = INCBIN_U8("data/weapons/wave_beam_bottom.gfx");
const u8 sWaveBeamGfx_Charged_Top[512] = INCBIN_U8("data/weapons/wave_beam_charged_top.gfx");
const u8 sWaveBeamGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/wave_beam_charged_bottom.gfx");

static const u16 sWaveBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x80, 2, 0)
};

static const u16 sWaveBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0xa0, 2, 0)
};

static const u16 sWaveBeamOam_Horizontal_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, 4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(-5, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(13, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0xa0, 2, 0)
};

static const u16 sWaveBeamOam_Horizontal_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(-5, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x80, 2, 0)
};

static const u16 sWaveBeamOam_Horizontal_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-5, -13, OAM_DIMS_16x8, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(-5, 5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(-5, -17, OAM_DIMS_16x8, OAM_NO_FLIP, 0xa0, 2, 0),
    OAM_ENTRY(-5, 9, OAM_DIMS_16x8, OAM_NO_FLIP, 0xa0, 2, 0)
};

static const u16 sWaveBeamOam_Horizontal_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-5, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(-5, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0xa0, 2, 0),
    OAM_ENTRY(-5, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0xa0, 2, 0)
};

static const u16 sWaveBeamOam_Horizontal_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(-5, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0xa0, 2, 0),
    OAM_ENTRY(-5, 2, OAM_DIMS_16x8, OAM_NO_FLIP, 0xa0, 2, 0)
};

static const u16 sWaveBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0)
};

static const u16 sWaveBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-3, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(-10, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(1, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc2, 2, 0)
};

static const u16 sWaveBeamOam_Diagonal_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-1, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(-12, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(5, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc2, 2, 0)
};

static const u16 sWaveBeamOam_Diagonal_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(-15, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0)
};

static const u16 sWaveBeamOam_Diagonal_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-1, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(-13, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(3, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc2, 2, 0),
    OAM_ENTRY(-16, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc2, 2, 0)
};

static const u16 sWaveBeamOam_Diagonal_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(-9, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(1, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc2, 2, 0),
    OAM_ENTRY(-13, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc2, 2, 0)
};

static const u16 sWaveBeamOam_Diagonal_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(-2, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc2, 2, 0),
    OAM_ENTRY(-12, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc2, 2, 0)
};

static const u16 sWaveBeamOam_Vertical_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x82, 2, 0)
};

static const u16 sWaveBeamOam_Vertical_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x82, 2, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x82, 2, 0),
    OAM_ENTRY(-4, 5, OAM_DIMS_8x16, OAM_NO_FLIP, 0xc6, 2, 0)
};

static const u16 sWaveBeamOam_Vertical_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(4, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x82, 2, 0),
    OAM_ENTRY(-12, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x82, 2, 0),
    OAM_ENTRY(-4, 13, OAM_DIMS_8x16, OAM_NO_FLIP, 0xc6, 2, 0)
};

static const u16 sWaveBeamOam_Vertical_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(8, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x82, 2, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x82, 2, 0)
};

static const u16 sWaveBeamOam_Vertical_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(5, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x82, 2, 0),
    OAM_ENTRY(-13, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x82, 2, 0),
    OAM_ENTRY(9, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0xc6, 2, 0),
    OAM_ENTRY(-17, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0xc6, 2, 0)
};

static const u16 sWaveBeamOam_Vertical_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x82, 2, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x82, 2, 0),
    OAM_ENTRY(6, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0xc6, 2, 0),
    OAM_ENTRY(-14, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0xc6, 2, 0)
};

static const u16 sWaveBeamOam_Vertical_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0x82, 2, 0),
    OAM_ENTRY(2, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0xc6, 2, 0),
    OAM_ENTRY(-10, -5, OAM_DIMS_8x16, OAM_NO_FLIP, 0xc6, 2, 0)
};

static const u16 sWaveBeamOam_Horizontal_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0xee, 2, 0)
};

static const u16 sWaveBeamOam_Horizontal_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0xee, 2, 0)
};

static const u16 sWaveBeamOam_Horizontal_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-3, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(-3, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(9, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x85, 2, 0),
    OAM_ENTRY(-6, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x84, 2, 0)
};

static const u16 sWaveBeamOam_Horizontal_Unused_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(0, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(-3, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(-3, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x84, 2, 0)
};

static const u16 sWaveBeamOam_Horizontal_Unused_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(4, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(4, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(0, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x84, 2, 0)
};

static const u16 sWaveBeamOam_Horizontal_Unused_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(13, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(13, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(8, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(8, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x84, 2, 0)
};

static const u16 sWaveBeamOam_Horizontal_Unused_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(16, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(16, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(19, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x85, 2, 0),
    OAM_ENTRY(19, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x85, 2, 0)
};

static const u16 sWaveBeamOam_Diagonal_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0)
};

static const u16 sWaveBeamOam_Diagonal_Unused_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0),
    OAM_ENTRY(-6, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa5, 2, 0)
};

static const u16 sWaveBeamOam_Diagonal_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0),
    OAM_ENTRY(-8, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0),
    OAM_ENTRY(1, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa5, 2, 0),
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0)
};

static const u16 sWaveBeamOam_Diagonal_Unused_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0),
    OAM_ENTRY(-8, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0),
    OAM_ENTRY(-2, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0),
    OAM_ENTRY(-9, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0)
};

static const u16 sWaveBeamOam_Diagonal_Unused_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0),
    OAM_ENTRY(-7, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0),
    OAM_ENTRY(3, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0),
    OAM_ENTRY(-10, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0)
};

static const u16 sWaveBeamOam_Diagonal_Unused_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(12, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0),
    OAM_ENTRY(1, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0),
    OAM_ENTRY(10, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0),
    OAM_ENTRY(-4, 10, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0)
};

static const u16 sWaveBeamOam_Diagonal_Unused_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(14, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0),
    OAM_ENTRY(3, 14, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa4, 2, 0),
    OAM_ENTRY(8, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa5, 2, 0),
    OAM_ENTRY(15, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xa5, 2, 0)
};

static const u16 sWaveBeamOam_Vertical_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0)
};

static const u16 sWaveBeamOam_Vertical_Unused_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-2, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-6, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-4, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc5, 2, 0)
};

static const u16 sWaveBeamOam_Vertical_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-9, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-4, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc5, 2, 0),
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0)
};

static const u16 sWaveBeamOam_Vertical_Unused_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(5, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-13, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(2, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-10, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0)
};

static const u16 sWaveBeamOam_Vertical_Unused_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(7, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-15, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-14, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0)
};

static const u16 sWaveBeamOam_Vertical_Unused_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(5, 13, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-13, 13, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(7, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-15, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0)
};

static const u16 sWaveBeamOam_Vertical_Unused_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(3, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-11, 16, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-8, 19, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc5, 2, 0),
    OAM_ENTRY(0, 19, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc5, 2, 0)
};

static const u16 sChargedWaveBeamOam_Horizontal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x83, 2, 0)
};

static const u16 sChargedWaveBeamOam_Horizontal_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(-9, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_32x16, OAM_X_FLIP, 0x86, 2, 0)
};

static const u16 sChargedWaveBeamOam_Horizontal_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(-9, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_32x16, OAM_X_FLIP, 0x86, 2, 0)
};

static const u16 sChargedWaveBeamOam_Horizontal_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -19, OAM_DIMS_32x16, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(-5, 3, OAM_DIMS_32x16, OAM_NO_FLIP, 0x83, 2, 0)
};

static const u16 sChargedWaveBeamOam_Horizontal_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(1, -22, OAM_DIMS_32x16, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(1, 6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x83, 2, 0)
};

static const u16 sChargedWaveBeamOam_Horizontal_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(8, -19, OAM_DIMS_32x16, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(8, 3, OAM_DIMS_32x16, OAM_NO_FLIP, 0x83, 2, 0)
};

static const u16 sChargedWaveBeamOam_Horizontal_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(12, -15, OAM_DIMS_32x16, OAM_X_FLIP, 0x86, 2, 0),
    OAM_ENTRY(12, -1, OAM_DIMS_32x16, OAM_X_FLIP, 0x86, 2, 0)
};

static const u16 sChargedWaveBeamOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe7, 2, 0)
};

static const u16 sChargedWaveBeamOam_Diagonal_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-7, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(4, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe7, 2, 0),
    OAM_ENTRY(-10, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(1, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe7, 2, 0),
    OAM_ENTRY(1, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc8, 2, 0),
    OAM_ENTRY(12, 12, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe7, 2, 0)
};

static const u16 sChargedWaveBeamOam_Diagonal_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-4, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(7, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe7, 2, 0),
    OAM_ENTRY(-13, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-2, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe7, 2, 0),
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe7, 2, 0),
    OAM_ENTRY(7, 7, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc8, 2, 0),
    OAM_ENTRY(18, 18, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe7, 2, 0)
};

static const u16 sChargedWaveBeamOam_Diagonal_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(2, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(13, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe7, 2, 0),
    OAM_ENTRY(-14, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-3, 13, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe7, 2, 0)
};

static const u16 sChargedWaveBeamOam_Diagonal_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(6, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(17, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe7, 2, 0),
    OAM_ENTRY(-13, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-2, 17, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe7, 2, 0)
};

static const u16 sChargedWaveBeamOam_Diagonal_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(11, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(22, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe7, 2, 0),
    OAM_ENTRY(-5, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(6, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe7, 2, 0)
};

static const u16 sChargedWaveBeamOam_Diagonal_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(12, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc8, 2, 0),
    OAM_ENTRY(23, 13, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe7, 2, 0),
    OAM_ENTRY(3, 11, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc8, 2, 0),
    OAM_ENTRY(14, 22, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe7, 2, 0)
};

static const u16 sChargedWaveBeamOam_Vertical_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8a, 2, 0)
};

static const u16 sChargedWaveBeamOam_Vertical_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -9, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(-10, -9, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(-8, 4, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8c, 2, 0)
};

static const u16 sChargedWaveBeamOam_Vertical_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -9, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(-14, -9, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(-8, -13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8c, 2, 0)
};

static const u16 sChargedWaveBeamOam_Vertical_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(3, -5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(-19, -5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8a, 2, 0)
};

static const u16 sChargedWaveBeamOam_Vertical_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(6, 1, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(-22, 1, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8a, 2, 0)
};

static const u16 sChargedWaveBeamOam_Vertical_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(3, 8, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(-19, 8, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8a, 2, 0)
};

static const u16 sChargedWaveBeamOam_Vertical_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-1, 12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8c, 2, 0),
    OAM_ENTRY(-15, 12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8c, 2, 0)
};

static const u16 sParticleChargedWaveBeamTrailOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc7, 2, 0)
};

static const u16 sParticleChargedWaveBeamTrailOam_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x8e, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 0x8e, 2, 0)
};

static const u16 sParticleChargedWaveBeamTrailOam_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xae, 2, 0)
};

static const u16 sParticleChargedWaveBeamTrailOam_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0xee, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 0xee, 2, 0)
};

const struct FrameData sWaveBeamOam_Horizontal[8] = {
    [0] = {
        .pFrame = sWaveBeamOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sWaveBeamOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sWaveBeamOam_Horizontal_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sWaveBeamOam_Horizontal_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sWaveBeamOam_Horizontal_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sWaveBeamOam_Horizontal_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sWaveBeamOam_Horizontal_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaveBeamOam_Diagonal[8] = {
    [0] = {
        .pFrame = sWaveBeamOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sWaveBeamOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sWaveBeamOam_Diagonal_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sWaveBeamOam_Diagonal_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sWaveBeamOam_Diagonal_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sWaveBeamOam_Diagonal_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sWaveBeamOam_Diagonal_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaveBeamOam_Vertical[8] = {
    [0] = {
        .pFrame = sWaveBeamOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sWaveBeamOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sWaveBeamOam_Vertical_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sWaveBeamOam_Vertical_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sWaveBeamOam_Vertical_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sWaveBeamOam_Vertical_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sWaveBeamOam_Vertical_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaveBeamOam_Horizontal_Unused[8] = {
    [0] = {
        .pFrame = sWaveBeamOam_Horizontal_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sWaveBeamOam_Horizontal_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sWaveBeamOam_Horizontal_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sWaveBeamOam_Horizontal_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sWaveBeamOam_Horizontal_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sWaveBeamOam_Horizontal_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sWaveBeamOam_Horizontal_Unused_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaveBeamOam_Diagonal_Unused[8] = {
    [0] = {
        .pFrame = sWaveBeamOam_Diagonal_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sWaveBeamOam_Diagonal_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sWaveBeamOam_Diagonal_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sWaveBeamOam_Diagonal_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sWaveBeamOam_Diagonal_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sWaveBeamOam_Diagonal_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sWaveBeamOam_Diagonal_Unused_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sWaveBeamOam_Vertical_Unused[8] = {
    [0] = {
        .pFrame = sWaveBeamOam_Vertical_Unused_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sWaveBeamOam_Vertical_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sWaveBeamOam_Vertical_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sWaveBeamOam_Vertical_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sWaveBeamOam_Vertical_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sWaveBeamOam_Vertical_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sWaveBeamOam_Vertical_Unused_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedWaveBeamOam_Horizontal[8] = {
    [0] = {
        .pFrame = sChargedWaveBeamOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sChargedWaveBeamOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sChargedWaveBeamOam_Horizontal_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sChargedWaveBeamOam_Horizontal_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sChargedWaveBeamOam_Horizontal_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sChargedWaveBeamOam_Horizontal_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sChargedWaveBeamOam_Horizontal_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedWaveBeamOam_Diagonal[8] = {
    [0] = {
        .pFrame = sChargedWaveBeamOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sChargedWaveBeamOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sChargedWaveBeamOam_Diagonal_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sChargedWaveBeamOam_Diagonal_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sChargedWaveBeamOam_Diagonal_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sChargedWaveBeamOam_Diagonal_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sChargedWaveBeamOam_Diagonal_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedWaveBeamOam_Vertical[8] = {
    [0] = {
        .pFrame = sChargedWaveBeamOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sChargedWaveBeamOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sChargedWaveBeamOam_Vertical_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sChargedWaveBeamOam_Vertical_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sChargedWaveBeamOam_Vertical_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sChargedWaveBeamOam_Vertical_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sChargedWaveBeamOam_Vertical_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleChargedWaveBeamTrailOam[5] = {
    [0] = {
        .pFrame = sParticleChargedWaveBeamTrailOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleChargedWaveBeamTrailOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleChargedWaveBeamTrailOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleChargedWaveBeamTrailOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const u8 sPlasmaBeamGfx_Top[512] = INCBIN_U8("data/weapons/plasma_beam_top.gfx");
const u8 sPlasmaBeamGfx_Bottom[512] = INCBIN_U8("data/weapons/plasma_beam_bottom.gfx");
const u8 sPlasmaBeamGfx_Charged_Top[512] = INCBIN_U8("data/weapons/plasma_beam_charged_top.gfx");
const u8 sPlasmaBeamGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/plasma_beam_charged_bottom.gfx");

static const u16 sPlasmaBeamOam_Horizontal_NoWave_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe0, 2, 0)
};

static const u16 sPlasmaBeamOam_Horizontal_NoWave_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe4, 2, 0)
};

static const u16 sPlasmaBeamOam_Diagonal_NoWave_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8e, 2, 0)
};

static const u16 sPlasmaBeamOam_Diagonal_NoWave_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0xce, 2, 0)
};

static const u16 sPlasmaBeamOam_Vertical_NoWave_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x83, 2, 0)
};

static const u16 sPlasmaBeamOam_Vertical_NoWave_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -7, OAM_DIMS_8x32, OAM_NO_FLIP, 0x87, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Horizontal_NoWave_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0xca, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x8, OAM_Y_FLIP, 0xca, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Horizontal_NoWave_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-10, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0xca, 2, 0),
    OAM_ENTRY(2, 0, OAM_DIMS_32x8, OAM_Y_FLIP, 0xca, 2, 0),
    OAM_ENTRY(12, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0xca, 2, 0),
    OAM_ENTRY(12, 0, OAM_DIMS_32x8, OAM_Y_FLIP, 0xca, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Diagonal_NoWave_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(2, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa1, 2, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(7, 7, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa5, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Diagonal_NoWave_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa1, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa5, 2, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(16, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa5, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Vertical_NoWave_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x88, 2, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x32, OAM_X_FLIP, 0x88, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x89, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x32, OAM_X_FLIP, 0x89, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Vertical_NoWave_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(0, -10, OAM_DIMS_8x32, OAM_NO_FLIP, 0x88, 2, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_8x32, OAM_X_FLIP, 0x88, 2, 0),
    OAM_ENTRY(0, 2, OAM_DIMS_8x32, OAM_NO_FLIP, 0x89, 2, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_8x32, OAM_X_FLIP, 0x89, 2, 0),
    OAM_ENTRY(0, 12, OAM_DIMS_8x32, OAM_NO_FLIP, 0x89, 2, 0),
    OAM_ENTRY(-8, 12, OAM_DIMS_8x32, OAM_X_FLIP, 0x89, 2, 0)
};

static const u16 sPlasmaBeamOam_Horizontal_Wave_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe0, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe0, 2, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe4, 2, 0)
};

static const u16 sPlasmaBeamOam_Horizontal_Wave_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe0, 2, 0),
    OAM_ENTRY(-8, 4, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe0, 2, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe4, 2, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe0, 2, 0)
};

static const u16 sPlasmaBeamOam_Horizontal_Wave_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe0, 2, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe0, 2, 0),
    OAM_ENTRY(-7, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe4, 2, 0)
};

static const u16 sPlasmaBeamOam_Horizontal_Wave_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -13, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe0, 2, 0),
    OAM_ENTRY(-8, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe0, 2, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe4, 2, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe4, 2, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe0, 2, 0)
};

static const u16 sPlasmaBeamOam_Horizontal_Wave_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe0, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe0, 2, 0),
    OAM_ENTRY(-8, -13, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe4, 2, 0),
    OAM_ENTRY(-8, 5, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe4, 2, 0)
};

static const u16 sPlasmaBeamOam_Horizontal_Wave_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe0, 2, 0),
    OAM_ENTRY(-8, -10, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe4, 2, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_32x8, OAM_NO_FLIP, 0xe4, 2, 0)
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-3, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8e, 2, 0),
    OAM_ENTRY(-9, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8e, 2, 0),
    OAM_ENTRY(5, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 0xce, 2, 0)
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8e, 2, 0),
    OAM_ENTRY(-11, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8e, 2, 0),
    OAM_ENTRY(12, 12, OAM_DIMS_16x16, OAM_NO_FLIP, 0xce, 2, 0),
    OAM_ENTRY(-5, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8e, 2, 0)
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(4, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8e, 2, 0),
    OAM_ENTRY(-14, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8e, 2, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0xce, 2, 0)
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-12, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8e, 2, 0),
    OAM_ENTRY(2, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8e, 2, 0),
    OAM_ENTRY(-16, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 0xce, 2, 0),
    OAM_ENTRY(6, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0xce, 2, 0),
    OAM_ENTRY(-5, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8e, 2, 0)
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8e, 2, 0),
    OAM_ENTRY(-3, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8e, 2, 0),
    OAM_ENTRY(-13, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0xce, 2, 0),
    OAM_ENTRY(3, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0xce, 2, 0)
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8e, 2, 0),
    OAM_ENTRY(-9, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0xce, 2, 0),
    OAM_ENTRY(-1, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0xce, 2, 0)
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(0, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(-4, 6, OAM_DIMS_8x32, OAM_NO_FLIP, 0x87, 2, 0)
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(4, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(-4, 16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x87, 2, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x83, 2, 0)
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(8, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(-4, -7, OAM_DIMS_8x32, OAM_NO_FLIP, 0x87, 2, 0)
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(5, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(9, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x87, 2, 0),
    OAM_ENTRY(-17, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x87, 2, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x83, 2, 0)
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(5, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x87, 2, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x87, 2, 0)
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Frame6[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x83, 2, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x87, 2, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x87, 2, 0)
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Unused_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(3, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8e, 2, 0),
    OAM_ENTRY(-9, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8e, 2, 0),
    OAM_ENTRY(-3, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8f, 2, 0),
    OAM_ENTRY(-10, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8f, 2, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8f, 2, 0),
    OAM_ENTRY(1, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8e, 2, 0)
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Unused_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(7, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8f, 2, 0),
    OAM_ENTRY(-5, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8f, 2, 0),
    OAM_ENTRY(5, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8f, 2, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x8e, 2, 0)
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Unused_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-2, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-6, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x86, 2, 0)
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Unused_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-7, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(4, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-12, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-4, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0)
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Unused_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(6, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-14, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(2, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x86, 2, 0),
    OAM_ENTRY(-10, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x86, 2, 0),
    OAM_ENTRY(-4, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x86, 2, 0)
};

static const u16 sPlasmaBeamOam_Vertical_Wave_Unused_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(6, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x86, 2, 0),
    OAM_ENTRY(-14, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x86, 2, 0),
    OAM_ENTRY(-4, 11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x86, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Horizontal_Wave_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Horizontal_Wave_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(-9, -5, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(4, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0xca, 2, 0),
    OAM_ENTRY(4, 0, OAM_DIMS_32x8, OAM_Y_FLIP, 0xca, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Horizontal_Wave_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(-9, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(-13, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0xca, 2, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_32x8, OAM_Y_FLIP, 0xca, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Horizontal_Wave_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -19, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(-5, 3, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Horizontal_Wave_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -22, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(1, 6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0xca, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x8, OAM_Y_FLIP, 0xca, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Horizontal_Wave_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(8, -19, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(8, 3, OAM_DIMS_32x16, OAM_NO_FLIP, 0x8a, 2, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0xca, 2, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_32x8, OAM_Y_FLIP, 0xca, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Horizontal_Wave_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(12, -15, OAM_DIMS_32x8, OAM_NO_FLIP, 0xca, 2, 0),
    OAM_ENTRY(12, -7, OAM_DIMS_32x8, OAM_Y_FLIP, 0xca, 2, 0),
    OAM_ENTRY(12, -1, OAM_DIMS_32x8, OAM_NO_FLIP, 0xca, 2, 0),
    OAM_ENTRY(12, 7, OAM_DIMS_32x8, OAM_Y_FLIP, 0xca, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Diagonal_Wave_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(1, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa1, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Diagonal_Wave_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-7, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(1, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa1, 2, 0),
    OAM_ENTRY(-10, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(-2, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa1, 2, 0),
    OAM_ENTRY(1, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(9, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa5, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Diagonal_Wave_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-4, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(4, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa1, 2, 0),
    OAM_ENTRY(-13, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(-5, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa1, 2, 0),
    OAM_ENTRY(-12, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa1, 2, 0),
    OAM_ENTRY(7, 7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(15, 15, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa5, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Diagonal_Wave_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(2, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(10, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa1, 2, 0),
    OAM_ENTRY(-14, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(-6, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa1, 2, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa1, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Diagonal_Wave_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(6, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(14, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa1, 2, 0),
    OAM_ENTRY(-13, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(-5, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa1, 2, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa5, 2, 0)
};

static const u16 sPlasmaBeamOam_Horizontal_Wave_Unused_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(10, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(18, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa1, 2, 0),
    OAM_ENTRY(-6, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(2, 18, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa1, 2, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(16, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa5, 2, 0)
};

static const u16 sPlasmaBeamOam_Horizontal_Wave_Unused_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(12, 2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(20, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa5, 2, 0),
    OAM_ENTRY(2, 12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x84, 2, 0),
    OAM_ENTRY(10, 20, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa5, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Vertical_Wave_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -7, OAM_DIMS_8x32, OAM_NO_FLIP, 0x88, 2, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_8x32, OAM_X_FLIP, 0x88, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Vertical_Wave_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(2, -9, OAM_DIMS_8x32, OAM_NO_FLIP, 0x88, 2, 0),
    OAM_ENTRY(-6, -9, OAM_DIMS_8x32, OAM_X_FLIP, 0x88, 2, 0),
    OAM_ENTRY(-3, -9, OAM_DIMS_8x32, OAM_NO_FLIP, 0x88, 2, 0),
    OAM_ENTRY(-11, -9, OAM_DIMS_8x32, OAM_X_FLIP, 0x88, 2, 0),
    OAM_ENTRY(0, 4, OAM_DIMS_8x32, OAM_NO_FLIP, 0x89, 2, 0),
    OAM_ENTRY(-8, 4, OAM_DIMS_8x32, OAM_X_FLIP, 0x89, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Vertical_Wave_Frame2[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(6, -9, OAM_DIMS_8x32, OAM_NO_FLIP, 0x88, 2, 0),
    OAM_ENTRY(-2, -9, OAM_DIMS_8x32, OAM_X_FLIP, 0x88, 2, 0),
    OAM_ENTRY(-6, -9, OAM_DIMS_8x32, OAM_NO_FLIP, 0x88, 2, 0),
    OAM_ENTRY(-14, -9, OAM_DIMS_8x32, OAM_X_FLIP, 0x88, 2, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x32, OAM_NO_FLIP, 0x88, 2, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_8x32, OAM_X_FLIP, 0x88, 2, 0),
    OAM_ENTRY(0, 16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x89, 2, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_8x32, OAM_X_FLIP, 0x89, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Vertical_Wave_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(11, -3, OAM_DIMS_8x32, OAM_NO_FLIP, 0x88, 2, 0),
    OAM_ENTRY(3, -3, OAM_DIMS_8x32, OAM_X_FLIP, 0x88, 2, 0),
    OAM_ENTRY(-11, -3, OAM_DIMS_8x32, OAM_NO_FLIP, 0x88, 2, 0),
    OAM_ENTRY(-19, -3, OAM_DIMS_8x32, OAM_X_FLIP, 0x88, 2, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x88, 2, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x32, OAM_X_FLIP, 0x88, 2, 0)
};

static const u16 sChargedPlasmaBeamOam_Vertical_Wave_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(14, 1, OAM_DIMS_8x32, OAM_NO_FLIP, 0x88, 2, 0),
    OAM_ENTRY(6, 1, OAM_DIMS_8x32, OAM_X_FLIP, 0x88, 2, 0),
    OAM_ENTRY(-14, 1, OAM_DIMS_8x32, OAM_NO_FLIP, 0x88, 2, 0),
    OAM_ENTRY(-22, 1, OAM_DIMS_8x32, OAM_X_FLIP, 0x88, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x89, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x32, OAM_X_FLIP, 0x89, 2, 0)
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Unused_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(11, 8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x88, 2, 0),
    OAM_ENTRY(3, 8, OAM_DIMS_8x32, OAM_X_FLIP, 0x88, 2, 0),
    OAM_ENTRY(-11, 8, OAM_DIMS_8x32, OAM_NO_FLIP, 0x88, 2, 0),
    OAM_ENTRY(-19, 8, OAM_DIMS_8x32, OAM_X_FLIP, 0x88, 2, 0),
    OAM_ENTRY(0, 16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x89, 2, 0),
    OAM_ENTRY(-8, 16, OAM_DIMS_8x32, OAM_X_FLIP, 0x89, 2, 0)
};

static const u16 sPlasmaBeamOam_Diagonal_Wave_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, 12, OAM_DIMS_8x32, OAM_NO_FLIP, 0x89, 2, 0),
    OAM_ENTRY(-15, 12, OAM_DIMS_8x32, OAM_X_FLIP, 0x89, 2, 0),
    OAM_ENTRY(7, 12, OAM_DIMS_8x32, OAM_NO_FLIP, 0x89, 2, 0),
    OAM_ENTRY(-1, 12, OAM_DIMS_8x32, OAM_X_FLIP, 0x89, 2, 0)
};

static const u16 sParticleChargedPlasmaBeamTrailOam_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xea, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0xea, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0xea, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 0xea, 2, 0)
};

static const u16 sParticleChargedFullBeamTrailOam_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0xea, 2, 0),
    OAM_ENTRY(-1, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0xea, 2, 0),
    OAM_ENTRY(-7, -1, OAM_DIMS_8x8, OAM_Y_FLIP, 0xea, 2, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_8x8, OAM_XY_FLIP, 0xea, 2, 0)
};

static const u16 sParticleChargedPlasmaBeamTrailOam_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0xeb, 2, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0xeb, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 0xeb, 2, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 0xeb, 2, 0)
};

static const u16 sParticleChargedFullBeamTrailOam_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0xeb, 2, 0),
    OAM_ENTRY(-1, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0xeb, 2, 0),
    OAM_ENTRY(-7, -1, OAM_DIMS_8x8, OAM_Y_FLIP, 0xeb, 2, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_8x8, OAM_XY_FLIP, 0xeb, 2, 0)
};

static const u16 sParticleChargedPlasmaBeamTrailOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc0, 2, 0)
};

static const u16 sParticleChargedFullBeamTrailOam_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x82, 2, 0)
};

static const u16 sParticleChargedFullBeamTrailOam_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xc4, 2, 0)
};

static const u16 sParticleChargedPlasmaBeamTrailOam_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x86, 2, 0)
};

const struct FrameData sPlasmaBeamOam_Horizontal_NoWave[3] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Horizontal_NoWave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Horizontal_NoWave_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Diagonal_NoWave[3] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Diagonal_NoWave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Diagonal_NoWave_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Vertical_NoWave[3] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Vertical_NoWave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Vertical_NoWave_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Horizontal_NoWave_Unused[3] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame6,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Diagonal_NoWave_Unused[3] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame6,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Vertical_NoWave_Unused[3] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame6,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPlasmaBeamOam_Horizontal_NoWave[3] = {
    [0] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_NoWave_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_NoWave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPlasmaBeamOam_Diagonal_NoWave[3] = {
    [0] = {
        .pFrame = sChargedPlasmaBeamOam_Diagonal_NoWave_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedPlasmaBeamOam_Diagonal_NoWave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPlasmaBeamOam_Vertical_NoWave[3] = {
    [0] = {
        .pFrame = sChargedPlasmaBeamOam_Vertical_NoWave_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedPlasmaBeamOam_Vertical_NoWave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Horizontal_Wave[8] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Horizontal_NoWave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Diagonal_Wave[8] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Diagonal_NoWave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Vertical_Wave[8] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Vertical_NoWave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Horizontal_Wave_Unused[6] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Diagonal_Wave_Unused[6] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPlasmaBeamOam_Vertical_Wave_Unused[6] = {
    [0] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Frame5,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sPlasmaBeamOam_Vertical_Wave_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPlasmaBeamOam_Horizontal_Wave[8] = {
    [0] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sChargedPlasmaBeamOam_Horizontal_Wave_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPlasmaBeamOam_Diagonal_Wave[8] = {
    [0] = {
        .pFrame = sChargedPlasmaBeamOam_Diagonal_Wave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sChargedPlasmaBeamOam_Diagonal_Wave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sChargedPlasmaBeamOam_Diagonal_Wave_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sChargedPlasmaBeamOam_Diagonal_Wave_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sChargedPlasmaBeamOam_Diagonal_Wave_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sPlasmaBeamOam_Horizontal_Wave_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPlasmaBeamOam_Vertical_Wave[8] = {
    [0] = {
        .pFrame = sChargedPlasmaBeamOam_Vertical_Wave_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sChargedPlasmaBeamOam_Vertical_Wave_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sChargedPlasmaBeamOam_Vertical_Wave_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sChargedPlasmaBeamOam_Vertical_Wave_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sChargedPlasmaBeamOam_Vertical_Wave_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sPlasmaBeamOam_Diagonal_Wave_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleChargedPlasmaBeamTrailOam[5] = {
    [0] = {
        .pFrame = sParticleChargedPlasmaBeamTrailOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleChargedPlasmaBeamTrailOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleChargedPlasmaBeamTrailOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleChargedPlasmaBeamTrailOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleChargedFullBeamTrailOam[9] = {
    [0] = {
        .pFrame = sParticleChargedPlasmaBeamTrailOam_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sParticleChargedFullBeamTrailOam_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = {
        .pFrame = sParticleChargedPlasmaBeamTrailOam_Frame2,
        .timer = CONVERT_SECONDS(.05f)
    },
    [3] = {
        .pFrame = sParticleChargedFullBeamTrailOam_Frame3,
        .timer = CONVERT_SECONDS(.05f)
    },
    [4] = {
        .pFrame = sParticleChargedPlasmaBeamTrailOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sParticleChargedFullBeamTrailOam_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sParticleChargedFullBeamTrailOam_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sParticleChargedPlasmaBeamTrailOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const u8 sPistolGfx_Top[512] = INCBIN_U8("data/weapons/pistol_top.gfx");
const u8 sPistolGfx_Bottom[512] = INCBIN_U8("data/weapons/pistol_bottom.gfx");
const u8 sPistolGfx_Charged_Top[512] = INCBIN_U8("data/weapons/pistol_charged_top.gfx");
const u8 sPistolGfx_Charged_Bottom[512] = INCBIN_U8("data/weapons/pistol_charged_bottom.gfx");

static const u16 sPistolOam_Horizontal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-6, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x80, 2, 0)
};

static const u16 sPistolOam_Horizontal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-6, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0xa0, 2, 0)
};

static const u16 sPistolOam_Diagonal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x82, 2, 0)
};

static const u16 sPistolOam_Diagonal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-7, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x84, 2, 0)
};

static const u16 sPistolOam_Vertical_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x86, 2, 0)
};

static const u16 sPistolOam_Vertical_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x87, 2, 0)
};

static const u16 sChargedPistolOam_Horizontal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-6, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc2, 2, 0)
};

static const u16 sChargedPistolOam_Horizontal_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc2, 2, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(9, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc2, 2, 0)
};

static const u16 sChargedPistolOam_Diagonal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(-2, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc6, 2, 0)
};

static const u16 sChargedPistolOam_Diagonal_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-6, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc6, 2, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc4, 2, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc6, 2, 0)
};

static const u16 sChargedPistolOam_Vertical_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc8, 2, 0),
    OAM_ENTRY(-8, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0xca, 2, 0)
};

static const u16 sChargedPistolOam_Vertical_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xca, 2, 0),
    OAM_ENTRY(-8, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc8, 2, 0),
    OAM_ENTRY(-8, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0xca, 2, 0)
};

static const u16 sParticleChargedPistolTrailOam_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xce, 2, 0)
};

static const u16 sParticleChargedPistolTrailOam_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xcf, 2, 0)
};

static const u16 sParticleChargedPistolTrailOam_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xee, 2, 0)
};

static const u16 sParticleChargedPistolTrailOam_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0xef, 2, 0)
};

const struct FrameData sPistolOam_Horizontal[3] = {
    [0] = {
        .pFrame = sPistolOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPistolOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPistolOam_Diagonal[3] = {
    [0] = {
        .pFrame = sPistolOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPistolOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPistolOam_Vertical[3] = {
    [0] = {
        .pFrame = sPistolOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(.05f)
    },
    [1] = {
        .pFrame = sPistolOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPistolOam_Horizontal[3] = {
    [0] = {
        .pFrame = sChargedPistolOam_Horizontal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedPistolOam_Horizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPistolOam_Diagonal[3] = {
    [0] = {
        .pFrame = sChargedPistolOam_Diagonal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedPistolOam_Diagonal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChargedPistolOam_Vertical[3] = {
    [0] = {
        .pFrame = sChargedPistolOam_Vertical_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sChargedPistolOam_Vertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleChargedPistolTrailOam[5] = {
    [0] = {
        .pFrame = sParticleChargedPistolTrailOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sParticleChargedPistolTrailOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sParticleChargedPistolTrailOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sParticleChargedPistolTrailOam_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleEscapeOam_Unused[2] = {
    [0] = {
        .pFrame = gParticleEscapeOamFrames,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sParticleSamusReflectionOam_Unused[2] = {
    [0] = {
        .pFrame = gParticleSamusReflectionOamFrames,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
