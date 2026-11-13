#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_38_Clipdata[157] = {
    #include "extracted/data/rooms/norfair/norfair_38_clipdata.gfx.inc"
};

const u8 sNorfair_38_Bg2[14] = {
    #include "extracted/data/rooms/norfair/norfair_38_bg2.gfx.inc"
};

const struct SpriteSpawn sNorfair_38_Spriteset1[10] = {
    { .y = 4, .x = 8, .id = SPRITESET_IDX(1) },
    { .y = 7, .x = 8, .id = SPRITESET_IDX(1) },
    { .y = 8, .x = 7, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 14, .id = SPRITESET_IDX(0) },
    { .y = 14, .x = 19, .id = SPRITESET_IDX(1) },
    { .y = 14, .x = 23, .id = SPRITESET_IDX(1) },
    { .y = 21, .x = 15, .id = SPRITESET_IDX(4) },
    { .y = 21, .x = 18, .id = SPRITESET_IDX(4) },
    { .y = 21, .x = 21, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_38_Bg1[462] = {
    #include "extracted/data/rooms/norfair/norfair_38_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_38_Spriteset0[3] = {
    { .y = 21, .x = 11, .id = SPRITESET_IDX(4) },
    { .y = 21, .x = 18, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_38_Bg0[228] = {
    #include "extracted/data/rooms/norfair/norfair_38_bg0.gfx.inc"
};

