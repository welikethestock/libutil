#ifndef __LIBUTIL_COMMON_RANDOM__
#define __LIBUTIL_COMMON_RANDOM__

#include "../common/decl.h"
#include "../arch/random.h"

LIBUTIL_EXTERN_C_BLOCK_START

typedef enum _LIBUTIL_RANDOM_GENERATORS
{
    LIBUTIL_RANDOM_GENERATOR_HW = 0
} LIBUTIL_RANDOM_GENERATORS;

typedef union _LIBUTIL_RANDOM_STATE
{
    struct
    {
        libutil_size Reserved;
    } HW;
} LIBUTIL_RANDOM_STATE;

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool LibUtil_Random(libutil_size Size, LIBUTIL_RANDOM_STATE *State, LIBUTIL_RANDOM_GENERATORS Generator, void *Output);

#ifdef __cplusplus
extern "C++"
{
    namespace LibUtil
    {
        namespace Random
        {
            template< typename _T = libutil_i32 > LIBUTIL_FORCE_INLINE
            _T Generate(LIBUTIL_RANDOM_STATE *State, LIBUTIL_RANDOM_GENERATORS Generator)
            {
                _T Result;
                LibUtil_Random(sizeof(_T), State, Generator, &Result);

                return *(_T *)(&Result);
            }
        }
    }
}
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
