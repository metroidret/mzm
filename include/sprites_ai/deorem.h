#ifndef DEOREM_AI_H
#define DEOREM_AI_H

#include "types.h"
#include "constants/projectile.h"

// Spawn health of deorem
#define DEOREM_MAX_HEALTH (MISSILE_DAMAGE * 3)

void Deorem(void);
void DeoremSegment(void);
void DeoremEye(void);
void DeoremThorn(void);

#endif /* DEOREM_AI_H */
