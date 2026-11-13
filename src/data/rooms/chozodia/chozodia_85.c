#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_51_Scrolls[SCROLL_DATA_SIZE(2)] = {
	85, // Room
	2, // Number of scrolls
	
	// Scroll 0
	17, 61, // X bounds
	2, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	3, 17, // X bounds
	32, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_85_Clipdata[423] = {
    #include "extracted/data/rooms/chozodia/chozodia_85_clipdata.gfx.inc"
};

const u8 sChozodia_85_Bg2[401] = {
    #include "extracted/data/rooms/chozodia/chozodia_85_bg2.gfx.inc"
};

const u8 sChozodia_85_Bg1[1438] = {
    #include "extracted/data/rooms/chozodia/chozodia_85_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_85_Spriteset0[4] = {
    { .y = 16, .x = 38, .id = SPRITESET_IDX(2) },
    { .y = 18, .x = 61, .id = SPRITESET_IDX(1) },
    { .y = 22, .x = 37, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

