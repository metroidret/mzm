#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_3_Scrolls[SCROLL_DATA_SIZE(2)] = {
	7, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 13, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 61, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sKraid_7_Clipdata[246] = {
    #include "extracted/data/rooms/kraid/kraid_7_clipdata.gfx.inc"
};

const u8 sKraid_7_Bg2[259] = {
    #include "extracted/data/rooms/kraid/kraid_7_bg2.gfx.inc"
};

const struct SpriteDataRom sKraid_7_Spriteset1[2] = {
    { .y = 9, .x = 6, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_7_Bg1[684] = {
    #include "extracted/data/rooms/kraid/kraid_7_bg1.gfx.inc"
};

const struct SpriteDataRom sKraid_7_Spriteset0[3] = {
    { .y = 9, .x = 6, .id = SPRITESET_IDX(0) },
    { .y = 18, .x = 17, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_7_Bg0[70] = {
    #include "extracted/data/rooms/kraid/kraid_7_bg0.gfx.inc"
};

