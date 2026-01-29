#include "minimap.h"
#include "dma.h"
#include "gba.h"
#include "macros.h"

#include "data/shortcut_pointers.h"
#include "data/menus/pause_screen_data.h"
#include "data/menus/pause_screen_map_data.h"

#include "constants/connection.h"
#include "constants/game_state.h"
#include "constants/minimap.h"

#include "structs/bg_clip.h"
#include "structs/game_state.h"
#include "structs/minimap.h"
#include "structs/samus.h"
#include "structs/room.h"

#ifdef DEBUG
static void MinimapDrawNumber(u8 value, void* dst);
#endif // DEBUG
static void MinimapSetTileAsExplored(void);
static void MinimapCheckForUnexploredTile(void);
static void MinimapUpdateForExploredTiles(void);
static void MinimapCopyTileGfx(u32* dst, u16* pTile, u8 palette);
static void MinimapCopyTileXFlippedGfx(u32* dst, u16* pTile, u8 palette);
static void MinimapCopyTileYFlippedGfx(u32* dst, u16* pTile, u8 palette);
static void MinimapCopyTileXYFlippedGfx(u32* dst, u16* pTile, u8 palette);

extern const struct RoomEntryRom* sAreaRoomEntryPointers[AREA_ENTRY_COUNT];

#ifdef DEBUG

/**
 * @brief Draws room ID and coordinates on the minimap
 * 
 */
void MinimapDrawRoomInfo(void)
{
    MinimapDrawNumber(gCurrentRoom, VRAM_OBJ + 0x12E0);
    MinimapDrawNumber(gMinimapX, VRAM_OBJ + 0x1340);
    MinimapDrawNumber(gMinimapY, VRAM_OBJ + 0x13A0);
}

/**
 * @brief Draws a number on the minimap
 * 
 * @param value Number to draw
 * @param dst Destination address
 */
static void MinimapDrawNumber(u8 value, void* dst)
{
    s32 zeroTile;
    s32 divisor;
    s32 tile;

    zeroTile = 10;
    divisor = 100;

    while (divisor > 0)
    {
        if (divisor == 1)
            zeroTile = 0;

        tile = ((value + 1) / divisor) % 10;
        if (tile == 0)
            tile = zeroTile;
        else
            zeroTile = 0;

        DmaTransfer(3, VRAM_OBJ + 0x7EA0 + (tile * 32), dst, 32, 32);
        divisor /= 10;
        dst += 0x20;
    }
}

#endif // DEBUG

/**
 * @brief 6c154 | 24 | Updates the minimap
 * 
 */
void MinimapUpdate(void)
{
    MinimapCheckForUnexploredTile();
    if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_LOWER_LINE)
    {
        MinimapSetTileAsExplored();
        MinimapUpdateForExploredTiles();
    }
    MinimapDraw();
}

static u32 sExploredMinimapBitFlags[32] = {
    1 << 0,  1 << 1,  1 << 2,  1 << 3,  1 << 4,
    1 << 5,  1 << 6,  1 << 7,  1 << 8,  1 << 9,
    1 << 10, 1 << 11, 1 << 12, 1 << 13, 1 << 14,
    1 << 15, 1 << 16, 1 << 17, 1 << 18, 1 << 19,
    1 << 20, 1 << 21, 1 << 22, 1 << 23, 1 << 24,
    1 << 25, 1 << 26, 1 << 27, 1 << 28, 1 << 29,
    1 << 30, 1 << 31
};

/**
 * @brief 6c178 | 4c | Sets the current minimap tile to be explored
 * 
 */
static void MinimapSetTileAsExplored(void)
{
    u32 offset;

    if (!gShipLandingFlag)
    {
        offset = gCurrentArea * MINIMAP_SIZE + gMinimapY; 
        sVisitedMinimapTilesPointer[offset] |= sExploredMinimapBitFlags[gMinimapX];
    }
}

/**
 * @brief 6c1c4 | 1d8 | To document
 * 
 * @param afterTransition To document
 */
