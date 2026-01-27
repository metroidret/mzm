#ifndef BLOCK_DATA_H
#define BLOCK_DATA_H

#include "types.h"

#include "constants/block.h"
#include "constants/clipdata.h"
#include "constants/connection.h"
#include "constants/game_state.h"

#include "structs/block.h"
#include "structs/connection.h"

extern const struct TankList sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS];

extern const struct TankList sStartingHealthAmmo;

extern const struct TankList sTankIncreaseAmount[DIFF_COUNT];

extern const CaaDamageType sClipdataAffectingActionDamageTypes[CAA_COUNT];

extern const struct BlockBehavior sBlockBehaviors[BEHAVIOR_BLOCK_AMOUNT];

extern const CaaDamageType sBlockWeaknesses[BLOCK_TYPE_COUNT];

extern const ClipdataTilemap sReformingBlocksTilemapValue[BLOCK_TYPE_COUNT];

extern const u8 sBrokenBlocksTimers[BLOCK_TYPE_COUNT][13];

extern const struct BombChainReverseData sBombChainReverseData[8];

extern const struct TankBehavior sTankBehaviors[BEHAVIOR_TANK_AMOUNT];

extern const u16 sHatchBehaviors[HATCH_COUNT][2];

extern const u16 sBldalphaValuesForClipdata[BEHAVIOR_BLDALPHA_AMOUNT];

extern const s8 sSubBombChainPositionOffset[4][4];

extern const u8 sBlockTouchOffsets[4][2];

extern const u16 sMotherBrainGlassBreakingBaseTilemapValues[5];

#endif /* BLOCK_DATA_H */
