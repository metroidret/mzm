#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_2_Clipdata[242] = {
    #include "extracted/data/rooms/tourian/tourian_2_clipdata.gfx.inc"
};

const u8 sTourian_2_Bg2[114] = {
    #include "extracted/data/rooms/tourian/tourian_2_bg2.gfx.inc"
};

const struct SpriteSpawn sTourian_2_Spriteset1[13] = {
    { .y = 5, .x = 16, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 20, .x = 16, .id = SPRITESET_IDX(1) },
    { .y = 29, .x = 14, .id = SPRITESET_IDX(0) },
    { .y = 31, .x = 12, .id = SPRITESET_IDX(0) },
    { .y = 34, .x = 16, .id = SPRITESET_IDX(1) },
    { .y = 39, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 41, .x = 3, .id = SPRITESET_IDX(1) },
    { .y = 43, .x = 14, .id = SPRITESET_IDX(0) },
    { .y = 44, .x = 16, .id = SPRITESET_IDX(1) },
    { .y = 45, .x = 5, .id = SPRITESET_IDX(0) },
    { .y = 47, .x = 10, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sTourian_2_Bg1[618] = {
    #include "extracted/data/rooms/tourian/tourian_2_bg1.gfx.inc"
};

const struct SpriteSpawn sTourian_2_Spriteset0[12] = {
    { .y = 5, .x = 16, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 20, .x = 16, .id = SPRITESET_IDX(1) },
    { .y = 21, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 26, .x = 12, .id = SPRITESET_IDX(0) },
    { .y = 31, .x = 8, .id = SPRITESET_IDX(0) },
    { .y = 34, .x = 16, .id = SPRITESET_IDX(1) },
    { .y = 37, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 41, .x = 3, .id = SPRITESET_IDX(1) },
    { .y = 44, .x = 16, .id = SPRITESET_IDX(1) },
    { .y = 47, .x = 10, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

