#ifdef __linux__
#include "page.h"
#include "../syscall.h"
#include <sys/syscall.h>

LIBUTIL_API
libutil_bool LibUtil_Page_Protect(void *Address, libutil_size Size, libutil_u32 Protection, libutil_u32 *OldProtection)
{
    libutil_i32 Result = LibUtil_Syscall3(SYS_mprotect, (libutil_size)(Address), (libutil_size)(Size), (libutil_size)(Protection));
#ifndef __linux__
    if(OldProtection != NULL)
    {
        *(libutil_i32*)(OldProtection) = Result;
    }
#endif

    return (Result == 0);
}

#endif
