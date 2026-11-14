#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_74_Clipdata[84] = {
    #include "extracted/data/rooms/chozodia/chozodia_74_clipdata.gfx.inc"
};

const u8 sChozodia_74_Bg1[189] = {
    #include "extracted/data/rooms/chozodia/chozodia_74_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_74_SpriteLayer0[2] = {
    { .y = 10, .x = 10, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_74_Bg0[45] = {
    #include "extracted/data/rooms/chozodia/chozodia_74_bg0.gfx.inc"
};

