#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_14_Clipdata[68] = {
    #include "extracted/data/rooms/tourian/tourian_14_clipdata.gfx.inc"
};

const u8 sTourian_14_Bg2[52] = {
    #include "extracted/data/rooms/tourian/tourian_14_bg2.gfx.inc"
};

const struct SpriteSpawn sTourian_14_SpriteLayer1[6] = {
    { .y = 2, .x = 10, .id = SPRITESET_IDX(1) },
    { .y = 2, .x = 16, .id = SPRITESET_IDX(1) },
    { .y = 2, .x = 22, .id = SPRITESET_IDX(1) },
    { .y = 6, .x = 16, .id = SPRITESET_IDX(0) },
    { .y = 11, .x = 15, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sTourian_14_Bg1[173] = {
    #include "extracted/data/rooms/tourian/tourian_14_bg1.gfx.inc"
};

const struct SpriteSpawn sTourian_14_SpriteLayer0[4] = {
    { .y = 2, .x = 10, .id = SPRITESET_IDX(1) },
    { .y = 2, .x = 22, .id = SPRITESET_IDX(1) },
    { .y = 6, .x = 16, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

