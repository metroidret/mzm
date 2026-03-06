#ifndef SEARCHLIGHT_EYE_DATA_H
#define SEARCHLIGHT_EYE_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sSearchlightEyeGfx[177];
extern const u16 sSearchlightEyePal[16];

extern const struct FrameData sSearchlightEyeOam_Idle[13];
extern const struct FrameData sSearchlightEyeBeamOam_Idle[5];
extern const struct FrameData sSearchlightEyeBeamOam_Unused[2];
extern const struct FrameData sSearchlightEyeProjectileOam_Moving[9];
extern const struct FrameData sSearchlightEyeOam_Shooting[4];

#endif /* SEARCHLIGHT_EYE_DATA_H */
