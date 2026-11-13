#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_50_Clipdata[32] = {
    #include "extracted/data/rooms/norfair/norfair_50_clipdata.gfx.inc"
};

const u8 sNorfair_50_Bg2[122] = {
    #include "extracted/data/rooms/norfair/norfair_50_bg2.gfx.inc"
};

const u8 sNorfair_50_Bg1[289] = {
    #include "extracted/data/rooms/norfair/norfair_50_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_50_SpriteLayer0[1] = {
    SPRITE_SPAWN_TERMINATOR
};

