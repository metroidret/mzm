#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_4_Scrolls[SCROLL_DATA_SIZE(2)] = {
	8, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 33, // X bounds
	3, 23, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_8_Clipdata[192] = {
    #include "extracted/data/rooms/chozodia/chozodia_8_clipdata.gfx.inc"
};

const u8 sChozodia_8_Bg2[332] = {
    #include "extracted/data/rooms/chozodia/chozodia_8_bg2.gfx.inc"
};

const u8 sChozodia_8_Bg1[511] = {
    #include "extracted/data/rooms/chozodia/chozodia_8_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_8_Spriteset0[2] = {
    { .y = 21, .x = 30, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

