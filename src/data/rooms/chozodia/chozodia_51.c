#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_51_Clipdata[449] = {
    #include "extracted/data/rooms/chozodia/chozodia_51_clipdata.gfx.inc"
};

const u8 sChozodia_51_Bg2[1632] = {
    #include "extracted/data/rooms/chozodia/chozodia_51_bg2.gfx.inc"
};

const struct SpriteDataRom sChozodia_51_Spriteset1[8] = {
    { .y = 7, .x = 21, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 41, .id = SPRITESET_IDX(3) },
    { .y = 12, .x = 9, .id = SPRITESET_IDX(3) },
    { .y = 20, .x = 46, .id = SPRITESET_IDX(1) },
    { .y = 25, .x = 23, .id = SPRITESET_IDX(3) },
    { .y = 30, .x = 12, .id = SPRITESET_IDX(0) },
    { .y = 30, .x = 23, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_51_Bg1[999] = {
    #include "extracted/data/rooms/chozodia/chozodia_51_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_51_Spriteset0[7] = {
    { .y = 7, .x = 21, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 41, .id = SPRITESET_IDX(3) },
    { .y = 18, .x = 2, .id = SPRITESET_IDX(1) },
    { .y = 20, .x = 46, .id = SPRITESET_IDX(1) },
    { .y = 30, .x = 15, .id = SPRITESET_IDX(3) },
    { .y = 30, .x = 27, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

