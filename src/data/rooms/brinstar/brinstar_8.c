#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_3_Scrolls[SCROLL_DATA_SIZE(2)] = {
	8, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	3, // Breakable block direction
	21, // Breakable block Y bound extension

	// Scroll 1
	15, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sBrinstar_8_Clipdata[143] = {
    #include "extracted/data/rooms/brinstar/brinstar_8_clipdata.gfx.inc"
};

const u8 sBrinstar_8_Bg2[196] = {
    #include "extracted/data/rooms/brinstar/brinstar_8_bg2.gfx.inc"
};

const struct SpriteSpawn sBrinstar_8_SpriteLayer1[6] = {
    { .y = 6, .x = 25, .id = SPRITESET_IDX(2) },
    { .y = 6, .x = 28, .id = SPRITESET_IDX(2) },
    { .y = 7, .x = 16, .id = SPRITESET_IDX(2) },
    { .y = 9, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 15, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_8_Bg1[407] = {
    #include "extracted/data/rooms/brinstar/brinstar_8_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_8_SpriteLayer0[3] = {
    { .y = 9, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 15, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_8_Bg0[205] = {
    #include "extracted/data/rooms/brinstar/brinstar_8_bg0.gfx.inc"
};