static void MinimapCheckSetAreaNameAsExplored(u8 afterTransition)
{
    u32 set;
    s32 i;
    s32 j;
    u32 area;
    u16* pMap;
    u32 actualX;
    u32 actualY;
    u32 offset;

    if (gShipLandingFlag)
        return;

    if (gLastAreaNameVisited.flags == 0)
        return;

    set = 0;
    i = 0;

    if (afterTransition == TRUE)
    {
        if (gLastAreaNameVisited.flags & 0x80)
        {
            i = gLastAreaNameVisited.flags & 0x7F;
            if (sMinimapAreaNames[i].area1 == gAreaBeforeTransition)
                set = 1;
            else if (sMinimapAreaNames[i].area2 == gAreaBeforeTransition)
                set = 2;
        }
    }
    else
    {
        for (i = 0; sMinimapAreaNames[i].area1 != UCHAR_MAX; i++)
        {
            if (sMinimapAreaNames[i].area1 == gLastAreaNameVisited.area)
            {
                if (gLastAreaNameVisited.mapX == sMinimapAreaNames[i].mapX1 && gLastAreaNameVisited.mapY == sMinimapAreaNames[i].mapY1)
                    set = 1;
            }
            else if (sMinimapAreaNames[i].area2 == gLastAreaNameVisited.area)
            {
                if (gLastAreaNameVisited.mapX == sMinimapAreaNames[i].mapX2 && gLastAreaNameVisited.mapY == sMinimapAreaNames[i].mapY2)
                    set = 2;
            }

            if (set != 0)
                break;
        }

        if (set != 0)
            gLastAreaNameVisited.flags = i | 0x80;
    }

    if (set == 1)
    {
        area = sMinimapAreaNames[i].area1;
        actualX = sMinimapAreaNames[i].mapX1 + sMinimapAreaNames[i].xOffset1 - 1;
        actualY = sMinimapAreaNames[i].mapY1 + sMinimapAreaNames[i].yOffset1 - 1;
        gLastAreaNameVisited.mapX = sMinimapAreaNames[i].mapX1 - 1;
        gLastAreaNameVisited.mapY = sMinimapAreaNames[i].mapY1 - 1;
    }
    else if (set == 2)
    {
        area = sMinimapAreaNames[i].area2;
        actualX = sMinimapAreaNames[i].mapX2 + sMinimapAreaNames[i].xOffset2 - 1;
        actualY = sMinimapAreaNames[i].mapY2 + sMinimapAreaNames[i].yOffset2 - 1;
        gLastAreaNameVisited.mapX = sMinimapAreaNames[i].mapX2 - 1;
        gLastAreaNameVisited.mapY = sMinimapAreaNames[i].mapY2 - 1;
    }
    else
    {
        gLastAreaNameVisited.flags = 0;
        return;
    }

    pMap = &gDecompressedMinimapData[actualX + actualY * MINIMAP_SIZE];

    offset = area * MINIMAP_SIZE + actualY;

    for (j = 0, i = 0; i < MINIMAP_SIZE; i++, pMap++)
    {
        set = *pMap & 0x3FF;
        if (set >= 0x141 && set <= 0x15E)
        {
            sVisitedMinimapTilesPointer[offset] |= sExploredMinimapBitFlags[actualX + j];
            j++;
        }
        else
        {
            break;
        }
    }

    if (afterTransition)
    {
        offset = area * MINIMAP_SIZE + gLastAreaNameVisited.mapY;
        sVisitedMinimapTilesPointer[offset] |= sExploredMinimapBitFlags[gLastAreaNameVisited.mapX];
        gLastAreaNameVisited.flags = 0;
    }
}

/**
 * @brief 6c39c | d8 | Checks if Samus is on an unexplored minimap tile
 * 
 */
