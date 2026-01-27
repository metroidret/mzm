#ifndef MOTHER_BRAIN_AI_H
#define MOTHER_BRAIN_AI_H

#include "types.h"
#include "macros.h"

// Mother brain part

MAKE_ENUM(u8, MotherBrainPartId) {
    MOTHER_BRAIN_PART_BEAM_SHOOTER,
    MOTHER_BRAIN_PART_BODY,
    MOTHER_BRAIN_PART_EYE,
    MOTHER_BRAIN_PART_BOTTOM,

    MOTHER_BRAIN_PART_COUNT
};

void MotherBrain(void);
void MotherBrainPart(void);
void MotherBrainBeam(void);
void MotherBrainBlock(void);
void MotherBrainGlassBreaking(void);

#endif /* MOTHER_BRAIN_AI_H */
