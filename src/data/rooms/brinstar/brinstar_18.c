#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_18_Clipdata[52] = {
    #include "extracted/data/rooms/brinstar/brinstar_18_clipdata.gfx.inc"
};

const u8 sBrinstar_18_Bg2[172] = {
    #include "extracted/data/rooms/brinstar/brinstar_18_bg2.gfx.inc"
};

const u8 sBrinstar_18_Bg1[135] = {
    #include "extracted/data/rooms/brinstar/brinstar_18_bg1.gfx.inc"
};

const struct SpriteDataRom sBrinstar_18_Spriteset0[2] = {
    { .y = 9, .x = 6, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

