#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_20_Clipdata[74] = {
    #include "extracted/data/rooms/kraid/kraid_20_clipdata.gfx.inc"
};

const u8 sKraid_20_Bg2[14] = {
    #include "extracted/data/rooms/kraid/kraid_20_bg2.gfx.inc"
};

const u8 sKraid_20_Bg1[210] = {
    #include "extracted/data/rooms/kraid/kraid_20_bg1.gfx.inc"
};

const struct SpriteDataRom sKraid_20_Spriteset0[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

