#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_25_Scrolls[SCROLL_DATA_SIZE(3)] = {
	39, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 61, // X bounds
	2, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	61, 76, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 76, // X bounds
	10, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_39_Clipdata[432] = {
    #include "extracted/data/rooms/chozodia/chozodia_39_clipdata.gfx.inc"
};

const u8 sChozodia_39_Bg2[677] = {
    #include "extracted/data/rooms/chozodia/chozodia_39_bg2.gfx.inc"
};

const u8 sChozodia_39_Bg1[1598] = {
    #include "extracted/data/rooms/chozodia/chozodia_39_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_39_Spriteset0[7] = {
    { .y = 8, .x = 61, .id = SPRITESET_IDX(4) },
    { .y = 19, .x = 47, .id = SPRITESET_IDX(3) },
    { .y = 26, .x = 16, .id = SPRITESET_IDX(0) },
    { .y = 26, .x = 30, .id = SPRITESET_IDX(0) },
    { .y = 26, .x = 44, .id = SPRITESET_IDX(0) },
    { .y = 26, .x = 76, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

