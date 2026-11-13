#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_35_Clipdata[121] = {
    #include "extracted/data/rooms/chozodia/chozodia_35_clipdata.gfx.inc"
};

const u8 sChozodia_35_Bg2[312] = {
    #include "extracted/data/rooms/chozodia/chozodia_35_bg2.gfx.inc"
};

const u8 sChozodia_35_Bg1[492] = {
    #include "extracted/data/rooms/chozodia/chozodia_35_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_35_SpriteLayer0[6] = {
    { .y = 5, .x = 2, .id = SPRITESET_IDX(1) },
    { .y = 5, .x = 20, .id = SPRITESET_IDX(3) },
    { .y = 5, .x = 58, .id = SPRITESET_IDX(0) },
    { .y = 6, .x = 32, .id = SPRITESET_IDX(3) },
    { .y = 9, .x = 44, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_35_Bg0[53] = {
    #include "extracted/data/rooms/chozodia/chozodia_35_bg0.gfx.inc"
};

