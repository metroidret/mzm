#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_13_Clipdata[284] = {
    #include "extracted/data/rooms/kraid/kraid_13_clipdata.gfx.inc"
};

const u8 sKraid_13_Bg2[308] = {
    #include "extracted/data/rooms/kraid/kraid_13_bg2.gfx.inc"
};

const struct SpriteSpawn sKraid_13_Spriteset1[16] = {
    { .y = 4, .x = 6, .id = SPRITESET_IDX(4) },
    { .y = 11, .x = 8, .id = SPRITESET_IDX(1) },
    { .y = 11, .x = 10, .id = SPRITESET_IDX(4) },
    { .y = 13, .x = 8, .id = SPRITESET_IDX(4) },
    { .y = 13, .x = 10, .id = SPRITESET_IDX(1) },
    { .y = 15, .x = 8, .id = SPRITESET_IDX(1) },
    { .y = 17, .x = 10, .id = SPRITESET_IDX(1) },
    { .y = 18, .x = 8, .id = SPRITESET_IDX(4) },
    { .y = 19, .x = 8, .id = SPRITESET_IDX(1) },
    { .y = 20, .x = 10, .id = SPRITESET_IDX(4) },
    { .y = 22, .x = 6, .id = SPRITESET_IDX(1) },
    { .y = 22, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 24, .x = 9, .id = SPRITESET_IDX(1) },
    { .y = 26, .x = 9, .id = SPRITESET_IDX(4) },
    { .y = 29, .x = 9, .id = SPRITESET_IDX(3) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_13_Bg1[562] = {
    #include "extracted/data/rooms/kraid/kraid_13_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_13_Spriteset0[16] = {
    { .y = 4, .x = 6, .id = SPRITESET_IDX(0) },
    { .y = 11, .x = 8, .id = SPRITESET_IDX(1) },
    { .y = 11, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 13, .x = 8, .id = SPRITESET_IDX(0) },
    { .y = 13, .x = 10, .id = SPRITESET_IDX(1) },
    { .y = 15, .x = 8, .id = SPRITESET_IDX(1) },
    { .y = 17, .x = 10, .id = SPRITESET_IDX(1) },
    { .y = 18, .x = 8, .id = SPRITESET_IDX(0) },
    { .y = 19, .x = 8, .id = SPRITESET_IDX(1) },
    { .y = 20, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 22, .x = 6, .id = SPRITESET_IDX(1) },
    { .y = 22, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 24, .x = 9, .id = SPRITESET_IDX(1) },
    { .y = 26, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 29, .x = 9, .id = SPRITESET_IDX(3) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_13_Bg0[42] = {
    #include "extracted/data/rooms/kraid/kraid_13_bg0.gfx.inc"
};

