#ifndef IMAGO_COCOON_AI_H
#define IMAGO_COCOON_AI_H

#include "types.h"
#include "macros.h"

MAKE_ENUM(u8, ImagoCocoonPartId) {
    IMAGO_COCOON_PART_VINE_LEFT_VINE_DECORATIONS,
    IMAGO_COCOON_PART_VINE_LEFT_MIDDLE,
    IMAGO_COCOON_PART_VINE_RIGHT_MIDDLE,
    IMAGO_COCOON_PART_CEILING_VINE,
    IMAGO_COCOON_PART_IMAGO_COCOON,
    IMAGO_COCOON_PART_VINE_RIGHT_VINE_DECORATIONS,
    IMAGO_COCOON_PART_VINE_RIGHT_RIGHT,
    IMAGO_COCOON_PART_VINE_LEFT_LEFT,
    IMAGO_COCOON_PART_VINE_RIGHT_LEFT,
    IMAGO_COCOON_PART_VINE_LEFT_RIGHT,

    IMAGO_COCOON_PART_COUNT
};

void ImagoCocoon(void);
void ImagoCocoonVine(void);
void ImagoCocoonSpore(void);
void WingedRipper(void);
void DefeatedImagoCocoon(void);
void ImagoCocoonCeilingVine(void);
void EventTriggerDiscoveredImagoPassage(void);
void ImagoCocoonAfterFight(void);

#endif /* IMAGO_COCOON_AI_H */
