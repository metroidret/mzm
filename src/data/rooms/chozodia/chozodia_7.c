#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_7_Clipdata[73] = {
    #include "extracted/data/rooms/chozodia/chozodia_7_clipdata.gfx.inc"
};

const u8 sChozodia_7_Bg2[114] = {
    #include "extracted/data/rooms/chozodia/chozodia_7_bg2.gfx.inc"
};

const struct SpriteDataRom sChozodia_7_Spriteset1[3] = {
    { .y = 5, .x = 11, .id = SPRITESET_IDX(3) },
    { .y = 9, .x = 16, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_7_Bg1[204] = {
    #include "extracted/data/rooms/chozodia/chozodia_7_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_7_Spriteset0[1] = {
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_7_Bg0[45] = {
    #include "extracted/data/rooms/chozodia/chozodia_7_bg0.gfx.inc"
};

