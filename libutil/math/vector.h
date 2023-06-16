#ifndef __LIBUTIL_MATH_VECTOR__
#define __LIBUTIL_MATH_VECTOR__

#include "../common/decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

typedef union _LIBUTIL_VECTOR3DF
{
    struct
    {
        float X, Y, Z;
    };
    struct
    {
        float x, y, z;
    };
    float Data[3 + 1];
} LIBUTIL_VECTOR3DF;

LIBUTIL_API LIBUTIL_IMPORT
void LibUtil_Vector3DFAdd(LIBUTIL_VECTOR3DF *Out, LIBUTIL_VECTOR3DF *Vector1, LIBUTIL_VECTOR3DF *Vector2);

LIBUTIL_API LIBUTIL_IMPORT
void LibUtil_Vector3DFSubtract(LIBUTIL_VECTOR3DF *Out, LIBUTIL_VECTOR3DF *Vector1, LIBUTIL_VECTOR3DF *Vector2);

LIBUTIL_API LIBUTIL_IMPORT
void LibUtil_Vector3DFMultiply(LIBUTIL_VECTOR3DF *Out, LIBUTIL_VECTOR3DF *Vector1, LIBUTIL_VECTOR3DF *Vector2);

LIBUTIL_API LIBUTIL_IMPORT
void LibUtil_Vector3DFMultiplyF(LIBUTIL_VECTOR3DF *InOut, float Factor);

LIBUTIL_API LIBUTIL_IMPORT
void LibUtil_Vector3DFDivide(LIBUTIL_VECTOR3DF *Out, LIBUTIL_VECTOR3DF *Vector1, LIBUTIL_VECTOR3DF *Vector2);

LIBUTIL_API
void LibUtil_Vector3DFDivideF(LIBUTIL_VECTOR3DF *Out, float Divisor);

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    typedef LIBUTIL_VECTOR3DF lu_vector3df;
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
