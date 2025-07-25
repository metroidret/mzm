#include "save_file.h"
#include "callbacks.h"
#include "dma.h"
#include "macros.h"
#include "event.h"

#include "data/demo_data.h"
#include "data/shortcut_pointers.h"
#include "data/save_file_data.h"
#include "data/block_data.h"
#include "data/in_game_cutscene_data.h"

#include "constants/color_fading.h"
#include "constants/connection.h"
#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/demo.h"
#include "constants/game_region.h"

#include "structs/audio.h"
#include "structs/bg_clip.h"
#include "structs/color_effects.h"
#include "structs/demo.h"
#include "structs/game_state.h"
#include "structs/in_game_cutscene.h"
#include "structs/minimap.h"
#include "structs/sprite.h"
#include "structs/save_file.h"
#include "structs/visual_effects.h"

extern const struct SaveDemo* sDemoRamDataPointers[MAX_AMOUNT_OF_DEMOS];

static struct SaveFileInfo sSaveFileInfo_Empty = {
    .exists = FALSE,
    .corruptionFlag = 0,
    .currentArea = AREA_BRINSTAR,
    .currentEnergy = 0,
    .maxEnergy = 0,
    .currentMissiles = 0,
    .maxMissiles = 0,
    .suitType = SUIT_NORMAL,
    .igtHours = 0,
    .igtMinutes = 0,
    .igtSeconds = 0,
    .hasSaved = FALSE,
    .completedGame = FALSE,
    .introPlayed = FALSE,
    .language = LANGUAGE_JAPANESE,
    .difficulty = DIFF_NORMAL,
    .timeAttack = FALSE,
};

/**
 * @brief 7329c | 64 | Fully reads the flash save into Ewram
 * 
 */
void SramRead_All(void)
{
    s32 i;
    u32 corrupt;

    i = 3;
    while (i != 0)
    {
        SramTestFlash();
        corrupt = gSramCorruptFlag;
        i--;
        if (!corrupt)
            break;
    }

    for (i = 3; i != 0; i--)
    {
        DoSramOperation(SRAM_OPERATION_READ_ALL_FLASH);
        if (DoSramOperation(SRAM_OPERATION_CHECK_ALL) == NULL)
            break;
    }

    SramRead_FileScreenOptionsUnlocked();
    unk_743a4();
    SramRead_MostRecentSaveFile();
    SramRead_TimeAttack();

    #ifdef REGION_EU
    SramRead_Language();
    #else // !REGION_EU
    if (SramRead_Language())
    {
        gLanguage = LANGUAGE_DEFAULT;
        SramWrite_Language();
    }
    #endif // REGION_EU
}

/**
 * @brief 73300 | 94 | Writes the file screen options unlocked to flash sram
 * 
 */
void SramWrite_FileScreenOptionsUnlocked(void)
{
    s32 i;
    u32* ptr;
    u32 checksum;
    struct SaveFileScreenOptions* pOptions;

    pOptions = &sSramEwramPointer->fileScreenOptions_fileA;

    // Write data and magic values
    pOptions->unk_8 = 0x30;
    pOptions->unk_9 = 0x31;
    pOptions->counter++;
    pOptions->galleryImages = gFileScreenOptionsUnlocked.galleryImages;
    pOptions->soundTestAndOriginalMetroid = gFileScreenOptionsUnlocked.soundTestAndOrigMetroid;
    pOptions->region = GAME_REGION;
    pOptions->unk_10 = 0x34;
    pOptions->unk_11 = gFileScreenOptionsUnlocked.unk_5;
    pOptions->unk_12 = gFileScreenOptionsUnlocked.unk_6;
    pOptions->unk_13 = gFileScreenOptionsUnlocked.unk_7;
    pOptions->fusionGalleryImages = gFileScreenOptionsUnlocked.fusionGalleryImages;
    pOptions->timeAttack = gFileScreenOptionsUnlocked.timeAttack;

    for (i = 0; i < ARRAY_SIZE(pOptions->ZeroMissionVer_Text); i++)
        pOptions->ZeroMissionVer_Text[i] = SAVE_FILE_GAME_VER_TEXT[i];

    // Reset checksum
    pOptions->checksum = 0;
    pOptions->notChecksum = ~0;

    ptr = (u32*)&sSramEwramPointer->fileScreenOptions_fileA;
    checksum = 0;
    for (i = 0; i < SRAM_GET_CHECKSUM_SIZE(struct SaveFileScreenOptions, 4, u32); i++)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    pOptions->checksum = checksum;
    pOptions->notChecksum = ~checksum;

    DoSramOperation(SRAM_OPERATION_WRITE_FILE_SCREEN_OPTIONS);
}

/**
 * @brief 73394 | 154 | Reads the file screen options unlocked from flash sram
 * 
 */
void SramRead_FileScreenOptionsUnlocked(void)
{
    u32 fileASanityCheck;
    u32 fileBSanityCheck;
    u32 fileCSanityCheck;
    
    fileASanityCheck = SramCheck_FileScreenOptionsUnlocked(0);
    fileBSanityCheck = SramCheck_FileScreenOptionsUnlocked(1);
    fileCSanityCheck = SramCheck_FileScreenOptionsUnlocked(2);

    // Convoluted (and somewhat useless) state machine to sync the file screen options of all files,
    // even though only the one for file A actually matters
    if (fileASanityCheck)
    {
        dma_fill16(3, USHORT_MAX, &sSramEwramPointer->fileScreenOptions_fileA, sizeof(sSramEwramPointer->fileScreenOptions_fileA));

        if (fileCSanityCheck)
        {
            dma_fill16(3, USHORT_MAX, &sSramEwramPointer->fileScreenOptions_fileC, sizeof(sSramEwramPointer->fileScreenOptions_fileC));

            if (fileBSanityCheck)
            {
                dma_fill16(3, USHORT_MAX, &sSramEwramPointer->fileScreenOptions_fileB, sizeof(sSramEwramPointer->fileScreenOptions_fileB));
            }
            else
            {
                DmaTransfer(3, &sSramEwramPointer->fileScreenOptions_fileB, &sSramEwramPointer->fileScreenOptions_fileA,
                    sizeof(sSramEwramPointer->fileScreenOptions_fileA), 16);
                fileASanityCheck = 0;
                DoSramOperation(SRAM_OPERATION_WRITE_FILE_SCREEN_OPTIONS);
            }
        }
        else
        {
            DmaTransfer(3, &sSramEwramPointer->fileScreenOptions_fileC, &sSramEwramPointer->fileScreenOptions_fileA,
                sizeof(sSramEwramPointer->fileScreenOptions_fileA), 16);
            fileASanityCheck = 0;
            DoSramOperation(SRAM_OPERATION_WRITE_FILE_SCREEN_OPTIONS);

            if (fileBSanityCheck)
            {
                DmaTransfer(3, &sSramEwramPointer->fileScreenOptions_fileA, &sSramEwramPointer->fileScreenOptions_fileB,
                    sizeof(sSramEwramPointer->fileScreenOptions_fileB), 16);
                DoSramOperation(1);
            }
        }
    }
    else
    {
        DmaTransfer(3, &sSramEwramPointer->fileScreenOptions_fileA, &sSramEwramPointer->fileScreenOptions_fileB,
            sizeof(sSramEwramPointer->fileScreenOptions_fileB), 16);
        DoSramOperation(1);
        if (fileCSanityCheck != 0)
        {
            DmaTransfer(3, &sSramEwramPointer->fileScreenOptions_fileA, &sSramEwramPointer->fileScreenOptions_fileC,
                sizeof(sSramEwramPointer->fileScreenOptions_fileC), 16);
            DoSramOperation(2);
        }
    }

    if (fileASanityCheck == 0)
    {
        SramCopy_FileScreenOptionsUnlocked();
        return;
    }
    
    // Sram is considered corrupted, fully clear it
    EraseSram();
    DmaTransfer(3, &sFileScreenOptionsUnlocked_Empty, &gFileScreenOptionsUnlocked, sizeof(gFileScreenOptionsUnlocked), 16);
    SramWrite_FileScreenOptionsUnlocked();
}

/**
 * @brief 734e8 | 9c | Checks the validity of the file screen options unlocked for a file
 * 
 * @param fileNumber File number
 * @return u32 Sanity checks
 */
