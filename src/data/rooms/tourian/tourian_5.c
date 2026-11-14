#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_2_Scrolls[SCROLL_DATA_SIZE(1)] = {
	5, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 111, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	2, // Breakable block direction
	2, // Breakable block Y bound extension
};

const u8 sTourian_5_Clipdata[597] = {
    #include "extracted/data/rooms/tourian/tourian_5_clipdata.gfx.inc"
};

const u8 sTourian_5_Bg2[226] = {
    #include "extracted/data/rooms/tourian/tourian_5_bg2.gfx.inc"
};

const u8 sTourian_5_Bg1[1425] = {
    #include "extracted/data/rooms/tourian/tourian_5_bg1.gfx.inc"
};

const struct SpriteSpawn sTourian_5_SpriteLayer0[24] = {
    { .y = 13, .x = 6, .id = SPRITESET_IDX(4) },
    { .y = 15, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 17, .x = 4, .id = SPRITESET_IDX(3) },
    { .y = 18, .x = 14, .id = SPRITESET_IDX(5) },
    { .y = 24, .x = 14, .id = SPRITESET_IDX(7) },
    { .y = 27, .x = 4, .id = SPRITESET_IDX(6) },
    { .y = 34, .x = 14, .id = SPRITESET_IDX(3) },
    { .y = 38, .x = 4, .id = SPRITESET_IDX(7) },
    { .y = 43, .x = 14, .id = SPRITESET_IDX(3) },
    { .y = 50, .x = 4, .id = SPRITESET_IDX(5) },
    { .y = 54, .x = 14, .id = SPRITESET_IDX(7) },
    { .y = 64, .x = 4, .id = SPRITESET_IDX(4) },
    { .y = 65, .x = 14, .id = SPRITESET_IDX(5) },
    { .y = 75, .x = 14, .id = SPRITESET_IDX(8) },
    { .y = 76, .x = 4, .id = SPRITESET_IDX(8) },
    { .y = 86, .x = 14, .id = SPRITESET_IDX(5) },
    { .y = 87, .x = 4, .id = SPRITESET_IDX(5) },
    { .y = 96, .x = 4, .id = SPRITESET_IDX(3) },
    { .y = 97, .x = 14, .id = SPRITESET_IDX(6) },
    { .y = 103, .x = 4, .id = SPRITESET_IDX(5) },
    { .y = 110, .x = 6, .id = SPRITESET_IDX(3) },
    { .y = 110, .x = 9, .id = SPRITESET_IDX(2) },
    { .y = 110, .x = 11, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sTourian_5_Bg0[186] = {
    #include "extracted/data/rooms/tourian/tourian_5_bg0.gfx.inc"
};

