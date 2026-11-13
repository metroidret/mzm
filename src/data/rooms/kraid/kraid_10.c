#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_5_Scrolls[SCROLL_DATA_SIZE(1)] = {
	10, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 17, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sKraid_10_Clipdata[165] = {
    #include "extracted/data/rooms/kraid/kraid_10_clipdata.gfx.inc"
};

const u8 sKraid_10_Bg2[113] = {
    #include "extracted/data/rooms/kraid/kraid_10_bg2.gfx.inc"
};

const u8 sKraid_10_Bg1[413] = {
    #include "extracted/data/rooms/kraid/kraid_10_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_10_Spriteset0[6] = {
    { .y = 3, .x = 25, .id = SPRITESET_IDX(0) },
    { .y = 8, .x = 18, .id = SPRITESET_IDX(1) },
    { .y = 16, .x = 16, .id = SPRITESET_IDX(2) },
    { .y = 16, .x = 19, .id = SPRITESET_IDX(2) },
    { .y = 16, .x = 22, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

