#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_6_Scrolls[SCROLL_DATA_SIZE(2)] = {
	25, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 15, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sKraid_25_Clipdata[195] = {
    #include "extracted/data/rooms/kraid/kraid_25_clipdata.gfx.inc"
};

const u8 sKraid_25_Bg2[229] = {
    #include "extracted/data/rooms/kraid/kraid_25_bg2.gfx.inc"
};

const struct SpriteDataRom sKraid_25_Spriteset1[10] = {
    { .y = 3, .x = 9, .id = SPRITESET_IDX(4) },
    { .y = 6, .x = 6, .id = SPRITESET_IDX(3) },
    { .y = 10, .x = 7, .id = SPRITESET_IDX(4) },
    { .y = 13, .x = 11, .id = SPRITESET_IDX(4) },
    { .y = 14, .x = 15, .id = SPRITESET_IDX(3) },
    { .y = 15, .x = 11, .id = SPRITESET_IDX(4) },
    { .y = 15, .x = 20, .id = SPRITESET_IDX(4) },
    { .y = 21, .x = 10, .id = SPRITESET_IDX(5) },
    { .y = 21, .x = 20, .id = SPRITESET_IDX(5) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_25_Bg1[487] = {
    #include "extracted/data/rooms/kraid/kraid_25_bg1.gfx.inc"
};

const struct SpriteDataRom sKraid_25_Spriteset0[10] = {
    { .y = 3, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 6, .x = 6, .id = SPRITESET_IDX(3) },
    { .y = 10, .x = 7, .id = SPRITESET_IDX(0) },
    { .y = 13, .x = 11, .id = SPRITESET_IDX(0) },
    { .y = 14, .x = 15, .id = SPRITESET_IDX(3) },
    { .y = 15, .x = 11, .id = SPRITESET_IDX(0) },
    { .y = 15, .x = 20, .id = SPRITESET_IDX(0) },
    { .y = 21, .x = 10, .id = SPRITESET_IDX(5) },
    { .y = 21, .x = 20, .id = SPRITESET_IDX(5) },
    ROOM_SPRITE_DATA_TERMINATOR
};

