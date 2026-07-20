#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_13_Clipdata[100] = {
    #include "extracted/data/rooms/tourian/tourian_13_clipdata.gfx.inc"
};

const u8 sTourian_13_Bg2[52] = {
    #include "extracted/data/rooms/tourian/tourian_13_bg2.gfx.inc"
};

const u8 sTourian_13_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	2, 10, SPRITESET_IDX(1),
	12, 15, SPRITESET_IDX(1),
	19, 7, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_13_Bg1[280] = {
    #include "extracted/data/rooms/tourian/tourian_13_bg1.gfx.inc"
};

const u8 sTourian_13_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	12, 15, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

