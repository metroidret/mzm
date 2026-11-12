#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_0_Scrolls[SCROLL_DATA_SIZE(1)] = {
	2, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	4, 20, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_2_Clipdata[251] = {
    #include "extracted/data/rooms/chozodia/chozodia_2_clipdata.gfx.inc"
};

const u8 sChozodia_2_Bg2[314] = {
    #include "extracted/data/rooms/chozodia/chozodia_2_bg2.gfx.inc"
};

const u8 sChozodia_2_Bg1[778] = {
    #include "extracted/data/rooms/chozodia/chozodia_2_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_2_Spriteset0[4] = {
    { .y = 9, .x = 23, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 30, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 35, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_2_Bg0[23] = {
    #include "extracted/data/rooms/chozodia/chozodia_2_bg0.gfx.inc"
};

