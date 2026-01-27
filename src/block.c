#include "block.h"
#include "macros.h"
#include "dma.h"
#include "gba.h"
#include "bg_clip.h"

#include "data/block_data.h"

#include "constants/audio.h"
#include "constants/block.h"
#include "constants/clipdata.h"
#include "constants/samus.h"

#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/game_state.h"
#include "structs/samus.h"
#include "structs/power_bomb_explosion.h"

/**
 * @brief 590b0 | 214 | Checks if something should happen to a block depending on the Ccaa
 * 
 * @param pClipBlock Clipdata Block Data Pointer
 * @return u32 1 if detroyed, 0 otherwise
 */
u32 BlockCheckCcaa(struct ClipdataBlockData* pClipBlock)
{
    u32 result;
    u32 bombChainType;
    u32 destroy;
    u16 block;

    result = FALSE;

    block = BEHAVIOR_TO_BLOCK(pClipBlock->behavior);
    // Check is block
    if (block <= BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_UNDERWATER_POWER_BOMB_TANK))
    {
        // Get block behavior
        pClipBlock->blockBehavior = BEHAVIOR_TO_BLOCK(pClipBlock->behavior);

        if (gCurrentClipdataAffectingAction == CAA_SPEEDBOOSTER_ON_GROUND)
        {
            if (!sBlockBehaviors[pClipBlock->blockBehavior].isSpeedboost)
                return result;
            
            gCurrentClipdataAffectingAction = CAA_SPEEDBOOSTER;
        }
        else if (gCurrentClipdataAffectingAction == CAA_BOMB_CHAIN)
        {
            if (!sBlockBehaviors[pClipBlock->blockBehavior].isBombChain)
                return result;
        }

        destroy = TRUE;
        bombChainType = BOMB_CHAIN_TYPE_VERTICAL1;

        // Apply behavior
        switch (pClipBlock->blockBehavior)
        {
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_TOP_RIGHT_SHOT_BLOCK_NEVER_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_TOP_RIGHT_SHOT_BLOCK_NO_REFORM):
                pClipBlock->xPosition--;
                break;
    
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_RIGHT_SHOT_BLOCK_NEVER_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_RIGHT_SHOT_BLOCK_NO_REFORM):
                pClipBlock->xPosition--;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_LEFT_SHOT_BLOCK_NEVER_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOTTOM_LEFT_SHOT_BLOCK_NO_REFORM):
                pClipBlock->yPosition--;
                break;
            
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOMB_BLOCK_NEVER_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_BOMB_BLOCK_REFORM):
                destroy = BlockCheckRevealOrDestroyBombBlock(pClipBlock);
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_MISSILE_BLOCK_NEVER_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_MISSILE_BLOCK_NO_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SUPER_MISSILE_BLOCK_NEVER_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SUPER_MISSILE_BLOCK_NO_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SPEEDBOOST_BLOCK_NO_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SPEEDBOOST_BLOCK_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_POWER_BOMB_BLOCK_NEVER_REFORM):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SCREW_ATTACK_BLOCK_NO_REFORM):
                destroy = BlockCheckRevealOrDestroyNonBombBlock(pClipBlock);
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_CRUMBLE_BLOCK):
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_SLOW_CRUMBLE_BLOCK):
                BlockCheckRevealOrDestroyNonBombBlock(pClipBlock);
                destroy = FALSE;
                break;
            
            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN1):
                bombChainType = BOMB_CHAIN_TYPE_VERTICAL1;
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN2):
                bombChainType = BOMB_CHAIN_TYPE_VERTICAL2;
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN3):
                bombChainType = BOMB_CHAIN_TYPE_VERTICAL3;
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_VERTICAL_BOMB_CHAIN4):
                bombChainType = BOMB_CHAIN_TYPE_VERTICAL4;
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN1):
                bombChainType = BOMB_CHAIN_TYPE_HORIZONTAL1;
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN2):
                bombChainType = BOMB_CHAIN_TYPE_HORIZONTAL2;
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN3):
                bombChainType = BOMB_CHAIN_TYPE_HORIZONTAL3;
                break;

            case BEHAVIOR_TO_BLOCK(CLIP_BEHAVIOR_HORIZONTAL_BOMB_CHAIN4):
                bombChainType = BOMB_CHAIN_TYPE_HORIZONTAL4;
                break;
        }
    }
    else
        return FALSE;

    // Abort if nothing happened
    if (!destroy)
        return FALSE;

    // Apply life type
    switch (sBlockBehaviors[pClipBlock->blockBehavior].lifeType)
    {
        case BLOCK_LIFE_TYPE_NO_NEVER_REFORM:
            if (BlockDestroyNonReformBlock(pClipBlock))
                result = TRUE;
            break;

        case BLOCK_LIFE_TYPE_REFORM:
            if (BlockStoreBrokenReformBlock(sBlockBehaviors[pClipBlock->blockBehavior].type,
                pClipBlock->xPosition, pClipBlock->yPosition, FALSE))
                result = TRUE;
            break;

        case BLOCK_LIFE_TYPE_BOMB_CHAIN:
            if (!BlockCheckRevealOrDestroyBombBlock(pClipBlock))
                break;

            // Check type isn't already active
            if (gActiveBombChainTypes & sBombChainReverseData[bombChainType].typeFlag)
                break;

            if (BlockStartBombChain(bombChainType, pClipBlock->xPosition, pClipBlock->yPosition))
            {
                // Destroy block
                if (BlockDestroyNonReformBlock(pClipBlock))
                    result = TRUE;
            }
            break;

        case BLOCK_LIFE_TYPE_TANK:
            // Check should reveal
            if (sClipdataAffectingActionDamageTypes[gCurrentClipdataAffectingAction] & TANK_WEAKNESS)
            {
                destroy = sTankBehaviors[BEHAVIOR_TO_TANK(pClipBlock->behavior)].revealedClipdata;
                if (destroy != CLIPDATA_AIR)
                {
                    BgClipSetBg1BlockValue(destroy, pClipBlock->yPosition, pClipBlock->xPosition);
                    BgClipSetClipdataBlockValue(destroy, pClipBlock->yPosition, pClipBlock->xPosition);
                    result = TRUE;
                }
            }
    }

    return result;
}

