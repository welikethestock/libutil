#include "../../common/features.h"

#if defined(LIBUTIL_X86) || defined(LIBUTIL_X86_64)
#include "../random.h"

#ifdef LIBUTIL_HAS_HARDWARE_RNG
libutil_bool LibUtil_Random16_HW(libutil_u16 *Output)
{
    return _rdrand16_step(Output);
}

libutil_bool LibUtil_Random32_HW(libutil_u32 *Output)
{
    return _rdrand32_step(Output);
}

libutil_bool LibUtil_Random64_HW(libutil_u64 *Output)
{
    return _rdrand64_step(Output);
}
#endif

#endif
