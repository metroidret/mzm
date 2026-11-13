#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_40_Clipdata[93] = {
    #include "extracted/data/rooms/brinstar/brinstar_40_clipdata.gfx.inc"
};

const u8 sBrinstar_40_Bg2[14] = {
    #include "extracted/data/rooms/brinstar/brinstar_40_bg2.gfx.inc"
};

const u8 sBrinstar_40_Bg1[236] = {
    #include "extracted/data/rooms/brinstar/brinstar_40_bg1.gfx.inc"
};

const struct SpriteDataRom sBrinstar_40_Spriteset0[3] = {
    { .y = 8, .x = 10, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 15, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

