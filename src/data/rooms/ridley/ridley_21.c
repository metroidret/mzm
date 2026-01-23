#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_21_Clipdata[56] = INCBIN_U8("data/rooms/ridley/ridley_21_clipdata.gfx");

const u8 sRidley_21_Bg2[14] = INCBIN_U8("data/rooms/ridley/ridley_21_bg2.gfx");

const u8 sRidley_21_Bg1[177] = INCBIN_U8("data/rooms/ridley/ridley_21_bg1.gfx");

const u8 sRidley_21_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	4, 8, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

