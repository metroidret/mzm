#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_4_Clipdata[119] = {
    #include "extracted/data/rooms/kraid/kraid_4_clipdata.gfx.inc"
};

const u8 sKraid_4_Bg2[36] = {
    #include "extracted/data/rooms/kraid/kraid_4_bg2.gfx.inc"
};

const u8 sKraid_4_Bg1[253] = {
    #include "extracted/data/rooms/kraid/kraid_4_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_4_SpriteLayer0[6] = {
    { .y = 3, .x = 27, .id = SPRITESET_IDX(1) },
    { .y = 4, .x = 11, .id = SPRITESET_IDX(2) },
    { .y = 4, .x = 29, .id = SPRITESET_IDX(2) },
    { .y = 9, .x = 11, .id = SPRITESET_IDX(3) },
    { .y = 12, .x = 25, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_4_Bg0[62] = {
    #include "extracted/data/rooms/kraid/kraid_4_bg0.gfx.inc"
};

