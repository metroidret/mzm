#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_6_Clipdata[128] = {
    #include "extracted/data/rooms/norfair/norfair_6_clipdata.gfx.inc"
};

const u8 sNorfair_6_Bg2[111] = {
    #include "extracted/data/rooms/norfair/norfair_6_bg2.gfx.inc"
};

const struct SpriteSpawn sNorfair_6_SpriteLayer1[7] = {
    { .y = 7, .x = 24, .id = SPRITESET_IDX(0) },
    { .y = 12, .x = 10, .id = SPRITESET_IDX(1) },
    { .y = 12, .x = 20, .id = SPRITESET_IDX(1) },
    { .y = 12, .x = 33, .id = SPRITESET_IDX(1) },
    { .y = 12, .x = 36, .id = SPRITESET_IDX(1) },
    { .y = 12, .x = 39, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_6_Bg1[280] = {
    #include "extracted/data/rooms/norfair/norfair_6_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_6_SpriteLayer0[7] = {
    { .y = 7, .x = 26, .id = SPRITESET_IDX(0) },
    { .y = 12, .x = 10, .id = SPRITESET_IDX(1) },
    { .y = 12, .x = 20, .id = SPRITESET_IDX(1) },
    { .y = 12, .x = 33, .id = SPRITESET_IDX(1) },
    { .y = 12, .x = 36, .id = SPRITESET_IDX(1) },
    { .y = 12, .x = 39, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_6_Bg0[175] = {
    #include "extracted/data/rooms/norfair/norfair_6_bg0.gfx.inc"
};

