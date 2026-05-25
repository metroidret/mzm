#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_32_Clipdata[54] = {
    #include "extracted/data/rooms/brinstar/brinstar_32_clipdata.gfx.inc"
};

const u8 sBrinstar_32_Bg2[14] = {
    #include "extracted/data/rooms/brinstar/brinstar_32_bg2.gfx.inc"
};

const u8 sBrinstar_32_Bg1[190] = {
    #include "extracted/data/rooms/brinstar/brinstar_32_bg1.gfx.inc"
};

const u8 sBrinstar_32_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	6, 5, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

