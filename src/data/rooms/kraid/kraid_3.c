#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_3_Clipdata[138] = {
    #include "extracted/data/rooms/kraid/kraid_3_clipdata.gfx.inc"
};

const u8 sKraid_3_Bg2[72] = {
    #include "extracted/data/rooms/kraid/kraid_3_bg2.gfx.inc"
};

const u8 sKraid_3_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	2, 34, SPRITESET_IDX(1),
	3, 5, SPRITESET_IDX(2),
	13, 26, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_3_Bg1[410] = {
    #include "extracted/data/rooms/kraid/kraid_3_bg1.gfx.inc"
};

const u8 sKraid_3_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	2, 34, SPRITESET_IDX(1),
	3, 5, SPRITESET_IDX(2),
	12, 26, SPRITESET_IDX(4),
	12, 38, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_3_Bg0[89] = {
    #include "extracted/data/rooms/kraid/kraid_3_bg0.gfx.inc"
};