u32 SramCheck_FileScreenOptionsUnlocked(u8 fileNumber)
{
    s32 i;
    struct SaveFileScreenOptions* pOptions;
    u32 flags;
    u32* ptr;
    u32 checksum;

    flags = 0;
    if (fileNumber == 2)
        pOptions = &sSramEwramPointer->fileScreenOptions_fileC;
    else if (fileNumber == 1)
        pOptions = &sSramEwramPointer->fileScreenOptions_fileB;
    else
        pOptions = &sSramEwramPointer->fileScreenOptions_fileA;

    checksum = 0;
    ptr = (u32*)pOptions;

    for (i = 0; i < (s32)SRAM_GET_CHECKSUM_SIZE(struct SaveFileScreenOptions, 4, u32); i++)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    if (pOptions->checksum != checksum)
        flags |= 1;

    for (i = 0; i < ARRAY_SIZE(pOptions->ZeroMissionVer_Text); i++)
    {
        if (pOptions->ZeroMissionVer_Text[i] != SAVE_FILE_GAME_VER_TEXT[i])
            flags |= 2;
    }

    if (pOptions->checksum != ~pOptions->notChecksum)
        flags |= 4;

    return flags;
}

/**
 * @brief 73584 | 2c | Copies the file screen options unlocked from Sram
 * 
 */
void SramCopy_FileScreenOptionsUnlocked(void)
{
    struct SaveFileScreenOptions* pOptions;

    pOptions = &sSramEwramPointer->fileScreenOptions_fileA;

    gFileScreenOptionsUnlocked.galleryImages = pOptions->galleryImages;
    gFileScreenOptionsUnlocked.soundTestAndOrigMetroid = pOptions->soundTestAndOriginalMetroid;
    gFileScreenOptionsUnlocked.unk_5 = pOptions->unk_11;
    gFileScreenOptionsUnlocked.unk_6 = pOptions->unk_12;
    gFileScreenOptionsUnlocked.unk_7 = pOptions->unk_13;
    gFileScreenOptionsUnlocked.fusionGalleryImages = pOptions->fusionGalleryImages;
    gFileScreenOptionsUnlocked.timeAttack = pOptions->timeAttack;
}

/**
 * @brief 735b0 | 128 | Processes saving the current file during the intro
 * 
 * @return u32 bool, ended
 */
u32 SramProcessIntroSave(void)
{
    if (!gDisableSoftReset)
    {
        // Start, disable soft reset
        gSramOperationStage = 0;
        gDisableSoftReset = TRUE;
    }

    switch (gSramOperationStage)
    {
        case 0:
            // Set intro played flag, and carry the completed game flags
            gGameCompletion.introPlayed = TRUE;
            gSaveFilesInfo[gMostRecentSaveFile].introPlayed = TRUE;
            gGameCompletion.completedGame = gSaveFilesInfo[gMostRecentSaveFile].completedGame;

            // Reset non world data part of the struct 
            BitFill(3, 0, &sSramEwramPointer->files[gMostRecentSaveFile], OFFSET_OF(struct SaveFile, worldData), 0x10);
            gSramOperationStage++;
            break;

        case 1:
            // Write header and game info
            SramWrite_HeaderAndGameInfo();
            gUnk_3000C20 = 0;
            gSramOperationStage++;
            break;

        case 2:
            // Send to flash sram
            if (unk_fbc(0))
                gSramOperationStage++;
            break;

        case 3:
            // Make a backup of the file
            DmaTransfer(3, &sSramEwramPointer->files[gMostRecentSaveFile], &sSramEwramPointer->filesCopy[gMostRecentSaveFile],
                sizeof(struct SaveFile), 16);
            gSramOperationStage++;
            break;

        case 4:
        default:
            // End, re-enable soft reset
            gDisableSoftReset = FALSE;
            gSramOperationStage = 0;
    }

    // If soft reset is enabled, then the save is complete
    return gDisableSoftReset ^ TRUE;
}

/**
 * @brief 736d8 | f4 | Writes the header and game info to the current file
 * 
 */
void SramWrite_HeaderAndGameInfo(void)
{
    s32 i;
    u32* ptr;
    u32 checksum;
    struct SaveFile* pFile;

    pFile = &sSramEwramPointer->files[gMostRecentSaveFile];

    // Write header strings
    StringCopy(pFile->ZERO_MISSION_010_Text, sZERO_MISSION_010_Text, SRAM_TEXT_SIZE);
    StringCopy(pFile->PlanetZebes_Text, sPlanetZebes_Text, SRAM_TEXT_SIZE);

    // Reset checksum
    pFile->checksum = 0;
    pFile->notChecksum = ~0;

    // Write game info
    pFile->gameCompletion.introPlayed = gGameCompletion.introPlayed;
    pFile->gameCompletion.completedGame = gGameCompletion.completedGame;
    pFile->difficulty = gDifficulty;
    pFile->timeAttack = gTimeAttackFlag;
    pFile->gameCompletion.language = gLanguage;

    // Write best completion times
    for (i = 0; i < ARRAY_SIZE(pFile->bestCompletionTimes); i++)
        pFile->bestCompletionTimes[i] = gBestCompletionTimes[i];

    // Write SAMUS ARAN text
    StringCopy(pFile->SamusAran_Text, sSamusAran_Text, SRAM_TEXT_SIZE);

    // Calculate checksum
    ptr = (u32*)&sSramEwramPointer->files[gMostRecentSaveFile];
    checksum = 0;
    for (i = 0; i < SRAM_GET_CHECKSUM_SIZE(struct SaveFile, 8, u32); i++)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    // Write checksum
    pFile->checksum = checksum;
    pFile->notChecksum = ~checksum;
}

/**
 * @brief 737cc | 124 | Processes saving the current file during the ending
 * 
 * @return u32 bool, ended
 */
u32 SramProcessEndingSave(void)
{
    u32 ended;
    u32 bit;

    #ifdef DEBUG
    if (gDebugMode)
        return TRUE;
    #endif

    ended = FALSE;

    switch (gSramOperationStage)
    {
        case 0:
            gUnk_3000C20 = 0;
            gSramOperationStage++;
            break;

        case 1:
            if (unk_fbc(2))
                gSramOperationStage++;
            break;

        case 2:
            // Set completed game flag based on difficulty and language
            // 0 | 0 | Hard hiragana | Normal hiragana | Easy hiragana | Hard english | Normal english | Easy english
            bit = 1;
            if (gLanguage == LANGUAGE_HIRAGANA)
                bit = 8;

            gGameCompletion.completedGame |= bit << gDifficulty;

            SramCheckSetNewBestCompletionTime();
            SramCopy_GameCompletion();
            gUnk_3000C20 = 0;
            gSramOperationStage++;
            break;

        case 3:
            if (unk_fbc(0))
            {
                // Save completion flags
                gSaveFilesInfo[gMostRecentSaveFile].completedGame = gGameCompletion.completedGame;
                gSramOperationStage++;
            }
            break;

        case 4:
            // Make a backup of the file
            DmaTransfer(3, &sSramEwramPointer->files[gMostRecentSaveFile], &sSramEwramPointer->filesCopy[gMostRecentSaveFile],
                sizeof(struct SaveFile), 16);
            gSramOperationStage++;
            break;

        case 5:
        default:
            gSramOperationStage = 0;
            ended = TRUE;
            break;
    }

    return ended;
}

/**
 * @brief 738f0 | f8 | Checks if a new best completion time should be set
 * 
 */
void SramCheckSetNewBestCompletionTime(void)
{
    u32 flags;
    u32 startValue;
    s32 convertedBestTime;
    s32 convertedIgt;

    if (sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].energy != (gEquipment.maxEnergy / sTankIncreaseAmount[gDifficulty].energy))
        flags = 1;
    else
        flags = 0;

    if (sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].missile != (gEquipment.maxMissiles / sTankIncreaseAmount[gDifficulty].missile))
        flags |= 2;

    if (sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].superMissile != (gEquipment.maxSuperMissiles / sTankIncreaseAmount[gDifficulty].superMissile))
        flags |= 4;

    if (sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].powerBomb != (gEquipment.maxPowerBombs / sTankIncreaseAmount[gDifficulty].powerBomb))
        flags |= 8;

    if (flags == 0)
        startValue = 6;
    else
        startValue = 0;

    flags = startValue;

    if (gLanguage != LANGUAGE_JAPANESE)
        flags += 3;

    flags += gDifficulty;
    convertedBestTime = (gBestCompletionTimes[flags].hours * 3600) + (gBestCompletionTimes[flags].minutes * 60) +
        (gBestCompletionTimes[flags].seconds);
    convertedIgt = (gInGameTimer.hours * 3600) + (gInGameTimer.minutes * 60) + (gInGameTimer.seconds);

    if (convertedBestTime > convertedIgt)
        gBestCompletionTimes[flags] = gInGameTimer;
}

