/*
 * $Id: fsound.c 27 2004-07-27 08:06:17Z sam $
 *
 *    (c) 2004 Sam Hocevar <sam@zoy.org>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the Do What The Fuck You Want To
 *  Public License as published by Banlu Kemiyatorn. See
 *  http://sam.zoy.org/projects/COPYING.WTFPL for more details.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "flessd/types.h"
#include "flessd/music.h"
#include "flessd/sound.h"

#include "defs.h"

/* CD variables */
typedef struct {
    SDL_CD *device;
    int playmode;
    int paused;
    int playing;
    int track;
} cd;
static cd *cd_bank = NULL;
static int cd_count = 0;

/* Sample variables */
static struct FSOUND_SAMPLE **sample_bank = NULL;
static int sample_count = 0;

DLL_API signed char F_API FSOUND_SetOutput(int outputtype)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_SetDriver(int driver)
{
    if(driver < 0)
        return TRUE; /* FIXME: disable everything */

    if(driver == 0)
        driver = 1;

    if(driver < 1 || driver > 1)
        return FALSE;

    return TRUE;
}

DLL_API signed char F_API FSOUND_SetMixer(int mixer)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_SetBufferSize(int len_ms)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_SetHWND(void *hwnd)
{
    /* FIXME: we ignore the HWND value */
    return TRUE;
}

DLL_API signed char F_API FSOUND_SetMinHardwareChannels(int min)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_SetMaxHardwareChannels(int max)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_SetMemorySystem(void *pool, int poollen, FSOUND_ALLOCCALLBACK useralloc, FSOUND_REALLOCCALLBACK userrealloc, FSOUND_FREECALLBACK userfree)
{
    STUB();
    return TRUE;
}


DLL_API signed char F_API FSOUND_Init(int mixrate, int maxsoftwarechannels, unsigned int flags)
{
    int i;

    /* Initialise the sample bank */
    sample_bank = NULL;
    sample_count = 0;

    /* Initialise SDL_mixer */
    if(SDL_InitSubSystem(SDL_INIT_AUDIO | SDL_INIT_NOPARACHUTE) < 0)
        return FALSE;

    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) < 0)
        return FALSE;

    if(Sound_Init() < 0)
        return FALSE;

    /* Initialise CD drive */
    if(SDL_InitSubSystem(SDL_INIT_CDROM) == 0)
    {
        cd_count = SDL_CDNumDrives();

        if(cd_count)
            cd_bank = malloc(sizeof(cd) * cd_count);

        for(i = 0; i < cd_count; i++)
        {
            cd_bank[i].device = SDL_CDOpen(i);
            cd_bank[i].playmode = 0;
            cd_bank[i].paused = 0;
            cd_bank[i].playing = 0;
            cd_bank[i].track = -1;
        }
    }

    return TRUE;
}

DLL_API void F_API FSOUND_Close()
{
    /* FIXME: do something with our allocated data */

    /* FIXME: do something with our CD drives */

    Sound_Quit();
    Mix_CloseAudio();
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
}


DLL_API void F_API FSOUND_Update()
{
    STUB();
    return;
}


DLL_API void F_API FSOUND_SetSpeakerMode(unsigned int speakermode)
{
    STUB();
    return;
}

DLL_API void F_API FSOUND_SetSFXMasterVolume(int volume)
{
    STUB();
    return;
}

DLL_API void F_API FSOUND_SetPanSeperation(float pansep)
{
    STUB();
    return;
}

DLL_API void F_API FSOUND_File_SetCallbacks(FSOUND_OPENCALLBACK useropen, FSOUND_CLOSECALLBACK userclose, FSOUND_READCALLBACK userread, FSOUND_SEEKCALLBACK userseek, FSOUND_TELLCALLBACK usertell)
{
    STUB();
    return;
}


DLL_API int F_API FSOUND_GetError()
{
    STUB();
    return 0;
}

DLL_API float F_API FSOUND_GetVersion()
{
    return FMOD_VERSION;
}

DLL_API int F_API FSOUND_GetOutput()
{
    STUB();
    return 0;
}

DLL_API void * F_API FSOUND_GetOutputHandle()
{
    STUB();
    return NULL;
}

