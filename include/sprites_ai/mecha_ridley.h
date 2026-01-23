#ifndef MECHA_RIDLEY_AI_H
#define MECHA_RIDLEY_AI_H

#include "types.h"

enum MechaRidleyPart {
    MECHA_RIDLEY_PART_RIGHT_ARM,
    MECHA_RIDLEY_PART_EYE,
    MECHA_RIDLEY_PART_HEAD,
    MECHA_RIDLEY_PART_NECK,
    MECHA_RIDLEY_PART_COVER,
    MECHA_RIDLEY_PART_CORE,
    MECHA_RIDLEY_PART_TORSO,
    MECHA_RIDLEY_PART_WAISTBAND,
    MECHA_RIDLEY_PART_LEFT_ARM,
    MECHA_RIDLEY_PART_TAIL,
    MECHA_RIDLEY_PART_MISSILE_LAUNCHER,

    MECHA_RIDLEY_PART_END
};

void MechaRidley(void);
void MechaRidleyPart(void);
void MechaRidleyLaser(void);
void MechaRidleyMissile(void);
void MechaRidleyFireball(void);

#endif /* MECHA_RIDLEY_AI_H */
