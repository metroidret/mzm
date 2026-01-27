#include "data/tourian_escape_data.h"

const u16 sTourianEscapeExplodingPal[9 * 16] = INCBIN_U16("data/tourian_escape/exploding.pal");
const u16 sMotherShipBlowingUpExplosionsPal[6 * 16] = INCBIN_U16("data/tourian_escape/blowing_up_explosions.pal");

const u16 sTourianEscapeSamusInHerShipPowerSuitPal[7 * 16] = INCBIN_U16("data/tourian_escape/samus_in_her_ship_power_suit.pal");
const u16 sTourianEscapeSamusInHerShipVariaSuitPal[7 * 16] = INCBIN_U16("data/tourian_escape/samus_in_her_ship_varia_suit.pal");
const u16 sTourianEscapeSamusInHerShipSuitlessPal[8 * 16] = INCBIN_U16("data/tourian_escape/samus_in_her_ship_suitless.pal");

const u16 sTourianEscapeSamusLookingAroundPal[7 * 16] = INCBIN_U16("data/tourian_escape/samus_looking_around.pal");
const u16 sTourianEscapeSamusChasedBackgroundPal[5 * 16] = INCBIN_U16("data/tourian_escape/samus_chased_background.pal");
const u16 sTourianEscapeSamusGettingShotPal[5 * 16] = INCBIN_U16("data/tourian_escape/samus_getting_shot.pal");
const u16 sTourianEscapeSamusSurroundedPal[16 * 16] = INCBIN_U16("data/tourian_escape/samus_surrounded.pal");
const u16 sTourianEscapeSamusChasedShipsPal[6 * 16] = INCBIN_U16("data/tourian_escape/samus_chased_ships.pal");
const u16 sTourianEscapeSamusChasedByPiratesFiringPal[4 * 16] = INCBIN_U16("data/tourian_escape/samus_chased_by_pirates_firing.pal");
const u16 sTourianEscapeSamusGoingToCrashPal[7 * 16] = INCBIN_U16("data/tourian_escape/samus_going_to_crash.pal");
const u16 sTourianEscape_479ee0[1 * 16] = INCBIN_U16("data/tourian_escape/479ee0.pal");
const u16 sTourianEscape_479f00[1 * 16] = INCBIN_U16("data/tourian_escape/479f00.pal");
const u16 sTourianEscapeSamusCrashingForegroundPal[3 * 16] = INCBIN_U16("data/tourian_escape/samus_crashing_foreground.pal");
const u16 sTourianEscape_479f80[7 * 16] = INCBIN_U16("data/tourian_escape/479f80.pal");
const u16 sTourianEscapeShipCrashingBackgroundAndShipPal[16 * 16] = INCBIN_U16("data/tourian_escape/ship_crashing_background_and_ship.pal");
const u16 sTourianEscapeSamusLookingAtSkyPal[10 * 16] = INCBIN_U16("data/tourian_escape/samus_looking_at_sky.pal");
const u16 sTourianEscapeSamusLookingAtMotherShipPal[10 * 16] = INCBIN_U16("data/tourian_escape/samus_looking_at_mother_ship.pal");

const u16 sTourianEscape_47a4e0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 0x6, 5, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x100, 6, 0),
    OAM_ENTRY(-64, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20, 5, 0),
    OAM_ENTRY(-32, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24, 5, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x65, 5, 0),
    OAM_ENTRY_MODE(-32, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x100, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT)
};

const u16 sTourianEscape_47a506[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 0x6, 5, 0),
    OAM_ENTRY_MODE(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x102, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY(-64, -24, OAM_DIMS_32x16, OAM_NO_FLIP, 0x20, 5, 0),
    OAM_ENTRY(-32, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x24, 5, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x65, 5, 0),
    OAM_ENTRY_MODE(-32, -16, OAM_DIMS_16x16, OAM_Y_FLIP, 0x102, 6, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT)
};

const u16 sTourianEscape_47a52c[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-64, -48, OAM_DIMS_64x64, OAM_NO_FLIP, 0x140, 7, 0),
    OAM_ENTRY(0, -48, OAM_DIMS_64x64, OAM_NO_FLIP, 0x148, 7, 0),
    OAM_ENTRY(64, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x1d0, 7, 0)
};

const u16 sTourianEscape_47a540[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-64, -48, OAM_DIMS_64x64, OAM_NO_FLIP, 0x140, 8, 0),
    OAM_ENTRY(0, -48, OAM_DIMS_64x64, OAM_NO_FLIP, 0x148, 8, 0),
    OAM_ENTRY(64, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 0x1d0, 8, 0)
};

const u16 sTourianEscape_47a554[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-128, -80, OAM_DIMS_64x64, OAM_NO_FLIP, 0x300, 6, 0),
    OAM_ENTRY(-64, -80, OAM_DIMS_64x64, OAM_NO_FLIP, 0x300, 6, 0),
    OAM_ENTRY(0, -80, OAM_DIMS_64x64, OAM_NO_FLIP, 0x300, 6, 0),
    OAM_ENTRY(64, -80, OAM_DIMS_64x64, OAM_NO_FLIP, 0x300, 6, 0)
};

const u16 sTourianEscape_47a56e[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-128, 16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x300, 6, 0),
    OAM_ENTRY(-64, 16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x300, 6, 0),
    OAM_ENTRY(0, 16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x300, 6, 0),
    OAM_ENTRY(64, 16, OAM_DIMS_64x64, OAM_NO_FLIP, 0x300, 6, 0)
};

const u16 sTourianEscape_47a588[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY_MODE(-32, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x380, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(0, -8, OAM_DIMS_16x32, OAM_NO_FLIP, 0x384, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY(-16, -56, OAM_DIMS_64x64, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(16, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x10d, 0, 0),
    OAM_ENTRY(-56, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x64, 0, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 0x48, 0, 0)
};

const u16 sTourianEscape_47a5ae[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY_MODE(-32, -8, OAM_DIMS_32x32, OAM_NO_FLIP, 0x386, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(0, -8, OAM_DIMS_16x32, OAM_NO_FLIP, 0x38a, 4, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY(-16, -56, OAM_DIMS_64x64, OAM_NO_FLIP, 0x9, 0, 0),
    OAM_ENTRY(16, 8, OAM_DIMS_32x16, OAM_NO_FLIP, 0x10d, 0, 0),
    OAM_ENTRY(-56, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x64, 0, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_8x32, OAM_NO_FLIP, 0x48, 0, 0)
};

const u16 sTourianEscape_47a5d4[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-8, -64, OAM_DIMS_64x64, OAM_NO_FLIP, 0x1a5, 2, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 0x1e4, 2, 0),
    OAM_ENTRY(-40, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x2a1, 2, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_NO_FLIP, 0x2a5, 2, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x283, 2, 0)
};

const u16 sTourianEscape_47a5f4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-16, -56, OAM_DIMS_64x64, OAM_NO_FLIP, 0x1ae, 2, 0),
    OAM_ENTRY(-16, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x2ae, 2, 0)
};

const u16 sTourianEscape_47a602[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-32, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x12, 1, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x16, 1, 0),
    OAM_ENTRY(16, -24, OAM_DIMS_8x32, OAM_NO_FLIP, 0x18, 1, 0),
    OAM_ENTRY(-32, 8, OAM_DIMS_32x8, OAM_NO_FLIP, 0x92, 1, 0),
    OAM_ENTRY(0, 8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x96, 1, 0)
};

const u16 sTourianEscape_47a622[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x1a, 3, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x1e, 3, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x9a, 3, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x9e, 3, 0),
    OAM_ENTRY(-24, 16, OAM_DIMS_32x8, OAM_NO_FLIP, 0xda, 3, 0)
};

const u16 sTourianEscape_47a642[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x13a, 3, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x13e, 3, 0),
    OAM_ENTRY(-24, 16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x1ba, 3, 0),
    OAM_ENTRY(8, 16, OAM_DIMS_16x8, OAM_NO_FLIP, 0x1be, 3, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0xfe, 3, 0)
};

const u16 sTourianEscape_47a662[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-24, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x1fa, 3, 0),
    OAM_ENTRY(8, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x1fe, 3, 0),
    OAM_ENTRY(-24, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x27a, 3, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x27e, 3, 0),
    OAM_ENTRY(-24, 16, OAM_DIMS_32x8, OAM_NO_FLIP, 0x2ba, 3, 0)
};

const u16 sTourianEscape_47a682[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3dc, 5, 0)
};

const u16 sTourianEscape_47a68a[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3dd, 5, 0)
};

const u16 sTourianEscape_47a692[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3de, 5, 0)
};

const u16 sTourianEscape_47a69a[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3df, 5, 0)
};

const u16 sTourianEscape_47a6a2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3fc, 5, 0)
};

const u16 sTourianEscape_47a6aa[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3fd, 5, 0)
};

const u16 sTourianEscape_47a6b2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3fe, 5, 0)
};

const u16 sTourianEscape_47a6ba[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3ff, 5, 0)
};

const u16 sTourianEscape_47a6c2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-64, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY_MODE(-40, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x184, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(8, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x184, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT)
};

