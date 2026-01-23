#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_76_Clipdata[95] = INCBIN_U8("data/rooms/chozodia/chozodia_76_clipdata.gfx");

const u8 sChozodia_76_Bg2[83] = INCBIN_U8("data/rooms/chozodia/chozodia_76_bg2.gfx");

const u8 sChozodia_76_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	9, 7, SPRITESET_IDX(0),
	9, 9, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_76_Bg1[269] = INCBIN_U8("data/rooms/chozodia/chozodia_76_bg1.gfx");

const u8 sChozodia_76_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	9, 9, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

