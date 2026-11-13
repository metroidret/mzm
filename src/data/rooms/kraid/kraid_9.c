#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_9_Clipdata[83] = {
    #include "extracted/data/rooms/kraid/kraid_9_clipdata.gfx.inc"
};

const u8 sKraid_9_Bg2[143] = {
    #include "extracted/data/rooms/kraid/kraid_9_bg2.gfx.inc"
};

const u8 sKraid_9_Bg1[334] = {
    #include "extracted/data/rooms/kraid/kraid_9_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_9_Spriteset0[8] = {
    { .y = 3, .x = 24, .id = SPRITESET_IDX(1) },
    { .y = 4, .x = 22, .id = SPRITESET_IDX(2) },
    { .y = 4, .x = 60, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 37, .id = SPRITESET_IDX(0) },
    { .y = 8, .x = 43, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 40, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 46, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_9_Bg0[156] = {
    #include "extracted/data/rooms/kraid/kraid_9_bg0.gfx.inc"
};

