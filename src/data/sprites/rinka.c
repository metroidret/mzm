#include "data/sprites/rinka.h"
#include "macros.h"

const u32 sRinkaOrangeGfx[242] = INCBIN_U32("data/sprites/rinka_orange.gfx.lz");
const u16 sRinkaOrangePal[16] = INCBIN_U16("data/sprites/rinka_orange.pal");
const u32 sRinkaGreenGfx[242] = INCBIN_U32("data/sprites/rinka_green.gfx.lz");
const u16 sRinkaGreenPal[16] = INCBIN_U16("data/sprites/rinka_green.pal");

static const u16 sRinkaOrangeOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sRinkaOrangeOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0)
};

static const u16 sRinkaOrangeOam_Moving_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sRinkaOrangeOam_Spawning_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0)
};

static const u16 sRinkaOrangeOam_Spawning_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0)
};

static const u16 sRinkaOrangeOam_Spawning_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0)
};

static const u16 sRinkaOrangeOam_Spawning_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0)
};

static const u16 sRinkaOrangeOam_Spawning_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(7, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-9, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x233, 8, 0)
};

static const u16 sRinkaOrangeOam_Spawning_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(7, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-9, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x213, 8, 0)
};

const struct FrameData sRinkaOrangeOam_Spawning[16] = {
    [0] = {
        .pFrame = sRinkaOrangeOam_Spawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sRinkaOrangeOam_Spawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sRinkaOrangeOam_Spawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sRinkaOrangeOam_Spawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sRinkaOrangeOam_Spawning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sRinkaOrangeOam_Spawning_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sRinkaOrangeOam_Spawning_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = {
        .pFrame = sRinkaOrangeOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [8] = {
        .pFrame = sRinkaOrangeOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [9] = {
        .pFrame = sRinkaOrangeOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [10] = {
        .pFrame = sRinkaOrangeOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [11] = {
        .pFrame = sRinkaOrangeOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [12] = {
        .pFrame = sRinkaOrangeOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [13] = {
        .pFrame = sRinkaOrangeOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [14] = {
        .pFrame = sRinkaOrangeOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [15] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRinkaOrangeOam_Moving[5] = {
    [0] = {
        .pFrame = sRinkaOrangeOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sRinkaOrangeOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sRinkaOrangeOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sRinkaOrangeOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};


static const u16 sRinkaGreenOam_Moving_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sRinkaGreenOam_Moving_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0)
};

static const u16 sRinkaGreenOam_Moving_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sRinkaGreenOam_Spawning_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20b, 8, 0)
};

static const u16 sRinkaGreenOam_Spawning_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20d, 8, 0)
};

static const u16 sRinkaGreenOam_Spawning_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20f, 8, 0)
};

static const u16 sRinkaGreenOam_Spawning_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0)
};

static const u16 sRinkaGreenOam_Spawning_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(7, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-9, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x233, 8, 0)
};

static const u16 sRinkaGreenOam_Spawning_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-9, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(7, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-9, 7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x213, 8, 0)
};

const struct FrameData sRinkaGreenOam_Spawning[16] = {
    [0] = {
        .pFrame = sRinkaGreenOam_Spawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sRinkaGreenOam_Spawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sRinkaGreenOam_Spawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sRinkaGreenOam_Spawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sRinkaGreenOam_Spawning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sRinkaGreenOam_Spawning_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sRinkaGreenOam_Spawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [7] = {
        .pFrame = sRinkaGreenOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sRinkaGreenOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sRinkaGreenOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sRinkaGreenOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 12)
    },
    [11] = {
        .pFrame = sRinkaGreenOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [12] = {
        .pFrame = sRinkaGreenOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [13] = {
        .pFrame = sRinkaGreenOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [14] = {
        .pFrame = sRinkaGreenOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [15] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRinkaGreenOam_Moving[5] = {
    [0] = {
        .pFrame = sRinkaGreenOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sRinkaGreenOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sRinkaGreenOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sRinkaGreenOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};
