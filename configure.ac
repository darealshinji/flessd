AC_INIT(include/fmod.h)

AC_PREREQ(2.50)
AC_CONFIG_AUX_DIR(autotools)
AC_CANONICAL_SYSTEM

AM_INIT_AUTOMAKE(flessd, 0.0)
AM_CONFIG_HEADER(config.h)

AC_PROG_CC
AC_STDC_HEADERS

AC_LIBTOOL_WIN32_DLL
AM_PROG_LIBTOOL 

AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T

AC_CHECK_HEADERS(unistd.h sys/param.h limits.h pwd.h errno.h)

dnl
dnl  Check the operating system
dnl
case x"${target_os}" in
  xdarwin*)
    CFLAGS="${CFLAGS} -no-cpp-precomp"
    ;;
  x*cygwin*)
    dnl Check if we are using the mno-cygwin mode in which case we are
    dnl actually dealing with a mingw32 compiler.
    AC_EGREP_CPP(yes, [#ifndef WIN32
                       yes
                       #endif],
                 AC_DEFINE(SYS_CYGWIN, 1, Have a Cygwin system.))
    AC_DEFINE(WIN32, 1, Using Win32.)
    ;;
  xbeos*)
    AC_DEFINE(SYS_BEOS, 1, Have a BeOS system.)
    ;;
  x*msvc*)
    SYS_MSVC=1
    ;;
  x*)
    ;;
esac

dnl
dnl  Check for available warning flags
dnl
CFLAGS_save="${CFLAGS}"

AC_CACHE_CHECK([if \$CC accepts -Wall],
    [ac_cv_c_Wall],
    [CFLAGS="-Wall ${CFLAGS_save}"
     AC_TRY_COMPILE([],,ac_cv_c_Wall=yes, ac_cv_c_Wall=no)])
if test "x${ac_cv_c_Wall}" != "xno"; then
    CFLAGS_save="-Wall ${CFLAGS_save}"
fi

AC_CACHE_CHECK([if \$CC accepts -Wsign-compare],
    [ac_cv_c_Wsign_compare],
    [CFLAGS="-Wsign-compare ${CFLAGS_save}"
     AC_TRY_COMPILE([],,ac_cv_c_Wsign_compare=yes, ac_cv_c_Wsign_compare=no)])
if test "x${ac_cv_c_Wsign_compare}" != "xno"; then
    CFLAGS_save="-Wsign-compare ${CFLAGS_save}"
fi

CFLAGS="${CFLAGS_save}"

dnl
dnl  Use 64 bits offsets
dnl
CFLAGS="-D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 ${CFLAGS}"

dnl
dnl  Check for SDL
dnl
AM_PATH_SDL(1.2.0, :, AC_MSG_ERROR([*** SDL version 1.2.0 not found!]))
AC_SUBST(SDL_CFLAGS)
AC_SUBST(SDL_LIBS)

dnl
dnl  Check for SDL_mixer
dnl
AC_CHECK_LIB(SDL_mixer, Mix_OpenAudio,
             :, AC_MSG_ERROR([*** SDL_mixer not found]), [[$SDL_LIBS]])
SDL_MIXER_LIBS="-lSDL_mixer"
AC_SUBST(SDL_MIXER_LIBS)

dnl
dnl  Check for SDL_sound
dnl
AC_CHECK_LIB(SDL_sound, Sound_Init,
             :, AC_MSG_ERROR([*** SDL_sound not found]), [[$SDL_LIBS]])
SDL_SOUND_LIBS="-lSDL_sound"
AC_SUBST(SDL_SOUND_LIBS)

AC_OUTPUT([
  Makefile
  include/Makefile
  src/Makefile
  src/fmod.pc
])

