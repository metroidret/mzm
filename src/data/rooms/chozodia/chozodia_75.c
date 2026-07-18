#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_75_Clipdata[83] = {
    #include "extracted/data/rooms/chozodia/chozodia_75_clipdata.gfx.inc"
};

const u8 sChozodia_75_Bg1[194] = {
    #include "extracted/data/rooms/chozodia/chozodia_75_bg1.gfx.inc"
};

const u8 sChozodia_75_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 9, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_75_Bg0[45] = {
    #include "extracted/data/rooms/chozodia/chozodia_75_bg0.gfx.inc"
};

