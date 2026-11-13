#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_27_Clipdata[520] = {
    #include "extracted/data/rooms/kraid/kraid_27_clipdata.gfx.inc"
};

const u8 sKraid_27_Bg2[258] = {
    #include "extracted/data/rooms/kraid/kraid_27_bg2.gfx.inc"
};

const struct SpriteSpawn sKraid_27_Spriteset1[11] = {
    { .y = 25, .x = 11, .id = SPRITESET_IDX(4) },
    { .y = 28, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 31, .x = 4, .id = SPRITESET_IDX(1) },
    { .y = 36, .x = 10, .id = SPRITESET_IDX(4) },
    { .y = 40, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 43, .x = 4, .id = SPRITESET_IDX(1) },
    { .y = 45, .x = 11, .id = SPRITESET_IDX(4) },
    { .y = 58, .x = 14, .id = SPRITESET_IDX(4) },
    { .y = 59, .x = 9, .id = SPRITESET_IDX(4) },
    { .y = 60, .x = 8, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_27_Bg1[879] = {
    #include "extracted/data/rooms/kraid/kraid_27_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_27_Spriteset0[8] = {
    { .y = 25, .x = 11, .id = SPRITESET_IDX(0) },
    { .y = 31, .x = 4, .id = SPRITESET_IDX(1) },
    { .y = 40, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 43, .x = 4, .id = SPRITESET_IDX(1) },
    { .y = 58, .x = 14, .id = SPRITESET_IDX(0) },
    { .y = 59, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 60, .x = 8, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

