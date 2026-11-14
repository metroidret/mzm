#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_42_Scrolls[SCROLL_DATA_SIZE(2)] = {
	71, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 61, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_71_Clipdata[186] = {
    #include "extracted/data/rooms/chozodia/chozodia_71_clipdata.gfx.inc"
};

const u8 sChozodia_71_Bg2[499] = {
    #include "extracted/data/rooms/chozodia/chozodia_71_bg2.gfx.inc"
};

const u8 sChozodia_71_Bg1[727] = {
    #include "extracted/data/rooms/chozodia/chozodia_71_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_71_SpriteLayer0[19] = {
    { .y = 7, .x = 2, .id = SPRITESET_IDX(1) },
    { .y = 8, .x = 2, .id = SPRITESET_IDX(1) },
    { .y = 13, .x = 13, .id = SPRITESET_IDX(9) },
    { .y = 13, .x = 18, .id = SPRITESET_IDX(9) },
    { .y = 15, .x = 27, .id = SPRITESET_IDX(8) },
    { .y = 15, .x = 36, .id = SPRITESET_IDX(8) },
    { .y = 15, .x = 44, .id = SPRITESET_IDX(9) },
    { .y = 15, .x = 49, .id = SPRITESET_IDX(9) },
    { .y = 19, .x = 57, .id = SPRITESET_IDX(4) },
    { .y = 20, .x = 10, .id = SPRITESET_IDX(7) },
    { .y = 20, .x = 15, .id = SPRITESET_IDX(9) },
    { .y = 20, .x = 20, .id = SPRITESET_IDX(9) },
    { .y = 20, .x = 25, .id = SPRITESET_IDX(9) },
    { .y = 20, .x = 30, .id = SPRITESET_IDX(9) },
    { .y = 20, .x = 35, .id = SPRITESET_IDX(9) },
    { .y = 20, .x = 40, .id = SPRITESET_IDX(9) },
    { .y = 20, .x = 45, .id = SPRITESET_IDX(9) },
    { .y = 20, .x = 50, .id = SPRITESET_IDX(9) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_71_Bg0[17] = {
    #include "extracted/data/rooms/chozodia/chozodia_71_bg0.gfx.inc"
};

