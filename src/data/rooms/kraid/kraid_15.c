#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_15_Clipdata[238] = {
    #include "extracted/data/rooms/kraid/kraid_15_clipdata.gfx.inc"
};

const u8 sKraid_15_Bg2[98] = {
    #include "extracted/data/rooms/kraid/kraid_15_bg2.gfx.inc"
};

const struct SpriteDataRom sKraid_15_Spriteset1[3] = {
    { .y = 5, .x = 7, .id = SPRITESET_IDX(4) },
    { .y = 19, .x = 10, .id = SPRITESET_IDX(4) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_15_Bg1[387] = {
    #include "extracted/data/rooms/kraid/kraid_15_bg1.gfx.inc"
};

const struct SpriteDataRom sKraid_15_Spriteset0[3] = {
    { .y = 5, .x = 7, .id = SPRITESET_IDX(0) },
	19,	10, SPRITESET_IDX(0),
    ROOM_SPRITE_DATA_TERMINATOR
};

