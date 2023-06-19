#ifdef LIBUTIL_WINE

#include "wine.h"
#include "../sys/syscall.h"
#include "ldr.h"

LIBUTIL_DECLARE_SYSCALL(NtAllocateVirtualMemory);
LIBUTIL_DECLARE_SYSCALL(NtProtectVirtualMemory);
LIBUTIL_DECLARE_SYSCALL(NtQueryVirtualMemory);

LIBUTIL_API
libutil_bool LibUtil_Nt_InitializeWine()
{
    LIBUTIL_SYSCALLID(NtAllocateVirtualMemory) = LibUtil_Nt_GetLdrExport(LIBUTIL_NT_BASE_NAME_HASH_NTDLL, 0xE2288130);
    if(!LIBUTIL_CHECK_SYSCALLID(NtAllocateVirtualMemory))
    {
        return FALSE;
    }

    LIBUTIL_SYSCALLID(NtProtectVirtualMemory) = LibUtil_Nt_GetLdrExport(LIBUTIL_NT_BASE_NAME_HASH_NTDLL, 0xF0FFF7E3);
    if(!LIBUTIL_CHECK_SYSCALLID(NtProtectVirtualMemory))
    {
        return FALSE;
    }

    LIBUTIL_SYSCALLID(NtQueryVirtualMemory) = LibUtil_Nt_GetLdrExport(LIBUTIL_NT_BASE_NAME_HASH_NTDLL, 0x28C732F5);
    if(!LIBUTIL_CHECK_SYSCALLID(NtQueryVirtualMemory))
    {
        return FALSE;
    }

    return TRUE;
}

#endif
