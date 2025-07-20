#include "data/ending_and_gallery_data.h"
#include "oam.h"

const u16 sEndingImageTextPal[14 * 16] = INCBIN_U16("data/ending/ImageText.pal");

static const u16 sEndingImageOam_LineTimer_English[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf0, OBJ_SIZE_16x16 | 0x1d4, 0x0,
    0xf0, OBJ_SIZE_16x16 | 0x1df, 0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1ed, 0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f5, 0x5,
    0xf0, OBJ_SIZE_16x16 | 0x0, 0x7,
    OBJ_SHAPE_VERTICAL | 0xf0, 0xf, 0x9,
    0xf0, OBJ_SIZE_16x16 | 0x16, 0xa,
    0xf0, OBJ_SIZE_16x16 | 0x21, 0xc
};

static const u16 sEndingImageOam_LinePercentage_English[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1fb, 0x12,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x10,
    0xf0, OBJ_SIZE_16x16 | 0x1e6, 0xe,
    0xf0, OBJ_SIZE_16x16 | 0xa, 0x14
};

static const u16 sEndingImageOam_LineClearTime_English[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1d2, 0x80,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f2, 0x84,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x12, 0x88
};

static const u16 sClearTimeEnglishOam_Clear_C[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1d2, 0x104
};

static const u16 sClearTimeEnglishOam_Clear_L[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1db, 0x114
};

static const u16 sClearTimeEnglishOam_Clear_E[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1e4, 0x108
};

static const u16 sClearTimeEnglishOam_Clear_A[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1ed, 0x100
};

static const u16 sClearTimeEnglishOam_Clear_R[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, 0x11e
};

static const u16 sClearTimeEnglishOam_Time_T[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0xa, 0x142
};

static const u16 sClearTimeEnglishOam_Time_I[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x12, 0x110
};

static const u16 sClearTimeEnglishOam_Time_M[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x18, 0x116
};

static const u16 sClearTimeEnglishOam_Time_E[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x23, 0x108
};

static const u16 sEndingImageOam_LineYourRate_English[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1c1, 0x8c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e1, 0x90,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1, 0x94,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x21, 0x98
};

static const u16 sYourRateEnglishOam_Your_Y[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1c2, 0x14a
};

static const u16 sYourRateEnglishOam_Your_O[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1cb, 0x11a
};

static const u16 sYourRateEnglishOam_Your_U[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1d5, 0x146
};

static const u16 sYourRateEnglishOam_Your_R[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1df, 0x11e
};

static const u16 sYourRateEnglishOam_Rate_R[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f1, 0x11e
};

static const u16 sYourRateEnglishOam_Rate_A[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1fb, 0x100
};

static const u16 sYourRateEnglishOam_Rate_T[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x4, 0x142
};

static const u16 sYourRateEnglishOam_Rate_E[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0xe, 0x108
};

static const u16 sYourRateEnglishOam_For_F[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x20, 0x10a
};

static const u16 sYourRateEnglishOam_For_O[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x29, 0x11a
};

static const u16 sYourRateEnglishOam_For_R[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x33, 0x11e
};

static const u16 sEndingImageOam_LineCollecting_English[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1b0, 0xc0,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1d0, 0xc4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, 0xc8,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x10, 0xcc,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x30, 0xd0,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x50, 0xd4
};

static const u16 sCollectingEnglishOam_Collecting_C1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1b0, 0x104
};

static const u16 sCollectingEnglishOam_Collecting_O[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1b9, 0x11a
};

static const u16 sCollectingEnglishOam_Collecting_L1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1c2, 0x114
};

static const u16 sCollectingEnglishOam_Collecting_L2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1ca, 0x114
};

static const u16 sCollectingEnglishOam_Collecting_E[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1d3, 0x108
};

static const u16 sCollectingEnglishOam_Collecting_C2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1dd, 0x104
};

static const u16 sCollectingEnglishOam_Collecting_T[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1e6, 0x142
};

static const u16 sCollectingEnglishOam_Collecting_I[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1ed, 0x110
};

static const u16 sCollectingEnglishOam_Collecting_N[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f3, 0x118
};

static const u16 sCollectingEnglishOam_Collecting_G[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1fe, 0x10c
};

static const u16 sCollectingEnglishOam_Items_I[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0xe, 0x110
};

static const u16 sCollectingEnglishOam_Items_T[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x14, 0x142
};

static const u16 sCollectingEnglishOam_Items_E[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1e, 0x108
};

static const u16 sCollectingEnglishOam_Items_M[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x27, 0x116
};

static const u16 sCollectingEnglishOam_Items_S[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x31, 0x140
};

static const u16 sCollectingEnglishOam_Is_I[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x41, 0x110
};

static const u16 sCollectingEnglishOam_Is_S[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x47, 0x140
};

static const u16 sEndingImageOam_LineNextMission_English[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ba, 0x1180,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1da, 0x1184,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1fa, 0x1188,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1a, 0x118c,
    0xf0, OBJ_SIZE_16x16 | 0x3a, 0x1190
};

const u16 sEndingImageOam_NewRecordEnglish[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e6, 0x5016,
    0xf0, OBJ_SIZE_16x16 | 0x6, 0x501a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x16, 0x501c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1e6, 0x5056,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x6, 0x505a,
    0x0, 0x16, 0x505c
};

#ifdef REGION_EU

static const u16 sFullLinesFrenchOam_0[OAM_DATA_SIZE(6)] = {
    6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ac, 0x80,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1cc, 0x84,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ec, 0x88,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0xc, 0x8c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x2c, 0x90,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4c, 0x94
};

static const u16 sClearTimeFrenchOam_0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ac, 0x106
};

static const u16 sClearTimeFrenchOam_1[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1b5, 0x146
};

static const u16 sClearTimeFrenchOam_2[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1be, 0x11e
};

static const u16 sClearTimeFrenchOam_3[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c8, 0x108
};

static const u16 sClearTimeFrenchOam_4[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d1, 0x108
};

static const u16 sClearTimeFrenchOam_5[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e3, 0x106
};

static const u16 sClearTimeFrenchOam_6[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ec, 0x108
};

static const u16 sClearTimeFrenchOam_7[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1fd, 0x114
};

static const u16 sClearTimeFrenchOam_8[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x6, 0x100
};

static const u16 sClearTimeFrenchOam_9[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x19, 0x116
};

static const u16 sClearTimeFrenchOam_10[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x22, 0x110
};

static const u16 sClearTimeFrenchOam_11[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x28, 0x140
};

static const u16 sClearTimeFrenchOam_12[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x31, 0x140
};

static const u16 sClearTimeFrenchOam_13[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x39, 0x110
};

static const u16 sClearTimeFrenchOam_14[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x3f, 0x11a
};

static const u16 sClearTimeFrenchOam_15[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x49, 0x118
};

static const u16 sFullLinesFrenchOam_3[OAM_DATA_SIZE(7)] = {
    7,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x198, 0xc0,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1b8, 0xc4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1d8, 0xc8,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f8, 0xcc,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x18, 0xd0,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x38, 0xd4,
    0xf0, OBJ_SIZE_16x16 | 0x58, 0xd8
};

static const u16 sCollectingFrenchOam_0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x198, 0x142
};

static const u16 sCollectingFrenchOam_1[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1a0, 0x100
};

static const u16 sCollectingFrenchOam_2[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ab, 0x146
};

static const u16 sCollectingFrenchOam_3[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1b5, 0x148
};

static const u16 sCollectingFrenchOam_4[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c7, 0x14c
};

static const u16 sCollectingFrenchOam_5[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d3, 0x11a
};

static const u16 sCollectingFrenchOam_6[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1dd, 0x102
};

static const u16 sCollectingFrenchOam_7[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e5, 0x112
};

static const u16 sCollectingFrenchOam_8[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x108
};

static const u16 sCollectingFrenchOam_9[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1f9, 0x142
};

static const u16 sCollectingFrenchOam_10[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x2, 0x140
};

static const u16 sCollectingFrenchOam_11[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x14, 0x104
};

static const u16 sCollectingFrenchOam_12[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e, 0x11a
};

static const u16 sCollectingFrenchOam_13[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x27, 0x114
};

static const u16 sCollectingFrenchOam_14[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x2f, 0x114
};

static const u16 sCollectingFrenchOam_15[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x38, 0x108
};

static const u16 sCollectingFrenchOam_16[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x42, 0x104
};

static const u16 sCollectingFrenchOam_17[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x4b, 0x142
};

static const u16 sCollectingFrenchOam_18[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x54, 0x108
};

static const u16 sCollectingFrenchOam_19[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x5d, 0x140
};

static const u16 sFullLinesFrenchOam_2[OAM_DATA_SIZE(8)] = {
    8,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ae, 0x1180,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0xe, 0x118c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x2e, 0x1190,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4e, 0x1194,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ce, 0x1184,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ee, 0x1188,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1ce, 0x11c4,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1ee, 0x11c8
};

static const u16 sEndingImageOam_NewRecordFrench[OAM_DATA_SIZE(4)] = {
    4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1de, 0x5016,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1fe, 0x501a,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1de, 0x5056,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1fe, 0x505a
};

static const u16 sFullLinesItalianOam_0[OAM_DATA_SIZE(7)] = {
    7,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1a7, 0x80,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1c7, 0x84,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e7, 0x88,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x7, 0x8c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x27, 0x90,
    0xf0, OBJ_SIZE_16x16 | 0x47, 0x94,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x57, 0x96
};

static const u16 sClearTimeItalianOam_0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1a7, 0x142
};

static const u16 sClearTimeItalianOam_1[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1b0, 0x108
};

static const u16 sClearTimeItalianOam_2[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1b9, 0x116
};

static const u16 sClearTimeItalianOam_3[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c3, 0x11c
};

static const u16 sClearTimeItalianOam_4[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1cc, 0x11a
};

static const u16 sClearTimeItalianOam_5[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1de, 0x104
};

static const u16 sClearTimeItalianOam_6[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e7, 0x11a
};

static const u16 sClearTimeItalianOam_7[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x116
};

static const u16 sClearTimeItalianOam_8[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1fb, 0x11c
};

static const u16 sClearTimeItalianOam_9[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x4, 0x114
};

static const u16 sClearTimeItalianOam_10[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0xd, 0x108
};

static const u16 sClearTimeItalianOam_11[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x16, 0x142
};

static const u16 sClearTimeItalianOam_12[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e, 0x100
};

static const u16 sClearTimeItalianOam_13[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x28, 0x116
};

static const u16 sClearTimeItalianOam_14[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x32, 0x108
};

static const u16 sClearTimeItalianOam_15[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x3b, 0x118
};

static const u16 sClearTimeItalianOam_16[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x45, 0x142
};

static const u16 sClearTimeItalianOam_17[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x4e, 0x11a
};

static const u16 sFullLinesItalianOam_2[OAM_DATA_SIZE(4)] = {
    4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1cd, 0xc0,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ed, 0xc4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0xd, 0xc8,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x2d, 0xcc
};

static const u16 sYourRateItalianOam_0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1cd, 0x11c
};

static const u16 sYourRateItalianOam_1[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d6, 0x108
};

static const u16 sYourRateItalianOam_2[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1df, 0x11e
};

static const u16 sYourRateItalianOam_3[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e8, 0x104
};

static const u16 sYourRateItalianOam_4[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1f1, 0x108
};

static const u16 sYourRateItalianOam_5[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1fa, 0x118
};

static const u16 sYourRateItalianOam_6[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x4, 0x142
};

static const u16 sYourRateItalianOam_7[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0xd, 0x146
};

static const u16 sYourRateItalianOam_8[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x16, 0x100
};

static const u16 sYourRateItalianOam_9[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x20, 0x114
};

static const u16 sYourRateItalianOam_10[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x29, 0x108
};

