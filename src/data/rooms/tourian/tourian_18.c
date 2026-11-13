#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_18_Clipdata[113] = {
    #include "extracted/data/rooms/tourian/tourian_18_clipdata.gfx.inc"
};

const u8 sTourian_18_Bg2[14] = {
    #include "extracted/data/rooms/tourian/tourian_18_bg2.gfx.inc"
};

const u8 sTourian_18_Bg1[270] = {
    #include "extracted/data/rooms/tourian/tourian_18_bg1.gfx.inc"
};

const struct SpriteSpawn sTourian_18_SpriteLayer0[3] = {
    { .y = 2, .x = 9, .id = SPRITESET_IDX(1) },
    { .y = 15, .x = 2, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

