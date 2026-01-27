#include "data/sprites/piston.h"
#include "macros.h"

const u32 sPistonGfx[179] = INCBIN_U32("data/sprites/piston.gfx.lz");
const u16 sPistonPal[16] = INCBIN_U16("data/sprites/piston.pal");

static const u16 sPistonOam_Idle_Frame0[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-8, -88, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -80, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x215, 8, 0)
};

static const u16 sPistonOam_Idle_Frame1[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -88, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -80, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x215, 8, 0)
};

static const u16 sPistonOam_Idle_Frame3[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -88, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -80, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-24, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x215, 8, 0)
};

static const u16 sPistonOam_Frame_Unused[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -87, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -79, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -63, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -31, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-25, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x237, 8, 0),
    OAM_ENTRY(9, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x215, 8, 0)
};

static const u16 sPistonOam_Opening_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -92, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -84, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -68, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -52, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -28, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-24, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x235, 8, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x217, 8, 0)
};

static const u16 sPistonOam_Opening_Frame1[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -96, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -88, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -72, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -24, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-24, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x219, 8, 0)
};

static const u16 sPistonOam_Opening_Frame2[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-8, -100, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -92, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -76, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -60, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -44, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -36, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -28, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-24, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(8, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21b, 8, 0)
};

static const u16 sPistonOam_Opening_Frame3[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-8, -105, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -97, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -81, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -65, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -49, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -41, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -25, OAM_DIMS_16x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-16, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23e, 8, 0),
    OAM_ENTRY(-21, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23f, 8, 0),
    OAM_ENTRY(13, -21, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0)
};

static const u16 sPistonOam_Opening_Frame4[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-8, -104, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -80, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-16, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23e, 8, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23f, 8, 0),
    OAM_ENTRY(13, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0)
};

static const u16 sPistonOam_Opening_Frame5[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-8, -104, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -80, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-16, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23e, 8, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23f, 8, 0),
    OAM_ENTRY(13, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0)
};

static const u16 sPistonOam_Opening_Frame6[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-8, -104, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -80, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 0x206, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-16, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23e, 8, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23f, 8, 0),
    OAM_ENTRY(13, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0)
};

static const u16 sPistonOam_Opening_Frame7[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-8, -104, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -80, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-16, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23e, 8, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23f, 8, 0),
    OAM_ENTRY(13, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0)
};

static const u16 sPistonOam_Opened_Frame0[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-8, -104, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -96, OAM_DIMS_16x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-8, -80, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-8, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-8, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 0x22e, 8, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 0x226, 8, 0),
    OAM_ENTRY(-16, -32, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 0x229, 8, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x22b, 8, 0),
    OAM_ENTRY(-16, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23e, 8, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(8, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23f, 8, 0),
    OAM_ENTRY(13, -20, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0)
};


const struct FrameData sPistonOam_Idle[5] = {
    [0] = {
        .pFrame = sPistonOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sPistonOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [2] = {
        .pFrame = sPistonOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [3] = {
        .pFrame = sPistonOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPistonOam_Opening[9] = {
    [0] = {
        .pFrame = sPistonOam_Opening_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sPistonOam_Opening_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sPistonOam_Opening_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sPistonOam_Opening_Frame3,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sPistonOam_Opening_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sPistonOam_Opening_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sPistonOam_Opening_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [7] = {
        .pFrame = sPistonOam_Opening_Frame7,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sPistonOam_Opened[2] = {
    [0] = {
        .pFrame = sPistonOam_Opened_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
