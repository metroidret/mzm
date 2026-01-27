#include "data/sprites/zebetite_and_cannon.h"
#include "macros.h"

const u32 sRinkaZebetiteAndCannonGfx[476] = INCBIN_U32("data/sprites/zebetite_rinka_cannon.gfx.lz");
const u16 sRinkaZebetiteAndCannonPal[32] = INCBIN_U16("data/sprites/zebetite_rinka_cannon.pal");

static const u16 sRinkaMotherBrainOam_Moving_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x200, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x200, 9, 0)
};

static const u16 sRinkaMotherBrainOam_Moving_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x201, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x201, 9, 0)
};

static const u16 sRinkaMotherBrainOam_Moving_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x202, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x202, 9, 0)
};

static const u16 sRinkaMotherBrainOam_Spawning_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x203, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x203, 9, 0)
};

static const u16 sRinkaMotherBrainOam_Spawning_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x204, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x204, 9, 0)
};

static const u16 sRinkaMotherBrainOam_Spawning_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x205, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x205, 9, 0)
};

static const u16 sRinkaMotherBrainOam_Spawning_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x206, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x206, 9, 0)
};

static const u16 sRinkaMotherBrainOam_Spawning_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x240, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x240, 9, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x241, 9, 0),
    OAM_ENTRY(-4, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 0x241, 9, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x261, 9, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 0x261, 9, 0)
};

static const u16 sRinkaMotherBrainOam_Spawning_Frame5[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x242, 9, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0x242, 9, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x243, 9, 0),
    OAM_ENTRY(-4, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 0x243, 9, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x263, 9, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x263, 9, 0)
};

static const u16 sZebetiteOam_Phase1_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x209, 8, 0)
};

static const u16 sZebetiteOam_Phase1_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x232, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x20a, 8, 0)
};

static const u16 sZebetiteOam_Phase1_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x20b, 8, 0)
};

static const u16 sZebetiteOam_Phase1_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x215, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x209, 8, 0)
};

static const u16 sZebetiteOam_Phase1_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x20a, 8, 0)
};

static const u16 sZebetiteOam_Phase1_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x20b, 8, 0)
};

static const u16 sZebetiteOam_Phase2_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x209, 8, 0)
};

static const u16 sZebetiteOam_Phase2_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x232, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x20a, 8, 0)
};

static const u16 sZebetiteOam_Phase2_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x20b, 8, 0)
};

static const u16 sZebetiteOam_Phase2_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 0x272, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x209, 8, 0)
};

static const u16 sZebetiteOam_Phase2_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x217, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x20a, 8, 0)
};

static const u16 sZebetiteOam_Phase2_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-8, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x20e, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 0x233, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x213, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x20b, 8, 0)
};

static const u16 sZebetiteOam_Phase4_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x209, 8, 0)
};

static const u16 sZebetiteOam_Phase4_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x20a, 8, 0)
};

static const u16 sZebetiteOam_Phase4_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x20b, 8, 0)
};

static const u16 sZebetiteOam_Phase4_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x209, 8, 0)
};

static const u16 sZebetiteOam_Phase4_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x219, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x20a, 8, 0)
};

static const u16 sZebetiteOam_Phase4_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x210, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23b, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x20b, 8, 0)
};

static const u16 sZebetiteOam_Phase6_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x209, 8, 0)
};

static const u16 sZebetiteOam_Phase6_Frame1[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x234, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x20a, 8, 0)
};

static const u16 sZebetiteOam_Phase6_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x20b, 8, 0)
};

static const u16 sZebetiteOam_Phase6_Frame3[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 0x274, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x254, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x209, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x209, 8, 0)
};

static const u16 sZebetiteOam_Phase6_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x32, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x20a, 8, 0)
};

static const u16 sZebetiteOam_Phase6_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x211, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x8, OAM_NO_FLIP, 0x23b, 8, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 0x214, 8, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x21b, 8, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x32, OAM_NO_FLIP, 0x20b, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x16, OAM_Y_FLIP, 0x20b, 8, 0)
};

static const u16 sCannonOam_AimingLeft_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-16, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x207, 8, 0)
};

static const u16 sCannonOam_ShootingLeft_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-15, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25b, 8, 0)
};

static const u16 sCannonOam_ShootingLeft_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-14, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25b, 8, 0)
};

static const u16 sCannonOam_LeftToDownLeftTransition_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-16, 1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x267, 8, 0)
};

static const u16 sCannonOam_AimingDownLeft_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-13, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x228, 8, 0)
};

static const u16 sCannonOam_ShootingDownLeft_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-12, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x248, 8, 0)
};

static const u16 sCannonOam_ShootingDownLeft_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-11, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x248, 8, 0)
};

static const u16 sCannonOam_DownLeftToDownTransition_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-7, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0x227, 8, 0)
};

static const u16 sCannonOam_AimingDown_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-4, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x208, 8, 0)
};

static const u16 sCannonOam_ShootingDown_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-4, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27b, 8, 0)
};

static const u16 sCannonOam_ShootingDown_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-4, 6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x27b, 8, 0)
};

static const u16 sCannonOam_DownToDownRightTransition_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-1, 0, OAM_DIMS_8x16, OAM_X_FLIP, 0x227, 8, 0)
};

static const u16 sCannonOam_AimingDownRight_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(5, 5, OAM_DIMS_8x8, OAM_X_FLIP, 0x228, 8, 0)
};

static const u16 sCannonOam_ShootingDownRight_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(4, 4, OAM_DIMS_8x8, OAM_X_FLIP, 0x248, 8, 0)
};

static const u16 sCannonOam_ShootingDownRight_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(3, 3, OAM_DIMS_8x8, OAM_X_FLIP, 0x248, 8, 0)
};

static const u16 sCannonOam_DownRightToRightTransition_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(0, 1, OAM_DIMS_16x8, OAM_X_FLIP, 0x267, 8, 0)
};

static const u16 sCannonOam_AimingRight_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(8, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x207, 8, 0)
};

static const u16 sCannonOam_ShootingRight_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(7, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x25b, 8, 0)
};

static const u16 sCannonOam_ShootingRight_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(6, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x25b, 8, 0)
};

static const u16 sCannonBulletOam_Left_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x244, 9, 0)
};

static const u16 sCannonBulletOam_Left_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x264, 9, 0)
};

static const u16 sCannonBulletOam_DownLeft_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x245, 9, 0)
};

static const u16 sCannonBulletOam_DownLeft_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x265, 9, 0)
};

static const u16 sCannonBulletOam_Down_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x246, 9, 0)
};

static const u16 sCannonBulletOam_Down_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x266, 9, 0)
};

static const u16 sCannonBulletOam_DownRight_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x245, 9, 0)
};

static const u16 sCannonBulletOam_DownRight_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x265, 9, 0)
};

static const u16 sCannonBulletOam_Right_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x244, 9, 0)
};

static const u16 sCannonBulletOam_Right_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x264, 9, 0)
};

static const u16 sMotherBrainBlockOam_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -14, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, 6, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23e, 8, 0)
};

static const u16 sMotherBrainBlockOam_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -11, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, 3, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23e, 8, 0)
};

static const u16 sMotherBrainBlockOam_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -7, OAM_DIMS_16x8, OAM_NO_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-8, -1, OAM_DIMS_16x8, OAM_NO_FLIP, 0x23e, 8, 0)
};

static const u16 sMotherBrainBlockOam_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0)
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

