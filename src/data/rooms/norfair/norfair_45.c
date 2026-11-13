#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_45_Clipdata[92] = {
    #include "extracted/data/rooms/norfair/norfair_45_clipdata.gfx.inc"
};

const u8 sNorfair_45_Bg1[166] = {
    #include "extracted/data/rooms/norfair/norfair_45_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_45_Spriteset0[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

