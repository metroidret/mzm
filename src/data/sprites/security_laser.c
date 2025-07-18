#include "data/sprites/security_laser.h"
#include "macros.h"

const u32 sSecurityLaserGfx[104] = INCBIN_U32("data/sprites/SecurityLaser.gfx.lz");
const u16 sSecurityLaserPal[16] = INCBIN_U16("data/sprites/SecurityLaser.pal");

static const u16 sSecurityLaserOam_VerticalSmall_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalSmall_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalSmall_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe7, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalSmall_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalSmall_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xe9, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalSmall_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xea, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalMedium_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xdd, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalMedium_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xde, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalMedium_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xdf, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalMedium_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalMedium_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xe1, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalMedium_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xe2, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalLarge_Frame0[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xc5, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalLarge_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xc6, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalLarge_Frame2[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe7, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xc7, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalLarge_Frame3[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xc8, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalLarge_Frame4[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xe9, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xc9, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalLarge_Frame5[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xea, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xca, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalVeryLarge_Frame0[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xbd, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalVeryLarge_Frame1[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xbe, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalVeryLarge_Frame2[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xe7, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xbf, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalVeryLarge_Frame3[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalVeryLarge_Frame4[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xe9, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xc1, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_VerticalVeryLarge_Frame5[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xea, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xc2, 0x1fc, OBJ_SPRITE_OAM | 0x201,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sSecurityLaserOam_HorizontalSmall_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x3, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

static const u16 sSecurityLaserOam_HorizontalSmall_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x2, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

static const u16 sSecurityLaserOam_HorizontalSmall_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

static const u16 sSecurityLaserOam_HorizontalSmall_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x0, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

static const u16 sSecurityLaserOam_HorizontalSmall_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1ff, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

static const u16 sSecurityLaserOam_HorizontalSmall_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1fe, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

static const u16 sSecurityLaserOam_HorizontalMedium_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0xb, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x204
};

static const u16 sSecurityLaserOam_HorizontalMedium_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0xa, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x204
};

static const u16 sSecurityLaserOam_HorizontalMedium_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x9, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x204
};

static const u16 sSecurityLaserOam_HorizontalMedium_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x8, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x204
};

static const u16 sSecurityLaserOam_HorizontalMedium_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x7, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x204
};

static const u16 sSecurityLaserOam_HorizontalMedium_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x6, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x204
};

static const u16 sSecurityLaserOam_HorizontalLarge_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x3, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x23, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x18, OBJ_SPRITE_OAM | 0x202
};

static const u16 sSecurityLaserOam_HorizontalLarge_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x2, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x22, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x18, OBJ_SPRITE_OAM | 0x202
};

static const u16 sSecurityLaserOam_HorizontalLarge_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x21, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x18, OBJ_SPRITE_OAM | 0x202
};

static const u16 sSecurityLaserOam_HorizontalLarge_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x0, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x20, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x18, OBJ_SPRITE_OAM | 0x202
};

static const u16 sSecurityLaserOam_HorizontalLarge_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1ff, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x18, OBJ_SPRITE_OAM | 0x202
};

static const u16 sSecurityLaserOam_HorizontalLarge_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1fe, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1e, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x18, OBJ_SPRITE_OAM | 0x202
};

static const u16 sSecurityLaserOam_HorizontalVeryLarge_Frame0[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x3, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x2b, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x18, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x38, OBJ_SPRITE_OAM | 0x204
};

static const u16 sSecurityLaserOam_HorizontalVeryLarge_Frame1[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x2, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x2a, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x18, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x38, OBJ_SPRITE_OAM | 0x204
};

static const u16 sSecurityLaserOam_HorizontalVeryLarge_Frame2[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x29, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x18, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x38, OBJ_SPRITE_OAM | 0x204
};

static const u16 sSecurityLaserOam_HorizontalVeryLarge_Frame3[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x0, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x28, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x18, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x38, OBJ_SPRITE_OAM | 0x204
};

static const u16 sSecurityLaserOam_HorizontalVeryLarge_Frame4[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1ff, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x27, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x18, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x38, OBJ_SPRITE_OAM | 0x204
};

