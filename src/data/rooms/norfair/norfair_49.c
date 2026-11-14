#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_49_Clipdata[182] = {
    #include "extracted/data/rooms/norfair/norfair_49_clipdata.gfx.inc"
};

const u8 sNorfair_49_Bg2[98] = {
    #include "extracted/data/rooms/norfair/norfair_49_bg2.gfx.inc"
};

const u8 sNorfair_49_Bg1[361] = {
    #include "extracted/data/rooms/norfair/norfair_49_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_49_SpriteLayer0[3] = {
    { .y = 6, .x = 21, .id = SPRITESET_IDX(0) },
    { .y = 12, .x = 7, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_49_Bg0[462] = {
    #include "extracted/data/rooms/norfair/norfair_49_bg0.gfx.inc"
};

