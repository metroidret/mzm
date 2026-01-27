#ifndef BLOCK_STRUCT_H
#define BLOCK_STRUCT_H

#include "types.h"

#include "constants/block.h"
#include "constants/text.h"

#define MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS 64
#define MAX_AMOUNT_OF_BROKEN_BLOCKS 48
#define MAX_AMOUNT_OF_BOMB_CHAINS 4

struct BrokenBlock {
    boolu8 broken;
    u8 stage;
    BlockType type;
    u8 xPosition;
    u8 yPosition;
    u16 timer;
};

struct ClipdataBlockData {
    u16 xPosition;
    u16 yPosition;
    u16 behavior;
    u8 blockBehavior;
};

struct BombChain {
    u8 currentOffset;
    u8 srcXPosition; 
    u8 srcYPosition;
    BombChainType type:3;
    u8 padding:3;
    u8 flipped:1;
    u8 unk:1;
};

struct TankList {
    u8 energy;
    u8 missile;
    u8 superMissile;
    u8 powerBomb;
};

struct BlockBehavior {
    BlockLifeType lifeType;
    BlockSubType subType;
    BlockType type;
    u8 isSpeedboost:4;
    u8 isBombChain:4;
};

struct BombChainReverseData {
    u8 typeFlag;
    u16 behavior;
};

struct TankBehavior {
    ItemType itemType;
    boolu8 underwater;
    MessageId messageId;
    u16 revealedClipdata;
};

typedef u32 (*BlockFunc_T)(struct ClipdataBlockData*);

extern struct BrokenBlock gBrokenBlocks[MAX_AMOUNT_OF_BROKEN_BLOCKS];
extern u16 gMakeSolidBlocks[MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS];
extern struct BombChain gBombChains[MAX_AMOUNT_OF_BOMB_CHAINS];
extern u8 gActiveBombChainTypes;

#endif /* BLOCK_STRUCT_H */
