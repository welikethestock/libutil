#include "../../common/features.h"

#ifdef LIBUTIL_WINDOWS
#include "page.h"
#include "../sys/syscall.h"
#include "../../common/mathbits.h"
#include "../../platform/nt/common.h"

#define LIBUTIL_PAGE_ALIGN 0x1000

#define MEM_COMMIT  0x1000
#define MEM_RESERVE 0x2000

static
libutil_i32 s_NtAllocateVirtualMemoryID = 0x17; //NOTE: TEMPORARY

LIBUTIL_API
libutil_bool LibUtil_Page_Allocate(void **BaseAddress, libutil_size Size, libutil_u32 Protection, libutil_u32 Flags)
{
    libutil_syscallarg AllocationType = (MEM_COMMIT | MEM_RESERVE);
    if(Flags & LIBUTIL_MAP_NORESERVE)
    {
        AllocationType &= ~(MEM_RESERVE);
    }

    LIBUTIL_ALIGN(16) libutil_syscallarg AlignedSize = Size;

    LIBUTIL_NT_STATUS Status = lu_syscall6(
        s_NtAllocateVirtualMemoryID,
        -1,
        (libutil_syscallarg)(BaseAddress),
        NULL,
        (libutil_syscallarg)(&AlignedSize),
        AllocationType,
        Protection
    );

    return LIBUTIL_NT_SUCCESS(Status);
}

LIBUTIL_API
libutil_bool LibUtil_Page_Protect(void *Address, libutil_size Size, libutil_u32 Protection, libutil_u32 *OldProtection)
{

}

#endif
