#ifndef __LIBUTIL_PLATFORM_VIRTUALMEMORY_PAGE__
#define __LIBUTIL_PLATFORM_VIRTUALMEMORY_PAGE__

#include "../../common/decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

enum
{
#ifdef LIBUTIL_LINUX
    LIBUTIL_MAP_FILE = 0x0,
    LIBUTIL_MAP_SHARED = 0x1,
    LIBUTIL_MAP_PRIVATE = 0x2,
    LIBUTIL_MAP_ANONYMOUS = 0x20,
    LIBUTIL_MAP_32BIT = 0x40,
    LIBUTIL_MAP_EXECUTABLE = 0x1000,
    LIBUTIL_MAP_NORESERVE = 0x4000,
    LIBUTIL_MAP_POPULATE = 0x8000,
#elif defined(LIBUTIL_WINDOWS)
    LIBUTIL_MAP_FILE = 0x0, // ignored
    LIBUTIL_MAP_EXECUTABLE = 0x0, // ignored
    LIBUTIL_MAP_SHARED = 0x0, // ignored
    LIBUTIL_MAP_32BIT = 0x0, // ignored
    LIBUTIL_MAP_POPULATE = 0x0, // ignored

    LIBUTIL_MAP_ANONYMOUS = 0x1, // ignored
    LIBUTIL_MAP_PRIVATE = 0x1,
    LIBUTIL_MAP_NORESERVE = 0x2,
#endif

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    LU_MAP_FILE = LIBUTIL_MAP_FILE,
    LU_MAP_SHARED = LIBUTIL_MAP_SHARED,
    LU_MAP_PRIVATE = LIBUTIL_MAP_PRIVATE,
    LU_MAP_ANONYMOUS = LIBUTIL_MAP_ANONYMOUS,
    LU_MAP_32BIT = LIBUTIL_MAP_32BIT,
    LU_MAP_EXECUTABLE = LIBUTIL_MAP_EXECUTABLE,
    LU_MAP_NORESERVE = LIBUTIL_MAP_NORESERVE,
    LU_MAP_POPULATE = LIBUTIL_MAP_POPULATE
#endif
};

enum
{
#ifdef LIBUTIL_LINUX
    LIBUTIL_PAGE_R      = 0x1,
    LIBUTIL_PAGE_W      = 0x2,
    LIBUTIL_PAGE_X      = 0x4,

    LIBUTIL_PAGE_RW     = (LIBUTIL_PAGE_R | LIBUTIL_PAGE_W),
    LIBUTIL_PAGE_RX     = (LIBUTIL_PAGE_R | LIBUTIL_PAGE_X),
    LIBUTIL_PAGE_RWX    = (LIBUTIL_PAGE_R | LIBUTIL_PAGE_W | LIBUTIL_PAGE_X),
#elif defined(LIBUTIL_WINDOWS)
    LIBUTIL_PAGE_R      = 0x2,
    LIBUTIL_PAGE_W      = 0x4,
    LIBUTIL_PAGE_X      = 0x10,

    LIBUTIL_PAGE_RW     = 0x4,
    LIBUTIL_PAGE_RX     = 0x20,
    LIBUTIL_PAGE_RWX    = 0x40,
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
libutil_bool LibUtil_Page_Allocate(void **BaseAddress, libutil_size Size, libutil_u32 Protection, libutil_u32 Flags);

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool LibUtil_Page_Free(void *BaseAddress);

LIBUTIL_API LIBUTIL_IMPORT
libutil_bool LibUtil_Page_Protect(void *Address, libutil_size Size, libutil_u32 Protection, libutil_u32 *OldProtection);

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    #define lu_pageallocate LibUtil_Page_Allocate
    #define lu_pagefree     LibUtil_Page_Free
    #define lu_pageprotect  LibUtil_Page_Protect
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#endif
