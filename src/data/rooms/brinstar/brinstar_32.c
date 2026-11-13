#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_32_Clipdata[54] = {
    #include "extracted/data/rooms/brinstar/brinstar_32_clipdata.gfx.inc"
};

const u8 sBrinstar_32_Bg2[14] = {
    #include "extracted/data/rooms/brinstar/brinstar_32_bg2.gfx.inc"
};

const u8 sBrinstar_32_Bg1[190] = {
    #include "extracted/data/rooms/brinstar/brinstar_32_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_32_Spriteset0[2] = {
    { .y = 6, .x = 5, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

