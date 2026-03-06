#ifndef TEXT_H
#define TEXT_H

#include "types.h"

#include "constants/text.h"

#include "structs/text.h"

u32 TextGetCharacterWidth(u16 charId);
void TextDrawCharacter(u16 charId, u32* dst, u16 indent, u8 color);
void TextDrawMessageCharacter(u16 charId, u32* dst, u16 indent, u8 color);
void TextDrawLocationTextCharacters(u8 param_1, const u16** ppText);
void TextDrawLocation(u8 locationText, u8 gfxSlot);
u8 unk_6f0a8(u8 textId, u8 gfxSlot, u8 param_3);
void TextStartMessage(u8 textId, u8 gfxSlot);
u8 TextProcessMessageBanner(void);
void TextStartStory(StoryTextId textId);
u8 TextProcessStory(void);
void TextStartFileScreen(u8 textId);
u8 TextProcessFileScreenPopUp(void);
void TextProcessDescription(void);
u8 TextProcessCurrentMessage(struct Message* pMessage, const u16* pText, u32* dst);
void TextDrawYesNoEasySleep(void);
void TextDrawEasySleep(void);

#endif /* TEXT_H */
