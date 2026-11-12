#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_58_Scrolls[SCROLL_DATA_SIZE(1)] = {
	97, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	1, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_97_Clipdata[135] = {
    #include "extracted/data/rooms/chozodia/chozodia_97_clipdata.gfx.inc"
};

const u8 sChozodia_97_Bg1[177] = {
    #include "extracted/data/rooms/chozodia/chozodia_97_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_97_Spriteset0[2] = {
    { .y = 8, .x = 2, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

