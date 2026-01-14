#ifndef FILE_SELECT_MENU_H
#define FILE_SELECT_MENU_H

#include "types.h"
#include "structs/save_file.h"

void FileSelectApplyStereo(void);
void FileSelectProcessOAM(void);

u32 FileSelectMenuMainLoop(void);

void FileSelectPlayMenuSound(u8 request);

#endif /* FILE_SELECT_MENU_H */
