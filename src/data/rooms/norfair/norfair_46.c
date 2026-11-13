#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_46_Clipdata[170] = {
    #include "extracted/data/rooms/norfair/norfair_46_clipdata.gfx.inc"
};

const u8 sNorfair_46_Bg2[228] = {
    #include "extracted/data/rooms/norfair/norfair_46_bg2.gfx.inc"
};

const u8 sNorfair_46_Bg1[314] = {
    #include "extracted/data/rooms/norfair/norfair_46_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_46_Spriteset0[2] = {
    { .y = 9, .x = 34, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_46_Bg0[126] = {
    #include "extracted/data/rooms/norfair/norfair_46_bg0.gfx.inc"
};