DLL_API int F_API FSOUND_GetDriver()
{
    STUB();
    return 0;
}

DLL_API int F_API FSOUND_GetMixer()
{
    STUB();
    return 0;
}

DLL_API int F_API FSOUND_GetNumDrivers()
{
    /* Tell the application we have one driver */
    return 1;
}

DLL_API const char * F_API FSOUND_GetDriverName(int id)
{
    if(id < 1 || id > 1)
        return "(unknown)";

    return "FLESSD";
}

DLL_API signed char F_API FSOUND_GetDriverCaps(int id, unsigned int *caps)
{
    STUB();
    return TRUE;
}

DLL_API int F_API FSOUND_GetOutputRate()
{
    STUB();
    return 0;
}

DLL_API int F_API FSOUND_GetMaxChannels()
{
    STUB();
    return 0;
}

DLL_API int F_API FSOUND_GetMaxSamples()
{
    STUB();
    return 0;
}

DLL_API int F_API FSOUND_GetSFXMasterVolume()
{
    STUB();
    return 0;
}

DLL_API signed char F_API FSOUND_GetNumHWChannels(int *num2d, int *num3d, int *total)
{
    STUB();
    return TRUE;
}

DLL_API int F_API FSOUND_GetChannelsPlaying()
{
    STUB();
    return 0;
}

DLL_API float F_API FSOUND_GetCPUUsage()
{
    STUB();
    return 0.0;
}

DLL_API void F_API FSOUND_GetMemoryStats(unsigned int *currentalloced, unsigned int *maxalloced)
{
    STUB();
    return;
}


DLL_API FSOUND_SAMPLE *F_API
FSOUND_Sample_Load(int index, const char *name_or_data, unsigned int mode,
                   int offset, int length)
{
    int pos = 0, grow = 1;
    FSOUND_SAMPLE *fsound_sample;
    Mix_Chunk *wave = NULL;

    /* First, try to open the sample */
    if(!(mode & FSOUND_LOADMEMORY))
    {
        wave = Mix_LoadWAV(name_or_data);
    }

    /* SDL_mixer could not directly load sample; use SDL_sound instead */
    if(!wave)
    {
        SDL_RWops *rw;

        if(mode & FSOUND_LOADMEMORY)
            rw = SDL_RWFromMem((void *)name_or_data, length);
        else
            rw = SDL_RWFromFile(name_or_data, "rb");

        if(rw)
        {
            Sound_Sample *sample;
            Sound_AudioInfo audioinfo;

            audioinfo.format = MIX_DEFAULT_FORMAT;
            audioinfo.channels = MIX_DEFAULT_CHANNELS;
            audioinfo.rate = MIX_DEFAULT_FREQUENCY;

            sample = Sound_NewSample(rw, NULL, &audioinfo, 0x10000);

            if(sample)
            {
                Sound_DecodeAll(sample);

                wave = malloc(sizeof(Mix_Chunk));
                wave->allocated = 1;
                wave->abuf = sample->buffer;
                wave->alen = sample->buffer_size;
                wave->volume = MIX_MAX_VOLUME;

                SDL_FreeRW(rw);
            }
        }
    }

    if(!wave)
        return NULL;

    /* Now insert the sample in our bank */
    if(index == FSOUND_FREE)
    {
        index = sample_count ? (sample_bank[sample_count - 1]->index + 1) : 0;
        pos = sample_count;
        grow = 1;
    }
    else if(index == FSOUND_UNMANAGED)
    {
        pos = -1;
        grow = 0;
    }
    else
    {
        int min = 0, max = sample_count - 1, mid;

        /* Deal with border cases */
        if(index <= sample_bank[min]->index)
        {
            pos = min;
            grow = (index != sample_bank[min]->index);
        }
        else if (index < sample_bank[max]->index)
        {
            pos = max + 1;
            grow = 1;
        }

        /* Look into our list */
        for(min = 0, max = sample_count - 1; min != max; )
        {
            mid = (min + max) / 2;
            if(sample_bank[mid]->index == index)
            {
                pos = mid;
                grow = 0;
                break;
            }
            else if(mid == min)
            {
                pos = max;
                grow = (index != sample_bank[max]->index);
                break;
            }
            else if(index < sample_bank[mid]->index)
                max = mid;
            else
                min = mid;
        }
    }

    /* Grow sample list if necessary */
    if(grow)
    {
        if(sample_count)
            sample_bank = realloc(sample_bank,
                                  sizeof(void *) * (sample_count + 1));
        else
            sample_bank = malloc(sizeof(void *) * (sample_count + 1));
        memmove(sample_bank + pos + 1, sample_bank + pos,
                sizeof(void *) * (sample_count - pos));
        sample_count++;
        sample_bank[pos] = malloc(sizeof(FSOUND_SAMPLE));
    }

    if(pos == -1)
        fsound_sample = malloc(sizeof(FSOUND_SAMPLE));
    else
        /* FIXME: remove previous sample if necessary */
        fsound_sample = sample_bank[pos];

    fsound_sample->index = index;
    fsound_sample->wave = wave;
    fsound_sample->mode = mode;

    return fsound_sample;
}

