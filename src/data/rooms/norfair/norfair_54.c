#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_15_Scrolls[SCROLL_DATA_SIZE(2)] = {
	54, // Room
	2, // Number of scrolls
	
	// Scroll 0
	16, 46, // X bounds
	2, 15, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	16, 46, // X bounds
	13, 29, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sNorfair_54_Clipdata[266] = {
    #include "extracted/data/rooms/norfair/norfair_54_clipdata.gfx.inc"
};

const u8 sNorfair_54_Bg2[606] = {
    #include "extracted/data/rooms/norfair/norfair_54_bg2.gfx.inc"
};

const u8 sNorfair_54_Bg1[927] = {
    #include "extracted/data/rooms/norfair/norfair_54_bg1.gfx.inc"
};

const u8 sNorfair_54_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	2, 23, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_54_Bg0[85] = {
    #include "extracted/data/rooms/norfair/norfair_54_bg0.gfx.inc"
};

