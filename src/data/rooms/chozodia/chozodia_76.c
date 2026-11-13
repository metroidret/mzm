#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_76_Clipdata[95] = {
    #include "extracted/data/rooms/chozodia/chozodia_76_clipdata.gfx.inc"
};

const u8 sChozodia_76_Bg2[83] = {
    #include "extracted/data/rooms/chozodia/chozodia_76_bg2.gfx.inc"
};

const struct SpriteSpawn sChozodia_76_Spriteset1[3] = {
    { .y = 9, .x = 7, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 9, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_76_Bg1[269] = {
    #include "extracted/data/rooms/chozodia/chozodia_76_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_76_Spriteset0[2] = {
    { .y = 9, .x = 9, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

