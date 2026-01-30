#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_5_Scrolls[SCROLL_DATA_SIZE(1)] = {
	6, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	3, // Breakable block direction
	21, // Breakable block Y bound extension
};

const u8 sCrateria_6_Clipdata[153] = INCBIN_U8("data/rooms/crateria/crateria_6_clipdata.gfx");

const u8 sCrateria_6_Bg2[269] = INCBIN_U8("data/rooms/crateria/crateria_6_bg2.gfx");

const u8 sCrateria_6_Bg1[403] = INCBIN_U8("data/rooms/crateria/crateria_6_bg1.gfx");

const u8 sCrateria_6_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	9, 9, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

