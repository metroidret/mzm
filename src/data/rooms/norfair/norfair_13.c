#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_13_Clipdata[54] = {
    #include "extracted/data/rooms/norfair/norfair_13_clipdata.gfx.inc"
};

const u8 sNorfair_13_Bg2[14] = {
    #include "extracted/data/rooms/norfair/norfair_13_bg2.gfx.inc"
};

const u8 sNorfair_13_Bg1[131] = {
    #include "extracted/data/rooms/norfair/norfair_13_bg1.gfx.inc"
};

const u8 sNorfair_13_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	7, 7, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_13_Bg0[79] = {
    #include "extracted/data/rooms/norfair/norfair_13_bg0.gfx.inc"
};

