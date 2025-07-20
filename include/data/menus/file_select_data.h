#ifndef FILE_SELECT_MENU_DATA_H
#define FILE_SELECT_MENU_DATA_H

#include "types.h"
#include "constants/menus/file_select.h"
#include "constants/text.h"
#include "structs/menu.h"
#include "structs/cutscene.h"
#include "structs/text.h"

extern const u16 sFileSelectPal[7 * 16];
extern const u16 sFileSelect_4548f8[2 * 16];
extern const u16 sFileSelectIconsPal[6 * 16];

extern const struct FrameData sFileSelectOam_SamusHeadTurningOn[5];
extern const struct FrameData sFileSelectOam_SamusHeadTurning[11];
extern const struct FrameData sFileSelectOam_SamusHeadSuitlessTurningOn[6];
extern const struct FrameData sFileSelectOam_SamusHeadSuitlessIdle[5];
extern const struct FrameData sFileSelectOam_SamusHeadSuitlessTurning[8];

extern const u32 sFileSelectChozoBackgroundGfx[2985];
#ifdef REGION_EU
extern const u32 sFileSelectAreaNamesGfx[331];
extern const u32 sFileSelectBgIconsGfx[651];
#else // !REGION_EU
extern const u32 sFileSelectCharactersGfx[1531];
#endif // REGION_EU

extern const u32 sFileSelectOptionsTextEnglishGfx[345];
extern const u32 sFileSelectOptionsTextGermanGfx[];
extern const u32 sFileSelectOptionsTextFrenchGfx[];
extern const u32 sFileSelectOptionsTextItalianGfx[];
extern const u32 sFileSelectOptionsTextSpanishGfx[];

#ifdef REGION_EU
extern const u32 sFileSelectLargeTextEnglishGfx[332];
extern const u32 sFileSelectLargeTextGermanGfx[391];
extern const u32 sFileSelectLargeTextFrenchGfx[392];
extern const u32 sFileSelectLargeTextItalianGfx[353];
extern const u32 sFileSelectLargeTextSpanishGfx[364];

extern const u32 sFileSelectDifficultyTextEnglishGfx[67];
extern const u32 sFileSelectDifficultyTextGermanGfx[70];
extern const u32 sFileSelectDifficultyTextFrenchGfx[71];
extern const u32 sFileSelectDifficultyTextItalianGfx[71];
extern const u32 sFileSelectDifficultyTextSpanishGfx[70];
#endif // REGION_EU

extern const u32 sFileSelectObjIconsGfx[1722];
extern const u32 sFileSelectChozoBackgroundTileTable[368];
extern const u32 sFileSelectMenuTileTable[];
extern const u32 sFileSelectOptionsTileTable[];
extern const u32 sFileSelect3BigPanelsTileTable[233];
extern const u32 sFileSelect1Small2BigPanelsTileTable[233];
extern const u32 sFileSelect2Big1SmallPanelsTileTable[230];

extern const struct MenuOamData sFileSelectOamData_Empty[2];

extern const struct OamArray sFileSelectOam[FILE_SELECT_OAM_ID_END];
extern const struct OamArray sOptionsOam[OPTIONS_OAM_ID_END];

extern const u8 sFileScreenMessagesInfo[FILE_SCREEN_MESSAGE_INFO_ID_COUNT][3];
extern const struct Message sFileScreenMessage_Empty;

extern const u8 sNesMetroidDataCheck[18];
extern const u16 sTimeAttackButtonCode[5];

#endif /* FILE_SELECT_MENU_DATA_H */
