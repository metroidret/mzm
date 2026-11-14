#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_21_Scrolls[SCROLL_DATA_SIZE(2)] = {
	31, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	2, 14, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	13, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_31_Clipdata[276] = {
    #include "extracted/data/rooms/chozodia/chozodia_31_clipdata.gfx.inc"
};

const u8 sChozodia_31_Bg2[177] = {
    #include "extracted/data/rooms/chozodia/chozodia_31_bg2.gfx.inc"
};

const u8 sChozodia_31_Bg1[987] = {
    #include "extracted/data/rooms/chozodia/chozodia_31_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_31_SpriteLayer0[6] = {
    { .y = 12, .x = 14, .id = SPRITESET_IDX(0) },
    { .y = 13, .x = 18, .id = SPRITESET_IDX(0) },
    { .y = 13, .x = 27, .id = SPRITESET_IDX(0) },
    { .y = 13, .x = 32, .id = SPRITESET_IDX(0) },
    { .y = 17, .x = 10, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