DLL_API FSOUND_SAMPLE * F_API FSOUND_Sample_Alloc(int index, int length, unsigned int mode, int deffreq, int defvol, int defpan, int defpri)
{
    STUB();
    return NULL;
}

DLL_API void F_API FSOUND_Sample_Free(FSOUND_SAMPLE *sptr)
{
    STUB();
    return;
}

DLL_API signed char F_API FSOUND_Sample_Upload(FSOUND_SAMPLE *sptr, void *srcdata, unsigned int mode)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Sample_Lock(FSOUND_SAMPLE *sptr, int offset, int length, void **ptr1, void **ptr2, unsigned int *len1, unsigned int *len2)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Sample_Unlock(FSOUND_SAMPLE *sptr, void *ptr1, void *ptr2, unsigned int len1, unsigned int len2)
{
    STUB();
    return TRUE;
}


DLL_API signed char F_API FSOUND_Sample_SetMode(FSOUND_SAMPLE *sptr, unsigned int mode)
{
    static unsigned int const allowed = FSOUND_LOOP_OFF
                                         | FSOUND_LOOP_NORMAL
                                         | FSOUND_LOOP_BIDI
                                         | FSOUND_2D;
    if(!sptr)
        return FALSE;

    if(mode & ~allowed)
        return FALSE;

    /* FIXME: better flag integrity check */
    sptr->mode = (sptr->mode & ~allowed) | mode;

    return TRUE;
}

DLL_API signed char F_API FSOUND_Sample_SetLoopPoints(FSOUND_SAMPLE *sptr, int loopstart, int loopend)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Sample_SetDefaults(FSOUND_SAMPLE *sptr, int deffreq, int defvol, int defpan, int defpri)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Sample_SetDefaultsEx(FSOUND_SAMPLE *sptr, int deffreq, int defvol, int defpan, int defpri, int varfreq, int varvol, int varpan)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Sample_SetMinMaxDistance(FSOUND_SAMPLE *sptr, float min, float max)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Sample_SetMaxPlaybacks(FSOUND_SAMPLE *sptr, int max)
{
    STUB();
    return TRUE;
}


DLL_API FSOUND_SAMPLE * F_API FSOUND_Sample_Get(int sampno)
{
    STUB();
    return NULL;
}

DLL_API const char * F_API FSOUND_Sample_GetName(FSOUND_SAMPLE *sptr)
{
    STUB();
    return NULL;
}

DLL_API unsigned int F_API FSOUND_Sample_GetLength(FSOUND_SAMPLE *sptr)
{
    STUB();
    return 0;
}

DLL_API signed char F_API FSOUND_Sample_GetLoopPoints(FSOUND_SAMPLE *sptr, int *loopstart, int *loopend)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Sample_GetDefaults(FSOUND_SAMPLE *sptr, int *deffreq, int *defvol, int *defpan, int *defpri)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Sample_GetDefaultsEx(FSOUND_SAMPLE *sptr, int *deffreq, int *defvol, int *defpan, int *defpri, int *varfreq, int *varvol, int *varpan)
{
    STUB();
    return TRUE;
}

