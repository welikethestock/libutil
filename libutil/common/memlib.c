#include "memlib.h"

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
            { // avx512
                _mm512_store_si512(
                    (__m512i *)(_Destination),
                    (((libutil_size)(_Source) & (64 - 1)) == 0) ? _mm512_load_si512((__m512i *)(_Source)) : _mm512_loadu_si512((__m512i *)(_Source))
                );

                Copied = 64;
            }
        #endif
        #ifdef LIBUTIL_FEATURE_AVX512F
            else
        #endif
        #ifdef LIBUTIL_FEATURE_AVX
            if(Length >= 32 && ((libutil_size)(_Destination) & (32 - 1)) == 0) // 32 byte aligned
            { // avx
                _mm256_store_si256(
                    (__m256i *)(_Destination),
                    (((libutil_size)(_Source) & (32 - 1)) == 0) ? _mm256_load_si256((__m256i *)(_Source)) : _mm256_loadu_si256((__m256i *)(_Source))
                );

                Copied = 32;
            }
        #endif
        #if defined(LIBUTIL_FEATURE_SSE2) && (defined(LIBUTIL_FEATURE_AVX) || defined(LIBUTIL_FEATURE_AVX512F))
            else
        #endif
        #if defined(LIBUTIL_FEATURE_SSE2)
            { // sse2
                _mm_store_si128(
                    (__m128i *)(_Destination),
                    (((libutil_size)(_Source) & (16 - 1)) == 0) ? _mm_load_si128((__m128i *)(_Source)) : _mm_loadu_si128((__m128i *)(_Source))
                );

                Copied = 16;
            }

            _Destination += Copied;
            _Source += Copied;
            Length -= Copied;
        }
        #endif
    #endif
    #if defined(LIBUTIL_FEATURE_SSE2) || defined(LIBUTIL_FEATURE_AVX) || defined(LIBUTIL_FEATURE_AVX512F)
        else {
    #endif
        #if defined(LIBUTIL_FEATURE_SSE2) || defined(LIBUTIL_FEATURE_AVX) || defined(LIBUTIL_FEATURE_AVX512F)
            if(Length >= (16 + 1)) // align address
            {
                libutil_size Align = (libutil_size)(_Destination) & (16 - 1);

                if(Align >= 8)
                {
                    *(libutil_i64 *)(_Destination) = *(libutil_i64 *)(_Source);

                    _Destination += 8;
                    _Source += 8;
                    Length -= 8;
                    Align -= 8;
                }

                if(Align >= 4)
                {
                    *(libutil_i32 *)(_Destination) = *(libutil_i32 *)(_Source);

                    _Destination += 4;
                    _Source += 4;
                    Length -= 4;
                    Align -= 4;
                }

                if(Align >= 2)
                {
                    *(libutil_i16 *)(_Destination) = *(libutil_i16 *)(_Source);

                    _Destination += 2;
                    _Source += 2;
                    Length -= 2;
                    Align -= 2;
                }
                if(Align >= 1)
                {
                    *_Destination = *_Source;

                    _Destination += 1;
                    _Source += 1;
                    Length -= 1;
                    Align -= 1;
                }
            }
            else
        #endif
            {
                while(Length != 0)
                {
                    if(Length >= 8)
                    {
                        *(libutil_i64 *)(_Destination) = *(libutil_i64 *)(_Source);

                        Copied = 8;
                    }
                    else if(Length >= 4)
                    {
                        *(libutil_i32 *)(_Destination) = *(libutil_i32 *)(_Source);

                        Copied = 4;
                    }
                    else if(Length >= 2)
                    {
                        *(libutil_i16 *)(_Destination) = *(libutil_i16 *)(_Source);

                        Copied = 2;
                    }
                    else
                    {
                        *_Destination = *_Source;

                        Copied = 1;
                    }

                    _Destination += Copied;
                    _Source += Copied;
                    Length -= Copied;
                }
            }
    #if defined(LIBUTIL_FEATURE_SSE2) || defined(LIBUTIL_FEATURE_AVX) || defined(LIBUTIL_FEATURE_AVX512F)
        }
    #endif
    }

    return Destination;
}

