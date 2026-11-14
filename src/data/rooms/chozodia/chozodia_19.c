#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_13_Scrolls[SCROLL_DATA_SIZE(1)] = {
	19, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 17, // Y bounds
	3, 18, // Breakable block position
	3, // Breakable block direction
	21, // Breakable block Y bound extension
};

const u8 sChozodia_19_Clipdata[165] = {
    #include "extracted/data/rooms/chozodia/chozodia_19_clipdata.gfx.inc"
};

const u8 sChozodia_19_Bg2[395] = {
    #include "extracted/data/rooms/chozodia/chozodia_19_bg2.gfx.inc"
};

const u8 sChozodia_19_Bg1[371] = {
    #include "extracted/data/rooms/chozodia/chozodia_19_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_19_SpriteLayer0[2] = {
    { .y = 12, .x = 13, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_19_Bg0[185] = {
    #include "extracted/data/rooms/chozodia/chozodia_19_bg0.gfx.inc"
};

