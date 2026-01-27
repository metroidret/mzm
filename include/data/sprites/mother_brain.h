#ifndef MOTHER_BRAIN_DATA_H
#define MOTHER_BRAIN_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

MAKE_ENUM(u8, MotherBrainOam) {
    MOTHER_BRAIN_OAM_IDLE,
    MOTHER_BRAIN_OAM_CHARGING_BEAM,
    MOTHER_BRAIN_OAM_EYE_CLOSED,
    MOTHER_BRAIN_OAM_2fa934,
    MOTHER_BRAIN_OAM_EYE_OPENING,
    MOTHER_BRAIN_OAM_2fa984,
    MOTHER_BRAIN_OAM_EYE_DYING,
    MOTHER_BRAIN_OAM_BOTTOM,
    MOTHER_BRAIN_OAM_BEAM_SPAWNING,
    MOTHER_BRAIN_OAM_BEAM_MOVING,

    MOTHER_BRAIN_OAM_COUNT
};

extern const struct MultiSpriteData sMotherBrainMultiSpriteData[7];

extern const u8 sMotherBrainDynamicPaletteData[19][2];

extern const u32 sMotherBrainGfx[1871];
extern const u16 sMotherBrainPal[96];

extern const struct FrameData sMotherBrainOam_Idle[12];
extern const struct FrameData sMotherBrainOam_ChargingBeam[5];

extern const struct FrameData sMotherBrainPartOam_EyeClosed[12];
extern const struct FrameData sMotherBrainPartOam_2fa934[5];
extern const struct FrameData sMotherBrainPartOam_EyeOpening[5];
extern const struct FrameData sMotherBrainPartOam_2fa984[8];
extern const struct FrameData sMotherBrainPartOam_EyeDying[5];

extern const struct FrameData sMotherBrainPartOam_Bottom[7];

extern const struct FrameData sMotherBrainPartOam_BeamSpawning[5];

extern const struct FrameData sMotherBrainBeamOam_Moving[3];

extern const struct FrameData sMotherBrainGlassBreakingOam_Breaking[18];

extern const struct FrameData sMotherBrainPartOam_EyeClosing[4];

#endif /* MOTHER_BRAIN_DATA_H */
