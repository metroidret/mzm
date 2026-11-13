#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_6_Clipdata[93] = {
    #include "extracted/data/rooms/tourian/tourian_6_clipdata.gfx.inc"
};

const u8 sTourian_6_Bg1[166] = {
    #include "extracted/data/rooms/tourian/tourian_6_bg1.gfx.inc"
};

const struct SpriteSpawn sTourian_6_Spriteset0[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

