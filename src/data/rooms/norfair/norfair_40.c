#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_40_Clipdata[46] = {
    #include "extracted/data/rooms/norfair/norfair_40_clipdata.gfx.inc"
};

const u8 sNorfair_40_Bg2[14] = {
    #include "extracted/data/rooms/norfair/norfair_40_bg2.gfx.inc"
};

const u8 sNorfair_40_Bg1[169] = {
    #include "extracted/data/rooms/norfair/norfair_40_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_40_SpriteLayer0[2] = {
    { .y = 5, .x = 5, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

