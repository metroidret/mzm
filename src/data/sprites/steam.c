#include "data/sprites/steam.h"
#include "macros.h"

const u32 sSteamGfx[195] = INCBIN_U32("data/sprites/Steam.gfx.lz");
const u16 sSteamPal[16] = INCBIN_U16("data/sprites/Steam.pal");

static const u16 sSteamOam_HorizontalLarge_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSteamOam_HorizontalLarge_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x200,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

static const u16 sSteamOam_HorizontalLarge_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x200,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x202,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

static const u16 sSteamOam_HorizontalLarge_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x18, OBJ_SPRITE_OAM | 0x200,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x202,
    0xf8, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x204,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

static const u16 sSteamOam_HorizontalLarge_Frame4[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xfc, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x25, OBJ_SPRITE_OAM | 0x200,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1b, OBJ_SPRITE_OAM | 0x202,
    0xf8, OBJ_SIZE_16x16 | 0xe, OBJ_SPRITE_OAM | 0x204,
    0xf8, OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x206
};

static const u16 sSteamOam_HorizontalLarge_Frame5[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf8, OBJ_Y_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x208,
    0x0, 0x1fd, OBJ_SPRITE_OAM | 0x208,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x30, OBJ_SPRITE_OAM | 0x202,
    0xf8, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0x204,
    0xf8, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x206,
    0xf8, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x207,
    0xfc, 0x0, OBJ_SPRITE_OAM | 0x207,
    0x0, OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSteamOam_HorizontalLarge_Frame6[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x3, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x208,
    0xf8, OBJ_SIZE_16x16 | 0x33, OBJ_SPRITE_OAM | 0x204,
    0xf8, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0x206,
    0x0, OBJ_Y_FLIP | 0xd, OBJ_SPRITE_OAM | 0x207,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x15, OBJ_SPRITE_OAM | 0x207,
    0xf8, OBJ_X_FLIP | 0xd, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSteamOam_HorizontalLarge_Frame7[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0xf, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | 0xd, OBJ_SPRITE_OAM | 0x208,
    0xf8, OBJ_SIZE_16x16 | 0x38, OBJ_SPRITE_OAM | 0x206,
    0xf8, OBJ_X_FLIP | 0x2d, OBJ_SPRITE_OAM | 0x207,
    0xfc, 0x25, OBJ_SPRITE_OAM | 0x207,
    0x0, OBJ_Y_FLIP | 0x2d, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSteamOam_HorizontalLarge_Frame8[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1a, OBJ_SPRITE_OAM | 0x208,
    0xff, OBJ_X_FLIP | 0x18, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_Y_FLIP | 0x38, OBJ_SPRITE_OAM | 0x207,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x40, OBJ_SPRITE_OAM | 0x207,
    0xf8, OBJ_X_FLIP | 0x38, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSteamOam_HorizontalLarge_Frame9[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x32, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | 0x30, OBJ_SPRITE_OAM | 0x208
};

static const u16 sSteamOam_VerticalLarge_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

static const u16 sSteamOam_VerticalLarge_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xe2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xed, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

static const u16 sSteamOam_VerticalLarge_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xd3, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xe0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xec, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

static const u16 sSteamOam_VerticalLarge_Frame4[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xfc, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xd5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xdf, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xef, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

static const u16 sSteamOam_VerticalLarge_Frame5[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf8, OBJ_Y_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x208,
    0x0, 0x1fd, OBJ_SPRITE_OAM | 0x208,
    0xc0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xd8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xe8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0xec, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xf0, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSteamOam_VerticalLarge_Frame6[OAM_DATA_SIZE(7)] = {
    0x7,
    0xed, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x208,
    0xf5, OBJ_X_FLIP | 0x1fa, OBJ_SPRITE_OAM | 0x208,
    0xbe, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xcc, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xe4, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xe0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0xdc, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSteamOam_VerticalLarge_Frame7[OAM_DATA_SIZE(6)] = {
    0x6,
    0xe5, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x208,
    0xed, OBJ_X_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x208,
    0xbb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xd8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0xd4, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xd0, 0x0, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSteamOam_VerticalLarge_Frame8[OAM_DATA_SIZE(5)] = {
    0x5,
    0xda, OBJ_Y_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x208,
    0xe2, 0x1fd, OBJ_SPRITE_OAM | 0x208,
    0xc8, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xc4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0xc0, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSteamOam_VerticalLarge_Frame9[OAM_DATA_SIZE(2)] = {
    0x2,
    0xcc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x208,
    0xd4, OBJ_X_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x208
};

static const u16 sSteamOam_HorizontalSmall_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x209
};

static const u16 sSteamOam_HorizontalSmall_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x209,
    0xf8, 0x1ff, OBJ_SPRITE_OAM | 0x209
};

static const u16 sSteamOam_HorizontalSmall_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, 0xb, OBJ_SPRITE_OAM | 0x209,
    0xfa, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    0xf8, 0x3, OBJ_SPRITE_OAM | 0x209
};

static const u16 sSteamOam_HorizontalSmall_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, OBJ_X_FLIP | 0x11, OBJ_SPRITE_OAM | 0x209,
    0xfa, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x20b,
    0xf8, 0x8, OBJ_SPRITE_OAM | 0x209,
    0xf8, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20c
};

static const u16 sSteamOam_HorizontalSmall_Frame4[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf9, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x20d,
    0xf8, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x20b,
    0xf8, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_X_FLIP | 0x1a, OBJ_SPRITE_OAM | 0x209,
    0xf8, OBJ_X_FLIP | 0x13, OBJ_SPRITE_OAM | 0x209
};

static const u16 sSteamOam_HorizontalSmall_Frame5[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf8, OBJ_X_FLIP | 0x3, OBJ_SPRITE_OAM | 0x20d,
    0xf8, OBJ_X_FLIP | 0x16, OBJ_SPRITE_OAM | 0x20b,
    0xf7, OBJ_X_FLIP | 0xf, OBJ_SPRITE_OAM | 0x20c,
    0xf7, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x20d,
    0xf8, OBJ_X_FLIP | 0x1e, OBJ_SPRITE_OAM | 0x20b
};

static const u16 sSteamOam_HorizontalSmall_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, OBJ_X_FLIP | 0x24, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_Y_FLIP | 0x1a, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x20d,
    0xf7, 0x11, OBJ_SPRITE_OAM | 0x20d
};

static const u16 sSteamOam_HorizontalSmall_Frame7[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, OBJ_Y_FLIP | 0x1e, OBJ_SPRITE_OAM | 0x20d,
    0xf8, OBJ_X_FLIP | 0x28, OBJ_SPRITE_OAM | 0x20d,
    0xf7, OBJ_X_FLIP | 0x13, OBJ_SPRITE_OAM | 0x20d
};

static const u16 sSteamOam_VerticalSmall_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf1, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x209
};

static const u16 sSteamOam_VerticalSmall_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xec, 0x1fb, OBJ_SPRITE_OAM | 0x209,
    0xfa, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    0xf2, 0x1fb, OBJ_SPRITE_OAM | 0x209
};

static const u16 sSteamOam_VerticalSmall_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xe7, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    0xee, 0x1fc, OBJ_SPRITE_OAM | 0x209,
    0xf4, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    0xf8, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20c
};

static const u16 sSteamOam_VerticalSmall_Frame4[OAM_DATA_SIZE(5)] = {
    0x5,
    0xe1, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    0xe8, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x209,
    0xf7, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20d,
    0xec, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    0xf1, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20c
};

static const u16 sSteamOam_VerticalSmall_Frame5[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf6, 0x1fc, OBJ_SPRITE_OAM | 0x20d,
    0xe4, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    0xea, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20c,
    0xf0, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20d,
    0xdd, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

static const u16 sSteamOam_VerticalSmall_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    0xda, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20c,
    0xe2, 0x1fc, OBJ_SPRITE_OAM | 0x20c,
    0xf2, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20d,
    0xe7, 0x1fc, OBJ_SPRITE_OAM | 0x20d
};

static const u16 sSteamOam_VerticalSmall_Frame7[OAM_DATA_SIZE(3)] = {
    0x3,
    0xe4, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20d,
    0xd7, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20d,
    0xef, 0x1fc, OBJ_SPRITE_OAM | 0x20d
};

const u16 sSteamDiagonalOam_Large_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x200,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sSteamDiagonalOam_Large_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x200,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x202,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSteamDiagonalOam_Large_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xe0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x18, OBJ_SPRITE_OAM | 0x200,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x202,
    0xf0, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x204,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sSteamDiagonalOam_Large_Frame4[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xfc, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xd8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x25, OBJ_SPRITE_OAM | 0x200,
    0xe0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x19, OBJ_SPRITE_OAM | 0x202,
    0xe8, OBJ_SIZE_16x16 | 0xe, OBJ_SPRITE_OAM | 0x204,
    0xf0, OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x206
};

const u16 sSteamDiagonalOam_Large_Frame5[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf8, OBJ_Y_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x208,
    0x0, 0x1fd, OBJ_SPRITE_OAM | 0x208,
    0xd0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x30, OBJ_SPRITE_OAM | 0x202,
    0xd8, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0x204,
    0xe4, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x206,
    0xf0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x207,
    0xf4, 0x0, OBJ_SPRITE_OAM | 0x207,
    0xf8, OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x207
};

const u16 sSteamDiagonalOam_Large_Frame6[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x3, OBJ_SPRITE_OAM | 0x208,
    0xf8, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x208,
    0xcc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x33, OBJ_SPRITE_OAM | 0x204,
    0xd8, OBJ_SIZE_16x16 | 0x1f, OBJ_SPRITE_OAM | 0x206,
    0xed, OBJ_Y_FLIP | 0xd, OBJ_SPRITE_OAM | 0x207,
    0xe9, OBJ_X_FLIP | OBJ_Y_FLIP | 0x15, OBJ_SPRITE_OAM | 0x207,
    0xe5, OBJ_X_FLIP | 0xd, OBJ_SPRITE_OAM | 0x207
};

const u16 sSteamDiagonalOam_Large_Frame7[OAM_DATA_SIZE(6)] = {
    0x6,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | 0xf, OBJ_SPRITE_OAM | 0x208,
    0xf0, OBJ_X_FLIP | 0xd, OBJ_SPRITE_OAM | 0x208,
    0xc8, OBJ_SIZE_16x16 | 0x38, OBJ_SPRITE_OAM | 0x206,
    0xd5, OBJ_X_FLIP | 0x2b, OBJ_SPRITE_OAM | 0x207,
    0xd9, 0x23, OBJ_SPRITE_OAM | 0x207,
    0xdd, OBJ_Y_FLIP | 0x2b, OBJ_SPRITE_OAM | 0x207
};

const u16 sSteamDiagonalOam_Large_Frame8[OAM_DATA_SIZE(5)] = {
    0x5,
    0xd8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1a, OBJ_SPRITE_OAM | 0x208,
    0xe0, OBJ_X_FLIP | 0x18, OBJ_SPRITE_OAM | 0x208,
    0xca, OBJ_Y_FLIP | 0x3e, OBJ_SPRITE_OAM | 0x207,
    0xc6, OBJ_X_FLIP | OBJ_Y_FLIP | 0x46, OBJ_SPRITE_OAM | 0x207,
    0xc2, OBJ_X_FLIP | 0x3e, OBJ_SPRITE_OAM | 0x207
};

const u16 sSteamDiagonalOam_Large_Frame9[OAM_DATA_SIZE(2)] = {
    0x2,
    0xc8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x32, OBJ_SPRITE_OAM | 0x208,
    0xd0, OBJ_X_FLIP | 0x30, OBJ_SPRITE_OAM | 0x208
};

const u16 sSteamDiagonalOam_Small_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf4, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x209,
    0xf8, 0x1ff, OBJ_SPRITE_OAM | 0x209
};