DLL_API unsigned int F_API FSOUND_Sample_GetMode(FSOUND_SAMPLE *sptr)
{
    if(!sptr)
        return 0;

    return sptr->mode;
}

DLL_API signed char F_API FSOUND_Sample_GetMinMaxDistance(FSOUND_SAMPLE *sptr, float *min, float *max)
{
    STUB();
    return TRUE;
}


DLL_API int F_API FSOUND_PlaySound(int channel, FSOUND_SAMPLE *sptr)
{
    if(!sptr)
        return -1;

    return Mix_PlayChannel(-1, sptr->wave, 0);
}

DLL_API int F_API FSOUND_PlaySoundEx(int channel, FSOUND_SAMPLE *sptr, FSOUND_DSPUNIT *dsp, signed char startpaused)
{
    STUB();
    return 0;
}

DLL_API signed char F_API FSOUND_StopSound(int channel)
{
    Mix_HaltChannel(channel);

    return TRUE;
}


DLL_API signed char F_API FSOUND_SetFrequency(int channel, int freq)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_SetVolume(int channel, int vol)
{
    /* FIXME: handle FSOUND_SetSFXMasterVolume */
    Mix_Volume(channel, vol * MIX_MAX_VOLUME / 255);

    return TRUE;
}

DLL_API signed char F_API FSOUND_SetVolumeAbsolute(int channel, int vol)
{
    Mix_Volume(channel, vol * MIX_MAX_VOLUME / 255);

    return TRUE;
}

DLL_API signed char F_API FSOUND_SetPan(int channel, int pan)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_SetSurround(int channel, signed char surround)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_SetMute(int channel, signed char mute)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_SetPriority(int channel, int priority)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_SetReserved(int channel, signed char reserved)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_SetPaused(int channel, signed char paused)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_SetLoopMode(int channel, unsigned int loopmode)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_SetCurrentPosition(int channel, unsigned int offset)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_3D_SetAttributes(int channel, const float *pos, const float *vel)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_3D_SetMinMaxDistance(int channel, float min, float max)
{
    STUB();
    return TRUE;
}


DLL_API signed char F_API FSOUND_IsPlaying(int channel)
{
    /* FIXME: do something real here */
    //STUB();
    return FALSE;
}

DLL_API int F_API FSOUND_GetFrequency(int channel)
{
    STUB();
    return 0;
}

DLL_API int F_API FSOUND_GetVolume(int channel)
{
    STUB();
    return 0;
}

DLL_API int F_API FSOUND_GetAmplitude(int channel)
{
    STUB();
    return 0;
}

DLL_API int F_API FSOUND_GetPan(int channel)
{
    STUB();
    return 0;
}

DLL_API signed char F_API FSOUND_GetSurround(int channel)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_GetMute(int channel)
{
    STUB();
    return TRUE;
}

DLL_API int F_API FSOUND_GetPriority(int channel)
{
    STUB();
    return 0;
}

DLL_API signed char F_API FSOUND_GetReserved(int channel)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_GetPaused(int channel)
{
    STUB();
    return TRUE;
}

DLL_API unsigned int F_API FSOUND_GetLoopMode(int channel)
{
    STUB();
    return 0;
}

DLL_API unsigned int F_API FSOUND_GetCurrentPosition(int channel)
{
    STUB();
    return 0;
}

DLL_API FSOUND_SAMPLE * F_API FSOUND_GetCurrentSample(int channel)
{
    STUB();
    return NULL;
}

DLL_API signed char F_API FSOUND_GetCurrentLevels(int channel, float *l, float *r)
{
    STUB();
    return TRUE;
}

DLL_API int F_API FSOUND_GetNumSubChannels(int channel)
{
    STUB();
    return 0;
}

DLL_API int F_API FSOUND_GetSubChannel(int channel, int subchannel)
{
    STUB();
    return 0;
}

DLL_API signed char F_API FSOUND_3D_GetAttributes(int channel, float *pos, float *vel)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_3D_GetMinMaxDistance(int channel, float *min, float *max)
{
    STUB();
    return TRUE;
}


