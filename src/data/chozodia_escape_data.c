#include "data/chozodia_escape_data.h"
#include "data/tourian_escape_data.h"
#include "constants/game_state.h"

const u16 sChozodiaEscapeShipHeatingUpPal[8 * 16] = INCBIN_U16("data/chozodia_escape/ship_heating_up.pal");
const u16 sChozodiaEscapeGroundHeatingUpPal[8 * 16] = INCBIN_U16("data/chozodia_escape/ground_heating_up.pal");

const u16 sChozodiaEscapeShipExplodingPal[9 * 16] = INCBIN_U16("data/chozodia_escape/ship_exploding.pal");
const u16 sChozodiaEscapeMissionAccomplishedPal[16 * 16] = INCBIN_U16("data/chozodia_escape/mission_accomplished.pal");
const u16 sChozodiaEscapeSamusInBlueShipPal[1 * 16] = INCBIN_U16("data/chozodia_escape/samus_in_blue_ship.pal");

const u16 sChozodiaEscapeOam_ShipExterior_Frame0[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-128, -80, OAM_DIMS_64x64, OAM_NO_FLIP, 0x100, 0, 1),
    OAM_ENTRY(-128, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x200, 0, 1),
    OAM_ENTRY(-64, -80, OAM_DIMS_64x64, OAM_NO_FLIP, 0x108, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(0, -80, OAM_DIMS_64x64, OAM_NO_FLIP, 0x110, 0, 1),
    OAM_ENTRY(0, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x210, 0, 1),
    OAM_ENTRY(64, -80, OAM_DIMS_64x64, OAM_NO_FLIP, 0x118, 0, 1),
    OAM_ENTRY(64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x218, 0, 1),
    OAM_ENTRY(-64, -112, OAM_DIMS_64x32, OAM_NO_FLIP, 0x88, 0, 1),
    OAM_ENTRY(0, -112, OAM_DIMS_64x32, OAM_NO_FLIP, 0x90, 0, 1)
};

const u16 sChozodiaEscapeOam_BlueShipAngledDown_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x30c, 3, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x38c, 3, 0)
};

const u16 sChozodiaEscapeOam_BlueShipAngledUp_Frame0[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-32, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 0x318, 2, 0),
    OAM_ENTRY(-32, 32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x310, 2, 0),
    OAM_ENTRY(0, 32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x314, 2, 0)
};

const u16 sChozodiaEscapeOam_MotherShipDoorClosed_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(8, 16, OAM_DIMS_16x16, OAM_X_FLIP, 0x3cc, 0, 1),
    OAM_ENTRY(-24, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3cc, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(0, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x210, 0, 1)
};

static const u16 sChozodiaEscapeOam_MotherShipDoorOpening_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(8, 16, OAM_DIMS_16x16, OAM_X_FLIP, 0x3ce, 0, 1),
    OAM_ENTRY(-24, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3ce, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(0, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x210, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1)
};

static const u16 sChozodiaEscapeOam_MotherShipDoorOpening_Frame2[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-24, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x395, 0, 1),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x397, 0, 1),
    OAM_ENTRY(8, 0, OAM_DIMS_16x32, OAM_X_FLIP, 0x395, 0, 1),
    OAM_ENTRY(0, 0, OAM_DIMS_8x32, OAM_X_FLIP, 0x397, 0, 1),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x395, 0, 1),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x397, 0, 1),
    OAM_ENTRY(8, 0, OAM_DIMS_16x32, OAM_X_FLIP, 0x395, 0, 1),
    OAM_ENTRY(0, 0, OAM_DIMS_8x32, OAM_X_FLIP, 0x397, 0, 1),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x395, 0, 1),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x397, 0, 1),
    OAM_ENTRY(8, 0, OAM_DIMS_16x32, OAM_X_FLIP, 0x395, 0, 1),
    OAM_ENTRY(0, 0, OAM_DIMS_8x32, OAM_X_FLIP, 0x397, 0, 1),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x392, 4, 1),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x394, 4, 1),
    OAM_ENTRY(8, 0, OAM_DIMS_16x32, OAM_X_FLIP, 0x392, 4, 1),
    OAM_ENTRY(0, 0, OAM_DIMS_8x32, OAM_X_FLIP, 0x394, 4, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(0, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x210, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1)
};

