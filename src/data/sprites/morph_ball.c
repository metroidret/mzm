#include "data/sprites/morph_ball.h"
#include "macros.h"

const u32 sMorphBallGfx[168] = INCBIN_U32("data/sprites/MorphBall.gfx.lz");
const u16 sMorphBallPal[16] = INCBIN_U16("data/sprites/MorphBall.pal");

static const u16 sMorphBallOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sMorphBallOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sMorphBallOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sMorphBallOutsideOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sMorphBallOutsideOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sMorphBallOutsideOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 522, 8, 0),
};

static const u16 sMorphBallOutsideOam_Idle_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 524, 8, 0),
};

static const u16 sMorphBallOutsideOam_Idle_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 526, 8, 0),
};

const struct FrameData sMorphBallOam_Idle[5] = {
    [0] = {
        .pFrame = sMorphBallOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sMorphBallOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sMorphBallOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [3] = {
        .pFrame = sMorphBallOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMorphBallOutsideOam_Idle[6] = {
    [0] = {
        .pFrame = sMorphBallOutsideOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(1.f) + CONVERT_SECONDS(2.f / 3)
    },
    [1] = {
        .pFrame = sMorphBallOutsideOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sMorphBallOutsideOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sMorphBallOutsideOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sMorphBallOutsideOam_Idle_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = FRAME_DATA_TERMINATOR
};
