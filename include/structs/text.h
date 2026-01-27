#ifndef TEXT_STRUCT_H
#define TEXT_STRUCT_H

#include "types.h"
#include "macros.h"

struct Message {
    u16 textIndex;
    u16 indent;
    u16 timer;
    u8 color;
    u8 line;

    u8 continuousDelay;
    u8 delay;

    u8 messageId;
    u8 gfxSlot;
    u8 stage;
    u8 isMessage;
    u8 messageEnded;
};

extern struct Message gCurrentMessage;
extern s8 gCurrentItemBeingAcquired;

#ifdef USE_EWRAM_SYMBOLS
extern u32 gCurrentCharacterGfx[32];
#else
#define gCurrentCharacterGfx CAST_TO_ARRAY(u32, [32], EWRAM_BASE + 0x27700)
#endif /* USE_EWRAM_SYMBOLS */

#endif /* TEXT_STRUCT_H */