static BlockFunc_T sNonReformDestroyFunctionPointers[BLOCK_SUB_TYPE_COUNT] = {
    [BLOCK_SUB_TYPE_REFORM] = BlockDestroySingleBreakableBlock,
    [BLOCK_SUB_TYPE_SQUARE_NO_REFORM] = BlockDestroySquareBlock,
    [BLOCK_SUB_TYPE_NO_REFORM] = BlockDestroySingleBreakableBlock,
    [BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM] = BlockDestroySquareBlock,
    [BLOCK_SUB_TYPE_BOMB_CHAIN] = BlockDestroyBombChainBlock
};

/**
 * @brief 592c4 | 6c | Handles the destruction of non reform blocks
 * 
 * @param pClipBlock Clipdata Block Data Pointer
 * @return u32 bool, could destroy
 */
u32 BlockDestroyNonReformBlock(struct ClipdataBlockData* pClipBlock)
{
    u32 subType;
    u32 result;

    result = FALSE;
    subType = sBlockBehaviors[pClipBlock->blockBehavior].subType;

    switch (subType)
    {
        case BLOCK_SUB_TYPE_REFORM:
        case BLOCK_SUB_TYPE_SQUARE_NO_REFORM:
        case BLOCK_SUB_TYPE_BOMB_CHAIN:
            // Nothing special to do
            break;

        case BLOCK_SUB_TYPE_NO_REFORM:
        case BLOCK_SUB_TYPE_SQUARE_NEVER_REFORM:
            // Store a never reform bock
            result = BlockStoreSingleNeverReformBlock(pClipBlock->xPosition, pClipBlock->yPosition);
            break;

        default:
            result = TRUE;
    }

    if (result)
        return FALSE;

    // Run special handler depending on the type
    result = sNonReformDestroyFunctionPointers[subType](pClipBlock);
    return result;
}

/**
 * @brief 59330 | 3c | Destroys a single bomb chain block
 * 
 * @param pClipBlock Clipdata Block Data Pointer
 * @return u8 TRUE
 */
u32 BlockDestroyBombChainBlock(struct ClipdataBlockData* pClipBlock)
{
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, sBlockBehaviors[pClipBlock->blockBehavior].type);
    SET_CLIP_BLOCK(CLIPDATA_AIR, pClipBlock->xPosition, pClipBlock->yPosition);
    return TRUE;
}

/**
 * @brief 5936c | 3c | Destroys a single block
 * 
 * @param pClipBlock Clipdata Block Data Pointer
 * @return u8 TRUE
 */
u32 BlockDestroySingleBreakableBlock(struct ClipdataBlockData* pClipBlock)
{
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, sBlockBehaviors[pClipBlock->blockBehavior].type);
    SET_CLIP_BLOCK(CLIPDATA_AIR, pClipBlock->xPosition, pClipBlock->yPosition);
    return TRUE;
}

/**
 * @brief 593a8 | d8 | Destroys a square block
 * 
 * @param pClipBlock Clipdata Block Data Pointer
 * @return u8 TRUE
 */
u32 BlockDestroySquareBlock(struct ClipdataBlockData* pClipBlock)
{
    u8 blockType;

    blockType = sBlockBehaviors[pClipBlock->blockBehavior].type;

    // Destroy top left
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, blockType);
    SET_CLIP_BLOCK(CLIPDATA_AIR, pClipBlock->xPosition, pClipBlock->yPosition);

    // Destroy bottom right
    pClipBlock->xPosition++;
    pClipBlock->yPosition++;
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, blockType);
    SET_CLIP_BLOCK(CLIPDATA_AIR, pClipBlock->xPosition, pClipBlock->yPosition);
    
    // Destroy top right
    pClipBlock->yPosition--;
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, blockType);
    SET_CLIP_BLOCK(CLIPDATA_AIR, pClipBlock->xPosition, pClipBlock->yPosition);
    
    // Destroy bottom left
    pClipBlock->xPosition--;
    pClipBlock->yPosition++;
    BlockStoreBrokenNonReformBlock(pClipBlock->xPosition, pClipBlock->yPosition, blockType);
    SET_CLIP_BLOCK(CLIPDATA_AIR, pClipBlock->xPosition, pClipBlock->yPosition);

    // Play sound
    if (gCurrentClipdataAffectingAction != CAA_SPEEDBOOSTER)
        SoundPlayNotAlreadyPlaying(SOUND_SQUARE_BLOCK_DESTROYED);

    return TRUE;
}

/**
 * @brief 59480 | 80 | Stores a single never reform block in the save array
 * 
 * @param xPosition X position
 * @param yPosition Y position
 * @return u32 bool, couldn't store
 */
u32 BlockStoreSingleNeverReformBlock(u16 xPosition, u16 yPosition)
{
    u32 overLimit;
    u8* pBlock;
    s32 i;

    if (gCurrentArea >= MAX_AMOUNT_OF_AREAS)
        return FALSE;

    if (xPosition * yPosition == 0)
        return FALSE;

    overLimit = TRUE;
    pBlock = gNeverReformBlocks[gCurrentArea];
    i = gNumberOfNeverReformBlocks[gCurrentArea] * NEVER_REFORM_BLOCK_INFO_SIZE;

    // Find empty slot
    for (; i < NEVER_REFORM_BLOCKS_SIZE - 4; i += NEVER_REFORM_BLOCK_INFO_SIZE)
    {
        if (pBlock[i] == UCHAR_MAX)
        {
            overLimit = FALSE;
            break;
        }
    }

    if (!overLimit)
    {
        pBlock[i++] = xPosition;
        pBlock[i] = yPosition;
    }

    return overLimit;
}

