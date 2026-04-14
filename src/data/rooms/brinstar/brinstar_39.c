#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_39_Clipdata[78] = {
    #include "extracted/data/rooms/brinstar/brinstar_39_clipdata.gfx.inc"
};

const u8 sBrinstar_39_Bg2[14] = {
    #include "extracted/data/rooms/brinstar/brinstar_39_bg2.gfx.inc"
};

const u8 sBrinstar_39_Bg1[216] = {
    #include "extracted/data/rooms/brinstar/brinstar_39_bg1.gfx.inc"
};

const u8 sBrinstar_39_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 9, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

