#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_31_Scrolls[SCROLL_DATA_SIZE(1)] = {
	49, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 21, // Y bounds
	9, 12, // Breakable block position
	2, // Breakable block direction
	2, // Breakable block Y bound extension
};

const u8 sChozodia_49_Clipdata[129] = INCBIN_U8("data/rooms/chozodia/chozodia_49_clipdata.gfx");

const u8 sChozodia_49_Bg2[255] = INCBIN_U8("data/rooms/chozodia/chozodia_49_bg2.gfx");

const u8 sChozodia_49_Bg1[327] = INCBIN_U8("data/rooms/chozodia/chozodia_49_bg1.gfx");

const u8 sChozodia_49_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	6, 5, SPRITESET_IDX(0),
	6, 14, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

