#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_30_Clipdata[76] = INCBIN_U8("data/rooms/brinstar/brinstar_30_clipdata.gfx");

const u8 sBrinstar_30_Bg2[14] = INCBIN_U8("data/rooms/brinstar/brinstar_30_bg2.gfx");

const u8 sBrinstar_30_Bg1[220] = INCBIN_U8("data/rooms/brinstar/brinstar_30_bg1.gfx");

const u8 sBrinstar_30_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	9, 11, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

