#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_13_Clipdata[206] = {
    #include "extracted/data/rooms/brinstar/brinstar_13_clipdata.gfx.inc"
};

const u8 sBrinstar_13_Bg2[78] = {
    #include "extracted/data/rooms/brinstar/brinstar_13_bg2.gfx.inc"
};

const u8 sBrinstar_13_Bg1[520] = {
    #include "extracted/data/rooms/brinstar/brinstar_13_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_13_SpriteLayer0[8] = {
    { .y = 2, .x = 8, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 23, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 27, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 31, .id = SPRITESET_IDX(2) },
    { .y = 2, .x = 44, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 48, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 51, .id = SPRITESET_IDX(3) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_13_Bg0[220] = {
    #include "extracted/data/rooms/brinstar/brinstar_13_bg0.gfx.inc"
};

