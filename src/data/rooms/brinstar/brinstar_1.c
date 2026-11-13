#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_1_Scrolls[SCROLL_DATA_SIZE(3)] = {
	1, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	19, 51, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 16, // X bounds
	2, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sBrinstar_1_Clipdata[317] = {
    #include "extracted/data/rooms/brinstar/brinstar_1_clipdata.gfx.inc"
};

const u8 sBrinstar_1_Bg2[14] = {
    #include "extracted/data/rooms/brinstar/brinstar_1_bg2.gfx.inc"
};

const struct SpriteSpawn sBrinstar_1_Spriteset1[15] = {
    { .y = 16, .x = 6, .id = SPRITESET_IDX(5) },
    { .y = 16, .x = 8, .id = SPRITESET_IDX(5) },
    { .y = 16, .x = 9, .id = SPRITESET_IDX(1) },
    { .y = 16, .x = 10, .id = SPRITESET_IDX(5) },
    { .y = 16, .x = 11, .id = SPRITESET_IDX(5) },
    { .y = 18, .x = 9, .id = SPRITESET_IDX(5) },
    { .y = 18, .x = 12, .id = SPRITESET_IDX(5) },
    { .y = 23, .x = 9, .id = SPRITESET_IDX(1) },
    { .y = 24, .x = 5, .id = SPRITESET_IDX(5) },
    { .y = 27, .x = 11, .id = SPRITESET_IDX(1) },
    { .y = 28, .x = 6, .id = SPRITESET_IDX(2) },
    { .y = 32, .x = 7, .id = SPRITESET_IDX(1) },
    { .y = 43, .x = 7, .id = SPRITESET_IDX(2) },
    { .y = 49, .x = 6, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_1_Bg1[1142] = {
    #include "extracted/data/rooms/brinstar/brinstar_1_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_1_Spriteset0[8] = {
    { .y = 16, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 23, .x = 9, .id = SPRITESET_IDX(1) },
    { .y = 27, .x = 11, .id = SPRITESET_IDX(1) },
    { .y = 28, .x = 6, .id = SPRITESET_IDX(2) },
    { .y = 32, .x = 7, .id = SPRITESET_IDX(1) },
    { .y = 43, .x = 7, .id = SPRITESET_IDX(2) },
    { .y = 49, .x = 6, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_1_Bg0[232] = {
    #include "extracted/data/rooms/brinstar/brinstar_1_bg0.gfx.inc"
};

