#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_8_Scrolls[SCROLL_DATA_SIZE(3)] = {
	15, // Room
	3, // Number of scrolls
	
	// Scroll 0
	17, 61, // X bounds
	3, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 61, // X bounds
	11, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 25, // X bounds
	2, 9, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sBrinstar_15_Clipdata[287] = {
    #include "extracted/data/rooms/brinstar/brinstar_15_clipdata.gfx.inc"
};

const u8 sBrinstar_15_Bg2[78] = {
    #include "extracted/data/rooms/brinstar/brinstar_15_bg2.gfx.inc"
};

const u8 sBrinstar_15_Bg1[975] = {
    #include "extracted/data/rooms/brinstar/brinstar_15_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_15_Spriteset0[4] = {
    { .y = 5, .x = 7, .id = SPRITESET_IDX(0) },
    { .y = 8, .x = 34, .id = SPRITESET_IDX(0) },
    { .y = 8, .x = 47, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

