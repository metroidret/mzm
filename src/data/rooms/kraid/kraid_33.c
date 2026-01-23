#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_33_Clipdata[71] = INCBIN_U8("data/rooms/kraid/kraid_33_clipdata.gfx");

const u8 sKraid_33_Bg2[29] = INCBIN_U8("data/rooms/kraid/kraid_33_bg2.gfx");

const u8 sKraid_33_Bg1[181] = INCBIN_U8("data/rooms/kraid/kraid_33_bg1.gfx");

const u8 sKraid_33_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	7, 14, SPRITESET_IDX(0),
	9, 6, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

