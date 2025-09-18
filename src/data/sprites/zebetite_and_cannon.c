#include "data/sprites/zebetite_and_cannon.h"
#include "macros.h"

const u32 sRinkaZebetiteAndCannonGfx[476] = INCBIN_U32("data/sprites/ZebetiteRinkaCannon.gfx.lz");
const u16 sRinkaZebetiteAndCannonPal[32] = INCBIN_U16("data/sprites/ZebetiteRinkaCannon.pal");

static const u16 sRinkaMotherBrainOam_Moving_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 512, 9, 0),
};

static const u16 sRinkaMotherBrainOam_Moving_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 513, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 513, 9, 0),
};

static const u16 sRinkaMotherBrainOam_Moving_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 514, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 514, 9, 0),
};

static const u16 sRinkaMotherBrainOam_Spawning_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 515, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 515, 9, 0),
};

static const u16 sRinkaMotherBrainOam_Spawning_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 516, 9, 0),
};

static const u16 sRinkaMotherBrainOam_Spawning_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 517, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 517, 9, 0),
};

static const u16 sRinkaMotherBrainOam_Spawning_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 518, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 518, 9, 0),
};

static const u16 sRinkaMotherBrainOam_Spawning_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 576, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 576, 9, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 577, 9, 0),
    OAM_ENTRY(-4, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 577, 9, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 609, 9, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 609, 9, 0),
};

static const u16 sRinkaMotherBrainOam_Spawning_Frame5[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 578, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 578, 9, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 579, 9, 0),
    OAM_ENTRY(-4, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 579, 9, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 611, 9, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_8x8, OAM_X_FLIP, 611, 9, 0),
};

static const u16 sZebetiteOam_Phase1_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 524, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 521, 8, 0),
};

static const u16 sZebetiteOam_Phase1_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 533, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 533, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 562, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 626, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 522, 8, 0),
};

static const u16 sZebetiteOam_Phase1_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 524, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 594, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 523, 8, 0),
};

static const u16 sZebetiteOam_Phase1_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 533, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 533, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 626, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 594, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 521, 8, 0),
};

static const u16 sZebetiteOam_Phase1_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 524, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 522, 8, 0),
};

static const u16 sZebetiteOam_Phase1_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 524, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 524, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 563, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 523, 8, 0),
};

static const u16 sZebetiteOam_Phase2_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 526, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 526, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 521, 8, 0),
};

static const u16 sZebetiteOam_Phase2_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 535, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 535, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 562, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 626, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 522, 8, 0),
};

static const u16 sZebetiteOam_Phase2_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 526, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 526, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 594, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 523, 8, 0),
};

static const u16 sZebetiteOam_Phase2_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 526, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 526, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 626, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 594, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 521, 8, 0),
};

static const u16 sZebetiteOam_Phase2_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 535, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 535, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 522, 8, 0),
};

static const u16 sZebetiteOam_Phase2_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 526, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 526, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 563, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 530, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 531, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 523, 8, 0),
};

static const u16 sZebetiteOam_Phase4_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 528, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 521, 8, 0),
};

static const u16 sZebetiteOam_Phase4_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 537, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 564, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 522, 8, 0),
};

static const u16 sZebetiteOam_Phase4_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 528, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 596, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 523, 8, 0),
};

static const u16 sZebetiteOam_Phase4_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 528, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 596, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 521, 8, 0),
};

static const u16 sZebetiteOam_Phase4_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 537, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 537, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 522, 8, 0),
};

static const u16 sZebetiteOam_Phase4_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 528, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 528, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 571, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 523, 8, 0),
};

static const u16 sZebetiteOam_Phase6_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 529, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 529, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 521, 8, 0),
};

static const u16 sZebetiteOam_Phase6_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 538, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 564, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 522, 8, 0),
};

static const u16 sZebetiteOam_Phase6_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 529, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 529, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 596, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 523, 8, 0),
};

static const u16 sZebetiteOam_Phase6_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 529, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 529, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 628, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 596, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 521, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 521, 8, 0),
};

static const u16 sZebetiteOam_Phase6_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 538, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 522, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 522, 8, 0),
};

static const u16 sZebetiteOam_Phase6_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 529, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 529, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 571, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 532, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 539, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 523, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 523, 8, 0),
};

static const u16 sCannonOam_AimingLeft_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 519, 8, 0),
};

static const u16 sCannonOam_ShootingLeft_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 606, 8, 0),
    OAM_ENTRY(-15, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 603, 8, 0),
};

static const u16 sCannonOam_ShootingLeft_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-14, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 603, 8, 0),
};

static const u16 sCannonOam_LeftToDownLeftTransition_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 615, 8, 0),
};

