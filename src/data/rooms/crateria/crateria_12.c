#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_12_Clipdata[48] = {
    #include "extracted/data/rooms/crateria/crateria_12_clipdata.gfx.inc"
};

const u8 sCrateria_12_Bg2[119] = {
    #include "extracted/data/rooms/crateria/crateria_12_bg2.gfx.inc"
};

const u8 sCrateria_12_Bg1[145] = {
    #include "extracted/data/rooms/crateria/crateria_12_bg1.gfx.inc"
};

const struct SpriteSpawn sCrateria_12_SpriteLayer0[2] = {
    { .y = 8, .x = 7, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

