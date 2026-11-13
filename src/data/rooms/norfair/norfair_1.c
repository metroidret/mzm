#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_1_Clipdata[310] = {
    #include "extracted/data/rooms/norfair/norfair_1_clipdata.gfx.inc"
};

const struct SpriteSpawn sNorfair_1_Spriteset2[10] = {
    { .y = 2, .x = 10, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 12, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 14, .id = SPRITESET_IDX(3) },
    { .y = 3, .x = 53, .id = SPRITESET_IDX(3) },
    { .y = 3, .x = 55, .id = SPRITESET_IDX(3) },
    { .y = 9, .x = 65, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 94, .id = SPRITESET_IDX(0) },
    { .y = 10, .x = 84, .id = SPRITESET_IDX(2) },
    { .y = 10, .x = 108, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_1_Bg2[375] = {
    #include "extracted/data/rooms/norfair/norfair_1_bg2.gfx.inc"
};

const struct SpriteSpawn sNorfair_1_Spriteset1[14] = {
    { .y = 3, .x = 11, .id = SPRITESET_IDX(3) },
    { .y = 3, .x = 13, .id = SPRITESET_IDX(3) },
    { .y = 3, .x = 15, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 12, .id = SPRITESET_IDX(3) },
    { .y = 4, .x = 14, .id = SPRITESET_IDX(3) },
    { .y = 9, .x = 65, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 94, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 70, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 72, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 84, .id = SPRITESET_IDX(4) },
    { .y = 10, .x = 108, .id = SPRITESET_IDX(4) },
    { .y = 12, .x = 29, .id = SPRITESET_IDX(4) },
    { .y = 12, .x = 60, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_1_Bg1[1181] = {
    #include "extracted/data/rooms/norfair/norfair_1_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_1_Spriteset0[13] = {
    { .y = 2, .x = 10, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 12, .id = SPRITESET_IDX(3) },
    { .y = 2, .x = 14, .id = SPRITESET_IDX(3) },
    { .y = 3, .x = 11, .id = SPRITESET_IDX(3) },
    { .y = 3, .x = 13, .id = SPRITESET_IDX(3) },
    { .y = 3, .x = 53, .id = SPRITESET_IDX(3) },
    { .y = 3, .x = 55, .id = SPRITESET_IDX(3) },
    { .y = 9, .x = 65, .id = SPRITESET_IDX(1) },
    { .y = 9, .x = 71, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 94, .id = SPRITESET_IDX(0) },
    { .y = 10, .x = 84, .id = SPRITESET_IDX(2) },
    { .y = 10, .x = 108, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_1_Bg0[399] = {
    #include "extracted/data/rooms/norfair/norfair_1_bg0.gfx.inc"
};

const u8 sNorfair_1_Scrolls[SCROLL_DATA_SIZE(1)] = {
	2, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	2, // Breakable block direction
	2, // Breakable block Y bound extension
};

const u8 sNorfair_2_Clipdata[285] = {
    #include "extracted/data/rooms/norfair/norfair_2_clipdata.gfx.inc"
};

const struct SpriteSpawn sNorfair_2_Spriteset2[4] = {
    { .y = 15, .x = 9, .id = SPRITESET_IDX(4) },
    { .y = 38, .x = 9, .id = SPRITESET_IDX(0) },
	39, 11,	SPRITESET_IDX(2),
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_2_Bg2[193] = {
    #include "extracted/data/rooms/norfair/norfair_2_bg2.gfx.inc"
};

const struct SpriteSpawn sNorfair_2_Spriteset1[7] = {
    { .y = 15, .x = 9, .id = SPRITESET_IDX(4) },
    { .y = 18, .x = 9, .id = SPRITESET_IDX(2) },
    { .y = 33, .x = 3, .id = SPRITESET_IDX(0) },
    { .y = 36, .x = 5, .id = SPRITESET_IDX(1) },
    { .y = 38, .x = 9, .id = SPRITESET_IDX(1) },
	39, 11,	SPRITESET_IDX(2),
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_2_Bg1[659] = {
    #include "extracted/data/rooms/norfair/norfair_2_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_2_Spriteset0[6] = {
    { .y = 15, .x = 9, .id = SPRITESET_IDX(4) },
	33,	3, SPRITESET_IDX(0),
	36,	5, SPRITESET_IDX(0),
    { .y = 38, .x = 9, .id = SPRITESET_IDX(0) },
	39, 11,	SPRITESET_IDX(2),
    SPRITE_SPAWN_TERMINATOR
};

