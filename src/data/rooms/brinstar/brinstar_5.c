#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_5_Clipdata[52] = {
    #include "extracted/data/rooms/brinstar/brinstar_5_clipdata.gfx.inc"
};

const u8 sBrinstar_5_Bg2[145] = {
    #include "extracted/data/rooms/brinstar/brinstar_5_bg2.gfx.inc"
};

const u8 sBrinstar_5_Bg1[141] = {
    #include "extracted/data/rooms/brinstar/brinstar_5_bg1.gfx.inc"
};

const struct SpriteDataRom sBrinstar_5_Spriteset0[2] = {
    { .y = 7, .x = 6, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

