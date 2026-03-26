#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_18_Clipdata[113] = {
    #include "extracted/data/rooms/tourian/tourian_18_clipdata.gfx.inc"
};

const u8 sTourian_18_Bg2[14] = {
    #include "extracted/data/rooms/tourian/tourian_18_bg2.gfx.inc"
};

const u8 sTourian_18_Bg1[270] = {
    #include "extracted/data/rooms/tourian/tourian_18_bg1.gfx.inc"
};

const u8 sTourian_18_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	2, 9, SPRITESET_IDX(1),
	15, 2, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

