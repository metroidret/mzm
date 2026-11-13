#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_3_Clipdata[154] = {
    #include "extracted/data/rooms/ridley/ridley_3_clipdata.gfx.inc"
};

const struct SpriteDataRom sRidley_3_Spriteset2[11] = {
    { .y = 2, .x = 18, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 31, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 47, .id = SPRITESET_IDX(3) },
    { .y = 6, .x = 29, .id = SPRITESET_IDX(0) },
    { .y = 6, .x = 43, .id = SPRITESET_IDX(0) },
    { .y = 6, .x = 56, .id = SPRITESET_IDX(0) },
    { .y = 7, .x = 19, .id = SPRITESET_IDX(0) },
    { .y = 8, .x = 13, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 34, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 60, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_3_Bg2[228] = {
    #include "extracted/data/rooms/ridley/ridley_3_bg2.gfx.inc"
};

const struct SpriteDataRom sRidley_3_Spriteset1[12] = {
    { .y = 2, .x = 18, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 39, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 44, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 61, .id = SPRITESET_IDX(3) },
    { .y = 6, .x = 29, .id = SPRITESET_IDX(1) },
    { .y = 6, .x = 43, .id = SPRITESET_IDX(1) },
    { .y = 6, .x = 56, .id = SPRITESET_IDX(0) },
    { .y = 8, .x = 13, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 23, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 34, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 48, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_3_Bg1[530] = {
    #include "extracted/data/rooms/ridley/ridley_3_bg1.gfx.inc"
};

const struct SpriteDataRom sRidley_3_Spriteset0[12] = {
    { .y = 2, .x = 18, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 39, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 44, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 61, .id = SPRITESET_IDX(3) },
    { .y = 6, .x = 29, .id = SPRITESET_IDX(0) },
    { .y = 6, .x = 43, .id = SPRITESET_IDX(0) },
    { .y = 6, .x = 56, .id = SPRITESET_IDX(1) },
    { .y = 8, .x = 13, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 23, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 34, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 48, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_3_Bg0[263] = {
    #include "extracted/data/rooms/ridley/ridley_3_bg0.gfx.inc"
};

