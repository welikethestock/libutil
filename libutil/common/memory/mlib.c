#include "mlib.h"

// TODO: vectorization
LIBUTIL_API
void *LibUtil_Memcpy(void *Destination, const void *Source, libutil_size Length)
{
    libutil_u8 *_Destination    = ((libutil_u8 *)(Destination));
    const libutil_u8 *_Source   = ((const libutil_u8 *)(Source));
    while(Length != 0)
    {
        libutil_size Copied;

    #if defined(LIBUTIL_FEATURE_SSE2) || defined(LIBUTIL_FEATURE_AVX) || defined(LIBUTIL_FEATURE_AVX512F)
        if(Length >= 16 && ((libutil_size)(_Destination) & (16 - 1)) == 0) // 16 byte aligned
        {
        #ifdef LIBUTIL_FEATURE_AVX512F
            if(Length >= 64 && ((libutil_size)(_Destination) & (64 - 1)) == 0) // 64 byte aligned
            {
                _mm512_store_si512(
                    (__m512i *)(_Destination),
                    _mm512_loadu_si512((__m512i *)(_Source))
                );

                Copied = 64;
            }
        #endif
        #ifdef LIBUTIL_FEATURE_AVX512F
            else
        #endif
        #ifdef LIBUTIL_FEATURE_AVX
            if(Length >= 32 && ((libutil_size)(_Destination) & (32 - 1)) == 0) // 32 byte aligned
            {
                _mm256_store_si256(
                    (__m256i *)(_Destination),
                    _mm256_loadu_si256((__m256i *)(_Source))
                );

                Copied = 32;
            }
        #endif
        #if defined(LIBUTIL_FEATURE_AVX) || defined(LIBUTIL_FEATURE_AVX512F)
            else
        #endif
            {
                _mm_store_si128(
                    (__m128i *)(_Destination),
                    _mm_loadu_si128((__m128i *)(_Source))
                );

                Copied = 16;
            }
        }
    #endif
    #if defined(LIBUTIL_FEATURE_SSE2) || defined(LIBUTIL_FEATURE_AVX) || defined(LIBUTIL_FEATURE_AVX512F)
        else {
    #endif
            if(Length >= 8)
            {
                *(long long *)(_Destination) = *(long long *)(_Source);

                Copied = 8;
            }
            else if(Length >= 4)
            {
                *(int *)(_Destination) = *(int *)(_Source);

                Copied = 4;
            }
            else if(Length >= 2)
            {
                *(short *)(_Destination) = *(short *)(_Source);

                Copied = 2;
            }
            else
            {
                *_Destination = *_Source;

                Copied = 1;
            }
    #if defined(LIBUTIL_FEATURE_SSE2) || defined(LIBUTIL_FEATURE_AVX) || defined(LIBUTIL_FEATURE_AVX512F)
        }
    #endif

        _Destination += Copied;
        _Source += Copied;
        Length -= Copied;
    }

    return Destination;
}

// TODO: vectorization
LIBUTIL_API
void *LibUtil_Memset(void *Destination, libutil_i32 Value, libutil_size Length)
{
    libutil_i8 *_Destination = ((libutil_i8 *)(Destination));
    while(Length != 0)
    {
        *_Destination = Value;

        ++_Destination;
        --Length;
    }

    return Destination;
}