static const u16 sFullLinesItalianOam_3[OAM_DATA_SIZE(7)] = {
    7,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1b2, 0xcd,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1d2, 0xd1,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f2, 0xd5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x12, 0xd9,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x32, 0xdd,
    0xf0, OBJ_SIZE_16x16 | 0x3a, 0x98,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4a, 0x9a
};

static const u16 sCollectingItalianOam_0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1b2, 0x140
};

static const u16 sCollectingItalianOam_1[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1bb, 0x142
};

static const u16 sCollectingItalianOam_2[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c4, 0x11e
};

static const u16 sCollectingItalianOam_3[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1cd, 0x146
};

static const u16 sCollectingItalianOam_4[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d6, 0x116
};

static const u16 sCollectingItalianOam_5[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, 0x108
};

static const u16 sCollectingItalianOam_6[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e9, 0x118
};

static const u16 sCollectingItalianOam_7[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1f3, 0x142
};

static const u16 sCollectingItalianOam_8[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fa, 0x110
};

static const u16 sCollectingItalianOam_9[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x8, 0x11e
};

static const u16 sCollectingItalianOam_10[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x11, 0x100
};

static const u16 sCollectingItalianOam_11[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c, 0x104
};

static const u16 sCollectingItalianOam_12[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x26, 0x104
};

static const u16 sCollectingItalianOam_13[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x30, 0x11a
};

static const u16 sCollectingItalianOam_14[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x38, 0x114
};

static const u16 sCollectingItalianOam_15[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x3f, 0x142
};

static const u16 sCollectingItalianOam_16[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x46, 0x110
};

static const u16 sFullLinesItalianOam_5[OAM_DATA_SIZE(6)] = {
    6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1b4, 0x11c0,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1d4, 0x11c4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f4, 0x11c8,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x14, 0x11cc,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x34, 0x11d0,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1cc, 0x1203
};

static const u16 sEndingImageOam_NewRecordItalian[OAM_DATA_SIZE(6)] = {
    6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e5, 0x5016,
    0xf0, OBJ_SIZE_16x16 | 0x5, 0x501a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x15, 0x501c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1e5, 0x5056,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x5, 0x505a,
    0x0, 0x15, 0x505c
};

static const u16 sFullLinesSpanishOam_0[OAM_DATA_SIZE(5)] = {
    5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ba, 0x80,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1da, 0x84,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1fa, 0x88,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1a, 0x8c,
    0xf0, OBJ_SIZE_16x16 | 0x3a, 0x90
};

static const u16 sClearTimeSpanishOam_0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ba, 0x142
};

static const u16 sClearTimeSpanishOam_1[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1c1, 0x110
};

static const u16 sClearTimeSpanishOam_2[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c7, 0x108
};

static const u16 sClearTimeSpanishOam_3[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, 0x116
};

static const u16 sClearTimeSpanishOam_4[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1da, 0x11c
};

static const u16 sClearTimeSpanishOam_5[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e3, 0x11a
};

static const u16 sClearTimeSpanishOam_6[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f7, 0x110
};

static const u16 sClearTimeSpanishOam_7[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1fd, 0x118
};

static const u16 sClearTimeSpanishOam_8[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x8, 0x144
};

static const u16 sClearTimeSpanishOam_9[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x13, 0x108
};

static const u16 sClearTimeSpanishOam_10[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c, 0x11e
};

static const u16 sClearTimeSpanishOam_11[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x25, 0x142
};

static const u16 sClearTimeSpanishOam_12[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x2c, 0x110
};

static const u16 sClearTimeSpanishOam_13[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x32, 0x106
};

static const u16 sClearTimeSpanishOam_14[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x3b, 0x11a
};

static const u16 sFullLinesSpanishOam_3[OAM_DATA_SIZE(7)] = {
    7,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x19f, 0xc0,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1bf, 0xc4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1df, 0xc8,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ff, 0xcc,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f, 0xd0,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x3f, 0xd4,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x5f, 0xd8
};

static const u16 sCollectingSpanishOam_0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x19f, 0x11c
};

static const u16 sCollectingSpanishOam_1[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1a8, 0x11a
};

static const u16 sCollectingSpanishOam_2[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1b1, 0x11e
};

static const u16 sCollectingSpanishOam_3[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ba, 0x104
};

static const u16 sCollectingSpanishOam_4[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c3, 0x108
};

static const u16 sCollectingSpanishOam_5[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1cc, 0x118
};

static const u16 sCollectingSpanishOam_6[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d6, 0x142
};

static const u16 sCollectingSpanishOam_7[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1de, 0x100
};

static const u16 sCollectingSpanishOam_8[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e7, 0x112
};

static const u16 sCollectingSpanishOam_9[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1f1, 0x108
};

static const u16 sCollectingSpanishOam_10[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x3, 0x106
};

static const u16 sCollectingSpanishOam_11[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0xd, 0x108
};

static const u16 sCollectingSpanishOam_12[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1f, 0x11a
};

static const u16 sCollectingSpanishOam_13[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x29, 0x102
};

static const u16 sCollectingSpanishOam_14[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x31, 0x112
};

static const u16 sCollectingSpanishOam_15[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x3b, 0x108
};

static const u16 sCollectingSpanishOam_16[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x44, 0x142
};

static const u16 sCollectingSpanishOam_17[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x4d, 0x11a
};

static const u16 sCollectingSpanishOam_18[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x56, 0x140
};

static const u16 sFullLinesSpanishOam_2[OAM_DATA_SIZE(7)] = {
    7,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ae, 0x1180,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ce, 0x1184,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ee, 0x1188,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0xe, 0x118c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x2e, 0x1190,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4e, 0x1194,
    0x0, 0x1ee, 0x11c8
};

static const u16 sEndingImageOam_NewRecordSpanish[OAM_DATA_SIZE(6)] = {
    6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e6, 0x5016,
    0xf0, OBJ_SIZE_16x16 | 0x6, 0x501a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x16, 0x501c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1e6, 0x5056,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x6, 0x505a,
    0x0, 0x16, 0x505c
};

static const u16 sFullLinesGermanOam_0[OAM_DATA_SIZE(5)] = {
    5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1c6, 0x80,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e6, 0x84,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x6, 0x88,
    0xf0, OBJ_SIZE_16x16 | 0x26, 0x8c,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x36, 0x8e
};

static const u16 sClearTimeGermanOam_0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c6, 0x102
};

static const u16 sClearTimeGermanOam_1[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1cf, 0x108
};

static const u16 sClearTimeGermanOam_2[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d8, 0x118
};

static const u16 sClearTimeGermanOam_3[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e2, 0x150
};

static const u16 sClearTimeGermanOam_4[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1eb, 0x142
};

static const u16 sClearTimeGermanOam_5[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f2, 0x110
};

static const u16 sClearTimeGermanOam_6[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, 0x10c
};

static const u16 sClearTimeGermanOam_7[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1, 0x142
};

static const u16 sClearTimeGermanOam_8[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0xa, 0x108
};

static const u16 sClearTimeGermanOam_9[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1a, 0x14e
};

static const u16 sClearTimeGermanOam_10[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x24, 0x108
};

static const u16 sClearTimeGermanOam_11[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x2b, 0x110
};

static const u16 sClearTimeGermanOam_12[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x30, 0x142
};

static const u16 sFullLinesGermanOam_3[OAM_DATA_SIZE(5)] = {
    5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1be, 0xc0,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1de, 0xc4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1fe, 0xc8,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e, 0xcc,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x3e, 0xd0
};

static const u16 sCollectingGermanOam_0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1be, 0x10c
};

static const u16 sCollectingGermanOam_1[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c7, 0x108
};

static const u16 sCollectingGermanOam_2[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, 0x10a
};

static const u16 sCollectingGermanOam_3[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d8, 0x146
};

static const u16 sCollectingGermanOam_4[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e2, 0x118
};

static const u16 sCollectingGermanOam_5[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ec, 0x106
};

static const u16 sCollectingGermanOam_6[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1f5, 0x108
};

static const u16 sCollectingGermanOam_7[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1fe, 0x118
};

static const u16 sCollectingGermanOam_8[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x8, 0x108
};

static const u16 sCollectingGermanOam_9[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x17, 0x110
};

static const u16 sCollectingGermanOam_10[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c, 0x142
};

static const u16 sCollectingGermanOam_11[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x25, 0x108
};

static const u16 sCollectingGermanOam_12[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x2e, 0x116
};

static const u16 sCollectingGermanOam_13[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x38, 0x140
};

static const u16 sFullLinesGermanOam_2[OAM_DATA_SIZE(6)] = {
    6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1af, 0x1180,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1cf, 0x1184,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ef, 0x1188,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0xf, 0x118c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x2f, 0x1190,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4f, 0x1194
};

static const u16 sEndingImageOam_NewRecordGerman[OAM_DATA_SIZE(6)] = {
    6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e6, 0x5016,
    0xf0, OBJ_SIZE_16x16 | 0x6, 0x501a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x16, 0x501c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1e6, 0x5056,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x6, 0x505a,
    0x0, 0x16, 0x505c
};

#else // !REGION_EU

static const u16 sEndingImage_UnusedOam_549f12[OAM_DATA_SIZE(5)] = {
    5,
    0xf0, OBJ_SIZE_16x16 | 0x1e5, 0x0,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fd, 0x4,
    0xf0, OBJ_SIZE_16x16 | 0x5, 0x5,
    0xf0, OBJ_SIZE_16x16 | 0x10, 0x7
};

static const u16 sEndingImage_UnusedOam_549f32[OAM_DATA_SIZE(4)] = {
    4,
    0xf0, OBJ_SIZE_16x16 | 0x1e8, 0x9,
    0xf0, OBJ_SIZE_16x16 | 0x1f3, 0xb,
    0xf0, OBJ_SIZE_16x16 | 0x1fe, 0xd,
    0xf0, OBJ_SIZE_16x16 | 0x9, 0xf
};

static const u16 sEndingImage_UnusedOam_549f4c[OAM_DATA_SIZE(5)] = {
    5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1b0, 0x80,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1d0, 0x84,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, 0x88,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x10, 0x8c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x30, 0x90
};

static const u16 sEndingImage_UnusedOam_549f6c[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1b1, 0x106
};

static const u16 sEndingImage_UnusedOam_549f74[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ba, 0x146
};

static const u16 sEndingImage_UnusedOam_549f7c[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c3, 0x11e
};

static const u16 sEndingImage_UnusedOam_549f84[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1cc, 0x108
};

static const u16 sEndingImage_UnusedOam_549f8c[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d5, 0x108
};

static const u16 sEndingImage_UnusedOam_549f94[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e3, 0x106
};

static const u16 sEndingImage_UnusedOam_549f9c[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ec, 0x108
};

static const u16 sEndingImage_UnusedOam_549fa4[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1f9, 0x114
};

static const u16 sEndingImage_UnusedOam_549fac[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x2, 0x100
};

static const u16 sEndingImage_UnusedOam_549fb4[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x10, 0x116
};

static const u16 sEndingImage_UnusedOam_549fbc[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x19, 0x110
};

static const u16 sEndingImage_UnusedOam_549fc4[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x21, 0x140
};

static const u16 sEndingImage_UnusedOam_549fcc[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x2a, 0x140
};

static const u16 sEndingImage_UnusedOam_549fd4[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x32, 0x110
};

static const u16 sEndingImage_UnusedOam_549fdc[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x3a, 0x11a
};

static const u16 sEndingImage_UnusedOam_549fe4[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x43, 0x118
};

static const u16 sEndingImage_UnusedOam_549fec[OAM_DATA_SIZE(7)] = {
    7,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x199, 0xc0,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1b9, 0xc4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1d9, 0xc8,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f9, 0xcc,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x19, 0xd0,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x39, 0xd4,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x59, 0xd8
};

