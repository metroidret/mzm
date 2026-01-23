#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_31_Clipdata[67] = INCBIN_U8("data/rooms/kraid/kraid_31_clipdata.gfx");

const u8 sKraid_31_Bg2[18] = INCBIN_U8("data/rooms/kraid/kraid_31_bg2.gfx");

const u8 sKraid_31_Bg1[208] = INCBIN_U8("data/rooms/kraid/kraid_31_bg1.gfx");

const u8 sKraid_31_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 8, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