const u16 sSteamDiagonalOam_Small_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xee, 0xb, OBJ_SPRITE_OAM | 0x209,
    0xfa, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    0xf4, 0x3, OBJ_SPRITE_OAM | 0x209
};

const u16 sSteamDiagonalOam_Small_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xea, OBJ_X_FLIP | 0x11, OBJ_SPRITE_OAM | 0x209,
    0xf6, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x20b,
    0xf0, 0x8, OBJ_SPRITE_OAM | 0x209,
    0xf8, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20c
};

const u16 sSteamDiagonalOam_Small_Frame4[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf9, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x20d,
    0xf2, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x20b,
    0xf5, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x20c,
    0xe5, OBJ_X_FLIP | 0x17, OBJ_SPRITE_OAM | 0x209,
    0xeb, OBJ_X_FLIP | 0xe, OBJ_SPRITE_OAM | 0x209
};

const u16 sSteamDiagonalOam_Small_Frame5[OAM_DATA_SIZE(5)] = {
    0x5,
    0xf8, OBJ_X_FLIP | 0x3, OBJ_SPRITE_OAM | 0x20d,
    0xe9, OBJ_X_FLIP | 0x13, OBJ_SPRITE_OAM | 0x20b,
    0xee, OBJ_X_FLIP | 0xe, OBJ_SPRITE_OAM | 0x20c,
    0xf3, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x20d,
    0xe2, OBJ_X_FLIP | 0x1c, OBJ_SPRITE_OAM | 0x20b
};

const u16 sSteamDiagonalOam_Small_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    0xdc, OBJ_X_FLIP | 0x22, OBJ_SPRITE_OAM | 0x20c,
    0xe4, OBJ_Y_FLIP | 0x19, OBJ_SPRITE_OAM | 0x20c,
    0xf0, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x20d,
    0xeb, 0x11, OBJ_SPRITE_OAM | 0x20d
};

const u16 sSteamDiagonalOam_Small_Frame7[OAM_DATA_SIZE(3)] = {
    0x3,
    0xe0, OBJ_Y_FLIP | 0x1c, OBJ_SPRITE_OAM | 0x20d,
    0xd9, OBJ_X_FLIP | 0x26, OBJ_SPRITE_OAM | 0x20d,
    0xe5, OBJ_X_FLIP | 0x13, OBJ_SPRITE_OAM | 0x20d
};

static const u16 sSteamOam_HorizontalLarge_Frame10[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x20e
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
