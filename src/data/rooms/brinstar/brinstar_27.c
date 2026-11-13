#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_27_Clipdata[52] = {
    #include "extracted/data/rooms/brinstar/brinstar_27_clipdata.gfx.inc"
};

const u8 sBrinstar_27_Bg2[156] = {
    #include "extracted/data/rooms/brinstar/brinstar_27_bg2.gfx.inc"
};

const u8 sBrinstar_27_Bg1[141] = {
    #include "extracted/data/rooms/brinstar/brinstar_27_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_27_Spriteset0[2] = {
    { .y = 7, .x = 6, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

