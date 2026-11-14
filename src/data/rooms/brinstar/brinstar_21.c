#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_10_Scrolls[SCROLL_DATA_SIZE(2)] = {
	21, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 76, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	33, 76, // X bounds
	11, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sBrinstar_21_Clipdata[241] = {
    #include "extracted/data/rooms/brinstar/brinstar_21_clipdata.gfx.inc"
};

const u8 sBrinstar_21_Bg2[174] = {
    #include "extracted/data/rooms/brinstar/brinstar_21_bg2.gfx.inc"
};

const struct SpriteSpawn sBrinstar_21_SpriteLayer1[9] = {
    { .y = 8, .x = 64, .id = SPRITESET_IDX(3) },
    { .y = 8, .x = 65, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 66, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 67, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 68, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 69, .id = SPRITESET_IDX(2) },
    { .y = 11, .x = 21, .id = SPRITESET_IDX(0) },
    { .y = 19, .x = 59, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_21_Bg1[1038] = {
    #include "extracted/data/rooms/brinstar/brinstar_21_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_21_SpriteLayer0[4] = {
    { .y = 8, .x = 64, .id = SPRITESET_IDX(3) },
    { .y = 11, .x = 21, .id = SPRITESET_IDX(0) },
    { .y = 19, .x = 59, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_21_Bg0[394] = {
    #include "extracted/data/rooms/brinstar/brinstar_21_bg0.gfx.inc"
};

