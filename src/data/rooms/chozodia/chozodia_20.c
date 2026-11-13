#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_20_Clipdata[412] = {
    #include "extracted/data/rooms/chozodia/chozodia_20_clipdata.gfx.inc"
};

const u8 sChozodia_20_Bg2[741] = {
    #include "extracted/data/rooms/chozodia/chozodia_20_bg2.gfx.inc"
};

const u8 sChozodia_20_Bg1[977] = {
    #include "extracted/data/rooms/chozodia/chozodia_20_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_20_Spriteset0[3] = {
    { .y = 16, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 16, .x = 13, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_20_Bg0[885] = {
    #include "extracted/data/rooms/chozodia/chozodia_20_bg0.gfx.inc"
};

