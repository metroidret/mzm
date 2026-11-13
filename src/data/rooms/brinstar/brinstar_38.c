#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_18_Scrolls[SCROLL_DATA_SIZE(2)] = {
	38, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sBrinstar_38_Clipdata[153] = {
    #include "extracted/data/rooms/brinstar/brinstar_38_clipdata.gfx.inc"
};

const u8 sBrinstar_38_Bg2[102] = {
    #include "extracted/data/rooms/brinstar/brinstar_38_bg2.gfx.inc"
};

const struct SpriteSpawn sBrinstar_38_Spriteset1[7] = {
    { .y = 3, .x = 15, .id = SPRITESET_IDX(1) },
    { .y = 3, .x = 19, .id = SPRITESET_IDX(1) },
    { .y = 3, .x = 37, .id = SPRITESET_IDX(1) },
    { .y = 3, .x = 40, .id = SPRITESET_IDX(1) },
    { .y = 6, .x = 30, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 5, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_38_Bg1[578] = {
    #include "extracted/data/rooms/brinstar/brinstar_38_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_38_Spriteset0[5] = {
    { .y = 3, .x = 19, .id = SPRITESET_IDX(1) },
    { .y = 3, .x = 37, .id = SPRITESET_IDX(1) },
    { .y = 3, .x = 40, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 5, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_38_Bg0[213] = {
    #include "extracted/data/rooms/brinstar/brinstar_38_bg0.gfx.inc"
};

