#include "data/sprites/morph_ball_launcher.h"
#include "macros.h"

const u32 sMorphBallLauncherGfx[303] = INCBIN_U32("data/sprites/morph_ball_launcher.gfx.lz");
const u16 sMorphBallLauncherPal[16] = INCBIN_U16("data/sprites/morph_ball_launcher.pal");

static const u16 sMorphBallLauncherOam_Idle_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-12, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(4, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-28, 15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-12, 15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-26, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(12, 15, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(4, 15, OAM_DIMS_8x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 8, 0)
};

static const u16 sMorphBallLauncherOam_Idle_Frame1[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20d, 8, 0),
    OAM_ENTRY(-28, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(12, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-12, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(4, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-28, 15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-12, 15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-26, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(12, 15, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(4, 15, OAM_DIMS_8x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 8, 0)
};

static const u16 sMorphBallLauncherOam_Idle_Frame2[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-28, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(12, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-12, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(4, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-28, 15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-12, 15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-26, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(12, 15, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(4, 15, OAM_DIMS_8x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 8, 0)
};

static const u16 sMorphBallLauncherOam_Launching_Frame0[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20f, 8, 0),
    OAM_ENTRY(-12, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(4, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-28, 15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-12, 15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-26, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(12, 15, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(4, 15, OAM_DIMS_8x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 8, 0)
};

static const u16 sMorphBallLauncherOam_Launching_Frame1[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-28, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(12, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-12, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(4, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-28, 15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-12, 15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-26, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(12, 15, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(4, 15, OAM_DIMS_8x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 8, 0)
};

static const u16 sMorphBallLauncherOam_Launching_Frame2[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22d, 8, 0),
    OAM_ENTRY(-28, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(12, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-12, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(4, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-28, 15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-12, 15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-26, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(12, 15, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(4, 15, OAM_DIMS_8x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 8, 0)
};

static const u16 sMorphBallLauncherOam_Launching_Frame3[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22f, 8, 0),
    OAM_ENTRY(-28, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x225, 8, 0),
    OAM_ENTRY(12, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x225, 8, 0),
    OAM_ENTRY(-12, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(4, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-28, 15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-12, 15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-26, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(12, 15, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(4, 15, OAM_DIMS_8x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 8, 0)
};

static const u16 sMorphBallLauncherOam_Launching_Frame4[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(-28, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x239, 8, 0),
    OAM_ENTRY(12, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x239, 8, 0),
    OAM_ENTRY(-12, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x222, 8, 0),
    OAM_ENTRY(4, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x222, 8, 0),
    OAM_ENTRY(-28, 15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-12, 15, OAM_DIMS_8x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-26, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-24, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x205, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(12, 15, OAM_DIMS_16x16, OAM_X_FLIP, 0x208, 8, 0),
    OAM_ENTRY(4, 15, OAM_DIMS_8x16, OAM_X_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(8, 8, OAM_DIMS_16x8, OAM_X_FLIP, 0x205, 8, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_8x16, OAM_X_FLIP, 0x207, 8, 0)
};

static const u16 sMorphBallLauncherPartOam_Back_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-11, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-19, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x203, 8, 0),
    OAM_ENTRY(3, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(11, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x203, 8, 0)
};

static const u16 sMorphBallLauncherPartOam_Energy_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-20, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0)
};

static const u16 sMorphBallLauncherPartOam_Energy_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-18, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(12, -20, OAM_DIMS_8x8, OAM_X_FLIP, 0x213, 8, 0)
};

static const u16 sMorphBallLauncherPartOam_Energy_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(10, -18, OAM_DIMS_8x8, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-20, 12, OAM_DIMS_8x8, OAM_Y_FLIP, 0x213, 8, 0),
    OAM_ENTRY(12, -2, OAM_DIMS_8x8, OAM_X_FLIP, 0x213, 8, 0)
};

static const u16 sMorphBallLauncherPartOam_Energy_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-10, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-18, 10, OAM_DIMS_8x8, OAM_Y_FLIP, 0x214, 8, 0),
    OAM_ENTRY(12, 12, OAM_DIMS_8x8, OAM_XY_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-3, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(10, -3, OAM_DIMS_8x8, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-20, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0)
};

static const u16 sMorphBallLauncherPartOam_Energy_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(2, -10, OAM_DIMS_8x8, OAM_X_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x215, 8, 0),
    OAM_ENTRY(10, 10, OAM_DIMS_8x8, OAM_XY_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 0x217, 8, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_16x8, OAM_X_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-18, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0)
};

static const u16 sMorphBallLauncherPartOam_Energy_Frame5[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-10, 2, OAM_DIMS_8x8, OAM_Y_FLIP, 0x233, 8, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-3, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-12, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-12, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-4, 4, OAM_DIMS_16x8, OAM_XY_FLIP, 0x219, 8, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x16, OAM_XY_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(2, -5, OAM_DIMS_8x8, OAM_X_FLIP, 0x237, 8, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x237, 8, 0)
};

static const u16 sMorphBallLauncherPartOam_Energy_Frame6[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(2, 2, OAM_DIMS_8x8, OAM_XY_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x16, OAM_XY_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-10, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x237, 8, 0)
};

static const u16 sMorphBallLauncherPartOam_Energy_Frame7[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23e, 8, 0),
    OAM_ENTRY(-8, 8, OAM_DIMS_16x8, OAM_Y_FLIP, 0x23e, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x16, OAM_XY_FLIP, 0x21d, 8, 0)
};

const struct FrameData sMorphBallLauncherOam_Idle[5] = {
    [0] = {
        .pFrame = sMorphBallLauncherOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sMorphBallLauncherOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sMorphBallLauncherOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [3] = {
        .pFrame = sMorphBallLauncherOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMorphBallLauncherOam_Launching[9] = {
    [0] = {
        .pFrame = sMorphBallLauncherOam_Launching_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sMorphBallLauncherOam_Launching_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sMorphBallLauncherOam_Launching_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sMorphBallLauncherOam_Launching_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sMorphBallLauncherOam_Launching_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sMorphBallLauncherOam_Launching_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sMorphBallLauncherOam_Launching_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sMorphBallLauncherOam_Launching_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMorphBallLauncherPartOam_Back[2] = {
    [0] = {
        .pFrame = sMorphBallLauncherPartOam_Back_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMorphBallLauncherPartOam_Energy[9] = {
    [0] = {
        .pFrame = sMorphBallLauncherPartOam_Energy_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sMorphBallLauncherPartOam_Energy_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sMorphBallLauncherPartOam_Energy_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sMorphBallLauncherPartOam_Energy_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sMorphBallLauncherPartOam_Energy_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sMorphBallLauncherPartOam_Energy_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sMorphBallLauncherPartOam_Energy_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sMorphBallLauncherPartOam_Energy_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = FRAME_DATA_TERMINATOR
};
