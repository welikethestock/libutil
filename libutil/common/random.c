#include "random.h"
#include "../arch/random.h"

LIBUTIL_API
libutil_bool LibUtil_Random(libutil_size Size, LIBUTIL_RANDOM_STATE *State, LIBUTIL_RANDOM_GENERATORS Generator, void *Output)
{
    switch(Generator)
    {
        case LIBUTIL_RANDOM_GENERATOR_HW:
        {
            switch(Size)
            {
                case sizeof(libutil_i16):
                {
                    *(libutil_i16 *)(Output) = LibUtil_Random16_HW();

                    return TRUE;
                }

                case sizeof(libutil_i32):
                {
                    *(libutil_i32 *)(Output) = LibUtil_Random32_HW();

                    return TRUE;
                }

                case sizeof(libutil_i64):
                {
                    *(libutil_i64 *)(Output) = LibUtil_Random64_HW();

                    return TRUE;
                }

                default:
                {
                    return FALSE;
                }
            }
        }

        default:
        {
            return FALSE;
        }
    }
}
