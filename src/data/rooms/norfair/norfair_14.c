#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_4_Scrolls[SCROLL_DATA_SIZE(1)] = {
	14, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 61, // X bounds
	4, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sNorfair_14_Clipdata[313] = {
    #include "extracted/data/rooms/norfair/norfair_14_clipdata.gfx.inc"
};

const u8 sNorfair_14_Bg2[14] = {
    #include "extracted/data/rooms/norfair/norfair_14_bg2.gfx.inc"
};

const struct SpriteDataRom sNorfair_14_Spriteset1[16] = {
    { .y = 6, .x = 44, .id = SPRITESET_IDX(3) },
    { .y = 6, .x = 46, .id = SPRITESET_IDX(3) },
    { .y = 6, .x = 48, .id = SPRITESET_IDX(3) },
    { .y = 7, .x = 43, .id = SPRITESET_IDX(3) },
    { .y = 7, .x = 45, .id = SPRITESET_IDX(3) },
    { .y = 7, .x = 47, .id = SPRITESET_IDX(3) },
    { .y = 7, .x = 49, .id = SPRITESET_IDX(3) },
    { .y = 8, .x = 44, .id = SPRITESET_IDX(3) },
    { .y = 8, .x = 46, .id = SPRITESET_IDX(3) },
    { .y = 8, .x = 48, .id = SPRITESET_IDX(3) },
    { .y = 10, .x = 29, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 34, .id = SPRITESET_IDX(1) },
    { .y = 12, .x = 47, .id = SPRITESET_IDX(1) },
    { .y = 19, .x = 18, .id = SPRITESET_IDX(1) },
    { .y = 21, .x = 19, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_14_Bg1[983] = {
    #include "extracted/data/rooms/norfair/norfair_14_bg1.gfx.inc"
};

const struct SpriteDataRom sNorfair_14_Spriteset0[16] = {
    { .y = 6, .x = 44, .id = SPRITESET_IDX(3) },
    { .y = 6, .x = 46, .id = SPRITESET_IDX(3) },
    { .y = 6, .x = 48, .id = SPRITESET_IDX(3) },
    { .y = 7, .x = 43, .id = SPRITESET_IDX(3) },
    { .y = 7, .x = 45, .id = SPRITESET_IDX(3) },
    { .y = 7, .x = 47, .id = SPRITESET_IDX(3) },
    { .y = 7, .x = 49, .id = SPRITESET_IDX(3) },
    { .y = 8, .x = 44, .id = SPRITESET_IDX(3) },
    { .y = 8, .x = 46, .id = SPRITESET_IDX(3) },
    { .y = 8, .x = 48, .id = SPRITESET_IDX(3) },
    { .y = 10, .x = 29, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 34, .id = SPRITESET_IDX(0) },
    { .y = 12, .x = 47, .id = SPRITESET_IDX(0) },
    { .y = 19, .x = 18, .id = SPRITESET_IDX(1) },
    { .y = 21, .x = 19, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_14_Bg0[1492] = {
    #include "extracted/data/rooms/norfair/norfair_14_bg0.gfx.inc"
};

