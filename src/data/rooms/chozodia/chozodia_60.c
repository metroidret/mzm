#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_60_Clipdata[256] = {
    #include "extracted/data/rooms/chozodia/chozodia_60_clipdata.gfx.inc"
};

const u8 sChozodia_60_Bg2[811] = {
    #include "extracted/data/rooms/chozodia/chozodia_60_bg2.gfx.inc"
};

const u8 sChozodia_60_Bg1[858] = {
    #include "extracted/data/rooms/chozodia/chozodia_60_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_60_SpriteLayer0[6] = {
    { .y = 7, .x = 46, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 32, .id = SPRITESET_IDX(3) },
    { .y = 20, .x = 21, .id = SPRITESET_IDX(3) },
    { .y = 29, .x = 23, .id = SPRITESET_IDX(0) },
    { .y = 30, .x = 46, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_60_Bg0[45] = {
    #include "extracted/data/rooms/chozodia/chozodia_60_bg0.gfx.inc"
};

