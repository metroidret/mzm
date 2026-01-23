#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_23_Clipdata[186] = INCBIN_U8("data/rooms/ridley/ridley_23_clipdata.gfx");

const u8 sRidley_23_Bg2[14] = INCBIN_U8("data/rooms/ridley/ridley_23_bg2.gfx");

const u8 sRidley_23_Bg1[488] = INCBIN_U8("data/rooms/ridley/ridley_23_bg1.gfx");

const u8 sRidley_23_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	19, 14, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

