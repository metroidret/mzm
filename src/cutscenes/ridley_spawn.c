#include "cutscenes/ridley_spawn.h"
#include "cutscenes/cutscene_utils.h"
#include "dma.h"

#include "data/shortcut_pointers.h"
#include "data/cutscenes/ridley_spawn_data.h"
#include "data/cutscenes/cutscenes_data.h"

#include "constants/audio.h"
#include "constants/cutscene.h"
#include "constants/samus.h"

#include "structs/cutscene.h"
#include "structs/display.h"
#include "structs/samus.h"

static void RidleySpawnUpdateRidley(struct CutsceneOamData* pOam);
static void RidleySpawnProcessOAM(void);

static struct Coordinates sRidleySpawnRidleyPositions[3] = {
    [0] = {
        .x = BLOCK_SIZE * 9,
        .y = BLOCK_SIZE * 5 + HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE + PIXEL_SIZE
    },
    [1] = {
        .x = BLOCK_SIZE * 7,
        .y = BLOCK_SIZE * 3
    },
    [2] = {
        .x = BLOCK_SIZE * 8 + HALF_BLOCK_SIZE,
        .y = BLOCK_SIZE * 5 + HALF_BLOCK_SIZE
    }
};

/**
 * @brief 65304 | 19c | Handles the ridley flying in part of the cutscene
 * 
 * @return u8 FALSE
 */
static u8 RidleySpawnRidleyFlyingIn(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            DmaTransfer(3, sRidleySpawnRidleyScreamingPal, PALRAM_OBJ, sizeof(sRidleySpawnRidleyScreamingPal), 16);
            CallLZ77UncompVram(sRidleySpawnScreamingGfx, VRAM_OBJ);
            
            CallLZ77UncompVram(sRidleySpawnBackgroundGfx, BGCNT_TO_VRAM_CHAR_BASE(sRidleySpawnPageData[3].graphicsPage));
            CallLZ77UncompVram(sRidleySpawnBackgroundTileTable, BGCNT_TO_VRAM_TILE_BASE(sRidleySpawnPageData[3].tiletablePage));
            DmaTransfer(3, sRidleySpawnBackgroundPal, PALRAM_BASE, sizeof(sRidleySpawnBackgroundPal), 16);
            SET_BACKDROP_COLOR(COLOR_BLACK);
            CutsceneSetBgcntPageData(sRidleySpawnPageData[3]);

            CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleySpawnPageData[3].bg, NON_GAMEPLAY_START_BG_POS);
            CutsceneReset();
            
            CUTSCENE_DATA.oam[0].xPosition = sRidleySpawnRidleyPositions[1].x;
            CUTSCENE_DATA.oam[0].yPosition = sRidleySpawnRidleyPositions[1].y;

            CUTSCENE_DATA.oam[0].rotationScaling = TRUE;
            CUTSCENE_DATA.oam[0].notDrawn = FALSE;
            CUTSCENE_DATA.oam[0].priority = 0;
            CUTSCENE_DATA.oam[0].objMode = FALSE;

            gCurrentOamScaling = Q_8_8(1.125f);
            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[0], RIDLEY_SPAWN_OAM_ID_RIDLEY_FLYING);
            CUTSCENE_DATA.dispcnt = sRidleySpawnPageData[3].bg | DCNT_OBJ;
            
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            CUTSCENE_DATA.oam[0].actions |= 3;
            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 2:
            if (CUTSCENE_DATA.oam[0].actions == 0)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            CutsceneFadeScreenToBlack();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    RidleySpawnUpdateRidley(&CUTSCENE_DATA.oam[0]);

    #ifdef DEBUG
    CutsceneCheckSkipStage(1);
    #endif // DEBUG

    return FALSE;
}

/**
 * @brief 654a0 | a0 | Updates the ridley object
 * 
 * @param pOam Cutscene OAM Pointer
 */
