#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_28_Clipdata[251] = {
    #include "extracted/data/rooms/norfair/norfair_28_clipdata.gfx.inc"
};

const u8 sNorfair_28_Bg2[165] = {
    #include "extracted/data/rooms/norfair/norfair_28_bg2.gfx.inc"
};

const u8 sNorfair_28_Bg1[724] = {
    #include "extracted/data/rooms/norfair/norfair_28_bg1.gfx.inc"
};

const struct SpriteDataRom sNorfair_28_Spriteset0[12] = {
    { .y = 7, .x = 24, .id = SPRITESET_IDX(0) },
    { .y = 7, .x = 46, .id = SPRITESET_IDX(0) },
    { .y = 7, .x = 52, .id = SPRITESET_IDX(1) },
    { .y = 7, .x = 56, .id = SPRITESET_IDX(1) },
    { .y = 8, .x = 11, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 54, .id = SPRITESET_IDX(1) },
    { .y = 12, .x = 7, .id = SPRITESET_IDX(4) },
    { .y = 12, .x = 12, .id = SPRITESET_IDX(4) },
    { .y = 12, .x = 25, .id = SPRITESET_IDX(4) },
    { .y = 12, .x = 34, .id = SPRITESET_IDX(4) },
    { .y = 12, .x = 40, .id = SPRITESET_IDX(4) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_28_Bg0[832] = {
    #include "extracted/data/rooms/norfair/norfair_28_bg0.gfx.inc"
};

