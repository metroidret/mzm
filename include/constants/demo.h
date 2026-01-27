#ifndef DEMO_CONSTANTS_H
#define DEMO_CONSTANTS_H

#include "types.h"
#include "macros.h"

MAKE_ENUM(u8, DemoState) {
    DEMO_STATE_NONE,
    DEMO_STATE_RECORDING_DEBUG,
    DEMO_STATE_PLAYING,
    DEMO_STATE_STARTING
};

#endif /* DEMO_CONSTANTS_H */
