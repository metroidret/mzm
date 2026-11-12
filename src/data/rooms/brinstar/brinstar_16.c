#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_9_Scrolls[SCROLL_DATA_SIZE(2)] = {
	16, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	9, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sBrinstar_16_Clipdata[191] = {
    #include "extracted/data/rooms/brinstar/brinstar_16_clipdata.gfx.inc"
};

const u8 sBrinstar_16_Bg2[40] = {
    #include "extracted/data/rooms/brinstar/brinstar_16_bg2.gfx.inc"
};

const u8 sBrinstar_16_Bg1[514] = {
    #include "extracted/data/rooms/brinstar/brinstar_16_bg1.gfx.inc"
};

const struct SpriteDataRom sBrinstar_16_Spriteset0[13] = {
    { .y = 2, .x = 4, .id = SPRITESET_IDX(5) },
    { .y = 2, .x = 5, .id = SPRITESET_IDX(5) },
    { .y = 2, .x = 6, .id = SPRITESET_IDX(5) },
    { .y = 2, .x = 12, .id = SPRITESET_IDX(5) },
    { .y = 2, .x = 13, .id = SPRITESET_IDX(5) },
    { .y = 2, .x = 14, .id = SPRITESET_IDX(5) },
    { .y = 11, .x = 8, .id = SPRITESET_IDX(1) },
    { .y = 14, .x = 12, .id = SPRITESET_IDX(0) },
    { .y = 17, .x = 8, .id = SPRITESET_IDX(0) },
    { .y = 21, .x = 9, .id = SPRITESET_IDX(2) },
    { .y = 23, .x = 10, .id = SPRITESET_IDX(1) },
    { .y = 26, .x = 11, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

