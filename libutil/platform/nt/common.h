#ifndef __LIBUTIL_PLATFORM_NT_COMMON__
#define __LIBUTIL_PLATFORM_NT_COMMON__

// initial: these were reconstructed from windows server 2012 r2

#include "../../common/decl.h"

LIBUTIL_EXTERN_C_BLOCK_START

typedef union _LIBUTIL_NT_LARGE_INTEGER
{
    struct
    {
        libutil_u32 LowPart;
        libutil_i32 HighPart;
    };
    libutil_i64 QuadPart;
} LIBUTIL_NT_LARGE_INTEGER;

typedef union _LIBUTIL_NT_ULARGE_INTEGER
{
    struct
    {
        libutil_u32 LowPart;
        libutil_u32 HighPart;
    };
    libutil_u64 QuadPart;
} LIBUTIL_NT_ULARGE_INTEGER;

typedef struct _LIBUTIL_NT_GUID
{
    libutil_u32     Data1;
    libutil_u16     Data2;
    libutil_u16     Data3;
    libutil_u8      Data4[8];
} LIBUTIL_NT_GUID;

typedef struct LIBUTIL_ALIGN(4) _LIBUTIL_NT_UNICODE_STRING32
{
    libutil_u16     Length;
    libutil_u16     MaximumLength;
    libutil_u32     Buffer;
} LIBUTIL_NT_UNICODE_STRING32;

typedef struct LIBUTIL_ALIGN(8) _LIBUTIL_NT_UNICODE_STRING64
{
    libutil_u16     Length;
    libutil_u16     MaximumLength;
    libutil_u64     Buffer;
} LIBUTIL_NT_UNICODE_STRING64;

typedef struct _LIBUTIL_NT_UNICODE_STRING
{
    libutil_u16     Length;
    libutil_u16     MaximumLength;
    libutil_wchar   *Buffer;
} LIBUTIL_NT_UNICODE_STRING;

typedef struct LIBUTIL_ALIGN(4) _LIBUTIL_NT_LIST_ENTRY32
{
    libutil_u32 Flink;
    libutil_u32 Blink;
} LIBUTIL_NT_LIST_ENTRY32;

typedef struct LIBUTIL_ALIGN(8) _LIBUTIL_NT_LIST_ENTRY64
{
    libutil_u64 Flink;
    libutil_u64 Blink;
} LIBUTIL_NT_LIST_ENTRY64;

typedef struct _LIBUTIL_NT_LIST_ENTRY
{
    struct _LIBUTIL_NT_LIST_ENTRY *Flink;
    struct _LIBUTIL_NT_LIST_ENTRY *Blink;
} LIBUTIL_NT_LIST_ENTRY;

typedef struct LIBUTIL_ALIGN(4) _LIBUTIL_NT_RTL_BALANCED_NODE32
{
    union
    {
        libutil_u32 Children[2];
        struct
        {
            libutil_u32 Left;
            libutil_u32 Right;
        };
    };
    union
    {
        struct
        {
            libutil_bool Red : 1;
            libutil_bool Balance : 1;
        };
        libutil_u32 ParentValue;
    };
} LIBUTIL_NT_RTL_BALANCED_NODE32;

typedef struct LIBUTIL_ALIGN(8) _LIBUTIL_NT_RTL_BALANCED_NODE64
{
    union
    {
        libutil_u64 Children[2];
        struct
        {
            libutil_u64 Left;
            libutil_u64 Right;
        };
    };
    union
    {
        struct
        {
            libutil_bool Red : 1;
            libutil_bool Balance : 1;
        };
        libutil_u64 ParentValue;
    };
} LIBUTIL_NT_RTL_BALANCED_NODE64;

typedef struct _LIBUTIL_NT_RTL_BALANCED_NODE
{
    union
    {
        struct _LIBUTIL_NT_RTL_BALANCED_NODE *Children[2];
        struct
        {
            struct _LIBUTIL_NT_RTL_BALANCED_NODE *Left;
            struct _LIBUTIL_NT_RTL_BALANCED_NODE *Right;
        };
    };
    union
    {
        struct
        {
            libutil_bool Red : 1;
            libutil_bool Balance : 1;
        };
        struct _LIBUTIL_NT_RTL_BALANCED_NODE *ParentValue;
    };
} LIBUTIL_NT_RTL_BALANCED_NODE;

#ifndef LIBUTIL_DISABLE_SHORT_NAMES
    typedef LIBUTIL_NT_LARGE_INTEGER        lu_nt_largeinteger;
    typedef LIBUTIL_NT_ULARGE_INTEGER       lu_nt_ulargeinteger;

    typedef LIBUTIL_NT_GUID                 lu_nt_guid;

    typedef LIBUTIL_NT_UNICODE_STRING32     lu_nt_unicodestring32;
    typedef LIBUTIL_NT_UNICODE_STRING64     lu_nt_unicodestring64;
    typedef LIBUTIL_NT_UNICODE_STRING       lu_nt_unicodestring;

    typedef LIBUTIL_NT_LIST_ENTRY32         lu_nt_list_entry32;
    typedef LIBUTIL_NT_LIST_ENTRY64         lu_nt_list_entry64;
    typedef LIBUTIL_NT_LIST_ENTRY           lu_nt_list_entry;

    typedef LIBUTIL_NT_RTL_BALANCED_NODE32  lu_nt_rtl_balancednode32;
    typedef LIBUTIL_NT_RTL_BALANCED_NODE64  lu_nt_rtl_balancednode64;
    typedef LIBUTIL_NT_RTL_BALANCED_NODE    lu_nt_rtl_balancednode;
#endif

LIBUTIL_EXTERN_C_BLOCK_END

#ifdef __cplusplus
    static_assert(sizeof(LIBUTIL_NT_LARGE_INTEGER) == 0x08, "sizeof(LIBUTIL_NT_LARGE_INTEGER) == 0x08");
    static_assert(sizeof(LIBUTIL_NT_ULARGE_INTEGER) == 0x08, "sizeof(LIBUTIL_NT_LARGE_UINTEGER) == 0x08");

    static_assert(sizeof(LIBUTIL_NT_GUID) == 0x10, "sizeof(LIBUTIL_NT_UNICODE_STRING32) == 0x10");

    static_assert(sizeof(LIBUTIL_NT_UNICODE_STRING32) == 0x08, "sizeof(LIBUTIL_NT_UNICODE_STRING32) == 0x08");
    static_assert(sizeof(LIBUTIL_NT_UNICODE_STRING64) == 0x10, "sizeof(LIBUTIL_NT_UNICODE_STRING64) == 0x10");

    static_assert(sizeof(LIBUTIL_NT_LIST_ENTRY32) == 0x08, "sizeof(LIBUTIL_NT_LIST_ENTRY32) == 0x08");
    static_assert(sizeof(LIBUTIL_NT_LIST_ENTRY64) == 0x10, "sizeof(LIBUTIL_NT_LIST_ENTRY32) == 0x10");
#endif

#endif