/**
 * @brief 59500 | 80 | Removes the broken never reform blocks of a room
 * 
 */
void BlockRemoveNeverReformBlocks(void)
{
    s32 i;
    s32 var_0;
    u8* pBlock;
    s32 limit;

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
        i = TRUE;
    else
        i = FALSE;

    if (gCurrentArea >= MAX_AMOUNT_OF_AREAS)
        i = TRUE;

    if (i)
        return;

    pBlock = gNeverReformBlocks[gCurrentArea];
    limit = gNumberOfNeverReformBlocks[gCurrentArea] * NEVER_REFORM_BLOCK_INFO_SIZE;
    for (var_0 = 0; i < limit; i += NEVER_REFORM_BLOCK_INFO_SIZE)
    {
        if (pBlock[i + 0] == 0)
            var_0 = 1;

        if (var_0 == 1)
        {
            if (pBlock[i + 1] == gCurrentRoom)
                var_0 = 2;
            else
                var_0 = 0;
        }
        else if (var_0 == 2)
        {
            BlockRemoveNeverReformSingleBlock(pBlock[i + 0], pBlock[i + 1]);
        }
    }
}

/**
 * @brief 59580 | 64 | Removes a never reform block from the BG1 and clipdata
 * 
 * @param xPosition X position
 * @param yPosition Y position
 */
void BlockRemoveNeverReformSingleBlock(u8 xPosition, u8 yPosition)
{
    u16 behavior;
    u32 position;

    // Get position
    position = gBgPointersAndDimensions.clipdataWidth * yPosition + xPosition;

    // Get previous behavior
    behavior = gTilemapAndClipPointers.pClipBehaviors[gBgPointersAndDimensions.pClipDecomp[position]];

    // Clear clipdata and bg1
    gBgPointersAndDimensions.pClipDecomp[position] = 0;
    gBgPointersAndDimensions.backgrounds[1].pDecomp[position] = 0;

    if (behavior == CLIP_BEHAVIOR_TOP_LEFT_SHOT_BLOCK_NEVER_REFORM)
    {
        // Clear the rest of the 2x2 block
        gBgPointersAndDimensions.pClipDecomp[position + 1] = 0;
        gBgPointersAndDimensions.backgrounds[1].pDecomp[position + 1] = 0;

        position += gBgPointersAndDimensions.clipdataWidth;
        gBgPointersAndDimensions.pClipDecomp[position] = 0;
        gBgPointersAndDimensions.backgrounds[1].pDecomp[position] = 0;
        position++;

        gBgPointersAndDimensions.pClipDecomp[position] = 0;
        gBgPointersAndDimensions.backgrounds[1].pDecomp[position] = 0;
    }
}

/**
 * @brief 595e4 | 18c | Shifts and reorganizes the never reform blocks when transitioning
 * 
 */
void BlockShiftNeverReformBlocks(void)
{
    u8* src;
    u8* dst;
    s32 amount;
    s32 var_0;
    s32 i;

    src = (u8*)gNeverReformBlocks[gAreaBeforeTransition];
    if (src[gNumberOfNeverReformBlocks[gAreaBeforeTransition] * NEVER_REFORM_BLOCK_INFO_SIZE] == UCHAR_MAX)
        return;

    dst = EWRAM_BASE;
    DmaTransfer(3, src, dst, NEVER_REFORM_BLOCKS_SIZE, 16);
    BitFill(3, USHORT_MAX, src, NEVER_REFORM_BLOCKS_SIZE, 16);

    var_0 = 0;
    amount = 0;
    i = 0;

    while (amount < gNumberOfNeverReformBlocks[gAreaBeforeTransition] * NEVER_REFORM_BLOCK_INFO_SIZE)
    {
        if (dst[amount] == 0)
        {
            if (var_0 == 1)
                var_0 = 10;
            else if (var_0 == 0 && dst[i + 1] == gCurrentRoom)
                var_0 = 1;
        }

        if (var_0 < 10)
        {
            src[i++] = dst[amount++];
            src[i++] = dst[amount++];
        }
        else if (var_0 == 10)
        {
            dst = EWRAM_BASE + gNumberOfNeverReformBlocks[gAreaBeforeTransition] * 2;
            while (*dst != UCHAR_MAX)
            {
                src[i++] = *dst++;
                src[i++] = *dst++;
            }

            var_0 = 2;
            dst = EWRAM_BASE;
        }
    }

    if (var_0 != 2)
    {
        if (var_0 != 1)
        {
            src[i++] = 0;
            src[i++] = gCurrentRoom;
        }

        dst = EWRAM_BASE + gNumberOfNeverReformBlocks[gAreaBeforeTransition] * NEVER_REFORM_BLOCK_INFO_SIZE;
        while (*dst != UCHAR_MAX)
        {
            src[i++] = *dst++;
            src[i++] = *dst++;
        }
    }

    gNumberOfNeverReformBlocks[gAreaBeforeTransition] = DIV_SHIFT(i, NEVER_REFORM_BLOCK_INFO_SIZE);
}

/**
 * @brief 59770 | 84 | Checks if a non bomb block should be destroyed
 * 
 * @param pClipBlock Clipdata block data pointer
 * @return u32 bool, destroy
 */
u32 BlockCheckRevealOrDestroyNonBombBlock(struct ClipdataBlockData* pClipBlock)
{
    s32 blockType;

    // Get block type
    blockType = sBlockBehaviors[pClipBlock->blockBehavior].type;

    // Check for block weakness
    if (sClipdataAffectingActionDamageTypes[gCurrentClipdataAffectingAction] & sBlockWeaknesses[blockType])
    {
        // Block is weak to current action, hence it can be destroyed
        return TRUE;
    }
    
    // Check weaknesses to reveal
    if (gCurrentClipdataAffectingAction != CAA_BOMB_PISTOL && (gCurrentClipdataAffectingAction != CAA_POWER_BOMB ||
        gCurrentPowerBomb.owner))
        return FALSE;

    // Check isn't already revealed
    if (pClipBlock->behavior != sReformingBlocksTilemapValue[blockType])
    {
        // Reveal
        BgClipSetBg1BlockValue(sReformingBlocksTilemapValue[blockType], pClipBlock->yPosition, pClipBlock->xPosition);
        BgClipSetClipdataBlockValue(sReformingBlocksTilemapValue[blockType], pClipBlock->yPosition, pClipBlock->xPosition);
    }

    return FALSE;
}

