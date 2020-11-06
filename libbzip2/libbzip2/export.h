#pragma once

#if defined(LIBBZIP2_STATIC)         // Using static.
#  define LIBBZIP2_SYMEXPORT
#elif defined(LIBBZIP2_STATIC_BUILD) // Building static.
#  define LIBBZIP2_SYMEXPORT
#elif defined(LIBBZIP2_SHARED)       // Using shared.
#  ifdef _WIN32
#    define LIBBZIP2_SYMEXPORT __declspec(dllimport)
#  else
#    define LIBBZIP2_SYMEXPORT
#  endif
#elif defined(LIBBZIP2_SHARED_BUILD) // Building shared.
#  ifdef _WIN32
#    define LIBBZIP2_SYMEXPORT __declspec(dllexport)
#  else
#    define LIBBZIP2_SYMEXPORT
#  endif
#else
// If none of the above macros are defined, then we assume we are being used
// by some third-party build system that cannot/doesn't signal the library
// type. Note that this fallback works for both static and shared libraries
// provided the library only exports functions (in other words, no global
// exported data) and for the shared case the result will be sub-optimal
// compared to having dllimport. If, however, your library does export data,
// then you will probably want to replace the fallback with the (commented
// out) error since it won't work for the shared case.
//
#  define LIBBZIP2_SYMEXPORT         // Using static or shared.
//#  error define LIBBZIP2_STATIC or LIBBZIP2_SHARED preprocessor macro to signal libbzip2 library type being linked
#endif
