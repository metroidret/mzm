#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_22_Scrolls[SCROLL_DATA_SIZE(4)] = {
	32, // Room
	4, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 25, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	25, 40, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	12, 31, // X bounds
	2, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 3
	15, 31, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_32_Clipdata[251] = {
    #include "extracted/data/rooms/chozodia/chozodia_32_clipdata.gfx.inc"
};

const u8 sChozodia_32_Bg2[265] = {
    #include "extracted/data/rooms/chozodia/chozodia_32_bg2.gfx.inc"
};

const u8 sChozodia_32_Bg1[972] = {
    #include "extracted/data/rooms/chozodia/chozodia_32_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_32_SpriteLayer0[3] = {
    { .y = 6, .x = 17, .id = SPRITESET_IDX(4) },
    { .y = 17, .x = 8, .id = SPRITESET_IDX(5) },
    SPRITE_SPAWN_TERMINATOR
};

