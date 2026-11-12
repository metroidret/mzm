#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_52_Clipdata[147] = {
    #include "extracted/data/rooms/norfair/norfair_52_clipdata.gfx.inc"
};

const u8 sNorfair_52_Bg2[1329] = {
    #include "extracted/data/rooms/norfair/norfair_52_bg2.gfx.inc"
};

const u8 sNorfair_52_Bg1[516] = {
    #include "extracted/data/rooms/norfair/norfair_52_bg1.gfx.inc"
};

const struct SpriteDataRom sNorfair_52_Spriteset0[2] = {
    { .y = 9, .x = 7, .id = SPRITESET_IDX(3) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_52_Bg0[694] = {
    #include "extracted/data/rooms/norfair/norfair_52_bg0.gfx.inc"
};

