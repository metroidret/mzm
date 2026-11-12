#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_21_Clipdata[56] = {
    #include "extracted/data/rooms/ridley/ridley_21_clipdata.gfx.inc"
};

const u8 sRidley_21_Bg2[14] = {
    #include "extracted/data/rooms/ridley/ridley_21_bg2.gfx.inc"
};

const u8 sRidley_21_Bg1[177] = {
    #include "extracted/data/rooms/ridley/ridley_21_bg1.gfx.inc"
};

const struct SpriteDataRom sRidley_21_Spriteset0[2] = {
    { .y = 4, .x = 8, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

