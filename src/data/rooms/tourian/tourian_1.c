#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_1_Clipdata[182] = {
    #include "extracted/data/rooms/tourian/tourian_1_clipdata.gfx.inc"
};

const u8 sTourian_1_Bg2[116] = {
    #include "extracted/data/rooms/tourian/tourian_1_bg2.gfx.inc"
};

const struct SpriteDataRom sTourian_1_Spriteset1[16] = {
    { .y = 2, .x = 19, .id = SPRITESET_IDX(1) },
    { .y = 3, .x = 22, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 57, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 71, .id = SPRITESET_IDX(0) },
    { .y = 4, .x = 42, .id = SPRITESET_IDX(0) },
    { .y = 5, .x = 72, .id = SPRITESET_IDX(0) },
    { .y = 6, .x = 58, .id = SPRITESET_IDX(0) },
    { .y = 7, .x = 22, .id = SPRITESET_IDX(0) },
    { .y = 8, .x = 64, .id = SPRITESET_IDX(1) },
    { .y = 8, .x = 69, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 33, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 53, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 11, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 48, .id = SPRITESET_IDX(1) },
    { .y = 11, .x = 23, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_1_Bg1[436] = {
    #include "extracted/data/rooms/tourian/tourian_1_bg1.gfx.inc"
};

const struct SpriteDataRom sTourian_1_Spriteset0[10] = {
    { .y = 2, .x = 19, .id = SPRITESET_IDX(1) },
    { .y = 4, .x = 42, .id = SPRITESET_IDX(0) },
    { .y = 4, .x = 58, .id = SPRITESET_IDX(0) },
    { .y = 5, .x = 21, .id = SPRITESET_IDX(0) },
    { .y = 5, .x = 72, .id = SPRITESET_IDX(0) },
    { .y = 8, .x = 69, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 11, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 48, .id = SPRITESET_IDX(1) },
    { .y = 11, .x = 23, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_1_Bg0[264] = {
    #include "extracted/data/rooms/tourian/tourian_1_bg0.gfx.inc"
};

