#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_41_Scrolls[SCROLL_DATA_SIZE(2)] = {
	69, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	3, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_69_Clipdata[157] = {
    #include "extracted/data/rooms/chozodia/chozodia_69_clipdata.gfx.inc"
};

const u8 sChozodia_69_Bg2[497] = {
    #include "extracted/data/rooms/chozodia/chozodia_69_bg2.gfx.inc"
};

const u8 sChozodia_69_Bg1[435] = {
    #include "extracted/data/rooms/chozodia/chozodia_69_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_69_SpriteLayer0[2] = {
    { .y = 18, .x = 41, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_69_Bg0[91] = {
    #include "extracted/data/rooms/chozodia/chozodia_69_bg0.gfx.inc"
};

