#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_12_Scrolls[SCROLL_DATA_SIZE(2)] = {
	22, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 13, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sRidley_22_Clipdata[127] = {
    #include "extracted/data/rooms/ridley/ridley_22_clipdata.gfx.inc"
};

const u8 sRidley_22_Bg2[14] = {
    #include "extracted/data/rooms/ridley/ridley_22_bg2.gfx.inc"
};

const u8 sRidley_22_Bg1[387] = {
    #include "extracted/data/rooms/ridley/ridley_22_bg1.gfx.inc"
};

const u8 sRidley_22_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_22_Bg0[67] = {
    #include "extracted/data/rooms/ridley/ridley_22_bg0.gfx.inc"
};

