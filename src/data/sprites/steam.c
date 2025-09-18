#include "data/sprites/steam.h"
#include "macros.h"

const u32 sSteamGfx[195] = INCBIN_U32("data/sprites/Steam.gfx.lz");
const u16 sSteamPal[16] = INCBIN_U16("data/sprites/Steam.pal");

static const u16 sSteamOam_HorizontalLarge_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSteamOam_HorizontalLarge_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_X_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sSteamOam_HorizontalLarge_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(11, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 512, 8, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_16x16, OAM_X_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSteamOam_HorizontalLarge_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(24, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 512, 8, 0),
    OAM_ENTRY(12, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 514, 8, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sSteamOam_HorizontalLarge_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 519, 8, 0),
    OAM_ENTRY(37, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 512, 8, 0),
    OAM_ENTRY(27, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 514, 8, 0),
    OAM_ENTRY(14, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(3, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sSteamOam_HorizontalLarge_Frame5[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 520, 8, 0),
    OAM_ENTRY(-3, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 514, 8, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 519, 8, 0),
};

static const u16 sSteamOam_HorizontalLarge_Frame6[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 520, 8, 0),
    OAM_ENTRY(1, 0, OAM_DIMS_8x8, OAM_X_FLIP, 520, 8, 0),
    OAM_ENTRY(51, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(13, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 519, 8, 0),
    OAM_ENTRY(21, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 519, 8, 0),
    OAM_ENTRY(13, -8, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
};

static const u16 sSteamOam_HorizontalLarge_Frame7[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(15, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 520, 8, 0),
    OAM_ENTRY(13, 0, OAM_DIMS_8x8, OAM_X_FLIP, 520, 8, 0),
    OAM_ENTRY(56, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(45, -8, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
    OAM_ENTRY(37, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(45, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 519, 8, 0),
};

static const u16 sSteamOam_HorizontalLarge_Frame8[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(26, -9, OAM_DIMS_8x8, OAM_XY_FLIP, 520, 8, 0),
    OAM_ENTRY(24, -1, OAM_DIMS_8x8, OAM_X_FLIP, 520, 8, 0),
    OAM_ENTRY(56, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 519, 8, 0),
    OAM_ENTRY(64, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 519, 8, 0),
    OAM_ENTRY(56, -8, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
};

static const u16 sSteamOam_HorizontalLarge_Frame9[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(50, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 520, 8, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_8x8, OAM_X_FLIP, 520, 8, 0),
};

static const u16 sSteamOam_VerticalLarge_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sSteamOam_VerticalLarge_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -30, OAM_DIMS_16x16, OAM_XY_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -19, OAM_DIMS_16x16, OAM_X_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSteamOam_VerticalLarge_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -45, OAM_DIMS_16x16, OAM_Y_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_XY_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sSteamOam_VerticalLarge_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 519, 8, 0),
    OAM_ENTRY(-8, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -43, OAM_DIMS_16x16, OAM_XY_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sSteamOam_VerticalLarge_Frame5[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 520, 8, 0),
    OAM_ENTRY(-3, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_XY_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x8, OAM_Y_FLIP, 519, 8, 0),
};

static const u16 sSteamOam_VerticalLarge_Frame6[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-4, -19, OAM_DIMS_8x8, OAM_XY_FLIP, 520, 8, 0),
    OAM_ENTRY(-6, -11, OAM_DIMS_8x8, OAM_X_FLIP, 520, 8, 0),
    OAM_ENTRY(-8, -66, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-8, -52, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_8x8, OAM_Y_FLIP, 519, 8, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_8x8, OAM_XY_FLIP, 519, 8, 0),
    OAM_ENTRY(-8, -36, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
};

static const u16 sSteamOam_VerticalLarge_Frame7[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-3, -27, OAM_DIMS_8x8, OAM_XY_FLIP, 520, 8, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_8x8, OAM_X_FLIP, 520, 8, 0),
    OAM_ENTRY(-8, -69, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_8x8, OAM_XY_FLIP, 519, 8, 0),
    OAM_ENTRY(-8, -44, OAM_DIMS_8x8, OAM_Y_FLIP, 519, 8, 0),
    OAM_ENTRY(0, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 519, 8, 0),
};

static const u16 sSteamOam_VerticalLarge_Frame8[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-5, -38, OAM_DIMS_8x8, OAM_Y_FLIP, 520, 8, 0),
    OAM_ENTRY(-3, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-8, -56, OAM_DIMS_8x8, OAM_Y_FLIP, 519, 8, 0),
    OAM_ENTRY(0, -60, OAM_DIMS_8x8, OAM_XY_FLIP, 519, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
};

static const u16 sSteamOam_VerticalLarge_Frame9[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-3, -52, OAM_DIMS_8x8, OAM_XY_FLIP, 520, 8, 0),
    OAM_ENTRY(-5, -44, OAM_DIMS_8x8, OAM_X_FLIP, 520, 8, 0),
};

static const u16 sSteamOam_HorizontalSmall_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -8, OAM_DIMS_8x8, OAM_X_FLIP, 521, 8, 0),
};

static const u16 sSteamOam_HorizontalSmall_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(4, -8, OAM_DIMS_8x8, OAM_X_FLIP, 521, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 521, 8, 0),
};

static const u16 sSteamOam_HorizontalSmall_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(11, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_X_FLIP, 523, 8, 0),
    OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 521, 8, 0),
};

