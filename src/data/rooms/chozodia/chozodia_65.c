#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_39_Scrolls[SCROLL_DATA_SIZE(2)] = {
	65, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	2, 13, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_65_Clipdata[167] = {
    #include "extracted/data/rooms/chozodia/chozodia_65_clipdata.gfx.inc"
};

const u8 sChozodia_65_Bg2[227] = {
    #include "extracted/data/rooms/chozodia/chozodia_65_bg2.gfx.inc"
};

const u8 sChozodia_65_Bg1[586] = {
    #include "extracted/data/rooms/chozodia/chozodia_65_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_65_SpriteLayer0[7] = {
    { .y = 3, .x = 11, .id = SPRITESET_IDX(1) },
    { .y = 4, .x = 5, .id = SPRITESET_IDX(1) },
    { .y = 7, .x = 11, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 4, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 13, .id = SPRITESET_IDX(1) },
    { .y = 14, .x = 5, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_65_Bg0[41] = {
    #include "extracted/data/rooms/chozodia/chozodia_65_bg0.gfx.inc"
};

