#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_41_Clipdata[214] = {
    #include "extracted/data/rooms/brinstar/brinstar_41_clipdata.gfx.inc"
};

const u8 sBrinstar_41_Bg2[100] = {
    #include "extracted/data/rooms/brinstar/brinstar_41_bg2.gfx.inc"
};

const struct SpriteDataRom sBrinstar_41_Spriteset1[18] = {
    { .y = 1, .x = 4, .id = SPRITESET_IDX(5) },
    { .y = 1, .x = 5, .id = SPRITESET_IDX(5) },
    { .y = 1, .x = 8, .id = SPRITESET_IDX(5) },
    { .y = 1, .x = 9, .id = SPRITESET_IDX(5) },
    { .y = 3, .x = 5, .id = SPRITESET_IDX(3) },
    { .y = 3, .x = 8, .id = SPRITESET_IDX(3) },
    { .y = 5, .x = 4, .id = SPRITESET_IDX(5) },
    { .y = 5, .x = 7, .id = SPRITESET_IDX(5) },
    { .y = 5, .x = 8, .id = SPRITESET_IDX(5) },
    { .y = 8, .x = 6, .id = SPRITESET_IDX(3) },
    { .y = 10, .x = 9, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 10, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 11, .id = SPRITESET_IDX(1) },
    { .y = 11, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 12, .x = 8, .id = SPRITESET_IDX(1) },
    { .y = 12, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 16, .x = 8, .id = SPRITESET_IDX(3) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_41_Bg1[765] = {
    #include "extracted/data/rooms/brinstar/brinstar_41_bg1.gfx.inc"
};

const struct SpriteDataRom sBrinstar_41_Spriteset0[17] = {
    { .y = 1, .x = 4, .id = SPRITESET_IDX(5) },
    { .y = 1, .x = 5, .id = SPRITESET_IDX(5) },
    { .y = 1, .x = 9, .id = SPRITESET_IDX(5) },
    { .y = 3, .x = 5, .id = SPRITESET_IDX(3) },
    { .y = 3, .x = 8, .id = SPRITESET_IDX(3) },
    { .y = 5, .x = 4, .id = SPRITESET_IDX(5) },
    { .y = 5, .x = 7, .id = SPRITESET_IDX(5) },
    { .y = 5, .x = 8, .id = SPRITESET_IDX(5) },
    { .y = 8, .x = 6, .id = SPRITESET_IDX(3) },
    { .y = 10, .x = 9, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 10, .x = 11, .id = SPRITESET_IDX(1) },
    { .y = 11, .x = 12, .id = SPRITESET_IDX(0) },
    { .y = 12, .x = 8, .id = SPRITESET_IDX(1) },
    { .y = 12, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 16, .x = 8, .id = SPRITESET_IDX(3) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_41_Bg0[48] = {
    #include "extracted/data/rooms/brinstar/brinstar_41_bg0.gfx.inc"
};
