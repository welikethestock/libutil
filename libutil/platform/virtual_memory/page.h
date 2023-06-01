#ifndef __LIBUTIL_PLATFORM_VIRTUALMEMORY_PAGE__
#define __LIBUTIL_PLATFORM_VIRTUALMEMORY_PAGE__

#include "../../common/decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

enum
{
#ifdef __linux__
    LIBUTIL_PAGE_R      = 0x1,
    LIBUTIL_PAGE_W      = 0x2,
    LIBUTIL_PAGE_X      = 0x4,

    LIBUTIL_PAGE_RW     = (LIBUTIL_PAGE_R | LIBUTIL_PAGE_W),
    LIBUTIL_PAGE_RX     = (LIBUTIL_PAGE_R | LIBUTIL_PAGE_X),
    LIBUTIL_PAGE_RWX    = (LIBUTIL_PAGE_R | LIBUTIL_PAGE_W | LIBUTIL_PAGE_X)
#endif
};

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool LibUtil_Page_Protect(void *Address, libutil_size Size, libutil_u32 Protection, libutil_u32 *OldProtection);

LIBUTIL_EXTERN_C_BLOCK_END

#endif
