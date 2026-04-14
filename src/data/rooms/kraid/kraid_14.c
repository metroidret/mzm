#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_14_Clipdata[118] = {
    #include "extracted/data/rooms/kraid/kraid_14_clipdata.gfx.inc"
};

const u8 sKraid_14_Bg2[46] = {
    #include "extracted/data/rooms/kraid/kraid_14_bg2.gfx.inc"
};

const u8 sKraid_14_Bg1[217] = {
    #include "extracted/data/rooms/kraid/kraid_14_bg1.gfx.inc"
};

const u8 sKraid_14_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	3, 5, SPRITESET_IDX(1),
	4, 4, SPRITESET_IDX(2),
	4, 14, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

