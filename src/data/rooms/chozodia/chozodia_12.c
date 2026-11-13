#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_8_Scrolls[SCROLL_DATA_SIZE(2)] = {
	12, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	5, 42, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	42, 51, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_12_Clipdata[276] = {
    #include "extracted/data/rooms/chozodia/chozodia_12_clipdata.gfx.inc"
};

const u8 sChozodia_12_Bg2[372] = {
    #include "extracted/data/rooms/chozodia/chozodia_12_bg2.gfx.inc"
};

const u8 sChozodia_12_Bg1[684] = {
    #include "extracted/data/rooms/chozodia/chozodia_12_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_12_Spriteset0[3] = {
    { .y = 40, .x = 8, .id = SPRITESET_IDX(2) },
    { .y = 49, .x = 14, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

