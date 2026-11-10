#ifndef SCROLL_STRUCT_H
#define SCROLL_STRUCT_H

#include "types.h"
#include "macros.h"

MAKE_ENUM(u8, ScrollSubData) {
    // Left bound
    SCROLL_SUB_DATA_X_START,
    // Right bound
    SCROLL_SUB_DATA_X_END,
    // Top bound
    SCROLL_SUB_DATA_Y_START,
    // Bottom bound
    SCROLL_SUB_DATA_Y_END,
    // Breakable block X position
    SCROLL_SUB_DATA_BREAKABLE_X,
    // Breakable block Y position
    SCROLL_SUB_DATA_BREAKABLE_Y,
    // Which direction 
    SCROLL_SUB_DATA_EXTENDED_DIRECTION,
    SCROLL_SUB_DATA_EXTENDED_VALUE,

    SCROLL_SUB_DATA_COUNT
};

#define SCROLL_DATA_SIZE(nbrScrolls) (2 + SCROLL_SUB_DATA_COUNT * nbrScrolls)

MAKE_ENUM(u8, ScrollExtensionDirection) {
    SCROLL_EXTENSION_DIRECTION_LEFT,
    SCROLL_EXTENSION_DIRECTION_RIGHT,
    SCROLL_EXTENSION_DIRECTION_TOP,
    SCROLL_EXTENSION_DIRECTION_BOTTOM,

    SCROLL_EXTENSION_DIRECTION_NONE = UCHAR_MAX
};

struct PACKED ScrollBounds {
    u8 start;
    u8 end;
};

struct ScrollExtension {
    // Breakable block X position
    u8 breakable_x;
    // Breakable block Y position
    u8 breakable_y;
    // The bound to extend
    ScrollExtensionDirection extention_direction;
    // The extended bound value
    u8 extended_bound;
};

#define SCROLL_EXTENSION_NONE \
(struct ScrollExtension) { \
    .breakable_x = UCHAR_MAX, \
    .breakable_y = UCHAR_MAX, \
    .extention_direction = SCROLL_EXTENSION_DIRECTION_NONE, \
    .extended_bound = UCHAR_MAX \
}

struct PACKED ScrollSub {
    struct ScrollBounds x_bounds;
    struct ScrollBounds y_bounds;
    struct ScrollExtension extension;
};

#define ScrollArray(length) ScrollArray_##length

// Variable-lenght arrays would be a better fit, especially with the GNU
// extension that allows declaring static ones, but agbcc doesn't support these.
// This works around that limitation by offering some phony template.
#define DEFINE_SCROLL_ARRAY(length) \
struct PACKED ScrollArray(length) { \
    u8 room; \
    u8 scrolls_len; \
    struct ScrollSub scrolls[length]; \
};

// We unfortunately have to manually define types for all the required sizes as
// we can't automatically declare them if they aren't defined yet in a macro as
// C doesn't support nested macros.
DEFINE_SCROLL_ARRAY(3)

MAKE_ENUM(u8, LockScreenType) {
    LOCK_SCREEN_TYPE_NONE,
    LOCK_SCREEN_TYPE_POSITION,
    LOCK_SCREEN_TYPE_MIDDLE
};

#define SCROLL_NOT_WITHIN_FLAG 0
#define SCROLL_WITHIN_FLAG 2

MAKE_ENUM(u8, ScrollVelocityCap) {
    SCROLL_VELOCITY_CAP_SET_DEFAULT,
    SCROLL_VELOCITY_CAP_SET_SLOW,
    SCROLL_VELOCITY_CAP_SET_FAST,

    SCROLL_VELOCITY_CAP_COUNT
};

MAKE_ENUM(u8, bg3ScrollingType) {
    BG3_SCROLLING_TYPE_NONE,
    BG3_SCROLLING_TYPE_NORMAL,
    BG3_SCROLLING_TYPE_HALVED,
    BG3_SCROLLING_TYPE_QUARTERED
};

#define SCROLL_X_ANCHOR (SCREEN_SIZE_X_SUB_PIXEL / 2)
#define SCROLL_Y_ANCHOR ((s32)(SCREEN_SIZE_Y_SUB_PIXEL * .6f))

struct Scroll {
    u8 within;
    u16 xEnd;
    u16 xStart;
    u16 yStart;
    u16 yEnd;
};

struct Camera {
    u16 xPosition;
    u16 yPosition;
    s8 xVelocity;
    s8 yVelocity;
};

struct LockScreen {
    LockScreenType lock;
    u16 xPositionCenter;
    u16 yPositionCenter;
};

struct CameraScrollVelocityCaps {
    s16 leftCap;
    s16 rightCap;
    s16 upCap;
    s16 downCap;
};


extern u8 gDisableScrolling;
extern u16 gSlowScrollingTimer;
extern boolu8 gSkipDoorTransition;
extern struct Scroll gCurrentScrolls[2];
extern struct Camera gCamera;
extern struct LockScreen gLockScreen;
extern s8 gScreenYOffset;
extern s16 gScreenXOffset;

extern u8 gNoClipLockCamera;
extern struct CameraScrollVelocityCaps gScrollingVelocityCaps;
extern const u8* gCurrentRoomScrollDataPointer;

#endif /* SCROLL_STRUCT_H */
