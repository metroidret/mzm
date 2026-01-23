#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_20_Clipdata[74] = INCBIN_U8("data/rooms/kraid/kraid_20_clipdata.gfx");

const u8 sKraid_20_Bg2[14] = INCBIN_U8("data/rooms/kraid/kraid_20_bg2.gfx");

const u8 sKraid_20_Bg1[210] = INCBIN_U8("data/rooms/kraid/kraid_20_bg1.gfx");

const u8 sKraid_20_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 9, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

