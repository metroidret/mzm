#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_29_Scrolls[SCROLL_DATA_SIZE(1)] = {
	47, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	3, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_47_Clipdata[149] = {
    #include "extracted/data/rooms/chozodia/chozodia_47_clipdata.gfx.inc"
};

const u8 sChozodia_47_Bg1[316] = {
    #include "extracted/data/rooms/chozodia/chozodia_47_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_47_Spriteset0[8] = {
    { .y = 14, .x = 7, .id = SPRITESET_IDX(8) },
    { .y = 14, .x = 11, .id = SPRITESET_IDX(8) },
    { .y = 19, .x = 2, .id = SPRITESET_IDX(1) },
    { .y = 19, .x = 7, .id = SPRITESET_IDX(6) },
    { .y = 19, .x = 11, .id = SPRITESET_IDX(8) },
    { .y = 20, .x = 2, .id = SPRITESET_IDX(1) },
    { .y = 20, .x = 16, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_47_Bg0[17] = {
    #include "extracted/data/rooms/chozodia/chozodia_47_bg0.gfx.inc"
};

