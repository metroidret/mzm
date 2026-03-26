#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_51_Clipdata[32] = {
    #include "extracted/data/rooms/norfair/norfair_51_clipdata.gfx.inc"
};

const u8 sNorfair_51_Bg2[505] = {
    #include "extracted/data/rooms/norfair/norfair_51_bg2.gfx.inc"
};

const u8 sNorfair_51_Bg1[] = {
    #include "extracted/data/rooms/norfair/norfair_51_bg1.gfx.inc"
};

const u8 sNorfair_51_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_51_Bg0[270] = {
    #include "extracted/data/rooms/norfair/norfair_51_bg0.gfx.inc"
};

