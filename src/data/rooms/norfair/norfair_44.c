#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_44_Clipdata[85] = {
    #include "extracted/data/rooms/norfair/norfair_44_clipdata.gfx.inc"
};

const u8 sNorfair_44_Bg1[162] = {
    #include "extracted/data/rooms/norfair/norfair_44_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_44_SpriteLayer0[2] = {
    { .y = 10, .x = 8, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

