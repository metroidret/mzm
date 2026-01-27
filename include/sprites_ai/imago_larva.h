#ifndef IMAGO_LARVA_AI_H
#define IMAGO_LARVA_AI_H

#include "types.h"
#include "macros.h"

MAKE_ENUM(u8, ImagoLarvaPartId) {
    IMAGO_LARVA_PART_CLAWS,
    IMAGO_LARVA_PART_RIGHT_DOT,
    IMAGO_LARVA_PART_MIDDLE_DOT,
    IMAGO_LARVA_PART_LEFT_DOT,
    IMAGO_LARVA_PART_SHELL,
    IMAGO_LARVA_PART_LARVA,

    IMAGO_LARVA_PART_COUNT
};

void ImagoLarva(void);
void ImagoLarvaPart(void);

#endif /* IMAGO_LARVA_AI_H */
