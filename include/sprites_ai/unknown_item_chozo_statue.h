#ifndef UNKNOWN_ITEM_CHOZO_STATUE_AI_H
#define UNKNOWN_ITEM_CHOZO_STATUE_AI_H

#include "types.h"

enum UnknownItemChozoStatuePart {
    UNKNOWN_ITEM_CHOZO_STATUE_PART_ARM,
    UNKNOWN_ITEM_CHOZO_STATUE_PART_GLOW,
    UNKNOWN_ITEM_CHOZO_STATUE_PART_EYE,
    UNKNOWN_ITEM_CHOZO_STATUE_PART_LEG,
    UNKNOWN_ITEM_CHOZO_STATUE_PART_HEAD,

    UNKNOWN_ITEM_CHOZO_STATUE_PART_END
};

void UnknownItemChozoStatue(void);
void UnknownItemChozoStatuePart(void);
void UnknownItemChozoStatueRefill(void);
void ChozoStatueStandingChangeClipdata(u8 bodyCaa, u8 handCaa);
void ChozoStatueSeatedChangeClipdata(u8 caa);

#endif /* UNKNOWN_ITEM_CHOZO_STATUE_AI_H */