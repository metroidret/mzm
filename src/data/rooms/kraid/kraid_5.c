#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_2_Scrolls[SCROLL_DATA_SIZE(1)] = {
	5, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	3, 15, // Y bounds
	17, 15, // Breakable block position
	3, // Breakable block direction
	21, // Breakable block Y bound extension
};

const u8 sKraid_5_Clipdata[233] = {
    #include "extracted/data/rooms/kraid/kraid_5_clipdata.gfx.inc"
};

const u8 sKraid_5_Bg2[41] = {
    #include "extracted/data/rooms/kraid/kraid_5_bg2.gfx.inc"
};

const struct SpriteSpawn sKraid_5_SpriteLayer1[5] = {
    { .y = 4, .x = 21, .id = SPRITESET_IDX(1) },
    { .y = 5, .x = 9, .id = SPRITESET_IDX(2) },
    { .y = 5, .x = 24, .id = SPRITESET_IDX(2) },
    { .y = 13, .x = 16, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_5_Bg1[480] = {
    #include "extracted/data/rooms/kraid/kraid_5_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_5_SpriteLayer0[6] = {
    { .y = 4, .x = 21, .id = SPRITESET_IDX(1) },
    { .y = 5, .x = 9, .id = SPRITESET_IDX(2) },
    { .y = 5, .x = 24, .id = SPRITESET_IDX(2) },
    { .y = 6, .x = 15, .id = SPRITESET_IDX(0) },
    { .y = 6, .x = 18, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

