#ifndef __LIBUTIL_ARCH_RANDOM__
#define __LIBUTIL_ARCH_RANDOM__

#include "../common/decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

#ifdef LIBUTIL_HAS_HARDWARE_RNG
LIBUTIL_API LIBUTIL_IMPORT
libutil_bool LibUtil_Random16_HW(libutil_u16 *Output);

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool LibUtil_Random32_HW(libutil_u32 *Output);

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool LibUtil_Random64_HW(libutil_u64 *Output);
#endif

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    #define lu_random16hw LibUtil_Random16_HW
    #define lu_random32hw LibUtil_Random32_HW
    #define lu_random64hw LibUtil_Random64_HW
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
