#include "data/rooms/test_rooms_data.h"
#include "macros.h"

const u32 sTileset_0_Gfx[445] = {
    #include "extracted/data/rooms/test/tileset_0_tiles.gfx.lz.inc"
};
const u8 sTileset_0_Tilemap[1410] = {
    #include "extracted/data/rooms/test/tileset_0.tm.inc"
};
const u16 sTileset_0_Pal[14 * 16] = {
    #include "extracted/data/rooms/test/tileset_0.pal.inc"
};

const u8 sTest_0_Clipdata[306] = {
    #include "extracted/data/rooms/test/test_0_clipdata.rle.inc"
};
const u8 sTest_0_Bg2[14] = {
    #include "extracted/data/rooms/test/test_0_bg2.rle.inc"
};
const u8 sTest_0_Bg1[369] = {
    #include "extracted/data/rooms/test/test_0_bg1.rle.inc"
};

const u8 sTest_1_Clipdata[446] = {
    #include "extracted/data/rooms/test/test_1_clipdata.rle.inc"
};
const u8 sTest_1_Bg2[14] = {
    #include "extracted/data/rooms/test/test_1_bg2.rle.inc"
};
const u8 sTest_1_Bg1[485] = {
    #include "extracted/data/rooms/test/test_1_bg1.rle.inc"
};

const u8 sTest_2_Clipdata[280] = {
    #include "extracted/data/rooms/test/test_2_clipdata.rle.inc"
};
const u8 sTest_2_Bg2[116] = {
    #include "extracted/data/rooms/test/test_2_bg2.rle.inc"
};
const u8 sTest_2_Bg1[209] = {
    #include "extracted/data/rooms/test/test_2_bg1.rle.inc"
};

const u8 sTest_3_Clipdata[156] = {
    #include "extracted/data/rooms/test/test_3_clipdata.rle.inc"
};
const u8 sTest_3_Bg2[14] = {
    #include "extracted/data/rooms/test/test_3_bg2.rle.inc"
};
const u8 sTest_3_Bg1[159] = {
    #include "extracted/data/rooms/test/test_3_bg1.rle.inc"
};

const u8 sTest_4_Clipdata[314] = {
    #include "extracted/data/rooms/test/test_4_clipdata.rle.inc"
};
const u8 sTest_4_Bg2[14] = {
    #include "extracted/data/rooms/test/test_4_bg2.rle.inc"
};
const u8 sTest_4_Bg1[330] = {
    #include "extracted/data/rooms/test/test_4_bg1.rle.inc"
};

const struct SpriteSpawn sTest1_0_SpriteLayer[2] = {
    { .y = 20, .x = 9, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const struct SpriteSpawn sTest1_1_SpriteLayer[3] = {
    { .y = 45, .x = 30, .id = SPRITESET_IDX(1) },
    { .y = 45, .x = 31, .id = SPRITESET_IDX(2) },
    SPRITE_SPAWN_TERMINATOR
};

const struct SpriteSpawn sTest1_2_SpriteLayer[2] = {
    { .y = 10, .x = 10, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const struct SpriteSpawn sTest1_3_SpriteLayer[2] = {
    { .y = 10, .x = 10, .id = SPRITESET_IDX(0) },
    SPRITE_SPAWN_TERMINATOR
};

const struct SpriteSpawn sTest_4_SpriteLayer[1] = {
    SPRITE_SPAWN_TERMINATOR
};

const struct SpriteSpawn sTest2_0_SpriteLayer[2] = {
    { .y = 4, .x = 10, .id = SPRITESET_IDX(16) },
    SPRITE_SPAWN_TERMINATOR
};

const struct SpriteSpawn sTest2_1_SpriteLayer[1] = {
    SPRITE_SPAWN_TERMINATOR
};

const struct SpriteSpawn sTest2_2_SpriteLayer[1] = {
    SPRITE_SPAWN_TERMINATOR
};

const struct SpriteSpawn sTest2_3_SpriteLayer[2] = {
    SPRITE_SPAWN_TERMINATOR,
    SPRITE_SPAWN_TERMINATOR
};

const struct SpriteSpawn sTest3_0_SpriteLayer[7] = {
    { .y = 3, .x = 14, .id = SPRITESET_IDX(1) },
    { .y = 8, .x = 12, .id = SPRITESET_IDX(3) },
    { .y = 8, .x = 15, .id = SPRITESET_IDX(2) },
    { .y = 7, .x = 21, .id = SPRITESET_IDX(3) },
    { .y = 7, .x = 22, .id = SPRITESET_IDX(2) },
    { .y = 3, .x = 22, .id = SPRITESET_IDX(1) },
    SPRITE_SPAWN_TERMINATOR
};

const struct SpriteSpawn sTest3_1_SpriteLayer[1] = {
    SPRITE_SPAWN_TERMINATOR
};

const struct SpriteSpawn sTest3_2_SpriteLayer[1] = {
    SPRITE_SPAWN_TERMINATOR
};

const struct SpriteSpawn sTest3_3_SpriteLayer[3] = {
    SPRITE_SPAWN_TERMINATOR,
    SPRITE_SPAWN_TERMINATOR
};

