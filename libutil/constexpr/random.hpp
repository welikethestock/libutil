#ifndef __LIBUTIL_CONSTEXPR_RANDOM__
#define __LIBUTIL_CONSTEXPR_RANDOM__

#include "../common/decl.h"

namespace LibUtil
{
    template< typename _T, LibUtil::U32 Seed, LibUtil::U32 Counter >
    constexpr _T CompileTimeRandom();
}

template< typename _T, libutil_u32 Seed, libutil_u32 Counter >
constexpr libutil_u32 CompileTimeRandom()
{
    return (Seed + Counter) * 1664525 + 1013904223;
}

#endif
