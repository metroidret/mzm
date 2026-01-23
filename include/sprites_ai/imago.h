#ifndef IMAGO_AI_H
#define IMAGO_AI_H

#include "types.h"

enum ImagoPart {
    IMAGO_PART_LEFT_WING_INTERNAL,
    IMAGO_PART_LEFT_WING_EXTERNAL,
    IMAGO_PART_BODY,
    IMAGO_PART_RIGHT_WING_INTERNAL,
    IMAGO_PART_RIGHT_WING_EXTERNAL,
    IMAGO_PART_CORE,
    IMAGO_PART_IMAGO,

    IMAGO_PART_END
};

void Imago(void);
void ImagoPart(void);
void ImagoNeedle(void);
void ImagoDamagedStinger(void);
void ImagoEgg(void);

#endif /* IMAGO_AI_H */