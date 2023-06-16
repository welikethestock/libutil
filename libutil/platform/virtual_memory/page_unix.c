#include "../../common/features.h"

#ifdef LIBUTIL_LINUX

#include "page.h"
#include "../sys/syscall.h"
#include "../../common/mathbits.h"
#include <sys/syscall.h>

#define LIBUTIL_PAGE_ALIGN 0x1000

LIBUTIL_API
libutil_bool LibUtil_Page_Allocate(libutil_u64 *BaseAddress, libutil_size Size, libutil_u32 Protection, libutil_u32 Flags)
{
    libutil_i64 Result = LibUtil_Syscall6(
        SYS_mmap,
        LibUtil_AlignDown(*BaseAddress, LIBUTIL_PAGE_ALIGN),
        LibUtil_AlignUp(Size, LIBUTIL_PAGE_ALIGN),
        Protection,
        Flags,
        -1,
        0
    );

    *((libutil_i64 *)(BaseAddress)) = Result;

    return (*BaseAddress != NULL);
}


LIBUTIL_API
libutil_bool LibUtil_Page_Protect(libutil_u64 Address, libutil_size Size, libutil_u32 Protection, libutil_u32 *OldProtection)
{
    libutil_i32 Result = LibUtil_Syscall3(
        SYS_mprotect,
        LibUtil_AlignDown(Address, LIBUTIL_PAGE_ALIGN),
        LibUtil_AlignUp(Size, LIBUTIL_PAGE_ALIGN),
        (libutil_size)(Protection)
    );

    return (Result == 0);
}

#endif