static const u16 sEndingImage_UnusedOam_54a018[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x19c, 0x142
};

static const u16 sEndingImage_UnusedOam_54a020[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1a4, 0x100
};

static const u16 sEndingImage_UnusedOam_54a028[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ae, 0x146
};

static const u16 sEndingImage_UnusedOam_54a030[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1b7, 0x148
};

static const u16 sEndingImage_UnusedOam_54a038[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c6, 0x14c
};

static const u16 sEndingImage_UnusedOam_54a040[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d2, 0x11a
};

static const u16 sEndingImage_UnusedOam_54a048[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1db, 0x102
};

static const u16 sEndingImage_UnusedOam_54a050[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e3, 0x112
};

static const u16 sEndingImage_UnusedOam_54a058[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ed, 0x108
};

static const u16 sEndingImage_UnusedOam_54a060[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, 0x142
};

static const u16 sEndingImage_UnusedOam_54a068[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ff, 0x140
};

static const u16 sEndingImage_UnusedOam_54a070[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0xd, 0x104
};

static const u16 sEndingImage_UnusedOam_54a078[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x16, 0x11a
};

static const u16 sEndingImage_UnusedOam_54a080[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e, 0x114
};

static const u16 sEndingImage_UnusedOam_54a088[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x26, 0x114
};

static const u16 sEndingImage_UnusedOam_54a090[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x2f, 0x108
};

static const u16 sEndingImage_UnusedOam_54a098[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x38, 0x104
};

static const u16 sEndingImage_UnusedOam_54a0a0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x41, 0x142
};

static const u16 sEndingImage_UnusedOam_54a0a8[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x4a, 0x108
};

static const u16 sEndingImage_UnusedOam_54a0b0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x53, 0x140
};

static const u16 sEndingImage_UnusedOam_54a0b8[OAM_DATA_SIZE(3)] = {
    3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1de, 0x180,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1fe, 0x184,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1e, 0x188
};

static const u16 sEndingImage_UnusedOam_54a0cc[OAM_DATA_SIZE(5)] = {
    5,
    0xf0, OBJ_SIZE_16x16 | 0x1e5, 0x0,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fd, 0x4,
    0xf0, OBJ_SIZE_16x16 | 0x5, 0x5,
    0xf0, OBJ_SIZE_16x16 | 0x10, 0x7
};

static const u16 sEndingImage_UnusedOam_54a0ec[OAM_DATA_SIZE(4)] = {
    4,
    0xf0, OBJ_SIZE_16x16 | 0x1e8, 0x9,
    0xf0, OBJ_SIZE_16x16 | 0x1f3, 0xb,
    0xf0, OBJ_SIZE_16x16 | 0x1fe, 0xd,
    0xf0, OBJ_SIZE_16x16 | 0x9, 0xf
};

static const u16 sEndingImage_UnusedOam_54a106[OAM_DATA_SIZE(6)] = {
    6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ac, 0x80,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1cc, 0x84,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ec, 0x88,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0xc, 0x8c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x2c, 0x90,
    0xf0, OBJ_SIZE_16x16 | 0x4c, 0x94
};

static const u16 sEndingImage_UnusedOam_54a12c[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ac, 0x142
};

static const u16 sEndingImage_UnusedOam_54a134[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1b5, 0x108
};

static const u16 sEndingImage_UnusedOam_54a13c[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1be, 0x116
};

static const u16 sEndingImage_UnusedOam_54a144[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c8, 0x11c
};

static const u16 sEndingImage_UnusedOam_54a14c[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d1, 0x11a
};

static const u16 sEndingImage_UnusedOam_54a154[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1de, 0x104
};

static const u16 sEndingImage_UnusedOam_54a15c[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e7, 0x11a
};

static const u16 sEndingImage_UnusedOam_54a164[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x116
};

static const u16 sEndingImage_UnusedOam_54a16c[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1fa, 0x11c
};

static const u16 sEndingImage_UnusedOam_54a174[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x2, 0x114
};

static const u16 sEndingImage_UnusedOam_54a17c[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0xb, 0x108
};

static const u16 sEndingImage_UnusedOam_54a184[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x14, 0x142
};

static const u16 sEndingImage_UnusedOam_54a18c[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c, 0x100
};

static const u16 sEndingImage_UnusedOam_54a194[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x26, 0x116
};

static const u16 sEndingImage_UnusedOam_54a19c[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x30, 0x108
};

static const u16 sEndingImage_UnusedOam_54a1a4[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x39, 0x118
};

static const u16 sEndingImage_UnusedOam_54a1ac[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x43, 0x142
};

static const u16 sEndingImage_UnusedOam_54a1b4[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x4b, 0x11a
};

static const u16 sEndingImage_UnusedOam_54a1bc[OAM_DATA_SIZE(4)] = {
    4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ce, 0xc0,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ee, 0xc4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0xe, 0xc8,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x2e, 0xcc
};

static const u16 sEndingImage_UnusedOam_54a1d6[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ce, 0x11c
};

static const u16 sEndingImage_UnusedOam_54a1de[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d7, 0x108
};

static const u16 sEndingImage_UnusedOam_54a1e6[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, 0x11e
};

static const u16 sEndingImage_UnusedOam_54a1ee[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e9, 0x104
};

static const u16 sEndingImage_UnusedOam_54a1f6[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1f2, 0x108
};

static const u16 sEndingImage_UnusedOam_54a1fe[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1fb, 0x118
};

static const u16 sEndingImage_UnusedOam_54a206[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x5, 0x142
};

static const u16 sEndingImage_UnusedOam_54a20e[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0xe, 0x146
};

static const u16 sEndingImage_UnusedOam_54a216[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x17, 0x100
};

static const u16 sEndingImage_UnusedOam_54a21e[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x20, 0x114
};

static const u16 sEndingImage_UnusedOam_54a226[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x29, 0x108
};

static const u16 sEndingImage_UnusedOam_54a22e[OAM_DATA_SIZE(5)] = {
    5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1b6, 0xcd,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1d6, 0xd1,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f6, 0xd5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x16, 0xd9,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x36, 0x96
};

static const u16 sEndingImage_UnusedOam_54a24e[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1b6, 0x140
};

static const u16 sEndingImage_UnusedOam_54a256[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1bf, 0x142
};

static const u16 sEndingImage_UnusedOam_54a25e[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c8, 0x11e
};

static const u16 sEndingImage_UnusedOam_54a266[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d1, 0x146
};

static const u16 sEndingImage_UnusedOam_54a26e[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1da, 0x116
};

static const u16 sEndingImage_UnusedOam_54a276[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e4, 0x108
};

static const u16 sEndingImage_UnusedOam_54a27e[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ed, 0x118
};

static const u16 sEndingImage_UnusedOam_54a286[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1f7, 0x142
};

static const u16 sEndingImage_UnusedOam_54a28e[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fe, 0x110
};

static const u16 sEndingImage_UnusedOam_54a296[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x9, 0x11e
};

static const u16 sEndingImage_UnusedOam_54a29e[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x12, 0x100
};

static const u16 sEndingImage_UnusedOam_54a2a6[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c, 0x104
};

static const u16 sEndingImage_UnusedOam_54a2ae[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x25, 0x104
};

static const u16 sEndingImage_UnusedOam_54a2b6[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x2e, 0x11a
};

static const u16 sEndingImage_UnusedOam_54a2be[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x36, 0x114
};

static const u16 sEndingImage_UnusedOam_54a2c6[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x3c, 0x142
};

static const u16 sEndingImage_UnusedOam_54a2ce[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x43, 0x110
};

static const u16 sEndingImage_UnusedOam_54a2d6[OAM_DATA_SIZE(5)] = {
    5,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1b4, 0x180,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1d4, 0x184,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1f4, 0x188,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x14, 0x18c,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x34, 0x190
};

static const u16 sEndingImage_UnusedOam_54a2f6[OAM_DATA_SIZE(5)] = {
    5,
    0xf0, OBJ_SIZE_16x16 | 0x1e5, 0x0,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fd, 0x4,
    0xf0, OBJ_SIZE_16x16 | 0x5, 0x5,
    0xf0, OBJ_SIZE_16x16 | 0x10, 0x7
};

static const u16 sEndingImage_UnusedOam_54a316[OAM_DATA_SIZE(4)] = {
    4,
    0xf0, OBJ_SIZE_16x16 | 0x1e8, 0x9,
    0xf0, OBJ_SIZE_16x16 | 0x1f3, 0xb,
    0xf0, OBJ_SIZE_16x16 | 0x1fe, 0xd,
    0xf0, OBJ_SIZE_16x16 | 0x9, 0xf
};

static const u16 sEndingImage_UnusedOam_54a330[OAM_DATA_SIZE(5)] = {
    5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1bb, 0x80,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1db, 0x84,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1fb, 0x88,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1b, 0x8c,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x3b, 0x90
};

static const u16 sEndingImage_UnusedOam_54a350[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1bc, 0x142
};

static const u16 sEndingImage_UnusedOam_54a358[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1c3, 0x110
};

static const u16 sEndingImage_UnusedOam_54a360[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1cb, 0x108
};

static const u16 sEndingImage_UnusedOam_54a368[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d4, 0x116
};

static const u16 sEndingImage_UnusedOam_54a370[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1de, 0x11c
};

static const u16 sEndingImage_UnusedOam_54a378[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e7, 0x11a
};

static const u16 sEndingImage_UnusedOam_54a380[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f2, 0x110
};

static const u16 sEndingImage_UnusedOam_54a388[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1fa, 0x118
};

static const u16 sEndingImage_UnusedOam_54a390[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x4, 0x144
};

static const u16 sEndingImage_UnusedOam_54a398[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0xe, 0x108
};

static const u16 sEndingImage_UnusedOam_54a3a0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x17, 0x11e
};

static const u16 sEndingImage_UnusedOam_54a3a8[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x20, 0x142
};

static const u16 sEndingImage_UnusedOam_54a3b0[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x27, 0x110
};

static const u16 sEndingImage_UnusedOam_54a3b8[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x2f, 0x106
};

static const u16 sEndingImage_UnusedOam_54a3c0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x38, 0x11a
};

static const u16 sEndingImage_UnusedOam_54a3c8[OAM_DATA_SIZE(6)] = {
    6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1a3, 0xc0,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1c3, 0xc4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e3, 0xc8,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x3, 0xcc,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x23, 0xd0,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x43, 0xd4
};

static const u16 sEndingImage_UnusedOam_54a3ee[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1a3, 0x11c
};

static const u16 sEndingImage_UnusedOam_54a3f6[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ac, 0x11a
};

static const u16 sEndingImage_UnusedOam_54a3fe[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1b5, 0x11e
};

static const u16 sEndingImage_UnusedOam_54a406[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1be, 0x104
};

static const u16 sEndingImage_UnusedOam_54a40e[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c7, 0x108
};

static const u16 sEndingImage_UnusedOam_54a416[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d0, 0x118
};

static const u16 sEndingImage_UnusedOam_54a41e[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1da, 0x142
};

static const u16 sEndingImage_UnusedOam_54a426[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e2, 0x100
};

static const u16 sEndingImage_UnusedOam_54a42e[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1eb, 0x112
};

static const u16 sEndingImage_UnusedOam_54a436[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0x108
};

static const u16 sEndingImage_UnusedOam_54a43e[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x2, 0x106
};

static const u16 sEndingImage_UnusedOam_54a446[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0xb, 0x108
};

static const u16 sEndingImage_UnusedOam_54a44e[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x19, 0x11a
};

static const u16 sEndingImage_UnusedOam_54a456[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x22, 0x102
};

static const u16 sEndingImage_UnusedOam_54a45e[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x2a, 0x112
};

static const u16 sEndingImage_UnusedOam_54a466[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x33, 0x108
};

static const u16 sEndingImage_UnusedOam_54a46e[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x3c, 0x142
};

