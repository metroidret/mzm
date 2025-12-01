#ifndef BG_CLIP_STRUCT_H
#define BG_CLIP_STRUCT_H

#include "types.h"
#include "structs/connection.h"

// Macros

/**
 * Gets a background block value using `gBgPointersAndDimensions` (order is y * width + x)
 */
#define GET_BG_BLOCK(bg, x, y) gBgPointersAndDimensions.backgrounds[bg].pDecomp[(y) * gBgPointersAndDimensions.backgrounds[bg].width + (x)]
/**
 * Gets a background block value using `gBgPointersAndDimensions` (order is width * y + x)
 */
#define GET_BG_BLOCK_(bg, x, y) gBgPointersAndDimensions.backgrounds[bg].pDecomp[gBgPointersAndDimensions.backgrounds[bg].width * (y) + (x)]
/**
 * Gets a clipdata block value using `gBgPointersAndDimensions` (order is y * width + x)
 */
#define GET_CLIP_BLOCK(x, y) gBgPointersAndDimensions.pClipDecomp[(y) * gBgPointersAndDimensions.clipdataWidth + (x)]
/**
 * Gets a clipdata block value using `gBgPointersAndDimensions` (order is width * y + x)
 */
#define GET_CLIP_BLOCK_(x, y) gBgPointersAndDimensions.pClipDecomp[gBgPointersAndDimensions.clipdataWidth * (y) + (x)]
/**
 * Sets a background block value using `gBgPointersAndDimensions` (order is y * width + x)
 */
#define SET_BG_BLOCK(bg, value, x, y) GET_BG_BLOCK(bg, x, y) = value
/**
 * Sets a background block value using `gBgPointersAndDimensions` (order is width * y + x)
 */
#define SET_BG_BLOCK_(bg, value, x, y) GET_BG_BLOCK_(bg, x, y) = value
/**
 * Sets a clipdata block value using `gBgPointersAndDimensions` (order is y * width + x)
 */
#define SET_CLIP_BLOCK(value, x, y) GET_CLIP_BLOCK(x, y) = value
/**
 * Sets a clipdata block value using `gBgPointersAndDimensions` (order is width * y + x)
 */
#define SET_CLIP_BLOCK_(value, x, y) GET_CLIP_BLOCK_(x, y) = value

// Structs

struct BackgroundPointersAndDimensions {
    struct {
        u16* pDecomp;
        u16 width;
        u16 height;
    } backgrounds[3];
    u16* pClipDecomp;
    u16 clipdataWidth;
    u16 clipdataHeight;
};

struct BG2Movement {
    s16 xOffset;
    s16 yOffset;
};

struct LastTank {
    u16 behavior;
    u8 xPosition;
    u8 yPosition;
};

struct ItemInfo {
    u8 room;
    s8 type;
    u8 xPosition;
    u8 yPosition;
};

// Globals

#define MAX_AMOUNT_OF_ITEMS_PER_AREA 64
#define MAX_AMOUNT_OF_NEVER_REFORM_BLOCK_PER_AREA 256
// The number of bytes required to save a never reform block
#define NEVER_REFORM_BLOCK_INFO_SIZE 2
#define NEVER_REFORM_BLOCKS_SIZE (MAX_AMOUNT_OF_NEVER_REFORM_BLOCK_PER_AREA * NEVER_REFORM_BLOCK_INFO_SIZE)

#ifdef USE_EWRAM_SYMBOLS
extern struct ItemInfo gItemsCollected[MAX_AMOUNT_OF_AREAS][MAX_AMOUNT_OF_ITEMS_PER_AREA];
extern u8 gNeverReformBlocks[MAX_AMOUNT_OF_AREAS][512];
#else
#define gItemsCollected CAST_TO_ARRAY(struct ItemInfo, [MAX_AMOUNT_OF_AREAS][MAX_AMOUNT_OF_ITEMS_PER_AREA], EWRAM_BASE + 0x36C00)
#define gNeverReformBlocks CAST_TO_ARRAY(u8, [MAX_AMOUNT_OF_AREAS][NEVER_REFORM_BLOCKS_SIZE], EWRAM_BASE + 0x35C00)
#endif /* USE_EWRAM_SYMBOLS */

extern u8 gNumberOfNeverReformBlocks[MAX_AMOUNT_OF_AREAS];
extern u8 gNumberOfItemsCollected[MAX_AMOUNT_OF_AREAS];
extern struct LastTank gLastTankCollected;
extern struct BackgroundPointersAndDimensions gBgPointersAndDimensions;

extern struct BG2Movement gBg2Movement;
extern struct BG3Movement gBg3Movement;
extern struct BG0Movement gBg0Movement;

extern u16 gBg0XPosition;
extern u16 gBg0YPosition;
extern u16 gBg1XPosition;
extern u16 gBg1YPosition;
extern u16 gBg2XPosition;
extern u16 gBg2YPosition;
extern u16 gBg3XPosition;
extern u16 gBg3YPosition;

extern s8 gCollectingTank;
extern u8 gDisableDoorAndTanks;
extern u8 gDisableClipdataChangingTransparency;

#endif /* BG_CLIP_STRUCT_H */