/**
 * @brief 597f4 | 88 | Checks if a bomb block should be destroyed
 * 
 * @param pClipBlock Clipdata block data pointer
 * @return u32 bool, destroy
 */
u32 BlockCheckRevealOrDestroyBombBlock(struct ClipdataBlockData* pClipBlock)
{
    s32 blockType;
    u16 value;
    u32 reveal;

    // Get block type
    blockType = sBlockBehaviors[pClipBlock->blockBehavior].type;

    // Check for block weakness
    if (sClipdataAffectingActionDamageTypes[gCurrentClipdataAffectingAction] & sBlockWeaknesses[blockType])
    {
        // Block is weak to current action, hence it can be destroyed
        return TRUE;
    }

    // Check weaknesses to reveal and isn't already revealed
    if (sClipdataAffectingActionDamageTypes[gCurrentClipdataAffectingAction] & CAA_REVEAL_BOMB_BLOCKS &&
        pClipBlock->behavior != sReformingBlocksTilemapValue[blockType])
    {
        reveal = TRUE;
        value = sReformingBlocksTilemapValue[blockType];

        if (blockType > BLOCK_TYPE_BOMB_BLOCK_NEVER_REFORM)
        {
            // Handle the special case of bomb chain blocks
            reveal = BlockCheckRevealBombChainBlock(blockType, pClipBlock->xPosition, pClipBlock->yPosition);
        }

        if (!reveal)
            return FALSE;

        // Reveal block
        BgClipSetBg1BlockValue(value, pClipBlock->yPosition, pClipBlock->xPosition);
        BgClipSetClipdataBlockValue(value, pClipBlock->yPosition, pClipBlock->xPosition);
    }

    return FALSE;
}

/**
 * @brief 5987c | 164 | Applies the Ccaa (Current Clipdata Affecting Action)
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param trueClip True clipdata block value
 * @return u32 bool, block changed
 */
u32 BlockApplyCcaa(u16 yPosition, u16 xPosition, u16 trueClip)
{
    struct ClipdataBlockData clipBlock;
    u32 result;

    // Create clipdata block data structure
    clipBlock.xPosition = xPosition;
    clipBlock.yPosition = yPosition;
    clipBlock.behavior = gTilemapAndClipPointers.pClipBehaviors[trueClip];
    clipBlock.blockBehavior = 0;

    result = FALSE;

    switch (gCurrentClipdataAffectingAction)
    {
        case CAA_BEAM:
        case CAA_BOMB_PISTOL:
        case CAA_MISSILE:
        case CAA_SUPER_MISSILE:
        case CAA_POWER_BOMB:
            // Check on hatch
            if (gTilemapAndClipPointers.pClipCollisions[trueClip] == CLIPDATA_TYPE_DOOR &&
                BgClipCheckOpeningHatch(clipBlock.xPosition, clipBlock.yPosition) != HATCH_OPENING_ACTION_NOT_OPENING)
            {
                result = TRUE;
            }
            else
            {
                // Check on block
                if (BlockCheckCcaa(&clipBlock))
                    result = TRUE;
            }
            break;

        case CAA_SPEEDBOOSTER:
        case CAA_SPEEDBOOSTER_ON_GROUND:
            if (BlockCheckCcaa(&clipBlock))
            {
                SoundPlayNotAlreadyPlaying(SOUND_BLOCK_DESTROYED_WITH_SPEEDBOOSTER);
                result = TRUE;
            }
            break;

        case CAA_SCREW_ATTACK:
            if (BlockCheckCcaa(&clipBlock))
            {
                SoundPlayNotAlreadyPlaying(SOUND_BLOCK_DESTROYED_WITH_SCREW_ATTACK);
                result = TRUE;
            }
            break;

        case CAA_BOMB_CHAIN:
        case CAA_BOMB_CHAIN_UNUSED:
            if (BlockCheckCcaa(&clipBlock))
                result = TRUE;
            break;

        case CAA_REMOVE_SOLID:
            if (!BlockUpdateMakeSolidBlocks(FALSE, xPosition, yPosition))
                BgClipSetBg1BlockValue(0, yPosition, xPosition);

            BgClipSetClipdataBlockValue(0, yPosition, xPosition);
            break;

        case CAA_MAKE_SOLID_GRIPPABLE:
            result = BlockUpdateMakeSolidBlocks(TRUE, xPosition, yPosition);
            if (result)
                BgClipSetClipdataBlockValue(CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID2, yPosition, xPosition);
            break;

        case CAA_MAKE_STOP_ENEMY:
            result = BlockUpdateMakeSolidBlocks(TRUE, xPosition, yPosition);
            if (result)
                BgClipSetClipdataBlockValue(CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_STOP_ENEMY_AIR, yPosition, xPosition);
            break;

        case CAA_MAKE_NON_POWER_GRIP:
            result = BlockUpdateMakeSolidBlocks(TRUE, xPosition, yPosition);
            if (result)
                BgClipSetClipdataBlockValue(CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_NON_POWER_GRIP, yPosition, xPosition);
            break;
    }

    return result;
}

/**
 * @brief 599e0 | b8 | Updates the "make solid blocks" array
 * 
 * @param makeSolid Make solid flag
 * @param xPosition X Position
 * @param yPosition Y Position
 * @return boolu32 could store
 */