static const u16 sSteamOam_HorizontalSmall_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(17, -8, OAM_DIMS_8x8, OAM_X_FLIP, 521, 8, 0),
    OAM_ENTRY(0, -6, OAM_DIMS_8x8, OAM_X_FLIP, 523, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_X_FLIP, 524, 8, 0),
};

static const u16 sSteamOam_HorizontalSmall_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(0, -7, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
    OAM_ENTRY(12, -8, OAM_DIMS_8x8, OAM_X_FLIP, 523, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_X_FLIP, 524, 8, 0),
    OAM_ENTRY(26, -8, OAM_DIMS_8x8, OAM_X_FLIP, 521, 8, 0),
    OAM_ENTRY(19, -8, OAM_DIMS_8x8, OAM_X_FLIP, 521, 8, 0),
};

static const u16 sSteamOam_HorizontalSmall_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
    OAM_ENTRY(22, -8, OAM_DIMS_8x8, OAM_X_FLIP, 523, 8, 0),
    OAM_ENTRY(15, -9, OAM_DIMS_8x8, OAM_X_FLIP, 524, 8, 0),
    OAM_ENTRY(10, -9, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
    OAM_ENTRY(30, -8, OAM_DIMS_8x8, OAM_X_FLIP, 523, 8, 0),
};

static const u16 sSteamOam_HorizontalSmall_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(36, -8, OAM_DIMS_8x8, OAM_X_FLIP, 524, 8, 0),
    OAM_ENTRY(26, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 524, 8, 0),
    OAM_ENTRY(12, -8, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
    OAM_ENTRY(17, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 525, 8, 0),
};

static const u16 sSteamOam_HorizontalSmall_Frame7[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(30, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 525, 8, 0),
    OAM_ENTRY(40, -8, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
    OAM_ENTRY(19, -9, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
};

static const u16 sSteamOam_VerticalSmall_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_X_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 521, 8, 0),
};

static const u16 sSteamOam_VerticalSmall_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_X_FLIP, 523, 8, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 521, 8, 0),
};

static const u16 sSteamOam_VerticalSmall_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -25, OAM_DIMS_8x8, OAM_X_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_X_FLIP, 523, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_X_FLIP, 524, 8, 0),
};

static const u16 sSteamOam_VerticalSmall_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -31, OAM_DIMS_8x8, OAM_X_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_X_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -9, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
    OAM_ENTRY(-4, -20, OAM_DIMS_8x8, OAM_X_FLIP, 523, 8, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_8x8, OAM_X_FLIP, 524, 8, 0),
};

static const u16 sSteamOam_VerticalSmall_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 525, 8, 0),
    OAM_ENTRY(-4, -28, OAM_DIMS_8x8, OAM_X_FLIP, 523, 8, 0),
    OAM_ENTRY(-4, -22, OAM_DIMS_8x8, OAM_X_FLIP, 524, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
    OAM_ENTRY(-4, -35, OAM_DIMS_8x8, OAM_X_FLIP, 523, 8, 0),
};

static const u16 sSteamOam_VerticalSmall_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -38, OAM_DIMS_8x8, OAM_X_FLIP, 524, 8, 0),
    OAM_ENTRY(-4, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-4, -14, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
    OAM_ENTRY(-4, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 525, 8, 0),
};

