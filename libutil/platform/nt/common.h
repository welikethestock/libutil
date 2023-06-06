#ifndef __LIBUTIL_PLATFORM_NT_COMMON__
#define __LIBUTIL_PLATFORM_NT_COMMON__

#include "../../common/decl.h"

typedef union
{
    struct
    {
        libutil_u32 LowPart;
        libutil_i32 HighPart;
    };
    libutil_i64 QuadPart;
} LIBUTIL_NT_LARGE_INTEGER;

typedef union
{
    struct
    {
        libutil_u32 LowPart;
        libutil_u32 HighPart;
    };
    libutil_u64 QuadPart;
} LIBUTIL_NT_ULARGE_INTEGER;

typedef struct _LIBUTIL_NT_UNICODE_STRING32
{
    libutil_u16     Length;
    libutil_u16     MaximumLength;
    libutil_u32     Buffer;
} LIBUTIL_NT_UNICODE_STRING32;

typedef struct _LIBUTIL_NT_UNICODE_STRING64
{
    libutil_u16     Length;
    libutil_u16     MaximumLength;
    libutil_u64     Buffer;
} LIBUTIL_NT_UNICODE_STRING64;

typedef struct _LIBUTIL_NT_LIST_ENTRY32
{
    libutil_u32 Flink;
    libutil_u32 Blink;
} LIBUTIL_NT_LIST_ENTRY32;

typedef struct _LIBUTIL_NT_LIST_ENTRY64
{
    libutil_u64 Flink;
    libutil_u64 Blink;
} LIBUTIL_NT_LIST_ENTRY64;

typedef struct _LIBUTIL_NT_LIST_ENTRY
{
    struct _LIBUTIL_NT_LIST_ENTRY *Flink;
    struct _LIBUTIL_NT_LIST_ENTRY *Blink;
} LIBUTIL_NT_LIST_ENTRY;

#endif
