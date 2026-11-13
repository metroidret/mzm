#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_46_Clipdata[83] = {
    #include "extracted/data/rooms/chozodia/chozodia_46_clipdata.gfx.inc"
};

const u8 sChozodia_46_Bg2[230] = {
    #include "extracted/data/rooms/chozodia/chozodia_46_bg2.gfx.inc"
};

const u8 sChozodia_46_Bg1[207] = {
    #include "extracted/data/rooms/chozodia/chozodia_46_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_46_Spriteset0[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_46_Bg0[66] = {
    #include "extracted/data/rooms/chozodia/chozodia_46_bg0.gfx.inc"
};

