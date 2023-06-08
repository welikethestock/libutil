#include "../../common/features.h"

#if defined(LIBUTIL_X86)
#include "mode.h"

LIBUTIL_API
void LibUtil_x86_Memcpy64(libutil_u64 Destination, libutil_u64 Source, libutil_u64 BufferLength)
{
    #if defined(LIBUTIL_GNUC)
    #elif defined(LIBUTIL_MSVC)
    __asm
    {
        push    esi
        push    edi

        LIBUTIL_X86_ENTER_CS(0x33)

        push    Destination
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RDI)

        push    Source
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RSI)

        push    BufferLength
        LIBUTIL_X86_POPREG64(LIBUTIL_X86_RCX)

        rep     movsb

        LIBUTIL_X86_EXIT_CS(0x23)

        pop     edi
        pop     esi
    }
    #endif
}

#endif

