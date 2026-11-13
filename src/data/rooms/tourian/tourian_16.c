#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_5_Scrolls[SCROLL_DATA_SIZE(2)] = {
	16, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 11, // Y bounds
	14, 11, // Breakable block position
	3, // Breakable block direction
	21, // Breakable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	20, 30, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sTourian_16_Clipdata[166] = {
    #include "extracted/data/rooms/tourian/tourian_16_clipdata.gfx.inc"
};

const u8 sTourian_16_Bg2[154] = {
    #include "extracted/data/rooms/tourian/tourian_16_bg2.gfx.inc"
};

const struct SpriteSpawn sTourian_16_Spriteset1[15] = {
    { .y = 4, .x = 9, .id = SPRITESET_IDX(1) },
    { .y = 4, .x = 24, .id = SPRITESET_IDX(1) },
    { .y = 16, .x = 2, .id = SPRITESET_IDX(1) },
    { .y = 16, .x = 31, .id = SPRITESET_IDX(1) },
    { .y = 17, .x = 12, .id = SPRITESET_IDX(0) },
    { .y = 17, .x = 21, .id = SPRITESET_IDX(0) },
    { .y = 18, .x = 15, .id = SPRITESET_IDX(0) },
    { .y = 18, .x = 18, .id = SPRITESET_IDX(0) },
    { .y = 26, .x = 6, .id = SPRITESET_IDX(1) },
    { .y = 26, .x = 27, .id = SPRITESET_IDX(1) },
    { .y = 28, .x = 13, .id = SPRITESET_IDX(0) },
    { .y = 28, .x = 21, .id = SPRITESET_IDX(0) },
    { .y = 29, .x = 17, .id = SPRITESET_IDX(0) },
    { .y = 31, .x = 17, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sTourian_16_Bg1[513] = {
    #include "extracted/data/rooms/tourian/tourian_16_bg1.gfx.inc"
};

const struct SpriteSpawn sTourian_16_Spriteset0[14] = {
    { .y = 4, .x = 9, .id = SPRITESET_IDX(1) },
    { .y = 4, .x = 24, .id = SPRITESET_IDX(1) },
    { .y = 16, .x = 2, .id = SPRITESET_IDX(1) },
    { .y = 16, .x = 6, .id = SPRITESET_IDX(0) },
    { .y = 16, .x = 27, .id = SPRITESET_IDX(0) },
    { .y = 16, .x = 31, .id = SPRITESET_IDX(1) },
    { .y = 17, .x = 12, .id = SPRITESET_IDX(0) },
    { .y = 17, .x = 21, .id = SPRITESET_IDX(0) },
    { .y = 26, .x = 6, .id = SPRITESET_IDX(1) },
    { .y = 26, .x = 27, .id = SPRITESET_IDX(1) },
    { .y = 28, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 28, .x = 24, .id = SPRITESET_IDX(0) },
    { .y = 31, .x = 17, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

