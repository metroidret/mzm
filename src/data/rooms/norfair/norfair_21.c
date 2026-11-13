#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_21_Clipdata[210] = {
    #include "extracted/data/rooms/norfair/norfair_21_clipdata.gfx.inc"
};

const u8 sNorfair_21_Bg2[28] = {
    #include "extracted/data/rooms/norfair/norfair_21_bg2.gfx.inc"
};

const struct SpriteSpawn sNorfair_21_Spriteset1[6] = {
    { .y = 2, .x = 18, .id = SPRITESET_IDX(1) },
    { .y = 2, .x = 29, .id = SPRITESET_IDX(1) },
    { .y = 5, .x = 14, .id = SPRITESET_IDX(2) },
    { .y = 5, .x = 34, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 24, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_21_Bg1[452] = {
    #include "extracted/data/rooms/norfair/norfair_21_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_21_Spriteset0[6] = {
    { .y = 2, .x = 18, .id = SPRITESET_IDX(1) },
    { .y = 2, .x = 29, .id = SPRITESET_IDX(1) },
    { .y = 5, .x = 14, .id = SPRITESET_IDX(4) },
    { .y = 5, .x = 34, .id = SPRITESET_IDX(4) },
    { .y = 8, .x = 24, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_21_Bg0[174] = {
    #include "extracted/data/rooms/norfair/norfair_21_bg0.gfx.inc"
};

