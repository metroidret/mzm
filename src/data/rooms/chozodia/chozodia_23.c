#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_15_Scrolls[SCROLL_DATA_SIZE(2)] = {
	23, // Room
	2, // Number of scrolls
	
	// Scroll 0
	17, 61, // X bounds
	2, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	3, 17, // X bounds
	32, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_23_Clipdata[401] = INCBIN_U8("data/rooms/chozodia/chozodia_23_clipdata.gfx");

const u8 sChozodia_23_Bg2[401] = INCBIN_U8("data/rooms/chozodia/chozodia_23_bg2.gfx");

const u8 sChozodia_23_Bg1[1441] = INCBIN_U8("data/rooms/chozodia/chozodia_23_bg1.gfx");

const u8 sChozodia_23_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	16, 38, SPRITESET_IDX(2),
	18, 61, SPRITESET_IDX(1),
	22, 37, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_23_Bg0[15] = INCBIN_U8("data/rooms/chozodia/chozodia_23_bg0.gfx");

