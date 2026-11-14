#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_13_Clipdata[100] = {
    #include "extracted/data/rooms/tourian/tourian_13_clipdata.gfx.inc"
};

const u8 sTourian_13_Bg2[52] = {
    #include "extracted/data/rooms/tourian/tourian_13_bg2.gfx.inc"
};

const struct SpriteSpawn sTourian_13_SpriteLayer1[4] = {
    { .y = 2, .x = 10, .id = SPRITESET_IDX(1) },
    { .y = 12, .x = 15, .id = SPRITESET_IDX(1) },
    { .y = 19, .x = 7, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sTourian_13_Bg1[280] = {
    #include "extracted/data/rooms/tourian/tourian_13_bg1.gfx.inc"
};

const struct SpriteSpawn sTourian_13_SpriteLayer0[2] = {
    { .y = 12, .x = 15, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

