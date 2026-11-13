#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_57_Scrolls[SCROLL_DATA_SIZE(2)] = {
	95, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	62, 71, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 31, // X bounds
	2, 71, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_95_Clipdata[572] = {
    #include "extracted/data/rooms/chozodia/chozodia_95_clipdata.gfx.inc"
};

const u8 sChozodia_95_Bg1[971] = {
    #include "extracted/data/rooms/chozodia/chozodia_95_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_95_Spriteset0[6] = {
    { .y = 18, .x = 30, .id = SPRITESET_IDX(3) },
    { .y = 28, .x = 18, .id = SPRITESET_IDX(3) },
    { .y = 38, .x = 30, .id = SPRITESET_IDX(3) },
    { .y = 48, .x = 18, .id = SPRITESET_IDX(3) },
    { .y = 58, .x = 30, .id = SPRITESET_IDX(3) },
    SPRITE_SPAWN_TERMINATOR
};

