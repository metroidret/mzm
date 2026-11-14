#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_1_Scrolls[SCROLL_DATA_SIZE(2)] = {
	4, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	9, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sRidley_4_Clipdata[187] = {
    #include "extracted/data/rooms/ridley/ridley_4_clipdata.gfx.inc"
};

const u8 sRidley_4_Bg2[14] = {
    #include "extracted/data/rooms/ridley/ridley_4_bg2.gfx.inc"
};

const u8 sRidley_4_Bg1[435] = {
    #include "extracted/data/rooms/ridley/ridley_4_bg1.gfx.inc"
};

const struct SpriteSpawn sRidley_4_SpriteLayer0[4] = {
    { .y = 5, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 21, .x = 4, .id = SPRITESET_IDX(0) },
    { .y = 21, .x = 14, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sRidley_4_Bg0[78] = {
    #include "extracted/data/rooms/ridley/ridley_4_bg0.gfx.inc"
};

