#ifndef RUINS_TEST_AI_H
#define RUINS_TEST_AI_H

#include "types.h"

enum RuinsTestFightStage {
    RUINS_TEST_FIGHT_STAGE_ON_GOING,
    RUINS_TEST_FIGHT_STAGE_LAST_SYMBOL_HIT,
    RUINS_TEST_FIGHT_STAGE_GHOST_AT_CENTER,
    RUINS_TEST_FIGHT_STAGE_GHOST_FADING_BACK,
    RUINS_TEST_FIGHT_STAGE_GHOST_STARTING_TO_DISAPPEAR,
    RUINS_TEST_FIGHT_STAGE_STARTING_CUTSCENE_FADE,
    RUINS_TEST_FIGHT_STAGE_STARTING_CUTSCENE,
    RUINS_TEST_FIGHT_STAGE_STARTING_SUIT_ANIM,
    RUINS_TEST_FIGHT_STAGE_SUIT_ANIM_ENDED
};

void RuinsTest(void);
void RuinsTestSymbol(void);
void RuinsTestSamusReflectionStart(void);
void RuinsTestReflectionCover(void);
void RuinsTestGhostOutline(void);
void RuinsTestShootableSymbol(void);
void RuinsTestGhost(void);
void RuinsTestSamusReflectionEnd(void);
void RuinsTestLightning(void);

#endif /* RUINS_TEST_AI_H */