static void MinimapCheckForUnexploredTile(void)
{
    u16 samusX;
    u16 samusY;
    u16 clipPosition;

    if (gUpdateMinimapFlag != MINIMAP_UPDATE_FLAG_NONE)
        return;

    samusX = gSamusData.xPosition - BLOCK_SIZE * 2;
    samusY = gSamusData.yPosition - BLOCK_SIZE * 2;

    if (samusX & 0x8000) // X < 0
        samusX = 0;
    else
    {
        clipPosition = gBgPointersAndDimensions.clipdataWidth * BLOCK_SIZE;
        clipPosition -= BLOCK_SIZE * 4;

        if (gSamusData.xPosition >= clipPosition)
            samusX = clipPosition - ONE_SUB_PIXEL;
    }

    if (samusY & 0x8000) // Y < 0
        samusY = 0;
    else
    {
        clipPosition = gBgPointersAndDimensions.clipdataHeight * BLOCK_SIZE;
        clipPosition -= BLOCK_SIZE * 4;

        if (gSamusData.yPosition >= clipPosition)
            samusY = clipPosition - ONE_SUB_PIXEL;
    }

    // Convert to block
    samusX /= BLOCK_SIZE;
    samusY /= BLOCK_SIZE;

    samusX /= SCREEN_SIZE_X_BLOCKS;
    samusY /= SCREEN_SIZE_Y_BLOCKS;

    // Check update X coords
    if (gMinimapX != samusX + gCurrentRoomEntry.mapX)
    {
        gMinimapX = samusX + gCurrentRoomEntry.mapX;
        gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_LOWER_LINE;
    }

    // Check update Y coords
    if (gMinimapY != samusY + gCurrentRoomEntry.mapY)
    {
        gMinimapY = samusY + gCurrentRoomEntry.mapY;
        gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_LOWER_LINE;
    }
}

/**
 * @brief 6c474 | a4 | Updates the minimap when taking a transition
 * 
 */
void MinimapCheckOnTransition(void)
{
    if (gAreaBeforeTransition != gCurrentArea)
    {
        // New area
        MinimapCheckSetAreaNameAsExplored(FALSE);

        // Get new minimap
        gAreaBeforeTransition = gCurrentArea;
        PauseScreenGetMinimapData(gAreaBeforeTransition, gDecompressedMinimapData);

        #ifdef REGION_EU
        DmaTransfer(3, gDecompressedMinimapData, gDecompressedMinimapVisitedTiles, sizeof(gDecompressedMinimapData), 16);
        #else // !REGION_EU
        DMA3_COPY_16(gDecompressedMinimapData, gDecompressedMinimapVisitedTiles, sizeof(gDecompressedMinimapData) / 2);
        #endif // REGION_EU

        MinimapCheckSetAreaNameAsExplored(TRUE);
        MinimapSetDownloadedTiles(gAreaBeforeTransition, gDecompressedMinimapVisitedTiles);

        // Clear coords
        gMinimapX = UCHAR_MAX;
        gMinimapY = UCHAR_MAX;
    }

    // Check for transition tile
    gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_NONE;
    MinimapCheckForUnexploredTile();

    if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_LOWER_LINE)
    {
        MinimapSetTileAsExplored();
        MinimapUpdateForExploredTiles();
    }

    // Full redraw
    gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_UPPER_LINE;
    MinimapDraw();

    gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_MIDDLE_LINE;
    MinimapDraw();

    gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_LOWER_LINE;
    MinimapDraw();
}

/**
 * @brief 6c518 | 9c | Updates the minimap for the explored tiles
 * 
 */
static void MinimapUpdateForExploredTiles(void)
{
    u32 offset;
    u32 tile;
    u16* map;
    u16* tiles;

    if (gShipLandingFlag)
        return;

    offset = gMinimapX + gMinimapY * MINIMAP_SIZE;
    tiles = &gDecompressedMinimapVisitedTiles[offset];
    
    if (!(*tiles & 0xF000))
    {
        map = &gDecompressedMinimapData[offset];
        if (*map & 0xF000)
            *tiles = *map;
        else
            *tiles = *map | 0x1000;

        tile = (*map & 0x3FF) - 0x141;
        if (tile < 0x4)
        {
            gLastAreaNameVisited.flags = TRUE;
            gLastAreaNameVisited.area = gCurrentArea;
            gLastAreaNameVisited.mapX = gMinimapX + 1;
            gLastAreaNameVisited.mapY = gMinimapY + 1;
        }
    }
}

