#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_7_Clipdata[692] = {
    #include "extracted/data/rooms/brinstar/brinstar_7_clipdata.gfx.inc"
};

const u8 sBrinstar_7_Bg2[] = {
    #include "extracted/data/rooms/brinstar/brinstar_7_bg2.gfx.inc"
};

const struct SpriteDataRom sBrinstar_7_Spriteset1[19] = {
    { .y = 12, .x = 5, .id = SPRITESET_IDX(2) },
    { .y = 15, .x = 5, .id = SPRITESET_IDX(1) },
    { .y = 25, .x = 8, .id = SPRITESET_IDX(1) },
    { .y = 35, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 36, .x = 7, .id = SPRITESET_IDX(2) },
    { .y = 43, .x = 8, .id = SPRITESET_IDX(2) },
    { .y = 45, .x = 11, .id = SPRITESET_IDX(1) },
    { .y = 55, .x = 8, .id = SPRITESET_IDX(1) },
    { .y = 62, .x = 9, .id = SPRITESET_IDX(5) },
    { .y = 65, .x = 4, .id = SPRITESET_IDX(5) },
    { .y = 67, .x = 6, .id = SPRITESET_IDX(5) },
    { .y = 67, .x = 8, .id = SPRITESET_IDX(5) },
    { .y = 75, .x = 5, .id = SPRITESET_IDX(5) },
    { .y = 78, .x = 10, .id = SPRITESET_IDX(1) },
    { .y = 80, .x = 6, .id = SPRITESET_IDX(2) },
    { .y = 82, .x = 10, .id = SPRITESET_IDX(1) },
    { .y = 84, .x = 6, .id = SPRITESET_IDX(1) },
    { .y = 89, .x = 9, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_7_Bg1[] = {
    #include "extracted/data/rooms/brinstar/brinstar_7_bg1.gfx.inc"
};

const struct SpriteDataRom sBrinstar_7_Spriteset0[18] = {
    { .y = 6, .x = 10, .id = SPRITESET_IDX(5) },
    { .y = 6, .x = 12, .id = SPRITESET_IDX(5) },
    { .y = 9, .x = 5, .id = SPRITESET_IDX(2) },
    { .y = 12, .x = 5, .id = SPRITESET_IDX(2) },
    { .y = 15, .x = 5, .id = SPRITESET_IDX(1) },
    { .y = 25, .x = 8, .id = SPRITESET_IDX(1) },
    { .y = 35, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 36, .x = 7, .id = SPRITESET_IDX(2) },
    { .y = 43, .x = 8, .id = SPRITESET_IDX(2) },
    { .y = 45, .x = 11, .id = SPRITESET_IDX(0) },
    { .y = 55, .x = 8, .id = SPRITESET_IDX(0) },
    { .y = 67, .x = 6, .id = SPRITESET_IDX(5) },
    { .y = 78, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 80, .x = 6, .id = SPRITESET_IDX(2) },
    { .y = 82, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 84, .x = 6, .id = SPRITESET_IDX(1) },
    { .y = 89, .x = 9, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

