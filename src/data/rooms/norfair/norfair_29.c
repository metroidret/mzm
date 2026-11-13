#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_29_Clipdata[183] = {
    #include "extracted/data/rooms/norfair/norfair_29_clipdata.gfx.inc"
};

const u8 sNorfair_29_Bg2[231] = {
    #include "extracted/data/rooms/norfair/norfair_29_bg2.gfx.inc"
};

const u8 sNorfair_29_Bg1[764] = {
    #include "extracted/data/rooms/norfair/norfair_29_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_29_Spriteset0[2] = {
    { .y = 12, .x = 11, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_29_Bg0[852] = {
    #include "extracted/data/rooms/norfair/norfair_29_bg0.gfx.inc"
};

