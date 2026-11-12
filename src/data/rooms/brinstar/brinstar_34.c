#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_34_Clipdata[69] = {
    #include "extracted/data/rooms/brinstar/brinstar_34_clipdata.gfx.inc"
};

const u8 sBrinstar_34_Bg2[14] = {
    #include "extracted/data/rooms/brinstar/brinstar_34_bg2.gfx.inc"
};

const u8 sBrinstar_34_Bg1[213] = {
    #include "extracted/data/rooms/brinstar/brinstar_34_bg1.gfx.inc"
};

const struct SpriteDataRom sBrinstar_34_Spriteset0[2] = {
    { .y = 10, .x = 10, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

