#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_0_Scrolls[SCROLL_DATA_SIZE(1)] = {
	0, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	11, 81, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	2, // Breakable block direction
	2, // Breakable block Y bound extension
};

const u8 sKraid_0_Clipdata[525] = {
    #include "extracted/data/rooms/kraid/kraid_0_clipdata.gfx.inc"
};

const u8 sKraid_0_Bg2[675] = {
    #include "extracted/data/rooms/kraid/kraid_0_bg2.gfx.inc"
};

const u8 sKraid_0_Bg1[1122] = {
    #include "extracted/data/rooms/kraid/kraid_0_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_0_Spriteset0[10] = {
    { .y = 17, .x = 9, .id = SPRITESET_IDX(2) },
    { .y = 24, .x = 7, .id = SPRITESET_IDX(0) },
    { .y = 35, .x = 10, .id = SPRITESET_IDX(0) },
    { .y = 51, .x = 8, .id = SPRITESET_IDX(0) },
    { .y = 62, .x = 3, .id = SPRITESET_IDX(1) },
    { .y = 65, .x = 3, .id = SPRITESET_IDX(1) },
    { .y = 68, .x = 3, .id = SPRITESET_IDX(1) },
    { .y = 74, .x = 5, .id = SPRITESET_IDX(0) },
    { .y = 74, .x = 14, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