DLL_API void F_API FSOUND_3D_Listener_SetAttributes(const float *pos, const float *vel, float fx, float fy, float fz, float tx, float ty, float tz)
{
    STUB();
    return;
}

DLL_API void F_API FSOUND_3D_Listener_GetAttributes(float *pos, float *vel, float *fx, float *fy, float *fz, float *tx, float *ty, float *tz)
{
    STUB();
    return;
}

DLL_API void F_API FSOUND_3D_Listener_SetCurrent(int current, int numlisteners)
{
    STUB();
    return;
}

DLL_API void F_API FSOUND_3D_SetDopplerFactor(float scale)
{
    STUB();
    return;
}

DLL_API void F_API FSOUND_3D_SetDistanceFactor(float scale)
{
    STUB();
    return;
}

DLL_API void F_API FSOUND_3D_SetRolloffFactor(float scale)
{
    STUB();
    return;
}


DLL_API int F_API FSOUND_FX_Enable(int channel, unsigned int fxtype)
{
    STUB();
    return 0;
}

DLL_API signed char F_API FSOUND_FX_Disable(int channel)
{
    STUB();
    return TRUE;
}


DLL_API signed char F_API FSOUND_FX_SetChorus(int fxid, float WetDryMix, float Depth, float Feedback, float Frequency, int Waveform, float Delay, int Phase)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_FX_SetCompressor(int fxid, float Gain, float Attack, float Release, float Threshold, float Ratio, float Predelay)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_FX_SetDistortion(int fxid, float Gain, float Edge, float PostEQCenterFrequency, float PostEQBandwidth, float PreLowpassCutoff)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_FX_SetEcho(int fxid, float WetDryMix, float Feedback, float LeftDelay, float RightDelay, int PanDelay)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_FX_SetFlanger(int fxid, float WetDryMix, float Depth, float Feedback, float Frequency, int Waveform, float Delay, int Phase)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_FX_SetGargle(int fxid, int RateHz, int WaveShape)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_FX_SetI3DL2Reverb(int fxid, int Room, int RoomHF, float RoomRolloffFactor, float DecayTime, float DecayHFRatio, int Reflections, float ReflectionsDelay, int Reverb, float ReverbDelay, float Diffusion, float Density, float HFReference)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_FX_SetParamEQ(int fxid, float Center, float Bandwidth, float Gain)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_FX_SetWavesReverb(int fxid, float InGain, float ReverbMix, float ReverbTime, float HighFreqRTRatio)
{
    STUB();
    return TRUE;
}


DLL_API signed char F_API FSOUND_Stream_SetBufferSize(int ms)
{
    STUB();
    return TRUE;
}

DLL_API FSOUND_STREAM * F_API FSOUND_Stream_Open(const char *name_or_data, unsigned int mode, int offset, int length)
{
    STUB();
    return NULL;
}

DLL_API FSOUND_STREAM * F_API FSOUND_Stream_Create(FSOUND_STREAMCALLBACK callback, int length, unsigned int mode, int samplerate, void *userdata)
{
    STUB();
    return NULL;
}

DLL_API signed char F_API FSOUND_Stream_Close(FSOUND_STREAM *stream)
{
    STUB();
    return TRUE;
}

DLL_API int F_API FSOUND_Stream_Play(int channel, FSOUND_STREAM *stream)
{
    STUB();
    return 0;
}

DLL_API int F_API FSOUND_Stream_PlayEx(int channel, FSOUND_STREAM *stream, FSOUND_DSPUNIT *dsp, signed char startpaused)
{
    STUB();
    return 0;
}

DLL_API signed char F_API FSOUND_Stream_Stop(FSOUND_STREAM *stream)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Stream_SetPosition(FSOUND_STREAM *stream, unsigned int position)
{
    STUB();
    return TRUE;
}

DLL_API unsigned int F_API FSOUND_Stream_GetPosition(FSOUND_STREAM *stream)
{
    STUB();
    return 0;
}

DLL_API signed char F_API FSOUND_Stream_SetTime(FSOUND_STREAM *stream, int ms)
{
    STUB();
    return TRUE;
}

DLL_API int F_API FSOUND_Stream_GetTime(FSOUND_STREAM *stream)
{
    STUB();
    return 0;
}

