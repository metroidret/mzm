#ifndef BOOT_DEBUG_STRUCT_H
#define BOOT_DEBUG_STRUCT_H

#include "types.h"

#include "constants/audio.h"
#include "constants/menus/boot_debug.h"

#include "structs/menu.h"
#include "structs/game_state.h"

#define BOOT_DEBUG_DATA sNonGameplayRamPointer->bootDebug

struct BootDebugText {
    u8 background;
    u8 xPosition;
    u8 yPosition;
    BootDebugColor palette;
    u8 size;
    const u8* text;
};

struct BootDebugData {
    BootDebugSubMenu menuCursor;
    u8 subMenu;
    u8 subMenuOption;
    u8 optionCursor;
    BootDebugMenuDepth menuDepth;
    u8 bg3vofs;
    u8 bg2vofs;
    u8 unk_07[5];
    Sound soundTestId;
    u16 bg0vofs;
    u16 bg0hofs;
    u16 dispcnt;
    struct FileScreenOptionsUnlocked fileScreenOptions;
    struct MenuOamData menuOam[BOOT_DEBUG_OAM_COUNT];
};

#endif /* BOOT_DEBUG_STRUCT_H */
