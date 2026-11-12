#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_9_Clipdata[117] = {
    #include "extracted/data/rooms/norfair/norfair_9_clipdata.gfx.inc"
};

const struct SpriteDataRom sNorfair_9_Spriteset2[3] = {
    { .y = 11, .x = 20, .id = SPRITESET_IDX(0) },
    { .y = 11, .x = 31, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_9_Bg2[14] = {
    #include "extracted/data/rooms/norfair/norfair_9_bg2.gfx.inc"
};

const struct SpriteDataRom sNorfair_9_Spriteset1[9] = {
    { .y = 2, .x = 20, .id = SPRITESET_IDX(0) },
    { .y = 2, .x = 31, .id = SPRITESET_IDX(0) },
    { .y = 11, .x = 18, .id = SPRITESET_IDX(0) },
    { .y = 11, .x = 20, .id = SPRITESET_IDX(2) },
    { .y = 11, .x = 23, .id = SPRITESET_IDX(0) },
    { .y = 11, .x = 28, .id = SPRITESET_IDX(2) },
    { .y = 11, .x = 34, .id = SPRITESET_IDX(0) },
    { .y = 11, .x = 36, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_9_Bg1[282] = {
    #include "extracted/data/rooms/norfair/norfair_9_bg1.gfx.inc"
};

const struct SpriteDataRom sNorfair_9_Spriteset0[6] = {
    { .y = 2, .x = 20, .id = SPRITESET_IDX(0) },
    { .y = 2, .x = 31, .id = SPRITESET_IDX(0) },
    { .y = 11, .x = 18, .id = SPRITESET_IDX(0) },
    { .y = 11, .x = 26, .id = SPRITESET_IDX(0) },
    { .y = 11, .x = 34, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_9_Bg0[265] = {
    #include "extracted/data/rooms/norfair/norfair_9_bg0.gfx.inc"
};

