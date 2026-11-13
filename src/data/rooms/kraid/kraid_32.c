#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_32_Clipdata[70] = {
    #include "extracted/data/rooms/kraid/kraid_32_clipdata.gfx.inc"
};

const u8 sKraid_32_Bg2[14] = {
    #include "extracted/data/rooms/kraid/kraid_32_bg2.gfx.inc"
};

const u8 sKraid_32_Bg1[211] = {
    #include "extracted/data/rooms/kraid/kraid_32_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_32_Spriteset0[2] = {
    { .y = 10, .x = 8, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

