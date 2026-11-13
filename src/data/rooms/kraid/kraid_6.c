#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_6_Clipdata[254] = {
    #include "extracted/data/rooms/kraid/kraid_6_clipdata.gfx.inc"
};

const u8 sKraid_6_Bg2[14] = {
    #include "extracted/data/rooms/kraid/kraid_6_bg2.gfx.inc"
};

const struct SpriteSpawn sKraid_6_SpriteLayer1[10] = {
    { .y = 14, .x = 12, .id = SPRITESET_IDX(4) },
    { .y = 15, .x = 10, .id = SPRITESET_IDX(4) },
    { .y = 16, .x = 13, .id = SPRITESET_IDX(4) },
    { .y = 17, .x = 11, .id = SPRITESET_IDX(4) },
    { .y = 23, .x = 12, .id = SPRITESET_IDX(4) },
    { .y = 24, .x = 10, .id = SPRITESET_IDX(4) },
    { .y = 25, .x = 13, .id = SPRITESET_IDX(4) },
    { .y = 26, .x = 11, .id = SPRITESET_IDX(4) },
    { .y = 28, .x = 4, .id = SPRITESET_IDX(3) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_6_Bg1[522] = {
    #include "extracted/data/rooms/kraid/kraid_6_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_6_SpriteLayer0[10] = {
    { .y = 14, .x = 12, .id = SPRITESET_IDX(0) },
    { .y = 15, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 16, .x = 13, .id = SPRITESET_IDX(0) },
    { .y = 17, .x = 11, .id = SPRITESET_IDX(0) },
    { .y = 23, .x = 12, .id = SPRITESET_IDX(0) },
    { .y = 24, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 25, .x = 13, .id = SPRITESET_IDX(0) },
    { .y = 26, .x = 11, .id = SPRITESET_IDX(0) },
    { .y = 28, .x = 4, .id = SPRITESET_IDX(3) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_6_Bg0[86] = {
    #include "extracted/data/rooms/kraid/kraid_6_bg0.gfx.inc"
};

