#include "data/sprites/area_banner.h"

#include "macros.h"

const u32 sAreaBannerGfx[65] = INCBIN_U32("data/sprites/area_banner.gfx.lz");
const u16 sAreaBannerPal[16] = INCBIN_U16("data/sprites/area_banner.pal");
const u16 sAreaBannerLocationTextPal[16] = INCBIN_U16("data/sprites/area_banner_location_text.pal");

static const u16 sAreaBannerOam_SpawnMiddle_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x21c, 8, 0)
};

static const u16 sAreaBannerOam_SpawnMiddle_Frame1[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-40, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(32, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0)
};

static const u16 sAreaBannerOam_SpawnMiddle_Frame2[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-72, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(64, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(32, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-64, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0)
};

static const u16 sAreaBannerOam_SpawnMiddle_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-104, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(96, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(64, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(32, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-96, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-64, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0)
};

static const u16 sAreaBannerOam_SpawnMiddle_Frame4[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-120, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(112, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-112, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0)
};

static const u16 sAreaBannerOam_SpawnMiddle_Frame5[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-120, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(112, -5, OAM_DIMS_8x8, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-120, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(112, -3, OAM_DIMS_8x8, OAM_X_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-112, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-80, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-48, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-16, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(16, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(48, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(80, -5, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-112, -3, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-80, -3, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-48, -3, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-16, -3, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(16, -3, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(48, -3, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(80, -3, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0)
};

static const u16 sAreaBannerOam_SpawnMiddle_Frame6[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-120, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(112, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-120, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(112, -2, OAM_DIMS_8x8, OAM_X_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-112, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-80, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-48, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(48, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(80, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-112, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-80, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-48, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(16, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(48, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(80, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0)
};

static const u16 sAreaBannerOam_SpawnMiddle_Frame7[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-120, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(112, -7, OAM_DIMS_8x8, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-120, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(112, -1, OAM_DIMS_8x8, OAM_X_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-112, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-80, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-48, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-16, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(16, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(48, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(80, -7, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-112, -1, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-80, -1, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-48, -1, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-16, -1, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(16, -1, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(48, -1, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(80, -1, OAM_DIMS_32x8, OAM_NO_FLIP, 0x23c, 8, 0)
};

static const u16 sAreaBannerOam_StaticMiddle_Frame0[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-120, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x8, OAM_X_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-120, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(112, 0, OAM_DIMS_8x8, OAM_X_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-112, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0)
};

static const u16 sAreaBannerOam_UnusedFrame[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-112, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(112, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-120, 8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0)
};

static const u16 sAreaBannerOam_SpawnBottom_Frame0[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-112, 6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, 6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, 6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, 6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, 6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, 6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, 6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(112, 6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-120, 6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0)
};

static const u16 sAreaBannerOam_SpawnBottom_Frame1[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-112, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(112, 4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-120, 4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0)
};

static const u16 sAreaBannerOam_SpawnBottom_Frame2[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-112, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, 2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(112, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-120, 2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0)
};

static const u16 sAreaBannerOam_SpawnBottom_Frame3[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-112, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-120, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(112, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0)
};

static const u16 sAreaBannerOam_SpawnBottom_Frame4[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-112, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(112, -2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-120, -2, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0)
};

static const u16 sAreaBannerOam_SpawnBottom_Frame5[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-112, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-120, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(112, -4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0)
};

static const u16 sAreaBannerOam_SpawnBottom_Frame6[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-112, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(112, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-120, -6, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0)
};

static const u16 sAreaBannerOam_StaticBottom_Frame0[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-112, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0)
};

const struct FrameData sAreaBannerOam_StaticMiddle[2] = {
    [0] = {
        .pFrame = sAreaBannerOam_StaticMiddle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAreaBannerOam_SpawnMiddle[9] = {
    [0] = {
        .pFrame = sAreaBannerOam_SpawnMiddle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sAreaBannerOam_SpawnMiddle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sAreaBannerOam_SpawnMiddle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sAreaBannerOam_SpawnMiddle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sAreaBannerOam_SpawnMiddle_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sAreaBannerOam_SpawnMiddle_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sAreaBannerOam_SpawnMiddle_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sAreaBannerOam_SpawnMiddle_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAreaBannerOam_RemovingMiddle[9] = {
    [0] = {
        .pFrame = sAreaBannerOam_SpawnMiddle_Frame7,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sAreaBannerOam_SpawnMiddle_Frame6,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sAreaBannerOam_SpawnMiddle_Frame5,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sAreaBannerOam_SpawnMiddle_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sAreaBannerOam_SpawnMiddle_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sAreaBannerOam_SpawnMiddle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sAreaBannerOam_SpawnMiddle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sAreaBannerOam_SpawnMiddle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAreaBannerOam_StaticBottom[2] = {
    [0] = {
        .pFrame = sAreaBannerOam_StaticBottom_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAreaBannerOam_SpawnBottom[8] = {
    [0] = {
        .pFrame = sAreaBannerOam_SpawnBottom_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sAreaBannerOam_SpawnBottom_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sAreaBannerOam_SpawnBottom_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sAreaBannerOam_SpawnBottom_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sAreaBannerOam_SpawnBottom_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sAreaBannerOam_SpawnBottom_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sAreaBannerOam_SpawnBottom_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAreaBannerOam_RemovingBottom[8] = {
    [0] = {
        .pFrame = sAreaBannerOam_SpawnBottom_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sAreaBannerOam_SpawnBottom_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sAreaBannerOam_SpawnBottom_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sAreaBannerOam_SpawnBottom_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sAreaBannerOam_SpawnBottom_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sAreaBannerOam_SpawnBottom_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sAreaBannerOam_SpawnBottom_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = FRAME_DATA_TERMINATOR
};
