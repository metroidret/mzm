#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_10_Scrolls[SCROLL_DATA_SIZE(2)] = {
	31, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	8, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sNorfair_31_Clipdata[120] = {
    #include "extracted/data/rooms/norfair/norfair_31_clipdata.gfx.inc"
};

const u8 sNorfair_31_Bg2[296] = {
    #include "extracted/data/rooms/norfair/norfair_31_bg2.gfx.inc"
};

const u8 sNorfair_31_Bg1[322] = {
    #include "extracted/data/rooms/norfair/norfair_31_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_31_SpriteLayer0[3] = {
    { .y = 14, .x = 11, .id = SPRITESET_IDX(2) },
    { .y = 15, .x = 14, .id = SPRITESET_IDX(3) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_31_Bg0[215] = {
    #include "extracted/data/rooms/norfair/norfair_31_bg0.gfx.inc"
};

