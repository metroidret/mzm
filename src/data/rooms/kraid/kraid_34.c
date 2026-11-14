#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_34_Clipdata[55] = {
    #include "extracted/data/rooms/kraid/kraid_34_clipdata.gfx.inc"
};

const u8 sKraid_34_Bg2[147] = {
    #include "extracted/data/rooms/kraid/kraid_34_bg2.gfx.inc"
};

const u8 sKraid_34_Bg1[144] = {
    #include "extracted/data/rooms/kraid/kraid_34_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_34_SpriteLayer0[2] = {
    { .y = 7, .x = 5, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

