#ifndef GAME_OVER_DATA_H
#define GAME_OVER_DATA_H

#include "types.h"

#include "constants/game_over.h"
#include "constants/game_state.h"
#include "constants/samus.h"

#include "structs/menus/game_over.h"
#include "structs/cutscene.h"

extern const u16 sGameOverMenuPal[16 * 5];
extern const u32 sGameOverTextAndBackgroundGfx[2738];
extern const u32 sGameOverTextPromptEnglishGfx[333];
extern const u32 sGameOverTextPromptHiraganaGfx[428];
extern const u32 sGameOverTextPromptGermanGfx[];
extern const u32 sGameOverTextPromptFrenchGfx[];
extern const u32 sGameOverTextPromptItalianGfx[];
extern const u32 sGameOverTextPromptSpanishGfx[];
extern const u32 sGameOverBackgroundTileTable[370];
extern const u32 sGameOverTextTileTable[116];
extern const u32 sGameOver_454520[160];

extern const struct GameOverDynamicPalette sGameOverDynamicPalette_Empty;
extern const u16 sGameOverSamusHeadXPositions[LANGUAGE_COUNT];
extern const u16 sGameOverSamusHeadYPositions[2];

extern const GameOverOamId sGameOverSamusHeadOamIds[SUIT_COUNT][SAMUS_CURSOR_ACTION_COUNT];
extern const struct OamArray sGameOverOam[GAME_OVER_OAM_ID_COUNT];

#endif /* GAME_OVER_DATA_H */
