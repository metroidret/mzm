#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_25_Clipdata[92] = {
    #include "extracted/data/rooms/ridley/ridley_25_clipdata.gfx.inc"
};

const u8 sRidley_25_Bg1[166] = {
    #include "extracted/data/rooms/ridley/ridley_25_bg1.gfx.inc"
};

const struct SpriteSpawn sRidley_25_SpriteLayer0[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

