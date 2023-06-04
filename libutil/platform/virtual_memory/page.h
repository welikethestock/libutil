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
    LIBUTIL_PAGE_RWX    = (LIBUTIL_PAGE_R | LIBUTIL_PAGE_W | LIBUTIL_PAGE_X),
#endif

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    LU_PAGE_R = LIBUTIL_PAGE_R,
    LU_PAGE_W = LIBUTIL_PAGE_W,
    LU_PAGE_X = LIBUTIL_PAGE_X,
    LU_PAGE_RW = LIBUTIL_PAGE_RW,
    LU_PAGE_RX = LIBUTIL_PAGE_RX,
    LU_PAGE_RWX = LIBUTIL_PAGE_RWX,
#endif
};

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool LibUtil_Page_Protect(void *Address, libutil_size Size, libutil_u32 Protection, libutil_u32 *OldProtection);

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    #define lu_pageprotect LibUtil_Page_Protect
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
