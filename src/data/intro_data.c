#include "data/intro_data.h"

#include "oam.h"
#include "macros.h"
#include "constants/intro.h"

const u16 sIntroEmergencyOrderTextOAM[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-72, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3, 1, 0),
    OAM_ENTRY(-64, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(-56, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0xe, 1, 0),
    OAM_ENTRY(-48, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(-40, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0x12, 1, 0),
    OAM_ENTRY(-32, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0xa, 1, 0),
    OAM_ENTRY(-24, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(-16, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0xf, 1, 0),
    OAM_ENTRY(-8, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0x6, 1, 0),
    OAM_ENTRY(0, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0x17, 1, 0),
    OAM_ENTRY(8, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1d, 1, 0),
    OAM_ENTRY(16, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0x10, 1, 0),
    OAM_ENTRY(24, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0x12, 1, 0),
    OAM_ENTRY(32, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0x7, 1, 0),
    OAM_ENTRY(40, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(48, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0x12, 1, 0),
    OAM_ENTRY(56, -56, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1c, 1, 0)
};

const u16 sIntroExterminateAllTextOAM[OAM_DATA_SIZE(54)] = {
    54,
    OAM_ENTRY(-104, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3, 1, 0),
    OAM_ENTRY(-96, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(-88, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x16, 1, 0),
    OAM_ENTRY(-80, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x14, 1, 0),
    OAM_ENTRY(-72, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(-64, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x12, 1, 0),
    OAM_ENTRY(-56, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0xe, 1, 0),
    OAM_ENTRY(-48, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0xc, 1, 0),
    OAM_ENTRY(-40, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0xf, 1, 0),
    OAM_ENTRY(-32, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 1, 0),
    OAM_ENTRY(-24, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x14, 1, 0),
    OAM_ENTRY(-16, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(-8, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1d, 1, 0),
    OAM_ENTRY(0, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 1, 0),
    OAM_ENTRY(8, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0xd, 1, 0),
    OAM_ENTRY(16, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0xd, 1, 0),
    OAM_ENTRY(24, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1d, 1, 0),
    OAM_ENTRY(32, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0xe, 1, 0),
    OAM_ENTRY(40, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(48, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x14, 1, 0),
    OAM_ENTRY(56, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x12, 1, 0),
    OAM_ENTRY(64, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x10, 1, 0),
    OAM_ENTRY(72, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0xc, 1, 0),
    OAM_ENTRY(80, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x7, 1, 0),
    OAM_ENTRY(88, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1c, 1, 0),
    OAM_ENTRY(-120, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3, 1, 0),
    OAM_ENTRY(-112, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x10, 1, 0),
    OAM_ENTRY(-104, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x12, 1, 0),
    OAM_ENTRY(-96, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0xa, 1, 0),
    OAM_ENTRY(-88, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 1, 0),
    OAM_ENTRY(-80, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0xf, 1, 0),
    OAM_ENTRY(-72, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0xc, 1, 0),
    OAM_ENTRY(-64, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x13, 1, 0),
    OAM_ENTRY(-56, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0xe, 1, 0),
    OAM_ENTRY(-48, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x13, 1, 0),
    OAM_ENTRY(-40, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1d, 1, 0),
    OAM_ENTRY(-32, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x10, 1, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0xf, 1, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1d, 1, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x11, 1, 0),
    OAM_ENTRY(0, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0xd, 1, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 1, 0),
    OAM_ENTRY(16, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0xf, 1, 0),
    OAM_ENTRY(24, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(32, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x14, 1, 0),
    OAM_ENTRY(40, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1d, 1, 0),
    OAM_ENTRY(48, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x18, 1, 0),
    OAM_ENTRY(56, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(64, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x5, 1, 0),
    OAM_ENTRY(72, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(80, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x13, 1, 0),
    OAM_ENTRY(88, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1e, 1, 0),
    OAM_ENTRY(96, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1f, 1, 0),
    OAM_ENTRY(104, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1f, 1, 0)
};

const u16 sIntroDefeatTheTextOAM[OAM_DATA_SIZE(52)] = {
    52,
    OAM_ENTRY(-104, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3, 1, 0),
    OAM_ENTRY(-96, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 1, 0),
    OAM_ENTRY(-88, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0xf, 1, 0),
    OAM_ENTRY(-80, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x7, 1, 0),
    OAM_ENTRY(-72, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1d, 1, 0),
    OAM_ENTRY(-64, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x7, 1, 0),
    OAM_ENTRY(-56, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(-48, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x9, 1, 0),
    OAM_ENTRY(-40, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(-32, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 1, 0),
    OAM_ENTRY(-24, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x14, 1, 0),
    OAM_ENTRY(-16, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1d, 1, 0),
    OAM_ENTRY(-8, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x14, 1, 0),
    OAM_ENTRY(0, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0xb, 1, 0),
    OAM_ENTRY(8, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(16, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1d, 1, 0),
    OAM_ENTRY(24, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0xe, 1, 0),
    OAM_ENTRY(32, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(40, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x6, 1, 0),
    OAM_ENTRY(48, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0xb, 1, 0),
    OAM_ENTRY(56, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 1, 0),
    OAM_ENTRY(64, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0xf, 1, 0),
    OAM_ENTRY(72, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0xc, 1, 0),
    OAM_ENTRY(80, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x6, 1, 0),
    OAM_ENTRY(88, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 1, 0),
    OAM_ENTRY(96, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0xd, 1, 0),
    OAM_ENTRY(104, -72, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1c, 1, 0),
    OAM_ENTRY(-96, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3, 1, 0),
    OAM_ENTRY(-88, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0xd, 1, 0),
    OAM_ENTRY(-80, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0xc, 1, 0),
    OAM_ENTRY(-72, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x9, 1, 0),
    OAM_ENTRY(-64, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(-56, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x5e, 1, 0),
    OAM_ENTRY(-48, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x9, 1, 0),
    OAM_ENTRY(-40, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x10, 1, 0),
    OAM_ENTRY(-32, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x12, 1, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0xe, 1, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x5d, 1, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3, 1, 0),
    OAM_ENTRY(0, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0xe, 1, 0),
    OAM_ENTRY(8, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x10, 1, 0),
    OAM_ENTRY(16, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x14, 1, 0),
    OAM_ENTRY(24, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0xb, 1, 0),
    OAM_ENTRY(32, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x8, 1, 0),
    OAM_ENTRY(40, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x12, 1, 0),
    OAM_ENTRY(48, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1d, 1, 0),
    OAM_ENTRY(56, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x5, 1, 0),
    OAM_ENTRY(64, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x12, 1, 0),
    OAM_ENTRY(72, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4, 1, 0),
    OAM_ENTRY(80, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0xc, 1, 0),
    OAM_ENTRY(88, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0xf, 1, 0),
    OAM_ENTRY(96, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x5f, 1, 0)
};

const u16 sIntroTextMarkerOAM[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x20, 1, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21, 1, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22, 1, 0)
};

const u16 sIntroShipFlyingTowardsCameraOam_1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-64, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 0x41, 3, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 0x49, 3, 0),
    OAM_ENTRY(-72, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x100, 3, 0),
    OAM_ENTRY(64, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x111, 3, 0),
    OAM_ENTRY_MODE(-56, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 0x52, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-8, -40, OAM_DIMS_64x64, OAM_X_FLIP, 0x52, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT)
};

const u16 sIntroShipFlyingTowardsCameraOam_2[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-64, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 0x41, 3, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 0x49, 3, 0),
    OAM_ENTRY(-16, 24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x147, 3, 0),
    OAM_ENTRY(-72, -24, OAM_DIMS_8x32, OAM_NO_FLIP, 0x80, 3, 0),
    OAM_ENTRY(64, -24, OAM_DIMS_8x32, OAM_NO_FLIP, 0x91, 3, 0),
    OAM_ENTRY(-72, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x100, 3, 0),
    OAM_ENTRY(64, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x111, 3, 0),
    OAM_ENTRY_MODE(-56, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 0x160, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-8, -40, OAM_DIMS_64x64, OAM_X_FLIP, 0x160, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT)
};

const u16 sIntroViewOfZebesShipOAM[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-16, -40, OAM_DIMS_64x32, OAM_NO_FLIP, 0x40, 3, 0),
    OAM_ENTRY(48, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 0x48, 3, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0xc0, 3, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0xc4, 3, 0)
};

const u16 sIntroViewOfZebesHeatOAM_2[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(0, -96, OAM_DIMS_64x64, OAM_NO_FLIP, 0x50, 4, 0),
    OAM_ENTRY(64, -96, OAM_DIMS_64x64, OAM_NO_FLIP, 0x58, 4, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x10d, 4, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x10f, 4, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x18d, 4, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x18f, 4, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_64x32, OAM_NO_FLIP, 0x150, 4, 0),
    OAM_ENTRY(64, -32, OAM_DIMS_64x32, OAM_NO_FLIP, 0x158, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x1d0, 4, 0),
    OAM_ENTRY(32, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x1d4, 4, 0),
    OAM_ENTRY(64, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x1d8, 4, 0),
    OAM_ENTRY(96, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x1dc, 4, 0)
};

const u16 sIntroViewOfZebesHeatOAM_1[OAM_DATA_SIZE(24)] = {
    24,
    OAM_ENTRY(0, -96, OAM_DIMS_64x32, OAM_NO_FLIP, 0x210, 4, 0),
    OAM_ENTRY(64, -96, OAM_DIMS_64x32, OAM_NO_FLIP, 0x218, 4, 0),
    OAM_ENTRY(0, -64, OAM_DIMS_32x16, OAM_NO_FLIP, 0x290, 4, 0),
    OAM_ENTRY(32, -64, OAM_DIMS_32x16, OAM_NO_FLIP, 0x294, 4, 0),
    OAM_ENTRY(64, -64, OAM_DIMS_32x16, OAM_NO_FLIP, 0x298, 4, 0),
    OAM_ENTRY(96, -64, OAM_DIMS_32x16, OAM_NO_FLIP, 0x29c, 4, 0),
    OAM_ENTRY(0, -48, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2d0, 4, 0),
    OAM_ENTRY(32, -48, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2d4, 4, 0),
    OAM_ENTRY(64, -48, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2d8, 4, 0),
    OAM_ENTRY(96, -48, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2dc, 4, 0),
    OAM_ENTRY(-24, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x2cd, 4, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x2cf, 4, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x34d, 4, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x34f, 4, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_64x32, OAM_NO_FLIP, 0x2f0, 4, 0),
    OAM_ENTRY(64, -40, OAM_DIMS_64x32, OAM_NO_FLIP, 0x2f8, 4, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x370, 4, 0),
    OAM_ENTRY(32, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x374, 4, 0),
    OAM_ENTRY(64, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x378, 4, 0),
    OAM_ENTRY(96, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x37c, 4, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3b0, 4, 0),
    OAM_ENTRY(32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3b4, 4, 0),
    OAM_ENTRY(64, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3b8, 4, 0),
    OAM_ENTRY(96, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x3bc, 4, 0)
};

const u16 sIntroFuzzOAM[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-128, -128, OAM_DIMS_64x64, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-64, -128, OAM_DIMS_64x64, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(0, -128, OAM_DIMS_64x64, OAM_NO_FLIP, 0x10, 0, 0),
    OAM_ENTRY(64, -128, OAM_DIMS_32x64, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(96, -128, OAM_DIMS_16x32, OAM_NO_FLIP, 0x1c, 0, 0),
    OAM_ENTRY(96, -96, OAM_DIMS_16x32, OAM_NO_FLIP, 0x9c, 0, 0),
    OAM_ENTRY(-128, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x100, 0, 0),
    OAM_ENTRY(-64, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x108, 0, 0),
    OAM_ENTRY(0, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x110, 0, 0),
    OAM_ENTRY(64, -64, OAM_DIMS_32x64, OAM_NO_FLIP, 0x118, 0, 0),
    OAM_ENTRY(96, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 0x11c, 0, 0),
    OAM_ENTRY(96, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x19c, 0, 0),
    OAM_ENTRY(-128, 0, OAM_DIMS_64x32, OAM_NO_FLIP, 0x200, 0, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_64x32, OAM_NO_FLIP, 0x208, 0, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_64x32, OAM_NO_FLIP, 0x210, 0, 0),
    OAM_ENTRY(64, 0, OAM_DIMS_32x32, OAM_NO_FLIP, 0x218, 0, 0),
    OAM_ENTRY(96, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x21c, 0, 0)
};

const u16 sIntroTextAndShipPal[16 * 6] = INCBIN_U16("data/intro/text_and_ship.pal");
const u16 sIntroPal_45f9d4[16 * 1] = INCBIN_U16("data/intro/45f9d4.pal");
const u16 sIntroSamusInHerShipPal[16 * 5] = INCBIN_U16("data/intro/samus_in_her_ship.pal");
const u16 sIntroViewOfZebesPal[16 * 10] = INCBIN_U16("data/intro/view_of_zebes.pal");
const u16 sIntroMotherBrainPal[16 * 5] = INCBIN_U16("data/intro/mother_brain.pal");


const u8 sIntroFuzzRandomValues_1[64] = {
    31, 0, 0, 0, 0, 0, 0, 0, 66, 8, 99, 12, 165, 20, 231, 28, 239, 61,
    181, 86, 255, 127, 239, 61, 255, 127, 255, 127, 239, 61, 239, 61,
    31, 0, 0, 0, 0, 0, 0, 0, 66, 8, 99, 12, 165, 20, 231, 28, 255, 127,
    255, 127, 49, 70, 255, 127, 181, 86, 49, 70, 239, 61, 255, 127
};

const u8 sIntroFuzzRandomValues_2[64] = {
    31, 0, 0, 0, 0, 0, 0, 0, 66, 8, 99, 12, 165, 20, 231, 28, 239, 61,
    49, 70, 255, 127, 239, 61, 255, 127, 49, 70, 255, 127, 49, 70, 31,
    0, 0, 0, 0, 0, 0, 0, 66, 8, 99, 12, 165, 20, 231, 28, 255, 127, 49,
    70, 255, 127, 181, 86, 239, 61, 156, 115, 255, 127, 255, 127
};

const u8 sTimeAttackPasswordCharacters[32] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '#',
    '?', 'C', '%', 'F', 'H', 'J', 'K', 'L', 'M', 'N', 'P',
    'Q', 'R', 'T', 'V', 'W', 'X', 'Y', '=', '-', '+'
};

const u32 sTimeAttackAntiCheatTimes[4] = {
    0 | 0 << 8 | 5 << 16  | 0 << 24,
    0 | 0 << 8 | 10 << 16 | 0 << 24,
    0 | 0 << 8 | 16 << 16 | 0 << 24,
    0 | 0 << 8 | 22 << 16 | 0 << 24
};

const u8 sSpriteXHalfRadius[3][4] = {
    [OAM_SHAPE_SQUARE] = {
        [OAM_SIZE_S_8x8] = 8/2,
        [OAM_SIZE_S_16x16] = 16/2,
        [OAM_SIZE_S_32x32] = 32/2,
        [OAM_SIZE_S_64x64] = 64/2
    },
    [OAM_SHAPE_HORIZONTAL] = {
        [OAM_SIZE_H_16x8] = 16/2,
        [OAM_SIZE_H_32x8] = 32/2,
        [OAM_SIZE_H_32x16] = 32/2,
        [OAM_SIZE_H_64x32] = 64/2
    },
    [OAM_SHAPE_VERTICAL] = {
        [OAM_SIZE_V_8x16] = 8/2,
        [OAM_SIZE_V_8x32] = 8/2,
        [OAM_SIZE_V_16x32] = 16/2,
        [OAM_SIZE_V_32x64] = 32/2
    }
};

const u8 sSpriteYHalfRadius[3][4] = {
    [OAM_SHAPE_SQUARE] = {
        [OAM_SIZE_S_8x8] = 8/2,
        [OAM_SIZE_S_16x16] = 16/2,
        [OAM_SIZE_S_32x32] = 32/2,
        [OAM_SIZE_S_64x64] = 64/2
    },
    [OAM_SHAPE_HORIZONTAL] = {
        [OAM_SIZE_H_16x8] = 8/2,
        [OAM_SIZE_H_32x8] = 8/2,
        [OAM_SIZE_H_32x16] =16/2,
        [OAM_SIZE_H_64x32] = 32/2
    },
    [OAM_SHAPE_VERTICAL] = {
        [OAM_SIZE_V_8x16] = 16/2,
        [OAM_SIZE_V_8x32] = 32/2,
        [OAM_SIZE_V_16x32] = 32/2,
        [OAM_SIZE_V_32x64] = 64/2
    }
};

const IntroTextAction sIntroEmergencyOrderActions[16] = {
    INTRO_TEXT_ACTION_START,
    INTRO_TEXT_ACTION_NONE,            // E
    INTRO_TEXT_ACTION_NONE,            // M
    INTRO_TEXT_ACTION_NONE,            // E
    INTRO_TEXT_ACTION_NONE,            // R
    INTRO_TEXT_ACTION_NONE,            // G
    INTRO_TEXT_ACTION_NONE,            // E
    INTRO_TEXT_ACTION_NONE,            // N
    INTRO_TEXT_ACTION_NONE,            // C
    INTRO_TEXT_ACTION_NONE,            // Y
    INTRO_TEXT_ACTION_SPACE,           // 
    INTRO_TEXT_ACTION_NONE,            // O
    INTRO_TEXT_ACTION_NONE,            // R
    INTRO_TEXT_ACTION_NONE,            // D
    INTRO_TEXT_ACTION_SKIP_CHARACTER,  // E
    INTRO_TEXT_ACTION_COUNT,             // R
};

const IntroTextAction sIntroExterminateAllActions[52] = {
    INTRO_TEXT_ACTION_START,
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // X
    INTRO_TEXT_ACTION_NONE,             // T
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // R
    INTRO_TEXT_ACTION_NONE,             // M
    INTRO_TEXT_ACTION_NONE,             // I
    INTRO_TEXT_ACTION_NONE,             // N
    INTRO_TEXT_ACTION_NONE,             // A
    INTRO_TEXT_ACTION_NONE,             // T
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // A
    INTRO_TEXT_ACTION_NONE,             // L
    INTRO_TEXT_ACTION_NONE,             // L
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // M
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // T
    INTRO_TEXT_ACTION_NONE,             // R
    INTRO_TEXT_ACTION_NONE,             // O
    INTRO_TEXT_ACTION_SKIP_CHARACTER,   // I
    INTRO_TEXT_ACTION_NEW_LINE,         // D
    INTRO_TEXT_ACTION_NONE,             // O
    INTRO_TEXT_ACTION_NONE,             // R
    INTRO_TEXT_ACTION_NONE,             // G
    INTRO_TEXT_ACTION_NONE,             // A
    INTRO_TEXT_ACTION_NONE,             // N
    INTRO_TEXT_ACTION_NONE,             // I
    INTRO_TEXT_ACTION_NONE,             // S
    INTRO_TEXT_ACTION_NONE,             // M
    INTRO_TEXT_ACTION_NONE,             // S
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // O
    INTRO_TEXT_ACTION_NONE,             // N
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // P
    INTRO_TEXT_ACTION_NONE,             // L
    INTRO_TEXT_ACTION_NONE,             // A
    INTRO_TEXT_ACTION_NONE,             // N
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // T
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // Z
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // B
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // S
    INTRO_TEXT_ACTION_NONE,             // .
    INTRO_TEXT_ACTION_SKIP_CHARACTER,   // .
    INTRO_TEXT_ACTION_COUNT,              // .
};

const IntroTextAction sIntroDefeatTheActions[50] = {
    INTRO_TEXT_ACTION_START,
    INTRO_TEXT_ACTION_NONE,             // A
    INTRO_TEXT_ACTION_NONE,             // N
    INTRO_TEXT_ACTION_NONE,             // D
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // D
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // F
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // A
    INTRO_TEXT_ACTION_NONE,             // T
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // T
    INTRO_TEXT_ACTION_NONE,             // H
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // M
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // C
    INTRO_TEXT_ACTION_NONE,             // H
    INTRO_TEXT_ACTION_NONE,             // A
    INTRO_TEXT_ACTION_NONE,             // N
    INTRO_TEXT_ACTION_NONE,             // I
    INTRO_TEXT_ACTION_NONE,             // C
    INTRO_TEXT_ACTION_SKIP_CHARACTER,   // A
    INTRO_TEXT_ACTION_NEW_LINE,         // 
    INTRO_TEXT_ACTION_NONE,             // L
    INTRO_TEXT_ACTION_NONE,             // I
    INTRO_TEXT_ACTION_NONE,             // F
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // -
    INTRO_TEXT_ACTION_NONE,             // F
    INTRO_TEXT_ACTION_NONE,             // O
    INTRO_TEXT_ACTION_NONE,             // R
    INTRO_TEXT_ACTION_NONE,             // M
    INTRO_TEXT_ACTION_NONE,             // ,
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // M
    INTRO_TEXT_ACTION_NONE,             // O
    INTRO_TEXT_ACTION_NONE,             // T
    INTRO_TEXT_ACTION_NONE,             // H
    INTRO_TEXT_ACTION_NONE,             // E
    INTRO_TEXT_ACTION_NONE,             // R
    INTRO_TEXT_ACTION_SPACE,            // 
    INTRO_TEXT_ACTION_NONE,             // B
    INTRO_TEXT_ACTION_NONE,             // R
    INTRO_TEXT_ACTION_NONE,             // A
    INTRO_TEXT_ACTION_NONE,             // I
    INTRO_TEXT_ACTION_SKIP_CHARACTER,   // N
    INTRO_TEXT_ACTION_COUNT,              // .
};


const u32 sIntroTextAndShipFlyingInGfx[1310] = INCBIN_U32("data/intro/text_and_ship.gfx.lz");
const u32 sIntroSpaceBackgroundGfx[3181] = INCBIN_U32("data/intro/space_background.gfx.lz");
const u32 sIntroSpaceBackgroundTileTable[577] = INCBIN_U32("data/intro/space_background.tt");
const u32 sIntroSamusInHerShipGfx[4800] = INCBIN_U32("data/intro/samus_in_her_ship.gfx.lz");
const u32 sIntroSamusInHerShipTileTable[418] = INCBIN_U32("data/intro/samus_in_her_ship.tt");
const u32 sIntroSamusShipViewOfZebesGfx[1224] = INCBIN_U32("data/intro/samus_ship_view_of_zebes.gfx.lz");
const u32 sIntroViewOfZebesGfx[2986] = INCBIN_U32("data/intro/view_of_zebes.gfx.lz");
const u32 sIntroViewOfZebesTileTable[577] = INCBIN_U32("data/intro/view_of_zebes.tt");
const u32 sIntroMotherBrainGfx[5004] = INCBIN_U32("data/intro/mother_brain.gfx.lz");
const u32 sIntroMotherBrainTileTable[577] = INCBIN_U32("data/intro/mother_brain.tt");
const u32 sIntroFuzzGfx[5224] = INCBIN_U32("data/intro/fuzz.gfx.lz");
const u32 sIntro_47920c[125] = INCBIN_U32("data/intro/47920c.tt");

