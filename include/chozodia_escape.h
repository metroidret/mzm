#ifndef CHOZODIA_ESCAPE_H
#define CHOZODIA_ESCAPE_H

#include "types.h"

typedef u8 (*ChozodiaEscapeFunc_T)(void);

u32 ChozodiaEscapeGetItemCountAndEndingNumber(void);
u32 ChozodiaEscapeMainLoop(void);

#endif /* CHOZODIA_ESCAPE_H */