static const u16 sEndingImage_UnusedOam_54a476[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x45, 0x11a
};

static const u16 sEndingImage_UnusedOam_54a47e[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x4e, 0x140
};

static const u16 sEndingImage_UnusedOam_54a486[OAM_DATA_SIZE(6)] = {
    6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1b2, 0x180,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1d2, 0x184,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f2, 0x188,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x12, 0x18c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x32, 0x190,
    0x0, 0x1ea, 0x1c7
};

static const u16 sEndingImage_UnusedOam_54a4ac[OAM_DATA_SIZE(5)] = {
    5,
    0xf0, OBJ_SIZE_16x16 | 0x1e5, 0x0,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fd, 0x4,
    0xf0, OBJ_SIZE_16x16 | 0x5, 0x5,
    0xf0, OBJ_SIZE_16x16 | 0x10, 0x7
};

static const u16 sEndingImage_UnusedOam_54a4cc[OAM_DATA_SIZE(4)] = {
    4,
    0xf0, OBJ_SIZE_16x16 | 0x1e8, 0x9,
    0xf0, OBJ_SIZE_16x16 | 0x1f3, 0xb,
    0xf0, OBJ_SIZE_16x16 | 0x1fe, 0xd,
    0xf0, OBJ_SIZE_16x16 | 0x9, 0xf
};

static const u16 sEndingImage_UnusedOam_54a4e6[OAM_DATA_SIZE(4)] = {
    4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1c3, 0x80,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e3, 0x84,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x3, 0x88,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x23, 0x8c
};

static const u16 sEndingImage_UnusedOam_54a500[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c3, 0x102
};

static const u16 sEndingImage_UnusedOam_54a508[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1cc, 0x108
};

static const u16 sEndingImage_UnusedOam_54a510[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d5, 0x118
};

static const u16 sEndingImage_UnusedOam_54a518[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e0, 0x150
};

static const u16 sEndingImage_UnusedOam_54a520[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ea, 0x142
};

static const u16 sEndingImage_UnusedOam_54a528[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f2, 0x110
};

static const u16 sEndingImage_UnusedOam_54a530[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1fa, 0x10c
};

static const u16 sEndingImage_UnusedOam_54a538[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x3, 0x142
};

static const u16 sEndingImage_UnusedOam_54a540[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0xc, 0x108
};

static const u16 sEndingImage_UnusedOam_54a548[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1a, 0x14e
};

static const u16 sEndingImage_UnusedOam_54a550[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x23, 0x108
};

static const u16 sEndingImage_UnusedOam_54a558[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x2b, 0x110
};

static const u16 sEndingImage_UnusedOam_54a560[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x33, 0x142
};

static const u16 sEndingImage_UnusedOam_54a568[OAM_DATA_SIZE(5)] = {
    5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1bf, 0xc0,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1df, 0xc4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ff, 0xc8,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f, 0xcc,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x3f, 0xd0
};

static const u16 sEndingImage_UnusedOam_54a588[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1bf, 0x10c
};

static const u16 sEndingImage_UnusedOam_54a590[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c8, 0x108
};

static const u16 sEndingImage_UnusedOam_54a598[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1d1, 0x10a
};

static const u16 sEndingImage_UnusedOam_54a5a0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1da, 0x146
};

static const u16 sEndingImage_UnusedOam_54a5a8[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1e3, 0x118
};

static const u16 sEndingImage_UnusedOam_54a5b0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ed, 0x106
};

static const u16 sEndingImage_UnusedOam_54a5b8[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1f6, 0x108
};

static const u16 sEndingImage_UnusedOam_54a5c0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1ff, 0x118
};

static const u16 sEndingImage_UnusedOam_54a5c8[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x9, 0x108
};

static const u16 sEndingImage_UnusedOam_54a5d0[OAM_DATA_SIZE(1)] = {
    1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x14, 0x110
};

static const u16 sEndingImage_UnusedOam_54a5d8[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x1c, 0x142
};

static const u16 sEndingImage_UnusedOam_54a5e0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x25, 0x108
};

static const u16 sEndingImage_UnusedOam_54a5e8[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x2e, 0x116
};

static const u16 sEndingImage_UnusedOam_54a5f0[OAM_DATA_SIZE(1)] = {
    1,
    0xf0, OBJ_SIZE_16x16 | 0x38, 0x140
};

static const u16 sEndingImage_UnusedOam_54a5f8[OAM_DATA_SIZE(5)] = {
    5,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1b0, 0x180,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1d0, 0x184,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1f0, 0x188,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x10, 0x18c,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x30, 0x190
};

#endif // REGION_EU

static const u16 sEndingImageOam_LineClearTime_Hiragana[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1dc, 0x80,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1fc, 0x84,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1c, 0x88
};

// ク
static const u16 sClearTimeHiraganaOam_0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1dc, 0xc0
};

// リ
static const u16 sClearTimeHiraganaOam_1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1e8, 0xc2
};

// ア
static const u16 sClearTimeHiraganaOam_2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0xc4
};

// タ
static const u16 sClearTimeHiraganaOam_3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1, 0xc6
};

// イ
static const u16 sClearTimeHiraganaOam_4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0xd, 0xc8
};

// ム
static const u16 sClearTimeHiraganaOam_5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x18, 0xca
};

static const u16 sEndingImageOam_LineCollecting_Hiragana[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1bb, 0x100,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1db, 0x104,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1fb, 0x108,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1b, 0x10c,
    0xf0, OBJ_SIZE_16x16 | 0x3b, 0x110
};

// ア
static const u16 sYourRateHiraganaOam_0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1bb, 0x140
};

// イ
static const u16 sYourRateHiraganaOam_1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1c7, 0x142
};

// テ
static const u16 sYourRateHiraganaOam_2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1d3, 0x144
};

// ム
static const u16 sYourRateHiraganaOam_3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1df, 0x146
};

// か
static const u16 sYourRateHiraganaOam_4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1ef, 0x148
};

// い
static const u16 sYourRateHiraganaOam_5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1fd, 0x14a
};

// し
static const u16 sYourRateHiraganaOam_6[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0xa, 0x14c
};

// ゅ
static const u16 sYourRateHiraganaOam_7[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x16, 0x14e
};

// う
static const u16 sYourRateHiraganaOam_8[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x22, 0x150
};

// り
static const u16 sYourRateHiraganaOam_9[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x2e, 0x152
};

// つ
static const u16 sYourRateHiraganaOam_10[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x3a, 0x154
};

const u16 sCreditsCharactersPal[3 * 16] = INCBIN_U16("data/ending/CreditsCharacters.pal");
const u16 sCreditsChozoWallPal[15 * 16] = INCBIN_U16("data/ending/CreditsChozoWall.pal");

static const u16 sEndingImage_Palette_0[16 * 16] = INCBIN_U16("data/ending/Image_0.pal");
static const u16 sEndingImage_Palette_1[16 * 16] = INCBIN_U16("data/ending/Image_1.pal");
static const u16 sEndingImage_Palette_2[16 * 16] = INCBIN_U16("data/ending/Image_2.pal");
static const u16 sEndingImage_Palette_3[16 * 16] = INCBIN_U16("data/ending/Image_3.pal");
static const u16 sEndingImage_Palette_4[16 * 16] = INCBIN_U16("data/ending/Image_4.pal");
static const u16 sEndingImage_Palette_5[16 * 16] = INCBIN_U16("data/ending/Image_5.pal");
static const u16 sEndingImage_Palette_6[16 * 16] = INCBIN_U16("data/ending/Image_6.pal");
static const u16 sEndingImage_Palette_7[16 * 16] = INCBIN_U16("data/ending/Image_7.pal");

const u16 sEndingPosingPal[13 * 16] = INCBIN_U16("data/ending/Posing.pal");
const u16 sEndingPosingPal_White1[5 * 16] = INCBIN_U16("data/ending/Posing_White1.pal");
const u16 sEndingPosingPal_White2[5 * 16] = INCBIN_U16("data/ending/Posing_White2.pal");
const u16 sEndingPosingPal_White3[5 * 16] = INCBIN_U16("data/ending/Posing_White3.pal");
const u16 sEndingPosingPal_White4[5 * 16] = INCBIN_U16("data/ending/Posing_White4.pal");

const u16 sUnlockedOptionsPal[1 * 16] = INCBIN_U16("data/ending/UnlockedOptions.pal");

const struct EndingImageOam sEndingImageOam_FullLines_English[ENDING_IMAGE_LINE_END] = {
    [ENDING_IMAGE_LINE_CLEAR_TIME] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sEndingImageOam_LineClearTime_English
    },
    [ENDING_IMAGE_LINE_TIMER] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE - 4,
        .pFrame = sEndingImageOam_LineTimer_English
    },
    [ENDING_IMAGE_LINE_YOUR_RATE] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sEndingImageOam_LineYourRate_English
    },
    [ENDING_IMAGE_LINE_COLLECTING] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sEndingImageOam_LineCollecting_English
    },
    [ENDING_IMAGE_LINE_PERCENTAGE] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 4,
        .yPosition = BLOCK_SIZE * 2,
        .pFrame = sEndingImageOam_LinePercentage_English
    },
    [ENDING_IMAGE_LINE_NEXT_MISSION] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE - 2,
        .pFrame = sEndingImageOam_LineNextMission_English
    },
};

const struct EndingImageOam sEndingImageOam_ClearTime_English[9] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Clear_C
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 1,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Clear_L
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 2,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Clear_E
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 3,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Clear_A
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 4,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Clear_R
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 5,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Time_T
    },
    [6] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 6,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Time_I
    },
    [7] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 7,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Time_M
    },
    [8] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 8,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Time_E
    }
};

const struct EndingImageOam sEndingImageOam_YourRate_English[11] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_Your_Y
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 1,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_Your_O
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 2,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_Your_U
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 3,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_Your_R
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 4,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_Rate_R
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 5,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_Rate_A
    },
    [6] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 6,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_Rate_T
    },
    [7] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 7,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_Rate_E
    },
    [8] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 8,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_For_F
    },
    [9] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 9,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_For_O
    },
    [10] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 10,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_For_R
    }
};

const struct EndingImageOam sEndingImageOam_Collecting_English[17] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_C1
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 1,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_O
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 2,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_L1
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 3,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_L2
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 4,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_E
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 5,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_C2
    },
    [6] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 6,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_T
    },
    [7] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 7,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_I
    },
    [8] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 8,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_N
    },
    [9] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 9,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_G
    },
    [10] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 10,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Items_I
    },
    [11] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 11,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Items_T
    },
    [12] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 12,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Items_E
    },
    [13] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 13,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Items_M
    },
    [14] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 14,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Items_S
    },
    [15] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 15,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Is_I
    },
    [16] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 16,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Is_S
    },
};

#ifdef REGION_EU

const struct EndingImageOam sEndingImageOam_FullLines_German[ENDING_IMAGE_LINE_END] = {
    [0] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sFullLinesGermanOam_0
    },
    [1] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 60,
        .pFrame = sEndingImageOam_LineTimer_English
    },
    [2] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sFullLinesGermanOam_2
    },
    [3] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sFullLinesGermanOam_3
    },
    [4] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 124,
        .yPosition = 128,
        .pFrame = sEndingImageOam_LinePercentage_English
    },
    [5] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 158,
        .pFrame = sFullLinesGermanOam_2
    },
};

const struct EndingImageOam sEndingImageOam_ClearTime_German[13] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeGermanOam_0
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 5,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeGermanOam_1
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 9,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeGermanOam_2
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 13,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeGermanOam_3
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 17,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeGermanOam_4
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 21,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeGermanOam_5
    },
    [6] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 25,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeGermanOam_6
    },
    [7] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 29,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeGermanOam_7
    },
    [8] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 33,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeGermanOam_8
    },
    [9] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 37,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeGermanOam_9
    },
    [10] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 41,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeGermanOam_10
    },
    [11] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 45,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeGermanOam_11
    },
    [12] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 49,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeGermanOam_12
    },
};

