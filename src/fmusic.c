/*
 * $Id: fmusic.c 27 2004-07-27 08:06:17Z sam $
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

#include "flessd/types.h"
#include "flessd/music.h"
#include "flessd/sound.h"

#include "defs.h"

DLL_API FMUSIC_MODULE * F_API FMUSIC_LoadSong(const char *name)
{
    STUB();
    return NULL;
}

DLL_API FMUSIC_MODULE * F_API FMUSIC_LoadSongEx(const char *name_or_data, int offset, int length, unsigned int mode, const int *samplelist, int samplelistnum)
{
    STUB();
    return NULL;
}

DLL_API int F_API FMUSIC_GetOpenState(FMUSIC_MODULE *mod)
{
    STUB();
    return 0;
}

DLL_API signed char F_API FMUSIC_FreeSong(FMUSIC_MODULE *mod)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FMUSIC_PlaySong(FMUSIC_MODULE *mod)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FMUSIC_StopSong(FMUSIC_MODULE *mod)
{
    STUB();
    return TRUE;
}

DLL_API void F_API FMUSIC_StopAllSongs()
{
    STUB();
    return;
}


DLL_API signed char F_API FMUSIC_SetZxxCallback(FMUSIC_MODULE *mod, FMUSIC_CALLBACK callback)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FMUSIC_SetRowCallback(FMUSIC_MODULE *mod, FMUSIC_CALLBACK callback, int rowstep)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FMUSIC_SetOrderCallback(FMUSIC_MODULE *mod, FMUSIC_CALLBACK callback, int orderstep)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FMUSIC_SetInstCallback(FMUSIC_MODULE *mod, FMUSIC_CALLBACK callback, int instrument)
{
    STUB();
    return TRUE;
}


DLL_API signed char F_API FMUSIC_SetSample(FMUSIC_MODULE *mod, int sampno, FSOUND_SAMPLE *sptr)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FMUSIC_SetUserData(FMUSIC_MODULE *mod, void *userdata)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FMUSIC_OptimizeChannels(FMUSIC_MODULE *mod, int maxchannels, int minvolume)
{
    STUB();
    return TRUE;
}


DLL_API signed char F_API FMUSIC_SetReverb(signed char reverb)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FMUSIC_SetLooping(FMUSIC_MODULE *mod, signed char looping)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FMUSIC_SetOrder(FMUSIC_MODULE *mod, int order)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FMUSIC_SetPaused(FMUSIC_MODULE *mod, signed char pause)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FMUSIC_SetMasterVolume(FMUSIC_MODULE *mod, int volume)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FMUSIC_SetMasterSpeed(FMUSIC_MODULE *mode, float speed)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FMUSIC_SetPanSeperation(FMUSIC_MODULE *mod, float pansep)
{
    STUB();
    return TRUE;
}


DLL_API const char * F_API FMUSIC_GetName(FMUSIC_MODULE *mod)
{
    STUB();
    return "(unknown)";
}

DLL_API int F_API FMUSIC_GetType(FMUSIC_MODULE *mod)
{
    STUB();
    return 0;
}

DLL_API int F_API FMUSIC_GetNumOrders(FMUSIC_MODULE *mod)
{
    STUB();
    return 0;
}

DLL_API int F_API FMUSIC_GetNumPatterns(FMUSIC_MODULE *mod)
{
    STUB();
    return 0;
}

DLL_API int F_API FMUSIC_GetNumInstruments(FMUSIC_MODULE *mod)
{
    STUB();
    return 0;
}

DLL_API int F_API FMUSIC_GetNumSamples(FMUSIC_MODULE *mod)
{
    STUB();
    return 0;
}

DLL_API int F_API FMUSIC_GetNumChannels(FMUSIC_MODULE *mod)
{
    STUB();
    return 0;
}

DLL_API FSOUND_SAMPLE * F_API FMUSIC_GetSample(FMUSIC_MODULE *mod, int sampno)
{
    STUB();
    return NULL;
}

DLL_API int F_API FMUSIC_GetPatternLength(FMUSIC_MODULE *mod, int orderno)
{
    STUB();
    return 0;
}


DLL_API signed char F_API FMUSIC_IsFinished(FMUSIC_MODULE *mod)
{
    STUB();
    return TRUE;
}

DLL_API signed char F_API FMUSIC_IsPlaying(FMUSIC_MODULE *mod)
{
    STUB();
    return TRUE;
}

DLL_API int F_API FMUSIC_GetMasterVolume(FMUSIC_MODULE *mod)
{
    STUB();
    return 0;
}

DLL_API int F_API FMUSIC_GetGlobalVolume(FMUSIC_MODULE *mod)
{
    STUB();
    return 0;
}

DLL_API int F_API FMUSIC_GetOrder(FMUSIC_MODULE *mod)
{
    STUB();
    return 0;
}

DLL_API int F_API FMUSIC_GetPattern(FMUSIC_MODULE *mod)
{
    STUB();
    return 0;
}

DLL_API int F_API FMUSIC_GetSpeed(FMUSIC_MODULE *mod)
{
    STUB();
    return 0;
}

DLL_API int F_API FMUSIC_GetBPM(FMUSIC_MODULE *mod)
{
    STUB();
    return 0;
}

DLL_API int F_API FMUSIC_GetRow(FMUSIC_MODULE *mod)
{
    STUB();
    return 0;
}

DLL_API signed char F_API FMUSIC_GetPaused(FMUSIC_MODULE *mod)
{
    STUB();
    return TRUE;
}

DLL_API int F_API FMUSIC_GetTime(FMUSIC_MODULE *mod)
{
    STUB();
    return 0;
}

DLL_API int F_API FMUSIC_GetRealChannel(FMUSIC_MODULE *mod, int modchannel)
{
    STUB();
    return 0;
}

DLL_API void * F_API FMUSIC_GetUserData(FMUSIC_MODULE *mod)
{
    STUB();
    return NULL;
}

