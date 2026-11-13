#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_12_Clipdata[110] = {
    #include "extracted/data/rooms/norfair/norfair_12_clipdata.gfx.inc"
};

const struct SpriteDataRom sNorfair_12_Spriteset2[4] = {
    { .y = 4, .x = 14, .id = SPRITESET_IDX(2) },
    { .y = 4, .x = 17, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 20, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_12_Bg2[48] = {
    #include "extracted/data/rooms/norfair/norfair_12_bg2.gfx.inc"
};

const struct SpriteDataRom sNorfair_12_Spriteset1[6] = {
    { .y = 4, .x = 14, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 17, .id = SPRITESET_IDX(2) },
    { .y = 4, .x = 20, .id = SPRITESET_IDX(3) },
    { .y = 5, .x = 16, .id = SPRITESET_IDX(3) },
    { .y = 5, .x = 18, .id = SPRITESET_IDX(3) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_12_Bg1[269] = {
    #include "extracted/data/rooms/norfair/norfair_12_bg1.gfx.inc"
};

const struct SpriteDataRom sNorfair_12_Spriteset0[6] = {
    { .y = 4, .x = 14, .id = SPRITESET_IDX(2) },
    { .y = 4, .x = 17, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 20, .id = SPRITESET_IDX(2) },
    { .y = 5, .x = 16, .id = SPRITESET_IDX(2) },
    { .y = 5, .x = 18, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_12_Bg0[129] = {
    #include "extracted/data/rooms/norfair/norfair_12_bg0.gfx.inc"
};

