#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_15_Clipdata[70] = {
    #include "extracted/data/rooms/norfair/norfair_15_clipdata.gfx.inc"
};

const u8 sNorfair_15_Bg2[14] = {
    #include "extracted/data/rooms/norfair/norfair_15_bg2.gfx.inc"
};

const struct SpriteSpawn sNorfair_15_Spriteset1[4] = {
    { .y = 9, .x = 13, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 17, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 21, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_15_Bg1[210] = {
    #include "extracted/data/rooms/norfair/norfair_15_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_15_Spriteset0[2] = {
    { .y = 9, .x = 16, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_15_Bg0[128] = {
    #include "extracted/data/rooms/norfair/norfair_15_bg0.gfx.inc"
};