/**
 * @brief 739e8 | 9c | Writes the game completion to the current file
 * 
 */
void SramCopy_GameCompletion(void)
{
    s32 i;
    u32* ptr;
    u32 checksum;
    struct SaveFile* pFile;

    pFile = &sSramEwramPointer->files[gMostRecentSaveFile];

    // Reset checksum
    pFile->checksum = 0;
    pFile->notChecksum = ~0;

    // Write completed game flags
    pFile->gameCompletion.completedGame = gGameCompletion.completedGame;

    // Write best completion times
    for (i = 0; i < ARRAY_SIZE(pFile->bestCompletionTimes); i++)
        pFile->bestCompletionTimes[i] = gBestCompletionTimes[i];

    // Calculate checksum
    ptr = (u32*)&sSramEwramPointer->files[gMostRecentSaveFile];
    checksum = 0;
    for (i = 0; i < SRAM_GET_CHECKSUM_SIZE(struct SaveFile, 8, u32); i++)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    // Write checksum
    pFile->checksum = checksum;
    pFile->notChecksum = ~checksum;
}

/**
 * @brief 73a84 | 120 | Processes saving the current file as if it were completed (used by debug code)
 * 
 * @return u32 bool, ended
 */
u32 SramProcessEndingSave_Debug(void)
{
    u32 ended;
    u32 bit;

    ended = FALSE;

    switch (gSramOperationStage)
    {
        case 0:
            gUnk_3000C20 = 0;
            gSramOperationStage++;
            break;

        case 1:
            if (unk_fbc(2))
                gSramOperationStage++;
            break;

        case 2:
            // Set completed game flag based on difficulty and language
            // 0 | 0 | Hard hiragana | Normal hiragana | Easy hiragana | Hard english | Normal english | Easy english
            bit = 1;
            if (gLanguage == LANGUAGE_HIRAGANA)
                bit = 1 << 3;

            gGameCompletion.completedGame |= bit << gDifficulty;

            SramCopy_GameCompletion();
            gUnk_3000C20 = 0;
            gSramOperationStage++;
            break;

        case 3:
            if (unk_fbc(0))
            {
                // Save completion flags
                gSaveFilesInfo[gMostRecentSaveFile].completedGame = gGameCompletion.completedGame;
                gSramOperationStage++;
            }
            break;

        case 4:
            // Make a backup of the file
            DmaTransfer(3, &sSramEwramPointer->files[gMostRecentSaveFile], &sSramEwramPointer->filesCopy[gMostRecentSaveFile],
                sizeof(struct SaveFile), 16);
            gSramOperationStage++;
            break;

        case 5:
        default:
            gSramOperationStage = 0;
            ended = TRUE;
            break;
    }

    return ended;
}

/**
 * @brief 73ba4 | 140 | Saves the current file to flash sram
 * 
 * @return u32 bool, ended
 */
u32 SramSaveFile(void)
{
    if (!gDisableSoftReset)
    {
        // Start, disable soft reset
        gDisableSoftReset = TRUE;
        gHasSaved = TRUE;
        gSramOperationStage = 0;
        gUnk_3000C20 = 0;
    }

    switch (gSramOperationStage)
    {
        case 0:
            if (unk_fbc(4))
                gSramOperationStage++;
            break;

        case 1:
            // Write arrays
            SramWrite_Arrays();
            gUnk_3000C20 = 0;
            gSramOperationStage++;
            break;

        case 2:
            // Write data
            SramWrite_ToEwram();
            gUnk_3000C20 = 0;
            gSramOperationStage++;
            break;

        case 3:
            // Send to flash sram
            if (unk_fbc(0))
            {
                gSaveFilesInfo[gMostRecentSaveFile].exists = TRUE;
                gSramOperationStage++;
            }
            break;

        case 4:
            // Make a backup of the file
            DmaTransfer(3, &sSramEwramPointer->files[gMostRecentSaveFile], &sSramEwramPointer->filesCopy[gMostRecentSaveFile],
                sizeof(struct SaveFile), 16);
            gSramOperationStage++;
            break;

        case 5:
        default:
            // End, re-enable soft reset
            gDisableSoftReset = FALSE;
    }

    // If soft reset is enabled, then the save is complete
    return gDisableSoftReset ^ TRUE;
}

/**
 * @brief 73ce4 | 350 | Writes all the current RAM values to the save file values (in Ewram)
 * 
 */
void SramWrite_ToEwram(void)
{
    s32 i;
    u32* ptr;
    u32 checksum;
    struct SaveFile* pFile;
    struct SaveMusicInfo musicInfo;

    musicInfo.musicTrack = gMusicInfo.musicTrack;
    musicInfo.unk_2 = gMusicInfo.unk_1E;
    musicInfo.unk_4 = gMusicInfo.unk_20;
    musicInfo.priority = gMusicInfo.priority;

    pFile = &sSramEwramPointer->files[gMostRecentSaveFile];

    StringCopy(pFile->ZERO_MISSION_010_Text, sZERO_MISSION_010_Text, SRAM_TEXT_SIZE);
    StringCopy(pFile->PlanetZebes_Text, sPlanetZebes_Text, SRAM_TEXT_SIZE);

    pFile->checksum = 0;
    pFile->notChecksum = ~0;

    pFile->gameCompletion = gGameCompletion;
    pFile->hasSaved = gHasSaved;
    pFile->currentArea = gCurrentArea;
    pFile->currentRoom = gCurrentRoom;
    pFile->LastDoorUsed = gLastDoorUsed;
    pFile->mapX = gMinimapX;
    pFile->mapY = gMinimapY;

    pFile->camera = gCamera;
    pFile->bg0XPosition = gBg0XPosition;
    pFile->bg0YPosition = gBg0YPosition;
    pFile->bg1XPosition = gBg1XPosition;
    pFile->bg1YPosition = gBg1YPosition;
    pFile->bg2XPosition = gBg2XPosition;
    pFile->bg2YPosition = gBg2YPosition;
    pFile->bg3XPosition = gBg3XPosition;
    pFile->bg3YPosition = gBg3YPosition;

    pFile->difficulty = gDifficulty;
    pFile->useMotherShipDoor = gUseMotherShipDoors;
    pFile->timeAttack = gTimeAttackFlag;

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
        pFile->numberOfNeverReformBlocksBroken[i] = gNumberOfNeverReformBlocks[i];

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
        pFile->numberOfItemsCollected[i] = gNumberOfItemsCollected[i];

    pFile->samusData = gSamusData;
    pFile->samusWeaponInfo = gSamusWeaponInfo;
    pFile->samusEcho = gSamusEcho;
    pFile->screwSpeedAnimation = gScrewSpeedAnimation;
    pFile->equipment = gEquipment;
    pFile->hazardDamage = gSamusHazardDamage;
    pFile->environmentalEffects[0] = gSamusEnvironmentalEffects[0];
    pFile->environmentalEffects[1] = gSamusEnvironmentalEffects[1];
    pFile->environmentalEffects[2] = gSamusEnvironmentalEffects[2];
    pFile->environmentalEffects[3] = gSamusEnvironmentalEffects[3];
    pFile->environmentalEffects[4] = gSamusEnvironmentalEffects[4];
    pFile->preventMovementTimer = gPreventMovementTimer;
    pFile->disableDrawingSamusAndScrolling = gDisableDrawingSamusAndScrolling;

    pFile->alarmTimer = gAlarmTimer;
    pFile->inGameTimer = gInGameTimer;

    for (i = 0; i < 12; i++)
        pFile->bestCompletionTimes[i] = gBestCompletionTimes[i];

    for (i = 0; i < MAX_AMOUNT_OF_IGT_AT_BOSSES; i++)
        pFile->inGameTimerAtBosses[i] = gInGameTimerAtBosses[i];

    pFile->musicInfo = musicInfo;
    for (i = 0; i < 1; i++)
        pFile->inGameCutscenesTriggered[i] = gInGameCutscenesTriggered[i];

    StringCopy(pFile->SamusAran_Text, sSamusAran_Text, SRAM_TEXT_SIZE);

    // Calculate checksum
    ptr = (u32*)&sSramEwramPointer->files[gMostRecentSaveFile];
    checksum = 0;
    for (i = 0; i < SRAM_GET_CHECKSUM_SIZE(struct SaveFile, 8, u32); i++)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    // Write checksum
    pFile->checksum = checksum;
    pFile->notChecksum = ~checksum;
}

/**
 * @brief 74034 | 2ac | Loads all the current save file values (in Ewram) to RAM
 * 
 */
