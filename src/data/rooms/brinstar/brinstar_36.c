#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_36_Clipdata[70] = {
    #include "extracted/data/rooms/brinstar/brinstar_36_clipdata.gfx.inc"
};

const u8 sBrinstar_36_Bg2[14] = {
    #include "extracted/data/rooms/brinstar/brinstar_36_bg2.gfx.inc"
};

const u8 sBrinstar_36_Bg1[215] = {
    #include "extracted/data/rooms/brinstar/brinstar_36_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_36_Spriteset0[2] = {
    { .y = 10, .x = 10, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

