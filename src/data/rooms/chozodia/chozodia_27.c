#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_27_Clipdata[85] = {
    #include "extracted/data/rooms/chozodia/chozodia_27_clipdata.gfx.inc"
};

const u8 sChozodia_27_Bg1[198] = {
    #include "extracted/data/rooms/chozodia/chozodia_27_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_27_Spriteset0[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_27_Bg0[43] = {
    #include "extracted/data/rooms/chozodia/chozodia_27_bg0.gfx.inc"
};

