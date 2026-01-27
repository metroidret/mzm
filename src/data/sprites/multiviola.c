#include "data/sprites/multiviola.h"
#include "macros.h"

const u32 sMultiviolaGfx[221] = INCBIN_U32("data/sprites/multiviola.gfx.lz");
const u16 sMultiviolaPal[16] = INCBIN_U16("data/sprites/multiviola.pal");

static const u16 sMultiviolaOam_Moving_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-7, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(8, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(4, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-4, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-12, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x216, 8, 0),
    OAM_ENTRY(7, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(7, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(2, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(2, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(7, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(4, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_XY_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-13, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-9, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-2, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(5, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x232, 8, 0),
    OAM_ENTRY(-17, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-13, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame5[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-13, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-13, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame6[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_Y_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-3, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-9, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-17, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame7[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(6, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-14, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20e, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame8[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -10, OAM_DIMS_16x8, OAM_NO_FLIP, 0x232, 8, 0),
    OAM_ENTRY(7, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(9, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(2, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-7, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame9[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(9, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(5, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-3, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(5, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame10[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(7, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(7, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(2, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame11[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -26, OAM_DIMS_16x16, OAM_X_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-4, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(2, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(7, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(4, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame12[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-15, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-7, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame13[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-11, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-15, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-12, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame14[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-11, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-4, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-15, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-14, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame15[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(4, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-1, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-7, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-14, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-8, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame16[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x232, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(0, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-10, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame17[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(1, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(5, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(8, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(7, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(2, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame18[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-3, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(4, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(8, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(6, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame19[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_X_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-13, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-9, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-2, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame20[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-15, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(2, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame21[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-12, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-13, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame22[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x216, 8, 0),
    OAM_ENTRY(-9, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-3, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-14, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-14, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0)
};

static const u16 sMultiviolaOam_Moving_Frame23[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0x214, 8, 0),
    OAM_ENTRY(5, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(0, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(-7, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-13, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x231, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0)
};

const struct FrameData sMultiviolaOam_Moving[57] = {
    [0] = {
        .pFrame = sMultiviolaOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sMultiviolaOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sMultiviolaOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sMultiviolaOam_Moving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sMultiviolaOam_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sMultiviolaOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sMultiviolaOam_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sMultiviolaOam_Moving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = {
        .pFrame = sMultiviolaOam_Moving_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [9] = {
        .pFrame = sMultiviolaOam_Moving_Frame9,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = {
        .pFrame = sMultiviolaOam_Moving_Frame10,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [11] = {
        .pFrame = sMultiviolaOam_Moving_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [12] = {
        .pFrame = sMultiviolaOam_Moving_Frame12,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [13] = {
        .pFrame = sMultiviolaOam_Moving_Frame13,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [14] = {
        .pFrame = sMultiviolaOam_Moving_Frame14,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [15] = {
        .pFrame = sMultiviolaOam_Moving_Frame15,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [16] = {
        .pFrame = sMultiviolaOam_Moving_Frame16,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [17] = {
        .pFrame = sMultiviolaOam_Moving_Frame17,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [18] = {
        .pFrame = sMultiviolaOam_Moving_Frame18,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [19] = {
        .pFrame = sMultiviolaOam_Moving_Frame19,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [20] = {
        .pFrame = sMultiviolaOam_Moving_Frame20,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [21] = {
        .pFrame = sMultiviolaOam_Moving_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [22] = {
        .pFrame = sMultiviolaOam_Moving_Frame22,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [23] = {
        .pFrame = sMultiviolaOam_Moving_Frame23,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [24] = {
        .pFrame = sMultiviolaOam_Moving_Frame16,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [25] = {
        .pFrame = sMultiviolaOam_Moving_Frame17,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [26] = {
        .pFrame = sMultiviolaOam_Moving_Frame18,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [27] = {
        .pFrame = sMultiviolaOam_Moving_Frame19,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [28] = {
        .pFrame = sMultiviolaOam_Moving_Frame20,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [29] = {
        .pFrame = sMultiviolaOam_Moving_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [30] = {
        .pFrame = sMultiviolaOam_Moving_Frame22,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [31] = {
        .pFrame = sMultiviolaOam_Moving_Frame23,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [32] = {
        .pFrame = sMultiviolaOam_Moving_Frame16,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [33] = {
        .pFrame = sMultiviolaOam_Moving_Frame17,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [34] = {
        .pFrame = sMultiviolaOam_Moving_Frame18,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [35] = {
        .pFrame = sMultiviolaOam_Moving_Frame19,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [36] = {
        .pFrame = sMultiviolaOam_Moving_Frame20,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [37] = {
        .pFrame = sMultiviolaOam_Moving_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [38] = {
        .pFrame = sMultiviolaOam_Moving_Frame22,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [39] = {
        .pFrame = sMultiviolaOam_Moving_Frame23,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [40] = {
        .pFrame = sMultiviolaOam_Moving_Frame16,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [41] = {
        .pFrame = sMultiviolaOam_Moving_Frame17,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [42] = {
        .pFrame = sMultiviolaOam_Moving_Frame18,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [43] = {
        .pFrame = sMultiviolaOam_Moving_Frame19,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [44] = {
        .pFrame = sMultiviolaOam_Moving_Frame12,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [45] = {
        .pFrame = sMultiviolaOam_Moving_Frame13,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [46] = {
        .pFrame = sMultiviolaOam_Moving_Frame14,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [47] = {
        .pFrame = sMultiviolaOam_Moving_Frame15,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [48] = {
        .pFrame = sMultiviolaOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [49] = {
        .pFrame = sMultiviolaOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [50] = {
        .pFrame = sMultiviolaOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [51] = {
        .pFrame = sMultiviolaOam_Moving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [52] = {
        .pFrame = sMultiviolaOam_Moving_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [53] = {
        .pFrame = sMultiviolaOam_Moving_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [54] = {
        .pFrame = sMultiviolaOam_Moving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [55] = {
        .pFrame = sMultiviolaOam_Moving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [56] = FRAME_DATA_TERMINATOR
};