void SramRead_FromEwram(void)
{
    s32 i;
    struct SaveFile* pFile;
    struct SaveMusicInfo musicInfo;

    pFile = &sSramEwramPointer->files[gMostRecentSaveFile];

    gGameCompletion = pFile->gameCompletion;
    gHasSaved = pFile->hasSaved;
    gCurrentArea = pFile->currentArea;
    gCurrentRoom = pFile->currentRoom;
    gLastDoorUsed = pFile->LastDoorUsed;
    gMinimapX = pFile->mapX;
    gMinimapY = pFile->mapY;

    gCamera = pFile->camera;
    gBg0XPosition = pFile->bg0XPosition;
    gBg0YPosition = pFile->bg0YPosition;
    gBg1XPosition = pFile->bg1XPosition;
    gBg1YPosition = pFile->bg1YPosition;
    gBg2XPosition = pFile->bg2XPosition;
    gBg2YPosition = pFile->bg2YPosition;
    gBg3XPosition = pFile->bg3XPosition;
    gBg3YPosition = pFile->bg3YPosition;

    gDifficulty = pFile->difficulty;
    gUseMotherShipDoors = pFile->useMotherShipDoor;
    gTimeAttackFlag = pFile->timeAttack;

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
        gNumberOfNeverReformBlocks[i] = pFile->numberOfNeverReformBlocksBroken[i];

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
        gNumberOfItemsCollected[i] = pFile->numberOfItemsCollected[i];

    gSamusData = pFile->samusData;
    gSamusWeaponInfo = pFile->samusWeaponInfo;
    gSamusEcho = pFile->samusEcho;
    gScrewSpeedAnimation = pFile->screwSpeedAnimation;
    gEquipment = pFile->equipment;
    gSamusHazardDamage = pFile->hazardDamage;
    gSamusEnvironmentalEffects[0] = pFile->environmentalEffects[0];
    gSamusEnvironmentalEffects[1] = pFile->environmentalEffects[1];
    gSamusEnvironmentalEffects[2] = pFile->environmentalEffects[2];
    gSamusEnvironmentalEffects[3] = pFile->environmentalEffects[3];
    gSamusEnvironmentalEffects[4] = pFile->environmentalEffects[4];
    gPreventMovementTimer = pFile->preventMovementTimer;
    gDisableDrawingSamusAndScrolling = pFile->disableDrawingSamusAndScrolling;

    gAlarmTimer = pFile->alarmTimer;
    gInGameTimer = pFile->inGameTimer;

    for (i = 0; i < ARRAY_SIZE(gBestCompletionTimes); i++)
        gBestCompletionTimes[i] = pFile->bestCompletionTimes[i];

    for (i = 0; i < MAX_AMOUNT_OF_IGT_AT_BOSSES; i++)
        gInGameTimerAtBosses[i] = pFile->inGameTimerAtBosses[i];

    musicInfo = pFile->musicInfo;
    for (i = 0; i < ARRAY_SIZE(gInGameCutscenesTriggered); i++)
        gInGameCutscenesTriggered[i] = pFile->inGameCutscenesTriggered[i];

    gMusicInfo.musicTrack = musicInfo.musicTrack;
    gMusicInfo.unk_1E = musicInfo.unk_2;
    gMusicInfo.unk_20 = musicInfo.unk_4;
    gMusicInfo.priority = musicInfo.priority;
}

/**
 * @brief 742e0 | 24 | Copies a string from src to dst, of length size
 * 
 * @param dst Destination pointer
 * @param src Source pointer
 * @param length String length
 */
void StringCopy(u8* dst, const u8* const src, u8 length)
{
    s32 i;

    for (i = 0; i < length; i++)
        dst[i] = src[i];
}

/**
 * @brief 74304 | a0 | Performs a series of tests on flash sram to verify it's working correctly
 * 
 */
void SramTestFlash(void)
{
    u32 flags;
    s32 i;
    u8 text[SRAM_TEXT_SIZE];
    
    flags = 0;
    gSramCorruptFlag = FALSE;

    // Perform a write Text -> Flash
    if (SramWriteChecked(sMetZeroSramCheck_Text, SRAM_BASE + OFFSET_OF(struct Sram, MetZeroSramCheck_Text), SRAM_TEXT_SIZE))
        flags = 1; // Internal check failed

    // Read the text previously written into a local buffer
    SramWriteUnchecked(SRAM_BASE + OFFSET_OF(struct Sram, MetZeroSramCheck_Text), text, SRAM_TEXT_SIZE);

    // Add 1 to every element
    for (i = 0; i < SRAM_TEXT_SIZE; i++)
        text[i]++;

    // Write the modified text to flash
    if (SramWriteChecked(text, SRAM_BASE + OFFSET_OF(struct Sram, MetZeroSramCheck_Text), SRAM_TEXT_SIZE))
        flags |= 2; // Internal check failed

    // Read the text previously written into a local buffer
    SramWriteUnchecked(SRAM_BASE + OFFSET_OF(struct Sram, MetZeroSramCheck_Text), text, SRAM_TEXT_SIZE);

    // Verify the contents of the buffer, it should contain the test text with 1 added to every letter
    for (i = 0; i < SRAM_TEXT_SIZE; i++)
    {
        if (text[i] != sMetZeroSramCheck_Text[i] + 1)
        {
            // Incorrect data
            flags |= 4;
            break;
        }
    }

    if (flags)
        gSramCorruptFlag = flags;
}

/**
 * @brief 743a4 | 1d0 | To document
 * 
 */
void unk_743a4(void)
{
    s32 i;
    u32 flag;

    for (i = 0; i < ARRAY_SIZE(gSaveFilesInfo); i++)
        gSaveFilesInfo[i] = sSaveFileInfo_Empty;

    gMostRecentSaveFile = 0;
    gIsLoadingFile = FALSE;

    for (i = 0; i < ARRAY_SIZE(gSaveFilesInfo); i++)
    {
        gMostRecentSaveFile = i;
        unk_74574();

        flag = gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag;

        if (flag == 0)
        {
            DmaTransfer(3, &sSramEwramPointer->files[gMostRecentSaveFile],
                &sSramEwramPointer->filesCopy[gMostRecentSaveFile], sizeof(struct SaveFile), 16);

            DoSramOperation(4);
            gSaveFilesInfo[i].exists = TRUE;
        }
        else if (flag == CORRUPTED_FILE_FLAG_CURRENT)
        {
            DmaTransfer(3, &sSramEwramPointer->filesCopy[gMostRecentSaveFile],
                &sSramEwramPointer->files[gMostRecentSaveFile], sizeof(struct SaveFile), 16);

            gSaveFilesInfo[i].exists = TRUE;
        }
        else if (flag == CORRUPTED_FILE_FLAG_CURRENT_AND_BACKUP)
        {
            BitFill(3, USHORT_MAX, &sSramEwramPointer->files[gMostRecentSaveFile], sizeof(struct SaveFile), 16);
            BitFill(3, USHORT_MAX, &sSramEwramPointer->filesCopy[gMostRecentSaveFile], sizeof(struct SaveFile), 16);
        }
        else if (flag > 2)
        {
            BitFill(3, USHORT_MAX, &sSramEwramPointer->files[gMostRecentSaveFile], sizeof(struct SaveFile), 16);
            DoSramOperation(3);
            BitFill(3, USHORT_MAX, &sSramEwramPointer->filesCopy[gMostRecentSaveFile], sizeof(struct SaveFile), 16);
            DoSramOperation(4);
            gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = 0;
        }
        else
        {
            while (TRUE);
        }
    }

    gMostRecentSaveFile = 0;
}

/**
 * @brief 74574 | b0 | To document
 * 
 */
void unk_74574(void)
{
    u32 sanityCheck1;
    u32 sanityCheck2;

    sanityCheck1 = unk_74624(FALSE);
    sanityCheck2 = unk_74624(TRUE);

    if (sanityCheck1 == 0)
    {
        gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = 0;
        return;
    }

    if (sanityCheck1 == 1)
    {
        gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = CORRUPTED_FILE_FLAG_CURRENT;
        if (sanityCheck2 != 0)
            gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = CORRUPTED_FILE_FLAG_CURRENT_AND_BACKUP;
        return;
    }

    gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = 3;
    if (sanityCheck2 == 0)
        gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = CORRUPTED_FILE_FLAG_CURRENT;
    else if (sanityCheck2 == 1)
        gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = CORRUPTED_FILE_FLAG_CURRENT_AND_BACKUP;
}

/**
 * @brief 74624 | 168 | To document
 * 
 * @param useCopy Use file copy flag
 * @return u32 Sanity checks
 */
