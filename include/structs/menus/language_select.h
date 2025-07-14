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
    u16 unk_0; // timer?
    u16 unk_2;
    u16 unk_4; // dispcnt?
    u8 unk_6[8];
    u16 unk_e; // bldcnt?
    u8 unk_10; // bool?
    u8 selectedLanguage; // 10
    struct LanguageColorAnimation languageAnimation; // 14
};

#endif /* LANGUAGE_SELECT_STRUCT_H */
