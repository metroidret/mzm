#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_16_Clipdata[302] = {
    #include "extracted/data/rooms/chozodia/chozodia_16_clipdata.gfx.inc"
};

const struct SpriteSpawn sChozodia_16_Spriteset2[10] = {
    { .y = 6, .x = 4, .id = SPRITESET_IDX(8) },
    { .y = 9, .x = 16, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 5, .id = SPRITESET_IDX(7) },
    { .y = 14, .x = 12, .id = SPRITESET_IDX(6) },
    { .y = 18, .x = 11, .id = SPRITESET_IDX(5) },
    { .y = 18, .x = 16, .id = SPRITESET_IDX(1) },
    { .y = 22, .x = 3, .id = SPRITESET_IDX(6) },
    { .y = 23, .x = 11, .id = SPRITESET_IDX(4) },
    { .y = 30, .x = 16, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_16_Bg2[214] = {
    #include "extracted/data/rooms/chozodia/chozodia_16_bg2.gfx.inc"
};

const struct SpriteSpawn sChozodia_16_Spriteset1[5] = {
    { .y = 6, .x = 4, .id = SPRITESET_IDX(8) },
    { .y = 10, .x = 12, .id = SPRITESET_IDX(5) },
    { .y = 18, .x = 16, .id = SPRITESET_IDX(1) },
    { .y = 23, .x = 11, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_16_Bg1[438] = {
    #include "extracted/data/rooms/chozodia/chozodia_16_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_16_Spriteset0[7] = {
    { .y = 6, .x = 4, .id = SPRITESET_IDX(8) },
    { .y = 10, .x = 5, .id = SPRITESET_IDX(7) },
    { .y = 14, .x = 12, .id = SPRITESET_IDX(6) },
    { .y = 18, .x = 11, .id = SPRITESET_IDX(5) },
    { .y = 18, .x = 16, .id = SPRITESET_IDX(1) },
    { .y = 23, .x = 11, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_16_Bg0[16] = {
    #include "extracted/data/rooms/chozodia/chozodia_16_bg0.gfx.inc"
};

