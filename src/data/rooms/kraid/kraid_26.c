#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_7_Scrolls[SCROLL_DATA_SIZE(2)] = {
	26, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 32, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	30, 81, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sKraid_26_Clipdata[415] = {
    #include "extracted/data/rooms/kraid/kraid_26_clipdata.gfx.inc"
};

const u8 sKraid_26_Bg2[545] = {
    #include "extracted/data/rooms/kraid/kraid_26_bg2.gfx.inc"
};

const struct SpriteSpawn sKraid_26_Spriteset1[8] = {
    { .y = 20, .x = 11, .id = SPRITESET_IDX(4) },
    { .y = 24, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 28, .x = 8, .id = SPRITESET_IDX(4) },
    { .y = 32, .x = 10, .id = SPRITESET_IDX(1) },
    { .y = 34, .x = 5, .id = SPRITESET_IDX(1) },
    { .y = 72, .x = 11, .id = SPRITESET_IDX(4) },
    { .y = 74, .x = 9, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_26_Bg1[1009] = {
    #include "extracted/data/rooms/kraid/kraid_26_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_26_Spriteset0[7] = {
    { .y = 20, .x = 11, .id = SPRITESET_IDX(0) },
    { .y = 24, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 28, .x = 8, .id = SPRITESET_IDX(0) },
    { .y = 32, .x = 10, .id = SPRITESET_IDX(1) },
    { .y = 72, .x = 11, .id = SPRITESET_IDX(0) },
    { .y = 74, .x = 9, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_26_Bg0[712] = {
    #include "extracted/data/rooms/kraid/kraid_26_bg0.gfx.inc"
};

