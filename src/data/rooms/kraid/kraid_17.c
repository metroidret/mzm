#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_17_Clipdata[] = {
    #include "extracted/data/rooms/kraid/kraid_17_clipdata.gfx.inc"
};

const u8 sKraid_17_Bg2[114] = {
    #include "extracted/data/rooms/kraid/kraid_17_bg2.gfx.inc"
};

const u8 sKraid_17_Bg1[493] = {
    #include "extracted/data/rooms/kraid/kraid_17_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_17_SpriteLayer0[5] = {
    { .y = 7, .x = 9, .id = SPRITESET_IDX(4) },
    { .y = 8, .x = 11, .id = SPRITESET_IDX(4) },
    { .y = 8, .x = 29, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 20, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_17_Bg0[] = {
    #include "extracted/data/rooms/kraid/kraid_17_bg0.gfx.inc"
};

