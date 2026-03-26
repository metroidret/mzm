#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_18_Clipdata[56] = {
    #include "extracted/data/rooms/norfair/norfair_18_clipdata.gfx.inc"
};

const u8 sNorfair_18_Bg2[14] = {
    #include "extracted/data/rooms/norfair/norfair_18_bg2.gfx.inc"
};

const u8 sNorfair_18_Bg1[125] = {
    #include "extracted/data/rooms/norfair/norfair_18_bg1.gfx.inc"
};

const u8 sNorfair_18_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	7, 6, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_18_Bg0[79] = {
    #include "extracted/data/rooms/norfair/norfair_18_bg0.gfx.inc"
};

