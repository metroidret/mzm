#ifndef GLOBALS_H
#define GLOBALS_H

#include "types.h"

extern u32 gInterruptCode[0x80];

extern Func_T gIntrVector[13];
extern u32 (*gIntrCodePointer)[0x80];

extern u16 gInterruptCheckFlag;

#endif /* GLOBALS_H */
