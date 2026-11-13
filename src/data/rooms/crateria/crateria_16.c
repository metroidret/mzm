#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_7_Scrolls[SCROLL_DATA_SIZE(1)] = {
	16, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sCrateria_16_Clipdata[241] = {
    #include "extracted/data/rooms/crateria/crateria_16_clipdata.gfx.inc"
};

const u8 sCrateria_16_Bg2[397] = {
    #include "extracted/data/rooms/crateria/crateria_16_bg2.gfx.inc"
};

const u8 sCrateria_16_Bg1[759] = {
    #include "extracted/data/rooms/crateria/crateria_16_bg1.gfx.inc"
};

const struct SpriteSpawn sCrateria_16_Spriteset0[2] = {
    { .y = 40, .x = 13, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sCrateria_16_Bg0[247] = {
    #include "extracted/data/rooms/crateria/crateria_16_bg0.gfx.inc"
};

