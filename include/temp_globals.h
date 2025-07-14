#ifndef TEMP_GLOBALS_H
#define TEMP_GLOBALS_H

#include "gba.h"
#include "types.h"

#include "structs/cutscene.h"
#include "structs/intro.h"
#include "structs/menus/game_over.h"
#include "structs/ending_and_gallery.h"
#include "structs/menus/language_select.h"
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
    #ifdef REGION_EU
    struct LanguageSelectData languageSelect;
    #endif // REGION_EU
    struct IntroData intro;
    struct TitleScreenData titleScreen;
    struct FileSelectData fileSelect;
    struct InGameData inGame;
    struct PauseScreenData pauseScreen;
    struct GameOverData gameOver;
    struct ChozodiaEscapeData chozodiaEscape;
    struct EndingData ending;
    struct TourianEscapeData tourianEscape;
    struct CutsceneData cutscene;
    struct FusionGalleryData fusionGallery;
    struct EraseSramData eraseSram;
    struct BootDebugData bootDebug;
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
