#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_58_Clipdata[138] = {
    #include "extracted/data/rooms/chozodia/chozodia_58_clipdata.gfx.inc"
};

const u8 sChozodia_58_Bg2[428] = {
    #include "extracted/data/rooms/chozodia/chozodia_58_bg2.gfx.inc"
};

const u8 sChozodia_58_Bg1[320] = {
    #include "extracted/data/rooms/chozodia/chozodia_58_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_58_Spriteset0[6] = {
    { .y = 4, .x = 10, .id = SPRITESET_IDX(4) },
    { .y = 4, .x = 23, .id = SPRITESET_IDX(4) },
    { .y = 5, .x = 17, .id = SPRITESET_IDX(4) },
    { .y = 6, .x = 2, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 31, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_58_Bg0[88] = {
    #include "extracted/data/rooms/chozodia/chozodia_58_bg0.gfx.inc"
};

