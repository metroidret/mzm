#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_4_Scrolls[SCROLL_DATA_SIZE(1)] = {
	10, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	12, 21, // Y bounds
	9, 12, // Breakable block position
	2, // Breakable block direction
	2, // Breakable block Y bound extension
};

const u8 sRidley_10_Clipdata[248] = {
    #include "extracted/data/rooms/ridley/ridley_10_clipdata.gfx.inc"
};

const u8 sRidley_10_Bg2[14] = {
    #include "extracted/data/rooms/ridley/ridley_10_bg2.gfx.inc"
};

const u8 sRidley_10_Bg1[855] = {
    #include "extracted/data/rooms/ridley/ridley_10_bg1.gfx.inc"
};

const struct SpriteDataRom sRidley_10_Spriteset0[5] = {
    { .y = 14, .x = 17, .id = SPRITESET_IDX(5) },
    { .y = 15, .x = 19, .id = SPRITESET_IDX(5) },
    { .y = 17, .x = 12, .id = SPRITESET_IDX(5) },
    { .y = 17, .x = 18, .id = SPRITESET_IDX(5) },
    ROOM_SPRITE_DATA_TERMINATOR
};

