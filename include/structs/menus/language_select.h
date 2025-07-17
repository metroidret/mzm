#ifndef LANGUAGE_SELECT_STRUCT_H
#define LANGUAGE_SELECT_STRUCT_H

#include "types.h"

#define LANGUAGE_SELECT_DATA sNonGameplayRamPointer->languageSelect

struct LanguageColorAnimation {
    u16 timer;
    u8 interval;
    u8 index;
};

struct LanguageSelectData {
    u16 timer;
    u16 unused_2;
    u16 dispcnt;
    u8 unused_6[8];
    u16 bldcnt;
    u8 loadLanguageSelect;
    u8 selectedLanguage;
    struct LanguageColorAnimation languageAnimation;
};

#endif /* LANGUAGE_SELECT_STRUCT_H */
