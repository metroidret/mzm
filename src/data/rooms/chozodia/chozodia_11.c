#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_7_Scrolls[SCROLL_DATA_SIZE(1)] = {
	11, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 14, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_11_Clipdata[95] = {
    #include "extracted/data/rooms/chozodia/chozodia_11_clipdata.gfx.inc"
};

const u8 sChozodia_11_Bg2_Unused[14] = {
    #include "extracted/data/rooms/chozodia/chozodia_11_bg2_unused.gfx.inc"
};

const u8 sChozodia_11_Bg1[221] = {
    #include "extracted/data/rooms/chozodia/chozodia_11_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_11_SpriteLayer0[2] = {
    { .y = 4, .x = 7, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

