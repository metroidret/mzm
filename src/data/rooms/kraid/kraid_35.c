#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_35_Clipdata[56] = {
    #include "extracted/data/rooms/kraid/kraid_35_clipdata.gfx.inc"
};

const u8 sKraid_35_Bg2[14] = {
    #include "extracted/data/rooms/kraid/kraid_35_bg2.gfx.inc"
};

const u8 sKraid_35_Bg1[193] = {
    #include "extracted/data/rooms/kraid/kraid_35_bg1.gfx.inc"
};

const struct SpriteDataRom sKraid_35_Spriteset0[2] = {
    { .y = 6, .x = 5, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

