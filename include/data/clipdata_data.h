#ifndef CLIPDATA_DATA_H
#define CLIPDATA_DATA_H

#include "types.h"

#include "constants/connection.h"
#include "constants/room.h"

#include "structs/clipdata.h"
#include "structs/scroll.h"

extern const u16 sMovementClipdataValues[16];
extern const u16 sHazardsDefinitions[EFFECT_HAZARD_COUNT][2];
extern const u16 sHazardClipdataValues[4];
extern const GroundEffect sGroundEffectsClipdataValues[8];
extern const struct ElevatorPair sElevatorRoomPairs[ELEVATOR_ROUTE_COUNT]; 
extern const u8 sScroll_Empty[11];
extern const struct CameraScrollVelocityCaps sScrollVelocityCaps[SCROLL_VELOCITY_CAP_COUNT];

#endif /* CLIPDATA_DATA_H */
