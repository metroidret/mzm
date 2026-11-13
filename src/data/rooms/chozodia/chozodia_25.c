#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_25_Clipdata[215] = {
    #include "extracted/data/rooms/chozodia/chozodia_25_clipdata.gfx.inc"
};

const u8 sChozodia_25_Bg2[868] = {
    #include "extracted/data/rooms/chozodia/chozodia_25_bg2.gfx.inc"
};

const u8 sChozodia_25_Bg1[902] = {
    #include "extracted/data/rooms/chozodia/chozodia_25_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_25_SpriteLayer0[2] = {
    { .y = 5, .x = 21, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

