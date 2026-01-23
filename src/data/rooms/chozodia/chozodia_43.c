#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_43_Clipdata[105] = INCBIN_U8("data/rooms/chozodia/chozodia_43_clipdata.gfx");

const u8 sChozodia_43_Bg2[184] = INCBIN_U8("data/rooms/chozodia/chozodia_43_bg2.gfx");

const u8 sChozodia_43_Bg1[276] = INCBIN_U8("data/rooms/chozodia/chozodia_43_bg1.gfx");

const u8 sChozodia_43_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	6, 2, SPRITESET_IDX(1),
	16, 16, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