const struct EndingImageOam sEndingImageOam_Collecting_German[14] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingGermanOam_0
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 5,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingGermanOam_1
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 9,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingGermanOam_2
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 13,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingGermanOam_3
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 17,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingGermanOam_4
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 21,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingGermanOam_5
    },
    [6] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 25,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingGermanOam_6
    },
    [7] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 29,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingGermanOam_7
    },
    [8] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 33,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingGermanOam_8
    },
    [9] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 37,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingGermanOam_9
    },
    [10] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 41,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingGermanOam_10
    },
    [11] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 45,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingGermanOam_11
    },
    [12] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 49,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingGermanOam_12
    },
    [13] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 53,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingGermanOam_13
    },
};

const struct EndingImageOam sEndingImageOam_FullLines_French[ENDING_IMAGE_LINE_END] = {
    [0] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sFullLinesFrenchOam_0
    },
    [1] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 60,
        .pFrame = sEndingImageOam_LineTimer_English
    },
    [2] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sFullLinesFrenchOam_2
    },
    [3] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sFullLinesFrenchOam_3
    },
    [4] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 124,
        .yPosition = 128,
        .pFrame = sEndingImageOam_LinePercentage_English
    },
    [5] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 155,
        .pFrame = sFullLinesFrenchOam_2
    },
};

const struct EndingImageOam sEndingImageOam_ClearTime_French[16] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeFrenchOam_0
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 5,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeFrenchOam_1
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 9,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeFrenchOam_2
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 13,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeFrenchOam_3
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 17,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeFrenchOam_4
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 21,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeFrenchOam_5
    },
    [6] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 25,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeFrenchOam_6
    },
    [7] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 29,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeFrenchOam_7
    },
    [8] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 33,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeFrenchOam_8
    },
    [9] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 37,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeFrenchOam_9
    },
    [10] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 41,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeFrenchOam_10
    },
    [11] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 45,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeFrenchOam_11
    },
    [12] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 49,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeFrenchOam_12
    },
    [13] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 53,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeFrenchOam_13
    },
    [14] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 57,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeFrenchOam_14
    },
    [15] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 61,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeFrenchOam_15
    },
};

const struct EndingImageOam sEndingImageOam_Collecting_French[20] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_0
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 5,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_1
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 9,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_2
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 13,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_3
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 17,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_4
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 21,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_5
    },
    [6] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 25,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_6
    },
    [7] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 29,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_7
    },
    [8] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 33,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_8
    },
    [9] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 37,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_9
    },
    [10] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 41,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_10
    },
    [11] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 45,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_11
    },
    [12] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 49,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_12
    },
    [13] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 53,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_13
    },
    [14] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 57,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_14
    },
    [15] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 61,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_15
    },
    [16] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 65,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_16
    },
    [17] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 69,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_17
    },
    [18] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 73,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_18
    },
    [19] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 77,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingFrenchOam_19
    },
};

const struct EndingImageOam sEndingImageOam_FullLines_Italian[ENDING_IMAGE_LINE_END] = {
    [0] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sFullLinesItalianOam_0
    },
    [1] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 60,
        .pFrame = sEndingImageOam_LineTimer_English
    },
    [2] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 92,
        .pFrame = sFullLinesItalianOam_2
    },
    [3] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sFullLinesItalianOam_3
    },
    [4] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 124,
        .yPosition = 128,
        .pFrame = sEndingImageOam_LinePercentage_English
    },
    [5] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 155,
        .pFrame = sFullLinesItalianOam_5
    },
};

const struct EndingImageOam sEndingImageOam_ClearTime_Italian[18] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_0
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 5,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_1
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 9,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_2
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 13,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_3
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 17,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_4
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 21,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_5
    },
    [6] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 25,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_6
    },
    [7] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 29,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_7
    },
    [8] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 33,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_8
    },
    [9] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 37,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_9
    },
    [10] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 41,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_10
    },
    [11] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 45,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_11
    },
    [12] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 49,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_12
    },
    [13] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 53,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_13
    },
    [14] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 57,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_14
    },
    [15] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 61,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_15
    },
    [16] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 65,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_16
    },
    [17] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 69,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeItalianOam_17
    },
};

const struct EndingImageOam sEndingImageOam_YourRate_Italian[11] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 92,
        .pFrame = sYourRateItalianOam_0
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 5,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 92,
        .pFrame = sYourRateItalianOam_1
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 9,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 92,
        .pFrame = sYourRateItalianOam_2
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 13,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 92,
        .pFrame = sYourRateItalianOam_3
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 17,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 92,
        .pFrame = sYourRateItalianOam_4
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 21,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 92,
        .pFrame = sYourRateItalianOam_5
    },
    [6] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 25,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 92,
        .pFrame = sYourRateItalianOam_6
    },
    [7] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 29,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 92,
        .pFrame = sYourRateItalianOam_7
    },
    [8] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 33,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 92,
        .pFrame = sYourRateItalianOam_8
    },
    [9] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 37,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 92,
        .pFrame = sYourRateItalianOam_9
    },
    [10] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 41,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 92,
        .pFrame = sYourRateItalianOam_10
    },
};

const struct EndingImageOam sEndingImageOam_Collecting_Italian[17] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingItalianOam_0
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 5,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingItalianOam_1
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 9,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingItalianOam_2
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 13,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingItalianOam_3
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 17,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingItalianOam_4
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 21,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingItalianOam_5
    },
    [6] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 25,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingItalianOam_6
    },
    [7] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 29,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingItalianOam_7
    },
    [8] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 33,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingItalianOam_8
    },
    [9] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 37,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingItalianOam_9
    },
    [10] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 41,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingItalianOam_10
    },
    [11] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 45,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingItalianOam_11
    },
    [12] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 49,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingItalianOam_12
    },
    [13] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 53,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingItalianOam_13
    },
    [14] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 57,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingItalianOam_14
    },
    [15] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 61,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingItalianOam_15
    },
    [16] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 65,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingItalianOam_16
    },
};

const struct EndingImageOam sEndingImageOam_FullLines_Spanish[ENDING_IMAGE_LINE_END] = {
    [0] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sFullLinesSpanishOam_0
    },
    [1] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 60,
        .pFrame = sEndingImageOam_LineTimer_English
    },
    [2] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sFullLinesSpanishOam_2
    },
    [3] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sFullLinesSpanishOam_3
    },
    [4] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 124,
        .yPosition = 128,
        .pFrame = sEndingImageOam_LinePercentage_English
    },
    [5] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 155,
        .pFrame = sFullLinesSpanishOam_2
    },
};

const struct EndingImageOam sEndingImageOam_ClearTime_Spanish[15] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeSpanishOam_0
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 5,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeSpanishOam_1
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 9,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeSpanishOam_2
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 13,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeSpanishOam_3
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 17,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeSpanishOam_4
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 21,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeSpanishOam_5
    },
    [6] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 25,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeSpanishOam_6
    },
    [7] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 29,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeSpanishOam_7
    },
    [8] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 33,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeSpanishOam_8
    },
    [9] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 37,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeSpanishOam_9
    },
    [10] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 41,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeSpanishOam_10
    },
    [11] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 45,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeSpanishOam_11
    },
    [12] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 49,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeSpanishOam_12
    },
    [13] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 53,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeSpanishOam_13
    },
    [14] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 57,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 40,
        .pFrame = sClearTimeSpanishOam_14
    },
};

const struct EndingImageOam sEndingImageOam_Collecting_Spanish[19] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_0
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 5,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_1
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 9,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_2
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 13,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_3
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 17,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_4
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 21,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_5
    },
    [6] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 25,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_6
    },
    [7] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 29,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_7
    },
    [8] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 33,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_8
    },
    [9] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 37,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_9
    },
    [10] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 41,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_10
    },
    [11] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 45,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_11
    },
    [12] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 49,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_12
    },
    [13] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 53,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_13
    },
    [14] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 57,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_14
    },
    [15] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 61,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_15
    },
    [16] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 65,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_16
    },
    [17] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 69,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_17
    },
    [18] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 73,
        .unk_2 = 0,
        .xPosition = 120,
        .yPosition = 108,
        .pFrame = sCollectingSpanishOam_18
    },
};

#endif // REGION_EU

const struct EndingImageOam sEndingImageOam_FullLines_Hiragana[ENDING_IMAGE_LINE_END] = {
    [ENDING_IMAGE_LINE_CLEAR_TIME] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sEndingImageOam_LineClearTime_Hiragana
    },
    [ENDING_IMAGE_LINE_TIMER] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE - 4,
        .pFrame = sEndingImageOam_LineTimer_English
    },
    [ENDING_IMAGE_LINE_YOUR_RATE] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sEndingImageOam_LineYourRate_English
    },
    [ENDING_IMAGE_LINE_COLLECTING] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sEndingImageOam_LineCollecting_Hiragana
    },
    [ENDING_IMAGE_LINE_PERCENTAGE] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 4,
        .yPosition = BLOCK_SIZE * 2,
        .pFrame = sEndingImageOam_LinePercentage_English
    },
    [ENDING_IMAGE_LINE_NEXT_MISSION] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE - 2,
        .pFrame = sEndingImageOam_LineNextMission_English
    },
};

const struct EndingImageOam sEndingImageOam_ClearTime_Hiragana[6] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeHiraganaOam_0
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 2,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeHiraganaOam_1
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 4,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeHiraganaOam_2
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 6,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeHiraganaOam_3
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 8,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeHiraganaOam_4
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 10,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeHiraganaOam_5
    }
};

const struct EndingImageOam sEndingImageOam_Collecting_Hiragana[11] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_0
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 1,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_1
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 2,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_2
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 3,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_3
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 4,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_4
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 5,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_5
    },
    [6] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 6,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_6
    },
    [7] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 7,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_7
    },
    [8] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 8,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_8
    },
    [9] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 9,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_9
    },
    [10] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 10,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_10
    }
};

extern const u32 sEndingImage_TopGfx_0[6186];
extern const u32 sEndingImage_TopTileTable_0[577];
extern const u32 sEndingImage_BottomGfx_0[3525];
extern const u32 sEndingImage_BottomTileTable_0[398];

extern const u32 sEndingImage_TopGfx_1[5578];
extern const u32 sEndingImage_TopTileTable_1[577];
extern const u32 sEndingImage_BottomGfx_1[3339];
extern const u32 sEndingImage_BottomTileTable_1[577];

extern const u32 sEndingImage_TopGfx_2[6259];
extern const u32 sEndingImage_TopTileTable_2[577];
extern const u32 sEndingImage_BottomGfx_2[3178];
extern const u32 sEndingImage_BottomTileTable_2[577];

extern const u32 sEndingImage_TopGfx_3[5289];
extern const u32 sEndingImage_TopTileTable_3[577];
extern const u32 sEndingImage_BottomGfx_3[2789];
extern const u32 sEndingImage_BottomTileTable_3[577];

extern const u32 sEndingImage_TopGfx_4[5900];
extern const u32 sEndingImage_TopTileTable_4[577];
extern const u32 sEndingImage_BottomGfx_4[3029];
extern const u32 sEndingImage_BottomTileTable_4[577];

extern const u32 sEndingImage_TopGfx_5[5080];
extern const u32 sEndingImage_TopTileTable_5[577];
extern const u32 sEndingImage_BottomGfx_5[3899];
extern const u32 sEndingImage_BottomTileTable_5[577];

extern const u32 sEndingImage_TopGfx_6[5748];
extern const u32 sEndingImage_TopTileTable_6[577];
extern const u32 sEndingImage_BottomGfx_6[2932];
extern const u32 sEndingImage_BottomTileTable_6[577];

