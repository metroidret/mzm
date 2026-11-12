#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_8_Scrolls[SCROLL_DATA_SIZE(2)] = {
	23, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 21, // Y bounds
	7, 16, // Breakable block position
	2, // Breakable block direction
	2, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	20, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sNorfair_23_Clipdata[295] = {
    #include "extracted/data/rooms/norfair/norfair_23_clipdata.gfx.inc"
};

const u8 sNorfair_23_Bg2[381] = {
    #include "extracted/data/rooms/norfair/norfair_23_bg2.gfx.inc"
};

const struct SpriteDataRom sNorfair_23_Spriteset1[6] = {
    { .y = 17, .x = 8, .id = SPRITESET_IDX(1) },
    { .y = 26, .x = 6, .id = SPRITESET_IDX(1) },
    { .y = 30, .x = 9, .id = SPRITESET_IDX(4) },
    { .y = 33, .x = 9, .id = SPRITESET_IDX(1) },
    { .y = 35, .x = 5, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_23_Bg1[637] = {
    #include "extracted/data/rooms/norfair/norfair_23_bg1.gfx.inc"
};

const struct SpriteDataRom sNorfair_23_Spriteset0[5] = {
    { .y = 17, .x = 8, .id = SPRITESET_IDX(0) },
    { .y = 26, .x = 6, .id = SPRITESET_IDX(0) },
    { .y = 33, .x = 9, .id = SPRITESET_IDX(1) },
    { .y = 35, .x = 5, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

