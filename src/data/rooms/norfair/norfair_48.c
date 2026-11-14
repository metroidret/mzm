#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_48_Clipdata[220] = {
    #include "extracted/data/rooms/norfair/norfair_48_clipdata.gfx.inc"
};

const u8 sNorfair_48_Bg2[978] = {
    #include "extracted/data/rooms/norfair/norfair_48_bg2.gfx.inc"
};

const u8 sNorfair_48_Bg1[437] = {
    #include "extracted/data/rooms/norfair/norfair_48_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_48_SpriteLayer0[3] = {
    { .y = 8, .x = 25, .id = SPRITESET_IDX(1) },
    { .y = 16, .x = 29, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_48_Bg0[76] = {
    #include "extracted/data/rooms/norfair/norfair_48_bg0.gfx.inc"
};

