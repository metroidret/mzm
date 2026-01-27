#ifndef BLOCK_H
#define BLOCK_H

#include "types.h"

#include "constants/samus.h"

#include "structs/block.h"

u32 BlockCheckCcaa(struct ClipdataBlockData* pClipBlock);
u32 BlockDestroyNonReformBlock(struct ClipdataBlockData* pClipBlock);
u32 BlockDestroyBombChainBlock(struct ClipdataBlockData* pClipBlock);
u32 BlockDestroySingleBreakableBlock(struct ClipdataBlockData* pClipBlock);
u32 BlockDestroySquareBlock(struct ClipdataBlockData* pClipBlock);
u32 BlockStoreSingleNeverReformBlock(u16 xPosition, u16 yPosition);
void BlockRemoveNeverReformBlocks(void);
void BlockRemoveNeverReformSingleBlock(u8 xPosition, u8 yPosition);
void BlockShiftNeverReformBlocks(void);
u32 BlockCheckRevealOrDestroyNonBombBlock(struct ClipdataBlockData* pClipBlock);
u32 BlockCheckRevealOrDestroyBombBlock(struct ClipdataBlockData* pClipBlock);
u32 BlockApplyCcaa(u16 yPosition, u16 xPosition, u16 trueClip);
boolu32 BlockUpdateMakeSolidBlocks(boolu8 makeSolid, u16 xPosition, u16 yPosition);
boolu32 BlockSamusApplyScrewSpeedboosterDamageToEnvironment(u16 xPosition, u16 yPosition, DestructingAction action);
void BlockUpdateBrokenBlocks(void);
void BlockUpdateBrokenBlockAnimation(struct BrokenBlock* pBlock);
boolu32 BlockStoreBrokenReformBlock(BlockType type, u16 xPosition, u16 yPosition, boolu8 advanceStage);
void BlockStoreBrokenNonReformBlock(u16 xPosition, u16 yPosition, BlockType type);
boolu32 BlockCheckRevealBombChainBlock(BlockType type, u16 xPosition, u16 yPosition);
boolu32 BlockCheckSamusInReformingBlock(u8 xPosition, u8 yPosition);
boolu32 BlockStartBombChain(BombChainType type, u16 xPosition, u16 yPosition);
void BlockProcessBombChains(void);
void BlockCheckStartNewSubBombChain(SubBombChainRequest type, u8 xPosition, u8 yPosition);
void BlockBrokenBlockRemoveCollision(u16 yPosition, u16 xPosition);

#endif /* BLOCK_H */