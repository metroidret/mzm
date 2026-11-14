#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_17_Scrolls[SCROLL_DATA_SIZE(2)] = {
	26, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	11, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	32, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_26_Clipdata[147] = {
    #include "extracted/data/rooms/chozodia/chozodia_26_clipdata.gfx.inc"
};

const u8 sChozodia_26_Bg2[105] = {
    #include "extracted/data/rooms/chozodia/chozodia_26_bg2.gfx.inc"
};

const u8 sChozodia_26_Bg1[706] = {
    #include "extracted/data/rooms/chozodia/chozodia_26_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_26_SpriteLayer0[3] = {
    { .y = 14, .x = 42, .id = SPRITESET_IDX(0) },
    { .y = 17, .x = 44, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_26_Bg0[111] = {
    #include "extracted/data/rooms/chozodia/chozodia_26_bg0.gfx.inc"
};

