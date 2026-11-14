#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_26_Scrolls[SCROLL_DATA_SIZE(3)] = {
	41, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 61, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 41, // X bounds
	2, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	17, 58, // X bounds
	29, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_41_Clipdata[895] = {
    #include "extracted/data/rooms/chozodia/chozodia_41_clipdata.gfx.inc"
};

const u8 sChozodia_41_Bg1[1632] = {
    #include "extracted/data/rooms/chozodia/chozodia_41_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_41_SpriteLayer0[2] = {
    { .y = 28, .x = 23, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

