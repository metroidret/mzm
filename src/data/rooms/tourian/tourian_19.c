#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_19_Clipdata[149] = {
    #include "extracted/data/rooms/tourian/tourian_19_clipdata.gfx.inc"
};

const u8 sTourian_19_Bg2[129] = {
    #include "extracted/data/rooms/tourian/tourian_19_bg2.gfx.inc"
};

const struct SpriteDataRom sTourian_19_Spriteset1[15] = {
    { .y = 2, .x = 26, .id = SPRITESET_IDX(1) },
    { .y = 5, .x = 28, .id = SPRITESET_IDX(0) },
    { .y = 6, .x = 19, .id = SPRITESET_IDX(0) },
    { .y = 6, .x = 24, .id = SPRITESET_IDX(0) },
    { .y = 10, .x = 15, .id = SPRITESET_IDX(1) },
    { .y = 11, .x = 7, .id = SPRITESET_IDX(1) },
    { .y = 11, .x = 22, .id = SPRITESET_IDX(0) },
    { .y = 12, .x = 17, .id = SPRITESET_IDX(1) },
    { .y = 14, .x = 11, .id = SPRITESET_IDX(0) },
    { .y = 15, .x = 5, .id = SPRITESET_IDX(0) },
    { .y = 15, .x = 18, .id = SPRITESET_IDX(0) },
    { .y = 17, .x = 14, .id = SPRITESET_IDX(0) },
    { .y = 19, .x = 7, .id = SPRITESET_IDX(1) },
    { .y = 19, .x = 21, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_19_Bg1[387] = {
    #include "extracted/data/rooms/tourian/tourian_19_bg1.gfx.inc"
};

const struct SpriteDataRom sTourian_19_Spriteset0[11] = {
    { .y = 2, .x = 26, .id = SPRITESET_IDX(1) },
    { .y = 4, .x = 17, .id = SPRITESET_IDX(0) },
    { .y = 5, .x = 28, .id = SPRITESET_IDX(0) },
    { .y = 10, .x = 15, .id = SPRITESET_IDX(1) },
    { .y = 11, .x = 7, .id = SPRITESET_IDX(1) },
    { .y = 12, .x = 17, .id = SPRITESET_IDX(1) },
    { .y = 15, .x = 4, .id = SPRITESET_IDX(0) },
    { .y = 15, .x = 18, .id = SPRITESET_IDX(0) },
    { .y = 19, .x = 7, .id = SPRITESET_IDX(1) },
    { .y = 19, .x = 21, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};
