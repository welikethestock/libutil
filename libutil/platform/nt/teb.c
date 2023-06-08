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

LIBUTIL_API LIBUTIL_IMPORT
LIBUTIL_NT_TEB32 *LibUtil_Nt_GetTeb32()
{
    return (LIBUTIL_NT_TEB32 *)(__readfsdword(0x18));
}

LIBUTIL_API LIBUTIL_IMPORT
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
        return 0;
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
    return 0;
    #endif
}
#endif

#endif

