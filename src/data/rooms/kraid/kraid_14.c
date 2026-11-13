#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_14_Clipdata[118] = {
    #include "extracted/data/rooms/kraid/kraid_14_clipdata.gfx.inc"
};

const u8 sKraid_14_Bg2[46] = {
    #include "extracted/data/rooms/kraid/kraid_14_bg2.gfx.inc"
};

const u8 sKraid_14_Bg1[217] = {
    #include "extracted/data/rooms/kraid/kraid_14_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_14_Spriteset0[4] = {
    { .y = 3, .x = 5, .id = SPRITESET_IDX(1) },
    { .y = 4, .x = 4, .id = SPRITESET_IDX(2) },
    { .y = 4, .x = 14, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

