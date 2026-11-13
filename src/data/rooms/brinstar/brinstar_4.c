#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_4_Clipdata[142] = {
    #include "extracted/data/rooms/brinstar/brinstar_4_clipdata.gfx.inc"
};

const u8 sBrinstar_4_Bg2[128] = {
    #include "extracted/data/rooms/brinstar/brinstar_4_bg2.gfx.inc"
};

const u8 sBrinstar_4_Bg1[544] = {
    #include "extracted/data/rooms/brinstar/brinstar_4_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_4_Spriteset0[4] = {
    { .y = 3, .x = 9, .id = SPRITESET_IDX(2) },
    { .y = 3, .x = 12, .id = SPRITESET_IDX(2) },
    { .y = 3, .x = 39, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

