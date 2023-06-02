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
#endif

#endif
