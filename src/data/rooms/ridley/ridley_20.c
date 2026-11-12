#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_20_Clipdata[92] = {
    #include "extracted/data/rooms/ridley/ridley_20_clipdata.gfx.inc"
};

const u8 sRidley_20_Bg1[166] = {
    #include "extracted/data/rooms/ridley/ridley_20_bg1.gfx.inc"
};

const struct SpriteDataRom sRidley_20_Spriteset0[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

