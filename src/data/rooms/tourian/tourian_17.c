#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_17_Clipdata[80] = {
    #include "extracted/data/rooms/tourian/tourian_17_clipdata.gfx.inc"
};

const u8 sTourian_17_Bg1[162] = {
    #include "extracted/data/rooms/tourian/tourian_17_bg1.gfx.inc"
};

const struct SpriteSpawn sTourian_17_Spriteset0[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

