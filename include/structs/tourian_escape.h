#ifndef TOURIAN_ESCAPE_STRUCT_H
#define TOURIAN_ESCAPE_STRUCT_H

#include "types.h"

#define TOURIAN_ESCAPE_DATA sNonGameplayRamPointer->tourianEscape

#define TOURIAN_ESCAPE_MAX_OBJECTS 10

struct TourianEscapeData {
    u8 stage;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u16 timer;

    u8 unk_8[TOURIAN_ESCAPE_MAX_OBJECTS];
    u8 unk_12;
    u8 unk_13;

    const u16* oamFramePointers[TOURIAN_ESCAPE_MAX_OBJECTS];
    u8 oamFrames[TOURIAN_ESCAPE_MAX_OBJECTS];
    u8 oamTimers[TOURIAN_ESCAPE_MAX_OBJECTS];
    u16 oamXPositions[TOURIAN_ESCAPE_MAX_OBJECTS];
    u16 oamYPositions[TOURIAN_ESCAPE_MAX_OBJECTS];
    u8 oamPriorities[TOURIAN_ESCAPE_MAX_OBJECTS];

    u16 unk_82;
    u16 scaling;

    u8 padding_86[16];

    s16 unk_96[TOURIAN_ESCAPE_MAX_OBJECTS];

    u8 padding_AA[4];

    s16 unk_AE;
    u16 unk_B0;

    u8 padding_B2[12];

    u8 unk_BE;
    u8 unk_BF;

    u16 dispcnt;
    u16 bldcnt;
    s16 win0h_H;
    s16 win0h_L;
    s16 win0v_H;
    s16 win0v_L;
};

extern s32 gWrittenToBg2X;
extern s32 gWrittenToBg2Y;

extern u16 gBg2XScaling;
extern u16 gBg2YScaling;
extern u16 gBg2Rotation;
extern s16 gWrittenToBg2Pa;
extern s16 gWrittenToBg2Pb;
extern s16 gWrittenToBg2Pc;
extern s16 gWrittenToBg2Pd;

#endif /* TOURIAN_ESCAPE_STRUCT_H */
