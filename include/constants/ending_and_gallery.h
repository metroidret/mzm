#ifndef ENDING_AND_GALLERY_CONSTANTS_H
#define ENDING_AND_GALLERY_CONSTANTS_H

#include "types.h"
#include "macros.h"

MAKE_ENUM(u8, EndingFlags) ENUM_FLAG {
    ENDING_FLAG_NONE,
    ENDING_FLAG_NEW_TIME_ATTACK_RECORD  = 1 << 0,
    ENDING_FLAG_UNKNOWN                 = 1 << 4,
    ENDING_FLAG_FIRST_TIME_ATTACK_CLEAR = 1 << 5,
    ENDING_FLAG_FIRST_HARD_MODE_CLEAR   = 1 << 6,
    ENDING_FLAG_FIRST_CLEAR             = 1 << 7
};

MAKE_ENUM(u32, EndingImageLine) {
    ENDING_IMAGE_LINE_CLEAR_TIME,
    ENDING_IMAGE_LINE_TIMER,
    ENDING_IMAGE_LINE_YOUR_RATE,
    ENDING_IMAGE_LINE_COLLECTING,
    ENDING_IMAGE_LINE_PERCENTAGE,
    ENDING_IMAGE_LINE_NEXT_MISSION,

    ENDING_IMAGE_LINE_COUNT
};

MAKE_ENUM(u8, CreditLineType) {
    CREDIT_LINE_TYPE_BLUE,
    CREDIT_LINE_TYPE_RED,
    CREDIT_LINE_TYPE_WHITE_BIG,
    CREDIT_LINE_TYPE_WHITE_SMALL,

    CREDIT_LINE_TYPE_BLANK = 5,
    CREDIT_LINE_TYPE_COUNT,

    CREDIT_LINE_TYPE_ALL_RIGHTS = 10,
    CREDIT_LINE_TYPE_THE_COPYRIGHT,
    CREDIT_LINE_TYPE_SCENARIO,
    CREDIT_LINE_TYPE_RESERVED
};

MAKE_ENUM(u8, EndingImage) {
    ENDING_IMAGE_ZERO,   // Always Easy, or Normal or Hard, Any%, >= 4 hours, Samus in her Gravity Suit sitting atop a rock
    ENDING_IMAGE_ONE,    // Normal or Hard, Any%, 2 < hours <= 4, Samus in her Gravity Suit with her helmet off looking into the distance
    ENDING_IMAGE_TWO,    // Normal or Hard, Any%, < 2 hours, Samus in her Zero Suit looking behind her
    ENDING_IMAGE_THREE,  // Normal or Hard, 100%, >= 2 hours, Samus in her orange two-piece, looking to the side
    ENDING_IMAGE_FOUR,   // Normal, 100%, < 2 hours, Samus in her orange two-piece, at a bar
    ENDING_IMAGE_FIVE,   // Hard, 100%, < 2 hours, Samus in her orange two-piece, looking away from the city
    ENDING_IMAGE_SIX,    // Normal, Low%, Samus in her orange two-piece, partially sitting on a window sill
    ENDING_IMAGE_SEVEN,  // Hard, Low%, Samus in her Gravity Suit and orange two-piece, ready for battle

    ENDING_IMAGE_COUNT
};

MAKE_ENUM(u8, EndingOamType) {
    ENDING_OAM_TYPE_NONE,
    ENDING_OAM_TYPE_CHAR,
    ENDING_OAM_TYPE_LINE
};

#define PEN_GET_ENDING(pen) ((pen) & 0xF)
#define PEN_GET_ABILITY(pen) ((pen) >> 4 & 0xF)
#define PEN_GET_POWER_BOMB(pen) ((pen) >> 8 & 0xF)
#define PEN_GET_SUPER_MISSILE(pen) ((pen) >> 12 & 0xF)
#define PEN_GET_MISSILE(pen) (LOW_BYTE((pen) >> 16))
#define PEN_GET_ENERGY(pen) (LOW_BYTE((pen) >> 24))

#endif /* ENDING_AND_GALLERY_CONSTANTS_H */
