#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_11_Scrolls[SCROLL_DATA_SIZE(1)] = {
	17, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	11, 22, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_17_Clipdata[145] = {
    #include "extracted/data/rooms/chozodia/chozodia_17_clipdata.gfx.inc"
};

const u8 sChozodia_17_Bg2[271] = {
    #include "extracted/data/rooms/chozodia/chozodia_17_bg2.gfx.inc"
};

const struct SpriteDataRom sChozodia_17_Spriteset1[2] = {
    { .y = 16, .x = 9, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_17_Bg1[364] = {
    #include "extracted/data/rooms/chozodia/chozodia_17_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_17_Spriteset0[2] = {
    { .y = 16, .x = 9, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

