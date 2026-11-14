#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_2_Clipdata[273] = {
    #include "extracted/data/rooms/ridley/ridley_2_clipdata.gfx.inc"
};

const u8 sRidley_2_Bg2[229] = {
    #include "extracted/data/rooms/ridley/ridley_2_bg2.gfx.inc"
};

const u8 sRidley_2_Bg1[666] = {
    #include "extracted/data/rooms/ridley/ridley_2_bg1.gfx.inc"
};

const struct SpriteSpawn sRidley_2_SpriteLayer0[4] = {
    { .y = 22, .x = 6, .id = SPRITESET_IDX(0) },
    { .y = 23, .x = 5, .id = SPRITESET_IDX(1) },
    { .y = 24, .x = 6, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sRidley_2_Bg0[116] = {
    #include "extracted/data/rooms/ridley/ridley_2_bg0.gfx.inc"
};

