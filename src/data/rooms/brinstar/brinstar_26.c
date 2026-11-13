#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_15_Scrolls[SCROLL_DATA_SIZE(1)] = {
	26, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	3, // Breakable block direction
	21, // Breakable block Y bound extension
};

const u8 sBrinstar_26_Clipdata[108] = {
    #include "extracted/data/rooms/brinstar/brinstar_26_clipdata.gfx.inc"
};

const u8 sBrinstar_26_Bg2[166] = {
    #include "extracted/data/rooms/brinstar/brinstar_26_bg2.gfx.inc"
};

const u8 sBrinstar_26_Bg1[340] = {
    #include "extracted/data/rooms/brinstar/brinstar_26_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_26_Spriteset0[2] = {
    { .y = 9, .x = 9, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

