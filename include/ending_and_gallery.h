#ifndef ENDING_AND_GALLERY_H
#define ENDING_AND_GALLERY_H

#include "types.h"

typedef u8 (*CreditsFunc_T)(void);

u32 CreditsMainLoop(void);
u32 GalleryMainLoop(void);

#endif /* ENDING_AND_GALLERY_H */
