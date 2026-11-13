#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_63_Clipdata[133] = {
    #include "extracted/data/rooms/chozodia/chozodia_63_clipdata.gfx.inc"
};

const u8 sChozodia_63_Bg2[574] = {
    #include "extracted/data/rooms/chozodia/chozodia_63_bg2.gfx.inc"
};

const u8 sChozodia_63_Bg1[415] = {
    #include "extracted/data/rooms/chozodia/chozodia_63_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_63_Spriteset0[8] = {
    { .y = 6, .x = 8, .id = SPRITESET_IDX(4) },
    { .y = 6, .x = 12, .id = SPRITESET_IDX(4) },
    { .y = 7, .x = 15, .id = SPRITESET_IDX(4) },
    { .y = 9, .x = 7, .id = SPRITESET_IDX(4) },
    { .y = 11, .x = 21, .id = SPRITESET_IDX(4) },
    { .y = 13, .x = 16, .id = SPRITESET_IDX(4) },
    { .y = 15, .x = 27, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

