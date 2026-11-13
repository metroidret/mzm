#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_13_Clipdata[54] = {
    #include "extracted/data/rooms/norfair/norfair_13_clipdata.gfx.inc"
};

const u8 sNorfair_13_Bg2[14] = {
    #include "extracted/data/rooms/norfair/norfair_13_bg2.gfx.inc"
};

const u8 sNorfair_13_Bg1[131] = {
    #include "extracted/data/rooms/norfair/norfair_13_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_13_SpriteLayer0[2] = {
    { .y = 7, .x = 7, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_13_Bg0[79] = {
    #include "extracted/data/rooms/norfair/norfair_13_bg0.gfx.inc"
};

