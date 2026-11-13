#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_30_Scrolls[SCROLL_DATA_SIZE(3)] = {
	48, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 32, // X bounds
	4, 27, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	32, 106, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_48_Clipdata[282] = {
    #include "extracted/data/rooms/chozodia/chozodia_48_clipdata.gfx.inc"
};

const u8 sChozodia_48_Bg2[902] = {
    #include "extracted/data/rooms/chozodia/chozodia_48_bg2.gfx.inc"
};

const struct SpriteSpawn sChozodia_48_Spriteset1[2] = {
    { .y = 26, .x = 23, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_48_Bg1[1155] = {
    #include "extracted/data/rooms/chozodia/chozodia_48_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_48_Spriteset0[2] = {
    { .y = 26, .x = 23, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

