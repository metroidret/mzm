#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_25_Clipdata[92] = INCBIN_U8("data/rooms/ridley/ridley_25_clipdata.gfx");

const u8 sRidley_25_Bg1[166] = INCBIN_U8("data/rooms/ridley/ridley_25_bg1.gfx");

const u8 sRidley_25_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 9, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

