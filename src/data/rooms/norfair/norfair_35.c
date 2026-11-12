#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_13_Scrolls[SCROLL_DATA_SIZE(2)] = {
	35, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	3, // Breakable block direction
	21, // Breakable block Y bound extension

	// Scroll 1
	16, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sNorfair_35_Clipdata[159] = {
    #include "extracted/data/rooms/norfair/norfair_35_clipdata.gfx.inc"
};

const u8 sNorfair_35_Bg2[183] = {
    #include "extracted/data/rooms/norfair/norfair_35_bg2.gfx.inc"
};

const u8 sNorfair_35_Bg1[601] = {
    #include "extracted/data/rooms/norfair/norfair_35_bg1.gfx.inc"
};

const struct SpriteDataRom sNorfair_35_Spriteset0[4] = {
    { .y = 9, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 15, .id = SPRITESET_IDX(1) },
    { .y = 11, .x = 24, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

