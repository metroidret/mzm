#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_11_Clipdata[91] = {
    #include "extracted/data/rooms/tourian/tourian_11_clipdata.gfx.inc"
};

const u8 sTourian_11_Bg1[167] = {
    #include "extracted/data/rooms/tourian/tourian_11_bg1.gfx.inc"
};

const struct SpriteSpawn sTourian_11_SpriteLayer0[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

