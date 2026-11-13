#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_62_Clipdata[199] = {
    #include "extracted/data/rooms/chozodia/chozodia_62_clipdata.gfx.inc"
};

const u8 sChozodia_62_Bg2[584] = {
    #include "extracted/data/rooms/chozodia/chozodia_62_bg2.gfx.inc"
};

const u8 sChozodia_62_Bg1[686] = {
    #include "extracted/data/rooms/chozodia/chozodia_62_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_62_SpriteLayer0[5] = {
    { .y = 8, .x = 6, .id = SPRITESET_IDX(2) },
    { .y = 14, .x = 12, .id = SPRITESET_IDX(2) },
    { .y = 17, .x = 7, .id = SPRITESET_IDX(2) },
    { .y = 24, .x = 11, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

