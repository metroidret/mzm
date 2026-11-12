#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_75_Clipdata[83] = {
    #include "extracted/data/rooms/chozodia/chozodia_75_clipdata.gfx.inc"
};

const u8 sChozodia_75_Bg1[194] = {
    #include "extracted/data/rooms/chozodia/chozodia_75_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_75_Spriteset0[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_75_Bg0[45] = {
    #include "extracted/data/rooms/chozodia/chozodia_75_bg0.gfx.inc"
};

