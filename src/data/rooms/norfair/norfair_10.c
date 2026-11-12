#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_10_Clipdata[160] = {
    #include "extracted/data/rooms/norfair/norfair_10_clipdata.gfx.inc"
};

const u8 sNorfair_10_Bg2[134] = {
    #include "extracted/data/rooms/norfair/norfair_10_bg2.gfx.inc"
};

const struct SpriteDataRom sNorfair_10_Spriteset1[7] = {
    { .y = 4, .x = 27, .id = SPRITESET_IDX(3) },
    { .y = 7, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 7, .x = 22, .id = SPRITESET_IDX(0) },
    { .y = 8, .x = 35, .id = SPRITESET_IDX(0) },
    { .y = 12, .x = 4, .id = SPRITESET_IDX(4) },
    { .y = 12, .x = 28, .id = SPRITESET_IDX(4) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_10_Bg1[341] = {
    #include "extracted/data/rooms/norfair/norfair_10_bg1.gfx.inc"
};

const struct SpriteDataRom sNorfair_10_Spriteset0[7] = {
    { .y = 4, .x = 27, .id = SPRITESET_IDX(3) },
    { .y = 7, .x = 22, .id = SPRITESET_IDX(0) },
    { .y = 8, .x = 35, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 18, .id = SPRITESET_IDX(1) },
    { .y = 12, .x = 4, .id = SPRITESET_IDX(4) },
    { .y = 12, .x = 28, .id = SPRITESET_IDX(4) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_10_Bg0[659] = {
    #include "extracted/data/rooms/norfair/norfair_10_bg0.gfx.inc"
};

