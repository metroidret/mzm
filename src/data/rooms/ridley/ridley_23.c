#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_23_Clipdata[186] = {
    #include "extracted/data/rooms/ridley/ridley_23_clipdata.gfx.inc"
};

const u8 sRidley_23_Bg2[14] = {
    #include "extracted/data/rooms/ridley/ridley_23_bg2.gfx.inc"
};

const u8 sRidley_23_Bg1[488] = {
    #include "extracted/data/rooms/ridley/ridley_23_bg1.gfx.inc"
};

const struct SpriteSpawn sRidley_23_Spriteset0[2] = {
    { .y = 19, .x = 14, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

