#ifndef __LIBUTIL_PLATFORM_NT_TIB__
#define __LIBUTIL_PLATFORM_NT_TIB__

#include "../../common/decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

#ifdef LIBUTIL_MSVC
#pragma pack(push, 1)
#endif

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_TIB32
{
    libutil_u32 ExceptionList;      /*_EXCEPTION_REGISTRATION_RECORD*/      /*+0x000*/
    libutil_u32 StackBase;                                                  /*+0x004*/
    libutil_u32 StackLimit;                                                 /*+0x008*/
    libutil_u32 SubSystemTib;                                               /*+0x00C*/
    union
    {
        libutil_u32 FiberData;                                              /*+0x010*/
        libutil_u32 Version;                                                /*+0x010*/
    };
    libutil_u32     ArbitraryUserPointer;                                   /*+0x014*/
    libutil_u32     Self;           /*_NT_TIB* */                           /*+0x018*/
} LIBUTIL_NT_TIB32;

typedef struct LIBUTIL_ALIGN(1) LIBUTIL_PACKED _LIBUTIL_NT_TIB64
{
    libutil_u64 ExceptionList;      /*_EXCEPTION_REGISTRATION_RECORD*/      /*+0x000*/
    libutil_u64 StackBase;                                                  /*+0x008*/
    libutil_u64 StackLimit;                                                 /*+0x010*/
    libutil_u64 SubSystemTib;                                               /*+0x018*/
    union
    {
        libutil_u64 FiberData;                                              /*+0x020*/
        libutil_u32 Version;                                                /*+0x020*/
    };
    libutil_u64     ArbitraryUserPointer;                                   /*+0x028*/
    libutil_u64     Self;           /*_NT_TIB* */                           /*+0x030*/
} LIBUTIL_NT_TIB64;

#ifdef LIBUTIL_MSVC
#pragma pack(pop)
#endif

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    typedef LIBUTIL_NT_TIB32 lu_nt_tib32;
    typedef LIBUTIL_NT_TIB64 lu_nt_tib64;
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#ifdef __cplusplus
    static_assert(sizeof(LIBUTIL_NT_TIB32) == 0x1C, "sizeof(LIBUTIL_NT_TIB64) == 0x1C");
    static_assert(sizeof(LIBUTIL_NT_TIB64) == 0x38, "sizeof(LIBUTIL_NT_TIB64) == 0x38");
#endif

#endif
