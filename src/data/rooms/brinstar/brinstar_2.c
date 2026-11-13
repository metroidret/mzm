#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_2_Scrolls[SCROLL_DATA_SIZE(2)] = {
	2, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 36, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	36, 61, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sBrinstar_2_Clipdata[122] = {
    #include "extracted/data/rooms/brinstar/brinstar_2_clipdata.gfx.inc"
};

const struct SpriteSpawn sBrinstar_2_Spriteset2[7] = {
    { .y = 2, .x = 19, .id = SPRITESET_IDX(0) },
    { .y = 2, .x = 23, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 12, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 16, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 27, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 53, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_2_Bg2[108] = {
    #include "extracted/data/rooms/brinstar/brinstar_2_bg2.gfx.inc"
};

const struct SpriteSpawn sBrinstar_2_Spriteset1[5] = {
    { .y = 2, .x = 19, .id = SPRITESET_IDX(0) },
    { .y = 2, .x = 23, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 27, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 53, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_2_Bg1[653] = {
    #include "extracted/data/rooms/brinstar/brinstar_2_bg1.gfx.inc"
};

const struct SpriteSpawn sBrinstar_2_Spriteset0[5] = {
    { .y = 2, .x = 19, .id = SPRITESET_IDX(0) },
    { .y = 2, .x = 23, .id = SPRITESET_IDX(0) },
    { .y = 3, .x = 27, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 53, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sBrinstar_2_Bg0[128] = {
    #include "extracted/data/rooms/brinstar/brinstar_2_bg0.gfx.inc"
};

