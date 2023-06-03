#include "random.h"
#include "../arch/random.h"

LIBUTIL_API
libutil_bool LibUtil_Random(libutil_size Size, LIBUTIL_RANDOM_STATE *State, LIBUTIL_RANDOM_GENERATORS Generator, void *Output)
{
    switch(Generator)
    {
    #ifdef LIBUTIL_HAS_HARDWARE_RNG
        case LIBUTIL_RANDOM_GENERATOR_HW:
        {
            switch(Size)
            {
                case sizeof(libutil_i16):
                {
                    while(!LibUtil_Random16_HW((libutil_u16 *)(Output))) {}

                    return TRUE;
                }

                case sizeof(libutil_i32):
                {
                    while(!LibUtil_Random32_HW((libutil_u32 *)(Output))) {}

                    return TRUE;
                }

                case sizeof(libutil_i64):
                {
                    while(!LibUtil_Random64_HW((libutil_u64 *)(Output))) {}

                    return TRUE;
                }

                default:
                {
                    return FALSE;
                }
            }
        }
    #endif

        default:
        {
            return FALSE;
        }
    }
}