boolu32 BlockUpdateMakeSolidBlocks(boolu8 makeSolid, u16 xPosition, u16 yPosition)
{
    u32 result;
    s32 i;
    u16* pBlocks;

    result = FALSE;

    if (!makeSolid)
    {
        // Remove solid
        pBlocks = gMakeSolidBlocks;
        for (i = MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS; i > 0; i--)
        {
            if (pBlocks[--i] == C_16_2_8(xPosition, yPosition))
            {
                // Found in the array, remove
                pBlocks[i] = 0;
                result = TRUE;
                break;
            }
        }
    }
    else
    {
        // Make solid
        pBlocks = gMakeSolidBlocks;
        for (i = MAX_AMOUNT_OF_MAKE_SOLID_BLOCKS; i > 0; i--)
        {
            if (pBlocks[--i] == C_16_2_8(xPosition, yPosition))
            {
                // Already in the array
                i = UCHAR_MAX;
                break;
            }
            else if (pBlocks[i] == 0)
            {
                // Found empty space
                break;
            }
        }

        result = FALSE;
        if (i != UCHAR_MAX)
        {
            if (GET_CLIP_BLOCK_(xPosition, yPosition) == CLIPDATA_AIR)
            {
                // Store if no block
                pBlocks[i] = C_16_2_8(xPosition, yPosition);
                result = TRUE;
            }
        }
    }

    return result;
}

/**
 * @brief 59a9c | b8 | Applies the speedbooster/screw attack destructing action
 * 
 * @param xPosition X Position
 * @param yPosition Y Position
 * @param action Destructing action
 * @return boolu32 block destroyed
 */
boolu32 BlockSamusApplyScrewSpeedboosterDamageToEnvironment(u16 xPosition, u16 yPosition, DestructingAction action)
{
    u16 blockY;
    u16 blockX;
    u16 clipdata;
    u16 result;
    u16 position;

    blockX = xPosition / BLOCK_SIZE;
    blockY = yPosition / BLOCK_SIZE;

    if (blockX < gBgPointersAndDimensions.clipdataWidth && blockY < gBgPointersAndDimensions.clipdataHeight)
    {
        // Set Ccaa
        if (action == DESTRUCTING_ACTION_SPEED)
            gCurrentClipdataAffectingAction = CAA_SPEEDBOOSTER;
        else if (action == DESTRUCTING_ACTION_SCREW)
            gCurrentClipdataAffectingAction = CAA_SCREW_ATTACK;
        else if (action == DESTRUCTING_ACTION_SPEED_SCREW)
            gCurrentClipdataAffectingAction = CAA_SCREW_ATTACK;
        else if (action == DESTRUCTING_ACTION_SPEED_ON_GROUND)
            gCurrentClipdataAffectingAction = CAA_SPEEDBOOSTER_ON_GROUND;
        else
            return FALSE;

        // Get clipdata block
        position = gBgPointersAndDimensions.clipdataWidth * blockY + blockX;
        clipdata = gBgPointersAndDimensions.pClipDecomp[position];

        if (clipdata != CLIPDATA_AIR)
        {
            // Apply first
            result = BlockApplyCcaa(blockY, blockX, clipdata);

            if (!result && action == DESTRUCTING_ACTION_SPEED_SCREW)
            {
                // Apply second
                gCurrentClipdataAffectingAction = CAA_SPEEDBOOSTER;
                BlockApplyCcaa(blockY, blockX, clipdata);
            }
        }
        #ifdef BUGFIX
        else
        {
            result = FALSE;
        }
        #endif // BUGFIX
    }
    else
    {
        return FALSE;
    }

    // Clear Ccaa
    gCurrentClipdataAffectingAction = CAA_NONE;

    // BUG: result is never set if Samus isn't colliding with any non air tile
    return result;
}

/**
 * @brief 59b54 | 120 | Updates the broken blocks
 * 
 */
void BlockUpdateBrokenBlocks(void)
{
    struct BrokenBlock* pBlock;
    s32 i;
    u32 updateStage;

    pBlock = gBrokenBlocks;

    for (i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; i++, pBlock++)
    {
        // Check exists
        if (pBlock->stage == 0)
            continue;

        // Update timer
        APPLY_DELTA_TIME_INC(pBlock->timer);

        if (pBlock->broken)
        {
            if (pBlock->timer < sBrokenBlocksTimers[pBlock->type][pBlock->stage])
                continue;

            updateStage = FALSE;
            pBlock->timer = 0;

            if (pBlock->stage >= ARRAY_SIZE(sBrokenBlocksTimers[0]))
            {
                if (BlockCheckSamusInReformingBlock(pBlock->xPosition, pBlock->yPosition))
                {
                    pBlock->stage = 2;
                }
                else
                {
                    BgClipSetClipdataBlockValue(sReformingBlocksTilemapValue[pBlock->type], pBlock->yPosition, pBlock->xPosition);
                    pBlock->broken = FALSE;
                    pBlock->stage = 0;
                    pBlock->type = BLOCK_TYPE_NONE;
                    pBlock->xPosition = 0;
                    pBlock->yPosition = 0;
                }
            }
            else if (pBlock->stage == 7)
            {
                if (BlockCheckSamusInReformingBlock(pBlock->xPosition, pBlock->yPosition))
                    pBlock->timer = sBrokenBlocksTimers[pBlock->type][pBlock->stage] / 2;
                else
                    updateStage = TRUE;
            }
            else
            {
                if (pBlock->stage == 1)
                    BlockBrokenBlockRemoveCollision(pBlock->yPosition, pBlock->xPosition);

                updateStage = TRUE;
            }

            if (updateStage)
            {
                pBlock->stage++;
                BlockUpdateBrokenBlockAnimation(pBlock);
            }
        }
        else if (pBlock->timer >= sBrokenBlocksTimers[pBlock->type][pBlock->stage])
        {
            pBlock->timer = 0;
            pBlock->stage++;

            BlockUpdateBrokenBlockAnimation(pBlock);

            if (pBlock->stage > 6)
            {
                pBlock->broken = FALSE;
                pBlock->stage = 0;
                pBlock->type = BLOCK_TYPE_NONE;
                pBlock->xPosition = 0;
                pBlock->yPosition = 0;
            }
        }
    }
}

