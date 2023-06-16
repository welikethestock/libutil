#ifndef __LIBUTIL_MATH_FLOAT__
#define __LIBUTIL_MATH_FLOAT__

#include "../common/decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

LIBUTIL_API LIBUTIL_IMPORT
libutil_i32 LibUtil_FtoI(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_ItoF(libutil_i32 Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_FloorF(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_CeilF(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_SinF(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_AsinF(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_SinhF(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_AsinhF(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_CosF(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_AcosF(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_CoshF(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_AcoshF(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_TanF(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_AtanF(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_Atan2F(float Value, float Dividor);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_TanhF(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_AtanhF(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_SqrtF(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_RsqrtF(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_InvSqrtF(float Value);

LIBUTIL_API LIBUTIL_IMPORT
float       LibUtil_PowF(float Value, float Power);

LIBUTIL_EXTERN_C_BLOCK_END

#endif
