#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_6_Scrolls[SCROLL_DATA_SIZE(2)] = {
	10, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	4, 14, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	14, 23, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_10_Clipdata[122] = {
    #include "extracted/data/rooms/chozodia/chozodia_10_clipdata.gfx.inc"
};

const u8 sChozodia_10_Bg2[178] = {
    #include "extracted/data/rooms/chozodia/chozodia_10_bg2.gfx.inc"
};

const u8 sChozodia_10_Bg1[465] = {
    #include "extracted/data/rooms/chozodia/chozodia_10_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_10_Spriteset0[3] = {
    { .y = 9, .x = 7, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 22, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};
