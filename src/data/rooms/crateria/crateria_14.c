#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_14_Clipdata[84] = {
    #include "extracted/data/rooms/crateria/crateria_14_clipdata.gfx.inc"
};

const u8 sCrateria_14_Bg2[131] = {
    #include "extracted/data/rooms/crateria/crateria_14_bg2.gfx.inc"
};

const u8 sCrateria_14_Bg1[271] = {
    #include "extracted/data/rooms/crateria/crateria_14_bg1.gfx.inc"
};

const struct SpriteDataRom sCrateria_14_Spriteset0[11] = {
    { .y = 2, .x = 17, .id = SPRITESET_IDX(2) },
    { .y = 2, .x = 21, .id = SPRITESET_IDX(2) },
    { .y = 3, .x = 12, .id = SPRITESET_IDX(2) },
    { .y = 3, .x = 24, .id = SPRITESET_IDX(2) },
    { .y = 4, .x = 6, .id = SPRITESET_IDX(2) },
    { .y = 6, .x = 15, .id = SPRITESET_IDX(1) },
    { .y = 7, .x = 17, .id = SPRITESET_IDX(1) },
    { .y = 8, .x = 19, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 7, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 28, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

