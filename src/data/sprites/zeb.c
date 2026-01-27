#include "data/sprites/zeb.h"
#include "macros.h"

const u32 sZebPinkGfx[162] = INCBIN_U32("data/sprites/zeb_pink.gfx.lz");
const u16 sZebPinkPal[16] = INCBIN_U16("data/sprites/zeb_pink.pal");
const u32 sZebBlueGfx[162] = INCBIN_U32("data/sprites/zeb_blue.gfx.lz");
const u16 sZebBluePal[16] = INCBIN_U16("data/sprites/zeb_blue.pal");

static const u16 sZebOam_Idle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-12, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sZebOam_Idle_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-11, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sZebOam_Idle_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-11, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-6, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0)
};

const struct FrameData sZebOam_Idle[5] = {
    [0] = {
        .pFrame = sZebOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sZebOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZebOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sZebOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZebOam_Moving[5] = {
    [0] = {
        .pFrame = sZebOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZebOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sZebOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sZebOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};
