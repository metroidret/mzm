#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_18_Clipdata[111] = {
    #include "extracted/data/rooms/kraid/kraid_18_clipdata.gfx.inc"
};

const u8 sKraid_18_Bg2[137] = {
    #include "extracted/data/rooms/kraid/kraid_18_bg2.gfx.inc"
};

const struct SpriteDataRom sKraid_18_Spriteset1[4] = {
    { .y = 15, .x = 13, .id = SPRITESET_IDX(4) },
    { .y = 16, .x = 10, .id = SPRITESET_IDX(4) },
    { .y = 21, .x = 11, .id = SPRITESET_IDX(5) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_18_Bg1[333] = {
    #include "extracted/data/rooms/kraid/kraid_18_bg1.gfx.inc"
};

const struct SpriteDataRom sKraid_18_Spriteset0[3] = {
    { .y = 16, .x = 10, .id = SPRITESET_IDX(4) },
    { .y = 21, .x = 11, .id = SPRITESET_IDX(5) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_18_Bg0[30] = {
    #include "extracted/data/rooms/kraid/kraid_18_bg0.gfx.inc"
};

