#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_11_Scrolls[SCROLL_DATA_SIZE(1)] = {
	32, // Room
	1, // Number of scrolls
	
	// Scroll 0
	37, 76, // X bounds
	2, 11, // Y bounds
	38, 3, // Breakable block position
	0, // Breakable block direction
	2, // Breakable block Y bound extension
};

const u8 sNorfair_32_Clipdata[193] = {
    #include "extracted/data/rooms/norfair/norfair_32_clipdata.gfx.inc"
};

const u8 sNorfair_32_Bg2[14] = {
    #include "extracted/data/rooms/norfair/norfair_32_bg2.gfx.inc"
};

const u8 sNorfair_32_Bg1[613] = {
    #include "extracted/data/rooms/norfair/norfair_32_bg1.gfx.inc"
};

const struct SpriteSpawn sNorfair_32_SpriteLayer0[5] = {
    { .y = 8, .x = 60, .id = SPRITESET_IDX(4) },
    { .y = 9, .x = 52, .id = SPRITESET_IDX(0) },
    { .y = 10, .x = 56, .id = SPRITESET_IDX(1) },
    { .y = 11, .x = 66, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sNorfair_32_Bg0[263] = {
    #include "extracted/data/rooms/norfair/norfair_32_bg0.gfx.inc"
};

