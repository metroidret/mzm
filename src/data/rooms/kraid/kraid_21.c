#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_21_Clipdata[360] = {
    #include "extracted/data/rooms/kraid/kraid_21_clipdata.gfx.inc"
};

const u8 sKraid_21_Bg1[521] = {
    #include "extracted/data/rooms/kraid/kraid_21_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_21_SpriteLayer0[16] = {
    { .y = 2, .x = 17, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 68, .id = SPRITESET_IDX(1) },
    { .y = 4, .x = 37, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 41, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 46, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 54, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 63, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 70, .id = SPRITESET_IDX(3) },
    { .y = 9, .x = 43, .id = SPRITESET_IDX(4) },
    { .y = 9, .x = 51, .id = SPRITESET_IDX(4) },
    { .y = 9, .x = 59, .id = SPRITESET_IDX(4) },
    { .y = 9, .x = 67, .id = SPRITESET_IDX(4) },
    { .y = 10, .x = 28, .id = SPRITESET_IDX(2) },
    { .y = 10, .x = 33, .id = SPRITESET_IDX(2) },
    { .y = 10, .x = 37, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_21_Bg0[119] = {
    #include "extracted/data/rooms/kraid/kraid_21_bg0.gfx.inc"
};