static MinimapFunc_T sMinimapTilesCopyGfxFunctionPointers[4] = {
    MinimapCopyTileGfx,
    MinimapCopyTileXFlippedGfx,
    MinimapCopyTileYFlippedGfx,
    MinimapCopyTileXYFlippedGfx
};

/**
 * @brief 6c5b4 | 100 | To document
 * 
 */
void MinimapDraw(void)
{
    s32 yOffset;
    s32 xOffset;
    s32 xPosition;
    s32 yPosition;
    u32 limit;
    u32* dst;
    u16 rawTile;
    u16 tile;
    u8 palette;
    u32 flip;
    u16* src;
    u16* tmp;
    #ifndef BUGFIX
    u16 tmp1;
    u16 tmp2;
    #endif // !BUGFIX

    if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_NONE)
        return;

    src = gDecompressedMinimapVisitedTiles;
    dst = (u32*)gMinimapTilesGfx + (gUpdateMinimapFlag - 1) * 24;

    if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_LOWER_LINE)
        yOffset = 1;
    else if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_MIDDLE_LINE)
        yOffset = 0;
    else if (gUpdateMinimapFlag == MINIMAP_UPDATE_FLAG_UPPER_LINE)
        yOffset = -1;
    else
    {
        gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_NONE;
        return;
    }

    for (xOffset = -1; xOffset < 2; xOffset++, dst += 8)
    {
        limit = MINIMAP_SIZE - 1;

        xPosition = gMinimapX + xOffset;
        if (xPosition > limit)
            xPosition = -1;

        yPosition = gMinimapY + yOffset;
        if (yPosition > limit)
            yPosition = -1;

        if (yPosition < 0 || xPosition < 0)
        {
            xPosition = limit;
            yPosition = limit;
        }

        tmp = &src[yPosition * MINIMAP_SIZE + xPosition];

        do {
        #ifndef BUGFIX
        // BUG: uses uninitalized variables
        tmp1 = tmp2 & 0xC00;
        #endif // !BUGFIX
        flip = (*tmp & 0xC00) >> 0xA;
        } while(0);

        do {
        palette = *tmp >> 0xC;
        } while(0);

        do {
        tile = *tmp & 0x3ff;
        } while(0);
        
        #ifndef REGION_EU
        if (gLanguage == LANGUAGE_HIRAGANA && tile > MINIMAP_TILE_BACKGROUND)
            tile += 0x20;
        #endif // !REGION_EU

        tile <<= 5;
        sMinimapTilesCopyGfxFunctionPointers[flip](dst, &tile, palette);
    }
}

/**
 * @brief 6c6b4 | d8 | Copies the graphics of a map tile
 * 
 * @param dst Destination pointer
 * @param pTile Tile pointer
 * @param palette Palette
 */
static void MinimapCopyTileGfx(u32* dst, u16* pTile, u8 palette)
{
    s32 i;
    u32 value;
    u32 tile;

    for (i = 0; i < 8; i++)
    {
        tile = sMinimapTilesGfx[*pTile];
        value = (sPauseScreen_40d74c[(tile / 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile % 16) + (palette << 4)]);
        (*pTile)++;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile / 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile % 16) + (palette << 4)]) << 8;
        (*pTile)++;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile / 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile % 16) + (palette << 4)]) << 16;
        (*pTile)++;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile / 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile % 16) + (palette << 4)]) << 24;
        (*pTile)++;

        *dst++ = value;
    }
}

/**
 * @brief 6c78c | ec | Copies the graphics of a map tile (X flipped)
 * 
 * @param dst Destination pointer
 * @param pTile Tile pointer
 * @param palette Palette
 */
