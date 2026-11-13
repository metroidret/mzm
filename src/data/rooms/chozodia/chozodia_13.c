#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_9_Scrolls[SCROLL_DATA_SIZE(5)] = {
	13, // Room
	5, // Number of scrolls
	
	// Scroll 0
	2, 17, // X bounds
	31, 65, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	65, 75, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 31, // X bounds
	70, 81, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 3
	15, 31, // X bounds
	31, 50, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 4
	2, 31, // X bounds
	11, 32, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_13_Clipdata[680] = {
    #include "extracted/data/rooms/chozodia/chozodia_13_clipdata.gfx.inc"
};

const struct SpriteDataRom sChozodia_13_Spriteset2[4] = {
    { .y = 15, .x = 20, .id = SPRITESET_IDX(4) },
    { .y = 21, .x = 14, .id = SPRITESET_IDX(4) },
    { .y = 23, .x = 24, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_13_Bg2[1468] = {
    #include "extracted/data/rooms/chozodia/chozodia_13_bg2.gfx.inc"
};

const struct SpriteDataRom sChozodia_13_Spriteset1[8] = {
    { .y = 23, .x = 9, .id = SPRITESET_IDX(4) },
    { .y = 23, .x = 20, .id = SPRITESET_IDX(4) },
    { .y = 30, .x = 17, .id = SPRITESET_IDX(3) },
    { .y = 36, .x = 8, .id = SPRITESET_IDX(3) },
    { .y = 46, .x = 11, .id = SPRITESET_IDX(4) },
    { .y = 75, .x = 18, .id = SPRITESET_IDX(4) },
    { .y = 80, .x = 19, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_13_Bg1[1694] = {
    #include "extracted/data/rooms/chozodia/chozodia_13_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_13_Spriteset0[3] = {
    { .y = 80, .x = 19, .id = SPRITESET_IDX(0) },
    { .y = 80, .x = 30, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_13_Bg0[187] = {
    #include "extracted/data/rooms/chozodia/chozodia_13_bg0.gfx.inc"
};