DLL_API int F_API FSOUND_Stream_GetLength(FSOUND_STREAM *stream)
{
    STUB();
    return 0;
}

DLL_API int F_API FSOUND_Stream_GetLengthMs(FSOUND_STREAM *stream)
{
    STUB();
    return 0;
}

DLL_API signed char F_API FSOUND_Stream_SetMode(FSOUND_STREAM *stream, unsigned int mode)
{
    STUB();
    return TRUE;
}

DLL_API unsigned int F_API FSOUND_Stream_GetMode(FSOUND_STREAM *stream)
{
    STUB();
    return 0;
}

DLL_API signed char F_API FSOUND_Stream_SetLoopPoints(FSOUND_STREAM *stream, unsigned int loopstartpcm, unsigned int loopendpcm)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Stream_SetLoopCount(FSOUND_STREAM *stream, int count)
{
    STUB();
    return TRUE;
}

DLL_API int F_API FSOUND_Stream_GetOpenState(FSOUND_STREAM *stream)
{
    STUB();
    return 0;
}

DLL_API FSOUND_SAMPLE * F_API FSOUND_Stream_GetSample(FSOUND_STREAM *stream)
{
    STUB();
    return NULL;
}

DLL_API FSOUND_DSPUNIT * F_API FSOUND_Stream_CreateDSP(FSOUND_STREAM *stream, FSOUND_DSPCALLBACK callback, int priority, void *userdata)
{
    STUB();
    return NULL;
}

DLL_API signed char F_API FSOUND_Stream_SetEndCallback(FSOUND_STREAM *stream, FSOUND_STREAMCALLBACK callback, void *userdata)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Stream_SetSyncCallback(FSOUND_STREAM *stream, FSOUND_STREAMCALLBACK callback, void *userdata)
{
    STUB();
    return TRUE;
}


DLL_API FSOUND_SYNCPOINT * F_API FSOUND_Stream_AddSyncPoint(FSOUND_STREAM *stream, unsigned int pcmoffset, const char *name)
{
    STUB();
    return NULL;
}

DLL_API signed char F_API FSOUND_Stream_DeleteSyncPoint(FSOUND_SYNCPOINT *point)
{
    STUB();
    return TRUE;
}

DLL_API int F_API FSOUND_Stream_GetNumSyncPoints(FSOUND_STREAM *stream)
{
    STUB();
    return 0;
}

DLL_API FSOUND_SYNCPOINT * F_API FSOUND_Stream_GetSyncPoint(FSOUND_STREAM *stream, int index)
{
    STUB();
    return NULL;
}

DLL_API char * F_API FSOUND_Stream_GetSyncPointInfo(FSOUND_SYNCPOINT *point, unsigned int *pcmoffset)
{
    STUB();
    return NULL;
}


DLL_API signed char F_API FSOUND_Stream_SetSubStream(FSOUND_STREAM *stream, int index)
{
    STUB();
    return TRUE;
}

DLL_API int F_API FSOUND_Stream_GetNumSubStreams(FSOUND_STREAM *stream)
{
    STUB();
    return 0;
}

DLL_API signed char F_API FSOUND_Stream_SetSubStreamSentence(FSOUND_STREAM *stream, const int *sentencelist, int numitems)
{
    STUB();
    return TRUE;
}


DLL_API signed char F_API FSOUND_Stream_GetNumTagFields(FSOUND_STREAM *stream, int *num)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Stream_GetTagField(FSOUND_STREAM *stream, int num, int *type, char **name, void **value, int *length)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Stream_FindTagField(FSOUND_STREAM *stream, int type, const char *name, void **value, int *length)
{
    STUB();
    return TRUE;
}


DLL_API signed char F_API FSOUND_Stream_Net_SetProxy(const char *proxy)
{
    STUB();
    return TRUE;
}

DLL_API char * F_API FSOUND_Stream_Net_GetLastServerStatus()
{
    STUB();
    return NULL;
}

