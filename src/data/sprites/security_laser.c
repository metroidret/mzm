#include "data/sprites/security_laser.h"
#include "macros.h"

const u32 sSecurityLaserGfx[104] = INCBIN_U32("data/sprites/SecurityLaser.gfx.lz");
const u16 sSecurityLaserPal[16] = INCBIN_U16("data/sprites/SecurityLaser.pal");

static const u16 sSecurityLaserOam_VerticalSmall_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalSmall_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalSmall_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalSmall_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalSmall_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalSmall_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMedium_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -35, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMedium_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMedium_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -33, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMedium_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMedium_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -31, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMedium_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -30, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLarge_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -59, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLarge_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -58, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLarge_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -57, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLarge_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLarge_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -55, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLarge_Frame5[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -54, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLarge_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-4, -27, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -67, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLarge_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-4, -26, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -66, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLarge_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-4, -25, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -65, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLarge_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLarge_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-4, -23, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -63, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLarge_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-4, -22, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -62, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 8, 0),
    OAM_ENTRY(-4, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmall_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(3, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmall_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(2, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmall_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(1, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmall_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmall_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-1, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmall_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-2, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMedium_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(11, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMedium_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(10, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMedium_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(9, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMedium_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMedium_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(7, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMedium_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(6, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLarge_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(3, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(35, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLarge_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(2, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(34, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLarge_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(33, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLarge_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(32, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLarge_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-1, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(31, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLarge_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(30, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLarge_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(3, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(43, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(56, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLarge_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(2, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(42, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(56, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLarge_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(1, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(41, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(56, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLarge_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(0, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(56, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLarge_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-1, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(39, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(56, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLarge_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-2, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(38, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 546, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 514, 8, 0),
    OAM_ENTRY(56, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 516, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 519, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 521, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-4, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 522, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(-4, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 523, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 519, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 521, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 522, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(-4, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 523, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 519, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 521, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -52, OAM_DIMS_8x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-4, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-4, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 522, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -46, OAM_DIMS_8x16, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(-4, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 523, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
    OAM_ENTRY(-4, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame1[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 519, 8, 0),
    OAM_ENTRY(-4, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 519, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame2[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-4, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 521, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -28, OAM_DIMS_8x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-4, -52, OAM_DIMS_8x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-4, -68, OAM_DIMS_8x16, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-4, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 522, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -34, OAM_DIMS_8x16, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(-4, -62, OAM_DIMS_8x16, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 523, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 524, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 556, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 560, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(12, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 534, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(2, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 564, 8, 0),
    OAM_ENTRY(6, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 564, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 524, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 556, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 556, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 560, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 560, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(0, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 533, 8, 0),
    OAM_ENTRY(16, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 533, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(6, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 564, 8, 0),
    OAM_ENTRY(18, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 566, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 524, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 556, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 556, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 560, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 560, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(4, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(20, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 534, 8, 0),
    OAM_ENTRY(28, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 532, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(10, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 564, 8, 0),
    OAM_ENTRY(22, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 564, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 524, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 556, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 556, 8, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 556, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 528, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 560, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 560, 8, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_32x8, OAM_NO_FLIP, 560, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(4, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 533, 8, 0),
    OAM_ENTRY(20, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 533, 8, 0),
    OAM_ENTRY(36, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(44, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 533, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(10, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 564, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 564, 8, 0),
    OAM_ENTRY(38, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 564, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_Y_FLIP, 539, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 568, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 568, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 568, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_Y_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_Y_FLIP, 568, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalSmallDisappearing_Unused_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_Y_FLIP, 539, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 568, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 568, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x8, OAM_Y_FLIP, 539, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_Y_FLIP, 539, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalMediumDisappearing_Unused_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalLargeDisappearing_Unused_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -80, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-4, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 536, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-4, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 537, 8, 0),
};

static const u16 sSecurityLaserOam_VerticalVeryLargeDisappearing_Unused_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-4, -80, OAM_DIMS_8x16, OAM_NO_FLIP, 538, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 571, 8, 0),
    OAM_ENTRY(16, -12, OAM_DIMS_8x8, OAM_X_FLIP, 571, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(16, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(16, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 571, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_8x8, OAM_X_FLIP, 571, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 572, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalSmallDisappearing_Unused_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 571, 8, 0),
    OAM_ENTRY(32, -12, OAM_DIMS_8x8, OAM_X_FLIP, 571, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(32, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 571, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_8x8, OAM_X_FLIP, 571, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 571, 8, 0),
    OAM_ENTRY(16, -12, OAM_DIMS_8x8, OAM_X_FLIP, 571, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 572, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalMediumDisappearing_Unused_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(48, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(32, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 572, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalLargeDisappearing_Unused_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(64, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(56, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(56, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame3[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(56, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(56, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 572, 8, 0),
};

static const u16 sSecurityLaserOam_HorizontalVeryLargeDisappearing_Unused_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(40, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(56, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
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
