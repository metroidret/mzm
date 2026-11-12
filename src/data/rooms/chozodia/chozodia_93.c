#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_93_Clipdata[414] = {
    #include "extracted/data/rooms/chozodia/chozodia_93_clipdata.gfx.inc"
};

const u8 sChozodia_93_Bg2[1335] = {
    #include "extracted/data/rooms/chozodia/chozodia_93_bg2.gfx.inc"
};

const u8 sChozodia_93_Bg1[979] = {
    #include "extracted/data/rooms/chozodia/chozodia_93_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_93_Spriteset0[6] = {
    { .y = 16, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 41, .x = 4, .id = SPRITESET_IDX(3) },
    { .y = 51, .x = 14, .id = SPRITESET_IDX(3) },
    { .y = 58, .x = 5, .id = SPRITESET_IDX(3) },
    { .y = 78, .x = 13, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_93_Bg0[122] = {
    #include "extracted/data/rooms/chozodia/chozodia_93_bg0.gfx.inc"
};

