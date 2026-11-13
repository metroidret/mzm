#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_8_Scrolls[SCROLL_DATA_SIZE(2)] = {
	15, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 61, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	17, 31, // X bounds
	22, 51, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sRidley_15_Clipdata[516] = {
    #include "extracted/data/rooms/ridley/ridley_15_clipdata.gfx.inc"
};

const struct SpriteSpawn sRidley_15_SpriteLayer2[6] = {
    { .y = 22, .x = 8, .id = SPRITESET_IDX(3) },
    { .y = 32, .x = 13, .id = SPRITESET_IDX(0) },
    { .y = 40, .x = 6, .id = SPRITESET_IDX(0) },
    { .y = 44, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 50, .x = 12, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sRidley_15_Bg2[14] = {
    #include "extracted/data/rooms/ridley/ridley_15_bg2.gfx.inc"
};

const struct SpriteSpawn sRidley_15_SpriteLayer1[5] = {
    { .y = 32, .x = 13, .id = SPRITESET_IDX(1) },
    { .y = 40, .x = 6, .id = SPRITESET_IDX(1) },
    { .y = 44, .x = 9, .id = SPRITESET_IDX(1) },
    { .y = 50, .x = 12, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sRidley_15_Bg1[1040] = {
    #include "extracted/data/rooms/ridley/ridley_15_bg1.gfx.inc"
};

const struct SpriteSpawn sRidley_15_SpriteLayer0[6] = {
    { .y = 22, .x = 8, .id = SPRITESET_IDX(3) },
    { .y = 32, .x = 13, .id = SPRITESET_IDX(1) },
    { .y = 40, .x = 6, .id = SPRITESET_IDX(0) },
    { .y = 44, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 50, .x = 12, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sRidley_15_Bg0[141] = {
    #include "extracted/data/rooms/ridley/ridley_15_bg0.gfx.inc"
};

