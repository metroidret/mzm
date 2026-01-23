#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_35_Clipdata[56] = INCBIN_U8("data/rooms/kraid/kraid_35_clipdata.gfx");

const u8 sKraid_35_Bg2[14] = INCBIN_U8("data/rooms/kraid/kraid_35_bg2.gfx");

const u8 sKraid_35_Bg1[193] = INCBIN_U8("data/rooms/kraid/kraid_35_bg1.gfx");

const u8 sKraid_35_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	6, 5, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

