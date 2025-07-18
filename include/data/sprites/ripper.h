#ifndef RIPPER_DATA_H
#define RIPPER_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sRipperBrownGfx[141];
extern const u16 sRipperBrownPal[16];
extern const u32 sRipperPurpleGfx[141];
extern const u16 sRipperPurplePal[16];

extern const struct FrameData sRipperOam_Moving[5];
extern const struct FrameData sRipperOam_TurningAround[3];
extern const struct FrameData sRipperOam_TurningAroundPart2[3];

#endif /* RIPPER_DATA_H */
