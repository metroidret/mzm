#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_96_Clipdata[222] = {
    #include "extracted/data/rooms/chozodia/chozodia_96_clipdata.gfx.inc"
};

const u8 sChozodia_96_Bg2[805] = {
    #include "extracted/data/rooms/chozodia/chozodia_96_bg2.gfx.inc"
};

const u8 sChozodia_96_Bg1[861] = {
    #include "extracted/data/rooms/chozodia/chozodia_96_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_96_SpriteLayer0[7] = {
    { .y = 7, .x = 46, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 32, .id = SPRITESET_IDX(3) },
    { .y = 18, .x = 40, .id = SPRITESET_IDX(0) },
    { .y = 20, .x = 21, .id = SPRITESET_IDX(3) },
    { .y = 25, .x = 27, .id = SPRITESET_IDX(3) },
    { .y = 30, .x = 46, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_96_Bg0[71] = {
    #include "extracted/data/rooms/chozodia/chozodia_96_bg0.gfx.inc"
};

