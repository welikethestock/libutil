#include "int.h"

LIBUTIL_API
libutil_u32 LibUtil_AbsI32(libutil_i32 Value)
{
#ifdef LIBUTIL_LITTLE_ENDIAN
    libutil_u32 Mask = (Value >> 31);
#else
    libutil_u32 Mask = (Value << 31);
#endif
    Value ^= Mask;
    Value += Mask & 1;

    return Value;
}

LIBUTIL_API
libutil_u64 LibUtil_AbsI64(libutil_i64 Value)
{
#ifdef LIBUTIL_LITTLE_ENDIAN
    libutil_u64 Mask = (Value >> 63);
#else
    libutil_u64 Mask = (Value << 63);
#endif
    Value ^= Mask;
    Value += Mask & 1;

    return Value;
}
