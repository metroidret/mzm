#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_17_Clipdata[71] = {
    #include "extracted/data/rooms/brinstar/brinstar_17_clipdata.gfx.inc"
};

const u8 sBrinstar_17_Bg2[89] = {
    #include "extracted/data/rooms/brinstar/brinstar_17_bg2.gfx.inc"
};

const u8 sBrinstar_17_Bg1[265] = {
    #include "extracted/data/rooms/brinstar/brinstar_17_bg1.gfx.inc"
};

const struct SpriteDataRom sBrinstar_17_Spriteset0[6] = {
    { .y = 4, .x = 14, .id = SPRITESET_IDX(0) },
    { .y = 5, .x = 20, .id = SPRITESET_IDX(0) },
    { .y = 6, .x = 16, .id = SPRITESET_IDX(0) },
    { .y = 8, .x = 13, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 19, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

