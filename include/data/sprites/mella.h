#ifndef MELLA_DATA_H
#define MELLA_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sMellaIdleYMovement[65];

extern const s16 sMellaIdleXMovement[49];

extern const u16 sMellaGoingDownYMovement[6];

extern const u16 sMellaGoingUpYMovement[7];

extern const u16 sMellaMovingXMovement[7];

extern const u32 sMellaGfx[162];
extern const u16 sMellaPal[16];

extern const struct FrameData sMellaOam_Idle[9];
extern const struct FrameData sMellowOam_Moving[9];

#endif /* MELLA_DATA_H */
