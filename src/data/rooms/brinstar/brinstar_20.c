#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_20_Clipdata[336] = {
    #include "extracted/data/rooms/brinstar/brinstar_20_clipdata.gfx.inc"
};

const u8 sBrinstar_20_Bg2[211] = {
    #include "extracted/data/rooms/brinstar/brinstar_20_bg2.gfx.inc"
};

const u8 sBrinstar_20_Bg1[1163] = {
    #include "extracted/data/rooms/brinstar/brinstar_20_bg1.gfx.inc"
};

const struct SpriteDataRom sBrinstar_20_Spriteset0[6] = {
    { .y = 16, .x = 4, .id = SPRITESET_IDX(2) },
    { .y = 22, .x = 5, .id = SPRITESET_IDX(2) },
    { .y = 33, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 38, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 47, .x = 10, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

