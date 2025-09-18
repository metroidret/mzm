#ifndef OAM_H
#define OAM_H

#include "types.h"

// Attribute 0

#define OBJ_ROTATION_SCALING      (1 << 8)
#define OBJ_DOUBLE_SIZE           (1 << 9)
#define OBJ_DISABLE               (1 << 9)
#define OBJ_MODE_SEMI_TRANSPARENT (1 << 10)
#define OBJ_MODE_OBJ_WINDOW       (1 << 11)
#define OBJ_MOSAIC                (1 << 12)
#define OBJ_COLOR_256_1           (1 << 13)

#define OAM_AFFINE_MODE_NORMAL            0
#define OAM_AFFINE_MODE_AFFINE            1
#define OAM_AFFINE_MODE_DISABLE_RENDERING 2
#define OAM_AFFINE_MODE_DOUBLE_SIZED      3

#define OAM_OBJ_MODE_NORMAL           0
#define OAM_OBJ_MODE_SEMI_TRANSPARENT 1
#define OAM_OBJ_MODE_WINDOW           2

#define OAM_SHAPE_SQUARE     0
#define OAM_SHAPE_HORIZONTAL 1
#define OAM_SHAPE_VERTICAL   2

// Attribute 1

#define OAM_NO_FLIP 0
#define OAM_X_FLIP  (1 << 0)
#define OAM_Y_FLIP  (1 << 1)
#define OAM_XY_FLIP (OAM_X_FLIP | OAM_Y_FLIP)

#define OAM_SIZE_S_8x8   0
#define OAM_SIZE_S_16x16 1
#define OAM_SIZE_S_32x32 2
#define OAM_SIZE_S_64x64 3

#define OAM_SIZE_H_16x8  0
#define OAM_SIZE_H_32x8  1
#define OAM_SIZE_H_32x16 2
#define OAM_SIZE_H_64x32 3

#define OAM_SIZE_V_8x16  0
#define OAM_SIZE_V_8x32  1
#define OAM_SIZE_V_16x32 2
#define OAM_SIZE_V_32x64 3

#define OAM_DIMS_8x8   ((OAM_SHAPE_SQUARE << 2)     | OAM_SIZE_S_8x8)
#define OAM_DIMS_16x16 ((OAM_SHAPE_SQUARE << 2)     | OAM_SIZE_S_16x16)
#define OAM_DIMS_32x32 ((OAM_SHAPE_SQUARE << 2)     | OAM_SIZE_S_32x32)
#define OAM_DIMS_64x64 ((OAM_SHAPE_SQUARE << 2)     | OAM_SIZE_S_64x64)

#define OAM_DIMS_16x8  ((OAM_SHAPE_HORIZONTAL << 2) | OAM_SIZE_H_16x8)
#define OAM_DIMS_32x8  ((OAM_SHAPE_HORIZONTAL << 2) | OAM_SIZE_H_32x8)
#define OAM_DIMS_32x16 ((OAM_SHAPE_HORIZONTAL << 2) | OAM_SIZE_H_32x16)
#define OAM_DIMS_64x32 ((OAM_SHAPE_HORIZONTAL << 2) | OAM_SIZE_H_64x32)

#define OAM_DIMS_8x16  ((OAM_SHAPE_VERTICAL << 2)   | OAM_SIZE_V_8x16)
#define OAM_DIMS_8x32  ((OAM_SHAPE_VERTICAL << 2)   | OAM_SIZE_V_8x32)
#define OAM_DIMS_16x32 ((OAM_SHAPE_VERTICAL << 2)   | OAM_SIZE_V_16x32)
#define OAM_DIMS_32x64 ((OAM_SHAPE_VERTICAL << 2)   | OAM_SIZE_V_32x64)

#define OAM_DIMS_SIZE(dims) (dims & 3)
#define OAM_DIMS_SHAPE(dims) ((dims >> 2) & 3)

/**
 * @brief A macro for creating OamData entries.
 * Assumes that:
 *   Rotation/Scaling = Off,
 *   Double-Size / Disable = Normal,
 *   OBJ Mode = Normal
 *   Mosaic = Off,
 *   Colors/Palettes = 16/16
 */
#define OAM_ENTRY(x, y, dims, flip, tile, palette, priority) \
    OAM_DIMS_SHAPE(dims) << 14 | ((y) & 0xFF), \
    OAM_DIMS_SIZE(dims) << 14 | (flip) << 12 | ((x) & 0x1FF), \
    ((palette) << 12) | ((priority) << 10) | (tile)

/**
 * @brief A macro for creating OamData entries that allows specifying OBJ Mode.
 * Assumes that:
 *   Rotation/Scaling = Off,
 *   Double-Size / Disable = Normal,
 *   Mosaic = Off,
 *   Colors/Palettes = 16/16
 */
#define OAM_ENTRY_MODE(x, y, dims, flip, tile, palette, priority, mode) \
    OAM_DIMS_SHAPE(dims) << 14 | (mode) << 10 | ((y) & 0xFF), \
    OAM_DIMS_SIZE(dims) << 14 | (flip) << 12 | ((x) & 0x1FF), \
    ((palette) << 12) | ((priority) << 10) | (tile)

struct FrameData {
    const u16* pFrame;
    u8 timer;
};

#define FRAME_DATA_TERMINATOR \
{\
    .pFrame = NULL,\
    .timer = 0\
}

#define OAM_PART_SIZE 3
#define OAM_DATA_SIZE(nbrOfParts) (1 + (nbrOfParts) * OAM_PART_SIZE)
#define GET_OAM_DATA_SIZE(size) (((size) - 1) / OAM_PART_SIZE)

#define FRAME_DATA_NBR_OF_FRAMES(oam) (ARRAY_SIZE((oam)) - 1)
#define FRAME_DATA_LAST_ANIM_FRAME(oam) (ARRAY_SIZE((oam)) - 2)

union OamData {
    struct {
    /*0x00*/ u32 y:8;
             u32 affineMode:2;  // 0x1, 0x2 -> 0x4
             u32 objMode:2;     // 0x4, 0x8 -> 0xC
             u32 mosaic:1;      // 0x10
             u32 bpp:1;         // 0x20
             u32 shape:2;       // 0x40, 0x80 -> 0xC0

    /*0x01*/ u32 x:9;
             u32 matrixNum:3;
             u32 xFlip:1;
             u32 yFlip:1;
             u32 size:2;        // 0x4000, 0x8000 -> 0xC000

    /*0x02*/ u16 tileNum:10;    // 0x3FF
             u16 priority:2;    // 0x400, 0x800 -> 0xC00
             u16 paletteNum:4;

    /*0x03*/ u16 fractional:8;
             u16 integer:7;
             u16 sign:1;
    } split;

    struct {
        u16 attr0;
        u16 attr1;
        u16 attr2;
        u16 affineParam;
    } all;
};

extern u8 gNextOamSlot;

#define OAM_BUFFER_DATA_SIZE 128
#define OAM_BUFFER_AFFINE_SIZE 32

extern union OamData gOamData[OAM_BUFFER_DATA_SIZE + OAM_BUFFER_AFFINE_SIZE];

#endif /* OAM_H */
