#ifndef MESSAGE_BANNER_AI_H
#define MESSAGE_BANNER_AI_H

#include "types.h"

// Message banner

#define MESSAGE_BANNER_POSE_GFX_INIT 0x8
#define MESSAGE_BANNER_POSE_POP_UP 0x9
#define MESSAGE_BANNER_POSE_STATIC 0x23
#define MESSAGE_BANNER_POSE_REMOVAL_INIT 0x24
#define MESSAGE_BANNER_POSE_REMOVAL_ANIMATION 0x25

void MessageBanner(void);
void SaveYesNoCursor(void);

#endif /* MESSAGE_BANNER_AI_H* */
