#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_7_Clipdata[180] = {
    #include "extracted/data/rooms/norfair/norfair_7_clipdata.gfx.inc"
};

const u8 sNorfair_7_Bg2[251] = {
    #include "extracted/data/rooms/norfair/norfair_7_bg2.gfx.inc"
};

const struct SpriteDataRom sNorfair_7_Spriteset1[7] = {
    { .y = 4, .x = 8, .id = SPRITESET_IDX(2) },
    { .y = 14, .x = 8, .id = SPRITESET_IDX(2) },
    { .y = 16, .x = 5, .id = SPRITESET_IDX(1) },
    { .y = 17, .x = 10, .id = SPRITESET_IDX(2) },
    { .y = 17, .x = 13, .id = SPRITESET_IDX(1) },
    { .y = 20, .x = 7, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_7_Bg1[478] = {
    #include "extracted/data/rooms/norfair/norfair_7_bg1.gfx.inc"
};

const struct SpriteDataRom sNorfair_7_Spriteset0[4] = {
    { .y = 11, .x = 11, .id = SPRITESET_IDX(2) },
    { .y = 15, .x = 9, .id = SPRITESET_IDX(2) },
    { .y = 19, .x = 7, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_7_Bg0[82] = {
    #include "extracted/data/rooms/norfair/norfair_7_bg0.gfx.inc"
};

