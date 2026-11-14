#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_24_Clipdata[130] = {
    #include "extracted/data/rooms/norfair/norfair_24_clipdata.gfx.inc"
};

const u8 sNorfair_24_Bg2[101] = {
    #include "extracted/data/rooms/norfair/norfair_24_bg2.gfx.inc"
};

const u8 sNorfair_24_Bg1[542] = {
    #include "extracted/data/rooms/norfair/norfair_24_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_24_SpriteLayer0[12] = {
    { .y = 4, .x = 36, .id = SPRITESET_IDX(0) },
    { .y = 5, .x = 11, .id = SPRITESET_IDX(8) },
    { .y = 5, .x = 37, .id = SPRITESET_IDX(8) },
    { .y = 6, .x = 16, .id = SPRITESET_IDX(9) },
    { .y = 6, .x = 24, .id = SPRITESET_IDX(3) },
    { .y = 8, .x = 33, .id = SPRITESET_IDX(5) },
    { .y = 9, .x = 13, .id = SPRITESET_IDX(3) },
    { .y = 9, .x = 16, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 19, .id = SPRITESET_IDX(4) },
    { .y = 9, .x = 23, .id = SPRITESET_IDX(2) },
    { .y = 9, .x = 27, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

