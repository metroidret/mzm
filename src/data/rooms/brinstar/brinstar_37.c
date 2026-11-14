#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_37_Clipdata[52] = {
    #include "extracted/data/rooms/brinstar/brinstar_37_clipdata.gfx.inc"
};

const u8 sBrinstar_37_Bg2[168] = {
    #include "extracted/data/rooms/brinstar/brinstar_37_bg2.gfx.inc"
};

const u8 sBrinstar_37_Bg1[137] = {
    #include "extracted/data/rooms/brinstar/brinstar_37_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_37_SpriteLayer0[2] = {
    { .y = 9, .x = 12, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

