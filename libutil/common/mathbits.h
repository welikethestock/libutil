#ifndef __LIBUTIL_COMMON_MATH_BIT__
#define __LIBUTIL_COMMON_MATH_BIT__

#include "decl.h"

LIBUTIL_API LIBUTIL_IMPORT
libutil_size LibUtil_AlignUp(libutil_size Value, libutil_size Alignment);

LIBUTIL_API LIBUTIL_IMPORT
libutil_size LibUtil_AlignDown(libutil_size Value, libutil_size Alignment);

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    #define lu_alignup      LibUtil_AlignUp
    #define lu_aligndown    LibUtil_AlignDown
#endif

#endif
