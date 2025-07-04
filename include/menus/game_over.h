#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "types.h"

#include "constants/game_over.h"

u32 GameOverSubroutine(void);
u32 GameOverProcessInput(void);
void GameOverUpdateTextGfx(void);
void GameOverInit(void);
void GameOverInit_Debug(void);
void GameOverVBlank(void);
void GameOverVBlank_Empty(void);
void GameOverUpdateLettersPalette(void);
void GameOverUpdateSamusHead(GameOverCursorAction action);
void GameOverProcessOAM(void);

#endif /* GAME_OVER_H */
