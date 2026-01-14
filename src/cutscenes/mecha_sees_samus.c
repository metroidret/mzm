#include "cutscenes/mecha_sees_samus.h"
#include "cutscenes/cutscene_utils.h"
#include "audio_wrappers.h"
#include "dma.h"
#include "oam_id.h"
#include "syscall_wrappers.h"

#include "data/cutscenes/cutscenes_data.h"
#include "data/cutscenes/mecha_sees_samus_data.h"
#include "data/shortcut_pointers.h"

#include "constants/audio.h"
#include "constants/cutscene.h"

#include "structs/cutscene.h"

static void MechaRidleySeesSamusProcessOAM(void);

/**
 * @brief 65924 | 100 | Handles the eye part of the mecha sees samus cutscene
 * 
 * @return u8 FALSE
 */
static u8 MechaRidleySeesSamusEyeOpen(void)
{
    switch (CUTSCENE_DATA.timeInfo.subStage)
    {
        case 0:
            if (CutsceneTransferAndUpdateFade())
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 1:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(.5f))
            {
                SoundPlay(SOUND_MECHA_SEES_SAMUS_EYE_OPENING);
                UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[0], 2);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 2:
            if (!CUTSCENE_DATA.oam[0].exists)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 3:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(1.f / 15))
            {
                SoundPlay(SOUND_MECHA_SEES_SAMUS_EYE_FOCUSING);
                UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[1], 4);
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 4:
            if (CUTSCENE_DATA.oam[1].ended)
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 5:
            if (CUTSCENE_DATA.timeInfo.timer > CONVERT_SECONDS(1.f))
            {
                CUTSCENE_DATA.timeInfo.timer = 0;
                CUTSCENE_DATA.timeInfo.subStage++;
            }
            break;

        case 6:
            CutsceneFadeScreenToBlack();
            {
                CUTSCENE_DATA.timeInfo.stage++;
                MACRO_CUTSCENE_NEXT_STAGE();
            }
    }

    #ifdef DEBUG
    CutsceneCheckSkipStage(1);
    #endif // DEBUG

    return FALSE;
}

/**
 * @brief 65a24 | 148 | Initializes the mecha ridley sees Samus cutscene
 * 
 * @return u8 FALSE
 */
static u8 MechaRidleySeesSamusInit(void)
{
    CutsceneFadeScreenToBlack();
    DmaTransfer(3, sMechaSeesSamusPal, PALRAM_BASE, sizeof(sMechaSeesSamusPal), 16);
    DmaTransfer(3, PALRAM_BASE, PALRAM_OBJ, PAL_SIZE, 32);

    SET_BACKDROP_COLOR(COLOR_BLACK);

    CallLZ77UncompVram(sMechaSeesSamusMetalGfx, BGCNT_TO_VRAM_CHAR_BASE(sMechaRidleySeesSamusPagesData[0].graphicsPage));
    CallLZ77UncompVram(sMechaSeesSamusCoverMetalTileTable, BGCNT_TO_VRAM_TILE_BASE(sMechaRidleySeesSamusPagesData[0].tiletablePage));
    CallLZ77UncompVram(sMechaSeesSamusCoverEyeGfx, BGCNT_TO_VRAM_CHAR_BASE(4));

    CutsceneSetBgcntPageData(sMechaRidleySeesSamusPagesData[0]);

    CutsceneSetBackgroundPosition(CUTSCENE_BG_EDIT_HOFS | CUTSCENE_BG_EDIT_VOFS, sMechaRidleySeesSamusPagesData[0].bg, NON_GAMEPLAY_START_BG_POS);
    CutsceneReset();

    CUTSCENE_DATA.oam[0].xPosition = SCREEN_SIZE_X_SUB_PIXEL / 2;
    CUTSCENE_DATA.oam[0].yPosition = SCREEN_SIZE_Y_SUB_PIXEL / 2;
    CUTSCENE_DATA.oam[0].priority = sMechaRidleySeesSamusPagesData[0].priority;
    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[0], 1);

    CUTSCENE_DATA.oam[1].xPosition = SCREEN_SIZE_X_SUB_PIXEL / 2;
    CUTSCENE_DATA.oam[1].yPosition = SCREEN_SIZE_Y_SUB_PIXEL / 2;
    CUTSCENE_DATA.oam[1].priority = sMechaRidleySeesSamusPagesData[0].priority + 1;
    UpdateCutsceneOamDataID(&CUTSCENE_DATA.oam[1], 3);

    CutsceneStartBackgroundFading(2);

    CUTSCENE_DATA.dispcnt = sMechaRidleySeesSamusPagesData[0].bg | DCNT_OBJ;
    CUTSCENE_DATA.timeInfo.timer = 0;
    CUTSCENE_DATA.timeInfo.subStage = 0;
    CUTSCENE_DATA.timeInfo.stage++;

    return FALSE;
}

static struct CutsceneStageData sMechaSeesSamusStageData[3] = {
    [0] = {
        .pFunction = MechaRidleySeesSamusInit,
        .oamLength = 2
    },
    [1] = {
        .pFunction = MechaRidleySeesSamusEyeOpen,
        .oamLength = 2
    },
    [2] = {
        .pFunction = CutsceneEndFunction,
        .oamLength = 2
    }
};

/**
 * @brief 65b6c | 34 | Mecha ridley sees Samus cutscene main loop
 * 
 * @return u8 bool, ended
 */
u8 MechaRidleySeesSamusMainLoop(void)
{
    u8 ended;

    ended = sMechaSeesSamusStageData[CUTSCENE_DATA.timeInfo.stage].pFunction();
    CutsceneUpdateBackgroundsPosition(TRUE);
    MechaRidleySeesSamusProcessOAM();

    return ended;
}

/**
 * @brief 65ba0 | 38 | Processes the OAM for the cutscene
 * 
 */
static void MechaRidleySeesSamusProcessOAM(void)
{
    gNextOamSlot = 0;
    ProcessCutsceneOam(sMechaSeesSamusStageData[CUTSCENE_DATA.timeInfo.stage].oamLength, CUTSCENE_DATA.oam, sMechaSeesSamusCutsceneOam);
    ResetFreeOam();
}
