#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_11_Clipdata[111] = {
    #include "extracted/data/rooms/norfair/norfair_11_clipdata.gfx.inc"
};

const struct SpriteSpawn sNorfair_11_Spriteset2[4] = {
    { .y = 6, .x = 16, .id = SPRITESET_IDX(4) },
    { .y = 6, .x = 26, .id = SPRITESET_IDX(4) },
    { .y = 7, .x = 35, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_11_Bg2[38] = {
    #include "extracted/data/rooms/norfair/norfair_11_bg2.gfx.inc"
};

const struct SpriteSpawn sNorfair_11_Spriteset1[6] = {
    { .y = 6, .x = 16, .id = SPRITESET_IDX(4) },
    { .y = 6, .x = 26, .id = SPRITESET_IDX(4) },
    { .y = 7, .x = 35, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 21, .id = SPRITESET_IDX(4) },
    { .y = 11, .x = 8, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_11_Bg1[311] = {
    #include "extracted/data/rooms/norfair/norfair_11_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_11_Spriteset0[5] = {
    { .y = 6, .x = 16, .id = SPRITESET_IDX(4) },
    { .y = 6, .x = 26, .id = SPRITESET_IDX(4) },
    { .y = 7, .x = 35, .id = SPRITESET_IDX(0) },
    { .y = 11, .x = 8, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_11_Bg0[199] = {
    #include "extracted/data/rooms/norfair/norfair_11_bg0.gfx.inc"
};