static void RidleySpawnUpdateRidley(struct CutsceneOamData* pOam)
{
    u16 velocity;
    
    if (pOam->actions & 1)
    {
        pOam->unk_16 += 2;
        gCurrentOamScaling += 4 + DIV_SHIFT(pOam->unk_16, 8);

        if (gCurrentOamScaling >= Q_8_8(1.97f))
        {
            gCurrentOamScaling = Q_8_8(1.97f);
            pOam->actions = 0;
        }
        else if (pOam->oamID != RIDLEY_SPAWN_OAM_ID_RIDLEY_SCREAMING && gCurrentOamScaling >= Q_8_8(1.44f))
        {
            SoundPlay(SOUND_RIDLEY_SPAWN_ROAR);
            UpdateCutsceneOamDataID(pOam, RIDLEY_SPAWN_OAM_ID_RIDLEY_SCREAMING);
        }
    }

    if (pOam->actions & 2)
    {
        pOam->unk_18++;
        velocity = DIV_SHIFT((u16)pOam->unk_18, 4);
        pOam->yVelocity = 4 - velocity;
        if (pOam->yVelocity < 0)
        {
            pOam->yVelocity = 0;
            pOam->actions &= 1;
        }

        pOam->yVelocity *= 4;
        pOam->yPosition += pOam->yVelocity;
    }
}

/**
 * @brief 65540 | 12c | Handles the helmet reflection part
 * 
 * @return u8 FALSE
 */
static u8 RidleySpawnHelmetReflection(void)
{    
    s32 velocity;

    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            CutsceneReset();
            gWrittenToBldalpha_L = BLDALPHA_MAX_VALUE / 2 + 2;
            gWrittenToBldalpha_H = BLDALPHA_MAX_VALUE / 2 - 2;

            CUTSCENE_DATA.bldcnt = BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_SCREEN_SECOND_TARGET;

            CUTSCENE_DATA.oam[0].xPosition = sRidleySpawnRidleyPositions[0].x;
            CUTSCENE_DATA.oam[0].yPosition = sRidleySpawnRidleyPositions[0].y;

            CUTSCENE_DATA.oam[0].priority = sRidleySpawnPageData[2].priority;
            CUTSCENE_DATA.oam[0].rotationScaling = TRUE;
            CUTSCENE_DATA.oam[0].objMode = 1;

            gCurrentOamScaling = Q_8_8(.25f);
            UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[0], RIDLEY_SPAWN_OAM_ID_RIDLEY_FLYING_REFLECTION);
            CUTSCENE_DATA.dispcnt = sRidleySpawnPageData[1].bg | sRidleySpawnPageData[2].bg | DCNT_OBJ;

            CUTSCENE_DATA.timeInfo.timer = 0;
            CUTSCENE_DATA.timeInfo.subStage++;
            break;

        case 1:
            gCurrentOamScaling += Q_8_8(0.0625f);
            if (gCurrentOamScaling >= Q_8_8(2.f))
            {
                gCurrentOamScaling = Q_8_8(2.f);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }

            velocity = 8 - SUB_PIXEL_TO_PIXEL(CUTSCENE_DATA.timeInfo.timer); // ?
            if (velocity > 0)
                CUTSCENE_DATA.oam[0].yPosition += velocity;

            CUTSCENE_DATA.oam[0].xPosition -= PIXEL_SIZE;
            break;

        case 2:
            CutsceneFadeScreenToBlack();
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
    }

    #ifdef DEBUG
    CutsceneCheckSkipStage(1);
    #endif // DEBUG

    return FALSE;
}

/**
 * @brief 6566c | 7c | Handles the samus looking up part of the cutscene
 * 
 * @return u8 FALSE
 */
static u8 RidleySpawnSamusLookingUp(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(.5f))
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;
    
        case 1:
            gCurrentOamScaling += Q_8_8(0.25f / 2);
            if (gCurrentOamScaling >= Q_8_8(2.f))
            {
                gCurrentOamScaling = Q_8_8(2.f);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;
        
        case 2:
            if (CUTSCENE_DATA.timeInfo.timer > TWO_THIRD_SECOND)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            CUTSCENE_DATA.timeInfo.stage++;
            MACRO_CUTSCENE_NEXT_STAGE();
            break;
    }

    #ifdef DEBUG
    CutsceneCheckSkipStage(0);
    #endif // DEBUG

    return FALSE;
}

/**
 * @brief 656e8 | 1bc | Initializes the ridley spawn cutscene
 * 
 * @return u8 FALSE
 */
