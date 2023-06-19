#include "vector.h"

LIBUTIL_API
void LibUtil_Vector3DFAdd(LIBUTIL_VECTOR3DF *Out, LIBUTIL_VECTOR3DF *Vector1, LIBUTIL_VECTOR3DF *Vector2)
{
#ifdef LIBUTIL_FEATURE_SSE
    __m128 In1 = _mm_loadu_ps(Vector1->Data);
    __m128 In2 = _mm_loadu_ps(Vector2->Data);
    _mm_storeu_ps(
        Out->Data,
        _mm_add_ps(In1, In2)
    );
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
void LibUtil_Vector3DFSubtract(LIBUTIL_VECTOR3DF *Out, LIBUTIL_VECTOR3DF *Vector1, LIBUTIL_VECTOR3DF *Vector2)
{
#ifdef LIBUTIL_FEATURE_SSE
    __m128 In1 = _mm_loadu_ps(Vector1->Data);
    __m128 In2 = _mm_loadu_ps(Vector2->Data);
    _mm_storeu_ps(
        Out->Data,
        _mm_sub_ps(In1, In2)
    );
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
void LibUtil_Vector3DFMultiply(LIBUTIL_VECTOR3DF *Out, LIBUTIL_VECTOR3DF *Vector1, LIBUTIL_VECTOR3DF *Vector2)
{
#ifdef LIBUTIL_FEATURE_SSE
    __m128 In1 = _mm_loadu_ps(Vector1->Data);
    __m128 In2 = _mm_loadu_ps(Vector2->Data);
    _mm_storeu_ps(
        Out->Data,
        _mm_mul_ps(In1, In2)
    );
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
void LibUtil_Vector3DFMultiplyF(LIBUTIL_VECTOR3DF *InOut, float Divisor)
{
#ifdef LIBUTIL_FEATURE_SSE
    _mm_storeu_ps(
        InOut->Data,
        _mm_mul_ps(
            _mm_loadu_ps(InOut->Data),
            _mm_load1_ps(&Divisor)
        )
    );
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
void LibUtil_Vector3DFDivide(LIBUTIL_VECTOR3DF *Out, LIBUTIL_VECTOR3DF *Vector1, LIBUTIL_VECTOR3DF *Vector2)
{
#ifdef LIBUTIL_FEATURE_SSE
    __m128 In1 = _mm_loadu_ps(Vector1->Data);
    __m128 In2 = _mm_loadu_ps(Vector2->Data);
    _mm_storeu_ps(
        Out->Data,
        _mm_div_ps(In1, In2)
    );
#else
    #error "Implement me"
#endif
}

LIBUTIL_API
void LibUtil_Vector3DFDivideF(LIBUTIL_VECTOR3DF *InOut, float Divisor)
{
#ifdef LIBUTIL_FEATURE_SSE
    _mm_storeu_ps(
        InOut->Data,
        _mm_div_ps(
            _mm_loadu_ps(InOut->Data),
            _mm_load1_ps(&Divisor)
        )
    );
#else
    #error "Implement me"
#endif
}
