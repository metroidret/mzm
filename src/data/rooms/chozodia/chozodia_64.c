#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_38_Scrolls[SCROLL_DATA_SIZE(1)] = {
	64, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	4, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_64_Clipdata[108] = {
    #include "extracted/data/rooms/chozodia/chozodia_64_clipdata.gfx.inc"
};

const u8 sChozodia_64_Bg2[394] = {
    #include "extracted/data/rooms/chozodia/chozodia_64_bg2.gfx.inc"
};

const u8 sChozodia_64_Bg1[359] = {
    #include "extracted/data/rooms/chozodia/chozodia_64_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_64_Spriteset0[4] = {
    { .y = 8, .x = 5, .id = SPRITESET_IDX(2) },
    { .y = 13, .x = 13, .id = SPRITESET_IDX(2) },
    { .y = 17, .x = 6, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