/**
 * @brief 59c74 | 134 | Updates the animation of a breaking block
 * 
 * @param pBlock Broken block pointer
 */
void BlockUpdateBrokenBlockAnimation(struct BrokenBlock* pBlock)
{
    u16 value;
    u16* dst;
    u16* src;
    s32 offset;

    value = CLIPDATA_TILEMAP_AIR;

    // Get clipdata tilemap value
    switch (pBlock->stage)
    {
        case 2:
        case 12:
            value = sReformingBlocksTilemapValue[pBlock->type];
            break;

        case 3:
        case 11:
            value = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID;
            break;

        case 4:
        case 10:
            value = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID_BREAKING_1;
            break;

        case 5:
        case 9:
            value = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID_BREAKING_2;
            break;

        case 6:
        case 8:
            value = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_SOLID_BREAKING_3;
            break;

        case 7:
            value = CLIPDATA_TILEMAP_FLAG | CLIPDATA_TILEMAP_AIR;
            break;

        case 0:
        case 1:
        case 13:
            break;
    }

    // No tile, abort
    if (value == CLIPDATA_TILEMAP_AIR)
        return;

    // Write value to BG1 map
    SET_BG_BLOCK(1, value, pBlock->xPosition, pBlock->yPosition);

    // Check is on screen, no need to update the tilemap if off screen, that can be delegated to the room tilemap update functions
    offset = SUB_PIXEL_TO_BLOCK(gBg1YPosition);
    if (offset - 4 > pBlock->yPosition || pBlock->yPosition > offset + 13)
        return;

    offset = SUB_PIXEL_TO_BLOCK(gBg1XPosition);
    if (offset - 4 > pBlock->xPosition || pBlock->xPosition > offset + 18)
        return;

    // Apply to tilemap
    dst = VRAM_BASE + 0x1000;
    if (pBlock->xPosition & 0x10)
        dst = VRAM_BASE + 0x1800;

    offset = (pBlock->xPosition & 0xF) * 2;
    dst += (pBlock->yPosition & 0xF) * 64 + offset;

    offset = value * 4;
    src = gTilemapAndClipPointers.pTilemap;
    dst[0] = src[offset++];
    dst[1] = src[offset++];
    dst[32] = src[offset++];
    dst[33] = src[offset];
}

/**
 * @brief 59da8 | ac | Stores a new broken block (that reforms)
 * 
 * @param type Block type
 * @param xPosition X Position
 * @param yPosition Y Position
 * @param advanceStage Starts the block at stage 2 if true
 * @return u32 1 if could store, 0 otherwise
 */
boolu32 BlockStoreBrokenReformBlock(BlockType type, u16 xPosition, u16 yPosition, boolu8 advanceStage)
{
    u32 result;
    s32 i;
    struct BrokenBlock* pBlock;

    result = FALSE;
    pBlock = gBrokenBlocks;
    for (i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS;)
    {
        if (pBlock->xPosition == xPosition && pBlock->yPosition == yPosition)
        {
            // Already in array
            if (pBlock->stage == 0)
                result = TRUE;
            else
                result = FALSE;
            break;
        }
        else
        {
            // Check save empty offset
            if (!(result & 0x80) && pBlock->stage == 0)
                result = i | 0x80; // Store empty offset
        }

        i++;
        pBlock++;
    }

    // Empty space was found
    if (result)
    {
        // Get offset
        if (result != TRUE)
            i = result & 0x7F;

        pBlock = gBrokenBlocks + i;

        // Store block
        pBlock->broken = TRUE;
        pBlock->type = type;
        pBlock->timer = 0;

        if (result & 0x80)
        {
            pBlock->xPosition = xPosition;
            pBlock->yPosition = yPosition;
        }

        if (!advanceStage)
        {
            pBlock->stage = 2;
            BlockBrokenBlockRemoveCollision(yPosition, xPosition);
            BlockUpdateBrokenBlockAnimation(pBlock);
        }
        else
        {
            pBlock->stage = 1;
        }

        result = TRUE;
    }

    return result;
}

/**
 * @brief 59e54 | a4 | Stores a new broken block (that doesn't reform)
 * 
 * @param xPosition X Position
 * @param yPosition Y Position
 * @param type Block type
 */
void BlockStoreBrokenNonReformBlock(u16 xPosition, u16 yPosition, BlockType type)
{
    struct BrokenBlock* pBlock;
    s32 i;
    s32 stage;

    for (pBlock = gBrokenBlocks, i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; i++, pBlock++)
    {
        if (pBlock->stage == 0)
        {
            // Found slot
            pBlock->broken = FALSE;
            pBlock->stage = 2;
            pBlock->type = type;
            pBlock->timer = 0;
            pBlock->xPosition = xPosition;
            pBlock->yPosition = yPosition;

            BlockUpdateBrokenBlockAnimation(pBlock);
            return;
        }
    }

    for (stage = 4; stage != 0; stage >>= 1)
    {
        for (pBlock = gBrokenBlocks, i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; i++, pBlock++)
        {
            // Already broken
            if (pBlock->broken)
                continue;

            // Not far enough
            if (pBlock->stage < stage)
                continue;

            // Remove bg1
            BgClipSetBg1BlockValue(0, pBlock->yPosition, pBlock->xPosition);

            // Register
            pBlock->broken = FALSE;
            pBlock->stage = 2;
            pBlock->type = type;
            pBlock->timer = 0;
            pBlock->xPosition = xPosition;
            pBlock->yPosition = yPosition;

            BlockUpdateBrokenBlockAnimation(&gBrokenBlocks[i]);
            return;
        }
    }
}

/**
 * @brief 59ef8 | 78 | Reveals a bomb chain block
 * 
 * @param type Block type
 * @param xPosition X Position
 * @param yPosition Y Position
 * @return u32 1 if was revealed, 0 otherwise
 */
