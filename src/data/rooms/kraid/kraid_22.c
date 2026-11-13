#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_22_Clipdata[86] = {
    #include "extracted/data/rooms/kraid/kraid_22_clipdata.gfx.inc"
};

const u8 sKraid_22_Bg2[299] = {
    #include "extracted/data/rooms/kraid/kraid_22_bg2.gfx.inc"
};

const struct SpriteDataRom sKraid_22_Spriteset1[12] = {
    { .y = 3, .x = 20, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 30, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 39, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 48, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 56, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 66, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 23, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 34, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 43, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 52, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 62, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_22_Bg1[382] = {
    #include "extracted/data/rooms/kraid/kraid_22_bg1.gfx.inc"
};

const struct SpriteDataRom sKraid_22_Spriteset0[12] = {
    { .y = 3, .x = 20, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 30, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 39, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 48, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 56, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 66, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 23, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 34, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 43, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 52, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 62, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

