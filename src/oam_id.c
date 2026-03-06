#include "oam_id.h"

/**
 * @brief 68128 | 20 | Updates the OAM ID of a menu oam data
 * 
 * @param pOam Menu OAM data pointer
 * @param oamId OAM ID
 */
void UpdateMenuOamDataId(struct MenuOamData* pOam, u8 oamId)
{
    pOam->oamId = oamId;
    pOam->exists = oamId ? OAM_ID_CHANGED_FLAG : FALSE;
}

/**
 * @brief 68148 | 20 | Updates the OAM ID of a cutscene oam data
 * 
 * @param pOam Cutscene OAM data pointer
 * @param oamId OAM ID
 */
void UpdateCutsceneOamDataId(struct CutsceneOamData* pOam, u8 oamId)
{
    pOam->oamId = oamId;
    pOam->exists = oamId ? OAM_ID_CHANGED_FLAG : FALSE;
}
