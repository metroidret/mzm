#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_17_Scrolls[SCROLL_DATA_SIZE(1)] = {
	31, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	3, 19, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sBrinstar_31_Clipdata[136] = {
    #include "extracted/data/rooms/brinstar/brinstar_31_clipdata.gfx.inc"
};

const u8 sBrinstar_31_Bg2[95] = {
    #include "extracted/data/rooms/brinstar/brinstar_31_bg2.gfx.inc"
};

const u8 sBrinstar_31_Bg1[408] = {
    #include "extracted/data/rooms/brinstar/brinstar_31_bg1.gfx.inc"
};

const struct SpriteDataRom sBrinstar_31_Spriteset0[5] = {
    { .y = 10, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 15, .x = 7, .id = SPRITESET_IDX(0) },
    { .y = 17, .x = 8, .id = SPRITESET_IDX(0) },
    { .y = 17, .x = 10, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

