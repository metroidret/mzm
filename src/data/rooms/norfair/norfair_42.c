#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_42_Clipdata[187] = {
    #include "extracted/data/rooms/norfair/norfair_42_clipdata.gfx.inc"
};

const u8 sNorfair_42_Bg2[223] = {
    #include "extracted/data/rooms/norfair/norfair_42_bg2.gfx.inc"
};

const u8 sNorfair_42_Bg1[314] = {
    #include "extracted/data/rooms/norfair/norfair_42_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_42_SpriteLayer0[3] = {
    { .y = 5, .x = 13, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 22, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_42_Bg0[91] = {
    #include "extracted/data/rooms/norfair/norfair_42_bg0.gfx.inc"
};

