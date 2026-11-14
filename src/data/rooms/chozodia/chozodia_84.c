#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_50_Scrolls[SCROLL_DATA_SIZE(1)] = {
	84, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 22, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_84_Clipdata[184] = {
    #include "extracted/data/rooms/chozodia/chozodia_84_clipdata.gfx.inc"
};

const u8 sChozodia_84_Bg2[38] = {
    #include "extracted/data/rooms/chozodia/chozodia_84_bg2.gfx.inc"
};

const u8 sChozodia_84_Bg1[480] = {
    #include "extracted/data/rooms/chozodia/chozodia_84_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_84_SpriteLayer0[3] = {
    { .y = 9, .x = 12, .id = SPRITESET_IDX(2) },
    { .y = 18, .x = 11, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_84_Bg0[119] = {
    #include "extracted/data/rooms/chozodia/chozodia_84_bg0.gfx.inc"
};

