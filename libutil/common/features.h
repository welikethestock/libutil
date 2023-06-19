#ifndef __LIBUTIL_COMMON_FEATURES__
#define __LIBUTIL_COMMON_FEATURES__

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4005) // macro redefinition
#endif

#ifndef LIBUTIL_DISABLE_AUTODETECT_FEATURES
    #if defined(_WIN32)
        #define LIBUTIL_WINDOWS
    #elif defined(__linux__)
        #define LIBUTIL_LINUX
    #endif

    #if defined(_MSC_VER)
        #define LIBUTIL_MSVC
    #elif defined(__GNUC__)
        #define LIBUTIL_GNUC
    #endif

    #ifdef __clang__
        #define LIBUTIL_CLANG
    #endif

    #if defined(__x86_64__) || defined(_M_X64) || defined(__i386) || defined(_M_IX86)
        #define LIBUTIL_LITTLE_ENDIAN

        #if (defined(__x86_64__) || defined(_M_X64)) && !defined(_LIBUTIL_SYNTAX_HIGHLIGHT_X86)
            #define LIBUTIL_64_BITS
            #define LIBUTIL_X86_64
        #else
            #define LIBUTIL_32_BITS
            #define LIBUTIL_X86
        #endif

        #define LIBUTIL_HAS_HARDWARE_RNG
    #endif

    #ifdef __SSE__
        #define LIBUTIL_FEATURE_SSE
    #endif

    #ifdef __SSE2__
        #define LIBUTIL_FEATURE_SSE2
    #endif

    #ifdef __SSE3__
        #define LIBUTIL_FEATURE_SSE3
    #endif

    #ifdef __SSE4_1__
        #define LIBUTIL_FEATURE_SSE4_1
    #endif

    #ifdef __SSE4_2__
        #define LIBUTIL_FEATURE_SSE4_2
    #endif

    #ifdef __AVX__
        #define LIBUTIL_FEATURE_AVX
        #ifdef LIBUTIL_MSVC
            #define LIBUTIL_FEATURE_SSE
            #define LIBUTIL_FEATURE_SSE2
            #define LIBUTIL_FEATURE_SSE3
            #define LIBUTIL_FEATURE_SSE4_1
            #define LIBUTIL_FEATURE_SSE4_2
        #endif
    #endif

    #ifdef __AVX2__
        #define LIBUTIL_FEATURE_AVX2
        #ifdef LIBUTIL_MSVC
            #define LIBUTIL_FEATURE_SSE
            #define LIBUTIL_FEATURE_SSE2
            #define LIBUTIL_FEATURE_SSE3
            #define LIBUTIL_FEATURE_SSE4_1
            #define LIBUTIL_FEATURE_SSE4_2
        #endif
    #endif

    #ifdef __AVX512F__
        #define LIBUTIL_FEATURE_AVX512F

        #ifdef LIBUTIL_MSVC
            #define LIBUTIL_FEATURE_SSE
            #define LIBUTIL_FEATURE_SSE2
            #define LIBUTIL_FEATURE_SSE3
            #define LIBUTIL_FEATURE_SSE4_1
            #define LIBUTIL_FEATURE_SSE4_2
        #endif
    #endif

    #ifdef __AVX512BW__
        #define LIBUTIL_FEATURE_AVX512F

        #ifdef LIBUTIL_MSVC
            #define LIBUTIL_FEATURE_SSE
            #define LIBUTIL_FEATURE_SSE2
            #define LIBUTIL_FEATURE_SSE3
            #define LIBUTIL_FEATURE_SSE4_1
            #define LIBUTIL_FEATURE_SSE4_2
        #endif
    #endif
#endif

#ifdef _MSC_VER
#pragma warning (pop)
#endif

#include "warnings.h"

#endif
