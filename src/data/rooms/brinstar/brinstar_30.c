#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_30_Clipdata[76] = {
    #include "extracted/data/rooms/brinstar/brinstar_30_clipdata.gfx.inc"
};

const u8 sBrinstar_30_Bg2[14] = {
    #include "extracted/data/rooms/brinstar/brinstar_30_bg2.gfx.inc"
};

const u8 sBrinstar_30_Bg1[220] = {
    #include "extracted/data/rooms/brinstar/brinstar_30_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_30_SpriteLayer0[2] = {
    { .y = 9, .x = 11, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

