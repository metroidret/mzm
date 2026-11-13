#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_4_Clipdata[90] = {
    #include "extracted/data/rooms/chozodia/chozodia_4_clipdata.gfx.inc"
};

const u8 sChozodia_4_Bg2[26] = {
    #include "extracted/data/rooms/chozodia/chozodia_4_bg2.gfx.inc"
};

const struct SpriteDataRom sChozodia_4_Spriteset1[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_4_Bg1[204] = {
    #include "extracted/data/rooms/chozodia/chozodia_4_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_4_Spriteset0[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_4_Bg0[44] = {
    #include "extracted/data/rooms/chozodia/chozodia_4_bg0.gfx.inc"
};

