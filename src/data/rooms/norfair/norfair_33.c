#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_33_Clipdata[184] = {
    #include "extracted/data/rooms/norfair/norfair_33_clipdata.gfx.inc"
};

const u8 sNorfair_33_Bg2[152] = {
    #include "extracted/data/rooms/norfair/norfair_33_bg2.gfx.inc"
};

const u8 sNorfair_33_Bg1[682] = {
    #include "extracted/data/rooms/norfair/norfair_33_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_33_Spriteset0[15] = {
    { .y = 4, .x = 15, .id = SPRITESET_IDX(0) },
    { .y = 4, .x = 33, .id = SPRITESET_IDX(1) },
    { .y = 4, .x = 50, .id = SPRITESET_IDX(8) },
    { .y = 5, .x = 20, .id = SPRITESET_IDX(1) },
    { .y = 7, .x = 26, .id = SPRITESET_IDX(7) },
    { .y = 7, .x = 36, .id = SPRITESET_IDX(4) },
    { .y = 7, .x = 42, .id = SPRITESET_IDX(3) },
    { .y = 7, .x = 45, .id = SPRITESET_IDX(5) },
    { .y = 8, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 8, .x = 13, .id = SPRITESET_IDX(1) },
    { .y = 8, .x = 16, .id = SPRITESET_IDX(0) },
    { .y = 8, .x = 26, .id = SPRITESET_IDX(6) },
    { .y = 8, .x = 31, .id = SPRITESET_IDX(3) },
    { .y = 10, .x = 49, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

