#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_41_Clipdata[93] = {
    #include "extracted/data/rooms/norfair/norfair_41_clipdata.gfx.inc"
};

const u8 sNorfair_41_Bg1[165] = {
    #include "extracted/data/rooms/norfair/norfair_41_bg1.gfx.inc"
};

const struct SpriteDataRom sNorfair_41_Spriteset0[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

