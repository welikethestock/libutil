#ifndef __LIBUTIL_ANALYSIS_DEBUG__
#define __LIBUTIL_ANALYSIS_DEBUG__

#include "../common/decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

LIBUTIL_API LIBUTIL_IMPORT
void LibUtil_Debug(const char *Format, ...);

#ifndef LIBUTIL_NO_DEBUG
    #define LIBUTIL_DEBUG LibUtil_Debug
#else
    #define LIBUTIL_DEBUG(Format, ...)
#endif

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    #define lu_debug LibUtil_Debug
    #define LU_DEBUG LIBUTIL_DEBUG
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
