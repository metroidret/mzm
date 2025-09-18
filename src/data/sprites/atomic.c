#include "data/sprites/atomic.h"

#include "macros.h"

const s16 sAtomicIdleYMovement[65] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 2,
    2, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, -1, -1, -2,
    -2, -1, -1, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0,
    SHORT_MAX
};

const s16 sAtomicIdleXMovement[81] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 2, 2,
    2, 2, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1, -2, -2,
    -2, -2, -1, -1, -1, -1, -1, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0,
    SHORT_MAX
};

const u32 sAtomicGfx[752] = INCBIN_U32("data/sprites/Atomic.gfx.lz");
const u16 sAtomicPal[64] = INCBIN_U16("data/sprites/Atomic.pal");

static const u16 sAtomicOam_Idle_Frame0[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_NO_FLIP, 658, 8, 0),
    OAM_ENTRY(4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 657, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-9, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 659, 8, 0),
};

static const u16 sAtomicOam_Idle_Frame1[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 659, 8, 0),
    OAM_ENTRY(1, 0, OAM_DIMS_8x8, OAM_NO_FLIP, 659, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sAtomicOam_Idle_Frame2[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-12, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 657, 8, 0),
    OAM_ENTRY(-2, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 658, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(1, -9, OAM_DIMS_8x8, OAM_XY_FLIP, 659, 8, 0),
};

static const u16 sAtomicOam_Idle_Frame3[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(0, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 659, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(-11, -5, OAM_DIMS_8x8, OAM_NO_FLIP, 657, 8, 0),
    OAM_ENTRY(-4, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 658, 8, 0),
};

static const u16 sAtomicOam_Idle_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-2, -3, OAM_DIMS_8x8, OAM_NO_FLIP, 659, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(-10, -8, OAM_DIMS_8x8, OAM_NO_FLIP, 657, 8, 0),
    OAM_ENTRY(-6, 3, OAM_DIMS_8x8, OAM_NO_FLIP, 658, 8, 0),
};

static const u16 sAtomicOam_Idle_Frame5[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(1, 1, OAM_DIMS_8x8, OAM_X_FLIP, 659, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-7, -11, OAM_DIMS_8x8, OAM_X_FLIP, 658, 8, 0),
    OAM_ENTRY(-10, -1, OAM_DIMS_8x8, OAM_X_FLIP, 657, 8, 0),
};

static const u16 sAtomicOam_Idle_Frame6[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-4, -12, OAM_DIMS_8x8, OAM_X_FLIP, 658, 8, 0),
    OAM_ENTRY(-12, -4, OAM_DIMS_8x8, OAM_X_FLIP, 657, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(1, 1, OAM_DIMS_8x8, OAM_X_FLIP, 659, 8, 0),
};

static const u16 sAtomicOam_Idle_Frame7[OAM_DATA_SIZE(3)] = {
    3,
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_X_FLIP, 659, 8, 0),
    OAM_ENTRY(-9, 0, OAM_DIMS_8x8, OAM_X_FLIP, 659, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
};

static const u16 sAtomicOam_Idle_Frame8[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(4, -4, OAM_DIMS_8x8, OAM_X_FLIP, 657, 8, 0),
    OAM_ENTRY(-6, 3, OAM_DIMS_8x8, OAM_X_FLIP, 658, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 542, 8, 0),
    OAM_ENTRY(-9, -9, OAM_DIMS_8x8, OAM_Y_FLIP, 659, 8, 0),
};

static const u16 sAtomicOam_Idle_Frame9[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-8, -8, OAM_DIMS_8x8, OAM_X_FLIP, 659, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 540, 8, 0),
    OAM_ENTRY(3, -5, OAM_DIMS_8x8, OAM_X_FLIP, 657, 8, 0),
    OAM_ENTRY(-4, 3, OAM_DIMS_8x8, OAM_X_FLIP, 658, 8, 0),
};

static const u16 sAtomicOam_Idle_Frame10[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-6, -3, OAM_DIMS_8x8, OAM_X_FLIP, 659, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 538, 8, 0),
    OAM_ENTRY(2, -8, OAM_DIMS_8x8, OAM_X_FLIP, 657, 8, 0),
    OAM_ENTRY(-2, 3, OAM_DIMS_8x8, OAM_X_FLIP, 658, 8, 0),
};

