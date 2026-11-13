#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_43_Clipdata[105] = {
    #include "extracted/data/rooms/chozodia/chozodia_43_clipdata.gfx.inc"
};

const u8 sChozodia_43_Bg2[184] = {
    #include "extracted/data/rooms/chozodia/chozodia_43_bg2.gfx.inc"
};

const u8 sChozodia_43_Bg1[276] = {
    #include "extracted/data/rooms/chozodia/chozodia_43_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_43_Spriteset0[3] = {
    { .y = 6, .x = 2, .id = SPRITESET_IDX(1) },
    { .y = 16, .x = 16, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

