#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_62_Clipdata[199] = {
    #include "extracted/data/rooms/chozodia/chozodia_62_clipdata.gfx.inc"
};

const u8 sChozodia_62_Bg2[584] = {
    #include "extracted/data/rooms/chozodia/chozodia_62_bg2.gfx.inc"
};

const u8 sChozodia_62_Bg1[686] = {
    #include "extracted/data/rooms/chozodia/chozodia_62_bg1.gfx.inc"
};

const u8 sChozodia_62_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	8, 6, SPRITESET_IDX(2),
	14, 12, SPRITESET_IDX(2),
	17, 7, SPRITESET_IDX(2),
	24, 11, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

