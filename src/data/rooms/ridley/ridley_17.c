#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_10_Scrolls[SCROLL_DATA_SIZE(2)] = {
	17, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 76, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 76, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sRidley_17_Clipdata[346] = {
    #include "extracted/data/rooms/ridley/ridley_17_clipdata.gfx.inc"
};

const struct SpriteSpawn sRidley_17_SpriteLayer2[10] = {
    { .y = 8, .x = 23, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 34, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 57, .id = SPRITESET_IDX(2) },
    { .y = 10, .x = 7, .id = SPRITESET_IDX(4) },
    { .y = 10, .x = 20, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 25, .id = SPRITESET_IDX(4) },
    { .y = 10, .x = 36, .id = SPRITESET_IDX(4) },
    { .y = 10, .x = 49, .id = SPRITESET_IDX(4) },
    { .y = 10, .x = 60, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sRidley_17_Bg2[1131] = {
    #include "extracted/data/rooms/ridley/ridley_17_bg2.gfx.inc"
};

const struct SpriteSpawn sRidley_17_SpriteLayer1[13] = {
    { .y = 8, .x = 23, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 34, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 39, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 47, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 57, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 63, .id = SPRITESET_IDX(2) },
    { .y = 10, .x = 7, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 20, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 25, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 36, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 49, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 60, .id = SPRITESET_IDX(5) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sRidley_17_Bg1[1107] = {
    #include "extracted/data/rooms/ridley/ridley_17_bg1.gfx.inc"
};

const struct SpriteSpawn sRidley_17_SpriteLayer0[13] = {
    { .y = 8, .x = 23, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 34, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 39, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 47, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 57, .id = SPRITESET_IDX(2) },
    { .y = 8, .x = 63, .id = SPRITESET_IDX(2) },
    { .y = 10, .x = 7, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 20, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 25, .id = SPRITESET_IDX(4) },
    { .y = 10, .x = 36, .id = SPRITESET_IDX(5) },
    { .y = 10, .x = 49, .id = SPRITESET_IDX(4) },
    { .y = 10, .x = 60, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sRidley_17_Bg0[466] = {
    #include "extracted/data/rooms/ridley/ridley_17_bg0.gfx.inc"
};