static const u16 sChozodiaEscapeOam_MotherShipDoorOpening_Frame3[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-24, 2, OAM_DIMS_16x32, OAM_NO_FLIP, 0x395, 0, 1),
    OAM_ENTRY(-8, 2, OAM_DIMS_8x32, OAM_NO_FLIP, 0x397, 0, 1),
    OAM_ENTRY(8, 2, OAM_DIMS_16x32, OAM_X_FLIP, 0x395, 0, 1),
    OAM_ENTRY(0, 2, OAM_DIMS_8x32, OAM_X_FLIP, 0x397, 0, 1),
    OAM_ENTRY(-24, 2, OAM_DIMS_16x32, OAM_NO_FLIP, 0x395, 0, 1),
    OAM_ENTRY(-8, 2, OAM_DIMS_8x32, OAM_NO_FLIP, 0x397, 0, 1),
    OAM_ENTRY(8, 2, OAM_DIMS_16x32, OAM_X_FLIP, 0x395, 0, 1),
    OAM_ENTRY(0, 2, OAM_DIMS_8x32, OAM_X_FLIP, 0x397, 0, 1),
    OAM_ENTRY(-24, 2, OAM_DIMS_16x32, OAM_NO_FLIP, 0x395, 0, 1),
    OAM_ENTRY(-8, 2, OAM_DIMS_8x32, OAM_NO_FLIP, 0x397, 0, 1),
    OAM_ENTRY(8, 2, OAM_DIMS_16x32, OAM_X_FLIP, 0x395, 0, 1),
    OAM_ENTRY(0, 2, OAM_DIMS_8x32, OAM_X_FLIP, 0x397, 0, 1),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x392, 4, 1),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x394, 4, 1),
    OAM_ENTRY(8, 0, OAM_DIMS_16x32, OAM_X_FLIP, 0x392, 4, 1),
    OAM_ENTRY(0, 0, OAM_DIMS_8x32, OAM_X_FLIP, 0x394, 4, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(0, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x210, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1)
};

static const u16 sChozodiaEscapeOam_MotherShipDoorOpening_Frame4[OAM_DATA_SIZE(22)] = {
    22,
    OAM_ENTRY(8, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x395, 0, 1),
    OAM_ENTRY(8, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x395, 0, 1),
    OAM_ENTRY(8, 5, OAM_DIMS_16x32, OAM_X_FLIP, 0x395, 0, 1),
    OAM_ENTRY(13, 11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3b1, 4, 1),
    OAM_ENTRY(-24, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x395, 0, 1),
    OAM_ENTRY(-8, 5, OAM_DIMS_8x32, OAM_NO_FLIP, 0x397, 0, 1),
    OAM_ENTRY(-24, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x395, 0, 1),
    OAM_ENTRY(-8, 5, OAM_DIMS_8x32, OAM_NO_FLIP, 0x397, 0, 1),
    OAM_ENTRY(-24, 5, OAM_DIMS_16x32, OAM_NO_FLIP, 0x395, 0, 1),
    OAM_ENTRY(-8, 5, OAM_DIMS_8x32, OAM_NO_FLIP, 0x397, 0, 1),
    OAM_ENTRY(0, 5, OAM_DIMS_8x32, OAM_X_FLIP, 0x397, 0, 1),
    OAM_ENTRY(0, 5, OAM_DIMS_8x32, OAM_X_FLIP, 0x397, 0, 1),
    OAM_ENTRY(0, 5, OAM_DIMS_8x32, OAM_X_FLIP, 0x397, 0, 1),
    OAM_ENTRY(-21, 11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3b0, 4, 1),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x392, 4, 1),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x394, 4, 1),
    OAM_ENTRY(8, 0, OAM_DIMS_16x32, OAM_X_FLIP, 0x392, 4, 1),
    OAM_ENTRY(0, 0, OAM_DIMS_8x32, OAM_X_FLIP, 0x394, 4, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(0, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x210, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1)
};

static const u16 sChozodiaEscapeOam_MotherShipDoorOpening_Frame5[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-24, 14, OAM_DIMS_16x32, OAM_NO_FLIP, 0x395, 0, 1),
    OAM_ENTRY(-8, 14, OAM_DIMS_8x32, OAM_NO_FLIP, 0x397, 0, 1),
    OAM_ENTRY(8, 14, OAM_DIMS_16x32, OAM_X_FLIP, 0x395, 0, 1),
    OAM_ENTRY(0, 14, OAM_DIMS_8x32, OAM_X_FLIP, 0x397, 0, 1),
    OAM_ENTRY(-21, 28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3f0, 2, 1),
    OAM_ENTRY(13, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3f1, 2, 1),
    OAM_ENTRY(13, 12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3b1, 4, 1),
    OAM_ENTRY(-21, 12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3b0, 4, 1),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x392, 4, 1),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x394, 4, 1),
    OAM_ENTRY(8, 0, OAM_DIMS_16x32, OAM_X_FLIP, 0x392, 4, 1),
    OAM_ENTRY(0, 0, OAM_DIMS_8x32, OAM_X_FLIP, 0x394, 4, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(0, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x210, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1)
};

