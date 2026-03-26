#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_40_Clipdata[64] = {
    #include "extracted/data/rooms/kraid/kraid_40_clipdata.gfx.inc"
};

const u8 sKraid_40_Bg2[62] = {
    #include "extracted/data/rooms/kraid/kraid_40_bg2.gfx.inc"
};

const u8 sKraid_40_Bg1[151] = {
    #include "extracted/data/rooms/kraid/kraid_40_bg1.gfx.inc"
};

const u8 sKraid_40_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

