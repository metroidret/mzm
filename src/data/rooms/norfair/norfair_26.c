#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_26_Clipdata[128] = {
    #include "extracted/data/rooms/norfair/norfair_26_clipdata.gfx.inc"
};

const u8 sNorfair_26_Bg2[14] = {
    #include "extracted/data/rooms/norfair/norfair_26_bg2.gfx.inc"
};

const u8 sNorfair_26_Bg1[364] = {
    #include "extracted/data/rooms/norfair/norfair_26_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_26_Spriteset0[2] = {
    { .y = 8, .x = 16, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_26_Bg0[128] = {
    #include "extracted/data/rooms/norfair/norfair_26_bg0.gfx.inc"
};

