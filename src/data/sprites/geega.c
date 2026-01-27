#include "data/sprites/geega.h"
#include "macros.h"

const u32 sGeegaGfx[153] = INCBIN_U32("data/sprites/geega.gfx.lz");
const u16 sGeegaPal[16] = INCBIN_U16("data/sprites/geega.pal");
const u32 sGeegaWhiteGfx[153] = INCBIN_U32("data/sprites/geega_white.gfx.lz");
const u16 sGeegaWhitePal[16] = INCBIN_U16("data/sprites/geega_white.pal");

static const u16 sGeegaOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sGeegaOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0)
};

static const u16 sGeegaOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sGeegaOam_Moving_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0)
};

static const u16 sGeegaOam_Moving_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0)
};

static const u16 sGeegaOam_Moving_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0)
};

const struct FrameData sGeegaOam_Idle[5] = {
    [0] = {
        .pFrame = sGeegaOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sGeegaOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sGeegaOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sGeegaOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sGeegaOam_Moving[9] = {
    [0] = {
        .pFrame = sGeegaOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sGeegaOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sGeegaOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sGeegaOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sGeegaOam_Moving_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sGeegaOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sGeegaOam_Moving_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sGeegaOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = FRAME_DATA_TERMINATOR
};
