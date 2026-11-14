#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_59_Clipdata[374] = {
    #include "extracted/data/rooms/chozodia/chozodia_59_clipdata.gfx.inc"
};

const struct SpriteSpawn sChozodia_59_SpriteLayer1[6] = {
    { .y = 6, .x = 11, .id = SPRITESET_IDX(3) },
    { .y = 15, .x = 13, .id = SPRITESET_IDX(3) },
    { .y = 21, .x = 12, .id = SPRITESET_IDX(0) },
    { .y = 34, .x = 5, .id = SPRITESET_IDX(0) },
    { .y = 40, .x = 2, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_59_Bg1[793] = {
    #include "extracted/data/rooms/chozodia/chozodia_59_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_59_SpriteLayer0[7] = {
    { .y = 6, .x = 11, .id = SPRITESET_IDX(3) },
    { .y = 15, .x = 13, .id = SPRITESET_IDX(3) },
    { .y = 21, .x = 12, .id = SPRITESET_IDX(0) },
    { .y = 34, .x = 5, .id = SPRITESET_IDX(0) },
    { .y = 34, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 40, .x = 13, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

