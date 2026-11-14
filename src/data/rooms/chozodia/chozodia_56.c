#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_37_Scrolls[SCROLL_DATA_SIZE(1)] = {
	56, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 39, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_56_Clipdata[301] = {
    #include "extracted/data/rooms/chozodia/chozodia_56_clipdata.gfx.inc"
};

const u8 sChozodia_56_Bg2[166] = {
    #include "extracted/data/rooms/chozodia/chozodia_56_bg2.gfx.inc"
};

const u8 sChozodia_56_Bg1[837] = {
    #include "extracted/data/rooms/chozodia/chozodia_56_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_56_SpriteLayer0[8] = {
    { .y = 11, .x = 14, .id = SPRITESET_IDX(3) },
    { .y = 17, .x = 15, .id = SPRITESET_IDX(7) },
    { .y = 18, .x = 15, .id = SPRITESET_IDX(6) },
    { .y = 26, .x = 13, .id = SPRITESET_IDX(3) },
    { .y = 31, .x = 6, .id = SPRITESET_IDX(6) },
    { .y = 38, .x = 2, .id = SPRITESET_IDX(1) },
    { .y = 38, .x = 9, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_56_Bg0[26] = {
    #include "extracted/data/rooms/chozodia/chozodia_56_bg0.gfx.inc"
};