boolu32 BlockCheckRevealBombChainBlock(BlockType type, u16 xPosition, u16 yPosition)
{
    struct BrokenBlock* pBlock;
    s32 i;
    s32 couldSpawn;

    couldSpawn = FALSE;

    for (pBlock = gBrokenBlocks, i = 0; i < MAX_AMOUNT_OF_BROKEN_BLOCKS; i++, pBlock++)
    {
        if (pBlock->xPosition == xPosition && pBlock->yPosition == yPosition)
        {
            couldSpawn = 0;
            break;
        }

        if (!(couldSpawn & 0x80) && pBlock->stage == 0)
            couldSpawn = i | 0x80;
    }

    if (couldSpawn)
    {
        pBlock = gBrokenBlocks + (couldSpawn & 0x7F);

        pBlock->broken = FALSE;
        pBlock->stage = 0;
        pBlock->type = type;
        pBlock->timer = 0;
        pBlock->xPosition = xPosition;
        pBlock->yPosition = yPosition;
        couldSpawn = TRUE;
    }

    return couldSpawn;
}

/**
 * @brief 59f70 | 70 | Checks if Samus is in a reforming block
 * 
 * @param xPosition X Position
 * @param yPosition Y Position
 * @return u32 in block
 */
boolu32 BlockCheckSamusInReformingBlock(u8 xPosition, u8 yPosition)
{
    u8 inX;
    u8 inY;
    boolu8 inBlock;

    // Check in X
    inX = FALSE;
    if (SUB_PIXEL_TO_BLOCK_(gSamusData.xPosition + gSamusPhysics.hitboxLeft) <= xPosition &&
        xPosition <= SUB_PIXEL_TO_BLOCK_(gSamusData.xPosition + gSamusPhysics.hitboxRight))
    {
        inX = TRUE;
    }

    // Check in Y
    inY = FALSE;
    if (SUB_PIXEL_TO_BLOCK_(gSamusData.yPosition + gSamusPhysics.hitboxTop) <= yPosition &&
        yPosition <= SUB_PIXEL_TO_BLOCK_(gSamusData.yPosition + gSamusPhysics.hitboxBottom))
    {
        inY = TRUE;
    }

    inBlock = FALSE;
    if (inX)
        inBlock = inY;
        
    return inBlock;
}

/**
 * @brief 59fe0 | b8 | Starts a new bomb chain
 * 
 * @param type Bomb chain type
 * @param xPosition X Position
 * @param yPosition Y Position
 * @return boolu32 could start
 */
boolu32 BlockStartBombChain(BombChainType type, u16 xPosition, u16 yPosition)
{
    boolu32 couldSpawn;
    s32 i;
    
    couldSpawn = FALSE;
    
    for (i = MAX_AMOUNT_OF_BOMB_CHAINS - 1 ; i >= 0; i--)
    {
        if (gBombChains[i].currentOffset == 0)
        {
            // Found empty slot
            gBombChains[i].currentOffset = 1;
            gBombChains[i].srcXPosition = xPosition;
            gBombChains[i].srcYPosition = yPosition;

            gBombChains[i].flipped = TRUE;
            gBombChains[i].unk = TRUE;
            gBombChains[i].type = type;
            
            // Add type
            gActiveBombChainTypes |= sBombChainReverseData[type].typeFlag;
            couldSpawn = TRUE;
            break;
        }
    }

    // Check play bomb chain sound
    if (couldSpawn && gActiveBombChainTypes == sBombChainReverseData[type].typeFlag)
        SoundPlayNotAlreadyPlaying(SOUND_BOMB_CHAIN);

    return couldSpawn;
}

/**
 * @brief 5a098 | 298 | Processes the bomb chains
 * 
 */