const u16 sTourianEscape_47a6dc[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-64, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY_MODE(-40, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x180, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(8, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x180, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT)
};

const u16 sTourianEscape_47a6f6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-64, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY_MODE(-40, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x184, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(8, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x184, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT)
};

const u16 sTourianEscape_47a710[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-64, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY_MODE(-40, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x180, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(8, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x180, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT)
};

const u16 sTourianEscape_47a72a[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-64, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY_MODE(-40, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x188, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(8, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 0x188, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT)
};

const u16 sTourianEscape_47a744[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-64, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x0, 0, 0),
    OAM_ENTRY(8, -24, OAM_DIMS_64x32, OAM_NO_FLIP, 0x194, 2, 0),
    OAM_ENTRY_MODE(-72, -24, OAM_DIMS_64x32, OAM_NO_FLIP, 0x18c, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT)
};

const u16 sTourianEscape_47a75e[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-100, -25, OAM_DIMS_64x32, OAM_NO_FLIP, 0x100, 1, 0),
    OAM_ENTRY(-40, -21, OAM_DIMS_32x32, OAM_NO_FLIP, 0x108, 1, 0),
    OAM_ENTRY(-12, -25, OAM_DIMS_64x32, OAM_NO_FLIP, 0x10c, 1, 0),
    OAM_ENTRY(50, -23, OAM_DIMS_32x32, OAM_NO_FLIP, 0x114, 1, 0)
};

const u16 sTourianEscape_47a778[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY_MODE(34, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x50, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY(-13, -24, OAM_DIMS_64x32, OAM_NO_FLIP, 0x10c, 1, 0),
    OAM_ENTRY_MODE(-32, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x50, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-64, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x50, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-88, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x50, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY(-100, -25, OAM_DIMS_64x32, OAM_NO_FLIP, 0x100, 1, 0),
    OAM_ENTRY(-40, -21, OAM_DIMS_32x32, OAM_NO_FLIP, 0x108, 1, 0),
    OAM_ENTRY(50, -25, OAM_DIMS_32x32, OAM_NO_FLIP, 0x114, 1, 0)
};

const u16 sTourianEscape_47a7aa[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY_MODE(64, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x50, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(8, -8, OAM_DIMS_16x8, OAM_NO_FLIP, 0x52, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(10, -1, OAM_DIMS_32x16, OAM_NO_FLIP, 0x10, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-24, 3, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-56, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 0x54, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-80, -16, OAM_DIMS_32x16, OAM_Y_FLIP, 0x14, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY(-100, -25, OAM_DIMS_64x32, OAM_NO_FLIP, 0x100, 1, 0),
    OAM_ENTRY(-40, -22, OAM_DIMS_32x32, OAM_NO_FLIP, 0x108, 1, 0),
    OAM_ENTRY(-14, -24, OAM_DIMS_64x32, OAM_NO_FLIP, 0x10c, 1, 0),
    OAM_ENTRY(50, -23, OAM_DIMS_32x32, OAM_NO_FLIP, 0x114, 1, 0)
};

const u16 sTourianEscape_47a7e8[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(35, -5, OAM_DIMS_16x8, OAM_NO_FLIP, 0x52, 2, 0),
    OAM_ENTRY(-64, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x50, 2, 0),
    OAM_ENTRY_MODE(0, -8, OAM_DIMS_16x32, OAM_X_FLIP, 0x54, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-24, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x10, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(8, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-40, 32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x54, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-48, -32, OAM_DIMS_32x16, OAM_Y_FLIP, 0x14, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(40, 0, OAM_DIMS_32x16, OAM_NO_FLIP, 0x10, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY(-100, -25, OAM_DIMS_64x32, OAM_NO_FLIP, 0x100, 1, 0),
    OAM_ENTRY(-40, -21, OAM_DIMS_32x32, OAM_NO_FLIP, 0x108, 1, 0),
    OAM_ENTRY(-12, -25, OAM_DIMS_64x32, OAM_NO_FLIP, 0x10c, 1, 0),
    OAM_ENTRY(50, -23, OAM_DIMS_32x32, OAM_NO_FLIP, 0x114, 1, 0)
};

const u16 sTourianEscape_47a832[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-32, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x50, 2, 0),
    OAM_ENTRY(24, -32, OAM_DIMS_16x32, OAM_XY_FLIP, 0x54, 2, 0),
    OAM_ENTRY(-56, -32, OAM_DIMS_16x32, OAM_Y_FLIP, 0x54, 2, 0),
    OAM_ENTRY_MODE(8, 16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x10, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-104, 56, OAM_DIMS_32x16, OAM_NO_FLIP, 0x10, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(88, 56, OAM_DIMS_32x16, OAM_NO_FLIP, 0x14, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(0, 104, OAM_DIMS_16x32, OAM_NO_FLIP, 0x54, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(40, -80, OAM_DIMS_32x16, OAM_Y_FLIP, 0x14, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-16, 24, OAM_DIMS_16x32, OAM_X_FLIP, 0x54, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY(-100, -26, OAM_DIMS_64x32, OAM_NO_FLIP, 0x100, 1, 0),
    OAM_ENTRY(-40, -22, OAM_DIMS_32x32, OAM_NO_FLIP, 0x108, 1, 0),
    OAM_ENTRY(-12, -24, OAM_DIMS_64x32, OAM_NO_FLIP, 0x10c, 1, 0),
    OAM_ENTRY(51, -23, OAM_DIMS_32x32, OAM_NO_FLIP, 0x114, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_32x16, OAM_NO_FLIP, 0x18, 2, 0)
};

const u16 sTourianEscape_47a888[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-56, 4, OAM_DIMS_32x16, OAM_NO_FLIP, 0x10, 2, 0),
    OAM_ENTRY_MODE(-56, 48, OAM_DIMS_32x16, OAM_NO_FLIP, 0x10, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(104, 80, OAM_DIMS_32x16, OAM_NO_FLIP, 0x10, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(104, -120, OAM_DIMS_32x16, OAM_Y_FLIP, 0x14, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-40, 72, OAM_DIMS_16x32, OAM_X_FLIP, 0x54, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY(-100, -24, OAM_DIMS_64x32, OAM_NO_FLIP, 0x100, 1, 0),
    OAM_ENTRY(-40, -22, OAM_DIMS_32x32, OAM_NO_FLIP, 0x108, 1, 0),
    OAM_ENTRY(-13, -25, OAM_DIMS_64x32, OAM_NO_FLIP, 0x10c, 1, 0),
    OAM_ENTRY(49, -23, OAM_DIMS_32x32, OAM_NO_FLIP, 0x114, 1, 0),
    OAM_ENTRY(-40, -72, OAM_DIMS_16x32, OAM_Y_FLIP, 0x54, 2, 0),
    OAM_ENTRY(8, -64, OAM_DIMS_16x32, OAM_XY_FLIP, 0x54, 2, 0)
};

const u16 sTourianEscape_47a8cc[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY_MODE(-120, 72, OAM_DIMS_32x16, OAM_NO_FLIP, 0x10, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-64, 120, OAM_DIMS_16x32, OAM_X_FLIP, 0x54, 2, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY(-100, -25, OAM_DIMS_64x32, OAM_NO_FLIP, 0x100, 1, 0),
    OAM_ENTRY(-40, -21, OAM_DIMS_32x32, OAM_NO_FLIP, 0x108, 1, 0),
    OAM_ENTRY(-12, -25, OAM_DIMS_64x32, OAM_NO_FLIP, 0x10c, 1, 0),
    OAM_ENTRY(50, -23, OAM_DIMS_32x32, OAM_NO_FLIP, 0x114, 1, 0),
    OAM_ENTRY(8, 112, OAM_DIMS_16x32, OAM_Y_FLIP, 0x54, 2, 0),
    OAM_ENTRY(-16, -112, OAM_DIMS_16x32, OAM_XY_FLIP, 0x54, 2, 0),
    OAM_ENTRY(-112, 29, OAM_DIMS_32x16, OAM_NO_FLIP, 0x10, 2, 0)
};

const u16 sTourianEscape_47a904[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-48, -32, OAM_DIMS_64x64, OAM_NO_FLIP, 0x0, 4, 0),
    OAM_ENTRY(16, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x28, 4, 0),
    OAM_ENTRY(48, -24, OAM_DIMS_32x32, OAM_NO_FLIP, 0x2c, 4, 0)
};

const u16 sTourianEscape_47a918[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3dc, 3, 0)
};

const u16 sTourianEscape_47a920[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3dd, 3, 0)
};

const u16 sTourianEscape_47a928[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3de, 3, 0)
};

const u16 sTourianEscape_47a930[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3df, 3, 0)
};

const u16 sTourianEscape_47a938[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3fc, 3, 0)
};

const u16 sTourianEscape_47a940[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3fd, 3, 0)
};

const u16 sTourianEscape_47a948[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3fe, 3, 0)
};

const u16 sTourianEscape_47a950[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3ff, 3, 0)
};

const u16 sTourianEscape_47a958[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY_MODE(-24, -88, OAM_DIMS_64x64, OAM_NO_FLIP, 0x10, 5, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(40, -88, OAM_DIMS_64x64, OAM_NO_FLIP, 0x18, 5, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-24, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x110, 5, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(40, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x118, 5, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-24, 40, OAM_DIMS_64x32, OAM_NO_FLIP, 0x210, 5, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(40, 40, OAM_DIMS_64x32, OAM_NO_FLIP, 0x218, 5, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-56, -88, OAM_DIMS_32x64, OAM_NO_FLIP, 0xc, 5, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT),
    OAM_ENTRY_MODE(-56, -24, OAM_DIMS_32x64, OAM_NO_FLIP, 0x10c, 5, 0, OAM_OBJ_MODE_SEMI_TRANSPARENT)
};

const u16 sTourianEscape_47a98a[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x4, 6, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x8, 6, 0)
};

const u16 sTourianEscape_47a998[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-5, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x84, 6, 0)
};

const u16 sTourianEscape_47a9a0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x86, 6, 0)
};

const u16 sTourianEscape_47a9a8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 0x88, 6, 0)
};

const u16 sTourianEscape_47a9b0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(13, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x100, 2, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 15, 0),
    OAM_ENTRY(17, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc2, 2, 0),
    OAM_ENTRY(33, -31, OAM_DIMS_8x8, OAM_NO_FLIP, 0x103, 2, 0),
    OAM_ENTRY(6, -9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x100, 2, 0),
    OAM_ENTRY(12, -10, OAM_DIMS_8x8, OAM_NO_FLIP, 0x101, 2, 0),
    OAM_ENTRY(8, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x102, 2, 0)
};

const u16 sTourianEscape_47a9dc[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(3, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x100, 2, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 15, 0),
    OAM_ENTRY(5, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x80, 2, 0),
    OAM_ENTRY(20, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc2, 2, 0),
    OAM_ENTRY(36, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x103, 2, 0),
    OAM_ENTRY(40, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x104, 2, 0),
    OAM_ENTRY(36, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x104, 2, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x102, 2, 0),
    OAM_ENTRY(2, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x103, 2, 0),
    OAM_ENTRY(12, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0)
};

const u16 sTourianEscape_47aa1a[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(7, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 0x101, 2, 0),
    OAM_ENTRY(-8, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x0, 15, 0),
    OAM_ENTRY(40, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x104, 2, 0),
    OAM_ENTRY(36, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x104, 2, 0),
    OAM_ENTRY(0, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x102, 2, 0),
    OAM_ENTRY(2, -14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x103, 2, 0),
    OAM_ENTRY(25, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x103, 2, 0),
    OAM_ENTRY(23, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x102, 2, 0),
    OAM_ENTRY(31, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x103, 2, 0),
    OAM_ENTRY(10, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x82, 2, 0),
    OAM_ENTRY(15, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0xe2, 2, 0)
};

const u16 sTourianEscape_47aa5e[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(15, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x101, 2, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 15, 0),
    OAM_ENTRY(2, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(31, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 0x103, 2, 0),
    OAM_ENTRY(15, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0xc0, 2, 0),
    OAM_ENTRY(23, -31, OAM_DIMS_8x8, OAM_NO_FLIP, 0x103, 2, 0),
    OAM_ENTRY(25, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x104, 2, 0),
    OAM_ENTRY(10, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x102, 2, 0),
    OAM_ENTRY(39, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0x104, 2, 0)
};

const u16 sTourianEscape_47aa96[OAM_DATA_SIZE(24)] = {
    24,
    OAM_ENTRY(-88, -104, OAM_DIMS_64x64, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-24, -104, OAM_DIMS_64x64, OAM_NO_FLIP, 0x10, 0, 0),
    OAM_ENTRY(40, -104, OAM_DIMS_64x64, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-104, -104, OAM_DIMS_16x32, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(-104, -72, OAM_DIMS_16x32, OAM_NO_FLIP, 0x86, 0, 0),
    OAM_ENTRY(-104, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x106, 0, 0),
    OAM_ENTRY(-104, -8, OAM_DIMS_16x32, OAM_NO_FLIP, 0x186, 0, 0),
    OAM_ENTRY(-104, 24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 0, 0),
    OAM_ENTRY(-120, -104, OAM_DIMS_16x32, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(-120, -72, OAM_DIMS_16x32, OAM_NO_FLIP, 0x86, 0, 0),
    OAM_ENTRY(-120, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x106, 0, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_16x32, OAM_NO_FLIP, 0x186, 0, 0),
    OAM_ENTRY(-120, 24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 0, 0),
    OAM_ENTRY(104, -104, OAM_DIMS_16x32, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(104, -72, OAM_DIMS_16x32, OAM_NO_FLIP, 0x86, 0, 0),
    OAM_ENTRY(104, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x106, 0, 0),
    OAM_ENTRY(104, -8, OAM_DIMS_16x32, OAM_NO_FLIP, 0x186, 0, 0),
    OAM_ENTRY(104, 24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 0, 0),
    OAM_ENTRY(-88, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 0x108, 0, 0),
    OAM_ENTRY(-24, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 0x110, 0, 0),
    OAM_ENTRY(40, -40, OAM_DIMS_64x64, OAM_NO_FLIP, 0x118, 0, 0),
    OAM_ENTRY(-88, 24, OAM_DIMS_64x32, OAM_NO_FLIP, 0x208, 0, 0),
    OAM_ENTRY(-24, 24, OAM_DIMS_64x32, OAM_NO_FLIP, 0x210, 0, 0),
    OAM_ENTRY(40, 24, OAM_DIMS_64x32, OAM_NO_FLIP, 0x218, 0, 0)
};

const u16 sTourianEscape_47ab28[OAM_DATA_SIZE(24)] = {
    24,
    OAM_ENTRY(-88, -56, OAM_DIMS_64x32, OAM_NO_FLIP, 0x288, 1, 0),
    OAM_ENTRY(-88, -104, OAM_DIMS_64x64, OAM_NO_FLIP, 0x8, 0, 0),
    OAM_ENTRY(-24, -104, OAM_DIMS_64x64, OAM_NO_FLIP, 0x10, 0, 0),
    OAM_ENTRY(40, -104, OAM_DIMS_64x64, OAM_NO_FLIP, 0x18, 0, 0),
    OAM_ENTRY(-104, -104, OAM_DIMS_16x32, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(-104, -72, OAM_DIMS_16x32, OAM_NO_FLIP, 0x86, 0, 0),
    OAM_ENTRY(-104, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x106, 0, 0),
    OAM_ENTRY(-104, -8, OAM_DIMS_16x32, OAM_NO_FLIP, 0x186, 0, 0),
    OAM_ENTRY(-104, 24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 0, 0),
    OAM_ENTRY(-120, -104, OAM_DIMS_16x32, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(-120, -72, OAM_DIMS_16x32, OAM_NO_FLIP, 0x86, 0, 0),
    OAM_ENTRY(-120, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x106, 0, 0),
    OAM_ENTRY(-120, -8, OAM_DIMS_16x32, OAM_NO_FLIP, 0x186, 0, 0),
    OAM_ENTRY(-120, 24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 0, 0),
    OAM_ENTRY(104, -104, OAM_DIMS_16x32, OAM_NO_FLIP, 0x6, 0, 0),
    OAM_ENTRY(104, -72, OAM_DIMS_16x32, OAM_NO_FLIP, 0x86, 0, 0),
    OAM_ENTRY(104, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x106, 0, 0),
    OAM_ENTRY(104, -8, OAM_DIMS_16x32, OAM_NO_FLIP, 0x186, 0, 0),
    OAM_ENTRY(104, 24, OAM_DIMS_16x32, OAM_NO_FLIP, 0x206, 0, 0),
    OAM_ENTRY(-88, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x308, 1, 0),
    OAM_ENTRY(-24, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x310, 1, 0),
    OAM_ENTRY(40, -24, OAM_DIMS_64x64, OAM_NO_FLIP, 0x318, 1, 0),
    OAM_ENTRY(-24, -56, OAM_DIMS_64x32, OAM_NO_FLIP, 0x290, 1, 0),
    OAM_ENTRY(40, -56, OAM_DIMS_64x32, OAM_NO_FLIP, 0x298, 1, 0)
};

const u16 sTourianEscape_47abba[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -48, OAM_DIMS_64x64, OAM_NO_FLIP, 0x0, 9, 0),
    OAM_ENTRY(-32, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x100, 9, 0)
};

const u16 sTourianEscape_47abc8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -48, OAM_DIMS_64x64, OAM_NO_FLIP, 0xc, 9, 0),
    OAM_ENTRY(-40, 16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x10a, 9, 0)
};

const u32 sTourianEscapeRainGfx[14] = INCBIN_U32("data/tourian_escape/rain.gfx.lz");

const u16 sTourianEscape_47ac10[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1, 0, 0)
};

const u16 sTourianEscape_47ac18[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x2, 0, 0),
    OAM_ENTRY(-4, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x3, 0, 0)
};

const u16 sTourianEscapeRainPal[1 * 16] = INCBIN_U16("data/tourian_escape/rain.pal");




static const u16 sChozodiaEscapeOam_ShipSmokeExplosion_Frame0[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-14, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x92, 3, 0),
    OAM_ENTRY(-2, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x92, 3, 0),
    OAM_ENTRY(-9, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1, 3, 0),
    OAM_ENTRY(-3, -32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x1, 3, 0),
    OAM_ENTRY(-8, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x92, 3, 0),
    OAM_ENTRY(0, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x92, 3, 0),
    OAM_ENTRY(-16, 2, OAM_DIMS_16x16, OAM_X_FLIP, 0x92, 3, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeExplosion_Frame1[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-12, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x92, 3, 0),
    OAM_ENTRY(-2, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x92, 3, 0),
    OAM_ENTRY(-9, -36, OAM_DIMS_8x8, OAM_Y_FLIP, 0x1, 3, 0),
    OAM_ENTRY(-2, -41, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1, 3, 0),
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x92, 3, 0),
    OAM_ENTRY(-14, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x94, 3, 0),
    OAM_ENTRY(3, -10, OAM_DIMS_16x16, OAM_XY_FLIP, 0x94, 3, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeExplosion_Frame2[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-12, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1, 3, 0),
    OAM_ENTRY(2, -22, OAM_DIMS_8x8, OAM_Y_FLIP, 0x1, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x94, 3, 0),
    OAM_ENTRY(0, -33, OAM_DIMS_16x16, OAM_X_FLIP, 0x94, 3, 0),
    OAM_ENTRY(-13, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x94, 3, 0),
    OAM_ENTRY(-8, -40, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(1, -48, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeExplosion_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-3, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1, 3, 0),
    OAM_ENTRY(2, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1, 3, 0),
    OAM_ENTRY(-7, -33, OAM_DIMS_16x16, OAM_X_FLIP, 0x94, 3, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeExplosion_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -43, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(4, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-7, -41, OAM_DIMS_16x16, OAM_XY_FLIP, 0x94, 3, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeExplosion_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -42, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(0, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-4, -23, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeExplosion_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -47, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(0, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-3, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-13, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-17, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x40, 4, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-4, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-20, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(6, -13, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame4[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-3, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-19, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame5[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-18, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(8, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-3, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(5, -15, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-3, -11, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame6[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(6, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-14, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-6, -22, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-14, -18, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame7[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -28, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-9, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(5, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(13, -22, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(5, -18, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame8[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(3, -29, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(5, -21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-20, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(1, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x42, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame2[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-22, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(2, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame3[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-21, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(4, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame4[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-20, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(3, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-8, -15, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(1, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-18, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-19, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-11, -34, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-19, -30, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-5, -30, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-3, -22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-19, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-16, -43, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-14, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame7[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-18, -26, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-1, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(7, -24, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-1, -20, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame8[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(1, -32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(3, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-17, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-9, -26, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-17, -22, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0)
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame9[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-11, -32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-9, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x1e, 2, 0)
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0)
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0)
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0)
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0)
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0)
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame7[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0)
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame8[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-5, -20, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-3, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0)
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame9[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-3, -22, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(0, -22, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0)
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame10[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, -27, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-3, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame5[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-8, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-8, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(0, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame6[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(0, -11, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-14, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame7[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-14, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame8[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-5, -20, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-3, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-8, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(0, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-14, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame9[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-3, -22, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-5, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-8, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(0, -22, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-8, -18, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(0, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-14, -11, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame10[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-5, -27, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-3, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(8, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(0, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-14, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame11[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(3, -20, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(5, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(0, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-14, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-14, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame12[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(5, -22, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(3, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(0, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(8, -22, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-14, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-8, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-14, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-14, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame13[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(3, -27, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(5, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-6, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-14, -12, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-6, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-14, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame14[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-11, -20, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-9, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-14, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame15[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-9, -22, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-11, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-14, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-6, -22, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-14, -18, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame16[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-11, -27, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-9, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame3[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-10, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-2, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-10, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(3, -11, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-7, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame4[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-2, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-10, -12, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-2, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-10, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(3, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-7, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame5[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-7, -20, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-5, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-10, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(3, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(3, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-7, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame6[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-5, -22, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-7, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-10, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-2, -22, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-10, -18, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(3, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(11, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(3, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(3, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-16, -11, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-7, -3, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame7[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(-7, -27, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-5, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(11, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(3, -12, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(11, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(3, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-7, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame8[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(6, -20, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(8, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(3, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-16, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-7, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame9[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(8, -22, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(6, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(3, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(11, -22, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(3, -18, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-10, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-16, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-7, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame10[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(6, -27, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-16, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(1, -10, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-7, -6, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame11[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-13, -20, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-11, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-16, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-2, -12, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame12[OAM_DATA_SIZE(5)] = {
    5,
    OAM_ENTRY(-11, -22, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-13, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-16, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-8, -22, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0)
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame13[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-13, -27, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-11, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0)
};

static const u16 sChozodiaEscapeOam_HugeExplosion_Frame0[OAM_DATA_SIZE(9)] = {
    9,
    OAM_ENTRY(-21, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(4, -21, OAM_DIMS_16x16, OAM_X_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-21, 1, OAM_DIMS_16x16, OAM_Y_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(4, 1, OAM_DIMS_16x16, OAM_XY_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-10, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(5, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-22, -7, OAM_DIMS_16x16, OAM_Y_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-8, 2, OAM_DIMS_16x16, OAM_XY_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-9, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_47b3c0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x48, 3, 0)
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame0[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x56, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x56, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x56, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x56, 3, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4a, 3, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x4a, 3, 0)
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame1[OAM_DATA_SIZE(6)] = {
    6,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x58, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x58, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x58, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x58, 3, 0),
    OAM_ENTRY(16, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4b, 3, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x4b, 3, 0)
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame2[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x5a, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x5a, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x5a, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x5a, 3, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x56, 3, 0),
    OAM_ENTRY(16, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x56, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 0x56, 3, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 0x56, 3, 0),
    OAM_ENTRY(-10, 4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4a, 3, 0),
    OAM_ENTRY(-18, 4, OAM_DIMS_8x16, OAM_X_FLIP, 0x4a, 3, 0)
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame3[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-12, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(3, -12, OAM_DIMS_8x16, OAM_X_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-12, 4, OAM_DIMS_8x8, OAM_Y_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-4, 3, OAM_DIMS_16x8, OAM_XY_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x5c, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x5c, 3, 0),
    OAM_ENTRY(-16, 0, OAM_DIMS_16x16, OAM_Y_FLIP, 0x5c, 3, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x5c, 3, 0),
    OAM_ENTRY(0, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x58, 3, 0),
    OAM_ENTRY(16, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x58, 3, 0),
    OAM_ENTRY(0, -8, OAM_DIMS_16x16, OAM_Y_FLIP, 0x58, 3, 0),
    OAM_ENTRY(16, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 0x58, 3, 0),
    OAM_ENTRY(-10, 4, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4b, 3, 0),
    OAM_ENTRY(-18, 4, OAM_DIMS_8x16, OAM_X_FLIP, 0x4b, 3, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4a, 3, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x4a, 3, 0)
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame4[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-13, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-2, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-14, -7, OAM_DIMS_16x16, OAM_Y_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-3, -6, OAM_DIMS_16x16, OAM_XY_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-4, -28, OAM_DIMS_32x16, OAM_NO_FLIP, 0x4e, 3, 0),
    OAM_ENTRY(-4, -20, OAM_DIMS_16x32, OAM_NO_FLIP, 0x96, 3, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_32x16, OAM_XY_FLIP, 0x4e, 3, 0),
    OAM_ENTRY(20, -28, OAM_DIMS_16x32, OAM_XY_FLIP, 0x96, 3, 0),
    OAM_ENTRY(15, -16, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4a, 3, 0),
    OAM_ENTRY(9, -16, OAM_DIMS_8x16, OAM_X_FLIP, 0x4a, 3, 0),
    OAM_ENTRY(-26, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x56, 3, 0),
    OAM_ENTRY(-10, -4, OAM_DIMS_16x16, OAM_X_FLIP, 0x56, 3, 0),
    OAM_ENTRY(-26, 12, OAM_DIMS_16x16, OAM_Y_FLIP, 0x56, 3, 0),
    OAM_ENTRY(-10, 12, OAM_DIMS_16x16, OAM_XY_FLIP, 0x56, 3, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x16, OAM_NO_FLIP, 0x4b, 3, 0),
    OAM_ENTRY(-12, -32, OAM_DIMS_8x16, OAM_X_FLIP, 0x4b, 3, 0)
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame5[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-15, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(0, -23, OAM_DIMS_16x16, OAM_X_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-16, -9, OAM_DIMS_16x16, OAM_Y_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-1, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0x52, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x98, 3, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_32x16, OAM_XY_FLIP, 0x52, 3, 0),
    OAM_ENTRY(24, -32, OAM_DIMS_16x32, OAM_XY_FLIP, 0x98, 3, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-26, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x58, 3, 0),
    OAM_ENTRY(-10, -4, OAM_DIMS_16x16, OAM_X_FLIP, 0x58, 3, 0),
    OAM_ENTRY(-26, 12, OAM_DIMS_16x16, OAM_Y_FLIP, 0x58, 3, 0),
    OAM_ENTRY(-10, 12, OAM_DIMS_16x16, OAM_XY_FLIP, 0x58, 3, 0),
    OAM_ENTRY(8, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-20, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x56, 3, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_16x16, OAM_X_FLIP, 0x56, 3, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_16x16, OAM_Y_FLIP, 0x56, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_XY_FLIP, 0x56, 3, 0)
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame6[OAM_DATA_SIZE(21)] = {
    21,
    OAM_ENTRY(-20, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x58, 3, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_16x16, OAM_X_FLIP, 0x58, 3, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_16x16, OAM_Y_FLIP, 0x58, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_XY_FLIP, 0x58, 3, 0),
    OAM_ENTRY(-15, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x90, 3, 0),
    OAM_ENTRY(0, -27, OAM_DIMS_16x16, OAM_X_FLIP, 0x90, 3, 0),
    OAM_ENTRY(-15, -12, OAM_DIMS_16x16, OAM_Y_FLIP, 0x90, 3, 0),
    OAM_ENTRY(0, -12, OAM_DIMS_16x16, OAM_XY_FLIP, 0x90, 3, 0),
    OAM_ENTRY(-8, -32, OAM_DIMS_32x16, OAM_NO_FLIP, 0xd2, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x9a, 3, 0),
    OAM_ENTRY(8, 0, OAM_DIMS_32x16, OAM_XY_FLIP, 0xd2, 3, 0),
    OAM_ENTRY(24, -32, OAM_DIMS_16x32, OAM_XY_FLIP, 0x9a, 3, 0),
    OAM_ENTRY(-24, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-26, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x5a, 3, 0),
    OAM_ENTRY(-10, -4, OAM_DIMS_16x16, OAM_X_FLIP, 0x5a, 3, 0),
    OAM_ENTRY(-26, 12, OAM_DIMS_16x16, OAM_Y_FLIP, 0x5a, 3, 0),
    OAM_ENTRY(-10, 12, OAM_DIMS_16x16, OAM_XY_FLIP, 0x5a, 3, 0),
    OAM_ENTRY(5, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(20, -8, OAM_DIMS_8x16, OAM_X_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(5, 8, OAM_DIMS_8x8, OAM_Y_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(13, 7, OAM_DIMS_16x8, OAM_XY_FLIP, 0xd0, 3, 0)
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame7[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-20, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x5a, 3, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_16x16, OAM_X_FLIP, 0x5a, 3, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_16x16, OAM_Y_FLIP, 0x5a, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_XY_FLIP, 0x5a, 3, 0),
    OAM_ENTRY(-14, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x92, 3, 0),
    OAM_ENTRY(-2, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x92, 3, 0),
    OAM_ENTRY(-9, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1, 3, 0),
    OAM_ENTRY(-3, -44, OAM_DIMS_8x8, OAM_Y_FLIP, 0x1, 3, 0),
    OAM_ENTRY(-8, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x92, 3, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x92, 3, 0),
    OAM_ENTRY(-16, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0x92, 3, 0),
    OAM_ENTRY(-24, -11, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-26, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x5c, 3, 0),
    OAM_ENTRY(-10, -4, OAM_DIMS_16x16, OAM_X_FLIP, 0x5c, 3, 0),
    OAM_ENTRY(-26, 12, OAM_DIMS_16x16, OAM_Y_FLIP, 0x5c, 3, 0),
    OAM_ENTRY(-10, 12, OAM_DIMS_16x16, OAM_XY_FLIP, 0x5c, 3, 0),
    OAM_ENTRY(2, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(13, -13, OAM_DIMS_16x16, OAM_X_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(1, -3, OAM_DIMS_16x16, OAM_Y_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(12, -2, OAM_DIMS_16x16, OAM_XY_FLIP, 0xd0, 3, 0)
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame8[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-20, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x5c, 3, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_16x16, OAM_X_FLIP, 0x5c, 3, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_16x16, OAM_Y_FLIP, 0x5c, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_XY_FLIP, 0x5c, 3, 0),
    OAM_ENTRY(-12, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x92, 3, 0),
    OAM_ENTRY(-2, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x92, 3, 0),
    OAM_ENTRY(-9, -44, OAM_DIMS_8x8, OAM_Y_FLIP, 0x1, 3, 0),
    OAM_ENTRY(-2, -49, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1, 3, 0),
    OAM_ENTRY(-8, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x92, 3, 0),
    OAM_ENTRY(-14, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x94, 3, 0),
    OAM_ENTRY(3, -18, OAM_DIMS_16x16, OAM_XY_FLIP, 0x94, 3, 0),
    OAM_ENTRY(-26, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x5e, 3, 0),
    OAM_ENTRY(-10, -4, OAM_DIMS_16x16, OAM_X_FLIP, 0x5e, 3, 0),
    OAM_ENTRY(-26, 12, OAM_DIMS_16x16, OAM_Y_FLIP, 0x5e, 3, 0),
    OAM_ENTRY(-10, 12, OAM_DIMS_16x16, OAM_XY_FLIP, 0x5e, 3, 0),
    OAM_ENTRY(0, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(15, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(-1, -1, OAM_DIMS_16x16, OAM_Y_FLIP, 0xd0, 3, 0),
    OAM_ENTRY(14, 0, OAM_DIMS_16x16, OAM_XY_FLIP, 0xd0, 3, 0)
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame9[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-12, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1, 3, 0),
    OAM_ENTRY(2, -26, OAM_DIMS_8x8, OAM_Y_FLIP, 0x1, 3, 0),
    OAM_ENTRY(-8, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x94, 3, 0),
    OAM_ENTRY(0, -37, OAM_DIMS_16x16, OAM_X_FLIP, 0x94, 3, 0),
    OAM_ENTRY(-13, -33, OAM_DIMS_16x16, OAM_X_FLIP, 0x94, 3, 0),
    OAM_ENTRY(-8, -44, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(1, -52, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-24, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-24, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(2, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(10, -16, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(2, -12, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(2, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(15, -15, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-4, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0),
    OAM_ENTRY(5, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-20, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x5e, 3, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_16x16, OAM_X_FLIP, 0x5e, 3, 0),
    OAM_ENTRY(-20, -24, OAM_DIMS_16x16, OAM_Y_FLIP, 0x5e, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_XY_FLIP, 0x5e, 3, 0)
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame10[OAM_DATA_SIZE(19)] = {
    19,
    OAM_ENTRY(-8, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-3, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1, 3, 0),
    OAM_ENTRY(2, -36, OAM_DIMS_8x8, OAM_NO_FLIP, 0x1, 3, 0),
    OAM_ENTRY(-7, -33, OAM_DIMS_16x16, OAM_X_FLIP, 0x94, 3, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-16, -12, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-24, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-24, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(11, -22, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(9, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(6, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(14, -22, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(6, -18, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(15, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(23, -16, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(15, -12, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(15, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-4, -15, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(5, -7, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0)
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame11[OAM_DATA_SIZE(15)] = {
    15,
    OAM_ENTRY(-8, -43, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(4, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-7, -41, OAM_DIMS_16x16, OAM_XY_FLIP, 0x94, 3, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-16, -8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-24, -12, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-16, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-24, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(18, -24, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(20, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(15, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-4, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(5, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(5, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0)
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame12[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-4, -42, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(0, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-4, -23, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-21, -20, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-19, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-24, -23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(18, -31, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(20, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(4, -12, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(4, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-4, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(13, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(5, -10, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0)
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame13[OAM_DATA_SIZE(11)] = {
    11,
    OAM_ENTRY(-4, -47, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-19, -22, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-21, -14, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-24, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-16, -22, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-2, -27, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-5, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(9, -19, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(7, -11, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0)
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame14[OAM_DATA_SIZE(7)] = {
    7,
    OAM_ENTRY(-21, -27, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-19, -19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(1, -31, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-1, -23, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-4, -35, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(4, -31, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-4, -27, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0)
};

static const u16 sChozodiaEscapeOam_47b914[OAM_DATA_SIZE(23)] = {
    23,
    OAM_ENTRY(32, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-82, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-74, 9, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-82, 13, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-82, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-69, 10, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-88, 13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-79, 21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0),
    OAM_ENTRY(73, -37, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(75, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(70, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(83, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(83, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(64, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0),
    OAM_ENTRY(73, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-23, -54, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-21, -46, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-5, -35, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-13, -39, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-5, -43, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-13, -50, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-32, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-23, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0)
};

static const u16 sChozodiaEscapeOam_47b9a0[OAM_DATA_SIZE(26)] = {
    26,
    OAM_ENTRY(32, -48, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-74, 13, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-82, 9, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-74, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-82, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-69, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-88, 13, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-79, 21, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0),
    OAM_ENTRY(75, -40, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(73, -32, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(70, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(78, -40, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(70, -36, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(83, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(91, -30, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(83, -26, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(83, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(64, -29, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(73, -21, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-10, -46, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-8, -38, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-13, -49, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-32, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-32, -46, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-23, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-23, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0)
};

static const u16 sChozodiaEscapeOam_47ba3e[OAM_DATA_SIZE(26)] = {
    26,
    OAM_ENTRY(32, -49, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-79, 1, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-77, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-82, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-69, 7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-69, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-88, 11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-79, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0),
    OAM_ENTRY(73, -45, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(75, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(91, -26, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(83, -30, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(91, -34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(83, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(64, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(73, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-8, -46, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-10, -38, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-13, -50, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-5, -46, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-13, -42, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-32, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-26, -36, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-32, -32, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-32, -45, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-23, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0)
};

static const u16 sChozodiaEscapeOam_47badc[OAM_DATA_SIZE(34)] = {
    34,
    OAM_ENTRY(32, -50, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-77, -2, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-79, 6, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-82, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-74, -2, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-82, 2, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-69, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-61, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-69, 12, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-69, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-88, 9, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-79, 17, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(86, -38, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(88, -30, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(83, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(64, -32, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(64, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(73, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(73, -30, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-10, -50, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-8, -42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-24, -31, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-32, -35, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-24, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-32, -46, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-15, -33, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-23, -29, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(46, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(54, 9, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(46, 13, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(46, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(59, 10, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(40, 13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0),
    OAM_ENTRY(49, 21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_47bbaa[OAM_DATA_SIZE(31)] = {
    31,
    OAM_ENTRY(32, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-79, -11, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-77, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-61, 8, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-69, 4, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-61, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-69, -7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-88, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-79, 12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(88, -35, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(86, -27, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(83, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(91, -35, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(83, -31, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(64, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(70, -25, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(64, -21, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(64, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(73, -25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-29, -45, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-27, -37, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-32, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-18, -37, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-20, -29, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(54, 13, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(46, 9, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(54, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(46, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(59, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(40, 13, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0),
    OAM_ENTRY(49, 21, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_47bc66[OAM_DATA_SIZE(29)] = {
    29,
    OAM_ENTRY(32, -54, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(32, -60, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-66, -5, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-64, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-69, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-88, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-88, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-79, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-79, 3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(86, -40, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(88, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(72, -21, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(64, -25, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(72, -29, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(64, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(81, -23, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(73, -19, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-27, -46, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-29, -38, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-32, -50, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-24, -46, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-32, -42, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(49, 1, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(51, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(46, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(59, 7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(59, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(40, 11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0),
    OAM_ENTRY(49, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0)
};

static const u16 sChozodiaEscapeOam_47bd16[OAM_DATA_SIZE(32)] = {
    32,
    OAM_ENTRY(32, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(40, -52, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(32, -48, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(32, -61, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-64, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-66, 4, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-69, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-61, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-69, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-88, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-82, 6, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-88, 10, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-88, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-79, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(67, -34, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(69, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(64, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(78, -26, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(76, -18, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-32, -48, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-30, -40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(51, -1, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(49, 7, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(46, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(54, -1, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(46, 3, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(59, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(67, 9, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(59, 13, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(59, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(40, 10, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(49, 18, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0)
};

static const u16 sChozodiaEscapeOam_47bdd8[OAM_DATA_SIZE(32)] = {
    32,
    OAM_ENTRY(40, -49, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(32, -53, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(40, -57, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(32, -64, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-66, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-64, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-80, 11, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-88, 7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-80, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-88, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-71, 9, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-79, 13, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(69, -35, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(67, -27, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(64, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(72, -35, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(64, -31, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(49, -6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(51, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(67, 13, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(59, 9, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(67, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(59, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(40, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(49, 17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-26, -43, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-18, -39, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-26, -35, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-26, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-13, -38, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-32, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-23, -27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_47be9a[OAM_DATA_SIZE(24)] = {
    24,
    OAM_ENTRY(35, -53, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(37, -45, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(32, -56, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-85, -5, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-83, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-88, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-74, 3, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-76, 11, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(64, -36, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(66, -28, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(62, 1, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(64, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(59, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(40, 7, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(40, 1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(49, 15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(49, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-18, -36, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-26, -40, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-18, -44, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-26, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-13, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-32, -36, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-23, -28, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_47bf2c[OAM_DATA_SIZE(27)] = {
    27,
    OAM_ENTRY(37, -61, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(35, -53, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(32, -65, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(40, -61, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(32, -57, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-75, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-77, 4, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-80, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-72, -4, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-80, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(64, 3, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(62, 11, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(59, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(67, 3, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(59, 7, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(40, 9, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(46, 13, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(40, 17, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(40, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(49, 13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-23, -47, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-21, -39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-26, -50, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-13, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-13, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-32, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-23, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0)
};

static const u16 sChozodiaEscapeOam_47bfd0[OAM_DATA_SIZE(23)] = {
    23,
    OAM_ENTRY(35, -60, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(37, -52, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-72, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-70, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(62, -4, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(64, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(48, 15, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(40, 11, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(48, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(40, 0, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(57, 13, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(49, 17, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-21, -49, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-23, -41, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-26, -53, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-18, -49, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-26, -45, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-13, -43, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-5, -39, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-13, -35, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-13, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-32, -38, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-23, -30, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0)
};

static const u16 sChozodiaEscapeOam_47c05c[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-80, -72, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-72, -69, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0),
    OAM_ENTRY(80, 24, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(88, 27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-10, 45, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-2, 49, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-10, 53, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-10, 40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-2, 50, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-16, 53, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_47c09a[OAM_DATA_SIZE(10)] = {
    10,
    OAM_ENTRY(-80, -73, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-72, -69, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0),
    OAM_ENTRY(80, 23, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(88, 27, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-2, 54, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-10, 50, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-2, 46, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-10, 39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-2, 50, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-16, 54, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_47c0d8[OAM_DATA_SIZE(14)] = {
    14,
    OAM_ENTRY(-80, -75, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-80, -81, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-72, -71, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0),
    OAM_ENTRY(80, 21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(80, 15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(88, 25, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-7, 42, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-5, 50, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-10, 39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-2, 48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-2, 42, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-16, 52, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0),
    OAM_ENTRY(24, -48, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(32, -45, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_47c12e[OAM_DATA_SIZE(26)] = {
    26,
    OAM_ENTRY(-80, -78, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-72, -74, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-80, -70, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-80, -83, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-72, -73, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-86, -70, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0),
    OAM_ENTRY(80, 19, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(88, 23, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(80, 27, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(80, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(88, 24, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(74, 27, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-5, 37, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-7, 45, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-10, 33, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-2, 37, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-10, 41, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-2, 43, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(6, 47, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-2, 51, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-2, 38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-16, 48, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(24, -50, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(32, -46, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-40, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-32, 11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_47c1cc[OAM_DATA_SIZE(24)] = {
    24,
    OAM_ENTRY(-72, -70, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-80, -74, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-72, -78, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-80, -85, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-72, -74, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-86, -70, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0),
    OAM_ENTRY(88, 26, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(80, 22, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(88, 18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(80, 11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(88, 22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(74, 26, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-7, 32, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-5, 40, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(6, 51, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-2, 47, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(6, 43, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-2, 36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-16, 47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(24, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(24, -57, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(32, -47, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-40, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-32, 10, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_47c25e[OAM_DATA_SIZE(26)] = {
    26,
    OAM_ENTRY(-77, -82, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-75, -74, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-80, -85, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-72, -76, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-72, -82, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-86, -72, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0),
    OAM_ENTRY(83, 14, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(85, 22, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(80, 11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(88, 20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(88, 14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(74, 24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0),
    OAM_ENTRY(1, 40, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(3, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-2, 37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-16, 46, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-16, 40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(24, -53, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(32, -49, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(24, -45, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(24, -58, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(32, -48, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(18, -45, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-40, 4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-40, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-32, 8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0)
};

static const u16 sChozodiaEscapeOam_47c2fc[OAM_DATA_SIZE(41)] = {
    41,
    OAM_ENTRY(-75, -84, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-77, -76, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-80, -88, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-72, -84, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-80, -80, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-72, -78, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-64, -74, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-72, -70, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-72, -83, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-86, -73, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(85, 12, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(83, 20, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(80, 8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(88, 12, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(80, 16, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(88, 18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(96, 22, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(88, 26, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(88, 13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(74, 23, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(3, 38, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(1, 46, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-2, 34, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(6, 38, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-2, 42, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-16, 44, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-10, 48, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-16, 52, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-16, 39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(32, -46, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(24, -50, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(32, -54, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(24, -61, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(32, -50, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(18, -46, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0),
    OAM_ENTRY(-40, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-32, 6, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-40, 10, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-40, -3, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-32, 7, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-46, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_47c3f4[OAM_DATA_SIZE(32)] = {
    32,
    OAM_ENTRY(-77, -89, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-75, -81, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-64, -70, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-72, -74, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-64, -78, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-72, -85, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-86, -74, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(83, 7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(85, 15, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(96, 26, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(88, 22, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(96, 18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(88, 11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(74, 22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(1, 31, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(3, 39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-8, 50, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-16, 46, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-8, 42, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-16, 35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(27, -58, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(29, -50, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(24, -61, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(32, -52, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(32, -58, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(18, -48, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-32, 10, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-40, 6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-32, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-40, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-32, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-46, 10, OAM_DIMS_16x16, OAM_XY_FLIP, 0x40, 3, 0)
};

static const u16 sChozodiaEscapeOam_47c4b6[OAM_DATA_SIZE(29)] = {
    29,
    OAM_ENTRY(-69, -83, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-67, -75, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-72, -86, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-86, -77, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-86, -83, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(91, 13, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(93, 21, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(88, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(74, 19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(74, 13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-11, 40, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-9, 48, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-14, 37, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(29, -60, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(27, -52, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(24, -64, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(32, -60, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(24, -56, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(32, -54, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(40, -50, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(32, -46, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(32, -59, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(18, -49, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0),
    OAM_ENTRY(-37, -1, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-35, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-40, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-32, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-32, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-46, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 3, 0)
};

static const u16 sChozodiaEscapeOam_47c566[OAM_DATA_SIZE(40)] = {
    40,
    OAM_ENTRY(-67, -85, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-69, -77, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-72, -89, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-64, -85, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-72, -81, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-86, -79, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-80, -75, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-86, -71, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-86, -84, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(93, 11, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(91, 19, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(88, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(96, 11, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(88, 15, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(74, 17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(80, 21, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(74, 25, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(74, 12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-9, 39, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-11, 47, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-14, 35, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-6, 39, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-14, 43, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(27, -66, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(29, -58, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(40, -47, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(32, -51, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(40, -55, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(32, -62, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(18, -51, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0),
    OAM_ENTRY(-35, -3, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-37, 5, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-40, -7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-32, -3, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-40, 1, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-32, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-24, 7, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-32, 11, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-32, -2, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-46, 8, OAM_DIMS_16x16, OAM_XY_FLIP, 0x42, 3, 0)
};

static const u16 sChozodiaEscapeOam_47c658[OAM_DATA_SIZE(26)] = {
    26,
    OAM_ENTRY(-69, -90, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-67, -82, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-78, -71, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-86, -75, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-78, -79, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-86, -86, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(91, 6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(93, 14, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(82, 25, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(74, 21, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(82, 17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(74, 10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-10, 31, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-8, 39, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(35, -58, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(37, -50, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(32, -61, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(18, -52, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(18, -58, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0),
    OAM_ENTRY(-37, -9, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-35, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-24, 10, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-32, 6, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-24, 2, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-32, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-46, 6, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 3, 0)
};

static const u16 sChozodiaEscapeOam_47c6f6[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-83, -84, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-81, -76, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-86, -87, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(77, 12, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(79, 20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(74, 9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(38, -61, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(36, -53, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(33, -65, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(41, -61, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(33, -57, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(19, -55, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(25, -51, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(19, -47, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(19, -60, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0),
    OAM_ENTRY(-29, -1, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-27, 7, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-46, 5, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 3, 0),
    OAM_ENTRY(-46, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x40, 4, 0)
};

static const u16 sChozodiaEscapeOam_47c770[OAM_DATA_SIZE(25)] = {
    25,
    OAM_ENTRY(-80, -86, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-82, -78, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-85, -90, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-77, -86, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-85, -82, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(79, 9, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(77, 17, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(74, 5, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(82, 9, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(74, 13, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(36, -67, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(38, -59, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(27, -48, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(19, -52, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(27, -56, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(19, -63, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0),
    OAM_ENTRY(-27, -2, OAM_DIMS_8x8, OAM_XY_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-29, 6, OAM_DIMS_8x8, OAM_X_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(-32, -6, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-24, -2, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-32, 2, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 4, 0),
    OAM_ENTRY(-46, 4, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-40, 8, OAM_DIMS_8x8, OAM_X_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-46, 12, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-46, -1, OAM_DIMS_16x16, OAM_NO_FLIP, 0x42, 4, 0)
};

static const u16 sChozodiaEscapeOam_47c808[OAM_DATA_SIZE(13)] = {
    13,
    OAM_ENTRY(-83, -92, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-81, -84, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(77, 5, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(79, 13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(23, -63, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(25, -55, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 3, 0),
    OAM_ENTRY(20, -66, OAM_DIMS_16x16, OAM_NO_FLIP, 0x46, 4, 0),
    OAM_ENTRY(-29, -8, OAM_DIMS_8x8, OAM_Y_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-27, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 0x4d, 4, 0),
    OAM_ENTRY(-38, 11, OAM_DIMS_8x8, OAM_XY_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-46, 7, OAM_DIMS_8x8, OAM_Y_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-38, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 0x47, 3, 0),
    OAM_ENTRY(-46, -4, OAM_DIMS_16x16, OAM_NO_FLIP, 0x44, 4, 0)
};

static const u16 sChozodiaEscapeOam_MotherShipDecaying_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x100, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x104, 1, 0)
};

static const u16 sChozodiaEscapeOam_47c866[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x106, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x10a, 1, 0)
};

static const u16 sChozodiaEscapeOam_47c874[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x10c, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x110, 1, 0)
};

static const u16 sChozodiaEscapeOam_47c882[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x112, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x116, 1, 0)
};

static const u16 sChozodiaEscapeOam_MotherShipDecaying_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x180, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x184, 1, 0)
};

static const u16 sChozodiaEscapeOam_MotherShipDecaying_Frame2[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x186, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x18a, 1, 0)
};

static const u16 sChozodiaEscapeOam_MotherShipDecaying_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x18c, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x190, 1, 0)
};

static const u16 sChozodiaEscapeOam_MotherShipDecaying_Frame4[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x192, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x196, 1, 0)
};

static const u16 sChozodiaEscapeOam_MotherShipDecaying_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x198, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x19c, 1, 0)
};

static const u16 sChozodiaEscapeOam_MotherShipDecaying_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x10c, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x110, 1, 0)
};

static const u16 sChozodiaEscapeOam_MotherShipDecaying_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-24, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 0x112, 1, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x32, OAM_NO_FLIP, 0x116, 1, 0)
};

const struct FrameData sChozodiaEscapeOam_ShipSmokeExplosion[8] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeExplosion_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeExplosion_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeExplosion_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeExplosion_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeExplosion_Frame4,
        .timer = 3
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeExplosion_Frame5,
        .timer = 3
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeExplosion_Frame6,
        .timer = 4
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_ShipSmokeSmallExplosion[7] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame5,
        .timer = 4
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_ShipSmokeSmallWideExplosion[10] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame4,
        .timer = 3
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame5,
        .timer = 3
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame6,
        .timer = 3
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame7,
        .timer = 3
    },
    [8] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame8,
        .timer = 3
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_ShipSmokeWideExplosion[11] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame7,
        .timer = 4
    },
    [8] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame8,
        .timer = 4
    },
    [9] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame9,
        .timer = 4
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_SmallExplosion[12] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame7,
        .timer = 2
    },
    [8] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame8,
        .timer = 2
    },
    [9] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame9,
        .timer = 2
    },
    [10] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame10,
        .timer = 2
    },
    [11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_MediumExplosion[18] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame5,
        .timer = 1
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame6,
        .timer = 1
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame7,
        .timer = 2
    },
    [8] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame8,
        .timer = 2
    },
    [9] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame9,
        .timer = 2
    },
    [10] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame10,
        .timer = 2
    },
    [11] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame11,
        .timer = 2
    },
    [12] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame12,
        .timer = 2
    },
    [13] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame13,
        .timer = 2
    },
    [14] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame14,
        .timer = 2
    },
    [15] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame15,
        .timer = 2
    },
    [16] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame16,
        .timer = 2
    },
    [17] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_MediumExplosion2[15] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame5,
        .timer = 1
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame7,
        .timer = 2
    },
    [8] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame8,
        .timer = 2
    },
    [9] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame9,
        .timer = 2
    },
    [10] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame10,
        .timer = 2
    },
    [11] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame11,
        .timer = 2
    },
    [12] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame12,
        .timer = 2
    },
    [13] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame13,
        .timer = 2
    },
    [14] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_HugeExplosion[13] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_HugeExplosion_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame3,
        .timer = 1
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame4,
        .timer = 1
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame5,
        .timer = 1
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame6,
        .timer = 1
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame7,
        .timer = 2
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame8,
        .timer = 2
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame9,
        .timer = 2
    },
    [8] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame10,
        .timer = 2
    },
    [9] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame11,
        .timer = 2
    },
    [10] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame12,
        .timer = 2
    },
    [11] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame13,
        .timer = 2
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTourianEscapeOam_HugeShipExplosion[16] = {
    [0] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame5,
        .timer = 3
    },
    [6] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame6,
        .timer = 3
    },
    [7] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame7,
        .timer = 3
    },
    [8] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame8,
        .timer = 3
    },
    [9] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame9,
        .timer = 3
    },
    [10] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame10,
        .timer = 3
    },
    [11] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame11,
        .timer = 3
    },
    [12] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame12,
        .timer = 3
    },
    [13] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame13,
        .timer = 3
    },
    [14] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame14,
        .timer = 3
    },
    [15] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_47cc64[11] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_47b9a0,
        .timer = 2
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_47ba3e,
        .timer = 2
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_47badc,
        .timer = 2
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_47bbaa,
        .timer = 2
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_47bc66,
        .timer = 2
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_47bd16,
        .timer = 3
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_47bdd8,
        .timer = 3
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_47be9a,
        .timer = 3
    },
    [8] = {
        .pFrame = sChozodiaEscapeOam_47bf2c,
        .timer = 3
    },
    [9] = {
        .pFrame = sChozodiaEscapeOam_47bfd0,
        .timer = 3
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_47ccbc[15] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_47c05c,
        .timer = 4
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_47c09a,
        .timer = 4
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_47c0d8,
        .timer = 4
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_47c12e,
        .timer = 4
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_47c1cc,
        .timer = 4
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_47c25e,
        .timer = 4
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_47c2fc,
        .timer = 4
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_47c3f4,
        .timer = 4
    },
    [8] = {
        .pFrame = sChozodiaEscapeOam_47c4b6,
        .timer = 4
    },
    [9] = {
        .pFrame = sChozodiaEscapeOam_47c566,
        .timer = 4
    },
    [10] = {
        .pFrame = sChozodiaEscapeOam_47c658,
        .timer = 4
    },
    [11] = {
        .pFrame = sChozodiaEscapeOam_47c6f6,
        .timer = 4
    },
    [12] = {
        .pFrame = sChozodiaEscapeOam_47c770,
        .timer = 4
    },
    [13] = {
        .pFrame = sChozodiaEscapeOam_47c808,
        .timer = 4
    },
    [14] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_MotherShipDecaying[9] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_MotherShipDecaying_Frame0,
        .timer = 64
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_MotherShipDecaying_Frame1,
        .timer = 16
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_MotherShipDecaying_Frame2,
        .timer = 16
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_MotherShipDecaying_Frame3,
        .timer = 16
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_MotherShipDecaying_Frame4,
        .timer = 16
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_MotherShipDecaying_Frame5,
        .timer = 16
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_MotherShipDecaying_Frame6,
        .timer = 16
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_MotherShipDecaying_Frame7,
        .timer = 120
    },
    [8] = FRAME_DATA_TERMINATOR
};

const u32 sTourianEscapeDebrisGfx[25] = INCBIN_U32("data/tourian_escape/debris.gfx.lz");

static const u16 sTourianEscape_47cde0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x180, 1, 0)
};

static const u16 sTourianEscape_47cde8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x181, 1, 0)
};

static const u16 sTourianEscape_47cdf0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x182, 1, 0)
};

static const u16 sTourianEscape_47cdf8[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 0x183, 1, 0)
};

// OAM Frame Pointers
const u16* const sTourianEscape_47ce00[4] = {
    [0] = sTourianEscape_47a682,
    [1] = sTourianEscape_47a68a,
    [2] = sTourianEscape_47a692,
    [3] = sTourianEscape_47a69a
};

// OAM Frame Pointers
const u16* const sTourianEscape_47ce10[4] = {
    [0] = sTourianEscape_47a6a2,
    [1] = sTourianEscape_47a6aa,
    [2] = sTourianEscape_47a6b2,
    [3] = sTourianEscape_47a6ba
};

// (x, y) and speed?
const u16 sTourianEscape_47ce20[TOURIAN_ESCAPE_MAX_OBJECTS][3] = {
    [0] = {
        [0] = QUARTER_BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [2] = 1
    },
    [1] = {
        [0] = BLOCK_SIZE * 2,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE,
        [2] = 1
    },
    [2] = {
        [0] = BLOCK_SIZE * 3,
        [1] = BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE,
        [2] = 2
    },
    [3] = {
        [0] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE,
        [2] = 1
    },
    [4] = {
        [0] = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        [2] = 1
    },
    [5] = {
        [0] = BLOCK_SIZE,
        [1] = BLOCK_SIZE - EIGHTH_BLOCK_SIZE,
        [2] = 2
    },
    [6] = {
        [0] = BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE,
        [2] = 1
    },
    [7] = {
        [0] = BLOCK_SIZE + QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [2] = 1
    },
    [8] = {
        [0] = HALF_BLOCK_SIZE,
        [1] = QUARTER_BLOCK_SIZE,
        [2] = 2
    },
    [9] = {
        [0] = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE + HALF_BLOCK_SIZE,
        [2] = 1
    }
};

// unused, (x, y) and speed?
static const u16 sTourianEscape_47ce5c[6][3] = {
    [0] = {
        [0] = BLOCK_SIZE + HALF_BLOCK_SIZE,
        [1] = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        [2] = 1
    },
    [1] = {
        [0] = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE - EIGHTH_BLOCK_SIZE,
        [2] = 2
    },
    [2] = {
        [0] = BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [2] = 1
    },
    [3] = {
        [0] = BLOCK_SIZE - EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE,
        [2] = 1
    },
    [4] = {
        [0] = BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [2] = 2
    },
    [5] = {
        [0] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE,
        [2] = 1
    }
};

// OAM X Positions
const u16 sTourianEscape_47ce80[8] = {
    [0] = 2,
    [1] = 3,
    [2] = 4,
    [3] = 5,
    [4] = 6,
    [5] = 7,
    [6] = 8,
    [7] = 9
};

// OAM Y Positions
const u16 sTourianEscape_47ce90[8] = {
    [0] = 2,
    [1] = 2,
    [2] = 2,
    [3] = 1,
    [4] = 1,
    [5] = 1,
    [6] = 0,
    [7] = 0
};

// OAM Frame Pointers
const u16* const sTourianEscape_47cea0[8] = {
    [0] = sTourianEscape_47a998,
    [1] = sTourianEscape_47a998,
    [2] = sTourianEscape_47a9a0,
    [3] = sTourianEscape_47a9a0,
    [4] = sTourianEscape_47a9a8,
    [5] = sTourianEscape_47a9a8,
    [6] = sTourianEscape_47a9a8,
    [7] = sTourianEscape_47a9a8
};

// OAM Frame Pointers
const u16* const sTourianEscape_47cec0[4] = {
    [0] = sTourianEscape_47cde0,
    [1] = sTourianEscape_47cde8,
    [2] = sTourianEscape_47cdf0,
    [3] = sTourianEscape_47cdf8
};

// Object 0 (x, y) OAM Positions, Zebes Exploding
const u16 sTourianEscape_47ced0[8][2] = {
    [0] = {
        [0] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2
    },
    [1] = {
        [0] = BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [2] = {
        [0] = BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [3] = {
        [0] = BLOCK_SIZE * 2,
        [1] = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE
    },
    [4] = {
        [0] = BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [5] = {
        [0] = THREE_QUARTER_BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE
    },
    [6] = {
        [0] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE + HALF_BLOCK_SIZE
    },
    [7] = {
        [0] = BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE - EIGHTH_BLOCK_SIZE
    }
};

// Object 1 (x, y) OAM Positions, Zebes Exploding
const u16 sTourianEscape_47cef0[8][2] = {
    [0] = {
        [0] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE
    },
    [1] = {
        [0] = THREE_QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE
    },
    [2] = {
        [0] = BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE
    },
    [3] = {
        [0] = BLOCK_SIZE * 3,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE
    },
    [4] = {
        [0] = BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [5] = {
        [0] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [6] = {
        [0] = BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE
    },
    [7] = {
        [0] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE - QUARTER_BLOCK_SIZE
    }
};

// Object 2 (x, y) OAM Positions, Zebes Exploding
const u16 sTourianEscape_47cf10[8][2] = {
    [0] = {
        [0] = BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [1] = {
        [0] = BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [2] = {
        [0] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE
    },
    [3] = {
        [0] = BLOCK_SIZE * 3,
        [1] = BLOCK_SIZE - QUARTER_BLOCK_SIZE
    },
    [4] = {
        [0] = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [5] = {
        [0] = BLOCK_SIZE - EIGHTH_BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE
    },
    [6] = {
        [0] = BLOCK_SIZE + QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE
    },
    [7] = {
        [0] = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE
    }
};

// Object 3 (x, y) OAM Positions, Zebes Exploding
const u16 sTourianEscape_47cf30[8][2] = {
    [0] = {
        [0] = BLOCK_SIZE * 2,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE
    },
    [1] = {
        [0] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [2] = {
        [0] = BLOCK_SIZE + QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2
    },
    [3] = {
        [0] = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE - QUARTER_BLOCK_SIZE
    },
    [4] = {
        [0] = BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [5] = {
        [0] = BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE
    },
    [6] = {
        [0] = BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE
    },
    [7] = {
        [0] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    }
};

// Objects 4-8 (x, y) OAM Positions, Zebes Exploding
const u16 sTourianEscape_47cf50[8][2] = {
    [0] = {
        [0] = BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 4 - EIGHTH_BLOCK_SIZE
    },
    [1] = {
        [0] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = PIXEL_SIZE
    },
    [2] = {
        [0] = BLOCK_SIZE + QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE
    },
    [3] = {
        [0] = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        [1] = PIXEL_SIZE + PIXEL_SIZE / 2
    },
    [4] = {
        [0] = BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 4 - PIXEL_SIZE / 2
    },
    [5] = {
        [0] = BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = PIXEL_SIZE / 2
    },
    [6] = {
        [0] = BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE,
        [1] = 0
    },
    [7] = {
        [0] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = EIGHTH_BLOCK_SIZE
    }
};

// OAM Frame Pointers
const u16* const sTourianEscape_47cf70[6] = {
    [0] = sTourianEscape_47a6c2,
    [1] = sTourianEscape_47a6dc,
    [2] = sTourianEscape_47a6f6,
    [3] = sTourianEscape_47a710,
    [4] = sTourianEscape_47a72a,
    [5] = sTourianEscape_47a744
};

// OAM Frame Pointers
const u16* const sTourianEscape_47cf88[7] = {
    [0] = sTourianEscape_47a75e,
    [1] = sTourianEscape_47a778,
    [2] = sTourianEscape_47a7aa,
    [3] = sTourianEscape_47a7e8,
    [4] = sTourianEscape_47a832,
    [5] = sTourianEscape_47a888,
    [6] = sTourianEscape_47a8cc
};

// Speeds?
const u16 sTourianEscape_47cfa4[8] = {
    -0x5A, 0x78, -0x78, 0x5A,
    -0x32, 0x46, -0x32, 0x28
};

// Speeds?
const u16 sTourianEscape_47cfb4[8] = {
    -0x1B, 0xC, 0x24, -0x1B,
    -0x19, 0x15, 0x14, -0x10
};

// Speeds?
const u16 sTourianEscape_47cfc4[8] = {
    0xA, -0xA, 0xA, -0xA,
    0xA, -0xA, 0xA, -0xA
};

// Speeds?
const u16 sTourianEscape_47cfd4[8] = {
    0x3, -0x1, -0x3, 0x3,
    0x5, -0x3, -0x4, 0x4
};

// OAM Frame Pointers
const u16* const sTourianEscape_47cfe4[4] = {
    [0] = sTourianEscape_47a9b0,
    [1] = sTourianEscape_47a9dc,
    [2] = sTourianEscape_47aa1a,
    [3] = sTourianEscape_47aa5e
};

// OAM Timers
const u8 sTourianEscape_47cff4[TOURIAN_ESCAPE_MAX_OBJECTS] = {
    [0] = 0,
    [1] = 8,
    [2] = 20,
    [3] = 0,
    [4] = 10,
    [5] = 8,
    [6] = 0,
    [7] = 24,
    [8] = 8,
    [9] = 22
};

// OAM X Positions
const u16 sTourianEscape_47cffe[TOURIAN_ESCAPE_MAX_OBJECTS] = {
    [0] = QUARTER_BLOCK_SIZE,
    [1] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
    [2] = BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
    [3] = BLOCK_SIZE + HALF_BLOCK_SIZE,
    [4] = BLOCK_SIZE * 2,
    [5] = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
    [6] = BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE,
    [7] = BLOCK_SIZE * 3 + EIGHTH_BLOCK_SIZE,
    [8] = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE,
    [9] = BLOCK_SIZE * 4 - EIGHTH_BLOCK_SIZE
};


const u32 sMotherShipExplodingFlashGfx[2588] = INCBIN_U32("data/tourian_escape/mother_ship_exploding_flash.gfx.lz");
const u32 sMotherShipExplodingFlashTileTable[561] = INCBIN_U32("data/tourian_escape/mother_ship_exploding_flash.tt");
const u32 sMotherShipBlowingUpExplosionsGfx[1761] = INCBIN_U32("data/tourian_escape/mother_ship_blowing_up_explosions.gfx.lz");

const u32 sTourianEscapeSamusInHerShipSuitGfx[3108] = INCBIN_U32("data/tourian_escape/samus_in_her_ship_suit.gfx.lz");
const u32 sTourianEscapeSamusInHerShipSuitTileTable[368] = INCBIN_U32("data/tourian_escape/samus_in_her_ship_suit.tt");
const u32 sTourianEscapeSamusInHerShipSuitlessGfx[4280] = INCBIN_U32("data/tourian_escape/samus_in_her_ship_suitless.gfx.lz");
const u32 sTourianEscapeSamusInHerShipSuitlessTileTable[368] = INCBIN_U32("data/tourian_escape/samus_in_her_ship_suitless.tt");
const u32 sTourianEscapeSamusInHerShipSuitlessEyesOpenedTileTable[368] = INCBIN_U32("data/tourian_escape/samus_in_her_ship_suitless_eyes_opened.tt");

const u32 sTourianEscapeZebesGfx[3442] = INCBIN_U32("data/tourian_escape/zebes.gfx.lz");
const u32 sTourianEscapeZebesTileTable[577] = INCBIN_U32("data/tourian_escape/zebes.tt");

const u32 sTourianEscapeZebesExplodingShipAndExplosionsGfx[1297] = INCBIN_U32("data/tourian_escape/zebes_exploding_ship_and_explosions.gfx.lz");

const u32 sTourianEscapeSamusChasedBackgroundGfx[5470] = INCBIN_U32("data/tourian_escape/samus_chased_background.gfx.lz");
const u32 sTourianEscapeSamusChasedBackgroundTileTable[577] = INCBIN_U32("data/tourian_escape/samus_chased_background.tt");
const u32 sTourianEscapeSamusSurroundedBackgroundGfx[2337] = INCBIN_U32("data/tourian_escape/samus_surrounded_background.gfx.lz");
const u32 sTourianEscapeSamusSurroundedBackgroundTileTable[551] = INCBIN_U32("data/tourian_escape/samus_surrounded_background.tt");

const u32 sTourianEscapeSamusSamusInHerShipLookingGfx[4090] = INCBIN_U32("data/tourian_escape/samus_samus_in_her_ship_looking.gfx.lz");
const u32 sTourianEscapeSamusSamusInHerShipLookingLeftTileTable[368] = INCBIN_U32("data/tourian_escape/samus_samus_in_her_ship_looking_left.tt");
const u32 sTourianEscapeSamusSamusInHerShipLookingRightTileTable[368] = INCBIN_U32("data/tourian_escape/samus_samus_in_her_ship_looking_right.tt");

const u32 sTourianEscape_49cb90[3064] = INCBIN_U32("data/tourian_escape/49cb90.gfx.lz");
const u32 sTourianEscape_49fb70[113] = INCBIN_U32("data/tourian_escape/49fb70.tt");

const u32 sTourianEscapeSamusSamusChasedShipsGfx[2507] = INCBIN_U32("data/tourian_escape/samus_samus_chased_ships.gfx.lz");
const u32 sTourianEscapeShipsAndProjectilesGfx[1461] = INCBIN_U32("data/tourian_escape/ships_and_projectiles.gfx.lz");

const u32 sTourianEscapeSamusGettingShotShipGfx[563] = INCBIN_U32("data/tourian_escape/samus_getting_shot_ship.gfx.lz");
const u32 sTourianEscapeSamusGettingShotGfx[2999] = INCBIN_U32("data/tourian_escape/samus_getting_shot.gfx.lz");
const u32 sTourianEscapeSamusGettingShotTileTable[566] = INCBIN_U32("data/tourian_escape/samus_getting_shot.tt");

const u32 sTourianEscapeShipCrashingBackgroundAndShipGfx[3251] = INCBIN_U32("data/tourian_escape/ship_crashing_background_and_ship.gfx.lz");
const u32 sTourianEscapeShipCrashingForegroundGfx[1914] = INCBIN_U32("data/tourian_escape/ship_crashing_foreground.gfx.lz");
const u32 sTourianEscapeShipCrashingForegroundTileTable[577] = INCBIN_U32("data/tourian_escape/ship_crashing_foreground.tt");
const u32 sTourianEscapeShipGoingToCrashGfx[1219] = INCBIN_U32("data/tourian_escape/ship_going_to_crash.gfx.lz");

const u32 sTourianEscapeShipCrashingExplosionGfx[1826] = INCBIN_U32("data/tourian_escape/ship_crashing_explosion.gfx.lz");
const u32 sTourianEscapeShipCrashingExplosionTileTable[577] = INCBIN_U32("data/tourian_escape/ship_crashing_explosion.tt");

const u32 sTourianEscapeSamusLookingAtSkyPiratesShipGfx[867] = INCBIN_U32("data/tourian_escape/samus_looking_at_sky_pirates_ship.gfx.lz");
const u32 sTourianEscapeSamusLookingAtSkySkyBackgroundGfx[3056] = INCBIN_U32("data/tourian_escape/samus_looking_at_sky_sky_background.gfx.lz");
const u32 sTourianEscapeSamusLookingAtSkySkyBackgroundTileTable[399] = INCBIN_U32("data/tourian_escape/samus_looking_at_sky_sky_background.tt");
const u32 sTourianEscapeSamusLookingAtSkyGfx[4060] = INCBIN_U32("data/tourian_escape/samus_looking_at_sky.gfx.lz");
const u32 sTourianEscapeSamusLookingAtSkyTopTileTable[430] = INCBIN_U32("data/tourian_escape/samus_looking_at_sky_top.tt");
const u32 sTourianEscapeSamusLookingAtSkyBottomTileTable[185] = INCBIN_U32("data/tourian_escape/samus_looking_at_sky_bottom.tt");

const u32 sTourianEscapeSamusLookingAtMotherShipGfx[2153] = INCBIN_U32("data/tourian_escape/samus_looking_at_mother_ship.gfx.lz");
const u32 sTourianEscapeSamusLookingAtMotherShipTileTable[577] = INCBIN_U32("data/tourian_escape/samus_looking_at_mother_ship.tt");
const u32 sTourianEscapeSamusLookingAtMotherShipMotherShipGfx[3112] = INCBIN_U32("data/tourian_escape/samus_looking_at_mother_ship_mother_ship.gfx.lz");
const u32 sTourianEscapeSamusLookingAtMotherShipMotherShipTileTable[577] = INCBIN_U32("data/tourian_escape/samus_looking_at_mother_ship_mother_ship.tt");

