#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_39_Clipdata[78] = {
    #include "extracted/data/rooms/kraid/kraid_39_clipdata.gfx.inc"
};

const u8 sKraid_39_Bg2[14] = {
    #include "extracted/data/rooms/kraid/kraid_39_bg2.gfx.inc"
};

const u8 sKraid_39_Bg1[216] = {
    #include "extracted/data/rooms/kraid/kraid_39_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_39_Spriteset0[2] = {
    { .y = 10, .x = 9, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

