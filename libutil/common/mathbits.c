#include "mathbits.h"

LIBUTIL_API
libutil_u64 LibUtil_AlignUp(libutil_u64 Value, libutil_size Alignment)
{
    return (Value + (Alignment - 1)) & ~(Alignment - 1);
}

LIBUTIL_API
libutil_u64 LibUtil_AlignDown(libutil_u64 Value, libutil_size Alignment)
{
    return (Value & ~(Alignment - 1));
}
