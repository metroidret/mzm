#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_3_Clipdata[189] = {
    #include "extracted/data/rooms/norfair/norfair_3_clipdata.gfx.inc"
};

const struct SpriteSpawn sNorfair_3_Spriteset2[9] = {
    { .y = 3, .x = 21, .id = SPRITESET_IDX(3) },
    { .y = 3, .x = 23, .id = SPRITESET_IDX(3) },
    { .y = 3, .x = 69, .id = SPRITESET_IDX(3) },
    { .y = 3, .x = 71, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 22, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 56, .id = SPRITESET_IDX(0) },
    { .y = 7, .x = 50, .id = SPRITESET_IDX(0) },
    { .y = 10, .x = 34, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_3_Bg2[211] = {
    #include "extracted/data/rooms/norfair/norfair_3_bg2.gfx.inc"
};

const struct SpriteSpawn sNorfair_3_Spriteset1[11] = {
    { .y = 4, .x = 19, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 21, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 23, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 56, .id = SPRITESET_IDX(0) },
    { .y = 5, .x = 20, .id = SPRITESET_IDX(3) },
    { .y = 5, .x = 22, .id = SPRITESET_IDX(3) },
    { .y = 7, .x = 50, .id = SPRITESET_IDX(1) },
    { .y = 7, .x = 69, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 63, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 34, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_3_Bg1[585] = {
    #include "extracted/data/rooms/norfair/norfair_3_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_3_Spriteset0[12] = {
    { .y = 3, .x = 19, .id = SPRITESET_IDX(3) },
    { .y = 3, .x = 21, .id = SPRITESET_IDX(3) },
    { .y = 3, .x = 23, .id = SPRITESET_IDX(3) },
    { .y = 3, .x = 69, .id = SPRITESET_IDX(3) },
    { .y = 3, .x = 71, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 20, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 22, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 56, .id = SPRITESET_IDX(0) },
    { .y = 7, .x = 50, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 63, .id = SPRITESET_IDX(0) },
    { .y = 10, .x = 34, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_3_Bg0[263] = {
    #include "extracted/data/rooms/norfair/norfair_3_bg0.gfx.inc"
};

