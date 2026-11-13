#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_18_Scrolls[SCROLL_DATA_SIZE(1)] = {
	28, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	11, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_28_Clipdata[506] = {
    #include "extracted/data/rooms/chozodia/chozodia_28_clipdata.gfx.inc"
};

const struct SpriteDataRom sChozodia_28_Spriteset2[7] = {
    { .y = 16, .x = 13, .id = SPRITESET_IDX(0) },
    { .y = 16, .x = 31, .id = SPRITESET_IDX(1) },
    { .y = 17, .x = 23, .id = SPRITESET_IDX(0) },
    { .y = 28, .x = 5, .id = SPRITESET_IDX(0) },
    { .y = 39, .x = 31, .id = SPRITESET_IDX(1) },
    { .y = 40, .x = 19, .id = SPRITESET_IDX(0) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_28_Bg2[326] = {
    #include "extracted/data/rooms/chozodia/chozodia_28_bg2.gfx.inc"
};

const struct SpriteDataRom sChozodia_28_Spriteset1[12] = {
    { .y = 14, .x = 10, .id = SPRITESET_IDX(4) },
    { .y = 15, .x = 20, .id = SPRITESET_IDX(6) },
    { .y = 16, .x = 31, .id = SPRITESET_IDX(1) },
    { .y = 20, .x = 7, .id = SPRITESET_IDX(5) },
    { .y = 22, .x = 20, .id = SPRITESET_IDX(0) },
    { .y = 25, .x = 20, .id = SPRITESET_IDX(8) },
    { .y = 26, .x = 27, .id = SPRITESET_IDX(4) },
    { .y = 28, .x = 5, .id = SPRITESET_IDX(0) },
    { .y = 32, .x = 20, .id = SPRITESET_IDX(4) },
    { .y = 34, .x = 27, .id = SPRITESET_IDX(7) },
    { .y = 39, .x = 31, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_28_Bg1[854] = {
    #include "extracted/data/rooms/chozodia/chozodia_28_bg1.gfx.inc"
};

const struct SpriteDataRom sChozodia_28_Spriteset0[9] = {
    { .y = 14, .x = 10, .id = SPRITESET_IDX(4) },
    { .y = 15, .x = 20, .id = SPRITESET_IDX(6) },
    { .y = 16, .x = 31, .id = SPRITESET_IDX(1) },
    { .y = 25, .x = 20, .id = SPRITESET_IDX(8) },
    { .y = 26, .x = 27, .id = SPRITESET_IDX(4) },
    { .y = 28, .x = 5, .id = SPRITESET_IDX(0) },
    { .y = 32, .x = 20, .id = SPRITESET_IDX(4) },
    { .y = 39, .x = 31, .id = SPRITESET_IDX(1) },
    ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_28_Bg0[16] = {
    #include "extracted/data/rooms/chozodia/chozodia_28_bg0.gfx.inc"
};

