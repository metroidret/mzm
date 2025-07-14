#ifndef LANGUAGE_SELECT_DATA_H
#define LANGUAGE_SELECT_DATA_H

#include "types.h"
#include "structs/menus/language_select.h"
#include "constants/game_state.h"

#ifdef REGION_EU

extern const u16 sLanguageSelectBgPal[16 * 16];
extern const u32 sLanguageSelectGfx[145];
extern const u32 sLanguageSelectTileTable[95];

extern const struct LanguageColorAnimation sInitialLanguageColorAnimation;
extern const u8 sLanguageSelectGameModeSub1Values[3];
extern const u16 sLanguageSelectLanguageTileTableOffsets[LANGUAGE_END - LANGUAGE_ENGLISH];
extern const u8 sLanguageTextAnimationPaletteRows[14];

#endif // REGION_EU

#endif /* LANGUAGE_SELECT_DATA_H */
