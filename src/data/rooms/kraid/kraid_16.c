#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_16_Clipdata[66] = {
    #include "extracted/data/rooms/kraid/kraid_16_clipdata.gfx.inc"
};

const u8 sKraid_16_Bg2[14] = {
    #include "extracted/data/rooms/kraid/kraid_16_bg2.gfx.inc"
};

const u8 sKraid_16_Bg1[171] = {
    #include "extracted/data/rooms/kraid/kraid_16_bg1.gfx.inc"
};

const u8 sKraid_16_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

