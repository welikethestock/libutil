#include "../../common/features.h"

#ifdef LIBUTIL_WINDOWS
#include "ldr.h"
#include "peb.h"
#include "../../arch/x86/mode.h"

#ifdef LIBUTIL_X86
LIBUTIL_API
LIBUTIL_NT_PEB_LDR_DATA32 *LibUtil_Nt_GetLdrData32()
{
    return (LIBUTIL_NT_PEB_LDR_DATA32 *)(LibUtil_Nt_GetPeb32()->Ldr);
}

LIBUTIL_API
LIBUTIL_NT_LDR_DATA_TABLE_ENTRY32 *LibUtil_Nt_ReadLdrDataEntry32()
{
    return (LIBUTIL_NT_LDR_DATA_TABLE_ENTRY32 *)(LibUtil_Nt_GetLdrData32()->InLoadOrderModuleList.Flink);
}

#ifndef LIBUTIL_X86_PURE32
LIBUTIL_API
libutil_u64 LibUtil_Nt_GetLdrData64()
{
    libutil_u64 PEB = LibUtil_Nt_GetPeb64();
    if(PEB == NULL)
    {
        return NULL;
    }

    libutil_u64 Ldr;
    LibUtil_x86_Memcpy64((libutil_u64)(&Ldr), PEB + LIBUTIL_OFFSETOF(LIBUTIL_NT_PEB64, Ldr), sizeof(libutil_u64));

    return Ldr;
}

LIBUTIL_API
libutil_bool LibUtil_Nt_ReadLdrData64(LIBUTIL_NT_PEB_LDR_DATA64 *Ldr)
{
    libutil_u64 Ldr64 = LibUtil_Nt_GetLdrData64();
    if(Ldr64 == NULL)
    {
        return FALSE;
    }

    LibUtil_x86_Memcpy64((libutil_u64)(Ldr), Ldr64, sizeof(LIBUTIL_NT_PEB_LDR_DATA64));

    return TRUE;
}

LIBUTIL_API
libutil_u64 LibUtil_Nt_GetLdrDataEntry64()
{
    libutil_u64 Ldr = LibUtil_Nt_GetLdrData64();
    if(Ldr == NULL)
    {
        return NULL;
    }

    libutil_u64 Entry;
    LibUtil_x86_Memcpy64((libutil_size)(&Entry), Ldr + LIBUTIL_OFFSETOF(LIBUTIL_NT_PEB_LDR_DATA64, InLoadOrderModuleList.Flink), sizeof(libutil_u64));

    return Entry;
}

LIBUTIL_API
libutil_bool LibUtil_Nt_ReadLdrDataEntry64(LIBUTIL_NT_LDR_DATA_TABLE_ENTRY64 *Entry, libutil_u64 Address)
{
    if(Address == NULL)
    {
        return FALSE;
    }

    LibUtil_x86_Memcpy64((libutil_size)(Entry), Address, sizeof(LIBUTIL_NT_LDR_DATA_TABLE_ENTRY64));

    return TRUE;
}
#endif
#elif defined(LIBUTIL_X86_64)
LIBUTIL_API
LIBUTIL_NT_PEB_LDR_DATA64 *LibUtil_Nt_GetLdrData64()
{
    return (LIBUTIL_NT_PEB_LDR_DATA64 *)(LibUtil_Nt_GetPeb64()->Ldr);
}
#endif

#endif
