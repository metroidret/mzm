#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_12_Scrolls[SCROLL_DATA_SIZE(2)] = {
	23, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 61, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 61, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sBrinstar_23_Clipdata[312] = {
    #include "extracted/data/rooms/brinstar/brinstar_23_clipdata.gfx.inc"
};

const u8 sBrinstar_23_Bg2[82] = {
    #include "extracted/data/rooms/brinstar/brinstar_23_bg2.gfx.inc"
};

const u8 sBrinstar_23_Bg1[732] = {
    #include "extracted/data/rooms/brinstar/brinstar_23_bg1.gfx.inc"
};

const struct SpriteDataRom sBrinstar_23_Spriteset0[17] = {
    { .y = 2, .x = 15, .id = SPRITESET_IDX(6) },
    { .y = 2, .x = 16, .id = SPRITESET_IDX(6) },
    { .y = 2, .x = 48, .id = SPRITESET_IDX(6) },
    { .y = 2, .x = 49, .id = SPRITESET_IDX(6) },
    { .y = 2, .x = 50, .id = SPRITESET_IDX(6) },
    { .y = 3, .x = 48, .id = SPRITESET_IDX(6) },
    { .y = 3, .x = 49, .id = SPRITESET_IDX(6) },
    { .y = 3, .x = 50, .id = SPRITESET_IDX(6) },
    { .y = 3, .x = 51, .id = SPRITESET_IDX(6) },
    { .y = 4, .x = 15, .id = SPRITESET_IDX(6) },
    { .y = 4, .x = 16, .id = SPRITESET_IDX(6) },
    { .y = 4, .x = 17, .id = SPRITESET_IDX(6) },
    { .y = 4, .x = 18, .id = SPRITESET_IDX(6) },
    { .y = 7, .x = 52, .id = SPRITESET_IDX(7) },
    { .y = 7, .x = 55, .id = SPRITESET_IDX(3) },
    { .y = 9, .x = 13, .id = SPRITESET_IDX(4) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_23_Bg0[669] = {
    #include "extracted/data/rooms/brinstar/brinstar_23_bg0.gfx.inc"
};

