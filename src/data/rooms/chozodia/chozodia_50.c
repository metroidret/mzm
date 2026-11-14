#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_32_Scrolls[SCROLL_DATA_SIZE(1)] = {
	50, // Room
	1, // Number of scrolls
	
	// Scroll 0
	0, 17, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_50_Clipdata[69] = {
    #include "extracted/data/rooms/chozodia/chozodia_50_clipdata.gfx.inc"
};

const u8 sChozodia_50_Bg2[193] = {
    #include "extracted/data/rooms/chozodia/chozodia_50_bg2.gfx.inc"
};

const u8 sChozodia_50_Bg1[171] = {
    #include "extracted/data/rooms/chozodia/chozodia_50_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_50_SpriteLayer0[1] = {
    SPRITE_SPAWN_TERMINATOR
};

