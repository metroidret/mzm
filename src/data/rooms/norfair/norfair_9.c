#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_9_Clipdata[117] = {
    #include "extracted/data/rooms/norfair/norfair_9_clipdata.gfx.inc"
};

const u8 sNorfair_9_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	11, 20, SPRITESET_IDX(0),
	11, 31, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_9_Bg2[14] = {
    #include "extracted/data/rooms/norfair/norfair_9_bg2.gfx.inc"
};

const u8 sNorfair_9_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	2, 20, SPRITESET_IDX(0),
	2, 31, SPRITESET_IDX(0),
	11, 18, SPRITESET_IDX(0),
	11, 20, SPRITESET_IDX(2),
	11, 23, SPRITESET_IDX(0),
	11, 28, SPRITESET_IDX(2),
	11, 34, SPRITESET_IDX(0),
	11, 36, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_9_Bg1[282] = {
    #include "extracted/data/rooms/norfair/norfair_9_bg1.gfx.inc"
};

const u8 sNorfair_9_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	2, 20, SPRITESET_IDX(0),
	2, 31, SPRITESET_IDX(0),
	11, 18, SPRITESET_IDX(0),
	11, 26, SPRITESET_IDX(0),
	11, 34, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_9_Bg0[265] = {
    #include "extracted/data/rooms/norfair/norfair_9_bg0.gfx.inc"
};

