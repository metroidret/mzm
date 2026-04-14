#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_12_Clipdata[110] = {
    #include "extracted/data/rooms/norfair/norfair_12_clipdata.gfx.inc"
};

const u8 sNorfair_12_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	4, 14, SPRITESET_IDX(2),
	4, 17, SPRITESET_IDX(3),
	4, 20, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_12_Bg2[48] = {
    #include "extracted/data/rooms/norfair/norfair_12_bg2.gfx.inc"
};

const u8 sNorfair_12_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	4, 14, SPRITESET_IDX(3),
	4, 17, SPRITESET_IDX(2),
	4, 20, SPRITESET_IDX(3),
	5, 16, SPRITESET_IDX(3),
	5, 18, SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_12_Bg1[269] = {
    #include "extracted/data/rooms/norfair/norfair_12_bg1.gfx.inc"
};

const u8 sNorfair_12_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	4, 14, SPRITESET_IDX(2),
	4, 17, SPRITESET_IDX(3),
	4, 20, SPRITESET_IDX(2),
	5, 16, SPRITESET_IDX(2),
	5, 18, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_12_Bg0[129] = {
    #include "extracted/data/rooms/norfair/norfair_12_bg0.gfx.inc"
};

