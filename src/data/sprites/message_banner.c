#include "data/sprites/message_banner.h"
#include "macros.h"

const u32 sMessageBannerGfx[139] = INCBIN_U32("data/sprites/message_banner.gfx.lz");
const u16 sMessageBannerPal[32] = INCBIN_U16("data/sprites/message_banner.pal");

static const u16 sSaveYesNoCursorOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sSaveYesNoCursorOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sSaveYesNoCursorOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-2, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25c, 8, 0)
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25c, 8, 0)
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-56, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(40, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25c, 8, 0)
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-88, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-56, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(40, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(72, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25c, 8, 0)
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame4[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-120, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-88, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-56, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(40, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(72, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(104, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x25c, 8, 0)
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame5[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-112, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-112, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(-80, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x264, 8, 0),
    OAM_ENTRY(-48, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x268, 8, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x26c, 8, 0),
    OAM_ENTRY(16, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x270, 8, 0),
    OAM_ENTRY(48, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(80, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x278, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x21f, 8, 0)
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame6[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-112, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-112, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(-80, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x264, 8, 0),
    OAM_ENTRY(-48, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x268, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x26c, 8, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x270, 8, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(80, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x278, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x21c, 8, 0)
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame7[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-120, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-120, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-112, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-112, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-80, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(-48, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(48, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(80, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(112, -10, OAM_DIMS_8x8, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(112, 2, OAM_DIMS_8x8, OAM_X_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x21d, 8, 0)
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame8[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-120, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-120, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-112, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-112, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(80, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(112, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(112, 4, OAM_DIMS_8x8, OAM_X_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x21d, 8, 0)
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame9[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-120, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-120, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-112, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-112, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x240, 8, 0),
    OAM_ENTRY(-80, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x244, 8, 0),
    OAM_ENTRY(-48, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x248, 8, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x24c, 8, 0),
    OAM_ENTRY(16, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x250, 8, 0),
    OAM_ENTRY(48, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(80, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 0x258, 8, 0),
    OAM_ENTRY(112, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(112, 6, OAM_DIMS_8x8, OAM_X_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x21d, 8, 0)
};

static const u16 sMessageBannerOam_TwoLinesStatic_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-120, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-120, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21d, 8, 0),
    OAM_ENTRY(-112, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(80, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(112, -16, OAM_DIMS_8x8, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(112, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x23c, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x21d, 8, 0)
};

static const u16 sMessageBannerOam_OneLineSpawn_Frame5[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-120, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x27c, 8, 0),
    OAM_ENTRY(-88, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x27c, 8, 0),
    OAM_ENTRY(-56, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x27c, 8, 0),
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x27c, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x27c, 8, 0),
    OAM_ENTRY(40, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x27c, 8, 0),
    OAM_ENTRY(72, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x27c, 8, 0),
    OAM_ENTRY(104, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x27c, 8, 0)
};

static const u16 sMessageBannerOam_OneLineSpawn_Frame6[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-120, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(112, -6, OAM_DIMS_8x8, OAM_X_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-112, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-112, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x260, 8, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x264, 8, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x268, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x26c, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x270, 8, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 0x278, 8, 0),
    OAM_ENTRY(-120, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23f, 8, 0),
    OAM_ENTRY(112, -2, OAM_DIMS_8x8, OAM_X_FLIP, 0x23f, 8, 0)
};

static const u16 sMessageBannerOam_OneLineSpawn_Frame7[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21f, 8, 0),
    OAM_ENTRY(-112, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-112, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-80, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x224, 8, 0),
    OAM_ENTRY(-48, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(16, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(48, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(80, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x21f, 8, 0)
};

static const u16 sMessageBannerOam_OneLineStatic_Frame0[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-112, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-48, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x208, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(80, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x218, 8, 0),
    OAM_ENTRY(-112, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x220, 8, 0),
    OAM_ENTRY(-80, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x224, 8, 0),
    OAM_ENTRY(-48, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x228, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x22c, 8, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x230, 8, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(80, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 0x238, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x21c, 8, 0)
};

const struct FrameData sSaveYesNoCursorOam_Idle[5] = {
    [0] = {
        .pFrame = sSaveYesNoCursorOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sSaveYesNoCursorOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sSaveYesNoCursorOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sSaveYesNoCursorOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMessageBannerOam_TwoLinesSpawn[11] = {
    [0] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [9] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame9,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMessageBannerOam_TwoLinesRemoving[11] = {
    [0] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame9,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame8,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMessageBannerOam_TwoLinesStatic[2] = {
    [0] = {
        .pFrame = sMessageBannerOam_TwoLinesStatic_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMessageBannerOam_OneLineSpawn[9] = {
    [0] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sMessageBannerOam_OneLineSpawn_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sMessageBannerOam_OneLineSpawn_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [7] = {
        .pFrame = sMessageBannerOam_OneLineSpawn_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMessageBannerOam_OneLineRemoving[9] = {
    [0] = {
        .pFrame = sMessageBannerOam_OneLineSpawn_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sMessageBannerOam_OneLineSpawn_Frame6,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sMessageBannerOam_OneLineSpawn_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [6] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [7] = {
        .pFrame = sMessageBannerOam_TwoLinesSpawn_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [8] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMessageBannerOam_OneLineStatic[2] = {
    [0] = {
        .pFrame = sMessageBannerOam_OneLineStatic_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
