#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_17_Clipdata[71] = {
    #include "extracted/data/rooms/brinstar/brinstar_17_clipdata.gfx.inc"
};

const u8 sBrinstar_17_Bg2[89] = {
    #include "extracted/data/rooms/brinstar/brinstar_17_bg2.gfx.inc"
};

const u8 sBrinstar_17_Bg1[265] = {
    #include "extracted/data/rooms/brinstar/brinstar_17_bg1.gfx.inc"
};

const u8 sBrinstar_17_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	4, 14, SPRITESET_IDX(0),
	5, 20, SPRITESET_IDX(0),
	6, 16, SPRITESET_IDX(0),
	8, 13, SPRITESET_IDX(0),
	9, 19, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

