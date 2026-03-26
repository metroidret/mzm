#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_40_Clipdata[93] = {
    #include "extracted/data/rooms/brinstar/brinstar_40_clipdata.gfx.inc"
};

const u8 sBrinstar_40_Bg2[14] = {
    #include "extracted/data/rooms/brinstar/brinstar_40_bg2.gfx.inc"
};

const u8 sBrinstar_40_Bg1[236] = {
    #include "extracted/data/rooms/brinstar/brinstar_40_bg1.gfx.inc"
};

const u8 sBrinstar_40_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	8, 10, SPRITESET_IDX(2),
	8, 15, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

