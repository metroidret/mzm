#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_61_Clipdata[81] = {
    #include "extracted/data/rooms/chozodia/chozodia_61_clipdata.gfx.inc"
};

const u8 sChozodia_61_Bg1[173] = {
    #include "extracted/data/rooms/chozodia/chozodia_61_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_61_Spriteset0[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_61_Bg0[44] = {
    #include "extracted/data/rooms/chozodia/chozodia_61_bg0.gfx.inc"
};

