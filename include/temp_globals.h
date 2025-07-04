#ifndef TEMP_GLOBALS_H
#define TEMP_GLOBALS_H

#include "gba.h"
#include "types.h"

#include "structs/cutscene.h"
#include "structs/intro.h"
#include "structs/menus/game_over.h"
#include "structs/ending_and_gallery.h"
#include "structs/menus/pause_screen.h"
#include "structs/menus/title_screen.h"
#include "structs/menus/erase_sram.h"
#include "structs/menus/file_select.h"
#include "structs/menus/boot_debug.h"
#include "structs/fusion_gallery.h"
#include "structs/chozodia_escape.h"
#include "structs/tourian_escape.h"

#include "cutscenes/kraid_rising.h"
#include "cutscenes/before_charlie.h"

struct InGameData {
    u8 clipdataCode[640];
    u8 hazeCode[512];
    u8 unused[424];
};

union NonGameplayRam {
    struct CutsceneData cutscene;
    struct IntroData intro;
    struct GameOverData gameOver;
    struct EndingData ending;
    struct PauseScreenData pauseScreen;
    struct TitleScreenData titleScreen;
    struct EraseSramData eraseSram;
    struct FileSelectData fileSelect;
    struct FusionGalleryData fusionGallery;
    struct ChozodiaEscapeData chozodiaEscape;
    struct TourianEscapeData tourianEscape;
    struct BootDebugData bootDebug;
    struct InGameData inGame;
};

union EwramData {
    struct PauseScreenEwramData pauseScreen;
    struct FileSelectEwramData fileSelect;
    struct KraidRisingEwramData kraidRising;
    struct BeforeCharlieEwramData beforeCharlie;
};

extern u16 gUnk_02035400;

extern u8 gUnk_03004FC9;
extern union NonGameplayRam gNonGameplayRam;

extern u16 gBg0HOFS_NonGameplay;
extern u16 gBg0VOFS_NonGameplay;
extern u16 gBg1HOFS_NonGameplay;
extern u16 gBg1VOFS_NonGameplay;
extern u16 gBg2HOFS_NonGameplay;
extern u16 gBg2VOFS_NonGameplay;
extern u16 gBg3HOFS_NonGameplay;
extern u16 gBg3VOFS_NonGameplay;

extern u16 gCurrentOamRotation;
extern u16 gCurrentOamScaling;

#endif
