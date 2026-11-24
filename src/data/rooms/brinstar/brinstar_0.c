#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const struct ScrollArray(3) sBrinstar_0_Scrolls = {
    .room = 0,
    .scrolls_len = 3,
    .scrolls = {
        {
            .x_bounds = { 2, 76 },
            .y_bounds = { 22, 31 },
            .extension = SCROLL_EXTENSION_NONE,
        },
        {
            .x_bounds = { 32, 46 },
            .y_bounds = { 2, 23 },
            .extension = SCROLL_EXTENSION_NONE,
        },
        {
            .x_bounds = { 32, 46 },
            .y_bounds = { 31, 41 },
            .extension = SCROLL_EXTENSION_NONE,
        }
    }
};

const u8 sBrinstar_0_Clipdata[311] = {
    #include "extracted/data/rooms/brinstar/brinstar_0_clipdata.gfx.inc"
};

const u8 sBrinstar_0_Bg2[124] = {
    #include "extracted/data/rooms/brinstar/brinstar_0_bg2.gfx.inc"
};

const struct SpriteSpawn sBrinstar_0_SpriteLayer1[9] = {
    { .y = 22, .x = 27, .id = SPRITESET_IDX(4) },
    { .y = 22, .x = 56, .id = SPRITESET_IDX(4) },
    { .y = 23, .x = 68, .id = SPRITESET_IDX(4) },
    { .y = 24, .x = 4, .id = SPRITESET_IDX(4) },
    { .y = 27, .x = 11, .id = SPRITESET_IDX(1) },
    { .y = 30, .x = 21, .id = SPRITESET_IDX(4) },
    { .y = 30, .x = 67, .id = SPRITESET_IDX(4) },
    { .y = 34, .x = 39, .id = SPRITESET_IDX(3) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_0_Bg1[1328] = {
    #include "extracted/data/rooms/brinstar/brinstar_0_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_0_SpriteLayer0[9] = {
    { .y = 22, .x = 27, .id = SPRITESET_IDX(0) },
    { .y = 22, .x = 56, .id = SPRITESET_IDX(0) },
    { .y = 23, .x = 68, .id = SPRITESET_IDX(0) },
    { .y = 24, .x = 4, .id = SPRITESET_IDX(0) },
    { .y = 27, .x = 11, .id = SPRITESET_IDX(1) },
    { .y = 30, .x = 21, .id = SPRITESET_IDX(0) },
    { .y = 30, .x = 67, .id = SPRITESET_IDX(0) },
    { .y = 34, .x = 39, .id = SPRITESET_IDX(3) },
    SPRITE_SPAWN_TERMINATOR
};

