#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_31_Scrolls[SCROLL_DATA_SIZE(1)] = {
	49, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 21, // Y bounds
	9, 12, // Breakable block position
	2, // Breakable block direction
	2, // Breakable block Y bound extension
};

const u8 sChozodia_49_Clipdata[129] = {
    #include "extracted/data/rooms/chozodia/chozodia_49_clipdata.gfx.inc"
};

const u8 sChozodia_49_Bg2[255] = {
    #include "extracted/data/rooms/chozodia/chozodia_49_bg2.gfx.inc"
};

const u8 sChozodia_49_Bg1[327] = {
    #include "extracted/data/rooms/chozodia/chozodia_49_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_49_SpriteLayer0[3] = {
    { .y = 6, .x = 5, .id = SPRITESET_IDX(0) },
    { .y = 6, .x = 14, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

