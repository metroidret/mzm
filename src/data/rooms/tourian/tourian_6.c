#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_6_Clipdata[93] = INCBIN_U8("data/rooms/tourian/tourian_6_clipdata.gfx");

const u8 sTourian_6_Bg1[166] = INCBIN_U8("data/rooms/tourian/tourian_6_bg1.gfx");

const u8 sTourian_6_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 9, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

