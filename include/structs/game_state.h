#ifndef GAME_STATE_STRUCT_H
#define GAME_STATE_STRUCT_H

#include "types.h"
#include "input.h"

#include "constants/ending_and_gallery.h"
#include "constants/game_state.h"

struct GameCompletion {
    s8 completedGame;
    u8 introPlayed;
    u8 language;
};

extern struct GameCompletion gGameCompletion;

struct FileScreenOptionsUnlocked {
    u16 galleryImages;
    u16 fusionGalleryImages;
    u8 soundTestAndOrigMetroid;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    u32 timeAttack;
};

extern struct FileScreenOptionsUnlocked gFileScreenOptionsUnlocked;
extern struct ButtonAssignments gButtonAssignments;
extern s8 gTourianEscapeCutsceneStage;
extern vu16 gVBlankRequestFlag;
extern boolu8 gDisableSoftReset;
extern u8 gDebugMode;
extern u8 gBootDebugActive;
extern boolu8 gDisableMusic;
extern boolu8 gDisableCutscenes_Unused;
extern s8 gDisablePause;
extern u8 gDisableScrolling;
extern boolu8 gShipLandingFlag;
extern boolu8 gTimeAttackFlag;
extern u16 gButtonInput;
extern u16 gPreviousButtonInput;
extern u16 gChangedInput;
extern bools8 gIsLoadingFile;
extern PauseScreenFlag gPauseScreenFlag;
extern bools8 gVblankActive;
extern u8 gFrameCounter8Bit;
extern u16 gFrameCounter16Bit;
extern Difficulty gDifficulty;
extern Language gLanguage;
extern boolu8 gResetGame;
extern u8 gNotPressingUp;
extern EndingFlags gEndingFlags;

extern GameMode gMainGameMode;
extern s16 gSubGameMode1;
extern s8 gSubGameMode2;
extern s8 gSubGameMode3;
extern u8 gSubGameModeStage;

extern boolu8 gHasSaved;
extern s8 gMostRecentSaveFile;
extern u8 gCompletedGameFlagCopy;

extern s16 gDebugVCount_InGameStart;
extern u16 gDebugVCount_InGameEnd;
extern s16 gDebugVCount_VBlankEnd;
extern s16 gDebugVCount_AudioMax;

#endif /* GAME_STATE_STRUCT_H */