u32 unk_74624(u8 useCopy)
{
    struct SaveFile* pFile;
    u32* ptr;
    u32 checksum;
    s32 result;
    s32 i;

    if (useCopy == FALSE)
        pFile = &sSramEwramPointer->files[gMostRecentSaveFile];
    else
        pFile = &sSramEwramPointer->filesCopy[gMostRecentSaveFile];

    ptr = (u32*)pFile;
    checksum = 0;

    for (i = 0; i < SRAM_GET_CHECKSUM_SIZE(struct SaveFile, 8, u32); i++)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    result = 0;
    if (pFile->checksum != checksum || checksum != ~pFile->notChecksum)
        result = 1;

    checksum = 0;
    for (i = 0; i < SRAM_TEXT_SIZE; i++)
    {
        if (sZERO_MISSION_010_Text[i] != pFile->ZERO_MISSION_010_Text[i])
        {
            checksum |= 1;
            break;
        }
    }

    for (i = 0; i < SRAM_TEXT_SIZE; i++)
    {
        if (sPlanetZebes_Text[i] != pFile->PlanetZebes_Text[i])
        {
            checksum |= 2;
            break;
        }
    }

    for (i = 0; i < SRAM_TEXT_SIZE; i++)
    {
        if (sSamusAran_Text[i] != pFile->SamusAran_Text[i])
        {
            checksum |= 4;
            break;
        }
    }

    if (checksum != 0)
    {
        if (checksum == (1 | 2 | 4))
            result |= 2;
        else
            result |= 1;
    }

    if (result > 1)
    {
        BitFill(3, USHORT_MAX, pFile, sizeof(*pFile), 16);
    }

    return result;
}

/**
 * @brief 7478c | 20 | Reads a save file from Ewram
 * 
 */
void SramLoadFile(void)
{
    if (gIsLoadingFile == TRUE)
    {
        SramRead_FromEwram();
        SramRead_Arrays();
    }
}

/**
 * @brief 747ac | 10 | Reads a save file from Ewram, unused
 * 
 */
void SramLoadFile_Unused(void)
{
    SramRead_FromEwram();
    SramRead_Arrays();
}

/**
 * @brief 747bc | 100 | Save the arrays to sram
 * 
 */
void SramWrite_Arrays(void)
{
    s32 i;
    s32 offset;
    s32 size;
    struct SaveFile* pFile;
    u8* src;
    struct SaveWorldData* dst;

    pFile = &sSramEwramPointer->files[gMostRecentSaveFile];

    dst = &pFile->worldData;
    
    DmaTransfer(3, gVisitedMinimapTiles, dst->visitedMinimapTiles, sizeof(dst->visitedMinimapTiles), 16);
    DmaTransfer(3, gHatchesOpened, dst->hatchesOpened, sizeof(dst->hatchesOpened), 16);
    DmaTransfer(3, gEventsTriggered, dst->eventsTriggered, sizeof(dst->eventsTriggered), 16);

    offset = 0;
    src = (u8*)gNeverReformBlocks;
    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
    {
        if (gNumberOfNeverReformBlocks[i] == 0)
            continue;

        size = gNumberOfNeverReformBlocks[i] * 2;
        DmaTransfer(3, &src[i * MINIMAP_SIZE * 16],
            &dst->neverReformBlocksBroken[offset], size, 16);
        offset += size;
    }

    offset = 0;
    src = (u8*)gItemsCollected;
    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
    {
        size = gNumberOfItemsCollected[i] * sizeof(struct ItemInfo);
        if (size == 0)
            continue;

        DmaTransfer(3, &src[i * MAX_AMOUNT_OF_ITEMS_PER_AREA * sizeof(struct ItemInfo)],
            &dst->itemsCollected[offset], size, 16);
        offset += size;
    }
}

/**
 * @brief 748bc | 128 | Loads the sram arrays to ram
 * 
 */
void SramRead_Arrays(void)
{
    s32 i;
    s32 offset;
    s32 size;
    struct SaveFile* pFile;
    struct SaveWorldData* src;
    u8* dst;

    pFile = &sSramEwramPointer->files[gMostRecentSaveFile];
    src = &pFile->worldData;

    DmaTransfer(3, src->visitedMinimapTiles, gVisitedMinimapTiles, sizeof(gVisitedMinimapTiles), 16);
    DmaTransfer(3, src->hatchesOpened, gHatchesOpened, sizeof(gHatchesOpened), 16);
    DmaTransfer(3, src->eventsTriggered, gEventsTriggered, sizeof(gEventsTriggered), 16);

    BitFill(3, USHORT_MAX, gNeverReformBlocks, sizeof(gNeverReformBlocks), 16);
    BitFill(3, USHORT_MAX, gItemsCollected, sizeof(gItemsCollected), 16);

    offset = 0;
    dst = (u8*)gNeverReformBlocks;
    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
    {
        if (gNumberOfNeverReformBlocks[i] != 0)
        {
            size = gNumberOfNeverReformBlocks[i] * 2;
            DmaTransfer(3, &src->neverReformBlocksBroken[offset],
                &dst[i * MINIMAP_SIZE * 16], size, 16);

            offset += size;
        }
    }

    offset = 0;
    dst = (u8*)gItemsCollected;
    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
    {
        size = gNumberOfItemsCollected[i] * 4;
        if (size != 0)
        {
            DmaTransfer(3, &src->itemsCollected[offset],
                &dst[i * MAX_AMOUNT_OF_ITEMS_PER_AREA * sizeof(struct ItemInfo)], size, 16);

            offset += size;
        }
    }

    MinimapLoadTilesWithObtainedItems();
}

/**
 * @brief 749e4 | 98 | Writes the most recent save file id to flash sram
 * 
 */
void SramWrite_MostRecentSaveFile(void)
{
    struct SaveValue* pSave;
    s32 i;
    u16 checksum;
    u16* ptr;

    pSave = &sSramEwramPointer->mostRecentFileSave;
    ptr = (u16*)pSave;

    pSave->magicNumber = 0x1E;
    pSave->counter++;
    pSave->checksum = 0;
    pSave->notChecksum = ~0;
    pSave->value = gMostRecentSaveFile;

    // Write start/end strings
    for (i = 0; i < SRAM_TEXT_SIZE; i++)
    {
        pSave->startText[i] = sMostRecentFileSave_Text[0][i];
        pSave->endText[i] = sMostRecentFileSave_Text[1][i];
    }

    // Calculate checksum
    checksum = 0;
    for (i = 0; i < SRAM_GET_CHECKSUM_SIZE(struct SaveValue, 4, u16); i++)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    pSave->checksum = checksum;
    pSave->notChecksum = ~checksum;

    DoSramOperation(SRAM_OPERATION_SAVE_MOST_RECENT_FILE);
}

/**
 * @brief 74a7c | f0 | Read the most recent save file id from flash sram
 * 
 */
void SramRead_MostRecentSaveFile(void)
{
    u32 error;
    s32 i;
    u16 checksum;
    u16 actualChecksum;
    u16* ptr;
    struct SaveValue* pSave;

    pSave = &sSramEwramPointer->mostRecentFileSave;
    if (pSave->magicNumber == 0x1E)
        error = 0;
    else
        error = 1;

    if (error == 0)
    {
        // Calculate checksum
        ptr = (u16*)&sSramEwramPointer->mostRecentFileSave;
        checksum = 0;
        actualChecksum = pSave->checksum;
        for (i = 0; i < SRAM_GET_CHECKSUM_SIZE(struct SaveValue, 4, u16); i++)
        {
            checksum += *ptr++;
            checksum += *ptr++;
            checksum += *ptr++;
            checksum += *ptr++;
        }

        if (actualChecksum != checksum)
            error = 2;

        if (error == 0)
        {
            for (i = 0; i < SRAM_TEXT_SIZE; i++)
            {
                if (pSave->startText[i] != sMostRecentFileSave_Text[0][i])
                {
                    error = 3;
                    break;
                }

                if (pSave->endText[i] != sMostRecentFileSave_Text[1][i])
                {
                    error = 3;
                    break;
                }
            }
        }
    } 

    if (error == 0)
    {
        gMostRecentSaveFile = pSave->value;
        return;
    }

    dma_fill16(3, USHORT_MAX, &sSramEwramPointer->mostRecentFileSave, sizeof(sSramEwramPointer->mostRecentFileSave));

    gMostRecentSaveFile = 0;
}

/**
 * @brief 74b6c | 9c | Writes the sound mode (stereo) to flash sram
 * 
 */
