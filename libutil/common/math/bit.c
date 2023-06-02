#include "bit.h"

LIBUTIL_API LIBUTIL_IMPORT
libutil_size LibUtil_AlignUp(libutil_size Value, libutil_size Alignment)
{
    return (Value + (Alignment - 1)) & ~(Alignment - 1);
}

LIBUTIL_API LIBUTIL_IMPORT
libutil_size LibUtil_AlignDown(libutil_size Value, libutil_size Alignment)
{
    return (Value & ~(Alignment - 1));
}
