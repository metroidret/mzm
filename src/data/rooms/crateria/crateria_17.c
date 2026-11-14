#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_8_Scrolls[SCROLL_DATA_SIZE(1)] = {
	17, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sCrateria_17_Clipdata[223] = {
    #include "extracted/data/rooms/crateria/crateria_17_clipdata.gfx.inc"
};

const u8 sCrateria_17_Bg2[527] = {
    #include "extracted/data/rooms/crateria/crateria_17_bg2.gfx.inc"
};

const u8 sCrateria_17_Bg1[735] = {
    #include "extracted/data/rooms/crateria/crateria_17_bg1.gfx.inc"
};

const struct SpriteSpawn sCrateria_17_SpriteLayer0[2] = {
    { .y = 40, .x = 13, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

