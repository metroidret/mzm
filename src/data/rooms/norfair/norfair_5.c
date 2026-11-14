#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_2_Scrolls[SCROLL_DATA_SIZE(5)] = {
	5, // Room
	5, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	11, 50, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 16, // X bounds
	60, 121, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 3
	2, 16, // X bounds
	49, 62, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 4
	15, 29, // X bounds
	2, 121, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sNorfair_5_Clipdata[1592] = {
    #include "extracted/data/rooms/norfair/norfair_5_clipdata.gfx.inc"
};

const u8 sNorfair_5_Bg2[2172] = {
    #include "extracted/data/rooms/norfair/norfair_5_bg2.gfx.inc"
};

const struct SpriteSpawn sNorfair_5_SpriteLayer1[14] = {
    { .y = 8, .x = 11, .id = SPRITESET_IDX(0) },
    { .y = 8, .x = 14, .id = SPRITESET_IDX(2) },
    { .y = 18, .x = 14, .id = SPRITESET_IDX(0) },
    { .y = 21, .x = 6, .id = SPRITESET_IDX(0) },
    { .y = 30, .x = 10, .id = SPRITESET_IDX(2) },
    { .y = 34, .x = 14, .id = SPRITESET_IDX(2) },
    { .y = 44, .x = 13, .id = SPRITESET_IDX(2) },
    { .y = 66, .x = 3, .id = SPRITESET_IDX(0) },
    { .y = 82, .x = 4, .id = SPRITESET_IDX(0) },
    { .y = 88, .x = 9, .id = SPRITESET_IDX(3) },
    { .y = 95, .x = 7, .id = SPRITESET_IDX(1) },
    { .y = 114, .x = 23, .id = SPRITESET_IDX(4) },
    { .y = 115, .x = 6, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_5_Bg1[2886] = {
    #include "extracted/data/rooms/norfair/norfair_5_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_5_SpriteLayer0[13] = {
    { .y = 6, .x = 12, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 12, .id = SPRITESET_IDX(0) },
    { .y = 18, .x = 14, .id = SPRITESET_IDX(0) },
    { .y = 21, .x = 6, .id = SPRITESET_IDX(0) },
    { .y = 34, .x = 14, .id = SPRITESET_IDX(2) },
    { .y = 45, .x = 14, .id = SPRITESET_IDX(0) },
    { .y = 66, .x = 3, .id = SPRITESET_IDX(0) },
    { .y = 82, .x = 4, .id = SPRITESET_IDX(0) },
    { .y = 88, .x = 9, .id = SPRITESET_IDX(3) },
    { .y = 95, .x = 7, .id = SPRITESET_IDX(1) },
    { .y = 114, .x = 23, .id = SPRITESET_IDX(4) },
    { .y = 115, .x = 6, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_5_Bg0[363] = {
    #include "extracted/data/rooms/norfair/norfair_5_bg0.gfx.inc"
};

