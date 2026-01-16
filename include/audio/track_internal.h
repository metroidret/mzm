#ifndef TRACK_INTERNAL_H
#define TRACK_INTERNAL_H

#include "structs/audio.h"

u8 InitTrack(struct TrackData* pTrack, const u32* pHeader);
void StopMusicOrSound(struct TrackData* pTrack);
void ResetTrack(struct TrackData* pTrack);
u32 TrackUpdateTempo(struct TrackData* pTrack);
void AudioCommand_Tempo(struct TrackData* pTrack, struct TrackVariables* pVariables);
void UpdateAudio(void);
void unk_4e10(struct TrackVariables* pVariables);
void TrackUpdatePitch(struct TrackVariables* pVariables);
void TrackUpdateVolume(struct TrackVariables* pVariables);
void TrackSendVariablesToChannel(struct SoundChannel* pChannel, struct TrackVariables* pVariables, s32 priority);
void AudioCommand_Goto(struct TrackVariables* pVariables);
void AudioCommand_PatternPlay(struct TrackVariables* pVariables);
void UploadSampleToWaveRAM(const u32* pSample);
void UploadSoundDataToSoundChannelRam(struct PSGSoundData* pSound);

#endif /* TRACK_INTERNAL_H */
