#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_35_Clipdata[123] = {
    #include "extracted/data/rooms/brinstar/brinstar_35_clipdata.gfx.inc"
};

const u8 sBrinstar_35_Bg2[58] = {
    #include "extracted/data/rooms/brinstar/brinstar_35_bg2.gfx.inc"
};

const u8 sBrinstar_35_Bg1[482] = {
    #include "extracted/data/rooms/brinstar/brinstar_35_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_35_Spriteset0[3] = {
    { .y = 5, .x = 7, .id = SPRITESET_IDX(1) },
    { .y = 5, .x = 9, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

