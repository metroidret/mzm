#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_27_Clipdata[56] = {
    #include "extracted/data/rooms/norfair/norfair_27_clipdata.gfx.inc"
};

const u8 sNorfair_27_Bg2[14] = {
    #include "extracted/data/rooms/norfair/norfair_27_bg2.gfx.inc"
};

const u8 sNorfair_27_Bg1[125] = {
    #include "extracted/data/rooms/norfair/norfair_27_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_27_SpriteLayer0[2] = {
    { .y = 7, .x = 6, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_27_Bg0[79] = {
    #include "extracted/data/rooms/norfair/norfair_27_bg0.gfx.inc"
};

