#include "save_file_load.h"
#include "event.h"

#include "data/empty_datatypes.h"
#include "data/in_game_cutscene_data.h"
#include "data/save_file_data.h"

#include "constants/game_state.h"

#include "structs/bg_clip.h"
#include "structs/connection.h"
#include "structs/game_state.h"
#include "structs/in_game_cutscene.h"
#include "structs/in_game_timer.h"
#include "structs/minimap.h"

/**
 * @brief 75a94 | 164 | To document
 * 
 */
void Sram_InitSaveFile(void)
{
    s32 i;
    s32 j;
    u32 flags;
    u32 flag;

    BitFill(3, 0, gVisitedMinimapTiles, 2 * sizeof(gVisitedMinimapTiles), 16);
    BitFill(3, USHORT_MAX, gNeverReformBlocks, sizeof(gNeverReformBlocks), 16);
    BitFill(3, USHORT_MAX, gItemsCollected, sizeof(gItemsCollected), 16);
    BitFill(3, USHORT_MAX, gHatchesOpened, 2 * sizeof(gHatchesOpened), 16);
    BitFill(3, 0, gEventsTriggered, sizeof(gEventsTriggered), 16);
    BitFill(3, 0, gMinimapTilesWithObtainedItems, sizeof(gMinimapTilesWithObtainedItems) * 2, 16);

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
    {
        gNumberOfNeverReformBlocks[i] = 0;
        gNumberOfItemsCollected[i] = 0;
    }

    gInGameTimer = sInGameTimer_Empty;

    for (i = 0; i < ARRAY_SIZE(gBestCompletionTimes); i++)
        gBestCompletionTimes[i] = sBestCompletionTime_Empty;

    for (i = 0; i < ARRAY_SIZE(gInGameTimerAtBosses); i++)
        gInGameTimerAtBosses[i] = sInGameTimer_Empty;

    for (i = 0; i < ARRAY_SIZE(gInGameCutscenesTriggered); i++)
    {
        for (j = 0, flags = 0; j < ARRAY_SIZE(sInGameCutsceneData); j++)
        {
            if (sInGameCutsceneData[i * 32 + j].unk_0)
                flag = TRUE;
            else
                flag = FALSE;

            flags |= flag << j;
        }
        gInGameCutscenesTriggered[i] = flags;
    }

    do {
    gDisableDrawingSamusAndScrolling = FALSE;
    gDifficulty = DIFF_NORMAL;
    } while(0);
    gDifficulty = DIFF_NORMAL;

    gTimeAttackFlag = FALSE;
    #ifdef DEBUG
    gIsLoadingFile = FALSE;
    #else // !DEBUG
    do {
    gIsLoadingFile = FALSE;
    } while(0);
    #endif // DEBUG
}

/**
 * @brief 75bf8 | c | Empty V-blank code for SRAM
 * 
 */
void Sram_VblankEmpty(void)
{
    vu8 c = 0;
}

/**
 * @brief 75c04 | 2c | To document
 * 
 * @param param_1 To document
 * @return u32 bool, is loading file
 */
u32 unk_75c04(u8 param_1)
{
    CallbackSetVblank(Sram_VblankEmpty);
    unk_7584c(param_1);
    return gIsLoadingFile;
}
