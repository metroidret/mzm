#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_15_Clipdata[81] = {
    #include "extracted/data/rooms/chozodia/chozodia_15_clipdata.gfx.inc"
};

const u8 sChozodia_15_Bg1[173] = {
    #include "extracted/data/rooms/chozodia/chozodia_15_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_15_Spriteset0[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_15_Bg0[44] = {
    #include "extracted/data/rooms/chozodia/chozodia_15_bg0.gfx.inc"
};

