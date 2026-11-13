#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_1_Scrolls[SCROLL_DATA_SIZE(1)] = {
	4, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 61, // X bounds
	8, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sTourian_4_Clipdata[375] = {
    #include "extracted/data/rooms/tourian/tourian_4_clipdata.gfx.inc"
};

const u8 sTourian_4_Bg2[144] = {
    #include "extracted/data/rooms/tourian/tourian_4_bg2.gfx.inc"
};

const u8 sTourian_4_Bg1[657] = {
    #include "extracted/data/rooms/tourian/tourian_4_bg1.gfx.inc"
};

const struct SpriteSpawn sTourian_4_Spriteset0[17] = {
    { .y = 9, .x = 28, .id = SPRITESET_IDX(8) },
    { .y = 9, .x = 38, .id = SPRITESET_IDX(8) },
    { .y = 9, .x = 48, .id = SPRITESET_IDX(4) },
    { .y = 9, .x = 59, .id = SPRITESET_IDX(3) },
    { .y = 10, .x = 53, .id = SPRITESET_IDX(6) },
    { .y = 11, .x = 38, .id = SPRITESET_IDX(11) },
    { .y = 11, .x = 48, .id = SPRITESET_IDX(9) },
    { .y = 12, .x = 42, .id = SPRITESET_IDX(10) },
    { .y = 12, .x = 44, .id = SPRITESET_IDX(9) },
    { .y = 12, .x = 52, .id = SPRITESET_IDX(9) },
    { .y = 12, .x = 54, .id = SPRITESET_IDX(9) },
    { .y = 15, .x = 7, .id = SPRITESET_IDX(0) },
    { .y = 16, .x = 43, .id = SPRITESET_IDX(2) },
    { .y = 16, .x = 53, .id = SPRITESET_IDX(1) },
    { .y = 19, .x = 43, .id = SPRITESET_IDX(5) },
    { .y = 19, .x = 53, .id = SPRITESET_IDX(7) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sTourian_4_Bg0[307] = {
    #include "extracted/data/rooms/tourian/tourian_4_bg0.gfx.inc"
};

