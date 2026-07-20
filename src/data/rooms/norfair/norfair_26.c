#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_26_Clipdata[128] = {
    #include "extracted/data/rooms/norfair/norfair_26_clipdata.gfx.inc"
};

const u8 sNorfair_26_Bg2[14] = {
    #include "extracted/data/rooms/norfair/norfair_26_bg2.gfx.inc"
};

const u8 sNorfair_26_Bg1[364] = {
    #include "extracted/data/rooms/norfair/norfair_26_bg1.gfx.inc"
};

const u8 sNorfair_26_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	8, 16, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_26_Bg0[128] = {
    #include "extracted/data/rooms/norfair/norfair_26_bg0.gfx.inc"
};

