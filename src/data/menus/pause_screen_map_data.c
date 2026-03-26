#include "data/menus/pause_screen_map_data.h"
#include "macros.h"

const u8 sMinimapTilesGfx[5120] = {
    #include "extracted/data/menus/pause_screen/minimap_tiles.gfx.inc"
};
const u32 sPauseScreen_40f4c4[1792] = {
    #include "extracted/data/menus/pause_screen/40f4c4.gfx.inc"
};
const u32 sMinimapTilesAreaNamesEnglishGfx[79] = {
    #include "extracted/data/menus/pause_screen/minimap_tiles_area_names_english.gfx.lz.inc"
};
const u32 sMinimapTilesAreaNamesHiraganaGfx[88] = {
    #include "extracted/data/menus/pause_screen/minimap_tiles_area_names_hiragana.gfx.lz.inc"
};
const u16 sMinimapTilesPal[5 * 16] = {
    #include "extracted/data/menus/pause_screen/minimap_tiles.pal.inc"
};
