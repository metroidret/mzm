#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_37_Clipdata[147] = {
    #include "extracted/data/rooms/chozodia/chozodia_37_clipdata.gfx.inc"
};

const u8 sChozodia_37_Bg2[208] = {
    #include "extracted/data/rooms/chozodia/chozodia_37_bg2.gfx.inc"
};

const struct SpriteDataRom sChozodia_37_Spriteset1[3] = {
    { .y = 8, .x = 2, .id = SPRITESET_IDX(1) },
    { .y = 8, .x = 20, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_37_Bg1[462] = {
    #include "extracted/data/rooms/chozodia/chozodia_37_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_37_Spriteset0[1] = {
    ROOM_SPRITE_DATA_TERMINATOR
};