static const u16 sSecurityLaserOam_HorizontalVeryLarge_Frame5[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1fe, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x26, OBJ_SPRITE_OAM | 0x222,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x18, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x38, OBJ_SPRITE_OAM | 0x204
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x206
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x208
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x209
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    0xe4, 0x1fc, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    0xea, 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    0xee, 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x206
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x208
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x209
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_VERTICAL | 0xd8, 0x1fc, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xde, 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    0xea, 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x206
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x208
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x209
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xcc, 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_VERTICAL | 0xe4, 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    0xdc, 0x1fc, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xd2, 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xde, 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame0[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x206
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame1[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x207
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame2[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x208
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame3[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x209
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xe4, 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_VERTICAL | 0xcc, 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_VERTICAL | 0xbc, 0x1fc, OBJ_SPRITE_OAM | 0x20a,
    0xdc, 0x1fc, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xde, 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xc2, 0x1fc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x22c
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x230
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1fc, OBJ_SPRITE_OAM | 0x214,
    0xf4, 0xc, OBJ_SPRITE_OAM | 0x216
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf4, 0x2, OBJ_SPRITE_OAM | 0x234,
    0xf4, 0x6, OBJ_SPRITE_OAM | 0x234
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x20c
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x22c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x22c
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x210
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x230
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x0, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x10, OBJ_SPRITE_OAM | 0x215
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x6, OBJ_SPRITE_OAM | 0x234,
    0xf4, 0x12, OBJ_SPRITE_OAM | 0x236
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x18, OBJ_SPRITE_OAM | 0x20c
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x22c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x18, OBJ_SPRITE_OAM | 0x22c
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x18, OBJ_SPRITE_OAM | 0x210
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x18, OBJ_SPRITE_OAM | 0x230
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x4, OBJ_SPRITE_OAM | 0x214,
    0xf4, 0x14, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1c, OBJ_SPRITE_OAM | 0x214
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0xa, OBJ_SPRITE_OAM | 0x234,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x16, OBJ_SPRITE_OAM | 0x234
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x20c
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x22c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x22c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x22c
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x210
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f8, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x230
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x4, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x14, OBJ_SPRITE_OAM | 0x215,
    0xf4, 0x24, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x2c, OBJ_SPRITE_OAM | 0x215
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0xa, OBJ_SPRITE_OAM | 0x234,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x234,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x26, OBJ_SPRITE_OAM | 0x234
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    0xe0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x21b
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x238,
    0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x238
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x238,
    0xe8, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    0xe0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x238
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x219
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x21a
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    0xd0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x21b
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x238,
    0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x238,
    0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    0xd8, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x21b
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    0xe0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x21b
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x219
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x21a
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x219
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x21a
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame3[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame4[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x219
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame5[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x21a
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x23b,
    0xf4, OBJ_X_FLIP | 0x10, OBJ_SPRITE_OAM | 0x23b
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0xf4, 0x10, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0xf4, 0x10, OBJ_SPRITE_OAM | 0x21c,
    0xf4, 0x0, OBJ_SPRITE_OAM | 0x23b,
    0xf4, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x23b
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x8, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x8, OBJ_SPRITE_OAM | 0x23c
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x8, OBJ_SPRITE_OAM | 0x21e
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x23b,
    0xf4, OBJ_X_FLIP | 0x20, OBJ_SPRITE_OAM | 0x23b
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0xf4, 0x20, OBJ_SPRITE_OAM | 0x21c,
    0xf4, 0x0, OBJ_SPRITE_OAM | 0x23b,
    0xf4, OBJ_X_FLIP | 0x18, OBJ_SPRITE_OAM | 0x23b
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf4, 0x8, OBJ_SPRITE_OAM | 0x23b,
    0xf4, OBJ_X_FLIP | 0x10, OBJ_SPRITE_OAM | 0x23b,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x23c
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x21e
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0xf4, 0x30, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x28, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x28, OBJ_SPRITE_OAM | 0x21c,
    0xf4, 0x8, OBJ_SPRITE_OAM | 0x21c,
    0xf4, 0x20, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x28, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x28, OBJ_SPRITE_OAM | 0x23c
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame5[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x28, OBJ_SPRITE_OAM | 0x21e
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    0xf4, 0x40, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x38, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x38, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x28, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame3[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x38, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x28, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame4[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x28, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x38, OBJ_SPRITE_OAM | 0x23c
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame5[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x18, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x28, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x38, OBJ_SPRITE_OAM | 0x21e
};

const struct FrameData sSecurityLaserOam_VerticalSmall[11] = {
    [0] = {
        .pFrame = sSecurityLaserOam_VerticalSmall_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_VerticalSmall_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_VerticalSmall_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_VerticalSmall_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_VerticalSmall_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_VerticalSmall_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sSecurityLaserOam_VerticalSmall_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sSecurityLaserOam_VerticalSmall_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sSecurityLaserOam_VerticalSmall_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sSecurityLaserOam_VerticalSmall_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_VerticalMedium[11] = {
    [0] = {
        .pFrame = sSecurityLaserOam_VerticalMedium_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_VerticalMedium_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_VerticalMedium_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_VerticalMedium_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_VerticalMedium_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_VerticalMedium_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sSecurityLaserOam_VerticalMedium_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sSecurityLaserOam_VerticalMedium_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sSecurityLaserOam_VerticalMedium_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sSecurityLaserOam_VerticalMedium_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_VerticalLarge[11] = {
    [0] = {
        .pFrame = sSecurityLaserOam_VerticalLarge_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_VerticalLarge_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_VerticalLarge_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_VerticalLarge_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_VerticalLarge_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_VerticalLarge_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sSecurityLaserOam_VerticalLarge_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sSecurityLaserOam_VerticalLarge_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sSecurityLaserOam_VerticalLarge_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sSecurityLaserOam_VerticalLarge_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_VerticalVeryLarge[11] = {
    [0] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLarge_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLarge_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLarge_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLarge_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLarge_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLarge_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLarge_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLarge_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLarge_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLarge_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_HorizontalSmall[11] = {
    [0] = {
        .pFrame = sSecurityLaserOam_HorizontalSmall_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_HorizontalSmall_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_HorizontalSmall_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_HorizontalSmall_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_HorizontalSmall_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_HorizontalSmall_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sSecurityLaserOam_HorizontalSmall_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sSecurityLaserOam_HorizontalSmall_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sSecurityLaserOam_HorizontalSmall_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sSecurityLaserOam_HorizontalSmall_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_HorizontalMedium[11] = {
    [0] = {
        .pFrame = sSecurityLaserOam_HorizontalMedium_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_HorizontalMedium_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_HorizontalMedium_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_HorizontalMedium_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_HorizontalMedium_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_HorizontalMedium_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sSecurityLaserOam_HorizontalMedium_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sSecurityLaserOam_HorizontalMedium_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sSecurityLaserOam_HorizontalMedium_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sSecurityLaserOam_HorizontalMedium_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_HorizontalLarge[11] = {
    [0] = {
        .pFrame = sSecurityLaserOam_HorizontalLarge_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_HorizontalLarge_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_HorizontalLarge_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_HorizontalLarge_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_HorizontalLarge_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_HorizontalLarge_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sSecurityLaserOam_HorizontalLarge_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sSecurityLaserOam_HorizontalLarge_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sSecurityLaserOam_HorizontalLarge_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sSecurityLaserOam_HorizontalLarge_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_HorizontalVeryLarge[11] = {
    [0] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLarge_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLarge_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLarge_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLarge_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLarge_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLarge_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLarge_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLarge_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLarge_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLarge_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_VerticalSmallDisappearing[7] = {
    [0] = {
        .pFrame = sSecurityLaserOam_VerticalSmallDisappearing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_VerticalSmallDisappearing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_VerticalSmallDisappearing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_VerticalSmallDisappearing_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_VerticalSmallDisappearing_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_VerticalSmallDisappearing_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_VerticalMediumDisappearing[7] = {
    [0] = {
        .pFrame = sSecurityLaserOam_VerticalMediumDisappearing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_VerticalMediumDisappearing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_VerticalMediumDisappearing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_VerticalMediumDisappearing_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_VerticalMediumDisappearing_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_VerticalMediumDisappearing_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_VerticalLargeDisappearing[7] = {
    [0] = {
        .pFrame = sSecurityLaserOam_VerticalLargeDisappearing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_VerticalLargeDisappearing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_VerticalLargeDisappearing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_VerticalLargeDisappearing_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_VerticalLargeDisappearing_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_VerticalLargeDisappearing_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_VerticalVeryLargeDisappearing[7] = {
    [0] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_HorizontalSmallDisappearing[7] = {
    [0] = {
        .pFrame = sSecurityLaserOam_HorizontalSmallDisappearing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_HorizontalSmallDisappearing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_HorizontalSmallDisappearing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_HorizontalSmallDisappearing_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_HorizontalSmallDisappearing_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_HorizontalSmallDisappearing_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_HorizontalMediumDisappearing[7] = {
    [0] = {
        .pFrame = sSecurityLaserOam_HorizontalMediumDisappearing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_HorizontalMediumDisappearing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_HorizontalMediumDisappearing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_HorizontalMediumDisappearing_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_HorizontalMediumDisappearing_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_HorizontalMediumDisappearing_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_HorizontalLargeDisappearing[7] = {
    [0] = {
        .pFrame = sSecurityLaserOam_HorizontalLargeDisappearing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_HorizontalLargeDisappearing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_HorizontalLargeDisappearing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_HorizontalLargeDisappearing_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_HorizontalLargeDisappearing_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_HorizontalLargeDisappearing_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_HorizontalVeryLargeDisappearing[7] = {
    [0] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_VerticalSmallDisappearing_Unused[7] = {
    [0] = {
        .pFrame = sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_VerticalMediumDisappearing_Unused[7] = {
    [0] = {
        .pFrame = sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_VerticalLargeDisappearing_Unused[7] = {
    [0] = {
        .pFrame = sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused[7] = {
    [0] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_HorizontalSmallDisappearing_Unused[7] = {
    [0] = {
        .pFrame = sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_HorizontalMediumDisappearing_Unused[7] = {
    [0] = {
        .pFrame = sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_HorizontalLargeDisappearing_Unused[7] = {
    [0] = {
        .pFrame = sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused[7] = {
    [0] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = FRAME_DATA_TERMINATOR
};
