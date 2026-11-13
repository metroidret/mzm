#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_43_Scrolls[SCROLL_DATA_SIZE(1)] = {
	72, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 17, // X bounds
	9, 18, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_72_Clipdata[106] = {
    #include "extracted/data/rooms/chozodia/chozodia_72_clipdata.gfx.inc"
};

const u8 sChozodia_72_Bg2[95] = {
    #include "extracted/data/rooms/chozodia/chozodia_72_bg2.gfx.inc"
};

const u8 sChozodia_72_Bg1[112] = {
    #include "extracted/data/rooms/chozodia/chozodia_72_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_72_SpriteLayer0[2] = {
    { .y = 15, .x = 11, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

