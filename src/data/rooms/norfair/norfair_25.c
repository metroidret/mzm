#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_9_Scrolls[SCROLL_DATA_SIZE(2)] = {
	25, // Room
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

const u8 sNorfair_25_Clipdata[138] = {
    #include "extracted/data/rooms/norfair/norfair_25_clipdata.gfx.inc"
};

const u8 sNorfair_25_Bg2[205] = {
    #include "extracted/data/rooms/norfair/norfair_25_bg2.gfx.inc"
};

const struct SpriteSpawn sNorfair_25_SpriteLayer1[5] = {
    { .y = 9, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 14, .x = 13, .id = SPRITESET_IDX(3) },
    { .y = 15, .x = 11, .id = SPRITESET_IDX(1) },
    { .y = 17, .x = 13, .id = SPRITESET_IDX(3) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_25_Bg1[365] = {
    #include "extracted/data/rooms/norfair/norfair_25_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_25_SpriteLayer0[3] = {
    { .y = 9, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 15, .x = 11, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_25_Bg0[214] = {
    #include "extracted/data/rooms/norfair/norfair_25_bg0.gfx.inc"
};