void SramWrite_SoundMode(void)
{
    struct SaveValue* pSave;
    s32 i;
    u16 checksum;
    u16* ptr;

    pSave = &sSramEwramPointer->soundModeSave;
    ptr = (u16*)pSave;

    pSave->magicNumber = 0x1F;
    pSave->counter++;
    pSave->checksum = 0;
    pSave->notChecksum = ~0;
    pSave->value = gStereoFlag;

    // Write start/end strings
    for (i = 0; i < SRAM_TEXT_SIZE; i++)
    {
        pSave->startText[i] = sSoundModeSave_Text[0][i];
        pSave->endText[i] = sSoundModeSave_Text[1][i];
    }

    // Calculate checksum
    checksum = 0;
    for (i = 0; i < SRAM_GET_CHECKSUM_SIZE(struct SaveValue, 4, u16); i++)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    pSave->checksum = checksum;
    pSave->notChecksum = ~checksum;

    DoSramOperation(SRAM_OPERATION_SAVE_SOUND_MODE);
}

/**
 * @brief 74c08 | f0 | Reads the sound mode (stereo) from flash sram
 * 
 */
void SramRead_SoundMode(void)
{
    u32 error;
    s32 i;
    u16 checksum;
    u16 actualChecksum;
    u16* ptr;
    struct SaveValue* pSave;

    pSave = &sSramEwramPointer->soundModeSave;
    if (pSave->magicNumber == 0x1F)
        error = 0;
    else
        error = 1;

    if (error == 0)
    {
        // Calculate checksum
        ptr = (u16*)&sSramEwramPointer->soundModeSave;
        checksum = 0;
        actualChecksum = pSave->checksum;
        for (i = 0; i < SRAM_GET_CHECKSUM_SIZE(struct SaveValue, 4, u16); i++)
        {
            checksum += *ptr++;
            checksum += *ptr++;
            checksum += *ptr++;
            checksum += *ptr++;
        }

        if (actualChecksum != checksum)
            error = 2;

        if (error == 0)
        {
            for (i = 0; i < SRAM_TEXT_SIZE; i++)
            {
                if (pSave->startText[i] != sSoundModeSave_Text[0][i])
                {
                    error = 3;
                    break;
                }
                if (pSave->endText[i] != sSoundModeSave_Text[1][i])
                {
                    error = 3;
                    break;
                }
            }
        }
    } 

    if (error == 0)
    {
        gStereoFlag = pSave->value;
        return;
    }

    dma_fill16(3, USHORT_MAX, &sSramEwramPointer->soundModeSave, sizeof(sSramEwramPointer->soundModeSave));

    gStereoFlag = FALSE;
}

/**
 * @brief 74cf8 | ac | Writes the language to flash sram
 * 
 */
void SramWrite_Language(void)
{
    struct SaveValue* pSave;
    s32 i;
    u16 checksum;
    u16* ptr;
    u32 value;
    
    pSave = &sSramEwramPointer->languagesSave[0];
    ptr = (u16*)pSave;

    pSave->magicNumber = 0x1F;
    pSave->counter++;
    pSave->checksum = 0;
    pSave->notChecksum = ~0;
    
    i = gLanguage;
    if ((u32)i >= LANGUAGE_END)
    {
        #ifdef REGION_EU
        i = 0;
        #else
        i = LANGUAGE_DEFAULT;
        #endif // REGION_EU
    }

    pSave->value = i;

    // Write start/end strings
    for (i = 0; i < SRAM_TEXT_SIZE; i++)
    {
        pSave->startText[i] = sLanguageSave_Text[0][i];
        pSave->endText[i] = sLanguageSave_Text[1][i];
    }

    // Calculate checksum
    checksum = 0;
    for (i = 0; i < SRAM_GET_CHECKSUM_SIZE(struct SaveValue, 4, u16); i++)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    pSave->checksum = checksum;
    pSave->notChecksum = ~checksum;

    DoSramOperation(SRAM_OPERATION_SAVE_LANGUAGE);
}

/**
 * @brief 74da4 | 1b4 | Reads the language from flash sram
 * 
 * @return u32 
 */
u32 SramRead_Language(void)
{
    struct SaveValue* pSave;
    u32 error;
    s32 i;
    s32 j;
    u16 checksum;
    u16 actualChecksum;
    u16* ptr;

    for (i = 0; i < ARRAY_SIZE(gSram.languagesSave); i++)
    {
        pSave = &sSramEwramPointer->languagesSave[i];
        ptr = (u16*)pSave;
        if (pSave->magicNumber == 0x1F)
            error = 0;
        else
            error = 1;

        if (error == 0)
        {
            checksum = 0;
            actualChecksum = pSave->checksum;
            for (j = 0; j < SRAM_GET_CHECKSUM_SIZE(struct SaveValue, 4, u16); j++)
            {
                checksum += *ptr++;
                checksum += *ptr++;
                checksum += *ptr++;
                checksum += *ptr++;
            }

            if (actualChecksum != checksum)
                error = 2;

            if (error == 0)
            {
                for (j = 0; j < SRAM_TEXT_SIZE; j++)
                {
                    if (pSave->startText[j] != sLanguageSave_Text[0][j])
                    {
                        error = 3;
                        break;
                    }
                    if (pSave->endText[j] != sLanguageSave_Text[1][j])
                    {
                        error = 4;
                        break;
                    }
                }
            }
        }

        if (i == 0)
        {
            if (error == 0)
            {
                DMA_SET(3, &sSramEwramPointer->languagesSave[0], &sSramEwramPointer->languagesSave[1],
                    DMA_ENABLE << 16 | sizeof(sSramEwramPointer->languagesSave[1]) / 2);

                DoSramOperation(SRAM_OPERATION_SAVE_LANGUAGE2);
                break;
            }
        }
        else if (error == 0)
        {
            DMA_SET(3, &sSramEwramPointer->languagesSave[1], &sSramEwramPointer->languagesSave[0],
                DMA_ENABLE << 16 | sizeof(sSramEwramPointer->languagesSave[0]) / 2);

            DoSramOperation(SRAM_OPERATION_SAVE_LANGUAGE);
            break;
        }
        else
        {
            dma_fill16(3, 0, &sSramEwramPointer->languagesSave[0], sizeof(sSramEwramPointer->languagesSave[0]));

            DoSramOperation(SRAM_OPERATION_SAVE_LANGUAGE);

            dma_fill16(3, 0, &sSramEwramPointer->languagesSave[1], sizeof(sSramEwramPointer->languagesSave[1]));

            DoSramOperation(SRAM_OPERATION_SAVE_LANGUAGE2);
        }
    }

    if (!error)
    {
        gLanguage = pSave->value;
        return FALSE;
    }

    gLanguage = LANGUAGE_JAPANESE;
    return TRUE;
}

/**
 * @brief 74f58 | b8 | Writes the time attack data to flash sram
 * 
 */
void SramWrite_TimeAttack(void)
{
    struct SaveTimeAttack* pSave;
    u16 checksum;
    u16* ptr;
    s32 i;

    pSave = &sSramEwramPointer->timeAttackSaves[0];
    ptr = (u16*)pSave;

    pSave->magicNumber = 0x40;
    pSave->counter++;
    pSave->checksum = 0;
    pSave->notChecksum = ~0;

    pSave->value = gTimeAttackRecord;
    
    // Write start/end strings
    for (i = 0; i < SRAM_TEXT_SIZE; i++)
    {
        pSave->startText[i] = sTimeAttackSave_Text[0][i];
        pSave->endText[i] = sTimeAttackSave_Text[1][i];
    }

    // Calculate checksum
    checksum = 0;
    for (i = 0; i < SRAM_GET_CHECKSUM_SIZE(struct SaveTimeAttack, 4, u16); i++)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    pSave->checksum = checksum;
    pSave->notChecksum = ~checksum;

    DoSramOperation(SRAM_OPERATION_SAVE_TIME_ATTACK);
}

/**
 * @brief 75010 | 1c8 | Reads the time attack data from flash sram
 * 
 */
