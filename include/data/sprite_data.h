#ifndef SPRITE_DATA_H
#define SPRITE_DATA_H

#include "types.h"
#include "constants/sprite.h"

#define GET_PSPRITE_HEALTH(id) sPrimarySpriteStats[(id)][SPRITE_STATS_HEALTH]
#define GET_SSPRITE_HEALTH(id) sSecondarySpriteStats[(id)][SPRITE_STATS_HEALTH]

#define GET_PSPRITE_DAMAGE(id) sPrimarySpriteStats[(id)][SPRITE_STATS_DAMAGE]
#define GET_SSPRITE_DAMAGE(id) sSecondarySpriteStats[(id)][SPRITE_STATS_DAMAGE]

#define GET_PSPRITE_WEAKNESS(id) sPrimarySpriteStats[(id)][SPRITE_STATS_WEAKNESSES]
#define GET_SSPRITE_WEAKNESS(id) sSecondarySpriteStats[(id)][SPRITE_STATS_WEAKNESSES]

// 2b0c94

extern const u8 sOamXFlipOffsets[3][4];

extern const u8 sOamYFlipOffsets[3][4];

extern const u8 sSpriteRandomNumberTable[32];

extern const s16 sSpritesFallingCeilingSpeed[16];

extern const s16 sSpritesFallingSpeed[16];

extern const s16 sSpritesFallingSpeed_Unused[8];

extern const s16 sSpritesFallingSpeed_Unused2[16];

extern const s16 sWorkerRobotSleepingFallingSpeed[10];

/**
 * @brief Stats of the primary sprites
 * 0 : Spawn health
 * 1 : Damage
 * 2 : Weaknesses
 * 3 : No drop probability
 * 4 : Small health drop probability
 * 5 : Large health drop probability
 * 6 : Missile drop probability
 * 7 : Super missile drop probability
 * 8 : Power bomb drop probability
 */
extern const u16 sPrimarySpriteStats[PSPRITE_COUNT][9];

/**
 * @brief Stats of the secondary sprites
 * 0 : Spawn health
 * 1 : Damage
 * 2 : Weaknesses
 * 3 : No drop probability
 * 4 : Small health drop probability
 * 5 : Large health drop probability
 * 6 : Missile drop probability
 * 7 : Super missile drop probability
 * 8 : Power bomb drop probability
 */
extern const u16 sSecondarySpriteStats[SSPRITE_COUNT][9];

#endif /* SPRITE_DATA_H */
