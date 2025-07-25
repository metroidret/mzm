#ifndef PAUSE_SCREEN_DATA_H
#define PAUSE_SCREEN_DATA_H

#include "types.h"
#include "connection.h"

#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/menus/pause_screen.h"
#include "constants/menus/status_screen.h"

#include "structs/cutscene.h"
#include "structs/text.h"
#include "structs/menus/pause_screen.h"

extern const u16 sPauseScreen_3fcef0[11 * 16];
extern const u16 sTankIconsPal[16 * 16];
extern const u16 sPauseScreen_3fd250[5 * 16];

extern const u16 sMinimapAnimatedPalette[1 * 16];
extern const u16 sSamusWireframePal[4 * 16];

// ... Oam

extern const u32 sMotifBehindWireframeSamusGfx[278];
extern const u32 sPauseScreenHudGfx[1404];
extern const u32 sMinimapLettersGfx[60];

extern const u32 sMenuNamesJapaneseGfx[92];
extern const u32 sEquipmentNamesJapaneseGfx[384];

extern const u32 sTankIconsGfx[1786];

extern const u32 sMapScreenAreaNamesEnglishGfx[216];
extern const u32 sMapScreenUnknownItemsNamesJapaneseGfx[65];
extern const u32 sMapScreenChozoStatueAreaNamesEnglishGfx[152];

extern const u32 sChozoHintBackgroundGfx[3618];

extern const u32 sBrinstarMinimap[133];
extern const u32 sKraidMinimap[121];
extern const u32 sNorfairMinimap[153];
extern const u32 sRidleyMinimap[120];
extern const u32 sTourianMinimap[91];
extern const u32 sCrateriaMinimap[114];
extern const u32 sChozodiaMinimap[194];
extern const u32 sTestMinimap[78];

extern const u32 sDebugMenuTileParts[175];
extern const u32 sMapScreenVisorOverlayTilemap[122];
extern const u32 sMapScreenOverlayTilemap[125];
extern const u32 sWorldMapOverlayTilemap[206];
extern const u32 sStatusScreenTilemap[264];
extern const u32 sEasySleepTilemap[196];
extern const u32 sStatusScreenBackgroundTilemap[169];
extern const u32 sMapScreenTextBg0TileTable[92];
extern const u32 sChozoHintBackgroundTileTable[577];

extern const u32 sEquipmentNamesHiraganaGfx[411];
extern const u32 sEquipmentNamesEnglishGfx[380];
extern const u32 sEquipmentNamesGermanGfx[];
extern const u32 sEquipmentNamesFrenchGfx[];
extern const u32 sEquipmentNamesItalianGfx[];
extern const u32 sEquipmentNamesSpanishGfx[];

extern const u32 sMapScreenAreaNamesHiraganaGfx[198];

extern const u32 sMenuNamesHiraganaGfx[113];
extern const u32 sMenuNamesEnglishGfx[92];
extern const u32 sMenuNamesGermanGfx[97];
extern const u32 sMenuNamesFrenchGfx[91];
extern const u32 sMenuNamesItalianGfx[];
extern const u32 sMenuNamesSpanishGfx[];

extern const u32 sMapScreenUnknownItemsNamesHiraganaGfx[76];
extern const u32 sMapScreenUnknownItemsNamesEnglishGfx[65];
extern const u32 sMapScreenUnknownItemsNamesGermanGfx[];
extern const u32 sMapScreenUnknownItemsNamesFrenchGfx[];
extern const u32 sMapScreenUnknownItemsNamesItalianGfx[];
extern const u32 sMapScreenUnknownItemsNamesSpanishGfx[];

extern const u32 sMapScreenChozoStatueAreaNamesHiraganaGfx[154];

extern const struct MenuOamData sMenuOamData_Empty;
extern const struct MenuOamData sMenuOamDataChozoHint_Empty;
extern const struct MenuOamData sMenuOamDataEraseSram_Empty;
extern const struct CutsceneOamData sCutsceneOam_Empty;

extern const struct MenuOamData sMenuOamDataMinimapRoomInfo;

extern const u16 sPauseScreen_BgCntPriority[4];

extern const struct PauseScreenAreaIconData sPauseScreenAreaIconsData[MAX_AMOUNT_OF_AREAS];
extern const u16 sMapScreenArrowsData[4][4];

extern const u8 sStatusScreenBeamFlagsOrder[5];
extern const u8 sStatusScreenBombFlagsOrder[1];
extern const u8 sStatusScreenSuitFlagsOrder[2];
extern const u8 sStatusScreenMiscFlagsOrder[6];

extern const u8 sStatusScreenFlagsSize[ABILITY_GROUP_STATUS_GROUPS_END];
extern const u16 sPowersOfTen[5];

extern const struct PauseScreenWireframeData sSamusWireframeData[SAMUS_WIREFRAME_DATA_END];

extern const u16 sChozoHintAreaNamesPosition[2];
extern const u8 sChozoHintAreaNamesOamIds[MAX_AMOUNT_OF_AREAS];

extern const struct WorldMapData sWorldMapData[MAX_AMOUNT_OF_AREAS - 1];
extern const u16 sWorldMapTargetPositions[16][2];

extern const u8 sBossIcons[MAX_AMOUNT_OF_AREAS - 1][5];
extern const u16 sMapChunksToUpdate[3];

extern const struct OamArray sPauseScreenMiscOam[MISC_OAM_ID_END];
extern const struct OamArray sPauseScreenOverlayOam[OVERLAY_OAM_ID_END];
extern const struct OamArray sPauseScreenBorderArrowsOam[BORDER_ARROW_OAM_ID_END];
extern const struct OamArray sPauseScreenSamusIconOam[SAMUS_ICON_OAM_ID_END];
extern const struct OamArray sPauseScreenBossIconsOam[BOSS_ICON_OAM_ID_END];
extern const struct OamArray sPauseScreenTargetsOam[TARGET_OAM_END];
extern const struct OamArray sPauseScreenWorldMapOam[WORLD_MAP_OAM_ID_END];

extern const u8 sMaintainedInputDelays_Fast[7];
#ifdef REGION_EU
extern const u8 sMaintainedInputDelays_Slow[4];
extern const u8 sMaintainedInputDelaysLastSet[MAINTAINED_INPUT_SPEED_COUNT];
#endif // REGION_EU

extern const struct MapScreenAreaIds sMapScreenAreaIds;
extern const u8 sMapScreenAreasViewOrder[MAX_AMOUNT_OF_AREAS];

extern const struct MinimapAreaName sMinimapAreaNames[10];

extern const u8 sPauseScreen_40d6fc[80];
extern const u8 sPauseScreen_40d74c[80];

extern u8* const sPauseScreen_IgtAndTanksVramAddresses[IGT_AND_TANKS_VRAM_ADDRESS_END];

extern const u8 sCharacterWidths[1184];

extern const struct Message sMessage_Empty;
extern const struct Message sMessageStoryText_Empty;
extern const struct Message sMessageFileScreen_Empty;
extern const struct Message sMessageDescription_Empty;

extern const u16 sPauseScreen_40dc90[1 * 16];
extern const u16 sPauseScreen_40dcb0[1 * 16];
extern const u16 sPauseScreen_40dcd0[1 * 16];
extern const u8 sPauseScreen_40dcf0[4];
extern const u8 sPauseScreen_40dcf4[16];

extern const u8 sMinimapAnimatedPaletteOffsets[MAX_AMOUNT_OF_AREAS + 1];

// ...?

#endif /* PAUSE_SCREEN_DATA_H */