extern const u32 sEndingImage_TopGfx_7[6818];
extern const u32 sEndingImage_TopTileTable_7[577];
extern const u32 sEndingImage_BottomGfx_7[3901];
extern const u32 sEndingImage_BottomTileTable_7[577];

const u32* const sEndingImagesTopGfxPointers[ENDING_IMAGE_COUNT] = {
    [ENDING_IMAGE_ZERO]  = sEndingImage_TopGfx_0,
    [ENDING_IMAGE_ONE]   = sEndingImage_TopGfx_1,
    [ENDING_IMAGE_TWO]   = sEndingImage_TopGfx_2,
    [ENDING_IMAGE_THREE] = sEndingImage_TopGfx_3,
    [ENDING_IMAGE_FOUR]  = sEndingImage_TopGfx_4,
    [ENDING_IMAGE_FIVE]  = sEndingImage_TopGfx_5,
    [ENDING_IMAGE_SIX]   = sEndingImage_TopGfx_6,
    [ENDING_IMAGE_SEVEN] = sEndingImage_TopGfx_7
};

const u32* const sEndingImagesBottomGfxPointers[ENDING_IMAGE_COUNT] = {
    [ENDING_IMAGE_ZERO]  = sEndingImage_BottomGfx_0,
    [ENDING_IMAGE_ONE]   = sEndingImage_BottomGfx_1,
    [ENDING_IMAGE_TWO]   = sEndingImage_BottomGfx_2,
    [ENDING_IMAGE_THREE] = sEndingImage_BottomGfx_3,
    [ENDING_IMAGE_FOUR]  = sEndingImage_BottomGfx_4,
    [ENDING_IMAGE_FIVE]  = sEndingImage_BottomGfx_5,
    [ENDING_IMAGE_SIX]   = sEndingImage_BottomGfx_6,
    [ENDING_IMAGE_SEVEN] = sEndingImage_BottomGfx_7
};

const u32* const sEndingImagesTopTileTablePointers[ENDING_IMAGE_COUNT] = {
    [ENDING_IMAGE_ZERO]  = sEndingImage_TopTileTable_0,
    [ENDING_IMAGE_ONE]   = sEndingImage_TopTileTable_1,
    [ENDING_IMAGE_TWO]   = sEndingImage_TopTileTable_2,
    [ENDING_IMAGE_THREE] = sEndingImage_TopTileTable_3,
    [ENDING_IMAGE_FOUR]  = sEndingImage_TopTileTable_4,
    [ENDING_IMAGE_FIVE]  = sEndingImage_TopTileTable_5,
    [ENDING_IMAGE_SIX]   = sEndingImage_TopTileTable_6,
    [ENDING_IMAGE_SEVEN] = sEndingImage_TopTileTable_7
};

const u32* const sEndingImagesHalfTileTablePointers[ENDING_IMAGE_COUNT] = {
    [ENDING_IMAGE_ZERO]  = sEndingImage_BottomTileTable_0,
    [ENDING_IMAGE_ONE]   = sEndingImage_BottomTileTable_1,
    [ENDING_IMAGE_TWO]   = sEndingImage_BottomTileTable_2,
    [ENDING_IMAGE_THREE] = sEndingImage_BottomTileTable_3,
    [ENDING_IMAGE_FOUR]  = sEndingImage_BottomTileTable_4,
    [ENDING_IMAGE_FIVE]  = sEndingImage_BottomTileTable_5,
    [ENDING_IMAGE_SIX]   = sEndingImage_BottomTileTable_6,
    [ENDING_IMAGE_SEVEN] = sEndingImage_BottomTileTable_7
};


const u16* const sEndingImagesPalPointers[ENDING_IMAGE_COUNT] = {
    [ENDING_IMAGE_ZERO]  = sEndingImage_Palette_0,
    [ENDING_IMAGE_ONE]   = sEndingImage_Palette_1,
    [ENDING_IMAGE_TWO]   = sEndingImage_Palette_2,
    [ENDING_IMAGE_THREE] = sEndingImage_Palette_3,
    [ENDING_IMAGE_FOUR]  = sEndingImage_Palette_4,
    [ENDING_IMAGE_FIVE]  = sEndingImage_Palette_5,
    [ENDING_IMAGE_SIX]   = sEndingImage_Palette_6,
    [ENDING_IMAGE_SEVEN] = sEndingImage_Palette_7
};

#if defined(REGION_EU)

const struct CreditsEntry sCredits[308] = {
    [0] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [1] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [2] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [3] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [4] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [5] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [6] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [7] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [8] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [9] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "STAFF CREDITS"
    },
    [10] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [11] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [12] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [13] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [14] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [15] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [16] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [17] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [18] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [19] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "PRODUCER"
    },
    [20] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [21] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [22] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Izushi Takehiro"
    },
    [23] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [24] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [25] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [26] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [27] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "DIRECTOR"
    },
    [28] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [29] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [30] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Sakamoto Yoshio"
    },
    [31] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [32] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [33] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [34] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [35] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "SAMUS DESIGN"
    },
    [36] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [37] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [38] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Kiyotake Hiroji"
    },
    [39] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [40] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [41] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [42] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [43] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "COURSE DESIGN"
    },
    [44] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [45] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [46] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Ueda Masani"
    },
    [47] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [48] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Hosokawa Takehiko"
    },
    [49] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [50] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nakada Ryuichi"
    },
    [51] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [52] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [53] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [54] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [55] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "GRAPHIC DESIGN"
    },
    [56] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [57] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [58] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Morisawa Takayasu"
    },
    [59] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [60] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Matsushita Tadashi"
    },
    [61] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [62] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Miyamoto Fumiko"
    },
    [63] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [64] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Sakiyama Chiharu"
    },
    [65] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [66] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Furuta Norikatsu"
    },
    [67] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [68] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Momose Hiroshi"
    },
    [69] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [70] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [71] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [72] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [73] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "PROGRAMMING"
    },
    [74] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [75] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [76] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Yamano Katsuya"
    },
    [77] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [78] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Katsuki Yoshinori"
    },
    [79] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [80] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Ozaki Nobuhiro"
    },
    [81] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [82] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Kawase Tomohiro"
    },
    [83] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [84] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Shimizu Hideaki"
    },
    [85] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [86] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [87] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [88] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [89] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "MUSIC COMPOSITION"
    },
    [90] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [91] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [92] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Yamamoto Kenji"
    },
    [93] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [94] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Hamano Minako"
    },
    [95] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [96] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [97] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [98] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [99] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "SOUND EFFECT & PROGRAMMING"
    },
    [100] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [101] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [102] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Fujii Takaya"
    },
    [103] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [104] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [105] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [106] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [107] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "PACKAGE & MANUAL DESIGN"
    },
    [108] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [109] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [110] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Inoue Yasuo"
    },
    [111] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [112] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nakamichi Sachiko"
    },
    [113] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [114] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Takahashi Yasuko"
    },
    [115] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [116] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [117] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [118] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [119] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "COORDINATION"
    },
    [120] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [121] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [122] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Harada Takahiro"
    },
    [123] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [124] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [125] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [126] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [127] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "DEBUG"
    },
    [128] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [129] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [130] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "SUPER MARIO CLUB"
    },
    [131] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [132] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [133] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [134] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [135] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [136] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "SPECIAL THANKS"
    },
    [137] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [138] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [139] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Fukui Kota"
    },
    [140] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [141] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nishimura Kentaro"
    },
    [142] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [143] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nakano Takao"
    },
    [144] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [145] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Osawa Kazuyoshi"
    },
    [146] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [147] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Furuta Takeshi"
    },
    [148] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [149] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Saeki Naoko"
    },
    [150] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [151] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Tanaka Hirokazu"
    },
    [152] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [153] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [154] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [155] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [156] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [157] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [158] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [159] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [160] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "NORTH AMERICAN LOCALIZATION"
    },
    [161] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [162] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [163] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nate Bihldorff"
    },
    [164] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [165] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Bill Trinen"
    },
    [166] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [167] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [168] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [169] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [170] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "LOCALIZATION MANAGEMENT"
    },
    [171] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [172] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [173] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Jeff Miller"
    },
    [174] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [175] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Leslie Swan"
    },
    [176] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [177] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [178] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [179] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [180] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [181] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [182] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [183] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [184] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "EUROPEAN LOCALIZATION"
    },
    [185] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [186] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [187] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "PRODUCT LOCALIZATION TEAM"
    },
    [188] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [189] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [190] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [191] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [192] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "COORDINATION"
    },
    [193] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [194] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [195] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Marcus Krause"
    },
    [196] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [197] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [198] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [199] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [200] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "TRANSLATION"
    },
    [201] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [202] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [203] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "GERMAN"
    },
    [204] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [205] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [206] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Jan Peitzmeier"
    },
    [207] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [208] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [209] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [210] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "FRENCH"
    },
    [211] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [212] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [213] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Thomas Miriel"
    },
    [214] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [215] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [216] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [217] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "SPANISH"
    },
    [218] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [219] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [220] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Miguel L#pez Genicio"
    },
    [221] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [222] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [223] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [224] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "ITALIAN"
    },
    [225] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [226] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [227] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Massimo Maietti"
    },
    [228] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [229] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [230] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [231] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [232] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "VALIDATION AND TESTING TEAM"
    },
    [233] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [234] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [235] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "SUPERVISOR"
    },
    [236] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [237] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [238] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Erkan Kasap"
    },
    [239] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [240] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Rudi Schnitzer"
    },
    [241] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [242] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [243] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Chris Strau$"
    },
    [244] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [245] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Blaz Majic"
    },
    [246] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [247] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Steffen Lotz"
    },
    [248] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [249] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Wolfgang Weber"
    },
    [250] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [251] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [252] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Daniel Barsan"
    },
    [253] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [254] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Raphael von Brasch"
    },
    [255] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [256] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Kamel Chelirem"
    },
    [257] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [258] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [259] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Santo Gennaro"
    },
    [260] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [261] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "%                   "
    },
    [262] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Angel Moreno Colmena"
    },
    [263] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [264] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Daniel Herron Museur"
    },
    [265] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [266] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Arrate Ugarte Sandon+s"
    },
    [267] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [268] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [269] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [270] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [271] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [272] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [273] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [274] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [275] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [276] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "EXECUTIVE PRODUCER"
    },
    [277] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [278] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [279] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Iwata Satoru"
    },
    [280] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "               "
    },
    [281] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = "               "
    },
    [282] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [283] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [284] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [285] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [286] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [287] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [288] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [289] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [290] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [291] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [292] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [293] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [294] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [295] = {
        .type = CREDIT_LINE_TYPE_ALL_RIGHTS,
        .text = ""
    },
    [296] = {
        .type = CREDIT_LINE_TYPE_THE_COPYRIGHT,
        .text = ""
    },
    [297] = {
        .type = CREDIT_LINE_TYPE_SCENARIO,
        .text = ""
    },
    [298] = {
        .type = CREDIT_LINE_TYPE_RESERVED,
        .text = ""
    },
    [299] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [300] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [301] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [302] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [303] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [304] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [305] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [306] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [307] = {
        .type = CREDIT_LINE_TYPE_END,
        .text = ""
    },
};

#elif defined(REGION_JP)

