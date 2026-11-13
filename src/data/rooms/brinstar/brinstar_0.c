#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_0_Scrolls[SCROLL_DATA_SIZE(3)] = {
	0, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 76, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	32, 46, // X bounds
	2, 23, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	32, 46, // X bounds
	31, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sBrinstar_0_Clipdata[311] = {
    #include "extracted/data/rooms/brinstar/brinstar_0_clipdata.gfx.inc"
};

const u8 sBrinstar_0_Bg2[124] = {
    #include "extracted/data/rooms/brinstar/brinstar_0_bg2.gfx.inc"
};

const struct SpriteSpawn sBrinstar_0_Spriteset1[9] = {
    { .y = 22, .x = 27, .id = SPRITESET_IDX(4) },
    { .y = 22, .x = 56, .id = SPRITESET_IDX(4) },
    { .y = 23, .x = 68, .id = SPRITESET_IDX(4) },
    { .y = 24, .x = 4, .id = SPRITESET_IDX(4) },
    { .y = 27, .x = 11, .id = SPRITESET_IDX(1) },
    { .y = 30, .x = 21, .id = SPRITESET_IDX(4) },
    { .y = 30, .x = 67, .id = SPRITESET_IDX(4) },
    { .y = 34, .x = 39, .id = SPRITESET_IDX(3) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_0_Bg1[1328] = {
    #include "extracted/data/rooms/brinstar/brinstar_0_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_0_Spriteset0[9] = {
    { .y = 22, .x = 27, .id = SPRITESET_IDX(0) },
    { .y = 22, .x = 56, .id = SPRITESET_IDX(0) },
    { .y = 23, .x = 68, .id = SPRITESET_IDX(0) },
    { .y = 24, .x = 4, .id = SPRITESET_IDX(0) },
    { .y = 27, .x = 11, .id = SPRITESET_IDX(1) },
    { .y = 30, .x = 21, .id = SPRITESET_IDX(0) },
    { .y = 30, .x = 67, .id = SPRITESET_IDX(0) },
    { .y = 34, .x = 39, .id = SPRITESET_IDX(3) },
    SPRITE_SPAWN_TERMINATOR
};

