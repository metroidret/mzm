#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_11_Clipdata[76] = {
    #include "extracted/data/rooms/kraid/kraid_11_clipdata.gfx.inc"
};

const u8 sKraid_11_Bg2[92] = {
    #include "extracted/data/rooms/kraid/kraid_11_bg2.gfx.inc"
};

const u8 sKraid_11_Bg1[286] = {
    #include "extracted/data/rooms/kraid/kraid_11_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_11_SpriteLayer0[7] = {
    { .y = 3, .x = 24, .id = SPRITESET_IDX(0) },
    { .y = 4, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 4, .x = 13, .id = SPRITESET_IDX(0) },
    { .y = 10, .x = 8, .id = SPRITESET_IDX(0) },
    { .y = 10, .x = 13, .id = SPRITESET_IDX(0) },
    { .y = 11, .x = 23, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

