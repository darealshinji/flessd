/*
 * $Id: defs.h 24 2004-07-26 18:35:56Z sam $
 *
 *    (c) 2004 Sam Hocevar <sam@zoy.org>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the Do What The Fuck You Want To
 *  Public License as published by Banlu Kemiyatorn. See
 *  http://sam.zoy.org/projects/COPYING.WTFPL for more details.
 */

#define STUB() fprintf(stderr, "stub! (%s)\n", __FUNCTION__);

#include <SDL.h>
#include <SDL_cdrom.h>
#include <SDL_mixer.h>
#include <SDL_sound.h>

struct FSOUND_SAMPLE
{
    Mix_Chunk *wave;
    int index;
    Uint32 mode;
};

