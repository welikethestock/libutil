#if defined(__x86_64__) || defined(_M_X64) || defined(__i386) || defined(_M_IX86)
#include "../random.h"

#ifdef LIBUTIL_HAS_HARDWARE_RNG
libutil_i16 LibUtil_Random16_HW()
{
    libutil_u16 Value;
    while(!_rdrand16_step(&Value)) {}

    return Value;
}

libutil_i32 LibUtil_Random32_HW()
{
    libutil_u32 Value;
    while(!_rdrand32_step(&Value)) {}

    return Value;
}

libutil_i64 LibUtil_Random64_HW()
{
    libutil_u64 Value;
    while(!_rdrand64_step(&Value)) {}

    return Value;
}
#endif

#endif