static const u16 sAtomicOam_Idle_Frame11[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-9, 1, OAM_DIMS_8x8, OAM_NO_FLIP, 659, 8, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 536, 8, 0),
    OAM_ENTRY(-1, -11, OAM_DIMS_8x8, OAM_NO_FLIP, 658, 8, 0),
    OAM_ENTRY(2, -1, OAM_DIMS_8x8, OAM_NO_FLIP, 657, 8, 0),
};

static const u16 sAtomicElectricityOam_MovingVertical_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x32, OAM_NO_FLIP, 533, 9, 0),
    OAM_ENTRY(-8, 32, OAM_DIMS_16x8, OAM_NO_FLIP, 661, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingVertical_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x32, OAM_NO_FLIP, 535, 9, 0),
    OAM_ENTRY(-4, 32, OAM_DIMS_8x8, OAM_NO_FLIP, 663, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingVertical_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-5, 8, OAM_DIMS_16x32, OAM_XY_FLIP, 533, 9, 0),
    OAM_ENTRY(-5, 0, OAM_DIMS_16x8, OAM_XY_FLIP, 661, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingVertical_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, 8, OAM_DIMS_8x32, OAM_XY_FLIP, 535, 9, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_XY_FLIP, 663, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingVertical_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 0, OAM_DIMS_16x32, OAM_X_FLIP, 533, 9, 0),
    OAM_ENTRY(-8, 32, OAM_DIMS_16x8, OAM_X_FLIP, 661, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingVertical_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, 0, OAM_DIMS_8x32, OAM_X_FLIP, 535, 9, 0),
    OAM_ENTRY(-4, 32, OAM_DIMS_8x8, OAM_X_FLIP, 663, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingVertical_Frame9[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-8, 8, OAM_DIMS_16x32, OAM_Y_FLIP, 533, 9, 0),
    OAM_ENTRY(-8, 0, OAM_DIMS_16x8, OAM_Y_FLIP, 661, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingVertical_Frame10[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-4, 8, OAM_DIMS_8x32, OAM_Y_FLIP, 535, 9, 0),
    OAM_ENTRY(-4, 0, OAM_DIMS_8x8, OAM_Y_FLIP, 663, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingVertical_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, 16, OAM_DIMS_8x32, OAM_NO_FLIP, 600, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingVertical_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, 8, OAM_DIMS_8x32, OAM_XY_FLIP, 600, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingVertical_Unused_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, 16, OAM_DIMS_8x32, OAM_NO_FLIP, 633, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingVertical_Unused_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, 8, OAM_DIMS_8x32, OAM_XY_FLIP, 633, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingDiagonal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_NO_FLIP, 640, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingDiagonal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_NO_FLIP, 644, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingDiagonal_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_XY_FLIP, 640, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingDiagonal_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_XY_FLIP, 644, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingDiagonal_Frame6[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_NO_FLIP, 648, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingDiagonal_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_NO_FLIP, 652, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingDiagonal_Frame9[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_XY_FLIP, 648, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingDiagonal_Frame10[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_XY_FLIP, 652, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingDiagonal_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 666, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingDiagonal_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, 16, OAM_DIMS_16x16, OAM_XY_FLIP, 666, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingDiagonal_Unused_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, 16, OAM_DIMS_16x16, OAM_NO_FLIP, 730, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingDiagonal_Unused_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-32, 16, OAM_DIMS_16x16, OAM_XY_FLIP, 730, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingHorizontal_Frame0[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-40, -8, OAM_DIMS_32x16, OAM_NO_FLIP, 688, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_NO_FLIP, 692, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingHorizontal_Frame1[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-40, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 752, 9, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 756, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingHorizontal_Frame3[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -5, OAM_DIMS_32x16, OAM_XY_FLIP, 688, 9, 0),
    OAM_ENTRY(-40, -5, OAM_DIMS_8x16, OAM_XY_FLIP, 692, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingHorizontal_Frame5[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -4, OAM_DIMS_32x8, OAM_XY_FLIP, 752, 9, 0),
    OAM_ENTRY(-40, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 756, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingHorizontal_Frame6[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-40, -8, OAM_DIMS_32x16, OAM_Y_FLIP, 688, 9, 0),
    OAM_ENTRY(-8, -8, OAM_DIMS_8x16, OAM_Y_FLIP, 692, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingHorizontal_Frame7[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-40, -4, OAM_DIMS_32x8, OAM_Y_FLIP, 752, 9, 0),
    OAM_ENTRY(-8, -4, OAM_DIMS_8x8, OAM_Y_FLIP, 756, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingHorizontal_Frame9[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -8, OAM_DIMS_32x16, OAM_X_FLIP, 688, 9, 0),
    OAM_ENTRY(-40, -8, OAM_DIMS_8x16, OAM_X_FLIP, 692, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingHorizontal_Frame10[OAM_DATA_SIZE(2)] = {
    2,
    OAM_ENTRY(-32, -4, OAM_DIMS_32x8, OAM_X_FLIP, 752, 9, 0),
    OAM_ENTRY(-40, -4, OAM_DIMS_8x8, OAM_X_FLIP, 756, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingHorizontal_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-40, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 693, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingHorizontal_Unused_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_XY_FLIP, 693, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingHorizontal_Unused_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-40, -4, OAM_DIMS_32x8, OAM_NO_FLIP, 726, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingHorizontal_Unused_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-48, -4, OAM_DIMS_32x8, OAM_XY_FLIP, 726, 9, 0),
};

static const u16 sAtomicElectricityOam_ExplodingNonDiagonal_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 656, 9, 0),
};

static const u16 sAtomicElectricityOam_ExplodingNonDiagonal_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -8, OAM_DIMS_16x16, OAM_NO_FLIP, 732, 9, 0),
};

static const u16 sAtomicElectricityOam_ExplodingNonDiagonal_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 528, 9, 0),
};

static const u16 sAtomicElectricityOam_ExplodingNonDiagonal_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 524, 9, 0),
};

static const u16 sAtomicElectricityOam_ExplodingNonDiagonal_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-32, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 520, 9, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x32, OAM_X_FLIP, 520, 9, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_Y_FLIP, 520, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x32, OAM_XY_FLIP, 520, 9, 0),
};

static const u16 sAtomicElectricityOam_ExplodingNonDiagonal_Frame5[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(17, -33, OAM_DIMS_16x16, OAM_NO_FLIP, 666, 9, 0),
    OAM_ENTRY(-33, -33, OAM_DIMS_16x16, OAM_X_FLIP, 666, 9, 0),
    OAM_ENTRY(17, 17, OAM_DIMS_16x16, OAM_Y_FLIP, 666, 9, 0),
    OAM_ENTRY(-33, 17, OAM_DIMS_16x16, OAM_XY_FLIP, 666, 9, 0),
    OAM_ENTRY(-32, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x32, OAM_X_FLIP, 516, 9, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_Y_FLIP, 516, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x32, OAM_XY_FLIP, 516, 9, 0),
};

static const u16 sAtomicElectricityOam_ExplodingNonDiagonal_Frame6[OAM_DATA_SIZE(8)] = {
    8,
    OAM_ENTRY(21, -37, OAM_DIMS_16x16, OAM_NO_FLIP, 730, 9, 0),
    OAM_ENTRY(-37, -37, OAM_DIMS_16x16, OAM_X_FLIP, 730, 9, 0),
    OAM_ENTRY(21, 21, OAM_DIMS_16x16, OAM_Y_FLIP, 730, 9, 0),
    OAM_ENTRY(-37, 21, OAM_DIMS_16x16, OAM_XY_FLIP, 730, 9, 0),
    OAM_ENTRY(-32, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x32, OAM_X_FLIP, 512, 9, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_Y_FLIP, 512, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x32, OAM_XY_FLIP, 512, 9, 0),
};

static const u16 sAtomicElectricityOam_ExplodingDiagonal_Frame3[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -16, OAM_DIMS_32x32, OAM_NO_FLIP, 524, 9, 0),
};

static const u16 sAtomicElectricityOam_ExplodingDiagonal_Frame4[OAM_DATA_SIZE(4)] = {
    4,
    OAM_ENTRY(-32, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 520, 9, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x32, OAM_X_FLIP, 520, 9, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_Y_FLIP, 520, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x32, OAM_XY_FLIP, 520, 9, 0),
};

static const u16 sAtomicElectricityOam_ExplodingDiagonal_Frame5[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-32, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 516, 9, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x32, OAM_X_FLIP, 516, 9, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_Y_FLIP, 516, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x32, OAM_XY_FLIP, 516, 9, 0),
    OAM_ENTRY(-4, -40, OAM_DIMS_8x16, OAM_NO_FLIP, 600, 9, 0),
    OAM_ENTRY(-4, -24, OAM_DIMS_8x8, OAM_NO_FLIP, 664, 9, 0),
    OAM_ENTRY(-40, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 693, 9, 0),
    OAM_ENTRY(-24, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 695, 9, 0),
    OAM_ENTRY(-4, 24, OAM_DIMS_8x16, OAM_XY_FLIP, 600, 9, 0),
    OAM_ENTRY(-4, 16, OAM_DIMS_8x8, OAM_XY_FLIP, 664, 9, 0),
    OAM_ENTRY(24, -4, OAM_DIMS_16x8, OAM_XY_FLIP, 693, 9, 0),
    OAM_ENTRY(16, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 695, 9, 0),
};

static const u16 sAtomicElectricityOam_ExplodingDiagonal_Frame6[OAM_DATA_SIZE(12)] = {
    12,
    OAM_ENTRY(-32, -32, OAM_DIMS_32x32, OAM_NO_FLIP, 512, 9, 0),
    OAM_ENTRY(0, -32, OAM_DIMS_32x32, OAM_X_FLIP, 512, 9, 0),
    OAM_ENTRY(-32, 0, OAM_DIMS_32x32, OAM_Y_FLIP, 512, 9, 0),
    OAM_ENTRY(0, 0, OAM_DIMS_32x32, OAM_XY_FLIP, 512, 9, 0),
    OAM_ENTRY(-4, -48, OAM_DIMS_8x16, OAM_NO_FLIP, 633, 9, 0),
    OAM_ENTRY(-4, -32, OAM_DIMS_8x8, OAM_NO_FLIP, 697, 9, 0),
    OAM_ENTRY(-48, -4, OAM_DIMS_16x8, OAM_NO_FLIP, 726, 9, 0),
    OAM_ENTRY(-32, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 728, 9, 0),
    OAM_ENTRY(-4, 32, OAM_DIMS_8x16, OAM_XY_FLIP, 633, 9, 0),
    OAM_ENTRY(-4, 24, OAM_DIMS_8x8, OAM_XY_FLIP, 697, 9, 0),
    OAM_ENTRY(32, -4, OAM_DIMS_16x8, OAM_XY_FLIP, 726, 9, 0),
    OAM_ENTRY(24, -4, OAM_DIMS_8x8, OAM_XY_FLIP, 728, 9, 0),
};

static const u16 sAtomicElectricityOam_MovingVertical_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-4, -4, OAM_DIMS_8x8, OAM_NO_FLIP, 516, 9, 0),
};

