#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_3_Clipdata[138] = {
    #include "extracted/data/rooms/kraid/kraid_3_clipdata.gfx.inc"
};

const u8 sKraid_3_Bg2[72] = {
    #include "extracted/data/rooms/kraid/kraid_3_bg2.gfx.inc"
};

const struct SpriteDataRom sKraid_3_Spriteset1[4] = {
    { .y = 2, .x = 34, .id = SPRITESET_IDX(1) },
    { .y = 3, .x = 5, .id = SPRITESET_IDX(2) },
    { .y = 13, .x = 26, .id = SPRITESET_IDX(4) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_3_Bg1[410] = {
    #include "extracted/data/rooms/kraid/kraid_3_bg1.gfx.inc"
};

const struct SpriteDataRom sKraid_3_Spriteset0[5] = {
    { .y = 2, .x = 34, .id = SPRITESET_IDX(1) },
    { .y = 3, .x = 5, .id = SPRITESET_IDX(2) },
    { .y = 12, .x = 26, .id = SPRITESET_IDX(4) },
    { .y = 12, .x = 38, .id = SPRITESET_IDX(4) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_3_Bg0[89] = {
    #include "extracted/data/rooms/kraid/kraid_3_bg0.gfx.inc"
};

