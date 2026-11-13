#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_4_Scrolls[SCROLL_DATA_SIZE(2)] = {
	9, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 76, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	32, 61, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sBrinstar_9_Clipdata[313] = {
    #include "extracted/data/rooms/brinstar/brinstar_9_clipdata.gfx.inc"
};

const u8 sBrinstar_9_Bg2[247] = {
    #include "extracted/data/rooms/brinstar/brinstar_9_bg2.gfx.inc"
};

const struct SpriteSpawn sBrinstar_9_Spriteset1[2] = {
    { .y = 1, .x = 69, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_9_Bg1[1389] = {
    #include "extracted/data/rooms/brinstar/brinstar_9_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_9_Spriteset0[1] = {
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_9_Bg0[172] = {
    #include "extracted/data/rooms/brinstar/brinstar_9_bg0.gfx.inc"
};

