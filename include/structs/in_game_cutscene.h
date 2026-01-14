#ifndef IN_GAME_CUTSCENE_STRUCT_H
#define IN_GAME_CUTSCENE_STRUCT_H

#include "types.h"

#include "constants/connection.h"
#include "constants/in_game_cutscene.h"

typedef u32 (*InGameCutsceneFunc_T)(u8, u8);

struct SuitFlashEffect {
    u8 left;
    u8 right;
    u8 top;
    u8 bottom;
    u8 timer; // Changed but never read
};

struct InGameCutscene {
    u16 timer;
    u8 stage;
    InGameCutsceneScene cutsceneNumber;
    InGameCutsceneScene queuedCutscene;
    u8 unknown;
    InGameCutsceneFunc_T pFunction;
};

struct InGameCutsceneData {
    u8 unk_0;
    Area area;
    InGameCutsceneFunc_T pFunction;
};

extern struct InGameCutscene gInGameCutscene;
extern struct SuitFlashEffect gSuitFlashEffect;

extern u32 gInGameCutscenesTriggered[1];

#endif /* IN_GAME_CUTSCENE_STRUCT_H */
