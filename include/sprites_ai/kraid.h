#ifndef KRAID_AI_H
#define KRAID_AI_H

#include "types.h"

enum KraidPart {
    KRAID_PART_BELLY,
    KRAID_PART_LEFT_ARM,
    KRAID_PART_TOP_HOLE_LEFT,
    KRAID_PART_TOP_HOLE_RIGHT,
    KRAID_PART_MIDDLE_HOLE_LEFT,
    KRAID_PART_MIDDLE_HOLE_RIGHT,
    KRAID_PART_KRAID,
    KRAID_PART_BOTTOM_HOLE_LEFT,
    KRAID_PART_BOTTOM_HOLE_RIGHT,
    KRAID_PART_LEFT_FEET,
    KRAID_PART_RIGHT_ARM,
    KRAID_PART_RIGHT_FEET,

    KRAID_PART_END
};

void Kraid(void);
void KraidPart(void);
void KraidSpike(void);
void KraidNail(void);

#endif /* KRAID_AI_H */
