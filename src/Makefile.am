
lib_LTLIBRARIES = libfmod0.la

libfmod0_la_SOURCES = fmusic.c fsound.c defs.h
libfmod0_la_LIBADD = 
libfmod0_la_CPPFLAGS = -I../include @SDL_CFLAGS@
libfmod0_la_LDFLAGS = -version-info 0:0:0 $(libtool_flags) \
                          @SDL_LIBS@ @SDL_MIXER_LIBS@ @SDL_SOUND_LIBS@

#if SYS_MSVC
#else
#libtool_flags = -no-undefined
#endif

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = fmod.pc
