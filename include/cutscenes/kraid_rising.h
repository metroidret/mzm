#ifndef KRAID_RISING_CUTSCENE
#define KRAID_RISING_CUTSCENE

#include "types.h"
#include "gba.h"
#include "structs/cutscene.h"

enum KraidRisingOamId {
    KRAID_RISING_OAM_ID_SAMUS = 1,
    KRAID_RISING_OAM_ID_DEBRIS,
    KRAID_RISING_OAM_ID_SMALL_PUFF,
    KRAID_RISING_OAM_ID_BIG_PUFF,

    KRAID_RISING_OAM_ID_END
};

#define KRAID_RISING_PUFF_AMOUNT 11
#define KRAID_RISING_DEBRIS_AMOUNT 6

struct KraidRisingEwramData {
    u8 padding_0[BGCNT_VRAM_TILE_SIZE * 2];
    u8 barelyOpenedTileTable[BGCNT_VRAM_TILE_SIZE];
    u8 aLittleOpenedTileTable[BGCNT_VRAM_TILE_SIZE];
    u8 openedTileTable[BGCNT_VRAM_TILE_SIZE];
    u8 kraidRisingTileTable[BGCNT_VRAM_TILE_SIZE];
    u8 caveBackgroundTileTable[BGCNT_VRAM_TILE_SIZE];
};

#define KRAID_RISING_EWRAM sEwramPointer->kraidRising

u8 KraidRisingMainLoop(void);

#endif /* KRAID_RISING_CUTSCENE */
