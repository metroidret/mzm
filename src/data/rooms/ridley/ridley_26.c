#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_26_Clipdata[138] = {
    #include "extracted/data/rooms/ridley/ridley_26_clipdata.gfx.inc"
};

const u8 sRidley_26_Bg2[14] = {
    #include "extracted/data/rooms/ridley/ridley_26_bg2.gfx.inc"
};

const u8 sRidley_26_Bg1[457] = {
    #include "extracted/data/rooms/ridley/ridley_26_bg1.gfx.inc"
};

const struct SpriteSpawn sRidley_26_SpriteLayer0[15] = {
    { .y = 9, .x = 33, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 34, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 35, .id = SPRITESET_IDX(3) },
    { .y = 9, .x = 36, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 37, .id = SPRITESET_IDX(3) },
    { .y = 9, .x = 38, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 39, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 33, .id = SPRITESET_IDX(0) },
    { .y = 10, .x = 34, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 35, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 36, .id = SPRITESET_IDX(2) },
    { .y = 10, .x = 37, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 38, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 39, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

