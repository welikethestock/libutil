#include "mlib.h"

// TODO: vectorization
LIBUTIL_API
void *LibUtil_Memcpy(void *Destination, const void *Source, libutil_size Length)
{
    libutil_u8 *_Destination    = ((libutil_u8 *)(Destination));
    const libutil_u8 *_Source   = ((const libutil_u8 *)(Source));
    while(Length != 0)
    {
        *_Destination = *_Source;

        ++_Destination;
        ++_Source;
        --Length;
    }

    return Destination;
}

// TODO: vectorization
LIBUTIL_API
void *LibUtil_Memset(void *Destination, libutil_i32 Value, libutil_size Length)
{
    libutil_i8 *_Destination = ((libutil_i8 *)(Destination));
    while(Length != 0)
    {
        *_Destination = Value;

        ++_Destination;
        --Length;
    }

    return Destination;
}
