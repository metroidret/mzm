#ifndef BOOT_DEBUG_H
#define BOOT_DEBUG_H

#include "types.h"
#include "structs/game_state.h"

void BootDebugUpdateMenuOam(void);
void BootDebugSetupMenuOam(void);
void BootDebugUpdateCursorOam(void);
void BootDebugUpdateNonCursorOam(void);
void BootDebugUpdateMapScreenPosition(void);
void BootDebugReadSram(void);
void BootDebugWriteSram(u8 selectSaveFile);
s32 BootDebugHandler(void);
void BootDebugSetVBlankCodePtr(void);
void VBlankCodeDuringBootDebug(void);
void BootDebugSetupMenu(void);
s32 BootDebugHandleInput(void);
s32 BootDebugSectionHandler(void);
void BootDebugSectionMapRoomOrDoorUpdated(u8 roomOrDoor);
void BootDebugSectionMapDrawRoomAndDoorIds(u8 initialized);
void BootDebugModeHandler(void);
void BootDebugSaveHandler(void);
void BootDebugSaveUpdateText(u8 subMenuOption, struct FileScreenOptionsUnlocked* fileScreenOptions);
void BootDebugSaveSetSaveTextColor(void);
void BootDebugSamusHandler(void);
void BootDebugSoundHandler(void);
void BootDebugSetSoundTestIdColor(void);
s32 BootDebugDemoHandler(void);
s32 BootDebugEtcHandler(void);
void BootDebugDrawMenuNames(void);
void BootDebugDrawSubMenuText(void);
void BootDebugDrawTextAtPosition(u8 background, u8 xPosition, u8 yPosition, u8 palette, u8 size, const u8* text);
void BootDebugSectionDrawStar(u8 prevIndex);
void BootDebugSectionSetFilesColor(void);
void BootDebugDrawSubMenuOptionText(u8 subMenu, u8 subMenuOption);
void BootDebugDrawNumber(u16* dst, u8 number, u8 numDigits, u8 palette);
void BootDebugDrawTextAtAddress(u16* dst, const u8* text, u8 palette);

#endif
