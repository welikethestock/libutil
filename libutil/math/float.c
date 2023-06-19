#include "float.h"

LIBUTIL_API
libutil_i32 LibUtil_FtoI(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE4_1
    __m128 In = _mm_load_ss(&Value);
    return _mm_cvt_ss2si(
        //_mm_floor_ss(In, In
        _mm_round_ss(In, In, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC)
    );
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_ItoF(libutil_i32 Value)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_cvt_si2ss(_mm_setzero_ps(), Value)
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_AbsF(float Value)
{
    *(libutil_i32 *)(&Value) &= ~(0x80000000);

    return Value;
}

LIBUTIL_API
float LibUtil_FloorF(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE4_1
    float Out;
    __m128 In = _mm_load_ss(&Value);
    _mm_store_ss(
        &Out,
        //_mm_floor_ss(In, In)
        _mm_round_ss(In, In, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC)
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_CeilF(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE4_1
    float Out;
    __m128 In = _mm_load_ss(&Value);
    _mm_store_ss(
        &Out,
        //_mm_ceil_ss(In, In)
        _mm_round_ss(In, In, _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC)
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_SinF(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_sin_ps(_mm_load1_ps(&Value))
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_AsinF(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_asin_ps(_mm_load1_ps(&Value))
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_SinhF(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_sinh_ps(_mm_load1_ps(&Value))
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_AsinhF(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_asinh_ps(_mm_load1_ps(&Value))
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_CosF(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_cos_ps(_mm_load1_ps(&Value))
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_AcosF(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_acos_ps(_mm_load1_ps(&Value))
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_CoshF(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_cosh_ps(_mm_load1_ps(&Value))
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_AcoshF(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_acosh_ps(_mm_load1_ps(&Value))
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_TanF(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_tan_ps(_mm_load1_ps(&Value))
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_AtanF(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_atan_ps(_mm_load1_ps(&Value))
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_Atan2F(float Value, float Dividor)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_atan2_ps(_mm_load1_ps(&Value), _mm_load1_ps(&Dividor))
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_TanhF(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_tanh_ps(_mm_load1_ps(&Value))
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_AtanhF(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_atanh_ps(_mm_load1_ps(&Value))
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_SqrtF(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_sqrt_ss(_mm_load_ss(&Value))
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_RsqrtF(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_rsqrt_ss(_mm_load_ss(&Value))
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_InvSqrtF(float Value)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_invsqrt_ps(_mm_load_ps1(&Value))
    );

    return Out;
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
float LibUtil_PowF(float Value, float Power)
{
#ifdef LIBUTIL_FEATURE_SSE
    float Out;
    _mm_store_ss(
        &Out,
        _mm_pow_ps(_mm_load_ps1(&Value), _mm_load_ps1(&Power))
    );

    return Out;
#else
    #error "Implement me"
#endif
}
