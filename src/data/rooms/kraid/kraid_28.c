#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_28_Clipdata[306] = {
    #include "extracted/data/rooms/kraid/kraid_28_clipdata.gfx.inc"
};

const u8 sKraid_28_Bg2[73] = {
    #include "extracted/data/rooms/kraid/kraid_28_bg2.gfx.inc"
};

const u8 sKraid_28_Bg1[838] = {
    #include "extracted/data/rooms/kraid/kraid_28_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_28_Spriteset0[15] = {
    { .y = 4, .x = 27, .id = SPRITESET_IDX(4) },
    { .y = 4, .x = 31, .id = SPRITESET_IDX(4) },
    { .y = 5, .x = 19, .id = SPRITESET_IDX(4) },
    { .y = 6, .x = 37, .id = SPRITESET_IDX(4) },
    { .y = 6, .x = 50, .id = SPRITESET_IDX(4) },
    { .y = 9, .x = 9, .id = SPRITESET_IDX(3) },
    { .y = 9, .x = 12, .id = SPRITESET_IDX(3) },
    { .y = 9, .x = 19, .id = SPRITESET_IDX(4) },
    { .y = 10, .x = 31, .id = SPRITESET_IDX(4) },
    { .y = 10, .x = 34, .id = SPRITESET_IDX(4) },
    { .y = 13, .x = 16, .id = SPRITESET_IDX(4) },
    { .y = 13, .x = 19, .id = SPRITESET_IDX(4) },
    { .y = 14, .x = 25, .id = SPRITESET_IDX(4) },
    { .y = 14, .x = 29, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_28_Bg0[62] = {
    #include "extracted/data/rooms/kraid/kraid_28_bg0.gfx.inc"
};

