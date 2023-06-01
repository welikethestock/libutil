#ifndef __LIBUTIL_COMMON_MEMORY_HEAP__
#define __LIBUTIL_COMMON_MEMORY_HEAP__

#include "../decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

LIBUTIL_API LIBUTIL_IMPORT
void *LibUtil_Heap_Allocate(libutil_size Size);

LIBUTIL_API LIBUTIL_IMPORT
void LibUtil_Heap_Free(void *Address);

#ifdef __cplusplus
extern "C++"
{
    namespace LibUtil
    {
        namespace Heap
        {
            template< typename _T = void * >
            LIBUTIL_FORCE_INLINE _T Allocate(libutil_size Size)
            {
                return (_T)(::LibUtil_Heap_Allocate(Size));
            }

            LIBUTIL_FORCE_INLINE void Free(void *Address)
            {
                return ::LibUtil_Heap_Free(Address);
            }
        }
    }
}
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