DLL_API signed char F_API FSOUND_Stream_Net_SetBufferProperties(int buffersize, int prebuffer_percent, int rebuffer_percent)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Stream_Net_GetBufferProperties(int *buffersize, int *prebuffer_percent, int *rebuffer_percent)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Stream_Net_SetMetadataCallback(FSOUND_STREAM *stream, FSOUND_METADATACALLBACK callback, void *userdata)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Stream_Net_GetStatus(FSOUND_STREAM *stream, int *status, int *bufferpercentused, int *bitrate, unsigned int *flags)
{
    STUB();
    return TRUE;
}


DLL_API signed char F_API FSOUND_CD_Play(char drive, int track)
{
    if((int)drive >= cd_count || cd_bank[(int)drive].device == NULL)
        return FALSE;

    SDL_CDPlayTracks(cd_bank[(int)drive].device, track - 1, 0, track, 0);

    return TRUE;
}

DLL_API void F_API FSOUND_CD_SetPlayMode(char drive, signed char mode)
{
    if((int)drive >= cd_count || cd_bank[(int)drive].device == NULL)
        return;

    cd_bank[(int)drive].playmode = mode;

    return;
}

DLL_API signed char F_API FSOUND_CD_Stop(char drive)
{
    if((int)drive >= cd_count || cd_bank[(int)drive].device == NULL)
        return FALSE;

    SDL_CDStop(cd_bank[(int)drive].device);

    return TRUE;
}

DLL_API signed char F_API FSOUND_CD_SetPaused(char drive, signed char paused)
{
    if((int)drive >= cd_count || cd_bank[(int)drive].device == NULL)
        return FALSE;

    if(paused)
        SDL_CDPause(cd_bank[(int)drive].device);
    else
        SDL_CDResume(cd_bank[(int)drive].device);

    return TRUE;
}

DLL_API signed char F_API FSOUND_CD_SetVolume(char drive, int volume)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_CD_SetTrackTime(char drive, unsigned int ms)
{
    if((int)drive >= cd_count || cd_bank[(int)drive].device == NULL)
        return FALSE;

    if(!CD_INDRIVE(SDL_CDStatus(cd_bank[(int)drive].device)))
        return FALSE;

    if(SDL_CDPlayTracks(cd_bank[(int)drive].device,
                        cd_bank[(int)drive].device->cur_track, 0,
                        cd_bank[(int)drive].device->cur_track,
                        ms * CD_FPS / 1000))
        return FALSE;

    return TRUE;
}

DLL_API signed char F_API FSOUND_CD_OpenTray(char drive, signed char open)
{
    if((int)drive >= cd_count || cd_bank[(int)drive].device == NULL)
        return FALSE;

    if(!CD_INDRIVE(SDL_CDStatus(cd_bank[(int)drive].device)))
        return FALSE;

    if(SDL_CDEject(cd_bank[(int)drive].device) < 0)
        return FALSE;

    return TRUE;
}

DLL_API signed char F_API FSOUND_CD_GetPaused(char drive)
{
    if((int)drive >= cd_count || cd_bank[(int)drive].device == NULL)
        return FALSE;

    if(!CD_INDRIVE(SDL_CDStatus(cd_bank[(int)drive].device)))
        return FALSE;

    return (cd_bank[(int)drive].device->status == CD_PAUSED) ? TRUE : FALSE;
}

DLL_API int F_API FSOUND_CD_GetTrack(char drive)
{
    if((int)drive >= cd_count || cd_bank[(int)drive].device == NULL)
        return -1;

    if(!CD_INDRIVE(SDL_CDStatus(cd_bank[(int)drive].device)))
        return -1;

    return cd_bank[(int)drive].device->cur_track;
}

DLL_API int F_API FSOUND_CD_GetNumTracks(char drive)
{
    if((int)drive >= cd_count || cd_bank[(int)drive].device == NULL)
        return -1;

    if(!CD_INDRIVE(SDL_CDStatus(cd_bank[(int)drive].device)))
        return -1;

    return cd_bank[(int)drive].device->numtracks;
}

DLL_API int F_API FSOUND_CD_GetVolume(char drive)
{
    STUB();
    return 0;
}