const struct CreditsEntry sCredits[245] = {
    [0] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [1] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [2] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [3] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [4] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [5] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [6] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [7] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "STAFF CREDITS"
    },
    [8] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [9] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [10] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [11] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [12] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [13] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [14] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [15] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [16] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [17] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "PRODUCER"
    },
    [18] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [19] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [20] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Izushi Takehiro"
    },
    [21] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [22] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [23] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [24] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [25] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [26] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [27] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [28] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "DIRECTOR"
    },
    [29] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [30] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [31] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Sakamoto Yoshio"
    },
    [32] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [33] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [34] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [35] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [36] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [37] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [38] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [39] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "SAMUS DESIGN"
    },
    [40] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [41] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [42] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Kiyotake Hiroji"
    },
    [43] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [44] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [45] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [46] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [47] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [48] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [49] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [50] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "COURSE DESIGN"
    },
    [51] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [52] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [53] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Ueda Masani"
    },
    [54] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [55] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Hosokawa Takehiko"
    },
    [56] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [57] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nakada Ryuichi"
    },
    [58] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [59] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [60] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [61] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [62] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [63] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [64] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [65] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "GRAPHIC DESIGN"
    },
    [66] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [67] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [68] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Morisawa Takayasu"
    },
    [69] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [70] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Matsushita Tadashi"
    },
    [71] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [72] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Miyamoto Fumiko"
    },
    [73] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [74] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Sakiyama Chiharu"
    },
    [75] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [76] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Furuta Norikatsu"
    },
    [77] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [78] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Momose Hiroshi"
    },
    [79] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [80] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [81] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [82] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [83] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [84] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [85] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [86] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "PROGRAMMING"
    },
    [87] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [88] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [89] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Yamano Katsuya"
    },
    [90] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [91] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Katsuki Yoshinori"
    },
    [92] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [93] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Ozaki Nobuhiro"
    },
    [94] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [95] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Kawase Tomohiro"
    },
    [96] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [97] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Shimizu Hideaki"
    },
    [98] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [99] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [100] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [101] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [102] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [103] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [104] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [105] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "MUSIC COMPOSITION"
    },
    [106] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [107] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [108] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Yamamoto Kenji"
    },
    [109] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [110] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Hamano Minako"
    },
    [111] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [112] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [113] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [114] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [115] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [116] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [117] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [118] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "SOUND EFFECT & PROGRAMMING"
    },
    [119] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [120] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [121] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Fujii Takaya"
    },
    [122] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [123] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [124] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [125] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [126] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [127] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [128] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [129] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "PACKAGE & MANUAL DESIGN"
    },
    [130] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [131] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [132] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Inoue Yasuo"
    },
    [133] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [134] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nakamichi Sachiko"
    },
    [135] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [136] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Takahashi Yasuko"
    },
    [137] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [138] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [139] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [140] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [141] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [142] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [143] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [144] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "COORDINATION"
    },
    [145] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [146] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [147] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Harada Takahiro"
    },
    [148] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [149] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [150] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [151] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [152] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [153] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [154] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [155] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "DEBUG"
    },
    [156] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [157] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [158] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "SUPER MARIO CLUB"
    },
    [159] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [160] = {
        .type = CREDIT_LINE_TYPE_WHITE_SMALL,
        .text = "M. Manabu"
    },
    [161] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [162] = {
        .type = CREDIT_LINE_TYPE_WHITE_SMALL,
        .text = "    Maeda N.  Fukushima H."
    },
    [163] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [164] = {
        .type = CREDIT_LINE_TYPE_WHITE_SMALL,
        .text = "   Miyake K.  Inaba H.    "
    },
    [165] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [166] = {
        .type = CREDIT_LINE_TYPE_WHITE_SMALL,
        .text = " Maruyama Y.  Ueno T.     "
    },
    [167] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [168] = {
        .type = CREDIT_LINE_TYPE_WHITE_SMALL,
        .text = "Matsumoto N.  Takami N.   "
    },
    [169] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [170] = {
        .type = CREDIT_LINE_TYPE_WHITE_SMALL,
        .text = "     S. Aiko  Homma Y.    "
    },
    [171] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [172] = {
        .type = CREDIT_LINE_TYPE_WHITE_SMALL,
        .text = "     Kato T.  Naitou K.   "
    },
    [173] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [174] = {
        .type = CREDIT_LINE_TYPE_WHITE_SMALL,
        .text = " Takeuchi A.  Fukakushi M."
    },
    [175] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [176] = {
        .type = CREDIT_LINE_TYPE_WHITE_SMALL,
        .text = "    Nakai J.  Maeda K.    "
    },
    [177] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [178] = {
        .type = CREDIT_LINE_TYPE_WHITE_SMALL,
        .text = "   Fujiki A.  Otani R.    "
    },
    [179] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [180] = {
        .type = CREDIT_LINE_TYPE_WHITE_SMALL,
        .text = "   Tanaka R.  Kuninobu M. "
    },
    [181] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [182] = {
        .type = CREDIT_LINE_TYPE_WHITE_SMALL,
        .text = "Higashino K.  S. Junya    "
    },
    [183] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [184] = {
        .type = CREDIT_LINE_TYPE_WHITE_SMALL,
        .text = "   Yamaji M.  Uchiyama Y. "
    },
    [185] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [186] = {
        .type = CREDIT_LINE_TYPE_WHITE_SMALL,
        .text = "Okazaki A."
    },
    [187] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [188] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [189] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [190] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [191] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [192] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [193] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [194] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "SPECIAL THANKS"
    },
    [195] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [196] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [197] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Fukui Kota"
    },
    [198] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [199] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nishimura Kentaro"
    },
    [200] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [201] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nakano Takao"
    },
    [202] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [203] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Osawa Kazuyoshi"
    },
    [204] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [205] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Furuta Takeshi"
    },
    [206] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [207] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Saeki Naoko"
    },
    [208] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [209] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Tanaka Hirokazu"
    },
    [210] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [211] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [212] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [213] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [214] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [215] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [216] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [217] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [218] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "EXECUTIVE PRODUCER"
    },
    [219] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [220] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [221] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Iwata Satoru"
    },
    [222] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "               "
    },
    [223] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [224] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [225] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [226] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [227] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [228] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [229] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [230] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [231] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [232] = {
        .type = CREDIT_LINE_TYPE_ALL_RIGHTS,
        .text = ""
    },
    [233] = {
        .type = CREDIT_LINE_TYPE_THE_COPYRIGHT,
        .text = ""
    },
    [234] = {
        .type = CREDIT_LINE_TYPE_SCENARIO,
        .text = ""
    },
    [235] = {
        .type = CREDIT_LINE_TYPE_RESERVED,
        .text = ""
    },
    [236] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [237] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [238] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [239] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [240] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [241] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [242] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [243] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [244] = {
        .type = CREDIT_LINE_TYPE_END,
        .text = ""
    },
};

#else // !(REGION_EU || REGION_JP)

const struct CreditsEntry sCredits[240] = {
    [0] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [1] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [2] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [3] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [4] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [5] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [6] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [7] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "STAFF CREDITS"
    },
    [8] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [9] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [10] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [11] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [12] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [13] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [14] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [15] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [16] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "PRODUCER"
    },
    [17] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [18] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [19] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Izushi Takehiro"
    },
    [20] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [21] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [22] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [23] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [24] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "DIRECTOR"
    },
    [25] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [26] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [27] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Sakamoto Yoshio"
    },
    [28] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [29] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [30] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [31] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [32] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "SAMUS DESIGN"
    },
    [33] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [34] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [35] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Kiyotake Hiroji"
    },
    [36] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [37] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [38] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [39] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [40] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "COURSE DESIGN"
    },
    [41] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [42] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [43] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Ueda Masani"
    },
    [44] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [45] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Hosokawa Takehiko"
    },
    [46] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [47] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nakada Ryuichi"
    },
    [48] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [49] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [50] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [51] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [52] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "GRAPHIC DESIGN"
    },
    [53] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [54] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [55] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Morisawa Takayasu"
    },
    [56] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [57] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Matsushita Tadashi"
    },
    [58] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [59] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Miyamoto Fumiko"
    },
    [60] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [61] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Sakiyama Chiharu"
    },
    [62] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [63] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Furuta Norikatsu"
    },
    [64] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [65] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Momose Hiroshi"
    },
    [66] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [67] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [68] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [69] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [70] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "PROGRAMMING"
    },
    [71] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [72] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [73] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Yamano Katsuya"
    },
    [74] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [75] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Katsuki Yoshinori"
    },
    [76] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [77] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Ozaki Nobuhiro"
    },
    [78] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [79] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Kawase Tomohiro"
    },
    [80] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [81] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Shimizu Hideaki"
    },
    [82] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [83] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [84] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [85] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [86] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "MUSIC COMPOSITION"
    },
    [87] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [88] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [89] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Yamamoto Kenji"
    },
    [90] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [91] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Hamano Minako"
    },
    [92] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [93] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [94] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [95] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [96] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "SOUND EFFECT & PROGRAMMING"
    },
    [97] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [98] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [99] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Fujii Takaya"
    },
    [100] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [101] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [102] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [103] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [104] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "PACKAGE & MANUAL DESIGN"
    },
    [105] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [106] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [107] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Inoue Yasuo"
    },
    [108] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [109] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nakamichi Sachiko"
    },
    [110] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [111] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Takahashi Yasuko"
    },
    [112] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [113] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [114] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [115] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [116] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "COORDINATION"
    },
    [117] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [118] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [119] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Harada Takahiro"
    },
    [120] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [121] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [122] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [123] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [124] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "DEBUG"
    },
    [125] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [126] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [127] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "SUPER MARIO CLUB"
    },
    [128] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [129] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [130] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [131] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [132] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [133] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "SPECIAL THANKS"
    },
    [134] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [135] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [136] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Fukui Kota"
    },
    [137] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [138] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nishimura Kentaro"
    },
    [139] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [140] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nakano Takao"
    },
    [141] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [142] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Osawa Kazuyoshi"
    },
    [143] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [144] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Furuta Takeshi"
    },
    [145] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [146] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Saeki Naoko"
    },
    [147] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [148] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Tanaka Hirokazu"
    },
    [149] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [150] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [151] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [152] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [153] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [154] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "NORTH AMERICAN LOCALIZATION"
    },
    [155] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [156] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [157] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nate Bihldorff"
    },
    [158] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [159] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Bill Trinen"
    },
    [160] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [161] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [162] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [163] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [164] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "LOCALIZATION MANAGEMENT"
    },
    [165] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [166] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [167] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Jeff Miller"
    },
    [168] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [169] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Leslie Swan"
    },
    [170] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [171] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [172] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [173] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [174] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "NOA PRODUCT TESTING DEPARTMENT"
    },
    [175] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [176] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [177] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Yoshinobu Mantani"
    },
    [178] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [179] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Kyle Hudson"
    },
    [180] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [181] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Eric Bush"
    },
    [182] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [183] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Randy Shoemake"
    },
    [184] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [185] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Rich Richardson"
    },
    [186] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [187] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Thomas Hertzog"
    },
    [188] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [189] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Michael Leslie"
    },
    [190] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [191] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Kathy Huguenard"
    },
    [192] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [193] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "David Hunziker"
    },
    [194] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [195] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Chris Needham"
    },
    [196] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [197] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Mika Kurosawa"
    },
    [198] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [199] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [200] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [201] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [202] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "SPECIAL THANKS"
    },
    [203] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [204] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Mike Fukuda"
    },
    [205] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [206] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Tatsumi Kimishima"
    },
    [207] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [208] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [209] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [210] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [211] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [212] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [213] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "EXECUTIVE PRODUCER"
    },
    [214] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [215] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [216] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Iwata Satoru"
    },
    [217] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "               "
    },
    [218] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = "               "
    },
    [219] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [220] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [221] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [222] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [223] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [224] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [225] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [226] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [227] = {
        .type = CREDIT_LINE_TYPE_ALL_RIGHTS,
        .text = ""
    },
    [228] = {
        .type = CREDIT_LINE_TYPE_THE_COPYRIGHT,
        .text = ""
    },
    [229] = {
        .type = CREDIT_LINE_TYPE_SCENARIO,
        .text = ""
    },
    [230] = {
        .type = CREDIT_LINE_TYPE_RESERVED,
        .text = ""
    },
    [231] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [232] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [233] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [234] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [235] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [236] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [237] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [238] = {
        .type = CREDIT_LINE_TYPE_BLANK,
        .text = ""
    },
    [239] = {
        .type = CREDIT_LINE_TYPE_END,
        .text = ""
    }
};

