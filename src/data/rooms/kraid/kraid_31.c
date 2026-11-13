#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_31_Clipdata[67] = {
    #include "extracted/data/rooms/kraid/kraid_31_clipdata.gfx.inc"
};

const u8 sKraid_31_Bg2[18] = {
    #include "extracted/data/rooms/kraid/kraid_31_bg2.gfx.inc"
};

const u8 sKraid_31_Bg1[208] = {
    #include "extracted/data/rooms/kraid/kraid_31_bg1.gfx.inc"
};

const struct SpriteDataRom sKraid_31_Spriteset0[2] = {
    { .y = 10, .x = 8, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

