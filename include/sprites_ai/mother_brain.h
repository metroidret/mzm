#ifndef MOTHER_BRAIN_AI_H
#define MOTHER_BRAIN_AI_H

#include "types.h"

// Mother brain part

enum MotherBrainPart {
    MOTHER_BRAIN_PART_BEAM_SHOOTER,
    MOTHER_BRAIN_PART_BODY,
    MOTHER_BRAIN_PART_EYE,
    MOTHER_BRAIN_PART_BOTTOM,

    MOTHER_BRAIN_PART_END
};

void MotherBrain(void);
void MotherBrainPart(void);
void MotherBrainBeam(void);
void MotherBrainBlock(void);
void MotherBrainGlassBreaking(void);

#endif /* MOTHER_BRAIN_AI_H */