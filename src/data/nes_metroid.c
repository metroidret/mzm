#include "data/nes_metroid.h"
#include "macros.h"

const NesEmuFunc_T sNesEmuBootLoader = (NesEmuFunc_T)(0xEB000033);

static const u8 sNesMetroidData_Prologue[156] = {
    36, 255, 174, 81, 105, 154, 162, 33,
    61, 132, 130, 10, 132, 228, 9, 173,
    17, 36, 139, 152, 192, 129, 127, 33,
    163, 82, 190, 25, 147, 9, 206, 32,
    16, 70, 74, 74, 248, 39, 49, 236,
    88, 199, 232, 51, 130, 227, 206, 191,
    133, 244, 223, 148, 206, 75, 9, 193,
    148, 86, 138, 192, 19, 114, 167, 252,
    159, 132, 77, 115, 163, 202, 154, 97,
    88, 151, 163, 39, 252, 3, 152, 118,
    35, 29, 199, 97, 3, 4, 174, 86,
    191, 56, 132, 0, 64, 167, 14, 253,
    255, 82, 254, 3, 111, 149, 48, 241,
    151, 251, 192, 133, 96, 214, 128, 37,
    169, 99, 190, 3, 1, 78, 56, 226,
    249, 162, 52, 255, 187, 62, 3, 68,
    120, 0, 144, 203, 136, 17, 58, 148,
    101, 192, 124, 99, 135, 240, 60, 175,
    214, 37, 228, 139, 56, 10, 172, 114,
    33, 212, 248, 7
};

const u8 sNesMetroidData_Text[18] = {
    'N', 'E', 'S', ' ', 'M', 'E', 'T', 'R', 'O', 'I', 'D', '\0',
    '\0', '\0', '\0', '\0', '0', '1'
};

const u8 sNesMetroidData[] = INCBIN_U8("data/nes_metroid.bin");

#if defined(REGION_US_BETA)
static const u8 sNesMetroidDataEnd[20] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xB2, 0xE8, 0xD2, 0x69, 0xC9, 0xDE, 0x80, 0x86,
    0x93, 0x84, 0x8B, 0x58
};
#elif defined(REGION_EU_BETA)
static const u8 sNesMetroidDataEnd[20] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x26, 0x16, 0xA5, 0xB4, 0x1B, 0x40, 0x7F, 0x38,
    0x07, 0x7A, 0xFC, 0x85
};
#endif
