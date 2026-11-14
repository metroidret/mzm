#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_21_Clipdata[89] = {
    #include "extracted/data/rooms/chozodia/chozodia_21_clipdata.gfx.inc"
};

const u8 sChozodia_21_Bg1[199] = {
    #include "extracted/data/rooms/chozodia/chozodia_21_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_21_SpriteLayer0[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_21_Bg0[46] = {
    #include "extracted/data/rooms/chozodia/chozodia_21_bg0.gfx.inc"
};