static void MinimapCopyTileXFlippedGfx(u32* dst, u16* pTile, u8 palette)
{
    s32 i;
    u32 value;
    u32 tile;

    for (i = 0; i < 8; i++)
    {
        *pTile += 3;

        tile = sMinimapTilesGfx[*pTile];
        value = (sPauseScreen_40d74c[(tile % 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile / 16) + (palette << 4)]);
        (*pTile)--;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile % 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile / 16) + (palette << 4)]) << 8;
        (*pTile)--;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile % 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile / 16) + (palette << 4)]) << 16;
        (*pTile)--;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile % 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile / 16) + (palette << 4)]) << 24;

        *dst++ = value;
        
        *pTile += 4;
    }
}

/**
 * @brief 6c878 | dc | Copies the graphics of a map tile (Y flipped)
 * 
 * @param dst Destination pointer
 * @param pTile Tile pointer
 * @param palette Palette
 */
static void MinimapCopyTileYFlippedGfx(u32* dst, u16* pTile, u8 palette)
{
    s32 i;
    u32 value;
    u32 tile;
    
    *pTile += 28;
    
    for (i = 0; i < 8; i++)
    {
        tile = sMinimapTilesGfx[*pTile];
        value = (sPauseScreen_40d74c[(tile / 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile % 16) + (palette << 4)]);
        (*pTile)++;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile / 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile % 16) + (palette << 4)]) << 8;
        (*pTile)++;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile / 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile % 16) + (palette << 4)]) << 16;
        (*pTile)++;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile / 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile % 16) + (palette << 4)]) << 24;

        *dst++ = value;
        *pTile -= 7;
    }
}

/**
 * @brief 6c954 | f0 | Copies the graphics of a map tile (X/Y flipped)
 * 
 * @param dst Destination pointer
 * @param pTile Tile pointer
 * @param palette Palette
 */
static void MinimapCopyTileXYFlippedGfx(u32* dst, u16* pTile, u8 palette)
{
    s32 i;
    u32 value;
    u32 tile;

    // Macro
    do{
        *pTile += 31;
    }while(0);
    
    for (i = 0; i < 8; i++)
    {
        tile = sMinimapTilesGfx[*pTile];
        value = (sPauseScreen_40d74c[(tile % 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile / 16) + (palette << 4)]);
        (*pTile)--;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile % 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile / 16) + (palette << 4)]) << 8;
        (*pTile)--;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile % 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile / 16) + (palette << 4)]) << 16;
        (*pTile)--;

        tile = sMinimapTilesGfx[*pTile];
        value |= (sPauseScreen_40d74c[(tile % 16) + (palette << 4)] |
            sPauseScreen_40d6fc[(tile / 16) + (palette << 4)]) << 24;
        (*pTile)--;

        *dst++ = value;
        
    }
}

/**
 * @brief 6ca44 | 6c | Updates the tiles of a minimap with obtained items
 * 
 * @param area Area
 * @param dst Destination pointer
 */
void MinimapSetTilesWithObtainedItems(Area area, u16* dst)
{
    u32* src;
    u32 tile;
    s32 i;
    s32 j;

    if (area >= MAX_AMOUNT_OF_AREAS)
        return;

    src = gMinimapTilesWithObtainedItems[area];

    for (i = 0; i < MINIMAP_SIZE; i++, src++)
    {
        if (!*src)
            continue;
        
        tile = *src;
        for (j = 0; j < MINIMAP_SIZE && tile; j++)
        {
            if (tile & sExploredMinimapBitFlags[j])
            {
                tile ^= sExploredMinimapBitFlags[j];
                dst[i * MINIMAP_SIZE + j]++;
            }
        }
    }
}

/**
 * @brief 6cab0 | 128 | Updates the tiles of a minimap with the downloaded tiles
 * 
 * @param area Area
 * @param dst Destination pointer
 */
