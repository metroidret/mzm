#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_6_Scrolls[SCROLL_DATA_SIZE(4)] = {
	20, // Room
	4, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 22, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	21, 40, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 16, // X bounds
	39, 50, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 3
	2, 16, // X bounds
	50, 61, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sNorfair_20_Clipdata[] = {
    #include "extracted/data/rooms/norfair/norfair_20_clipdata.gfx.inc"
};

const u8 sNorfair_20_Bg2[724] = {
    #include "extracted/data/rooms/norfair/norfair_20_bg2.gfx.inc"
};

const u8 sNorfair_20_Bg1[] = {
    #include "extracted/data/rooms/norfair/norfair_20_bg1.gfx.inc"
};

const struct SpriteDataRom sNorfair_20_Spriteset0[9] = {
    { .y = 8, .x = 8, .id = SPRITESET_IDX(0) },
    { .y = 10, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 13, .x = 9, .id = SPRITESET_IDX(3) },
    { .y = 24, .x = 6, .id = SPRITESET_IDX(0) },
    { .y = 24, .x = 7, .id = SPRITESET_IDX(0) },
    { .y = 30, .x = 5, .id = SPRITESET_IDX(2) },
    { .y = 30, .x = 12, .id = SPRITESET_IDX(2) },
    { .y = 34, .x = 9, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_20_Bg0[] = {
    #include "extracted/data/rooms/norfair/norfair_20_bg0.gfx.inc"
};

