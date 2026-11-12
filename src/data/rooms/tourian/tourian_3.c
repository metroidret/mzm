#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_3_Clipdata[64] = {
    #include "extracted/data/rooms/tourian/tourian_3_clipdata.gfx.inc"
};

const u8 sTourian_3_Bg2[14] = {
    #include "extracted/data/rooms/tourian/tourian_3_bg2.gfx.inc"
};

const u8 sTourian_3_Bg1[225] = {
    #include "extracted/data/rooms/tourian/tourian_3_bg1.gfx.inc"
};

const struct SpriteDataRom sTourian_3_Spriteset0[8] = {
    { .y = 2, .x = 9, .id = SPRITESET_IDX(1) },
    { .y = 2, .x = 14, .id = SPRITESET_IDX(2) },
    { .y = 2, .x = 19, .id = SPRITESET_IDX(2) },
    { .y = 2, .x = 24, .id = SPRITESET_IDX(1) },
    { .y = 2, .x = 29, .id = SPRITESET_IDX(2) },
    { .y = 2, .x = 34, .id = SPRITESET_IDX(2) },
    { .y = 2, .x = 39, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

