#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_12_Clipdata[117] = {
    #include "extracted/data/rooms/kraid/kraid_12_clipdata.gfx.inc"
};

const u8 sKraid_12_Bg2[73] = {
    #include "extracted/data/rooms/kraid/kraid_12_bg2.gfx.inc"
};

const struct SpriteSpawn sKraid_12_Spriteset1[13] = {
    { .y = 3, .x = 86, .id = SPRITESET_IDX(1) },
    { .y = 7, .x = 20, .id = SPRITESET_IDX(6) },
    { .y = 9, .x = 65, .id = SPRITESET_IDX(5) },
    { .y = 9, .x = 69, .id = SPRITESET_IDX(5) },
    { .y = 9, .x = 73, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 64, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 66, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 68, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 70, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 72, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 74, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 76, .id = SPRITESET_IDX(5) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_12_Bg1[345] = {
    #include "extracted/data/rooms/kraid/kraid_12_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_12_Spriteset0[7] = {
    { .y = 3, .x = 86, .id = SPRITESET_IDX(1) },
    { .y = 5, .x = 24, .id = SPRITESET_IDX(5) },
    { .y = 6, .x = 25, .id = SPRITESET_IDX(5) },
    { .y = 7, .x = 20, .id = SPRITESET_IDX(6) },
    { .y = 7, .x = 23, .id = SPRITESET_IDX(5) },
    { .y = 8, .x = 24, .id = SPRITESET_IDX(5) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_12_Bg0[205] = {
    #include "extracted/data/rooms/kraid/kraid_12_bg0.gfx.inc"
};

