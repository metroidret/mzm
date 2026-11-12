#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_7_Scrolls[SCROLL_DATA_SIZE(1)] = {
	22, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	9, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sNorfair_22_Clipdata[264] = {
    #include "extracted/data/rooms/norfair/norfair_22_clipdata.gfx.inc"
};

const u8 sNorfair_22_Bg2[456] = {
    #include "extracted/data/rooms/norfair/norfair_22_bg2.gfx.inc"
};

const struct SpriteDataRom sNorfair_22_Spriteset1[8] = {
    { .y = 9, .x = 21, .id = SPRITESET_IDX(4) },
    { .y = 9, .x = 30, .id = SPRITESET_IDX(4) },
    { .y = 16, .x = 18, .id = SPRITESET_IDX(0) },
    { .y = 16, .x = 24, .id = SPRITESET_IDX(1) },
    { .y = 17, .x = 35, .id = SPRITESET_IDX(1) },
    { .y = 19, .x = 29, .id = SPRITESET_IDX(1) },
    { .y = 21, .x = 11, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_22_Bg1[647] = {
    #include "extracted/data/rooms/norfair/norfair_22_bg1.gfx.inc"
};

const struct SpriteDataRom sNorfair_22_Spriteset0[8] = {
    { .y = 9, .x = 21, .id = SPRITESET_IDX(4) },
    { .y = 9, .x = 30, .id = SPRITESET_IDX(4) },
    { .y = 16, .x = 18, .id = SPRITESET_IDX(0) },
    { .y = 16, .x = 24, .id = SPRITESET_IDX(0) },
    { .y = 17, .x = 35, .id = SPRITESET_IDX(0) },
    { .y = 19, .x = 29, .id = SPRITESET_IDX(1) },
    { .y = 21, .x = 11, .id = SPRITESET_IDX(2) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_22_Bg0[175] = {
    #include "extracted/data/rooms/norfair/norfair_22_bg0.gfx.inc"
};

