#include "data/sprites/boss_statues.h"

#include "macros.h"

const u32 sBossStatuesGfx[2388] = INCBIN_U32("data/sprites/BossStatues.gfx.lz");
const u16 sBossStatuesPal[128] = INCBIN_U16("data/sprites/BossStatues.pal");

static const u16 sKraidStatueOam_Idle_Frame0[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(80, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 607, 8, 0),
    OAM_ENTRY(16, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(80, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 627, 8, 0),
    OAM_ENTRY(88, -44, OAM_DIMS_16x32, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(96, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 757, 8, 0),
};

static const u16 sKraidStatueOam_Activating_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(64, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 780, 8, 0),
    OAM_ENTRY(80, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 607, 8, 0),
    OAM_ENTRY(72, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(16, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(80, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 627, 8, 0),
    OAM_ENTRY(88, -44, OAM_DIMS_16x32, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(96, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 757, 8, 0),
};

static const u16 sKraidStatueOam_Activating_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(64, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 782, 8, 0),
    OAM_ENTRY(80, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 607, 8, 0),
    OAM_ENTRY(72, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(16, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(80, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 627, 8, 0),
    OAM_ENTRY(88, -44, OAM_DIMS_16x32, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(96, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 757, 8, 0),
};

static const u16 sKraidStatueOam_Activating_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(64, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 814, 8, 0),
    OAM_ENTRY(80, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 607, 8, 0),
    OAM_ENTRY(72, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 662, 8, 0),
    OAM_ENTRY(16, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(80, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 627, 8, 0),
    OAM_ENTRY(88, -44, OAM_DIMS_16x32, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(96, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 757, 8, 0),
};

static const u16 sKraidStatueOam_Activating_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(64, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 784, 8, 0),
    OAM_ENTRY(72, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 694, 8, 0),
    OAM_ENTRY(80, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 703, 8, 0),
    OAM_ENTRY(16, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(80, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 627, 8, 0),
    OAM_ENTRY(88, -44, OAM_DIMS_16x32, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(96, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 757, 8, 0),
};

static const u16 sKraidStatueOam_Activating_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(64, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 816, 8, 0),
    OAM_ENTRY(72, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 726, 8, 0),
    OAM_ENTRY(80, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 735, 8, 0),
    OAM_ENTRY(16, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(80, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 627, 8, 0),
    OAM_ENTRY(88, -44, OAM_DIMS_16x32, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(96, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 757, 8, 0),
};

static const u16 sKraidStatueOam_Activating_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(64, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 786, 8, 0),
    OAM_ENTRY(72, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 758, 8, 0),
    OAM_ENTRY(80, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 799, 8, 0),
    OAM_ENTRY(16, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(80, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 627, 8, 0),
    OAM_ENTRY(88, -44, OAM_DIMS_16x32, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(96, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 757, 8, 0),
};

static const u16 sKraidStatueOam_Activating_Frame6[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(64, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 818, 8, 0),
    OAM_ENTRY(72, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 728, 8, 0),
    OAM_ENTRY(80, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 831, 8, 0),
    OAM_ENTRY(16, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(80, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 627, 8, 0),
    OAM_ENTRY(88, -44, OAM_DIMS_16x32, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(96, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 757, 8, 0),
};

static const u16 sKraidStatueOam_Activating_Frame7[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(64, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 788, 8, 0),
    OAM_ENTRY(72, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 760, 8, 0),
    OAM_ENTRY(80, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 730, 8, 0),
    OAM_ENTRY(16, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(80, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 627, 8, 0),
    OAM_ENTRY(88, -44, OAM_DIMS_16x32, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(96, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 757, 8, 0),
};

static const u16 sKraidStatueOam_Activated_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(64, -40, OAM_DIMS_16x8, OAM_NO_FLIP, 820, 8, 0),
    OAM_ENTRY(80, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 703, 8, 0),
    OAM_ENTRY(72, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 762, 8, 0),
    OAM_ENTRY(16, -72, OAM_DIMS_64x64, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(80, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 627, 8, 0),
    OAM_ENTRY(88, -44, OAM_DIMS_16x32, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(96, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 757, 8, 0),
};

static const u16 sKraidStatueOam_Opening_Frame8[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(64, -41, OAM_DIMS_16x8, OAM_NO_FLIP, 784, 8, 0),
    OAM_ENTRY(72, -49, OAM_DIMS_16x8, OAM_NO_FLIP, 694, 8, 0),
    OAM_ENTRY(80, -57, OAM_DIMS_8x8, OAM_NO_FLIP, 703, 8, 0),
    OAM_ENTRY(16, -73, OAM_DIMS_64x64, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(80, -49, OAM_DIMS_8x32, OAM_NO_FLIP, 627, 8, 0),
    OAM_ENTRY(88, -45, OAM_DIMS_16x32, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(96, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 757, 8, 0),
};

static const u16 sKraidStatueOam_Opening_Frame11[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(63, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 784, 8, 0),
    OAM_ENTRY(71, -50, OAM_DIMS_16x8, OAM_NO_FLIP, 694, 8, 0),
    OAM_ENTRY(79, -58, OAM_DIMS_8x8, OAM_NO_FLIP, 703, 8, 0),
    OAM_ENTRY(15, -74, OAM_DIMS_64x64, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(79, -50, OAM_DIMS_8x32, OAM_NO_FLIP, 627, 8, 0),
    OAM_ENTRY(87, -46, OAM_DIMS_16x32, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(95, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 757, 8, 0),
};

static const u16 sKraidStatueOam_Opening_Frame14[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(63, -43, OAM_DIMS_16x8, OAM_NO_FLIP, 784, 8, 0),
    OAM_ENTRY(71, -51, OAM_DIMS_16x8, OAM_NO_FLIP, 694, 8, 0),
    OAM_ENTRY(79, -59, OAM_DIMS_8x8, OAM_NO_FLIP, 703, 8, 0),
    OAM_ENTRY(15, -75, OAM_DIMS_64x64, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(79, -51, OAM_DIMS_8x32, OAM_NO_FLIP, 627, 8, 0),
    OAM_ENTRY(87, -47, OAM_DIMS_16x32, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(95, -15, OAM_DIMS_8x8, OAM_NO_FLIP, 757, 8, 0),
};

static const u16 sKraidStatueOam_Opening_Frame17[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(62, -44, OAM_DIMS_16x8, OAM_NO_FLIP, 784, 8, 0),
    OAM_ENTRY(70, -52, OAM_DIMS_16x8, OAM_NO_FLIP, 694, 8, 0),
    OAM_ENTRY(78, -60, OAM_DIMS_8x8, OAM_NO_FLIP, 703, 8, 0),
    OAM_ENTRY(14, -76, OAM_DIMS_64x64, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(78, -52, OAM_DIMS_8x32, OAM_NO_FLIP, 627, 8, 0),
    OAM_ENTRY(86, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(94, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 757, 8, 0),
};

static const u16 sKraidStatueOam_Opening_Frame20[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(7, -68, OAM_DIMS_8x16, OAM_NO_FLIP, 961, 8, 0),
    OAM_ENTRY(15, -76, OAM_DIMS_64x64, OAM_NO_FLIP, 790, 8, 0),
    OAM_ENTRY(79, -66, OAM_DIMS_8x32, OAM_NO_FLIP, 798, 8, 0),
    OAM_ENTRY(87, -68, OAM_DIMS_16x32, OAM_NO_FLIP, 926, 8, 0),
    OAM_ENTRY(103, -49, OAM_DIMS_8x16, OAM_NO_FLIP, 863, 8, 0),
};

static const u16 sKraidStatueOam_Opening_Frame21[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(6, -70, OAM_DIMS_8x16, OAM_NO_FLIP, 961, 8, 0),
    OAM_ENTRY(14, -78, OAM_DIMS_64x64, OAM_NO_FLIP, 790, 8, 0),
    OAM_ENTRY(78, -69, OAM_DIMS_8x32, OAM_NO_FLIP, 798, 8, 0),
    OAM_ENTRY(86, -71, OAM_DIMS_16x32, OAM_NO_FLIP, 926, 8, 0),
    OAM_ENTRY(102, -52, OAM_DIMS_8x16, OAM_NO_FLIP, 863, 8, 0),
};

static const u16 sKraidStatueOam_Opening_Frame24[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(5, -73, OAM_DIMS_8x16, OAM_NO_FLIP, 961, 8, 0),
    OAM_ENTRY(13, -81, OAM_DIMS_64x64, OAM_NO_FLIP, 790, 8, 0),
    OAM_ENTRY(77, -73, OAM_DIMS_8x32, OAM_NO_FLIP, 798, 8, 0),
    OAM_ENTRY(85, -76, OAM_DIMS_16x32, OAM_NO_FLIP, 926, 8, 0),
    OAM_ENTRY(101, -57, OAM_DIMS_8x16, OAM_NO_FLIP, 863, 8, 0),
};

static const u16 sKraidStatueOam_Opening_Frame27[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(4, -74, OAM_DIMS_8x16, OAM_NO_FLIP, 961, 8, 0),
    OAM_ENTRY(12, -82, OAM_DIMS_64x64, OAM_NO_FLIP, 790, 8, 0),
    OAM_ENTRY(76, -74, OAM_DIMS_8x32, OAM_NO_FLIP, 798, 8, 0),
    OAM_ENTRY(84, -77, OAM_DIMS_16x32, OAM_NO_FLIP, 926, 8, 0),
    OAM_ENTRY(100, -58, OAM_DIMS_8x16, OAM_NO_FLIP, 863, 8, 0),
};

static const u16 sKraidStatueOam_Opening_Frame30[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(14, -85, OAM_DIMS_64x64, OAM_NO_FLIP, 770, 8, 0),
    OAM_ENTRY(-2, -61, OAM_DIMS_8x16, OAM_NO_FLIP, 864, 8, 0),
    OAM_ENTRY(6, -69, OAM_DIMS_8x32, OAM_NO_FLIP, 833, 8, 0),
    OAM_ENTRY(78, -91, OAM_DIMS_8x8, OAM_NO_FLIP, 746, 8, 0),
    OAM_ENTRY(78, -83, OAM_DIMS_16x32, OAM_NO_FLIP, 778, 8, 0),
    OAM_ENTRY(94, -75, OAM_DIMS_16x16, OAM_NO_FLIP, 812, 8, 0),
};

static const u16 sKraidStatueOam_Opening_Frame31[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(13, -87, OAM_DIMS_64x64, OAM_NO_FLIP, 770, 8, 0),
    OAM_ENTRY(-3, -63, OAM_DIMS_8x16, OAM_NO_FLIP, 864, 8, 0),
    OAM_ENTRY(5, -71, OAM_DIMS_8x32, OAM_NO_FLIP, 833, 8, 0),
    OAM_ENTRY(77, -94, OAM_DIMS_8x8, OAM_NO_FLIP, 746, 8, 0),
    OAM_ENTRY(77, -86, OAM_DIMS_16x32, OAM_NO_FLIP, 778, 8, 0),
    OAM_ENTRY(93, -78, OAM_DIMS_16x16, OAM_NO_FLIP, 812, 8, 0),
};

static const u16 sKraidStatueOam_Opening_Frame32[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(12, -88, OAM_DIMS_64x64, OAM_NO_FLIP, 770, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 864, 8, 0),
    OAM_ENTRY(4, -72, OAM_DIMS_8x32, OAM_NO_FLIP, 833, 8, 0),
    OAM_ENTRY(76, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 746, 8, 0),
    OAM_ENTRY(76, -88, OAM_DIMS_16x32, OAM_NO_FLIP, 778, 8, 0),
    OAM_ENTRY(92, -80, OAM_DIMS_16x16, OAM_NO_FLIP, 812, 8, 0),
};

static const u16 sKraidStatueOam_Opening_Frame41[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(52, -86, OAM_DIMS_16x8, OAM_NO_FLIP, 764, 8, 0),
    OAM_ENTRY(52, -72, OAM_DIMS_16x8, OAM_NO_FLIP, 1004, 8, 0),
    OAM_ENTRY(12, -88, OAM_DIMS_64x64, OAM_NO_FLIP, 770, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 864, 8, 0),
    OAM_ENTRY(4, -72, OAM_DIMS_8x32, OAM_NO_FLIP, 833, 8, 0),
    OAM_ENTRY(76, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 746, 8, 0),
    OAM_ENTRY(76, -88, OAM_DIMS_16x32, OAM_NO_FLIP, 778, 8, 0),
    OAM_ENTRY(92, -80, OAM_DIMS_16x16, OAM_NO_FLIP, 812, 8, 0),
};

static const u16 sKraidStatueOam_Opened_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(52, -86, OAM_DIMS_16x8, OAM_NO_FLIP, 766, 8, 0),
    OAM_ENTRY(52, -72, OAM_DIMS_16x8, OAM_NO_FLIP, 755, 8, 0),
    OAM_ENTRY(12, -88, OAM_DIMS_64x64, OAM_NO_FLIP, 770, 8, 0),
    OAM_ENTRY(-4, -64, OAM_DIMS_8x16, OAM_NO_FLIP, 864, 8, 0),
    OAM_ENTRY(4, -72, OAM_DIMS_8x32, OAM_NO_FLIP, 833, 8, 0),
    OAM_ENTRY(76, -96, OAM_DIMS_8x8, OAM_NO_FLIP, 746, 8, 0),
    OAM_ENTRY(76, -88, OAM_DIMS_16x32, OAM_NO_FLIP, 778, 8, 0),
    OAM_ENTRY(92, -80, OAM_DIMS_16x16, OAM_NO_FLIP, 812, 8, 0),
};

static const u16 sRidleyStatueOam_Idle_Frame0[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-79, -68, OAM_DIMS_64x32, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-79, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 643, 8, 0),
    OAM_ENTRY(-47, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 647, 8, 0),
    OAM_ENTRY(-79, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 707, 8, 0),
    OAM_ENTRY(-87, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 610, 8, 0),
    OAM_ENTRY(-87, -36, OAM_DIMS_8x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-103, -28, OAM_DIMS_16x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-95, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 641, 8, 0),
};

static const u16 sRidleyStatueOam_Activating_Frame0[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-72, -46, OAM_DIMS_16x8, OAM_NO_FLIP, 512, 8, 0),
    OAM_ENTRY(-79, -68, OAM_DIMS_64x32, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-79, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 643, 8, 0),
    OAM_ENTRY(-47, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 647, 8, 0),
    OAM_ENTRY(-79, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 707, 8, 0),
    OAM_ENTRY(-87, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 610, 8, 0),
    OAM_ENTRY(-87, -36, OAM_DIMS_8x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-103, -28, OAM_DIMS_16x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-95, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 641, 8, 0),
};

static const u16 sRidleyStatueOam_Activating_Frame1[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-72, -46, OAM_DIMS_16x8, OAM_NO_FLIP, 544, 8, 0),
    OAM_ENTRY(-79, -68, OAM_DIMS_64x32, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-79, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 643, 8, 0),
    OAM_ENTRY(-47, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 647, 8, 0),
    OAM_ENTRY(-79, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 707, 8, 0),
    OAM_ENTRY(-87, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 610, 8, 0),
    OAM_ENTRY(-87, -36, OAM_DIMS_8x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-103, -28, OAM_DIMS_16x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-95, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 641, 8, 0),
};

static const u16 sRidleyStatueOam_Activating_Frame2[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-72, -46, OAM_DIMS_16x8, OAM_NO_FLIP, 576, 8, 0),
    OAM_ENTRY(-79, -68, OAM_DIMS_64x32, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-79, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 643, 8, 0),
    OAM_ENTRY(-47, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 647, 8, 0),
    OAM_ENTRY(-79, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 707, 8, 0),
    OAM_ENTRY(-87, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 610, 8, 0),
    OAM_ENTRY(-87, -36, OAM_DIMS_8x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-103, -28, OAM_DIMS_16x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-95, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 641, 8, 0),
};

static const u16 sRidleyStatueOam_Activating_Frame3[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-72, -46, OAM_DIMS_16x8, OAM_NO_FLIP, 608, 8, 0),
    OAM_ENTRY(-79, -68, OAM_DIMS_64x32, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-79, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 643, 8, 0),
    OAM_ENTRY(-47, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 647, 8, 0),
    OAM_ENTRY(-79, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 707, 8, 0),
    OAM_ENTRY(-87, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 610, 8, 0),
    OAM_ENTRY(-87, -36, OAM_DIMS_8x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-103, -28, OAM_DIMS_16x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-95, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 641, 8, 0),
};

static const u16 sRidleyStatueOam_Activating_Frame4[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-72, -46, OAM_DIMS_16x8, OAM_NO_FLIP, 739, 8, 0),
    OAM_ENTRY(-79, -68, OAM_DIMS_64x32, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-79, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 643, 8, 0),
    OAM_ENTRY(-47, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 647, 8, 0),
    OAM_ENTRY(-79, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 707, 8, 0),
    OAM_ENTRY(-87, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 610, 8, 0),
    OAM_ENTRY(-87, -36, OAM_DIMS_8x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-103, -28, OAM_DIMS_16x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-95, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 641, 8, 0),
};

static const u16 sRidleyStatueOam_Activating_Frame5[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-72, -46, OAM_DIMS_16x8, OAM_NO_FLIP, 709, 8, 0),
    OAM_ENTRY(-79, -68, OAM_DIMS_64x32, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-79, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 643, 8, 0),
    OAM_ENTRY(-47, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 647, 8, 0),
    OAM_ENTRY(-79, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 707, 8, 0),
    OAM_ENTRY(-87, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 610, 8, 0),
    OAM_ENTRY(-87, -36, OAM_DIMS_8x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-103, -28, OAM_DIMS_16x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-95, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 641, 8, 0),
};

static const u16 sRidleyStatueOam_Activating_Frame6[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-72, -46, OAM_DIMS_16x8, OAM_NO_FLIP, 741, 8, 0),
    OAM_ENTRY(-79, -68, OAM_DIMS_64x32, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-79, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 643, 8, 0),
    OAM_ENTRY(-47, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 647, 8, 0),
    OAM_ENTRY(-79, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 707, 8, 0),
    OAM_ENTRY(-87, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 610, 8, 0),
    OAM_ENTRY(-87, -36, OAM_DIMS_8x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-103, -28, OAM_DIMS_16x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-95, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 641, 8, 0),
};

static const u16 sRidleyStatueOam_Activating_Frame7[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-72, -46, OAM_DIMS_16x8, OAM_NO_FLIP, 711, 8, 0),
    OAM_ENTRY(-79, -68, OAM_DIMS_64x32, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-79, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 643, 8, 0),
    OAM_ENTRY(-47, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 647, 8, 0),
    OAM_ENTRY(-79, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 707, 8, 0),
    OAM_ENTRY(-87, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 610, 8, 0),
    OAM_ENTRY(-87, -36, OAM_DIMS_8x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-103, -28, OAM_DIMS_16x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-95, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 641, 8, 0),
};

static const u16 sRidleyStatueOam_Activated_Frame5[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-72, -46, OAM_DIMS_16x8, OAM_NO_FLIP, 743, 8, 0),
    OAM_ENTRY(-79, -68, OAM_DIMS_64x32, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-79, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 643, 8, 0),
    OAM_ENTRY(-47, -36, OAM_DIMS_32x16, OAM_NO_FLIP, 647, 8, 0),
    OAM_ENTRY(-79, -20, OAM_DIMS_16x8, OAM_NO_FLIP, 707, 8, 0),
    OAM_ENTRY(-87, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 610, 8, 0),
    OAM_ENTRY(-87, -36, OAM_DIMS_8x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-103, -28, OAM_DIMS_16x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-95, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 641, 8, 0),
};

static const u16 sRidleyStatueOam_Opening_Frame8[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-72, -47, OAM_DIMS_16x8, OAM_NO_FLIP, 608, 8, 0),
    OAM_ENTRY(-79, -69, OAM_DIMS_64x32, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-79, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 643, 8, 0),
    OAM_ENTRY(-47, -37, OAM_DIMS_32x16, OAM_NO_FLIP, 647, 8, 0),
    OAM_ENTRY(-79, -21, OAM_DIMS_16x8, OAM_NO_FLIP, 707, 8, 0),
    OAM_ENTRY(-87, -45, OAM_DIMS_8x8, OAM_NO_FLIP, 610, 8, 0),
    OAM_ENTRY(-87, -37, OAM_DIMS_8x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-103, -29, OAM_DIMS_16x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-95, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 641, 8, 0),
};

static const u16 sRidleyStatueOam_Opening_Frame11[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-71, -48, OAM_DIMS_16x8, OAM_NO_FLIP, 608, 8, 0),
    OAM_ENTRY(-78, -70, OAM_DIMS_64x32, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-78, -38, OAM_DIMS_32x16, OAM_NO_FLIP, 643, 8, 0),
    OAM_ENTRY(-46, -38, OAM_DIMS_32x16, OAM_NO_FLIP, 647, 8, 0),
    OAM_ENTRY(-78, -22, OAM_DIMS_16x8, OAM_NO_FLIP, 707, 8, 0),
    OAM_ENTRY(-86, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 610, 8, 0),
    OAM_ENTRY(-86, -38, OAM_DIMS_8x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-102, -30, OAM_DIMS_16x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-94, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 641, 8, 0),
};

static const u16 sRidleyStatueOam_Opening_Frame14[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-71, -49, OAM_DIMS_16x8, OAM_NO_FLIP, 608, 8, 0),
    OAM_ENTRY(-78, -71, OAM_DIMS_64x32, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-78, -39, OAM_DIMS_32x16, OAM_NO_FLIP, 643, 8, 0),
    OAM_ENTRY(-46, -39, OAM_DIMS_32x16, OAM_NO_FLIP, 647, 8, 0),
    OAM_ENTRY(-78, -23, OAM_DIMS_16x8, OAM_NO_FLIP, 707, 8, 0),
    OAM_ENTRY(-86, -47, OAM_DIMS_8x8, OAM_NO_FLIP, 610, 8, 0),
    OAM_ENTRY(-86, -39, OAM_DIMS_8x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-102, -31, OAM_DIMS_16x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-94, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 641, 8, 0),
};

static const u16 sRidleyStatueOam_Opening_Frame17[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-70, -50, OAM_DIMS_16x8, OAM_NO_FLIP, 608, 8, 0),
    OAM_ENTRY(-77, -72, OAM_DIMS_64x32, OAM_NO_FLIP, 515, 8, 0),
    OAM_ENTRY(-77, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 643, 8, 0),
    OAM_ENTRY(-45, -40, OAM_DIMS_32x16, OAM_NO_FLIP, 647, 8, 0),
    OAM_ENTRY(-77, -24, OAM_DIMS_16x8, OAM_NO_FLIP, 707, 8, 0),
    OAM_ENTRY(-85, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 610, 8, 0),
    OAM_ENTRY(-85, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 642, 8, 0),
    OAM_ENTRY(-101, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 672, 8, 0),
    OAM_ENTRY(-93, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 641, 8, 0),
};

static const u16 sRidleyStatueOam_Opening_Frame20[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-78, -73, OAM_DIMS_64x32, OAM_NO_FLIP, 846, 8, 0),
    OAM_ENTRY(-78, -41, OAM_DIMS_32x16, OAM_NO_FLIP, 974, 8, 0),
    OAM_ENTRY(-46, -41, OAM_DIMS_32x16, OAM_NO_FLIP, 978, 8, 0),
    OAM_ENTRY(-14, -65, OAM_DIMS_8x16, OAM_NO_FLIP, 960, 8, 0),
    OAM_ENTRY(-94, -64, OAM_DIMS_16x32, OAM_NO_FLIP, 876, 8, 0),
    OAM_ENTRY(-110, -55, OAM_DIMS_16x32, OAM_NO_FLIP, 906, 8, 0),
};

static const u16 sRidleyStatueOam_Opening_Frame21[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-77, -75, OAM_DIMS_64x32, OAM_NO_FLIP, 846, 8, 0),
    OAM_ENTRY(-77, -43, OAM_DIMS_32x16, OAM_NO_FLIP, 974, 8, 0),
    OAM_ENTRY(-45, -43, OAM_DIMS_32x16, OAM_NO_FLIP, 978, 8, 0),
    OAM_ENTRY(-13, -67, OAM_DIMS_8x16, OAM_NO_FLIP, 960, 8, 0),
    OAM_ENTRY(-93, -66, OAM_DIMS_16x32, OAM_NO_FLIP, 876, 8, 0),
    OAM_ENTRY(-109, -58, OAM_DIMS_16x32, OAM_NO_FLIP, 906, 8, 0),
};

static const u16 sRidleyStatueOam_Opening_Frame24[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-76, -78, OAM_DIMS_64x32, OAM_NO_FLIP, 846, 8, 0),
    OAM_ENTRY(-76, -46, OAM_DIMS_32x16, OAM_NO_FLIP, 974, 8, 0),
    OAM_ENTRY(-44, -46, OAM_DIMS_32x16, OAM_NO_FLIP, 978, 8, 0),
    OAM_ENTRY(-12, -70, OAM_DIMS_8x16, OAM_NO_FLIP, 960, 8, 0),
    OAM_ENTRY(-92, -70, OAM_DIMS_16x32, OAM_NO_FLIP, 876, 8, 0),
    OAM_ENTRY(-108, -62, OAM_DIMS_16x32, OAM_NO_FLIP, 906, 8, 0),
};

static const u16 sRidleyStatueOam_Opening_Frame27[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-75, -79, OAM_DIMS_64x32, OAM_NO_FLIP, 846, 8, 0),
    OAM_ENTRY(-75, -47, OAM_DIMS_32x16, OAM_NO_FLIP, 974, 8, 0),
    OAM_ENTRY(-43, -47, OAM_DIMS_32x16, OAM_NO_FLIP, 978, 8, 0),
    OAM_ENTRY(-11, -71, OAM_DIMS_8x16, OAM_NO_FLIP, 960, 8, 0),
    OAM_ENTRY(-91, -71, OAM_DIMS_16x32, OAM_NO_FLIP, 876, 8, 0),
    OAM_ENTRY(-107, -63, OAM_DIMS_16x32, OAM_NO_FLIP, 906, 8, 0),
};

static const u16 sRidleyStatueOam_Opening_Frame30[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-97, -80, OAM_DIMS_32x8, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-65, -81, OAM_DIMS_32x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-105, -72, OAM_DIMS_32x16, OAM_NO_FLIP, 563, 8, 0),
    OAM_ENTRY(-73, -73, OAM_DIMS_16x16, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(-81, -57, OAM_DIMS_16x8, OAM_NO_FLIP, 630, 8, 0),
    OAM_ENTRY(-65, -58, OAM_DIMS_8x16, OAM_NO_FLIP, 632, 8, 0),
    OAM_ENTRY(-57, -74, OAM_DIMS_32x32, OAM_NO_FLIP, 569, 8, 0),
    OAM_ENTRY(-57, -42, OAM_DIMS_16x8, OAM_NO_FLIP, 697, 8, 0),
    OAM_ENTRY(-41, -42, OAM_DIMS_32x16, OAM_NO_FLIP, 699, 8, 0),
    OAM_ENTRY(-25, -74, OAM_DIMS_16x32, OAM_NO_FLIP, 573, 8, 0),
    OAM_ENTRY(-9, -58, OAM_DIMS_8x16, OAM_NO_FLIP, 639, 8, 0),
};

static const u16 sRidleyStatueOam_Opening_Frame31[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-96, -83, OAM_DIMS_32x8, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-64, -84, OAM_DIMS_32x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-104, -75, OAM_DIMS_32x16, OAM_NO_FLIP, 563, 8, 0),
    OAM_ENTRY(-72, -76, OAM_DIMS_16x16, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(-80, -60, OAM_DIMS_16x8, OAM_NO_FLIP, 630, 8, 0),
    OAM_ENTRY(-64, -60, OAM_DIMS_8x16, OAM_NO_FLIP, 632, 8, 0),
    OAM_ENTRY(-56, -76, OAM_DIMS_32x32, OAM_NO_FLIP, 569, 8, 0),
    OAM_ENTRY(-56, -44, OAM_DIMS_16x8, OAM_NO_FLIP, 697, 8, 0),
    OAM_ENTRY(-40, -44, OAM_DIMS_32x16, OAM_NO_FLIP, 699, 8, 0),
    OAM_ENTRY(-24, -76, OAM_DIMS_16x32, OAM_NO_FLIP, 573, 8, 0),
    OAM_ENTRY(-8, -60, OAM_DIMS_8x16, OAM_NO_FLIP, 639, 8, 0),
};

static const u16 sRidleyStatueOam_Opening_Frame32[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-95, -85, OAM_DIMS_32x8, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-63, -85, OAM_DIMS_32x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-103, -77, OAM_DIMS_32x16, OAM_NO_FLIP, 563, 8, 0),
    OAM_ENTRY(-71, -77, OAM_DIMS_16x16, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(-79, -61, OAM_DIMS_16x8, OAM_NO_FLIP, 630, 8, 0),
    OAM_ENTRY(-63, -61, OAM_DIMS_8x16, OAM_NO_FLIP, 632, 8, 0),
    OAM_ENTRY(-55, -77, OAM_DIMS_32x32, OAM_NO_FLIP, 569, 8, 0),
    OAM_ENTRY(-55, -45, OAM_DIMS_16x8, OAM_NO_FLIP, 697, 8, 0),
    OAM_ENTRY(-39, -45, OAM_DIMS_32x16, OAM_NO_FLIP, 699, 8, 0),
    OAM_ENTRY(-23, -77, OAM_DIMS_16x32, OAM_NO_FLIP, 573, 8, 0),
    OAM_ENTRY(-7, -61, OAM_DIMS_8x16, OAM_NO_FLIP, 639, 8, 0),
};

static const u16 sRidleyStatueOam_Opening_Frame41[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-58, -73, OAM_DIMS_16x8, OAM_NO_FLIP, 713, 8, 0),
    OAM_ENTRY(-95, -85, OAM_DIMS_32x8, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-63, -85, OAM_DIMS_32x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-103, -77, OAM_DIMS_32x16, OAM_NO_FLIP, 563, 8, 0),
    OAM_ENTRY(-71, -77, OAM_DIMS_16x16, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(-79, -61, OAM_DIMS_16x8, OAM_NO_FLIP, 630, 8, 0),
    OAM_ENTRY(-63, -61, OAM_DIMS_8x16, OAM_NO_FLIP, 632, 8, 0),
    OAM_ENTRY(-55, -77, OAM_DIMS_32x32, OAM_NO_FLIP, 569, 8, 0),
    OAM_ENTRY(-55, -45, OAM_DIMS_16x8, OAM_NO_FLIP, 697, 8, 0),
    OAM_ENTRY(-39, -45, OAM_DIMS_32x16, OAM_NO_FLIP, 699, 8, 0),
    OAM_ENTRY(-23, -77, OAM_DIMS_16x32, OAM_NO_FLIP, 573, 8, 0),
    OAM_ENTRY(-7, -61, OAM_DIMS_8x16, OAM_NO_FLIP, 639, 8, 0),
};

static const u16 sRidleyStatueOam_Opened_Frame0[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-58, -73, OAM_DIMS_16x8, OAM_NO_FLIP, 800, 8, 0),
    OAM_ENTRY(-95, -85, OAM_DIMS_32x8, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-63, -85, OAM_DIMS_32x8, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-103, -77, OAM_DIMS_32x16, OAM_NO_FLIP, 563, 8, 0),
    OAM_ENTRY(-71, -77, OAM_DIMS_16x16, OAM_NO_FLIP, 567, 8, 0),
    OAM_ENTRY(-79, -61, OAM_DIMS_16x8, OAM_NO_FLIP, 630, 8, 0),
    OAM_ENTRY(-63, -61, OAM_DIMS_8x16, OAM_NO_FLIP, 632, 8, 0),
    OAM_ENTRY(-55, -77, OAM_DIMS_32x32, OAM_NO_FLIP, 569, 8, 0),
    OAM_ENTRY(-55, -45, OAM_DIMS_16x8, OAM_NO_FLIP, 697, 8, 0),
    OAM_ENTRY(-39, -45, OAM_DIMS_32x16, OAM_NO_FLIP, 699, 8, 0),
    OAM_ENTRY(-23, -77, OAM_DIMS_16x32, OAM_NO_FLIP, 573, 8, 0),
    OAM_ENTRY(-7, -61, OAM_DIMS_8x16, OAM_NO_FLIP, 639, 8, 0),
};

const struct FrameData sKraidStatueOam_Idle[2] = {
    [0] = {
        .pFrame = sKraidStatueOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKraidStatueOam_Activating[13] = {
    [0] = {
        .pFrame = sKraidStatueOam_Activating_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sKraidStatueOam_Activating_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sKraidStatueOam_Activating_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sKraidStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sKraidStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sKraidStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sKraidStatueOam_Activating_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [7] = {
        .pFrame = sKraidStatueOam_Activating_Frame7,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [8] = {
        .pFrame = sKraidStatueOam_Activating_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [9] = {
        .pFrame = sKraidStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [10] = {
        .pFrame = sKraidStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [11] = {
        .pFrame = sKraidStatueOam_Activating_Frame3,
        .timer = UCHAR_MAX
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKraidStatueOam_Activated[7] = {
    [0] = {
        .pFrame = sKraidStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sKraidStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sKraidStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sKraidStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = {
        .pFrame = sKraidStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sKraidStatueOam_Activated_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKraidStatueOam_Opening[43] = {
    [0] = {
        .pFrame = sKraidStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sKraidStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sKraidStatueOam_Activating_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sKraidStatueOam_Activating_Frame7,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sKraidStatueOam_Activating_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sKraidStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sKraidStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [7] = {
        .pFrame = sKraidStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(1.0f)
    },
    [8] = {
        .pFrame = sKraidStatueOam_Opening_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [9] = {
        .pFrame = sKraidStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = {
        .pFrame = sKraidStatueOam_Opening_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [11] = {
        .pFrame = sKraidStatueOam_Opening_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [12] = {
        .pFrame = sKraidStatueOam_Opening_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [13] = {
        .pFrame = sKraidStatueOam_Opening_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [14] = {
        .pFrame = sKraidStatueOam_Opening_Frame14,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [15] = {
        .pFrame = sKraidStatueOam_Opening_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [16] = {
        .pFrame = sKraidStatueOam_Opening_Frame14,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [17] = {
        .pFrame = sKraidStatueOam_Opening_Frame17,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [18] = {
        .pFrame = sKraidStatueOam_Opening_Frame14,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [19] = {
        .pFrame = sKraidStatueOam_Opening_Frame17,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [20] = {
        .pFrame = sKraidStatueOam_Opening_Frame20,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [21] = {
        .pFrame = sKraidStatueOam_Opening_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [22] = {
        .pFrame = sKraidStatueOam_Opening_Frame20,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [23] = {
        .pFrame = sKraidStatueOam_Opening_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [24] = {
        .pFrame = sKraidStatueOam_Opening_Frame24,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [25] = {
        .pFrame = sKraidStatueOam_Opening_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [26] = {
        .pFrame = sKraidStatueOam_Opening_Frame24,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [27] = {
        .pFrame = sKraidStatueOam_Opening_Frame27,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [28] = {
        .pFrame = sKraidStatueOam_Opening_Frame24,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [29] = {
        .pFrame = sKraidStatueOam_Opening_Frame27,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [30] = {
        .pFrame = sKraidStatueOam_Opening_Frame30,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [31] = {
        .pFrame = sKraidStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [32] = {
        .pFrame = sKraidStatueOam_Opening_Frame32,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [33] = {
        .pFrame = sKraidStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [34] = {
        .pFrame = sKraidStatueOam_Opening_Frame32,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [35] = {
        .pFrame = sKraidStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [36] = {
        .pFrame = sKraidStatueOam_Opening_Frame32,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [37] = {
        .pFrame = sKraidStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [38] = {
        .pFrame = sKraidStatueOam_Opening_Frame32,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [39] = {
        .pFrame = sKraidStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [40] = {
        .pFrame = sKraidStatueOam_Opening_Frame32,
        .timer = TWO_THIRD_SECOND
    },
    [41] = {
        .pFrame = sKraidStatueOam_Opening_Frame41,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [42] = FRAME_DATA_TERMINATOR
};

const struct FrameData sKraidStatueOam_Opened[2] = {
    [0] = {
        .pFrame = sKraidStatueOam_Opened_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyStatueOam_Idle[2] = {
    [0] = {
        .pFrame = sRidleyStatueOam_Idle_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyStatueOam_Activating[13] = {
    [0] = {
        .pFrame = sRidleyStatueOam_Activating_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sRidleyStatueOam_Activating_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sRidleyStatueOam_Activating_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sRidleyStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sRidleyStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sRidleyStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sRidleyStatueOam_Activating_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [7] = {
        .pFrame = sRidleyStatueOam_Activating_Frame7,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [8] = {
        .pFrame = sRidleyStatueOam_Activating_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [9] = {
        .pFrame = sRidleyStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [10] = {
        .pFrame = sRidleyStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [11] = {
        .pFrame = sRidleyStatueOam_Activating_Frame3,
        .timer = UCHAR_MAX
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyStatueOam_Activated[7] = {
    [0] = {
        .pFrame = sRidleyStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sRidleyStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sRidleyStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sRidleyStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = {
        .pFrame = sRidleyStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [5] = {
        .pFrame = sRidleyStatueOam_Activated_Frame5,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyStatueOam_Opening[43] = {
    [0] = {
        .pFrame = sRidleyStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sRidleyStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = {
        .pFrame = sRidleyStatueOam_Activating_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sRidleyStatueOam_Activating_Frame7,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [4] = {
        .pFrame = sRidleyStatueOam_Activating_Frame6,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [5] = {
        .pFrame = sRidleyStatueOam_Activating_Frame5,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [6] = {
        .pFrame = sRidleyStatueOam_Activating_Frame4,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [7] = {
        .pFrame = sRidleyStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(1.0f)
    },
    [8] = {
        .pFrame = sRidleyStatueOam_Opening_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [9] = {
        .pFrame = sRidleyStatueOam_Activating_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = {
        .pFrame = sRidleyStatueOam_Opening_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [11] = {
        .pFrame = sRidleyStatueOam_Opening_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [12] = {
        .pFrame = sRidleyStatueOam_Opening_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [13] = {
        .pFrame = sRidleyStatueOam_Opening_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [14] = {
        .pFrame = sRidleyStatueOam_Opening_Frame14,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [15] = {
        .pFrame = sRidleyStatueOam_Opening_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [16] = {
        .pFrame = sRidleyStatueOam_Opening_Frame14,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [17] = {
        .pFrame = sRidleyStatueOam_Opening_Frame17,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [18] = {
        .pFrame = sRidleyStatueOam_Opening_Frame14,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [19] = {
        .pFrame = sRidleyStatueOam_Opening_Frame17,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [20] = {
        .pFrame = sRidleyStatueOam_Opening_Frame20,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [21] = {
        .pFrame = sRidleyStatueOam_Opening_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [22] = {
        .pFrame = sRidleyStatueOam_Opening_Frame20,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [23] = {
        .pFrame = sRidleyStatueOam_Opening_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [24] = {
        .pFrame = sRidleyStatueOam_Opening_Frame24,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [25] = {
        .pFrame = sRidleyStatueOam_Opening_Frame21,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [26] = {
        .pFrame = sRidleyStatueOam_Opening_Frame24,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [27] = {
        .pFrame = sRidleyStatueOam_Opening_Frame27,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [28] = {
        .pFrame = sRidleyStatueOam_Opening_Frame24,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [29] = {
        .pFrame = sRidleyStatueOam_Opening_Frame27,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [30] = {
        .pFrame = sRidleyStatueOam_Opening_Frame30,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [31] = {
        .pFrame = sRidleyStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [32] = {
        .pFrame = sRidleyStatueOam_Opening_Frame32,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [33] = {
        .pFrame = sRidleyStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [34] = {
        .pFrame = sRidleyStatueOam_Opening_Frame32,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [35] = {
        .pFrame = sRidleyStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [36] = {
        .pFrame = sRidleyStatueOam_Opening_Frame32,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [37] = {
        .pFrame = sRidleyStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [38] = {
        .pFrame = sRidleyStatueOam_Opening_Frame32,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [39] = {
        .pFrame = sRidleyStatueOam_Opening_Frame31,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [40] = {
        .pFrame = sRidleyStatueOam_Opening_Frame32,
        .timer = TWO_THIRD_SECOND
    },
    [41] = {
        .pFrame = sRidleyStatueOam_Opening_Frame41,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [42] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRidleyStatueOam_Opened[2] = {
    [0] = {
        .pFrame = sRidleyStatueOam_Opened_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};
