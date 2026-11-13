#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_7_Clipdata[538] = {
    #include "extracted/data/rooms/crateria/crateria_7_clipdata.gfx.inc"
};

const u8 sCrateria_7_Bg2[1867] = {
    #include "extracted/data/rooms/crateria/crateria_7_bg2.gfx.inc"
};

const u8 sCrateria_7_Bg1[1592] = {
    #include "extracted/data/rooms/crateria/crateria_7_bg1.gfx.inc"
};

const struct SpriteDataRom sCrateria_7_Spriteset0[20] = {
    { .y = 3, .x = 65, .id = SPRITESET_IDX(1) },
    { .y = 4, .x = 54, .id = SPRITESET_IDX(1) },
    { .y = 4, .x = 59, .id = SPRITESET_IDX(1) },
    { .y = 5, .x = 50, .id = SPRITESET_IDX(1) },
    { .y = 6, .x = 45, .id = SPRITESET_IDX(1) },
    { .y = 7, .x = 30, .id = SPRITESET_IDX(1) },
    { .y = 7, .x = 36, .id = SPRITESET_IDX(1) },
    { .y = 8, .x = 14, .id = SPRITESET_IDX(1) },
    { .y = 8, .x = 21, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 28, .id = SPRITESET_IDX(1) },
    { .y = 23, .x = 35, .id = SPRITESET_IDX(0) },
    { .y = 23, .x = 78, .id = SPRITESET_IDX(0) },
    { .y = 24, .x = 27, .id = SPRITESET_IDX(0) },
    { .y = 24, .x = 49, .id = SPRITESET_IDX(0) },
    { .y = 24, .x = 70, .id = SPRITESET_IDX(0) },
    { .y = 25, .x = 84, .id = SPRITESET_IDX(0) },
    { .y = 26, .x = 43, .id = SPRITESET_IDX(0) },
    { .y = 26, .x = 75, .id = SPRITESET_IDX(0) },
    { .y = 27, .x = 5, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

