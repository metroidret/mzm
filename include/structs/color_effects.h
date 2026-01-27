#ifndef COLOR_EFFECTS_STRUCT_H
#define COLOR_EFFECTS_STRUCT_H

#include "types.h"

#include "constants/color_fading.h"

// Typedef

typedef u8 (*ColorFadingFunc_T)(u8, u8);
typedef u8 (*ColorFadingUnkFunc_T)(void);

// Structs

struct ColorFading {
    ColorFadingEffect type;
    u8 stage;
    u8 fadeTimer;
    u8 unk_3;
    ColorFadingStatus status;
    boolu8 useSecondColorSet;
    u16 workTimer;
};

struct ColorFadingData {
    boolu8 isWhite;
    ColorFadingUnkFunc_T pUpdateFunction;
    ColorFadingSpeed firstColorSet;
    ColorFadingUnkFunc_T pProcessFunction;
    ColorFadingSpeed secondColorSet;
    u16 bgColorMask;
    u16 objColorMask;
    ColorFadingFunction fadeFunction;
};

struct ColorFadingColorInfo {
    const u8* const colorArray;
    u8 size;
};

// Globals

extern struct ColorFading gColorFading;
extern u16 gBg3CntDuringDoorTransition;
extern u16 gBg1CntDuringDoorTransition;

#endif /* COLOR_EFFECTS_STRUCT_H */
