#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_12_Scrolls[SCROLL_DATA_SIZE(1)] = {
	18, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	11, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_18_Clipdata[402] = {
    #include "extracted/data/rooms/chozodia/chozodia_18_clipdata.gfx.inc"
};

const struct SpriteSpawn sChozodia_18_Spriteset2[10] = {
    { .y = 13, .x = 31, .id = SPRITESET_IDX(4) },
    { .y = 14, .x = 12, .id = SPRITESET_IDX(4) },
    { .y = 18, .x = 19, .id = SPRITESET_IDX(3) },
    { .y = 20, .x = 23, .id = SPRITESET_IDX(4) },
    { .y = 25, .x = 43, .id = SPRITESET_IDX(4) },
    { .y = 26, .x = 38, .id = SPRITESET_IDX(3) },
    { .y = 29, .x = 10, .id = SPRITESET_IDX(4) },
    { .y = 35, .x = 29, .id = SPRITESET_IDX(3) },
    { .y = 39, .x = 20, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_18_Bg2[14] = {
    #include "extracted/data/rooms/chozodia/chozodia_18_bg2.gfx.inc"
};

const struct SpriteSpawn sChozodia_18_Spriteset1[15] = {
    { .y = 20, .x = 46, .id = SPRITESET_IDX(1) },
    { .y = 21, .x = 2, .id = SPRITESET_IDX(1) },
    { .y = 21, .x = 13, .id = SPRITESET_IDX(9) },
    { .y = 21, .x = 18, .id = SPRITESET_IDX(9) },
    { .y = 21, .x = 23, .id = SPRITESET_IDX(9) },
    { .y = 22, .x = 8, .id = SPRITESET_IDX(9) },
    { .y = 27, .x = 31, .id = SPRITESET_IDX(9) },
    { .y = 30, .x = 17, .id = SPRITESET_IDX(9) },
    { .y = 30, .x = 22, .id = SPRITESET_IDX(9) },
    { .y = 30, .x = 27, .id = SPRITESET_IDX(9) },
    { .y = 31, .x = 8, .id = SPRITESET_IDX(7) },
    { .y = 32, .x = 34, .id = SPRITESET_IDX(8) },
    { .y = 35, .x = 8, .id = SPRITESET_IDX(9) },
    { .y = 35, .x = 13, .id = SPRITESET_IDX(9) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_18_Bg1[949] = {
    #include "extracted/data/rooms/chozodia/chozodia_18_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_18_Spriteset0[23] = {
    { .y = 18, .x = 12, .id = SPRITESET_IDX(8) },
    { .y = 19, .x = 46, .id = SPRITESET_IDX(1) },
    { .y = 20, .x = 2, .id = SPRITESET_IDX(1) },
    { .y = 20, .x = 46, .id = SPRITESET_IDX(1) },
    { .y = 21, .x = 2, .id = SPRITESET_IDX(1) },
    { .y = 21, .x = 13, .id = SPRITESET_IDX(9) },
    { .y = 21, .x = 18, .id = SPRITESET_IDX(9) },
    { .y = 21, .x = 23, .id = SPRITESET_IDX(9) },
    { .y = 22, .x = 8, .id = SPRITESET_IDX(9) },
    { .y = 23, .x = 19, .id = SPRITESET_IDX(9) },
    { .y = 23, .x = 24, .id = SPRITESET_IDX(9) },
    { .y = 25, .x = 30, .id = SPRITESET_IDX(8) },
    { .y = 27, .x = 31, .id = SPRITESET_IDX(9) },
    { .y = 30, .x = 17, .id = SPRITESET_IDX(9) },
    { .y = 30, .x = 22, .id = SPRITESET_IDX(9) },
    { .y = 30, .x = 27, .id = SPRITESET_IDX(9) },
    { .y = 31, .x = 8, .id = SPRITESET_IDX(9) },
    { .y = 32, .x = 34, .id = SPRITESET_IDX(8) },
    { .y = 35, .x = 8, .id = SPRITESET_IDX(9) },
    { .y = 35, .x = 13, .id = SPRITESET_IDX(9) },
    { .y = 36, .x = 19, .id = SPRITESET_IDX(9) },
    { .y = 36, .x = 25, .id = SPRITESET_IDX(7) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_18_Bg0[17] = {
    #include "extracted/data/rooms/chozodia/chozodia_18_bg0.gfx.inc"
};

