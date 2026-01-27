#ifndef CONNECTION_STRUCT_H
#define CONNECTION_STRUCT_H

#include "types.h"
#include "macros.h"

#include "constants/connection.h"
#include "constants/event.h"

#include "structs/animated_graphics.h"

// Structs

struct Door {
    DoorType type;
    u8 sourceRoom;
    u8 xStart;
    u8 xEnd;
    u8 yStart;
    u8 yEnd;
    u8 destinationDoor;
    s8 xExit;
    s8 yExit;
};

struct EventBasedConnection {
    Area sourceArea;
    u8 sourceDoor;
    Event event;
    u8 destinationDoor;
};

struct HatchLockEvent {
    u8 room;
    Event event;
    HatchLockEventType type;
    boolu8 hatchesToLock_0:1;
    boolu8 hatchesToLock_1:1;
    boolu8 hatchesToLock_2:1;
    boolu8 hatchesToLock_3:1;
    boolu8 hatchesToLock_4:1;
    boolu8 hatchesToLock_5:1;
    boolu8 hatchesToLock_6:1;
    boolu8 hatchesToLock_7:1;
    boolu8 hatchesToLock_8:1;
    boolu8 hatchesToLock_9:1;
    boolu8 hatchesToLock_10:1;
    boolu8 hatchesToLock_11:1;
    boolu8 hatchesToLock_12:1;
    boolu8 hatchesToLock_13:1;
    boolu8 hatchesToLock_14:1;
    boolu8 hatchesToLock_15:1;
};

struct HatchData {
    /* 0 */
    boolu16 exists:1;
    u16 currentAnimationFrame:3;
    boolu16 facingRight:1;
    u16 securityLevel:3; // Left over from fusion
    /* 1 */
    HatchState state:2;
    HatchLockState locked:2;
    u16 flashingTimer:4;
    /* 2 */
    u16 hitTimer:4;
    u16 hits:4;
    /* 3 */
    HatchType type;
    u8 animationDurationCounter;
    u8 xPosition;
    u8 yPosition;
    u8 sourceDoor;
};

struct LastElevatorUsed {
    u16 unused;
    ElevatorRoute route;
    ElevatorDirection direction;
};

struct HatchesState {
    bools8 unlocking;
    bools8 navigationDoorsUnlocking;
    u16 hatchesLockedWithTimer;
    u16 hatchesLockedWithEvent;
    u16 hatchesLockedWithEventUnlockable;
};

MAKE_ENUM(u8, AreaConnectionField) {
    AREA_CONNECTION_FIELD_SOURCE_AREA,
    AREA_CONNECTION_FIELD_SOURCE_DOOR,
    AREA_CONNECTION_FIELD_DESTINATION_AREA,

    AREA_CONNECTION_FIELD_COUNT
};

MAKE_ENUM(u8, EventBasedConnectionField) {
    EVENT_BASED_CONNECTION_FIELD_SOURCE_AREA,
    EVENT_BASED_CONNECTION_FIELD_SOURCE_DOOR,
    EVENT_BASED_CONNECTION_FIELD_EVENT,
    EVENT_BASED_CONNECTION_FIELD_DESTINATION_DOOR,

    EVENT_BASED_CONNECTION_FIELD_COUNT
};

#define MAX_AMOUNT_OF_HATCHES 16
#define MAX_AMOUNT_OF_AREAS 8

#ifdef USE_EWRAM_SYMBOLS
extern u32 gHatchesOpened[MAX_AMOUNT_OF_AREAS][8];
#else
#define gHatchesOpened CAST_TO_ARRAY(u32, [MAX_AMOUNT_OF_AREAS][8], EWRAM_BASE + 0x37C00)
#endif /* USE_EWRAM_SYMBOLS */

extern u8 gWhichBGPositionIsWrittenToBG3OFS;
extern struct Coordinates gDoorPositionStart;
extern boolu8 gUseMotherShipDoors;
extern Area gCurrentArea;
extern Area gAreaBeforeTransition;
extern u8 gCurrentRoom;
extern u8 gLastDoorUsed;
extern u8 gLastDoorProperties;
extern boolu8 gDisplayLocationText;
extern s8 gDoorUnlockTimer;
extern struct HatchesState gHatchesState;
extern struct HatchData gHatchData[MAX_AMOUNT_OF_HATCHES];
extern struct LastElevatorUsed gLastElevatorUsed;
extern u8 gNumberOfValidHatchesInRoom;

extern struct AnimatedPaletteTiming gHatchFlashingAnimation;

#define LOCK_DOORS() gDoorUnlockTimer = 1

#endif /* CONNECTION_STRUCT_H */
