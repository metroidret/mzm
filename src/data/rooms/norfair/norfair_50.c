#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_50_Clipdata[32] = {
    #include "extracted/data/rooms/norfair/norfair_50_clipdata.gfx.inc"
};

const u8 sNorfair_50_Bg2[122] = {
    #include "extracted/data/rooms/norfair/norfair_50_bg2.gfx.inc"
};

const u8 sNorfair_50_Bg1[289] = {
    #include "extracted/data/rooms/norfair/norfair_50_bg1.gfx.inc"
};

const u8 sNorfair_50_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