static const u16 sSteamOam_VerticalSmall_Frame7[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -28, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
    OAM_ENTRY(-4, -41, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
    OAM_ENTRY(-4, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 525, 8, 0),
};

const u16 sSteamDiagonalOam_Large_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 512, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 514, 8, 0),
};

const u16 sSteamDiagonalOam_Large_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(11, -24, OAM_DIMS_16x16, OAM_XY_FLIP, 512, 8, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_X_FLIP, 514, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
};

const u16 sSteamDiagonalOam_Large_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(24, -32, OAM_DIMS_16x16, OAM_Y_FLIP, 512, 8, 0),
    OAM_ENTRY(12, -24, OAM_DIMS_16x16, OAM_XY_FLIP, 514, 8, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
};

const u16 sSteamDiagonalOam_Large_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 519, 8, 0),
    OAM_ENTRY(37, -40, OAM_DIMS_16x16, OAM_Y_FLIP, 512, 8, 0),
    OAM_ENTRY(25, -32, OAM_DIMS_16x16, OAM_XY_FLIP, 514, 8, 0),
    OAM_ENTRY(14, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
};

const u16 sSteamDiagonalOam_Large_Frame5[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 520, 8, 0),
    OAM_ENTRY(-3, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(48, -48, OAM_DIMS_16x16, OAM_XY_FLIP, 514, 8, 0),
    OAM_ENTRY(32, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(16, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 519, 8, 0),
};

const u16 sSteamDiagonalOam_Large_Frame6[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(3, -16, OAM_DIMS_8x8, OAM_XY_FLIP, 520, 8, 0),
    OAM_ENTRY(1, -8, OAM_DIMS_8x8, OAM_X_FLIP, 520, 8, 0),
    OAM_ENTRY(51, -52, OAM_DIMS_16x16, OAM_X_FLIP, 516, 8, 0),
    OAM_ENTRY(31, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(13, -19, OAM_DIMS_8x8, OAM_Y_FLIP, 519, 8, 0),
    OAM_ENTRY(21, -23, OAM_DIMS_8x8, OAM_XY_FLIP, 519, 8, 0),
    OAM_ENTRY(13, -27, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
};

const u16 sSteamDiagonalOam_Large_Frame7[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(15, -24, OAM_DIMS_8x8, OAM_XY_FLIP, 520, 8, 0),
    OAM_ENTRY(13, -16, OAM_DIMS_8x8, OAM_X_FLIP, 520, 8, 0),
    OAM_ENTRY(56, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(43, -43, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
    OAM_ENTRY(35, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(43, -35, OAM_DIMS_8x8, OAM_Y_FLIP, 519, 8, 0),
};

const u16 sSteamDiagonalOam_Large_Frame8[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(26, -40, OAM_DIMS_8x8, OAM_XY_FLIP, 520, 8, 0),
    OAM_ENTRY(24, -32, OAM_DIMS_8x8, OAM_X_FLIP, 520, 8, 0),
    OAM_ENTRY(62, -54, OAM_DIMS_8x8, OAM_Y_FLIP, 519, 8, 0),
    OAM_ENTRY(70, -58, OAM_DIMS_8x8, OAM_XY_FLIP, 519, 8, 0),
    OAM_ENTRY(62, -62, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
};

const u16 sSteamDiagonalOam_Large_Frame9[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(50, -56, OAM_DIMS_8x8, OAM_XY_FLIP, 520, 8, 0),
    OAM_ENTRY(48, -48, OAM_DIMS_8x8, OAM_X_FLIP, 520, 8, 0),
};

const u16 sSteamDiagonalOam_Small_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(4, -12, OAM_DIMS_8x8, OAM_X_FLIP, 521, 8, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 521, 8, 0),
};

const u16 sSteamDiagonalOam_Small_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(11, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -6, OAM_DIMS_8x8, OAM_X_FLIP, 523, 8, 0),
    OAM_ENTRY(3, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 521, 8, 0),
};

const u16 sSteamDiagonalOam_Small_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(17, -22, OAM_DIMS_8x8, OAM_X_FLIP, 521, 8, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_8x8, OAM_X_FLIP, 523, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_X_FLIP, 524, 8, 0),
};

const u16 sSteamDiagonalOam_Small_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(0, -7, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
    OAM_ENTRY(7, -14, OAM_DIMS_8x8, OAM_X_FLIP, 523, 8, 0),
    OAM_ENTRY(4, -11, OAM_DIMS_8x8, OAM_X_FLIP, 524, 8, 0),
    OAM_ENTRY(23, -27, OAM_DIMS_8x8, OAM_X_FLIP, 521, 8, 0),
    OAM_ENTRY(14, -21, OAM_DIMS_8x8, OAM_X_FLIP, 521, 8, 0),
};

const u16 sSteamDiagonalOam_Small_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
    OAM_ENTRY(19, -23, OAM_DIMS_8x8, OAM_X_FLIP, 523, 8, 0),
    OAM_ENTRY(14, -18, OAM_DIMS_8x8, OAM_X_FLIP, 524, 8, 0),
    OAM_ENTRY(10, -13, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
    OAM_ENTRY(28, -30, OAM_DIMS_8x8, OAM_X_FLIP, 523, 8, 0),
};

const u16 sSteamDiagonalOam_Small_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(34, -36, OAM_DIMS_8x8, OAM_X_FLIP, 524, 8, 0),
    OAM_ENTRY(25, -28, OAM_DIMS_8x8, OAM_Y_FLIP, 524, 8, 0),
    OAM_ENTRY(12, -16, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
    OAM_ENTRY(17, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 525, 8, 0),
};

const u16 sSteamDiagonalOam_Small_Frame7[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(28, -32, OAM_DIMS_8x8, OAM_Y_FLIP, 525, 8, 0),
    OAM_ENTRY(38, -39, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
    OAM_ENTRY(19, -27, OAM_DIMS_8x8, OAM_X_FLIP, 525, 8, 0),
};

static const u16 sSteamOam_HorizontalLarge_Frame10[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 526, 8, 0),
};

const struct FrameData sSteamOam_HorizontalLarge[12] = {
    [0] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [9] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame9,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame10,
        .timer = TWO_THIRD_SECOND
    },
    [11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSteamOam_VerticalLarge[12] = {
    [0] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSteamOam_VerticalLarge_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSteamOam_VerticalLarge_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSteamOam_VerticalLarge_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSteamOam_VerticalLarge_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSteamOam_VerticalLarge_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sSteamOam_VerticalLarge_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sSteamOam_VerticalLarge_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sSteamOam_VerticalLarge_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [9] = {
        .pFrame = sSteamOam_VerticalLarge_Frame9,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame10,
        .timer = CONVERT_SECONDS(0.5f)
    },
    [11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSteamOam_HorizontalSmall[10] = {
    [0] = {
        .pFrame = sSteamOam_HorizontalSmall_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSteamOam_HorizontalSmall_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSteamOam_HorizontalSmall_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSteamOam_HorizontalSmall_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSteamOam_HorizontalSmall_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSteamOam_HorizontalSmall_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sSteamOam_HorizontalSmall_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sSteamOam_HorizontalSmall_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame10,
        .timer = ONE_THIRD_SECOND
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSteamOam_VerticalSmall[10] = {
    [0] = {
        .pFrame = sSteamOam_HorizontalSmall_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSteamOam_VerticalSmall_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSteamOam_VerticalSmall_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSteamOam_VerticalSmall_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSteamOam_VerticalSmall_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSteamOam_VerticalSmall_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sSteamOam_VerticalSmall_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sSteamOam_VerticalSmall_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame10,
        .timer = CONVERT_SECONDS(1.f / 6)
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSteamDiagonalOam_Large[12] = {
    [0] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSteamDiagonalOam_Large_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSteamDiagonalOam_Large_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSteamDiagonalOam_Large_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSteamDiagonalOam_Large_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSteamDiagonalOam_Large_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sSteamDiagonalOam_Large_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sSteamDiagonalOam_Large_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sSteamDiagonalOam_Large_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [9] = {
        .pFrame = sSteamDiagonalOam_Large_Frame9,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame10,
        .timer = CONVERT_SECONDS(7.f / 12)
    },
    [11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSteamDiagonalOam_Small[10] = {
    [0] = {
        .pFrame = sSteamOam_HorizontalSmall_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSteamDiagonalOam_Small_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSteamDiagonalOam_Small_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSteamDiagonalOam_Small_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSteamDiagonalOam_Small_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSteamDiagonalOam_Small_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sSteamDiagonalOam_Small_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sSteamDiagonalOam_Small_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sSteamOam_HorizontalLarge_Frame10,
        .timer = CONVERT_SECONDS(0.25f)
    },
    [9] = FRAME_DATA_TERMINATOR
};
