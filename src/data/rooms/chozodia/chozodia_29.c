#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_19_Scrolls[SCROLL_DATA_SIZE(2)] = {
	29, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 34, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	32, 46, // X bounds
	4, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_29_Clipdata[335] = {
    #include "extracted/data/rooms/chozodia/chozodia_29_clipdata.gfx.inc"
};

const u8 sChozodia_29_Bg2[385] = {
    #include "extracted/data/rooms/chozodia/chozodia_29_bg2.gfx.inc"
};

const struct SpriteDataRom sChozodia_29_Spriteset1[7] = {
    { .y = 9, .x = 40, .id = SPRITESET_IDX(0) },
    { .y = 15, .x = 41, .id = SPRITESET_IDX(2) },
    { .y = 20, .x = 40, .id = SPRITESET_IDX(0) },
    { .y = 25, .x = 37, .id = SPRITESET_IDX(0) },
    { .y = 29, .x = 20, .id = SPRITESET_IDX(0) },
    { .y = 30, .x = 5, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_29_Bg1[964] = {
    #include "extracted/data/rooms/chozodia/chozodia_29_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_29_Spriteset0[2] = {
    { .y = 15, .x = 41, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_29_Bg0[159] = {
    #include "extracted/data/rooms/chozodia/chozodia_29_bg0.gfx.inc"
};

