#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_17_Clipdata[112] = {
    #include "extracted/data/rooms/norfair/norfair_17_clipdata.gfx.inc"
};

const u8 sNorfair_17_Bg2[20] = {
    #include "extracted/data/rooms/norfair/norfair_17_bg2.gfx.inc"
};

const struct SpriteDataRom sNorfair_17_Spriteset1[5] = {
    { .y = 4, .x = 12, .id = SPRITESET_IDX(2) },
    { .y = 5, .x = 24, .id = SPRITESET_IDX(2) },
    { .y = 7, .x = 11, .id = SPRITESET_IDX(2) },
    { .y = 9, .x = 18, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_17_Bg1[249] = {
    #include "extracted/data/rooms/norfair/norfair_17_bg1.gfx.inc"
};

const struct SpriteDataRom sNorfair_17_Spriteset0[7] = {
    { .y = 4, .x = 12, .id = SPRITESET_IDX(2) },
    { .y = 5, .x = 24, .id = SPRITESET_IDX(2) },
    { .y = 6, .x = 17, .id = SPRITESET_IDX(2) },
    { .y = 7, .x = 11, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 21, .id = SPRITESET_IDX(2) },
    { .y = 9, .x = 12, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

