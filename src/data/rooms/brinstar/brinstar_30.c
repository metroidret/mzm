#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_30_Clipdata[76] = {
    #include "extracted/data/rooms/brinstar/brinstar_30_clipdata.gfx.inc"
};

const u8 sBrinstar_30_Bg2[14] = {
    #include "extracted/data/rooms/brinstar/brinstar_30_bg2.gfx.inc"
};

const u8 sBrinstar_30_Bg1[220] = {
    #include "extracted/data/rooms/brinstar/brinstar_30_bg1.gfx.inc"
};

const u8 sBrinstar_30_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	9, 11, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

