#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_13_Clipdata[118] = {
    #include "extracted/data/rooms/ridley/ridley_13_clipdata.gfx.inc"
};

const u8 sRidley_13_Bg2[401] = {
    #include "extracted/data/rooms/ridley/ridley_13_bg2.gfx.inc"
};

const u8 sRidley_13_Bg1[245] = {
    #include "extracted/data/rooms/ridley/ridley_13_bg1.gfx.inc"
};

const u8 sRidley_13_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	7, 15, SPRITESET_IDX(1),
	9, 20, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_13_Bg0[43] = {
    #include "extracted/data/rooms/ridley/ridley_13_bg0.gfx.inc"
};

