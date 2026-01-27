#ifndef UNKNOWN_ITEM_CHOZO_STATUE_AI_H
#define UNKNOWN_ITEM_CHOZO_STATUE_AI_H

#include "types.h"
#include "constants/clipdata.h"

MAKE_ENUM(u8, UnknownItemChozoStatuePartId) {
    UNKNOWN_ITEM_CHOZO_STATUE_PART_ARM,
    UNKNOWN_ITEM_CHOZO_STATUE_PART_GLOW,
    UNKNOWN_ITEM_CHOZO_STATUE_PART_EYE,
    UNKNOWN_ITEM_CHOZO_STATUE_PART_LEG,
    UNKNOWN_ITEM_CHOZO_STATUE_PART_HEAD,

    UNKNOWN_ITEM_CHOZO_STATUE_PART_COUNT
};

void UnknownItemChozoStatue(void);
void UnknownItemChozoStatuePart(void);
void UnknownItemChozoStatueRefill(void);
void ChozoStatueStandingChangeClipdata(ClipdataAffectingAction bodyCaa, ClipdataAffectingAction handCaa);
void ChozoStatueSeatedChangeClipdata(ClipdataAffectingAction caa);

#endif /* UNKNOWN_ITEM_CHOZO_STATUE_AI_H */
