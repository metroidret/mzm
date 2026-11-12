#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_1_Clipdata[92] = {
    #include "extracted/data/rooms/ridley/ridley_1_clipdata.gfx.inc"
};

const u8 sRidley_1_Bg1[166] = {
    #include "extracted/data/rooms/ridley/ridley_1_bg1.gfx.inc"
};

const struct SpriteDataRom sRidley_1_Spriteset0[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

