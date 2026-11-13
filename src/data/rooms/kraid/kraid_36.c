#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_36_Clipdata[69] = {
    #include "extracted/data/rooms/kraid/kraid_36_clipdata.gfx.inc"
};

const u8 sKraid_36_Bg2[26] = {
    #include "extracted/data/rooms/kraid/kraid_36_bg2.gfx.inc"
};

const u8 sKraid_36_Bg1[224] = {
    #include "extracted/data/rooms/kraid/kraid_36_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_36_Spriteset0[2] = {
    { .y = 10, .x = 10, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

