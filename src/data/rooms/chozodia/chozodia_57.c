#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_57_Clipdata[542] = {
    #include "extracted/data/rooms/chozodia/chozodia_57_clipdata.gfx.inc"
};

const u8 sChozodia_57_Bg2[128] = {
    #include "extracted/data/rooms/chozodia/chozodia_57_bg2.gfx.inc"
};

const u8 sChozodia_57_Bg1[1626] = {
    #include "extracted/data/rooms/chozodia/chozodia_57_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_57_SpriteLayer0[4] = {
    { .y = 57, .x = 6, .id = SPRITESET_IDX(0) },
    { .y = 62, .x = 13, .id = SPRITESET_IDX(0) },
    { .y = 78, .x = 11, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_57_Bg0[456] = {
    #include "extracted/data/rooms/chozodia/chozodia_57_bg0.gfx.inc"
};

