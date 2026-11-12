#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_11_Scrolls[SCROLL_DATA_SIZE(2)] = {
	22, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 24, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sBrinstar_22_Clipdata[172] = {
    #include "extracted/data/rooms/brinstar/brinstar_22_clipdata.gfx.inc"
};

const u8 sBrinstar_22_Bg2[50] = {
    #include "extracted/data/rooms/brinstar/brinstar_22_bg2.gfx.inc"
};

const struct SpriteDataRom sBrinstar_22_Spriteset1[9] = {
    { .y = 4, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 17, .x = 14, .id = SPRITESET_IDX(0) },
    { .y = 23, .x = 4, .id = SPRITESET_IDX(2) },
    { .y = 23, .x = 5, .id = SPRITESET_IDX(2) },
    { .y = 23, .x = 6, .id = SPRITESET_IDX(2) },
    { .y = 23, .x = 8, .id = SPRITESET_IDX(2) },
    { .y = 23, .x = 9, .id = SPRITESET_IDX(2) },
    { .y = 25, .x = 9, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_22_Bg1[611] = {
    #include "extracted/data/rooms/brinstar/brinstar_22_bg1.gfx.inc"
};

const struct SpriteDataRom sBrinstar_22_Spriteset0[3] = {
    { .y = 5, .x = 11, .id = SPRITESET_IDX(0) },
    { .y = 25, .x = 9, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_22_Bg0[93] = {
    #include "extracted/data/rooms/brinstar/brinstar_22_bg0.gfx.inc"
};