static const u16 sAtomicElectricityOam_Charging_Frame0[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -16, OAM_DIMS_8x32, OAM_NO_FLIP, 607, 9, 0),
};

static const u16 sAtomicElectricityOam_Charging_Frame1[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -5, OAM_DIMS_16x16, OAM_NO_FLIP, 734, 9, 0),
};

static const u16 sAtomicElectricityOam_Charging_Frame2[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, 1, OAM_DIMS_32x8, OAM_NO_FLIP, 603, 9, 0),
};

static const u16 sAtomicElectricityOam_Charging_Frame4[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(0, -16, OAM_DIMS_8x32, OAM_XY_FLIP, 607, 9, 0),
};

static const u16 sAtomicElectricityOam_Charging_Frame5[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-8, -11, OAM_DIMS_16x16, OAM_XY_FLIP, 734, 9, 0),
};

static const u16 sAtomicElectricityOam_Charging_Frame7[OAM_DATA_SIZE(1)] = {
    1,
    OAM_ENTRY(-16, -9, OAM_DIMS_32x8, OAM_XY_FLIP, 603, 9, 0),
};

const struct FrameData sAtomicOam_Idle[13] = {
    [0] = {
        .pFrame = sAtomicOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sAtomicOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sAtomicOam_Idle_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sAtomicOam_Idle_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sAtomicOam_Idle_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sAtomicOam_Idle_Frame5,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sAtomicOam_Idle_Frame6,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = {
        .pFrame = sAtomicOam_Idle_Frame7,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [8] = {
        .pFrame = sAtomicOam_Idle_Frame8,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [9] = {
        .pFrame = sAtomicOam_Idle_Frame9,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [10] = {
        .pFrame = sAtomicOam_Idle_Frame10,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [11] = {
        .pFrame = sAtomicOam_Idle_Frame11,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAtomicElectricityOam_MovingVertical[13] = {
    [0] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAtomicElectricityOam_MovingVertical_Unused[5] = {
    [0] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAtomicElectricityOam_MovingDiagonal[13] = {
    [0] = {
        .pFrame = sAtomicElectricityOam_MovingDiagonal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sAtomicElectricityOam_MovingDiagonal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sAtomicElectricityOam_MovingDiagonal_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sAtomicElectricityOam_MovingDiagonal_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sAtomicElectricityOam_MovingDiagonal_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sAtomicElectricityOam_MovingDiagonal_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sAtomicElectricityOam_MovingDiagonal_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = {
        .pFrame = sAtomicElectricityOam_MovingDiagonal_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAtomicElectricityOam_MovingDiagonal_Unused[5] = {
    [0] = {
        .pFrame = sAtomicElectricityOam_MovingDiagonal_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sAtomicElectricityOam_MovingDiagonal_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sAtomicElectricityOam_MovingDiagonal_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sAtomicElectricityOam_MovingDiagonal_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAtomicElectricityOam_MovingHorizontal[13] = {
    [0] = {
        .pFrame = sAtomicElectricityOam_MovingHorizontal_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sAtomicElectricityOam_MovingHorizontal_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sAtomicElectricityOam_MovingHorizontal_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = {
        .pFrame = sAtomicElectricityOam_MovingHorizontal_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sAtomicElectricityOam_MovingHorizontal_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sAtomicElectricityOam_MovingHorizontal_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [9] = {
        .pFrame = sAtomicElectricityOam_MovingHorizontal_Frame9,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [10] = {
        .pFrame = sAtomicElectricityOam_MovingHorizontal_Frame10,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [11] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAtomicElectricityOam_MovingHorizontal_Unused[5] = {
    [0] = {
        .pFrame = sAtomicElectricityOam_MovingHorizontal_Unused_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sAtomicElectricityOam_MovingHorizontal_Unused_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sAtomicElectricityOam_MovingHorizontal_Unused_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sAtomicElectricityOam_MovingHorizontal_Unused_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAtomicElectricityOam_ExplodingNonDiagonal[8] = {
    [0] = {
        .pFrame = sAtomicElectricityOam_ExplodingNonDiagonal_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sAtomicElectricityOam_ExplodingNonDiagonal_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sAtomicElectricityOam_ExplodingNonDiagonal_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sAtomicElectricityOam_ExplodingNonDiagonal_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sAtomicElectricityOam_ExplodingNonDiagonal_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sAtomicElectricityOam_ExplodingNonDiagonal_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sAtomicElectricityOam_ExplodingNonDiagonal_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAtomicElectricityOam_ExplodingDiagonal[8] = {
    [0] = {
        .pFrame = sAtomicElectricityOam_ExplodingNonDiagonal_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sAtomicElectricityOam_ExplodingNonDiagonal_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sAtomicElectricityOam_ExplodingNonDiagonal_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sAtomicElectricityOam_ExplodingDiagonal_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sAtomicElectricityOam_ExplodingDiagonal_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sAtomicElectricityOam_ExplodingDiagonal_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sAtomicElectricityOam_ExplodingDiagonal_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sAtomicElectricityOam_Charging[12] = {
    [0] = {
        .pFrame = sAtomicElectricityOam_Charging_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sAtomicElectricityOam_Charging_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sAtomicElectricityOam_Charging_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame2,
        .timer = CONVERT_SECONDS(0.5f)
    },
    [4] = {
        .pFrame = sAtomicElectricityOam_Charging_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sAtomicElectricityOam_Charging_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame2,
        .timer = CONVERT_SECONDS(0.5f)
    },
    [7] = {
        .pFrame = sAtomicElectricityOam_Charging_Frame7,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [8] = {
        .pFrame = sAtomicElectricityOam_MovingVertical_Frame2,
        .timer = CONVERT_SECONDS(0.5f)
    },
    [9] = {
        .pFrame = sAtomicElectricityOam_Charging_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [10] = {
        .pFrame = sAtomicElectricityOam_Charging_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [11] = FRAME_DATA_TERMINATOR
};
