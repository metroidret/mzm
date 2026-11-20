#ifndef TRANSPARENCY_CONSTANTS_H
#define TRANSPARENCY_CONSTANTS_H

#include "types.h"
#include "macros.h"

// Values from 4 and above take bg0 priority into account, values below always
// use TRANSPARENCY_BG0_HIGH_PRIORITY instead.
#define TRANSPARENCY_USE_BG0_PRIORITY_MASK (~3)

// Values from 8 and above will use BLDCNT_BG0_FIRST_TARGET_PIXEL instead of
// BLDCNT_BG0_SECOND_TARGET_PIXEL.
#define TRANSPARENCY_USE_BG0_FIRST_TARGET_PIXEL_MASK (~7)

MAKE_ENUM(u8, Transparency) ENUM_FLAG {
    TRANSPARENCY_NONE,

    TRANSPARENCY_BG0_HIGH_PRIORITY = 0, // Order from front to back is bg0, bg1, Samus, bg2, bg3
    TRANSPARENCY_BG0_HIGH_MID_PRIORITY = 1, // Order from front to back is bg1, bg0, Samus, bg2, bg3
    TRANSPARENCY_BG0_LOW_MID_PRIORITY = 2, // Order from front to back is bg1, Samus, bg0, bg2, bg3
    TRANSPARENCY_BG0_LOW_PRIORITY = 3, // Order from front to back is bg1, Samus, bg2, bg0, bg3

    TRANSPARENCY_04 = 1 << 2,
    TRANSPARENCY_EVA_07 = 2 << 2,
    TRANSPARENCY_EVA_0A = 3 << 2,
    TRANSPARENCY_EVA_0D = 4 << 2,
    TRANSPARENCY_EVA_10 = 5 << 2,
    TRANSPARENCY_EVB_00 = 6 << 2,
    TRANSPARENCY_EVB_03 = 7 << 2,
    TRANSPARENCY_EVB_06 = 8 << 2,
    TRANSPARENCY_EVB_09 = 9 << 2,
    TRANSPARENCY_EVB_0B = 10 << 2,
    TRANSPARENCY_EVB_0D = 11 << 2,
    TRANSPARENCY_EVB_10 = 12 << 2,
};

#endif /* TRANSPARENCY_CONSTANTS_H */
