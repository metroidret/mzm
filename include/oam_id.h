#ifndef OAM_ID_H
#define OAM_ID_H

#include "types.h"
#include "structs/cutscene.h"
#include "structs/menu.h"

void UpdateMenuOamDataId(struct MenuOamData* pOam, u8 oamId);
void UpdateCutsceneOamDataId(struct CutsceneOamData* pOam, u8 oamId);

#endif /* OAM_ID_H */
