#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_7_Clipdata[76] = {
    #include "extracted/data/rooms/ridley/ridley_7_clipdata.gfx.inc"
};

const u8 sRidley_7_Bg2[68] = {
    #include "extracted/data/rooms/ridley/ridley_7_bg2.gfx.inc"
};

const struct SpriteDataRom sRidley_7_Spriteset1[6] = {
    { .y = 2, .x = 10, .id = SPRITESET_IDX(2) },
    { .y = 2, .x = 15, .id = SPRITESET_IDX(2) },
    { .y = 2, .x = 18, .id = SPRITESET_IDX(2) },
    { .y = 2, .x = 23, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 16, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_7_Bg1[206] = {
    #include "extracted/data/rooms/ridley/ridley_7_bg1.gfx.inc"
};

const struct SpriteDataRom sRidley_7_Spriteset0[8] = {
    { .y = 2, .x = 10, .id = SPRITESET_IDX(2) },
    { .y = 2, .x = 14, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 19, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 23, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 14, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 16, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 18, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_7_Bg0[464] = {
    #include "extracted/data/rooms/ridley/ridley_7_bg0.gfx.inc"
};