void SramRead_TimeAttack(void)
{
    struct SaveTimeAttack* pSave;
    u32 error;
    s32 i;
    s32 j;
    u16 checksum;
    u16 actualChecksum;
    u16* ptr;

    for (i = 0; i < ARRAY_SIZE(gSram.timeAttackSaves); i++)
    {
        pSave = &sSramEwramPointer->timeAttackSaves[i];
        ptr = (u16*)pSave;
        if (pSave->magicNumber == 0x40)
            error = 0;
        else
            error = 1;

        if (error == 0)
        {
            checksum = 0;
            actualChecksum = pSave->checksum;
            for (j = 0; j < SRAM_GET_CHECKSUM_SIZE(struct SaveTimeAttack, 4, u16); j++)
            {
                checksum += *ptr++;
                checksum += *ptr++;
                checksum += *ptr++;
                checksum += *ptr++;
            }

            if (actualChecksum != checksum)
                error = 2;

            if (error == 0)
            {
                for (j = 0; j < SRAM_TEXT_SIZE; j++)
                {
                    if (pSave->startText[j] != sTimeAttackSave_Text[0][j])
                    {
                        error = 3;
                        break;
                    }
                    if (pSave->endText[j] != sTimeAttackSave_Text[1][j])
                    {
                        error = 4;
                        break;
                    }
                }
            }
        }

        if (i == 0)
        {
            if (error == 0)
            {
                DMA_SET(3, &sSramEwramPointer->timeAttackSaves[0], &sSramEwramPointer->timeAttackSaves[1],
                    DMA_ENABLE << 16 | sizeof(sSramEwramPointer->timeAttackSaves[1]) / 2);

                DoSramOperation(SRAM_OPERATION_SAVE_TIME_ATTACK2);
                break;
            }
        }
        else if (error == 0)
        {
            DMA_SET(3, &sSramEwramPointer->timeAttackSaves[1], &sSramEwramPointer->timeAttackSaves[0],
                DMA_ENABLE << 16 | sizeof(sSramEwramPointer->timeAttackSaves[0]) / 2);

            DoSramOperation(SRAM_OPERATION_SAVE_TIME_ATTACK);
            break;
        }
        else
        {
            BitFill(3, USHORT_MAX, &sSramEwramPointer->timeAttackSaves[0], sizeof(sSramEwramPointer->timeAttackSaves[0]), 16);
            DoSramOperation(SRAM_OPERATION_SAVE_TIME_ATTACK);

            BitFill(3, USHORT_MAX, &sSramEwramPointer->timeAttackSaves[1], sizeof(sSramEwramPointer->timeAttackSaves[1]), 16);
            DoSramOperation(SRAM_OPERATION_SAVE_TIME_ATTACK2);
        }
    }

    if (!error)
        gTimeAttackRecord = pSave->value;
    else
        BitFill(3, USHORT_MAX, &gTimeAttackRecord, sizeof(gTimeAttackRecord), 16);
}

/**
 * @brief 751d8 | 18c | Writes RAM values to the demo save in Sram
 * 
 */
void SramWrite_ToEwram_DemoRam(void)
{
    struct SaveDemo* pFile;
    u32 value;

    value = USHORT_MAX;

    pFile = &gSram.demoSave;
    BitFill(3, value, pFile, sizeof(struct SaveDemo), 16);

    pFile->currentArea = gCurrentArea;
    pFile->lastDoorUsed = gLastDoorUsed;
    pFile->samusData = gSamusData;
    pFile->samusWeaponInfo = gSamusWeaponInfo;
    pFile->samusEcho = gSamusEcho;
    pFile->screwSpeedAnimation = gScrewSpeedAnimation;
    pFile->equipment = gEquipment;
    pFile->hazardDamage = gSamusHazardDamage;
    
    pFile->environmentalEffects[0] = gSamusEnvironmentalEffects[0];
    pFile->environmentalEffects[1] = gSamusEnvironmentalEffects[1];
    pFile->environmentalEffects[2] = gSamusEnvironmentalEffects[2];
    pFile->environmentalEffects[3] = gSamusEnvironmentalEffects[3];
    pFile->environmentalEffects[4] = gSamusEnvironmentalEffects[4];

    DmaTransfer(3, gVisitedMinimapTiles[gCurrentArea], pFile->visitedMinimapTiles, sizeof(pFile->visitedMinimapTiles), 16);
    DmaTransfer(3, gHatchesOpened[gCurrentArea], pFile->hatchesOpened, sizeof(pFile->hatchesOpened), 16);

    pFile->text[0] = 'A';
    pFile->text[1] = 'T';
    pFile->text[2] = 'R';
    pFile->text[3] = 'U';
    pFile->text[4] = 'N';
    pFile->text[5] = 'E';
    pFile->text[6] = 'N';
    pFile->text[7] = 'D';

    pFile->useMotherShipDoors = gUseMotherShipDoors;
    DoSramOperation(SRAM_OPERATION_SAVE_DEMO_RAM);
}

/**
 * @brief 75364 | 130 | Loads the demo ram values
 * 
 * @param loadSamusData Load samus data flag
 * @param demoNumber Demo number
 */
void SramLoad_DemoRamValues(u8 loadSamusData, u8 demoNumber)
{
    const struct SaveDemo* pDemo;

    pDemo = sDemoRamDataPointers[demoNumber];

    if (loadSamusData == FALSE)
    {
        gCurrentArea = pDemo->currentArea;
        gLastDoorUsed = pDemo->lastDoorUsed;
        gUseMotherShipDoors = pDemo->useMotherShipDoors;

        DmaTransfer(3, pDemo->visitedMinimapTiles, gVisitedMinimapTiles[gCurrentArea], sizeof(pDemo->visitedMinimapTiles), 16);
        DmaTransfer(3, pDemo->hatchesOpened, gHatchesOpened[gCurrentArea], sizeof(pDemo->hatchesOpened), 16);
    } 
    else if (loadSamusData == TRUE)
    {
        gSamusData = pDemo->samusData;
        gSamusWeaponInfo = pDemo->samusWeaponInfo;
        gSamusEcho = pDemo->samusEcho;
        gScrewSpeedAnimation = pDemo->screwSpeedAnimation;
        gEquipment = pDemo->equipment;
        gSamusHazardDamage = pDemo->hazardDamage;
        gSamusEnvironmentalEffects[0] = pDemo->environmentalEffects[0];
        gSamusEnvironmentalEffects[1] = pDemo->environmentalEffects[1];
        gSamusEnvironmentalEffects[2] = pDemo->environmentalEffects[2];
        gSamusEnvironmentalEffects[3] = pDemo->environmentalEffects[3];
        gSamusEnvironmentalEffects[4] = pDemo->environmentalEffects[4];
    }
}

/**
 * @brief 75494 | 110 | Deletes a save file
 * 
 * @param file Save file id
 * @return u32 bool, ended
 */
u32 SramDeleteFile(u8 file)
{
    struct Sram* pSram;

    pSram = &gSram;

    if (!gDisableSoftReset)
    {
        gDisableSoftReset = TRUE;
        gSramOperationStage = 0;
    }

    switch (gSramOperationStage)
    {
        case 0:
            gSaveFilesInfo[file] = sSaveFileInfo_Empty;
            gSaveFilesInfo[file].language = gLanguage;

            BitFill(3, USHORT_MAX, &pSram->files[file], sizeof(pSram->files[file]), 16);
            gSramOperationStage++;
            break;

        case 1:
            gMostRecentSaveFile = file;
            if (unk_fbc(0))
                gSramOperationStage++;
            break;

        case 2:
            BitFill(3, USHORT_MAX, &pSram->filesCopy[file], sizeof(pSram->filesCopy[file]), 16);
            gSramOperationStage++;
            break;

        case 3:
            gMostRecentSaveFile = file;
            if (unk_fbc(1))
                gSramOperationStage++;
            break;

        case 4:
        default:
            gDisableSoftReset = FALSE;
            gSramOperationStage = 0;
            break;
    }

    return gDisableSoftReset ^ TRUE;
}

/**
 * @brief 755a4 | 11c | Copies a save file
 * 
 * @param src Source file
 * @param dst Destination file
 * @return u32 bool, ended
 */
u32 SramCopyFile(u8 src, u8 dst)
{
    struct Sram* pSram;

    pSram = &gSram;

    if (!gDisableSoftReset)
    {
        gDisableSoftReset = TRUE;
        gSramOperationStage = 0;
    }

    switch (gSramOperationStage)
    {
        case 0:
            // Copy save file info
            gSaveFilesInfo[dst] = gSaveFilesInfo[src];

            // Copy file
            DmaTransfer(3, &pSram->files[src], &pSram->files[dst], sizeof(struct SaveFile), 16);
            gSramOperationStage++;
            break;

        case 1:
            gMostRecentSaveFile = dst;
            if (unk_fbc(0))
                gSramOperationStage++;
            gMostRecentSaveFile = src;
            break;

        case 2:
            // Copy copy of the file
            DmaTransfer(3, &pSram->filesCopy[src], &pSram->filesCopy[dst], sizeof(struct SaveFile), 16);
            gSramOperationStage++;
            break;

        case 3:
            gMostRecentSaveFile = dst;
            if (unk_fbc(1))
                gSramOperationStage++;
            gMostRecentSaveFile = src;
            break;

        case 4:
        default:
            // End, re-enable soft reset
            gDisableSoftReset = FALSE;
            gSramOperationStage = 0;
            break;
    }

    // If soft reset is enabled, then the process is complete
    return gDisableSoftReset ^ TRUE;
}

