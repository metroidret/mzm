#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_24_Clipdata[85] = {
    #include "extracted/data/rooms/ridley/ridley_24_clipdata.gfx.inc"
};

const u8 sRidley_24_Bg1[162] = {
    #include "extracted/data/rooms/ridley/ridley_24_bg1.gfx.inc"
};

const struct SpriteSpawn sRidley_24_SpriteLayer0[2] = {
    { .y = 10, .x = 8, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

