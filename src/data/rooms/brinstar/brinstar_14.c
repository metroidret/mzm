#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_7_Scrolls[SCROLL_DATA_SIZE(2)] = {
	14, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	9, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sBrinstar_14_Clipdata[212] = {
    #include "extracted/data/rooms/brinstar/brinstar_14_clipdata.gfx.inc"
};

const u8 sBrinstar_14_Bg2[38] = {
    #include "extracted/data/rooms/brinstar/brinstar_14_bg2.gfx.inc"
};

const u8 sBrinstar_14_Bg1[532] = {
    #include "extracted/data/rooms/brinstar/brinstar_14_bg1.gfx.inc"
};

const struct SpriteDataRom sBrinstar_14_Spriteset0[2] = {
    { .y = 3, .x = 9, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

