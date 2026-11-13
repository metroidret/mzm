#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_1_Scrolls[SCROLL_DATA_SIZE(3)] = {
	1, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 61, // X bounds
	2, 13, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	32, 46, // X bounds
	2, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 2
	2, 16, // X bounds
	2, 61, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sCrateria_1_Clipdata[672] = {
    #include "extracted/data/rooms/crateria/crateria_1_clipdata.gfx.inc"
};

const u8 sCrateria_1_Bg2[335] = {
    #include "extracted/data/rooms/crateria/crateria_1_bg2.gfx.inc"
};

const u8 sCrateria_1_Bg1[1608] = {
    #include "extracted/data/rooms/crateria/crateria_1_bg1.gfx.inc"
};

const struct SpriteDataRom sCrateria_1_Spriteset0[19] = {
    { .y = 4, .x = 34, .id = SPRITESET_IDX(4) },
    { .y = 5, .x = 23, .id = SPRITESET_IDX(3) },
    { .y = 5, .x = 43, .id = SPRITESET_IDX(3) },
    { .y = 9, .x = 4, .id = SPRITESET_IDX(3) },
    { .y = 9, .x = 14, .id = SPRITESET_IDX(4) },
    { .y = 9, .x = 27, .id = SPRITESET_IDX(4) },
    { .y = 12, .x = 3, .id = SPRITESET_IDX(7) },
    { .y = 14, .x = 14, .id = SPRITESET_IDX(7) },
    { .y = 17, .x = 14, .id = SPRITESET_IDX(3) },
    { .y = 18, .x = 3, .id = SPRITESET_IDX(4) },
    { .y = 29, .x = 13, .id = SPRITESET_IDX(4) },
    { .y = 32, .x = 4, .id = SPRITESET_IDX(3) },
    { .y = 37, .x = 4, .id = SPRITESET_IDX(4) },
    { .y = 42, .x = 15, .id = SPRITESET_IDX(4) },
    { .y = 43, .x = 4, .id = SPRITESET_IDX(3) },
    { .y = 47, .x = 15, .id = SPRITESET_IDX(3) },
    { .y = 50, .x = 4, .id = SPRITESET_IDX(4) },
    { .y = 60, .x = 8, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sCrateria_1_Bg0[14] = {
    #include "extracted/data/rooms/crateria/crateria_1_bg0.gfx.inc"
};

