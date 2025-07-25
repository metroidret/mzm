#ifndef HAZE_STRUCT_H
#define HAZE_STRUCT_H

#include "types.h"

typedef u32 (*HazeFunc_T)(void);

struct Haze {
    void* pAffected;
    u16 unk_4;
    u8 size;
    u8 enabled:7;
    u8 active:1;
};

struct HazeLoop {
    s16 timer;
    u8 unk_2;
    u8 unk_3;
};

extern struct Haze gHazeInfo;
extern struct HazeLoop gHazeLoops[3];

extern u8 gUnk_3005728;
extern u8 gUnk_3005729;

extern u8 gUnk_3005514;

extern HazeFunc_T gHazeProcessCodePointer;

extern u8 gCurrentHazeValue;

#ifdef USE_EWRAM_SYMBOLS
extern u16 gHazeValues[1280];
extern u16 gPreviousHazeValues[1280];
#else
#define gHazeValues CAST_TO_ARRAY(u16, [1280], EWRAM_BASE + 0x26300)
#define gPreviousHazeValues CAST_TO_ARRAY(u16, [1280], EWRAM_BASE + 0x26D00)
#endif /* USE_EWRAM_SYMBOLS */

#endif /* HAZE_STRUCT_H */
