#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_0_Scrolls[SCROLL_DATA_SIZE(1)] = {
	0, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	2, // Breakable block direction
	2, // Breakable block Y bound extension
};

const u8 sTourian_0_Clipdata[158] = {
    #include "extracted/data/rooms/tourian/tourian_0_clipdata.gfx.inc"
};

const u8 sTourian_0_Bg2[178] = {
    #include "extracted/data/rooms/tourian/tourian_0_bg2.gfx.inc"
};

const u8 sTourian_0_Bg1[445] = {
    #include "extracted/data/rooms/tourian/tourian_0_bg1.gfx.inc"
};

const struct SpriteDataRom sTourian_0_Spriteset0[2] = {
    { .y = 15, .x = 9, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