static const u16 sChozodiaEscapeOam_MotherShipDoorOpening_Frame6[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-24, 12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x395, 0, 1),
    OAM_ENTRY(-8, 12, OAM_DIMS_8x32, OAM_NO_FLIP, 0x397, 0, 1),
    OAM_ENTRY(8, 12, OAM_DIMS_16x32, OAM_X_FLIP, 0x395, 0, 1),
    OAM_ENTRY(0, 12, OAM_DIMS_8x32, OAM_X_FLIP, 0x397, 0, 1),
    OAM_ENTRY(-24, 12, OAM_DIMS_16x32, OAM_NO_FLIP, 0x395, 0, 1),
    OAM_ENTRY(-8, 12, OAM_DIMS_8x32, OAM_NO_FLIP, 0x397, 0, 1),
    OAM_ENTRY(8, 12, OAM_DIMS_16x32, OAM_X_FLIP, 0x395, 0, 1),
    OAM_ENTRY(0, 12, OAM_DIMS_8x32, OAM_X_FLIP, 0x397, 0, 1),
    OAM_ENTRY(-21, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3f0, 4, 1),
    OAM_ENTRY(13, 29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3f1, 4, 1),
    OAM_ENTRY(13, 13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3b1, 4, 1),
    OAM_ENTRY(-21, 13, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3b0, 4, 1),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x392, 4, 1),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x394, 4, 1),
    OAM_ENTRY(8, 0, OAM_DIMS_16x32, OAM_X_FLIP, 0x392, 4, 1),
    OAM_ENTRY(0, 0, OAM_DIMS_8x32, OAM_X_FLIP, 0x394, 4, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(0, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x210, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1)
};

static const u16 sChozodiaEscapeOam_MotherShipDoorOpening_Frame7[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-24, 13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x395, 0, 1),
    OAM_ENTRY(-8, 13, OAM_DIMS_8x32, OAM_NO_FLIP, 0x397, 0, 1),
    OAM_ENTRY(8, 13, OAM_DIMS_16x32, OAM_X_FLIP, 0x395, 0, 1),
    OAM_ENTRY(0, 13, OAM_DIMS_8x32, OAM_X_FLIP, 0x397, 0, 1),
    OAM_ENTRY(-24, 13, OAM_DIMS_16x32, OAM_NO_FLIP, 0x395, 0, 1),
    OAM_ENTRY(-8, 13, OAM_DIMS_8x32, OAM_NO_FLIP, 0x397, 0, 1),
    OAM_ENTRY(8, 13, OAM_DIMS_16x32, OAM_X_FLIP, 0x395, 0, 1),
    OAM_ENTRY(0, 13, OAM_DIMS_8x32, OAM_X_FLIP, 0x397, 0, 1),
    OAM_ENTRY(-21, 28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3f0, 4, 1),
    OAM_ENTRY(13, 28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3f1, 4, 1),
    OAM_ENTRY(13, 12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3b1, 4, 1),
    OAM_ENTRY(-21, 12, OAM_DIMS_8x16, OAM_NO_FLIP, 0x3b0, 4, 1),
    OAM_ENTRY(-24, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x392, 4, 1),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 0x394, 4, 1),
    OAM_ENTRY(8, 0, OAM_DIMS_16x32, OAM_X_FLIP, 0x392, 4, 1),
    OAM_ENTRY(0, 0, OAM_DIMS_8x32, OAM_X_FLIP, 0x394, 4, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(0, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x210, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1),
    OAM_ENTRY(-64, -16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x208, 0, 1)
};

