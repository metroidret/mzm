#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_8_Clipdata[62] = {
    #include "extracted/data/rooms/ridley/ridley_8_clipdata.gfx.inc"
};

const u8 sRidley_8_Bg2[118] = {
    #include "extracted/data/rooms/ridley/ridley_8_bg2.gfx.inc"
};

const struct SpriteDataRom sRidley_8_Spriteset1[5] = {
    { .y = 3, .x = 10, .id = SPRITESET_IDX(2) },
    { .y = 3, .x = 17, .id = SPRITESET_IDX(2) },
    { .y = 3, .x = 23, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 17, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_8_Bg1[224] = {
    #include "extracted/data/rooms/ridley/ridley_8_bg1.gfx.inc"
};

const struct SpriteDataRom sRidley_8_Spriteset0[6] = {
    { .y = 3, .x = 14, .id = SPRITESET_IDX(2) },
    { .y = 3, .x = 19, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 14, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 17, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 20, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_8_Bg0[127] = {
    #include "extracted/data/rooms/ridley/ridley_8_bg0.gfx.inc"
};

