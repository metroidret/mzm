#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_55_Scrolls[SCROLL_DATA_SIZE(1)] = {
	91, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 22, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_91_Clipdata[170] = {
    #include "extracted/data/rooms/chozodia/chozodia_91_clipdata.gfx.inc"
};

const u8 sChozodia_91_Bg2[38] = {
    #include "extracted/data/rooms/chozodia/chozodia_91_bg2.gfx.inc"
};

const u8 sChozodia_91_Bg1[497] = {
    #include "extracted/data/rooms/chozodia/chozodia_91_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_91_Spriteset0[3] = {
    { .y = 9, .x = 12, .id = SPRITESET_IDX(2) },
    { .y = 18, .x = 11, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

