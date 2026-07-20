#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_49_Clipdata[182] = {
    #include "extracted/data/rooms/norfair/norfair_49_clipdata.gfx.inc"
};

const u8 sNorfair_49_Bg2[98] = {
    #include "extracted/data/rooms/norfair/norfair_49_bg2.gfx.inc"
};

const u8 sNorfair_49_Bg1[361] = {
    #include "extracted/data/rooms/norfair/norfair_49_bg1.gfx.inc"
};

const u8 sNorfair_49_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	6, 21, SPRITESET_IDX(0),
	12, 7, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_49_Bg0[462] = {
    #include "extracted/data/rooms/norfair/norfair_49_bg0.gfx.inc"
};

