#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_33_Clipdata[71] = {
    #include "extracted/data/rooms/kraid/kraid_33_clipdata.gfx.inc"
};

const u8 sKraid_33_Bg2[29] = {
    #include "extracted/data/rooms/kraid/kraid_33_bg2.gfx.inc"
};

const u8 sKraid_33_Bg1[181] = {
    #include "extracted/data/rooms/kraid/kraid_33_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_33_Spriteset0[3] = {
    { .y = 7, .x = 14, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 6, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