const struct FrameData sChozodiaEscapeOam_MotherShipDoorOpening[9] = {
    sChozodiaEscapeOam_MotherShipDoorClosed_Frame0,
    24,
    sChozodiaEscapeOam_MotherShipDoorOpening_Frame1,
    10,
    sChozodiaEscapeOam_MotherShipDoorOpening_Frame2,
    20,
    sChozodiaEscapeOam_MotherShipDoorOpening_Frame3,
    10,
    sChozodiaEscapeOam_MotherShipDoorOpening_Frame4,
    10,
    sChozodiaEscapeOam_MotherShipDoorOpening_Frame5,
    10,
    sChozodiaEscapeOam_MotherShipDoorOpening_Frame6,
    8,
    sChozodiaEscapeOam_MotherShipDoorOpening_Frame7,
    60,
    NULL,
    0
};

static const u16 sChozodiaEscapeOam_Unused_5c9f3c[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x360, 5, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x362, 5, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a0, 5, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a2, 5, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 5, 0)
};

static const u16 sChozodiaEscapeOam_Unused_5c9f5c[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x363, 5, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x365, 5, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a3, 5, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a5, 5, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c0, 5, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c4, 5, 0)
};

static const u16 sChozodiaEscapeOam_Unused_5c9f82[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x366, 5, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x368, 5, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a6, 5, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3a8, 5, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c6, 5, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c2, 5, 0)
};

static const u16 sChozodiaEscapeOam_Unused_5c9fa8[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x369, 5, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x36b, 5, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a9, 5, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3ab, 5, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c4, 5, 0)
};

static const u16 sChozodiaEscapeOam_Unused_5c9fc8[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x369, 5, 0),
    OAM_ENTRY(-8, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0x36b, 5, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x3a9, 5, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3ab, 5, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x3c6, 5, 0)
};

const u16 sChozodiaEscapeOam_BlueShipFarAway_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x200, 15, 0)
};

const u16 sChozodiaEscapeOam_BlueShipVeryClose_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-64, -56, OAM_DIMS_64x64, OAM_NO_FLIP, 0x0, 15, 0),
    OAM_ENTRY(0, -56, OAM_DIMS_64x64, OAM_NO_FLIP, 0x8, 15, 0),
    OAM_ENTRY(-64, 8, OAM_DIMS_64x64, OAM_NO_FLIP, 0x100, 15, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_64x64, OAM_NO_FLIP, 0x108, 15, 0)
};

