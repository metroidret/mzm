#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_19_Clipdata[237] = {
    #include "extracted/data/rooms/norfair/norfair_19_clipdata.gfx.inc"
};

const u8 sNorfair_19_Bg2[14] = {
    #include "extracted/data/rooms/norfair/norfair_19_bg2.gfx.inc"
};

const u8 sNorfair_19_Bg1[552] = {
    #include "extracted/data/rooms/norfair/norfair_19_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_19_SpriteLayer0[7] = {
    { .y = 2, .x = 9, .id = SPRITESET_IDX(1) },
    { .y = 2, .x = 21, .id = SPRITESET_IDX(0) },
    { .y = 2, .x = 39, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 24, .id = SPRITESET_IDX(3) },
    { .y = 11, .x = 32, .id = SPRITESET_IDX(2) },
    { .y = 12, .x = 13, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_19_Bg0[656] = {
    #include "extracted/data/rooms/norfair/norfair_19_bg0.gfx.inc"
};