static const u16 sCannonOam_AimingDownLeft_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-13, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 552, 8, 0),
};

static const u16 sCannonOam_ShootingDownLeft_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 606, 8, 0),
    OAM_ENTRY(-12, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 584, 8, 0),
};

static const u16 sCannonOam_ShootingDownLeft_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-11, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 584, 8, 0),
};

static const u16 sCannonOam_DownLeftToDownTransition_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-7, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 551, 8, 0),
};

static const u16 sCannonOam_AimingDown_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-4, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 520, 8, 0),
};

static const u16 sCannonOam_ShootingDown_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 606, 8, 0),
    OAM_ENTRY(-4, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 635, 8, 0),
};

static const u16 sCannonOam_ShootingDown_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(-4, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 635, 8, 0),
};

static const u16 sCannonOam_DownToDownRightTransition_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x16, OAM_X_FLIP, 551, 8, 0),
};

static const u16 sCannonOam_AimingDownRight_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(5, 5, OAM_DIMS_8x8, OAM_X_FLIP, 552, 8, 0),
};

static const u16 sCannonOam_ShootingDownRight_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 606, 8, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_8x8, OAM_X_FLIP, 584, 8, 0),
};

static const u16 sCannonOam_ShootingDownRight_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(3, 3, OAM_DIMS_8x8, OAM_X_FLIP, 584, 8, 0),
};

static const u16 sCannonOam_DownRightToRightTransition_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(0, 1, OAM_DIMS_16x8, OAM_X_FLIP, 615, 8, 0),
};

static const u16 sCannonOam_AimingRight_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_8x8, OAM_X_FLIP, 519, 8, 0),
};

static const u16 sCannonOam_ShootingRight_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 606, 8, 0),
    OAM_ENTRY(7, -4, OAM_DIMS_8x8, OAM_X_FLIP, 603, 8, 0),
};

static const u16 sCannonOam_ShootingRight_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 604, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_8x8, OAM_X_FLIP, 603, 8, 0),
};

static const u16 sCannonBulletOam_Left_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 580, 9, 0),
};

static const u16 sCannonBulletOam_Left_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 612, 9, 0),
};

static const u16 sCannonBulletOam_DownLeft_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 581, 9, 0),
};

static const u16 sCannonBulletOam_DownLeft_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 613, 9, 0),
};

static const u16 sCannonBulletOam_Down_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 582, 9, 0),
};

static const u16 sCannonBulletOam_Down_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 614, 9, 0),
};

static const u16 sCannonBulletOam_DownRight_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_X_FLIP, 581, 9, 0),
};

static const u16 sCannonBulletOam_DownRight_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_X_FLIP, 613, 9, 0),
};

static const u16 sCannonBulletOam_Right_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_X_FLIP, 580, 9, 0),
};

static const u16 sCannonBulletOam_Right_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_X_FLIP, 612, 9, 0),
};

static const u16 sMotherBrainBlockOam_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(-8, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 574, 8, 0),
};

static const u16 sMotherBrainBlockOam_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(-8, 3, OAM_DIMS_16x8, OAM_NO_FLIP, 574, 8, 0),
};

static const u16 sMotherBrainBlockOam_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(-8, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 574, 8, 0),
};

static const u16 sMotherBrainBlockOam_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 542, 8, 0),
};



