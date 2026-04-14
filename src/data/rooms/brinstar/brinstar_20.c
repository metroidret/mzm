#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_20_Clipdata[336] = {
    #include "extracted/data/rooms/brinstar/brinstar_20_clipdata.gfx.inc"
};

const u8 sBrinstar_20_Bg2[211] = {
    #include "extracted/data/rooms/brinstar/brinstar_20_bg2.gfx.inc"
};

const u8 sBrinstar_20_Bg1[1163] = {
    #include "extracted/data/rooms/brinstar/brinstar_20_bg1.gfx.inc"
};

const u8 sBrinstar_20_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	16, 4, SPRITESET_IDX(2),
	22, 5, SPRITESET_IDX(2),
	33, 10, SPRITESET_IDX(0),
	38, 9, SPRITESET_IDX(0),
	47, 10, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