#endif

const u16* const sEndingWhitePalPointers[4] = {
    [0] = sEndingPosingPal_White1,
    [1] = sEndingPosingPal_White2,
    [2] = sEndingPosingPal_White3,
    [3] = sEndingPosingPal_White4
};

const u8 sEndingImage_54e2dc[8] = {
    4, 3, 2, 1, 1, 1, 2, 3
};

const u8 sEndingImageNewRecordPalettes[12] = {
    5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 5
};

#ifdef REGION_EU
const u16 * const sEndingImageOamPointers_NewRecord[LANGUAGE_END] = {
    [LANGUAGE_JAPANESE] = sEndingImageOam_NewRecordEnglish,
    [LANGUAGE_HIRAGANA] = sEndingImageOam_NewRecordEnglish,
    [LANGUAGE_ENGLISH] = sEndingImageOam_NewRecordEnglish,
    [LANGUAGE_GERMAN] = sEndingImageOam_NewRecordGerman,
    [LANGUAGE_FRENCH] = sEndingImageOam_NewRecordFrench,
    [LANGUAGE_ITALIAN] = sEndingImageOam_NewRecordItalian,
    [LANGUAGE_SPANISH] = sEndingImageOam_NewRecordSpanish
};
#endif // REGION_EU

const u32 sCreditsCharactersGfx[] = INCBIN_U32("data/ending/CreditsCharacters.gfx.lz");

static const u32 sEndingImage_TopGfx_0[6186] = INCBIN_U32("data/ending/Image_Top_0.gfx.lz");
static const u32 sEndingImage_TopTileTable_0[577] = INCBIN_U32("data/ending/Image_Top_0.tt");
static const u32 sEndingImage_BottomGfx_0[3525] = INCBIN_U32("data/ending/Image_Bottom_0.gfx.lz");
static const u32 sEndingImage_BottomTileTable_0[398] = INCBIN_U32("data/ending/Image_Bottom_0.tt");

static const u32 sEndingImage_TopGfx_1[5578] = INCBIN_U32("data/ending/Image_Top_1.gfx.lz");
static const u32 sEndingImage_TopTileTable_1[577] = INCBIN_U32("data/ending/Image_Top_1.tt");
static const u32 sEndingImage_BottomGfx_1[3339] = INCBIN_U32("data/ending/Image_Bottom_1.gfx.lz");
static const u32 sEndingImage_BottomTileTable_1[577] = INCBIN_U32("data/ending/Image_Bottom_1.tt");

static const u32 sEndingImage_TopGfx_2[6259] = INCBIN_U32("data/ending/Image_Top_2.gfx.lz");
static const u32 sEndingImage_TopTileTable_2[577] = INCBIN_U32("data/ending/Image_Top_2.tt");
static const u32 sEndingImage_BottomGfx_2[3178] = INCBIN_U32("data/ending/Image_Bottom_2.gfx.lz");
static const u32 sEndingImage_BottomTileTable_2[577] = INCBIN_U32("data/ending/Image_Bottom_2.tt");

static const u32 sEndingImage_TopGfx_3[5289] = INCBIN_U32("data/ending/Image_Top_3.gfx.lz");
static const u32 sEndingImage_TopTileTable_3[577] = INCBIN_U32("data/ending/Image_Top_3.tt");
static const u32 sEndingImage_BottomGfx_3[2789] = INCBIN_U32("data/ending/Image_Bottom_3.gfx.lz");
static const u32 sEndingImage_BottomTileTable_3[577] = INCBIN_U32("data/ending/Image_Bottom_3.tt");

static const u32 sEndingImage_TopGfx_4[5900] = INCBIN_U32("data/ending/Image_Top_4.gfx.lz");
static const u32 sEndingImage_TopTileTable_4[577] = INCBIN_U32("data/ending/Image_Top_4.tt");
static const u32 sEndingImage_BottomGfx_4[3029] = INCBIN_U32("data/ending/Image_Bottom_4.gfx.lz");
static const u32 sEndingImage_BottomTileTable_4[577] = INCBIN_U32("data/ending/Image_Bottom_4.tt");

static const u32 sEndingImage_TopGfx_5[5080] = INCBIN_U32("data/ending/Image_Top_5.gfx.lz");
static const u32 sEndingImage_TopTileTable_5[577] = INCBIN_U32("data/ending/Image_Top_5.tt");
static const u32 sEndingImage_BottomGfx_5[3899] = INCBIN_U32("data/ending/Image_Bottom_5.gfx.lz");
static const u32 sEndingImage_BottomTileTable_5[577] = INCBIN_U32("data/ending/Image_Bottom_5.tt");

static const u32 sEndingImage_TopGfx_6[5748] = INCBIN_U32("data/ending/Image_Top_6.gfx.lz");
static const u32 sEndingImage_TopTileTable_6[577] = INCBIN_U32("data/ending/Image_Top_6.tt");
static const u32 sEndingImage_BottomGfx_6[2932] = INCBIN_U32("data/ending/Image_Bottom_6.gfx.lz");
static const u32 sEndingImage_BottomTileTable_6[577] = INCBIN_U32("data/ending/Image_Bottom_6.tt");

static const u32 sEndingImage_TopGfx_7[6818] = INCBIN_U32("data/ending/Image_Top_7.gfx.lz");
static const u32 sEndingImage_TopTileTable_7[577] = INCBIN_U32("data/ending/Image_Top_7.tt");
static const u32 sEndingImage_BottomGfx_7[3901] = INCBIN_U32("data/ending/Image_Bottom_7.gfx.lz");
static const u32 sEndingImage_BottomTileTable_7[577] = INCBIN_U32("data/ending/Image_Bottom_7.tt");

const u32 sEndingImageTextEnglishGfx[803] = INCBIN_U32("data/ending/TextEnglish.gfx.lz");
const u32 sEndingImageTextHiraganaGfx[511] = INCBIN_U32("data/ending/TextHiragana.gfx.lz");
#ifdef REGION_EU
const u32 sEndingImageTextFrenchGfx[759] = INCBIN_U32("data/ending/TextFrench.gfx.lz");
const u32 sEndingImageTextGermanGfx[726] = INCBIN_U32("data/ending/TextGerman.gfx.lz");
const u32 sEndingImageTextItalianGfx[883] = INCBIN_U32("data/ending/TextItalian.gfx.lz");
const u32 sEndingImageTextSpanishGfx[773] = INCBIN_U32("data/ending/TextSpanish.gfx.lz");
#endif // REGION_EU

const u8 sEndingImageNumbersGfx_Upper[10 * 64] = INCBIN_U8("data/ending/Numbers_Upper.gfx");
const u8 sEndingImageNumbersGfx_Lower[10 * 64] = INCBIN_U8("data/ending/Numbers_Lower.gfx");

const u32 sEndingImageNumbersMiscEnglishGfx[218] = INCBIN_U32("data/ending/NumbersMiscEnglish.gfx.lz");
#ifdef REGION_EU
const u32 sEndingImageNumbersMiscGermanGfx[209] = INCBIN_U32("data/ending/NumbersMiscGerman.gfx.lz");
const u32 sEndingImageNumbersMiscFrenchGfx[217] = INCBIN_U32("data/ending/NumbersMiscFrench.gfx.lz");
const u32 sEndingImageNumbersMiscItalianGfx[208] = INCBIN_U32("data/ending/NumbersMiscItalian.gfx.lz");
const u32 sEndingImageNumbersMiscSpanishGfx[225] = INCBIN_U32("data/ending/NumbersMiscSpanish.gfx.lz");
#endif // REGION_EU

const u32 sEndingSamusPosingSpaceBackgroundGfx[2938] = INCBIN_U32("data/ending/SamusPosingSpaceBackground.gfx.lz");
const u32 sEndingSamusPosingSpaceBackgroundTileTable[412] = INCBIN_U32("data/ending/SamusPosingSpaceBackground.tt");
const u32 sEndingLightGfx[743] = INCBIN_U32("data/ending/EndingLight.gfx.lz");
const u32 sEndingLightTileTable[145] = INCBIN_U32("data/ending/EndingLight.tt");

const u32 sEndingSamusPosingGfx_1[1481] = INCBIN_U32("data/ending/SamusPosing_1.gfx.lz");
const u32 sEndingSamusPosingTileTable_1[209] = INCBIN_U32("data/ending/SamusPosing_1.tt");
const u32 sEndingSamusPosingGfx_2[1562] = INCBIN_U32("data/ending/SamusPosing_2.gfx.lz");
const u32 sEndingSamusPosingTileTable_2[230] = INCBIN_U32("data/ending/SamusPosing_2.tt");
const u32 sEndingSamusPosingGfx_3[1712] = INCBIN_U32("data/ending/SamusPosing_3.gfx.lz");
const u32 sEndingSamusPosingTileTable_3[238] = INCBIN_U32("data/ending/SamusPosing_3.tt");
const u32 sEndingSamusPosingGfx_4[1692] = INCBIN_U32("data/ending/SamusPosing_4.gfx.lz");
const u32 sEndingSamusPosingTileTable_4[221] = INCBIN_U32("data/ending/SamusPosing_4.tt");
const u32 sEndingSamusPosingGfx_5[1279] = INCBIN_U32("data/ending/SamusPosing_5.gfx.lz");
const u32 sEndingSamusPosingTileTable_5[181] = INCBIN_U32("data/ending/SamusPosing_5.tt");

const u32 sEndingSamusPosingSuitlessGfx[1167] = INCBIN_U32("data/ending/SamusPosingSuitless.gfx.lz");
const u32 sEndingSamusPosingSuitlessTileTable[135] = INCBIN_U32("data/ending/SamusPosingSuitless.tt");
const u32 sEndingSamusPosingFullSuitGfx[1557] = INCBIN_U32("data/ending/SamusPosingFullSuit.gfx.lz");
const u32 sEndingSamusPosingFullSuitTileTable[226] = INCBIN_U32("data/ending/SamusPosingFullSuit.tt");
const u32 sEndingSamusPosingHelmetOffGfx[1568] = INCBIN_U32("data/ending/SamusPosingHelmetOff.gfx.lz");
const u32 sEndingSamusPosingHelmetOffTileTable[226] = INCBIN_U32("data/ending/SamusPosingHelmetOff.tt");

const u32 sCreditsChozoWallBackgroundGfx[7710] = INCBIN_U32("data/ending/CreditsChozoWallBackground.gfx.lz");
const u32 sCreditsChozoWallBackgroundTileTable[551] = INCBIN_U32("data/ending/CreditsChozoWallBackground.tt");
const u32 sCreditsChozoWallBottomGfx[3909] = INCBIN_U32("data/ending/CreditsChozoWallBottom.gfx.lz");
const u32 sCreditsChozoWallBottomTileTable[307] = INCBIN_U32("data/ending/CreditsChozoWallBottom.tt");
const u32 sCreditsChozoWallBottomZoomedGfx[5160] = INCBIN_U32("data/ending/CreditsChozoWallBottomZoomed.gfx.lz");
const u32 sCreditsChozoWallBottomZoomedTileTable[368] = INCBIN_U32("data/ending/CreditsChozoWallBottomZoomed.tt");
const u32 sCreditsChozoDrawingGfx[4770] = INCBIN_U32("data/ending/CreditsChozoDrawing.gfx.lz");
const u32 sCreditsChozoDrawingTileTable[368] = INCBIN_U32("data/ending/CreditsChozoDrawing.tt");

const u32 sUnlockedOptionsTileTable[127] = INCBIN_U32("data/ending/UnlockedOptions.tt");
