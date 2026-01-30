#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_16_Scrolls[SCROLL_DATA_SIZE(2)] = {
	24, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	9, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_24_Clipdata[145] = INCBIN_U8("data/rooms/chozodia/chozodia_24_clipdata.gfx");

const u8 sChozodia_24_Bg2[256] = INCBIN_U8("data/rooms/chozodia/chozodia_24_bg2.gfx");

const u8 sChozodia_24_Bg1[300] = INCBIN_U8("data/rooms/chozodia/chozodia_24_bg1.gfx");

const u8 sChozodia_24_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_24_Bg0[62] = INCBIN_U8("data/rooms/chozodia/chozodia_24_bg0.gfx");

