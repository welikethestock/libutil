#ifdef __linux__
#include "page.h"
#include "../sys/syscall.h"
#include "../../common/mathbits.h"
#include <sys/syscall.h>

#define LIBUTIL_PAGE_ALIGN 0x1000

LIBUTIL_API
libutil_bool LibUtil_Page_Protect(void *Address, libutil_size Size, libutil_u32 Protection, libutil_u32 *OldProtection)
{
    libutil_i32 Result = LibUtil_Syscall3(
        SYS_mprotect,
        LibUtil_AlignDown((libutil_size)(Address), LIBUTIL_PAGE_ALIGN),
        LibUtil_AlignUp(Size, LIBUTIL_PAGE_ALIGN),
        (libutil_size)(Protection)
    );

    return (Result == 0);
}

#endif
