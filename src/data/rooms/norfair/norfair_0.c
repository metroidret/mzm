#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_0_Scrolls[SCROLL_DATA_SIZE(1)] = {
	0, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	2, // Breakable block direction
	2, // Breakable block Y bound extension
};

const u8 sNorfair_0_Clipdata[238] = {
    #include "extracted/data/rooms/norfair/norfair_0_clipdata.gfx.inc"
};

const u8 sNorfair_0_Bg2[167] = {
    #include "extracted/data/rooms/norfair/norfair_0_bg2.gfx.inc"
};

const u8 sNorfair_0_Bg1[501] = {
    #include "extracted/data/rooms/norfair/norfair_0_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_0_SpriteLayer0[4] = {
    { .y = 15, .x = 9, .id = SPRITESET_IDX(4) },
    { .y = 21, .x = 8, .id = SPRITESET_IDX(2) },
    { .y = 25, .x = 8, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

