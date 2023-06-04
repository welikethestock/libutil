#ifndef __LIBUTIL_COMMON_MEMORY_MLIB__
#define __LIBUTIL_COMMON_MEMORY_MLIB__

#include "decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

LIBUTIL_API LIBUTIL_IMPORT
void            *LibUtil_Memcpy(void *Destination, const void *Source, libutil_size Length);

LIBUTIL_API LIBUTIL_IMPORT
void            *LibUtil_Memset(void *Destination, libutil_i32 Value, libutil_size Length);

LIBUTIL_API LIBUTIL_IMPORT
libutil_i32     LibUtil_Memcmp(const void *Block, const void *Other, libutil_size Length);

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    #define lu_memcpy LibUtil_Memcpy
    #define lu_memset LibUtil_Memset
    #define lu_memcmp LibUtil_Memcmp
#endif

#ifdef __cplusplus
extern "C++"
{
    namespace LibUtil
    {
        LIBUTIL_FORCE_INLINE
        void *Memcpy(void *Destination, const void *Source, LibUtil::Size Length)
        {
            return LibUtil_Memcpy(Destination, Source, Length);
        }

        LIBUTIL_FORCE_INLINE
        void *Memset(void *Destination, LibUtil::I32 Value, LibUtil::Size Length)
        {
            return LibUtil_Memset(Destination, Value, Length);
        }
    }
}
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
