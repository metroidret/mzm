#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_47_Clipdata[151] = {
    #include "extracted/data/rooms/norfair/norfair_47_clipdata.gfx.inc"
};

const struct SpriteDataRom sNorfair_47_Spriteset2[4] = {
    { .y = 6, .x = 11, .id = SPRITESET_IDX(2) },
    { .y = 6, .x = 14, .id = SPRITESET_IDX(2) },
    { .y = 6, .x = 22, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_47_Bg2[65] = {
    #include "extracted/data/rooms/norfair/norfair_47_bg2.gfx.inc"
};

const struct SpriteDataRom sNorfair_47_Spriteset1[5] = {
    { .y = 6, .x = 11, .id = SPRITESET_IDX(2) },
    { .y = 6, .x = 14, .id = SPRITESET_IDX(2) },
    { .y = 6, .x = 22, .id = SPRITESET_IDX(2) },
    { .y = 10, .x = 27, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_47_Bg1[277] = {
    #include "extracted/data/rooms/norfair/norfair_47_bg1.gfx.inc"
};

const struct SpriteDataRom sNorfair_47_Spriteset0[5] = {
    { .y = 6, .x = 11, .id = SPRITESET_IDX(2) },
    { .y = 6, .x = 14, .id = SPRITESET_IDX(2) },
    { .y = 6, .x = 22, .id = SPRITESET_IDX(2) },
    { .y = 10, .x = 27, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

