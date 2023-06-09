#ifndef __LIBUTIL_COMMON_MEMORY_HEAP__
#define __LIBUTIL_COMMON_MEMORY_HEAP__

#include "decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

LIBUTIL_API LIBUTIL_IMPORT
void *LibUtil_Heap_Allocate(libutil_size Size);

LIBUTIL_API LIBUTIL_IMPORT
void *LibUtil_Heap_Reallocate(void *Address, libutil_size Size);

LIBUTIL_API LIBUTIL_IMPORT
void LibUtil_Heap_Free(void *Address);

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    #define lu_malloc   LibUtil_Heap_Allocate
    #define lu_realloc  LibUtil_Heap_Reallocate
    #define lu_free     LibUtil_Heap_Free
#endif

#ifdef LIBUTIL_HEAP_CALLBACKS
typedef void *(*LIBUTIL_HEAP_MALLOC)(libutil_size Size);
typedef void *(*LIBUTIL_HEAP_REALLOC)(void *Address, libutil_size NewSize);
typedef void (*LIBUTIL_HEAP_FREE)(void *Address);

LIBUTIL_API LIBUTIL_IMPORT
void LibUtil_Heap_SetMalloc(LIBUTIL_HEAP_MALLOC Callback);

LIBUTIL_API LIBUTIL_IMPORT
void LibUtil_Heap_SetRealloc(LIBUTIL_HEAP_REALLOC Callback);

LIBUTIL_API LIBUTIL_IMPORT
void LibUtil_Heap_SetFree(LIBUTIL_HEAP_FREE Callback);

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    #define lu_setmalloc    LibUtil_Heap_Allocate
    #define lu_setrealloc   LibUtil_Heap_Reallocate
    #define lu_setfree      LibUtil_Heap_Free
#endif
#endif

#ifdef __cplusplus
extern "C++"
{
    namespace LibUtil
    {
        namespace Heap
        {
            template< typename _T = void * > LIBUTIL_FORCE_INLINE
            _T Allocate(libutil_size Size)
            {
                return (_T)(LibUtil_Heap_Allocate(Size));
            }

            LIBUTIL_FORCE_INLINE
            void Free(void *Address)
            {
                return LibUtil_Heap_Free(Address);
            }

        #ifdef LIBUTIL_HEAP_CALLBACKS
            LIBUTIL_FORCE_INLINE
            void SetMalloc(LIBUTIL_HEAP_MALLOC Callback)
            {
                LibUtil_Heap_SetMalloc(Callback);
            }

            LIBUTIL_FORCE_INLINE
            void SetRealloc(LIBUTIL_HEAP_REALLOC Callback)
            {
                LibUtil_Heap_SetRealloc(Callback);
            }

            LIBUTIL_FORCE_INLINE
            void SetFree(LIBUTIL_HEAP_FREE Callback)
            {
                LibUtil_Heap_SetFree(Callback);
            }
        #endif
        }
    }
}
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
