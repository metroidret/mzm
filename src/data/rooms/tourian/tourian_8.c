#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_3_Scrolls[SCROLL_DATA_SIZE(2)] = {
	8, // Room
	2, // Number of scrolls
	
	// Scroll 0
	17, 31, // X bounds
	12, 111, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	2, // Breakable block direction
	2, // Breakable block Y bound extension

	// Scroll 1
	2, 18, // X bounds
	101, 111, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sTourian_8_Clipdata[657] = INCBIN_U8("data/rooms/tourian/tourian_8_clipdata.gfx");

const u8 sTourian_8_Bg2[1201] = INCBIN_U8("data/rooms/tourian/tourian_8_bg2.gfx");

const u8 sTourian_8_Bg1[1638] = INCBIN_U8("data/rooms/tourian/tourian_8_bg1.gfx");

const u8 sTourian_8_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	15, 24, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

