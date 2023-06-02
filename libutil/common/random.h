#ifndef __LIBUTIL_COMMON_RANDOM__
#define __LIBUTIL_COMMON_RANDOM__

#include "../common/decl.h"
#include "../arch/random.h"

LIBUTIL_EXTERN_C_BLOCK_START

typedef enum _LIBUTIL_RANDOM_GENERATORS
{
#ifdef LIBUTIL_HAS_HARDWARE_RNG
    LIBUTIL_RANDOM_GENERATOR_HW
#endif
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

            template<> LIBUTIL_FORCE_INLINE
            float Generate(LIBUTIL_RANDOM_STATE *State, LIBUTIL_RANDOM_GENERATORS Generator)
            {
                libutil_u32 Result = Generate<libutil_u32>(State, Generator);

                return (float)((float)(Result) / (float)((libutil_u32)(-1)));
            }

            template<> LIBUTIL_FORCE_INLINE
            double Generate(LIBUTIL_RANDOM_STATE *State, LIBUTIL_RANDOM_GENERATORS Generator)
            {
                libutil_u64 Result = Generate<libutil_u64>(State, Generator);

                return (double)((double)(Result) / (double)((libutil_u64)(-1)));
            }
        }
    }
}
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