const struct FrameData sRinkaMotherBrainOam_Spawning[16] = {
    [0] = {
        .pFrame = sRinkaMotherBrainOam_Spawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sRinkaMotherBrainOam_Spawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sRinkaMotherBrainOam_Spawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sRinkaMotherBrainOam_Spawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sRinkaMotherBrainOam_Spawning_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sRinkaMotherBrainOam_Spawning_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sRinkaMotherBrainOam_Spawning_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = {
        .pFrame = sRinkaMotherBrainOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [8] = {
        .pFrame = sRinkaMotherBrainOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [9] = {
        .pFrame = sRinkaMotherBrainOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [10] = {
        .pFrame = sRinkaMotherBrainOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [11] = {
        .pFrame = sRinkaMotherBrainOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [12] = {
        .pFrame = sRinkaMotherBrainOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [13] = {
        .pFrame = sRinkaMotherBrainOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [14] = {
        .pFrame = sRinkaMotherBrainOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(7.f / 60)
    },
    [15] = FRAME_DATA_TERMINATOR
};

const struct FrameData sRinkaMotherBrainOam_Moving[5] = {
    [0] = {
        .pFrame = sRinkaMotherBrainOam_Moving_Frame0,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [1] = {
        .pFrame = sRinkaMotherBrainOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [2] = {
        .pFrame = sRinkaMotherBrainOam_Moving_Frame2,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [3] = {
        .pFrame = sRinkaMotherBrainOam_Moving_Frame1,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZebetiteOam_Phase1[7] = {
    [0] = {
        .pFrame = sZebetiteOam_Phase1_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZebetiteOam_Phase1_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZebetiteOam_Phase1_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sZebetiteOam_Phase1_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sZebetiteOam_Phase1_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sZebetiteOam_Phase1_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZebetiteOam_Phase2[7] = {
    [0] = {
        .pFrame = sZebetiteOam_Phase2_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZebetiteOam_Phase2_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZebetiteOam_Phase2_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sZebetiteOam_Phase2_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sZebetiteOam_Phase2_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sZebetiteOam_Phase2_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZebetiteOam_Phase4[7] = {
    [0] = {
        .pFrame = sZebetiteOam_Phase4_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZebetiteOam_Phase4_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZebetiteOam_Phase4_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sZebetiteOam_Phase4_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sZebetiteOam_Phase4_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sZebetiteOam_Phase4_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sZebetiteOam_Phase6[7] = {
    [0] = {
        .pFrame = sZebetiteOam_Phase6_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sZebetiteOam_Phase6_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sZebetiteOam_Phase6_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sZebetiteOam_Phase6_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sZebetiteOam_Phase6_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sZebetiteOam_Phase6_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonOam_AimingLeft[2] = {
    [0] = {
        .pFrame = sCannonOam_AimingLeft_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonOam_ShootingLeft[4] = {
    [0] = {
        .pFrame = sCannonOam_AimingLeft_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sCannonOam_ShootingLeft_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sCannonOam_ShootingLeft_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonOam_LeftToDownLeftTransition[2] = {
    [0] = {
        .pFrame = sCannonOam_LeftToDownLeftTransition_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonOam_AimingDownLeft[2] = {
    [0] = {
        .pFrame = sCannonOam_AimingDownLeft_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonOam_ShootingDownLeft[4] = {
    [0] = {
        .pFrame = sCannonOam_AimingDownLeft_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sCannonOam_ShootingDownLeft_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sCannonOam_ShootingDownLeft_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonOam_DownLeftToDownTransition[2] = {
    [0] = {
        .pFrame = sCannonOam_DownLeftToDownTransition_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonOam_AimingDown[2] = {
    [0] = {
        .pFrame = sCannonOam_AimingDown_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonOam_ShootingDown[4] = {
    [0] = {
        .pFrame = sCannonOam_AimingDown_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sCannonOam_ShootingDown_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sCannonOam_ShootingDown_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonOam_DownToDownRightTransition[2] = {
    [0] = {
        .pFrame = sCannonOam_DownToDownRightTransition_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonOam_AimingDownRight[2] = {
    [0] = {
        .pFrame = sCannonOam_AimingDownRight_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonOam_ShootingDownRight[4] = {
    [0] = {
        .pFrame = sCannonOam_AimingDownRight_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sCannonOam_ShootingDownRight_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sCannonOam_ShootingDownRight_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonOam_DownRightToRightTransition[2] = {
    [0] = {
        .pFrame = sCannonOam_DownRightToRightTransition_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonOam_AimingRight[2] = {
    [0] = {
        .pFrame = sCannonOam_AimingRight_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonOam_ShootingRight[4] = {
    [0] = {
        .pFrame = sCannonOam_AimingRight_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = {
        .pFrame = sCannonOam_ShootingRight_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sCannonOam_ShootingRight_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonBulletOam_Left[3] = {
    [0] = {
        .pFrame = sCannonBulletOam_Left_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sCannonBulletOam_Left_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonBulletOam_DownLeft[3] = {
    [0] = {
        .pFrame = sCannonBulletOam_DownLeft_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sCannonBulletOam_DownLeft_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonBulletOam_Down[3] = {
    [0] = {
        .pFrame = sCannonBulletOam_Down_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sCannonBulletOam_Down_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonBulletOam_DownRight[3] = {
    [0] = {
        .pFrame = sCannonBulletOam_DownRight_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sCannonBulletOam_DownRight_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sCannonBulletOam_Right[3] = {
    [0] = {
        .pFrame = sCannonBulletOam_Right_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sCannonBulletOam_Right_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sMotherBrainBlockOam[5] = {
    [0] = {
        .pFrame = sMotherBrainBlockOam_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sMotherBrainBlockOam_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sMotherBrainBlockOam_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sMotherBrainBlockOam_Frame3,
        .timer = UCHAR_MAX
    },
    [4] = FRAME_DATA_TERMINATOR
};