const u16 sChozodiaEscapeOam_MissionAccomplishedEnglish_Frame0[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-37, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(-15, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 0, 0),
    OAM_ENTRY(-2, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 0, 0),
    OAM_ENTRY(9, -24, OAM_DIMS_8x16, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(18, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x13, 0, 0),
    OAM_ENTRY(30, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x11, 0, 0),
    OAM_ENTRY(-71, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(-58, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-46, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-34, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x13, 0, 0),
    OAM_ENTRY(-22, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(-9, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x15, 0, 0),
    OAM_ENTRY(3, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0xd, 0, 0),
    OAM_ENTRY(13, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0xa, 0, 0),
    OAM_ENTRY(22, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 0, 0),
    OAM_ENTRY(34, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(46, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(58, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x4, 0, 0),
    OAM_ENTRY(69, 0, OAM_DIMS_8x16, OAM_NO_FLIP, 0xb, 0, 0)
};

const u16 sChozodiaEscapeOam_MissionAccomplishedHiragana_Frame0[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-63, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa0, 0, 0),
    OAM_ENTRY(-48, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa2, 0, 0),
    OAM_ENTRY(-33, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa4, 0, 0),
    OAM_ENTRY(-17, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa6, 0, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xa8, 0, 0),
    OAM_ENTRY(14, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xaa, 0, 0),
    OAM_ENTRY(27, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xac, 0, 0),
    OAM_ENTRY(41, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0xae, 0, 0),
    OAM_ENTRY(55, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0xb0, 0, 0)
};

#ifdef REGION_EU

const u16 sChozodiaEscapeOam_MissionAccomplishedGerman_Frame0[OAM_DATA_SIZE(21)] = {
    21,
    OAM_ENTRY(-94, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(-81, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x110, 0, 0),
    OAM_ENTRY(-76, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x146, 0, 0),
    OAM_ENTRY(-67, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x146, 0, 0),
    OAM_ENTRY(-58, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x110, 0, 0),
    OAM_ENTRY(-53, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x140, 0, 0),
    OAM_ENTRY(-44, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x118, 0, 0),
    OAM_ENTRY(-28, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x100, 0, 0),
    OAM_ENTRY(-18, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x102, 0, 0),
    OAM_ENTRY(-9, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 0x10c, 0, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x108, 0, 0),
    OAM_ENTRY(9, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x146, 0, 0),
    OAM_ENTRY(18, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x104, 0, 0),
    OAM_ENTRY(27, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x10e, 0, 0),
    OAM_ENTRY(36, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x114, 0, 0),
    OAM_ENTRY(41, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x140, 0, 0),
    OAM_ENTRY(50, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x146, 0, 0),
    OAM_ENTRY(59, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x146, 0, 0),
    OAM_ENTRY(68, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x108, 0, 0),
    OAM_ENTRY(77, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x118, 0, 0),
    OAM_ENTRY(88, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0xb0, 0, 0)
};

const u16 sChozodiaEscapeOam_MissionAccomplishedFrench_Frame0[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-67, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(-54, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x110, 0, 0),
    OAM_ENTRY(-49, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x146, 0, 0),
    OAM_ENTRY(-40, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x146, 0, 0),
    OAM_ENTRY(-31, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x110, 0, 0),
    OAM_ENTRY(-26, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x140, 0, 0),
    OAM_ENTRY(-17, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x118, 0, 0),
    OAM_ENTRY(-1, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x144, 0, 0),
    OAM_ENTRY(8, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x154, 0, 0),
    OAM_ENTRY(17, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x14a, 0, 0),
    OAM_ENTRY(26, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x146, 0, 0),
    OAM_ENTRY(35, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x146, 0, 0),
    OAM_ENTRY(44, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x110, 0, 0),
    OAM_ENTRY(49, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x108, 0, 0),
    OAM_ENTRY(59, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0xb0, 0, 0)
};

const u16 sChozodiaEscapeOam_MissionAccomplishedItalian_Frame0[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-78, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(-65, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x110, 0, 0),
    OAM_ENTRY(-60, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x146, 0, 0),
    OAM_ENTRY(-51, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x146, 0, 0),
    OAM_ENTRY(-42, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x110, 0, 0),
    OAM_ENTRY(-37, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x140, 0, 0),
    OAM_ENTRY(-28, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x118, 0, 0),
    OAM_ENTRY(-19, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x108, 0, 0),
    OAM_ENTRY(-3, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x104, 0, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x140, 0, 0),
    OAM_ENTRY(15, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x116, 0, 0),
    OAM_ENTRY(28, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x142, 0, 0),
    OAM_ENTRY(37, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x110, 0, 0),
    OAM_ENTRY(42, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x14a, 0, 0),
    OAM_ENTRY(51, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x148, 0, 0),
    OAM_ENTRY(60, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x100, 0, 0),
    OAM_ENTRY(71, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0xb0, 0, 0)
};

const u16 sChozodiaEscapeOam_MissionAccomplishedSpanish_Frame0[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-74, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0xb1, 0, 0),
    OAM_ENTRY(-66, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0xf, 0, 0),
    OAM_ENTRY(-53, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x110, 0, 0),
    OAM_ENTRY(-48, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x146, 0, 0),
    OAM_ENTRY(-39, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x110, 0, 0),
    OAM_ENTRY(-34, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x156, 0, 0),
    OAM_ENTRY(-25, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x118, 0, 0),
    OAM_ENTRY(-10, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x104, 0, 0),
    OAM_ENTRY(-1, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x14a, 0, 0),
    OAM_ENTRY(8, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x116, 0, 0),
    OAM_ENTRY(21, -9, OAM_DIMS_8x16, OAM_NO_FLIP, 0x142, 0, 0),
    OAM_ENTRY(31, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x114, 0, 0),
    OAM_ENTRY(37, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x110, 0, 0),
    OAM_ENTRY(42, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0x106, 0, 0),
    OAM_ENTRY(51, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x100, 0, 0),
    OAM_ENTRY(64, -11, OAM_DIMS_8x16, OAM_NO_FLIP, 0xb0, 0, 0)
};

#endif // REGION_EU

const u8 sChozodiaEscapeHeatingUpPalOffsets[8] = {
    0 * 16, 1 * 16, 2 * 16, 3 * 16,
    4 * 16, 5 * 16, 6 * 16, 7 * 16
};

const struct FrameData* const sChozodiaEscape_5ca0c4[5] = {
    sTourianEscapeOam_HugeShipExplosion,
    sChozodiaEscapeOam_SmallExplosion,
    sChozodiaEscapeOam_MediumExplosion,
    sChozodiaEscapeOam_MotherShipDecaying,
    sChozodiaEscapeOam_ShipSmokeExplosion
};

const u16 sChozodiaEscape_5ca0d8[8][2] = {
    [0] = { BLOCK_SIZE + QUARTER_BLOCK_SIZE + 8, BLOCK_SIZE },
    [1] = { BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE, BLOCK_SIZE * 2 - 8 },
    [2] = { BLOCK_SIZE + QUARTER_BLOCK_SIZE, BLOCK_SIZE + QUARTER_BLOCK_SIZE },
    [3] = { BLOCK_SIZE * 2 - 8, BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE },
    [4] = { BLOCK_SIZE + HALF_BLOCK_SIZE, BLOCK_SIZE + HALF_BLOCK_SIZE },
    [5] = { BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE, BLOCK_SIZE + QUARTER_BLOCK_SIZE + 8 },
    [6] = { BLOCK_SIZE + HALF_BLOCK_SIZE + 8, BLOCK_SIZE + HALF_BLOCK_SIZE + 8 },
    [7] = { BLOCK_SIZE * 2 + 8, BLOCK_SIZE + 8 }
};

const u16 sChozodiaEscape_5ca0f8[8][2] = {
    [0] = { BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE, BLOCK_SIZE * 2 - 8 },
    [1] = { BLOCK_SIZE + QUARTER_BLOCK_SIZE + 8, BLOCK_SIZE },
    [2] = { BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE, BLOCK_SIZE + QUARTER_BLOCK_SIZE + 8 },
    [3] = { BLOCK_SIZE + HALF_BLOCK_SIZE, BLOCK_SIZE + HALF_BLOCK_SIZE },
    [4] = { BLOCK_SIZE * 2 - 8, BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE },
    [5] = { BLOCK_SIZE + QUARTER_BLOCK_SIZE, BLOCK_SIZE + QUARTER_BLOCK_SIZE },
    [6] = { BLOCK_SIZE * 2 + 8, BLOCK_SIZE + 8 },
    [7] = { BLOCK_SIZE + HALF_BLOCK_SIZE + 8, BLOCK_SIZE + HALF_BLOCK_SIZE + 8 }
};

#ifdef REGION_EU
const u16 * const sChozodiaEscapeOamPointers_MissionAccomplished[LANGUAGE_COUNT] = {
    [LANGUAGE_JAPANESE] = sChozodiaEscapeOam_MissionAccomplishedEnglish_Frame0,
    [LANGUAGE_HIRAGANA] = sChozodiaEscapeOam_MissionAccomplishedHiragana_Frame0,
    [LANGUAGE_ENGLISH] = sChozodiaEscapeOam_MissionAccomplishedEnglish_Frame0,
    [LANGUAGE_GERMAN] = sChozodiaEscapeOam_MissionAccomplishedGerman_Frame0,
    [LANGUAGE_FRENCH] = sChozodiaEscapeOam_MissionAccomplishedFrench_Frame0,
    [LANGUAGE_ITALIAN] = sChozodiaEscapeOam_MissionAccomplishedItalian_Frame0,
    [LANGUAGE_SPANISH] = sChozodiaEscapeOam_MissionAccomplishedSpanish_Frame0
};
#endif // REGION_EU

const u32 sChozodiaEscapeCraterBackgroundGfx[5227] = INCBIN_U32("data/chozodia_escape/crater_background.gfx.lz");
const u32 sChozodiaEscapeCraterBackgroundTileTable[418] = INCBIN_U32("data/chozodia_escape/crater_background.tt");

const u32 sChozodiaEscapeBlueShipVeryCloseGfx[1079] = INCBIN_U32("data/chozodia_escape/blue_ship_very_close.gfx.lz");

const u32 sChozodiaEscapeZebesBackgroundTileTable[176] = INCBIN_U32("data/chozodia_escape/zebes_background.tt");
const u32 sChozodiaEscapeZebesAndSkyGfx[4574] = INCBIN_U32("data/chozodia_escape/zebes_and_sky.gfx.lz");
const u32 sChozodiaEscapeZebesSkyTileTable[418] = INCBIN_U32("data/chozodia_escape/zebes_sky.tt");

const u32 sChozodiaEscapeSamusInBlueShipGfx[2699] = INCBIN_U32("data/chozodia_escape/samus_in_blue_ship.gfx.lz");
const u32 sChozodiaEscapeSamusInBlueShipTileTable[368] = INCBIN_U32("data/chozodia_escape/samus_in_blue_ship.tt");

const u32 sChozodiaEscapeMissionAccomplishedLettersGfx[] = INCBIN_U32("data/chozodia_escape/mission_accomplished_letters.gfx.lz");