// TODO: vectorization
// NOTE: _mm_setzero_si128, etc
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

LIBUTIL_API
libutil_i32 LibUtil_Memcmp(const void *Block, const void *Other, libutil_size Length)
{
    const libutil_u8 *_Block = (const libutil_u8 *)(Block);
    const libutil_u8 *_Other = (const libutil_u8 *)(Other);
    while(Length != 0)
    {
    #if defined(LIBUTIL_FEATURE_SSE2) || defined(LIBUTIL_FEATURE_AVX) || defined(LIBUTIL_FEATURE_AVX512F)
        if(Length >= 16)
        {
        #if defined(LIBUTIL_FEATURE_AVX) || defined(LIBUTIL_FEATURE_AVX512F)
            if(Length >= 32)
            { // avx
                if(_mm256_movemask_epi8(_mm256_cmpeq_epi16(
                    (((libutil_size)(_Block) & (32 - 1)) == 0) ? _mm256_load_si256((__m256i *)(_Block)) : _mm256_loadu_si256((__m256i *)(_Block)),
                    (((libutil_size)(_Other) & (32 - 1)) == 0) ? _mm256_load_si256((__m256i *)(_Other)) : _mm256_loadu_si256((__m256i *)(_Other))
                )) != 0xFFFFFFFFu)
                {
                    return /*FALSE*/1;
                }

                _Block += 32;
                _Other += 32;
                Length -= 32;
            }
        #endif
        #if defined(LIBUTIL_FEATURE_SSE2) && (defined(LIBUTIL_FEATURE_AVX) || defined(LIBUTIL_FEATURE_AVX512F))
            else
        #endif
        #if defined(LIBUTIL_FEATURE_SSE2)
            { // sse2
                if(_mm_movemask_epi8(_mm_cmpeq_epi16(
                    (((libutil_size)(_Block) & (16 - 1)) == 0) ? _mm_load_si128((__m128i *)(_Block)) : _mm_loadu_si128((__m128i *)(_Block)),
                    (((libutil_size)(_Other) & (16 - 1)) == 0) ? _mm_load_si128((__m128i *)(_Other)) : _mm_loadu_si128((__m128i *)(_Other))
                )) != 0xFFFFu)
                {
                    return /*FALSE*/1;
                }

                _Block += 16;
                _Other += 16;
                Length -= 16;
            }
        }
    #endif
    #endif
    #if defined(LIBUTIL_FEATURE_SSE2) || defined(LIBUTIL_FEATURE_AVX) || defined(LIBUTIL_FEATURE_AVX512F)
        else {
    #endif
        { // fallback / handle trailing bytes not handable with simd instructions
            while(Length != 0)
            {
                libutil_size Compared;

                if(Length >= 8)
                {
                    if(*(libutil_i64 *)(_Block) != *(libutil_i64 *)(_Other))
                    {
                        return /*FALSE*/1;
                    }

                    Compared = 8;
                }
                else if(Length >= 4)
                {
                    if(*(libutil_i32 *)(_Block) != *(libutil_i32 *)(_Other))
                    {
                        return /*FALSE*/1;
                    }

                    Compared = 4;
                }
                else if(Length >= 2)
                {
                    if(*(libutil_i16 *)(_Block) != *(libutil_i16 *)(_Other))
                    {
                        return /*FALSE*/1;
                    }

                    Compared = 2;
                }
                else
                {
                    if(*(libutil_i8 *)(_Block) != *(libutil_i8 *)(_Other))
                    {
                        return /*FALSE*/1;
                    }

                    Compared = 1;
                }

                _Block += Compared;
                _Other += Compared;
                Length -= Compared;
            }
        }
    #if defined(LIBUTIL_FEATURE_SSE2) || defined(LIBUTIL_FEATURE_AVX) || defined(LIBUTIL_FEATURE_AVX512F)
        }
    #endif
    }

    return /*TRUE*/0;
}