void BlockProcessBombChains(void)
{
    u8 horizontal;
    struct ClipdataBlockData clipBlock;
    struct BombChain* pChain;
    u16 clipdata;

    pChain = gBombChains;
    // Update a single bomb chain at a time
    pChain += MOD_AND(gFrameCounter8Bit, ARRAY_SIZE(gBombChains));

    if (pChain->currentOffset == 0)
        return;

    horizontal = FALSE;
    if (pChain->type > BOMB_CHAIN_TYPE_VERTICAL4)
        horizontal = TRUE;

    // Create clipdata block data structure
    clipBlock.behavior = sBombChainReverseData[pChain->type].behavior;
    clipBlock.blockBehavior = BEHAVIOR_TO_BLOCK(clipBlock.behavior);
    clipBlock.yPosition = 0;
    clipBlock.xPosition = 0;

    if (!horizontal)
    {
        // Update vertical
        clipBlock.xPosition = pChain->srcXPosition;
        if (pChain->flipped)
        {
            // Going up
            clipBlock.yPosition = pChain->srcYPosition - pChain->currentOffset;
            if (clipBlock.yPosition <= 1)
            {
                pChain->flipped = FALSE;
            }
            else
            {
                clipdata = GET_CLIP_BLOCK(clipBlock.xPosition, clipBlock.yPosition);
                if (clipBlock.behavior == gTilemapAndClipPointers.pClipBehaviors[clipdata])
                {
                    if (!BlockDestroyNonReformBlock(&clipBlock))
                        pChain->flipped = FALSE;
                }
                else
                {
                    pChain->flipped = FALSE;
                    BlockCheckStartNewSubBombChain(SUB_BOMB_CHAIN_REQUEST_HORIZONTAL_WHEN_GOING_UP, clipBlock.xPosition, clipBlock.yPosition);
                }
            }
        }
        
        if (pChain->unk)
        {
            // Going down
            clipBlock.yPosition = pChain->srcYPosition + pChain->currentOffset;
            if (clipBlock.yPosition >= gBgPointersAndDimensions.clipdataHeight - 2)
            {
                pChain->unk = FALSE;
            }
            else
            {
                clipdata = GET_CLIP_BLOCK(clipBlock.xPosition, clipBlock.yPosition);
                if (clipBlock.behavior == gTilemapAndClipPointers.pClipBehaviors[clipdata])
                {
                    if (!BlockDestroyNonReformBlock(&clipBlock))
                        pChain->unk = FALSE;
                }
                else
                {
                    pChain->unk = FALSE;
                    BlockCheckStartNewSubBombChain(SUB_BOMB_CHAIN_REQUEST_HORIZONTAL_WHEN_GOING_DOWN, clipBlock.xPosition, clipBlock.yPosition);
                }
            }
        }
    }
    else
    {
        clipBlock.yPosition = pChain->srcYPosition;
        if (pChain->flipped)
        {
            // Going left
            clipBlock.xPosition = pChain->srcXPosition - pChain->currentOffset;
            if (clipBlock.xPosition <= 1)
            {
                pChain->flipped = FALSE;
            }
            else
            {
                clipdata = GET_CLIP_BLOCK(clipBlock.xPosition, clipBlock.yPosition);
                if (clipBlock.behavior == gTilemapAndClipPointers.pClipBehaviors[clipdata])
                {
                    if (!BlockDestroyNonReformBlock(&clipBlock))
                        pChain->flipped = FALSE;
                }
                else
                {
                    pChain->flipped = FALSE;
                    BlockCheckStartNewSubBombChain(SUB_BOMB_CHAIN_REQUEST_VERTICAL_WHEN_GOING_LEFT, clipBlock.xPosition, clipBlock.yPosition);
                }
            }
        }

        if (pChain->unk)
        {
            // Going right
            clipBlock.xPosition = pChain->srcXPosition + pChain->currentOffset;
            if (clipBlock.xPosition >= gBgPointersAndDimensions.clipdataWidth - 2)
            {
                pChain->unk = FALSE;
            }
            else
            {
                clipdata = GET_CLIP_BLOCK(clipBlock.xPosition, clipBlock.yPosition);
                if (clipBlock.behavior == gTilemapAndClipPointers.pClipBehaviors[clipdata])
                {
                    if (!BlockDestroyNonReformBlock(&clipBlock))
                        pChain->unk = FALSE;
                }
                else
                {
                    pChain->unk = FALSE;
                    BlockCheckStartNewSubBombChain(SUB_BOMB_CHAIN_REQUEST_VERTICAL_WHEN_GOING_RIGHT, clipBlock.xPosition, clipBlock.yPosition);
                }
            }
        }
    }

    // Check update offset
    if (pChain->flipped || pChain->unk)
    {
        pChain->currentOffset++;
    }
    else
    {
        // Bomb chain ended
        pChain->currentOffset = 0;

        // Remove type
        gActiveBombChainTypes &= ~sBombChainReverseData[pChain->type].typeFlag;

        // Fade sound if no bomb chains active
        if (gActiveBombChainTypes == 0)
            SoundFade(SOUND_BOMB_CHAIN, CONVERT_SECONDS(1.f / 6));
    }
}

/**
 * @brief 5a330 | b0 | Checks if a new sub bomb chain should start
 * 
 * @param type Sub bomb chain type
 * @param xPosition X position
 * @param yPosition Y position
 */
void BlockCheckStartNewSubBombChain(SubBombChainRequest type, u8 xPosition, u8 yPosition)
{
    u16 clipdata;
    s32 i;
    s32 yOffset;
    s32 xOffset;
    s32 offset;
    s32 width;

    // Set bomb chain CAA
    gCurrentClipdataAffectingAction = CAA_BOMB_CHAIN;

    // Check the current position
    clipdata = GET_CLIP_BLOCK(xPosition, yPosition);
    if (clipdata != CLIPDATA_AIR)
        BlockApplyCcaa(yPosition, xPosition, clipdata);

    for (i = 0; i < ARRAY_SIZE(sSubBombChainPositionOffset[0]) / 2; i++)
    {
        width = gBgPointersAndDimensions.clipdataWidth;

        // Get Y offset
        yOffset = yPosition + sSubBombChainPositionOffset[type][i * 2 + 1];
        offset = yOffset * gBgPointersAndDimensions.clipdataWidth;
        
        // Get X offset
        xOffset = xPosition + sSubBombChainPositionOffset[type][i * 2 + 0];
        offset += xOffset;

        // Get clipdata
        clipdata = gBgPointersAndDimensions.pClipDecomp[offset];

        // Apply to block
        if (clipdata != CLIPDATA_AIR)
            BlockApplyCcaa(yOffset, xOffset, clipdata);
    }

    // Clear CAA
    gCurrentClipdataAffectingAction = CAA_NONE;
}

/**
 * @brief 5a3e0 | a4 | Removes the collision and graphics of a broken block 
 * 
 * @param yPosition Y position
 * @param xPosition X position
 */
void BlockBrokenBlockRemoveCollision(u16 yPosition, u16 xPosition)
{
    u16 position;
    u16* dst;

    position = gBgPointersAndDimensions.clipdataWidth * yPosition + xPosition;
    gBgPointersAndDimensions.pClipDecomp[position] = 0;
    gBgPointersAndDimensions.backgrounds[1].pDecomp[position] = 0;

    if (gBg1YPosition / BLOCK_SIZE - 4 > yPosition)
        return;
    
    if (yPosition > gBg1YPosition / BLOCK_SIZE + 13)
        return;

    if (gBg1XPosition / BLOCK_SIZE - 4 > xPosition)
        return;
        
    if (xPosition > gBg1XPosition / BLOCK_SIZE + 18)
        return;

    dst = VRAM_BASE + 0x1000;
    if (xPosition & 0x10)
        dst = VRAM_BASE + 0x1800;

    dst += (yPosition & 0xF) * BLOCK_SIZE + (xPosition & 0xF) * 2;

    dst[0] = gTilemapAndClipPointers.pTilemap[0];
    dst[1] = gTilemapAndClipPointers.pTilemap[1];
    dst[32] = gTilemapAndClipPointers.pTilemap[2];
    dst[33] = gTilemapAndClipPointers.pTilemap[3];
}
