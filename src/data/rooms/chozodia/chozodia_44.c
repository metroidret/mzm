#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_28_Scrolls[SCROLL_DATA_SIZE(1)] = {
	44, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 22, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	UCHAR_MAX, // Breakable block direction
	UCHAR_MAX, // Breakable block Y bound extension
};

const u8 sChozodia_44_Clipdata[136] = {
    #include "extracted/data/rooms/chozodia/chozodia_44_clipdata.gfx.inc"
};

const u8 sChozodia_44_Bg2[221] = {
    #include "extracted/data/rooms/chozodia/chozodia_44_bg2.gfx.inc"
};

const struct SpriteSpawn sChozodia_44_Spriteset1[4] = {
    { .y = 6, .x = 4, .id = SPRITESET_IDX(3) },
    { .y = 13, .x = 3, .id = SPRITESET_IDX(3) },
    { .y = 21, .x = 16, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sChozodia_44_Bg1[344] = {
    #include "extracted/data/rooms/chozodia/chozodia_44_bg1.gfx.inc"
};

const struct SpriteSpawn sChozodia_44_Spriteset0[6] = {
    { .y = 6, .x = 4, .id = SPRITESET_IDX(3) },
    { .y = 6, .x = 16, .id = SPRITESET_IDX(1) },
    { .y = 10, .x = 12, .id = SPRITESET_IDX(3) },
    { .y = 13, .x = 3, .id = SPRITESET_IDX(3) },
    { .y = 21, .x = 16, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

