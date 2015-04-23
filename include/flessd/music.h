#ifndef _FLESSD_MUSIC_H_
#define _FLESSD_MUSIC_H_

#ifdef __cplusplus
extern "C" {
#endif

DLL_API FMUSIC_MODULE * F_API FMUSIC_LoadSong(const char *name);
DLL_API FMUSIC_MODULE * F_API FMUSIC_LoadSongEx(const char *name_or_data, int offset, int length, unsigned int mode, const int *samplelist, int samplelistnum);
DLL_API int             F_API FMUSIC_GetOpenState(FMUSIC_MODULE *mod);
DLL_API signed char     F_API FMUSIC_FreeSong(FMUSIC_MODULE *mod);
DLL_API signed char     F_API FMUSIC_PlaySong(FMUSIC_MODULE *mod);
DLL_API signed char     F_API FMUSIC_StopSong(FMUSIC_MODULE *mod);
DLL_API void            F_API FMUSIC_StopAllSongs();

DLL_API signed char     F_API FMUSIC_SetZxxCallback(FMUSIC_MODULE *mod, FMUSIC_CALLBACK callback);
DLL_API signed char     F_API FMUSIC_SetRowCallback(FMUSIC_MODULE *mod, FMUSIC_CALLBACK callback, int rowstep);
DLL_API signed char     F_API FMUSIC_SetOrderCallback(FMUSIC_MODULE *mod, FMUSIC_CALLBACK callback, int orderstep);
DLL_API signed char     F_API FMUSIC_SetInstCallback(FMUSIC_MODULE *mod, FMUSIC_CALLBACK callback, int instrument);

DLL_API signed char     F_API FMUSIC_SetSample(FMUSIC_MODULE *mod, int sampno, FSOUND_SAMPLE *sptr);
DLL_API signed char     F_API FMUSIC_SetUserData(FMUSIC_MODULE *mod, void *userdata);
DLL_API signed char     F_API FMUSIC_OptimizeChannels(FMUSIC_MODULE *mod, int maxchannels, int minvolume);

DLL_API signed char     F_API FMUSIC_SetReverb(signed char reverb);
DLL_API signed char     F_API FMUSIC_SetLooping(FMUSIC_MODULE *mod, signed char looping);
DLL_API signed char     F_API FMUSIC_SetOrder(FMUSIC_MODULE *mod, int order);
DLL_API signed char     F_API FMUSIC_SetPaused(FMUSIC_MODULE *mod, signed char pause);
DLL_API signed char     F_API FMUSIC_SetMasterVolume(FMUSIC_MODULE *mod, int volume);
DLL_API signed char     F_API FMUSIC_SetMasterSpeed(FMUSIC_MODULE *mode, float speed);
DLL_API signed char     F_API FMUSIC_SetPanSeperation(FMUSIC_MODULE *mod, float pansep);

DLL_API const char *    F_API FMUSIC_GetName(FMUSIC_MODULE *mod);
DLL_API int             F_API FMUSIC_GetType(FMUSIC_MODULE *mod);
DLL_API int             F_API FMUSIC_GetNumOrders(FMUSIC_MODULE *mod);
DLL_API int             F_API FMUSIC_GetNumPatterns(FMUSIC_MODULE *mod);
DLL_API int             F_API FMUSIC_GetNumInstruments(FMUSIC_MODULE *mod);
DLL_API int             F_API FMUSIC_GetNumSamples(FMUSIC_MODULE *mod);
DLL_API int             F_API FMUSIC_GetNumChannels(FMUSIC_MODULE *mod);
DLL_API FSOUND_SAMPLE * F_API FMUSIC_GetSample(FMUSIC_MODULE *mod, int sampno);
DLL_API int             F_API FMUSIC_GetPatternLength(FMUSIC_MODULE *mod, int orderno);

DLL_API signed char     F_API FMUSIC_IsFinished(FMUSIC_MODULE *mod);
DLL_API signed char     F_API FMUSIC_IsPlaying(FMUSIC_MODULE *mod);
DLL_API int             F_API FMUSIC_GetMasterVolume(FMUSIC_MODULE *mod);
DLL_API int             F_API FMUSIC_GetGlobalVolume(FMUSIC_MODULE *mod);
DLL_API int             F_API FMUSIC_GetOrder(FMUSIC_MODULE *mod);
DLL_API int             F_API FMUSIC_GetPattern(FMUSIC_MODULE *mod);
DLL_API int             F_API FMUSIC_GetSpeed(FMUSIC_MODULE *mod);
DLL_API int             F_API FMUSIC_GetBPM(FMUSIC_MODULE *mod);
DLL_API int             F_API FMUSIC_GetRow(FMUSIC_MODULE *mod);
DLL_API signed char     F_API FMUSIC_GetPaused(FMUSIC_MODULE *mod);
DLL_API int             F_API FMUSIC_GetTime(FMUSIC_MODULE *mod);
DLL_API int             F_API FMUSIC_GetRealChannel(FMUSIC_MODULE *mod, int modchannel);
DLL_API void *          F_API FMUSIC_GetUserData(FMUSIC_MODULE *mod);

#ifdef __cplusplus
}
#endif

#endif
