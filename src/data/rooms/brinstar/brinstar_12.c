#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_12_Clipdata[379] = {
    #include "extracted/data/rooms/brinstar/brinstar_12_clipdata.gfx.inc"
};

const u8 sBrinstar_12_Bg2[337] = {
    #include "extracted/data/rooms/brinstar/brinstar_12_bg2.gfx.inc"
};

const u8 sBrinstar_12_Bg1[1226] = {
    #include "extracted/data/rooms/brinstar/brinstar_12_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_12_SpriteLayer0[5] = {
    { .y = 3, .x = 13, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 113, .id = SPRITESET_IDX(0) },
    { .y = 11, .x = 41, .id = SPRITESET_IDX(0) },
    { .y = 11, .x = 88, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_12_Bg0[203] = {
    #include "extracted/data/rooms/brinstar/brinstar_12_bg0.gfx.inc"
};

