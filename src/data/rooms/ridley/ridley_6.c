#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_2_Scrolls[SCROLL_DATA_SIZE(2)] = {
	6, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 61, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	59, 71, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sRidley_6_Clipdata[491] = {
    #include "extracted/data/rooms/ridley/ridley_6_clipdata.gfx.inc"
};

const u8 sRidley_6_Bg2[14] = {
    #include "extracted/data/rooms/ridley/ridley_6_bg2.gfx.inc"
};

const u8 sRidley_6_Bg1[997] = {
    #include "extracted/data/rooms/ridley/ridley_6_bg1.gfx.inc"
};

const struct SpriteSpawn sRidley_6_Spriteset0[7] = {
    { .y = 8, .x = 5, .id = SPRITESET_IDX(0) },
    { .y = 12, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 13, .x = 6, .id = SPRITESET_IDX(0) },
    { .y = 19, .x = 7, .id = SPRITESET_IDX(1) },
    { .y = 31, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 59, .x = 3, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sRidley_6_Bg0[211] = {
    #include "extracted/data/rooms/ridley/ridley_6_bg0.gfx.inc"
};

