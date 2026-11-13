#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_3_Scrolls[SCROLL_DATA_SIZE(1)] = {
	4, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakable block position
	3, // Breakable block direction
	21, // Breakable block Y bound extension
};

const u8 sCrateria_4_Clipdata[108] = {
    #include "extracted/data/rooms/crateria/crateria_4_clipdata.gfx.inc"
};

const u8 sCrateria_4_Bg2[183] = {
    #include "extracted/data/rooms/crateria/crateria_4_bg2.gfx.inc"
};

const u8 sCrateria_4_Bg1[321] = {
    #include "extracted/data/rooms/crateria/crateria_4_bg1.gfx.inc"
};

const struct SpriteSpawn sCrateria_4_SpriteLayer0[9] = {
    { .y = 3, .x = 7, .id = SPRITESET_IDX(4) },
    { .y = 3, .x = 9, .id = SPRITESET_IDX(3) },
    { .y = 5, .x = 4, .id = SPRITESET_IDX(3) },
    { .y = 7, .x = 4, .id = SPRITESET_IDX(3) },
    { .y = 9, .x = 4, .id = SPRITESET_IDX(5) },
    { .y = 9, .x = 6, .id = SPRITESET_IDX(2) },
    { .y = 9, .x = 9, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 12, .id = SPRITESET_IDX(4) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sCrateria_4_Bg0[15] = {
    #include "extracted/data/rooms/crateria/crateria_4_bg0.gfx.inc"
};

