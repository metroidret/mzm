#ifndef ERASE_SRAM_MENU_DATA_H
#define ERASE_SRAM_MENU_DATA_H

#include "types.h"

#include "constants/menus/erase_sram.h"

#include "structs/cutscene.h"

extern const u16 sEraseSramMenuObjectsPal[7 * 16];
extern const u16 sEraseSramMenuBackgroundPal[15 * 16 - 1];

extern const u32 sEraseSramMenuObjectsGfx[477];
extern const u32 sEraseSramMenuFirstBoxGfx[118];

extern const u32 sEraseSramMenuConfirmJapaneseGfx[245];
extern const u32 sEraseSramMenuConfirmEnglishGfx[191];
extern const u32 sEraseSramMenuConfirmFrenchGfx[209];
extern const u32 sEraseSramMenuConfirmGermanGfx[222];
extern const u32 sEraseSramMenuConfirmItalianGfx[201];
extern const u32 sEraseSramMenuConfirmSpanishGfx[204];

extern const u32 sEraseSramMenuQuestionJapaneseGfx[245];
extern const u32 sEraseSramMenuQuestionEnglishGfx[185];
extern const u32 sEraseSramMenuQuestionFrenchGfx[187];
extern const u32 sEraseSramMenuQuestionGermanGfx[205];
extern const u32 sEraseSramMenuQuestionItalianGfx[221];
extern const u32 sEraseSramMenuQuestionSpanishGfx[208];

extern const u32 sEraseSramMenuBoxTileTable[137];
extern const u32 sEraseSramMenuBackgroundTileTable[368];

extern const EraseSramOamId sEraseSramQuestionWindowNoSelectedOamId;
extern const EraseSramOamId sEraseSramQuestionWindowYesSelectedOamId;
extern const EraseSramOamId sEraseSramConfirmWindowNoSelectedOamId;
extern const EraseSramOamId sEraseSramConfirmWindowYesSelectedOamId;
extern const u16 sEraseSramMenuSoundsID[ERASE_SRAM_SOUND_COUNT];
extern const u16 sEraseSramMenuCursorPosition[2][2];
extern const u16 sEraseSramMenuCursorPositionOffset[ERASE_SRAM_OPTION_COUNT][2];
extern const struct OamArray sEraseSramMenuOam[ERASE_SRAM_OAM_ID_COUNT];

#endif /* ERASE_SRAM_MENU_DATA_H */
