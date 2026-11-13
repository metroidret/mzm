#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_38_Clipdata[83] = {
    #include "extracted/data/rooms/kraid/kraid_38_clipdata.gfx.inc"
};

const u8 sKraid_38_Bg2[14] = {
    #include "extracted/data/rooms/kraid/kraid_38_bg2.gfx.inc"
};

const struct SpriteSpawn sKraid_38_Spriteset1[5] = {
    { .y = 5, .x = 4, .id = SPRITESET_IDX(4) },
    { .y = 6, .x = 6, .id = SPRITESET_IDX(4) },
    { .y = 8, .x = 4, .id = SPRITESET_IDX(4) },
    { .y = 10, .x = 5, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_38_Bg1[185] = {
    #include "extracted/data/rooms/kraid/kraid_38_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_38_Spriteset0[4] = {
    { .y = 6, .x = 6, .id = SPRITESET_IDX(0) },
    { .y = 8, .x = 4, .id = SPRITESET_IDX(0) },
    { .y = 10, .x = 5, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_38_Bg0[59] = {
    #include "extracted/data/rooms/kraid/kraid_38_bg0.gfx.inc"
};

