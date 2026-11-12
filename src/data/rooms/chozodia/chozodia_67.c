#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_67_Clipdata[215] = {
    #include "extracted/data/rooms/chozodia/chozodia_67_clipdata.gfx.inc"
};

const u8 sChozodia_67_Bg2[868] = {
    #include "extracted/data/rooms/chozodia/chozodia_67_bg2.gfx.inc"
};

const u8 sChozodia_67_Bg1[902] = {
    #include "extracted/data/rooms/chozodia/chozodia_67_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_67_Spriteset0[7] = {
    { .y = 5, .x = 21, .id = SPRITESET_IDX(0) },
    { .y = 10, .x = 15, .id = SPRITESET_IDX(3) },
    { .y = 15, .x = 15, .id = SPRITESET_IDX(3) },
    { .y = 20, .x = 15, .id = SPRITESET_IDX(3) },
    { .y = 39, .x = 26, .id = SPRITESET_IDX(0) },
    { .y = 40, .x = 18, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_67_Bg0[334] = {
    #include "extracted/data/rooms/chozodia/chozodia_67_bg0.gfx.inc"
};