static u8 RidleySpawnInit(void)
{
    CutsceneFadeScreenToBlack();

    if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
        DmaTransfer(3, sRidleySpawnSamusVariaPal, PALRAM_OBJ, sizeof(sRidleySpawnSamusVariaPal), 16);
    else
        DmaTransfer(3, sRidleySpawnSamusPal, PALRAM_OBJ, sizeof(sRidleySpawnSamusPal), 16);

    DmaTransfer(3, sRidleySpawnBackgroundPal, PALRAM_BASE, sizeof(sRidleySpawnBackgroundPal), 16);
    SET_BACKDROP_COLOR(COLOR_BLACK);

    CallLZ77UncompVram(sRidleySpawnSamusAndRidleyGfx, VRAM_OBJ);

    CallLZ77UncompVram(sRidleySpawnBackgroundGfx, BGCNT_TO_VRAM_CHAR_BASE(sRidleySpawnPageData[0].graphicsPage));
    CallLZ77UncompVram(sRidleySpawnBackgroundTileTable, BGCNT_TO_VRAM_TILE_BASE(sRidleySpawnPageData[0].tiletablePage));

    CallLZ77UncompVram(sRidleySpawnSamusHelmetFaceGfx, BGCNT_TO_VRAM_CHAR_BASE(sRidleySpawnPageData[1].graphicsPage));
    CallLZ77UncompVram(sRidleySpawnSamusHelmetTileTable, BGCNT_TO_VRAM_TILE_BASE(sRidleySpawnPageData[1].tiletablePage));
    CallLZ77UncompVram(sRidleySpawnSamusFaceTileTable, BGCNT_TO_VRAM_TILE_BASE(sRidleySpawnPageData[2].tiletablePage));

    CutsceneSetBgcntPageData(sRidleySpawnPageData[1]);
    CutsceneSetBgcntPageData(sRidleySpawnPageData[2]);
    CutsceneSetBgcntPageData(sRidleySpawnPageData[0]);

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleySpawnPageData[1].bg, NON_GAMEPLAY_START_BG_POS);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleySpawnPageData[2].bg, NON_GAMEPLAY_START_BG_POS);
    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sRidleySpawnPageData[0].bg, NON_GAMEPLAY_START_BG_POS);
    
    CutsceneReset();

    CUTSCENE_DATA.oam[0].xPosition = sRidleySpawnRidleyPositions[2].x;
    CUTSCENE_DATA.oam[0].yPosition = sRidleySpawnRidleyPositions[2].y;
    CUTSCENE_DATA.oam[0].priority = sRidleySpawnPageData[0].priority;
    CUTSCENE_DATA.oam[0].rotationScaling = TRUE;
    CUTSCENE_DATA.oam[0].objMode = 1;

    gCurrentOamScaling = Q_8_8(1.f);
    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[0], RIDLEY_SPAWN_OAM_ID_SAMUS);

    CUTSCENE_DATA.dispcnt = sRidleySpawnPageData[0].bg | DCNT_OBJ;

    PlayMusic(MUSIC_RIDLEY_BATTLE, 0);
    CUTSCENE_DATA.timeInfo.stage++;
    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;
    
    return FALSE;
}

static struct CutsceneStageData sRidleySpawnStageData[5] = {
    [0] = {
        .pFunction = RidleySpawnInit,
        .oamLength = 1,
    },
    [1] = {
        .pFunction = RidleySpawnSamusLookingUp,
        .oamLength = 1
    },
    [2] = {
        .pFunction = RidleySpawnHelmetReflection,
        .oamLength = 1
    },
    [3] = {
        .pFunction = RidleySpawnRidleyFlyingIn,
        .oamLength = 1
    },
    [4] = {
        .pFunction = CutsceneEndFunction,
        .oamLength = 1
    }
};

/**
 * @brief 658a4 | 34 | Main loop for the ridley spawn cutscene
 * 
 * @return u8 bool, ended
 */
u8 RidleySpawnMainLoop(void)
{
    u8 ended;

    ended = sRidleySpawnStageData[CUTSCENE_DATA.timeInfo.stage].pFunction();
    CutsceneUpdateBackgroundsPosition(TRUE);
    RidleySpawnProcessOAM();
    
    return ended;
}

/**
 * @brief 658d8 | 4c | Processes the OAM for the cutscene
 * 
 */
static void RidleySpawnProcessOAM(void)
{
    gNextOamSlot = 0;
    ProcessCutsceneOam(sRidleySpawnStageData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sRidleySpawnOam);
    ResetFreeOam();
    CalculateOamPart4(gCurrentOamRotation, gCurrentOamScaling, 0);
}
