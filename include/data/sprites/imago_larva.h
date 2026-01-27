#ifndef IMAGO_LARVA_DATA_H
#define IMAGO_LARVA_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

MAKE_ENUM(u8, ImagoLarvaOam) {
    IMAGO_LARVA_OAM_SHELL_ATTACKING,
    IMAGO_LARVA_OAM_SHELL_IDLE,
    IMAGO_LARVA_OAM_SHELL_RETREATING,
    IMAGO_LARVA_OAM_SHELL_DYING,
    IMAGO_LARVA_OAM_CLAWS_ATTACKING,
    IMAGO_LARVA_OAM_CLAWS_IDLE,
    IMAGO_LARVA_OAM_CLAWS_RETREATING,
    IMAGO_LARVA_OAM_CLAWS_TAKING_DAMAGE,
    IMAGO_LARVA_OAM_LEFT_DOT_APPEARING,
    IMAGO_LARVA_OAM_MIDDLE_DOT_APPEARING,
    IMAGO_LARVA_OAM_RIGHT_DOT_APPEARING,
    IMAGO_LARVA_OAM_LEFT_DOT_VISIBLE,
    IMAGO_LARVA_OAM_MIDDLE_DOT_VISIBLE,
    IMAGO_LARVA_OAM_RIGHT_DOT_VISIBLE,
    IMAGO_LARVA_OAM_LEFT_DOT_DISAPPEARING,
    IMAGO_LARVA_OAM_MIDDLE_DOT_DISAPPEARING,
    IMAGO_LARVA_OAM_RIGHT_DOT_DISAPPEARING,
    IMAGO_LARVA_OAM_SHELL_WARNING,
    IMAGO_LARVA_OAM_IDLE,
    IMAGO_LARVA_OAM_CLAWS_WARNING_FIRST_PART,
    IMAGO_LARVA_OAM_CLAWS_WARNING_SECOND_PART,
    IMAGO_LARVA_OAM_WARNING,
    IMAGO_LARVA_OAM_SHELL_TAKING_DAMAGE,

    IMAGO_LARVA_OAM_COUNT
};

extern const struct MultiSpriteData sImagoLarvaMultiSpriteData_Attacking[12];
extern const struct MultiSpriteData sImagoLarvaMultiSpriteData_Idle[5];
extern const struct MultiSpriteData sImagoLarvaMultiSpriteData_Retreating[12];
extern const struct MultiSpriteData sImagoLarvaMultiSpriteData_Dying[9];
extern const struct MultiSpriteData sImagoLarvaMultiSpriteData_Warning[10];
extern const struct MultiSpriteData sImagoLarvaMultiSpriteData_TakingDamage[5];

extern const u8 sImagoLarvaPaletteRows[4];

extern const u32 sImagoLarvaGfx[1195];
extern const u16 sImagoLarvaPal[80];

extern const struct FrameData sImagoLarvaPartOam_ShellAttacking[12];
extern const struct FrameData sImagoLarvaPartOam_ShellIdle[5];
extern const struct FrameData sImagoLarvaPartOam_ShellRetreating[12];
extern const struct FrameData sImagoLarvaPartOam_ShellDying[9];

extern const struct FrameData sImagoLarvaPartOam_ClawsAttacking[5];
extern const struct FrameData sImagoLarvaPartOam_ClawsIdle[5];
extern const struct FrameData sImagoLarvaPartOam_ClawsRetreating[5];
extern const struct FrameData sImagoLarvaPartOam_ClawsTakingDamage[4];

extern const struct FrameData sImagoLarvaPartOam_LeftDotAppearing[4];
extern const struct FrameData sImagoLarvaPartOam_MiddleDotAppearing[4];
extern const struct FrameData sImagoLarvaPartOam_RightDotAppearing[4];
extern const struct FrameData sImagoLarvaPartOam_LeftDotVisible[2];
extern const struct FrameData sImagoLarvaPartOam_MiddleDotVisible[2];
extern const struct FrameData sImagoLarvaPartOam_RightDotVisible[2];
extern const struct FrameData sImagoLarvaPartOam_LeftDotDisappearing[4];
extern const struct FrameData sImagoLarvaPartOam_MiddleDotDisappearing[4];
extern const struct FrameData sImagoLarvaPartOam_RightDotDisappearing[4];

extern const struct FrameData sImagoLarvaPartOam_ShellWarning[10];

extern const struct FrameData sImagoLarvaOam_Idle[9];

extern const struct FrameData sImagoLarvaPartOam_ClawsWarningFirstPart[3];
extern const struct FrameData sImagoLarvaPartOam_ClawsWarningSecondPart[3];

extern const struct FrameData sImagoLarvaOam_Warning[10];

extern const struct FrameData sImagoLarvaPartOam_ShellTakingDamage[5];

#endif /* IMAGO_LARVA_DATA_H */
