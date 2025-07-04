#ifndef MINIMAP_H
#define MINIMAP_H

#include "types.h"

#include "constants/connection.h"
#include "constants/event.h"

#ifdef DEBUG
void MinimapDrawRoomInfo(void);
void MinimapDrawNumber(u8 value, void* dst);
#endif // DEBUG

void MinimapUpdate(void);
void MinimapSetTileAsExplored(void);
void MinimapCheckSetAreaNameAsExplored(u8 afterTransition);
void MinimapCheckForUnexploredTile(void);
void MinimapCheckOnTransition(void);
void MinimapUpdateForExploredTiles(void);
void MinimapDraw(void);
void MinimapCopyTileGfx(u32* dst, u16* pTile, u8 palette);
void MinimapCopyTileXFlippedGfx(u32* dst, u16* pTile, u8 palette);
void MinimapCopyTileYFlippedGfx(u32* dst, u16* pTile, u8 palette);
void MinimapCopyTileXYFlippedGfx(u32* dst, u16* pTile, u8 palette);
void MinimapSetTilesWithObtainedItems(Area area, u16* dst);
void MinimapSetDownloadedTiles(Area area, u16* dst);
void MinimapUpdateForCollectedItem(u8 xPosition, u8 yPosition);
u32 MinimapCheckIsTileExplored(u8 xPosition, u8 yPosition);
void MinimapLoadTilesWithObtainedItems(void);
void MinimapUpdateChunk(Event event);

#endif /* MINIMAP_H */