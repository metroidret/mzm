#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_24_Scrolls[SCROLL_DATA_SIZE(3)] = {
	34, // Room
	3, // Number of scrolls
	
	// Scroll 0
	17, 31, // X bounds
	14, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	31, 46, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_34_Clipdata[221] = {
    #include "extracted/data/rooms/chozodia/chozodia_34_clipdata.gfx.inc"
};

const u8 sChozodia_34_Bg2[224] = {
    #include "extracted/data/rooms/chozodia/chozodia_34_bg2.gfx.inc"
};

const struct SpriteSpawn sChozodia_34_Spriteset1[5] = {
    { .y = 18, .x = 24, .id = SPRITESET_IDX(3) },
    { .y = 24, .x = 24, .id = SPRITESET_IDX(3) },
    { .y = 24, .x = 26, .id = SPRITESET_IDX(4) },
    { .y = 30, .x = 22, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_34_Bg1[922] = {
    #include "extracted/data/rooms/chozodia/chozodia_34_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_34_Spriteset0[2] = {
    { .y = 24, .x = 26, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_34_Bg0[42] = {
    #include "extracted/data/rooms/chozodia/chozodia_34_bg0.gfx.inc"
};

