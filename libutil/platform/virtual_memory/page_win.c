#include "../../common/features.h"

#ifdef LIBUTIL_WINDOWS
#include "page.h"
#include "../../common/mathbits.h"
#include "../../platform/nt/common.h"
#include "../../platform/nt/teb.h"

#define LIBUTIL_PAGE_ALIGN 0x1000

#define MEM_COMMIT  0x1000
#define MEM_RESERVE 0x2000

LIBUTIL_DEFINE_SYSCALL(NtAllocateVirtualMemory);

LIBUTIL_API
libutil_bool LibUtil_Page_Allocate(libutil_syscallarg *BaseAddress, libutil_size Size, libutil_u32 Protection, libutil_u32 Flags)
{
    if(!LIBUTIL_CHECK_SYSCALLID(NtAllocateVirtualMemory))
    {
        return FALSE;
    }

    libutil_syscallarg AllocationType = (MEM_COMMIT | MEM_RESERVE);
    if(Flags & LIBUTIL_MAP_NORESERVE)
    {
        AllocationType &= ~(MEM_RESERVE);
    }

    if(*BaseAddress != NULL)
    {
        *BaseAddress = (libutil_size)(LibUtil_AlignDown(*BaseAddress, 0x1000));
    }

#ifndef LIBUTIL_WINE
    LIBUTIL_ALIGN(16) libutil_syscallarg AlignedSize = LibUtil_AlignUp(Size, 0x1000);

    LIBUTIL_NT_STATUS Status = lu_syscall6(
        LIBUTIL_SYSCALLID(NtAllocateVirtualMemory),
        -1,
        (libutil_syscallarg)(BaseAddress),
        NULL,
        (libutil_syscallarg)(&AlignedSize), //NOTE: not proper
        AllocationType,
        Protection
    );
#else
    LIBUTIL_NT_STATUS Status = ((LIBUTIL_NT_STATUS(LIBUTIL_MSABI *)(void *, libutil_size *, void *, libutil_size *, libutil_u32, libutil_u32))(LIBUTIL_SYSCALLID(NtAllocateVirtualMemory)))(
        (void *)(-1),
        (libutil_size *)(BaseAddress),
        NULL,
        (libutil_size *)(&Size),
        AllocationType,
        Protection
    );
#endif

    return LIBUTIL_NT_SUCCESS(Status);
}

LIBUTIL_DEFINE_SYSCALL(NtProtectVirtualMemory);
LIBUTIL_API
libutil_bool LibUtil_Page_Protect(libutil_syscallarg Address, libutil_size Size, libutil_u32 Protection, libutil_u32 *OldProtection)
{
    if(!LIBUTIL_CHECK_SYSCALLID(NtProtectVirtualMemory))
    {
        return FALSE;
    }

#ifndef LIBUTIL_WINE
    LIBUTIL_NT_STATUS Status = LibUtil_Syscall5(
        LIBUTIL_SYSCALLID(NtProtectVirtualMemory),
        -1,
        (libutil_syscallarg)(LibUtil_AlignDown(Address, 0x1000)),
        (libutil_syscallarg)(LibUtil_AlignUp(Size, 0x1000)), //NOTE: not proper
        Protection,
        (libutil_syscallarg)(&OldProtection)
    );
#else
    LIBUTIL_NT_STATUS Status = ((LIBUTIL_NT_STATUS(LIBUTIL_MSABI *)(void *, libutil_size, libutil_size, libutil_u32, libutil_u32 *))(LIBUTIL_SYSCALLID(NtProtectVirtualMemory)))(
        (void *)(-1),
        (libutil_size)(LibUtil_AlignDown(Address, 0x1000)),
        (libutil_size)(LibUtil_AlignUp(Size, 0x1000)),
        Protection,
        OldProtection
    );
#endif

    return LIBUTIL_NT_SUCCESS(Status);
}

LIBUTIL_DEFINE_SYSCALL(NtQueryVirtualMemory);
LIBUTIL_API
libutil_bool LibUtil_Page_QueryProtection(libutil_syscallarg Address, libutil_u32* Protection)
{
    if(!LIBUTIL_CHECK_SYSCALLID(NtQueryVirtualMemory))
    {
        return FALSE;
    }

#ifndef LIBUTIL_WINE
#if defined(LIBUTIL_X86) && !defined(LIBUTIL_X86_PURE32)
    LIBUTIL_ALIGN(16) union
    {
        LIBUTIL_NT_MEMORY_BASIC_INFORMATION32 Info32;
        LIBUTIL_NT_MEMORY_BASIC_INFORMATION64 Info64;
    } Memory;
#else
    LIBUTIL_ALIGN(16) LIBUTIL_NT_MEMORY_BASIC_INFORMATION MemoryInfo;
#endif

    LIBUTIL_NT_STATUS Status = LibUtil_Syscall6(
        LIBUTIL_SYSCALLID(NtQueryVirtualMemory),
        (libutil_syscallarg)(-1),
        LibUtil_AlignDown(Address, 0x1000),
    #if defined(LIBUTIL_X86) && !defined(LIBUTIL_X86_PURE32)
        (libutil_syscallarg)(&Memory),
    #else
        (libutil_syscallarg)(&MemoryInfo),
    #endif
        LIBUTIL_NT_MemoryBasicInformation,
    #if defined(LIBUTIL_X86) && !defined(LIBUTIL_X86_PURE32)
        (LibUtil_Nt_GetTeb64() == NULL) ? sizeof(Memory.Info32) : sizeof(Memory.Info64),
    #else
        sizeof(MemoryInfo),
    #endif
        NULL
    );
#else
    LIBUTIL_NT_MEMORY_BASIC_INFORMATION MemoryInfo;
    LIBUTIL_NT_STATUS Status = ((LIBUTIL_NT_STATUS(LIBUTIL_MSABI*)(void *, libutil_size, LIBUTIL_NT_MEMORY_BASIC_INFORMATION *, libutil_i32, libutil_size, void *))(LIBUTIL_SYSCALLID(NtQueryVirtualMemory)))(
        (void *)(-1),
        (libutil_size)(LibUtil_AlignDown(Address, 0x1000)),
        &MemoryInfo,
        LIBUTIL_NT_MemoryBasicInformation,
        sizeof(MemoryInfo),
        NULL
    );
#endif

    if(!LIBUTIL_NT_SUCCESS(Status))
    {
        return FALSE;
    }

#ifndef LIBUTIL_WINE
#if defined(LIBUTIL_X86) && !defined(LIBUTIL_X86_PURE32)
    if(LibUtil_Nt_GetTeb64() == NULL)
    {
        *Protection = Memory.Info32.Protect;
    }
    else
    {
        *Protection = Memory.Info64.Protect;
    }
#else
    *Protection = MemoryInfo.Protect;
#endif
#else
    *Protection = MemoryInfo.Protect;
#endif

    return TRUE;
}

LIBUTIL_API
libutil_bool LibUtil_Page_IsExecutable(libutil_syscallarg Address)
{
    libutil_u32 Protection;
    if(!LibUtil_Page_QueryProtection(Address, &Protection))
    {
        return FALSE;
    }

    return (Protection & LIBUTIL_PAGE_X);
}

#endif
