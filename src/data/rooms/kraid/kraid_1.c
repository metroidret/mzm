#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_1_Clipdata[279] = {
    #include "extracted/data/rooms/kraid/kraid_1_clipdata.gfx.inc"
};

const u8 sKraid_1_Bg2[149] = {
    #include "extracted/data/rooms/kraid/kraid_1_bg2.gfx.inc"
};

const struct SpriteSpawn sKraid_1_Spriteset1[5] = {
    { .y = 6, .x = 47, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 48, .id = SPRITESET_IDX(0) },
    { .y = 12, .x = 10, .id = SPRITESET_IDX(1) },
    { .y = 12, .x = 56, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_1_Bg1[670] = {
    #include "extracted/data/rooms/kraid/kraid_1_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_1_Spriteset0[6] = {
    { .y = 5, .x = 66, .id = SPRITESET_IDX(0) },
    { .y = 6, .x = 47, .id = SPRITESET_IDX(0) },
    { .y = 8, .x = 65, .id = SPRITESET_IDX(0) },
    { .y = 9, .x = 48, .id = SPRITESET_IDX(0) },
    { .y = 12, .x = 56, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_1_Bg0[121] = {
    #include "extracted/data/rooms/kraid/kraid_1_bg0.gfx.inc"
};

const u8 sKraid_1_Scrolls[SCROLL_DATA_SIZE(1)] = {
	2, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 61, // Y bounds
	10, 60, // Breakable block position
	3, // Breakable block direction
	71, // Breakable block Y bound extension
};


const u8 sKraid_2_Clipdata[555] = {
    #include "extracted/data/rooms/kraid/kraid_2_clipdata.gfx.inc"
};

const u8 sKraid_2_Bg2[665] = {
    #include "extracted/data/rooms/kraid/kraid_2_bg2.gfx.inc"
};

const struct SpriteSpawn sKraid_2_Spriteset1[15] = {
    { .y = 15, .x = 14, .id = SPRITESET_IDX(4) },
    { .y = 20, .x = 12, .id = SPRITESET_IDX(4) },
    { .y = 21, .x = 15, .id = SPRITESET_IDX(4) },
    { .y = 25, .x = 14, .id = SPRITESET_IDX(4) },
    { .y = 42, .x = 14, .id = SPRITESET_IDX(1) },
    { .y = 45, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 46, .x = 8, .id = SPRITESET_IDX(4) },
    { .y = 48, .x = 14, .id = SPRITESET_IDX(1) },
    { .y = 50, .x = 6, .id = SPRITESET_IDX(4) },
    { .y = 51, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 54, .x = 14, .id = SPRITESET_IDX(1) },
    { .y = 55, .x = 7, .id = SPRITESET_IDX(4) },
    { .y = 57, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 67, .x = 13, .id = SPRITESET_IDX(3) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_2_Bg1[1100] = {
    #include "extracted/data/rooms/kraid/kraid_2_bg1.gfx.inc"
};

const struct SpriteSpawn sKraid_2_Spriteset0[15] = {
    { .y = 15, .x = 14, .id = SPRITESET_IDX(0) },
    { .y = 20, .x = 12, .id = SPRITESET_IDX(0) },
    { .y = 21, .x = 15, .id = SPRITESET_IDX(0) },
    { .y = 25, .x = 14, .id = SPRITESET_IDX(0) },
    { .y = 42, .x = 14, .id = SPRITESET_IDX(1) },
    { .y = 45, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 46, .x = 8, .id = SPRITESET_IDX(0) },
    { .y = 48, .x = 14, .id = SPRITESET_IDX(1) },
    { .y = 50, .x = 6, .id = SPRITESET_IDX(0) },
    { .y = 51, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 54, .x = 14, .id = SPRITESET_IDX(1) },
    { .y = 55, .x = 7, .id = SPRITESET_IDX(0) },
    { .y = 57, .x = 12, .id = SPRITESET_IDX(1) },
    { .y = 67, .x = 13, .id = SPRITESET_IDX(3) },
    SPRITE_SPAWN_TERMINATOR
};

const u8 sKraid_2_Bg0[80] = {
    #include "extracted/data/rooms/kraid/kraid_2_bg0.gfx.inc"
};

