#ifndef MINIMAP_STRUCT_H
#define MINIMAP_STRUCT_H

#include "types.h"

#include "constants/minimap.h"

#include "structs/connection.h"

#define MINIMAP_SIZE 32
#define MINIMAP_CENTER ((MINIMAP_SIZE * HALF_BLOCK_SIZE) / 2 + PIXEL_SIZE)

typedef void (*MinimapFunc_T)(u32*, u16*, u8);

struct LastAreaName {
    u8 flags;
    Area area;
    u8 mapX;
    u8 mapY;
};

extern struct LastAreaName gLastAreaNameVisited;
extern u8 gMinimapX;
extern u8 gMinimapY;
extern MinimapUpdateFlag gUpdateMinimapFlag;

#ifdef USE_EWRAM_SYMBOLS
extern u32 gMinimapTilesWithObtainedItems[MAX_AMOUNT_OF_AREAS * MINIMAP_SIZE];
extern u16 gDecompressedMinimapVisitedTiles[MINIMAP_SIZE * MINIMAP_SIZE];
extern u16 gDecompressedMinimapData[MINIMAP_SIZE * MINIMAP_SIZE];
extern u32 gVisitedMinimapTiles[MAX_AMOUNT_OF_AREAS * MINIMAP_SIZE];
extern u32 gMinimapTilesGfx[5 * 24];
#else
#define gMinimapTilesWithObtainedItems CAST_TO_ARRAY(u32, [MAX_AMOUNT_OF_AREAS][MINIMAP_SIZE], EWRAM_BASE + 0x33800)
#define gDecompressedMinimapVisitedTiles CAST_TO_ARRAY(u16, [MINIMAP_SIZE * MINIMAP_SIZE], EWRAM_BASE + 0x34000)
#define gDecompressedMinimapData CAST_TO_ARRAY(u16, [MINIMAP_SIZE * MINIMAP_SIZE], EWRAM_BASE + 0x34800)
#define gVisitedMinimapTiles CAST_TO_ARRAY(u32, [MAX_AMOUNT_OF_AREAS][MINIMAP_SIZE], EWRAM_BASE + 0x37400)
#define gMinimapTilesGfx CAST_TO_ARRAY(u32, [5 * 24], EWRAM_BASE + 0x37E20)
#endif /* USE_EWRAM_SYMBOLS */

#endif /* MINIMAP_STRUCT_H */
