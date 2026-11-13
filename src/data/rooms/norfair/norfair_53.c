#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_53_Clipdata[100] = {
    #include "extracted/data/rooms/norfair/norfair_53_clipdata.gfx.inc"
};

const u8 sNorfair_53_Bg2[108] = {
    #include "extracted/data/rooms/norfair/norfair_53_bg2.gfx.inc"
};

const u8 sNorfair_53_Bg1[234] = {
    #include "extracted/data/rooms/norfair/norfair_53_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_53_SpriteLayer0[2] = {
    { .y = 19, .x = 6, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

