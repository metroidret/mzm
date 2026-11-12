#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_1_Scrolls[SCROLL_DATA_SIZE(2)] = {
	3, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 17, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	16, 46, // X bounds
	2, 18, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_3_Clipdata[258] = {
    #include "extracted/data/rooms/chozodia/chozodia_3_clipdata.gfx.inc"
};

const u8 sChozodia_3_Bg2[370] = {
    #include "extracted/data/rooms/chozodia/chozodia_3_bg2.gfx.inc"
};

const u8 sChozodia_3_Bg1[725] = {
    #include "extracted/data/rooms/chozodia/chozodia_3_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_3_Spriteset0[8] = {
    { .y = 6, .x = 2, .id = SPRITESET_IDX(1) },
    { .y = 6, .x = 9, .id = SPRITESET_IDX(6) },
    { .y = 10, .x = 13, .id = SPRITESET_IDX(6) },
    { .y = 16, .x = 25, .id = SPRITESET_IDX(9) },
    { .y = 16, .x = 30, .id = SPRITESET_IDX(9) },
    { .y = 16, .x = 35, .id = SPRITESET_IDX(9) },
    { .y = 16, .x = 46, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_3_Bg0[17] = {
    #include "extracted/data/rooms/chozodia/chozodia_3_bg0.gfx.inc"
};

