#ifndef PAUSE_SCREEN_SUB_MENUS_DATA_H
#define PAUSE_SCREEN_SUB_MENUS_DATA_H

#include "types.h"

#include "constants/menus/pause_screen.h"
#include "constants/event.h"

#include "structs/menus/pause_screen.h"

extern const struct ChozoStatueTarget sChozoStatueTargets[TARGET_COUNT];

extern const u8 sChozoStatueTargetConditions[TARGET_COUNT][2];
extern const Event sChozoStatueHintEvents[TARGET_COUNT];

extern const s8 sChozoStatueTargetPathBrinstar[9][2];
extern const s8 sChozoStatueTargetPathKraid[9][2];
extern const s8 sChozoStatueTargetPathNorfair[9][2];
extern const s8 sChozoStatueTargetPathRidley[9][2];
extern const s8 sChozoStatueTargetPathCrateria[9][2];

#endif /* PAUSE_SCREEN_SUB_MENUS_DATA_H */
