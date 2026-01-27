#ifndef CLIPDATA_STRUCT_H
#define CLIPDATA_STRUCT_H

#include "types.h"

#include "constants/clipdata.h"
#include "constants/connection.h"

// Structs

struct ElevatorPair {
    Area area1;
    u8 room1;
    u8 mapX1;
    u8 mapY1;
    Area area2;
    u8 room2;
    u8 mapX2;
    u8 mapY2;
};

struct CurrentAffectingClip {
    ClipdataMovement movement;
    HazardType hazard;
};

struct CollisionData {
    s32 clipdataType;
    s32 subPixelX;
    s32 subPixelY;
    ClipdataActor actorType;
    u16 tileX;
    u16 tileY;
};

struct TilemapAndClipPointers {
    u16* pTilemap;
    u8* pClipCollisions;
    u16* pClipBehaviors;
};

// Typedef

typedef u32 (*ClipFunc_T)(struct CollisionData*);


// Globals

extern ClipFunc_T gClipdataCodePointer;
extern ClipdataAffectingAction gCurrentClipdataAffectingAction;
extern struct CurrentAffectingClip gCurrentAffectingClipdata;
extern struct TilemapAndClipPointers gTilemapAndClipPointers;

extern u16 gEffectYPosition;
extern s16 gEffectYPositionOffset;

#endif /* CLIPDATA_STRUCT_H */
