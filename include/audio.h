#ifndef AUDIO_H
#define AUDIO_H

#include "types.h"
#include "structs/audio.h"

void UpdateMusic(void);
void UpdatePsgSounds(void);
void UpdateTrack(struct TrackData* pTrack);

void FreeSoundChannel(struct SoundChannel* pChannel);

void AudioCommand_Fine(struct TrackData* pTrack, struct TrackVariables* pVariables);
void AudioCommand_FineAndQueue(struct TrackData* pTrack, struct TrackVariables* pVariables);
void AudioCommand_PatternEnd(struct TrackVariables* pVariables);
void AudioCommand_Repeat(struct TrackVariables* pVariables);
void AudioCommand_Priority(struct TrackVariables* pVariables);
void AudioCommand_KeyShift(struct TrackVariables* pVariables);
void AudioCommand_Voice(struct TrackData* pTrack, struct TrackVariables* pVariables);
void AudioCommand_Volume(struct TrackVariables* pVariables);
void AudioCommand_PanPot(struct TrackVariables* pVariables);
void AudioCommand_PitchBend(struct TrackVariables* pVariables);
void AudioCommand_BendRange(struct TrackVariables* pVariables);
void AudioCommand_LfoSpeed(struct TrackVariables* pVariables);
void AudioCommand_LfoDelay(struct TrackVariables* pVariables);
void AudioCommand_ModulationDepth(struct TrackVariables* pVariables);
void AudioCommand_ModulationType(struct TrackVariables* pVariables);
void AudioCommand_Tune(struct TrackVariables* pVariables);
void AudioCommand_ExtendCommand(struct TrackVariables* pVariables);
void AudioCommand_EndOfTie(struct TrackVariables* pVariables);
void Music_EmptyCommand(struct TrackVariables* pVariables);
void ClearRegistersForPsg(struct PSGSoundData* pSound, u8 channel);
void ClearRegistersForPsg_Unused(struct PSGSoundData* pSound, u8 channel);

#endif /* AUDIO_H */
