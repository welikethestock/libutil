#if defined(__x86_64__) || defined(_M_X64) || defined(__i386) || defined(_M_IX86)
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
