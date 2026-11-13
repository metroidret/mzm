#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_73_Clipdata[143] = {
    #include "extracted/data/rooms/chozodia/chozodia_73_clipdata.gfx.inc"
};

const u8 sChozodia_73_Bg2[139] = {
    #include "extracted/data/rooms/chozodia/chozodia_73_bg2.gfx.inc"
};

const u8 sChozodia_73_Bg1[450] = {
    #include "extracted/data/rooms/chozodia/chozodia_73_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_73_Spriteset0[4] = {
    { .y = 19, .x = 6, .id = SPRITESET_IDX(0) },
    { .y = 19, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 19, .x = 13, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_73_Bg0[108] = {
    #include "extracted/data/rooms/chozodia/chozodia_73_bg0.gfx.inc"
};

