#include "../../common/features.h"

#ifdef LIBUTIL_WINDOWS
#include "teb.h"

#ifdef LIBUTIL_X86_64
LIBUTIL_API
LIBUTIL_NT_TEB64 *LibUtil_Nt_GetTeb64()
{
    return (LIBUTIL_NT_TEB64 *)(__readgsqword(0x30));
}
#else
#include "../../arch/x86/mode.h"

LIBUTIL_API
LIBUTIL_NT_TEB32 *LibUtil_Nt_GetTeb32()
{
    return (LIBUTIL_NT_TEB32 *)(__readfsdword(0x18));
}

#ifndef LIBUTIL_X86_PURE32
LIBUTIL_API
libutil_u64 LibUtil_Nt_GetTeb64()
{
    #ifdef LIBUTIL_MSVC
        libutil_u32 _GS;
        __asm
        {
            push    gs
            pop     _GS
        }

        if(_GS == NULL) // not WoW
        {
            return NULL;
        }

        LIBUTIL_NT_ULARGE_INTEGER R12;

        LIBUTIL_X86_ENTER_CS(0x33);
        __asm
        {
            LIBUTIL_X86_PUSHREG64(LIBUTIL_X86_R12)
            pop R12.LowPart
        }
        LIBUTIL_X86_EXIT_CS(0x23);

        return R12.QuadPart;
    #else
        return NULL;
    #endif
}

void CopyMemory64(libutil_u64 Destination, libutil_u64 Source, libutil_u64 BufferLength)
{
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
}

LIBUTIL_API
libutil_bool LibUtil_Nt_ReadTeb64(LIBUTIL_NT_TEB64 *TEB)
{
    libutil_u64 TEB64 = LibUtil_Nt_GetTeb64();
    if(TEB64 == NULL)
    {
        return FALSE;
    }

    LibUtil_x86_Memcpy64((libutil_u64)(TEB), TEB64, sizeof(LIBUTIL_NT_TEB64));

    return TRUE;
}
#endif
#endif

#endif

