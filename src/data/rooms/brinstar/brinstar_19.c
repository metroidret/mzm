#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_19_Clipdata[325] = {
    #include "extracted/data/rooms/brinstar/brinstar_19_clipdata.gfx.inc"
};

const u8 sBrinstar_19_Bg2[42] = {
    #include "extracted/data/rooms/brinstar/brinstar_19_bg2.gfx.inc"
};

const struct SpriteSpawn sBrinstar_19_SpriteLayer1[7] = {
    { .y = 3, .x = 16, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 20, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 24, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 77, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 81, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 96, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_19_Bg1[935] = {
    #include "extracted/data/rooms/brinstar/brinstar_19_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_19_SpriteLayer0[5] = {
    { .y = 3, .x = 13, .id = SPRITESET_IDX(1) },
    { .y = 3, .x = 50, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 80, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 96, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_19_Bg0[274] = {
    #include "extracted/data/rooms/brinstar/brinstar_19_bg0.gfx.inc"
};

