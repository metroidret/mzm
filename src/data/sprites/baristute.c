#include "data/sprites/baristute.h"

#include "macros.h"

const s16 sBaristuteFallingYVelocity[8] = {
    4, 8, 12, 16, 20, 24, 28, SHORT_MAX
};

const s16 sBaristuteJumpingYVelocity[10] = {
    -12, -16, -16, -8, -4, 0, 12, 18, 24, 32
};

const u32 sBaristuteGfx[596] = INCBIN_U32("data/sprites/baristute.gfx.lz");
const u16 sBaristutePal[80] = INCBIN_U16("data/sprites/baristute.pal");

static const u16 sBaristuteOam_Idle_Frame0[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-16, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_16x32, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(11, -25, OAM_DIMS_16x32, OAM_X_FLIP, 0x247, 8, 0),
    OAM_ENTRY(11, -39, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(0, -35, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(16, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(19, -11, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(7, -11, OAM_DIMS_16x16, OAM_X_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-27, -25, OAM_DIMS_16x32, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-27, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-17, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-32, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-35, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-23, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sBaristuteOam_Walking_Frame1[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-30, -32, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-27, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-16, -41, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -41, OAM_DIMS_16x32, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -18, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(-16, -19, OAM_DIMS_16x16, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(0, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x252, 8, 0),
    OAM_ENTRY(16, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(19, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(7, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-17, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(11, -26, OAM_DIMS_16x32, OAM_X_FLIP, 0x247, 8, 0),
    OAM_ENTRY(11, -40, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(0, -36, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-35, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-38, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-27, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sBaristuteOam_Walking_Frame2[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-16, -42, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -42, OAM_DIMS_16x32, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -20, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-16, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x292, 8, 0),
    OAM_ENTRY(0, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x292, 8, 0),
    OAM_ENTRY(11, -40, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(12, -26, OAM_DIMS_16x32, OAM_X_FLIP, 0x247, 8, 0),
    OAM_ENTRY(0, -37, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(16, -11, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(20, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(7, -13, OAM_DIMS_16x16, OAM_X_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-27, -45, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-31, -37, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20a, 8, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-37, -20, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-41, -22, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-27, -21, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sBaristuteOam_Walking_Frame3[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-16, -39, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -39, OAM_DIMS_16x32, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x292, 8, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-29, -28, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-27, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-16, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(15, -29, OAM_DIMS_16x32, OAM_X_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(12, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(0, -33, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(18, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(21, -11, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(9, -11, OAM_DIMS_16x16, OAM_X_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-33, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-37, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-24, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sBaristuteOam_Walking_Frame4[OAM_DATA_SIZE(17)] = {
    17,
    OAM_ENTRY(-16, -41, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -41, OAM_DIMS_16x32, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x252, 8, 0),
    OAM_ENTRY(12, -41, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(0, -36, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(13, -29, OAM_DIMS_16x32, OAM_X_FLIP, 0x247, 8, 0),
    OAM_ENTRY(17, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(21, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-29, -29, OAM_DIMS_16x32, OAM_NO_FLIP, 0x20c, 8, 0),
    OAM_ENTRY(-27, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-16, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-32, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-36, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-24, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sBaristuteOam_Walking_Frame5[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-16, -42, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -42, OAM_DIMS_16x32, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(13, -44, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(13, -36, OAM_DIMS_16x32, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(16, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(20, -20, OAM_DIMS_16x16, OAM_X_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(8, -19, OAM_DIMS_16x16, OAM_X_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-27, -31, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-28, -41, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-16, -36, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-30, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-33, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-21, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sBaristuteOam_Warning_Frame1[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-4, -26, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(-16, -40, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -40, OAM_DIMS_16x32, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(-16, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(0, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(12, -25, OAM_DIMS_16x32, OAM_X_FLIP, 0x247, 8, 0),
    OAM_ENTRY(11, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(0, -35, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(16, -11, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(20, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(7, -13, OAM_DIMS_16x16, OAM_X_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-28, -25, OAM_DIMS_16x32, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-27, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-17, -35, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-32, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-36, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-23, -13, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sBaristuteOam_Warning_Frame2[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-4, -23, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-16, -35, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -35, OAM_DIMS_16x32, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -13, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-16, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x212, 8, 0),
    OAM_ENTRY(0, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x212, 8, 0),
    OAM_ENTRY(10, -35, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(12, -28, OAM_DIMS_16x32, OAM_X_FLIP, 0x204, 8, 0),
    OAM_ENTRY(0, -31, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(16, -9, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(21, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(6, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-26, -34, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-29, -27, OAM_DIMS_16x32, OAM_NO_FLIP, 0x204, 8, 0),
    OAM_ENTRY(-17, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-32, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-37, -9, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21a, 8, 0),
    OAM_ENTRY(-22, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sBaristuteOam_Jumping_Frame0[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-27, -46, OAM_DIMS_16x32, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(11, -46, OAM_DIMS_16x32, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-16, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -48, OAM_DIMS_16x32, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(12, -14, OAM_DIMS_16x16, OAM_X_FLIP, 0x287, 8, 0),
    OAM_ENTRY(17, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(20, -15, OAM_DIMS_16x16, OAM_X_FLIP, 0x29c, 8, 0),
    OAM_ENTRY(8, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-28, -14, OAM_DIMS_16x16, OAM_NO_FLIP, 0x287, 8, 0),
    OAM_ENTRY(-33, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-36, -15, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29c, 8, 0),
    OAM_ENTRY(-24, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-15, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-1, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-16, -28, OAM_DIMS_16x16, OAM_NO_FLIP, 0x292, 8, 0),
    OAM_ENTRY(0, -28, OAM_DIMS_16x16, OAM_X_FLIP, 0x292, 8, 0)
};

static const u16 sBaristuteOam_Jumping_Frame1[OAM_DATA_SIZE(16)] = {
    16,
    OAM_ENTRY(-27, -48, OAM_DIMS_16x32, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(11, -48, OAM_DIMS_16x32, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(0, -50, OAM_DIMS_16x32, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-16, -50, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(12, -16, OAM_DIMS_16x16, OAM_X_FLIP, 0x287, 8, 0),
    OAM_ENTRY(17, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(20, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x29c, 8, 0),
    OAM_ENTRY(8, -18, OAM_DIMS_16x16, OAM_X_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-28, -16, OAM_DIMS_16x16, OAM_NO_FLIP, 0x287, 8, 0),
    OAM_ENTRY(-33, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25c, 8, 0),
    OAM_ENTRY(-36, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x29c, 8, 0),
    OAM_ENTRY(-24, -18, OAM_DIMS_16x16, OAM_NO_FLIP, 0x25e, 8, 0),
    OAM_ENTRY(-15, -40, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-1, -40, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-16, -29, OAM_DIMS_16x16, OAM_NO_FLIP, 0x292, 8, 0),
    OAM_ENTRY(0, -29, OAM_DIMS_16x16, OAM_X_FLIP, 0x292, 8, 0)
};

static const u16 sBaristuteOam_Idle_Frame2[OAM_DATA_SIZE(20)] = {
    20,
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-16, -38, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -38, OAM_DIMS_16x32, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -17, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25b, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x292, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x292, 8, 0),
    OAM_ENTRY(-27, -38, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-26, -24, OAM_DIMS_16x16, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-26, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 0x287, 8, 0),
    OAM_ENTRY(10, -8, OAM_DIMS_16x16, OAM_X_FLIP, 0x287, 8, 0),
    OAM_ENTRY(-14, -31, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(15, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(18, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(6, -11, OAM_DIMS_16x16, OAM_X_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(11, -38, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(10, -24, OAM_DIMS_16x16, OAM_X_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-2, -31, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-31, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-34, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-22, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0)
};

static const u16 sBaristuteOam_Idle_Frame1[OAM_DATA_SIZE(18)] = {
    18,
    OAM_ENTRY(-4, -25, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(-16, -39, OAM_DIMS_16x32, OAM_NO_FLIP, 0x200, 8, 0),
    OAM_ENTRY(0, -39, OAM_DIMS_16x32, OAM_X_FLIP, 0x200, 8, 0),
    OAM_ENTRY(-4, -16, OAM_DIMS_8x8, OAM_NO_FLIP, 0x25a, 8, 0),
    OAM_ENTRY(-16, -17, OAM_DIMS_16x16, OAM_NO_FLIP, 0x252, 8, 0),
    OAM_ENTRY(0, -17, OAM_DIMS_16x16, OAM_X_FLIP, 0x252, 8, 0),
    OAM_ENTRY(11, -39, OAM_DIMS_16x16, OAM_X_FLIP, 0x207, 8, 0),
    OAM_ENTRY(11, -25, OAM_DIMS_16x32, OAM_X_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-1, -33, OAM_DIMS_16x16, OAM_X_FLIP, 0x202, 8, 0),
    OAM_ENTRY(16, -10, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(19, -11, OAM_DIMS_16x16, OAM_X_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(7, -12, OAM_DIMS_16x16, OAM_X_FLIP, 0x21e, 8, 0),
    OAM_ENTRY(-27, -39, OAM_DIMS_16x16, OAM_NO_FLIP, 0x207, 8, 0),
    OAM_ENTRY(-27, -25, OAM_DIMS_16x32, OAM_NO_FLIP, 0x247, 8, 0),
    OAM_ENTRY(-15, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 0x202, 8, 0),
    OAM_ENTRY(-32, -10, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-35, -11, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21c, 8, 0),
    OAM_ENTRY(-23, -12, OAM_DIMS_16x16, OAM_NO_FLIP, 0x21e, 8, 0)
};

const struct FrameData sBaristuteOam_Idle[5] = {
    [0] = {
        .pFrame = sBaristuteOam_Idle_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sBaristuteOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sBaristuteOam_Idle_Frame2,
        .timer = 16
    },
    [3] = {
        .pFrame = sBaristuteOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBaristuteOam_Warning[4] = {
    [0] = {
        .pFrame = sBaristuteOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sBaristuteOam_Warning_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sBaristuteOam_Warning_Frame2,
        .timer = 16
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBaristuteOam_Jumping[3] = {
    [0] = {
        .pFrame = sBaristuteOam_Jumping_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sBaristuteOam_Jumping_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBaristuteOam_Landing[4] = {
    [0] = {
        .pFrame = sBaristuteOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sBaristuteOam_Warning_Frame2,
        .timer = 8
    },
    [2] = {
        .pFrame = sBaristuteOam_Warning_Frame1,
        .timer = 12
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBaristuteOam_WalkingSlow[7] = {
    [0] = {
        .pFrame = sBaristuteOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sBaristuteOam_Walking_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sBaristuteOam_Walking_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sBaristuteOam_Walking_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sBaristuteOam_Walking_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sBaristuteOam_Walking_Frame5,
        .timer = 8
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBaristuteOam_WalkingFast[7] = {
    [0] = {
        .pFrame = sBaristuteOam_Idle_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sBaristuteOam_Walking_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sBaristuteOam_Walking_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sBaristuteOam_Walking_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sBaristuteOam_Walking_Frame4,
        .timer = 5
    },
    [5] = {
        .pFrame = sBaristuteOam_Walking_Frame5,
        .timer = 5
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBaristuteOam_WalkingVeryFast[7] = {
    [0] = {
        .pFrame = sBaristuteOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sBaristuteOam_Walking_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sBaristuteOam_Walking_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sBaristuteOam_Walking_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sBaristuteOam_Walking_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sBaristuteOam_Walking_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBaristuteOam_WalkingExtremelyFast[7] = {
    [0] = {
        .pFrame = sBaristuteOam_Idle_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sBaristuteOam_Walking_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sBaristuteOam_Walking_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sBaristuteOam_Walking_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sBaristuteOam_Walking_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sBaristuteOam_Walking_Frame5,
        .timer = 2
    },
    [6] = FRAME_DATA_TERMINATOR
};
