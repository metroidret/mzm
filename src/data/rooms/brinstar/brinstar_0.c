#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const struct ScrollArray(3) sBrinstar_0_Scrolls = {
    .room = 0,
    .scrolls_len = 3,
    .scrolls = {
        {
            .x_bounds = { 2, 76 },
            .y_bounds = { 22, 31 },
            .extension = SCROLL_EXTENSION_NONE,
        },
        {
            .x_bounds = { 32, 46 },
            .y_bounds = { 2, 23 },
            .extension = SCROLL_EXTENSION_NONE,
        },
        {
            .x_bounds = { 32, 46 },
            .y_bounds = { 31, 41 },
            .extension = SCROLL_EXTENSION_NONE,
        }
    }
};

const u8 sBrinstar_0_Clipdata[311] = {
    #include "extracted/data/rooms/brinstar/brinstar_0_clipdata.gfx.inc"
};

const u8 sBrinstar_0_Bg2[124] = {
    #include "extracted/data/rooms/brinstar/brinstar_0_bg2.gfx.inc"
};

const u8 sBrinstar_0_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	22, 27, SPRITESET_IDX(4),
	22, 56, SPRITESET_IDX(4),
	23, 68, SPRITESET_IDX(4),
	24, 4, SPRITESET_IDX(4),
	27, 11, SPRITESET_IDX(1),
	30, 21, SPRITESET_IDX(4),
	30, 67, SPRITESET_IDX(4),
	34, 39, SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_0_Bg1[1328] = {
    #include "extracted/data/rooms/brinstar/brinstar_0_bg1.gfx.inc"
};

const u8 sBrinstar_0_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	22, 27, SPRITESET_IDX(0),
	22, 56, SPRITESET_IDX(0),
	23, 68, SPRITESET_IDX(0),
	24, 4, SPRITESET_IDX(0),
	27, 11, SPRITESET_IDX(1),
	30, 21, SPRITESET_IDX(0),
	30, 67, SPRITESET_IDX(0),
	34, 39, SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

