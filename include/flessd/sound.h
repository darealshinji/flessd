#ifndef _FLESSD_SOUND_H_
#define _FLESSD_SOUND_H_

#ifdef __cplusplus
extern "C" {
#endif

DLL_API signed char     F_API FSOUND_SetOutput(int outputtype);
DLL_API signed char     F_API FSOUND_SetDriver(int driver);
DLL_API signed char     F_API FSOUND_SetMixer(int mixer);
DLL_API signed char     F_API FSOUND_SetBufferSize(int len_ms);
DLL_API signed char     F_API FSOUND_SetHWND(void *hwnd);
DLL_API signed char     F_API FSOUND_SetMinHardwareChannels(int min);
DLL_API signed char     F_API FSOUND_SetMaxHardwareChannels(int max);
DLL_API signed char     F_API FSOUND_SetMemorySystem(void *pool,
                                                     int poollen,
                                                     FSOUND_ALLOCCALLBACK   useralloc,
                                                     FSOUND_REALLOCCALLBACK userrealloc,
                                                     FSOUND_FREECALLBACK    userfree);

DLL_API signed char     F_API FSOUND_Init(int mixrate, int maxsoftwarechannels, unsigned int flags);
DLL_API void            F_API FSOUND_Close();

DLL_API void            F_API FSOUND_Update();

DLL_API void            F_API FSOUND_SetSpeakerMode(unsigned int speakermode);
DLL_API void            F_API FSOUND_SetSFXMasterVolume(int volume);
DLL_API void            F_API FSOUND_SetPanSeperation(float pansep);
DLL_API void            F_API FSOUND_File_SetCallbacks(FSOUND_OPENCALLBACK  useropen,
                                                       FSOUND_CLOSECALLBACK userclose,
                                                       FSOUND_READCALLBACK  userread,
                                                       FSOUND_SEEKCALLBACK  userseek,
                                                       FSOUND_TELLCALLBACK  usertell);

DLL_API int             F_API FSOUND_GetError();
DLL_API float           F_API FSOUND_GetVersion();
DLL_API int             F_API FSOUND_GetOutput();
DLL_API void *          F_API FSOUND_GetOutputHandle();
DLL_API int             F_API FSOUND_GetDriver();
DLL_API int             F_API FSOUND_GetMixer();
DLL_API int             F_API FSOUND_GetNumDrivers();
DLL_API const char *    F_API FSOUND_GetDriverName(int id);
DLL_API signed char     F_API FSOUND_GetDriverCaps(int id, unsigned int *caps);
DLL_API int             F_API FSOUND_GetOutputRate();
DLL_API int             F_API FSOUND_GetMaxChannels();
DLL_API int             F_API FSOUND_GetMaxSamples();
DLL_API int             F_API FSOUND_GetSFXMasterVolume();
DLL_API signed char     F_API FSOUND_GetNumHWChannels(int *num2d, int *num3d, int *total);
DLL_API int             F_API FSOUND_GetChannelsPlaying();
DLL_API float           F_API FSOUND_GetCPUUsage();
DLL_API void            F_API FSOUND_GetMemoryStats(unsigned int *currentalloced, unsigned int *maxalloced);

DLL_API FSOUND_SAMPLE * F_API FSOUND_Sample_Load(int index, const char *name_or_data, unsigned int mode, int offset, int length);
DLL_API FSOUND_SAMPLE * F_API FSOUND_Sample_Alloc(int index, int length, unsigned int mode, int deffreq, int defvol, int defpan, int defpri);
DLL_API void            F_API FSOUND_Sample_Free(FSOUND_SAMPLE *sptr);
DLL_API signed char     F_API FSOUND_Sample_Upload(FSOUND_SAMPLE *sptr, void *srcdata, unsigned int mode);
DLL_API signed char     F_API FSOUND_Sample_Lock(FSOUND_SAMPLE *sptr, int offset, int length, void **ptr1, void **ptr2, unsigned int *len1, unsigned int *len2);
DLL_API signed char     F_API FSOUND_Sample_Unlock(FSOUND_SAMPLE *sptr, void *ptr1, void *ptr2, unsigned int len1, unsigned int len2);

DLL_API signed char     F_API FSOUND_Sample_SetMode(FSOUND_SAMPLE *sptr, unsigned int mode);
DLL_API signed char     F_API FSOUND_Sample_SetLoopPoints(FSOUND_SAMPLE *sptr, int loopstart, int loopend);
DLL_API signed char     F_API FSOUND_Sample_SetDefaults(FSOUND_SAMPLE *sptr, int deffreq, int defvol, int defpan, int defpri);
DLL_API signed char     F_API FSOUND_Sample_SetDefaultsEx(FSOUND_SAMPLE *sptr, int deffreq, int defvol, int defpan, int defpri, int varfreq, int varvol, int varpan);
DLL_API signed char     F_API FSOUND_Sample_SetMinMaxDistance(FSOUND_SAMPLE *sptr, float min, float max);
DLL_API signed char     F_API FSOUND_Sample_SetMaxPlaybacks(FSOUND_SAMPLE *sptr, int max);

DLL_API FSOUND_SAMPLE * F_API FSOUND_Sample_Get(int sampno);
DLL_API const char *    F_API FSOUND_Sample_GetName(FSOUND_SAMPLE *sptr);
DLL_API unsigned int    F_API FSOUND_Sample_GetLength(FSOUND_SAMPLE *sptr);
DLL_API signed char     F_API FSOUND_Sample_GetLoopPoints(FSOUND_SAMPLE *sptr, int *loopstart, int *loopend);
DLL_API signed char     F_API FSOUND_Sample_GetDefaults(FSOUND_SAMPLE *sptr, int *deffreq, int *defvol, int *defpan, int *defpri);
DLL_API signed char     F_API FSOUND_Sample_GetDefaultsEx(FSOUND_SAMPLE *sptr, int *deffreq, int *defvol, int *defpan, int *defpri, int *varfreq, int *varvol, int *varpan);
DLL_API unsigned int    F_API FSOUND_Sample_GetMode(FSOUND_SAMPLE *sptr);
DLL_API signed char     F_API FSOUND_Sample_GetMinMaxDistance(FSOUND_SAMPLE *sptr, float *min, float *max);

DLL_API int             F_API FSOUND_PlaySound(int channel, FSOUND_SAMPLE *sptr);
DLL_API int             F_API FSOUND_PlaySoundEx(int channel, FSOUND_SAMPLE *sptr, FSOUND_DSPUNIT *dsp, signed char startpaused);
DLL_API signed char     F_API FSOUND_StopSound(int channel);

DLL_API signed char     F_API FSOUND_SetFrequency(int channel, int freq);
DLL_API signed char     F_API FSOUND_SetVolume(int channel, int vol);
DLL_API signed char     F_API FSOUND_SetVolumeAbsolute(int channel, int vol);
DLL_API signed char     F_API FSOUND_SetPan(int channel, int pan);
DLL_API signed char     F_API FSOUND_SetSurround(int channel, signed char surround);
DLL_API signed char     F_API FSOUND_SetMute(int channel, signed char mute);
DLL_API signed char     F_API FSOUND_SetPriority(int channel, int priority);
DLL_API signed char     F_API FSOUND_SetReserved(int channel, signed char reserved);
DLL_API signed char     F_API FSOUND_SetPaused(int channel, signed char paused);
DLL_API signed char     F_API FSOUND_SetLoopMode(int channel, unsigned int loopmode);
DLL_API signed char     F_API FSOUND_SetCurrentPosition(int channel, unsigned int offset);
DLL_API signed char     F_API FSOUND_3D_SetAttributes(int channel, const float *pos, const float *vel);
DLL_API signed char     F_API FSOUND_3D_SetMinMaxDistance(int channel, float min, float max);

DLL_API signed char     F_API FSOUND_IsPlaying(int channel);
DLL_API int             F_API FSOUND_GetFrequency(int channel);
DLL_API int             F_API FSOUND_GetVolume(int channel);
DLL_API int             F_API FSOUND_GetAmplitude(int channel);
DLL_API int             F_API FSOUND_GetPan(int channel);
DLL_API signed char     F_API FSOUND_GetSurround(int channel);
DLL_API signed char     F_API FSOUND_GetMute(int channel);
DLL_API int             F_API FSOUND_GetPriority(int channel);
DLL_API signed char     F_API FSOUND_GetReserved(int channel);
DLL_API signed char     F_API FSOUND_GetPaused(int channel);
DLL_API unsigned int    F_API FSOUND_GetLoopMode(int channel);
DLL_API unsigned int    F_API FSOUND_GetCurrentPosition(int channel);
DLL_API FSOUND_SAMPLE * F_API FSOUND_GetCurrentSample(int channel);
DLL_API signed char     F_API FSOUND_GetCurrentLevels(int channel, float *l, float *r);
DLL_API int             F_API FSOUND_GetNumSubChannels(int channel);
DLL_API int             F_API FSOUND_GetSubChannel(int channel, int subchannel);
DLL_API signed char     F_API FSOUND_3D_GetAttributes(int channel, float *pos, float *vel);
DLL_API signed char     F_API FSOUND_3D_GetMinMaxDistance(int channel, float *min, float *max);

DLL_API void            F_API FSOUND_3D_Listener_SetAttributes(const float *pos, const float *vel, float fx, float fy, float fz, float tx, float ty, float tz);
DLL_API void            F_API FSOUND_3D_Listener_GetAttributes(float *pos, float *vel, float *fx, float *fy, float *fz, float *tx, float *ty, float *tz);
DLL_API void            F_API FSOUND_3D_Listener_SetCurrent(int current, int numlisteners);
DLL_API void            F_API FSOUND_3D_SetDopplerFactor(float scale);
DLL_API void            F_API FSOUND_3D_SetDistanceFactor(float scale);
DLL_API void            F_API FSOUND_3D_SetRolloffFactor(float scale);

DLL_API int             F_API FSOUND_FX_Enable(int channel, unsigned int fxtype);
DLL_API signed char     F_API FSOUND_FX_Disable(int channel);

DLL_API signed char     F_API FSOUND_FX_SetChorus(int fxid, float WetDryMix, float Depth, float Feedback, float Frequency, int Waveform, float Delay, int Phase);
DLL_API signed char     F_API FSOUND_FX_SetCompressor(int fxid, float Gain, float Attack, float Release, float Threshold, float Ratio, float Predelay);
DLL_API signed char     F_API FSOUND_FX_SetDistortion(int fxid, float Gain, float Edge, float PostEQCenterFrequency, float PostEQBandwidth, float PreLowpassCutoff);
DLL_API signed char     F_API FSOUND_FX_SetEcho(int fxid, float WetDryMix, float Feedback, float LeftDelay, float RightDelay, int PanDelay);
DLL_API signed char     F_API FSOUND_FX_SetFlanger(int fxid, float WetDryMix, float Depth, float Feedback, float Frequency, int Waveform, float Delay, int Phase);
DLL_API signed char     F_API FSOUND_FX_SetGargle(int fxid, int RateHz, int WaveShape);
DLL_API signed char     F_API FSOUND_FX_SetI3DL2Reverb(int fxid, int Room, int RoomHF, float RoomRolloffFactor, float DecayTime, float DecayHFRatio, int Reflections, float ReflectionsDelay, int Reverb, float ReverbDelay, float Diffusion, float Density, float HFReference);
DLL_API signed char     F_API FSOUND_FX_SetParamEQ(int fxid, float Center, float Bandwidth, float Gain);
DLL_API signed char     F_API FSOUND_FX_SetWavesReverb(int fxid, float InGain, float ReverbMix, float ReverbTime, float HighFreqRTRatio);

DLL_API signed char        F_API FSOUND_Stream_SetBufferSize(int ms);

DLL_API FSOUND_STREAM *    F_API FSOUND_Stream_Open(const char *name_or_data, unsigned int mode, int offset, int length);
DLL_API FSOUND_STREAM *    F_API FSOUND_Stream_Create(FSOUND_STREAMCALLBACK callback, int length, unsigned int mode, int samplerate, void *userdata);
DLL_API signed char        F_API FSOUND_Stream_Close(FSOUND_STREAM *stream);

DLL_API int                F_API FSOUND_Stream_Play(int channel, FSOUND_STREAM *stream);
DLL_API int                F_API FSOUND_Stream_PlayEx(int channel, FSOUND_STREAM *stream, FSOUND_DSPUNIT *dsp, signed char startpaused);
DLL_API signed char        F_API FSOUND_Stream_Stop(FSOUND_STREAM *stream);

DLL_API signed char        F_API FSOUND_Stream_SetPosition(FSOUND_STREAM *stream, unsigned int position);
DLL_API unsigned int       F_API FSOUND_Stream_GetPosition(FSOUND_STREAM *stream);
DLL_API signed char        F_API FSOUND_Stream_SetTime(FSOUND_STREAM *stream, int ms);
DLL_API int                F_API FSOUND_Stream_GetTime(FSOUND_STREAM *stream);
DLL_API int                F_API FSOUND_Stream_GetLength(FSOUND_STREAM *stream);
DLL_API int                F_API FSOUND_Stream_GetLengthMs(FSOUND_STREAM *stream);

DLL_API signed char        F_API FSOUND_Stream_SetMode(FSOUND_STREAM *stream, unsigned int mode);
DLL_API unsigned int       F_API FSOUND_Stream_GetMode(FSOUND_STREAM *stream);
DLL_API signed char        F_API FSOUND_Stream_SetLoopPoints(FSOUND_STREAM *stream, unsigned int loopstartpcm, unsigned int loopendpcm);
DLL_API signed char        F_API FSOUND_Stream_SetLoopCount(FSOUND_STREAM *stream, int count);
DLL_API int                F_API FSOUND_Stream_GetOpenState(FSOUND_STREAM *stream);
DLL_API FSOUND_SAMPLE *    F_API FSOUND_Stream_GetSample(FSOUND_STREAM *stream);
DLL_API FSOUND_DSPUNIT *   F_API FSOUND_Stream_CreateDSP(FSOUND_STREAM *stream, FSOUND_DSPCALLBACK callback, int priority, void *userdata);

DLL_API signed char        F_API FSOUND_Stream_SetEndCallback(FSOUND_STREAM *stream, FSOUND_STREAMCALLBACK callback, void *userdata);
DLL_API signed char        F_API FSOUND_Stream_SetSyncCallback(FSOUND_STREAM *stream, FSOUND_STREAMCALLBACK callback, void *userdata);

DLL_API FSOUND_SYNCPOINT * F_API FSOUND_Stream_AddSyncPoint(FSOUND_STREAM *stream, unsigned int pcmoffset, const char *name);
DLL_API signed char        F_API FSOUND_Stream_DeleteSyncPoint(FSOUND_SYNCPOINT *point);
DLL_API int                F_API FSOUND_Stream_GetNumSyncPoints(FSOUND_STREAM *stream);
DLL_API FSOUND_SYNCPOINT * F_API FSOUND_Stream_GetSyncPoint(FSOUND_STREAM *stream, int index);
DLL_API char *             F_API FSOUND_Stream_GetSyncPointInfo(FSOUND_SYNCPOINT *point, unsigned int *pcmoffset);

DLL_API signed char        F_API FSOUND_Stream_SetSubStream(FSOUND_STREAM *stream, int index);
DLL_API int                F_API FSOUND_Stream_GetNumSubStreams(FSOUND_STREAM *stream);
DLL_API signed char        F_API FSOUND_Stream_SetSubStreamSentence(FSOUND_STREAM *stream, const int *sentencelist, int numitems);

DLL_API signed char        F_API FSOUND_Stream_GetNumTagFields(FSOUND_STREAM *stream, int *num);
DLL_API signed char        F_API FSOUND_Stream_GetTagField(FSOUND_STREAM *stream, int num, int *type, char **name, void **value, int *length);
DLL_API signed char        F_API FSOUND_Stream_FindTagField(FSOUND_STREAM *stream, int type, const char *name, void **value, int *length);

DLL_API signed char        F_API FSOUND_Stream_Net_SetProxy(const char *proxy);
DLL_API char *             F_API FSOUND_Stream_Net_GetLastServerStatus();
DLL_API signed char        F_API FSOUND_Stream_Net_SetBufferProperties(int buffersize, int prebuffer_percent, int rebuffer_percent);
DLL_API signed char        F_API FSOUND_Stream_Net_GetBufferProperties(int *buffersize, int *prebuffer_percent, int *rebuffer_percent);
DLL_API signed char        F_API FSOUND_Stream_Net_SetMetadataCallback(FSOUND_STREAM *stream, FSOUND_METADATACALLBACK callback, void *userdata);
DLL_API signed char        F_API FSOUND_Stream_Net_GetStatus(FSOUND_STREAM *stream, int *status, int *bufferpercentused, int *bitrate, unsigned int *flags);

DLL_API signed char     F_API FSOUND_CD_Play(char drive, int track);
DLL_API void            F_API FSOUND_CD_SetPlayMode(char drive, signed char mode);
DLL_API signed char     F_API FSOUND_CD_Stop(char drive);
DLL_API signed char     F_API FSOUND_CD_SetPaused(char drive, signed char paused);
DLL_API signed char     F_API FSOUND_CD_SetVolume(char drive, int volume);
DLL_API signed char     F_API FSOUND_CD_SetTrackTime(char drive, unsigned int ms);
DLL_API signed char     F_API FSOUND_CD_OpenTray(char drive, signed char open);

DLL_API signed char     F_API FSOUND_CD_GetPaused(char drive);
DLL_API int             F_API FSOUND_CD_GetTrack(char drive);
DLL_API int             F_API FSOUND_CD_GetNumTracks(char drive);
DLL_API int             F_API FSOUND_CD_GetVolume(char drive);
DLL_API int             F_API FSOUND_CD_GetTrackLength(char drive, int track);
DLL_API int             F_API FSOUND_CD_GetTrackTime(char drive);

DLL_API FSOUND_DSPUNIT *F_API FSOUND_DSP_Create(FSOUND_DSPCALLBACK callback, int priority, void *userdata);
DLL_API void            F_API FSOUND_DSP_Free(FSOUND_DSPUNIT *unit);
DLL_API void            F_API FSOUND_DSP_SetPriority(FSOUND_DSPUNIT *unit, int priority);
DLL_API int             F_API FSOUND_DSP_GetPriority(FSOUND_DSPUNIT *unit);
DLL_API void            F_API FSOUND_DSP_SetActive(FSOUND_DSPUNIT *unit, signed char active);
DLL_API signed char     F_API FSOUND_DSP_GetActive(FSOUND_DSPUNIT *unit);

DLL_API FSOUND_DSPUNIT *F_API FSOUND_DSP_GetClearUnit();
DLL_API FSOUND_DSPUNIT *F_API FSOUND_DSP_GetSFXUnit();
DLL_API FSOUND_DSPUNIT *F_API FSOUND_DSP_GetMusicUnit();
DLL_API FSOUND_DSPUNIT *F_API FSOUND_DSP_GetFFTUnit();
DLL_API FSOUND_DSPUNIT *F_API FSOUND_DSP_GetClipAndCopyUnit();

DLL_API signed char     F_API FSOUND_DSP_MixBuffers(void *destbuffer, void *srcbuffer, int len, int freq, int vol, int pan, unsigned int mode);
DLL_API void            F_API FSOUND_DSP_ClearMixBuffer();
DLL_API int             F_API FSOUND_DSP_GetBufferLength();
DLL_API int             F_API FSOUND_DSP_GetBufferLengthTotal();
DLL_API float *         F_API FSOUND_DSP_GetSpectrum();

DLL_API signed char     F_API FSOUND_Reverb_SetProperties(const FSOUND_REVERB_PROPERTIES *prop);
DLL_API signed char     F_API FSOUND_Reverb_GetProperties(FSOUND_REVERB_PROPERTIES *prop);
DLL_API signed char     F_API FSOUND_Reverb_SetChannelProperties(int channel, const FSOUND_REVERB_CHANNELPROPERTIES *prop);
DLL_API signed char     F_API FSOUND_Reverb_GetChannelProperties(int channel, FSOUND_REVERB_CHANNELPROPERTIES *prop);

DLL_API signed char     F_API FSOUND_Record_SetDriver(int outputtype);
DLL_API int             F_API FSOUND_Record_GetNumDrivers();
DLL_API const char *    F_API FSOUND_Record_GetDriverName(int id);
DLL_API int             F_API FSOUND_Record_GetDriver();

DLL_API signed char     F_API FSOUND_Record_StartSample(FSOUND_SAMPLE *sptr, signed char loop);
DLL_API signed char     F_API FSOUND_Record_Stop();
DLL_API int             F_API FSOUND_Record_GetPosition();

#ifdef __cplusplus
}
#endif

#endif
