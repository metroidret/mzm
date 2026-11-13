#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_20_Scrolls[SCROLL_DATA_SIZE(1)] = {
	30, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 39, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_30_Clipdata[293] = {
    #include "extracted/data/rooms/chozodia/chozodia_30_clipdata.gfx.inc"
};

const u8 sChozodia_30_Bg2[184] = {
    #include "extracted/data/rooms/chozodia/chozodia_30_bg2.gfx.inc"
};

const u8 sChozodia_30_Bg1[828] = {
    #include "extracted/data/rooms/chozodia/chozodia_30_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_30_SpriteLayer0[5] = {
    { .y = 17, .x = 15, .id = SPRITESET_IDX(7) },
    { .y = 18, .x = 15, .id = SPRITESET_IDX(6) },
    { .y = 31, .x = 6, .id = SPRITESET_IDX(6) },
    { .y = 38, .x = 2, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_30_Bg0[26] = {
    #include "extracted/data/rooms/chozodia/chozodia_30_bg0.gfx.inc"
};

