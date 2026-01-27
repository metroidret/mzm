#ifndef CABLE_LINK_STRUCTS_H
#define CABLE_LINK_STRUCTS_H

#include "types.h"

#include "constants/cable_link.h"

struct IoTransferInfo {
    Func_T pFunction;
    u8 linkInProgress;
    u16 timer;
    ActiveTransfer active;
    ConnectStage connectStage;
    LinkStage linkStage;
    TransferResult result;
    u8 errorFlag;
    u16 command;
    s8 fusionGalleryImages;
    s8 language;
    u16 musicTrack;
    u16 musicPriority;
};

extern struct IoTransferInfo gIoTransferInfo;

extern struct MultiBootData gMultiBootParamData;
extern const u8* gDataSentPointer;
extern u32 gDataSentSize;

extern u32 gMultibootErrorFlags;  // set but never read
extern u32 gMultibootUnk_3005880; // read but never set (always 0)
extern u8 gMultibootInProgress;   // set but never read

#endif /* CABLE_LINK_STRUCTS_H */
