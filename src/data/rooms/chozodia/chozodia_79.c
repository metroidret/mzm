#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_45_Scrolls[SCROLL_DATA_SIZE(4)] = {
	79, // Room
	4, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 31, // X bounds
	11, 24, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 17, // X bounds
	20, 33, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 3
	15, 31, // X bounds
	24, 33, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_79_Clipdata[296] = {
    #include "extracted/data/rooms/chozodia/chozodia_79_clipdata.gfx.inc"
};

const u8 sChozodia_79_Bg2[303] = {
    #include "extracted/data/rooms/chozodia/chozodia_79_bg2.gfx.inc"
};

const u8 sChozodia_79_Bg1[811] = {
    #include "extracted/data/rooms/chozodia/chozodia_79_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_79_SpriteLayer0[6] = {
    { .y = 15, .x = 31, .id = SPRITESET_IDX(2) },
    { .y = 16, .x = 2, .id = SPRITESET_IDX(1) },
    { .y = 18, .x = 14, .id = SPRITESET_IDX(7) },
    { .y = 26, .x = 5, .id = SPRITESET_IDX(7) },
    { .y = 27, .x = 28, .id = SPRITESET_IDX(6) },
    SPRITE_SPAWN_TERMINATOR
};

