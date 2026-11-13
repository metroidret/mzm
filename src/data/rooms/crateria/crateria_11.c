#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_11_Clipdata[150] = {
    #include "extracted/data/rooms/crateria/crateria_11_clipdata.gfx.inc"
};

const u8 sCrateria_11_Bg2[241] = {
    #include "extracted/data/rooms/crateria/crateria_11_bg2.gfx.inc"
};

const u8 sCrateria_11_Bg1[313] = {
    #include "extracted/data/rooms/crateria/crateria_11_bg1.gfx.inc"
};

const struct SpriteSpawn sCrateria_11_SpriteLayer0[7] = {
    { .y = 3, .x = 12, .id = SPRITESET_IDX(2) },
    { .y = 4, .x = 16, .id = SPRITESET_IDX(0) },
    { .y = 4, .x = 21, .id = SPRITESET_IDX(2) },
    { .y = 5, .x = 7, .id = SPRITESET_IDX(2) },
    { .y = 7, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 20, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

