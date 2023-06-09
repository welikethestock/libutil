#include "../../common/features.h"

#ifdef LIBUTIL_WINDOWS
#include "peb.h"
#include "teb.h"
#include "../../arch/x86/mode.h"

#ifdef LIBUTIL_X86
LIBUTIL_API
LIBUTIL_NT_PEB32 *LibUtil_Nt_GetPeb32()
{
    return (LIBUTIL_NT_PEB32 *)(LibUtil_Nt_GetTeb32()->ProcessEnvironmentBlock);
}

#ifndef LIBUTIL_X86_PURE32
LIBUTIL_API
libutil_u64 LibUtil_Nt_GetPeb64()
{
    libutil_u64 TEB = LibUtil_Nt_GetTeb64();
    if(TEB == NULL)
    {
        return NULL;
    }

    libutil_u64 PEB;
    LibUtil_x86_Memcpy64((libutil_u64)(&PEB), TEB + LIBUTIL_OFFSETOF(LIBUTIL_NT_TEB64, ProcessEnvironmentBlock), sizeof(libutil_u64));

    return PEB;
}

LIBUTIL_API
libutil_bool LibUtil_Nt_ReadPeb64(LIBUTIL_NT_PEB64 *PEB)
{
    libutil_u64 PEB64 = LibUtil_Nt_GetPeb64();
    if(PEB64 == NULL)
    {
        return FALSE;
    }

    LibUtil_x86_Memcpy64((libutil_u64)(PEB), PEB64, sizeof(LIBUTIL_NT_PEB64));

    return TRUE;
}
#endif
#elif defined(LIBUTIL_X86_64)
LIBUTIL_API
LIBUTIL_NT_PEB64 *LibUtil_Nt_GetPeb64()
{
    return (LIBUTIL_NT_PEB64 *)(LibUtil_Nt_GetTeb64()->ProcessEnvironmentBlock);
}
#endif

#endif