/**
 * @brief 756c0 | 108 | Writes the SRAM data to the file info
 * 
 */
void SramWrite_FileInfo(void)
{
    s32 i;
    struct Sram* pSram;
    struct SaveFile* pFile;

    pSram = &gSram;
    
    for (i = 0; i < ARRAY_SIZE(pSram->files); i++)
    {
        pFile = &pSram->files[i];

        gSaveFilesInfo[i].currentArea = pFile->currentArea;

        if (gSaveFilesInfo[i].exists == TRUE)
        {
            gSaveFilesInfo[i].currentEnergy = pFile->equipment.currentEnergy;
            gSaveFilesInfo[i].maxEnergy = pFile->equipment.maxEnergy;
            gSaveFilesInfo[i].currentMissiles = pFile->equipment.currentMissiles;
            gSaveFilesInfo[i].maxMissiles = pFile->equipment.maxMissiles;
            gSaveFilesInfo[i].suitType = pFile->equipment.suitType;
            gSaveFilesInfo[i].igtHours = pFile->inGameTimer.hours;
            gSaveFilesInfo[i].igtMinutes = pFile->inGameTimer.minutes;
            gSaveFilesInfo[i].igtSeconds = pFile->inGameTimer.seconds;
            gSaveFilesInfo[i].hasSaved = pFile->hasSaved;
            gSaveFilesInfo[i].completedGame = pFile->gameCompletion.completedGame;
            gSaveFilesInfo[i].introPlayed = pFile->gameCompletion.introPlayed;
            gSaveFilesInfo[i].language = pFile->gameCompletion.language;
            gSaveFilesInfo[i].timeAttack = pFile->timeAttack;

            if (pFile->difficulty >= DIFF_END)
                gSaveFilesInfo[i].difficulty = DIFF_NORMAL;
            else
                gSaveFilesInfo[i].difficulty = pFile->difficulty;
        }

        if (gSaveFilesInfo[i].exists && gSaveFilesInfo[i].hasSaved)
            continue;

        gSaveFilesInfo[i].exists = FALSE;
        gSaveFilesInfo[i].currentArea = AREA_BRINSTAR;
        gSaveFilesInfo[i].currentEnergy = 0;
        gSaveFilesInfo[i].maxEnergy = 0;
        gSaveFilesInfo[i].currentMissiles = 0;
        gSaveFilesInfo[i].maxMissiles = 0;
        gSaveFilesInfo[i].suitType = SUIT_NORMAL;
        gSaveFilesInfo[i].igtHours = 0;
        gSaveFilesInfo[i].igtMinutes = 0;
        gSaveFilesInfo[i].igtSeconds = 0;
        gSaveFilesInfo[i].language = gLanguage;

        if (!gSaveFilesInfo[i].introPlayed)
            continue;

        gSaveFilesInfo[i].currentArea = AREA_CRATERIA;
        gSaveFilesInfo[i].currentEnergy = 99;
        gSaveFilesInfo[i].maxEnergy = 99;
        gSaveFilesInfo[i].difficulty = DIFF_EASY;

        if (pFile->difficulty > DIFF_HARD)
            gSaveFilesInfo[i].difficulty = DIFF_NORMAL;
        else
            gSaveFilesInfo[i].difficulty = pFile->difficulty;
        
        gSaveFilesInfo[i].language = pFile->gameCompletion.language;
        gSaveFilesInfo[i].timeAttack = pFile->timeAttack;
    }
}

/**
 * @brief 757c8 | 84 | To document
 * 
 * @param file File number
 */
void unk_757c8(u8 file)
{
    s32 previousFile;

    previousFile = gMostRecentSaveFile;
    gMostRecentSaveFile = file;

    switch (gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag)
    {
        case CORRUPTED_FILE_FLAG_CURRENT:
            DoSramOperation(3);
            break;

        case CORRUPTED_FILE_FLAG_CURRENT_AND_BACKUP:
            DoSramOperation(3);
            DoSramOperation(4);
            break;

        case 0:
        case 3:
        case 4:
            break;
    }

    gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = 0;
    gMostRecentSaveFile = previousFile;
}

/**
 * @brief 7584c | 120 | To document
 * 
 * @param param_1 To document
 */
void unk_7584c(u8 param_1)
{
    #ifdef DEBUG
    u8 temp;
    #endif // DEBUG

    gButtonAssignments = sDefaultButtonAssignments;
    gMaxInGameTimerFlag = FALSE;
    gShipLandingFlag = FALSE;
    gColorFading.type = COLOR_FADING_CANCEL;

    switch (param_1)
    {
        case 0:
            gSectionInfo = sSectionInfo;
            Sram_CheckLoadSaveFile();

            gCurrentCutscene = 0;
            break;

        case 1:
            gSectionInfo = sSectionInfo;
            Sram_InitSaveFile();
            gCurrentRoom = 0;
            gLastDoorUsed = 0;
            gMaxInGameTimerFlag = TRUE;
            gSkipDoorTransition = FALSE;
            #ifdef DEBUG
            if (gDemoState != DEMO_STATE_NONE)
            #endif // DEBUG
            {
                gDebugMode = FALSE;            
            }

            #if defined(REGION_EU)
            if (INVALID_EU_LANGUAGE(gLanguage))
            #elif defined(REGION_JP)
            if (gLanguage > LANGUAGE_HIRAGANA)
            #endif
            {
                gLanguage = LANGUAGE_DEFAULT;
            }

            gCurrentCutscene = 0;
            break;

        case 2:
            #ifdef DEBUG
            gSectionInfo = sSectionInfo;
            Sram_InitSaveFile();
            // Written this way to produce matching ASM
            temp = gDebugMode;
            if (gDebugMode == 0)
            {
                gDebugMode = 2;
                BootDebugWriteSram(temp);
            }

            gEquipment.downloadedMapStatus = gSectionInfo.downloadedMaps;
            gSectionInfo.sectionIndex = gCurrentArea;
            gSectionInfo.starIndex = gCurrentArea;
            gAreaBeforeTransition = gCurrentArea;
            gCurrentRoom = 0;
            gLastDoorUsed = 1;
            SramRead_Language();
            #endif // DEBUG
            break;

        case 3:
            gIsLoadingFile = gSaveFilesInfo[gMostRecentSaveFile].exists;
            if (gIsLoadingFile)
                SramLoadFile();

            gCurrentCutscene = 0;
            break;
    }

    gSubGameMode3 = 0;
    gMonochromeBgFading = 0;
    gDisableSoftReset = FALSE;
    gSubGameModeStage = 0;
    gPauseScreenFlag = PAUSE_SCREEN_NONE;
    gDisablePause = FALSE;
    gSamusDoorPositionOffset = 0;
}

/**
 * @brief 7596c | 128 | Checks if a save file should load
 * 
 */
void Sram_CheckLoadSaveFile(void)
{
    // Checks current save file exists
    gIsLoadingFile = gSaveFilesInfo[gMostRecentSaveFile].exists;
    if (!gIsLoadingFile)
    {
        // No save file, create one and setup data
        Sram_InitSaveFile();

        gColorFading.type = COLOR_FADING_LANDING_SHIP;

        gEquipment.downloadedMapStatus = 0;
        gCurrentArea = gSectionInfo.sectionIndex;
        gAreaBeforeTransition = gSectionInfo.sectionIndex;
        
        gCurrentRoom = 0;
        gLastDoorUsed = 0;

        gGameCompletion.completedGame = gSaveFilesInfo[gMostRecentSaveFile].completedGame;
        gGameCompletion.introPlayed = gSaveFilesInfo[gMostRecentSaveFile].introPlayed;
        gGameCompletion.language = gSaveFilesInfo[gMostRecentSaveFile].language;
    
        gDifficulty = gSaveFilesInfo[gMostRecentSaveFile].difficulty;
        gTimeAttackFlag = gSaveFilesInfo[gMostRecentSaveFile].timeAttack;
        gUseMotherShipDoors = FALSE;
        gShipLandingFlag = TRUE;
    }
    else
    {
        // Save file exists, load it
        SramLoadFile();
    }

    gGameCompletion.language = gSaveFilesInfo[gMostRecentSaveFile].language;
    gLanguage = gGameCompletion.language;
    gSkipDoorTransition = FALSE;
    gDebugMode = FALSE;
}