void MinimapSetDownloadedTiles(Area area, u16* dst)
{
    u32* pVisited;
    s32 i;
    s32 j;
    u32 tmp;
    u32 tmp2;

    pVisited = &sVisitedMinimapTilesPointer[area * MINIMAP_SIZE];

    if ((gEquipment.downloadedMapStatus >> area) & 1 || (u8)(area - MAX_AMOUNT_OF_AREAS) <= 2)
    {
        for (i = 0; i < MINIMAP_SIZE; i++, pVisited++)
        {
            for (j = 0; j < MINIMAP_SIZE; j++, dst++)
            {
                tmp2 = *pVisited;
                if (sExploredMinimapBitFlags[j] & tmp2)
                {
                    if (!(*dst & 0xF000))
                        *dst |= 0x1000;
                }
                else if (*dst >= 0x3000)
                {
                    *dst = 0x140;
                }
                else if (*dst & 0x3000)
                {
                    *dst &= 0xFFF;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < MINIMAP_SIZE; i++, pVisited++)
        {
            for (j = 0; j < MINIMAP_SIZE; j++, dst++)
            {
                tmp = *pVisited;
                if (sExploredMinimapBitFlags[j] & tmp)
                {
                    if (!(*dst & 0xF000))
                        *dst |= 0x1000;
                }
                else if (*dst & 0xF000)
                {
                    *dst = 0x140;
                }
            }
        }
    }
}

/**
 * @brief 6cbd8 | 90 | Updates the minimap for a collected item
 * 
 * @param xPosition X position
 * @param yPosition Y position
 */
void MinimapUpdateForCollectedItem(u8 xPosition, u8 yPosition)
{
    u32 itemX;
    u32 itemY;
    u32* ptr;
    u16* ptrU;

    if (gCurrentArea < MAX_AMOUNT_OF_AREAS)
    {
        itemX = (xPosition - SCREEN_X_PADDING) / SCREEN_SIZE_X_BLOCKS + gCurrentRoomEntry.mapX;
        itemY = (yPosition - SCREEN_Y_PADDING) / SCREEN_SIZE_Y_BLOCKS + gCurrentRoomEntry.mapY;

        ptr = gMinimapTilesWithObtainedItems[gCurrentArea];
        ptr[itemY] |= sExploredMinimapBitFlags[itemX];

        itemX += itemY * MINIMAP_SIZE;

        ptrU = gDecompressedMinimapVisitedTiles;
        ptrU[itemX]++;

        ptrU = gDecompressedMinimapData;
        ptrU[itemX]++;

        gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_LOWER_LINE;
        MinimapDraw();
    }
}

/**
 * @brief 6cc68 | 64 | Checks if a minimap has been explored
 * 
 * @param xPosition X Position
 * @param yPosition Y Position
 * @return u32 Explored bit flag
 */
u32 MinimapCheckIsTileExplored(u8 xPosition, u8 yPosition)
{
    u32 mapX;
    u32 mapY;
    u32 offset;
    u32* ptr;
    u32 tileOffset;

    if (gCurrentArea >= MAX_AMOUNT_OF_AREAS)
        return 1;

    offset = gCurrentArea * MINIMAP_SIZE;
    mapX = (xPosition - SCREEN_X_PADDING) / SCREEN_SIZE_X_BLOCKS + gCurrentRoomEntry.mapX;
    mapY = (yPosition - SCREEN_Y_PADDING) / SCREEN_SIZE_Y_BLOCKS + gCurrentRoomEntry.mapY;

    tileOffset = mapY + offset;
    return sVisitedMinimapTilesPointer[tileOffset] & sExploredMinimapBitFlags[mapX];
}

/**
 * @brief 6cccc | b8 | Sets the minimap tiles with obtained items when loading a save file
 * 
 */
void MinimapLoadTilesWithObtainedItems(void)
{
    u8 i;
    s32 j;
    s32 yPosition;
    s32 xPosition;
    struct ItemInfo* pItem;
    u32* pTiles;
    u32 xOffset;
    u32 yOffset;

    BitFill(3, 0, gMinimapTilesWithObtainedItems, sizeof(gMinimapTilesWithObtainedItems) * 2, 16);

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
    {
        pItem = gItemsCollected[i];
        pTiles = gMinimapTilesWithObtainedItems[i];

        for (j = 0; j < MINIMAP_SIZE * 2; j++, pItem++)
        {
            if (pItem->room == UCHAR_MAX)
                break;

            xPosition = (pItem->xPosition - SCREEN_X_PADDING) / SCREEN_SIZE_X_BLOCKS;
            yPosition = (pItem->yPosition - SCREEN_Y_PADDING) / SCREEN_SIZE_Y_BLOCKS;

            xOffset = xPosition + sAreaRoomEntryPointers[i][pItem->room].mapX;
            yOffset = yPosition + sAreaRoomEntryPointers[i][pItem->room].mapY;

            pTiles[yOffset] |= sExploredMinimapBitFlags[xOffset];
        }
    }
}

/**
 * @brief 6cd84 | 174 | Updates a minimap chunk/boss icon
 * 
 * @param event Event linked
 */
void MinimapUpdateChunk(Event event)
{
    s32 i;
    u16* pMinimap;
    u16* pVisited;
    u16* pMinimapLower;
    u16* pVisitedLower;
    u16* ptr;
    u32 mask;

    for (i = 0; i < (u32)ARRAY_SIZE(sBossIcons); i++)
    {
        if (event == sBossIcons[i][0])
            break;
    }

    if (i >= ARRAY_SIZE(sBossIcons))
        return;

    if (i != gCurrentArea)
        return;

    i = sBossIcons[i][3] * MINIMAP_SIZE + sBossIcons[i][2];

    pMinimap = &gDecompressedMinimapData[i];
    pVisited = &gDecompressedMinimapVisitedTiles[i];

    if (gCurrentArea == AREA_CRATERIA)
    {
        if ((*pMinimap & 0x3FF) == sMapChunksToUpdate[2])
        {
            mask = 0xF000;
            ptr = pVisited;
            pVisitedLower = pMinimap;
            
            for (i = 2; i >= 0; i--)
            {
                (*pVisitedLower)++;
                if (mask & *ptr)
                    (*ptr)++;
                
                ptr++;
                pVisitedLower++;
            }

            i = FALSE;
        }
        else
            i = TRUE;
    }
    else if (gCurrentArea == AREA_KRAID)
    {
        if ((*pMinimap & 0x3FF) == sMapChunksToUpdate[0])
        {
            pVisitedLower = pVisited;
            pMinimapLower = pMinimap;

            for (i = 0; i < 2; i++)
            {
                (*pMinimapLower) += 0x20;
                (*pVisitedLower) += 0x20;
                
                pVisitedLower++;
                pMinimapLower++;
            }

            pVisitedLower = pVisited;
            pVisitedLower += MINIMAP_SIZE;
            pMinimapLower = pMinimap;
            pMinimapLower += MINIMAP_SIZE;

            for (i = 0; i < 2; i++)
            {
                (*pMinimapLower) += 0x20;
                (*pVisitedLower) += 0x20;
                
                pVisitedLower++;
                pMinimapLower++;
            }

            i = FALSE;
        }
        else
            i = TRUE;
    }
    else if (gCurrentArea == AREA_RIDLEY)
    {
        if ((*pMinimap & 0x3FF) == sMapChunksToUpdate[1])
        {
            pVisitedLower = pVisited;
            pMinimapLower = pMinimap;
            for (i = 0; i < 2; i++)
            {
                (*pMinimapLower) += 0x20;
                (*pVisitedLower) += 0x20;
                
                pVisitedLower++;
                pMinimapLower++;
            }

            pVisitedLower = pVisited;
            pVisitedLower += MINIMAP_SIZE;
            pMinimapLower = pMinimap;
            pMinimapLower += MINIMAP_SIZE;

            for (i = 0; i < 2; i++)
            {
                (*pMinimapLower) += 0x20;
                (*pVisitedLower) += 0x20;
                
                pVisitedLower++;
                pMinimapLower++;
            }

            i = FALSE;
        }
        else
            i = TRUE;
    }

    if (i)
        return;

    gUpdateMinimapFlag = MINIMAP_UPDATE_FLAG_LOWER_LINE;
    MinimapDraw();
}
