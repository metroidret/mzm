#ifndef SOFT_RESET_H
#define SOFT_RESET_H

#include "types.h"

u32 SoftResetMainLoop(void);
void SoftResetInit(void);
void SoftResetVBlank(void);
void SoftResetVBlank_Empty(void);

#endif /* SOFT_RESET_H */
