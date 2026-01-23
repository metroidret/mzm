#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_20_Clipdata[412] = INCBIN_U8("data/rooms/chozodia/chozodia_20_clipdata.gfx");

const u8 sChozodia_20_Bg2[741] = INCBIN_U8("data/rooms/chozodia/chozodia_20_bg2.gfx");

const u8 sChozodia_20_Bg1[977] = INCBIN_U8("data/rooms/chozodia/chozodia_20_bg1.gfx");

const u8 sChozodia_20_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	16, 9, SPRITESET_IDX(0),
	16, 13, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_20_Bg0[885] = INCBIN_U8("data/rooms/chozodia/chozodia_20_bg0.gfx");

