#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_34_Clipdata[55] = {
    #include "extracted/data/rooms/kraid/kraid_34_clipdata.gfx.inc"
};

const u8 sKraid_34_Bg2[147] = {
    #include "extracted/data/rooms/kraid/kraid_34_bg2.gfx.inc"
};

const u8 sKraid_34_Bg1[144] = {
    #include "extracted/data/rooms/kraid/kraid_34_bg1.gfx.inc"
};

const u8 sKraid_34_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	7, 5, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

