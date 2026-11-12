#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_15_Clipdata[218] = {
    #include "extracted/data/rooms/tourian/tourian_15_clipdata.gfx.inc"
};

const u8 sTourian_15_Bg2[102] = {
    #include "extracted/data/rooms/tourian/tourian_15_bg2.gfx.inc"
};

const struct SpriteDataRom sTourian_15_Spriteset1[12] = {
    { .y = 17, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 18, .x = 3, .id = SPRITESET_IDX(1) },
    { .y = 23, .x = 7, .id = SPRITESET_IDX(0) },
    { .y = 23, .x = 15, .id = SPRITESET_IDX(1) },
    { .y = 27, .x = 15, .id = SPRITESET_IDX(1) },
    { .y = 28, .x = 3, .id = SPRITESET_IDX(1) },
    { .y = 28, .x = 13, .id = SPRITESET_IDX(0) },
    { .y = 31, .x = 5, .id = SPRITESET_IDX(0) },
    { .y = 37, .x = 3, .id = SPRITESET_IDX(1) },
    { .y = 39, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 41, .x = 8, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_15_Bg1[573] = {
    #include "extracted/data/rooms/tourian/tourian_15_bg1.gfx.inc"
};

const struct SpriteDataRom sTourian_15_Spriteset0[7] = {
    { .y = 18, .x = 3, .id = SPRITESET_IDX(1) },
    { .y = 18, .x = 5, .id = SPRITESET_IDX(0) },
    { .y = 27, .x = 15, .id = SPRITESET_IDX(1) },
    { .y = 28, .x = 3, .id = SPRITESET_IDX(1) },
    { .y = 28, .x = 13, .id = SPRITESET_IDX(0) },
    { .y = 41, .x = 8, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

