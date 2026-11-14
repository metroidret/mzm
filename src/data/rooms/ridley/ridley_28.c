#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_28_Clipdata[250] = {
    #include "extracted/data/rooms/ridley/ridley_28_clipdata.gfx.inc"
};

const u8 sRidley_28_Bg2[157] = {
    #include "extracted/data/rooms/ridley/ridley_28_bg2.gfx.inc"
};

const u8 sRidley_28_Bg1[626] = {
    #include "extracted/data/rooms/ridley/ridley_28_bg1.gfx.inc"
};

const struct SpriteSpawn sRidley_28_SpriteLayer0[5] = {
    { .y = 15, .x = 8, .id = SPRITESET_IDX(2) },
    { .y = 22, .x = 6, .id = SPRITESET_IDX(0) },
    { .y = 23, .x = 5, .id = SPRITESET_IDX(1) },
    { .y = 24, .x = 6, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sRidley_28_Bg0[116] = {
    #include "extracted/data/rooms/ridley/ridley_28_bg0.gfx.inc"
};

