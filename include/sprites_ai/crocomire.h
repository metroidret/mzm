#ifndef CROCOMIRE_AI_H
#define CROCOMIRE_AI_H

#include "types.h"

enum CrocomirePart {
    CROCOMIRE_PART_RIGHT_ARM,
    CROCOMIRE_PART_HEAD,
    CROCOMIRE_PART_LEGS,
    CROCOMIRE_PART_BODY,
    CROCOMIRE_PART_TONGUE,
    CROCOMIRE_PART_LEFT_ARM,

    CROCOMIRE_PART_END
};

void Crocomire(void);
void CrocomirePart(void);

#endif /* CROCOMIRE_AI_H */