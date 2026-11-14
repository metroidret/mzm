#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_3_Clipdata[775] = {
    #include "extracted/data/rooms/brinstar/brinstar_3_clipdata.gfx.inc"
};

const u8 sBrinstar_3_Bg2[139] = {
    #include "extracted/data/rooms/brinstar/brinstar_3_bg2.gfx.inc"
};

const struct SpriteSpawn sBrinstar_3_SpriteLayer1[13] = {
    { .y = 11, .x = 11, .id = SPRITESET_IDX(1) },
    { .y = 14, .x = 9, .id = SPRITESET_IDX(1) },
    { .y = 18, .x = 10, .id = SPRITESET_IDX(2) },
    { .y = 28, .x = 15, .id = SPRITESET_IDX(2) },
    { .y = 36, .x = 12, .id = SPRITESET_IDX(2) },
    { .y = 44, .x = 11, .id = SPRITESET_IDX(1) },
    { .y = 76, .x = 5, .id = SPRITESET_IDX(2) },
    { .y = 78, .x = 7, .id = SPRITESET_IDX(1) },
    { .y = 86, .x = 9, .id = SPRITESET_IDX(1) },
    { .y = 98, .x = 8, .id = SPRITESET_IDX(1) },
    { .y = 104, .x = 3, .id = SPRITESET_IDX(2) },
    { .y = 115, .x = 8, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_3_Bg1[3530] = {
    #include "extracted/data/rooms/brinstar/brinstar_3_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_3_SpriteLayer0[13] = {
    { .y = 11, .x = 11, .id = SPRITESET_IDX(0) },
    { .y = 14, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 18, .x = 10, .id = SPRITESET_IDX(2) },
    { .y = 28, .x = 15, .id = SPRITESET_IDX(2) },
    { .y = 36, .x = 12, .id = SPRITESET_IDX(2) },
    { .y = 44, .x = 11, .id = SPRITESET_IDX(0) },
    { .y = 76, .x = 5, .id = SPRITESET_IDX(2) },
    { .y = 78, .x = 7, .id = SPRITESET_IDX(0) },
    { .y = 86, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 98, .x = 8, .id = SPRITESET_IDX(0) },
    { .y = 104, .x = 3, .id = SPRITESET_IDX(2) },
    { .y = 115, .x = 8, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

