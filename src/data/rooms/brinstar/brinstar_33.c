#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_33_Clipdata[71] = {
    #include "extracted/data/rooms/brinstar/brinstar_33_clipdata.gfx.inc"
};

const u8 sBrinstar_33_Bg2[14] = {
    #include "extracted/data/rooms/brinstar/brinstar_33_bg2.gfx.inc"
};

const u8 sBrinstar_33_Bg1[211] = {
    #include "extracted/data/rooms/brinstar/brinstar_33_bg1.gfx.inc"
};

const u8 sBrinstar_33_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 8, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

