#include "data/sprites/message_banner.h"
#include "macros.h"

const u32 sMessageBannerGfx[139] = INCBIN_U32("data/sprites/MessageBanner.gfx.lz");
const u16 sMessageBannerPal[32] = INCBIN_U16("data/sprites/MessageBanner.pal");

static const u16 sSaveYesNoCursorOam_Idle_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 542, 8, 0),
};

static const u16 sSaveYesNoCursorOam_Idle_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-3, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 542, 8, 0),
};

static const u16 sSaveYesNoCursorOam_Idle_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-2, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 542, 8, 0),
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 604, 8, 0),
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 604, 8, 0),
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-56, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(40, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 604, 8, 0),
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame3[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-88, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-56, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(40, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(72, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 604, 8, 0),
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame4[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-120, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-88, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-56, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(40, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(72, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(104, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 604, 8, 0),
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame5[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(-112, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-80, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-48, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(48, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(80, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-112, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 608, 8, 0),
    OAM_ENTRY(-80, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 612, 8, 0),
    OAM_ENTRY(-48, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 616, 8, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 620, 8, 0),
    OAM_ENTRY(16, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 624, 8, 0),
    OAM_ENTRY(48, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(80, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 632, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 543, 8, 0),
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame6[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-112, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-48, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(80, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-112, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 608, 8, 0),
    OAM_ENTRY(-80, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 612, 8, 0),
    OAM_ENTRY(-48, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 616, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 620, 8, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 624, 8, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(80, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 632, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 540, 8, 0),
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame7[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-120, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-120, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(-112, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-80, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-48, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(16, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(48, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(80, -10, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-112, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-80, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 580, 8, 0),
    OAM_ENTRY(-48, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 584, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 8, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(48, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 596, 8, 0),
    OAM_ENTRY(80, -6, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 8, 0),
    OAM_ENTRY(112, -10, OAM_DIMS_8x8, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(112, 2, OAM_DIMS_8x8, OAM_X_FLIP, 572, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 541, 8, 0),
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame8[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-120, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-120, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(-112, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-80, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-48, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(16, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(48, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(80, -12, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-112, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 580, 8, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 584, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 596, 8, 0),
    OAM_ENTRY(80, -4, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 8, 0),
    OAM_ENTRY(112, -12, OAM_DIMS_8x8, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(112, 4, OAM_DIMS_8x8, OAM_X_FLIP, 572, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 541, 8, 0),
};

static const u16 sMessageBannerOam_TwoLinesSpawn_Frame9[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-120, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-120, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(-112, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-80, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(16, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(48, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(80, -14, OAM_DIMS_32x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-112, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-80, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 580, 8, 0),
    OAM_ENTRY(-48, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 584, 8, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 588, 8, 0),
    OAM_ENTRY(16, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 592, 8, 0),
    OAM_ENTRY(48, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 596, 8, 0),
    OAM_ENTRY(80, -2, OAM_DIMS_32x16, OAM_NO_FLIP, 600, 8, 0),
    OAM_ENTRY(112, -14, OAM_DIMS_8x8, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(112, 6, OAM_DIMS_8x8, OAM_X_FLIP, 572, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 541, 8, 0),
};

static const u16 sMessageBannerOam_TwoLinesStatic_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-120, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-120, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 572, 8, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 541, 8, 0),
    OAM_ENTRY(-112, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-48, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_64x32, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(80, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(112, -16, OAM_DIMS_8x8, OAM_X_FLIP, 540, 8, 0),
    OAM_ENTRY(112, 8, OAM_DIMS_8x8, OAM_X_FLIP, 572, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 541, 8, 0),
};

static const u16 sMessageBannerOam_OneLineSpawn_Frame5[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-120, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(-88, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(-56, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(-24, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(40, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(72, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 636, 8, 0),
    OAM_ENTRY(104, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 636, 8, 0),
};

static const u16 sMessageBannerOam_OneLineSpawn_Frame6[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-120, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(112, -6, OAM_DIMS_8x8, OAM_X_FLIP, 543, 8, 0),
    OAM_ENTRY(-112, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-112, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 608, 8, 0),
    OAM_ENTRY(-80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 612, 8, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 616, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 620, 8, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 624, 8, 0),
    OAM_ENTRY(48, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(80, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 632, 8, 0),
    OAM_ENTRY(-120, -2, OAM_DIMS_8x8, OAM_NO_FLIP, 575, 8, 0),
    OAM_ENTRY(112, -2, OAM_DIMS_8x8, OAM_X_FLIP, 575, 8, 0),
};

static const u16 sMessageBannerOam_OneLineSpawn_Frame7[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 543, 8, 0),
    OAM_ENTRY(-112, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-80, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-48, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-16, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(16, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(48, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(80, -6, OAM_DIMS_32x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-112, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 544, 8, 0),
    OAM_ENTRY(-80, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 548, 8, 0),
    OAM_ENTRY(-48, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 552, 8, 0),
    OAM_ENTRY(-16, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 556, 8, 0),
    OAM_ENTRY(16, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 560, 8, 0),
    OAM_ENTRY(48, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 564, 8, 0),
    OAM_ENTRY(80, -2, OAM_DIMS_32x8, OAM_NO_FLIP, 568, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 543, 8, 0),
};

static const u16 sMessageBannerOam_OneLineStatic_Frame0[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-120, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-112, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 516, 8, 0),
    OAM_ENTRY(-48, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 520, 8, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(48, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(80, -8, OAM_DIMS_32x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-112, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 544, 8, 0),
    OAM_ENTRY(-80, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 548, 8, 0),
    OAM_ENTRY(-48, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 552, 8, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 556, 8, 0),
    OAM_ENTRY(16, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 560, 8, 0),
    OAM_ENTRY(48, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 564, 8, 0),
    OAM_ENTRY(80, 0, OAM_DIMS_32x8, OAM_NO_FLIP, 568, 8, 0),
    OAM_ENTRY(112, -8, OAM_DIMS_8x16, OAM_X_FLIP, 540, 8, 0),
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
