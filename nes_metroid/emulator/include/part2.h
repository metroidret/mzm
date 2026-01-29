#ifndef PART2_H
#define PART2_H

#include "types.h"

#include "structs/part2.h"

// part2
void EmulatorAudio_SetTimer1Reload(u16 timer1Reload);
u16 sub_03000024(u8 arg0);
u16 sub_03000050(u16 arg0);
void EmulatorAudio_UpdateApuAndOutput(void);
void EmulatorAudio_StartTimers(u16 timer0Reload);
void EmulatorAudio_DisableTimers(void);
void EmulatorAudio_SetNewSource(void* src);
void sub_030001F0(void* arg0, u16 arg1, u32 arg2, u8 arg3);
void sub_0300023C(void* arg0, void* arg1, u16 arg2, s32 arg3, void* arg4);
void EmulatorAudio_SetupOutput(void* outputBuffer0, void* outputBuffer1, void* outputBuffer2, u16 timer0Reload, u32 timer1Reload, void* func);
void EmulatorAudio_CallDisableTimers(void);
void sub_0300033C(u32 arg0);
void sub_03000348(u32 arg0);
void sub_03000354(u32 arg0, u32 arg1);
void sub_03000368(u32 arg0);
u8 EmulatorAudio_GetActiveChannels(EmulatorAudioApuRegisters apuRegister);
void EmulatorAudio_Stub(u8 value);
void EmulatorAudio_WriteToApu(EmulatorAudioApuRegisters apuRegister, u8 value);
void EmulatorAudio_Write8(u8* dst, u8 val);
u8 EmulatorAudio_Read8(u8* src);
void EmulatorAudio_Initialize(void);
void EmulatorAudio_Timer1Callback(void);
void EmulatorAudio_Disable(void);
void EmulatorAudio_Reset(void);
void EmulatorAudio_ClearChannels(void);

// part2_2
void sub_03000778(void);
void EmulatorAudio_Pulse1_SetLengthCounter(u32 lengthCounter);
void sub_03000790(void);
void sub_03000824(void);
void sub_03000848(u16 timer);
void sub_0300089C(u8 arg0);
void EmulatorAudio_Pulse1_WriteVolume(u8 value);
void EmulatorAudio_Pulse1_WriteSweep(u8 value);
void EmulatorAudio_Pulse1_WriteLo(u8 value);
void sub_03000948(void);

// part2_3
void EmulatorAudio_Pulse1_WriteHi(u8 value);
void EmulatorAudio_Pulse1_ClearVariables(void);
void sub_03000D20(void);
void EmulatorAudio_Pulse2_SetLengthCounter(u32 lengthCounter);
void sub_03000D38(void);
void sub_03000DEC(void);
void sub_03000E10(void);
void sub_03000E40(u16 timer);
void sub_03000E94(u8 arg0);
void EmulatorAudio_Pulse2_WriteVolume(u8 value);
void EmulatorAudio_Pulse2_WriteSweep(u8 value);
void EmulatorAudio_Pulse2_WriteLo(u8 value);
void EmulatorAudio_Pulse2_WriteHi(u8 value);
void EmulatorAudio_Pulse2_ClearVariables(void);

// part2_4
void sub_03001318(void);
void EmulatorAudio_Triangle_SetLengthCounter(u32 lengthCounter);
void sub_03001340(void);
void sub_030013C8(void);
void sub_030013F0(u16 arg0);
void EmulatorAudio_Triangle_WriteLinear(u8 value);
void EmulatorAudio_Triangle_WriteLo(u8 value);
void sub_030014E0(void);
void EmulatorAudio_Triangle_WriteHi(u8 value);

// part2_5
void sub_03001730(void);
void sub_0300173C(void);
void EmulatorAudio_Noise_SetLengthCounter(u32 lengthCounter);
void sub_03001794(void);
void sub_03001840(void);
void sub_03001864(u8 arg0);
void EmulatorAudio_Noise_WriteVolume(u8 value);
void EmulatorAudio_Noise_WriteLo(u8 value);
void EmulatorAudio_Noise_WriteHi(u8 value);
void EmulatorAudio_Noise_ClearVariables(void);
void EmulatorAudio_SoundChannel_Write(u8 value);
void EmulatorAudio_FrameCounter_Write(u8 value);
void sub_03001D24(u32 arg0);
void EmulatorAudio_ProcessApuAndMixBuffers(void* outputBuffer, u32 timer1Reload);
void EmulatorAudio_SetupEngine(void);

#endif /* PART2_H */