DLL_API int F_API FSOUND_CD_GetTrackLength(char drive, int track)
{
    if((int)drive >= cd_count || cd_bank[(int)drive].device == NULL)
        return -1;

    if(!CD_INDRIVE(SDL_CDStatus(cd_bank[(int)drive].device)))
        return -1;

    if(track < 1 || track > cd_bank[(int)drive].device->numtracks)
        return -1;

    return cd_bank[(int)drive].device->track[track - 1].length * 1000 / CD_FPS;
}

DLL_API int F_API FSOUND_CD_GetTrackTime(char drive)
{
    STUB();
    return 0;
}


DLL_API FSOUND_DSPUNIT * F_API FSOUND_DSP_Create(FSOUND_DSPCALLBACK callback, int priority, void *userdata)
{
    STUB();
    return NULL;
}

DLL_API void F_API FSOUND_DSP_Free(FSOUND_DSPUNIT *unit)
{
    STUB();
    return;
}

DLL_API void F_API FSOUND_DSP_SetPriority(FSOUND_DSPUNIT *unit, int priority)
{
    STUB();
    return;
}

DLL_API int F_API FSOUND_DSP_GetPriority(FSOUND_DSPUNIT *unit)
{
    STUB();
    return 0;
}

DLL_API void F_API FSOUND_DSP_SetActive(FSOUND_DSPUNIT *unit, signed char active)
{
    STUB();
    return;
}

DLL_API signed char F_API FSOUND_DSP_GetActive(FSOUND_DSPUNIT *unit)
{
    STUB();
    return TRUE;
}


DLL_API FSOUND_DSPUNIT * F_API FSOUND_DSP_GetClearUnit()
{
    STUB();
    return NULL;
}

DLL_API FSOUND_DSPUNIT * F_API FSOUND_DSP_GetSFXUnit()
{
    STUB();
    return NULL;
}

DLL_API FSOUND_DSPUNIT * F_API FSOUND_DSP_GetMusicUnit()
{
    STUB();
    return NULL;
}

DLL_API FSOUND_DSPUNIT * F_API FSOUND_DSP_GetFFTUnit()
{
    STUB();
    return NULL;
}

DLL_API FSOUND_DSPUNIT * F_API FSOUND_DSP_GetClipAndCopyUnit()
{
    STUB();
    return NULL;
}


DLL_API signed char F_API FSOUND_DSP_MixBuffers(void *destbuffer, void *srcbuffer, int len, int freq, int vol, int pan, unsigned int mode)
{
    STUB();
    return TRUE;
}

DLL_API void F_API FSOUND_DSP_ClearMixBuffer()
{
    STUB();
    return;
}

DLL_API int F_API FSOUND_DSP_GetBufferLength()
{
    STUB();
    return 0;
}

DLL_API int F_API FSOUND_DSP_GetBufferLengthTotal()
{
    STUB();
    return 0;
}

DLL_API float * F_API FSOUND_DSP_GetSpectrum()
{
    STUB();
    return NULL;
}


DLL_API signed char F_API FSOUND_Reverb_SetProperties(const FSOUND_REVERB_PROPERTIES *prop)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Reverb_GetProperties(FSOUND_REVERB_PROPERTIES *prop)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Reverb_SetChannelProperties(int channel, const FSOUND_REVERB_CHANNELPROPERTIES *prop)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Reverb_GetChannelProperties(int channel, FSOUND_REVERB_CHANNELPROPERTIES *prop)
{
    STUB();
    return TRUE;
}


DLL_API signed char F_API FSOUND_Record_SetDriver(int outputtype)
{
    STUB();
    return TRUE;
}

DLL_API int F_API FSOUND_Record_GetNumDrivers()
{
    STUB();
    return 0;
}

DLL_API const char * F_API FSOUND_Record_GetDriverName(int id)
{
    STUB();
    return NULL;
}

DLL_API int F_API FSOUND_Record_GetDriver()
{
    STUB();
    return 0;
}


DLL_API signed char F_API FSOUND_Record_StartSample(FSOUND_SAMPLE *sptr, signed char loop)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FSOUND_Record_Stop()
{
    STUB();
    return TRUE;
}

DLL_API int F_API FSOUND_Record_GetPosition()
{
    STUB();
    return 0;
}

