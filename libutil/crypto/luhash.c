#include "luhash.h"

LIBUTIL_API
libutil_u32 LibUtil_LUHash(const void *Data, libutil_u32 Seed, libutil_size Length)
{
    libutil_u32 Hash = Seed ^ (Length & 0xFFFFFFFF);
    Hash *= 0x4A95CF27;

    const libutil_u8 *_Data = (const libutil_u8 *)(Data);
    for(libutil_size Index = 0; Length != 0; --Length, ++Index)
    {
        if(Length >= 4)
        {
            Hash ^= *(libutil_u32 *)(&_Data[Index]);
            Hash *= 0x4A95CF27;
        }
        else
        {
            switch(Length)
            {
                case 3:
                {
                #ifdef LIBUTIL_LITTLE_ENDIAN
                    Hash ^= (_Data[Length] << 16);
                #else
                    Hash ^= (_Data[Length] >> 16);
                #endif
                }

                case 2:
                {
                #ifdef LIBUTIL_LITTLE_ENDIAN
                    Hash ^= (_Data[Length] << 8);
                #else
                    Hash ^= (_Data[Length] >> 8);
                #endif
                }

                case 1:
                {
                    Hash ^= _Data[Length];
                    Hash *= 0x4A95CF27;

                    break;
                }
            }

            break;
        }
    }

    return Hash;
}
