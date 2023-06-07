#ifndef __LIBUTIL_COMMON_FEATURES__
#define __LIBUTIL_COMMON_FEATURES__

#ifndef LIBUTIL_DISABLE_AUTODETECT_FEATURES
    #ifdef __SSE2__
        #define LIBUTIL_FEATURE_SSE2
    #endif

    #ifdef __AVX__
        #define LIBUTIL_FEATURE_AVX
    #endif

    #ifdef __AVX512F__
        #define LIBUTIL_FEATURE_AVX512F
    #endif

    #if 0//defined(__linux__)
        #define LIBUTIL_LINUX
    #elif 1//defined(_WIN32)
        #define LIBUTIL_WINDOWS
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

        #if defined(__x86_64__) || defined(_M_X64)
            #define LIBUTIL_64_BITS
            #define LIBUTIL_X86_64
        #else
            #define LIBUTIL_32_BITS
            #define LIBUTIL_X86
        #endif

        #define LIBUTIL_HAS_HARDWARE_RNG
    #endif
#endif

#endif
