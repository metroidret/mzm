#ifndef SYSCALLS_H
#define SYSCALLS_H

#include "types.h"

#define SYSCALL(num) asm("svc " #num)

#define SYSCALL_SoftReset 0
#define SYSCALL_RegisterRamReset 1
#define SYSCALL_Halt 2
#define SYSCALL_Stop 3
#define SYSCALL_IntrWait 4
#define SYSCALL_VBlankIntrWait 5
#define SYSCALL_Div 6
#define SYSCALL_DivArm 7
#define SYSCALL_Sqrt 8
#define SYSCALL_ArcTan 9
#define SYSCALL_ArcTan2 10
#define SYSCALL_CpuSet 11
#define SYSCALL_CpuSetFast 12
#define SYSCALL_BiosChecksum 13
#define SYSCALL_BgAffineSet 14
#define SYSCALL_ObjAffineSet 15
#define SYSCALL_BitUnPack 16
#define SYSCALL_LZ77UnCompWram 17
#define SYSCALL_LZ77UnCompVram 18
#define SYSCALL_HuffUnComp 19
#define SYSCALL_LRUnCompWram 20
#define SYSCALL_LRUnCompVram 21
#define SYSCALL_Diff8bitUnFilterWram 22
#define SYSCALL_Diff8bitUnFilterVram 23
#define SYSCALL_Diff16bitUnFilter 24
#define SYSCALL_SoundBiasChange 25
#define SYSCALL_SoundDriverInit 26
#define SYSCALL_SoundDriverMode 27
#define SYSCALL_SoundDriverMain 28
#define SYSCALL_SoundDriverVSync 29
#define SYSCALL_SoundChannelClear 30
#define SYSCALL_MidiKey2Freq 31
#define SYSCALL_MusicPlayerOpen 32
#define SYSCALL_MusicPlayerStart 33
#define SYSCALL_MusicPlayerStop 34
#define SYSCALL_MusicPlayerContinue 35
#define SYSCALL_MusicPlayerFadeOut 36
#define SYSCALL_MultiBoot 37
#define SYSCALL_HardReset 38
#define SYSCALL_CustomHalt 39
#define SYSCALL_SoundDriverVSyncOff 40
#define SYSCALL_SoundDriverVSyncOn 41
#define SYSCALL_GetJumpList 42

struct WaveData {
    u16 type;
    u16 stat;
    u32 freq;
    u32 loop;
    u32 size;
    /* s8 data[size+1]; */
};

void CpuFastSet(void *src, void *dst, u16 size);
void CpuSet(void *src, void *dst, u32 size);
s32 DivarmDiv(s32 number, s32 denom);
s32 DivarmMod(s32 denom, s32 number);
void LZ77UncompVram(const void *src, void *dst);
void LZ77UncompWram(const void *src, void *dst);
u32 MidiKey2Freq(u32* wd, u8 mk, u8 fp);
int Multiboot(void *mbp); /* TODO: proper struct */
void SoundBias0(void);
void SoundBias200(void);
u16 Sqrt(u32 number);
void VBlankIntrWait(void);

#endif /* SYSCALLS_H */
