#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_10_Scrolls[SCROLL_DATA_SIZE(2)] = {
	14, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	6, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	2, 17, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_14_Clipdata[286] = {
    #include "extracted/data/rooms/chozodia/chozodia_14_clipdata.gfx.inc"
};

const u8 sChozodia_14_Bg2[368] = {
    #include "extracted/data/rooms/chozodia/chozodia_14_bg2.gfx.inc"
};

const struct SpriteSpawn sChozodia_14_SpriteLayer1[6] = {
    { .y = 10, .x = 6, .id = SPRITESET_IDX(5) },
    { .y = 16, .x = 11, .id = SPRITESET_IDX(0) },
    { .y = 20, .x = 6, .id = SPRITESET_IDX(0) },
    { .y = 28, .x = 11, .id = SPRITESET_IDX(3) },
    { .y = 39, .x = 7, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_14_Bg1[776] = {
    #include "extracted/data/rooms/chozodia/chozodia_14_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_14_SpriteLayer0[3] = {
    { .y = 10, .x = 6, .id = SPRITESET_IDX(5) },
    { .y = 20, .x = 6, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_14_Bg0[185] = {
    #include "extracted/data/rooms/chozodia/chozodia_14_bg0.gfx.inc"
};

