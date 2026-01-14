#ifndef BEFORE_RUINS_TEST_CUTSCENE
#define BEFORE_RUINS_TEST_CUTSCENE

#include "types.h"
#include "structs/cutscene.h"
#include "macros.h"

#include "data/cutscenes/before_ruins_test_data.h"

struct BeforeRuinsTestEwramData {
    u16 wallPal[ARRAY_SIZE(sBeforeRuinsTestChozoWallPal)];

    u8 padding_100[0x300];

    u16 wallPalMonochromeTransition[ARRAY_SIZE(sBeforeRuinsTestChozoWallPal) * 2];
    
    u8 padding_500[0x3200];

    u16 wallPalMonochrome[ARRAY_SIZE(sBeforeRuinsTestChozoWallPal)];
};

#define BEFORE_RUINS_TEST_EWRAM sEwramPointer->beforeRuinsTest

u8 BeforeRuinsTestMainLoop(void);

#endif /* BEFORE_RUINS_TEST_CUTSCENE */
