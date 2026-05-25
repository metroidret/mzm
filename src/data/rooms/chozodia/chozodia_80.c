#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_46_Scrolls[SCROLL_DATA_SIZE(1)] = {
	80, // Room
	1, // Number of scrolls
	
	// Scroll 0
	17, 31, // X bounds
	1, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_80_Clipdata[155] = {
    #include "extracted/data/rooms/chozodia/chozodia_80_clipdata.gfx.inc"
};

const u8 sChozodia_80_Bg2[140] = {
    #include "extracted/data/rooms/chozodia/chozodia_80_bg2.gfx.inc"
};

const u8 sChozodia_80_Bg1[321] = {
    #include "extracted/data/rooms/chozodia/chozodia_80_bg1.gfx.inc"
};

const u8 sChozodia_80_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_80_Bg0[67] = {
    #include "extracted/data/rooms/chozodia/chozodia_80_bg0.gfx.inc"
};

